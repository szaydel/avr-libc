/* Copyright (c) 2002, 2007 Marek Michalkiewicz
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

#if !defined(__DOXYGEN__)

#include "asmdef.h"

TINY_WEAK_ALIAS _U(strcat_P) _U(strcat)

#define dest_hi r25
#define dest_lo r24
#define src_hi r23
#define src_lo r22

ENTRY _U(strcat)
	X_movw	ZL, src_lo
	X_movw	XL, dest_lo
.L_strcat_skip:
	ld	__tmp_reg__, X+
	tst	__tmp_reg__
	brne	.L_strcat_skip
	; undo post-increment
#if !defined(__AVR_TINY__)
	sbiw	XL, 1
#else
	ld	__tmp_reg__, -X
#endif /* !__AVR_TINY__ */
.L_strcat_loop:
	ld	__tmp_reg__, Z+
	st	X+, __tmp_reg__
	tst	__tmp_reg__
	brne	.L_strcat_loop
; return dest (unchanged)
	ret
ENDFUNC

#endif /* not __DOXYGEN__ */
