/* Copyright (c) 2007  Dmitry Xmelkov
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

/* Test of tanh() function. ULP control. */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "progmem.h"

union lofl_u {
    long lo;
    float fl;
};

volatile union lofl_u v = { .lo = 1 };

PROGMEM const struct {		/* Table of test cases.	*/
    union lofl_u x;		/* argument	*/
    union lofl_u z;		/* tanh(x)	*/
    unsigned int maxulp;	/* max possible error in ULP	*/
} t[] = {

    { { .fl= 0 },	{ .fl= 0 },	0 },
    { { 0x3a000000 },	{ 0x39ffffff },		1 },
    { { 0x3b000000 },	{ 0x3affffeb },		1 },
    { { 0x3e0ffffe },	{ 0x3e0f0ee6 },		4 },
    { { 0x3e0fffff },	{ 0x3e0f0ee7 },		4 },
    { { 0x3e100000 },	{ 0x3e0f0ee8 },		3 },	/* .140625	*/
    { { 0x3e100001 },	{ 0x3e0f0ee9 },		3 },
    { { .fl= 0.25 },	{ .fl= .24491866 },	1 },
    { { .fl= 0.5 },	{ .fl= .46211716 },	1 },
    { { .fl= 1 },	{ .fl= .76159416 },	1 },
    { { .fl= 2 },	{ .fl= .96402758 },	1 },
    { { .fl= 5 },	{ .fl= .99990920 },	1 },
    { { .fl= 10 },	{ .fl= 1.0 },	0 },
};

void x_exit (int index)
{
#ifndef	__AVR__
    fprintf (stderr, "t[%d]:  %#lx\n", index - 1, v.lo);
#endif
    exit (index ? index : -1);
}

int main ()
{
    union lofl_u x, z;
    unsigned int maxulp;
    unsigned long v1, z1, r;
    int i;
    
    for (i = 0; i < (int) (sizeof(t) / sizeof(t[0])); i++) {
	x.lo = pgm_read_dword (& t[i].x);
	z.lo = pgm_read_dword (& t[i].z);
	maxulp = pgm_read_word (& t[i].maxulp);
	v.fl = tanh (x.fl);
	
	v1 = (v.lo < 0) ? (unsigned long)~(v.lo) : v.lo + 0x80000000;
	z1 = (z.lo < 0) ? (unsigned long)~(z.lo) : z.lo + 0x80000000;
	r = (v1 >= z1) ? v1 - z1 : z1 - v1;
	
	if (r > maxulp) x_exit (i+1);
    }
    return 0;
}
