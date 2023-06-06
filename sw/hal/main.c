// ================================================================================================
//! \file       main.c
//! \brief      main functions.
//! \author     sunyanjun
//! \version    1.0
//! \date       2017.03.21
//! \copyright  SANTROLL

// ================================================================================================
// the includes

#include"sw/config/config.h"

// ================================================================================================
// the globals

HAL_Obj      hal;
HAL_Handle   halHandle;
PWM_PARM_OBJ PwmsParm = PWM_PARM_OBJ_DEFAULTS;
float        MainLoopUsage = 0;
float        MainISR_Usage = 0;


// ================================================================================================
// the functions

void main()
{
	// Only used if running from FLASH
	#ifdef FLASH
	memCopy((uint16_t *)&RamfuncsLoadStart,(uint16_t *)&RamfuncsLoadEnd,(uint16_t *)&RamfuncsRunStart);
	#endif

	// initialize the hardware abstraction layer
	halHandle = HAL_init(&hal,sizeof(hal));

	// set the hardware abstraction layer parameters
	HAL_setParams();

	// enable the PWM Power
	HAL_Pwm_BUF1_En(halHandle);
	HAL_Pwm_BUF2_En(halHandle);
	HAL_Pwm_POWER_En(halHandle);

	// global Initialization
	MainInit();

	// enable debug interrupts
	HAL_enableDebugInt(halHandle);

	// enable the ADC interrupts
	HAL_enableAdcInts(halHandle);

	// enable global interrupts
	HAL_enableGlobalInts(halHandle);

	// Enable the PWM
	HAL_Pwm_ShutDown_Dis(halHandle);
	HAL_enablePwm(halHandle);

	for(;;)
	{
		Main_Loop();

		//! 主循环负载率计算  cosf sqrtf sinf
		MainLoopUsage = (float)(TIMER_getPeriod(halHandle->timerHandle[1]) - TIMER_getCount(halHandle->timerHandle[1]))
				       /(float)TIMER_getPeriod(halHandle->timerHandle[0]);

		//! 主循环定时
		while(TIMER_getStatus(halHandle->timerHandle[0]) == TIMER_Status_CntIsNotZero){}
		TIMER_clearFlag(halHandle->timerHandle[0]);
		TIMER_reload(halHandle->timerHandle[0]);
		TIMER_reload(halHandle->timerHandle[1]);
	}
}



#ifdef FLASH
#pragma CODE_SECTION(ADC_ISR,"ramfuncs");
#endif /* FLASH */

interrupt void ADC_ISR(void)
{
	//! acknowledge the ADC interrupt
	HAL_acqAdcInt(halHandle,ADC_IntNumber_1);

	TIMER_reload(halHandle->timerHandle[2]);

	Main_ISR();

	//! 中断负载率计算
#if Single_or_Double == 1
    // 发波单更新
    MainISR_Usage = (float)(TIMER_getPeriod(halHandle->timerHandle[2]) - TIMER_getCount(halHandle->timerHandle[2]))
                   /(HAL_SYSTEM_FREQ_MHz*PwmsParm.Prd);
    PMSM_Param.DualRefresh = 0;
#elif Single_or_Double == 2
    // 发波双更新
    MainISR_Usage = (float)(TIMER_getPeriod(halHandle->timerHandle[2]) - TIMER_getCount(halHandle->timerHandle[2]))
                   /(HAL_SYSTEM_FREQ_MHz*PwmsParm.Prd / 2.0);
    PMSM_Param.DualRefresh = 1;
#elif Single_or_Double == 3
    // 发波二分之一更新
    MainISR_Usage = (float)(TIMER_getPeriod(halHandle->timerHandle[2]) - TIMER_getCount(halHandle->timerHandle[2]))
                   /(HAL_SYSTEM_FREQ_MHz*PwmsParm.Prd * 2);
#endif
	return;
}

// ================================================================================================
// end of main.c
