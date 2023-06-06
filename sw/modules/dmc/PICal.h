// ================================================================================================
//! \file       PICal.h
//! \brief      Contains public interface to various functions related to the PICal module
//! \author     lining
//! \version    1.0.0
//! \date       2017年4月5日
//! \copyright  SANTROLL.
// ================================================================================================

#ifndef _PICAL_H_
#define _PICAL_H_

//! @defgroup PICAL PICAL
//! @{

#ifdef __cplusplus
extern "C" {
#endif
// ================================================================================================


// ================================================================================================
// the includes


// ================================================================================================
// the defines


// ================================================================================================
// the typedefs

typedef struct
{
	float Kp;             //!< [in]     比例系数
	float Ki;             //!< [in]     积分系数
	float Ref;            //!< [in]     给定值
	float Fbk;            //!< [in]     反馈值
	float StsIn;          //!< [in]     下一级PI饱和状态标志位，0：未饱和；   1：饱和

	float Out;            //!< [out]    PI输出
	float Ui;             //!< [out]    积分项累计
	float StsOut;         //!< [out]    本级PI饱和状态标志位，0：未饱和；   1：饱和

	float Kcor;           //!< [inner]  抗饱和系数
	float Err;            //!< [inner]  跟踪误差
	float Max;            //!< [inner]  输出限幅最大值
	float Min;            //!< [inner]  输入限幅最大值

	void (*Init)();       //!< Pointer to the init function
	void (*Cal)();	      //!< Pointer to the Cal function
}PI_OBJ;
#define PI_OBJ_DEFAULTS { 0,0,0,0,0,0,0,0,0,0,-1.0,1.0,\
		                 (void (*)(long))PICalInit,\
                         (void (*)(long))PICal}

// ================================================================================================
// the globals


// ================================================================================================
// the function prototypes

//! \brief     PI Calculate
//! \param[in] v        Handle to PI object
extern void PICal(PI_OBJ* v);

//! \brief     PI Parameters Initialize
//! \param[in] v        Handle to PI object
extern void PICalInit(PI_OBJ* v);

// ================================================================================================
#ifdef __cplusplus
}
#endif // extern "C"

//! @} // end of PICAL

#endif // end of _PICAL_H_
