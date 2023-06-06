//! \file       hal_pwm.h
//! \brief      Contains public interface to various functions related to the PWM module
//! \author     sunyanjun
//! \version    1.0
//! \date       2017.03.21
//! \copyright  SANTROLL

#ifndef _HAL_PWM_H_
#define _HAL_PWM_H_

//! @defgroup HAL_PWM HAL_PWM
//! @{

#ifdef __cplusplus
extern "C" {
#endif
// ============================================================================
// the typedefs

typedef struct
{
	float Prd;       //!< [in]    [us]  PWM周期设定值，实时刷新
	float DBRED;     //!< [in]    [us]  上升沿死区时间，初始化时生效
	float DBFED;     //!< [in]    [us]  下降沿死区时间，初始化时生效
	float Duty_A;    //!< [in]    [%]   PWM module 1 占空比，实时刷新
	float Duty_B;    //!< [in]    [%]   PWM module 2 占空比，实时刷新
	float Duty_C;    //!< [in]    [%]   PWM module 3 占空比，实时刷新
	float TBPRD;     //!< [inner] [/]   PWM 占空比寄存器值

	void  (*Set)();
}PWM_PARM_OBJ;

#define PWM_PARM_OBJ_DEFAULTS   { HAL_PWM_PERIOD_us,  /* 初始PWM周期*/\
                                  HAL_PWM_DBRED_us,\
                                  HAL_PWM_DBFED_us,\
                                  1.0,\
                                  1.0,\
                                  1.0,\
                                  0,\
                                  (void (*)(long))PWMs_Set}


extern void PWMs_Set(HAL_Handle handle,PWM_PARM_OBJ* PWM);
// ============================================================================
// the function prototypes


//! \brief      Enables the PWM devices
//! \details    Turns on the outputs of the EPWM peripheral which will allow
//!             the power switches to be controlled.
//! \param[in]  handle  The hardware abstraction layer (HAL) handle
static inline void HAL_enablePwm(HAL_Handle handle)
{
  HAL_Obj *obj = (HAL_Obj *)handle;

  PWM_clearOneShotTrip(obj->pwmHandle[PWM_Number_1]);
  PWM_clearOneShotTrip(obj->pwmHandle[PWM_Number_2]);
  PWM_clearOneShotTrip(obj->pwmHandle[PWM_Number_3]);

  return;
} // end of HAL_enablePwm() function


//! \brief      Disables the PWM device
//! \details    Turns off the outputs of the EPWM peripherals which will put
//!             the power switches into a high impedance state.
//! \param[in]  handle  The hardware abstraction layer (HAL) handle
static inline void HAL_disablePwm(HAL_Handle handle)
{
  HAL_Obj *obj = (HAL_Obj *)handle;

  PWM_setOneShotTrip(obj->pwmHandle[PWM_Number_1]);
  PWM_setOneShotTrip(obj->pwmHandle[PWM_Number_2]);
  PWM_setOneShotTrip(obj->pwmHandle[PWM_Number_3]);

  return;
} // end of HAL_disablePwm() function


//! \brief     Reads PWM compare register A
//! \param[in] handle    The hardware abstraction layer (HAL) handle
//! \param[in] pwmNumber  The PWM number
//! \return    The PWM compare value
static inline uint16_t HAL_readPwmCmpA(HAL_Handle handle,const PWM_Number_e pwmNumber)
{
  HAL_Obj *obj = (HAL_Obj *)handle;

  // the compare value to be returned
  uint16_t pwmValue;

  pwmValue = PWM_get_CmpA(obj->pwmHandle[pwmNumber]);

  return(pwmValue);
} // end of HAL_readPwmCmpA() function


//! \brief     Reads PWM compare mirror register A
//! \param[in] handle    The hardware abstraction layer (HAL) handle
//! \param[in] pwmNumber  The PWM number
//! \return    The PWM compare value
static inline uint16_t HAL_readPwmCmpAM(HAL_Handle handle,const PWM_Number_e pwmNumber)
{
  HAL_Obj *obj = (HAL_Obj *)handle;

  // the compare value to be returned
  uint16_t pwmValue;

  pwmValue = PWM_get_CmpAM(obj->pwmHandle[pwmNumber]);

  return(pwmValue);
} // end of HAL_readPwmCmpAM() function


//! \brief     Reads PWM compare register B
//! \param[in] handle    The hardware abstraction layer (HAL) handle
//! \param[in] pwmNumber  The PWM number
//! \return    The PWM compare value
static inline uint16_t HAL_readPwmCmpB(HAL_Handle handle,const PWM_Number_e pwmNumber)
{
  HAL_Obj *obj = (HAL_Obj *)handle;

  // the compare value to be returned
  uint16_t pwmValue;

  pwmValue = PWM_get_CmpB(obj->pwmHandle[pwmNumber]);

  return(pwmValue);
} // end of HAL_readPwmCmpB() function


//! \brief     Reads PWM period register
//! \param[in] handle    The hardware abstraction layer (HAL) handle
//! \param[in] pwmNumber  The PWM number
//! \return    The PWM period value
static inline uint16_t HAL_readPwmPeriod(HAL_Handle handle,const PWM_Number_e pwmNumber)
{
  HAL_Obj *obj = (HAL_Obj *)handle;

  // the period value to be returned
  uint16_t pwmPeriodValue;

  pwmPeriodValue = PWM_getPeriod(obj->pwmHandle[pwmNumber]);

  return(pwmPeriodValue);
} // end of HAL_readPwmPeriod() function


//! \brief     Acknowledges an interrupt from the PWM so that another PWM interrupt can
//!            happen again.
//! \param[in] handle     The hardware abstraction layer (HAL) handle
//! \param[in] pwmNumber  The PWM number
static inline void HAL_acqPwmInt(HAL_Handle handle,const PWM_Number_e pwmNumber)
{
  HAL_Obj *obj = (HAL_Obj *)handle;


  // clear the PWM interrupt flag
  PWM_clearIntFlag(obj->pwmHandle[pwmNumber]);


  // clear the SOCA flag
  PWM_clearSocAFlag(obj->pwmHandle[pwmNumber]);


  // Acknowledge interrupt from PIE group 3
  PIE_clearInt(obj->pieHandle,PIE_GroupNumber_3);

  return;
} // end of HAL_acqPwmInt() function


//! \brief      Configures the fault protection logic
//! \details    Sets up the trip zone inputs so that when a comparator
//!             signal from outside the micro-controller trips a fault,
//!             the EPWM peripheral blocks will force the
//!             power switches into a high impedance state.
//! \param[in]  handle  The hardware abstraction layer (HAL) handle
extern void HAL_setupFaults(HAL_Handle handle);


//! \brief     Enables the PWM interrupt
//! \param[in] handle  The hardware abstraction layer (HAL) handle
extern void HAL_enablePwmInt(HAL_Handle handle);


//! \brief     Sets up the PWMs (Pulse Width Modulators)
//! \param[in] handle          The hardware abstraction layer (HAL) handle
//! \param[in] numPwmTicksPerIsrTick  The number of PWM clock ticks per ISR clock tick
extern void HAL_setupPwms(HAL_Handle handle,const uint_least16_t numPwmTicksPerIsrTick);

extern void HAL_writeDacData(HAL_Handle handle,uint16_t Num , float Duty);
// ============================================================================

#ifdef __cplusplus
}
#endif // extern "C"

//! @} // end of HAL_PWM

#endif /* _HAL_PWM_H_ */
