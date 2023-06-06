// ================================================================================================
//! \file       SystemConfig.h
//! \brief      
//! \author     sunyanjun
//! \version    1.0.0
//! \date       2017年4月12日
//! \copyright  SANTROLL.
// ================================================================================================

#ifndef _SYSTEMCONFIG_H_
#define _SYSTEMCONFIG_H_

//! @defgroup SYSTEMCONFIG
//! @{

#ifdef __cplusplus
extern "C" {
#endif
// ================================================================================================
// the includes

// ================================================================================================
// the defines

//! \brief 高速系统时钟, MHz
#define HAL_SYSTEM_FREQ_MHz                 (90.0)

//! \brief 低速系统时钟频率, MHz
#define HAL_LSPCLK_FREQ_MHz                 (90.0L/4.0L)

//! \brief 主循环周期，单位us
#define HAL_MAINLOOP_PRD_us                 (1000.0)//(2000.0)
#define HAL_MAINLOOP_PRD_ms                 (HAL_MAINLOOP_PRD_us/1000)

//! \breif 低优先级任务循环周期，单位us
#define HAL_LOWLOOP_PRD_us                  (10000.0)

//! \brief 初始PWM周期设定值，单位us，
//! \brief 数值范围[1000.0,20.0]，对应PWM频率[1kHz,50kHZ]
//#define HAL_PWM_PERIOD_us                   (100.0)
#define HAL_PWM_PERIOD_us                   (200.0)

#if MOTOR_ID == 0x02 || MOTOR_ID == 0x04 || MOTOR_ID == 0x08 || MOTOR_ID == 0x10
//! \brief PWM上升沿死区时间，单位us
#define HAL_PWM_DBRED_us                    (4.0)
//! \brief PWM下降沿死区时间，单位us
#define HAL_PWM_DBFED_us                    (4.0)
#else
//! \brief PWM上升沿死区时间，单位us
#define HAL_PWM_DBRED_us                    (3.0)
//! \brief PWM下降沿死区时间，单位us
#define HAL_PWM_DBFED_us                    (3.0)
#endif

//! \brief PWM中断产生频率，单位PWM周期，可用数值【1,2,3】
#if Single_or_Double == 1||Single_or_Double == 2
    #define HAL_PWM_TICKS_PER_ISR_TICK          (1)
#elif Single_or_Double == 3
    #define HAL_PWM_TICKS_PER_ISR_TICK          (2)
#endif

// ================================================================================================
// the typedefs


// ================================================================================================
// the globals


// ================================================================================================
// the function prototypes




// ================================================================================================
#ifdef __cplusplus
}
#endif // extern "C"

//! @} // end of SYSTEMCONFIG

#endif // end of _SYSTEMCONFIG_H_
