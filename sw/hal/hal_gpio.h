//! \file       hal_gpio.h
//! \brief      Contains public interface to various functions related to the GPIO module
//! \author     sunyanjun
//! \version    1.0
//! \date       2017.03.21
//! \copyright  SANTROLL

#ifndef _HAL_GPIO_H_
#define _HAL_GPIO_H_

//! @defgroup HAL_GPIO HAL_GPIO
//! @{

#ifdef __cplusplus
extern "C" {
#endif

// ============================================================================
// the function prototypes

//! \brief      Sets the GPIO pin high
//! \details    Takes in the enumeration GPIO_Number_e and sets that GPIO
//!             pin high.
//! \param[in]  handle      The hardware abstraction layer (HAL) handle
//! \param[in]  gpioNumber  The GPIO number
static inline void HAL_setGpioHigh(HAL_Handle handle,const GPIO_Number_e gpioNumber)
{
  HAL_Obj *obj = (HAL_Obj *)handle;


  // set GPIO high
  GPIO_setHigh(obj->gpioHandle,gpioNumber);

  return;
} // end of HAL_setGpioHigh() function


//! \brief      Sets the GPIO pin low
//! \details    Takes in the enumeration GPIO_Number_e and clears that GPIO
//!             pin low.
//! \param[in]  handle      The hardware abstraction layer (HAL) handle
//! \param[in]  gpioNumber  The GPIO number
static inline void HAL_setGpioLow(HAL_Handle handle,const GPIO_Number_e gpioNumber)
{
  HAL_Obj *obj = (HAL_Obj *)handle;


  // set GPIO low
  GPIO_setLow(obj->gpioHandle,gpioNumber);

  return;
} // end of HAL_setGpioLow() function


//! \brief      Toggles the GPIO pin
//! \details    Takes in the enumeration GPIO_Number_e and toggles that GPIO
//!             pin.
//! \param[in]  handle      The hardware abstraction layer (HAL) handle
//! \param[in]  gpioNumber  The GPIO number
static inline void HAL_toggleGpio(HAL_Handle handle,const GPIO_Number_e gpioNumber)
{
  HAL_Obj *obj = (HAL_Obj *)handle;


  // set GPIO high
  GPIO_toggle(obj->gpioHandle,gpioNumber);

  return;
} // end of HAL_setGpioHigh() function


//! \brief      Reads the specified GPIO pin
//! \details    Takes in the enumeration GPIO_Number_e and reads that GPIO
//! \param[in]  handle      The hardware abstraction layer (HAL) handle
//! \param[in]  gpioNumber  The GPIO number
static inline bool HAL_readGpio(HAL_Handle handle,const GPIO_Number_e gpioNumber)
{
  HAL_Obj *obj = (HAL_Obj *)handle;

  // read GPIO
  return(GPIO_read(obj->gpioHandle,gpioNumber));
} // end of HAL_readGpio() function


//! \brief     Sets up the GPIO (General Purpose I/O) pins
//! \param[in] handle  The hardware abstraction layer (HAL) handle
extern void HAL_setupGpios(HAL_Handle handle);


// ============================================================================

#ifdef __cplusplus
}
#endif // extern "C"

//! @} // end of HAL_GPIO

#endif /* _HAL_GPIO_H_ */
