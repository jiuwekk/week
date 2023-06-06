// ================================================================================================
//! \file       AngelComp.h
//! \brief
//! \author     sunyanjun
//! \version    1.0.0
//! \date       2017年5月23日
//! \copyright  SANTROLL.
// ================================================================================================

#ifndef _ANGELCOMP_H_
#define _ANGELCOMP_H_

//! @defgroup ANGELCOMP ANGELCOMP
//! @{

#ifdef __cplusplus
extern "C" {
#endif
// ================================================================================================


// ================================================================================================
// the includes


// ================================================================================================
// the defines

#define ANGELCOMP_OBJ_DEFAULTS { 0,\
                                 0,\
                                 0,\
                                 0,\
                                 0,\
                                 0,\
                                 (void (*)(uint32_t))AngelComp_Calc }

// ================================================================================================
// the typedefs
typedef struct
{
    float  Ne;             //!< 电气转速，
    float  Angel;          //!< 当前角度
    float  Delay_park;     //!< park变换延时
    float  Delay_ipark;    //!< ipark变换延时
    float  Angle_park;
    float  Angle_ipark;

    void (*Calc)();
} ANGELCOMP_OBJ;

// ================================================================================================
// the globals


// ================================================================================================
// the function prototypes

void AngelComp_Calc(ANGELCOMP_OBJ* A);

// ================================================================================================
#ifdef __cplusplus
}
#endif // extern "C"

//! @} // end of ANGELCOMP

#endif // end of _ANGELCOMP_H_
