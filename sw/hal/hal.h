// ================================================================================================
//! \file       hal.h
//! \brief      Contains public interface to various functions related to the HAL object
//! \author     sunyanjun
//! \version    1.0
//! \date       2017.03.21
//! \copyright  SANTROLL
// ================================================================================================

#ifndef _HAL_H_
#define _HAL_H_

//! @defgroup HAL HAL
//! @{

#ifdef __cplusplus
extern "C" {
#endif
// ================================================================================================
// the includes

#include "sw/hal/hal_obj.h"
#include "sw/hal/hal_qep.h"
#include "sw/hal/hal_spi.h"
#include "sw/hal/hal_gpio.h"
#include "sw/hal/hal_pwm.h"
#include "sw/hal/hal_timer.h"
#include "sw/hal/hal_adc.h"
#include "sw/hal/hal_clks.h"
#include "sw/hal/hal_ints.h"
#include "sw/hal/hal_flash.h"
#include "sw/hal/hal_can.h"
#include "sw/hal/hal_sci.h"
#include "sw/hal/hal_i2c.h"


// ================================================================================================
// the defines

#define Device_cal (void   (*)(void))0x3D7C80



// ================================================================================================
// the typedefs


// ================================================================================================
// the globals

extern HAL_Obj hal;            //!< Defines the HAL object
extern HAL_Handle halHandle;   //!< Defines the HAL object Handle
extern PWM_PARM_OBJ PwmsParm;  //!< PWM配置参数
extern float MainLoopUsage;    //!< 主循环负载率
extern float MainISR_Usage;    //!< 主中断负载率

#ifdef FLASH
//! Used for running BackGround in flash, and ISR in RAM
extern uint16_t *RamfuncsLoadStart, *RamfuncsLoadEnd, *RamfuncsRunStart;
#endif /* FLASH */

// ================================================================================================
// the function prototypes


//! \brief      Executes calibration routines
//! \details    Values for offset and gain are programmed into OTP memory at
//!             the TI factory.  This calls and internal function that programs
//!             these offsets and gains into the ADC registers.
//! \param[in]  handle  The hardware abstraction layer (HAL) handle
extern void HAL_cal(HAL_Handle handle);


//! \brief      Initializes the hardware abstraction layer (HAL) object
//! \details    Initializes all handles to the microcontroller peripherals.
//!             Returns a handle to the HAL object.
//! \param[in]  pMemory   A pointer to the memory for the hardware abstraction layer object
//! \param[in]  numBytes  The number of bytes allocated for the hardware abstraction layer object, bytes
//! \return     The hardware abstraction layer (HAL) object handle
extern HAL_Handle HAL_init(void *pMemory,const size_t numBytes);


//! \brief      Sets the hardware abstraction layer parameters
//! \details    Sets up the microcontroller peripherals.  Creates all of the scale
//!             factors for the ADC voltage and current conversions.  Sets the initial
//!             offset values for voltage and current measurements.
extern void HAL_setParams();


// ================================================================================================
#ifdef __cplusplus
}
#endif // extern "C"

//! @} // end of HAL

#endif // end of _HAL_H_ definition


