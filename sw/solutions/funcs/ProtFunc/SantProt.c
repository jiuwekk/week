// ================================================================================================
//! \file       SantProt.c
//! \brief      松正控制协议
//! \author     xjh
//! \version    1.0.0
//! \date       2019年10月08日
//! \copyright  SANTROLL.
// ================================================================================================

#if COUST_ID == 0

VCU_OBJ VCU_Comm = VCU_OBJ_DEFAULTS;

void VCU_Rx(VCU_OBJ* V)
{
    static int16_t Timer0 = 0;
    static int16_t Timer1 = 0;

    // ID5 接收
    if(ECanaBoxRxRdy(M1_CAN_HANDLE,6))
    {
        ECanaBoxRxMsg(M1_CAN_HANDLE,&V->RMsg,6);
        V->ID5.All[0] = V->RMsg.Data.D16.MD01;
        V->ID5.All[1] = V->RMsg.Data.D16.MD23;
        V->ID5.All[2] = V->RMsg.Data.D16.MD45;
        V->ID5.All[3] = V->RMsg.Data.D16.MD67;
        V->ID5Update = 1;
    }
    // ID5 丢失检测
    if(V->ID5Update == 1)
    {
        V->ID5Update = 0;
        Timer0 = 0;
    }
    else
    {
        Timer0++;
        if(Timer0 > ((uint16_t)(2000.0/PMSM.Var.PwmOutPeriod*1002.0)))
            Timer0 = (uint16_t)(2000.0/PMSM.Var.PwmOutPeriod*1002.0);
    }
    V->ID5Lost = (Timer0>((uint16_t)(2000.0/PMSM.Var.PwmOutPeriod*1000.0)))?1:0;
    PMSM.Var.Flags.Bit.Id5tm = Timer0;

    // ID6 接收
    if(ECanaBoxRxRdy(M1_CAN_HANDLE,7))
    {
        ECanaBoxRxMsg(M1_CAN_HANDLE,&V->RMsg,7);
        V->ID6.All[0] = V->RMsg.Data.D16.MD01;
        V->ID6.All[1] = V->RMsg.Data.D16.MD23;
        V->ID6.All[2] = V->RMsg.Data.D16.MD45;
        V->ID6.All[3] = V->RMsg.Data.D16.MD67;
        V->ID6Update = 1;
    }
    // ID6 丢失检测
    if(V->ID6Update == 1)
    {
        V->ID6Update = 0;
        Timer1 = 0;
    }
    else
    {
        Timer1++;
        if(Timer1 > ((uint16_t)(2000.0/PMSM.Var.PwmOutPeriod*1002.0)))
            Timer1 = (uint16_t)(2000.0/PMSM.Var.PwmOutPeriod*1002.0);
    }
    V->ID6Lost = (Timer1>((uint16_t)(2000.0/PMSM.Var.PwmOutPeriod*1000.0)))?1:0;
    PMSM.Var.Flags.Bit.Id6tm = Timer1;

    CanOrderUpdate();
}
void VCU_Tx(VCU_OBJ* V)
{
    CanSendUpdate();
    static int16_t MsgCounter0 = 0;
    static int16_t MsgCounter1 = 0;
//    static int16_t MsgCounter2 = 0;
//    static int16_t XXXZ = 0;
//    static int16_t XXXC = 0;

    #if 10                                                                  //!< Send 10ms
    switch(MsgCounter0)
    {
        case 0:
        {
            if(V->ID1.Bit.Heart<=255)
            {V->ID1.Bit.Heart++;}
            else{V->ID1.Bit.Heart = 0;}
            if(!ECanaBoxTxBsy(M1_CAN_HANDLE,2))
            {
                V->TMsg.Data.D16.MD01  =V->ID1.All[0];
                V->TMsg.Data.D16.MD23  =V->ID1.All[1];
                V->TMsg.Data.D16.MD45  =V->ID1.All[2];
                V->TMsg.Data.D16.MD67  =V->ID1.All[3];
                ECanaBoxTxMsg(M1_CAN_HANDLE,&VCU_Comm.TMsg,2);
            }
            MsgCounter0++;
            break;
        }
        default:
        {
            MsgCounter0++;
            if(MsgCounter0 >= (10/HAL_MAINLOOP_PRD_ms)) MsgCounter0 = 0;
        }
    }
    #endif

    #if 100                                                                 //!< Send 100ms
    switch(MsgCounter1)
    {
        case 0:
        {
            if(!ECanaBoxTxBsy(M1_CAN_HANDLE,3))
            {

                V->TMsg.Data.D16.MD01  =V->ID2.All[0];
                V->TMsg.Data.D16.MD23  =V->ID2.All[1];
                V->TMsg.Data.D16.MD45  =V->ID2.All[2];
                V->TMsg.Data.D16.MD67  =V->ID2.All[3];
                ECanaBoxTxMsg(M1_CAN_HANDLE,&VCU_Comm.TMsg,3);
            }
            MsgCounter1++;
            break;
        }
        case 1:
        {
            if(!ECanaBoxTxBsy(M1_CAN_HANDLE,4))
            {
                V->TMsg.Data.D16.MD01  =V->ID3.All[0];
                V->TMsg.Data.D16.MD23  =V->ID3.All[1];
                V->TMsg.Data.D16.MD45  =V->ID3.All[2];
                V->TMsg.Data.D16.MD67  =V->ID3.All[3];
                ECanaBoxTxMsg(M1_CAN_HANDLE,&VCU_Comm.TMsg,4);
            }
            MsgCounter1++;
            break;
        }
        case 2:
        {
            if(!ECanaBoxTxBsy(M1_CAN_HANDLE,5))
            {
                V->TMsg.Data.D16.MD01  =V->ID4.All[0];
                V->TMsg.Data.D16.MD23  =V->ID4.All[1];
                V->TMsg.Data.D16.MD45  =V->ID4.All[2];
                V->TMsg.Data.D16.MD67  =V->ID4.All[3];
                ECanaBoxTxMsg(M1_CAN_HANDLE,&VCU_Comm.TMsg,5);
            }
            MsgCounter1++;
            break;
        }
//        case 3:
//        {
//
//          if( PMSM.Intf.Cmd.MotGateReq&& PMSM.Intf.Cmd.DCRelayState && MsgCounter2 < 20 )
//            {
//                XXXC += MainISR_Usage;
//                XXXZ += MainLoopUsage;
//                if(!ECanaBoxTxBsy(M1_CAN_HANDLE,0x19))
//                    {
//                        V->Msg.Data.D16.MD01  = MainISR_Usage*1000;
//                        V->Msg.Data.D16.MD23  = MainLoopUsage*1000;
//                        V->Msg.Data.D16.MD45  = XXXC*50;
//                        V->Msg.Data.D16.MD67  = XXXZ*50;
//                        ECanaBoxTxMsg(M1_CAN_HANDLE,&VCU_Comm.Msg,0x19);
//                    }
//                MsgCounter2 ++;
//            }
//
//            MsgCounter1++;
//
//            break;
//        }

        default:
        {
            MsgCounter1++;
            if(MsgCounter1 >= (100/HAL_MAINLOOP_PRD_ms)) MsgCounter1 = 0;
        }
    }
    #endif
}

void CanOrderUpdate(void)
{
    static uint16_t MotStateReqHis = 0;

    {
        PMSM.Intf.Cmd.DCRelayState  = VCU_Comm.ID5.Bit.DCRelayState;
        PMSM.Intf.Cmd.MotGateReq    = VCU_Comm.ID5.Bit.MotGateReq;
    }


    // 高速不响应关管指令
    if(fabsf(App_Output.data_process.NmFil) > 500.0)
    {
        if((MotStateReqHis == 1) && ((PMSM.Intf.Cmd.MotGateReq == 0) || (PMSM.Intf.Cmd.DCRelayState == 0)))
        {
            PMSM.Intf.Cmd.MotGateReq = 1;
            PMSM.Intf.Cmd.DCRelayState = 1;
        }
    }
    MotStateReqHis = PMSM.Intf.Cmd.MotGateReq;

    PMSM.Intf.Cmd.MotModeReq    = VCU_Comm.ID5.Bit.MotModeReq;
    if( VCU_Comm.ID5.Bit.MotModeReq == 0 )
    {
        PMSM.Intf.Cmd.MotTqReq  = (int16_t)VCU_Comm.ID5.Bit.Parm1TqRef * (1.0/4096);
        PMSM.Intf.Cmd.MotTqRef2 = (int16_t)VCU_Comm.ID5.Bit.Parm2 * (1.0 / 4096);
        PMSM.Intf.Cmd.MotSpdLim = (int16_t)VCU_Comm.ID5.Bit.Parm3SpdLmt;
    }
    else if( VCU_Comm.ID5.Bit.MotModeReq == 4 )
    {
        PMSM.Intf.Cmd.MotTqReq   = (int16_t)VCU_Comm.ID5.Bit.Parm1TqRef * (1.0/4096);
        PMSM.Intf.Cmd.GearPos    = (int16_t)VCU_Comm.ID5.Bit.GearState;
        PMSM.Intf.Cmd.MotSpdLim = (int16_t)VCU_Comm.ID5.Bit.Parm3SpdLmt;
        PMSM.Intf.Cmd.MotSpdHold = 0;
        PMSM.Intf.Cmd.MotSpdReq = (int16_t)VCU_Comm.ID5.Bit.Parm3SpdLmt;
    }
    else
    {
        PMSM.Intf.Cmd.MotSpdReq = (int16_t)VCU_Comm.ID5.Bit.Parm3SpdLmt;
    }
    PMSM.Intf.Cmd.BusCurGeneLim   = (float)VCU_Comm.ID6.Bit.BusCurGeneLim;
    PMSM.Intf.Cmd.BusCurDriveLim  = (float)VCU_Comm.ID6.Bit.BusCurDriveLim;
//    PMSM.Intf.Cmd.MotTorqLimPos   = (float)VCU_Comm.ID6.Bit.MotTorqLim;
//    PMSM.Intf.Cmd.MotTorqLimNeg   = -PMSM.Intf.Cmd.MotTorqLimPos;
}

void CanSendUpdate(void)
{
    //MARK MBD 整车通信数据替换
    PMSM.Intf.Sts.BusCurrent        = App_Output.data_process.CurBusFil;
    PMSM.Var.TqReal                 = App_Output.table.TqReal;
#if 1
    VCU_Comm.ID1.Bit.BusCurrent     = (int16_t)PMSM.Intf.Sts.BusCurrent;
//    if(UserParm.Var.CalibratStep != 0)
//    {
//        if(UserParm.Var.CalibratStep == 4)
//        {
//            VCU_Comm.ID1.Bit.Rsvd0      = (int16_t)(AppFun.StudyResult * 10);
//        }else if(UserParm.Var.CalibratStep == 6 || UserParm.Var.CalibratStep == 7)
//        {
//            VCU_Comm.ID1.Bit.Rsvd0      = (int16_t)(Algo_Output.Cur_loop.IsFbk * UserParm.Var.CurBase / SQRT2);
//        }else
//        {
//            VCU_Comm.ID1.Bit.Rsvd0      = (int16_t)AppFun.StudyResult;
//        }
//
//    }else
//    {
//        VCU_Comm.ID1.Bit.Rsvd0      = 0;
//    }
    VCU_Comm.ID1.Bit.RawTheta       = PMSM.Var.ThetaRT;
    VCU_Comm.ID1.Bit.MotSpdReal     = (int16_t)(App_Output.data_process.NmFil);
#endif

#if 2
    VCU_Comm.ID2.Bit.BusVoltage = (uint16_t)PMSM.Var.VoltBusFilted;
    if(UserParm.Var.CalibratStep == 6 || UserParm.Var.CalibratStep == 7)
    {
        VCU_Comm.ID2.Bit.Rsvd = (uint16_t)(PMSM.Var.VoltBusFilted * Algo_Output.Cur_loop.Vs);
    }else
    {
        VCU_Comm.ID2.Bit.Rsvd = (int16_t)(PMSM.Var.VoltCapFilted);
    }
    VCU_Comm.ID2.Bit.CutBack    = (uint16_t)PMSM.Var.CutBackFilted;
    VCU_Comm.ID2.Bit.InvTemp    = (uint16_t)(PMSM.Var.InvTemp + 50.0);
    VCU_Comm.ID2.Bit.MotTemp    = (uint16_t)(PMSM.Var.MotTemp + 50.0);
#endif

#if 3
    VCU_Comm.ID3.Bit.MotTqMax =  (int16_t)(App_Output.table.TqMax);
    VCU_Comm.ID3.Bit.MotTqReal = (int16_t)(PMSM.Var.TqReal);
#endif

#if 4
    VCU_Comm.ID4.All[0] = PMSM.FaultNow.All[0] & UserParm.Var.FaultMask2_0;
    VCU_Comm.ID4.All[1] = PMSM.FaultNow.All[1] & UserParm.Var.FaultMask2_1;
    VCU_Comm.ID4.All[2] = PMSM.FaultNow.All[2] & UserParm.Var.FaultMask2_2;
    VCU_Comm.ID4.All[3] = PMSM.FaultNow.All[3] & UserParm.Var.FaultMask2_3;
#endif
}
#endif


// ================================================================================================
// end of SantProt.c
