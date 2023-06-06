//! \file       hal_gpio.c
//! \brief      Contains various functions related to the GPIO object
//! \author     sunyanjun
//! \version    1.0
//! \date       2017.03.21
//! \copyright  SANTROLL

// ============================================================================
// the includes
#include"sw/config/config.h"

#if EVCBD_ID == 0x01
void HAL_setupGpios(HAL_Handle handle)
{
  HAL_Obj *obj = (HAL_Obj *)handle;


  // PWM1
  GPIO_setMode(obj->gpioHandle,GPIO_Number_0,GPIO_0_Mode_EPWM1A);

  // PWM2
  GPIO_setMode(obj->gpioHandle,GPIO_Number_1,GPIO_1_Mode_EPWM1B);

  // PWM3
  GPIO_setMode(obj->gpioHandle,GPIO_Number_2,GPIO_2_Mode_EPWM2A);

  // PWM4
  GPIO_setMode(obj->gpioHandle,GPIO_Number_3,GPIO_3_Mode_EPWM2B);

  // PWM5
  GPIO_setMode(obj->gpioHandle,GPIO_Number_4,GPIO_4_Mode_EPWM3A);

  // PWM6
  GPIO_setMode(obj->gpioHandle,GPIO_Number_5,GPIO_5_Mode_EPWM3B);

  // PCha
  GPIO_setLow(obj->gpioHandle,GPIO_Number_6);
  GPIO_setPullup(obj->gpioHandle,GPIO_Number_6,GPIO_Pullup_Disable);
  GPIO_setMode(obj->gpioHandle,GPIO_Number_6,GPIO_6_Mode_GeneralPurpose);
  GPIO_setDirection(obj->gpioHandle,GPIO_Number_6,GPIO_Direction_Output);

  // SD-IN
  GPIO_setLow(obj->gpioHandle,GPIO_Number_7);
  GPIO_setPullup(obj->gpioHandle,GPIO_Number_7,GPIO_Pullup_Disable);
  GPIO_setMode(obj->gpioHandle,GPIO_Number_7,GPIO_7_Mode_GeneralPurpose);
  GPIO_setDirection(obj->gpioHandle,GPIO_Number_7,GPIO_Direction_Output);

  // Coder-Err
  GPIO_setQualification(obj->gpioHandle,GPIO_Number_8,GPIO_Qual_Sample_3);
  GPIO_setPullup(obj->gpioHandle,GPIO_Number_8,GPIO_Pullup_Enable);
  GPIO_setMode(obj->gpioHandle,GPIO_Number_8,GPIO_8_Mode_GeneralPurpose);
  GPIO_setDirection(obj->gpioHandle,GPIO_Number_8,GPIO_Direction_Input);

  // JCT
  GPIO_setLow(obj->gpioHandle,GPIO_Number_9);
  GPIO_setPullup(obj->gpioHandle,GPIO_Number_9,GPIO_Pullup_Disable);
  GPIO_setMode(obj->gpioHandle,GPIO_Number_9,GPIO_9_Mode_GeneralPurpose);
  GPIO_setDirection(obj->gpioHandle,GPIO_Number_9,GPIO_Direction_Output);

  // No Connection
  GPIO_setMode(obj->gpioHandle,GPIO_Number_10,GPIO_10_Mode_GeneralPurpose);

  // Coder-RST
  GPIO_setLow(obj->gpioHandle,GPIO_Number_11);
  GPIO_setPullup(obj->gpioHandle,GPIO_Number_11,GPIO_Pullup_Disable);
  GPIO_setMode(obj->gpioHandle,GPIO_Number_11,GPIO_11_Mode_GeneralPurpose);
  GPIO_setDirection(obj->gpioHandle,GPIO_Number_11,GPIO_Direction_Output);

  // MOD
  GPIO_setQualification(obj->gpioHandle,GPIO_Number_12,GPIO_Qual_Sample_3);
  GPIO_setPullup(obj->gpioHandle,GPIO_Number_12,GPIO_Pullup_Disable);
  GPIO_setMode(obj->gpioHandle,GPIO_Number_12,GPIO_12_Mode_GeneralPurpose);
  GPIO_setDirection(obj->gpioHandle,GPIO_Number_12,GPIO_Direction_Input);

  // RDC-SPI-SOMI
  GPIO_setQualification(obj->gpioHandle,GPIO_Number_13,GPIO_Qual_ASync);
  GPIO_setPullup(obj->gpioHandle,GPIO_Number_13,GPIO_Pullup_Enable);
  GPIO_setMode(obj->gpioHandle,GPIO_Number_13,GPIO_13_Mode_SPISOMIB);

  // RDC-SPI-CLK
  GPIO_setPullup(obj->gpioHandle,GPIO_Number_14, GPIO_Pullup_Enable);
  GPIO_setMode(obj->gpioHandle,GPIO_Number_14,GPIO_14_Mode_SPICLKB);

  // RDC-SPI-CS
  GPIO_setPullup(obj->gpioHandle,GPIO_Number_15, GPIO_Pullup_Enable);
  GPIO_setMode(obj->gpioHandle,GPIO_Number_15,GPIO_15_Mode_SPISTEB_NOT);

  // No Connection
  GPIO_setMode(obj->gpioHandle,GPIO_Number_16,GPIO_16_Mode_GeneralPurpose);

  // No Connection
  GPIO_setMode(obj->gpioHandle,GPIO_Number_17,GPIO_17_Mode_GeneralPurpose);

  // No Connection
  GPIO_setMode(obj->gpioHandle,GPIO_Number_18,GPIO_18_Mode_GeneralPurpose);

  // XCLKIN
  // GPIO_setMode(obj->gpioHandle,GPIO_Number_19,GPIO_19_Mode_SPISTEA_NOT);

  // RDC-A-QEP
  GPIO_setQualification(obj->gpioHandle,GPIO_Number_20,GPIO_Qual_Sample_3);
  GPIO_setPullup(obj->gpioHandle,GPIO_Number_20,GPIO_Pullup_Enable);
  GPIO_setMode(obj->gpioHandle,GPIO_Number_20,GPIO_20_Mode_EQEP1A);

  // RDC-B-QEP
  GPIO_setQualification(obj->gpioHandle,GPIO_Number_21,GPIO_Qual_Sample_3);
  GPIO_setPullup(obj->gpioHandle,GPIO_Number_21,GPIO_Pullup_Enable);
  GPIO_setMode(obj->gpioHandle,GPIO_Number_21,GPIO_21_Mode_EQEP1B);

  // LED2
  GPIO_setHigh(obj->gpioHandle,GPIO_Number_22);
  GPIO_setPullup(obj->gpioHandle,GPIO_Number_22,GPIO_Pullup_Disable);
  GPIO_setMode(obj->gpioHandle,GPIO_Number_22,GPIO_22_Mode_GeneralPurpose);
  GPIO_setDirection(obj->gpioHandle,GPIO_Number_22,GPIO_Direction_Output);

  // RDC-Z-QEP
  GPIO_setQualification(obj->gpioHandle,GPIO_Number_23,GPIO_Qual_Sample_3);
  GPIO_setPullup(obj->gpioHandle,GPIO_Number_23,GPIO_Pullup_Enable);
  GPIO_setMode(obj->gpioHandle,GPIO_Number_23,GPIO_23_Mode_EQEP1I);

  // DH-1
  GPIO_setQualification(obj->gpioHandle,GPIO_Number_24,GPIO_Qual_Sample_3);
  GPIO_setPullup(obj->gpioHandle,GPIO_Number_24,GPIO_Pullup_Disable);
  GPIO_setMode(obj->gpioHandle,GPIO_Number_24,GPIO_24_Mode_GeneralPurpose);
  GPIO_setDirection(obj->gpioHandle,GPIO_Number_24,GPIO_Direction_Input);

  // DH-2
  GPIO_setQualification(obj->gpioHandle,GPIO_Number_25,GPIO_Qual_Sample_3);
  GPIO_setPullup(obj->gpioHandle,GPIO_Number_25,GPIO_Pullup_Disable);
  GPIO_setMode(obj->gpioHandle,GPIO_Number_25,GPIO_25_Mode_GeneralPurpose);
  GPIO_setDirection(obj->gpioHandle,GPIO_Number_25,GPIO_Direction_Input);

  // DH-3
  GPIO_setQualification(obj->gpioHandle,GPIO_Number_26,GPIO_Qual_Sample_3);
  GPIO_setPullup(obj->gpioHandle,GPIO_Number_26,GPIO_Pullup_Disable);
  GPIO_setMode(obj->gpioHandle,GPIO_Number_26,GPIO_26_Mode_GeneralPurpose);
  GPIO_setDirection(obj->gpioHandle,GPIO_Number_26,GPIO_Direction_Input);

  // BKL
  GPIO_setQualification(obj->gpioHandle,GPIO_Number_27,GPIO_Qual_Sample_3);
  GPIO_setPullup(obj->gpioHandle,GPIO_Number_27,GPIO_Pullup_Disable);
  GPIO_setMode(obj->gpioHandle,GPIO_Number_27,GPIO_27_Mode_GeneralPurpose);
  GPIO_setDirection(obj->gpioHandle,GPIO_Number_27,GPIO_Direction_Input);

  // RX-SCI
  GPIO_setQualification(obj->gpioHandle,GPIO_Number_28,GPIO_Qual_ASync);
  GPIO_setPullup(obj->gpioHandle,GPIO_Number_28,GPIO_Pullup_Disable);
  GPIO_setMode(obj->gpioHandle,GPIO_Number_28,GPIO_28_Mode_SCIRXDA);

  // TX-SCI
  GPIO_setPullup(obj->gpioHandle,GPIO_Number_29,GPIO_Pullup_Disable);
  GPIO_setMode(obj->gpioHandle,GPIO_Number_29,GPIO_29_Mode_SCITXDA);

  // RX-CAN
  GPIO_setQualification(obj->gpioHandle,GPIO_Number_30,GPIO_Qual_ASync);
  GPIO_setPullup(obj->gpioHandle,GPIO_Number_30,GPIO_Pullup_Enable);
  GPIO_setMode(obj->gpioHandle,GPIO_Number_30,GPIO_30_Mode_CANRXA);

  // TX-CAN
  GPIO_setPullup(obj->gpioHandle,GPIO_Number_31,GPIO_Pullup_Enable);
  GPIO_setMode(obj->gpioHandle,GPIO_Number_31,GPIO_31_Mode_CANTXA);

  // I2C-SDA
  GPIO_setQualification(obj->gpioHandle,GPIO_Number_32,GPIO_Qual_ASync);
  GPIO_setPullup(obj->gpioHandle,GPIO_Number_32,GPIO_Pullup_Enable);
  GPIO_setMode(obj->gpioHandle,GPIO_Number_32,GPIO_32_Mode_SDAA);

  // I2C-SCL
  GPIO_setPullup(obj->gpioHandle,GPIO_Number_33,GPIO_Pullup_Enable);
  GPIO_setMode(obj->gpioHandle,GPIO_Number_33,GPIO_33_Mode_SCLA);

  // No Connection
  GPIO_setMode(obj->gpioHandle,GPIO_Number_34,GPIO_34_Mode_GeneralPurpose);

  // JTAG
  GPIO_setMode(obj->gpioHandle,GPIO_Number_35,GPIO_35_Mode_JTAG_TDI);
  GPIO_setMode(obj->gpioHandle,GPIO_Number_36,GPIO_36_Mode_JTAG_TMS);
  GPIO_setMode(obj->gpioHandle,GPIO_Number_37,GPIO_37_Mode_JTAG_TDO);
  GPIO_setMode(obj->gpioHandle,GPIO_Number_38,GPIO_38_Mode_JTAG_TCK);

  // AHD
  GPIO_setQualification(obj->gpioHandle,GPIO_Number_39,GPIO_Qual_Sample_3);
  GPIO_setPullup(obj->gpioHandle,GPIO_Number_39,GPIO_Pullup_Disable);
  GPIO_setMode(obj->gpioHandle,GPIO_Number_39,GPIO_39_Mode_GeneralPurpose);
  GPIO_setDirection(obj->gpioHandle,GPIO_Number_39,GPIO_Direction_Input);

  // MDRV
  GPIO_setHigh(obj->gpioHandle,GPIO_Number_40);
  GPIO_setPullup(obj->gpioHandle,GPIO_Number_40,GPIO_Pullup_Disable);
  GPIO_setMode(obj->gpioHandle,GPIO_Number_40,GPIO_40_Mode_GeneralPurpose);
  GPIO_setDirection(obj->gpioHandle,GPIO_Number_40,GPIO_Direction_Output);

  // No Connection
  GPIO_setMode(obj->gpioHandle,GPIO_Number_41,GPIO_41_Mode_GeneralPurpose);

  // LED1
  GPIO_setHigh(obj->gpioHandle,GPIO_Number_42);
  GPIO_setPullup(obj->gpioHandle,GPIO_Number_42,GPIO_Pullup_Disable);
  GPIO_setMode(obj->gpioHandle,GPIO_Number_42,GPIO_42_Mode_GeneralPurpose);
  GPIO_setDirection(obj->gpioHandle,GPIO_Number_42,GPIO_Direction_Output);

  // TC
  GPIO_setLow(obj->gpioHandle,GPIO_Number_43);
  GPIO_setPullup(obj->gpioHandle,GPIO_Number_43,GPIO_Pullup_Disable);
  GPIO_setMode(obj->gpioHandle,GPIO_Number_43,GPIO_43_Mode_GeneralPurpose);
  GPIO_setDirection(obj->gpioHandle,GPIO_Number_43,GPIO_Direction_Output);

  // No Connection
  GPIO_setMode(obj->gpioHandle,GPIO_Number_44,GPIO_44_Mode_GeneralPurpose);

  // LOCK
  GPIO_setQualification(obj->gpioHandle,GPIO_Number_50,GPIO_Qual_Sample_3);
  GPIO_setPullup(obj->gpioHandle,GPIO_Number_50,GPIO_Pullup_Disable);
  GPIO_setMode(obj->gpioHandle,GPIO_Number_50,GPIO_50_Mode_GeneralPurpose);
  GPIO_setDirection(obj->gpioHandle,GPIO_Number_50,GPIO_Direction_Input);

  // FBK
  GPIO_setQualification(obj->gpioHandle,GPIO_Number_51,GPIO_Qual_Sample_3);
  GPIO_setPullup(obj->gpioHandle,GPIO_Number_51,GPIO_Pullup_Disable);
  GPIO_setMode(obj->gpioHandle,GPIO_Number_51,GPIO_51_Mode_GeneralPurpose);
  GPIO_setDirection(obj->gpioHandle,GPIO_Number_51,GPIO_Direction_Input);

  // No Connection
  GPIO_setMode(obj->gpioHandle,GPIO_Number_52,GPIO_52_Mode_GeneralPurpose);

  // TES
  GPIO_setQualification(obj->gpioHandle,GPIO_Number_53,GPIO_Qual_Sample_3);
  GPIO_setPullup(obj->gpioHandle,GPIO_Number_53,GPIO_Pullup_Disable);
  GPIO_setMode(obj->gpioHandle,GPIO_Number_53,GPIO_53_Mode_GeneralPurpose);
  GPIO_setDirection(obj->gpioHandle,GPIO_Number_53,GPIO_Direction_Input);

  // No Connection
  GPIO_setMode(obj->gpioHandle,GPIO_Number_54,GPIO_54_Mode_GeneralPurpose);

  // No Connection
  GPIO_setMode(obj->gpioHandle,GPIO_Number_55,GPIO_55_Mode_GeneralPurpose);

  // No Connection
  GPIO_setMode(obj->gpioHandle,GPIO_Number_56,GPIO_56_Mode_GeneralPurpose);

  // VAC1
  GPIO_setQualification(obj->gpioHandle,GPIO_Number_57,GPIO_Qual_Sample_3);
  GPIO_setPullup(obj->gpioHandle,GPIO_Number_57,GPIO_Pullup_Disable);
  GPIO_setMode(obj->gpioHandle,GPIO_Number_57,GPIO_57_Mode_GeneralPurpose);
  GPIO_setDirection(obj->gpioHandle,GPIO_Number_57,GPIO_Direction_Input);

  // PLEN
  GPIO_setHigh(obj->gpioHandle,GPIO_Number_58);
  GPIO_setPullup(obj->gpioHandle,GPIO_Number_58,GPIO_Pullup_Disable);
  GPIO_setMode(obj->gpioHandle,GPIO_Number_58,GPIO_58_Mode_GeneralPurpose);
  GPIO_setDirection(obj->gpioHandle,GPIO_Number_58,GPIO_Direction_Output);

  return;
}  // end of HAL_setupGpios() function

#elif ((EVCBD_ID == 0x02) || (EVCBD_ID == 0x03) || (EVCBD_ID == 0x04) || (EVCBD_ID == 0x05) || (EVCBD_ID == 0x06))
void HAL_setupGpios(HAL_Handle handle)
{
  HAL_Obj *obj = (HAL_Obj *)handle;


  // PWM1
  GPIO_setMode(obj->gpioHandle,GPIO_Number_0,GPIO_0_Mode_EPWM1A);

  // PWM2
  GPIO_setMode(obj->gpioHandle,GPIO_Number_1,GPIO_1_Mode_EPWM1B);

  // PWM3
  GPIO_setMode(obj->gpioHandle,GPIO_Number_2,GPIO_2_Mode_EPWM2A);

  // PWM4
  GPIO_setMode(obj->gpioHandle,GPIO_Number_3,GPIO_3_Mode_EPWM2B);

  // PWM5
  GPIO_setMode(obj->gpioHandle,GPIO_Number_4,GPIO_4_Mode_EPWM3A);

  // PWM6
  GPIO_setMode(obj->gpioHandle,GPIO_Number_5,GPIO_5_Mode_EPWM3B);

  // IGBT-POWER
  GPIO_setLow(obj->gpioHandle,GPIO_Number_6);
  GPIO_setPullup(obj->gpioHandle,GPIO_Number_6,GPIO_Pullup_Disable);
  GPIO_setMode(obj->gpioHandle,GPIO_Number_6,GPIO_6_Mode_GeneralPurpose);
  GPIO_setDirection(obj->gpioHandle,GPIO_Number_6,GPIO_Direction_Output);

  // IGBT-RST
  GPIO_setLow(obj->gpioHandle,GPIO_Number_7);
  GPIO_setPullup(obj->gpioHandle,GPIO_Number_7,GPIO_Pullup_Disable);
  GPIO_setMode(obj->gpioHandle,GPIO_Number_7,GPIO_7_Mode_GeneralPurpose);
  GPIO_setDirection(obj->gpioHandle,GPIO_Number_7,GPIO_Direction_Output);

  // KEEP-POWER
  GPIO_setLow(obj->gpioHandle,GPIO_Number_8);
  GPIO_setPullup(obj->gpioHandle,GPIO_Number_8,GPIO_Pullup_Disable);
  GPIO_setMode(obj->gpioHandle,GPIO_Number_8,GPIO_8_Mode_GeneralPurpose);
  GPIO_setDirection(obj->gpioHandle,GPIO_Number_8,GPIO_Direction_Output);

  // SW7
  GPIO_setQualification(obj->gpioHandle,GPIO_Number_9,GPIO_Qual_Sample_3);
  GPIO_setPullup(obj->gpioHandle,GPIO_Number_9,GPIO_Pullup_Disable);
  GPIO_setMode(obj->gpioHandle,GPIO_Number_9,GPIO_9_Mode_GeneralPurpose);
  GPIO_setDirection(obj->gpioHandle,GPIO_Number_9,GPIO_Direction_Input);

  // SW6
  GPIO_setQualification(obj->gpioHandle,GPIO_Number_10,GPIO_Qual_Sample_3);
  GPIO_setPullup(obj->gpioHandle,GPIO_Number_10,GPIO_Pullup_Disable);
  GPIO_setMode(obj->gpioHandle,GPIO_Number_10,GPIO_10_Mode_GeneralPurpose);
  GPIO_setDirection(obj->gpioHandle,GPIO_Number_10,GPIO_Direction_Input);

  // SW5
  GPIO_setQualification(obj->gpioHandle,GPIO_Number_11,GPIO_Qual_Sample_3);
  GPIO_setPullup(obj->gpioHandle,GPIO_Number_11,GPIO_Pullup_Disable);
  GPIO_setMode(obj->gpioHandle,GPIO_Number_11,GPIO_11_Mode_GeneralPurpose);
  GPIO_setDirection(obj->gpioHandle,GPIO_Number_11,GPIO_Direction_Input);

  // IN1
  GPIO_setLow(obj->gpioHandle,GPIO_Number_12);
  GPIO_setPullup(obj->gpioHandle,GPIO_Number_12,GPIO_Pullup_Disable);
  GPIO_setMode(obj->gpioHandle,GPIO_Number_12,GPIO_12_Mode_GeneralPurpose);
  GPIO_setDirection(obj->gpioHandle,GPIO_Number_12,GPIO_Direction_Output);

  // LED2
  GPIO_setHigh(obj->gpioHandle,GPIO_Number_13);
  GPIO_setPullup(obj->gpioHandle,GPIO_Number_13,GPIO_Pullup_Disable);
  GPIO_setMode(obj->gpioHandle,GPIO_Number_13,GPIO_13_Mode_GeneralPurpose);
  GPIO_setDirection(obj->gpioHandle,GPIO_Number_13,GPIO_Direction_Output);

  // TX-SCI
  GPIO_setPullup(obj->gpioHandle,GPIO_Number_14,GPIO_Pullup_Disable);
  GPIO_setMode(obj->gpioHandle,GPIO_Number_14,GPIO_14_Mode_SCITXDB);

  // RX-SCI
  GPIO_setQualification(obj->gpioHandle,GPIO_Number_15,GPIO_Qual_ASync);
  GPIO_setPullup(obj->gpioHandle,GPIO_Number_15,GPIO_Pullup_Disable);
  GPIO_setMode(obj->gpioHandle,GPIO_Number_15,GPIO_15_Mode_SCIRXDB);

  // ST1
  GPIO_setQualification(obj->gpioHandle,GPIO_Number_16,GPIO_Qual_Sample_3);
  GPIO_setPullup(obj->gpioHandle,GPIO_Number_16,GPIO_Pullup_Enable);
  GPIO_setMode(obj->gpioHandle,GPIO_Number_16,GPIO_16_Mode_GeneralPurpose);
  GPIO_setDirection(obj->gpioHandle,GPIO_Number_16,GPIO_Direction_Input);

  // RDC-SPI-SOMI
  GPIO_setQualification(obj->gpioHandle,GPIO_Number_17,GPIO_Qual_ASync);
  GPIO_setPullup(obj->gpioHandle,GPIO_Number_17,GPIO_Pullup_Enable);
  GPIO_setMode(obj->gpioHandle,GPIO_Number_17,GPIO_17_Mode_SPISOMIA);

  // RDC-SPI-CLK
  GPIO_setPullup(obj->gpioHandle,GPIO_Number_18, GPIO_Pullup_Enable);
  GPIO_setMode(obj->gpioHandle,GPIO_Number_18,GPIO_18_Mode_SPICLKA);

  // XCLKIN
  // GPIO_setMode(obj->gpioHandle,GPIO_Number_19,GPIO_19_Mode_SPISTEA_NOT);

  // RDC-RST
  GPIO_setHigh(obj->gpioHandle,GPIO_Number_20);
  GPIO_setPullup(obj->gpioHandle,GPIO_Number_20,GPIO_Pullup_Enable);
  GPIO_setMode(obj->gpioHandle,GPIO_Number_20,GPIO_20_Mode_GeneralPurpose);
  GPIO_setDirection(obj->gpioHandle,GPIO_Number_20,GPIO_Direction_Output);

  // RDC-FAULT
  GPIO_setQualification(obj->gpioHandle,GPIO_Number_21,GPIO_Qual_Sample_3);
  GPIO_setPullup(obj->gpioHandle,GPIO_Number_21,GPIO_Pullup_Enable);
  GPIO_setMode(obj->gpioHandle,GPIO_Number_21,GPIO_21_Mode_GeneralPurpose);
  GPIO_setDirection(obj->gpioHandle,GPIO_Number_21,GPIO_Direction_Input);

  // SPEED-OC
  GPIO_setLow(obj->gpioHandle,GPIO_Number_22);
  GPIO_setPullup(obj->gpioHandle,GPIO_Number_22,GPIO_Pullup_Disable);
  GPIO_setMode(obj->gpioHandle,GPIO_Number_22,GPIO_22_Mode_GeneralPurpose);
  GPIO_setDirection(obj->gpioHandle,GPIO_Number_22,GPIO_Direction_Output);

  // No Connection
  GPIO_setMode(obj->gpioHandle,GPIO_Number_23,GPIO_23_Mode_GeneralPurpose);

  // RDC-A-QEP
  GPIO_setQualification(obj->gpioHandle,GPIO_Number_24,GPIO_Qual_Sample_3);
  GPIO_setPullup(obj->gpioHandle,GPIO_Number_24,GPIO_Pullup_Enable);
  GPIO_setMode(obj->gpioHandle,GPIO_Number_24,GPIO_24_Mode_EQEP2A);

  // RDC-B-QEP
  GPIO_setQualification(obj->gpioHandle,GPIO_Number_25,GPIO_Qual_Sample_3);
  GPIO_setPullup(obj->gpioHandle,GPIO_Number_25,GPIO_Pullup_Enable);
  GPIO_setMode(obj->gpioHandle,GPIO_Number_25,GPIO_25_Mode_EQEP2B);

  // RDC-Z-QEP
  GPIO_setQualification(obj->gpioHandle,GPIO_Number_26,GPIO_Qual_Sample_3);
  GPIO_setPullup(obj->gpioHandle,GPIO_Number_26,GPIO_Pullup_Enable);
  GPIO_setMode(obj->gpioHandle,GPIO_Number_26,GPIO_26_Mode_EQEP2I);

  // No Connection
  GPIO_setMode(obj->gpioHandle,GPIO_Number_27,GPIO_27_Mode_GeneralPurpose);

  // I2C-SDA
  GPIO_setQualification(obj->gpioHandle,GPIO_Number_28,GPIO_Qual_ASync);
  GPIO_setPullup(obj->gpioHandle,GPIO_Number_28,GPIO_Pullup_Enable);
  GPIO_setMode(obj->gpioHandle,GPIO_Number_28,GPIO_28_Mode_SDDA);

  // I2C-SCL
  GPIO_setPullup(obj->gpioHandle,GPIO_Number_29,GPIO_Pullup_Enable);
  GPIO_setMode(obj->gpioHandle,GPIO_Number_29,GPIO_29_Mode_SCLA);

  // RX-CAN
  GPIO_setQualification(obj->gpioHandle,GPIO_Number_30,GPIO_Qual_ASync);
  GPIO_setPullup(obj->gpioHandle,GPIO_Number_30,GPIO_Pullup_Enable);
  GPIO_setMode(obj->gpioHandle,GPIO_Number_30,GPIO_30_Mode_CANRXA);

  // TX-CAN
  GPIO_setPullup(obj->gpioHandle,GPIO_Number_31,GPIO_Pullup_Enable);
  GPIO_setMode(obj->gpioHandle,GPIO_Number_31,GPIO_31_Mode_CANTXA);

  // FAULT-OC
  GPIO_setLow(obj->gpioHandle,GPIO_Number_32);
  GPIO_setPullup(obj->gpioHandle,GPIO_Number_32,GPIO_Pullup_Disable);
  GPIO_setMode(obj->gpioHandle,GPIO_Number_32,GPIO_32_Mode_GeneralPurpose);
  GPIO_setDirection(obj->gpioHandle,GPIO_Number_32,GPIO_Direction_Output);

  // No Connection
  GPIO_setMode(obj->gpioHandle,GPIO_Number_33,GPIO_33_Mode_GeneralPurpose);

  // No Connection
  GPIO_setMode(obj->gpioHandle,GPIO_Number_34,GPIO_34_Mode_GeneralPurpose);

  // JTAG
  GPIO_setMode(obj->gpioHandle,GPIO_Number_35,GPIO_35_Mode_JTAG_TDI);
  GPIO_setMode(obj->gpioHandle,GPIO_Number_36,GPIO_36_Mode_JTAG_TMS);
  GPIO_setMode(obj->gpioHandle,GPIO_Number_37,GPIO_37_Mode_JTAG_TDO);
  GPIO_setMode(obj->gpioHandle,GPIO_Number_38,GPIO_38_Mode_JTAG_TCK);

  // No Connection
  GPIO_setMode(obj->gpioHandle,GPIO_Number_39,GPIO_39_Mode_GeneralPurpose);

  // SW4
  GPIO_setQualification(obj->gpioHandle,GPIO_Number_40,GPIO_Qual_Sample_3);
  GPIO_setPullup(obj->gpioHandle,GPIO_Number_40,GPIO_Pullup_Disable);
  GPIO_setMode(obj->gpioHandle,GPIO_Number_40,GPIO_40_Mode_GeneralPurpose);
  GPIO_setDirection(obj->gpioHandle,GPIO_Number_40,GPIO_Direction_Input);

  // SW3
  GPIO_setQualification(obj->gpioHandle,GPIO_Number_41,GPIO_Qual_Sample_3);
  GPIO_setPullup(obj->gpioHandle,GPIO_Number_41,GPIO_Pullup_Disable);
  GPIO_setMode(obj->gpioHandle,GPIO_Number_41,GPIO_41_Mode_GeneralPurpose);
  GPIO_setDirection(obj->gpioHandle,GPIO_Number_41,GPIO_Direction_Input);

  // SW2
  GPIO_setQualification(obj->gpioHandle,GPIO_Number_42,GPIO_Qual_Sample_3);
  GPIO_setPullup(obj->gpioHandle,GPIO_Number_42,GPIO_Pullup_Disable);
  GPIO_setMode(obj->gpioHandle,GPIO_Number_42,GPIO_42_Mode_GeneralPurpose);
  GPIO_setDirection(obj->gpioHandle,GPIO_Number_42,GPIO_Direction_Input);

  // SW1
  GPIO_setQualification(obj->gpioHandle,GPIO_Number_43,GPIO_Qual_Sample_3);
  GPIO_setPullup(obj->gpioHandle,GPIO_Number_43,GPIO_Pullup_Disable);
  GPIO_setMode(obj->gpioHandle,GPIO_Number_43,GPIO_43_Mode_GeneralPurpose);
  GPIO_setDirection(obj->gpioHandle,GPIO_Number_43,GPIO_Direction_Input);

  // KSI
  GPIO_setQualification(obj->gpioHandle,GPIO_Number_44,GPIO_Qual_Sample_3);
  GPIO_setPullup(obj->gpioHandle,GPIO_Number_44,GPIO_Pullup_Disable);
  GPIO_setMode(obj->gpioHandle,GPIO_Number_44,GPIO_44_Mode_GeneralPurpose);
  GPIO_setDirection(obj->gpioHandle,GPIO_Number_44,GPIO_Direction_Input);

  // FAULT-IGBT-1
  GPIO_setQualification(obj->gpioHandle,GPIO_Number_50,GPIO_Qual_Sample_3);
  GPIO_setPullup(obj->gpioHandle,GPIO_Number_50,GPIO_Pullup_Disable);
  GPIO_setMode(obj->gpioHandle,GPIO_Number_50,GPIO_50_Mode_GeneralPurpose);
  GPIO_setDirection(obj->gpioHandle,GPIO_Number_50,GPIO_Direction_Input);

  // FAULT-IGBT-2
  GPIO_setQualification(obj->gpioHandle,GPIO_Number_51,GPIO_Qual_Sample_3);
  GPIO_setPullup(obj->gpioHandle,GPIO_Number_51,GPIO_Pullup_Disable);
  GPIO_setMode(obj->gpioHandle,GPIO_Number_51,GPIO_51_Mode_GeneralPurpose);
  GPIO_setDirection(obj->gpioHandle,GPIO_Number_51,GPIO_Direction_Input);

  // FAULT-IGBT-3
  GPIO_setQualification(obj->gpioHandle,GPIO_Number_52,GPIO_Qual_Sample_3);
  GPIO_setPullup(obj->gpioHandle,GPIO_Number_52,GPIO_Pullup_Disable);
  GPIO_setMode(obj->gpioHandle,GPIO_Number_52,GPIO_52_Mode_GeneralPurpose);
  GPIO_setDirection(obj->gpioHandle,GPIO_Number_52,GPIO_Direction_Input);

  // IN2
  GPIO_setLow(obj->gpioHandle,GPIO_Number_53);
  GPIO_setPullup(obj->gpioHandle,GPIO_Number_53,GPIO_Pullup_Disable);
  GPIO_setMode(obj->gpioHandle,GPIO_Number_53,GPIO_53_Mode_GeneralPurpose);
  GPIO_setDirection(obj->gpioHandle,GPIO_Number_53,GPIO_Direction_Output);

  // ST2
  GPIO_setQualification(obj->gpioHandle,GPIO_Number_54,GPIO_Qual_Sample_3);
  GPIO_setPullup(obj->gpioHandle,GPIO_Number_54,GPIO_Pullup_Enable);
  GPIO_setMode(obj->gpioHandle,GPIO_Number_54,GPIO_54_Mode_GeneralPurpose);
  GPIO_setDirection(obj->gpioHandle,GPIO_Number_54,GPIO_Direction_Input);

  // BUF-EN1
  GPIO_setHigh(obj->gpioHandle,GPIO_Number_55);
  GPIO_setPullup(obj->gpioHandle,GPIO_Number_55,GPIO_Pullup_Enable);
  GPIO_setMode(obj->gpioHandle,GPIO_Number_55,GPIO_55_Mode_GeneralPurpose);
  GPIO_setDirection(obj->gpioHandle,GPIO_Number_55,GPIO_Direction_Output);

  // BUF-EN2
  GPIO_setLow(obj->gpioHandle,GPIO_Number_56);
  GPIO_setPullup(obj->gpioHandle,GPIO_Number_56,GPIO_Pullup_Disable);
  GPIO_setMode(obj->gpioHandle,GPIO_Number_56,GPIO_56_Mode_GeneralPurpose);
  GPIO_setDirection(obj->gpioHandle,GPIO_Number_56,GPIO_Direction_Output);

  // RDC-SPI-CS
  GPIO_setPullup(obj->gpioHandle,GPIO_Number_57, GPIO_Pullup_Enable);
  GPIO_setMode(obj->gpioHandle,GPIO_Number_57,GPIO_57_Mode_SPISTEA_NOT);

  // LED1
  GPIO_setHigh(obj->gpioHandle,GPIO_Number_58);
  GPIO_setPullup(obj->gpioHandle,GPIO_Number_58,GPIO_Pullup_Disable);
  GPIO_setMode(obj->gpioHandle,GPIO_Number_58,GPIO_58_Mode_GeneralPurpose);
  GPIO_setDirection(obj->gpioHandle,GPIO_Number_58,GPIO_Direction_Output);

  return;
}  // end of HAL_setupGpios() function

#elif EVCBD_ID == 0x07
void HAL_setupGpios(HAL_Handle handle)
{
    HAL_Obj *obj = (HAL_Obj *)handle;


    // PWM1
    GPIO_setMode(obj->gpioHandle,GPIO_Number_0,GPIO_0_Mode_EPWM1A);

    // PWM2
    GPIO_setMode(obj->gpioHandle,GPIO_Number_1,GPIO_1_Mode_EPWM1B);

    // PWM3
    GPIO_setMode(obj->gpioHandle,GPIO_Number_2,GPIO_2_Mode_EPWM2A);

    // PWM4
    GPIO_setMode(obj->gpioHandle,GPIO_Number_3,GPIO_3_Mode_EPWM2B);

    // PWM5
    GPIO_setMode(obj->gpioHandle,GPIO_Number_4,GPIO_4_Mode_EPWM3A);

    // PWM6
    GPIO_setMode(obj->gpioHandle,GPIO_Number_5,GPIO_5_Mode_EPWM3B);

    // No Connection
    GPIO_setMode(obj->gpioHandle,GPIO_Number_6,GPIO_6_Mode_GeneralPurpose);

    // No Connection
    GPIO_setMode(obj->gpioHandle,GPIO_Number_7,GPIO_7_Mode_GeneralPurpose);

    // No Connection
    GPIO_setMode(obj->gpioHandle,GPIO_Number_8,GPIO_8_Mode_GeneralPurpose);

    // No Connection
    GPIO_setMode(obj->gpioHandle,GPIO_Number_9,GPIO_9_Mode_ECAP3);

    // Buff En2 高有效，默认设置为低
    GPIO_setMode(obj->gpioHandle,GPIO_Number_10,GPIO_10_Mode_GeneralPurpose);
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_10,GPIO_Pullup_Disable);
    GPIO_setDirection(obj->gpioHandle,GPIO_Number_10,GPIO_Direction_Output);
    GPIO_setLow(obj->gpioHandle,GPIO_Number_10);


    // No Connection
    GPIO_setMode(obj->gpioHandle,GPIO_Number_11,GPIO_11_Mode_GeneralPurpose);

    // ST1
    GPIO_setQualification(obj->gpioHandle,GPIO_Number_12,GPIO_Qual_Sample_3);
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_12,GPIO_Pullup_Enable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_12,GPIO_12_Mode_GeneralPurpose);
    GPIO_setDirection(obj->gpioHandle,GPIO_Number_12,GPIO_Direction_Input);

    // LED2
    GPIO_setHigh(obj->gpioHandle,GPIO_Number_13);
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_13,GPIO_Pullup_Disable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_13,GPIO_13_Mode_GeneralPurpose);
    GPIO_setDirection(obj->gpioHandle,GPIO_Number_13,GPIO_Direction_Output);

    // TX-SCI
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_14,GPIO_Pullup_Disable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_14,GPIO_14_Mode_SCITXDB);

    // No Connection
    GPIO_setMode(obj->gpioHandle,GPIO_Number_15,GPIO_15_Mode_GeneralPurpose);


    // Keep power
    GPIO_setHigh(obj->gpioHandle,GPIO_Number_16);
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_16,GPIO_Pullup_Disable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_16,GPIO_16_Mode_GeneralPurpose);
    GPIO_setDirection(obj->gpioHandle,GPIO_Number_16,GPIO_Direction_Output);

    // RDC-SPI-SOMI
    GPIO_setQualification(obj->gpioHandle,GPIO_Number_17,GPIO_Qual_ASync);
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_17,GPIO_Pullup_Enable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_17,GPIO_17_Mode_SPISOMIA);

    // RDC-SPI-CLK
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_18, GPIO_Pullup_Enable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_18,GPIO_18_Mode_SPICLKA);

    // No Connection
    GPIO_setMode(obj->gpioHandle,GPIO_Number_19,GPIO_19_Mode_GeneralPurpose);

    // Switch in 1, Low enable
    GPIO_setQualification(obj->gpioHandle,GPIO_Number_20,GPIO_Qual_Sample_3);
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_20,GPIO_Pullup_Disable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_20,GPIO_20_Mode_GeneralPurpose);
    GPIO_setDirection(obj->gpioHandle,GPIO_Number_20,GPIO_Direction_Input);

    // Switch in 2, Low enable
    GPIO_setQualification(obj->gpioHandle,GPIO_Number_21,GPIO_Qual_Sample_3);
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_21,GPIO_Pullup_Disable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_21,GPIO_21_Mode_GeneralPurpose);
    GPIO_setDirection(obj->gpioHandle,GPIO_Number_21,GPIO_Direction_Input);

    // No Connection
    GPIO_setMode(obj->gpioHandle,GPIO_Number_22,GPIO_22_Mode_GeneralPurpose);

    // Switch in 4, Low enable
    GPIO_setQualification(obj->gpioHandle,GPIO_Number_23,GPIO_Qual_Sample_3);
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_23,GPIO_Pullup_Disable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_23,GPIO_23_Mode_GeneralPurpose);
    GPIO_setDirection(obj->gpioHandle,GPIO_Number_23,GPIO_Direction_Input);

    // EQEPA
    GPIO_setQualification(obj->gpioHandle,GPIO_Number_24,GPIO_Qual_Sample_3);
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_24,GPIO_Pullup_Enable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_24,GPIO_24_Mode_EQEP2A);

    // EQEPB
    GPIO_setQualification(obj->gpioHandle,GPIO_Number_25,GPIO_Qual_Sample_3);
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_25,GPIO_Pullup_Enable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_25,GPIO_25_Mode_EQEP2B);

    // IGBT-POWER
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_26,GPIO_Pullup_Disable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_26,GPIO_26_Mode_GeneralPurpose);
    GPIO_setDirection(obj->gpioHandle,GPIO_Number_26,GPIO_Direction_Output);
    GPIO_setLow(obj->gpioHandle,GPIO_Number_26);


    // IGBT-RST
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_27,GPIO_Pullup_Disable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_27,GPIO_27_Mode_GeneralPurpose);
    GPIO_setDirection(obj->gpioHandle,GPIO_Number_27,GPIO_Direction_Output);
    GPIO_setLow(obj->gpioHandle,GPIO_Number_27);

    // RDC-FAULT
    GPIO_setQualification(obj->gpioHandle,GPIO_Number_28,GPIO_Qual_ASync);
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_28,GPIO_Pullup_Disable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_28,GPIO_28_Mode_GeneralPurpose);
    GPIO_setDirection(obj->gpioHandle,GPIO_Number_28,GPIO_Direction_Input);

    // DRV2
    GPIO_setLow(obj->gpioHandle,GPIO_Number_29);
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_29,GPIO_Pullup_Disable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_29,GPIO_29_Mode_GeneralPurpose);
    GPIO_setDirection(obj->gpioHandle,GPIO_Number_29,GPIO_Direction_Output);

    // RX-CAN
    GPIO_setQualification(obj->gpioHandle,GPIO_Number_30,GPIO_Qual_ASync);
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_30,GPIO_Pullup_Enable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_30,GPIO_30_Mode_CANRXA);

    // TX-CAN
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_31,GPIO_Pullup_Enable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_31,GPIO_31_Mode_CANTXA);

    // I2C-SDA
    GPIO_setQualification(obj->gpioHandle,GPIO_Number_32,GPIO_Qual_ASync);
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_32,GPIO_Pullup_Enable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_32,GPIO_32_Mode_SDDA);

    // I2C-SCL
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_33,GPIO_Pullup_Enable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_33,GPIO_33_Mode_SCLA);

    // No Connection
    GPIO_setMode(obj->gpioHandle,GPIO_Number_34,GPIO_34_Mode_GeneralPurpose);

    // JTAG
    GPIO_setMode(obj->gpioHandle,GPIO_Number_35,GPIO_35_Mode_JTAG_TDI);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_36,GPIO_36_Mode_JTAG_TMS);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_37,GPIO_37_Mode_JTAG_TDO);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_38,GPIO_38_Mode_JTAG_TCK);

    // Fault1
    GPIO_setQualification(obj->gpioHandle,GPIO_Number_39,GPIO_Qual_Sample_3);
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_39,GPIO_Pullup_Disable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_39,GPIO_39_Mode_GeneralPurpose);
    GPIO_setDirection(obj->gpioHandle,GPIO_Number_39,GPIO_Direction_Input);

    // No Connection
    GPIO_setMode(obj->gpioHandle,GPIO_Number_40,GPIO_40_Mode_GeneralPurpose);

    // No Connection
    GPIO_setMode(obj->gpioHandle,GPIO_Number_41,GPIO_41_Mode_GeneralPurpose);

    // Switch in 3, Low enable
    GPIO_setQualification(obj->gpioHandle,GPIO_Number_42,GPIO_Qual_Sample_3);
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_42,GPIO_Pullup_Disable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_42,GPIO_42_Mode_GeneralPurpose);
    GPIO_setDirection(obj->gpioHandle,GPIO_Number_42,GPIO_Direction_Input);

    // No Connection
    GPIO_setMode(obj->gpioHandle,GPIO_Number_43,GPIO_43_Mode_GeneralPurpose);

    // KSI
    GPIO_setQualification(obj->gpioHandle,GPIO_Number_44,GPIO_Qual_Sample_3);
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_44,GPIO_Pullup_Disable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_44,GPIO_44_Mode_GeneralPurpose);
    GPIO_setDirection(obj->gpioHandle,GPIO_Number_44,GPIO_Direction_Input);

    // ST2
    GPIO_setQualification(obj->gpioHandle,GPIO_Number_50,GPIO_Qual_Sample_3);
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_50,GPIO_Pullup_Enable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_50,GPIO_50_Mode_GeneralPurpose);
    GPIO_setDirection(obj->gpioHandle,GPIO_Number_50,GPIO_Direction_Input);

    // DVR1
    GPIO_setLow(obj->gpioHandle,GPIO_Number_51);
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_51,GPIO_Pullup_Disable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_51,GPIO_51_Mode_GeneralPurpose);
    GPIO_setDirection(obj->gpioHandle,GPIO_Number_51,GPIO_Direction_Output);

    // RDC-RST
    GPIO_setMode(obj->gpioHandle,GPIO_Number_52,GPIO_52_Mode_GeneralPurpose);
    GPIO_setQualification(obj->gpioHandle,GPIO_Number_52,GPIO_Qual_Sample_3);
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_52,GPIO_Pullup_Disable);
    GPIO_setDirection(obj->gpioHandle,GPIO_Number_52,GPIO_Direction_Output);
    GPIO_setHigh(obj->gpioHandle,GPIO_Number_52);

    // Fault2
    GPIO_setQualification(obj->gpioHandle,GPIO_Number_53,GPIO_Qual_Sample_3);
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_53,GPIO_Pullup_Disable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_53,GPIO_53_Mode_GeneralPurpose);
    GPIO_setDirection(obj->gpioHandle,GPIO_Number_53,GPIO_Direction_Input);

    // Fault3
    GPIO_setQualification(obj->gpioHandle,GPIO_Number_54,GPIO_Qual_Sample_3);
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_54,GPIO_Pullup_Disable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_54,GPIO_54_Mode_GeneralPurpose);
    GPIO_setDirection(obj->gpioHandle,GPIO_Number_54,GPIO_Direction_Input);

    //BuFF-En1
    GPIO_setQualification(obj->gpioHandle,GPIO_Number_55,GPIO_Qual_Sample_3);
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_55,GPIO_Pullup_Disable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_55,GPIO_55_Mode_GeneralPurpose);
    GPIO_setDirection(obj->gpioHandle,GPIO_Number_55,GPIO_Direction_Output);
    GPIO_setHigh(obj->gpioHandle,GPIO_Number_55);

    // No Connection
    GPIO_setMode(obj->gpioHandle,GPIO_Number_56,GPIO_56_Mode_GeneralPurpose);

    // RDC-CS
    GPIO_setQualification(obj->gpioHandle,GPIO_Number_57,GPIO_Qual_ASync);
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_57,GPIO_Pullup_Disable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_57,GPIO_57_Mode_SPISTEA_NOT);
    GPIO_setDirection(obj->gpioHandle,GPIO_Number_57,GPIO_Direction_Output);

    // LED1
    GPIO_setHigh(obj->gpioHandle,GPIO_Number_58);
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_58,GPIO_Pullup_Disable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_58,GPIO_58_Mode_GeneralPurpose);
    GPIO_setDirection(obj->gpioHandle,GPIO_Number_58,GPIO_Direction_Output);

  return;
}  // end of HAL_setupGpios() function
#elif EVCBD_ID == 0x08
void HAL_setupGpios(HAL_Handle handle)
{
    HAL_Obj *obj = (HAL_Obj *)handle;

    // PWM1
    GPIO_setMode(obj->gpioHandle,GPIO_Number_0,GPIO_0_Mode_EPWM1A);

    // PWM2
    GPIO_setMode(obj->gpioHandle,GPIO_Number_1,GPIO_1_Mode_EPWM1B);

    // PWM3
    GPIO_setMode(obj->gpioHandle,GPIO_Number_2,GPIO_2_Mode_EPWM2A);

    // PWM4
    GPIO_setMode(obj->gpioHandle,GPIO_Number_3,GPIO_3_Mode_EPWM2B);

    // PWM5
    GPIO_setMode(obj->gpioHandle,GPIO_Number_4,GPIO_4_Mode_EPWM3A);

    // PWM6
    GPIO_setMode(obj->gpioHandle,GPIO_Number_5,GPIO_5_Mode_EPWM3B);

    // IGBT_POWER_EN
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_6,GPIO_Pullup_Disable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_6,GPIO_6_Mode_GeneralPurpose);
    GPIO_setDirection(obj->gpioHandle,GPIO_Number_6,GPIO_Direction_Output);
    GPIO_setLow(obj->gpioHandle,GPIO_Number_6);

    // IGBT-RST
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_7,GPIO_Pullup_Disable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_7,GPIO_7_Mode_GeneralPurpose);
    GPIO_setDirection(obj->gpioHandle,GPIO_Number_7,GPIO_Direction_Output);
    GPIO_setLow(obj->gpioHandle,GPIO_Number_7);

    // IGBT_Fault1
    GPIO_setQualification(obj->gpioHandle,GPIO_Number_8,GPIO_Qual_Sample_3);
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_8,GPIO_Pullup_Disable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_8,GPIO_8_Mode_GeneralPurpose);
    GPIO_setDirection(obj->gpioHandle,GPIO_Number_8,GPIO_Direction_Input);
    // IGBT_Fault2
    GPIO_setQualification(obj->gpioHandle,GPIO_Number_9,GPIO_Qual_Sample_3);
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_9,GPIO_Pullup_Disable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_9,GPIO_9_Mode_GeneralPurpose);
    GPIO_setDirection(obj->gpioHandle,GPIO_Number_9,GPIO_Direction_Input);
    // IGBT_Fault3
    GPIO_setQualification(obj->gpioHandle,GPIO_Number_10,GPIO_Qual_Sample_3);
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_10,GPIO_Pullup_Disable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_10,GPIO_10_Mode_GeneralPurpose);
    GPIO_setDirection(obj->gpioHandle,GPIO_Number_10,GPIO_Direction_Input);

    // B+_TEST
    GPIO_setQualification(obj->gpioHandle,GPIO_Number_11,GPIO_Qual_Sample_3);
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_11,GPIO_Pullup_Disable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_11,GPIO_11_Mode_GeneralPurpose);
    GPIO_setDirection(obj->gpioHandle,GPIO_Number_11,GPIO_Direction_Input);

    // SWITCH5
    GPIO_setQualification(obj->gpioHandle,GPIO_Number_12,GPIO_Qual_Sample_3);
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_12,GPIO_Pullup_Disable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_12,GPIO_12_Mode_GeneralPurpose);
    GPIO_setDirection(obj->gpioHandle,GPIO_Number_12,GPIO_Direction_Input);

    // RDC-SAMPLE  //采样结果     1->0转移
    GPIO_setHigh(obj->gpioHandle,GPIO_Number_13);
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_13,GPIO_Pullup_Disable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_13,GPIO_13_Mode_GeneralPurpose);
    GPIO_setDirection(obj->gpioHandle,GPIO_Number_13,GPIO_Direction_Output);

    // TX-SCI
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_14,GPIO_Pullup_Disable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_14,GPIO_14_Mode_SCITXDB);

    // RX-SCI
    GPIO_setQualification(obj->gpioHandle,GPIO_Number_15,GPIO_Qual_ASync);
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_15,GPIO_Pullup_Disable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_15,GPIO_15_Mode_SCIRXDB);

    // ST1 高边驱动的状态
    GPIO_setQualification(obj->gpioHandle,GPIO_Number_16,GPIO_Qual_Sample_3);
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_16,GPIO_Pullup_Disable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_16,GPIO_16_Mode_GeneralPurpose);
    GPIO_setDirection(obj->gpioHandle,GPIO_Number_16,GPIO_Direction_Input);

    // RDC-SPI-SOMI  RDC_DATA旋变数据输入
    GPIO_setQualification(obj->gpioHandle,GPIO_Number_17,GPIO_Qual_ASync);
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_17,GPIO_Pullup_Enable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_17,GPIO_17_Mode_SPISOMIA);

    // RDC-SPI-CLK
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_18, GPIO_Pullup_Enable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_18,GPIO_18_Mode_SPICLKA);

    // XCLKIN
    // GPIO_setMode(obj->gpioHandle,GPIO_Number_19,GPIO_19_Mode_SPISTEA_NOT);

    // LED1
    GPIO_setLow(obj->gpioHandle,GPIO_Number_20);
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_20,GPIO_Pullup_Disable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_20,GPIO_20_Mode_GeneralPurpose);
    GPIO_setDirection(obj->gpioHandle,GPIO_Number_20,GPIO_Direction_Output);

    // LED2
    GPIO_setLow(obj->gpioHandle,GPIO_Number_21);
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_21,GPIO_Pullup_Disable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_21,GPIO_21_Mode_GeneralPurpose);
    GPIO_setDirection(obj->gpioHandle,GPIO_Number_21,GPIO_Direction_Output);

    // SWITCH1
    GPIO_setQualification(obj->gpioHandle,GPIO_Number_22,GPIO_Qual_Sample_3);
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_22,GPIO_Pullup_Disable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_22,GPIO_22_Mode_GeneralPurpose);
    GPIO_setDirection(obj->gpioHandle,GPIO_Number_22,GPIO_Direction_Input);


    //BuFF-En1
    GPIO_setQualification(obj->gpioHandle,GPIO_Number_23,GPIO_Qual_Sample_3);
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_23,GPIO_Pullup_Disable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_23,GPIO_23_Mode_GeneralPurpose);
    GPIO_setDirection(obj->gpioHandle,GPIO_Number_23,GPIO_Direction_Output);
    GPIO_setHigh(obj->gpioHandle,GPIO_Number_23);

    // EQEPA
    GPIO_setQualification(obj->gpioHandle,GPIO_Number_24,GPIO_Qual_Sample_3);
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_24,GPIO_Pullup_Enable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_24,GPIO_24_Mode_EQEP2A);

    // EQEPB
    GPIO_setQualification(obj->gpioHandle,GPIO_Number_25,GPIO_Qual_Sample_3);
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_25,GPIO_Pullup_Enable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_25,GPIO_25_Mode_EQEP2B);

    // RDC-DOS
    GPIO_setQualification(obj->gpioHandle,GPIO_Number_26,GPIO_Qual_Sample_3);
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_26,GPIO_Pullup_Enable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_26,GPIO_26_Mode_GeneralPurpose);
    GPIO_setDirection(obj->gpioHandle,GPIO_Number_26,GPIO_Direction_Input);
    // RDC-LOT
    GPIO_setQualification(obj->gpioHandle,GPIO_Number_27,GPIO_Qual_Sample_3);
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_27,GPIO_Pullup_Enable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_27,GPIO_27_Mode_GeneralPurpose);
    GPIO_setDirection(obj->gpioHandle,GPIO_Number_27,GPIO_Direction_Input);

    // I2C-SDA
    GPIO_setQualification(obj->gpioHandle,GPIO_Number_28,GPIO_Qual_ASync);
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_28,GPIO_Pullup_Enable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_28,GPIO_28_Mode_SDDA);

    // I2C-SCL
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_29,GPIO_Pullup_Enable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_29,GPIO_29_Mode_SCLA);

    // RX-CAN
    GPIO_setQualification(obj->gpioHandle,GPIO_Number_30,GPIO_Qual_ASync);
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_30,GPIO_Pullup_Enable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_30,GPIO_30_Mode_CANRXA);

    // TX-CAN
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_31,GPIO_Pullup_Enable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_31,GPIO_31_Mode_CANTXA);

    // SWITCH2
    GPIO_setQualification(obj->gpioHandle,GPIO_Number_32,GPIO_Qual_Sample_3);
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_32,GPIO_Pullup_Disable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_32,GPIO_32_Mode_GeneralPurpose);
    GPIO_setDirection(obj->gpioHandle,GPIO_Number_32,GPIO_Direction_Input);

    // SWITCH3
    GPIO_setQualification(obj->gpioHandle,GPIO_Number_33,GPIO_Qual_Sample_3);
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_33,GPIO_Pullup_Disable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_33,GPIO_33_Mode_GeneralPurpose);
    GPIO_setDirection(obj->gpioHandle,GPIO_Number_33,GPIO_Direction_Input);

//    上拉3.3V
    GPIO_setQualification(obj->gpioHandle,GPIO_Number_34,GPIO_Qual_Sample_3);
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_34,GPIO_Pullup_Disable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_34,GPIO_34_Mode_GeneralPurpose);
    GPIO_setDirection(obj->gpioHandle,GPIO_Number_34,GPIO_Direction_Input);

    // JTAG
    GPIO_setMode(obj->gpioHandle,GPIO_Number_35,GPIO_35_Mode_JTAG_TDI);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_36,GPIO_36_Mode_JTAG_TMS);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_37,GPIO_37_Mode_JTAG_TDO);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_38,GPIO_38_Mode_JTAG_TCK);

    // IN2 驱动2
    GPIO_setLow(obj->gpioHandle,GPIO_Number_39);
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_39,GPIO_Pullup_Disable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_39,GPIO_39_Mode_GeneralPurpose);
    GPIO_setDirection(obj->gpioHandle,GPIO_Number_39,GPIO_Direction_Output);

    // HOLD_Power
    GPIO_setLow(obj->gpioHandle,GPIO_Number_40);
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_40,GPIO_Pullup_Disable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_40,GPIO_40_Mode_GeneralPurpose);
    GPIO_setDirection(obj->gpioHandle,GPIO_Number_40,GPIO_Direction_Output);

    // KSI_TEST
    GPIO_setQualification(obj->gpioHandle,GPIO_Number_41,GPIO_Qual_Sample_3);
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_41,GPIO_Pullup_Disable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_41,GPIO_41_Mode_GeneralPurpose);
    GPIO_setDirection(obj->gpioHandle,GPIO_Number_41,GPIO_Direction_Input);

    // M1_Temp_ref
    GPIO_setMode(obj->gpioHandle,GPIO_Number_42,GPIO_42_Mode_EPWM8A);
    // M2_Temp_ref
    GPIO_setMode(obj->gpioHandle,GPIO_Number_43,GPIO_43_Mode_EPWM8B);

    // RDC_RD //输出缓冲使能 1->0转移 旋变
    GPIO_setHigh(obj->gpioHandle,GPIO_Number_44);
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_44,GPIO_Pullup_Disable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_44,GPIO_44_Mode_GeneralPurpose);
    GPIO_setDirection(obj->gpioHandle,GPIO_Number_44,GPIO_Direction_Output);

    // SWITCH4
    GPIO_setQualification(obj->gpioHandle,GPIO_Number_50,GPIO_Qual_Sample_3);
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_50,GPIO_Pullup_Enable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_50,GPIO_50_Mode_GeneralPurpose);
    GPIO_setDirection(obj->gpioHandle,GPIO_Number_50,GPIO_Direction_Input);
    // SWITCH6
    GPIO_setQualification(obj->gpioHandle,GPIO_Number_51,GPIO_Qual_Sample_3);
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_51,GPIO_Pullup_Enable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_51,GPIO_51_Mode_GeneralPurpose);
    GPIO_setDirection(obj->gpioHandle,GPIO_Number_51,GPIO_Direction_Input);
    //RDC_RST 旋变复位 0：有效
    GPIO_setLow(obj->gpioHandle,GPIO_Number_52);
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_52,GPIO_Pullup_Disable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_52,GPIO_52_Mode_GeneralPurpose);
    GPIO_setDirection(obj->gpioHandle,GPIO_Number_52,GPIO_Direction_Output);

    // IN1 驱动1
    GPIO_setLow(obj->gpioHandle,GPIO_Number_53);
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_53,GPIO_Pullup_Disable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_53,GPIO_53_Mode_GeneralPurpose);
    GPIO_setDirection(obj->gpioHandle,GPIO_Number_53,GPIO_Direction_Output);
    // IN3 驱动3
    GPIO_setLow(obj->gpioHandle,GPIO_Number_54);
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_54,GPIO_Pullup_Disable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_54,GPIO_54_Mode_GeneralPurpose);
    GPIO_setDirection(obj->gpioHandle,GPIO_Number_54,GPIO_Direction_Output);
    // IN4 驱动4
    GPIO_setLow(obj->gpioHandle,GPIO_Number_55);
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_55,GPIO_Pullup_Disable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_55,GPIO_55_Mode_GeneralPurpose);
    GPIO_setDirection(obj->gpioHandle,GPIO_Number_55,GPIO_Direction_Output);
    // ST2 高边驱动的状态
    GPIO_setQualification(obj->gpioHandle,GPIO_Number_56,GPIO_Qual_Sample_3);
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_56,GPIO_Pullup_Disable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_56,GPIO_56_Mode_GeneralPurpose);
    GPIO_setDirection(obj->gpioHandle,GPIO_Number_56,GPIO_Direction_Input);

    // RDC-SPI-CS
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_57, GPIO_Pullup_Enable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_57,GPIO_57_Mode_SPISTEA_NOT);

    // RDC-RDVEL, 1:位置  0:速度
    GPIO_setHigh(obj->gpioHandle,GPIO_Number_58);
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_58,GPIO_Pullup_Disable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_58,GPIO_58_Mode_GeneralPurpose);
    GPIO_setDirection(obj->gpioHandle,GPIO_Number_58,GPIO_Direction_Output);

#if 0
    // SWITCH8
    ENABLE_PROTECTED_REGISTER_WRITE_MODE;
    obj->gpioHandle->AIOMUX1 &= (~0x30000000);
    DISABLE_PROTECTED_REGISTER_WRITE_MODE;
#endif
  return;
}  // end of HAL_setupGpios() function
#elif EVCBD_ID == 0x09
void HAL_setupGpios(HAL_Handle handle)
{
    HAL_Obj *obj = (HAL_Obj *)handle;

    // PWM1
    GPIO_setMode(obj->gpioHandle,GPIO_Number_0,GPIO_0_Mode_EPWM1A);

    // PWM2
    GPIO_setMode(obj->gpioHandle,GPIO_Number_1,GPIO_1_Mode_EPWM1B);

    // PWM3
    GPIO_setMode(obj->gpioHandle,GPIO_Number_2,GPIO_2_Mode_EPWM2A);

    // PWM4
    GPIO_setMode(obj->gpioHandle,GPIO_Number_3,GPIO_3_Mode_EPWM2B);

    // PWM5
    GPIO_setMode(obj->gpioHandle,GPIO_Number_4,GPIO_4_Mode_EPWM3A);

    // PWM6
    GPIO_setMode(obj->gpioHandle,GPIO_Number_5,GPIO_5_Mode_EPWM3B);


    // PWM1_OUT
    GPIO_setMode(obj->gpioHandle,GPIO_Number_6,GPIO_6_Mode_EPWM4A);
    // PWM2_OUT
    GPIO_setMode(obj->gpioHandle,GPIO_Number_7,GPIO_7_Mode_EPWM4B);
    // PWM3_OUT
    GPIO_setMode(obj->gpioHandle,GPIO_Number_8,GPIO_8_Mode_EPWM5A);
    // PWM4_OUT
    GPIO_setMode(obj->gpioHandle,GPIO_Number_9,GPIO_9_Mode_EPWM5B);


  //  // PWM1_OUT ,上拉
  //  GPIO_setHigh(obj->gpioHandle,GPIO_Number_6);
  //  GPIO_setPullup(obj->gpioHandle,GPIO_Number_6,GPIO_Pullup_Enable);
  //  GPIO_setMode(obj->gpioHandle,GPIO_Number_6,GPIO_6_Mode_GeneralPurpose);
  //  GPIO_setDirection(obj->gpioHandle,GPIO_Number_6,GPIO_Direction_Output);
  //
  //  // PWM2_OUT
  //  GPIO_setHigh(obj->gpioHandle,GPIO_Number_7);
  //  GPIO_setPullup(obj->gpioHandle,GPIO_Number_7,GPIO_Pullup_Enable);
  //  GPIO_setMode(obj->gpioHandle,GPIO_Number_7,GPIO_7_Mode_GeneralPurpose);
  //  GPIO_setDirection(obj->gpioHandle,GPIO_Number_7,GPIO_Direction_Output);

  //  // PWM3_OUT
  //  GPIO_setHigh(obj->gpioHandle,GPIO_Number_8);
  //  GPIO_setPullup(obj->gpioHandle,GPIO_Number_8,GPIO_Pullup_Enable);
  //  GPIO_setMode(obj->gpioHandle,GPIO_Number_8,GPIO_8_Mode_GeneralPurpose);
  //  GPIO_setDirection(obj->gpioHandle,GPIO_Number_8,GPIO_Direction_Output);
  //
  //  // PWM4_0UT
  //  GPIO_setHigh(obj->gpioHandle,GPIO_Number_9);
  //  GPIO_setPullup(obj->gpioHandle,GPIO_Number_9,GPIO_Pullup_Enable);
  //  GPIO_setMode(obj->gpioHandle,GPIO_Number_9,GPIO_9_Mode_GeneralPurpose);
  //  GPIO_setDirection(obj->gpioHandle,GPIO_Number_9,GPIO_Direction_Output);

    // PWM5_OUT
    GPIO_setHigh(obj->gpioHandle,GPIO_Number_10);
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_10,GPIO_Pullup_Enable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_10,GPIO_10_Mode_GeneralPurpose);
    GPIO_setDirection(obj->gpioHandle,GPIO_Number_10,GPIO_Direction_Output);

    // POL_LOW_EN
    GPIO_setLow(obj->gpioHandle,GPIO_Number_11);
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_11,GPIO_Pullup_Disable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_11,GPIO_11_Mode_GeneralPurpose);
    GPIO_setDirection(obj->gpioHandle,GPIO_Number_11,GPIO_Direction_Output);

    // STATUS-DRV4
    GPIO_setQualification(obj->gpioHandle,GPIO_Number_12,GPIO_Qual_Sample_3);
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_12,GPIO_Pullup_Disable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_12,GPIO_12_Mode_GeneralPurpose);
    GPIO_setDirection(obj->gpioHandle,GPIO_Number_12,GPIO_Direction_Input);

    // SW5
    GPIO_setQualification(obj->gpioHandle,GPIO_Number_13,GPIO_Qual_Sample_3);
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_13,GPIO_Pullup_Enable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_13,GPIO_13_Mode_GeneralPurpose);
    GPIO_setDirection(obj->gpioHandle,GPIO_Number_13,GPIO_Direction_Input);

    // LED1
    GPIO_setLow(obj->gpioHandle,GPIO_Number_14);
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_14,GPIO_Pullup_Disable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_14,GPIO_14_Mode_GeneralPurpose);
    GPIO_setDirection(obj->gpioHandle,GPIO_Number_14,GPIO_Direction_Output);

    // LED2
    GPIO_setLow(obj->gpioHandle,GPIO_Number_15);
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_15,GPIO_Pullup_Disable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_15,GPIO_15_Mode_GeneralPurpose);
    GPIO_setDirection(obj->gpioHandle,GPIO_Number_15,GPIO_Direction_Output);

    // 电机温度检测控制2
    GPIO_setLow(obj->gpioHandle,GPIO_Number_16);
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_16,GPIO_Pullup_Disable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_16,GPIO_16_Mode_GeneralPurpose);
    GPIO_setDirection(obj->gpioHandle,GPIO_Number_16,GPIO_Direction_Output);


    // RDC-SPI-SOMI  RDC_DATA旋变数据输入
    GPIO_setQualification(obj->gpioHandle,GPIO_Number_17,GPIO_Qual_ASync);
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_17,GPIO_Pullup_Enable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_17,GPIO_17_Mode_SPISOMIA);

    // RDC-SPI-CLK
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_18, GPIO_Pullup_Enable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_18,GPIO_18_Mode_SPICLKA);

    // XCLKIN
    // GPIO_setMode(obj->gpioHandle,GPIO_Number_19,GPIO_19_Mode_SPISTEA_NOT);

    // SW3
    GPIO_setQualification(obj->gpioHandle,GPIO_Number_20,GPIO_Qual_Sample_3);
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_20,GPIO_Pullup_Enable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_20,GPIO_20_Mode_GeneralPurpose);
    GPIO_setDirection(obj->gpioHandle,GPIO_Number_20,GPIO_Direction_Input);


    // RDC-LOT
    GPIO_setQualification(obj->gpioHandle,GPIO_Number_21,GPIO_Qual_Sample_3);
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_21,GPIO_Pullup_Enable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_21,GPIO_21_Mode_GeneralPurpose);
    GPIO_setDirection(obj->gpioHandle,GPIO_Number_21,GPIO_Direction_Input);

    // SW6
    GPIO_setQualification(obj->gpioHandle,GPIO_Number_22,GPIO_Qual_Sample_3);
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_22,GPIO_Pullup_Enable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_22,GPIO_22_Mode_GeneralPurpose);
    GPIO_setDirection(obj->gpioHandle,GPIO_Number_22,GPIO_Direction_Input);

    // POT低端检测
    GPIO_setQualification(obj->gpioHandle,GPIO_Number_23,GPIO_Qual_Sample_3);
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_23,GPIO_Pullup_Enable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_23,GPIO_23_Mode_GeneralPurpose);
    GPIO_setDirection(obj->gpioHandle,GPIO_Number_23,GPIO_Direction_Input);

    // RDC-A-QEP
    GPIO_setQualification(obj->gpioHandle,GPIO_Number_24,GPIO_Qual_Sample_3);
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_24,GPIO_Pullup_Enable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_24,GPIO_24_Mode_EQEP2A);

    // RDC-B-QEP
    GPIO_setQualification(obj->gpioHandle,GPIO_Number_25,GPIO_Qual_Sample_3);
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_25,GPIO_Pullup_Enable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_25,GPIO_25_Mode_EQEP2B);

    // ENC-Z
    GPIO_setQualification(obj->gpioHandle,GPIO_Number_26,GPIO_Qual_Sample_3);
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_26,GPIO_Pullup_Enable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_26,GPIO_26_Mode_EQEP2I);

    // RDC-DOS
    GPIO_setQualification(obj->gpioHandle,GPIO_Number_27,GPIO_Qual_Sample_3);
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_27,GPIO_Pullup_Enable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_27,GPIO_27_Mode_GeneralPurpose);
    GPIO_setDirection(obj->gpioHandle,GPIO_Number_27,GPIO_Direction_Input);

    // I2C-SDA
    GPIO_setQualification(obj->gpioHandle,GPIO_Number_28,GPIO_Qual_ASync);
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_28,GPIO_Pullup_Enable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_28,GPIO_28_Mode_SDDA);

    // I2C-SCL
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_29,GPIO_Pullup_Enable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_29,GPIO_29_Mode_SCLA);

    // RX-CAN
    GPIO_setQualification(obj->gpioHandle,GPIO_Number_30,GPIO_Qual_ASync);
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_30,GPIO_Pullup_Enable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_30,GPIO_30_Mode_CANRXA);

    // TX-CAN
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_31,GPIO_Pullup_Enable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_31,GPIO_31_Mode_CANTXA);

    // SW7
    GPIO_setQualification(obj->gpioHandle,GPIO_Number_32,GPIO_Qual_Sample_3);
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_32,GPIO_Pullup_Enable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_32,GPIO_32_Mode_GeneralPurpose);
    GPIO_setDirection(obj->gpioHandle,GPIO_Number_32,GPIO_Direction_Input);

    // SW8
    GPIO_setQualification(obj->gpioHandle,GPIO_Number_33,GPIO_Qual_Sample_3);
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_33,GPIO_Pullup_Enable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_33,GPIO_33_Mode_GeneralPurpose);
    GPIO_setDirection(obj->gpioHandle,GPIO_Number_33,GPIO_Direction_Input);

    // RDC-RDVEL, 1:位置  0:速度
    GPIO_setHigh(obj->gpioHandle,GPIO_Number_34);
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_34,GPIO_Pullup_Disable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_34,GPIO_34_Mode_GeneralPurpose);
    GPIO_setDirection(obj->gpioHandle,GPIO_Number_34,GPIO_Direction_Output);

    // JTAG
    GPIO_setMode(obj->gpioHandle,GPIO_Number_35,GPIO_35_Mode_JTAG_TDI);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_36,GPIO_36_Mode_JTAG_TMS);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_37,GPIO_37_Mode_JTAG_TDO);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_38,GPIO_38_Mode_JTAG_TCK);

    // RDC-SAMPLE  //采样结果     1->0转移
    GPIO_setHigh(obj->gpioHandle,GPIO_Number_39);
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_39,GPIO_Pullup_Disable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_39,GPIO_39_Mode_GeneralPurpose);
    GPIO_setDirection(obj->gpioHandle,GPIO_Number_39,GPIO_Direction_Output);

    // 电机温度检测 控制
    GPIO_setLow(obj->gpioHandle,GPIO_Number_40);
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_40,GPIO_Pullup_Disable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_40,GPIO_40_Mode_GeneralPurpose);
    GPIO_setDirection(obj->gpioHandle,GPIO_Number_40,GPIO_Direction_Output);

    // THRO POT 控制
    GPIO_setLow(obj->gpioHandle,GPIO_Number_41);
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_41,GPIO_Pullup_Disable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_41,GPIO_41_Mode_GeneralPurpose);
    GPIO_setDirection(obj->gpioHandle,GPIO_Number_41,GPIO_Direction_Output);
    // BRA POT 控制
    GPIO_setLow(obj->gpioHandle,GPIO_Number_42);
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_42,GPIO_Pullup_Disable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_42,GPIO_42_Mode_GeneralPurpose);
    GPIO_setDirection(obj->gpioHandle,GPIO_Number_42,GPIO_Direction_Output);
    // PreCharge
    GPIO_setLow(obj->gpioHandle,GPIO_Number_43);
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_43,GPIO_Pullup_Disable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_43,GPIO_43_Mode_GeneralPurpose);
    GPIO_setDirection(obj->gpioHandle,GPIO_Number_43,GPIO_Direction_Output);


    //RDC_RST 旋变复位 0：有效
    GPIO_setLow(obj->gpioHandle,GPIO_Number_44);
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_44,GPIO_Pullup_Disable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_44,GPIO_44_Mode_GeneralPurpose);
    GPIO_setDirection(obj->gpioHandle,GPIO_Number_44,GPIO_Direction_Output);



    // RDC_RD //输出缓冲使能 1->0转移 旋变
    GPIO_setLow(obj->gpioHandle,GPIO_Number_50);
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_50,GPIO_Pullup_Disable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_50,GPIO_50_Mode_GeneralPurpose);
    GPIO_setDirection(obj->gpioHandle,GPIO_Number_50,GPIO_Direction_Output);


    //EN-PWM
    GPIO_setLow(obj->gpioHandle,GPIO_Number_51);
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_51,GPIO_Pullup_Disable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_51,GPIO_51_Mode_GeneralPurpose);
    GPIO_setDirection(obj->gpioHandle,GPIO_Number_51,GPIO_Direction_Output);

    //STATUS-DRV1
    GPIO_setQualification(obj->gpioHandle,GPIO_Number_52,GPIO_Qual_Sample_3);
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_52,GPIO_Pullup_Disable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_52,GPIO_52_Mode_GeneralPurpose);
    GPIO_setDirection(obj->gpioHandle,GPIO_Number_52,GPIO_Direction_Input);

    // KSI-DSP
    GPIO_setQualification(obj->gpioHandle,GPIO_Number_53,GPIO_Qual_Sample_3);
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_53,GPIO_Pullup_Disable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_53,GPIO_53_Mode_GeneralPurpose);
    GPIO_setDirection(obj->gpioHandle,GPIO_Number_53,GPIO_Direction_Input);

    // Keep-power
    GPIO_setLow(obj->gpioHandle,GPIO_Number_54);
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_54,GPIO_Pullup_Disable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_54,GPIO_54_Mode_GeneralPurpose);
    GPIO_setDirection(obj->gpioHandle,GPIO_Number_54,GPIO_Direction_Output);

    //STATUS-DRV2
    GPIO_setQualification(obj->gpioHandle,GPIO_Number_55,GPIO_Qual_Sample_3);
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_55,GPIO_Pullup_Disable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_55,GPIO_55_Mode_GeneralPurpose);
    GPIO_setDirection(obj->gpioHandle,GPIO_Number_55,GPIO_Direction_Input);

    //STATUS-DRV3
    GPIO_setQualification(obj->gpioHandle,GPIO_Number_56,GPIO_Qual_Sample_3);
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_56,GPIO_Pullup_Disable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_56,GPIO_56_Mode_GeneralPurpose);
    GPIO_setDirection(obj->gpioHandle,GPIO_Number_56,GPIO_Direction_Input);

    // RDC-SPI-CS
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_57, GPIO_Pullup_Enable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_57,GPIO_57_Mode_SPISTEA_NOT);

    // SW4
    GPIO_setQualification(obj->gpioHandle,GPIO_Number_58,GPIO_Qual_Sample_3);
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_58,GPIO_Pullup_Disable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_58,GPIO_58_Mode_GeneralPurpose);
    GPIO_setDirection(obj->gpioHandle,GPIO_Number_58,GPIO_Direction_Input);

    return;
}  // end of HAL_setupGpios() function
#elif EVCBD_ID == 0x0D
void HAL_setupGpios(HAL_Handle handle)
{
    HAL_Obj *obj = (HAL_Obj *)handle;

    // JTAG
    GPIO_setMode(obj->gpioHandle,GPIO_Number_35,GPIO_35_Mode_JTAG_TDI);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_36,GPIO_36_Mode_JTAG_TMS);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_37,GPIO_37_Mode_JTAG_TDO);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_38,GPIO_38_Mode_JTAG_TCK);

    // PWM1
    GPIO_setMode(obj->gpioHandle,GPIO_Number_0,GPIO_0_Mode_EPWM1A);
    // PWM2
    GPIO_setMode(obj->gpioHandle,GPIO_Number_1,GPIO_1_Mode_EPWM1B);
    // PWM3
    GPIO_setMode(obj->gpioHandle,GPIO_Number_2,GPIO_2_Mode_EPWM2A);
    // PWM4
    GPIO_setMode(obj->gpioHandle,GPIO_Number_3,GPIO_3_Mode_EPWM2B);
    // PWM5
    GPIO_setMode(obj->gpioHandle,GPIO_Number_4,GPIO_4_Mode_EPWM3A);
    // PWM6
    GPIO_setMode(obj->gpioHandle,GPIO_Number_5,GPIO_5_Mode_EPWM3B);

    // IGBT_POWER_EN
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_6,GPIO_Pullup_Disable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_6,GPIO_6_Mode_GeneralPurpose);
    GPIO_setDirection(obj->gpioHandle,GPIO_Number_6,GPIO_Direction_Output);
    GPIO_setLow(obj->gpioHandle,GPIO_Number_6);
    // IGBT-RST
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_7,GPIO_Pullup_Disable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_7,GPIO_7_Mode_GeneralPurpose);
    GPIO_setDirection(obj->gpioHandle,GPIO_Number_7,GPIO_Direction_Output);
    GPIO_setLow(obj->gpioHandle,GPIO_Number_7);
    // IGBT_Fault1
    GPIO_setQualification(obj->gpioHandle,GPIO_Number_8,GPIO_Qual_Sample_3);
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_8,GPIO_Pullup_Disable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_8,GPIO_8_Mode_GeneralPurpose);
    GPIO_setDirection(obj->gpioHandle,GPIO_Number_8,GPIO_Direction_Input);
    // IGBT_Fault2
    GPIO_setQualification(obj->gpioHandle,GPIO_Number_9,GPIO_Qual_Sample_3);
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_9,GPIO_Pullup_Disable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_9,GPIO_9_Mode_GeneralPurpose);
    GPIO_setDirection(obj->gpioHandle,GPIO_Number_9,GPIO_Direction_Input);
    // IGBT_Fault3
    GPIO_setQualification(obj->gpioHandle,GPIO_Number_10,GPIO_Qual_Sample_3);
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_10,GPIO_Pullup_Disable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_10,GPIO_10_Mode_GeneralPurpose);
    GPIO_setDirection(obj->gpioHandle,GPIO_Number_10,GPIO_Direction_Input);

    // TX-SCI
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_22,GPIO_Pullup_Disable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_22,GPIO_22_Mode_SCITXDB);
    // RX-SCI
    GPIO_setQualification(obj->gpioHandle,GPIO_Number_23,GPIO_Qual_ASync);
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_23,GPIO_Pullup_Disable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_23,GPIO_23_Mode_SCIRXDB);

    // M1_Temp_ref
    GPIO_setMode(obj->gpioHandle,GPIO_Number_42,GPIO_42_Mode_EPWM8A);
    // M2_Temp_ref
    GPIO_setMode(obj->gpioHandle,GPIO_Number_43,GPIO_43_Mode_EPWM8B);

    // RDC-SPI-CS
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_57, GPIO_Pullup_Enable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_57,GPIO_57_Mode_SPISTEA_NOT);

    // RDC-SPI-SOMI  RDC_DATA旋变数据输入
    GPIO_setQualification(obj->gpioHandle,GPIO_Number_17,GPIO_Qual_ASync);
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_17,GPIO_Pullup_Enable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_17,GPIO_17_Mode_SPISOMIA);

    // RDC-SPI-CLK  RDC-SCK
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_18, GPIO_Pullup_Enable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_18,GPIO_18_Mode_SPICLKA);

    // EQEPA
    GPIO_setQualification(obj->gpioHandle,GPIO_Number_20,GPIO_Qual_Sample_3);
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_20,GPIO_Pullup_Enable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_20,GPIO_20_Mode_EQEP1A);

    // EQEPB
    GPIO_setQualification(obj->gpioHandle,GPIO_Number_21,GPIO_Qual_Sample_3);
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_21,GPIO_Pullup_Enable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_21,GPIO_21_Mode_EQEP1B);

    // RDC-DOS
    GPIO_setQualification(obj->gpioHandle,GPIO_Number_26,GPIO_Qual_Sample_3);
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_26,GPIO_Pullup_Enable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_26,GPIO_26_Mode_GeneralPurpose);
    GPIO_setDirection(obj->gpioHandle,GPIO_Number_26,GPIO_Direction_Input);

    // RDC-LOT
    GPIO_setQualification(obj->gpioHandle,GPIO_Number_27,GPIO_Qual_Sample_3);
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_27,GPIO_Pullup_Enable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_27,GPIO_27_Mode_GeneralPurpose);
    GPIO_setDirection(obj->gpioHandle,GPIO_Number_27,GPIO_Direction_Input);

    // RDC-RDVEL, 1:位置  0:速度
    GPIO_setHigh(obj->gpioHandle,GPIO_Number_58);
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_58,GPIO_Pullup_Disable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_58,GPIO_58_Mode_GeneralPurpose);
    GPIO_setDirection(obj->gpioHandle,GPIO_Number_58,GPIO_Direction_Output);

    // RDC-SAMPLE  //采样结果     1->0转移
    GPIO_setHigh(obj->gpioHandle,GPIO_Number_13);
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_13,GPIO_Pullup_Disable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_13,GPIO_13_Mode_GeneralPurpose);
    GPIO_setDirection(obj->gpioHandle,GPIO_Number_13,GPIO_Direction_Output);

    // RDC_RD //输出缓冲使能 1->0转移 旋变
    GPIO_setHigh(obj->gpioHandle,GPIO_Number_44);
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_44,GPIO_Pullup_Disable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_44,GPIO_44_Mode_GeneralPurpose);
    GPIO_setDirection(obj->gpioHandle,GPIO_Number_44,GPIO_Direction_Output);

    //RDC_RST 旋变复位 0：有效
    GPIO_setLow(obj->gpioHandle,GPIO_Number_52);
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_52,GPIO_Pullup_Disable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_52,GPIO_52_Mode_GeneralPurpose);
    GPIO_setDirection(obj->gpioHandle,GPIO_Number_52,GPIO_Direction_Output);

    // I2C-SDA
    GPIO_setQualification(obj->gpioHandle,GPIO_Number_28,GPIO_Qual_ASync);
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_28,GPIO_Pullup_Enable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_28,GPIO_28_Mode_SDDA);

    // I2C-SCL
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_29,GPIO_Pullup_Enable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_29,GPIO_29_Mode_SCLA);

    // RX-CAN
    GPIO_setQualification(obj->gpioHandle,GPIO_Number_30,GPIO_Qual_ASync);
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_30,GPIO_Pullup_Enable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_30,GPIO_30_Mode_CANRXA);

    // TX-CAN
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_31,GPIO_Pullup_Enable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_31,GPIO_31_Mode_CANTXA);

    // LED1
    GPIO_setLow(obj->gpioHandle,GPIO_Number_32);
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_32,GPIO_Pullup_Disable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_32,GPIO_32_Mode_GeneralPurpose);
    GPIO_setDirection(obj->gpioHandle,GPIO_Number_32,GPIO_Direction_Output);

    // LED2
    GPIO_setLow(obj->gpioHandle,GPIO_Number_33);
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_33,GPIO_Pullup_Disable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_33,GPIO_33_Mode_GeneralPurpose);
    GPIO_setDirection(obj->gpioHandle,GPIO_Number_33,GPIO_Direction_Output);






    // BuFF-En1
    GPIO_setQualification(obj->gpioHandle,GPIO_Number_16,GPIO_Qual_Sample_3);
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_16,GPIO_Pullup_Disable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_16,GPIO_16_Mode_GeneralPurpose);
    GPIO_setDirection(obj->gpioHandle,GPIO_Number_16,GPIO_Direction_Output);
    GPIO_setHigh(obj->gpioHandle,GPIO_Number_16);

    // B+-Test
    GPIO_setQualification(obj->gpioHandle,GPIO_Number_14,GPIO_Qual_Sample_3);
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_14,GPIO_Pullup_Disable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_14,GPIO_14_Mode_GeneralPurpose);
    GPIO_setDirection(obj->gpioHandle,GPIO_Number_14,GPIO_Direction_Input);

    // HOLD-Power
    GPIO_setQualification(obj->gpioHandle,GPIO_Number_15,GPIO_Qual_Sample_3);
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_15,GPIO_Pullup_Disable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_15,GPIO_15_Mode_GeneralPurpose);
    GPIO_setDirection(obj->gpioHandle,GPIO_Number_15,GPIO_Direction_Output);

    // KSI
    GPIO_setQualification(obj->gpioHandle,GPIO_Number_24,GPIO_Qual_Sample_3);
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_24,GPIO_Pullup_Disable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_24,GPIO_24_Mode_GeneralPurpose);
    GPIO_setDirection(obj->gpioHandle,GPIO_Number_24,GPIO_Direction_Input);



    // 电机温度检测 控制1
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_34,GPIO_Pullup_Disable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_34,GPIO_34_Mode_GeneralPurpose);
    GPIO_setDirection(obj->gpioHandle,GPIO_Number_34,GPIO_Direction_Output);
    GPIO_setLow(obj->gpioHandle,GPIO_Number_34);
//    GPIO_setHigh(obj->gpioHandle,GPIO_Number_34);
    // 电机温度检测 控制2
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_39,GPIO_Pullup_Disable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_39,GPIO_39_Mode_GeneralPurpose);
    GPIO_setDirection(obj->gpioHandle,GPIO_Number_39,GPIO_Direction_Output);
    GPIO_setLow(obj->gpioHandle,GPIO_Number_39);
//    GPIO_setHigh(obj->gpioHandle,GPIO_Number_39);

    // SWITCH2
    GPIO_setQualification(obj->gpioHandle,GPIO_Number_50,GPIO_Qual_Sample_3);
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_50,GPIO_Pullup_Enable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_50,GPIO_50_Mode_GeneralPurpose);
    GPIO_setDirection(obj->gpioHandle,GPIO_Number_50,GPIO_Direction_Input);
    // SWITCH3
    GPIO_setQualification(obj->gpioHandle,GPIO_Number_54,GPIO_Qual_Sample_3);
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_54,GPIO_Pullup_Enable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_54,GPIO_54_Mode_GeneralPurpose);
    GPIO_setDirection(obj->gpioHandle,GPIO_Number_54,GPIO_Direction_Input);
    // SWITCH4
    GPIO_setQualification(obj->gpioHandle,GPIO_Number_53,GPIO_Qual_Sample_3);
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_53,GPIO_Pullup_Enable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_53,GPIO_53_Mode_GeneralPurpose);
    GPIO_setDirection(obj->gpioHandle,GPIO_Number_53,GPIO_Direction_Input);
    // SWITCH5
    GPIO_setQualification(obj->gpioHandle,GPIO_Number_12,GPIO_Qual_Sample_3);
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_12,GPIO_Pullup_Enable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_12,GPIO_12_Mode_GeneralPurpose);
    GPIO_setDirection(obj->gpioHandle,GPIO_Number_12,GPIO_Direction_Input);
    // SWITCH6
    GPIO_setQualification(obj->gpioHandle,GPIO_Number_51,GPIO_Qual_Sample_3);
    GPIO_setPullup(obj->gpioHandle,GPIO_Number_51,GPIO_Pullup_Enable);
    GPIO_setMode(obj->gpioHandle,GPIO_Number_51,GPIO_51_Mode_GeneralPurpose);
    GPIO_setDirection(obj->gpioHandle,GPIO_Number_51,GPIO_Direction_Input);

    // XCLKIN
    // GPIO_setMode(obj->gpioHandle,GPIO_Number_19,GPIO_19_Mode_SPISTEA_NOT);

  return;
}  // end of HAL_setupGpios() function






#endif

