/*
 * Copyright (C) 2022, Microchip Technology Inc. and its subsidiaries ("Microchip")
 * All rights reserved.
 *
 * This software is developed by Microchip Technology Inc. and its subsidiaries ("Microchip").
 *
 * Redistribution and use in source and binary forms, with or without modification, are
 * permitted provided that the following conditions are met:
 *
 *     1. Redistributions of source code must retain the above copyright notice, this list of
 *        conditions and the following disclaimer.
 *
 *     2. Redistributions in binary form must reproduce the above copyright notice, this list
 *        of conditions and the following disclaimer in the documentation and/or other
 *        materials provided with the distribution. Publication is not required when
 *        this file is used in an embedded application.
 *
 *     3. Microchip's name may not be used to endorse or promote products derived from this
 *        software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY MICROCHIP "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
 * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL MICROCHIP BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING BUT NOT LIMITED TO
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWSOEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef _AVR_ATA5787_H_INCLUDED
#define _AVR_ATA5787_H_INCLUDED


#ifndef _AVR_IO_H_
#  error "Include <avr/io.h> instead of this file."
#endif

#ifndef _AVR_IOXXX_H_
#  define _AVR_IOXXX_H_ "ioa5787.h"
#else
#  error "Attempt to include more than one <avr/ioXXX.h> file."
#endif

/* Registers and associated bit numbers */

#define PRR0    _SFR_IO8(0x01)
#define PRSPI   0
#define PRRXDC  1
#define PRTXDC  2
#define PRCRC   3
#define PRVM    4
#define PRCO    5
#define PRUART  6
#define PRTRC   7

#define __AVR_HAVE_PRR0	((1<<PRSPI)|(1<<PRRXDC)|(1<<PRTXDC)|(1<<PRCRC)|(1<<PRVM)|(1<<PRCO)|(1<<PRUART)|(1<<PRTRC))
#define __AVR_HAVE_PRR0_PRSPI
#define __AVR_HAVE_PRR0_PRRXDC
#define __AVR_HAVE_PRR0_PRTXDC
#define __AVR_HAVE_PRR0_PRCRC
#define __AVR_HAVE_PRR0_PRVM
#define __AVR_HAVE_PRR0_PRCO
#define __AVR_HAVE_PRR0_PRUART
#define __AVR_HAVE_PRR0_PRTRC

#define PRR1    _SFR_IO8(0x02)
#define PRT1    0
#define PRT2    1
#define PRT3    2
#define PRT4    3
#define PRT5    4

#define __AVR_HAVE_PRR1	((1<<PRT1)|(1<<PRT2)|(1<<PRT3)|(1<<PRT4)|(1<<PRT5))
#define __AVR_HAVE_PRR1_PRT1
#define __AVR_HAVE_PRR1_PRT2
#define __AVR_HAVE_PRR1_PRT3
#define __AVR_HAVE_PRR1_PRT4
#define __AVR_HAVE_PRR1_PRT5

#define PRR2    _SFR_IO8(0x03)
#define PRXB    0
#define PRXA    1
#define PRSF    2
#define PRDF    3
#define PRIDS   4
#define PRRS    5
#define PRSSM   7

#define __AVR_HAVE_PRR2	((1<<PRXB)|(1<<PRXA)|(1<<PRSF)|(1<<PRDF)|(1<<PRIDS)|(1<<PRRS)|(1<<PRSSM))
#define __AVR_HAVE_PRR2_PRXB
#define __AVR_HAVE_PRR2_PRXA
#define __AVR_HAVE_PRR2_PRSF
#define __AVR_HAVE_PRR2_PRDF
#define __AVR_HAVE_PRR2_PRIDS
#define __AVR_HAVE_PRR2_PRRS
#define __AVR_HAVE_PRR2_PRSSM

#define RDPR    _SFR_IO8(0x04)
#define PRPTB   0
#define PRPTA   1
#define PRFLT   2
#define PRTMP   3
#define APRPTB  4
#define APRPTA  5
#define ARDPRF  6
#define RDPRF   7

#define PINB    _SFR_IO8(0x05)
#define PINB7   7
#define PINB6   6
#define PINB5   5
#define PINB4   4
#define PINB3   3
#define PINB2   2
#define PINB1   1
#define PINB0   0

#define DDRB    _SFR_IO8(0x06)
#define DDRB7   7
// Inserted "DDB7" from "DDRB7" due to compatibility
#define DDB7    7
#define DDRB6   6
// Inserted "DDB6" from "DDRB6" due to compatibility
#define DDB6    6
#define DDRB5   5
// Inserted "DDB5" from "DDRB5" due to compatibility
#define DDB5    5
#define DDRB4   4
// Inserted "DDB4" from "DDRB4" due to compatibility
#define DDB4    4
#define DDRB3   3
// Inserted "DDB3" from "DDRB3" due to compatibility
#define DDB3    3
#define DDRB2   2
// Inserted "DDB2" from "DDRB2" due to compatibility
#define DDB2    2
#define DDRB1   1
// Inserted "DDB1" from "DDRB1" due to compatibility
#define DDB1    1
#define DDRB0   0
// Inserted "DDB0" from "DDRB0" due to compatibility
#define DDB0    0

#define PORTB   _SFR_IO8(0x07)
#define PORTB7  7
#define PORTB6  6
#define PORTB5  5
#define PORTB4  4
#define PORTB3  3
#define PORTB2  2
#define PORTB1  1
#define PORTB0  0

#define PINC    _SFR_IO8(0x08)
#define PINC5   5
#define PINC4   4
#define PINC3   3
#define PINC2   2
#define PINC1   1
#define PINC0   0

#define DDRC    _SFR_IO8(0x09)
#define DDRC5   5
// Inserted "DDC5" from "DDRC5" due to compatibility
#define DDC5    5
#define DDRC4   4
// Inserted "DDC4" from "DDRC4" due to compatibility
#define DDC4    4
#define DDRC3   3
// Inserted "DDC3" from "DDRC3" due to compatibility
#define DDC3    3
#define DDRC2   2
// Inserted "DDC2" from "DDRC2" due to compatibility
#define DDC2    2
#define DDRC1   1
// Inserted "DDC1" from "DDRC1" due to compatibility
#define DDC1    1
#define DDRC0   0
// Inserted "DDC0" from "DDRC0" due to compatibility
#define DDC0    0

#define PORTC   _SFR_IO8(0x0A)
#define PORTC5  5
#define PORTC4  4
#define PORTC3  3
#define PORTC2  2
#define PORTC1  1
#define PORTC0  0

/* Reserved [0x0B..0x0C] */

#define RDSIFR  _SFR_IO8(0x0D)
#define NBITA   0
#define NBITB   1
#define EOTA    2
#define EOTB    3
#define SOTA    4
#define SOTB    5
#define WCOA    6
#define WCOB    7

#define MCUCR   _SFR_IO8(0x0E)
#define IVCE    0
#define IVSEL   1
#define SPIIO   2
#define ENPS    3
#define PUD     4
#define PB4HS   5
#define PB7LS   6
#define PB7HS   7

#define PCIFR   _SFR_IO8(0x0F)
#define PCIF0   0
#define PCIF1   1

#define T0CR    _SFR_IO8(0x10)
#define T0PS0   0
#define T0PS1   1
#define T0PS2   2
#define T0IE    3
#define T0PR    4

#define T1CR    _SFR_IO8(0x11)
#define T1OTM   0
#define T1CTM   1
#define T1CRM   2
#define T1TOP   4
#define T1RES   5
#define T1TOS   6
#define T1ENA   7

#define T2CR    _SFR_IO8(0x12)
#define T2OTM   0
#define T2CTM   1
#define T2CRM   2
#define T2TOP   4
#define T2RES   5
#define T2TOS   6
#define T2ENA   7

#define T3CR    _SFR_IO8(0x13)
#define T3OTM   0
#define T3CTM   1
#define T3CRM   2
#define T3CPRM  3
#define T3TOP   4
#define T3RES   5
#define T3TOS   6
#define T3ENA   7

#define T4CR    _SFR_IO8(0x14)
#define T4OTM   0
#define T4CTM   1
#define T4CRM   2
#define T4CPRM  3
#define T4TOP   4
#define T4RES   5
#define T4TOS   6
#define T4ENA   7

#define T1IFR   _SFR_IO8(0x15)
#define T1OFF   0
#define T1COF   1

#define T2IFR   _SFR_IO8(0x16)
#define T2OFF   0
#define T2COF   1

#define T3IFR   _SFR_IO8(0x17)
#define T3OFF   0
#define T3COF   1
#define T3ICF   2

#define T4IFR   _SFR_IO8(0x18)
#define T4OFF   0
#define T4COF   1
#define T4ICF   2

#define T5IFR   _SFR_IO8(0x19)
#define T5OFF   0
#define T5COF   1

#define GPIOR0  _SFR_IO8(0x1A)

#define GPIOR3  _SFR_IO8(0x1B)

#define GPIOR4  _SFR_IO8(0x1C)

#define GPIOR5  _SFR_IO8(0x1D)

#define GPIOR6  _SFR_IO8(0x1E)

#define EECR    _SFR_IO8(0x1F)
#define EERE    0
#define EEWE    1
#define EEMWE   2
#define EERIE   3
#define EEPM0   4
#define EEPM1   5
#define EEPAGE  6
#define NVMBSY  7

#define EEDR    _SFR_IO8(0x20)

/* Combine EEARL and EEARH */
#define EEAR    _SFR_IO16(0x21)

#define EEARL   _SFR_IO8(0x21)
#define EEARH   _SFR_IO8(0x22)

#define EEPR    _SFR_IO8(0x23)
#define EEAP0   0
#define EEAP1   1
#define EEAP2   2
#define EEAP3   3

#define GPIOR1  _SFR_IO8(0x24)

#define GPIOR2  _SFR_IO8(0x25)

#define PCICR   _SFR_IO8(0x26)
#define PCIE0   0
#define PCIE1   1

#define EIMSK   _SFR_IO8(0x27)
#define INT0    0
#define INT1    1

#define EIFR    _SFR_IO8(0x28)
#define INTF0   0
#define INTF1   1

#define CRCDIR  _SFR_IO8(0x29)

#define VMCSR   _SFR_IO8(0x2A)
#define VMLS0   0
#define VMLS1   1
#define VMLS2   2
#define VMLS3   3
#define VMIM    4
#define VMF     5

#define MCUSR   _SFR_IO8(0x2B)
#define PORF    0
#define EXTRF   1
#define WDRF    3
#define DWRF    4

#define SPCR    _SFR_IO8(0x2C)
#define SPR0    0
#define SPR1    1
#define CPHA    2
#define CPOL    3
#define MSTR    4
#define DORD    5
#define SPE     6
#define SPIE    7

#define SPSR    _SFR_IO8(0x2D)
#define SPI2X   0
#define RXIF    4
#define TXIF    5
#define SPIF    7

#define SPDR    _SFR_IO8(0x2E)

#define T0IFR   _SFR_IO8(0x2F)
#define T0F     0

/* Reserved [0x30] */

#define DWDR    _SFR_IO8(0x31)

#define RDCR    _SFR_IO8(0x32)
#define RDPU    0
#define ADIVEN  1
#define RDEN    2

#define EOTSA   _SFR_IO8(0x33)
#define CARFA   0
#define AMPFA   1
#define SYTFA   2
#define MANFA   3
#define TMOFA   4
#define TELRA   5
#define RRFA    6
#define EOTBF   7

#define EOTCA   _SFR_IO8(0x34)
#define CARFEA  0
#define AMPFEA  1
#define SYTFEA  2
#define MANFEA  3
#define TMOFEA  4
#define TELREA  5
#define RRFEA   6
#define EOTBFE  7

#define EOTSB   _SFR_IO8(0x35)
#define CARFB   0
#define AMPFB   1
#define SYTFB   2
#define MANFB   3
#define TMOFB   4
#define TELRB   5
#define RRFB    6
#define EOTAF   7

#define EOTCB   _SFR_IO8(0x36)
#define CARFEB  0
#define AMPFEB  1
#define SYTFEB  2
#define MANFEB  3
#define TMOFEB  4
#define TELREB  5
#define RRFEB   6
#define EOTAFE  7

#define SPMCSR  _SFR_IO8(0x37)
#define SELFPRGEN 0
#define PGERS   1
#define PGWRT   2
#define BLBSET  3
#define SPMIE   7

/* Reserved [0x38] */

#define SMCR    _SFR_IO8(0x39)
#define SE      0
#define SM0     1
#define SM1     2

#define CMCR    _SFR_IO8(0x3A)
#define CMM0    0
#define CMM1    1
#define CMM2    2
#define CCS     3
#define CMONEN  6
#define CMCCE   7

#define CMIMR   _SFR_IO8(0x3B)
#define ECIE    0

#define CLPR    _SFR_IO8(0x3C)
#define CLKPS0  0
#define CLKPS1  1
#define CLKPS2  2
#define CLTPS0  3
#define CLTPS1  4
#define CLTPS2  5
#define CLPCE   7

/* SP [0x3D..0x3E] */

/* SREG [0x3F] */

#define FSEN    _SFR_MEM8(0x60)
#define SDPU    0
#define SDEN    1

/* Reserved [0x61..0x63] */

#define FFREQ1L _SFR_MEM8(0x64)

#define FFREQ1M _SFR_MEM8(0x65)

#define FFREQ1H _SFR_MEM8(0x66)

#define FFREQ2L _SFR_MEM8(0x67)

#define FFREQ2M _SFR_MEM8(0x68)

#define FFREQ2H _SFR_MEM8(0x69)

/* Reserved [0x6A] */

#define EICRA   _SFR_MEM8(0x6B)
#define ISC00   0
#define ISC01   1
#define ISC10   2
#define ISC11   3

#define PCMSK0  _SFR_MEM8(0x6C)
#define PCINT0  0
#define PCINT1  1
#define PCINT2  2
#define PCINT3  3
#define PCINT4  4
#define PCINT5  5
#define PCINT6  6
#define PCINT7  7

#define PCMSK1  _SFR_MEM8(0x6D)
#define PCINT8  0
#define PCINT9  1
#define PCINT10 2
#define PCINT11 3
#define PCINT12 4
#define PCINT13 5

#define WDTCR   _SFR_MEM8(0x6E)
#define WDPS0   0
#define WDPS1   1
#define WDPS2   2
#define WDE     3
#define WDCE    4

#define T1CNT   _SFR_MEM8(0x6F)

#define T1COR   _SFR_MEM8(0x70)

#define T1MR    _SFR_MEM8(0x71)
#define T1CS0   0
#define T1CS1   1
#define T1PS0   2
#define T1PS1   3
#define T1PS2   4
#define T1PS3   5
#define T1DC0   6
#define T1DC1   7

#define T1IMR   _SFR_MEM8(0x72)
#define T1OIM   0
#define T1CIM   1

#define T2CNT   _SFR_MEM8(0x73)

#define T2COR   _SFR_MEM8(0x74)

#define T2MR    _SFR_MEM8(0x75)
#define T2CS0   0
#define T2CS1   1
#define T2PS0   2
#define T2PS1   3
#define T2PS2   4
#define T2PS3   5
#define T2DC0   6
#define T2DC1   7

#define T2IMR   _SFR_MEM8(0x76)
#define T2OIM   0
#define T2CIM   1

/* Combine T3CNTL and T3CNTH */
#define T3CNT   _SFR_MEM16(0x77)

#define T3CNTL  _SFR_MEM8(0x77)
#define T3CNTH  _SFR_MEM8(0x78)

/* Combine T3CORL and T3CORH */
#define T3COR   _SFR_MEM16(0x79)

#define T3CORL  _SFR_MEM8(0x79)
#define T3CORH  _SFR_MEM8(0x7A)

/* Combine T3ICRL and T3ICRH */
#define T3ICR   _SFR_MEM16(0x7B)

#define T3ICRL  _SFR_MEM8(0x7B)
#define T3ICRH  _SFR_MEM8(0x7C)

#define T3MRA   _SFR_MEM8(0x7D)
#define T3CS0   0
#define T3CS1   1
#define T3PS0   2
#define T3PS1   3
#define T3PS2   4

#define T3MRB   _SFR_MEM8(0x7E)
#define T3SCE   1
#define T3CNC   2
#define T3CE0   3
#define T3CE1   4
#define T3ICS0  5
#define T3ICS1  6
#define T3ICS2  7

#define T3IMR   _SFR_MEM8(0x7F)
#define T3OIM   0
#define T3CIM   1
#define T3CPIM  2

/* Combine T4CNTL and T4CNTH */
#define T4CNT   _SFR_MEM16(0x80)

#define T4CNTL  _SFR_MEM8(0x80)
#define T4CNTH  _SFR_MEM8(0x81)

/* Combine T4CORL and T4CORH */
#define T4COR   _SFR_MEM16(0x82)

#define T4CORL  _SFR_MEM8(0x82)
#define T4CORH  _SFR_MEM8(0x83)

/* Combine T4ICRL and T4ICRH */
#define T4ICR   _SFR_MEM16(0x84)

#define T4ICRL  _SFR_MEM8(0x84)
#define T4ICRH  _SFR_MEM8(0x85)

#define T4MRA   _SFR_MEM8(0x86)
#define T4CS0   0
#define T4CS1   1
#define T4PS0   2
#define T4PS1   3
#define T4PS2   4

#define T4MRB   _SFR_MEM8(0x87)
#define T4SCE   1
#define T4CNC   2
#define T4CE0   3
#define T4CE1   4
#define T4ICS0  5
#define T4ICS1  6
#define T4ICS2  7

#define T4IMR   _SFR_MEM8(0x88)
#define T4OIM   0
#define T4CIM   1
#define T4CPIM  2

/* Reserved [0x89] */

/* Combine T5OCRL and T5OCRH */
#define T5OCR   _SFR_MEM16(0x8A)

#define T5OCRL  _SFR_MEM8(0x8A)
#define T5OCRH  _SFR_MEM8(0x8B)

#define T5CCR   _SFR_MEM8(0x8C)
#define T5CS0   0
#define T5CS1   1
#define T5CS2   2
#define T5CTC   3

/* Combine T5CNTL and T5CNTH */
#define T5CNT   _SFR_MEM16(0x8D)

#define T5CNTL  _SFR_MEM8(0x8D)
#define T5CNTH  _SFR_MEM8(0x8E)

#define T5IMR   _SFR_MEM8(0x8F)
#define T5OIM   0
#define T5CIM   1

#define GTCCR   _SFR_MEM8(0x90)
#define PSR10   0
#define TSM     7

#define SOTSB   _SFR_MEM8(0x91)
#define CAROB   0
#define AMPOB   1
#define SYTOB   2
#define MANOB   3
#define WUPOB   4
#define SFIDOB  5
#define RROB    6
#define WCOAO   7

#define SOTSA   _SFR_MEM8(0x92)
#define CAROA   0
#define AMPOA   1
#define SYTOA   2
#define MANOA   3
#define WUPOA   4
#define SFIDOA  5
#define RROA    6
#define WCOBO   7

#define SOTCB   _SFR_MEM8(0x93)
#define CAROEB  0
#define AMPOEB  1
#define SYTOEB  2
#define MANOEB  3
#define WUPEB   4
#define SFIDEB  5
#define RROEB   6
#define WCOAOE  7

#define SOTCA   _SFR_MEM8(0x94)
#define CAROEA  0
#define AMPOEA  1
#define SYTOEA  2
#define MANOEA  3
#define WUPEA   4
#define SFIDEA  5
#define RROEA   6
#define WCOBOE  7

#define TESRB   _SFR_MEM8(0x95)
#define CRCOB   0
#define EOTLB0  1
#define EOTLB1  2

#define TESRA   _SFR_MEM8(0x96)
#define CRCOA   0
#define EOTLA0  1
#define EOTLA1  2

/* Reserved [0x97] */

#define RDSIMR  _SFR_MEM8(0x98)
#define NBITAM  0
#define NBITBM  1
#define EOTAM   2
#define EOTBM   3
#define SOTAM   4
#define SOTBM   5
#define WCOAM   6
#define WCOBM   7

#define RDOCR   _SFR_MEM8(0x99)
#define TMDS0   1
#define TMDS1   2
#define ETRPA   3
#define ETRPB   4
#define RDSIDA  5
#define RDSIDB  6

/* Reserved [0x9A] */

/* Combine TEMPL and TEMPH */
#define TEMP    _SFR_MEM16(0x9B)

#define TEMPL   _SFR_MEM8(0x9B)
#define TEMPH   _SFR_MEM8(0x9C)

#define SYCB    _SFR_MEM8(0x9D)
#define SYCSB0  0
#define SYCSB1  1
#define SYCSB2  2
#define SYCSB3  3
#define SYTLB0  4
#define SYTLB1  5
#define SYTLB2  6
#define SYTLB3  7

#define SYCA    _SFR_MEM8(0x9E)
#define SYCSA0  0
#define SYCSA1  1
#define SYCSA2  2
#define SYCSA3  3
#define SYTLA0  4
#define SYTLA1  5
#define SYTLA2  6
#define SYTLA3  7

#define RXFOB   _SFR_MEM8(0x9F)

#define RXFOA   _SFR_MEM8(0xA0)

#define DMPATB  _SFR_MEM8(0xA1)

#define DMPATA  _SFR_MEM8(0xA2)

#define DMPC    _SFR_MEM8(0xA3)
#define PCFTDA  0
#define PCIALA  1
#define PCSIGA  2
#define PCENA   3
#define PCFTDB  4
#define PCIALB  5
#define PCSIGB  6
#define PCENB   7

#define DMPCB   _SFR_MEM8(0xA4)
#define PCSEVB0 0
#define PCSEVB1 1
#define PCSEVB2 2
#define PCLENB0 3
#define PCLENB1 4
#define PCLENB2 5
#define PSELB0  6
#define PSELB1  7

#define DMPCA   _SFR_MEM8(0xA5)
#define PCSEVA0 0
#define PCSEVA1 1
#define PCSEVA2 2
#define PCLENA0 3
#define PCLENA1 4
#define PCLENA2 5
#define PSELA0  6
#define PSELA1  7

#define DMSRB   _SFR_MEM8(0xA6)

#define DMSRA   _SFR_MEM8(0xA7)

#define DMMB    _SFR_MEM8(0xA8)
#define DMATB0  0
#define DMATB1  1
#define DMATB2  2
#define DMATB3  3
#define DMATB4  4
#define DMPB    5
#define DMHB    6
#define DMNEB   7

#define DMMA    _SFR_MEM8(0xA9)
#define DMATA0  0
#define DMATA1  1
#define DMATA2  2
#define DMATA3  3
#define DMATA4  4
#define DMPA    5
#define DMHA    6
#define DMNEA   7

#define DMCDB   _SFR_MEM8(0xAA)
#define DMCLB0  0
#define DMCLB1  1
#define DMCLB2  2
#define DMCLB3  3
#define DMCLB4  4
#define DMCTB0  5
#define DMCTB1  6
#define DMCTB2  7

#define DMCDA   _SFR_MEM8(0xAB)
#define DMCLA0  0
#define DMCLA1  1
#define DMCLA2  2
#define DMCLA3  3
#define DMCLA4  4
#define DMCTA0  5
#define DMCTA1  6
#define DMCTA2  7

#define DMCRB   _SFR_MEM8(0xAC)
#define DMPGB0  0
#define DMPGB1  1
#define DMPGB2  2
#define DMPGB3  3
#define DMPGB4  4
#define SASKB   5
#define SY1TB   6
#define DMARB   7

#define DMCRA   _SFR_MEM8(0xAD)
#define DMPGA0  0
#define DMPGA1  1
#define DMPGA2  2
#define DMPGA3  3
#define DMPGA4  4
#define SASKA   5
#define SY1TA   6
#define DMARA   7

#define DMDN    _SFR_MEM8(0xAE)
#define DMDNA0  0
#define DMDNA1  1
#define DMDNA2  2
#define DMDNA3  3
#define DMDNB0  4
#define DMDNB1  5
#define DMDNB2  6
#define DMDNB3  7

#define CHCR    _SFR_MEM8(0xAF)
#define BWM0    0
#define BWM1    1
#define BWM2    2
#define BWM3    3

#define CHDN    _SFR_MEM8(0xB0)
#define BBDN0   0
#define BBDN1   1
#define BBDN2   2
#define BBDN3   3
#define BBDN4   4
#define ADCDN   5

#define SFIDCB  _SFR_MEM8(0xB1)
#define SFIDTB0 0
#define SFIDTB1 1
#define SFIDTB2 2
#define SFIDTB3 3
#define SFIDTB4 4
#define SEMEB   7

#define SFIDLB  _SFR_MEM8(0xB2)

#define WUPTB   _SFR_MEM8(0xB3)

#define WUPLB   _SFR_MEM8(0xB4)

#define SFID1B  _SFR_MEM8(0xB5)

#define SFID2B  _SFR_MEM8(0xB6)

#define SFID3B  _SFR_MEM8(0xB7)

#define SFID4B  _SFR_MEM8(0xB8)

#define WUP1B   _SFR_MEM8(0xB9)

#define WUP2B   _SFR_MEM8(0xBA)

#define WUP3B   _SFR_MEM8(0xBB)

#define WUP4B   _SFR_MEM8(0xBC)

#define SFIDCA  _SFR_MEM8(0xBD)
#define SFIDTA0 0
#define SFIDTA1 1
#define SFIDTA2 2
#define SFIDTA3 3
#define SFIDTA4 4
#define SEMEA   7

#define SFIDLA  _SFR_MEM8(0xBE)

#define WUPTA   _SFR_MEM8(0xBF)

#define WUPLA   _SFR_MEM8(0xC0)

#define SFID1A  _SFR_MEM8(0xC1)

#define SFID2A  _SFR_MEM8(0xC2)

#define SFID3A  _SFR_MEM8(0xC3)

#define SFID4A  _SFR_MEM8(0xC4)

#define WUP1A   _SFR_MEM8(0xC5)

#define WUP2A   _SFR_MEM8(0xC6)

#define WUP3A   _SFR_MEM8(0xC7)

#define WUP4A   _SFR_MEM8(0xC8)

#define CLKOD   _SFR_MEM8(0xC9)

#define CLKOCR  _SFR_MEM8(0xCA)
#define CLKOS0  0
#define CLKOS1  1
#define CLKOEN  2

#define XFUSE   _SFR_MEM8(0xCB)
#define FLPT0   0
#define FLPT1   1
#define E2PT0   2
#define E2PT1   3
#define NVPTE   4
#define CKOUT   6

#define SRCCAL  _SFR_MEM8(0xCC)
#define SRCCAL0 0
#define SRCCAL1 1
#define SRCCAL2 2
#define SRCCAL3 3
#define SRCCAL4 4
#define SRCCAL5 5
#define SRCTC0  6
#define SRCTC1  7

#define FRCCAL  _SFR_MEM8(0xCD)
#define FRCCAL0 0
#define FRCCAL1 1
#define FRCCAL2 2
#define FRCCAL3 3
#define FRCCAL4 4
#define FRCTC   5

#define CMSR    _SFR_MEM8(0xCE)
#define ECF     0

#define CMOCR   _SFR_MEM8(0xCF)
#define FRCAO   0
#define SRCAO   1
#define FRCACT  2
#define SRCACT  3

#define SUPFR   _SFR_MEM8(0xD0)
#define AVCCRF  0
#define AVCCLF  1
#define DCRDYF  2
#define DCERF   3

#define SUPCR   _SFR_MEM8(0xD1)
#define AVCCRM  0
#define AVCCLM  1
#define AVEN    5
#define AVDIC   6

#define SUPCA1  _SFR_MEM8(0xD2)
#define DVCAL0  0
#define DVCAL1  1
#define VVCAL0  2
#define VVCAL1  3
#define AVCAL0  4
#define AVCAL1  5

#define SUPCA2  _SFR_MEM8(0xD3)
#define BGCAL0  0
#define BGCAL1  1
#define BGCAL2  2
#define BGCAL3  3
#define BGCAL4  4
#define BGCAL5  5

#define SUPCA3  _SFR_MEM8(0xD4)
#define DMCAL0  0
#define DMCAL1  1
#define VMCAL0  2
#define VMCAL1  3
#define AMCAL0  4
#define AMCAL1  5
#define VMOCAL0 6
#define VMOCAL1 7

#define SUPCA4  _SFR_MEM8(0xD5)
#define PTCAL0  0
#define PTCAL1  1
#define PTCAL2  2
#define PTCAL3  3
#define PTCAL4  4
#define PTCAL5  5
#define PTCAL6  6
#define PTCAL7  7

#define DCCAL1  _SFR_MEM8(0xD6)
#define CCAL0   0
#define CCAL1   1
#define CCAL2   2
#define CCAL3   3
#define ZCCAL0  4
#define ZCCAL1  5
#define ZCCAL2  6
#define ZCCAL3  7

#define DCCAL2  _SFR_MEM8(0xD7)
#define DTCAL0  0
#define DTCAL1  1
#define DTCAL2  2
#define DTCAL3  3
#define OFCAL0  4
#define OFCAL1  5
#define OFCAL2  6
#define OFCAL3  7

#define DCCAL3  _SFR_MEM8(0xD8)
#define SAWCAL0 0
#define SAWCAL1 1

#define DCTST   _SFR_MEM8(0xD9)
#define DCTST0  0
#define DCTST1  1
#define DCTST2  2
#define DCTST3  3
#define DCTST4  4

#define CALRDY  _SFR_MEM8(0xDA)

/* Reserved [0xDB] */

#define RCTUNE4 _SFR_MEM8(0xDC)
#define CTUNE40 0
#define CTUNE41 1
#define CTUNE42 2
#define CTUNE43 3
#define RTUNE40 4
#define RTUNE41 5
#define RTUNE42 6
#define RTUNE43 7

#define DCC1    _SFR_MEM8(0xDD)
#define DCEN    0
#define DCHSSW  1
#define DCCDIV0 4
#define DCCDIV1 5

#define DCC2    _SFR_MEM8(0xDE)
#define DCVOUT0 0
#define DCVOUT1 1
#define DCCLIM0 2
#define DCCLIM1 3
#define DCDRV0  4
#define DCDRV1  5

#define DFS     _SFR_MEM8(0xDF)
#define DFFLRF  0
#define DFUFL   1
#define DFOFL   2

/* Combine DFTLL and DFTLH */
#define DFTL    _SFR_MEM16(0xE0)

#define DFTLL   _SFR_MEM8(0xE0)
#define DFTLH   _SFR_MEM8(0xE1)

#define DFL     _SFR_MEM8(0xE2)
#define DFFLS0  0
#define DFFLS1  1
#define DFFLS2  2
#define DFFLS3  3
#define DFFLS4  4
#define DFFLS5  5
#define DFCLR   7

#define DFWP    _SFR_MEM8(0xE3)

#define DFRP    _SFR_MEM8(0xE4)

#define DFD     _SFR_MEM8(0xE5)

#define DFI     _SFR_MEM8(0xE6)
#define DFFLIM  0
#define DFERIM  1

#define DFC     _SFR_MEM8(0xE7)
#define DFFLC0  0
#define DFFLC1  1
#define DFFLC2  2
#define DFFLC3  3
#define DFFLC4  4
#define DFFLC5  5
#define DFDRA   7

#define SFS     _SFR_MEM8(0xE8)
#define SFFLRF  0
#define SFUFL   1
#define SFOFL   2

#define SFL     _SFR_MEM8(0xE9)
#define SFFLS0  0
#define SFFLS1  1
#define SFFLS2  2
#define SFFLS3  3
#define SFFLS4  4
#define SFCLR   7

#define SFWP    _SFR_MEM8(0xEA)

#define SFRP    _SFR_MEM8(0xEB)

#define SFD     _SFR_MEM8(0xEC)

#define SFI     _SFR_MEM8(0xED)
#define SFFLIM  0
#define SFERIM  1

#define SFC     _SFR_MEM8(0xEE)
#define SFFLC0  0
#define SFFLC1  1
#define SFFLC2  2
#define SFFLC3  3
#define SFFLC4  4
#define SFDRA   7

#define SSMCR   _SFR_MEM8(0xEF)
#define SSMTX   0
#define SSMTM   1
#define SETRPA  6
#define SETRPB  7

#define SSMRCR  _SFR_MEM8(0xF0)
#define SSMPA   0
#define SSMPB   1
#define SSMAD   2
#define SSMHIS  3
#define SSMPVS  4
#define SSMIFA  5
#define SSMIDSE 6
#define SSMTMOE 7

#define SSMFBR  _SFR_MEM8(0xF1)
#define SSMFID0 0
#define SSMFID1 1
#define SSMFID2 2
#define SSMDFDT 3
#define SSMHADT 4
#define SSMPLDT 5

#define SSMRR   _SFR_MEM8(0xF2)
#define SSMR    0
#define SSMST   1

#define SSMSR   _SFR_MEM8(0xF3)
#define SSMESM0 0
#define SSMESM1 1
#define SSMESM2 2
#define SSMESM3 3
#define SSMERR  7

#define SSMIFR  _SFR_MEM8(0xF4)
#define SSMIF   0

#define SSMIMR  _SFR_MEM8(0xF5)
#define SSMIM   0

#define MSMSTR  _SFR_MEM8(0xF6)
#define SSMMST0 0
#define SSMMST1 1
#define SSMMST2 2
#define SSMMST3 3
#define SSMMST4 4

#define SSMSTR  _SFR_MEM8(0xF7)
#define SSMSTA0 0
#define SSMSTA1 1
#define SSMSTA2 2
#define SSMSTA3 3
#define SSMSTA4 4
#define SSMSTA5 5

#define SSMXSR  _SFR_MEM8(0xF8)
#define SSMSTB0 0
#define SSMSTB1 1
#define SSMSTB2 2
#define SSMSTB3 3
#define SSMSTB4 4
#define SSMSTB5 5

#define MSMCR1  _SFR_MEM8(0xF9)
#define MSMSM00 0
#define MSMSM01 1
#define MSMSM02 2
#define MSMSM03 3
#define MSMSM10 4
#define MSMSM11 5
#define MSMSM12 6
#define MSMSM13 7

#define MSMCR2  _SFR_MEM8(0xFA)
#define MSMSM20 0
#define MSMSM21 1
#define MSMSM22 2
#define MSMSM23 3
#define MSMSM30 4
#define MSMSM31 5
#define MSMSM32 6
#define MSMSM33 7

#define MSMCR3  _SFR_MEM8(0xFB)
#define MSMSM40 0
#define MSMSM41 1
#define MSMSM42 2
#define MSMSM43 3
#define MSMSM50 4
#define MSMSM51 5
#define MSMSM52 6
#define MSMSM53 7

#define MSMCR4  _SFR_MEM8(0xFC)
#define MSMSM60 0
#define MSMSM61 1
#define MSMSM62 2
#define MSMSM63 3
#define MSMSM70 4
#define MSMSM71 5
#define MSMSM72 6
#define MSMSM73 7

#define GTCR    _SFR_MEM8(0xFD)
#define RXTEHA  0
#define GAPMA   1
#define DARA    2
#define IWUPA   3
#define RXTEHB  4
#define GAPMB   5
#define DARB    6
#define IWUPB   7

/* Reserved [0xFE..0xFF] */

#define FESR    _SFR_MEM8(0x100)
#define SAT     0
#define XRDY    2
#define PLCK    3

#define FEEN1   _SFR_MEM8(0x101)
#define PLEN    0
#define PLCAL   1
#define XTOEN   2
#define LNAEN   3
#define ADEN    4
#define ADCLK   5
#define PLSP1   6

#define FEEN2   _SFR_MEM8(0x102)
#define PAEN    2
#define TMPM    3
#define PLPEN   4
#define XTPEN   5
#define XTOEXT  7

#define FELNA   _SFR_MEM8(0x103)
#define LNABN0  0
#define LNABN1  1
#define LNABN2  2
#define LNABN3  3
#define LNABH0  4
#define LNABH1  5
#define LNABH2  6
#define LNABH3  7

#define FEAS    _SFR_MEM8(0x104)
#define SDRX1   0
#define SDTX1   1
#define SDRX2   2
#define SDTX2   3
#define SDRX3   4
#define SDTX3   5

/* Reserved [0x105] */

#define FEVCT   _SFR_MEM8(0x106)

#define FEBT    _SFR_MEM8(0x107)
#define CTN20   0
#define CTN21   1
#define RTN20   2
#define RTN21   3

#define FEMS    _SFR_MEM8(0x108)
#define PLLS0   0
#define PLLS1   1
#define PLLS2   2
#define PLLS3   3
#define PLLM0   4
#define PLLM1   5
#define PLLM2   6
#define PLLM3   7

#define FETN4   _SFR_MEM8(0x109)
#define CTN40   0
#define CTN41   1
#define CTN42   2
#define CTN43   3
#define RTN40   4
#define RTN41   5
#define RTN42   6
#define RTN43   7

#define FECR    _SFR_MEM8(0x10A)
#define LBNHB   0
#define S4N3    1
#define ANDP    2
#define ADHS    3
#define PLCKG   4
#define ANPS    5

#define FEVCO   _SFR_MEM8(0x10B)
#define CPCC0   0
#define CPCC1   1
#define CPCC2   2
#define CPCC3   3
#define VCOB0   4
#define VCOB1   5
#define VCOB2   6
#define VCOB3   7

#define FEBIA   _SFR_MEM8(0x10C)
#define HISEN   6
#define IFAEN   7

#define SPARE1  _SFR_MEM8(0x10D)
#define CHBIR0  0
#define CHBIR1  1
#define CHBIR2  2
#define CHBIR3  3
#define CHBIR4  4
#define CHBIR5  5
#define CHBIR6  6
#define CHBIR7  7

/* Reserved [0x10E..0x11F] */

#define SOTC1A  _SFR_MEM8(0x120)
#define CAROEA1 0
#define AMPOEA1 1
#define SYTOEA1 2
#define MANOEA1 3
#define WUPEA1  4
#define SFIDEA1 5
#define RROEA1  6
#define WCOBOE1 7

#define SOTC2A  _SFR_MEM8(0x121)
#define CAROEA2 0
#define AMPOEA2 1
#define SYTOEA2 2
#define MANOEA2 3
#define WUPEA2  4
#define SFIDEA2 5
#define RROEA2  6
#define WCOBOE2 7

#define SOTC1B  _SFR_MEM8(0x122)
#define CAROEB1 0
#define AMPOEB1 1
#define SYTOEB1 2
#define MANOEB1 3
#define WUPEB1  4
#define SFIDEB1 5
#define RROEB1  6
#define WCOAOE1 7

#define SOTC2B  _SFR_MEM8(0x123)
#define CAROEB2 0
#define AMPOEB2 1
#define SYTOEB2 2
#define MANOEB2 3
#define WUPEB2  4
#define SFIDEB2 5
#define RROEB2  6
#define WCOAOE2 7

#define EOTC1A  _SFR_MEM8(0x124)
#define CARFEA1 0
#define AMPFEA1 1
#define SYTFEA1 2
#define MANFEA1 3
#define TMOFEA1 4
#define TELREA1 5
#define RRFEA1  6
#define EOTBFE1 7

#define EOTC2A  _SFR_MEM8(0x125)
#define CARFEA2 0
#define AMPFEA2 1
#define SYTFEA2 2
#define MANFEA2 3
#define TMOFEA2 4
#define TELREA2 5
#define RRFEA2  6
#define EOTBFE2 7

#define EOTC3A  _SFR_MEM8(0x126)
#define CARFEA3 0
#define AMPFEA3 1
#define SYTFEA3 2
#define MANFEA3 3
#define TMOFEA3 4
#define TELREA3 5
#define RRFEA3  6
#define EOTBFE3 7

#define EOTC1B  _SFR_MEM8(0x127)
#define CARFEB1 0
#define AMPFEB1 1
#define SYTFEB1 2
#define MANFEB1 3
#define TMOFEB1 4
#define TELREB1 5
#define RRFEB1  6
#define EOTAFE1 7

#define EOTC2B  _SFR_MEM8(0x128)
#define CARFEB2 0
#define AMPFEB2 1
#define SYTFEB2 2
#define MANFEB2 3
#define TMOFEB2 4
#define TELREB2 5
#define RRFEB2  6
#define EOTAFE2 7

#define EOTC3B  _SFR_MEM8(0x129)
#define CARFEB3 0
#define AMPFEB3 1
#define SYTFEB3 2
#define MANFEB3 3
#define TMOFEB3 4
#define TELREB3 5
#define RRFEB3  6
#define EOTAFE3 7

#define WCOTOA  _SFR_MEM8(0x12A)

#define WCOTOB  _SFR_MEM8(0x12B)

#define SOTTOA  _SFR_MEM8(0x12C)

#define SOTTOB  _SFR_MEM8(0x12D)

#define SSMFCR  _SFR_MEM8(0x12E)
#define SSMIDSO 0
#define SSMIDSF 1
#define SSMSEH  2
#define SSMCEH  3

/* Reserved [0x12F..0x13D] */

#define RXBC1   _SFR_MEM8(0x13E)
#define RXCEA   0
#define RXCBLA0 1
#define RXCBLA1 2
#define RXLSBA  3
#define RXCEB   4
#define RXCBLB0 5
#define RXCBLB1 6
#define RXLSBB  7

#define RXBC2   _SFR_MEM8(0x13F)
#define RXBPB   0
#define RXBF    1
#define RXBCLR  2

#define RXTLLB  _SFR_MEM8(0x140)

#define RXTLHB  _SFR_MEM8(0x141)

#define RXCRLB  _SFR_MEM8(0x142)

#define RXCRHB  _SFR_MEM8(0x143)

#define RXCSBB  _SFR_MEM8(0x144)

#define RXCILB  _SFR_MEM8(0x145)

#define RXCIHB  _SFR_MEM8(0x146)

#define RXCPLB  _SFR_MEM8(0x147)

#define RXCPHB  _SFR_MEM8(0x148)

#define RXDSB   _SFR_MEM8(0x149)

#define RXTLLA  _SFR_MEM8(0x14A)

#define RXTLHA  _SFR_MEM8(0x14B)

#define RXCRLA  _SFR_MEM8(0x14C)

#define RXCRHA  _SFR_MEM8(0x14D)

#define RXCSBA  _SFR_MEM8(0x14E)

#define RXCILA  _SFR_MEM8(0x14F)

#define RXCIHA  _SFR_MEM8(0x150)

#define RXCPLA  _SFR_MEM8(0x151)

#define RXCPHA  _SFR_MEM8(0x152)

#define RXDSA   _SFR_MEM8(0x153)

#define CRCCR   _SFR_MEM8(0x154)
#define CRCRS   0
#define REFLI   1
#define REFLO   2

#define CRCDOR  _SFR_MEM8(0x155)

#define IDB0    _SFR_MEM8(0x156)

#define IDB1    _SFR_MEM8(0x157)

#define IDB2    _SFR_MEM8(0x158)

#define IDB3    _SFR_MEM8(0x159)

#define IDC     _SFR_MEM8(0x15A)
#define IDL0    0
#define IDL1    1
#define IDBO0   2
#define IDBO1   3
#define IDFIM   5
#define IDCLR   6
#define IDCE    7

#define IDS     _SFR_MEM8(0x15B)
#define IDOK    0
#define IDFULL  1

#define RSSAV   _SFR_MEM8(0x15C)

#define RSSPK   _SFR_MEM8(0x15D)

#define RSSL    _SFR_MEM8(0x15E)

#define RSSH    _SFR_MEM8(0x15F)

#define RSSC    _SFR_MEM8(0x160)
#define RSUP0   0
#define RSUP1   1
#define RSUP2   2
#define RSUP3   3
#define RSWLH   4
#define RSHRX   5
#define RSPKF   6

#define DBCR    _SFR_MEM8(0x161)
#define DBMD    0
#define DBCS    1
#define DBTMS   2

#define DBTC    _SFR_MEM8(0x162)

#define DBENB   _SFR_MEM8(0x163)

#define DBENC   _SFR_MEM8(0x164)

#define DBGSW   _SFR_MEM8(0x165)
#define DBGGS0  0
#define DBGGS1  1
#define DBGGS2  2
#define DBGGS3  3
#define CPBFOS0 4
#define CPBFOS1 5
#define CPBF    6
#define DBGSE   7

#define SFFR    _SFR_MEM8(0x166)
#define RFL0    0
#define RFL1    1
#define RFL2    2
#define RFC     3
#define TFL0    4
#define TFL1    5
#define TFL2    6
#define TFC     7

#define SFIR    _SFR_MEM8(0x167)
#define RIL0    0
#define RIL1    1
#define RIL2    2
#define SRIE    3
#define TIL0    4
#define TIL1    5
#define TIL2    6
#define STIE    7

#define EECR2   _SFR_MEM8(0x168)
#define EEBRE   0
#define EEFF    6
#define EECF    7

#define PGMST   _SFR_MEM8(0x169)
#define PGMSYN0 0
#define PGMSYN1 1
#define PGMSYN2 2
#define PGMSYN3 3
#define PGMSYN4 4

#define EEST    _SFR_MEM8(0x16A)
#define EESYN0  0
#define EESYN1  1
#define EESYN2  2
#define EESYN3  3

#define RSHSG   _SFR_MEM8(0x16B)

#define RSIFG   _SFR_MEM8(0x16C)

#define RSLDV   _SFR_MEM8(0x16D)

#define RSHDV   _SFR_MEM8(0x16E)

#define RSCOM   _SFR_MEM8(0x16F)
#define RSDC    0
#define RSIFC   1
#define RSHISC  2

#define OCCR    _SFR_MEM8(0x170)
#define OCEN    0
#define OCSEL   1

#define OCCNT   _SFR_MEM8(0x171)

#define OCGATE  _SFR_MEM8(0x172)

#define LINCR   _SFR_MEM8(0x173)
#define LCMD0   0
#define LCMD1   1
#define LCMD2   2
#define LENA    3
#define LCONF0  4
#define LCONF1  5
#define LIN13   6
#define LSWRES  7

#define LINSIR  _SFR_MEM8(0x174)
#define LRXOK   0
#define LTXOK   1
#define LIDOK   2
#define LERR    3
#define LBUSY   4
#define LIDST0  5
#define LIDST1  6
#define LIDST2  7

#define LINENIR _SFR_MEM8(0x175)
#define LENRXOK 0
#define LENTXOK 1
#define LENIDOK 2
#define LENERR  3

#define LINERR  _SFR_MEM8(0x176)
#define LBERR   0
#define LCERR   1
#define LPERR   2
#define LSERR   3
#define LFERR   4
#define LOVERR  5
#define LTOERR  6
#define LABORT  7

#define LINBTR  _SFR_MEM8(0x177)
#define LBT0    0
#define LBT1    1
#define LBT2    2
#define LBT3    3
#define LBT4    4
#define LBT5    5
#define LDISR   7

#define LINBRRL _SFR_MEM8(0x178)
#define LDIV0   0
#define LDIV1   1
#define LDIV2   2
#define LDIV3   3
#define LDIV4   4
#define LDIV5   5
#define LDIV6   6
#define LDIV7   7

#define LINBRRH _SFR_MEM8(0x179)
#define LDIV8   0
#define LDIV9   1
#define LDIV10  2
#define LDIV11  3

#define LINDLR  _SFR_MEM8(0x17A)
#define LRXDL0  0
#define LRXDL1  1
#define LRXDL2  2
#define LRXDL3  3
#define LTXDL0  4
#define LTXDL1  5
#define LTXDL2  6
#define LTXDL3  7

#define LINIDR  _SFR_MEM8(0x17B)
#define LID0    0
#define LID1    1
#define LID2    2
#define LID3    3
#define LID4    4
#define LID5    5
#define LP0     6
#define LP1     7

#define LINSEL  _SFR_MEM8(0x17C)
#define LINDX0  0
#define LINDX1  1
#define LINDX2  2
#define LAINC   3

#define LINDAT  _SFR_MEM8(0x17D)
#define LDATA0  0
#define LDATA1  1
#define LDATA2  2
#define LDATA3  3
#define LDATA4  4
#define LDATA5  5
#define LDATA6  6
#define LDATA7  7

#define TRCCR   _SFR_MEM8(0x17E)
#define TRCCE   0
#define TRCEN   1

#define TRCDR   _SFR_MEM8(0x17F)

/* Combine TRCIDL and TRCIDH */
#define TRCID   _SFR_MEM16(0x180)

#define TRCIDL  _SFR_MEM8(0x180)
#define TRCIDH  _SFR_MEM8(0x181)



/* Values and associated defines */


#define SLEEP_MODE_IDLE (0x00<<1)
#define SLEEP_MODE_PWR_DOWN (0x01<<1)
#define SLEEP_MODE_PWR_OFF (0x03<<1)

/* Interrupt vectors */
/* Vector 0 is the reset vector */
/* External Interrupt Request 0 */
#define INT0_vect            _VECTOR(1)
#define INT0_vect_num        1

/* External Interrupt Request 1 */
#define INT1_vect            _VECTOR(2)
#define INT1_vect_num        2

/* Pin Change Interrupt Request 0 */
#define PCI0_vect            _VECTOR(3)
#define PCI0_vect_num        3

/* Pin Change Interrupt Request 1 */
#define PCI1_vect            _VECTOR(4)
#define PCI1_vect_num        4

/* Voltage Monitoring Interrupt */
#define VMON_vect            _VECTOR(5)
#define VMON_vect_num        5

/* AVCC Reset Interrupt */
#define AVCCR_vect            _VECTOR(6)
#define AVCCR_vect_num        6

/* AVCC Low Interrupt */
#define AVCCL_vect            _VECTOR(7)
#define AVCCL_vect_num        7

/* Timer 0 Interval Interrupt */
#define T0INT_vect            _VECTOR(8)
#define T0INT_vect_num        8

/* Timer/Counter1 Compare Match Interrupt */
#define T1COMP_vect            _VECTOR(9)
#define T1COMP_vect_num        9

/* Timer/Counter1 Overflow Interrupt */
#define T1OVF_vect            _VECTOR(10)
#define T1OVF_vect_num        10

/* Timer/Counter2 Compare Match Interrupt */
#define T2COMP_vect            _VECTOR(11)
#define T2COMP_vect_num        11

/* Timer/Counter2 Overflow Interrupt */
#define T2OVF_vect            _VECTOR(12)
#define T2OVF_vect_num        12

/* Timer/Counter3 Capture Event Interrupt */
#define T3CAP_vect            _VECTOR(13)
#define T3CAP_vect_num        13

/* Timer/Counter3 Compare Match Interrupt */
#define T3COMP_vect            _VECTOR(14)
#define T3COMP_vect_num        14

/* Timer/Counter3 Overflow Interrupt */
#define T3OVF_vect            _VECTOR(15)
#define T3OVF_vect_num        15

/* Timer/Counter4 Capture Event Interrupt */
#define T4CAP_vect            _VECTOR(16)
#define T4CAP_vect_num        16

/* Timer/Counter4 Compare Match Interrupt */
#define T4COMP_vect            _VECTOR(17)
#define T4COMP_vect_num        17

/* Timer/Counter4 Overflow Interrupt */
#define T4OVF_vect            _VECTOR(18)
#define T4OVF_vect_num        18

/* Timer/Counter5 Compare Match Interrupt */
#define T5COMP_vect            _VECTOR(19)
#define T5COMP_vect_num        19

/* Timer/Counter5 Overflow Interrupt */
#define T5OVF_vect            _VECTOR(20)
#define T5OVF_vect_num        20

/* SPI Serial Transfer Complete Interrupt */
#define SPI_vect            _VECTOR(21)
#define SPI_vect_num        21

/* SPI Rx Buffer Interrupt */
#define SRX_FIFO_vect            _VECTOR(22)
#define SRX_FIFO_vect_num        22

/* SPI Tx Buffer Interrupt */
#define STX_FIFO_vect            _VECTOR(23)
#define STX_FIFO_vect_num        23

/* LIN/UART Transfer Complete Interrupt */
#define LINTC_vect            _VECTOR(24)
#define LINTC_vect_num        24

/* LIN/UART Error Interrupt */
#define LINERR_vect            _VECTOR(25)
#define LINERR_vect_num        25

/* Sequencer State Machine Interrupt */
#define SSM_vect            _VECTOR(26)
#define SSM_vect_num        26

/* Data FIFO fill level reached Interrupt */
#define DFFLR_vect            _VECTOR(27)
#define DFFLR_vect_num        27

/* Data FIFO overflow or underflow error Interrupt */
#define DFOUE_vect            _VECTOR(28)
#define DFOUE_vect_num        28

/* RSSI/Preamble FIFO fill level reached Interrupt */
#define SFFLR_vect            _VECTOR(29)
#define SFFLR_vect_num        29

/* RSSI/Preamble FIFO overflow or underflow error Interrupt */
#define SFOUE_vect            _VECTOR(30)
#define SFOUE_vect_num        30

/* Tx Modulator Telegram Finish Interrupt */
#define TMTCF_vect            _VECTOR(31)
#define TMTCF_vect_num        31

/* UHF receiver wake up ok on Rx path A */
#define UHF_WCOA_vect            _VECTOR(32)
#define UHF_WCOA_vect_num        32

/* UHF receiver wake up ok on Rx path B */
#define UHF_WCOB_vect            _VECTOR(33)
#define UHF_WCOB_vect_num        33

/* UHF receiver start of telegram ok on Rx path A */
#define UHF_SOTA_vect            _VECTOR(34)
#define UHF_SOTA_vect_num        34

/* UHF receiver start of telegram ok on Rx path B */
#define UHF_SOTB_vect            _VECTOR(35)
#define UHF_SOTB_vect_num        35

/* UHF receiver end of telegram on Rx path A */
#define UHF_EOTA_vect            _VECTOR(36)
#define UHF_EOTA_vect_num        36

/* UHF receiver end of telegram on Rx path B */
#define UHF_EOTB_vect            _VECTOR(37)
#define UHF_EOTB_vect_num        37

/* UHF receiver new bit on Rx path A */
#define UHF_NBITA_vect            _VECTOR(38)
#define UHF_NBITA_vect_num        38

/* UHF receiver new bit on Rx path B */
#define UHF_NBITB_vect            _VECTOR(39)
#define UHF_NBITB_vect_num        39

/* External input Clock monitoring Interrupt */
#define EXCM_vect            _VECTOR(40)
#define EXCM_vect_num        40

/* EEPROM Ready Interrupt */
#define ERDY_vect            _VECTOR(41)
#define ERDY_vect_num        41

/* Store Program Memory Ready */
#define SPMR_vect            _VECTOR(42)
#define SPMR_vect_num        42

/* IDSCAN Full Interrupt */
#define IDFULL_vect            _VECTOR(43)
#define IDFULL_vect_num        43

#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#  define _VECTORS_SIZE 176
#else
#  define _VECTORS_SIZE 176U
#endif


/* Constants */

#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#  define SPM_PAGESIZE 64
#  define FLASHSTART   0x8000
#  define FLASHEND     0xD1FF
#else
#  define SPM_PAGESIZE 64U
#  define FLASHSTART   0x8000U
#  define FLASHEND     0xD1FFU
#endif
#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#  define RAMSTART     0x0200
#  define RAMSIZE      2048
#  define RAMEND       0x09FF
#else
#  define RAMSTART     0x0200U
#  define RAMSIZE      2048U
#  define RAMEND       0x09FFU
#endif
#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#  define E2START     0
#  define E2SIZE      1024
#  define E2PAGESIZE  16
#  define E2END       0x03FF
#else
#  define E2START     0U
#  define E2SIZE      1024U
#  define E2PAGESIZE  16U
#  define E2END       0x03FFU
#endif
#define XRAMEND      RAMEND


/* Fuses */

#define FUSE_MEMORY_SIZE 1

/* Fuse Byte */
#define FUSE_EXTCLKEN    (unsigned char)~_BV(0)
#define FUSE_RSTDISBL    (unsigned char)~_BV(1)
#define FUSE_BOOTRST     (unsigned char)~_BV(2)
#define FUSE_EESAVE      (unsigned char)~_BV(3)
#define FUSE_WDTON       (unsigned char)~_BV(4)
#define FUSE_SPIEN       (unsigned char)~_BV(5)
#define FUSE_DWEN        (unsigned char)~_BV(6)
#define FUSE_CKDIV8      (unsigned char)~_BV(7)
#define LFUSE_DEFAULT    (FUSE_SPIEN)



/* Lock Bits */
#define __LOCK_BITS_EXIST
#define __BOOT_LOCK_BITS_0_EXIST
#define __BOOT_LOCK_BITS_1_EXIST


/* Signature */
#define SIGNATURE_0 0x1E
#define SIGNATURE_1 0x94
#define SIGNATURE_2 0x6C




#endif /* #ifdef _AVR_ATA5787_H_INCLUDED */

