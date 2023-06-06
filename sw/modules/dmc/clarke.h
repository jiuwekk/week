// ================================================================================================
//! \file       clarke.h
//! \brief      
//! \author     jiangkun
//! \version    1.0.0
//! \date       2017Äê4ÔÂ5ÈÕ
//! \copyright  SANTROLL.
// ================================================================================================

#ifndef _CLARKE_H_
#define _CLARKE_H_

//! @defgroup CLARKE CLARKE
//! @{

#ifdef __cplusplus
extern "C" {
#endif
// ================================================================================================


// ================================================================================================
// the includes


// ================================================================================================
// the defines

#define CLARKE_OBJ_DEFAULTS { 0, \
                              0, \
                              0, \
                              0, \
                              (void (*)(long))clarke_calc }

// ================================================================================================
// the typedefs

typedef struct {
                  float  As;            //!< [in]  phase-a stator variable
                  float  Bs;            //!< [in]  phase-b stator variable
                  float  Alpha;         //!< [out] stationary d-axis stator variable
                  float  Beta;          //!< [out] stationary q-axis stator variable
                  void  (*calc)();      //!< Pointer to calculation function
                 } CLARKE_OBJ;

typedef CLARKE_OBJ *CLARKE_handle;
// ================================================================================================
// the globals


// ================================================================================================
// the function prototypes

extern void clarke_calc(CLARKE_handle v);

// ================================================================================================
#ifdef __cplusplus
}
#endif // extern "C"

//! @} // end of CLARKE

#endif // end of _CLARKE_H_
