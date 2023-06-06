// ================================================================================================
//! \file       park.h
//! \brief      
//! \author     zw
//! \version    1.0.0
//! \date       2017Äê4ÔÂ5ÈÕ
//! \copyright  SANTROLL.
// ================================================================================================

#ifndef _PARK_H_
#define _PARK_H_

//! @defgroup PARK PARK
//! @{

#ifdef __cplusplus
extern "C" {
#endif
// ================================================================================================


// ================================================================================================
// the includes


// ================================================================================================
// the defines

#define PARK_OBJ_DEFAULTS { 0,\
                            0,\
                            0,\
                            0,\
                            0,\
                            (void (*)(long))park_calc }

// ================================================================================================
// the typedefs
typedef struct {  float  Alpha;         //!< [in] stationary alpha-axis stator variable
                  float  Beta;          //!< [in] stationary beta-axis stator variable
                  float  Angle;         //!< [in] rotating angle (pu)
                  float  Ds;            //!< [out] rotating d-axis stator variable
                  float  Qs;            //!< [out] rotating q-axis stator variable
                  void  (*calc)();      //!< Pointer to calculation function
                 } PARK_OBJ;

// ================================================================================================
// the globals


// ================================================================================================
// the function prototypes

//! \brief     park calc
//! \param[in] v        Handle to PARK object
extern void park_calc(PARK_OBJ* v);


// ================================================================================================
#ifdef __cplusplus
}
#endif // extern "C"

//! @} // end of PARK

#endif // end of _PARK_H_
