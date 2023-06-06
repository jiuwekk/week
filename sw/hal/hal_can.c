//! \file       hal_can.c
//! \brief      Contains various functions related to the CAN object
//! \author     sunyanjun
//! \version    1.0
//! \date       2017.03.21
//! \copyright  SANTROLL


CAN_Handle CAN_init(void *pMemory,const size_t numBytes)
{
  if(numBytes < sizeof(CAN_Obj))
    return((CAN_Handle)NULL);

  return((CAN_Handle)pMemory);
} // end of CAN_init() function



// BOX 0-1:上位机一收一发
// BOX 2-5:MCU状态反馈,发送
// BOX 6-7:VCU指令，接收
// BOX 8-9:DBG数据，发送
void HAL_setupCAN(CAN_Handle Handle)
{
	ECAN_BOX_PARAM P;

	HAL_CAN_init(Handle);
    P.IDE = MSGID_IDE_EX; P.AME = MSGID_AME_EN; P.LAMI = CANGAM_LAMI_EN;
    P.Num = 0x00; P.ID = UPCOM_RXID; P.Mask = 0x00000000; P.DLC = 8; P.TPL = 0; P.MD = CANMD_Rx;  HAL_SetCANBox(Handle, &P);
    P.Num = 0x01; P.ID = UPCOM_TXID; P.Mask = 0x00000000; P.DLC = 8; P.TPL = 0; P.MD = CANMD_Tx;  HAL_SetCANBox(Handle, &P);
    P.Num = 0x02; P.ID = STAT1ID;    P.Mask = 0x00000000; P.DLC = 8; P.TPL = 0; P.MD = CANMD_Tx;  HAL_SetCANBox(Handle, &P);
    P.Num = 0x03; P.ID = STAT2ID;    P.Mask = 0x00000000; P.DLC = 8; P.TPL = 0; P.MD = CANMD_Tx;  HAL_SetCANBox(Handle, &P);
    P.Num = 0x04; P.ID = STAT3ID;    P.Mask = 0x00000000; P.DLC = 8; P.TPL = 0; P.MD = CANMD_Tx;  HAL_SetCANBox(Handle, &P);
    P.Num = 0x05; P.ID = STAT4ID;    P.Mask = 0x00000000; P.DLC = 8; P.TPL = 0; P.MD = CANMD_Tx;  HAL_SetCANBox(Handle, &P);
    P.Num = 0x06; P.ID = ORDER1ID;   P.Mask = 0x00000000; P.DLC = 8; P.TPL = 0; P.MD = CANMD_Rx;  HAL_SetCANBox(Handle, &P);
    P.Num = 0x07; P.ID = ORDER2ID;   P.Mask = 0x00000000; P.DLC = 8; P.TPL = 0; P.MD = CANMD_Rx;  HAL_SetCANBox(Handle, &P);
    P.Num = 0x08; P.ID = DBG1_ID;    P.Mask = 0x00000000; P.DLC = 8; P.TPL = 0; P.MD = CANMD_Tx;  HAL_SetCANBox(Handle, &P);
    P.Num = 0x09; P.ID = DBG2_ID;    P.Mask = 0x00000000; P.DLC = 8; P.TPL = 0; P.MD = CANMD_Tx;  HAL_SetCANBox(Handle, &P);
    P.Num = 0x0A; P.ID = DBG3_ID;    P.Mask = 0x00000000; P.DLC = 8; P.TPL = 0; P.MD = CANMD_Tx;  HAL_SetCANBox(Handle, &P);
    P.Num = 0x0B; P.ID = DBG4_ID;    P.Mask = 0x00000000; P.DLC = 8; P.TPL = 0; P.MD = CANMD_Tx;  HAL_SetCANBox(Handle, &P);
    P.Num = 0x0C; P.ID = DBG5_ID;    P.Mask = 0x00000000; P.DLC = 8; P.TPL = 0; P.MD = CANMD_Tx;  HAL_SetCANBox(Handle, &P);
    P.Num = 0x0D; P.ID = DBG6_ID;    P.Mask = 0x00000000; P.DLC = 8; P.TPL = 0; P.MD = CANMD_Tx;  HAL_SetCANBox(Handle, &P);
    P.Num = 0x0E; P.ID = UPCOM_TXID1; P.Mask = 0x00000000; P.DLC = 8; P.TPL = 0; P.MD = CANMD_Tx;  HAL_SetCANBox(Handle, &P);
    P.Num = 0x0F; P.ID = UPCOM_TXID2; P.Mask = 0x00000000; P.DLC = 8; P.TPL = 0; P.MD = CANMD_Tx;  HAL_SetCANBox(Handle, &P);
    P.Num = 0x10; P.ID = 0x1f002A10; P.Mask = 0x00000000; P.DLC = 8; P.TPL = 0; P.MD = CANMD_Tx;  HAL_SetCANBox(Handle, &P);
    P.Num = 0x11; P.ID = 0x00000011; P.Mask = 0x00000000; P.DLC = 8; P.TPL = 0; P.MD = CANMD_Tx;  HAL_SetCANBox(Handle, &P);
    P.Num = 0x12; P.ID = 0x00000012; P.Mask = 0x00000000; P.DLC = 8; P.TPL = 0; P.MD = CANMD_Tx;  HAL_SetCANBox(Handle, &P);
    P.Num = 0x13; P.ID = 0x00000013; P.Mask = 0x00000000; P.DLC = 8; P.TPL = 0; P.MD = CANMD_Tx;  HAL_SetCANBox(Handle, &P);
    P.Num = 0x14; P.ID = 0x00000014; P.Mask = 0x00000000; P.DLC = 8; P.TPL = 0; P.MD = CANMD_Tx;  HAL_SetCANBox(Handle, &P);
    P.Num = 0x15; P.ID = 0x00000015; P.Mask = 0x00000000; P.DLC = 8; P.TPL = 0; P.MD = CANMD_Tx;  HAL_SetCANBox(Handle, &P);
    P.Num = 0x16; P.ID = 0x00000016; P.Mask = 0x00000000; P.DLC = 8; P.TPL = 0; P.MD = CANMD_Tx;  HAL_SetCANBox(Handle, &P);
    P.Num = 0x17; P.ID = 0x00000017; P.Mask = 0x00000000; P.DLC = 8; P.TPL = 0; P.MD = CANMD_Tx;  HAL_SetCANBox(Handle, &P);
    P.Num = 0x18; P.ID = 0x00000018; P.Mask = 0x00000000; P.DLC = 8; P.TPL = 0; P.MD = CANMD_Tx;  HAL_SetCANBox(Handle, &P);
    P.Num = 0x19; P.ID = 0x00000019; P.Mask = 0x00000000; P.DLC = 8; P.TPL = 0; P.MD = CANMD_Tx;  HAL_SetCANBox(Handle, &P);
    P.Num = 0x1A; P.ID = 0x0000001A; P.Mask = 0x00000000; P.DLC = 8; P.TPL = 0; P.MD = CANMD_Tx;  HAL_SetCANBox(Handle, &P);
    P.Num = 0x1B; P.ID = 0x0000001B; P.Mask = 0x00000000; P.DLC = 8; P.TPL = 0; P.MD = CANMD_Tx;  HAL_SetCANBox(Handle, &P);
    P.Num = 0x1C; P.ID = 0x0000001C; P.Mask = 0x00000000; P.DLC = 8; P.TPL = 0; P.MD = CANMD_Tx;  HAL_SetCANBox(Handle, &P);
    P.Num = 0x1D; P.ID = 0x0000001D; P.Mask = 0x00000000; P.DLC = 8; P.TPL = 0; P.MD = CANMD_Tx;  HAL_SetCANBox(Handle, &P);
    P.Num = 0x1E; P.ID = 0x0000001E; P.Mask = 0x00000000; P.DLC = 8; P.TPL = 0; P.MD = CANMD_Tx;  HAL_SetCANBox(Handle, &P);
    P.Num = 0x1F; P.ID = 0x0000001F; P.Mask = 0x00000000; P.DLC = 8; P.TPL = 0; P.MD = CANMD_Tx;  HAL_SetCANBox(Handle, &P);
}


void HAL_SetCANBox(CAN_Handle Handle, ECAN_BOX_PARAM* P)
{
    uint32_t Temp1 = 0;
	uint32_t Temp2 = 0;
	uint32_t Temp3 = 0;

	Temp1 = (0x01L << P->Num);
	Temp2 = Handle->ECanaRegs.CANME.all;
	Temp3 = Handle->ECanaRegs.CANMD.all & (~Temp1);

	Handle->ECanaRegs.CANME.all = Temp2&(~Temp1);
	(&Handle->ECanaMboxes.MBOX0 + P->Num)->MSGID.all =(P->IDE ? (P->ID | P->AME | P->IDE):((P->ID << 18) | P->AME | P->IDE));
	(&Handle->ECanaMboxes.MBOX0 + P->Num)->MSGCTRL.all  = (P->TPL << 8) | (P->DLC);
	(&Handle->ECanaLAMRegs.LAM0 + P->Num)->all = P->Mask | P->LAMI;
	Handle->ECanaRegs.CANMD.all = Temp3 | ((uint32_t)P->MD << P->Num);
	Handle->ECanaRegs.CANME.all = (Temp2 | Temp1);
}


void ECanaBoxTxMsg(CAN_Handle Handle,ECANMSG* ECanMsg,Uint16 BoxNum)
{
	Handle->ECanaRegs.CANTA.all = 0x01L << BoxNum;
	Handle->ECanaRegs.CANAA.all = 0x01L << BoxNum;
	(&Handle->ECanaMboxes.MBOX0 + BoxNum)->MDL.all = ECanMsg->Data.D32.MDL;
	(&Handle->ECanaMboxes.MBOX0 + BoxNum)->MDH.all = ECanMsg->Data.D32.MDH;
	Handle->ECanaRegs.CANTRS.all = 0x01L << BoxNum;
}


void ECanaBoxRxMsg(CAN_Handle Handle,ECANMSG* ECanMsg,Uint16 BoxNum)
{
	ECanMsg->Data.D32.MDL = (&Handle->ECanaMboxes.MBOX0 + BoxNum)->MDL.all;
	ECanMsg->Data.D32.MDH = (&Handle->ECanaMboxes.MBOX0 + BoxNum)->MDH.all;
	Handle->ECanaRegs.CANRMP.all  = 0x01L << BoxNum;
}


void HAL_CAN_init(CAN_Handle Handle)
{
	struct ECAN_REGS ECanaShadow;

	EALLOW;     // EALLOW enables access to protected bits

	//-------------------------------------------------------------------------
	// 1. Disable all Mailboxes, Required before writing the MSGIDs
	Handle->ECanaRegs.CANME.all = 0x0L;

	//-------------------------------------------------------------------------
	// 2. Configure eCAN RX and TX pins for CAN operation using eCAN regs
	ECanaShadow.CANTIOC.all = Handle->ECanaRegs.CANTIOC.all;
	ECanaShadow.CANTIOC.bit.TXFUNC = ECAN_CANTIOC_TXFUNC_CANTX;
	Handle->ECanaRegs.CANTIOC.all = ECanaShadow.CANTIOC.all;

	ECanaShadow.CANRIOC.all = Handle->ECanaRegs.CANRIOC.all;
	ECanaShadow.CANRIOC.bit.RXFUNC = ECAN_CANTIOC_RXFUNC_CANRX;
	Handle->ECanaRegs.CANRIOC.all = ECanaShadow.CANRIOC.all;

	//-------------------------------------------------------------------------
	// 3.Initialize all bits of 'Message Control Register' to zero
	// Some bits of MSGCTRL register come up in an unknown state. For proper operation,
	// all bits (including reserved bits) of MSGCTRL must be initialized to zero
	Handle->ECanaMboxes.MBOX0.MSGCTRL.all =  0x00000000;
	Handle->ECanaMboxes.MBOX1.MSGCTRL.all =  0x00000000;
	Handle->ECanaMboxes.MBOX2.MSGCTRL.all =  0x00000000;
	Handle->ECanaMboxes.MBOX3.MSGCTRL.all =  0x00000000;
	Handle->ECanaMboxes.MBOX4.MSGCTRL.all =  0x00000000;
	Handle->ECanaMboxes.MBOX5.MSGCTRL.all =  0x00000000;
	Handle->ECanaMboxes.MBOX6.MSGCTRL.all =  0x00000000;
	Handle->ECanaMboxes.MBOX7.MSGCTRL.all =  0x00000000;
	Handle->ECanaMboxes.MBOX8.MSGCTRL.all =  0x00000000;
	Handle->ECanaMboxes.MBOX9.MSGCTRL.all =  0x00000000;
	Handle->ECanaMboxes.MBOX10.MSGCTRL.all = 0x00000000;
	Handle->ECanaMboxes.MBOX11.MSGCTRL.all = 0x00000000;
	Handle->ECanaMboxes.MBOX12.MSGCTRL.all = 0x00000000;
	Handle->ECanaMboxes.MBOX13.MSGCTRL.all = 0x00000000;
	Handle->ECanaMboxes.MBOX14.MSGCTRL.all = 0x00000000;
	Handle->ECanaMboxes.MBOX15.MSGCTRL.all = 0x00000000;
	Handle->ECanaMboxes.MBOX16.MSGCTRL.all = 0x00000000;
	Handle->ECanaMboxes.MBOX17.MSGCTRL.all = 0x00000000;
	Handle->ECanaMboxes.MBOX18.MSGCTRL.all = 0x00000000;
	Handle->ECanaMboxes.MBOX19.MSGCTRL.all = 0x00000000;
	Handle->ECanaMboxes.MBOX20.MSGCTRL.all = 0x00000000;
	Handle->ECanaMboxes.MBOX21.MSGCTRL.all = 0x00000000;
	Handle->ECanaMboxes.MBOX22.MSGCTRL.all = 0x00000000;
	Handle->ECanaMboxes.MBOX23.MSGCTRL.all = 0x00000000;
	Handle->ECanaMboxes.MBOX24.MSGCTRL.all = 0x00000000;
	Handle->ECanaMboxes.MBOX25.MSGCTRL.all = 0x00000000;
	Handle->ECanaMboxes.MBOX26.MSGCTRL.all = 0x00000000;
	Handle->ECanaMboxes.MBOX27.MSGCTRL.all = 0x00000000;
	Handle->ECanaMboxes.MBOX28.MSGCTRL.all = 0x00000000;
	Handle->ECanaMboxes.MBOX29.MSGCTRL.all = 0x00000000;
	Handle->ECanaMboxes.MBOX30.MSGCTRL.all = 0x00000000;
	Handle->ECanaMboxes.MBOX31.MSGCTRL.all = 0x00000000;

	//-------------------------------------------------------------------------
	// 4.Configure bit timing parameters for eCANA
	ECanaShadow.CANMC.all = Handle->ECanaRegs.CANMC.all;
	ECanaShadow.CANMC.bit.CCR = ECAN_CANMC_CCR_Config;
	Handle->ECanaRegs.CANMC.all = ECanaShadow.CANMC.all;

	// Wait until the CPU has been granted permission to change the configuration registers
	do
	{
	  ECanaShadow.CANES.all = Handle->ECanaRegs.CANES.all;
	} while(ECanaShadow.CANES.bit.CCE != 1 );         // Wait for CCE bit to be set..

	ECanaShadow.CANBTC.all = 0;
	ECanaShadow.CANBTC.bit.TSEG2REG = (ECANA_PHASE_SEG2 -1);
	ECanaShadow.CANBTC.bit.TSEG1REG = (ECANA_PROP_SEG + ECANA_PHASE_SEG1 - 1);
	ECanaShadow.CANBTC.bit.SJWREG   = (ECANA_SJW_SEG - 1);
	ECanaShadow.CANBTC.bit.BRPREG   = ((HAL_SYSTEM_FREQ_MHz * 1000000.0L / 2.0L / ECANA_BAUDRATE / ECANA_TQ_NUM) - 1);
	ECanaShadow.CANBTC.bit.SAM      = ECAN_CANBTC_SAM_1;
	Handle->ECanaRegs.CANBTC.all = ECanaShadow.CANBTC.all;

	ECanaShadow.CANMC.all = Handle->ECanaRegs.CANMC.all;   // [EALLOW,32]
	ECanaShadow.CANMC.bit.SCB  = ECAN_CANMC_SCB_32;
	ECanaShadow.CANMC.bit.CCR  = ECAN_CANMC_CCR_Normal;
	ECanaShadow.CANMC.bit.PDR  = 0;
	ECanaShadow.CANMC.bit.DBO  = ECAN_CANMC_DBO_LSB;
	ECanaShadow.CANMC.bit.WUBA = 0;
	ECanaShadow.CANMC.bit.CDR  = 0;
	ECanaShadow.CANMC.bit.ABO  = ECAN_CANMC_ABO_Auto;
	ECanaShadow.CANMC.bit.STM  = 0;
	ECanaShadow.CANMC.bit.SRES = 0;
	ECanaShadow.CANMC.bit.MBNR = 0;
	Handle->ECanaRegs.CANMC.all = ECanaShadow.CANMC.all;

	// Wait until the CPU no longer has permission to change the configuration registers
	do
	{
	  ECanaShadow.CANES.all = Handle->ECanaRegs.CANES.all;
	} while(ECanaShadow.CANES.bit.CCE != 0 );       // Wait for CCE bit to be  cleared.

	//-------------------------------------------------------------------------
	// 5.Time out function
	Handle->ECanaRegs.CANTSC     = 0x00000000;		// [EALLOW,32]Reset the Time stamp Counter.
	Handle->ECanaRegs.CANTOC.all = 0x00000000;		// The time-out function is disabled.

	//-------------------------------------------------------------------------
	// 6.Interrupts
	Handle->ECanaRegs.CANMIM.all  = 0x00000000; 	// [EALLOW]Mail box Interrupt disabled.
	Handle->ECanaRegs.CANMIL.all  = 0x00000000; 	// Mail box Interrupt line 0.
	Handle->ECanaRegs.CANGIM.all  = 0x00000000; 	// [EALLOW]
	EDIS;

	// TRSn TAn, RMPn, GIFn bits are all zero upon reset and are cleared again as a matter of precaution.
	Handle->ECanaRegs.CANTRR.all  = 0xFFFFFFFF; 	// Clear all TRSn bits
	Handle->ECanaRegs.CANTA.all   = 0xFFFFFFFF; 	// Clear all TAn bits
	Handle->ECanaRegs.CANRMP.all  = 0xFFFFFFFF; 	// Clear all RMPn bits
	Handle->ECanaRegs.CANGIF0.all = 0xFFFFFFFF; 	// Clear all interrupt flag bits
	Handle->ECanaRegs.CANGIF1.all = 0xFFFFFFFF;

	// -------------------------------------------------------------------------
	// 7.Old message are Protected.
	Handle->ECanaRegs.CANOPC.all  = 0xFFFFFFFF;
}

