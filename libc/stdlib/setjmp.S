/* Copyright (c) 2002, Marek Michalkiewicz
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



/*
   setjmp.S

   Contributors:
     Created by Marek Michalkiewicz <marekm@linux.org.pl>
 */

/*
   jmp_buf:
	offset	size	description
	 0	16/2	call-saved registers (r2-r17)
			(AVR_TINY arch has only 2 call saved registers (r18,r19))
	16/2	 2	frame pointer (r29:r28)
	18/4	 2	stack pointer (SPH:SPL)
	20/6	 1	status register (SREG)
	21/7	 2/3	return address (PC) (2 bytes used for <=128Kw flash)
	23/24/9 = total size (AVR_TINY arch always has 2 bytes PC)
   All multibytes are stored as little-endian.

   int setjmp(jmp_buf __jmpb);
   void longjmp(jmp_buf __jmpb, int __val) __attribute__((noreturn));
 */

#ifndef	__DOXYGEN__

#include "asmdef.h"

#define jmpb_hi	r25
#define jmpb_lo	r24
#define val_hi	r23
#define val_lo	r22

#define ret_lo	r24
#define ret_hi	r25

ENTRY _U(setjmp)
	X_movw	XL, jmpb_lo
  ; save call-saved registers and frame pointer
#if !defined(__AVR_TINY__)
	.irp	.L_regno, 2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,28,29
#else
	.irp	.L_regno, 18,19,28,29
#endif
	st	X+, r\.L_regno
	.endr
  ; get return address
#if  defined(__AVR_3_BYTE_PC__) && __AVR_3_BYTE_PC__
	pop	__tmp_reg__		; used below
#endif
	pop	ZH
	pop	ZL
  ; save stack pointer (after poping)
	in	ret_lo, SPL_IO_ADDR
	st	X+, ret_lo
#ifdef SPH_IO_ADDR
	in	ret_lo, SPH_IO_ADDR
	st	X+, ret_lo
#else
	st	X+, __zero_reg__
#endif
  ; save status register (I flag)
	in	ret_lo, SREG_IO_ADDR
	st	X+, ret_lo
  ; save return address
	st	X+, ZL
	st	X+, ZH
  ; return zero
	clr	ret_lo
	clr	ret_hi
#if  defined(__AVR_3_BYTE_PC__) && __AVR_3_BYTE_PC__
	st	X+, __tmp_reg__
	rjmp	.L_jmp3
#else
	ijmp
#endif
ENDFUNC


ENTRY _U(longjmp)
	X_movw	XL, jmpb_lo
  ; return value
	X_movw	ret_lo, val_lo
  ; if zero, change to 1
	cpi	ret_lo, 1
	cpc	ret_hi, __zero_reg__
	adc	ret_lo, __zero_reg__
  ; restore call-saved registers and frame pointer
#if !defined(__AVR_TINY__)
	.irp	.L_regno, 2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,28,29
#else
	.irp	.L_regno, 18,19,28,29
#endif
	ld	r\.L_regno, X+
	.endr
  ; restore stack pointer (SP value before the setjmp() call) and SREG
	ld	ZL, X+
	ld	ZH, X+
	ld	__tmp_reg__, X+
#if  defined (__AVR_XMEGA__) && __AVR_XMEGA__
	/* A write to SPL will automatically disable interrupts for up to 4
	   instructions or until the next I/O memory write.	*/
	out	SREG_IO_ADDR, __tmp_reg__
	out	SPL_IO_ADDR, ZL
	out	SPH_IO_ADDR, ZH
#else
# ifdef SPH_IO_ADDR
	/* interrupts disabled for shortest possible time (3 cycles) */
	cli
	out	SPH_IO_ADDR, ZH
# endif
	/* Restore status register (including the interrupt enable flag).
	   Interrupts are re-enabled only after the next instruction.  */
	out	SREG_IO_ADDR, __tmp_reg__
	out	SPL_IO_ADDR, ZL
#endif
  ; get return address and jump
	ld	ZL, X+
	ld	ZH, X+
#if  defined(__AVR_3_BYTE_PC__) && __AVR_3_BYTE_PC__
	ld	__tmp_reg__, X+
.L_jmp3:
	push	ZL
	push	ZH
	push	__tmp_reg__
	ret
#else
	ijmp
#endif

	.size	_U(longjmp), . - _U(longjmp)

#endif	/* !__DOXYGEN__ */
