//! \file       hal.c
//! \brief      Contains various functions related to the HAL object
//! \author     sunyanjun
//! \version    1.0
//! \date       2017.03.21
//! \copyright  SANTROLL

// ============================================================================
// the includes
#include"sw/config/config.h"

// ============================================================================
// the defines


#ifdef FLASH
#pragma CODE_SECTION(HAL_setupFlash,"ramfuncs");
#endif /* FLASH */


// ============================================================================
// the globals


// ============================================================================
// the functions


void HAL_cal(HAL_Handle handle)
{
  HAL_Obj *obj = (HAL_Obj *)handle;


  // enable the ADC clock
  CLK_enableAdcClock(obj->clkHandle);


  // Run the Device_cal() function
  // This function copies the ADC and oscillator calibration values from TI reserved
  // OTP into the appropriate trim registers
  // This boot ROM automatically calls this function to calibrate the interal 
  // oscillators and ADC with device specific calibration data.
  // If the boot ROM is bypassed by Code Composer Studio during the development process,
  // then the calibration must be initialized by the application
  ENABLE_PROTECTED_REGISTER_WRITE_MODE;
  (*Device_cal)();
  DISABLE_PROTECTED_REGISTER_WRITE_MODE;

  // run offsets calibration in user's memory
  HAL_AdcOffsetSelfCal(handle);

  // run oscillator compensation
  HAL_OscTempComp(handle);

  // disable the ADC clock
  CLK_disableAdcClock(obj->clkHandle);

  return;
} // end of HAL_cal() function


HAL_Handle HAL_init(void *pMemory,const size_t numBytes)
{
  HAL_Handle handle;
  HAL_Obj *obj;


  if(numBytes < sizeof(HAL_Obj))
    return((HAL_Handle)NULL);


  // assign the handle
  handle = (HAL_Handle)pMemory;


  // assign the object
  obj = (HAL_Obj *)handle;


  // initialize the watchdog driver
  obj->wdogHandle = WDOG_init((void *)WDOG_BASE_ADDR,sizeof(WDOG_Obj));


  // disable watchdog
  HAL_disableWdog(handle);


  // initialize the ADC
  obj->adcHandle = ADC_init((void *)ADC_BASE_ADDR,sizeof(ADC_Obj));


  // initialize the clock handle
  obj->clkHandle = CLK_init((void *)CLK_BASE_ADDR,sizeof(CLK_Obj));


  // initialize the CPU handle
  obj->cpuHandle = CPU_init(&cpu,sizeof(cpu));


  // initialize the FLASH handle
  obj->flashHandle = FLASH_init((void *)FLASH_BASE_ADDR,sizeof(FLASH_Obj));


  // initialize the GPIO handle
  obj->gpioHandle = GPIO_init((void *)GPIO_BASE_ADDR,sizeof(GPIO_Obj));

  // initialize the oscillator handle
  obj->oscHandle = OSC_init((void *)OSC_BASE_ADDR,sizeof(OSC_Obj));


  // initialize the PIE handle
  obj->pieHandle = PIE_init((void *)PIE_BASE_ADDR,sizeof(PIE_Obj));


  // initialize the PLL handle
  obj->pllHandle = PLL_init((void *)PLL_BASE_ADDR,sizeof(PLL_Obj));


  // initialize the SPI handles
  obj->spiAHandle = SPI_init((void *)SPIA_BASE_ADDR,sizeof(SPI_Obj));
  obj->spiBHandle = SPI_init((void *)SPIB_BASE_ADDR,sizeof(SPI_Obj));


  // initialize PWM handles
  obj->pwmHandle[0] = PWM_init((void *)PWM_ePWM1_BASE_ADDR,sizeof(PWM_Obj));
  obj->pwmHandle[1] = PWM_init((void *)PWM_ePWM2_BASE_ADDR,sizeof(PWM_Obj));
  obj->pwmHandle[2] = PWM_init((void *)PWM_ePWM3_BASE_ADDR,sizeof(PWM_Obj));
#if EVCBD_ID == 0x08 || EVCBD_ID == 0x0D
  obj->pwmHandle[7] = PWM_init((void *)PWM_ePWM8_BASE_ADDR,sizeof(PWM_Obj));
#elif EVCBD_ID == 0x09
  obj->pwmHandle[3] = PWM_init((void *)PWM_ePWM4_BASE_ADDR,sizeof(PWM_Obj));
  obj->pwmHandle[4] = PWM_init((void *)PWM_ePWM5_BASE_ADDR,sizeof(PWM_Obj));
#endif


  // initialize power handle
  obj->pwrHandle = PWR_init((void *)PWR_BASE_ADDR,sizeof(PWR_Obj));


  // initialize timer handles
  obj->timerHandle[0] = TIMER_init((void *)TIMER0_BASE_ADDR,sizeof(TIMER_Obj));
  obj->timerHandle[1] = TIMER_init((void *)TIMER1_BASE_ADDR,sizeof(TIMER_Obj));
  obj->timerHandle[2] = TIMER_init((void *)TIMER2_BASE_ADDR,sizeof(TIMER_Obj));


  // initialize QEP driver
  obj->qepHandle[0] = QEP_init((void*)QEP1_BASE_ADDR,sizeof(QEP_Obj));
  obj->qepHandle[1] = QEP_init((void*)QEP2_BASE_ADDR,sizeof(QEP_Obj));

  // initialize CAN Handle
  obj->canAHandle = CAN_init((void*)CAN_BASE_ADDR,sizeof(CAN_Obj));

  // initialize SCI Handle
  obj->sciHandle[SCI_MODULE_A] = SCI_init((void*)SCIA_BASE_ADDR,sizeof(SCI_Obj));
  obj->sciHandle[SCI_MODULE_B] = SCI_init((void*)SCIB_BASE_ADDR,sizeof(SCI_Obj));

  // initialize I2C Handle
  obj->i2cHandle = I2C_init((void*)I2CA_BASE_ADDR,sizeof(I2C_Obj));

  return(handle);
} // end of HAL_init() function


void HAL_setParams()
{
	// disable global interrupts
	CPU_disableGlobalInts(halHandle->cpuHandle);

	// disable cpu interrupts
	CPU_disableInts(halHandle->cpuHandle);

	// clear cpu interrupt flags
	CPU_clearIntFlags(halHandle->cpuHandle);

	// setup the clocks
	HAL_setupClks(halHandle);

	// Setup the PLL
	HAL_setupPll(halHandle,PLL_ClkFreq_90_MHz);

	// setup the PIE
	HAL_setupPie(halHandle);

	// run the device calibration
	HAL_cal(halHandle);

	// setup the peripheral clocks
	HAL_setupPeripheralClks(halHandle);

	// setup the timers
	HAL_setupTimers(halHandle, (float_t)HAL_SYSTEM_FREQ_MHz);

	// setup the flash
	HAL_setupFlash(halHandle);

	// setup the ADCs
	HAL_setupAdcs(halHandle);

	// setup TZ faults
	HAL_setupFaults(halHandle);

	// setup the PWMs
	HAL_setupPwms(halHandle,HAL_PWM_TICKS_PER_ISR_TICK);

	// setup the GPIOs
	HAL_setupGpios(halHandle);

	// setup the QEP
	HAL_setupQEP(M1_QEP_HANDLE);

	// setup the spi
	HAL_setupSpi(M1_SPI_HANDLE);

	// setup the cana
	HAL_setupCAN(M1_CAN_HANDLE);

	// setup the SCI
	HAL_setupSci(M1_SCI_HANDLE);

	// setup the i2c
	HAL_setupI2C(M1_I2C_HANDLE);

	// initialize the interrupt vector table
	HAL_initIntVectorTable(halHandle);

 return;
} // end of HAL_setParams() function


// end of file
