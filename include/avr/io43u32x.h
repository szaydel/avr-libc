/* Copyright (c) 2003,2005 Keith Gudger
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

/* avr/io43u32x.h - definitions for AT43USB32x */

#ifndef _AVR_IO43U32X_H_
#define _AVR_IO43U32X_H_ 1

/* This file should only be included from <avr/io.h>, never directly. */

#ifndef _AVR_IO_H_
#  error "Include <avr/io.h> instead of this file."
#endif

#ifndef _AVR_IOXXX_H_
#  define _AVR_IOXXX_H_ "io43u32x.h"
#else
#  error "Attempt to include more than one <avr/ioXXX.h> file."
#endif 

/* I/O registers */

/* Analog Comparator Control and Status Register */
#define ACSR	_SFR_IO8(0x08)

/* UART Baud Rate Register */
#define UBRR	_SFR_IO8(0x09)

/* UART Control Register */
#define UCR	_SFR_IO8(0x0A)

/* UART Status Register */
#define USR	_SFR_IO8(0x0B)

/* UART I/O Data Register */
#define UDR	_SFR_IO8(0x0C)

/* Input Pins, Port E */                  // new port for 43324/6
#define PINE	_SFR_IO8(0x01)

/* Data Direction Register, Port E */
#define DDRE	_SFR_IO8(0x02)

/* Data Register, Port E */
#define PORTE	_SFR_IO8(0x03) 

/* SPI Control Register */
#define SPCR	_SFR_IO8(0x0D)

/* SPI Status Register */
#define SPSR	_SFR_IO8(0x0E)

/* SPI I/O Data Register */
#define SPDR	_SFR_IO8(0x0F)

/* Input Pins, Port D */
#define PIND	_SFR_IO8(0x10)

/* Data Direction Register, Port D */
#define DDRD	_SFR_IO8(0x11)

/* Data Register, Port D */
#define PORTD	_SFR_IO8(0x12)

/* Input Pins, Port C */
#define PINC    _SFR_IO8(0x13)

/* Data Direction Register, Port C */
#define DDRC    _SFR_IO8(0x14)

/* Data Register, Port C */
#define PORTC	_SFR_IO8(0x15)

/* Input Pins, Port B */
#define PINB	_SFR_IO8(0x16)

/* Data Direction Register, Port B */
#define DDRB	_SFR_IO8(0x17)

/* Data Register, Port B */
#define PORTB	_SFR_IO8(0x18)

/* Input Pins, Port A */
#define PINA	_SFR_IO8(0x19)

/* Data Direction Register, Port A */
#define DDRA	_SFR_IO8(0x1A)

/* Data Register, Port A */
#define PORTA	_SFR_IO8(0x1B)

/* 0x1C..0x1F reserved */

/* Watchdog Timer Control Register */
#define WDTCR	_SFR_IO8(0x21)

/* T/C 1 Input Capture Register */
#define ICR1	_SFR_IO16(0x24)
#define ICR1L	_SFR_IO8(0x24)
#define ICR1H	_SFR_IO8(0x25)

/* Timer/Counter1 Output Compare Register B */
#define OCR1B	_SFR_IO16(0x28)
#define OCR1BL	_SFR_IO8(0x28)
#define OCR1BH	_SFR_IO8(0x29)

/* Timer/Counter1 Output Compare Register A */
#define OCR1A	_SFR_IO16(0x2A)
#define OCR1AL	_SFR_IO8(0x2A)
#define OCR1AH	_SFR_IO8(0x2B)

/* Timer/Counter 1 */
#define TCNT1	_SFR_IO16(0x2C)
#define TCNT1L	_SFR_IO8(0x2C)
#define TCNT1H	_SFR_IO8(0x2D)

/* Timer/Counter 1 Control and Status Register */
#define TCCR1B	_SFR_IO8(0x2E)

/* Timer/Counter 1 Control Register */
#define TCCR1A	_SFR_IO8(0x2F)

/* Timer/Counter 0 */
#define TCNT0	_SFR_IO8(0x32)

/* Timer/Counter 0 Control Register */
#define TCCR0	_SFR_IO8(0x33)

/* MCU general Control Register */
#define MCUCR	_SFR_IO8(0x35)

/* Timer/Counter Interrupt Flag Register */
#define TIFR	_SFR_IO8(0x38)

/* Timer/Counter Interrupt MaSK register */
#define TIMSK	_SFR_IO8(0x39)

/* General Interrupt Control Register */
#define GIFR	_SFR_IO8(0x3A)

/* General Interrupt Mask register */
#define GIMSK	_SFR_IO8(0x3B)

/* Interrupt vectors */

#define SIG_INTERRUPT0		_VECTOR(1)
#define SIG_INTERRUPT1		_VECTOR(2)
#define SIG_TIMER1_CAPT1	_VECTOR(3)
#define SIG_INPUT_CAPTURE1	_VECTOR(3)
#define SIG_OUTPUT_COMPARE1A		_VECTOR(4)
#define SIG_OUTPUT_COMPARE1B		_VECTOR(5)
#define SIG_OVERFLOW1		_VECTOR(6)
#define SIG_OVERFLOW0		_VECTOR(7)
#define SIG_SPI				_VECTOR(8)
#define SIG_UART_RECV		_VECTOR(9)
#define SIG_UART_DATA    	_VECTOR(10)
#define SIG_UART_TRANS     	_VECTOR(11)
#define SIG_USB_INT         _VECTOR(12)

#define _VECTORS_SIZE 52

/*
   The Register Bit names are represented by their bit number (0-7).
*/

/* Timer/Counter Interrupt MaSK register */
#define    TICIE1       3
#define    OCIE1A       6
#define    OCIE1B       5
#define    TOIE1        7
#define    TOIE0        1

/* Timer/Counter Interrupt Flag Register */
#define    ICF1         3
#define    OCF1A        6
#define    OCF1B        5
#define    TOV1         7
#define    TOV0         1

/* MCU general Control Register */
#define    SE           5
#define    SM           4
#define    ISC11        3
#define    ISC10        2
#define    ISC01        1
#define    ISC00        0

/* Timer/Counter 0 Control Register */
#define    CS02         2
#define    CS01         1
#define    CS00         0


/* Timer/Counter 1 Control Register */
#define    COM1A1       7
#define    COM1A0       6
#define    COM1B1       5
#define    COM1B0       4
#define    PWM11        1
#define    PWM10        0

/* Timer/Counter 1 Control and Status Register */
#define    ICNC1        7
#define    ICES1        6
#define    CTC1         3
#define    CS12         2
#define    CS11         1
#define    CS10         0

/* Watchdog Timer Control Register */
#define    WDTOE        4
#define    WDE          3
#define    WDP2         2
#define    WDP1         1
#define    WDP0         0

/* Data Register, Port A */
#define    PA7          7
#define    PA6          6
#define    PA5          5
#define    PA4          4
#define    PA3          3
#define    PA2          2
#define    PA1          1
#define    PA0          0

/* Data Direction Register, Port A */
#define    DDA7         7
#define    DDA6         6
#define    DDA5         5
#define    DDA4         4
#define    DDA3         3
#define    DDA2         2
#define    DDA1         1
#define    DDA0         0

/* Input Pins, Port A */
#define    PINA7        7
#define    PINA6        6
#define    PINA5        5
#define    PINA4        4
#define    PINA3        3
#define    PINA2        2
#define    PINA1        1
#define    PINA0        0

/* Data Register, Port B */
#define    PB7          7
#define    PB6          6
#define    PB5          5
#define    PB4          4
#define    PB3          3
#define    PB2          2
#define    PB1          1
#define    PB0          0

/* Data Direction Register, Port B */
#define    DDB7         7
#define    DDB6         6
#define    DDB5         5
#define    DDB4         4
#define    DDB3         3
#define    DDB2         2
#define    DDB1         1
#define    DDB0         0

/* Input Pins, Port B */
#define    PINB7        7
#define    PINB6        6
#define    PINB5        5
#define    PINB4        4
#define    PINB3        3
#define    PINB2        2
#define    PINB1        1
#define    PINB0        0

/* Data Direction Register, Port C */
#define    DDC7         7
#define    DDC6         6
#define    DDC5         5
#define    DDC4         4
#define    DDC3         3
#define    DDC2         2
#define    DDC1         1
#define    DDC0         0

/* Input Pins, Port C */
#define    PINC7        7
#define    PINC6        6
#define    PINC5        5
#define    PINC4        4
#define    PINC3        3
#define    PINC2        2
#define    PINC1        1
#define    PINC0        0

/* Data Register, Port C */
#define    PC7          7
#define    PC6          6
#define    PC5          5
#define    PC4          4
#define    PC3          3
#define    PC2          2
#define    PC1          1
#define    PC0          0

/* Data Register, Port D */
#define    PD7          7
#define    PD6          6
#define    PD5          5
#define    PD4          4
#define    PD3          3
#define    PD2          2
#define    PD1          1
#define    PD0          0

/* Data Direction Register, Port D */
#define    DDD7         7
#define    DDD6         6
#define    DDD5         5
#define    DDD4         4
#define    DDD3         3
#define    DDD2         2
#define    DDD1         1
#define    DDD0         0

/* Input Pins, Port D */
#define    PIND7        7
#define    PIND6        6
#define    PIND5        5
#define    PIND4        4
#define    PIND3        3
#define    PIND2        2
#define    PIND1        1
#define    PIND0        0

/* Data Register, Port E */
#define    PE7          7
#define    PE6          6
#define    PE5          5
#define    PE4          4
#define    PE3          3
#define    PE2          2
#define    PE1          1
#define    PE0          0

/* Data Direction Register, Port E */
#define    DDE7         7
#define    DDE6         6
#define    DDE5         5
#define    DDE4         4
#define    DDE3         3
#define    DDE2         2
#define    DDE1         1
#define    DDE0         0

/* Input Pins, Port E */
#define    PINE7        7
#define    PINE6        6
#define    PINE5        5
#define    PINE4        4
#define    PINE3        3
#define    PINE2        2
#define    PINE1        1
#define    PINE0        0

/* SPI Status Register */
#define    SPIF         7
#define    WCOL         6

/* SPI Control Register */
#define    SPIE         7
#define    SPE          6
#define    DORD         5
#define    MSTR         4
#define    CPOL         3
#define    CPHA         2
#define    SPR1         1
#define    SPR0         0

/* UART Status Register */
#define    RXC          7
#define    TXC          6
#define    UDRE         5
#define    FE           4
#define    DOR          3

/* UART Control Register */
#define    RXCIE        7
#define    TXCIE        6
#define    UDRIE        5
#define    RXEN         4
#define    TXEN         3
#define    CHR9         2
#define    RXB8         1
#define    TXB8         0

/* Constants */
#define    RAMSTART 0x60
#define    RAMEND   0x025F     /*Last On-Chip SRAM Location*/
#define    XRAMEND  RAMEND
#define    E2END    0x0000

/* FIXME: should be 0x1FFFF for max 128K (64K*16) external program memory,
   but no RAMPZ causes gcrt1.S build to fail, so assume 64K for now...  */
#define    FLASHEND 0x0FFFF

#define SLEEP_MODE_IDLE         0
#define SLEEP_MODE_PWR_DOWN     _BV(SM)


#endif /* _AVR_43USB32X_H_ */
