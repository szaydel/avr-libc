# Copyright (c) 2004,2005,2006,2007  Theodore A. Roth
# All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are met:
#
# * Redistributions of source code must retain the above copyright
#   notice, this list of conditions and the following disclaimer.
# * Redistributions in binary form must reproduce the above copyright
#   notice, this list of conditions and the following disclaimer in
#   the documentation and/or other materials provided with the
#   distribution.
# * Neither the name of the copyright holders nor the names of
#   contributors may be used to endorse or promote products derived
#   from this software without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
# AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
# IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
# ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
# LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
# CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
# SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
# INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
# CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
# ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
# POSSIBILITY OF SUCH DAMAGE.

avrdir = $(prefix)/avr/include/avr

avr_HEADERS = version.h @AVRLIBC_INCLUDE_HFILES@

EXTRA_HEADERS =

nodist_avr_HEADERS = \
    builtins.h

EXTRA_DIST = \
    builtins.h.in \
    version.h.in

do_subst = sed \
	-e 's,[@]AVR_LIBC_MAJOR[@],$(AVR_LIBC_MAJOR),g' \
	-e 's,[@]AVR_LIBC_MINOR[@],$(AVR_LIBC_MINOR),g' \
	-e 's,[@]AVR_LIBC_REVISION[@],$(AVR_LIBC_REVISION),g' \
	-e 's,[@]AVR_LIBC_RELDATE[@],$(AVR_LIBC_RELDATE),g' \
	-e 's,[@]AVR_LIBC_VERSION[@],$(AVR_LIBC_VERSION),g' \
	-e 's,[@]AVR_LIBC_VERSION_NUMERIC[@],$(AVR_LIBC_VERSION_NUMERIC),g'

version.h: version.h.in $(top_builddir)/config.h
	$(do_subst) < $(srcdir)/version.h.in > version.h

CLEANFILES = version.h
