/* Copyright (c) 2002  Michael Stumpf  <mistumpf@de.pepperl-fuchs.com>
   Copyright (c) 2006  Dmitry Xmelkov
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

#include "fp32def.h"
#include "asmdef.h"

/* float sinhf (float x);
     The sinhf() function returns the hyperbolic sine of x, which is
     defined mathematically as (exp(x) - exp(-x)) / 2.

   Notes:
     ldexpf() is used twice to avoid overflow for big x.
 */

#define	X2SMALL	0x3e9fffff	/* < 0.3125	*/

#define	exp_lo	r20		/* float ldexpf (float, int exp);	*/
#define	exp_hi	r21

ENTRY_FLOAT sinhf sinh sinhl
  ; save sign
	push	rA3
  ; is arg too small ?
	andi	rA3, 0x7f
	ldi	ZH,  hhi8 (X2SMALL + 1)
	cpi	rA2, hlo8 (X2SMALL + 1)
	cpc	rA3, ZH
	brsh	1f
  ; for small x
	ldi	ZL, lo8(.L_table)
	ldi	ZH, hi8(.L_table)
	LDI_XH_hh8(.L_table)
	XCALL	_U(__fp_powsodd)
	rjmp	2f
  ; expf(-fabsf(x))	// negative to exclude an extra inversion
1:	ori	rA3, 0x80
	XCALL	_U(expf)
  ; expf(-fabsf(x)) / 2
	ldi	exp_lo, lo8(-1)
	ldi	exp_hi, hi8(-1)
	XCALL	_U(ldexpf)
  ; save
	push	rA3
	push	rA2
	push	rA1
	push	rA0
  ; expf(fabsf(x)) / 2
	ldi	exp_lo, lo8(2)
	ldi	exp_hi, hi8(2)
	XCALL	_U(ldexpf)
	XCALL	_U(__inversef)
  ; result (in absolute value)
	pop	rB0
	pop	rB1
	pop	rB2
	pop	rB3
	XCALL	_U(__subsf3)
  ; set sign
2:	pop	r0
	sbrc	r0, 7
	ori	rA3, 0x80
	ret
ENDFUNC

	PGMX_SECTION(fplib.sinh)
OBJECT .L_table
	.byte	2
	.byte	     0x89,0x88,0x08,0x3c	; 1/120
	.byte	0xab,0xaa,0xaa,0x2a,0x3e	; 1/6
	.byte	0x00,0x00,0x00,0x80,0x3f	; 1
ENDOBJ .L_table

#endif /* !defined(__AVR_TINY__) */
