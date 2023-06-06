//! \file       hal_timer.c
//! \brief      Contains various functions related to the TIMER object
//! \author     sunyanjun
//! \version    1.0
//! \date       2017.03.21
//! \copyright  SANTROLL


void HAL_setupTimers(HAL_Handle handle,const float_t systemFreq_MHz)
{
  HAL_Obj  *obj = (HAL_Obj *)handle;
  uint32_t  timerPeriod = (uint32_t)(systemFreq_MHz * HAL_MAINLOOP_PRD_us) - 1;

  // use timer 0 for Mainloop Period
  TIMER_setDecimationFactor(obj->timerHandle[0],0);
  TIMER_setEmulationMode(obj->timerHandle[0],TIMER_EmulationMode_RunFree);
  TIMER_setPeriod(obj->timerHandle[0],timerPeriod);
  TIMER_setPreScaler(obj->timerHandle[0],0);
  TIMER_reload(obj->timerHandle[0]);

  // use timer 1 for Mainloop usage diagnostics
  TIMER_setDecimationFactor(obj->timerHandle[1],0);
  TIMER_setEmulationMode(obj->timerHandle[1],TIMER_EmulationMode_RunFree);
  TIMER_setPeriod(obj->timerHandle[1],0xFFFFFFFF);
  TIMER_setPreScaler(obj->timerHandle[1],0);

  // use timer 2 for ISR usage diagnostics
  TIMER_setDecimationFactor(obj->timerHandle[2],0);
  TIMER_setEmulationMode(obj->timerHandle[2],TIMER_EmulationMode_RunFree);
  TIMER_setPeriod(obj->timerHandle[2],0xFFFFFFFF);
  TIMER_setPreScaler(obj->timerHandle[2],0);

  return;
}  // end of HAL_setupTimers() function


void HAL_enableTimer0Int(HAL_Handle handle)
{
  HAL_Obj *obj = (HAL_Obj *)handle;

  PIE_enableTimer0Int(obj->pieHandle);

  // enable the interrupt
  TIMER_enableInt(obj->timerHandle[0]);

  // enable the cpu interrupt for TINT0
  CPU_enableInt(obj->cpuHandle,CPU_IntNumber_1);

  return;
} // end of HAL_enablePwmInt() function


