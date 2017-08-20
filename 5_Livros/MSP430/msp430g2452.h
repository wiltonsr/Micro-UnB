/********************************************************************
*
* Standard register and bit definitions for the Texas Instruments
* MSP430 microcontroller.
*
* This file supports assembler and C development for
* MSP430G2452 devices.
*
* Texas Instruments, Version 1.0
*
* Rev. 1.0, Setup
*
********************************************************************/

#ifndef __MSP430G2452
#define __MSP430G2452

#ifdef  __IAR_SYSTEMS_ICC__
#ifndef _SYSTEM_BUILD
#pragma system_include
#endif
#endif

#if (((__TID__ >> 8) & 0x7F) != 0x2b)     /* 0x2b = 43 dec */
#error msp430g2452.h file for use with ICC430/A430 only
#endif


#ifdef __IAR_SYSTEMS_ICC__
#include "in430.h"
#pragma language=extended

#define DEFC(name, address) __no_init volatile unsigned char name @ address;
#define DEFW(name, address) __no_init volatile unsigned short name @ address;
#define DEFXC  volatile unsigned char
#define DEFXW  volatile unsigned short

#endif  /* __IAR_SYSTEMS_ICC__  */


#ifdef __IAR_SYSTEMS_ASM__
#define DEFC(name, address) sfrb name = address;
#define DEFW(name, address) sfrw name = address;

#endif /* __IAR_SYSTEMS_ASM__*/

#ifdef __cplusplus
#define READ_ONLY
#else
#define READ_ONLY const
#endif

/************************************************************
* STANDARD BITS
************************************************************/

#define BIT0                (0x0001u)
#define BIT1                (0x0002u)
#define BIT2                (0x0004u)
#define BIT3                (0x0008u)
#define BIT4                (0x0010u)
#define BIT5                (0x0020u)
#define BIT6                (0x0040u)
#define BIT7                (0x0080u)
#define BIT8                (0x0100u)
#define BIT9                (0x0200u)
#define BITA                (0x0400u)
#define BITB                (0x0800u)
#define BITC                (0x1000u)
#define BITD                (0x2000u)
#define BITE                (0x4000u)
#define BITF                (0x8000u)

/************************************************************
* STATUS REGISTER BITS
************************************************************/

#define C                   (0x0001u)
#define Z                   (0x0002u)
#define N                   (0x0004u)
#define V                   (0x0100u)
#define GIE                 (0x0008u)
#define CPUOFF              (0x0010u)
#define OSCOFF              (0x0020u)
#define SCG0                (0x0040u)
#define SCG1                (0x0080u)

/* Low Power Modes coded with Bits 4-7 in SR */

#ifndef __IAR_SYSTEMS_ICC__ /* Begin #defines for assembler */
#define LPM0                (CPUOFF)
#define LPM1                (SCG0+CPUOFF)
#define LPM2                (SCG1+CPUOFF)
#define LPM3                (SCG1+SCG0+CPUOFF)
#define LPM4                (SCG1+SCG0+OSCOFF+CPUOFF)
/* End #defines for assembler */

#else /* Begin #defines for C */
#define LPM0_bits           (CPUOFF)
#define LPM1_bits           (SCG0+CPUOFF)
#define LPM2_bits           (SCG1+CPUOFF)
#define LPM3_bits           (SCG1+SCG0+CPUOFF)
#define LPM4_bits           (SCG1+SCG0+OSCOFF+CPUOFF)

#include "in430.h"

#define LPM0      _BIS_SR(LPM0_bits)     /* Enter Low Power Mode 0 */
#define LPM0_EXIT _BIC_SR_IRQ(LPM0_bits) /* Exit Low Power Mode 0 */
#define LPM1      _BIS_SR(LPM1_bits)     /* Enter Low Power Mode 1 */
#define LPM1_EXIT _BIC_SR_IRQ(LPM1_bits) /* Exit Low Power Mode 1 */
#define LPM2      _BIS_SR(LPM2_bits)     /* Enter Low Power Mode 2 */
#define LPM2_EXIT _BIC_SR_IRQ(LPM2_bits) /* Exit Low Power Mode 2 */
#define LPM3      _BIS_SR(LPM3_bits)     /* Enter Low Power Mode 3 */
#define LPM3_EXIT _BIC_SR_IRQ(LPM3_bits) /* Exit Low Power Mode 3 */
#define LPM4      _BIS_SR(LPM4_bits)     /* Enter Low Power Mode 4 */
#define LPM4_EXIT _BIC_SR_IRQ(LPM4_bits) /* Exit Low Power Mode 4 */
#endif /* End #defines for C */

/************************************************************
* PERIPHERAL FILE MAP
************************************************************/

/************************************************************
* SPECIAL FUNCTION REGISTER ADDRESSES + CONTROL BITS
************************************************************/

#define IE1_                (0x0000u)  /* Interrupt Enable 1 */
DEFC(   IE1               , IE1_)
#define WDTIE               (0x01)    /* Watchdog Interrupt Enable */
#define OFIE                (0x02)    /* Osc. Fault  Interrupt Enable */
#define NMIIE               (0x10)    /* NMI Interrupt Enable */
#define ACCVIE              (0x20)    /* Flash Access Violation Interrupt Enable */

#define IFG1_               (0x0002u)  /* Interrupt Flag 1 */
DEFC(   IFG1              , IFG1_)
#define WDTIFG              (0x01)    /* Watchdog Interrupt Flag */
#define OFIFG               (0x02)    /* Osc. Fault Interrupt Flag */
#define PORIFG              (0x04)    /* Power On Interrupt Flag */
#define RSTIFG              (0x08)    /* Reset Interrupt Flag */
#define NMIIFG              (0x10)    /* NMI Interrupt Flag */

/************************************************************
* ADC10
************************************************************/
#define __MSP430_HAS_ADC10__            /* Definition to show that Module is available */

#define ADC10DTC0_          (0x0048u)    /* ADC10 Data Transfer Control 0 */
DEFC(   ADC10DTC0         , ADC10DTC0_)
#define ADC10DTC1_          (0x0049u)    /* ADC10 Data Transfer Control 1 */
DEFC(   ADC10DTC1         , ADC10DTC1_)
#define ADC10AE0_           (0x004Au)    /* ADC10 Analog Enable 0 */
DEFC(   ADC10AE0          , ADC10AE0_)

#define ADC10CTL0_          (0x01B0u)    /* ADC10 Control 0 */
DEFW(   ADC10CTL0         , ADC10CTL0_)
#define ADC10CTL1_          (0x01B2u)    /* ADC10 Control 1 */
DEFW(   ADC10CTL1         , ADC10CTL1_)
#define ADC10MEM_           (0x01B4u)    /* ADC10 Memory */
DEFW(   ADC10MEM          , ADC10MEM_)
#define ADC10SA_            (0x01BCu)    /* ADC10 Data Transfer Start Address */
DEFW(   ADC10SA           , ADC10SA_)

/* ADC10CTL0 */
#define ADC10SC             (0x001)     /* ADC10 Start Conversion */
#define ENC                 (0x002)     /* ADC10 Enable Conversion */
#define ADC10IFG            (0x004)     /* ADC10 Interrupt Flag */
#define ADC10IE             (0x008)     /* ADC10 Interrupt Enalbe */
#define ADC10ON             (0x010)     /* ADC10 On/Enable */
#define REFON               (0x020)     /* ADC10 Reference on */
#define REF2_5V             (0x040)     /* ADC10 Ref 0:1.5V / 1:2.5V */
#define MSC                 (0x080)     /* ADC10 Multiple SampleConversion */
#define REFBURST            (0x100)     /* ADC10 Reference Burst Mode */
#define REFOUT              (0x200)     /* ADC10 Enalbe output of Ref. */
#define ADC10SR             (0x400)     /* ADC10 Sampling Rate 0:200ksps / 1:50ksps */
#define ADC10SHT0           (0x800)     /* ADC10 Sample Hold Select Bit: 0 */
#define ADC10SHT1           (0x1000u)    /* ADC10 Sample Hold Select Bit: 1 */
#define SREF0               (0x2000u)    /* ADC10 Reference Select Bit: 0 */
#define SREF1               (0x4000u)    /* ADC10 Reference Select Bit: 1 */
#define SREF2               (0x8000u)    /* ADC10 Reference Select Bit: 2 */
#define ADC10SHT_0          (0*0x800u)   /* 4 x ADC10CLKs */
#define ADC10SHT_1          (1*0x800u)   /* 8 x ADC10CLKs */
#define ADC10SHT_2          (2*0x800u)   /* 16 x ADC10CLKs */
#define ADC10SHT_3          (3*0x800u)   /* 64 x ADC10CLKs */

#define SREF_0              (0*0x2000u)  /* VR+ = AVCC and VR- = AVSS */
#define SREF_1              (1*0x2000u)  /* VR+ = VREF+ and VR- = AVSS */
#define SREF_2              (2*0x2000u)  /* VR+ = VEREF+ and VR- = AVSS */
#define SREF_3              (3*0x2000u)  /* VR+ = VEREF+ and VR- = AVSS */
#define SREF_4              (4*0x2000u)  /* VR+ = AVCC and VR- = VREF-/VEREF- */
#define SREF_5              (5*0x2000u)  /* VR+ = VREF+ and VR- = VREF-/VEREF- */
#define SREF_6              (6*0x2000u)  /* VR+ = VEREF+ and VR- = VREF-/VEREF- */
#define SREF_7              (7*0x2000u)  /* VR+ = VEREF+ and VR- = VREF-/VEREF- */

/* ADC10CTL1 */
#define ADC10BUSY           (0x0001u)    /* ADC10 BUSY */
#define CONSEQ0             (0x0002u)    /* ADC10 Conversion Sequence Select 0 */
#define CONSEQ1             (0x0004u)    /* ADC10 Conversion Sequence Select 1 */
#define ADC10SSEL0          (0x0008u)    /* ADC10 Clock Source Select Bit: 0 */
#define ADC10SSEL1          (0x0010u)    /* ADC10 Clock Source Select Bit: 1 */
#define ADC10DIV0           (0x0020u)    /* ADC10 Clock Divider Select Bit: 0 */
#define ADC10DIV1           (0x0040u)    /* ADC10 Clock Divider Select Bit: 1 */
#define ADC10DIV2           (0x0080u)    /* ADC10 Clock Divider Select Bit: 2 */
#define ISSH                (0x0100u)    /* ADC10 Invert Sample Hold Signal */
#define ADC10DF             (0x0200u)    /* ADC10 Data Format 0:binary 1:2's complement */
#define SHS0                (0x0400u)    /* ADC10 Sample/Hold Source Bit: 0 */
#define SHS1                (0x0800u)    /* ADC10 Sample/Hold Source Bit: 1 */
#define INCH0               (0x1000u)    /* ADC10 Input Channel Select Bit: 0 */
#define INCH1               (0x2000u)    /* ADC10 Input Channel Select Bit: 1 */
#define INCH2               (0x4000u)    /* ADC10 Input Channel Select Bit: 2 */
#define INCH3               (0x8000u)    /* ADC10 Input Channel Select Bit: 3 */

#define CONSEQ_0            (0*2u)       /* Single channel single conversion */
#define CONSEQ_1            (1*2u)       /* Sequence of channels */
#define CONSEQ_2            (2*2u)       /* Repeat single channel */
#define CONSEQ_3            (3*2u)       /* Repeat sequence of channels */

#define ADC10SSEL_0         (0*8u)       /* ADC10OSC */
#define ADC10SSEL_1         (1*8u)       /* ACLK */
#define ADC10SSEL_2         (2*8u)       /* MCLK */
#define ADC10SSEL_3         (3*8u)       /* SMCLK */

#define ADC10DIV_0          (0*0x20u)    /* ADC10 Clock Divider Select 0 */
#define ADC10DIV_1          (1*0x20u)    /* ADC10 Clock Divider Select 1 */
#define ADC10DIV_2          (2*0x20u)    /* ADC10 Clock Divider Select 2 */
#define ADC10DIV_3          (3*0x20u)    /* ADC10 Clock Divider Select 3 */
#define ADC10DIV_4          (4*0x20u)    /* ADC10 Clock Divider Select 4 */
#define ADC10DIV_5          (5*0x20u)    /* ADC10 Clock Divider Select 5 */
#define ADC10DIV_6          (6*0x20u)    /* ADC10 Clock Divider Select 6 */
#define ADC10DIV_7          (7*0x20u)    /* ADC10 Clock Divider Select 7 */

#define SHS_0               (0*0x400u)   /* ADC10SC */
#define SHS_1               (1*0x400u)   /* TA3 OUT1 */
#define SHS_2               (2*0x400u)   /* TA3 OUT0 */
#define SHS_3               (3*0x400u)   /* TA3 OUT2 */

#define INCH_0              (0*0x1000u)  /* Selects Channel 0 */
#define INCH_1              (1*0x1000u)  /* Selects Channel 1 */
#define INCH_2              (2*0x1000u)  /* Selects Channel 2 */
#define INCH_3              (3*0x1000u)  /* Selects Channel 3 */
#define INCH_4              (4*0x1000u)  /* Selects Channel 4 */
#define INCH_5              (5*0x1000u)  /* Selects Channel 5 */
#define INCH_6              (6*0x1000u)  /* Selects Channel 6 */
#define INCH_7              (7*0x1000u)  /* Selects Channel 7 */
#define INCH_8              (8*0x1000u)  /* Selects Channel 8 */
#define INCH_9              (9*0x1000u)  /* Selects Channel 9 */
#define INCH_10             (10*0x1000u) /* Selects Channel 10 */
#define INCH_11             (11*0x1000u) /* Selects Channel 11 */
#define INCH_12             (12*0x1000u) /* Selects Channel 12 */
#define INCH_13             (13*0x1000u) /* Selects Channel 13 */
#define INCH_14             (14*0x1000u) /* Selects Channel 14 */
#define INCH_15             (15*0x1000u) /* Selects Channel 15 */

/* ADC10DTC0 */
#define ADC10FETCH          (0x001)     /* This bit should normally be reset */
#define ADC10B1             (0x002)     /* ADC10 block one */
#define ADC10CT             (0x004)     /* ADC10 continuous transfer */
#define ADC10TB             (0x008)     /* ADC10 two-block mode */
#define ADC10DISABLE        (0x000)     /* ADC10DTC1 */

/************************************************************
* Basic Clock Module
************************************************************/
#define __MSP430_HAS_BC2__            /* Definition to show that Module is available */

#define DCOCTL_             (0x0056u)  /* DCO Clock Frequency Control */
DEFC(   DCOCTL            , DCOCTL_)
#define BCSCTL1_            (0x0057u)  /* Basic Clock System Control 1 */
DEFC(   BCSCTL1           , BCSCTL1_)
#define BCSCTL2_            (0x0058u)  /* Basic Clock System Control 2 */
DEFC(   BCSCTL2           , BCSCTL2_)
#define BCSCTL3_            (0x0053u)  /* Basic Clock System Control 3 */
DEFC(   BCSCTL3           , BCSCTL3_)

#define MOD0                (0x01)   /* Modulation Bit 0 */
#define MOD1                (0x02)   /* Modulation Bit 1 */
#define MOD2                (0x04)   /* Modulation Bit 2 */
#define MOD3                (0x08)   /* Modulation Bit 3 */
#define MOD4                (0x10)   /* Modulation Bit 4 */
#define DCO0                (0x20)   /* DCO Select Bit 0 */
#define DCO1                (0x40)   /* DCO Select Bit 1 */
#define DCO2                (0x80)   /* DCO Select Bit 2 */

#define RSEL0               (0x01)   /* Range Select Bit 0 */
#define RSEL1               (0x02)   /* Range Select Bit 1 */
#define RSEL2               (0x04)   /* Range Select Bit 2 */
#define RSEL3               (0x08)   /* Range Select Bit 3 */
#define DIVA0               (0x10)   /* ACLK Divider 0 */
#define DIVA1               (0x20)   /* ACLK Divider 1 */
#define XTS                 (0x40)   /* LFXTCLK 0:Low Freq. / 1: High Freq. */
#define XT2OFF              (0x80)   /* Enable XT2CLK */

#define DIVA_0              (0x00)   /* ACLK Divider 0: /1 */
#define DIVA_1              (0x10)   /* ACLK Divider 1: /2 */
#define DIVA_2              (0x20)   /* ACLK Divider 2: /4 */
#define DIVA_3              (0x30)   /* ACLK Divider 3: /8 */

#define DIVS0               (0x02)   /* SMCLK Divider 0 */
#define DIVS1               (0x04)   /* SMCLK Divider 1 */
#define SELS                (0x08)   /* SMCLK Source Select 0:DCOCLK / 1:XT2CLK/LFXTCLK */
#define DIVM0               (0x10)   /* MCLK Divider 0 */
#define DIVM1               (0x20)   /* MCLK Divider 1 */
#define SELM0               (0x40)   /* MCLK Source Select 0 */
#define SELM1               (0x80)   /* MCLK Source Select 1 */

#define DIVS_0              (0x00)   /* SMCLK Divider 0: /1 */
#define DIVS_1              (0x02)   /* SMCLK Divider 1: /2 */
#define DIVS_2              (0x04)   /* SMCLK Divider 2: /4 */
#define DIVS_3              (0x06)   /* SMCLK Divider 3: /8 */

#define DIVM_0              (0x00)   /* MCLK Divider 0: /1 */
#define DIVM_1              (0x10)   /* MCLK Divider 1: /2 */
#define DIVM_2              (0x20)   /* MCLK Divider 2: /4 */
#define DIVM_3              (0x30)   /* MCLK Divider 3: /8 */

#define SELM_0              (0x00)   /* MCLK Source Select 0: DCOCLK */
#define SELM_1              (0x40)   /* MCLK Source Select 1: DCOCLK */
#define SELM_2              (0x80)   /* MCLK Source Select 2: XT2CLK/LFXTCLK */
#define SELM_3              (0xC0)   /* MCLK Source Select 3: LFXTCLK */

#define LFXT1OF             (0x01)   /* Low/high Frequency Oscillator Fault Flag */
#define XT2OF               (0x02)   /* High frequency oscillator 2 fault flag */
#define XCAP0               (0x04)   /* XIN/XOUT Cap 0 */
#define XCAP1               (0x08)   /* XIN/XOUT Cap 1 */
#define LFXT1S0             (0x10)   /* Mode 0 for LFXT1 (XTS = 0) */
#define LFXT1S1             (0x20)   /* Mode 1 for LFXT1 (XTS = 0) */
#define XT2S0               (0x40)   /* Mode 0 for XT2 */
#define XT2S1               (0x80)   /* Mode 1 for XT2 */

#define XCAP_0              (0x00)   /* XIN/XOUT Cap : 0 pF */
#define XCAP_1              (0x04)   /* XIN/XOUT Cap : 6 pF */
#define XCAP_2              (0x08)   /* XIN/XOUT Cap : 10 pF */
#define XCAP_3              (0x0C)   /* XIN/XOUT Cap : 12.5 pF */

#define LFXT1S_0            (0x00)   /* Mode 0 for LFXT1 : Normal operation */
#define LFXT1S_1            (0x10)   /* Mode 1 for LFXT1 : Reserved */
#define LFXT1S_2            (0x20)   /* Mode 2 for LFXT1 : VLO */
#define LFXT1S_3            (0x30)   /* Mode 3 for LFXT1 : Digital input signal */

#define XT2S_0              (0x00)   /* Mode 0 for XT2 : 0.4 - 1 MHz */
#define XT2S_1              (0x40)   /* Mode 1 for XT2 : 1 - 4 MHz */
#define XT2S_2              (0x80)   /* Mode 2 for XT2 : 2 - 16 MHz */
#define XT2S_3              (0xC0)   /* Mode 3 for XT2 : Digital input signal */

/************************************************************
* Comparator A
************************************************************/
#define __MSP430_HAS_CAPLUS__         /* Definition to show that Module is available */

#define CACTL1_             (0x0059u)  /* Comparator A Control 1 */
DEFC(   CACTL1            , CACTL1_)
#define CACTL2_             (0x005Au)  /* Comparator A Control 2 */
DEFC(   CACTL2            , CACTL2_)
#define CAPD_               (0x005Bu)  /* Comparator A Port Disable */
DEFC(   CAPD              , CAPD_)

#define CAIFG               (0x01)    /* Comp. A Interrupt Flag */
#define CAIE                (0x02)    /* Comp. A Interrupt Enable */
#define CAIES               (0x04)    /* Comp. A Int. Edge Select: 0:rising / 1:falling */
#define CAON                (0x08)    /* Comp. A enable */
#define CAREF0              (0x10)    /* Comp. A Internal Reference Select 0 */
#define CAREF1              (0x20)    /* Comp. A Internal Reference Select 1 */
#define CARSEL              (0x40)    /* Comp. A Internal Reference Enable */
#define CAEX                (0x80)    /* Comp. A Exchange Inputs */

#define CAREF_0             (0x00)    /* Comp. A Int. Ref. Select 0 : Off */
#define CAREF_1             (0x10)    /* Comp. A Int. Ref. Select 1 : 0.25*Vcc */
#define CAREF_2             (0x20)    /* Comp. A Int. Ref. Select 2 : 0.5*Vcc */
#define CAREF_3             (0x30)    /* Comp. A Int. Ref. Select 3 : Vt*/

#define CAOUT               (0x01)    /* Comp. A Output */
#define CAF                 (0x02)    /* Comp. A Enable Output Filter */
#define P2CA0               (0x04)    /* Comp. A +Terminal Multiplexer */
#define P2CA1               (0x08)    /* Comp. A -Terminal Multiplexer */
#define P2CA2               (0x10)    /* Comp. A -Terminal Multiplexer */
#define P2CA3               (0x20)    /* Comp. A -Terminal Multiplexer */
#define P2CA4               (0x40)    /* Comp. A +Terminal Multiplexer */
#define CASHORT             (0x80)    /* Comp. A Short + and - Terminals */

#define CAPD0               (0x01)    /* Comp. A Disable Input Buffer of Port Register .0 */
#define CAPD1               (0x02)    /* Comp. A Disable Input Buffer of Port Register .1 */
#define CAPD2               (0x04)    /* Comp. A Disable Input Buffer of Port Register .2 */
#define CAPD3               (0x08)    /* Comp. A Disable Input Buffer of Port Register .3 */
#define CAPD4               (0x10)    /* Comp. A Disable Input Buffer of Port Register .4 */
#define CAPD5               (0x20)    /* Comp. A Disable Input Buffer of Port Register .5 */
#define CAPD6               (0x40)    /* Comp. A Disable Input Buffer of Port Register .6 */
#define CAPD7               (0x80)    /* Comp. A Disable Input Buffer of Port Register .7 */

/*************************************************************
* Flash Memory
*************************************************************/
#define __MSP430_HAS_FLASH2__         /* Definition to show that Module is available */

#define FCTL1_              (0x0128u)  /* FLASH Control 1 */
DEFW(   FCTL1             , FCTL1_)
#define FCTL2_              (0x012Au)  /* FLASH Control 2 */
DEFW(   FCTL2             , FCTL2_)
#define FCTL3_              (0x012Cu)  /* FLASH Control 3 */
DEFW(   FCTL3             , FCTL3_)

#define FRKEY               (0x9600u)  /* Flash key returned by read */
#define FWKEY               (0xA500u)  /* Flash key for write */
#define FXKEY               (0x3300u)  /* for use with XOR instruction */

#define ERASE               (0x0002u)  /* Enable bit for Flash segment erase */
#define MERAS               (0x0004u)  /* Enable bit for Flash mass erase */
#define WRT                 (0x0040u)  /* Enable bit for Flash write */
#define BLKWRT              (0x0080u)  /* Enable bit for Flash segment write */
#define SEGWRT              (0x0080u)  /* old definition */ /* Enable bit for Flash segment write */

#define FN0                 (0x0001u)  /* Divide Flash clock by 1 to 64 using FN0 to FN5 according to: */
#define FN1                 (0x0002u)  /*  32*FN5 + 16*FN4 + 8*FN3 + 4*FN2 + 2*FN1 + FN0 + 1 */
#ifndef FN2
#define FN2                 (0x0004u)
#endif
#ifndef FN3
#define FN3                 (0x0008u)
#endif
#ifndef FN4
#define FN4                 (0x0010u)
#endif
#define FN5                 (0x0020u)
#define FSSEL0              (0x0040u)  /* Flash clock select 0 */        /* to distinguish from USART SSELx */
#define FSSEL1              (0x0080u)  /* Flash clock select 1 */

#define FSSEL_0             (0x0000u)  /* Flash clock select: 0 - ACLK */
#define FSSEL_1             (0x0040u)  /* Flash clock select: 1 - MCLK */
#define FSSEL_2             (0x0080u)  /* Flash clock select: 2 - SMCLK */
#define FSSEL_3             (0x00C0u)  /* Flash clock select: 3 - SMCLK */

#define BUSY                (0x0001u)  /* Flash busy: 1 */
#define KEYV                (0x0002u)  /* Flash Key violation flag */
#define ACCVIFG             (0x0004u)  /* Flash Access violation flag */
#define WAIT                (0x0008u)  /* Wait flag for segment write */
#define LOCK                (0x0010u)  /* Lock bit: 1 - Flash is locked (read only) */
#define EMEX                (0x0020u)  /* Flash Emergency Exit */
#define LOCKA               (0x0040u)  /* Segment A Lock bit: read = 1 - Segment is locked (read only) */
#define FAIL                (0x0080u)  /* Last Program or Erase failed */

/************************************************************
* DIGITAL I/O Port1/2 Pull up / Pull down Resistors
************************************************************/
#define __MSP430_HAS_PORT1_R__        /* Definition to show that Module is available */
#define __MSP430_HAS_PORT2_R__        /* Definition to show that Module is available */

#define P1IN_               (0x0020u)  /* Port 1 Input */
READ_ONLY DEFC( P1IN           , P1IN_)
#define P1OUT_              (0x0021u)  /* Port 1 Output */
DEFC(   P1OUT             , P1OUT_)
#define P1DIR_              (0x0022u)  /* Port 1 Direction */
DEFC(   P1DIR             , P1DIR_)
#define P1IFG_              (0x0023u)  /* Port 1 Interrupt Flag */
DEFC(   P1IFG             , P1IFG_)
#define P1IES_              (0x0024u)  /* Port 1 Interrupt Edge Select */
DEFC(   P1IES             , P1IES_)
#define P1IE_               (0x0025u)  /* Port 1 Interrupt Enable */
DEFC(   P1IE              , P1IE_)
#define P1SEL_              (0x0026u)  /* Port 1 Selection */
DEFC(   P1SEL             , P1SEL_)
#define P1SEL2_             (0x0041u)  /* Port 1 Selection 2 */
DEFC(   P1SEL2            , P1SEL2_)
#define P1REN_              (0x0027u)  /* Port 1 Resistor Enable */
DEFC(   P1REN             , P1REN_)

#define P2IN_               (0x0028u)  /* Port 2 Input */
READ_ONLY DEFC( P2IN           , P2IN_)
#define P2OUT_              (0x0029u)  /* Port 2 Output */
DEFC(   P2OUT             , P2OUT_)
#define P2DIR_              (0x002Au)  /* Port 2 Direction */
DEFC(   P2DIR             , P2DIR_)
#define P2IFG_              (0x002Bu)  /* Port 2 Interrupt Flag */
DEFC(   P2IFG             , P2IFG_)
#define P2IES_              (0x002Cu)  /* Port 2 Interrupt Edge Select */
DEFC(   P2IES             , P2IES_)
#define P2IE_               (0x002Du)  /* Port 2 Interrupt Enable */
DEFC(   P2IE              , P2IE_)
#define P2SEL_              (0x002Eu)  /* Port 2 Selection */
DEFC(   P2SEL             , P2SEL_)
#define P2SEL2_             (0x0042u)  /* Port 2 Selection 2 */
DEFC(   P2SEL2            , P2SEL2_)
#define P2REN_              (0x002Fu)  /* Port 2 Resistor Enable */
DEFC(   P2REN             , P2REN_)

/************************************************************
* Timer0_A3
************************************************************/
#define __MSP430_HAS_TA3__            /* Definition to show that Module is available */

#define TA0IV_              (0x012Eu)  /* Timer0_A3 Interrupt Vector Word */
READ_ONLY DEFW( TA0IV          , TA0IV_)
#define TA0CTL_             (0x0160u)  /* Timer0_A3 Control */
DEFW(   TA0CTL            , TA0CTL_)
#define TA0CCTL0_           (0x0162u)  /* Timer0_A3 Capture/Compare Control 0 */
DEFW(   TA0CCTL0          , TA0CCTL0_)
#define TA0CCTL1_           (0x0164u)  /* Timer0_A3 Capture/Compare Control 1 */
DEFW(   TA0CCTL1          , TA0CCTL1_)
#define TA0CCTL2_           (0x0166u)  /* Timer0_A3 Capture/Compare Control 2 */
DEFW(   TA0CCTL2          , TA0CCTL2_)
#define TA0R_               (0x0170u)  /* Timer0_A3 */
DEFW(   TA0R              , TA0R_)
#define TA0CCR0_            (0x0172u)  /* Timer0_A3 Capture/Compare 0 */
DEFW(   TA0CCR0           , TA0CCR0_)
#define TA0CCR1_            (0x0174u)  /* Timer0_A3 Capture/Compare 1 */
DEFW(   TA0CCR1           , TA0CCR1_)
#define TA0CCR2_            (0x0176u)  /* Timer0_A3 Capture/Compare 2 */
DEFW(   TA0CCR2           , TA0CCR2_)

/* Alternate register names */
#define TAIV                TA0IV     /* Timer A Interrupt Vector Word */
#define TACTL               TA0CTL    /* Timer A Control */
#define TACCTL0             TA0CCTL0  /* Timer A Capture/Compare Control 0 */
#define TACCTL1             TA0CCTL1  /* Timer A Capture/Compare Control 1 */
#define TACCTL2             TA0CCTL2  /* Timer A Capture/Compare Control 2 */
#define TAR                 TA0R      /* Timer A */
#define TACCR0              TA0CCR0   /* Timer A Capture/Compare 0 */
#define TACCR1              TA0CCR1   /* Timer A Capture/Compare 1 */
#define TACCR2              TA0CCR2   /* Timer A Capture/Compare 2 */
#define TAIV_               TA0IV_    /* Timer A Interrupt Vector Word */
#define TACTL_              TA0CTL_   /* Timer A Control */
#define TACCTL0_            TA0CCTL0_ /* Timer A Capture/Compare Control 0 */
#define TACCTL1_            TA0CCTL1_ /* Timer A Capture/Compare Control 1 */
#define TACCTL2_            TA0CCTL2_ /* Timer A Capture/Compare Control 2 */
#define TAR_                TA0R_     /* Timer A */
#define TACCR0_             TA0CCR0_  /* Timer A Capture/Compare 0 */
#define TACCR1_             TA0CCR1_  /* Timer A Capture/Compare 1 */
#define TACCR2_             TA0CCR2_  /* Timer A Capture/Compare 2 */

/* Alternate register names 2 */
#define CCTL0               TACCTL0   /* Timer A Capture/Compare Control 0 */
#define CCTL1               TACCTL1   /* Timer A Capture/Compare Control 1 */
#define CCTL2               TACCTL2   /* Timer A Capture/Compare Control 2 */
#define CCR0                TACCR0    /* Timer A Capture/Compare 0 */
#define CCR1                TACCR1    /* Timer A Capture/Compare 1 */
#define CCR2                TACCR2    /* Timer A Capture/Compare 2 */
#define CCTL0_              TACCTL0_  /* Timer A Capture/Compare Control 0 */
#define CCTL1_              TACCTL1_  /* Timer A Capture/Compare Control 1 */
#define CCTL2_              TACCTL2_  /* Timer A Capture/Compare Control 2 */
#define CCR0_               TACCR0_   /* Timer A Capture/Compare 0 */
#define CCR1_               TACCR1_   /* Timer A Capture/Compare 1 */
#define CCR2_               TACCR2_   /* Timer A Capture/Compare 2 */

#define TASSEL1             (0x0200u)  /* Timer A clock source select 0 */
#define TASSEL0             (0x0100u)  /* Timer A clock source select 1 */
#define ID1                 (0x0080u)  /* Timer A clock input divider 1 */
#define ID0                 (0x0040u)  /* Timer A clock input divider 0 */
#define MC1                 (0x0020u)  /* Timer A mode control 1 */
#define MC0                 (0x0010u)  /* Timer A mode control 0 */
#define TACLR               (0x0004u)  /* Timer A counter clear */
#define TAIE                (0x0002u)  /* Timer A counter interrupt enable */
#define TAIFG               (0x0001u)  /* Timer A counter interrupt flag */

#define MC_0                (0*0x10u)  /* Timer A mode control: 0 - Stop */
#define MC_1                (1*0x10u)  /* Timer A mode control: 1 - Up to CCR0 */
#define MC_2                (2*0x10u)  /* Timer A mode control: 2 - Continous up */
#define MC_3                (3*0x10u)  /* Timer A mode control: 3 - Up/Down */
#define ID_0                (0*0x40u)  /* Timer A input divider: 0 - /1 */
#define ID_1                (1*0x40u)  /* Timer A input divider: 1 - /2 */
#define ID_2                (2*0x40u)  /* Timer A input divider: 2 - /4 */
#define ID_3                (3*0x40u)  /* Timer A input divider: 3 - /8 */
#define TASSEL_0            (0*0x100u) /* Timer A clock source select: 0 - TACLK */
#define TASSEL_1            (1*0x100u) /* Timer A clock source select: 1 - ACLK  */
#define TASSEL_2            (2*0x100u) /* Timer A clock source select: 2 - SMCLK */
#define TASSEL_3            (3*0x100u) /* Timer A clock source select: 3 - INCLK */

#define CM1                 (0x8000u)  /* Capture mode 1 */
#define CM0                 (0x4000u)  /* Capture mode 0 */
#define CCIS1               (0x2000u)  /* Capture input select 1 */
#define CCIS0               (0x1000u)  /* Capture input select 0 */
#define SCS                 (0x0800u)  /* Capture sychronize */
#define SCCI                (0x0400u)  /* Latched capture signal (read) */
#define CAP                 (0x0100u)  /* Capture mode: 1 /Compare mode : 0 */
#define OUTMOD2             (0x0080u)  /* Output mode 2 */
#define OUTMOD1             (0x0040u)  /* Output mode 1 */
#define OUTMOD0             (0x0020u)  /* Output mode 0 */
#define CCIE                (0x0010u)  /* Capture/compare interrupt enable */
#define CCI                 (0x0008u)  /* Capture input signal (read) */
#define OUT                 (0x0004u)  /* PWM Output signal if output mode 0 */
#define COV                 (0x0002u)  /* Capture/compare overflow flag */
#define CCIFG               (0x0001u)  /* Capture/compare interrupt flag */

#define OUTMOD_0            (0*0x20u)  /* PWM output mode: 0 - output only */
#define OUTMOD_1            (1*0x20u)  /* PWM output mode: 1 - set */
#define OUTMOD_2            (2*0x20u)  /* PWM output mode: 2 - PWM toggle/reset */
#define OUTMOD_3            (3*0x20u)  /* PWM output mode: 3 - PWM set/reset */
#define OUTMOD_4            (4*0x20u)  /* PWM output mode: 4 - toggle */
#define OUTMOD_5            (5*0x20u)  /* PWM output mode: 5 - Reset */
#define OUTMOD_6            (6*0x20u)  /* PWM output mode: 6 - PWM toggle/set */
#define OUTMOD_7            (7*0x20u)  /* PWM output mode: 7 - PWM reset/set */
#define CCIS_0              (0*0x1000u) /* Capture input select: 0 - CCIxA */
#define CCIS_1              (1*0x1000u) /* Capture input select: 1 - CCIxB */
#define CCIS_2              (2*0x1000u) /* Capture input select: 2 - GND */
#define CCIS_3              (3*0x1000u) /* Capture input select: 3 - Vcc */
#define CM_0                (0*0x4000u) /* Capture mode: 0 - disabled */
#define CM_1                (1*0x4000u) /* Capture mode: 1 - pos. edge */
#define CM_2                (2*0x4000u) /* Capture mode: 1 - neg. edge */
#define CM_3                (3*0x4000u) /* Capture mode: 1 - both edges */

/* T0_A3IV Definitions */
#define TA0IV_NONE          (0x0000u)    /* No Interrupt pending */
#define TA0IV_TACCR1        (0x0002u)    /* TA0CCR1_CCIFG */
#define TA0IV_TACCR2        (0x0004u)    /* TA0CCR2_CCIFG */
#define TA0IV_6             (0x0006u)    /* Reserved */
#define TA0IV_8             (0x0008u)    /* Reserved */
#define TA0IV_TAIFG         (0x000Au)    /* TA0IFG */

/************************************************************
* USI
************************************************************/
#define __MSP430_HAS_USI__            /* Definition to show that Module is available */

#define USICTL0_            (0x0078)  /* USI  Control Register 0 */
#ifndef __IAR_SYSTEMS_ICC__
DEFC(   USICTL0           , USICTL0_)
#endif
#define USICTL1_            (0x0079)  /* USI  Control Register 1 */
#ifndef __IAR_SYSTEMS_ICC__
DEFC(   USICTL1           , USICTL1_)
#endif
#define USICKCTL_           (0x007A)  /* USI  Clock Control Register */
#ifndef __IAR_SYSTEMS_ICC__
DEFC(   USICKCTL          , USICKCTL_)
#endif
#define USICNT_             (0x007B)  /* USI  Bit Counter Register */
#ifndef __IAR_SYSTEMS_ICC__
DEFC(   USICNT            , USICNT_)
#endif
#define USISRL_             (0x007C)  /* USI  Low Byte Shift Register */
#ifndef __IAR_SYSTEMS_ICC__
DEFC(   USISRL            , USISRL_)
#endif
#define USISRH_             (0x007D)  /* USI  High Byte Shift Register */
#ifndef __IAR_SYSTEMS_ICC__
DEFC(   USISRH            , USISRH_)
#endif
#define USICTL_             (0x0078)  /* USI  Control Register */
#ifndef __IAR_SYSTEMS_ICC__
DEFW(   USICTL            , USICTL_)
#endif

#ifdef __IAR_SYSTEMS_ICC__
__no_init union
{
  struct
  {
    DEFXC                             USICTL0;
    DEFXC                             USICTL1;
  };
  DEFXW                               USICTL;
} @ 0x0078;
#endif
#define USICCTL_            (0x007A)  /* USI  Clock and Counter Control Register */
#ifndef __IAR_SYSTEMS_ICC__
DEFW(   USICCTL           , USICCTL_)
#endif

#ifdef __IAR_SYSTEMS_ICC__
__no_init union
{
  struct
  {
    DEFXC                             USICKCTL;
    DEFXC                             USICNT;
  };
  DEFXW                               USICCTL;
} @ 0x007A;
#endif
#define USISR_              (0x007C)  /* USI  Shift Register */
#ifndef __IAR_SYSTEMS_ICC__
DEFW(   USISR             , USISR_)
#endif

#ifdef __IAR_SYSTEMS_ICC__
__no_init union
{
  struct
  {
    DEFXC                             USISRL;
    DEFXC                             USISRH;
  };
  DEFXW                               USISR;
} @ 0x007C;
#endif

#define USIPE7              (0x80)    /* USI  Port Enable Px.7 */
#define USIPE6              (0x40)    /* USI  Port Enable Px.6 */
#define USIPE5              (0x20)    /* USI  Port Enable Px.5 */
#define USILSB              (0x10)    /* USI  LSB first  1:LSB / 0:MSB */
#define USIMST              (0x08)    /* USI  Master Select  0:Slave / 1:Master */
#define USIGE               (0x04)    /* USI  General Output Enable Latch */
#define USIOE               (0x02)    /* USI  Output Enable */
#define USISWRST            (0x01)    /* USI  Software Reset */

#define USICKPH             (0x80)    /* USI  Sync. Mode: Clock Phase */
#define USII2C              (0x40)    /* USI  I2C Mode */
#define USISTTIE            (0x20)    /* USI  START Condition interrupt enable */
#define USIIE               (0x10)    /* USI  Counter Interrupt enable */
#define USIAL               (0x08)    /* USI  Arbitration Lost */
#define USISTP              (0x04)    /* USI  STOP Condition received */
#define USISTTIFG           (0x02)    /* USI  START Condition interrupt Flag */
#define USIIFG              (0x01)    /* USI  Counter Interrupt Flag */

#define USIDIV2             (0x80)    /* USI  Clock Divider 2 */
#define USIDIV1             (0x40)    /* USI  Clock Divider 1 */
#define USIDIV0             (0x20)    /* USI  Clock Divider 0 */
#define USISSEL2            (0x10)    /* USI  Clock Source Select 2 */
#define USISSEL1            (0x08)    /* USI  Clock Source Select 1 */
#define USISSEL0            (0x04)    /* USI  Clock Source Select 0 */
#define USICKPL             (0x02)    /* USI  Clock Polarity 0:Inactive=Low / 1:Inactive=High */
#define USISWCLK            (0x01)    /* USI  Software Clock */

#define USIDIV_0            (0x00)    /* USI  Clock Divider: 0 */
#define USIDIV_1            (0x20)    /* USI  Clock Divider: 1 */
#define USIDIV_2            (0x40)    /* USI  Clock Divider: 2 */
#define USIDIV_3            (0x60)    /* USI  Clock Divider: 3 */
#define USIDIV_4            (0x80)    /* USI  Clock Divider: 4 */
#define USIDIV_5            (0xA0)    /* USI  Clock Divider: 5 */
#define USIDIV_6            (0xC0)    /* USI  Clock Divider: 6 */
#define USIDIV_7            (0xE0)    /* USI  Clock Divider: 7 */

#define USISSEL_0           (0x00)    /* USI  Clock Source: 0 */
#define USISSEL_1           (0x04)    /* USI  Clock Source: 1 */
#define USISSEL_2           (0x08)    /* USI  Clock Source: 2 */
#define USISSEL_3           (0x0C)    /* USI  Clock Source: 3 */
#define USISSEL_4           (0x10)    /* USI  Clock Source: 4 */
#define USISSEL_5           (0x14)    /* USI  Clock Source: 5 */
#define USISSEL_6           (0x18)    /* USI  Clock Source: 6 */
#define USISSEL_7           (0x1C)    /* USI  Clock Source: 7 */

#define USISCLREL           (0x80)    /* USI  SCL Released */
#define USI16B              (0x40)    /* USI  16 Bit Shift Register Enable */
#define USIIFGCC            (0x20)    /* USI  Interrupt Flag Clear Control */
#define USICNT4             (0x10)    /* USI  Bit Count 4 */
#define USICNT3             (0x08)    /* USI  Bit Count 3 */
#define USICNT2             (0x04)    /* USI  Bit Count 2 */
#define USICNT1             (0x02)    /* USI  Bit Count 1 */
#define USICNT0             (0x01)    /* USI  Bit Count 0 */
/************************************************************
* WATCHDOG TIMER
************************************************************/
#define __MSP430_HAS_WDT__            /* Definition to show that Module is available */

#define WDTCTL_             (0x0120u)  /* Watchdog Timer Control */
DEFW(   WDTCTL            , WDTCTL_)
/* The bit names have been prefixed with "WDT" */
#define WDTIS0              (0x0001u)
#define WDTIS1              (0x0002u)
#define WDTSSEL             (0x0004u)
#define WDTCNTCL            (0x0008u)
#define WDTTMSEL            (0x0010u)
#define WDTNMI              (0x0020u)
#define WDTNMIES            (0x0040u)
#define WDTHOLD             (0x0080u)

#define WDTPW               (0x5A00u)

/* WDT-interval times [1ms] coded with Bits 0-2 */
/* WDT is clocked by fSMCLK (assumed 1MHz) */
#define WDT_MDLY_32         (WDTPW+WDTTMSEL+WDTCNTCL)                         /* 32ms interval (default) */
#define WDT_MDLY_8          (WDTPW+WDTTMSEL+WDTCNTCL+WDTIS0)                  /* 8ms     " */
#define WDT_MDLY_0_5        (WDTPW+WDTTMSEL+WDTCNTCL+WDTIS1)                  /* 0.5ms   " */
#define WDT_MDLY_0_064      (WDTPW+WDTTMSEL+WDTCNTCL+WDTIS1+WDTIS0)           /* 0.064ms " */
/* WDT is clocked by fACLK (assumed 32KHz) */
#define WDT_ADLY_1000       (WDTPW+WDTTMSEL+WDTCNTCL+WDTSSEL)                 /* 1000ms  " */
#define WDT_ADLY_250        (WDTPW+WDTTMSEL+WDTCNTCL+WDTSSEL+WDTIS0)          /* 250ms   " */
#define WDT_ADLY_16         (WDTPW+WDTTMSEL+WDTCNTCL+WDTSSEL+WDTIS1)          /* 16ms    " */
#define WDT_ADLY_1_9        (WDTPW+WDTTMSEL+WDTCNTCL+WDTSSEL+WDTIS1+WDTIS0)   /* 1.9ms   " */
/* Watchdog mode -> reset after expired time */
/* WDT is clocked by fSMCLK (assumed 1MHz) */
#define WDT_MRST_32         (WDTPW+WDTCNTCL)                                  /* 32ms interval (default) */
#define WDT_MRST_8          (WDTPW+WDTCNTCL+WDTIS0)                           /* 8ms     " */
#define WDT_MRST_0_5        (WDTPW+WDTCNTCL+WDTIS1)                           /* 0.5ms   " */
#define WDT_MRST_0_064      (WDTPW+WDTCNTCL+WDTIS1+WDTIS0)                    /* 0.064ms " */
/* WDT is clocked by fACLK (assumed 32KHz) */
#define WDT_ARST_1000       (WDTPW+WDTCNTCL+WDTSSEL)                          /* 1000ms  " */
#define WDT_ARST_250        (WDTPW+WDTCNTCL+WDTSSEL+WDTIS0)                   /* 250ms   " */
#define WDT_ARST_16         (WDTPW+WDTCNTCL+WDTSSEL+WDTIS1)                   /* 16ms    " */
#define WDT_ARST_1_9        (WDTPW+WDTCNTCL+WDTSSEL+WDTIS1+WDTIS0)            /* 1.9ms   " */

/* INTERRUPT CONTROL */
/* These two bits are defined in the Special Function Registers */
/* #define WDTIE               0x01 */
/* #define WDTIFG              0x01 */

/************************************************************
* Calibration Data in Info Mem
************************************************************/

#ifndef __DisableCalData

#define CALDCO_16MHZ_         (0x10F8u)  /* DCOCTL  Calibration Data for 16MHz */
READ_ONLY DEFC( CALDCO_16MHZ     , CALDCO_16MHZ_)
#define CALBC1_16MHZ_         (0x10F9u)  /* BCSCTL1 Calibration Data for 16MHz */
READ_ONLY DEFC( CALBC1_16MHZ     , CALBC1_16MHZ_)
#define CALDCO_12MHZ_         (0x10FAu)  /* DCOCTL  Calibration Data for 12MHz */
READ_ONLY DEFC( CALDCO_12MHZ     , CALDCO_12MHZ_)
#define CALBC1_12MHZ_         (0x10FBu)  /* BCSCTL1 Calibration Data for 12MHz */
READ_ONLY DEFC( CALBC1_12MHZ     , CALBC1_12MHZ_)
#define CALDCO_8MHZ_          (0x10FCu)  /* DCOCTL  Calibration Data for 8MHz */
READ_ONLY DEFC( CALDCO_8MHZ      , CALDCO_8MHZ_)
#define CALBC1_8MHZ_          (0x10FDu)  /* BCSCTL1 Calibration Data for 8MHz */
READ_ONLY DEFC( CALBC1_8MHZ      , CALBC1_8MHZ_)
#define CALDCO_1MHZ_          (0x10FEu)  /* DCOCTL  Calibration Data for 1MHz */
READ_ONLY DEFC( CALDCO_1MHZ      , CALDCO_1MHZ_)
#define CALBC1_1MHZ_          (0x10FFu)  /* BCSCTL1 Calibration Data for 1MHz */
READ_ONLY DEFC( CALBC1_1MHZ      , CALBC1_1MHZ_)

#endif /* #ifndef __DisableCalData */

/************************************************************
* Interrupt Vectors (offset from 0xFFE0)
************************************************************/

#define PORT1_VECTOR        (2 * 2u)  /* 0xFFE4 Port 1 */
#define PORT2_VECTOR        (3 * 2u)  /* 0xFFE6 Port 2 */
#define USI_VECTOR          (4 * 2u)  /* 0xFFE8 USI */
#define ADC10_VECTOR        (5 * 2u)  /* 0xFFEA ADC10 */
#define TIMER0_A1_VECTOR    (8 * 2u)  /* 0xFFF0 Timer0_A CC1, TA */
#define TIMER0_A0_VECTOR    (9 * 2u)  /* 0xFFF2 Timer0_A CC0 */
#define WDT_VECTOR          (10 * 2u) /* 0xFFF4 Watchdog Timer */
#define COMPARATORA_VECTOR  (11 * 2u) /* 0xFFF6 Comparator A */
#define NMI_VECTOR          (14 * 2u) /* 0xFFFC Non-maskable */
#define RESET_VECTOR        (15 * 2u) /* 0xFFFE Reset [Highest Priority] */

/************************************************************
* End of Modules
************************************************************/
#pragma language=default

#endif /* #ifndef __MSP430G2452 */

