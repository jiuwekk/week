// ================================================================================================
//! \file       CanDbgData.c
//! \brief      Can调试数据发送
//! \author     xjh
//! \version    1.0.0
//! \date       2019年11月04日
//! \copyright  SANTROLL.
// ================================================================================================
ECANMSG      DbgMsg[10] = ECANMSG_DEFAULTS;
#if COUST_ID == 0
void DbgDataTx(void)
{
    static int16_t MsgCounter0 = 0;
    static int16_t MsgCounter1 = 0;
//    static int16_t count = 0 ;
//    static int16_t MsgCounter2 = 0;
//    if(UserParm.Var.DebugMode == Debug_Idle)
//    {}
//    else
//        if(UserParm.Var.DebugMode == Degub_Send_DQ_and_Fundata)
    if(UserParm.Var.DebugMode == Debug_Idle)
    {
        //!< Send 10ms
        switch(MsgCounter0)
        {
            case 0:
            {
                if(!ECanaBoxTxBsy(M1_CAN_HANDLE,8))
                {
                    DbgMsg[0].Data.D16.MD01  =(int16_t)(AlgoFun.IdRef*1000.0);//
                    DbgMsg[0].Data.D16.MD23  =(int16_t)(Algo_Output.Cur_loop.Id * 1000.0);//
                    DbgMsg[0].Data.D16.MD45 = (int16_t)(AlgoFun.IqRef*1000.0);//
                    DbgMsg[0].Data.D16.MD67 = (int16_t)(Algo_Output.Cur_loop.Iq * 1000.0);//
                    ECanaBoxTxMsg(M1_CAN_HANDLE,&DbgMsg[0],8);
                    MsgCounter0++;
                }
                break;
            }
            case 1:
            {
                if(!ECanaBoxTxBsy(M1_CAN_HANDLE,9))
                {
                    DbgMsg[1].Data.D16.MD01  =(int16_t)(App_Output.ctrl.TqReq* 1000.0);//(App_Output.ctrl.IsRef * 1000.0);//
                    DbgMsg[1].Data.D16.MD23  =(int16_t)(0);//(Algo_Output.Cur_loop.IsFbk * 1000.0);//
                    DbgMsg[1].Data.D16.MD45  =(int16_t)(Algo_Output.Cur_loop.Ud*1000.0);//
                    DbgMsg[1].Data.D16.MD67  =(int16_t)(Algo_Output.Cur_loop.Uq*1000.0);//
                    ECanaBoxTxMsg(M1_CAN_HANDLE,&DbgMsg[1],9);
                    MsgCounter0++;
                }
                break;
            }
            case 2:
            {
                if(!ECanaBoxTxBsy(M1_CAN_HANDLE,0x0B))
                {
                    DbgMsg[2].Data.D16.MD01  =(int16_t)(AppFun.Us * 1000.0);//
                    DbgMsg[2].Data.D16.MD23  =(int16_t)(AppFun.LimTP_I* 1000.0);//(AlgoFun.PI_Id_Ui );//
                    DbgMsg[2].Data.D16.MD45  =(int16_t)(AppFun.LimTN_I* 1000.0);//(AlgoFun.PI_Iq_Ui * 1000.0);//
                    DbgMsg[2].Data.D16.MD67  =(int16_t)(AppFun.Tqreq * 1000.0);//
                    ECanaBoxTxMsg(M1_CAN_HANDLE,&DbgMsg[2],0x0B);
                    MsgCounter0++;
                }
                break;
            }
            case 3:
            {
                if(!ECanaBoxTxBsy(M1_CAN_HANDLE,0x0C))
                {
                    DbgMsg[3].Data.D16.MD01  =(int16_t)(AlgoFun.Psi_whole * 1000.0);//
                    DbgMsg[3].Data.D16.MD23  =(int16_t)(AlgoFun.Psi_Weak * 1000.0);//
                    DbgMsg[3].Data.D16.MD45 = (int16_t)(AlgoFun.PsiWeak_Ui * 1000.0);//
                    DbgMsg[3].Data.D16.MD67 = (int16_t)(0);//
                    ECanaBoxTxMsg(M1_CAN_HANDLE,&DbgMsg[3],0x0C);
                    MsgCounter0++;
                }
                break;
            }
            case 4:
            {
                if(!ECanaBoxTxBsy(M1_CAN_HANDLE,0x0D))
                {
                    DbgMsg[4].Data.D16.MD01  =(int16_t)(PMSM_Input.AgoSample.CurUPu*100 );//(AppFun.LimTP_I*1000);//
                    DbgMsg[4].Data.D16.MD23  =(int16_t)(PMSM_Input.AgoSample.CurVPu*100 );//(AppFun.LimTN_I*1000);//
                    DbgMsg[4].Data.D16.MD45 = (int16_t)(PMSM_Input.AgoSample.CurWPu*100 );//(PMSM_Param.FW1Ki);//
                    DbgMsg[4].Data.D16.MD67 = (int16_t)(PMSM_Param.FW1Kp);//
                    ECanaBoxTxMsg(M1_CAN_HANDLE,&DbgMsg[4],0x0D);
                    MsgCounter0++;
                }
                break;
            }
//            case 5:
//            {
//                if(!ECanaBoxTxBsy(M1_CAN_HANDLE,0x10))
//                {
//                    DbgMsg[5].Data.D16.MD01  =(uint16_t)(PMSM.Sens.CurU*100);//
//                    DbgMsg[5].Data.D16.MD23  =(uint16_t)(PMSM.Sens.CurV*100);//
//                    DbgMsg[5].Data.D16.MD45 = (uint16_t)(PMSM.Sens.CurW*100);//
//                    DbgMsg[5].Data.D16.MD67 = (int16_t)(0);//
//                    ECanaBoxTxMsg(M1_CAN_HANDLE,&DbgMsg[5],0x10);
//                    MsgCounter0++;
//                }
//                break;
//            }
            default:
            {
                MsgCounter0++;
                if(MsgCounter0 >= (50/HAL_MAINLOOP_PRD_ms)) MsgCounter0 = 0;
            }
        }
//        switch(MsgCounter2)
//        {
//            case 0:
//            {
//                if(!ECanaBoxTxBsy(M1_CAN_HANDLE,0x10))
//                {
//                    DbgMsg[5].Data.D16.MD01  =(int16_t)(APP_FluxWeak_GEAR2_rtZPMSM_Input_bus.AgoSample.CurUPu);//
//                    DbgMsg[5].Data.D16.MD23  =(int16_t)(APP_FluxWeak_GEAR2_rtZPMSM_Input_bus.AgoSample.CurVPu);//
//                    DbgMsg[5].Data.D16.MD45 = (int16_t)(APP_FluxWeak_GEAR2_rtZPMSM_Input_bus.AgoSample.CurWPu);//
//                    DbgMsg[5].Data.D16.MD67 = (int16_t)(0);//
//                    ECanaBoxTxMsg(M1_CAN_HANDLE,&DbgMsg[5],0x10);
//                    MsgCounter2++;
//                }
//                break;
//            }
//            default:
//            {
//                MsgCounter2++;
//                if(MsgCounter2 >= 5) MsgCounter2 = 0;
//            }
//        }
        switch(MsgCounter1)
        {
//        static uint16_t count = 0 ;
        static uint16_t enable = 0 ;
            case 0:
            {
                if(!ECanaBoxTxBsy(M1_CAN_HANDLE,0x0A))
                {
                    DbgMsg[9].Data.D16.MD01  = (int16_t)AppFun.StudyStep; //0;
                    DbgMsg[9].Data.D16.MD23  = (int16_t)AppFun.StudyResult; //BlcdeAAACount ;AppFun.StudyResult
                    DbgMsg[9].Data.D16.MD45  = (int16_t)(0);//
                    DbgMsg[9].Data.D16.MD67  = (int16_t)(enable);//M1_VOLT_CAP;//
                    ECanaBoxTxMsg(M1_CAN_HANDLE,&DbgMsg[9],0x0A);
                    MsgCounter1++;
//                    if ( PMSM.Intf.Cmd.DCRelayState && PMSM.Intf.Cmd.MotGateReq )
//                    {
//                        enable = 1;
//                    }
//                    if( count < 9999 && enable == 1 && !PMSM.Intf.Cmd.DCRelayState )
//                    {
//                        count++;
//                    }
                if ( PMSM.Intf.Cmd.DCRelayState && PMSM.Intf.Cmd.MotGateReq && (PMSM_Input.AppComm.ModeReq==4) &&(VCU_Comm.ID1.Bit.MotSpdReal< 20))
                {
                    enable = 1;
                }else
                {
                    enable = 0;
                }

                }
            }
            break;
            default:
            {
                MsgCounter1++;
                if(MsgCounter1 >= (20/HAL_MAINLOOP_PRD_ms)) MsgCounter1 = 0;
            }
        }
    }
}
#endif


// ================================================================================================
// end of CanDbgData.c
