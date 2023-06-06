// ================================================================================================
//! \file       lpf.h
//! \brief      
//! \author     sunyanjun
//! \version    1.0.0
//! \date       2017年4月25日
//! \copyright  SANTROLL.
// ================================================================================================

#ifndef _LPF_H_
#define _LPF_H_

//! @defgroup LPF LPF
//! @{

#ifdef __cplusplus
extern "C" {
#endif
// ================================================================================================
// the defines

//! \brief         无误差跟踪一阶低通滤波器宏实现
//! \param[in] In  滤波器输入
//! \param[in] Out 滤波器输出
//! \param[in] Tr  滤波时间常数
//! \param[in] T   滤波器执行周期
//! \param[in] K   K= T/Tr,滤波系数
#define Macro_LPF(In, Out, K)	{Out += K * (In - Out);}

// ================================================================================================
#ifdef __cplusplus
}
#endif // extern "C"

//! @} // end of LPF

#endif // end of _LPF_H_
