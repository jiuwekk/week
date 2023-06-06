// ================================================================================================
//! \file       PICal.h
//! \brief      Contains public interface to various functions related to the PICal module
//! \author     lining
//! \version    1.0.0
//! \date       2017��4��5��
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
	float Kp;             //!< [in]     ����ϵ��
	float Ki;             //!< [in]     ����ϵ��
	float Ref;            //!< [in]     ����ֵ
	float Fbk;            //!< [in]     ����ֵ
	float StsIn;          //!< [in]     ��һ��PI����״̬��־λ��0��δ���ͣ�   1������

	float Out;            //!< [out]    PI���
	float Ui;             //!< [out]    �������ۼ�
	float StsOut;         //!< [out]    ����PI����״̬��־λ��0��δ���ͣ�   1������

	float Kcor;           //!< [inner]  ������ϵ��
	float Err;            //!< [inner]  �������
	float Max;            //!< [inner]  ����޷����ֵ
	float Min;            //!< [inner]  �����޷����ֵ

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
