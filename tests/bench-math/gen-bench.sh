#!/bin/bash

# Recognized variables:
#
# CC=[avr-gcc]		Used to compile bench-float.c.
# JOBS=[1]              Number of parallel Jobs for make.
# TMIES=[1]             Multiplicator for N_VALS from the input files.
# builddir=             Use AVR-LibC from builddir instead of CC's.
#
# ./gen-banch.sh A B ... will read files $BASE-A.txt $BASE-B.txt etc.
# and user their input to generate the output file.

funcs=
texts=

out=out.dox

CC=${CC-avr-gcc}
TIMES=${TIMES-1}
JOBS=${JOBS-1}
BASE=${BASE-libm}

# Lines of extra avr-gcc arguments, used per "grep sinf" in Makefile.
cargs=cargs.txt

# Included by Makefile.
margs=margs.txt

id=10

Err ()
{
    echo "error: $1"
    exit 1
}

set_libs_crt ()
{
    LIBS=
    CRT=
    if [ -n "$builddir" ] ; then
      local multilibdir=$($CC -mmcu=$1 -print-multi-directory)
      # Use the same replacements like in mlib-gen.py::to_ident() and
      # configure.ac's CHECK_AVR_DEVICE.  This flattens out the multilib path.
      # For example, "avr25/tiny-stack" becomes "avr25_tiny_stack",
      # and "." becomes "avr2".
      local multilibdir=$(echo "$multilibdir"     \
                    | sed -e 's:^\.$:avr2:' \
                    | sed -e 's:/:_:g'      \
                    | sed -e 's:-:_:g')
      local crt=crt$1.o
      [ -d "$builddir/avr/devices" ] \
	  || Err "\$builddir/avr/devices = $builddir/avr/devices: not found"
      local incl="-I../../include -I $builddir/include"
      local flags="-nostdlib -nodevicelib -nostartfiles"
      local m="$builddir/avr/lib/$multilibdir"
      CRT=$(find $builddir/avr/devices -name $crt -print | head -1)
      local libs="$m/libc.a $m/libm.a $(dirname $CRT)/lib$1.a -lgcc"
      LIBS="$incl $flags -Wl,--start-group $libs -Wl,--end-group"
    fi
}

fun ()
{
    local x=_$1_${id}_
    id=$(( 1 + $id ))

    local sym=$1
    local e=
    case "$1" in
	fmin* | fmax* | fabs* ) e=" -DEXACT" ;;
    esac
    funcs="${funcs} $x"
    texts="${texts} text-$x.out"
    # Test FUNC=sinf against AFUNC=avrtest_sinl etc.
    echo " -DFUNC=$1 -DNARGS=$2 -DAFUNC=avrtest_${1::-1}l -DID=$x$e" >> $cargs
    shift
    shift
    local aargs=
    while (( "$# ")); do
	aargs="$aargs $1"
	shift
    done
    echo "AARGS_$x = $aargs" >> $margs

    [ $sym = addf ] && sym=__addsf3
    [ $sym = mulf ] && sym=__mulsf3
    [ $sym = divf ] && sym=__divsf3
    [ $sym = addl ] && sym=__adddf3
    [ $sym = mull ] && sym=__muldf3
    [ $sym = divl ] && sym=__divdf3
    [ $sym = __builtin_powif ] && sym=__powisf2
    [ $sym = __builtin_powil ] && sym=__powidf2
    echo "SYMBL_$x = $sym" >> $margs
}

do_func_txt ()
{
    echo -n "" > $cargs
    grep ^= "$1" | cut -c 2- > $margs

    texts=

    echo
    echo "== $1 =="

    # Line starts:
    # # -> Ignore (comment)
    # ! -> Eval
    # 1 -> Head
    # 2 -> Tail
    # None of these -> FUNCTION N_ARGS N_VALS*TIMES,X0,X1[,Y0,Y1]
    while read -u 11 p; do
	case "$p" in
	    "#"* | "" | [12=]* ) ;;
	    !*) eval $(echo "$p" | cut -c 2-) || exit 2 ;;
	    *) fun $p ;;
	esac
    done 11<$1

    set_libs_crt $MCU
    echo "CC = ${CC-avr-gcc}" >> $margs
    echo "MCU = $MCU" >> $margs
    echo "BASE = $BASE" >> $margs
    echo "CRT  = $CRT"  >> $margs
    echo "LIBS = $LIBS" >> $margs
    echo "TIMES = $TIMES" >> $margs

    echo "== $cargs =="
    cat $cargs

    echo "== $margs =="
    cat $margs

    [ -n "$texts" ] && (make clean ; nice -10 make -j$JOBS $texts)
}

#set -x

b="${builddir+builddir=$builddir }"
c="" && [ $CC != avr-gcc ] && c="CC=$CC "
t="" && [ $TIMES != 1 ] && t="TIMES=$TIMES "
j="" && [ $JOBS != 1 ] && j="JOBS=$JOBS "
B="" && [ $BASE != libm ] && B="BASE=$BASE "

cat <<EOF > $out
/* Auto-generated file.  DO NOT EDIT, OR YOUR CHANGES WILL BE LOST!
   This file has been auto-generated by:
   $ ${j}${c}${b}${t}${B}$0 $*
*/

/**
EOF

for f in $*; do
    fil="$BASE-$f.txt"
    [ -f "$fil" ] || Err "$fil: not found"

    do_func_txt $fil

    grep ^1 "$fil" | cut -c 2- >> $out
    [ -n "$texts" ] && cat $texts >> $out
    grep ^2 "$fil" | cut -c 2- >> $out
done

cat <<EOF >> $out
*/
EOF

echo "== $out =="
cat $out

make clean
rm -f -- $cargs $margs
