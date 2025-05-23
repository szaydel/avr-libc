/* Copyright (c) 2005, Dmitry Xmelkov
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

#ifndef	_XTOA_FAST_H_
#define _XTOA_FAST_H_

#ifndef	__ASSEMBLER__

#include <stddef.h>	/* for 'size_t'	*/

char * itoa_fast (int val, char *s, int base);
char * utoa_fast (unsigned val, char *s, int base);
char * ltoa_fast (long val, char *s, int base);
char * ultoa_fast (unsigned long val, char *s, int base);

char * itoa_width (int val, char *s, int base, size_t width);
char * utoa_width (unsigned val, char *s, int base, size_t width);
char * ltoa_width (long val, char *s, int base, size_t width);
char * ultoa_width (unsigned long val, char *s, int base, size_t width);

/* Internal function for use from `printf'.	*/
char * __ultoa_invert (unsigned long val, char *s, int base);

#endif	/* ifndef __ASSEMBLER__ */

/* Next flags are to use with `base'. Unused fields are reserved.	*/
#define XTOA_PREFIX	0x0100	/* put prefix for octal or hex	*/
#define XTOA_UPPER	0x0200	/* use upper case letters	*/

#endif	/* _XTOA_FAST_H_ */
