// ================================================================================================
//! \file       svpwm.h
//! \brief      Contains public interface to various functions related to the SVPWMCal module
//! \author     lining
//! \version    1.0.0
//! \date       2017年3月31日
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
	uint32_t SEG57;  //!< [in]   七段式/五段式配置，输入列表：SVPWM_CONFIG_e
	float Alpha;     //!< [in]   alpha轴标幺化电压，标幺电压基值为Udc/sqrt(3)
	float Beta;      //!< [in]   beta轴标幺化电压，标幺电压基值为Udc/sqrt(3)
	float Ta;        //!< [out]  a相电压调制占空比，范围为0~1，对应底层配置为 cnt增加到cmpA时 setvalue
	float Tb;        //!< [out]  b相电压调制占空比，范围为0~1，对应底层配置为 cnt增加到cmpA时 setvalue
	float Tc;        //!< [out]  c相电压调制占空比，范围为0~1，对应底层配置为 cnt增加到cmpA时 setvalue

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
