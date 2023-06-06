//! \file       hal_obj.h
//! \brief      Defines the structures for the HAL object
//! \author     sunyanjun
//! \version    1.0
//! \date       2017.03.21
//! \copyright  SANTROLL

#ifndef _HAL_OBJ_H_
#define _HAL_OBJ_H_

//! @defgroup HAL_OBJ HAL_OBJ
//! @{

#ifdef __cplusplus
extern "C" {
#endif

// ============================================================================
// the includes

// drivers
#include "sw/drivers/adc/src/32b/f28x/f2806x/adc.h"
#include "sw/drivers/clk/src/32b/f28x/f2806x/clk.h"
#include "sw/drivers/cpu/src/32b/f28x/f2806x/cpu.h"
#include "sw/drivers/flash/src/32b/f28x/f2806x/flash.h"
#include "sw/drivers/gpio/src/32b/f28x/f2806x/gpio.h"
#include "sw/drivers/osc/src/32b/f28x/f2806x/osc.h"
#include "sw/drivers/pie/src/32b/f28x/f2806x/pie.h"
#include "sw/drivers/pll/src/32b/f28x/f2806x/pll.h"
#include "sw/drivers/pwm/src/32b/f28x/f2806x/pwm.h"
#include "sw/drivers/pwmdac/src/32b/f28x/f2806x/pwmdac.h"
#include "sw/drivers/pwr/src/32b/f28x/f2806x/pwr.h"
#include "sw/drivers/spi/src/32b/f28x/f2806x/spi.h"
#include "sw/drivers/timer/src/32b/f28x/f2806x/timer.h"
#include "sw/drivers/wdog/src/32b/f28x/f2806x/wdog.h"
#include "sw/drivers/qep/src/32b/f28x/f2806x/qep.h"
#include "sw/drivers/can/src/32b/f28x/f2806x/can.h"
#include "sw/drivers/sci/src/32b/f28x/f2806x/sci.h"
#include "sw/drivers/i2c/src/32b/f28x/f2806x/i2c.h"


// ============================================================================
// the defines

#define Delay_us(A) usDelay((((long double) A * HAL_SYSTEM_FREQ_MHz) - 9.0L) / 5.0L)
#define fsatf(A, Pos, Neg)  (__fmax(((__fmin((A),(Pos)))),(Neg)))


// ============================================================================
// the typedefs

//! \brief      Defines the hardware abstraction layer (HAL) data
//! \details    The HAL object contains all handles to peripherals.  When accessing a
//!             peripheral on a processor, use a HAL function along with the HAL handle
//!             for that processor to access its peripherals.
//!
#if EVCBD_ID == 0x08 || EVCBD_ID == 0x0D
typedef struct _HAL_Obj_
{
  ADC_Handle    adcHandle;        //!< the ADC handle
  CLK_Handle    clkHandle;        //!< the clock handle
  CPU_Handle    cpuHandle;        //!< the CPU handle
  FLASH_Handle  flashHandle;      //!< the flash handle
  GPIO_Handle   gpioHandle;       //!< the GPIO handle
  OSC_Handle    oscHandle;        //!< the oscillator handle
  PIE_Handle    pieHandle;        //!< the PIE handle
  PLL_Handle    pllHandle;        //!< the PLL handle
  PWM_Handle    pwmHandle[8];     //!< the PWM handles
  PWR_Handle    pwrHandle;        //!< the power handle
  TIMER_Handle  timerHandle[3];   //!< the timer handles
  WDOG_Handle   wdogHandle;       //!< the watchdog handle
  SPI_Handle    spiAHandle;       //!< the SPI handle
  SPI_Handle    spiBHandle;       //!< the SPI handle
  QEP_Handle    qepHandle[2];     //!< the QEP handle
  CAN_Handle    canAHandle;       //!< The CAN Handle
  SCI_Handle    sciHandle[2];     //!< The SCI Handle
  I2C_Handle    i2cHandle;        //!< The I2C Handle
} HAL_Obj;
#elif EVCBD_ID == 0x09
typedef struct _HAL_Obj_
{
  ADC_Handle    adcHandle;        //!< the ADC handle
  CLK_Handle    clkHandle;        //!< the clock handle
  CPU_Handle    cpuHandle;        //!< the CPU handle
  FLASH_Handle  flashHandle;      //!< the flash handle
  GPIO_Handle   gpioHandle;       //!< the GPIO handle
  OSC_Handle    oscHandle;        //!< the oscillator handle
  PIE_Handle    pieHandle;        //!< the PIE handle
  PLL_Handle    pllHandle;        //!< the PLL handle
  PWM_Handle    pwmHandle[5];     //!< the PWM handles
  PWR_Handle    pwrHandle;        //!< the power handle
  TIMER_Handle  timerHandle[3];   //!< the timer handles
  WDOG_Handle   wdogHandle;       //!< the watchdog handle
  SPI_Handle    spiAHandle;       //!< the SPI handle
  SPI_Handle    spiBHandle;       //!< the SPI handle
  QEP_Handle    qepHandle[2];     //!< the QEP handle
  CAN_Handle    canAHandle;       //!< The CAN Handle
  SCI_Handle    sciHandle[2];     //!< The SCI Handle
  I2C_Handle    i2cHandle;        //!< The I2C Handle
} HAL_Obj;
#else
typedef struct _HAL_Obj_
{
  ADC_Handle    adcHandle;        //!< the ADC handle
  CLK_Handle    clkHandle;        //!< the clock handle
  CPU_Handle    cpuHandle;        //!< the CPU handle
  FLASH_Handle  flashHandle;      //!< the flash handle
  GPIO_Handle   gpioHandle;       //!< the GPIO handle
  OSC_Handle    oscHandle;        //!< the oscillator handle
  PIE_Handle    pieHandle;        //!< the PIE handle
  PLL_Handle    pllHandle;        //!< the PLL handle
  PWM_Handle    pwmHandle[3];     //!< the PWM handles
  PWR_Handle    pwrHandle;        //!< the power handle
  TIMER_Handle  timerHandle[3];   //!< the timer handles
  WDOG_Handle   wdogHandle;       //!< the watchdog handle
  SPI_Handle    spiAHandle;       //!< the SPI handle
  SPI_Handle    spiBHandle;       //!< the SPI handle
  QEP_Handle    qepHandle[2];     //!< the QEP handle
  CAN_Handle    canAHandle;       //!< The CAN Handle
  SCI_Handle    sciHandle[2];     //!< The SCI Handle
  I2C_Handle    i2cHandle;        //!< The I2C Handle
} HAL_Obj;
#endif

//! \brief      Defines the HAL handle
//! \details    The HAL handle is a pointer to a HAL object.  In all HAL functions
//!             the HAL handle is passed so that the function knows what peripherals
//!             are to be accessed.
//!
typedef struct _HAL_Obj_ *HAL_Handle;


// ============================================================================
// the globals


// ============================================================================

#ifdef __cplusplus
}
#endif // extern "C"

//! @} // end of HAL_OBJ

#endif // end of _HAL_OBJ_H_ definition

