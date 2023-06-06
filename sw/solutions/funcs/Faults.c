// ================================================================================================
//! \file       Faults.c
//! \brief      
//! \author     sunyanjun
//! \version    1.0.0
//! \date       2017年5月3日
//! \copyright  SANTROLL.
// ================================================================================================

void FaultChkSlow(void)
{
	PMSM.Var.Cutback = 1.0;
	Macro_LPF(PMSM.Var.Cutback,PMSM.Var.CutBackFilted,PMSM.Lpf_Coef.CutBack_Tr);
	LogicPowerErrChk();    //(3,5)
	ParErrChk();
#if Loose_DM == 1
#else
	CurSensorErrChk();
#endif
	PMSM.FaultNow.M3_FAULT_OBJ.Msg1LostErr = VCU_Comm.ID5Lost;
    PMSM.FaultNow.M3_FAULT_OBJ.Msg2LostErr = VCU_Comm.ID6Lost;
    PMSM.FaultNow.M3_FAULT_OBJ.MotTempSensorErr1 = PMSM.Var.Flags.Bit.MotTemp1Err;
    PMSM.FaultNow.M3_FAULT_OBJ.MotTempSensorErr2 = PMSM.Var.Flags.Bit.MotTemp2Err;
    PMSM.FaultNow.M3_FAULT_OBJ.InvTempSensorErr1 = PMSM.Var.Flags.Bit.InvTemp1Err;
    PMSM.FaultNow.M3_FAULT_OBJ.InvTempSensorErr2 = PMSM.Var.Flags.Bit.InvTemp2Err;
    PMSM.FaultNow.M3_FAULT_OBJ.InvTempSensorErr3 = PMSM.Var.Flags.Bit.InvTemp3Err;
	// 更新历史故障
    if((UserParm.Var.FaultHis[0] != (UserParm.Var.FaultHis[0]|PMSM.FaultNow.All[0]))
     ||(UserParm.Var.FaultHis[1] != (UserParm.Var.FaultHis[1]|PMSM.FaultNow.All[1]))
     ||(UserParm.Var.FaultHis[2] != (UserParm.Var.FaultHis[2]|PMSM.FaultNow.All[2]))
     ||(UserParm.Var.FaultHis[3] != (UserParm.Var.FaultHis[3]|PMSM.FaultNow.All[3])))
    {
        if((MonSoft.Step == 0)&&(UserParm.StsPnt[0x00] == PARM_IDLE))
        {
            UserParm.Var.FaultHis[0]  |= PMSM.FaultNow.All[0];
            UserParm.Var.FaultHis[1]  |= PMSM.FaultNow.All[1];
            UserParm.Var.FaultHis[2]  |= PMSM.FaultNow.All[2];
            UserParm.Var.FaultHis[3]  |= PMSM.FaultNow.All[3];
            UserParm.Sts.FaultHis[0] = PARM_WRITING;
        }
    }

    if(   PMSM.FaultNow.M3_FAULT_OBJ.MotStallErr     || PMSM.FaultNow.M3_FAULT_OBJ.DcUnderVolt2Err \
       || PMSM.FaultNow.M3_FAULT_OBJ.DcOverVolt2Err  || PMSM.FaultNow.M3_FAULT_OBJ.OverSpeed2Err   \
       || PMSM.FaultNow.M3_FAULT_OBJ.OverSpeed1Err   || PMSM.FaultNow.M3_FAULT_OBJ.MotOverTemp3Err \
       || PMSM.FaultNow.M3_FAULT_OBJ.MotOverTemp2Err || PMSM.FaultNow.M3_FAULT_OBJ.InvOverTemp3Err \
       || PMSM.FaultNow.M3_FAULT_OBJ.InvOverTemp2Err || PMSM.FaultNow.M3_FAULT_OBJ.Msg1LostErr     \
       || PMSM.FaultNow.M3_FAULT_OBJ.PwrMdlErr       || PMSM.FaultNow.M3_FAULT_OBJ.AcOverCur2Err   \
       || PMSM.FaultNow.M3_FAULT_OBJ.DcOverVolt3Err  || PMSM.FaultNow.M3_FAULT_OBJ.DcUnderVolt3Err \
       || PMSM.FaultNow.M3_FAULT_OBJ.PosSensorErr    || PMSM.FaultNow.M3_FAULT_OBJ.Msg2LostErr)
    {
        PMSM.Var.FaultGrade = 3;
    }else if(  PMSM.FaultNow.M3_FAULT_OBJ.DcOverVolt1Err  || PMSM.FaultNow.M3_FAULT_OBJ.DcUnderVolt1Err \
            || PMSM.FaultNow.M3_FAULT_OBJ.MotOverTemp1Err || PMSM.FaultNow.M3_FAULT_OBJ.InvOverTemp1Err \
            || PMSM.FaultNow.M3_FAULT_OBJ.AcOverCur1Err )
    {
        PMSM.Var.FaultGrade = 2;
    }else if(  PMSM.FaultNow.M3_FAULT_OBJ.InvTempSensorErr1 || PMSM.FaultNow.M3_FAULT_OBJ.InvTempSensorErr2 \
            || PMSM.FaultNow.M3_FAULT_OBJ.InvTempSensorErr3)// ||\
//            PMSM.FaultNow.M3_FAULT_OBJ.MotTempSensorErr1 || PMSM.FaultNow.M3_FAULT_OBJ.MotTempSensorErr2)
    {
        PMSM.Var.FaultGrade = 1;
    }else
    {
        PMSM.Var.FaultGrade = 0;
    }
#if Err_Code_En == 1
    GetFaultCode(PMSM.Var.Flags.Bit.KSI_SW,&PMSM.FaultNow,0);
#endif
}
void LogicPowerErrChk(void)
{
#if 0
    static uint16_t LogicPowerCnt = 0;
    static uint16_t LogicPowerCnt1 = 0;


    /*! Brd24V逻辑电源故障检测,不检测欠压，防止掉电时，出现历史故障记录  */
    if(PMSM.Var.Brd24V > 35.00)
    {
        LogicPowerCnt++;
    }
    else if(PMSM.Var.Brd24V < 16.0)
    {
        if(LogicPowerCnt > 0)
        {
            LogicPowerCnt--;
        }
    }

    if(PMSM.Var.Flags.Bit.KSI_SW == 0)
    {
        LogicPowerCnt1 = 0;
    }
    else if(PMSM.Var.Brd24V < 20.00)
    {
        LogicPowerCnt1++;
    }
    else if(PMSM.Var.Brd24V > 21.0)
    {
        if(LogicPowerCnt1 > 0)
        {
            LogicPowerCnt1--;
        }
    }

    if(LogicPowerCnt >= 10)
    {
        LogicPowerCnt = 10;
        PMSM.FaultNow.M3_FAULT_OBJ.LogicPowerErr = 0x01;// & PMSM.FaultMask.M3_FAULT_OBJ.LogicPowerErr;
    }
    else if(LogicPowerCnt1 >= 10)
    {
        LogicPowerCnt1 = 10;
        PMSM.FaultNow.M3_FAULT_OBJ.LogicPowerErr = 0x01;// & PMSM.FaultMask.M3_FAULT_OBJ.LogicPowerErr;
    }
    else if(LogicPowerCnt == 0 && LogicPowerCnt1 == 0)
    {
        PMSM.FaultNow.M3_FAULT_OBJ.LogicPowerErr = 0;
    }
#else
    if(PMSM.Var.Flags.Bit.KSI_SW == 0)
        PMSM.FaultNow.M3_FAULT_OBJ.LogicPowerErr = 0;
    else
        PMSM.FaultNow.M3_FAULT_OBJ.LogicPowerErr = (((int16_t)PMSM.Var.Brd24V>30)?1:0) || (((int16_t)PMSM.Var.Brd24V<15)?1:0);
#endif
}
void ParErrChk(void)
{
    if(UserParm.ErrCode > PARM_WRITING)
    {
        PMSM.FaultNow.M3_FAULT_OBJ.ParErr = 0x01 & PMSM.FaultMask.M3_FAULT_OBJ.ParErr;
    }
}

void CurSensorErrChk(void)
{
    #if   (CUR_SEN_TYPE == CUR_SEN_plusU_plusV_plusW) | (CUR_SEN_TYPE == CUR_SEN_mnusU_mnusV_mnusW)    //!< [+U +V +W] //!< [-U -V -W]
        if((PMSM.Sens.CurU_Offset < 4095.0) && ((PMSM.Sens.CurU_Offset > 2148)||(PMSM.Sens.CurU_Offset < 1948)))
        {
            PMSM.FaultNow.Bit.CurSensorErr = 0x01 & PMSM.FaultMask.Bit.CurSensorErr;
        }
        if((PMSM.Sens.CurV_Offset < 4095.0) && ((PMSM.Sens.CurV_Offset > 2148)||(PMSM.Sens.CurV_Offset < 1948)))
        {
            PMSM.FaultNow.Bit.CurSensorErr = 0x01 & PMSM.FaultMask.Bit.CurSensorErr;
        }
        if((PMSM.Sens.CurW_Offset < 4095.0) && ((PMSM.Sens.CurW_Offset > 2148)||(PMSM.Sens.CurW_Offset < 1948)))
        {
            PMSM.FaultNow.Bit.CurSensorErr = 0x01 & PMSM.FaultMask.Bit.CurSensorErr;
        }
    #elif (CUR_SEN_TYPE == CUR_SEN_plusU_plusV_noneW) | (CUR_SEN_TYPE == CUR_SEN_plusU_mnusV_noneW) | (CUR_SEN_TYPE == CUR_SEN_mnusU_plusV_noneW) | (CUR_SEN_TYPE == CUR_SEN_mnusU_mnusV_noneW)
         //!< [+U +V   ]  //!< [+U -V   ] //!< [-U +V   ] //!< [-U -V   ]
        if((PMSM.Sens.CurU_Offset < 4095.0) && ((PMSM.Sens.CurU_Offset > 2148)||(PMSM.Sens.CurU_Offset < 1948)))
        {
            PMSM.FaultNow.Bit.CurSensorErr = 0x01 & PMSM.FaultMask.Bit.CurSensorErr;
        }
        if((PMSM.Sens.CurV_Offset < 4095.0) && ((PMSM.Sens.CurV_Offset > 2148)||(PMSM.Sens.CurV_Offset < 1948)))
        {
            PMSM.FaultNow.Bit.CurSensorErr = 0x01 & PMSM.FaultMask.Bit.CurSensorErr;
        }
    #elif (CUR_SEN_TYPE == CUR_SEN_plusU_noneV_plusW) | (CUR_SEN_TYPE == CUR_SEN_plusU_noneV_mnusW) | (CUR_SEN_TYPE == CUR_SEN_mnusU_noneV_plusW) | (CUR_SEN_TYPE == CUR_SEN_mnusU_noneV_mnusW )
        //!< [+U    +W] //!< [+U    -W] //!< [-U    +W]  //!< [-U    -W]
        if((PMSM.Sens.CurU_Offset < 4095.0) && ((PMSM.Sens.CurU_Offset > 2148)||(PMSM.Sens.CurU_Offset < 1948)))
        {
            PMSM.FaultNow.M3_FAULT_OBJ.CurSensorErr = 0x01 & PMSM.FaultMask.M3_FAULT_OBJ.CurSensorErr;
        }
        if((PMSM.Sens.CurW_Offset < 4095.0) && ((PMSM.Sens.CurW_Offset > 2148)||(PMSM.Sens.CurW_Offset < 1948)))
        {
            PMSM.FaultNow.M3_FAULT_OBJ.CurSensorErr = 0x01 & PMSM.FaultMask.M3_FAULT_OBJ.CurSensorErr;
        }
    #elif (CUR_SEN_TYPE == CUR_SEN_noneU_plusV_plusW) | (CUR_SEN_TYPE == CUR_SEN_noneU_plusV_mnusW ) | (CUR_SEN_TYPE == CUR_SEN_noneU_mnusV_plusW) | (CUR_SEN_TYPE == CUR_SEN_noneU_mnusV_mnusW)
        //!< [   +V +W] //!< [   +V -W] //!< [   -V +W] //!< [   -V -W]
        if((PMSM.Sens.CurV_Offset < 4095.0) && ((PMSM.Sens.CurV_Offset > 2148)||(PMSM.Sens.CurV_Offset < 1948)))
        {
            PMSM.FaultNow.Bit.CurSensorErr = 0x01 & PMSM.FaultMask.Bit.CurSensorErr;
        }
        if((PMSM.Sens.CurW_Offset < 4095.0) && ((PMSM.Sens.CurW_Offset > 2148)||(PMSM.Sens.CurW_Offset < 1948)))
        {
            PMSM.FaultNow.Bit.CurSensorErr = 0x01 & PMSM.FaultMask.Bit.CurSensorErr;
        }
    #else
        PMSM.FaultNow.Bit.CurSensorErr = 1;
    #endif
}


// ================================================================================================
// end of Faults.c
