//! \file       hal_can.h
//! \brief      Contains public interface to various functions related to the CAN module
//! \author     sunyanjun
//! \version    1.0
//! \date       2017.03.21
//! \copyright  SANTROLL

#ifndef _HAL_CAN_H_
#define _HAL_CAN_H_

//! @defgroup HAL_CAN HAL_CAN
//! @{

#ifdef __cplusplus
extern "C" {
#endif

// ============================================================================
// the includes

#include "sw/drivers/can/src/32b/f28x/f2806x/can.h"


// ============================================================================
// the defines

//! \brief Defines the base address of the CAN registers
#define CAN_BASE_ADDR           (0x00006000)

//! \brief 目前支持的波特率：125000Hz，250000Hz，500000Hz，1000000Hz.
#define ECANA_BAUDRATE          (500000.0L)//(250000.0L)    //!< Bus Speed,Unit: bps.


//! \datils <pre>
//! 位段的TQ数目约束如下：
//! ECAN Bit-Timing Configuration;
//! TQ_NUM = SYNC_SEG + PROP_SEG + PHASE_SEG1 + PHASE_SEG2;
//! IPT <= 2: Information processing time;
//! 8 <= TQ_NUM <= 25;
//! IPT <= (PROP_SEG + PHASE_SEG1) <= 16;
//! IPT <= (PHASE_SEG2) <= 8;
//! PHASE_SEG2 <= (PROP_SEG + PHASE_SEG1);
//! 1 <= SJW_SEG <= Min(4, PHASE_SEG2);
//! </pre>
#define ECANA_TQ_NUM			(15)		//!< Bit time, Unit: TQ.
#define ECANA_SYNC_SEG			(1)			//!< Sync Seg, Constant, 1 TQ by default.
#define ECANA_PROP_SEG          (4)			//!< Prop Seg,
#define ECANA_PHASE_SEG1		(6)			//!< Phase1 Seg,
#define ECANA_PHASE_SEG2        (4)			//!< Phase2 Seg,
#define ECANA_SJW_SEG           (1)        	//!< Resynchronization jump width


// ============================================================================
// the typedefs


typedef enum
{
	MSGID_AME_DIS = (0L<<30),   //!< Acceptance mask disable
	MSGID_AME_EN  = (1L<<30)    //!< Acceptance mask enable
}MSGID_AME_e;


typedef enum
{
	MSGID_IDE_ST = (0L<<31),    //!< Standard Frame
	MSGID_IDE_EX = (1L<<31)     //!< Extended Frame
}MSGID_IDE_e;


typedef enum
{
	CANMD_Tx = 0L,              //!< Box used for transmitting message
	CANMD_Rx = 1L               //!< Box Used for receiving message
}ECAN_CANMD_e;


typedef enum
{
	CANGAM_LAMI_DIS = (0L<<30),  //!< Standard or extended frames can be received
	CANGAM_LAMI_EN  = (1L<<30)   //!< Standard and extended frames can be received
}CANGAM_LAMI_e;


typedef enum
{
	ECAN_CANTIOC_TXFUNC_RSVD  = 0,
	ECAN_CANTIOC_TXFUNC_CANTX = 1  //!< CANTx Pin Enabled
}ECAN_CANTIOC_TXFUNC_e;


typedef enum
{
	ECAN_CANTIOC_RXFUNC_RSVD  = 0,
	ECAN_CANTIOC_RXFUNC_CANRX = 1  //!< CANRx Pin Enabled
}ECAN_CANRIOC_RXFUNC_e;


typedef enum
{
	ECAN_CANBTC_SAM_1 = 0,  //!< The CAN module samples three times,(Make sure that CANBTC_BRP >= 3)
	ECAN_CANBTC_SAM_3 = 1   //!< The CAN module samples only once at the sampling point
}ECAN_CANBTC_SAM_e;


typedef enum
{
	ECAN_CANMC_SCB_16 = 0,   //!< 0 - 15 CANBox Enabled
	ECAN_CANMC_SCB_32 = 1    //!< 0 - 31 CANBox Enabled,Time-stamping Enabled
}ECAN_CANMC_SCB_e;


typedef enum
{
	ECAN_CANMC_CCR_Normal = 0, //!< CAN module in Normal mode
	ECAN_CANMC_CCR_Config = 1  //!< CAN module in Configuration mode
}ECAN_CANMC_CCR_e;


typedef enum
{
	ECAN_CANMC_DBO_LSB = 1, //!< Least significant byte first
	ECAN_CANMC_DBO_MSB = 0  //!< Most significant byte first.
}ECAN_CANMC_DBO_e;


typedef enum
{
	ECAN_CANMC_ABO_Auto = 1, //!< Auto bus-on after 128 * 11 recessive bits
	ECAN_CANMC_ABO_CCR  = 0  //!< Bus on after CCR cleared
}ECAN_CANMC_ABO_e;


typedef struct
{
	union
	{
		struct
		{
			Uint32 MDL;
			Uint32 MDH;
		}D32;
		struct
		{
			Uint32 MD01:16;
			Uint32 MD23:16;
			Uint32 MD45:16;
			Uint32 MD67:16;
		}D16;
		struct
		{
			Uint32 MD0:8;
			Uint32 MD1:8;
			Uint32 MD2:8;
			Uint32 MD3:8;
			Uint32 MD4:8;
			Uint32 MD5:8;
			Uint32 MD6:8;
			Uint32 MD7:8;
		}D8;
	}Data;
}ECANMSG;

//! \brief ECANMSG initial Values
//#define ECANMSG_DEFAULTS {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}}  // 修改
#define ECANMSG_DEFAULTS {{0,0}}  // mark 修改

//!< \brief CAN Box configuration Parameter
typedef struct
{
	  uint32_t      Num;     //!< CAN box Number[0,31]
	  uint32_t      ID;      //!< CAN box Identifier
	  uint32_t      Mask;    //!< CAN box Local-Acceptance-Mask
	  uint16_t      DLC;     //!< Transmit-priority level[0,8]
	  uint16_t      TPL;     //!< Data-length[0,31]
	  ECAN_CANMD_e  MD;      //!< CAN box Direction,Send or Receive
	  MSGID_IDE_e   IDE;     //!< ID format, Standard or Extended
	  MSGID_AME_e   AME;     //!< Acceptance mask Enable or Disable
	  CANGAM_LAMI_e LAMI;    //!< CAN box Local-acceptance-mask identifier extension bit
}ECAN_BOX_PARAM;


// ============================================================================
// the function prototypes


//! \brief Initializes the CAN object
//! \param[in] pMemory          Memory pointer for new object
//! \param[in] numBytes         Object size
//! \return                     CAN Handle
extern CAN_Handle CAN_init(void *pMemory,const size_t numBytes);


//! \brief     Initialize the CAN peripheral
//! \param[in] CANHandle        Handle to CAN object
extern void HAL_CAN_init(CAN_Handle Handle);


//! \brief     Sets up the CAN peripheral
//! \param[in] CANHandle        Handle to CAN object
extern void HAL_setupCAN(CAN_Handle Handle);


//! \brief     Sets up the CAN peripheral
extern void HAL_SetCANBox(CAN_Handle Handle, ECAN_BOX_PARAM* Para);


//! \brief    Trasmit a msg via Box: BoxNum
extern void ECanaBoxTxMsg(CAN_Handle Handle,ECANMSG* ECanMsg,Uint16 BoxNum);


//! \brief    Receive a msg via Box: BoxNum
extern void ECanaBoxRxMsg(CAN_Handle Handle,ECANMSG* ECanMsg,Uint16 BoxNum);


//! \return  Tx_state: 0 ->Idle, 1 -> A Msg Transmitting;
static inline uint32_t ECanaBoxTxBsy(CAN_Handle Handle, uint16_t BoxNum)
{
	return ((Handle->ECanaRegs.CANTRS.all & (0x01L << BoxNum)) > 0);
}


//! \return  Rx_state: 0 ->Idle, 1 -> A Msg pending.
static inline uint32_t ECanaBoxRxRdy(CAN_Handle Handle, uint16_t BoxNum)
{
	return ((Handle->ECanaRegs.CANRMP.all & (0x01L << BoxNum)) > 0);
}

// ============================================================================

#ifdef __cplusplus
}
#endif // extern "C"

//! @} // end of HAL_CAN

#endif /* _HAL_CAN_H_ */
