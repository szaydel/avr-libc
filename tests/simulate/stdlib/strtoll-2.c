/* Copyright (c) 2007  Dmitry Xmelkov
   Copyright (c) 2025  Georg-Johann Lay
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

/* Overflow. */
#include <stdlib.h>
#include "strtoll.h"

int main (void)
{
    static struct t_s
    {
	char s[14];		/* string to convert	*/
	int base;
	long long ret;		/* result must	*/
	int err;		/* errno must	*/
	unsigned char len;	/* endptr displacement must	*/
    } t[] = {

	{ "2147483647", 0,	0x7fffffff, 0, 10 },
	{ "0x7fffffff", 0,	0x7fffffff, 0, 10 },
	{ "017777777777", 0,	0x7fffffff, 0, 12 },
	{ "2147483648", 0,	0x80000000LL, 0, 10 },
	{ "0x80000000", 0,	0x80000000LL, 0, 10 },
	{ "020000000000", 0,	0x80000000LL, 0, 12 },

	{ "-2147483647", 0,	-0x7fffffffLL, 0, 11 },
	{ "-0x7fffffff", 0,	-0x7fffffffLL, 0, 11 },
	{ "-017777777777", 0,	-0x7fffffffLL, 0, 13 },
	{ "-2147483648", 0,	-0x80000000LL, 0, 11 },
	{ "-0x80000000", 0,	-0x80000000LL, 0, 11 },
	{ "-020000000000", 0,	-0x80000000LL, 0, 13 },
	{ "-2147483649", 0,	-0x80000001LL, 0, 11 },
	{ "-0x80000001", 0,	-0x80000001LL, 0, 11 },
	{ "-020000000001", 0,	-0x80000001LL, 0, 13 },
    };

    for (int i = 0; i != ARRAY_SIZE (t); i++)
    {
	struct t_s *p = t + i;
	if (t_strtoll (p->s, p->base, p->ret, p->err, p->len))
	    exit (i + 1);
    }
    return 0;
}
