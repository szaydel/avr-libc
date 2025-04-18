/* Copyright (c) 2003, 2007 Reiner Patommel
   Copyright (c) 2007  Dmitry Xmelkov
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

#if !defined(__AVR_TINY__)

#if !defined(__DOXYGEN__)

#include "asmdef.h"

#define strp_lo	r24
#define dlm_lo	r22
#define str_lo	r20
#define chr	r19

#define ret_lo	r24

ENTRY _U(strsep_P)
  ; check a NULL pointer
	X_movw	ZL, strp_lo
	ld	XL, Z			; str address
	ldd	XH, Z+1
	X_movw	str_lo, XL		; save for return
	adiw	XL, 0
	breq	5f			; return NULL
  ; get a symbol from str
1:	ld	chr, X+
  ; scan delim[]
	X_movw	ZL, dlm_lo
2:	X_lpm	r0, Z+
	cp	r0, chr
	cpse	r0, __zero_reg__
	brne	2b	; if symbol is't match && no delim end
	brne	1b	; if symbol is absent in delim[] && not a zero
  ; chr is found in delim[] (possible, it is a terminating zero of str)
	tst	r0			; the same, as chr
	brne	3f
	X_movw	XL, r0			; __zero_reg__ is r1
	rjmp	4f
  ; OK, delimiter symbol is found
3:	st	-X, __zero_reg__	; replace by '\0'
	adiw	XL, 1			; address of next token
  ; save result to *sp and return
4:	X_movw	ZL, strp_lo
	st	Z, XL
	std	Z+1, XH
5:	X_movw	ret_lo, str_lo		; return original address
	ret

ENDFUNC
#endif /* not __DOXYGEN__ */

#endif /* !defined(__AVR_TINY__) */
