//! \file       hal_sci.c
//! \brief      Contains various functions related to the SCI object
//! \author     sunyanjun
//! \version    1.0
//! \date       2017.03.21
//! \copyright  SANTROLL

void HAL_setupSci(SCI_Handle sciHandle)
{
	SCI_setCharLength(sciHandle,SCI_CharLength_8_Bits);
	SCI_setMode(sciHandle,SCI_Mode_IdleLine);
	SCI_disableLoopBack(sciHandle);
	SCI_disableParity(sciHandle);
	SCI_setParity(sciHandle,SCI_Parity_Odd);
	SCI_setNumStopBits(sciHandle,SCI_NumStopBits_One);

	SCI_enableTx(sciHandle);
	SCI_enableRx(sciHandle);
	SCI_disableSleep(sciHandle);
	SCI_disableTxWake(sciHandle);
	SCI_disableRxErrorInt(sciHandle);
	SCI_enable(sciHandle);

	// 联合体内所有波特率均已测试通过
	SCI_setBaudRate(sciHandle,(SCI_BaudRate_e)SCI_BAUDRATES_9600);

	SCI_setPriority(sciHandle,SCI_Priority_AfterRxRxSeq);

	SCI_disableAutoBaudAlign(sciHandle);
	SCI_setTxDelay(sciHandle,0);

	SCI_clearTxFifoInt(sciHandle);
	SCI_resetChannels(sciHandle);
	SCI_enableTxFifoEnh(sciHandle);

	SCI_clearRxFifoOvf(sciHandle);
	SCI_clearRxFifoInt(sciHandle);

	SCI_disableTxInt(sciHandle);
	SCI_disableRxInt(sciHandle);
	SCI_enableRxFifoInt(sciHandle);
	SCI_setRxFifoIntLevel(sciHandle,SCI_FifoLevel_1_Word);
}
