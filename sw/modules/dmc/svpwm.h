// ================================================================================================
//! \file       svpwm.h
//! \brief      Contains public interface to various functions related to the SVPWMCal module
//! \author     lining
//! \version    1.0.0
//! \date       2017��3��31��
//! \copyright  SANTROLL.
// ================================================================================================

#ifndef _SVPWM_H_
#define _SVPWM_H_

//! @defgroup SVPWM SVPWM
//! @{

#ifdef __cplusplus
extern "C" {
#endif
// ================================================================================================


// ================================================================================================
// the includes


// ================================================================================================
// the typedefs

typedef enum
{
	SVPWM_SEG5 = 0,
	SVPWM_SEG7 = 1
}SVPWM_CONFIG_e;


typedef struct
{
	uint32_t SEG57;  //!< [in]   �߶�ʽ/���ʽ���ã������б�SVPWM_CONFIG_e
	float Alpha;     //!< [in]   alpha����ۻ���ѹ�����۵�ѹ��ֵΪUdc/sqrt(3)
	float Beta;      //!< [in]   beta����ۻ���ѹ�����۵�ѹ��ֵΪUdc/sqrt(3)
	float Ta;        //!< [out]  a���ѹ����ռ�ձȣ���ΧΪ0~1����Ӧ�ײ�����Ϊ cnt���ӵ�cmpAʱ setvalue
	float Tb;        //!< [out]  b���ѹ����ռ�ձȣ���ΧΪ0~1����Ӧ�ײ�����Ϊ cnt���ӵ�cmpAʱ setvalue
	float Tc;        //!< [out]  c���ѹ����ռ�ձȣ���ΧΪ0~1����Ӧ�ײ�����Ϊ cnt���ӵ�cmpAʱ setvalue

    void (*Cal)();  //!< Pointer to the Cal function
}SVPWM_OBJ;



// ================================================================================================
// the defines

#define SVPWM_OBJ_DEFAULTS { 0,0,0,0,0,0,\
                             (void (*)(long))SVPWMCal}

// ================================================================================================
// the globals


// ================================================================================================
// the function prototypes

//! \brief     SVPWM Calculate Function
//! \param[in] sv        Handle to SVPMW object
extern void SVPWMCal(SVPWM_OBJ* sv);


// ================================================================================================
#ifdef __cplusplus
}
#endif // extern "C"

//! @} // end of SVPWM

#endif // end of _SVPWM_H_
