/* --COPYRIGHT--,BSD
 * Copyright (c) 2015, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * --/COPYRIGHT--*/
#ifndef _GPIO_H_
#define _GPIO_H_

//! \file   drivers/gpio/src/32b/f28x/f2806x/gpio.h
//! \brief  Contains public interface to general purpose I/O (GPIO) methods
//!
//! (C) Copyright 2015, Texas Instruments, Inc.


// **************************************************************************
// the includes

#include "sw/modules/types/src/types.h"

#include "sw/drivers/cpu/src/32b/f28x/f2806x/cpu.h"


//!
//!
//! \defgroup GPIO GPIO
//!
//@{


#ifdef __cplusplus
extern "C" {
#endif


// **************************************************************************
// the defines

//! \brief Defines the base address of the general purpose I/O (GPIO) registers
//!
#define  GPIO_BASE_ADDR        (0x00006F80)


//! \brief Defines the location of the CONFIG bits in the GPMUX register
//!
#define  GPIO_GPMUX_CONFIG_BITS    (3 << 0)
//! \brief Defines number of GPIOs covered by each GPxMUX register
//!
#define GPIO_GPMUX_NUMGPIOS_PER_REG     16


//! \brief Defines the location of the GPIOx bits in the GPxQSELy register
//!
#define  GPIO_GPxQSELy_GPIOx_BITS          3

//! \brief Defines number of GPIOs covered by each GPxQSELy register
//!
#define GPIO_GPxQSELx_NUMGPIOS_PER_REG  16


//! \brief Defines the location of the GPIOx bits in the GPxQSELy register
//!
#define  GPIO_GPxCTRL_QUALPRDx_BITS        0xFF

//! \brief Defines number of bits per QUALPRDx field per GPxCTRL register
//!
#define GPIO_GPxCTRL_QUALPRDx_NUMBITS_PER_REG   8


// **************************************************************************
// the typedefs

//! \brief Enumeration to define the general purpose I/O (GPIO) modes for each pin
//!
typedef enum
{
  GPIO_0_Mode_GeneralPurpose=0,    //!< Denotes a general purpose function
  GPIO_0_Mode_EPWM1A,              //!< Denotes a EPWM1A function
  GPIO_0_Mode_Rsvd_2,              //!< Denotes a reserved function
  GPIO_0_Mode_Rsvd_3,              //!< Denotes a reserved function
  GPIO_1_Mode_GeneralPurpose=0,    //!< Denotes a general purpose function
  GPIO_1_Mode_EPWM1B,              //!< Denotes a EPWM1B function
  GPIO_1_Mode_Rsvd_2,              //!< Denotes a reserved function
  GPIO_1_Mode_COMP1OUT,            //!< Denotes a COMP1OUT function
  GPIO_2_Mode_GeneralPurpose=0,    //!< Denotes a general purpose function
  GPIO_2_Mode_EPWM2A,              //!< Denotes a EPWM2A function
  GPIO_2_Mode_Rsvd_2,              //!< Denotes a reserved function
  GPIO_2_Mode_Rsvd_3,              //!< Denotes a reserved function
  GPIO_3_Mode_GeneralPurpose=0,    //!< Denotes a general purpose function
  GPIO_3_Mode_EPWM2B,              //!< Denotes a EPWM2B function
  GPIO_3_Mode_SPISOMIA,            //!< Denotes a SPISOMIA function
  GPIO_3_Mode_COMP2OUT,            //!< Denotes a COMP2OUT function
  GPIO_4_Mode_GeneralPurpose=0,    //!< Denotes a general purpose function
  GPIO_4_Mode_EPWM3A,              //!< Denotes a EPWM3A function
  GPIO_4_Mode_Rsvd_2,              //!< Denotes a reserved function
  GPIO_4_Mode_Rsvd_3,              //!< Denotes a reserved function
  GPIO_5_Mode_GeneralPurpose=0,    //!< Denotes a general purpose function
  GPIO_5_Mode_EPWM3B,              //!< Denotes a EPWM3B function
  GPIO_5_Mode_SPISIMOA,            //!< Denotes a SPISOMIA function
  GPIO_5_Mode_ECAP1,               //!< Denotes a ECAP1 function
  GPIO_6_Mode_GeneralPurpose=0,    //!< Denotes a general purpose function
  GPIO_6_Mode_EPWM4A,              //!< Denotes a EPWM4A function
  GPIO_6_Mode_EPWMSYNCI,           //!< Denotes a EPWMSYNCI function
  GPIO_6_Mode_EPWMSYNCO,           //!< Denotes a EPWMSYNCO function
  GPIO_7_Mode_GeneralPurpose=0,    //!< Denotes a general purpose function
  GPIO_7_Mode_EPWM4B,              //!< Denotes a EPWM4B function
  GPIO_7_Mode_SCIRXDA,             //!< Denotes a SCIRXDA function
  GPIO_7_Mode_ECAP2,               //!< Denotes a ECAP2 function
  GPIO_8_Mode_GeneralPurpose=0,    //!< Denotes a general purpose function
  GPIO_8_Mode_EPWM5A,              //!< Denotes a EPWM5A function
  GPIO_8_Mode_Rsvd_2,              //!< Denotes a reserved function
  GPIO_8_Mode_ADCSOCAO_NOT,        //!< Denotes a ADCSICAO_NOT function
  GPIO_9_Mode_GeneralPurpose=0,    //!< Denotes a general purpose function
  GPIO_9_Mode_EPWM5B,              //!< Denotes a EPWM5B function
  GPIO_9_Mode_SCITXDB,             //!< Denotes a SCITXDB function
  GPIO_9_Mode_ECAP3,               //!< Denotes a ECAP3 function
  GPIO_10_Mode_GeneralPurpose=0,   //!< Denotes a general purpose function
  GPIO_10_Mode_EPWM6A,             //!< Denotes a EPWM6A function
  GPIO_10_Mode_Rsvd_2,             //!< Denotes a reserved function
  GPIO_10_Mode_ADCSOCBO_NOT,       //!< Denotes a ADCSOCBO_NOT function
  GPIO_11_Mode_GeneralPurpose=0,   //!< Denotes a general purpose function
  GPIO_11_Mode_EPWM6B,             //!< Denotes a EPWM6B function
  GPIO_11_Mode_SCIRXDB,            //!< Denotes a SCIRXDB function
  GPIO_11_Mode_ECAP1,              //!< Denotes a ECAP1 function
  GPIO_12_Mode_GeneralPurpose=0,   //!< Denotes a general purpose function
  GPIO_12_Mode_TZ1_NOT,            //!< Denotes a TZ1_NOT function
  GPIO_12_Mode_SCITXDA,            //!< Denotes a SCITXDA function
  GPIO_12_Mode_SPISIMOB,           //!< Denotes a SPISIMOB function
  GPIO_13_Mode_GeneralPurpose=0,   //!< Denotes a general purpose function
  GPIO_13_Mode_TZ2_NOT,            //!< Denotes a TZ2_NOT function
  GPIO_13_Mode_Rsvd_2,             //!< Denotes a reserved function
  GPIO_13_Mode_SPISOMIB,           //!< Denotes a SPISOMIB function
  GPIO_14_Mode_GeneralPurpose=0,   //!< Denotes a general purpose function
  GPIO_14_Mode_TZ3_NOT,            //!< Denotes a TZ3_NOT function
  GPIO_14_Mode_SCITXDB,            //!< Denotes a SCITXDB function
  GPIO_14_Mode_SPICLKB,            //!< Denotes a SPICLKB function
  GPIO_15_Mode_GeneralPurpose=0,   //!< Denotes a general purpose function
  GPIO_15_Mode_ECAP2,              //!< Denotes a ECAP2 function
  GPIO_15_Mode_SCIRXDB,            //!< Denotes a SCIRXDB function
  GPIO_15_Mode_SPISTEB_NOT,        //!< Denotes a SPISTEB_NOT function
  GPIO_16_Mode_GeneralPurpose=0,   //!< Denotes a general purpose function
  GPIO_16_Mode_SPISIMOA,           //!< Denotes a SPISIMOA function
  GPIO_16_Mode_Rsvd_2,             //!< Denotes a reserved function
  GPIO_16_Mode_TZ2_NOT,            //!< Denotes a TZ2_NOT function
  GPIO_17_Mode_GeneralPurpose=0,   //!< Denotes a general purpose function
  GPIO_17_Mode_SPISOMIA,           //!< Denotes a SPISOMIA function
  GPIO_17_Mode_Rsvd_2,             //!< Denotes a reserved function
  GPIO_17_Mode_TZ3_NOT,            //!< Denotes a TZ3_NOT function
  GPIO_18_Mode_GeneralPurpose=0,   //!< Denotes a general purpose function
  GPIO_18_Mode_SPICLKA,            //!< Denotes a SPICLKA function
  GPIO_18_Mode_SCITXDB,            //!< Denotes a SCITXDB function
  GPIO_18_Mode_XCLKOUT,            //!< Denotes a XCLKOUT function
  GPIO_19_Mode_GeneralPurpose=0,   //!< Denotes a general purpose function
  GPIO_19_Mode_SPISTEA_NOT,        //!< Denotes a SPISTEA_NOT function
  GPIO_19_Mode_SCIRXDB,            //!< Denotes a SCIRXDB function
  GPIO_19_Mode_ECAP1,              //!< Denotes a ECAP1 function
  GPIO_20_Mode_GeneralPurpose=0,   //!< Denotes a general purpose function
  GPIO_20_Mode_EQEP1A,             //!< Denotes a EQEP1A function
  GPIO_20_Mode_MDXA,               //!< Denotes a MDXA function
  GPIO_20_Mode_COMP1OUT,           //!< Denotes a COMP1OUT function
  GPIO_21_Mode_GeneralPurpose=0,   //!< Denotes a general purpose function
  GPIO_21_Mode_EQEP1B,             //!< Denotes a EQEP1B function
  GPIO_21_Mode_MDRA,               //!< Denotes a MDRA function
  GPIO_21_Mode_COMP2OUT,           //!< Denotes a COMP2OUT function
  GPIO_22_Mode_GeneralPurpose=0,   //!< Denotes a general purpose function
  GPIO_22_Mode_EQEP1S,             //!< Denotes a EQEP1S function
  GPIO_22_Mode_MCLKXA,             //!< Denotes a MCLKXA function
  GPIO_22_Mode_SCITXDB,            //!< Denotes a SCITXDB function
  GPIO_23_Mode_GeneralPurpose=0,   //!< Denotes a general purpose function
  GPIO_23_Mode_EQEP1I,             //!< Denotes a EQEP1I function
  GPIO_23_Mode_MFSXA,              //!< Denotes a MFSXA function
  GPIO_23_Mode_SCIRXDB,            //!< Denotes a SCIRXDB function
  GPIO_24_Mode_GeneralPurpose=0,   //!< Denotes a general purpose function
  GPIO_24_Mode_ECAP1,              //!< Denotes a ECAP1 function
  GPIO_24_Mode_EQEP2A,             //!< Denotes a EQEP2A function
  GPIO_24_Mode_SPISIMOB,           //!< Denotes a SPISIMOB function
  GPIO_25_Mode_GeneralPurpose=0,   //!< Denotes a general purpose function
  GPIO_25_Mode_ECAP2,              //!< Denotes a ECAP2 function
  GPIO_25_Mode_EQEP2B,             //!< Denotes a EQEP2B function
  GPIO_25_Mode_SPISOMIB,           //!< Denotes a SPISOMIB function
  GPIO_26_Mode_GeneralPurpose=0,   //!< Denotes a general purpose function
  GPIO_26_Mode_ECAP3,              //!< Denotes a ECAP3 function
  GPIO_26_Mode_EQEP2I,             //!< Denotes a EQEP2I function
  GPIO_26_Mode_SPICLKB,            //!< Denotes a SPICLKB function
  GPIO_27_Mode_GeneralPurpose=0,   //!< Denotes a general purpose function
  GPIO_27_Mode_HRCAP2,             //!< Denotes a HRCAP2 function
  GPIO_27_Mode_EQEP2S,             //!< Denotes a EQEP2S function
  GPIO_27_Mode_SPISTEB_NOT,        //!< Denotes a SPISTEB function
  GPIO_28_Mode_GeneralPurpose=0,   //!< Denotes a general purpose function
  GPIO_28_Mode_SCIRXDA,            //!< Denotes a SCIRXDA function
  GPIO_28_Mode_SDDA,               //!< Denotes a SDDA function
  GPIO_28_Mode_TZ2_NOT,            //!< Denotes a TZ2_NOT function
  GPIO_29_Mode_GeneralPurpose=0,   //!< Denotes a general purpose function
  GPIO_29_Mode_SCITXDA,            //!< Denotes a SCITXDA function
  GPIO_29_Mode_SCLA,               //!< Denotes a SCLA function
  GPIO_29_Mode_TZ3_NOT,            //!< Denotes a TZ3_NOT function
  GPIO_30_Mode_GeneralPurpose=0,   //!< Denotes a general purpose function
  GPIO_30_Mode_CANRXA,             //!< Denotes a CANRXA function
  GPIO_30_Mode_EQEP2I,             //!< Denotes a EQEP2I function
  GPIO_30_Mode_EPWM7A,             //!< Denotes a EPWM7A function
  GPIO_31_Mode_GeneralPurpose=0,   //!< Denotes a general purpose function
  GPIO_31_Mode_CANTXA,             //!< Denotes a CANTXA function
  GPIO_31_Mode_EQEP2S,             //!< Denotes a EQEP2S function
  GPIO_31_Mode_EPWM8A,             //!< Denotes a EPWM8A function
  GPIO_32_Mode_GeneralPurpose=0,   //!< Denotes a general purpose function
  GPIO_32_Mode_SDDA,               //!< Denotes a SDDA function
  GPIO_32_Mode_EPWMSYNCI,          //!< Denotes a EPWMSYNCI function
  GPIO_32_Mode_ADCSOCAO_NOT,       //!< Denotes a ADCSOCAO_NOT function
  GPIO_33_Mode_GeneralPurpose=0,   //!< Denotes a general purpose function
  GPIO_33_Mode_SCLA,               //!< Denotes a SCLA function
  GPIO_33_Mode_EPWMSYNCO,          //!< Denotes a EPWMSYNCO function
  GPIO_33_Mode_ADCSOCBO_NOT,       //!< Denotes a ADCSOCBO_NOT function
  GPIO_34_Mode_GeneralPurpose=0,   //!< Denotes a general purpose function
  GPIO_34_Mode_COMP2OUT,           //!< Denotes a COMP2OUT function
  GPIO_34_Mode_Rsvd_2,             //!< Denotes a reserved function
  GPIO_34_Mode_COMP3OUT,           //!< Denotes a COMP3OUT function
  GPIO_35_Mode_JTAG_TDI=0,         //!< Denotes a JTAG_TDI function
  GPIO_35_Mode_Rsvd_1,             //!< Denotes a reserved function
  GPIO_35_Mode_Rsvd_2,             //!< Denotes a reserved function
  GPIO_35_Mode_Rsvd_3,             //!< Denotes a reserved function
  GPIO_36_Mode_JTAG_TMS=0,         //!< Denotes a JTAG_TMS function
  GPIO_36_Mode_Rsvd_1,             //!< Denotes a reserved function
  GPIO_36_Mode_Rsvd_2,             //!< Denotes a reserved function
  GPIO_36_Mode_Rsvd_3,             //!< Denotes a reserved function
  GPIO_37_Mode_JTAG_TDO=0,         //!< Denotes a JTAG_TDO function
  GPIO_37_Mode_Rsvd_1,             //!< Denotes a reserved function
  GPIO_37_Mode_Rsvd_2,             //!< Denotes a reserved function
  GPIO_37_Mode_Rsvd_3,             //!< Denotes a reserved function
  GPIO_38_Mode_JTAG_TCK=0,         //!< Denotes a JTAG_TCK function
  GPIO_38_Mode_Rsvd_1,             //!< Denotes a reserved function
  GPIO_38_Mode_Rsvd_2,             //!< Denotes a reserved function
  GPIO_38_Mode_Rsvd_3,             //!< Denotes a reserved function
  GPIO_39_Mode_GeneralPurpose=0,   //!< Denotes a general purpose function
  GPIO_39_Mode_Rsvd_1,             //!< Denotes a reserved function
  GPIO_39_Mode_Rsvd_2,             //!< Denotes a reserved function
  GPIO_39_Mode_Rsvd_3,             //!< Denotes a reserved function
  GPIO_40_Mode_GeneralPurpose=0,   //!< Denotes a general purpose function
  GPIO_40_Mode_EPWM7A,             //!< Denotes a EPWM7A function
  GPIO_40_Mode_SCITXDB,            //!< Denotes a SCITXDB function
  GPIO_40_Mode_Rsvd_3,             //!< Denotes a reserved function
  GPIO_41_Mode_GeneralPurpose=0,   //!< Denotes a general purpose function
  GPIO_41_Mode_EPWM7B,             //!< Denotes a EPWM7B function
  GPIO_41_Mode_SCIRXDB,            //!< Denotes a SCIRXDB function
  GPIO_41_Mode_Rsvd_3,             //!< Denotes a reserved function
  GPIO_42_Mode_GeneralPurpose=0,   //!< Denotes a general purpose function
  GPIO_42_Mode_EPWM8A,             //!< Denotes a EPWM8A function
  GPIO_42_Mode_TZ1_NOT,            //!< Denotes a TZ1_NOT function
  GPIO_42_Mode_COMP1OUT,           //!< Denotes a COMP1OUT function
  GPIO_43_Mode_GeneralPurpose=0,   //!< Denotes a general purpose function
  GPIO_43_Mode_EPWM8B,             //!< Denotes a EPWM8B function
  GPIO_43_Mode_TZ2_NOT,            //!< Denotes a TZ2_NOT function
  GPIO_43_Mode_COMP2OUT,           //!< Denotes a COMP2OUT function
  GPIO_44_Mode_GeneralPurpose=0,   //!< Denotes a general purpose function
  GPIO_44_Mode_MFSRA,              //!< Denotes a MFSRA function
  GPIO_44_Mode_SCIRXDB,            //!< Denotes a SCIRXDB function
  GPIO_44_Mode_EPWM7B,             //!< Denotes a EPWM7B function
  GPIO_50_Mode_GeneralPurpose=0,   //!< Denotes a general purpose function
  GPIO_50_Mode_EQEP1A,             //!< Denotes a EQEP1A function
  GPIO_50_Mode_MDXA,               //!< Denotes a MDXA function
  GPIO_50_Mode_TZ1_NOT,            //!< Denotes a TZ1_NOT function
  GPIO_51_Mode_GeneralPurpose=0,   //!< Denotes a general purpose function
  GPIO_51_Mode_EQEP1B,             //!< Denotes a EQEP1B function
  GPIO_51_Mode_MDRA,               //!< Denotes a MDRA function
  GPIO_51_Mode_TZ2_NOT,            //!< Denotes a TZ2_NOT function
  GPIO_52_Mode_GeneralPurpose=0,   //!< Denotes a general purpose function
  GPIO_52_Mode_EQEP1S,             //!< Denotes a EQEP1S function
  GPIO_52_Mode_MCLKXA,             //!< Denotes a MCLKXA function
  GPIO_52_Mode_TZ3_NOT,            //!< Denotes a TZ3_NOT function
  GPIO_53_Mode_GeneralPurpose=0,   //!< Denotes a general purpose function
  GPIO_53_Mode_EQEP1I,             //!< Denotes a EQEP1I function
  GPIO_53_Mode_MFSXA,              //!< Denotes a MFSXA function
  GPIO_53_Mode_Rsvd_1,             //!< Denotes a reserved function
  GPIO_54_Mode_GeneralPurpose=0,   //!< Denotes a general purpose function
  GPIO_54_Mode_SPISIMOA,           //!< Denotes a SPISIMOA function
  GPIO_54_Mode_EQEP2A,             //!< Denotes a EQEP2A function
  GPIO_54_Mode_HRCAP1,             //!< Denotes a HRCAP1 function
  GPIO_55_Mode_GeneralPurpose=0,   //!< Denotes a general purpose function
  GPIO_55_Mode_SPISOMIA,           //!< Denotes a SPISOMIA function
  GPIO_55_Mode_EQEP2B,             //!< Denotes a EQEP2B function
  GPIO_55_Mode_HRCAP2,             //!< Denotes a HRCAP2 function
  GPIO_56_Mode_GeneralPurpose=0,   //!< Denotes a general purpose function
  GPIO_56_Mode_SPICLKA,            //!< Denotes a SPICLKA function
  GPIO_56_Mode_EQEP2I,             //!< Denotes a EQEP2I function
  GPIO_56_Mode_HRCAP3,             //!< Denotes a HRCAP3 function
  GPIO_57_Mode_GeneralPurpose=0,   //!< Denotes a general purpose function
  GPIO_57_Mode_SPISTEA_NOT,        //!< Denotes a SPISTEA_NOT function
  GPIO_57_Mode_EQEP2S,             //!< Denotes a EQEP2S function
  GPIO_57_Mode_HRCAP4,             //!< Denotes a HRCAP4 function
  GPIO_58_Mode_GeneralPurpose=0,   //!< Denotes a general purpose function
  GPIO_58_Mode_MCLKRA,             //!< Denotes a MCLKRA function
  GPIO_58_Mode_SCITXDB,            //!< Denotes a SCITXDB function
  GPIO_58_Mode_EPWM7A              //!< Denotes a EPWM7A function
} GPIO_Mode_e;


//! \brief Enumeration to define the general purpose I/O (GPIO) directions
//!
typedef enum
{
  GPIO_Direction_Input=0,    //!< Denotes an input direction
  GPIO_Direction_Output      //!< Denotes an output direction
} GPIO_Direction_e;


//! \brief Enumeration to define the general purpose I/O (GPIO) pullups
//!
typedef enum
{
  GPIO_Pullup_Enable=0,    //!< Denotes a pullup enabled
  GPIO_Pullup_Disable      //!< Denotes a pullup disabled
} GPIO_Pullup_e;


//! \brief Enumeration to define the general purpose I/O (GPIO) qualification
//!
typedef enum
{
  GPIO_Qual_Sync = 0,      //!< Denotes input will be synchronized to SYSCLK
  GPIO_Qual_Sample_3,      //!< Denotes input is qualified with 3 samples
  GPIO_Qual_Sample_6,      //!< Denotes input is qualified with 6 samples
  GPIO_Qual_ASync          //!< Denotes input is asynchronous
} GPIO_Qual_e;


//! \brief Enumeration to define the general purpose I/O (GPIO) ports
//!
typedef enum
{
  GPIO_Port_A = 0,    //!< GPIO Port A
  GPIO_Port_B         //!< GPIO Port B
} GPIO_Port_e;


//! \brief Enumeration to define the general purpose I/O (GPIO) numbers
//!
typedef enum
{
  GPIO_Number_0=0,    //!< Denotes GPIO number 0
  GPIO_Number_1,      //!< Denotes GPIO number 1
  GPIO_Number_2,      //!< Denotes GPIO number 2
  GPIO_Number_3,      //!< Denotes GPIO number 3
  GPIO_Number_4,      //!< Denotes GPIO number 4
  GPIO_Number_5,      //!< Denotes GPIO number 5
  GPIO_Number_6,      //!< Denotes GPIO number 6
  GPIO_Number_7,      //!< Denotes GPIO number 7
  GPIO_Number_8,      //!< Denotes GPIO number 8
  GPIO_Number_9,      //!< Denotes GPIO number 9
  GPIO_Number_10,     //!< Denotes GPIO number 10
  GPIO_Number_11,     //!< Denotes GPIO number 11
  GPIO_Number_12,     //!< Denotes GPIO number 12
  GPIO_Number_13,     //!< Denotes GPIO number 13
  GPIO_Number_14,     //!< Denotes GPIO number 14
  GPIO_Number_15,     //!< Denotes GPIO number 15
  GPIO_Number_16,     //!< Denotes GPIO number 16
  GPIO_Number_17,     //!< Denotes GPIO number 17
  GPIO_Number_18,     //!< Denotes GPIO number 18
  GPIO_Number_19,     //!< Denotes GPIO number 19
  GPIO_Number_20,     //!< Denotes GPIO number 20
  GPIO_Number_21,     //!< Denotes GPIO number 21
  GPIO_Number_22,     //!< Denotes GPIO number 22
  GPIO_Number_23,     //!< Denotes GPIO number 23
  GPIO_Number_24,     //!< Denotes GPIO number 24
  GPIO_Number_25,     //!< Denotes GPIO number 25
  GPIO_Number_26,     //!< Denotes GPIO number 26
  GPIO_Number_27,     //!< Denotes GPIO number 27
  GPIO_Number_28,     //!< Denotes GPIO number 28
  GPIO_Number_29,     //!< Denotes GPIO number 29
  GPIO_Number_30,     //!< Denotes GPIO number 30
  GPIO_Number_31,     //!< Denotes GPIO number 31
  GPIO_Number_32,     //!< Denotes GPIO number 32
  GPIO_Number_33,     //!< Denotes GPIO number 33
  GPIO_Number_34,     //!< Denotes GPIO number 34
  GPIO_Number_35,     //!< Denotes GPIO number 35
  GPIO_Number_36,     //!< Denotes GPIO number 36
  GPIO_Number_37,     //!< Denotes GPIO number 37
  GPIO_Number_38,     //!< Denotes GPIO number 38
  GPIO_Number_39,     //!< Denotes GPIO number 39
  GPIO_Number_40,     //!< Denotes GPIO number 40
  GPIO_Number_41,     //!< Denotes GPIO number 41
  GPIO_Number_42,     //!< Denotes GPIO number 42
  GPIO_Number_43,     //!< Denotes GPIO number 43
  GPIO_Number_44,     //!< Denotes GPIO number 44
  GPIO_Number_50=50,  //!< Denotes GPIO number 50
  GPIO_Number_51,     //!< Denotes GPIO number 51
  GPIO_Number_52,     //!< Denotes GPIO number 52
  GPIO_Number_53,     //!< Denotes GPIO number 53
  GPIO_Number_54,     //!< Denotes GPIO number 54
  GPIO_Number_55,     //!< Denotes GPIO number 55
  GPIO_Number_56,     //!< Denotes GPIO number 56
  GPIO_Number_57,     //!< Denotes GPIO number 57
  GPIO_Number_58,     //!< Denotes GPIO number 58
  GPIO_numGpios
} GPIO_Number_e;


//! \brief Defines the General Purpose I/O (GPIO) object
//!
typedef struct _GPIO_Obj_
{
  volatile uint32_t GPACTRL;         //!< GPIO A Control Register
  volatile uint32_t GPAQSEL1;        //!< GPIO A Qualifier Select 1 Register
  volatile uint32_t GPAQSEL2;        //!< GPIO A Qualifier Select 2 Register
  volatile uint32_t GPAMUX1;         //!< GPIO A MUX 1 Register
  volatile uint32_t GPAMUX2;         //!< GPIO A MUX 2 Register
  volatile uint32_t GPADIR;          //!< GPIO A Direction Register
  volatile uint32_t GPAPUD;          //!< GPIO A Pull Up Disable Register
  volatile uint16_t rsvd_1[2];       //!< Reserved
  volatile uint32_t GPBCTRL;         //!< GPIO B Control Register
  volatile uint32_t GPBQSEL1;        //!< GPIO B Qualifier Select 1 Register
  volatile uint32_t GPBQSEL2;        //!< GPIO B Qualifier Select 2 Register
  volatile uint32_t GPBMUX1;         //!< GPIO B MUX 1 Register
  volatile uint32_t GPBMUX2;         //!< GPIO B MUX 2 Register
  volatile uint32_t GPBDIR;          //!< GPIO B Direction Register
  volatile uint32_t GPBPUD;          //!< GPIO B Pull Up Disable Register
  volatile uint16_t rsvd_4[24];      //!< Reserved
  volatile uint32_t AIOMUX1;         //!< Analog, I/O Mux 1 Register
  volatile uint16_t rsvd_5[2];       //!< Reserved
  volatile uint32_t AIODIR;          //!< Analog, I/O Direction Register
  volatile uint16_t rsvd_6[4];       //!< Reserved
  volatile uint32_t GPADAT;          //!< GPIO A Data Register
  volatile uint32_t GPASET;          //!< GPIO A Set Register
  volatile uint32_t GPACLEAR;        //!< GPIO A Clear Register
  volatile uint32_t GPATOGGLE;       //!< GPIO A Toggle Register
  volatile uint32_t GPBDAT;          //!< GPIO B Data Register
  volatile uint32_t GPBSET;          //!< GPIO B Set Register
  volatile uint32_t GPBCLEAR;        //!< GPIO B Clear Register
  volatile uint32_t GPBTOGGLE;       //!< GPIO B Toggle Register
  volatile uint16_t rsvd_7[8];       //!< Reserved
  volatile uint32_t AIODAT;          //!< Analog I/O Data Register
  volatile uint32_t AIOSET;          //!< Analog I/O Data Set Register
  volatile uint32_t AIOCLEAR;        //!< Analog I/O Clear Register
  volatile uint32_t AIOTOGGLE;       //!< Analog I/O Toggle Register
  volatile uint16_t GPIOXINTnSEL[3]; //!< XINT1-3 Source Select Registers
  volatile uint16_t rsvd_8[5];       //!< Reserved
  volatile uint32_t GPIOLPMSEL;      //!< GPIO Low Power Mode Wakeup Select Register
} GPIO_Obj;


//! \brief Defines the general purpose I/O (GPIO) handle
//!
typedef struct _GPIO_Obj_ *GPIO_Handle;


// **************************************************************************
// the globals


// **************************************************************************
// the function prototypes

//! \brief     Returns the data value present on a pin (either input or output)
//! \param[in] gpioHandle  The general purpose I/O (GPIO) object handle
//! \param[in] gpioNumber  The GPIO number
//! \return    The boolean state of a pin (high/low)
extern bool GPIO_getData(GPIO_Handle gpioHandle, const GPIO_Number_e gpioNumber);


//! \brief     Returns the data value present on a GPIO port
//! \param[in] gpioHandle  The general purpose I/O (GPIO) object handle
//! \param[in] gpioPort  The GPIO port
//! \return    The data values for the specified port
extern uint32_t GPIO_getPortData(GPIO_Handle gpioHandle, const GPIO_Port_e gpioPort);


//! \brief     Initializes the general purpose I/O (GPIO) object handle
//! \param[in] pMemory     A pointer to the base address of the GPIO registers
//! \param[in] numBytes    The number of bytes allocated for the GPIO object, bytes
//! \return    The general purpose I/O (GPIO) object handle
extern GPIO_Handle GPIO_init(void *pMemory,const size_t numBytes);


//! \brief     Sets the general purpose I/O (GPIO) signal direction
//! \param[in] gpioHandle  The general purpose I/O (GPIO) object handle
//! \param[in] gpioNumber  The GPIO number
//! \param[in] direction   The signal direction
extern void GPIO_setDirection(GPIO_Handle gpioHandle,const GPIO_Number_e gpioNumber,const GPIO_Direction_e direction);


//! \brief     Sets the general purpose I/O (GPIO) pullup disable
//! \param[in] gpioHandle  The general purpose I/O (GPIO) object handle
//! \param[in] gpioNumber  The GPIO number
//! \param[in] pullup   The pullup enable or disable signal
extern void GPIO_setPullup(GPIO_Handle gpioHandle,const GPIO_Number_e gpioNumber,const GPIO_Pullup_e pullup);


//! \brief     Sets the general purpose I/O (GPIO) external interrupt number
//! \param[in] gpioHandle  The general purpose I/O (GPIO) object handle
//! \param[in] gpioNumber  The GPIO number
//! \param[in] intNumber   The interrupt number
extern void GPIO_setExtInt(GPIO_Handle gpioHandle,const GPIO_Number_e gpioNumber,const CPU_ExtIntNumber_e intNumber);


//! \brief     Sets the specified general purpose I/O (GPIO) signal low
//! \param[in] gpioHandle  The general purpose I/O (GPIO) object handle
//! \param[in] gpioNumber  The GPIO number
extern void GPIO_setLow(GPIO_Handle gpioHandle,const GPIO_Number_e gpioNumber);


//! \brief     Sets the mode for the specified general purpose I/O (GPIO) signal
//! \param[in] gpioHandle  The general purpose I/O (GPIO) object handle
//! \param[in] gpioNumber  The GPIO number
//! \param[in] mode        The mode
extern void GPIO_setMode(GPIO_Handle gpioHandle,const GPIO_Number_e gpioNumber,const GPIO_Mode_e mode);


//! \brief     Reads the specified general purpose I/O (GPIO)
//! \param[in] gpioHandle  The general purpose I/O (GPIO) object handle
//! \param[in] gpioNumber  The GPIO number
//! \return    The general purpose I/O (GPIO) state, HIGH or LOW
extern bool GPIO_read(GPIO_Handle gpioHandle,const GPIO_Number_e gpioNumber);


//! \brief     Sets the specified general purpose I/O (GPIO) signal high
//! \param[in] gpioHandle  The general purpose I/O (GPIO) object handle
//! \param[in] gpioNumber  The GPIO number
extern void GPIO_setHigh(GPIO_Handle gpioHandle,const GPIO_Number_e gpioNumber);


//! \brief     Sets data output on a given GPIO port
//! \param[in] gpioHandle   The general purpose I/O (GPIO) object handle
//! \param[in] gpioPort     The GPIO number
//! \param[in] data         The data to write to the port
extern void GPIO_setPortData(GPIO_Handle gpioHandle, const GPIO_Port_e gpioPort, const uint32_t data);


//! \brief     Sets the qualification for the specified general purpose I/O (GPIO)
//! \param[in] gpioHandle    The general purpose I/O (GPIO) object handle
//! \param[in] gpioNumber    The GPIO number
//! \param[in] qualification The desired input qualification
extern void GPIO_setQualification(GPIO_Handle gpioHandle, const GPIO_Number_e gpioNumber, const GPIO_Qual_e qualification);


//! \brief     Sets the qualification period for the specified general purpose I/O block (8 I/O's per block)
//! \param[in] gpioHandle   The general purpose I/O (GPIO) object handle
//! \param[in] gpioNumber   The GPIO number
//! \param[in] period       The desired input qualification period
extern void GPIO_setQualificationPeriod(GPIO_Handle gpioHandle, const GPIO_Number_e gpioNumber, const uint_least8_t period);


//! \brief     Toggles the specified general purpose I/O (GPIO) signal
//! \param[in] gpioHandle  The general purpose I/O (GPIO) object handle
//! \param[in] gpioNumber  The GPIO number
extern void GPIO_toggle(GPIO_Handle gpioHandle,const GPIO_Number_e gpioNumber);


//! \brief     Selects a gpio pin to wake up device from STANDBY and HALT LPM
//! \param[in] gpioHandle  The general purpose I/O (GPIO) object handle
//! \param[in] gpioNumber  The GPIO number
extern void GPIO_lpmSelect(GPIO_Handle gpioHandle,const GPIO_Number_e gpioNumber);


#ifdef __cplusplus
}
#endif // extern "C"

//@} // ingroup
#endif // end of _GPIO_H_ definition



