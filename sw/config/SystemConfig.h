// ================================================================================================
//! \file       SystemConfig.h
//! \brief      
//! \author     sunyanjun
//! \version    1.0.0
//! \date       2017��4��12��
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

//! \brief ����ϵͳʱ��, MHz
#define HAL_SYSTEM_FREQ_MHz                 (90.0)

//! \brief ����ϵͳʱ��Ƶ��, MHz
#define HAL_LSPCLK_FREQ_MHz                 (90.0L/4.0L)

//! \brief ��ѭ�����ڣ���λus
#define HAL_MAINLOOP_PRD_us                 (1000.0)//(2000.0)
#define HAL_MAINLOOP_PRD_ms                 (HAL_MAINLOOP_PRD_us/1000)

//! \breif �����ȼ�����ѭ�����ڣ���λus
#define HAL_LOWLOOP_PRD_us                  (10000.0)

//! \brief ��ʼPWM�����趨ֵ����λus��
//! \brief ��ֵ��Χ[1000.0,20.0]����ӦPWMƵ��[1kHz,50kHZ]
//#define HAL_PWM_PERIOD_us                   (100.0)
#define HAL_PWM_PERIOD_us                   (200.0)

#if MOTOR_ID == 0x02 || MOTOR_ID == 0x04 || MOTOR_ID == 0x08 || MOTOR_ID == 0x10
//! \brief PWM����������ʱ�䣬��λus
#define HAL_PWM_DBRED_us                    (4.0)
//! \brief PWM�½�������ʱ�䣬��λus
#define HAL_PWM_DBFED_us                    (4.0)
#else
//! \brief PWM����������ʱ�䣬��λus
#define HAL_PWM_DBRED_us                    (3.0)
//! \brief PWM�½�������ʱ�䣬��λus
#define HAL_PWM_DBFED_us                    (3.0)
#endif

//! \brief PWM�жϲ���Ƶ�ʣ���λPWM���ڣ�������ֵ��1,2,3��
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
