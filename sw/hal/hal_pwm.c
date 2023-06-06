//! \file       hal_pwm.c
//! \brief      Contains various functions related to the PWM object
//! \author     sunyanjun
//! \version    1.0
//! \date       2017.03.21
//! \copyright  SANTROLL

void PWMs_Set(HAL_Handle handle,PWM_PARM_OBJ* Parm)
{
	Parm->TBPRD = (HAL_SYSTEM_FREQ_MHz *0.5) * Parm->Prd;

	PWM_setPeriod(handle->pwmHandle[0],(uint16_t)Parm->TBPRD);
	PWM_setPeriod(handle->pwmHandle[1],(uint16_t)Parm->TBPRD);
	PWM_setPeriod(handle->pwmHandle[2],(uint16_t)Parm->TBPRD);

	PWM_setCmpA(handle->pwmHandle[0],(uint16_t)(Parm->TBPRD * Parm->Duty_A));
	PWM_setCmpA(handle->pwmHandle[1],(uint16_t)(Parm->TBPRD * Parm->Duty_B));
	PWM_setCmpA(handle->pwmHandle[2],(uint16_t)(Parm->TBPRD * Parm->Duty_C));
}

//#define DOUBLE_PWM 1
#if EVCBD_ID == 0x08 || EVCBD_ID == 0x0D
void HAL_setupPwms(HAL_Handle handle,const uint_least16_t numPwmTicksPerIsrTick)
{
    HAL_Obj   *obj = (HAL_Obj *)handle;
    uint_least8_t    cnt;
    // turns off the outputs of the EPWM peripherals which will put the power switches
    // into a high impedance state.
    PWM_setOneShotTrip(obj->pwmHandle[PWM_Number_1]);
    PWM_setOneShotTrip(obj->pwmHandle[PWM_Number_2]);
    PWM_setOneShotTrip(obj->pwmHandle[PWM_Number_3]);

    for(cnt=0;cnt<3;cnt++)
    {
        // setup the Time-Base Control Register (TBCTL)
        PWM_setCounterMode(obj->pwmHandle[cnt],PWM_CounterMode_UpDown);
        PWM_disableCounterLoad(obj->pwmHandle[cnt]);
        PWM_setPeriodLoad(obj->pwmHandle[cnt],PWM_PeriodLoad_Immediate);
        PWM_setSyncMode(obj->pwmHandle[cnt],PWM_SyncMode_EPWMxSYNC);
        PWM_setHighSpeedClkDiv(obj->pwmHandle[cnt],PWM_HspClkDiv_by_1);
        PWM_setClkDiv(obj->pwmHandle[cnt],PWM_ClkDiv_by_1);
        PWM_setPhaseDir(obj->pwmHandle[cnt],PWM_PhaseDir_CountUp);
        PWM_setRunMode(obj->pwmHandle[cnt],PWM_RunMode_FreeRun);

        // setup the Timer-Based Phase Register (TBPHS)
        PWM_setPhase(obj->pwmHandle[cnt],0);

        // setup the Time-Base Counter Register (TBCTR)
        PWM_setCount(obj->pwmHandle[cnt],0);

        // setup the Time-Base Period Register (TBPRD)
        // set to zero initially
        PWM_setPeriod(obj->pwmHandle[cnt],0);

        // setup the Counter-Compare Control Register (CMPCTL)
#if Single_or_Double == 1||Single_or_Double == 3
      PWM_setLoadMode_CmpA(obj->pwmHandle[cnt],PWM_LoadMode_Zero);
#elif Single_or_Double == 2
      PWM_setLoadMode_CmpA(obj->pwmHandle[cnt],PWM_LoadMode_Either);
#endif
        PWM_setLoadMode_CmpB(obj->pwmHandle[cnt],PWM_LoadMode_Zero);
        PWM_setShadowMode_CmpA(obj->pwmHandle[cnt],PWM_ShadowMode_Shadow);
        PWM_setShadowMode_CmpB(obj->pwmHandle[cnt],PWM_ShadowMode_Immediate);

        // setup the Action-Qualifier Output A Register (AQCTLA)
        PWM_setActionQual_CntUp_CmpA_PwmA(obj->pwmHandle[cnt],PWM_ActionQual_Set);
        PWM_setActionQual_CntDown_CmpA_PwmA(obj->pwmHandle[cnt],PWM_ActionQual_Clear);

        // setup the Dead-Band Generator Control Register (DBCTL)
        PWM_setDeadBandInputMode(obj->pwmHandle[cnt],PWM_DeadBandInputMode_EPWMxA_Rising_and_Falling);
        PWM_setDeadBandOutputMode(obj->pwmHandle[cnt],PWM_DeadBandOutputMode_EPWMxA_Rising_EPWMxB_Falling);
        PWM_setDeadBandPolarity(obj->pwmHandle[cnt],PWM_DeadBandPolarity_EPWMxB_Inverted);

        // setup the Dead-Band Rising Edge Delay Register (DBRED)
        PWM_setDeadBandRisingEdgeDelay(obj->pwmHandle[cnt],(PwmsParm.DBRED*HAL_SYSTEM_FREQ_MHz));

        // setup the Dead-Band Falling Edge Delay Register (DBFED)
        PWM_setDeadBandFallingEdgeDelay(obj->pwmHandle[cnt],(PwmsParm.DBFED*HAL_SYSTEM_FREQ_MHz));
        // setup the PWM-Chopper Control Register (PCCTL)
        PWM_disableChopping(obj->pwmHandle[cnt]);

        // setup the Trip Zone Select Register (TZSEL)
        PWM_disableTripZones(obj->pwmHandle[cnt]);
    }
  // pwm输出设置
    for(cnt=7;cnt<8;cnt++)
    {
        // initialize the Time-Base Control Register (TBCTL)
        PWM_setCounterMode(obj->pwmHandle[cnt],PWM_CounterMode_UpDown);
        PWM_disableCounterLoad(obj->pwmHandle[cnt]);
        PWM_setPeriodLoad(obj->pwmHandle[cnt],PWM_PeriodLoad_Immediate);
        PWM_setSyncMode(obj->pwmHandle[cnt],PWM_SyncMode_EPWMxSYNC);
        PWM_setHighSpeedClkDiv(obj->pwmHandle[cnt],PWM_HspClkDiv_by_1);
        PWM_setClkDiv(obj->pwmHandle[cnt],PWM_ClkDiv_by_1);
        PWM_setPhaseDir(obj->pwmHandle[cnt],PWM_PhaseDir_CountUp);
        PWM_setRunMode(obj->pwmHandle[cnt],PWM_RunMode_FreeRun);

        // initialize the Timer-Based Phase Register (TBPHS)
        PWM_setPhase(obj->pwmHandle[cnt],0);

        // setup the Time-Base Counter Register (TBCTR)
        PWM_setCount(obj->pwmHandle[cnt],0);

        // Initialize the Time-Base Period Register (TBPRD)
        // set to zero initially
        PWM_setPeriod(obj->pwmHandle[cnt],0);

        // initialize the Counter-Compare Control Register (CMPCTL)
        PWM_setLoadMode_CmpA(obj->pwmHandle[cnt],PWM_LoadMode_Zero);
        PWM_setLoadMode_CmpB(obj->pwmHandle[cnt],PWM_LoadMode_Zero);
        PWM_setShadowMode_CmpA(obj->pwmHandle[cnt],PWM_ShadowMode_Shadow);
        PWM_setShadowMode_CmpB(obj->pwmHandle[cnt],PWM_ShadowMode_Shadow);

        PWM_setActionQual_CntUp_CmpA_PwmA(obj->pwmHandle[cnt],PWM_ActionQual_Set);
        PWM_setActionQual_CntDown_CmpA_PwmA(obj->pwmHandle[cnt],PWM_ActionQual_Clear);

        PWM_setActionQual_CntUp_CmpB_PwmB(obj->pwmHandle[cnt],PWM_ActionQual_Set);
        PWM_setActionQual_CntDown_CmpB_PwmB(obj->pwmHandle[cnt],PWM_ActionQual_Clear);

        // Initialize the Dead-Band Control Register (DBCTL)
        PWM_disableDeadBand(obj->pwmHandle[cnt]);

        // Initialize the PWM-Chopper Control Register (PCCTL)
        PWM_disableChopping(obj->pwmHandle[cnt]);

        // Initialize the Trip-Zone Control Register (TZSEL)
        PWM_disableTripZones(obj->pwmHandle[cnt]);

        // Initialize the Trip-Zone Control Register (TZCTL)
        PWM_setTripZoneState_TZA(obj->pwmHandle[cnt],PWM_TripZoneState_HighImp);
        PWM_setTripZoneState_TZB(obj->pwmHandle[cnt],PWM_TripZoneState_HighImp);
        PWM_setTripZoneState_DCAEVT1(obj->pwmHandle[cnt],PWM_TripZoneState_HighImp);
        PWM_setTripZoneState_DCAEVT2(obj->pwmHandle[cnt],PWM_TripZoneState_HighImp);
        PWM_setTripZoneState_DCBEVT1(obj->pwmHandle[cnt],PWM_TripZoneState_HighImp);
    }
//PT100设置
    PWM_setPeriod(handle->pwmHandle[7],(uint16_t)2250);
    //设置占空比 PWM逻辑是反的  0.3 出70%
//    PWM_setCmpA(handle->pwmHandle[7],(uint16_t)(2250* 0.2439));// 2495mv 恒流源5ma
//    PWM_setCmpB(handle->pwmHandle[7],(uint16_t)(2250* 0.2439));// 2495mv 恒流源5ma

//    PWM_setCmpA(handle->pwmHandle[7],(uint16_t)(2250* 0.3951));// 2495mv 恒流源4ma
//    PWM_setCmpB(handle->pwmHandle[7],(uint16_t)(2250* 0.3951));// 2495mv 恒流源4ma

    PWM_setCmpA(handle->pwmHandle[7],(uint16_t)(2250* 0.092727));//  恒流源4ma
    PWM_setCmpB(handle->pwmHandle[7],(uint16_t)(2250* 0.092727));//  恒流源4ma

//      PWM_setCmpA(handle->pwmHandle[7],(uint16_t)(2250* 0.0));//  恒流源4.417ma
//      PWM_setCmpB(handle->pwmHandle[7],(uint16_t)(2250* 0.0));//  恒流源4.417ma
    //PWM8使能
    PWM_clearOneShotTrip(handle->pwmHandle[PWM_Number_8]);
    // pwm输出设置结束

  // setup the Event Trigger Selection Register (ETSEL)
  PWM_disableInt(obj->pwmHandle[PWM_Number_1]);
#if Single_or_Double == 1||Single_or_Double == 3
      PWM_setSocAPulseSrc(obj->pwmHandle[PWM_Number_1],PWM_SocPulseSrc_CounterEqualZero);
#elif Single_or_Double == 2
      PWM_setSocAPulseSrc(obj->pwmHandle[PWM_Number_1],PWM_SocPulseSrc_CounterEqualZeroOrPeriod);
#endif

  PWM_enableSocAPulse(obj->pwmHandle[PWM_Number_1]);


  // setup the Event Trigger Prescale Register (ETPS)
  if(numPwmTicksPerIsrTick == 3)
    {
      PWM_setIntPeriod(obj->pwmHandle[PWM_Number_1],PWM_IntPeriod_ThirdEvent);
      PWM_setSocAPeriod(obj->pwmHandle[PWM_Number_1],PWM_SocPeriod_ThirdEvent);
    }
  else if(numPwmTicksPerIsrTick == 2)
    {
      PWM_setIntPeriod(obj->pwmHandle[PWM_Number_1],PWM_IntPeriod_SecondEvent);
      PWM_setSocAPeriod(obj->pwmHandle[PWM_Number_1],PWM_SocPeriod_SecondEvent);
    }
  else
    {
      PWM_setIntPeriod(obj->pwmHandle[PWM_Number_1],PWM_IntPeriod_FirstEvent);
      PWM_setSocAPeriod(obj->pwmHandle[PWM_Number_1],PWM_SocPeriod_FirstEvent);
    }


  // setup the Event Trigger Clear Register (ETCLR)
  PWM_clearIntFlag(obj->pwmHandle[PWM_Number_1]);
  PWM_clearSocAFlag(obj->pwmHandle[PWM_Number_1]);

  // first step to synchronize the pwms
  CLK_disableTbClockSync(obj->clkHandle);

  // since the PWM is configured as an up/down counter, the period register is set to one-half
  // of the desired PWM period
  PwmsParm.Set(halHandle,&PwmsParm);

  // last step to synchronize the pwms
  CLK_enableTbClockSync(obj->clkHandle);

  return;
}  // end of HAL_setupPwms() function
#elif EVCBD_ID == 0x09
void HAL_writeDacData(HAL_Handle handle,uint16_t Num , float Duty)
{
  HAL_Obj *obj = (HAL_Obj *)handle;

  if(Num >4)return;
  if(Num <1)return;

  uint16_t Cmp = 0;
  Cmp = (uint16_t)(Duty * 28125);   // 这个值要和PWM设定值一直45
  if(Num == 1)
  {
      PWM_write_CmpA(obj->pwmHandle[PWMDAC_Number_4],Cmp);
  }
  else if(Num == 2)
  {
      PWM_write_CmpB(obj->pwmHandle[PWMDAC_Number_4],Cmp);
  }
  else if(Num == 3)
  {
      PWM_write_CmpA(obj->pwmHandle[PWMDAC_Number_5],Cmp);
  }
  else if(Num == 4)
  {
      PWM_write_CmpB(obj->pwmHandle[PWMDAC_Number_5],Cmp);
  }
  else
      ;

  return;
} // end of HAL_writeDacData() function

void HAL_setupPwms(HAL_Handle handle,const uint_least16_t numPwmTicksPerIsrTick)
{
  HAL_Obj   *obj = (HAL_Obj *)handle;
  uint_least8_t    cnt;


  // turns off the outputs of the EPWM peripherals which will put the power switches
  // into a high impedance state.
  PWM_setOneShotTrip(obj->pwmHandle[PWM_Number_1]);
  PWM_setOneShotTrip(obj->pwmHandle[PWM_Number_2]);
  PWM_setOneShotTrip(obj->pwmHandle[PWM_Number_3]);

  for(cnt=0;cnt<3;cnt++)
    {
      // setup the Time-Base Control Register (TBCTL)
      PWM_setCounterMode(obj->pwmHandle[cnt],PWM_CounterMode_UpDown);
      PWM_disableCounterLoad(obj->pwmHandle[cnt]);
      PWM_setPeriodLoad(obj->pwmHandle[cnt],PWM_PeriodLoad_Immediate);
      PWM_setSyncMode(obj->pwmHandle[cnt],PWM_SyncMode_EPWMxSYNC);
      PWM_setHighSpeedClkDiv(obj->pwmHandle[cnt],PWM_HspClkDiv_by_1);
      PWM_setClkDiv(obj->pwmHandle[cnt],PWM_ClkDiv_by_1);
      PWM_setPhaseDir(obj->pwmHandle[cnt],PWM_PhaseDir_CountUp);
      PWM_setRunMode(obj->pwmHandle[cnt],PWM_RunMode_FreeRun);

      // setup the Timer-Based Phase Register (TBPHS)
      PWM_setPhase(obj->pwmHandle[cnt],0);

      // setup the Time-Base Counter Register (TBCTR)
      PWM_setCount(obj->pwmHandle[cnt],0);

      // setup the Time-Base Period Register (TBPRD)
      // set to zero initially
      PWM_setPeriod(obj->pwmHandle[cnt],0);

      // setup the Counter-Compare Control Register (CMPCTL)
#if PWM_DOUBLE == 0
      PWM_setLoadMode_CmpA(obj->pwmHandle[cnt],PWM_LoadMode_Zero);  // 单发波
#else
      PWM_setLoadMode_CmpA(obj->pwmHandle[cnt],PWM_LoadMode_Either);  // 双发波
#endif
      PWM_setLoadMode_CmpB(obj->pwmHandle[cnt],PWM_LoadMode_Zero);
      PWM_setShadowMode_CmpA(obj->pwmHandle[cnt],PWM_ShadowMode_Shadow);
      PWM_setShadowMode_CmpB(obj->pwmHandle[cnt],PWM_ShadowMode_Immediate);

      // setup the Action-Qualifier Output A Register (AQCTLA)
      PWM_setActionQual_CntUp_CmpA_PwmA(obj->pwmHandle[cnt],PWM_ActionQual_Set);
      PWM_setActionQual_CntDown_CmpA_PwmA(obj->pwmHandle[cnt],PWM_ActionQual_Clear);

      // setup the Dead-Band Generator Control Register (DBCTL)
      PWM_setDeadBandInputMode(obj->pwmHandle[cnt],PWM_DeadBandInputMode_EPWMxA_Rising_and_Falling);
      PWM_setDeadBandOutputMode(obj->pwmHandle[cnt],PWM_DeadBandOutputMode_EPWMxA_Rising_EPWMxB_Falling);
      PWM_setDeadBandPolarity(obj->pwmHandle[cnt],PWM_DeadBandPolarity_EPWMxB_Inverted);

      // setup the Dead-Band Rising Edge Delay Register (DBRED)
      PWM_setDeadBandRisingEdgeDelay(obj->pwmHandle[cnt],(PwmsParm.DBRED*HAL_SYSTEM_FREQ_MHz));

      // setup the Dead-Band Falling Edge Delay Register (DBFED)
      PWM_setDeadBandFallingEdgeDelay(obj->pwmHandle[cnt],(PwmsParm.DBFED*HAL_SYSTEM_FREQ_MHz));
      // setup the PWM-Chopper Control Register (PCCTL)
      PWM_disableChopping(obj->pwmHandle[cnt]);

      // setup the Trip Zone Select Register (TZSEL)
      PWM_disableTripZones(obj->pwmHandle[cnt]);
    }
  // pwm输出设置

      uint16_t halfPeriod_cycles = 28125;       // 8div 28125->200Hz, 26250->100Hz
      for(cnt=3;cnt<5;cnt++)
      {
       // initialize the Time-Base Control Register (TBCTL)
       PWM_setCounterMode(obj->pwmHandle[cnt],PWM_CounterMode_UpDown);
       PWM_disableCounterLoad(obj->pwmHandle[cnt]);
       PWM_setPeriodLoad(obj->pwmHandle[cnt],PWM_PeriodLoad_Immediate);
       PWM_setSyncMode(obj->pwmHandle[cnt],PWM_SyncMode_EPWMxSYNC);
       PWM_setHighSpeedClkDiv(obj->pwmHandle[cnt],PWM_HspClkDiv_by_8);  // 注意修改8div
       PWM_setClkDiv(obj->pwmHandle[cnt],PWM_ClkDiv_by_1);
       PWM_setPhaseDir(obj->pwmHandle[cnt],PWM_PhaseDir_CountUp);
       PWM_setRunMode(obj->pwmHandle[cnt],PWM_RunMode_FreeRun);

       // initialize the Timer-Based Phase Register (TBPHS)
       PWM_setPhase(obj->pwmHandle[cnt],0);

       // setup the Time-Base Counter Register (TBCTR)
       PWM_setCount(obj->pwmHandle[cnt],0);

       // Initialize the Time-Base Period Register (TBPRD)
       // set to zero initially
       PWM_setPeriod(obj->pwmHandle[cnt],0);

       // initialize the Counter-Compare Control Register (CMPCTL)
       PWM_setLoadMode_CmpA(obj->pwmHandle[cnt],PWM_LoadMode_Zero);
       PWM_setLoadMode_CmpB(obj->pwmHandle[cnt],PWM_LoadMode_Zero);
       PWM_setShadowMode_CmpA(obj->pwmHandle[cnt],PWM_ShadowMode_Shadow);
       PWM_setShadowMode_CmpB(obj->pwmHandle[cnt],PWM_ShadowMode_Shadow);

       // Initialize the Action-Qualifier Output A Register (AQCTLA)
//       PWM_setActionQual_CntUp_CmpA_PwmA(obj->pwmHandle[cnt],PWM_ActionQual_Clear);
//       PWM_setActionQual_CntDown_CmpA_PwmA(obj->pwmHandle[cnt],PWM_ActionQual_Set);

       PWM_setActionQual_CntUp_CmpA_PwmA(obj->pwmHandle[cnt],PWM_ActionQual_Set);
       PWM_setActionQual_CntDown_CmpA_PwmA(obj->pwmHandle[cnt],PWM_ActionQual_Clear);

       //
//       if(cnt == 3)
         {
//           PWM_setActionQual_CntUp_CmpB_PwmB(obj->pwmHandle[cnt],PWM_ActionQual_Clear);
//           PWM_setActionQual_CntDown_CmpB_PwmB(obj->pwmHandle[cnt],PWM_ActionQual_Set);
           PWM_setActionQual_CntUp_CmpB_PwmB(obj->pwmHandle[cnt],PWM_ActionQual_Set);
           PWM_setActionQual_CntDown_CmpB_PwmB(obj->pwmHandle[cnt],PWM_ActionQual_Clear);
         }

       // Initialize the Dead-Band Control Register (DBCTL)
       PWM_disableDeadBand(obj->pwmHandle[cnt]);

       // Initialize the PWM-Chopper Control Register (PCCTL)
       PWM_disableChopping(obj->pwmHandle[cnt]);

       // Initialize the Trip-Zone Control Register (TZSEL)
       PWM_disableTripZones(obj->pwmHandle[cnt]);

       // Initialize the Trip-Zone Control Register (TZCTL)
       PWM_setTripZoneState_TZA(obj->pwmHandle[cnt],PWM_TripZoneState_HighImp);
       PWM_setTripZoneState_TZB(obj->pwmHandle[cnt],PWM_TripZoneState_HighImp);
       PWM_setTripZoneState_DCAEVT1(obj->pwmHandle[cnt],PWM_TripZoneState_HighImp);
       PWM_setTripZoneState_DCAEVT2(obj->pwmHandle[cnt],PWM_TripZoneState_HighImp);
       PWM_setTripZoneState_DCBEVT1(obj->pwmHandle[cnt],PWM_TripZoneState_HighImp);
      }

      // since the PWM is configured as an up/down counter, the period register is set to one-half
      // of the desired PWM period
      PWM_setPeriod(obj->pwmHandle[PWM_Number_3],halfPeriod_cycles);
      PWM_setPeriod(obj->pwmHandle[PWM_Number_4],halfPeriod_cycles);
  // pwm输出设置结束


  // setup the Event Trigger Selection Register (ETSEL)
  PWM_disableInt(obj->pwmHandle[PWM_Number_1]);
#if PWM_DOUBLE == 0
  PWM_setSocAPulseSrc(obj->pwmHandle[PWM_Number_1],PWM_SocPulseSrc_CounterEqualZero);  // 单发波
#else
  PWM_setSocAPulseSrc(obj->pwmHandle[PWM_Number_1],PWM_SocPulseSrc_CounterEqualZeroOrPeriod); // 双发波
#endif
  PWM_enableSocAPulse(obj->pwmHandle[PWM_Number_1]);


  // setup the Event Trigger Prescale Register (ETPS)
  if(numPwmTicksPerIsrTick == 3)
    {
      PWM_setIntPeriod(obj->pwmHandle[PWM_Number_1],PWM_IntPeriod_ThirdEvent);
      PWM_setSocAPeriod(obj->pwmHandle[PWM_Number_1],PWM_SocPeriod_ThirdEvent);
    }
  else if(numPwmTicksPerIsrTick == 2)
    {
      PWM_setIntPeriod(obj->pwmHandle[PWM_Number_1],PWM_IntPeriod_SecondEvent);
      PWM_setSocAPeriod(obj->pwmHandle[PWM_Number_1],PWM_SocPeriod_SecondEvent);
    }
  else
    {
      PWM_setIntPeriod(obj->pwmHandle[PWM_Number_1],PWM_IntPeriod_FirstEvent);
      PWM_setSocAPeriod(obj->pwmHandle[PWM_Number_1],PWM_SocPeriod_FirstEvent);
    }


  // setup the Event Trigger Clear Register (ETCLR)
  PWM_clearIntFlag(obj->pwmHandle[PWM_Number_1]);
  PWM_clearSocAFlag(obj->pwmHandle[PWM_Number_1]);

  // first step to synchronize the pwms
  CLK_disableTbClockSync(obj->clkHandle);

  // since the PWM is configured as an up/down counter, the period register is set to one-half
  // of the desired PWM period
  PwmsParm.Set(halHandle,&PwmsParm);

  // last step to synchronize the pwms
  CLK_enableTbClockSync(obj->clkHandle);

  return;
}  // end of HAL_setupPwms() function
#else
void HAL_setupPwms(HAL_Handle handle,const uint_least16_t numPwmTicksPerIsrTick)
{
  HAL_Obj   *obj = (HAL_Obj *)handle;
  uint_least8_t    cnt;


  // turns off the outputs of the EPWM peripherals which will put the power switches
  // into a high impedance state.
  PWM_setOneShotTrip(obj->pwmHandle[PWM_Number_1]);
  PWM_setOneShotTrip(obj->pwmHandle[PWM_Number_2]);
  PWM_setOneShotTrip(obj->pwmHandle[PWM_Number_3]);

  for(cnt=0;cnt<3;cnt++)
    {
      // setup the Time-Base Control Register (TBCTL)
      PWM_setCounterMode(obj->pwmHandle[cnt],PWM_CounterMode_UpDown);
      PWM_disableCounterLoad(obj->pwmHandle[cnt]);
      PWM_setPeriodLoad(obj->pwmHandle[cnt],PWM_PeriodLoad_Immediate);
      PWM_setSyncMode(obj->pwmHandle[cnt],PWM_SyncMode_EPWMxSYNC);
      PWM_setHighSpeedClkDiv(obj->pwmHandle[cnt],PWM_HspClkDiv_by_1);
      PWM_setClkDiv(obj->pwmHandle[cnt],PWM_ClkDiv_by_1);
      PWM_setPhaseDir(obj->pwmHandle[cnt],PWM_PhaseDir_CountUp);
      PWM_setRunMode(obj->pwmHandle[cnt],PWM_RunMode_FreeRun);

      // setup the Timer-Based Phase Register (TBPHS)
      PWM_setPhase(obj->pwmHandle[cnt],0);

      // setup the Time-Base Counter Register (TBCTR)
      PWM_setCount(obj->pwmHandle[cnt],0);

      // setup the Time-Base Period Register (TBPRD)
      // set to zero initially
      PWM_setPeriod(obj->pwmHandle[cnt],0);

      // setup the Counter-Compare Control Register (CMPCTL)
#if Single_or_Double == 1||Single_or_Double == 3
      PWM_setLoadMode_CmpA(obj->pwmHandle[cnt],PWM_LoadMode_Zero);
#elif Single_or_Double == 2
      PWM_setLoadMode_CmpA(obj->pwmHandle[cnt],PWM_LoadMode_Either);
#endif
      PWM_setLoadMode_CmpB(obj->pwmHandle[cnt],PWM_LoadMode_Zero);
      PWM_setShadowMode_CmpA(obj->pwmHandle[cnt],PWM_ShadowMode_Shadow);
      PWM_setShadowMode_CmpB(obj->pwmHandle[cnt],PWM_ShadowMode_Immediate);

      // setup the Action-Qualifier Output A Register (AQCTLA)
      PWM_setActionQual_CntUp_CmpA_PwmA(obj->pwmHandle[cnt],PWM_ActionQual_Set);
      PWM_setActionQual_CntDown_CmpA_PwmA(obj->pwmHandle[cnt],PWM_ActionQual_Clear);

      // setup the Dead-Band Generator Control Register (DBCTL)
      PWM_setDeadBandInputMode(obj->pwmHandle[cnt],PWM_DeadBandInputMode_EPWMxA_Rising_and_Falling);
      PWM_setDeadBandOutputMode(obj->pwmHandle[cnt],PWM_DeadBandOutputMode_EPWMxA_Rising_EPWMxB_Falling);
      PWM_setDeadBandPolarity(obj->pwmHandle[cnt],PWM_DeadBandPolarity_EPWMxB_Inverted);

      // setup the Dead-Band Rising Edge Delay Register (DBRED)
      PWM_setDeadBandRisingEdgeDelay(obj->pwmHandle[cnt],(PwmsParm.DBRED*HAL_SYSTEM_FREQ_MHz));

      // setup the Dead-Band Falling Edge Delay Register (DBFED)
      PWM_setDeadBandFallingEdgeDelay(obj->pwmHandle[cnt],(PwmsParm.DBFED*HAL_SYSTEM_FREQ_MHz));
      // setup the PWM-Chopper Control Register (PCCTL)
      PWM_disableChopping(obj->pwmHandle[cnt]);

      // setup the Trip Zone Select Register (TZSEL)
      PWM_disableTripZones(obj->pwmHandle[cnt]);
    }


  // setup the Event Trigger Selection Register (ETSEL)
  PWM_disableInt(obj->pwmHandle[PWM_Number_1]);
#if Single_or_Double == 1||Single_or_Double == 3
  PWM_setSocAPulseSrc(obj->pwmHandle[PWM_Number_1],PWM_SocPulseSrc_CounterEqualZero);
#elif Single_or_Double == 2
  PWM_setSocAPulseSrc(obj->pwmHandle[PWM_Number_1],PWM_SocPulseSrc_CounterEqualZeroOrPeriod);
#endif
  PWM_enableSocAPulse(obj->pwmHandle[PWM_Number_1]);


  // setup the Event Trigger Prescale Register (ETPS)
  if(numPwmTicksPerIsrTick == 3)
    {
      PWM_setIntPeriod(obj->pwmHandle[PWM_Number_1],PWM_IntPeriod_ThirdEvent);
      PWM_setSocAPeriod(obj->pwmHandle[PWM_Number_1],PWM_SocPeriod_ThirdEvent);
    }
  else if(numPwmTicksPerIsrTick == 2)
    {
      PWM_setIntPeriod(obj->pwmHandle[PWM_Number_1],PWM_IntPeriod_SecondEvent);
      PWM_setSocAPeriod(obj->pwmHandle[PWM_Number_1],PWM_SocPeriod_SecondEvent);
    }
  else
    {
      PWM_setIntPeriod(obj->pwmHandle[PWM_Number_1],PWM_IntPeriod_FirstEvent);
      PWM_setSocAPeriod(obj->pwmHandle[PWM_Number_1],PWM_SocPeriod_FirstEvent);
    }


  // setup the Event Trigger Clear Register (ETCLR)
  PWM_clearIntFlag(obj->pwmHandle[PWM_Number_1]);
  PWM_clearSocAFlag(obj->pwmHandle[PWM_Number_1]);

  // first step to synchronize the pwms
  CLK_disableTbClockSync(obj->clkHandle);

  // since the PWM is configured as an up/down counter, the period register is set to one-half
  // of the desired PWM period
  PwmsParm.Set(halHandle,&PwmsParm);

  // last step to synchronize the pwms
  CLK_enableTbClockSync(obj->clkHandle);

  return;
}  // end of HAL_setupPwms() function
#endif

void HAL_setupFaults(HAL_Handle handle)
{
  HAL_Obj *obj = (HAL_Obj *)handle;
  uint_least8_t cnt;


  // Configure Trip Mechanism for the Motor control software
  // -Cycle by cycle trip on CPU halt
  // -One shot fault trip zone
  // These trips need to be repeated for EPWM1 ,2 & 3
  for(cnt=0;cnt<3;cnt++)
    {
      PWM_enableTripZoneSrc(obj->pwmHandle[cnt],PWM_TripZoneSrc_CycleByCycle_TZ6_NOT);

      // What do we want the OST/CBC events to do?
      // TZA events can force EPWMxA
      // TZB events can force EPWMxB

      PWM_setTripZoneState_TZA(obj->pwmHandle[cnt],PWM_TripZoneState_EPWM_Low);
      PWM_setTripZoneState_TZB(obj->pwmHandle[cnt],PWM_TripZoneState_EPWM_Low);
    }

  return;
} // end of HAL_setupFaults() function


void HAL_enablePwmInt(HAL_Handle handle)
{
  HAL_Obj *obj = (HAL_Obj *)handle;

  PIE_enablePwmInt(obj->pieHandle,PWM_Number_1);

  // enable the interrupt
  PWM_enableInt(obj->pwmHandle[PWM_Number_1]);

  // enable the cpu interrupt for EPWM1_INT
  CPU_enableInt(obj->cpuHandle,CPU_IntNumber_3);

  return;
} // end of HAL_enablePwmInt() function
