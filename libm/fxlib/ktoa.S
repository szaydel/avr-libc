/* Copyright (c) 2025  Georg-Johann Lay
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
   POSSIBILITY OF SUCH DAMAGE.  */

#ifndef __AVR_TINY__

#include "asmdef.h"

;; The argument registers as of avr-gcc ABI.
#define A0      22
#define A1      A0+1
#define A2      A0+2
#define A3      A0+3
#define pBufArg 20
#define Mode    18

;; Passed from the signed routines: 0 or '-'.
#define Sign    r27

;;; char* R24 = ktoa (accum R20, char *R20, uint8_t R18)
;;; char* R24 = ktoa (accum A[], char *,    uint8_t Mode)
;;; bool Mode.7 specifies whether to truncate instead of round.
;;; bool Mode.6 specifies whether no trailing zeros is in effect.
;;; bool Mode.5 specifies a comma as decimal point instead of a dot.
;;; uint8_t Mode.4..0 == 31:  Print ALL digits.
;;;         Mode.4..0 != 31:  Specifies the rounding point resp. the
;;;                           number of fractional digits.
ENTRY ktoa
    tst     A3
    brpl .Lpos
    ldi     Sign, '-'
    XCALL   _U(__negsi2)        ; libgcc
    brvc .Ltouk

    ;; Now this is annoying: We have to emit -65536, which is not
    ;; representable as unsigned accum.
    X_movw  r30, pBufArg
    st      Z+, Sign
    X_movw  pBufArg, r30
    ldi     Sign, '6'
    ;; A0 and A1 are already 0.
    ldi     A2, hlo8(5536 << 16)
    ldi     A3, hhi8(5536 << 16)
    XCALL   _U(uktoa.sign)
    X_sbiw  r24, 1
    ret

.Lpos:
    clr     Sign
.Ltouk:
    lsl     A0
    rol     A1
    rol     A2
    rol     A3
    XJMP    _U(uktoa.sign)
ENDFUNC

#endif /* !AVR_TINY */
