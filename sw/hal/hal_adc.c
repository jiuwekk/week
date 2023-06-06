//! \file       hal_adc.c
//! \brief      Contains various functions related to the ADC object
//! \author     sunyanjun
//! \version    1.0
//! \date       2017.03.21
//! \copyright  SANTROLL


// ============================================================================
// the includes
#include"sw/config/config.h"

#if  EVCBD_ID == 0x01
void HAL_setupAdcs(HAL_Handle handle)
{
  HAL_Obj *obj = (HAL_Obj *)handle;


  // disable the ADCs
  ADC_disable(obj->adcHandle);

  // power up the bandgap circuit
  ADC_enableBandGap(obj->adcHandle);

  // set the ADC voltage reference source to internal
  ADC_setVoltRefSrc(obj->adcHandle,ADC_VoltageRefSrc_Int);

  // enable the ADC reference buffers
  ADC_enableRefBuffers(obj->adcHandle);

  // Set main clock scaling factor (max45MHz clock for the ADC module)
  ADC_setDivideSelect(obj->adcHandle,ADC_DivideSelect_ClkIn_by_2);

  // power up the ADCs
  ADC_powerUp(obj->adcHandle);

  // enable the ADCs
  ADC_enable(obj->adcHandle);

  // set the ADC interrupt pulse generation to prior
  ADC_setIntPulseGenMode(obj->adcHandle,ADC_IntPulseGenMode_Prior);

  // set the temperature sensor source to external
  ADC_setTempSensorSrc(obj->adcHandle,ADC_TempSensorSrc_Ext);

  // configure the interrupt sources
  ADC_disableInt(obj->adcHandle,ADC_IntNumber_1);
  ADC_setIntMode(obj->adcHandle,ADC_IntNumber_1,ADC_IntMode_ClearFlag);
  ADC_setIntSrc(obj->adcHandle,ADC_IntNumber_1,ADC_IntSrc_EOC15);

  //configure the SOCs
  // IU
  ADC_setSocChanNumber(obj->adcHandle,ADC_SocNumber_0,ADC_SocChanNumber_A0);
  ADC_setSocTrigSrc(obj->adcHandle,ADC_SocNumber_0,ADC_SocTrigSrc_EPWM1_ADCSOCA);
  ADC_setSocSampleDelay(obj->adcHandle,ADC_SocNumber_0,ADC_SocSampleDelay_9_cycles);

  // Duplicate conversion due to ADC Initial Conversion bug (SPRZ342)
  // IU
  ADC_setSocChanNumber(obj->adcHandle,ADC_SocNumber_1,ADC_SocChanNumber_A0);
  ADC_setSocTrigSrc(obj->adcHandle,ADC_SocNumber_1,ADC_SocTrigSrc_EPWM1_ADCSOCA);
  ADC_setSocSampleDelay(obj->adcHandle,ADC_SocNumber_1,ADC_SocSampleDelay_9_cycles);

  // IV
  ADC_setSocChanNumber(obj->adcHandle,ADC_SocNumber_2,ADC_SocChanNumber_A1);
  ADC_setSocTrigSrc(obj->adcHandle,ADC_SocNumber_2,ADC_SocTrigSrc_EPWM1_ADCSOCA);
  ADC_setSocSampleDelay(obj->adcHandle,ADC_SocNumber_2,ADC_SocSampleDelay_9_cycles);

  // IW
  ADC_setSocChanNumber(obj->adcHandle,ADC_SocNumber_3,ADC_SocChanNumber_A2);
  ADC_setSocTrigSrc(obj->adcHandle,ADC_SocNumber_3,ADC_SocTrigSrc_EPWM1_ADCSOCA);
  ADC_setSocSampleDelay(obj->adcHandle,ADC_SocNumber_3,ADC_SocSampleDelay_9_cycles);

  // VU
  ADC_setSocChanNumber(obj->adcHandle,ADC_SocNumber_4,ADC_SocChanNumber_A3);
  ADC_setSocTrigSrc(obj->adcHandle,ADC_SocNumber_4,ADC_SocTrigSrc_EPWM1_ADCSOCA);
  ADC_setSocSampleDelay(obj->adcHandle,ADC_SocNumber_4,ADC_SocSampleDelay_9_cycles);

  // VV
  ADC_setSocChanNumber(obj->adcHandle,ADC_SocNumber_5,ADC_SocChanNumber_A4);
  ADC_setSocTrigSrc(obj->adcHandle,ADC_SocNumber_5,ADC_SocTrigSrc_EPWM1_ADCSOCA);
  ADC_setSocSampleDelay(obj->adcHandle,ADC_SocNumber_5,ADC_SocSampleDelay_9_cycles);

  // VW
  ADC_setSocChanNumber(obj->adcHandle,ADC_SocNumber_6,ADC_SocChanNumber_A5);
  ADC_setSocTrigSrc(obj->adcHandle,ADC_SocNumber_6,ADC_SocTrigSrc_EPWM1_ADCSOCA);
  ADC_setSocSampleDelay(obj->adcHandle,ADC_SocNumber_6,ADC_SocSampleDelay_9_cycles);

  // CAP-VOLTAGE
  ADC_setSocChanNumber(obj->adcHandle,ADC_SocNumber_7,ADC_SocChanNumber_A6);
  ADC_setSocTrigSrc(obj->adcHandle,ADC_SocNumber_7,ADC_SocTrigSrc_EPWM1_ADCSOCA);
  ADC_setSocSampleDelay(obj->adcHandle,ADC_SocNumber_7,ADC_SocSampleDelay_9_cycles);

  // BAT-VOLTAGE
  ADC_setSocChanNumber(obj->adcHandle,ADC_SocNumber_8,ADC_SocChanNumber_A7);
  ADC_setSocTrigSrc(obj->adcHandle,ADC_SocNumber_8,ADC_SocTrigSrc_EPWM1_ADCSOCA);
  ADC_setSocSampleDelay(obj->adcHandle,ADC_SocNumber_8,ADC_SocSampleDelay_9_cycles);

  // INV-TEMP
  ADC_setSocChanNumber(obj->adcHandle,ADC_SocNumber_9,ADC_SocChanNumber_B0);
  ADC_setSocTrigSrc(obj->adcHandle,ADC_SocNumber_9,ADC_SocTrigSrc_EPWM1_ADCSOCA);
  ADC_setSocSampleDelay(obj->adcHandle,ADC_SocNumber_9,ADC_SocSampleDelay_9_cycles);

  // MOTOR-TEMP
  ADC_setSocChanNumber(obj->adcHandle,ADC_SocNumber_10,ADC_SocChanNumber_B2);
  ADC_setSocTrigSrc(obj->adcHandle,ADC_SocNumber_10,ADC_SocTrigSrc_EPWM1_ADCSOCA);
  ADC_setSocSampleDelay(obj->adcHandle,ADC_SocNumber_10,ADC_SocSampleDelay_9_cycles);

  // 15V
  ADC_setSocChanNumber(obj->adcHandle,ADC_SocNumber_11,ADC_SocChanNumber_B3);
  ADC_setSocTrigSrc(obj->adcHandle,ADC_SocNumber_11,ADC_SocTrigSrc_EPWM1_ADCSOCA);
  ADC_setSocSampleDelay(obj->adcHandle,ADC_SocNumber_11,ADC_SocSampleDelay_9_cycles);

  // 5V
  ADC_setSocChanNumber(obj->adcHandle,ADC_SocNumber_12,ADC_SocChanNumber_B4);
  ADC_setSocTrigSrc(obj->adcHandle,ADC_SocNumber_12,ADC_SocTrigSrc_EPWM1_ADCSOCA);
  ADC_setSocSampleDelay(obj->adcHandle,ADC_SocNumber_12,ADC_SocSampleDelay_9_cycles);

  // ANALOG1
  ADC_setSocChanNumber(obj->adcHandle,ADC_SocNumber_13,ADC_SocChanNumber_B5);
  ADC_setSocTrigSrc(obj->adcHandle,ADC_SocNumber_13,ADC_SocTrigSrc_EPWM1_ADCSOCA);
  ADC_setSocSampleDelay(obj->adcHandle,ADC_SocNumber_13,ADC_SocSampleDelay_9_cycles);

  // 12V
  ADC_setSocChanNumber(obj->adcHandle,ADC_SocNumber_14,ADC_SocChanNumber_B6);
  ADC_setSocTrigSrc(obj->adcHandle,ADC_SocNumber_14,ADC_SocTrigSrc_EPWM1_ADCSOCA);
  ADC_setSocSampleDelay(obj->adcHandle,ADC_SocNumber_14,ADC_SocSampleDelay_9_cycles);

  // I_Bat
  ADC_setSocChanNumber(obj->adcHandle,ADC_SocNumber_15,ADC_SocChanNumber_B7);
  ADC_setSocTrigSrc(obj->adcHandle,ADC_SocNumber_15,ADC_SocTrigSrc_EPWM1_ADCSOCA);
  ADC_setSocSampleDelay(obj->adcHandle,ADC_SocNumber_15,ADC_SocSampleDelay_9_cycles);

  return;
} // end of HAL_setupAdcs() function
#elif ((EVCBD_ID == 0x02) || (EVCBD_ID == 0x03) || (EVCBD_ID == 0x04) || (EVCBD_ID == 0x05) || (EVCBD_ID == 0x06))
void HAL_setupAdcs(HAL_Handle handle)
{
  HAL_Obj *obj = (HAL_Obj *)handle;


  // disable the ADCs
  ADC_disable(obj->adcHandle);

  // power up the bandgap circuit
  ADC_enableBandGap(obj->adcHandle);

  // set the ADC voltage reference source to internal
  ADC_setVoltRefSrc(obj->adcHandle,ADC_VoltageRefSrc_Int);

  // enable the ADC reference buffers
  ADC_enableRefBuffers(obj->adcHandle);

  // Set main clock scaling factor (max45MHz clock for the ADC module)
  ADC_setDivideSelect(obj->adcHandle,ADC_DivideSelect_ClkIn_by_2);

  // power up the ADCs
  ADC_powerUp(obj->adcHandle);

  // enable the ADCs
  ADC_enable(obj->adcHandle);

  // set the ADC interrupt pulse generation to prior
  ADC_setIntPulseGenMode(obj->adcHandle,ADC_IntPulseGenMode_Prior);

  // set the temperature sensor source to external
  ADC_setTempSensorSrc(obj->adcHandle,ADC_TempSensorSrc_Ext);

  // configure the interrupt sources
  ADC_disableInt(obj->adcHandle,ADC_IntNumber_1);
  ADC_setIntMode(obj->adcHandle,ADC_IntNumber_1,ADC_IntMode_ClearFlag);
  ADC_setIntSrc(obj->adcHandle,ADC_IntNumber_1,ADC_IntSrc_EOC2);

  //configure the SOCs
  // IU
  ADC_setSocChanNumber(obj->adcHandle,ADC_SocNumber_0,ADC_SocChanNumber_A0);
  ADC_setSocTrigSrc(obj->adcHandle,ADC_SocNumber_0,ADC_SocTrigSrc_EPWM1_ADCSOCA);
  ADC_setSocSampleDelay(obj->adcHandle,ADC_SocNumber_0,ADC_SocSampleDelay_9_cycles);

  // Duplicate conversion due to ADC Initial Conversion bug (SPRZ342)
  // IU
  ADC_setSocChanNumber(obj->adcHandle,ADC_SocNumber_1,ADC_SocChanNumber_A0);
  ADC_setSocTrigSrc(obj->adcHandle,ADC_SocNumber_1,ADC_SocTrigSrc_EPWM1_ADCSOCA);
  ADC_setSocSampleDelay(obj->adcHandle,ADC_SocNumber_1,ADC_SocSampleDelay_9_cycles);

  // IV
  ADC_setSocChanNumber(obj->adcHandle,ADC_SocNumber_2,ADC_SocChanNumber_B0);
  ADC_setSocTrigSrc(obj->adcHandle,ADC_SocNumber_2,ADC_SocTrigSrc_EPWM1_ADCSOCA);
  ADC_setSocSampleDelay(obj->adcHandle,ADC_SocNumber_2,ADC_SocSampleDelay_9_cycles);

  // H-VOLTAGE
  ADC_setSocChanNumber(obj->adcHandle,ADC_SocNumber_3,ADC_SocChanNumber_A1);
  ADC_setSocTrigSrc(obj->adcHandle,ADC_SocNumber_3,ADC_SocTrigSrc_EPWM1_ADCSOCA);
  ADC_setSocSampleDelay(obj->adcHandle,ADC_SocNumber_3,ADC_SocSampleDelay_9_cycles);

  // POWER-24V
  ADC_setSocChanNumber(obj->adcHandle,ADC_SocNumber_4,ADC_SocChanNumber_A2);
  ADC_setSocTrigSrc(obj->adcHandle,ADC_SocNumber_4,ADC_SocTrigSrc_EPWM1_ADCSOCA);
  ADC_setSocSampleDelay(obj->adcHandle,ADC_SocNumber_4,ADC_SocSampleDelay_9_cycles);

  // 12V
  ADC_setSocChanNumber(obj->adcHandle,ADC_SocNumber_5,ADC_SocChanNumber_A3);
  ADC_setSocTrigSrc(obj->adcHandle,ADC_SocNumber_5,ADC_SocTrigSrc_EPWM1_ADCSOCA);
  ADC_setSocSampleDelay(obj->adcHandle,ADC_SocNumber_5,ADC_SocSampleDelay_9_cycles);

  // ANALOG3
  ADC_setSocChanNumber(obj->adcHandle,ADC_SocNumber_6,ADC_SocChanNumber_A5);
  ADC_setSocTrigSrc(obj->adcHandle,ADC_SocNumber_6,ADC_SocTrigSrc_EPWM1_ADCSOCA);
  ADC_setSocSampleDelay(obj->adcHandle,ADC_SocNumber_6,ADC_SocSampleDelay_9_cycles);

  // ANALOG2
  ADC_setSocChanNumber(obj->adcHandle,ADC_SocNumber_7,ADC_SocChanNumber_A6);
  ADC_setSocTrigSrc(obj->adcHandle,ADC_SocNumber_7,ADC_SocTrigSrc_EPWM1_ADCSOCA);
  ADC_setSocSampleDelay(obj->adcHandle,ADC_SocNumber_7,ADC_SocSampleDelay_9_cycles);

  // ANALOG1
  ADC_setSocChanNumber(obj->adcHandle,ADC_SocNumber_8,ADC_SocChanNumber_A7);
  ADC_setSocTrigSrc(obj->adcHandle,ADC_SocNumber_8,ADC_SocTrigSrc_EPWM1_ADCSOCA);
  ADC_setSocSampleDelay(obj->adcHandle,ADC_SocNumber_8,ADC_SocSampleDelay_9_cycles);

  // INV-TEMP1
  ADC_setSocChanNumber(obj->adcHandle,ADC_SocNumber_9,ADC_SocChanNumber_B5);
  ADC_setSocTrigSrc(obj->adcHandle,ADC_SocNumber_9,ADC_SocTrigSrc_EPWM1_ADCSOCA);
  ADC_setSocSampleDelay(obj->adcHandle,ADC_SocNumber_9,ADC_SocSampleDelay_9_cycles);

  // INV-TEMP2
  ADC_setSocChanNumber(obj->adcHandle,ADC_SocNumber_10,ADC_SocChanNumber_B4);
  ADC_setSocTrigSrc(obj->adcHandle,ADC_SocNumber_10,ADC_SocTrigSrc_EPWM1_ADCSOCA);
  ADC_setSocSampleDelay(obj->adcHandle,ADC_SocNumber_10,ADC_SocSampleDelay_9_cycles);

  // INV-TEMP3
  ADC_setSocChanNumber(obj->adcHandle,ADC_SocNumber_11,ADC_SocChanNumber_B3);
  ADC_setSocTrigSrc(obj->adcHandle,ADC_SocNumber_11,ADC_SocTrigSrc_EPWM1_ADCSOCA);
  ADC_setSocSampleDelay(obj->adcHandle,ADC_SocNumber_11,ADC_SocSampleDelay_9_cycles);

  // M1-TEMP
  ADC_setSocChanNumber(obj->adcHandle,ADC_SocNumber_12,ADC_SocChanNumber_B6);
  ADC_setSocTrigSrc(obj->adcHandle,ADC_SocNumber_12,ADC_SocTrigSrc_EPWM1_ADCSOCA);
  ADC_setSocSampleDelay(obj->adcHandle,ADC_SocNumber_12,ADC_SocSampleDelay_9_cycles);

  // M2-TEMP
  ADC_setSocChanNumber(obj->adcHandle,ADC_SocNumber_13,ADC_SocChanNumber_B7);
  ADC_setSocTrigSrc(obj->adcHandle,ADC_SocNumber_13,ADC_SocTrigSrc_EPWM1_ADCSOCA);
  ADC_setSocSampleDelay(obj->adcHandle,ADC_SocNumber_13,ADC_SocSampleDelay_9_cycles);



  return;
} // end of HAL_setupAdcs() function

#elif  EVCBD_ID == 0x07
void HAL_setupAdcs(HAL_Handle handle)
{
  HAL_Obj *obj = (HAL_Obj *)handle;


  // disable the ADCs
  ADC_disable(obj->adcHandle);

  // power up the bandgap circuit
  ADC_enableBandGap(obj->adcHandle);

  // set the ADC voltage reference source to internal
  ADC_setVoltRefSrc(obj->adcHandle,ADC_VoltageRefSrc_Int);

  // enable the ADC reference buffers
  ADC_enableRefBuffers(obj->adcHandle);

  // Set main clock scaling factor (max45MHz clock for the ADC module)
  ADC_setDivideSelect(obj->adcHandle,ADC_DivideSelect_ClkIn_by_2);

  // power up the ADCs
  ADC_powerUp(obj->adcHandle);

  // enable the ADCs
  ADC_enable(obj->adcHandle);

  // set the ADC interrupt pulse generation to prior
  ADC_setIntPulseGenMode(obj->adcHandle,ADC_IntPulseGenMode_Prior);

  // set the temperature sensor source to external
  ADC_setTempSensorSrc(obj->adcHandle,ADC_TempSensorSrc_Ext);

  // configure the interrupt sources
  ADC_disableInt(obj->adcHandle,ADC_IntNumber_1);
  ADC_setIntMode(obj->adcHandle,ADC_IntNumber_1,ADC_IntMode_ClearFlag);
  ADC_setIntSrc(obj->adcHandle,ADC_IntNumber_1,ADC_IntSrc_EOC2);

  //configure the SOCs
  // IU
  ADC_setSocChanNumber(obj->adcHandle,ADC_SocNumber_0,ADC_SocChanNumber_A0);
  ADC_setSocTrigSrc(obj->adcHandle,ADC_SocNumber_0,ADC_SocTrigSrc_EPWM1_ADCSOCA);
  ADC_setSocSampleDelay(obj->adcHandle,ADC_SocNumber_0,ADC_SocSampleDelay_9_cycles);

  // Duplicate conversion due to ADC Initial Conversion bug (SPRZ342)
  // IU
  ADC_setSocChanNumber(obj->adcHandle,ADC_SocNumber_1,ADC_SocChanNumber_A0);
  ADC_setSocTrigSrc(obj->adcHandle,ADC_SocNumber_1,ADC_SocTrigSrc_EPWM1_ADCSOCA);
  ADC_setSocSampleDelay(obj->adcHandle,ADC_SocNumber_1,ADC_SocSampleDelay_9_cycles);

  // IW
  ADC_setSocChanNumber(obj->adcHandle,ADC_SocNumber_2,ADC_SocChanNumber_B0);
  ADC_setSocTrigSrc(obj->adcHandle,ADC_SocNumber_2,ADC_SocTrigSrc_EPWM1_ADCSOCA);
  ADC_setSocSampleDelay(obj->adcHandle,ADC_SocNumber_2,ADC_SocSampleDelay_9_cycles);

  // H-VOLTAGE
  ADC_setSocChanNumber(obj->adcHandle,ADC_SocNumber_3,ADC_SocChanNumber_B7);
  ADC_setSocTrigSrc(obj->adcHandle,ADC_SocNumber_3,ADC_SocTrigSrc_EPWM1_ADCSOCA);
  ADC_setSocSampleDelay(obj->adcHandle,ADC_SocNumber_3,ADC_SocSampleDelay_9_cycles);

  // POWER-24V
  ADC_setSocChanNumber(obj->adcHandle,ADC_SocNumber_4,ADC_SocChanNumber_A7);
  ADC_setSocTrigSrc(obj->adcHandle,ADC_SocNumber_4,ADC_SocTrigSrc_EPWM1_ADCSOCA);
  ADC_setSocSampleDelay(obj->adcHandle,ADC_SocNumber_4,ADC_SocSampleDelay_9_cycles);

  // 12V
  ADC_setSocChanNumber(obj->adcHandle,ADC_SocNumber_5,ADC_SocChanNumber_A6);
  ADC_setSocTrigSrc(obj->adcHandle,ADC_SocNumber_5,ADC_SocTrigSrc_EPWM1_ADCSOCA);
  ADC_setSocSampleDelay(obj->adcHandle,ADC_SocNumber_5,ADC_SocSampleDelay_9_cycles);

  // ANALOG2
  ADC_setSocChanNumber(obj->adcHandle,ADC_SocNumber_7,ADC_SocChanNumber_A4);
  ADC_setSocTrigSrc(obj->adcHandle,ADC_SocNumber_7,ADC_SocTrigSrc_EPWM1_ADCSOCA);
  ADC_setSocSampleDelay(obj->adcHandle,ADC_SocNumber_7,ADC_SocSampleDelay_9_cycles);

  // ANALOG1
  ADC_setSocChanNumber(obj->adcHandle,ADC_SocNumber_8,ADC_SocChanNumber_A5);
  ADC_setSocTrigSrc(obj->adcHandle,ADC_SocNumber_8,ADC_SocTrigSrc_EPWM1_ADCSOCA);
  ADC_setSocSampleDelay(obj->adcHandle,ADC_SocNumber_8,ADC_SocSampleDelay_9_cycles);

  // INV-TEMP1
  ADC_setSocChanNumber(obj->adcHandle,ADC_SocNumber_9,ADC_SocChanNumber_B6);
  ADC_setSocTrigSrc(obj->adcHandle,ADC_SocNumber_9,ADC_SocTrigSrc_EPWM1_ADCSOCA);
  ADC_setSocSampleDelay(obj->adcHandle,ADC_SocNumber_9,ADC_SocSampleDelay_9_cycles);

  // INV-TEMP2
  ADC_setSocChanNumber(obj->adcHandle,ADC_SocNumber_10,ADC_SocChanNumber_B5);
  ADC_setSocTrigSrc(obj->adcHandle,ADC_SocNumber_10,ADC_SocTrigSrc_EPWM1_ADCSOCA);
  ADC_setSocSampleDelay(obj->adcHandle,ADC_SocNumber_10,ADC_SocSampleDelay_9_cycles);

  // INV-TEMP3
  ADC_setSocChanNumber(obj->adcHandle,ADC_SocNumber_11,ADC_SocChanNumber_B4);
  ADC_setSocTrigSrc(obj->adcHandle,ADC_SocNumber_11,ADC_SocTrigSrc_EPWM1_ADCSOCA);
  ADC_setSocSampleDelay(obj->adcHandle,ADC_SocNumber_11,ADC_SocSampleDelay_9_cycles);

  // M1-TEMP
  ADC_setSocChanNumber(obj->adcHandle,ADC_SocNumber_12,ADC_SocChanNumber_B2);
  ADC_setSocTrigSrc(obj->adcHandle,ADC_SocNumber_12,ADC_SocTrigSrc_EPWM1_ADCSOCA);
  ADC_setSocSampleDelay(obj->adcHandle,ADC_SocNumber_12,ADC_SocSampleDelay_9_cycles);

  // M2-TEMP
  ADC_setSocChanNumber(obj->adcHandle,ADC_SocNumber_13,ADC_SocChanNumber_B1);
  ADC_setSocTrigSrc(obj->adcHandle,ADC_SocNumber_13,ADC_SocTrigSrc_EPWM1_ADCSOCA);
  ADC_setSocSampleDelay(obj->adcHandle,ADC_SocNumber_13,ADC_SocSampleDelay_9_cycles);

  return;
} // end of HAL_setupAdcs() function
#elif  EVCBD_ID == 0x08
void HAL_setupAdcs(HAL_Handle handle)
{
    HAL_Obj *obj = (HAL_Obj *)handle;

    // disable the ADCs
    ADC_disable(obj->adcHandle);

    // power up the bandgap circuit
    ADC_enableBandGap(obj->adcHandle);

    // set the ADC voltage reference source to internal
    ADC_setVoltRefSrc(obj->adcHandle,ADC_VoltageRefSrc_Int);

    // enable the ADC reference buffers
    ADC_enableRefBuffers(obj->adcHandle);

    // Set main clock scaling factor (max45MHz clock for the ADC module)
    ADC_setDivideSelect(obj->adcHandle,ADC_DivideSelect_ClkIn_by_2);

    // power up the ADCs
    ADC_powerUp(obj->adcHandle);

    // enable the ADCs
    ADC_enable(obj->adcHandle);

    // set the ADC interrupt pulse generation to prior
    ADC_setIntPulseGenMode(obj->adcHandle,ADC_IntPulseGenMode_Prior);

    // set the temperature sensor source to external
    ADC_setTempSensorSrc(obj->adcHandle,ADC_TempSensorSrc_Ext);

    //ADC_setVoltRefSrc    20200609 jk升级外部选择外部基准源
    ADC_setVoltRefSrc(obj->adcHandle,ADC_VoltageRefSrc_Ext);

    // configure the interrupt sources
    ADC_disableInt(obj->adcHandle,ADC_IntNumber_1);
    ADC_setIntMode(obj->adcHandle,ADC_IntNumber_1,ADC_IntMode_ClearFlag);
    ADC_setIntSrc(obj->adcHandle,ADC_IntNumber_1,ADC_IntSrc_EOC2);
    //configure the SOCs
    // IU
    ADC_setSocChanNumber(obj->adcHandle,ADC_SocNumber_0,ADC_SocChanNumber_A0);
    ADC_setSocTrigSrc(obj->adcHandle,ADC_SocNumber_0,ADC_SocTrigSrc_EPWM1_ADCSOCA);
    ADC_setSocSampleDelay(obj->adcHandle,ADC_SocNumber_0,ADC_SocSampleDelay_9_cycles);

    // Duplicate conversion due to ADC Initial Conversion bug (SPRZ342)
    // IU
    ADC_setSocChanNumber(obj->adcHandle,ADC_SocNumber_1,ADC_SocChanNumber_A0);
    ADC_setSocTrigSrc(obj->adcHandle,ADC_SocNumber_1,ADC_SocTrigSrc_EPWM1_ADCSOCA);
    ADC_setSocSampleDelay(obj->adcHandle,ADC_SocNumber_1,ADC_SocSampleDelay_9_cycles);

    // IW
    ADC_setSocChanNumber(obj->adcHandle,ADC_SocNumber_2,ADC_SocChanNumber_B0);
    ADC_setSocTrigSrc(obj->adcHandle,ADC_SocNumber_2,ADC_SocTrigSrc_EPWM1_ADCSOCA);
    ADC_setSocSampleDelay(obj->adcHandle,ADC_SocNumber_2,ADC_SocSampleDelay_9_cycles);

    // H-VOLTAGE
    ADC_setSocChanNumber(obj->adcHandle,ADC_SocNumber_3,ADC_SocChanNumber_A7);
    ADC_setSocTrigSrc(obj->adcHandle,ADC_SocNumber_3,ADC_SocTrigSrc_EPWM1_ADCSOCA);
    ADC_setSocSampleDelay(obj->adcHandle,ADC_SocNumber_3,ADC_SocSampleDelay_9_cycles);

  // 5V
    ADC_setSocChanNumber(obj->adcHandle,ADC_SocNumber_4,ADC_SocChanNumber_A4);
    ADC_setSocTrigSrc(obj->adcHandle,ADC_SocNumber_4,ADC_SocTrigSrc_EPWM1_ADCSOCA);
    ADC_setSocSampleDelay(obj->adcHandle,ADC_SocNumber_4,ADC_SocSampleDelay_9_cycles);

    // 12V
    ADC_setSocChanNumber(obj->adcHandle,ADC_SocNumber_5,ADC_SocChanNumber_A5);
    ADC_setSocTrigSrc(obj->adcHandle,ADC_SocNumber_5,ADC_SocTrigSrc_EPWM1_ADCSOCA);
    ADC_setSocSampleDelay(obj->adcHandle,ADC_SocNumber_5,ADC_SocSampleDelay_9_cycles);

    // POWER-24V
    ADC_setSocChanNumber(obj->adcHandle,ADC_SocNumber_6,ADC_SocChanNumber_A6);
    ADC_setSocTrigSrc(obj->adcHandle,ADC_SocNumber_6,ADC_SocTrigSrc_EPWM1_ADCSOCA);
    ADC_setSocSampleDelay(obj->adcHandle,ADC_SocNumber_6,ADC_SocSampleDelay_9_cycles);

    // INV-TEMP1
    ADC_setSocChanNumber(obj->adcHandle,ADC_SocNumber_7,ADC_SocChanNumber_B1);
    ADC_setSocTrigSrc(obj->adcHandle,ADC_SocNumber_7,ADC_SocTrigSrc_EPWM1_ADCSOCA);
    ADC_setSocSampleDelay(obj->adcHandle,ADC_SocNumber_7,ADC_SocSampleDelay_9_cycles);

    // INV-TEMP2
    ADC_setSocChanNumber(obj->adcHandle,ADC_SocNumber_8,ADC_SocChanNumber_B2);
    ADC_setSocTrigSrc(obj->adcHandle,ADC_SocNumber_8,ADC_SocTrigSrc_EPWM1_ADCSOCA);
    ADC_setSocSampleDelay(obj->adcHandle,ADC_SocNumber_8,ADC_SocSampleDelay_9_cycles);

    // INV-TEMP3
    ADC_setSocChanNumber(obj->adcHandle,ADC_SocNumber_9,ADC_SocChanNumber_B3);
    ADC_setSocTrigSrc(obj->adcHandle,ADC_SocNumber_9,ADC_SocTrigSrc_EPWM1_ADCSOCA);
    ADC_setSocSampleDelay(obj->adcHandle,ADC_SocNumber_9,ADC_SocSampleDelay_9_cycles);

    // M1-TEMP
    ADC_setSocChanNumber(obj->adcHandle,ADC_SocNumber_10,ADC_SocChanNumber_B4);
    ADC_setSocTrigSrc(obj->adcHandle,ADC_SocNumber_10,ADC_SocTrigSrc_EPWM1_ADCSOCA);
    ADC_setSocSampleDelay(obj->adcHandle,ADC_SocNumber_10,ADC_SocSampleDelay_9_cycles);

    // M2-TEMP
    ADC_setSocChanNumber(obj->adcHandle,ADC_SocNumber_11,ADC_SocChanNumber_B5);
    ADC_setSocTrigSrc(obj->adcHandle,ADC_SocNumber_11,ADC_SocTrigSrc_EPWM1_ADCSOCA);
    ADC_setSocSampleDelay(obj->adcHandle,ADC_SocNumber_11,ADC_SocSampleDelay_9_cycles);

    // ANALOG1
    ADC_setSocChanNumber(obj->adcHandle,ADC_SocNumber_12,ADC_SocChanNumber_A1);
    ADC_setSocTrigSrc(obj->adcHandle,ADC_SocNumber_12,ADC_SocTrigSrc_EPWM1_ADCSOCA);
    ADC_setSocSampleDelay(obj->adcHandle,ADC_SocNumber_12,ADC_SocSampleDelay_9_cycles);

    // ANALOG2
    ADC_setSocChanNumber(obj->adcHandle,ADC_SocNumber_13,ADC_SocChanNumber_A2);
    ADC_setSocTrigSrc(obj->adcHandle,ADC_SocNumber_13,ADC_SocTrigSrc_EPWM1_ADCSOCA);
    ADC_setSocSampleDelay(obj->adcHandle,ADC_SocNumber_13,ADC_SocSampleDelay_9_cycles);

    // ANALOG3
    ADC_setSocChanNumber(obj->adcHandle,ADC_SocNumber_14,ADC_SocChanNumber_A3);
    ADC_setSocTrigSrc(obj->adcHandle,ADC_SocNumber_14,ADC_SocTrigSrc_EPWM1_ADCSOCA);
    ADC_setSocSampleDelay(obj->adcHandle,ADC_SocNumber_14,ADC_SocSampleDelay_9_cycles);

    // ANALOG4
    ADC_setSocChanNumber(obj->adcHandle,ADC_SocNumber_15,ADC_SocChanNumber_B6);
    ADC_setSocTrigSrc(obj->adcHandle,ADC_SocNumber_15,ADC_SocTrigSrc_EPWM1_ADCSOCA);
    ADC_setSocSampleDelay(obj->adcHandle,ADC_SocNumber_15,ADC_SocSampleDelay_9_cycles);

//    // ANALOG5
//    ADC_setSocChanNumber(obj->adcHandle,ADC_SocNumber_15,ADC_SocChanNumber_B7);
//    ADC_setSocTrigSrc(obj->adcHandle,ADC_SocNumber_15,ADC_SocTrigSrc_EPWM1_ADCSOCA);
//    ADC_setSocSampleDelay(obj->adcHandle,ADC_SocNumber_15,ADC_SocSampleDelay_9_cycles);

    return;
} // end of HAL_setupAdcs() function
#elif  EVCBD_ID == 0x09  //S控制板05XB
void HAL_setupAdcs(HAL_Handle handle)
{
  HAL_Obj *obj = (HAL_Obj *)handle;


  // disable the ADCs
  ADC_disable(obj->adcHandle);

  // power up the bandgap circuit
  ADC_enableBandGap(obj->adcHandle);

  // set the ADC voltage reference source to internal
  ADC_setVoltRefSrc(obj->adcHandle,ADC_VoltageRefSrc_Int);

  // enable the ADC reference buffers
  ADC_enableRefBuffers(obj->adcHandle);

  // Set main clock scaling factor (max45MHz clock for the ADC module)
  ADC_setDivideSelect(obj->adcHandle,ADC_DivideSelect_ClkIn_by_2);

  // power up the ADCs
  ADC_powerUp(obj->adcHandle);

  // enable the ADCs
  ADC_enable(obj->adcHandle);

  // set the ADC interrupt pulse generation to prior
  ADC_setIntPulseGenMode(obj->adcHandle,ADC_IntPulseGenMode_Prior);

  // set the temperature sensor source to external
  ADC_setTempSensorSrc(obj->adcHandle,ADC_TempSensorSrc_Ext);

  // configure the interrupt sources
  ADC_disableInt(obj->adcHandle,ADC_IntNumber_1);
  ADC_setIntMode(obj->adcHandle,ADC_IntNumber_1,ADC_IntMode_ClearFlag);
  ADC_setIntSrc(obj->adcHandle,ADC_IntNumber_1,ADC_IntSrc_EOC2);

  //configure the SOCs
  // IU
  ADC_setSocChanNumber(obj->adcHandle,ADC_SocNumber_0,ADC_SocChanNumber_A0);
  ADC_setSocTrigSrc(obj->adcHandle,ADC_SocNumber_0,ADC_SocTrigSrc_EPWM1_ADCSOCA);
  ADC_setSocSampleDelay(obj->adcHandle,ADC_SocNumber_0,ADC_SocSampleDelay_9_cycles);

  // Duplicate conversion due to ADC Initial Conversion bug (SPRZ342)
  // IU
  ADC_setSocChanNumber(obj->adcHandle,ADC_SocNumber_1,ADC_SocChanNumber_A0);
  ADC_setSocTrigSrc(obj->adcHandle,ADC_SocNumber_1,ADC_SocTrigSrc_EPWM1_ADCSOCA);
  ADC_setSocSampleDelay(obj->adcHandle,ADC_SocNumber_1,ADC_SocSampleDelay_9_cycles);

  // IV
  ADC_setSocChanNumber(obj->adcHandle,ADC_SocNumber_2,ADC_SocChanNumber_B0);
  ADC_setSocTrigSrc(obj->adcHandle,ADC_SocNumber_2,ADC_SocTrigSrc_EPWM1_ADCSOCA);
  ADC_setSocSampleDelay(obj->adcHandle,ADC_SocNumber_2,ADC_SocSampleDelay_9_cycles);

  // US
  ADC_setSocChanNumber(obj->adcHandle,ADC_SocNumber_3,ADC_SocChanNumber_A1);
  ADC_setSocTrigSrc(obj->adcHandle,ADC_SocNumber_3,ADC_SocTrigSrc_EPWM1_ADCSOCA);
  ADC_setSocSampleDelay(obj->adcHandle,ADC_SocNumber_3,ADC_SocSampleDelay_9_cycles);

  // VS
  ADC_setSocChanNumber(obj->adcHandle,ADC_SocNumber_4,ADC_SocChanNumber_A2);
  ADC_setSocTrigSrc(obj->adcHandle,ADC_SocNumber_4,ADC_SocTrigSrc_EPWM1_ADCSOCA);
  ADC_setSocSampleDelay(obj->adcHandle,ADC_SocNumber_4,ADC_SocSampleDelay_9_cycles);

  // WS
  ADC_setSocChanNumber(obj->adcHandle,ADC_SocNumber_5,ADC_SocChanNumber_A3);
  ADC_setSocTrigSrc(obj->adcHandle,ADC_SocNumber_5,ADC_SocTrigSrc_EPWM1_ADCSOCA);
  ADC_setSocSampleDelay(obj->adcHandle,ADC_SocNumber_5,ADC_SocSampleDelay_9_cycles);

  // 电源电压
  ADC_setSocChanNumber(obj->adcHandle,ADC_SocNumber_6,ADC_SocChanNumber_B2);
  ADC_setSocTrigSrc(obj->adcHandle,ADC_SocNumber_6,ADC_SocTrigSrc_EPWM1_ADCSOCA);
  ADC_setSocSampleDelay(obj->adcHandle,ADC_SocNumber_6,ADC_SocSampleDelay_9_cycles);

  // 电容电压
  ADC_setSocChanNumber(obj->adcHandle,ADC_SocNumber_7,ADC_SocChanNumber_B3);
  ADC_setSocTrigSrc(obj->adcHandle,ADC_SocNumber_7,ADC_SocTrigSrc_EPWM1_ADCSOCA);
  ADC_setSocSampleDelay(obj->adcHandle,ADC_SocNumber_7,ADC_SocSampleDelay_9_cycles);

  // BRA_POT(刹车电压)
  ADC_setSocChanNumber(obj->adcHandle,ADC_SocNumber_8,ADC_SocChanNumber_A4);
  ADC_setSocTrigSrc(obj->adcHandle,ADC_SocNumber_8,ADC_SocTrigSrc_EPWM1_ADCSOCA);
  ADC_setSocSampleDelay(obj->adcHandle,ADC_SocNumber_8,ADC_SocSampleDelay_9_cycles);

  // THRO_POT(油门电压)
  ADC_setSocChanNumber(obj->adcHandle,ADC_SocNumber_9,ADC_SocChanNumber_B7);
  ADC_setSocTrigSrc(obj->adcHandle,ADC_SocNumber_9,ADC_SocTrigSrc_EPWM1_ADCSOCA);
  ADC_setSocSampleDelay(obj->adcHandle,ADC_SocNumber_9,ADC_SocSampleDelay_9_cycles);

  // 内部15V电压采集
  ADC_setSocChanNumber(obj->adcHandle,ADC_SocNumber_10,ADC_SocChanNumber_A5);
  ADC_setSocTrigSrc(obj->adcHandle,ADC_SocNumber_10,ADC_SocTrigSrc_EPWM1_ADCSOCA);
  ADC_setSocSampleDelay(obj->adcHandle,ADC_SocNumber_10,ADC_SocSampleDelay_9_cycles);

  // INV-TEMP(只有一路温度采集)
  ADC_setSocChanNumber(obj->adcHandle,ADC_SocNumber_11,ADC_SocChanNumber_B1);
  ADC_setSocTrigSrc(obj->adcHandle,ADC_SocNumber_11,ADC_SocTrigSrc_EPWM1_ADCSOCA);
  ADC_setSocSampleDelay(obj->adcHandle,ADC_SocNumber_11,ADC_SocSampleDelay_9_cycles);

  // M1-TEMP
  ADC_setSocChanNumber(obj->adcHandle,ADC_SocNumber_12,ADC_SocChanNumber_A6);
  ADC_setSocTrigSrc(obj->adcHandle,ADC_SocNumber_12,ADC_SocTrigSrc_EPWM1_ADCSOCA);
  ADC_setSocSampleDelay(obj->adcHandle,ADC_SocNumber_12,ADC_SocSampleDelay_9_cycles);

  // M2-TEMP
  ADC_setSocChanNumber(obj->adcHandle,ADC_SocNumber_13,ADC_SocChanNumber_A7);
  ADC_setSocTrigSrc(obj->adcHandle,ADC_SocNumber_13,ADC_SocTrigSrc_EPWM1_ADCSOCA);
  ADC_setSocSampleDelay(obj->adcHandle,ADC_SocNumber_13,ADC_SocSampleDelay_9_cycles);

  // 外部5V电压检测
  ADC_setSocChanNumber(obj->adcHandle,ADC_SocNumber_14,ADC_SocChanNumber_B6);
  ADC_setSocTrigSrc(obj->adcHandle,ADC_SocNumber_14,ADC_SocTrigSrc_EPWM1_ADCSOCA);
  ADC_setSocSampleDelay(obj->adcHandle,ADC_SocNumber_14,ADC_SocSampleDelay_9_cycles);

  // 外部12V电压检测
  ADC_setSocChanNumber(obj->adcHandle,ADC_SocNumber_15,ADC_SocChanNumber_B5);
  ADC_setSocTrigSrc(obj->adcHandle,ADC_SocNumber_15,ADC_SocTrigSrc_EPWM1_ADCSOCA);
  ADC_setSocSampleDelay(obj->adcHandle,ADC_SocNumber_15,ADC_SocSampleDelay_9_cycles);

  return;
} // end of HAL_setupAdcs() function
#elif EVCBD_ID == 0x0A
void HAL_setupAdcs(HAL_Handle handle)
{
  HAL_Obj *obj = (HAL_Obj *)handle;


  // disable the ADCs
  ADC_disable(obj->adcHandle);

  // power up the bandgap circuit
  ADC_enableBandGap(obj->adcHandle);

  // set the ADC voltage reference source to internal
  ADC_setVoltRefSrc(obj->adcHandle,ADC_VoltageRefSrc_Int);

  // enable the ADC reference buffers
  ADC_enableRefBuffers(obj->adcHandle);

  // Set main clock scaling factor (max45MHz clock for the ADC module)
  ADC_setDivideSelect(obj->adcHandle,ADC_DivideSelect_ClkIn_by_2);

  // power up the ADCs
  ADC_powerUp(obj->adcHandle);

  // enable the ADCs
  ADC_enable(obj->adcHandle);

  // set the ADC interrupt pulse generation to prior
  ADC_setIntPulseGenMode(obj->adcHandle,ADC_IntPulseGenMode_Prior);

  // set the temperature sensor source to external
  ADC_setTempSensorSrc(obj->adcHandle,ADC_TempSensorSrc_Ext);

  // configure the interrupt sources
  ADC_disableInt(obj->adcHandle,ADC_IntNumber_1);
  ADC_setIntMode(obj->adcHandle,ADC_IntNumber_1,ADC_IntMode_ClearFlag);
  ADC_setIntSrc(obj->adcHandle,ADC_IntNumber_1,ADC_IntSrc_EOC2);

  //configure the SOCs
  // IU
  ADC_setSocChanNumber(obj->adcHandle,ADC_SocNumber_0,ADC_SocChanNumber_A0);
  ADC_setSocTrigSrc(obj->adcHandle,ADC_SocNumber_0,ADC_SocTrigSrc_EPWM1_ADCSOCA);
  ADC_setSocSampleDelay(obj->adcHandle,ADC_SocNumber_0,ADC_SocSampleDelay_9_cycles);

  // Duplicate conversion due to ADC Initial Conversion bug (SPRZ342)
  // IU
  ADC_setSocChanNumber(obj->adcHandle,ADC_SocNumber_1,ADC_SocChanNumber_A0);
  ADC_setSocTrigSrc(obj->adcHandle,ADC_SocNumber_1,ADC_SocTrigSrc_EPWM1_ADCSOCA);
  ADC_setSocSampleDelay(obj->adcHandle,ADC_SocNumber_1,ADC_SocSampleDelay_9_cycles);

  // IV
  ADC_setSocChanNumber(obj->adcHandle,ADC_SocNumber_2,ADC_SocChanNumber_B0);
  ADC_setSocTrigSrc(obj->adcHandle,ADC_SocNumber_2,ADC_SocTrigSrc_EPWM1_ADCSOCA);
  ADC_setSocSampleDelay(obj->adcHandle,ADC_SocNumber_2,ADC_SocSampleDelay_9_cycles);

  // US
//  ADC_setSocChanNumber(obj->adcHandle,ADC_SocNumber_3,ADC_SocChanNumber_A1);
//  ADC_setSocTrigSrc(obj->adcHandle,ADC_SocNumber_3,ADC_SocTrigSrc_EPWM1_ADCSOCA);
//  ADC_setSocSampleDelay(obj->adcHandle,ADC_SocNumber_3,ADC_SocSampleDelay_9_cycles);

  // VS
//  ADC_setSocChanNumber(obj->adcHandle,ADC_SocNumber_4,ADC_SocChanNumber_A2);
//  ADC_setSocTrigSrc(obj->adcHandle,ADC_SocNumber_4,ADC_SocTrigSrc_EPWM1_ADCSOCA);
//  ADC_setSocSampleDelay(obj->adcHandle,ADC_SocNumber_4,ADC_SocSampleDelay_9_cycles);

  // WS
//  ADC_setSocChanNumber(obj->adcHandle,ADC_SocNumber_5,ADC_SocChanNumber_A3);
//  ADC_setSocTrigSrc(obj->adcHandle,ADC_SocNumber_5,ADC_SocTrigSrc_EPWM1_ADCSOCA);
//  ADC_setSocSampleDelay(obj->adcHandle,ADC_SocNumber_5,ADC_SocSampleDelay_9_cycles);

  // 电源电压
  ADC_setSocChanNumber(obj->adcHandle,ADC_SocNumber_6,ADC_SocChanNumber_A6);
  ADC_setSocTrigSrc(obj->adcHandle,ADC_SocNumber_6,ADC_SocTrigSrc_EPWM1_ADCSOCA);
  ADC_setSocSampleDelay(obj->adcHandle,ADC_SocNumber_6,ADC_SocSampleDelay_9_cycles);

  // 电容电压
  ADC_setSocChanNumber(obj->adcHandle,ADC_SocNumber_7,ADC_SocChanNumber_A7);
  ADC_setSocTrigSrc(obj->adcHandle,ADC_SocNumber_7,ADC_SocTrigSrc_EPWM1_ADCSOCA);
  ADC_setSocSampleDelay(obj->adcHandle,ADC_SocNumber_7,ADC_SocSampleDelay_9_cycles);

  // BRA_POT(刹车电压)
//  ADC_setSocChanNumber(obj->adcHandle,ADC_SocNumber_8,ADC_SocChanNumber_A4);
//  ADC_setSocTrigSrc(obj->adcHandle,ADC_SocNumber_8,ADC_SocTrigSrc_EPWM1_ADCSOCA);
//  ADC_setSocSampleDelay(obj->adcHandle,ADC_SocNumber_8,ADC_SocSampleDelay_9_cycles);

  // THRO_POT(油门电压)
  ADC_setSocChanNumber(obj->adcHandle,ADC_SocNumber_9,ADC_SocChanNumber_B3);
  ADC_setSocTrigSrc(obj->adcHandle,ADC_SocNumber_9,ADC_SocTrigSrc_EPWM1_ADCSOCA);
  ADC_setSocSampleDelay(obj->adcHandle,ADC_SocNumber_9,ADC_SocSampleDelay_9_cycles);

  // INV-TEMP(只有一路温度采集)
  ADC_setSocChanNumber(obj->adcHandle,ADC_SocNumber_11,ADC_SocChanNumber_B2);
  ADC_setSocTrigSrc(obj->adcHandle,ADC_SocNumber_11,ADC_SocTrigSrc_EPWM1_ADCSOCA);
  ADC_setSocSampleDelay(obj->adcHandle,ADC_SocNumber_11,ADC_SocSampleDelay_9_cycles);

  // M1-TEMP
  ADC_setSocChanNumber(obj->adcHandle,ADC_SocNumber_12,ADC_SocChanNumber_B1);
  ADC_setSocTrigSrc(obj->adcHandle,ADC_SocNumber_12,ADC_SocTrigSrc_EPWM1_ADCSOCA);
  ADC_setSocSampleDelay(obj->adcHandle,ADC_SocNumber_12,ADC_SocSampleDelay_9_cycles);

  // M2-TEMP
//  ADC_setSocChanNumber(obj->adcHandle,ADC_SocNumber_13,ADC_SocChanNumber_A7);
//  ADC_setSocTrigSrc(obj->adcHandle,ADC_SocNumber_13,ADC_SocTrigSrc_EPWM1_ADCSOCA);
//  ADC_setSocSampleDelay(obj->adcHandle,ADC_SocNumber_13,ADC_SocSampleDelay_9_cycles);

  // 外部5V电压检测
  ADC_setSocChanNumber(obj->adcHandle,ADC_SocNumber_14,ADC_SocChanNumber_B4);
  ADC_setSocTrigSrc(obj->adcHandle,ADC_SocNumber_14,ADC_SocTrigSrc_EPWM1_ADCSOCA);
  ADC_setSocSampleDelay(obj->adcHandle,ADC_SocNumber_14,ADC_SocSampleDelay_9_cycles);

  // 外部12V电压检测
  ADC_setSocChanNumber(obj->adcHandle,ADC_SocNumber_15,ADC_SocChanNumber_A4);
  ADC_setSocTrigSrc(obj->adcHandle,ADC_SocNumber_15,ADC_SocTrigSrc_EPWM1_ADCSOCA);
  ADC_setSocSampleDelay(obj->adcHandle,ADC_SocNumber_15,ADC_SocSampleDelay_9_cycles);

  // 内部15V电压采集
  ADC_setSocChanNumber(obj->adcHandle,ADC_SocNumber_10,ADC_SocChanNumber_A5);
  ADC_setSocTrigSrc(obj->adcHandle,ADC_SocNumber_10,ADC_SocTrigSrc_EPWM1_ADCSOCA);
  ADC_setSocSampleDelay(obj->adcHandle,ADC_SocNumber_10,ADC_SocSampleDelay_9_cycles);

  // 模拟量采集1
  ADC_setSocChanNumber(obj->adcHandle,ADC_SocNumber_3,ADC_SocChanNumber_B7);
  ADC_setSocTrigSrc(obj->adcHandle,ADC_SocNumber_3,ADC_SocTrigSrc_EPWM1_ADCSOCA);
  ADC_setSocSampleDelay(obj->adcHandle,ADC_SocNumber_3,ADC_SocSampleDelay_9_cycles);

  // 模拟量采集2
  ADC_setSocChanNumber(obj->adcHandle,ADC_SocNumber_4,ADC_SocChanNumber_B6);
  ADC_setSocTrigSrc(obj->adcHandle,ADC_SocNumber_4,ADC_SocTrigSrc_EPWM1_ADCSOCA);
  ADC_setSocSampleDelay(obj->adcHandle,ADC_SocNumber_4,ADC_SocSampleDelay_9_cycles);

  // 模拟量采集3
  ADC_setSocChanNumber(obj->adcHandle,ADC_SocNumber_5,ADC_SocChanNumber_B5);
  ADC_setSocTrigSrc(obj->adcHandle,ADC_SocNumber_5,ADC_SocTrigSrc_EPWM1_ADCSOCA);
  ADC_setSocSampleDelay(obj->adcHandle,ADC_SocNumber_5,ADC_SocSampleDelay_9_cycles);

  return;
} // end of HAL_setupAdcs() function
#elif EVCBD_ID == 0x0D
void HAL_setupAdcs(HAL_Handle handle)
{
  HAL_Obj *obj = (HAL_Obj *)handle;


  // disable the ADCs
  ADC_disable(obj->adcHandle);

  // power up the bandgap circuit
  ADC_enableBandGap(obj->adcHandle);

  // set the ADC voltage reference source to internal
  ADC_setVoltRefSrc(obj->adcHandle,ADC_VoltageRefSrc_Int);

  // enable the ADC reference buffers
  ADC_enableRefBuffers(obj->adcHandle);

  // Set main clock scaling factor (max45MHz clock for the ADC module)
  ADC_setDivideSelect(obj->adcHandle,ADC_DivideSelect_ClkIn_by_2);

  // power up the ADCs
  ADC_powerUp(obj->adcHandle);

  // enable the ADCs
  ADC_enable(obj->adcHandle);

  // set the ADC interrupt pulse generation to prior
  ADC_setIntPulseGenMode(obj->adcHandle,ADC_IntPulseGenMode_Prior);

  // set the temperature sensor source to external
  ADC_setTempSensorSrc(obj->adcHandle,ADC_TempSensorSrc_Ext);

  // configure the interrupt sources
  ADC_disableInt(obj->adcHandle,ADC_IntNumber_1);
  ADC_setIntMode(obj->adcHandle,ADC_IntNumber_1,ADC_IntMode_ClearFlag);
  ADC_setIntSrc(obj->adcHandle,ADC_IntNumber_1,ADC_IntSrc_EOC2);

  //configure the SOCs
  // IU
  ADC_setSocChanNumber(obj->adcHandle,ADC_SocNumber_0,ADC_SocChanNumber_B0);//HP1逻辑板因为电流传感器现场问题,互换UW,原理图采集的U实际上是W
  ADC_setSocTrigSrc(obj->adcHandle,ADC_SocNumber_0,ADC_SocTrigSrc_EPWM1_ADCSOCA);
  ADC_setSocSampleDelay(obj->adcHandle,ADC_SocNumber_0,ADC_SocSampleDelay_9_cycles);

  // Duplicate conversion due to ADC Initial Conversion bug (SPRZ342)
  // IW
  ADC_setSocChanNumber(obj->adcHandle,ADC_SocNumber_8,ADC_SocChanNumber_A0);
  ADC_setSocTrigSrc(obj->adcHandle,ADC_SocNumber_8,ADC_SocTrigSrc_EPWM1_ADCSOCA);
  ADC_setSocSampleDelay(obj->adcHandle,ADC_SocNumber_8,ADC_SocSampleDelay_9_cycles);

  // Vol_U
  ADC_setSocChanNumber(obj->adcHandle,ADC_SocNumber_1,ADC_SocChanNumber_A1);
  ADC_setSocTrigSrc(obj->adcHandle,ADC_SocNumber_1,ADC_SocTrigSrc_EPWM1_ADCSOCA);
  ADC_setSocSampleDelay(obj->adcHandle,ADC_SocNumber_1,ADC_SocSampleDelay_9_cycles);

  // Volt_W
  ADC_setSocChanNumber(obj->adcHandle,ADC_SocNumber_2,ADC_SocChanNumber_A2);
  ADC_setSocTrigSrc(obj->adcHandle,ADC_SocNumber_2,ADC_SocTrigSrc_EPWM1_ADCSOCA);
  ADC_setSocSampleDelay(obj->adcHandle,ADC_SocNumber_2,ADC_SocSampleDelay_9_cycles);

  // CTRL_Temp
  ADC_setSocChanNumber(obj->adcHandle,ADC_SocNumber_3,ADC_SocChanNumber_A3);
  ADC_setSocTrigSrc(obj->adcHandle,ADC_SocNumber_3,ADC_SocTrigSrc_EPWM1_ADCSOCA);
  ADC_setSocSampleDelay(obj->adcHandle,ADC_SocNumber_3,ADC_SocSampleDelay_9_cycles);

  // +15V-Test
  ADC_setSocChanNumber(obj->adcHandle,ADC_SocNumber_4,ADC_SocChanNumber_A4);
  ADC_setSocTrigSrc(obj->adcHandle,ADC_SocNumber_4,ADC_SocTrigSrc_EPWM1_ADCSOCA);
  ADC_setSocSampleDelay(obj->adcHandle,ADC_SocNumber_4,ADC_SocSampleDelay_9_cycles);

  // +12V-Test
  ADC_setSocChanNumber(obj->adcHandle,ADC_SocNumber_5,ADC_SocChanNumber_A5);
  ADC_setSocTrigSrc(obj->adcHandle,ADC_SocNumber_5,ADC_SocTrigSrc_EPWM1_ADCSOCA);
  ADC_setSocSampleDelay(obj->adcHandle,ADC_SocNumber_5,ADC_SocSampleDelay_9_cycles);

  // +5Vout-Test
  ADC_setSocChanNumber(obj->adcHandle,ADC_SocNumber_6,ADC_SocChanNumber_A6);
  ADC_setSocTrigSrc(obj->adcHandle,ADC_SocNumber_6,ADC_SocTrigSrc_EPWM1_ADCSOCA);
  ADC_setSocSampleDelay(obj->adcHandle,ADC_SocNumber_6,ADC_SocSampleDelay_9_cycles);

  // +5V-Test
  ADC_setSocChanNumber(obj->adcHandle,ADC_SocNumber_7,ADC_SocChanNumber_A7);
  ADC_setSocTrigSrc(obj->adcHandle,ADC_SocNumber_7,ADC_SocTrigSrc_EPWM1_ADCSOCA);
  ADC_setSocSampleDelay(obj->adcHandle,ADC_SocNumber_7,ADC_SocSampleDelay_9_cycles);

  // Volt_V
  ADC_setSocChanNumber(obj->adcHandle,ADC_SocNumber_9,ADC_SocChanNumber_B1);
  ADC_setSocTrigSrc(obj->adcHandle,ADC_SocNumber_9,ADC_SocTrigSrc_EPWM1_ADCSOCA);
  ADC_setSocSampleDelay(obj->adcHandle,ADC_SocNumber_9,ADC_SocSampleDelay_9_cycles);

  // 母线电压
  ADC_setSocChanNumber(obj->adcHandle,ADC_SocNumber_10,ADC_SocChanNumber_B2);
  ADC_setSocTrigSrc(obj->adcHandle,ADC_SocNumber_10,ADC_SocTrigSrc_EPWM1_ADCSOCA);
  ADC_setSocSampleDelay(obj->adcHandle,ADC_SocNumber_10,ADC_SocSampleDelay_9_cycles);

  // M1_Temp
  ADC_setSocChanNumber(obj->adcHandle,ADC_SocNumber_11,ADC_SocChanNumber_B3);
  ADC_setSocTrigSrc(obj->adcHandle,ADC_SocNumber_11,ADC_SocTrigSrc_EPWM1_ADCSOCA);
  ADC_setSocSampleDelay(obj->adcHandle,ADC_SocNumber_11,ADC_SocSampleDelay_9_cycles);

  // M2_Temp
  ADC_setSocChanNumber(obj->adcHandle,ADC_SocNumber_12,ADC_SocChanNumber_B4);
  ADC_setSocTrigSrc(obj->adcHandle,ADC_SocNumber_12,ADC_SocTrigSrc_EPWM1_ADCSOCA);
  ADC_setSocSampleDelay(obj->adcHandle,ADC_SocNumber_12,ADC_SocSampleDelay_9_cycles);

  // 油门B
  ADC_setSocChanNumber(obj->adcHandle,ADC_SocNumber_13,ADC_SocChanNumber_B5);
  ADC_setSocTrigSrc(obj->adcHandle,ADC_SocNumber_13,ADC_SocTrigSrc_EPWM1_ADCSOCA);
  ADC_setSocSampleDelay(obj->adcHandle,ADC_SocNumber_13,ADC_SocSampleDelay_9_cycles);

  // 油门A
  ADC_setSocChanNumber(obj->adcHandle,ADC_SocNumber_14,ADC_SocChanNumber_B6);
  ADC_setSocTrigSrc(obj->adcHandle,ADC_SocNumber_14,ADC_SocTrigSrc_EPWM1_ADCSOCA);
  ADC_setSocSampleDelay(obj->adcHandle,ADC_SocNumber_14,ADC_SocSampleDelay_9_cycles);

  // NTC-Temp
  ADC_setSocChanNumber(obj->adcHandle,ADC_SocNumber_15,ADC_SocChanNumber_B7);
  ADC_setSocTrigSrc(obj->adcHandle,ADC_SocNumber_15,ADC_SocTrigSrc_EPWM1_ADCSOCA);
  ADC_setSocSampleDelay(obj->adcHandle,ADC_SocNumber_15,ADC_SocSampleDelay_9_cycles);

  return;
} // end of HAL_setupAdcs() function



#endif

void HAL_enableAdcInts(HAL_Handle handle)
{
  HAL_Obj *obj = (HAL_Obj *)handle;


  // enable the PIE interrupts associated with the ADC interrupts
  PIE_enableAdcInt(obj->pieHandle,ADC_IntNumber_1);


  // enable the ADC interrupts
  ADC_enableInt(obj->adcHandle,ADC_IntNumber_1);


  // enable the cpu interrupt for ADC interrupts
  CPU_enableInt(obj->cpuHandle,CPU_IntNumber_10);

  return;
} // end of HAL_enableAdcInts() function


void HAL_AdcOffsetSelfCal(HAL_Handle handle)
{
  HAL_Obj *obj = (HAL_Obj *)handle;
  uint16_t AdcConvMean;

  // disable the ADCs
  ADC_disable(obj->adcHandle);

  // power up the bandgap circuit
  ADC_enableBandGap(obj->adcHandle);

  // set the ADC voltage reference source to internal
  ADC_setVoltRefSrc(obj->adcHandle,ADC_VoltageRefSrc_Int);

  // enable the ADC reference buffers
  ADC_enableRefBuffers(obj->adcHandle);

  // Set main clock scaling factor (max45MHz clock for the ADC module)
  ADC_setDivideSelect(obj->adcHandle,ADC_DivideSelect_ClkIn_by_2);

  // power up the ADCs
  ADC_powerUp(obj->adcHandle);

  // enable the ADCs
  ADC_enable(obj->adcHandle);

  //Select VREFLO internal connection on B5
  ADC_enableVoltRefLoConv(obj->adcHandle);

  //Select channel B5 for all SOC
  HAL_AdcCalChanSelect(handle, ADC_SocChanNumber_B5);

  //Apply artificial offset (+80) to account for a negative offset that may reside in the ADC core
  ADC_setOffTrim(obj->adcHandle, 80);

  //Capture ADC conversion on VREFLO
  AdcConvMean = HAL_AdcCalConversion(handle);

  //Set offtrim register with new value (i.e remove artical offset (+80) and create a two's compliment of the offset error)
  ADC_setOffTrim(obj->adcHandle, 80 - AdcConvMean);

  //Select external ADCIN5 input pin on B5
  ADC_disableVoltRefLoConv(obj->adcHandle);

  return;
} // end of HAL_AdcOffsetSelfCal() function


void HAL_AdcCalChanSelect(HAL_Handle handle, const ADC_SocChanNumber_e chanNumber)
{
  HAL_Obj *obj = (HAL_Obj *)handle;

  ADC_setSocChanNumber(obj->adcHandle,ADC_SocNumber_0,chanNumber);
  ADC_setSocChanNumber(obj->adcHandle,ADC_SocNumber_1,chanNumber);
  ADC_setSocChanNumber(obj->adcHandle,ADC_SocNumber_2,chanNumber);
  ADC_setSocChanNumber(obj->adcHandle,ADC_SocNumber_3,chanNumber);
  ADC_setSocChanNumber(obj->adcHandle,ADC_SocNumber_4,chanNumber);
  ADC_setSocChanNumber(obj->adcHandle,ADC_SocNumber_5,chanNumber);
  ADC_setSocChanNumber(obj->adcHandle,ADC_SocNumber_6,chanNumber);
  ADC_setSocChanNumber(obj->adcHandle,ADC_SocNumber_7,chanNumber);
  ADC_setSocChanNumber(obj->adcHandle,ADC_SocNumber_8,chanNumber);
  ADC_setSocChanNumber(obj->adcHandle,ADC_SocNumber_9,chanNumber);
  ADC_setSocChanNumber(obj->adcHandle,ADC_SocNumber_10,chanNumber);
  ADC_setSocChanNumber(obj->adcHandle,ADC_SocNumber_11,chanNumber);
  ADC_setSocChanNumber(obj->adcHandle,ADC_SocNumber_12,chanNumber);
  ADC_setSocChanNumber(obj->adcHandle,ADC_SocNumber_13,chanNumber);
  ADC_setSocChanNumber(obj->adcHandle,ADC_SocNumber_14,chanNumber);
  ADC_setSocChanNumber(obj->adcHandle,ADC_SocNumber_15,chanNumber);

  return;
} // end of HAL_AdcCalChanSelect() function


uint16_t HAL_AdcCalConversion(HAL_Handle handle)
{
  HAL_Obj *obj = (HAL_Obj *)handle;
  uint16_t index, SampleSize, Mean;
  uint32_t Sum;
  ADC_SocSampleDelay_e ACQPS_Value;

  index       = 0;     //initialize index to 0
  SampleSize  = 256;   //set sample size to 256 (**NOTE: Sample size must be multiples of 2^x where is an integer >= 4)
  Sum         = 0;     //set sum to 0
  Mean        = 999;   //initialize mean to known value

  //Set the ADC sample window to the desired value (Sample window = ACQPS + 1)
  ACQPS_Value = ADC_SocSampleDelay_7_cycles;

  ADC_setSocSampleDelay(obj->adcHandle,ADC_SocNumber_0,ACQPS_Value);
  ADC_setSocSampleDelay(obj->adcHandle,ADC_SocNumber_1,ACQPS_Value);
  ADC_setSocSampleDelay(obj->adcHandle,ADC_SocNumber_2,ACQPS_Value);
  ADC_setSocSampleDelay(obj->adcHandle,ADC_SocNumber_3,ACQPS_Value);
  ADC_setSocSampleDelay(obj->adcHandle,ADC_SocNumber_4,ACQPS_Value);
  ADC_setSocSampleDelay(obj->adcHandle,ADC_SocNumber_5,ACQPS_Value);
  ADC_setSocSampleDelay(obj->adcHandle,ADC_SocNumber_6,ACQPS_Value);
  ADC_setSocSampleDelay(obj->adcHandle,ADC_SocNumber_7,ACQPS_Value);
  ADC_setSocSampleDelay(obj->adcHandle,ADC_SocNumber_8,ACQPS_Value);
  ADC_setSocSampleDelay(obj->adcHandle,ADC_SocNumber_9,ACQPS_Value);
  ADC_setSocSampleDelay(obj->adcHandle,ADC_SocNumber_10,ACQPS_Value);
  ADC_setSocSampleDelay(obj->adcHandle,ADC_SocNumber_11,ACQPS_Value);
  ADC_setSocSampleDelay(obj->adcHandle,ADC_SocNumber_12,ACQPS_Value);
  ADC_setSocSampleDelay(obj->adcHandle,ADC_SocNumber_13,ACQPS_Value);
  ADC_setSocSampleDelay(obj->adcHandle,ADC_SocNumber_14,ACQPS_Value);
  ADC_setSocSampleDelay(obj->adcHandle,ADC_SocNumber_15,ACQPS_Value);

  // Enabled ADCINT1 and ADCINT2
  ADC_enableInt(obj->adcHandle, ADC_IntNumber_1);
  ADC_enableInt(obj->adcHandle, ADC_IntNumber_2);

  // Disable continuous sampling for ADCINT1 and ADCINT2
  ADC_setIntMode(obj->adcHandle, ADC_IntNumber_1, ADC_IntMode_EOC);
  ADC_setIntMode(obj->adcHandle, ADC_IntNumber_2, ADC_IntMode_EOC);

  //ADCINTs trigger at end of conversion
  ADC_setIntPulseGenMode(obj->adcHandle, ADC_IntPulseGenMode_Prior);

  // Setup ADCINT1 and ADCINT2 trigger source
  ADC_setIntSrc(obj->adcHandle, ADC_IntNumber_1, ADC_IntSrc_EOC6);
  ADC_setIntSrc(obj->adcHandle, ADC_IntNumber_2, ADC_IntSrc_EOC14);

  // Setup each SOC's ADCINT trigger source
  ADC_setupSocTrigSrc(obj->adcHandle, ADC_SocNumber_0, ADC_Int2TriggersSOC);
  ADC_setupSocTrigSrc(obj->adcHandle, ADC_SocNumber_1, ADC_Int2TriggersSOC);
  ADC_setupSocTrigSrc(obj->adcHandle, ADC_SocNumber_2, ADC_Int2TriggersSOC);
  ADC_setupSocTrigSrc(obj->adcHandle, ADC_SocNumber_3, ADC_Int2TriggersSOC);
  ADC_setupSocTrigSrc(obj->adcHandle, ADC_SocNumber_4, ADC_Int2TriggersSOC);
  ADC_setupSocTrigSrc(obj->adcHandle, ADC_SocNumber_5, ADC_Int2TriggersSOC);
  ADC_setupSocTrigSrc(obj->adcHandle, ADC_SocNumber_6, ADC_Int2TriggersSOC);
  ADC_setupSocTrigSrc(obj->adcHandle, ADC_SocNumber_7, ADC_Int2TriggersSOC);
  ADC_setupSocTrigSrc(obj->adcHandle, ADC_SocNumber_8, ADC_Int1TriggersSOC);
  ADC_setupSocTrigSrc(obj->adcHandle, ADC_SocNumber_9, ADC_Int1TriggersSOC);
  ADC_setupSocTrigSrc(obj->adcHandle, ADC_SocNumber_10, ADC_Int1TriggersSOC);
  ADC_setupSocTrigSrc(obj->adcHandle, ADC_SocNumber_11, ADC_Int1TriggersSOC);
  ADC_setupSocTrigSrc(obj->adcHandle, ADC_SocNumber_12, ADC_Int1TriggersSOC);
  ADC_setupSocTrigSrc(obj->adcHandle, ADC_SocNumber_13, ADC_Int1TriggersSOC);
  ADC_setupSocTrigSrc(obj->adcHandle, ADC_SocNumber_14, ADC_Int1TriggersSOC);
  ADC_setupSocTrigSrc(obj->adcHandle, ADC_SocNumber_15, ADC_Int1TriggersSOC);

  // Delay before converting ADC channels
  usDelay(ADC_DELAY_usec);

  ADC_setSocFrcWord(obj->adcHandle, 0x00FF);

  while( index < SampleSize )
    {
      //Wait for ADCINT1 to trigger, then add ADCRESULT0-7 registers to sum
      while (ADC_getIntFlag(obj->adcHandle, ADC_IntNumber_1) == 0){}

      //Must clear ADCINT1 flag since INT1CONT = 0
      ADC_clearIntFlag(obj->adcHandle, ADC_IntNumber_1);

      Sum += ADC_readResult(obj->adcHandle, ADC_ResultNumber_0);
      Sum += ADC_readResult(obj->adcHandle, ADC_ResultNumber_1);
      Sum += ADC_readResult(obj->adcHandle, ADC_ResultNumber_2);
      Sum += ADC_readResult(obj->adcHandle, ADC_ResultNumber_3);
      Sum += ADC_readResult(obj->adcHandle, ADC_ResultNumber_4);
      Sum += ADC_readResult(obj->adcHandle, ADC_ResultNumber_5);
      Sum += ADC_readResult(obj->adcHandle, ADC_ResultNumber_6);
      Sum += ADC_readResult(obj->adcHandle, ADC_ResultNumber_7);

      //Wait for ADCINT2 to trigger, then add ADCRESULT8-15 registers to sum
      while (ADC_getIntFlag(obj->adcHandle, ADC_IntNumber_2) == 0){}

      //Must clear ADCINT2 flag since INT2CONT = 0
      ADC_clearIntFlag(obj->adcHandle, ADC_IntNumber_2);

      Sum += ADC_readResult(obj->adcHandle, ADC_ResultNumber_8);
      Sum += ADC_readResult(obj->adcHandle, ADC_ResultNumber_9);
      Sum += ADC_readResult(obj->adcHandle, ADC_ResultNumber_10);
      Sum += ADC_readResult(obj->adcHandle, ADC_ResultNumber_11);
      Sum += ADC_readResult(obj->adcHandle, ADC_ResultNumber_12);
      Sum += ADC_readResult(obj->adcHandle, ADC_ResultNumber_13);
      Sum += ADC_readResult(obj->adcHandle, ADC_ResultNumber_14);
      Sum += ADC_readResult(obj->adcHandle, ADC_ResultNumber_15);

      index+=16;

  } // end data collection

  //Disable ADCINT1 and ADCINT2 to STOP the ping-pong sampling
  ADC_disableInt(obj->adcHandle, ADC_IntNumber_1);
  ADC_disableInt(obj->adcHandle, ADC_IntNumber_2);

  //Calculate average ADC sample value
  Mean = Sum / SampleSize;

  // Clear start of conversion trigger
  ADC_setupSocTrigSrc(obj->adcHandle, ADC_SocNumber_0, ADC_NoIntTriggersSOC);
  ADC_setupSocTrigSrc(obj->adcHandle, ADC_SocNumber_1, ADC_NoIntTriggersSOC);
  ADC_setupSocTrigSrc(obj->adcHandle, ADC_SocNumber_2, ADC_NoIntTriggersSOC);
  ADC_setupSocTrigSrc(obj->adcHandle, ADC_SocNumber_3, ADC_NoIntTriggersSOC);
  ADC_setupSocTrigSrc(obj->adcHandle, ADC_SocNumber_4, ADC_NoIntTriggersSOC);
  ADC_setupSocTrigSrc(obj->adcHandle, ADC_SocNumber_5, ADC_NoIntTriggersSOC);
  ADC_setupSocTrigSrc(obj->adcHandle, ADC_SocNumber_6, ADC_NoIntTriggersSOC);
  ADC_setupSocTrigSrc(obj->adcHandle, ADC_SocNumber_7, ADC_NoIntTriggersSOC);
  ADC_setupSocTrigSrc(obj->adcHandle, ADC_SocNumber_8, ADC_NoIntTriggersSOC);
  ADC_setupSocTrigSrc(obj->adcHandle, ADC_SocNumber_9, ADC_NoIntTriggersSOC);
  ADC_setupSocTrigSrc(obj->adcHandle, ADC_SocNumber_10, ADC_NoIntTriggersSOC);
  ADC_setupSocTrigSrc(obj->adcHandle, ADC_SocNumber_11, ADC_NoIntTriggersSOC);
  ADC_setupSocTrigSrc(obj->adcHandle, ADC_SocNumber_12, ADC_NoIntTriggersSOC);
  ADC_setupSocTrigSrc(obj->adcHandle, ADC_SocNumber_13, ADC_NoIntTriggersSOC);
  ADC_setupSocTrigSrc(obj->adcHandle, ADC_SocNumber_14, ADC_NoIntTriggersSOC);
  ADC_setupSocTrigSrc(obj->adcHandle, ADC_SocNumber_15, ADC_NoIntTriggersSOC);

  //return the average
  return(Mean);
} // end of HAL_AdcCalConversion() function
