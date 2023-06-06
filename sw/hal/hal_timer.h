//! \file       hal_timer.h
//! \brief      Contains public interface to various functions related to the TIMER module
//! \author     sunyanjun
//! \version    1.0
//! \date       2017.03.21
//! \copyright  SANTROLL

#ifndef _HAL_TIMER_H_
#define _HAL_TIMER_H_

//! @defgroup HAL_TIMER HAL_TIMER
//! @{

#ifdef __cplusplus
extern "C" {
#endif

// ============================================================================
// the function prototypes

//! \brief     Starts the timer
//! \param[in] handle       The hardware abstraction layer (HAL) handle
//! \param[in] timerNumber  The timer number, 0,1 or 2
static inline void HAL_startTimer(HAL_Handle handle,const uint_least8_t timerNumber)
{
  HAL_Obj  *obj = (HAL_Obj *)handle;

  // start the specified timer
  TIMER_start(obj->timerHandle[timerNumber]);

  return;
}  // end of HAL_startTimer() function


//! \brief     Stops the timer
//! \param[in] handle       The hardware abstraction layer (HAL) handle
//! \param[in] timerNumber  The timer number, 0,1 or 2
static inline void HAL_stopTimer(HAL_Handle handle,const uint_least8_t timerNumber)
{
  HAL_Obj  *obj = (HAL_Obj *)handle;

  // stop the specified timer
  TIMER_stop(obj->timerHandle[timerNumber]);

  return;
}  // end of HAL_stopTimer() function


//! \brief     Sets the timer period
//! \param[in] handle       The hardware abstraction layer (HAL) handle
//! \param[in] timerNumber  The timer number, 0,1 or 2
//! \param[in] period       The timer period
static inline void HAL_setTimerPeriod(HAL_Handle handle,const uint_least8_t timerNumber, const uint32_t period)
{
  HAL_Obj  *obj = (HAL_Obj *)handle;

  // set the period
  TIMER_setPeriod(obj->timerHandle[timerNumber], period);

  return;
}  // end of HAL_setTimerPeriod() function


//! \brief     Reads the timer count
//! \param[in] handle       The hardware abstraction layer (HAL) handle
//! \param[in] timerNumber  The timer number, 0,1 or 2
//! \return    The timer count
static inline uint32_t HAL_readTimerCnt(HAL_Handle handle,const uint_least8_t timerNumber)
{
  HAL_Obj *obj = (HAL_Obj *)handle;
  uint32_t timerCnt = TIMER_getCount(obj->timerHandle[timerNumber]);

  return(timerCnt);
} // end of HAL_readTimerCnt() function


//! \brief     Reloads the timer
//! \param[in] handle       The hardware abstraction layer (HAL) handle
//! \param[in] timerNumber  The timer number, 0,1 or 2
static inline void HAL_reloadTimer(HAL_Handle handle,const uint_least8_t timerNumber)
{
  HAL_Obj  *obj = (HAL_Obj *)handle;

  // reload the specified timer
  TIMER_reload(obj->timerHandle[timerNumber]);

  return;
}  // end of HAL_reloadTimer() function


//! \brief     Gets the timer period
//! \param[in] handle       The hardware abstraction layer (HAL) handle
//! \param[in] timerNumber  The timer number, 0,1 or 2
//! \return    The timer period
static inline uint32_t HAL_getTimerPeriod(HAL_Handle handle,const uint_least8_t timerNumber)
{
  HAL_Obj  *obj = (HAL_Obj *)handle;

  uint32_t timerPeriod = TIMER_getPeriod(obj->timerHandle[timerNumber]);

  return(timerPeriod);
}  // end of HAL_getTimerPeriod() function


//! \brief     Acknowledges an interrupt from Timer 0 so that another Timer 0 interrupt can
//!            happen again.
//! \param[in] handle     The hardware abstraction layer (HAL) handle
static inline void HAL_acqTimer0Int(HAL_Handle handle)
{
  HAL_Obj *obj = (HAL_Obj *)handle;


  // clear the Timer 0 interrupt flag
  TIMER_clearFlag(obj->timerHandle[0]);


  // Acknowledge interrupt from PIE group 1
  PIE_clearInt(obj->pieHandle,PIE_GroupNumber_1);

  return;
} // end of HAL_acqTimer0Int() function


//! \brief     Enables the Timer 0 interrupt
//! \param[in] handle  The hardware abstraction layer (HAL) handle
extern void HAL_enableTimer0Int(HAL_Handle handle);


//! \brief     Sets up the timers
//! \param[in] handle          The hardware abstraction layer (HAL) handle
//! \param[in] systemFreq_MHz  The system frequency, MHz
void HAL_setupTimers(HAL_Handle handle,const float_t systemFreq_MHz);


// ============================================================================

#ifdef __cplusplus
}
#endif // extern "C"

//! @} // end of HAL_TIMER

#endif /* _HAL_TIMER_H_ */
