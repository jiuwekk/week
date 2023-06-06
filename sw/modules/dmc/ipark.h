// ================================================================================================
//! \file       ipark.h
//! \brief      
//! \author     jiangkun
//! \version    1.0.0
//! \date       2017Äê4ÔÂ5ÈÕ
//! \copyright  SANTROLL.
// ================================================================================================

#ifndef _IPARK_H_
#define _IPARK_H_

//! @defgroup IPARK IPARK
//! @{

#ifdef __cplusplus
extern "C" {
#endif
// ================================================================================================


// ================================================================================================
// the includes


// ================================================================================================
// the defines
#define IPARK_OBJ_DEFAULTS {  0, \
                              0, \
                              0, \
                              0, \
                              0, \
                              (void (*)(long))ipark_calc}

// ================================================================================================
// the typedefs

typedef struct {
                  float  Angle;             //!< [in]  rotating angle (pu)
                  float  Ds;                //!< [in]  rotating d-axis stator variable
                  float  Qs;                //!< [in]  rotating q-axis stator variable
                  float  Alpha;             //!< [out] stationary d-axis stator variable
                  float  Beta;              //!< [out] stationary q-axis stator variable
                  void  (*calc)();          //!< Pointer to calculation function
               }IPARK_OBJ;
typedef IPARK_OBJ *IPARK_handle;
// ================================================================================================
// the globals


// ================================================================================================
// the function prototypes

extern void ipark_calc(IPARK_handle v);



// ================================================================================================
#ifdef __cplusplus
}
#endif // extern "C"

//! @} // end of IPARK

#endif // end of _IPARK_H_
