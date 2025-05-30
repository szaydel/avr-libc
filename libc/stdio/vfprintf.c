/* Copyright (c) 2002, Alexander Popov (sasho@vip.bg)
   Copyright (c) 2002,2004,2005 Joerg Wunsch
   Copyright (c) 2005, Helmut Wallner
   Copyright (c) 2007, Dmitry Xmelkov
   All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are met:

   * Redistributions of source code must retain the above copyright
     notice, this list of conditions and the following disclaimer.
   * Redistributions in binary form must reproduce the above copyright
     notice, this list of conditions and the following disclaimer in
     the documentation and/or other materials provided with the
     distribution.
   * Neither the name of the copyright holders nor the names of
     contributors may be used to endorse or promote products derived
     from this software without specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
  POSSIBILITY OF SUCH DAMAGE. */

/* From: Id: printf_p_new.c,v 1.1.1.9 2002/10/15 20:10:28 joerg_wunsch Exp */
#if !defined(__AVR_TINY__)

#include <avr/pgmspace.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sectionname.h"
#include "stdio_private.h"
#include "ftoa_engine.h"
#include "ntz.h"
#include "xtoa_fast.h"

/*
 * This file can be compiled into more than one flavour.  The default
 * is to offer the usual modifiers and integer formatting support
 * (level 2).  Level 1 maintains a minimal version that just offers
 * integer formatting, but no modifier support whatsoever.  Level 3 is
 * intended for floating point support.
 */

#ifndef PRINTF_LEVEL
# define PRINTF_LEVEL PRINTF_STD
#endif

#if PRINTF_LEVEL == PRINTF_MIN || PRINTF_LEVEL == PRINTF_STD \
    || PRINTF_LEVEL == PRINTF_FLT
/* OK */
#else
# error "Not a known printf level."
#endif

#ifndef	__AVR_HAVE_LPMX__
# if  defined(__AVR_ENHANCED__) && __AVR_ENHANCED__
#  define __AVR_HAVE_LPMX__	1
# endif
#endif

#if  defined(__AVR_HAVE_LPMX__) && __AVR_HAVE_LPMX__
# define GETBYTE(flag, mask, pnt)	({	\
    unsigned char __c;				\
    asm (					\
	"sbrc	%2,%3	\n\t"			\
	"lpm	%0,Z+	\n\t"			\
	"sbrs	%2,%3	\n\t"			\
	"ld	%0,Z+	"			\
	: "=&r" (__c),				\
	  "+z" (pnt)				\
	: "r" (flag),				\
	  "I" (ntz(mask))			\
    );						\
    __c;					\
})
#elif	1
# define GETBYTE(flag, mask, pnt)	({	\
    unsigned char __c;				\
    asm (					\
	"lpm		\n\t"			\
	"sbrs	%2,%3	\n\t"			\
	"ld	r0,Z	\n\t"			\
	"adiw	r30,1	\n\t"			\
	"mov	%0,r0	"			\
	: "=r" (__c),				\
	  "+z" (pnt)				\
	: "r" (flag),				\
	  "I" (ntz(mask))			\
	: "r0"					\
    );						\
    __c;					\
})
#else
# define GETBYTE(flag, mask, pnt)	({	\
    unsigned char __c;				\
    __c = ((flag) & (mask))			\
	  ? pgm_read_byte(pnt) : *pnt;		\
    pnt++;					\
    __c;					\
})
#endif

/* --------------------------------------------------------------------	*/
#if  PRINTF_LEVEL <= PRINTF_MIN

#define FL_PGMSTRING	0x01
#define FL_ALTHEX	0x04
#define FL_ALT		0x10
#define FL_ALTLWR	0x20
#define FL_NEGATIVE	0x40
#define FL_LONG 	0x80
#define FL_LONG_DOUBLE 	(__SIZEOF_LONG_DOUBLE__ != __SIZEOF_DOUBLE__ ? 0x08 : 0)

ATTRIBUTE_CLIB_SECTION
int
vfprintf (FILE * stream, const char *fmt, va_list ap)
{
    unsigned char c;		/* holds a char from the format string */
    unsigned char flags;
    unsigned char buf[11];	/* size for -1 in octal, without '\0'	*/

    stream->len = 0;

    if ((stream->flags & __SWR) == 0)
	return EOF;

    for (;;) {

	for (;;) {
	    c = GETBYTE (stream->flags, __SPGM, fmt);
	    if (!c) goto ret;
	    if (c == '%') {
		c = GETBYTE (stream->flags, __SPGM, fmt);
		if (c != '%') break;
	    }
	    putc (c, stream);
	}

	for (flags = 0;
	     !(flags & FL_LONG);	/* 'll' will detect as error	*/
	     c = GETBYTE (stream->flags, __SPGM, fmt))
	{
	    if (c && strchr_P (PSTR(" +-.0123456789h"), c))
		continue;
	    if (c == '#') {
		flags |= FL_ALT;
		continue;
	    }
	    if (c == 'l') {
		flags |= FL_LONG;
		continue;
	    }
	    if (c == 'L') {
		flags |= FL_LONG_DOUBLE;
		continue;
	    }
	    break;
	}

	/* Only a format character is valid.	*/

	if (c && strchr_P (PSTR("EFGefg"), c)) {
            if (flags & FL_LONG_DOUBLE)
                (void) va_arg (ap, long double);
            else
                (void) va_arg (ap, double);
	    putc ('?', stream);
	    continue;
	}

	{
	    const char * pnt;

	    switch (c) {

	      case 'c':
		putc (va_arg (ap, int), stream);
		continue;

	      case 'S':
		flags |= FL_PGMSTRING;
		/* FALLTHROUGH */

	      case 's':
		pnt = va_arg (ap, char *);
	        while ( (c = GETBYTE (flags, FL_PGMSTRING, pnt)) != 0)
		    putc (c, stream);
		continue;
	    }
	}

	if (c == 'd' || c == 'i') {
	    long x = (flags & FL_LONG) ? va_arg(ap,long) : va_arg(ap,int);
	    flags &= ~FL_ALT;
	    if (x < 0) {
		x = -x;
		/* `putc ('-', stream)' will considerably enlarge stack size.
		   So flag is used.	*/
		flags |= FL_NEGATIVE;
	    }
	    c = __ultoa_invert (x, (char *)buf, 10) - (char *)buf;

	} else {
	    int base;

	    switch (c) {
	      case 'u':
		flags &= ~FL_ALT;
	        base = 10;
		goto ultoa;
	      case 'o':
	        base = 8;
		goto ultoa;
	      case 'p':
	        flags |= FL_ALT;
		/* fallthrough */
	      case 'x':
		flags |= (FL_ALTHEX | FL_ALTLWR);
	        base = 16;
		goto ultoa;
	      case 'X':
		flags |= FL_ALTHEX;
	        base = 16 | XTOA_UPPER;
	      ultoa:
		c = __ultoa_invert ((flags & FL_LONG)
				    ? va_arg(ap, unsigned long)
				    : va_arg(ap, unsigned int),
				    (char *)buf, base)  -  (char *)buf;
		break;

	      default:
	        goto ret;
	    }
	}

	/* Integer number output.	*/
	if (flags & FL_NEGATIVE)
	    putc ('-', stream);
	if ((flags & FL_ALT) && (buf[c-1] != '0')) {
	    putc ('0', stream);
	    if (flags & FL_ALTHEX)
#if  FL_ALTLWR != 'x' - 'X'
# error
#endif
		putc ('X' + (flags & FL_ALTLWR), stream);
	}
	do {
	    putc (buf[--c], stream);
	} while (c);

    } /* for (;;) */

  ret:
    return stream->len;
}

/* --------------------------------------------------------------------	*/
#else	/* i.e. PRINTF_LEVEL > PRINTF_MIN */

#define FL_ZFILL	0x01
#define FL_PLUS		0x02
#define FL_SPACE	0x04
#define FL_LPAD		0x08
#define FL_ALT		0x10
#define FL_WIDTH	0x20
#define FL_PREC		0x40
#define FL_LONG		0x80

#define FL_PGMSTRING	FL_LONG
#define FL_NEGATIVE	FL_LONG

#define FL_ALTUPP	FL_PLUS
#define FL_ALTHEX	FL_SPACE

#define	FL_FLTUPP	FL_ALT
#define FL_FLTEXP	FL_PREC
#define	FL_FLTFIX	FL_LONG

/* %Lf might not be the same like %f. */
#define XFL_LONG	((__SIZEOF_LONG_DOUBLE__ != __SIZEOF_DOUBLE__) << 0)


ATTRIBUTE_CLIB_SECTION
int vfprintf (FILE * stream, const char *fmt, va_list ap)
{
    unsigned char c;		/* holds a char from the format string */
    unsigned char flags;
    unsigned char width;
    unsigned char prec;
    unsigned char buf[11];	/* size for -1 in octal, without '\0'	*/
    unsigned char xflags;

    stream->len = 0;

    if ((stream->flags & __SWR) == 0)
	return EOF;

    for (;;) {

	for (;;) {
	    c = GETBYTE (stream->flags, __SPGM, fmt);
	    if (!c) goto ret;
	    if (c == '%') {
		c = GETBYTE (stream->flags, __SPGM, fmt);
		if (c != '%') break;
	    }
	    putc (c, stream);
	}

	if (XFL_LONG)
	    xflags = 0;
	flags = 0;
	width = 0;
	prec = 0;

	do {
	    if (flags < FL_WIDTH) {
		switch (c) {
		  case '0':
		    flags |= FL_ZFILL;
		    continue;
		  case '+':
		    flags |= FL_PLUS;
		    /* FALLTHROUGH */
		  case ' ':
		    flags |= FL_SPACE;
		    continue;
		  case '-':
		    flags |= FL_LPAD;
		    continue;
		  case '#':
		    flags |= FL_ALT;
		    continue;
		}
	    }

	    if (flags < FL_LONG) {
		if (c >= '0' && c <= '9') {
		    c -= '0';
		    if (flags & FL_PREC) {
			prec = 10*prec + c;
			continue;
		    }
		    width = 10*width + c;
		    flags |= FL_WIDTH;
		    continue;
		}
		if (c == '.') {
		    if (flags & FL_PREC)
			goto ret;
		    flags |= FL_PREC;
		    continue;
		}
		if (c == 'l') {
		    flags |= FL_LONG;
		    continue;
		}
		if (c == 'L') {
		    xflags |= XFL_LONG;
		    continue;
		}
		if (c == 'h')
		    continue;
	    }

	    break;
	} while ( (c = GETBYTE (stream->flags, __SPGM, fmt)) != 0);

	/* Only a format character is valid.	*/

#if	'F' != 'E'+1  ||  'G' != 'F'+1  ||  'f' != 'e'+1  ||  'g' != 'f'+1
# error
#endif

	/* We only support 32-bit floating point, hence if double is 64 bits
	   wide, there is nothing to do here because ... will promote float
	   to double.  */
#if (PRINTF_LEVEL >= PRINTF_FLT) && (__SIZEOF_DOUBLE__ == __SIZEOF_FLOAT__)

	if ((xflags & XFL_LONG)
	    && ((c >= 'E' && c <= 'G') || (c >= 'e' && c <= 'g')))
	{
	    (void) va_arg (ap, long double);
	    buf[0] = '?';
	    goto buf_addr;
	}

	if (c >= 'E' && c <= 'G') {
	    flags |= FL_FLTUPP;
	    c += 'e' - 'E';
	    goto flt_oper;

	} else if (c >= 'e' && c <= 'g') {

	    int exp;		/* exponent of master decimal digit	*/
	    int n;
	    unsigned char vtype;	/* result of float value parse	*/
	    unsigned char sign;		/* sign character (or 0)	*/
# define ndigs	c		/* only for this block, undef is below	*/

	    flags &= ~FL_FLTUPP;

	  flt_oper:
	    if (!(flags & FL_PREC))
		prec = 6;
	    flags &= ~(FL_FLTEXP | FL_FLTFIX);
	    if (c == 'e')
		flags |= FL_FLTEXP;
	    else if (c == 'f')
		flags |= FL_FLTFIX;
	    else if (prec > 0)
		prec -= 1;

	    if (flags & FL_FLTFIX) {
		vtype = 7;		/* 'prec' arg for 'ftoa_engine'	*/
		ndigs = prec < 60 ? prec + 1 : 60;
	    } else {
		if (prec > 7) prec = 7;
		vtype = prec;
		ndigs = 0;
	    }
	    exp = __ftoa_engine (va_arg(ap,double), (char *)buf, vtype, ndigs);
	    vtype = buf[0];

	    sign = 0;
	    if ((vtype & FTOA_MINUS) && !(vtype & FTOA_NAN))
		sign = '-';
	    else if (flags & FL_PLUS)
		sign = '+';
	    else if (flags & FL_SPACE)
		sign = ' ';

	    if (vtype & (FTOA_NAN | FTOA_INF)) {
		const char *p;
		ndigs = sign ? 4 : 3;
		if (width > ndigs) {
		    width -= ndigs;
		    if (!(flags & FL_LPAD)) {
			do {
			    putc (' ', stream);
			} while (--width);
		    }
		} else {
		    width = 0;
		}
		if (sign)
		    putc (sign, stream);
		p = PSTR("inf");
		if (vtype & FTOA_NAN)
		    p = PSTR("nan");
# if ('I'-'i' != 'N'-'n') || ('I'-'i' != 'F'-'f') || ('I'-'i' != 'A'-'a')
#  error
# endif
		while ( (ndigs = pgm_read_byte(p)) != 0) {
		    if (flags & FL_FLTUPP)
			ndigs += 'I' - 'i';
		    putc (ndigs, stream);
		    p++;
		}
		goto tail;
	    }

	    /* Output format adjustment, number of decimal digits in buf[] */
	    if (flags & FL_FLTFIX) {
		ndigs += exp;
		if ((vtype & FTOA_CARRY) && buf[1] == '1')
		    ndigs -= 1;
		if ((signed char)ndigs < 1)
		    ndigs = 1;
		else if (ndigs > 8)
		    ndigs = 8;
	    } else if (!(flags & FL_FLTEXP)) {		/* 'g(G)' format */
		if (exp <= prec && exp >= -4)
		    flags |= FL_FLTFIX;
		while (prec && buf[1+prec] == '0')
		    prec--;
		if (flags & FL_FLTFIX) {
		    ndigs = prec + 1;		/* number of digits in buf */
		    prec = prec > exp
			   ? prec - exp : 0;	/* fractional part length  */
		}
	    }

	    /* Conversion result length, width := free space length	*/
	    if (flags & FL_FLTFIX)
		n = (exp>0 ? exp+1 : 1);
	    else
		n = 5;		/* 1e+00 */
	    if (sign) n += 1;
	    if (prec) n += prec + 1;
	    width = width > n ? width - n : 0;

	    /* Output before first digit	*/
	    if (!(flags & (FL_LPAD | FL_ZFILL))) {
		while (width) {
		    putc (' ', stream);
		    width--;
		}
	    }
	    if (sign) putc (sign, stream);
	    if (!(flags & FL_LPAD)) {
		while (width) {
		    putc ('0', stream);
		    width--;
		}
	    }

	    if (flags & FL_FLTFIX) {		/* 'f' format		*/

		n = exp > 0 ? exp : 0;		/* exponent of left digit */
		do {
		    if (n == -1)
			putc ('.', stream);
		    flags = (n <= exp && n > exp - ndigs)
			    ? buf[exp - n + 1] : '0';
		    if (--n < -prec)
			break;
		    putc (flags, stream);
		} while (1);
		if (n == exp
		    && (buf[1] > '5'
		        || (buf[1] == '5' && !(vtype & FTOA_CARRY))) )
		{
		    flags = '1';
		}
		putc (flags, stream);

	    } else {				/* 'e(E)' format	*/

		/* mantissa	*/
		if (buf[1] != '1')
		    vtype &= ~FTOA_CARRY;
		putc (buf[1], stream);
		if (prec) {
		    putc ('.', stream);
		    sign = 2;
		    do {
			putc (buf[sign++], stream);
		    } while (--prec);
		}

		/* exponent	*/
		putc (flags & FL_FLTUPP ? 'E' : 'e', stream);
		ndigs = '+';
		if (exp < 0 || (exp == 0 && (vtype & FTOA_CARRY) != 0)) {
		    exp = -exp;
		    ndigs = '-';
		}
		putc (ndigs, stream);
		for (ndigs = '0'; exp >= 10; exp -= 10)
		    ndigs += 1;
		putc (ndigs, stream);
		putc ('0' + exp, stream);
	    }

	    goto tail;
# undef ndigs
	}

#else		/* to: PRINTF_LEVEL >= PRINTF_FLT && double == float */
	if ((c >= 'E' && c <= 'G') || (c >= 'e' && c <= 'g')) {
	    if (xflags & XFL_LONG)
		(void) va_arg (ap, long double);
	    else
		(void) va_arg (ap, double);
	    buf[0] = '?';
	    goto buf_addr;
	}

#endif

	{
	    const char * pnt;
	    size_t size;

	    switch (c) {

	      case 'c':
		buf[0] = va_arg (ap, int);
	      buf_addr: if (0) goto buf_addr;
		pnt = (char *)buf;
		size = 1;
		goto no_pgmstring;

	      case 's':
		pnt = va_arg (ap, char *);
		size = strnlen (pnt, (flags & FL_PREC) ? prec : ~0);
	      no_pgmstring:
		flags &= ~FL_PGMSTRING;
		goto str_lpad;

	      case 'S':
	        pnt = va_arg (ap, char *);
		size = strnlen_P (pnt, (flags & FL_PREC) ? prec : ~0);
		flags |= FL_PGMSTRING;

	      str_lpad:
		if (!(flags & FL_LPAD)) {
		    while (size < width) {
			putc (' ', stream);
			width--;
		    }
		}
		while (size) {
		    putc (GETBYTE (flags, FL_PGMSTRING, pnt), stream);
		    if (width) width -= 1;
		    size -= 1;
		}
		goto tail;
	    }
	}

	if (c == 'd' || c == 'i') {
	    long x = (flags & FL_LONG) ? va_arg(ap,long) : va_arg(ap,int);
	    flags &= ~(FL_NEGATIVE | FL_ALT);
	    if (x < 0) {
		x = -x;
		flags |= FL_NEGATIVE;
	    }
	    c = __ultoa_invert (x, (char *)buf, 10) - (char *)buf;

	} else {
	    int base;

	    if (c == 'u') {
		flags &= ~FL_ALT;
		base = 10;
		goto ultoa;
	    }

	    flags &= ~(FL_PLUS | FL_SPACE);

	    switch (c) {
	      case 'o':
	        base = 8;
		goto ultoa;
	      case 'p':
	        flags |= FL_ALT;
		/* fallthrough */
	      case 'x':
		if (flags & FL_ALT)
		    flags |= FL_ALTHEX;
	        base = 16;
		goto ultoa;
	      case 'X':
		if (flags & FL_ALT)
		    flags |= (FL_ALTHEX | FL_ALTUPP);
	        base = 16 | XTOA_UPPER;
	      ultoa:
		c = __ultoa_invert ((flags & FL_LONG)
				    ? va_arg(ap, unsigned long)
				    : va_arg(ap, unsigned int),
				    (char *)buf, base)  -  (char *)buf;
		flags &= ~FL_NEGATIVE;
		break;

	      default:
	        goto ret;
	    }
	}

	{
	    unsigned char len;

	    len = c;
	    if (flags & FL_PREC) {
		flags &= ~FL_ZFILL;
		if (len < prec) {
		    len = prec;
		    if ((flags & FL_ALT) && !(flags & FL_ALTHEX))
			flags &= ~FL_ALT;
		}
	    }
	    if (flags & FL_ALT) {
		if (buf[c-1] == '0') {
		    flags &= ~(FL_ALT | FL_ALTHEX | FL_ALTUPP);
		} else {
		    len += 1;
		    if (flags & FL_ALTHEX)
		    	len += 1;
		}
	    } else if (flags & (FL_NEGATIVE | FL_PLUS | FL_SPACE)) {
		len += 1;
	    }

	    if (!(flags & FL_LPAD)) {
		if (flags & FL_ZFILL) {
		    prec = c;
		    if (len < width) {
			prec += width - len;
			len = width;
		    }
		}
		while (len < width) {
		    putc (' ', stream);
		    len++;
		}
	    }

	    width =  (len < width) ? width - len : 0;

	    if (flags & FL_ALT) {
		putc ('0', stream);
		if (flags & FL_ALTHEX)
		    putc (flags & FL_ALTUPP ? 'X' : 'x', stream);
	    } else if (flags & (FL_NEGATIVE | FL_PLUS | FL_SPACE)) {
		unsigned char z = ' ';
		if (flags & FL_PLUS) z = '+';
		if (flags & FL_NEGATIVE) z = '-';
		putc (z, stream);
	    }

	    while (prec > c) {
		putc ('0', stream);
		prec--;
	    }

	    do {
		putc (buf[--c], stream);
	    } while (c);
	}

      tail:
	/* Tail is possible.	*/
	while (width) {
	    putc (' ', stream);
	    width--;
	}
    } /* for (;;) */

  ret:
    return stream->len;
}

#endif	/* PRINTF_LEVEL > PRINTF_MIN */

#endif /* !defined(__AVR_TINY__) */
