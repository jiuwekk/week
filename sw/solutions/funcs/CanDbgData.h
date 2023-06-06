// ================================================================================================
//! \file       CanDbgData.h
//! \brief      调试数据发送
//! \author     xjh
//! \version    1.0.0
//! \date       2019年11月04日
//! \copyright  SANTROLL.
// ================================================================================================

#ifndef _CANDBGDATA_H_
#define _CANDBGDATA_H_

//! @defgroup CANDBGDATA
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
typedef enum
{
    Debug_Idle = 0,                    /*No debug behavior*/
    Degub_Send_DQ,                     /*Send DQ axis current, voltage */
    Degub_Send_Fundata,                /*Send monitoring data*/
    Degub_Send_DQ_and_Fundata          /*Send DQ axis current, voltage and monitoring data*/
}DEBUGMODE_DEF;
// ================================================================================================
// the globals


// ================================================================================================
// the function prototypes
extern void DbgDataTx(void);


// ================================================================================================
#ifdef __cplusplus
}
#endif // extern "C"

//! @} // end of CANDBGDATA

#endif // end of _CANDBGDATA_H_
