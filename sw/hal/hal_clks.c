//! \file       hal_clks.c
//! \brief      Contains various functions related to the CLKS object
//! \author     sunyanjun
//! \version    1.0
//! \date       2017.03.21
//! \copyright  SANTROLL

void HAL_setupClks(HAL_Handle handle)
{
  HAL_Obj *obj = (HAL_Obj *)handle;

  // 0.enable internal oscillator 1
  CLK_enableOsc1(obj->clkHandle);

  // 1.Sets the XCLKIN Clock Source
  CLK_setXClkInSrc(obj->clkHandle, CLK_XClkInSrc_Gpio19);

  // 2.Disables the crystal oscillator
  CLK_disableCrystalOsc(obj->clkHandle);

  // 3.Enables the XCLKIN oscillator input
  CLK_enableClkIn(obj->clkHandle);

  // 4.Sets the oscillator 2 clock source
  CLK_setOsc2Src(obj->clkHandle,CLK_Osc2Src_External);

  // 5.Sets the oscillator clock source
  CLK_setOscSrc(obj->clkHandle,CLK_OscSrc_External);

  // 6.Sets the watchdog clock source
  CLK_setWatchDogSrc(obj->clkHandle,CLK_WdClkSrc_IntOsc1);

  // 7.Disables internal oscillator 2
  CLK_disableOsc2(obj->clkHandle);

  // 8.set the low speed clock prescaler
  CLK_setLowSpdPreScaler(obj->clkHandle,CLK_LowSpdPreScaler_SysClkOut_by_4);

  // 9.set the clock out prescaler
  CLK_setClkOutPreScaler(obj->clkHandle,CLK_ClkOutPreScaler_SysClkOut_by_4);

  return;
} // end of HAL_setupClks() function


void HAL_setupPeripheralClks(HAL_Handle handle)
{
  HAL_Obj *obj = (HAL_Obj *)handle;


  CLK_enableAdcClock(obj->clkHandle);

  CLK_enableCompClock(obj->clkHandle,CLK_CompNumber_1);
  CLK_enableCompClock(obj->clkHandle,CLK_CompNumber_2);
  CLK_enableCompClock(obj->clkHandle,CLK_CompNumber_3);

  CLK_enableEcap1Clock(obj->clkHandle);

  CLK_enableEcanaClock(obj->clkHandle);

  CLK_enableEqep1Clock(obj->clkHandle);
  CLK_enableEqep2Clock(obj->clkHandle);

  CLK_enablePwmClock(obj->clkHandle,PWM_Number_1);
  CLK_enablePwmClock(obj->clkHandle,PWM_Number_2);
  CLK_enablePwmClock(obj->clkHandle,PWM_Number_3);
  CLK_enablePwmClock(obj->clkHandle,PWM_Number_4);
  CLK_enablePwmClock(obj->clkHandle,PWM_Number_5);
  CLK_enablePwmClock(obj->clkHandle,PWM_Number_6);
  CLK_enablePwmClock(obj->clkHandle,PWM_Number_7);
#if EVCBD_ID == 0x08 || EVCBD_ID == 0x0D
  CLK_enablePwmClock(obj->clkHandle,PWM_Number_8);
#endif

  CLK_disableHrPwmClock(obj->clkHandle);

  CLK_enableI2cClock(obj->clkHandle);

  CLK_disableLinAClock(obj->clkHandle);

  CLK_disableClaClock(obj->clkHandle);

  CLK_enableSciaClock(obj->clkHandle);

  CLK_enableScibClock(obj->clkHandle);

  CLK_enableSpiaClock(obj->clkHandle);

  CLK_enableSpibClock(obj->clkHandle);

  CLK_enableTbClockSync(obj->clkHandle);

  return;
} // end of HAL_setupPeripheralClks() function


void HAL_setupPll(HAL_Handle handle,const PLL_ClkFreq_e clkFreq)
{
  HAL_Obj *obj = (HAL_Obj *)handle;


  // make sure PLL is not running in limp mode
  if(PLL_getClkStatus(obj->pllHandle) != PLL_ClkStatus_Normal)
    {
      // reset the clock detect
      PLL_resetClkDetect(obj->pllHandle);

      // ???????
      asm("        ESTOP0");
    }


  // Divide Select must be ClkIn/4 before the clock rate can be changed
  if(PLL_getDivideSelect(obj->pllHandle) != PLL_DivideSelect_ClkIn_by_4)
    {
      PLL_setDivideSelect(obj->pllHandle,PLL_DivideSelect_ClkIn_by_4);
    }


  if(PLL_getClkFreq(obj->pllHandle) != clkFreq)
    {
      // disable the clock detect
      PLL_disableClkDetect(obj->pllHandle);

      // set the clock rate
      PLL_setClkFreq(obj->pllHandle,clkFreq);
    }


  // wait until locked
  while(PLL_getLockStatus(obj->pllHandle) != PLL_LockStatus_Done) {}


  // enable the clock detect
  PLL_enableClkDetect(obj->pllHandle);


  // set divide select to ClkIn/2 to get desired clock rate
  // NOTE: clock must be locked before setting this register
  PLL_setDivideSelect(obj->pllHandle,PLL_DivideSelect_ClkIn_by_4);

  return;
} // end of HAL_setupPll() function



void HAL_OscTempComp(HAL_Handle handle)
{
  HAL_Obj *obj = (HAL_Obj *)handle;
  uint16_t Temperature;

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

  // enable non-overlap mode
  ADC_enableNoOverlapMode(obj->adcHandle);

  // connect channel A5 internally to the temperature sensor
  ADC_setTempSensorSrc(obj->adcHandle, ADC_TempSensorSrc_Int);

  // set SOC0 channel select to ADCINA5
  ADC_setSocChanNumber(obj->adcHandle, ADC_SocNumber_0, ADC_SocChanNumber_A5);

  // set SOC0 acquisition period to 26 ADCCLK
  ADC_setSocSampleDelay(obj->adcHandle, ADC_SocNumber_0, ADC_SocSampleDelay_64_cycles);

  // connect ADCINT1 to EOC0
  ADC_setIntSrc(obj->adcHandle, ADC_IntNumber_1, ADC_IntSrc_EOC0);

  // clear ADCINT1 flag
  ADC_clearIntFlag(obj->adcHandle, ADC_IntNumber_1);

  // enable ADCINT1
  ADC_enableInt(obj->adcHandle, ADC_IntNumber_1);

  // force start of conversion on SOC0
  ADC_setSocFrc(obj->adcHandle, ADC_SocFrc_0);

  // wait for end of conversion
  while (ADC_getIntFlag(obj->adcHandle, ADC_IntNumber_1) == 0){}

  // clear ADCINT1 flag
  ADC_clearIntFlag(obj->adcHandle, ADC_IntNumber_1);

  Temperature = ADC_readResult(obj->adcHandle, ADC_ResultNumber_0);

  HAL_osc1Comp(handle, Temperature);

  HAL_osc2Comp(handle, Temperature);

  return;
} // end of HAL_OscTempComp() function


void HAL_osc1Comp(HAL_Handle handle, const int16_t sensorSample)
{
	int16_t compOscFineTrim;
	HAL_Obj *obj = (HAL_Obj *)handle;

	ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    compOscFineTrim = ((sensorSample - getRefTempOffset())*(int32_t)getOsc1FineTrimSlope()
                      + OSC_POSTRIM_OFF + FP_ROUND )/FP_SCALE + getOsc1FineTrimOffset() - OSC_POSTRIM;

    if(compOscFineTrim > 31)
      {
        compOscFineTrim = 31;
      }
	else if(compOscFineTrim < -31)
      {
        compOscFineTrim = -31;
      }

    OSC_setTrim(obj->oscHandle, OSC_Number_1, HAL_getOscTrimValue(getOsc1CoarseTrim(), compOscFineTrim));

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of HAL_osc1Comp() function


void HAL_osc2Comp(HAL_Handle handle, const int16_t sensorSample)
{
	int16_t compOscFineTrim;
	HAL_Obj *obj = (HAL_Obj *)handle;

	ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    compOscFineTrim = ((sensorSample - getRefTempOffset())*(int32_t)getOsc2FineTrimSlope()
                      + OSC_POSTRIM_OFF + FP_ROUND )/FP_SCALE + getOsc2FineTrimOffset() - OSC_POSTRIM;

    if(compOscFineTrim > 31)
      {
        compOscFineTrim = 31;
      }
	else if(compOscFineTrim < -31)
      {
        compOscFineTrim = -31;
      }

    OSC_setTrim(obj->oscHandle, OSC_Number_2, HAL_getOscTrimValue(getOsc2CoarseTrim(), compOscFineTrim));

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of HAL_osc2Comp() function


uint16_t HAL_getOscTrimValue(int16_t coarse, int16_t fine)
{
  uint16_t regValue = 0;

  if(fine < 0)
    {
      regValue = ((-fine) | 0x20) << 9;
    }
  else
    {
      regValue = fine << 9;
    }

  if(coarse < 0)
    {
      regValue |= ((-coarse) | 0x80);
    }
  else
    {
      regValue |= coarse;
    }

  return regValue;
} // end of HAL_getOscTrimValue() function


void HAL_disableWdog(HAL_Handle halHandle)
{
  HAL_Obj *hal = (HAL_Obj *)halHandle;


  WDOG_disable(hal->wdogHandle);


  return;
} // end of HAL_disableWdog() function

