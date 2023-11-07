// ================================================================================================
//! \file       MainLoop.c
//! \brief      ������ѭ�����庯��
//! \author     sunyanjun
//! \version    1.0
//! \date       2017.03.21
//! \copyright  SANTROLL
// ================================================================================================

uint32_t     TotalRunTimePwrOn = 0; //!< [0.1s]   ������ʱ��,�ϵ�ʱ��
uint32_t     TotalRunTime      = 0; //!< [0.1s]   ������ʱ��
uint32_t     SingleRunTime     = 0; //!< [0.1s]   ��������ʱ��
uint16_t     countqqa          = 0;
void Main_Loop(void)
{
    SignalSamp();                                           // �źŲɼ�
    FaultChkSlow();                                         // ����ˢ��
    VCU_Comm.Rx(&VCU_Comm);
    VCU_Comm.Tx(&VCU_Comm);                                 // VCU1 ͨѶ
#if EVCBD_ID == 0x09 && XB05_Precharge_En == 1
    MainDrvStateflow();                                     //���Ӵ���״̬��
    SflMainVoltComp();                                      //Ԥ��״̬��// ע��˺������ڽӴ���״̬�������
#endif
    ParmRefresh();                                          // ���ò������¡���ز���ˢ�¡�LED��˸
    MonSoft.Comm(&MonSoft);                                 // ��λ��ͨѶ
    UserParm.Stateflow(&UserParm);                          // �û�������д����
    RunTime();                                              // ����ʱ�亯��
    DbgDataTx();                                            // debug���ݷ���
    MbdAppSampInput();                                      //MARK MBD ģ��APP��������
    MbdAppCommInput();                                      //MARK MBD ģ��ͨѶ����
    PMSM_Param.MaxT = App_Output.table.TqMax;               // ����й��ϣ��������ת��
    APP_FluxWeak_GEAR2_step();                                             // ģ������
#if EVCBD_ID == 0x08
        if(UserParm.Var.HighDevice == 1)
        {
            HAL_DRV1_En(halHandle);
            HAL_DRV2_En(halHandle);
            HAL_DRV3_En(halHandle);
            HAL_DRV4_En(halHandle);
        }
        else
        {
            HAL_DRV1_Dis(halHandle);
            HAL_DRV2_Dis(halHandle);
            HAL_DRV3_Dis(halHandle);
            HAL_DRV4_Dis(halHandle);
        }
#endif
//    MbdAppOut();                                          // ģ�����
    MbdFaultToBsw();                                        // ʵʱ����ˢ��
    return;
}

void ParmRefresh(void)                                                      //�û���������ݴ��ݣ���λ����ؽ������ݴ���
{
    static uint16_t Index = 0;

    Index++;
    if(Index >= (uint16_t)(HAL_LOWLOOP_PRD_us/HAL_MAINLOOP_PRD_us))
    {
        Index = 0;
    }

    switch(Index)
    {
        case 0:
        {
            PMSM.FaultMask.All[0] = UserParm.Var.FaultMask1_0;
            PMSM.FaultMask.All[1] = UserParm.Var.FaultMask1_1;
            PMSM.FaultMask.All[2] = UserParm.Var.FaultMask1_2;
            PMSM.FaultMask.All[3] = UserParm.Var.FaultMask1_3;
            PMSM.Lpf_Coef.Calc(&PMSM.Lpf_Coef);
            break;
        }
        case 1:
        {
            //MARK MBD ģ��ʹ�õĲ������и���
            PMSM_Param.CurNorm = (float)UserParm.Var.CurBase / SQRT2 * 0.1;
            PMSM_Param.VoltNorm = (float)UserParm.Var.VoltBase * 0.1;
            PMSM_Param.MaxSpd  = UserParm.Var.OverSpd1;

            PMSM_Param.FW1_ref = 1;//200/310;
            PMSM_Param.FW2_ref = 1;//200/310;


            PMSM_Param.SpdKp = (float)UserParm.Var.Kp_SpdM0*0.01;
            PMSM_Param.SpdKi = (float)UserParm.Var.Ki_SpdM0*0.01;

            PMSM_Param.SlopeKp = (float)UserParm.Var.Kp_SpdM3*0.001;
            PMSM_Param.SlopeKi = (float)UserParm.Var.Ki_SpdM3*0.01;


            PMSM_Param.IqKp = (float)UserParm.Var.Kp_Iq*0.001;
            PMSM_Param.IqKi = (float)UserParm.Var.Ki_Iq*0.0001;
            PMSM_Param.IdKp = (float)UserParm.Var.Kp_Id*0.001;
            PMSM_Param.IdKi = (float)UserParm.Var.Ki_Id*0.0001;

            PMSM_Param.FW2Kp = (float)UserParm.Var.Kp_FW2*0.01; // �Ƕ����Ż�
            PMSM_Param.FW2Ki = (float)UserParm.Var.Ki_FW2*0.01;

            PMSM_Param.FW1Kp = (float)UserParm.Var.Kp_FW1*0.01; // id���Ż�
            PMSM_Param.FW1Ki = (float)UserParm.Var.Ki_FW1*0.01;

            PMSM_Param.LimIKp = (float)UserParm.Var.Kp_IdcLmt*0.001; // IDC����
            PMSM_Param.LimIKi = (float)UserParm.Var.Ki_IdcLmt*0.00001;

            PMSM_Param.SV5En = (UserParm.Var.SVPWM_SEGs == 1)?0:1;
            PMSM_Param.SpdFilterTime = UserParm.Var.Spd_Tr*0.1;     // ת���˲�ʱ�䳣�� ms

            PMSM_Param.ZeroPoint = UserParm.Var.ElecZero; // ������
            PMSM_Param.VWDirChg = UserParm.Var.SwapPhase; // �������Ի�
            PMSM_Param.ResolverDirChg = UserParm.Var.SwapEncoderDir; // ���䷽����
            PMSM_Param.SlopeMaxT    = UserParm.Var.SlopeIsMax * 0.001; //פ�����Ť�أ�������

            PMSM_Param.TuneFreqCoef = UserParm.Var.TuneFreqCoef;
            PMSM_Param.FreqLow      = UserParm.Var.FreqLow;
            PMSM_Param.FreqUp       = UserParm.Var.FreqUp;
            PMSM_Param.ASCSpd       = UserParm.Var.ASCSpd;

            PMSM_Param.FilNarrow = 0;
            PMSM_Param.FilDeadzone = 0;
#if Single_or_Double ==1
            PMSM_Param.IParkComp     = 1.5;
#else
            PMSM_Param.IParkComp     = 0.75;
#endif
            PMSM_Param.ParkComp      = 4;

            //�궨��������
//            PMSM_Param.VsLimitVolt = (float)UserParm.Var.VsMax_Ref * 0.1;
            PMSM_Param.VsLimitVolt = 200/1.05;
            PMSM_Param.If = (float)UserParm.Var.If * 0.1;
            PMSM_Param.Bemf = (float)UserParm.Var.Bemf * 0.1;
#if 0
#define MTPA_K30             1.6752     //!< MTPA���3�η�ϵ��#
#define MTPA_K20             (-3.7148)  //!< MTPA���2�η�ϵ��#
#define MTPA_K10             2.9001     //!< MTPA���1�η�ϵ��#
#define MTPA_K00             0.0207     //!< MTPA���0�η�ϵ��#
            PMSM_Param.MTPAK3 = MTPA_K30;
            PMSM_Param.MTPAK2 = MTPA_K20;
            PMSM_Param.MTPAK1 = MTPA_K10;
            PMSM_Param.MTPAK0 = MTPA_K00;
#else
            PMSM_Param.MTPAK3 = MTPA_K3;
            PMSM_Param.MTPAK2 = MTPA_K2;
            PMSM_Param.MTPAK1 = MTPA_K1;
            PMSM_Param.MTPAK0 = MTPA_K0;
#endif

            //���ϲ�������
            PMSM_Param.OV1 = (float)UserParm.Var.DcOverVolt1 * 0.1;
            PMSM_Param.OV2 = (float)UserParm.Var.DcOverVolt2 * 0.1;
            PMSM_Param.OV3 = (float)UserParm.Var.DcOverVolt3 * 0.1;
            PMSM_Param.LV1 = (float)UserParm.Var.DcUnderVolt1 * 0.1;
            PMSM_Param.LV2 = (float)UserParm.Var.DcUnderVolt2 * 0.1;
            PMSM_Param.LV3 = (float)UserParm.Var.DcUnderVolt3 * 0.1;

            PMSM_Param.OS1 = (float)UserParm.Var.OverSpd1;
            PMSM_Param.OS2 = (float)UserParm.Var.OverSpd2;

            PMSM_Param.MotOT1 = (float)UserParm.Var.MotOverTemp1;
            PMSM_Param.MotOT2 = (float)UserParm.Var.MotOverTemp2;
            PMSM_Param.MotOT3 = (float)UserParm.Var.MotOverTemp3;

            PMSM_Param.InvOT1 = (float)UserParm.Var.InvOverTemp1;
            PMSM_Param.InvOT2 = (float)UserParm.Var.InvOverTemp2;
            PMSM_Param.InvOT3 = (float)UserParm.Var.InvOverTemp3;

            PMSM_Param.OC1 = (float)UserParm.Var.AcOverCur1 / UserParm.Var.CurBase;
            PMSM_Param.OC2 = (float)UserParm.Var.AcOverCur2 / UserParm.Var.CurBase;

            PMSM_Param.DamperTimer = (float)UserParm.Var.DamperTimer * 0.1;
            PMSM_Param.DamperGain = (float)UserParm.Var.DamperGain * 0.00001;
            PMSM_Param.FLStartAng = (float)UserParm.Var.FLStartAng;
            break;
        }
        case 2:
        {
            Watch.Var.KSI_SW          =     (int16_t)(PMSM.Var.Flags.Bit.KSI_SW        ); // 00
            Watch.Var.VoltBus         =     (int16_t)(PMSM.Var.VoltBusFilted           ); // 00
            Watch.Var.VoltCap         =     (int16_t)(PMSM.Var.VoltCapFilted           ); // 00
            Watch.Var.TqMax           =     (int16_t)(App_Output.table.TqMax           ); // 01
            Watch.Var.TqReal          =     (int16_t)(App_Output.table.TqReal          ); // 01
            Watch.Var.MotTemp         =     (int16_t)(PMSM.Var.MotTemp + 50            ); // 01
            Watch.Var.InvTemp         =     (int16_t)(PMSM.Var.InvTemp + 50            ); // 02
            Watch.Var.ThetaRawE       =     (int16_t)(AlgoFun.ThetaRawE * 1000         ); // 02
            Watch.Var.ThetaRawM       =     (int16_t)(AlgoFun.ThetaRawM * 1000         ); // 02

            Watch.Var.Angle_park      =     (int16_t)(AlgoFun.Angle_park * 1000        ); // 03
            Watch.Var.Angle_Ipark     =     (int16_t)(AlgoFun.Angle_Ipark * 1000       ); // 03
            Watch.Var.MBD_PwmWorkMode =     (int16_t)(Algo_Output.IGBT_ctrl.PwmWorkMode); // 03
            Watch.Var.MotState        =     (int16_t)App_Output.state.ModeSt            ; // 04
            Watch.Var.MotMode         =     (int16_t)App_Output.state.RunSt             ; // 04
            Watch.Var.Speed           =     (int16_t)(App_Output.data_process.NmFil    ); // 04
            Watch.Var.ThetaRT         =     (int16_t)PMSM.Var.ThetaRT                   ; // 05
            Watch.Var.MainLoopUsage   =     (int16_t)(MainLoopUsage * 10000.0          ); // 05
            Watch.Var.MainISR_Usage   =     (int16_t)(MainISR_Usage * 10000.0          ); // 05

            break;
        }
        case 3:
        {
            Watch.Var.ParmErrCode     =     UserParm.ErrCode                            ; // 06
            Watch.Var.ParmErrIndex    =     UserParm.ErrIndex                           ; // 06
            Watch.Var.CurBus          =     (int16_t)(PMSM.Var.CurBus                  ); // 06
            Watch.Var.IGBT1Err        =     HAL_Pwm_Fault1(halHandle)                   ; // 07
            Watch.Var.IGBT2Err        =     HAL_Pwm_Fault2(halHandle)                   ; // 07
            Watch.Var.IGBT3Err        =     HAL_Pwm_Fault3(halHandle)                   ; // 07
            Watch.Var.MBD_KeepPowerEn =     (int16_t)(App_Output.power.KeepPowerEn     ); // 08
            break;
        }
        case 4:
        {
            // ��в�������
            PMSM.Var.Ld  = (float)UserParm.Var.Bemf / (float)UserParm.Var.VoltBase * (float)UserParm.Var.SpeedBase / 1000.0 \
                         / ((float)UserParm.Var.If / (float)UserParm.Var.CurBase);
            break;
        }
        case 5:
        {
            LEDFlash();
            break;
        }
    }
}


void LEDFlash(void)                                                         //LED������������
{
    static uint16_t State  = 0;
    static uint16_t Code0  = 0;        //������1
    static uint16_t Code1  = 0;        //������2
    static uint16_t Index  = 0;        //��ǰ�Ĺ���λλ��ַ
    static uint16_t IndexHis  = 0;    //��ʷ�Ĺ���λλ��ַ
    static uint16_t Delay  = 0;
    static uint32_t Faults = 0;

    // ��˸״̬��
    switch(State)
    {
        case 0: // ��ʼ��
        {
            Faults = PMSM.FaultNow.All[1];
            Faults = (Faults << 16) | PMSM.FaultNow.All[0];
            if(Faults)
            {
                HAL_LED2_on(halHandle);
            }
            else
            {
                HAL_LED2_off(halHandle);
            }
            Code0 = 1;
            Code1 = 1;
             if(Delay < (uint16_t)(2000000.0/HAL_LOWLOOP_PRD_us))
            {
                Delay++;
            }
            else
            {
                State++;
                Delay = 0;
            }
            break;
        }
        case 1: // Ѱ�ҹ���λ
        {
            for(Index = IndexHis; Index < 32; Index++)
            {
                if((Faults>>Index) & 0x01L)
                {
                    Code0 = ((Index>>3)&0x07) + 1;
                    Code1 = (Index&0x07) + 1;
                    break;
                }
            }

            if(Faults>>(Index + 1))
            {
                IndexHis = Index + 1;
                if(IndexHis > 31)
                {
                    IndexHis = 0;
                }
            }
            else
            {
                IndexHis = 0;
            }
            State++;
            break;
        }
        case 2: // ��˸����һ
        {
            if(Code0)
            {
                if(Delay < (uint16_t)(250000.0/HAL_LOWLOOP_PRD_us))
                {
                    Delay++;
                    HAL_LED1_on(halHandle);
                }
                else if(Delay < (uint16_t)(500000.0/HAL_LOWLOOP_PRD_us))
                {
                    Delay++;
                    HAL_LED1_off(halHandle);
                }
                else
                {
                    Code0--;
                    Delay = 0;
                }
            }
            else
            {
                State++;
            }
            break;
        }
        case 3: // ��˸���ڼ���
        {
             if(Delay < (uint16_t)(1000000.0/HAL_LOWLOOP_PRD_us))
            {
                Delay++;
            }
            else
            {
                State++;
                Delay = 0;
            }
            break;
        }
        case 4: // ��˸�������
        {
            if(Code1)
            {
                if(Delay < (uint16_t)(250000.0/HAL_LOWLOOP_PRD_us))
                {
                    Delay++;
                    HAL_LED1_on(halHandle);
                }
                else if(Delay < (uint16_t)(500000.0/HAL_LOWLOOP_PRD_us))
                {
                    Delay++;
                    HAL_LED1_off(halHandle);
                }
                else
                {
                    Code1--;
                    Delay = 0;
                }
            }
            else
            {
                State++;
            }
            break;
        }
        case 5: // ��˸�����
        {
             if(Delay < (uint16_t)(1000000.0/HAL_LOWLOOP_PRD_us))
            {
                Delay++;
            }
            else
            {
                State = 0;
                Delay = 0;
            }
            break;
        }
    }
}

void RunTime(void)                                                          //ϵͳ����ʱ����㺯��
{
    static uint16_t TmCnt = 0;
    static uint16_t WriteStep = 0;

    if(PMSM.Var.Flags.Bit.KSI_SW)
    {
        WriteStep = 0;
        if(TmCnt < 100)
        {
            TmCnt++;
        }
        else
        {
            TmCnt = 0;
            SingleRunTime++;
            TotalRunTime = TotalRunTimePwrOn + SingleRunTime;
        }
    }
    else    // �����¼������ʱ��
    {
        if(WriteStep == 0)
        {
            if(UserParm.VarPnt[18] != (TotalRunTime >> 16))     // ���ֽ�λ���ͱ仯
            {
                if((MonSoft.Step == 0)&&(UserParm.StsPnt[18] == PARM_IDLE))
                {
                    WriteStep++;
                    UserParm.StsPnt[18] = PARM_WRITING;
                    UserParm.VarPnt[18] = TotalRunTime >> 16;
                }
            }
            else
            {
                WriteStep++;
            }
        }
        else if(WriteStep == 1)
        {
            if(UserParm.StsPnt[18] == PARM_IDLE)
            {
                WriteStep++;
            }
            else
            {
                ;
            }
        }
        else if(WriteStep == 2)
        {
            if((MonSoft.Step == 0)&&(UserParm.StsPnt[19] == PARM_IDLE))
            {
                WriteStep++;
                UserParm.StsPnt[19] = PARM_WRITING;
                UserParm.VarPnt[19] = TotalRunTime & 0x0000FFFF;
            }

        }
        else if(WriteStep == 3)
        {
            if(UserParm.StsPnt[19] == PARM_IDLE)
            {
                WriteStep++;
            }
            else
            {
                ;
            }
        }
        else
        {
            ;
        }
    }

}
void AscCondJudeg(void)                                                     //ASC�����ж�
{
    if(fabsf(App_Output.data_process.NmFil) > ASCCONDSPD)
    {
        PMSM.Var.Flags.Bit.AscCondOk = 1;
    }else if(fabsf(App_Output.data_process.NmFil) > (ASCCONDSPD - 100))
    {
        ;
    }else
    {
        PMSM.Var.Flags.Bit.AscCondOk = 0;
    }
}

void MbdAppSampInput(void)                                                  //APP��������
{
    PMSM_Input.AppSample.MotTemp1 = PMSM.Var.MotTemp1;
    PMSM_Input.AppSample.MotTemp2 = PMSM.Var.MotTemp2;
    PMSM_Input.AppSample.InvTemp1 = PMSM.Var.InvTemp1;
    PMSM_Input.AppSample.InvTemp2 = PMSM.Var.InvTemp2;
    PMSM_Input.AppSample.InvTemp3 = PMSM.Var.InvTemp3;
//    PMSM_Input.AppSample.VoltBus = PMSM.Var.VoltBus / 10;//200;
    PMSM_Input.AppSample.VoltCap = PMSM.Var.VoltCap / 10;//200;   PosSen
    PMSM_Input.AppSample.VoltCap_compensate = PMSM.Var.VoltCap_pui;//200;   PosSen
//    PMSM_Input.AppSample.Brd24V = PMSM.Var.Brd24V;
//    PMSM_Input.AppSample.Brd15V = PMSM.Var.Brd12V;
    PMSM_Input.AppSample.AnaInput1AD = 0;
    PMSM_Input.AppSample.AnaInput2AD = 0;
    PMSM_Input.AppSample.AnaInput3AD = 0;
    PMSM_Input.AppSample.KsiSt = 1;//PMSM.Var.Flags.Bit.KSI_SW;
    PMSM_Input.AppSample.Sw1InputSt = 0;
    PMSM_Input.AppSample.Sw2InputSt = 0;
    PMSM_Input.AppSample.Sw3InputSt = 0;
    PMSM_Input.AppSample.ReadyFin = 1;
    PMSM_Input.AppSample.ExtTorque = PMSM.Intf.Cmd.MotTqRef2;
    PMSM_Input.AppSample.ElecZeroStep = UserParm.Var.ElecZeroStudyType;  // ���ѧϰ����
    PMSM_Input.AppSample.CalibStep = UserParm.Var.CalibratStep;          // �궨���� 0 - 7
    PMSM_Input.AppSample.CalibMTPATheta = UserParm.Var.CalibMTPATheta * 0.01;   // ��ʼ�궨MTPA�Ƕ�   [0 pi/2]  rad

//    if(UserParm.Var.CalibratStep == 5) // MTPA�궨
//    {
//        PMSM_Input.AppSample.CalibMTPATheta = PMSM.Intf.Cmd.MotTqRef2 * PI2;
//
//        PMSM_Input.AppSample.CalibMTPATheta = fsatf(PMSM_Input.AppSample.CalibMTPATheta, PI_2, 0);
//    }else
//    {
//        PMSM_Input.AppSample.CalibMTPATheta = 0;
//    }
}
void MbdAppCommInput(void)                                                  //APPָ������
{
//    if(UserParm.Var.CalibratStep == 7) // Ť�ؾ��ȱ궨
//    {
//        PMSM_Input.AppComm.TqReq = PMSM.Intf.Cmd.MotTqReq * 256;        // Ť������,ʹ��Ϊ΢�����أ��궨16����
//        PMSM_Input.AppComm.TqReq = fsatf(PMSM_Input.AppComm.TqReq,1.0,0);// ����һ��
//    }else
    {
        PMSM_Input.AppComm.TqReq = PMSM.Intf.Cmd.MotTqReq;              // Ť������
    }

        PMSM_Input.AppComm.SpdReq = PMSM.Intf.Cmd.MotSpdReq;
              // �ٶ�����
    PMSM_Input.AppComm.TqUpperLim = 1.0;
    PMSM_Input.AppComm.TqLowerLim = -1.0;
    PMSM_Input.AppComm.SpdUpperLim = PMSM.Intf.Cmd.MotSpdLim; //3000;
    PMSM_Input.AppComm.SpdLowerLim = (-PMSM.Intf.Cmd.MotSpdLim); //-3000;
    PMSM_Input.AppComm.DrvLimCur = PMSM.Intf.Cmd.BusCurDriveLim; //200;
    PMSM_Input.AppComm.GenLimCur = PMSM.Intf.Cmd.BusCurGeneLim; //50;
    PMSM_Input.AppComm.GateReq = PMSM.Intf.Cmd.MotGateReq;                // ����״̬;
#if XB05_Precharge_En == 0
    PMSM_Input.AppComm.MainRelayState = PMSM.Intf.Cmd.DCRelayState;       // ����״̬
#else
    PMSM_Input.AppComm.MainRelayState = MainDrv.Sts.Bits.PreChargeRdy;//PMSM.Intf.Cmd.DCRelayState;       // ����״̬
#endif
    PMSM_Input.AppComm.GearState = PMSM.Intf.Cmd.GearPos;
    if(UserParm.Var.CalibratStep != 0)
    {
        PMSM_Input.AppComm.ModeReq = 8;                                    // ģʽ����Ϊ�궨
    }else
    {
        PMSM_Input.AppComm.ModeReq = PMSM.Intf.Cmd.MotModeReq;  // 7 ;// ģʽ����
    }


//    PMSM_Input.AppComm.ModeReq = 8;//MARK ģʽ

//    PMSM_Input.AppComm.CanMsg1Lost = PMSM.FaultNow.M3_FAULT_OBJ.Msg1LostErr;
//    PMSM_Input.AppComm.CanMsg2Lost = PMSM.FaultNow.M3_FAULT_OBJ.Msg2LostErr;
}

void MbdAppOut(void)                                                        //APP�������
{
#if 0
    McuSt.data_process.NmFilPu      = App_Output.data_process.NmFilPu;
    McuSt.data_process.VoltCapFilPu = App_Output.data_process.VoltCapFilPu;
    McuSt.data_process.CurBus       = App_Output.data_process.CurBus;
    McuSt.data_process.CurBusFil    = App_Output.data_process.CurBusFil;
    McuSt.data_process.MotTemp      = App_Output.data_process.MotTemp;
    McuSt.data_process.InvTemp      = App_Output.data_process.InvTemp;
    McuSt.data_process.NVComp       = App_Output.data_process.NVComp;
    McuSt.table.TqMax               = App_Output.table.TqMax;
    McuSt.table.TqReal              = App_Output.table.TqReal ;
    McuSt.fault.LimtCoef            = App_Output.fault.LimtCoef ;
    McuSt.fault.PwmWorkMode         = App_Output.fault.PwmWorkMode;
    McuSt.fault.FaultCode1          = App_Output.fault.FaultCode1;
    McuSt.state.RunSt               = App_Output.state.RunSt;
    McuSt.state.ModeSt              = App_Output.state.ModeSt;
    McuSt.power.KeepPowerEn         = App_Output.power.KeepPowerEn;
    McuSt.power.DRV1_En             = App_Output.power.DRV1_En;
    McuSt.power.DRV2_En             = App_Output.power.DRV2_En;
    McuSt.ctrl.AscEn                = App_Output.ctrl.AscEn;
    McuSt.ctrl.IdRefSet             = App_Output.ctrl.IdRefSet;
    McuSt.ctrl.IqRefSet             = App_Output.ctrl.IqRefSet;
    McuSt.ctrl.AngleRefSet          = App_Output.ctrl.AngleRefSet;
    McuSt.ctrl.IdIqSetEn            = App_Output.ctrl.IdIqSetEn;
    McuSt.ctrl.AngleSetEn           = App_Output.ctrl.AngleSetEn;
    McuSt.ctrl.VsRef                = App_Output.ctrl.VsRef;
    McuSt.ctrl.IsRef                = App_Output.ctrl.IsRef;
    McuSt.ctrl.PwmFreq              = App_Output.ctrl.PwmFreq;
#endif
}
void MbdFaultToBsw(void)                                                    //APP����Ĺ�����
{
    PMSM.FaultNow.M3_FAULT_OBJ.ErrLevel           = PMSM.Var.FaultGrade ;
    PMSM.FaultNow.M3_FAULT_OBJ.MotStallErr        = (App_Output.fault.FaultCode1>>0)&0x00000001;
    PMSM.FaultNow.M3_FAULT_OBJ.DcOverVolt1Err     = (App_Output.fault.FaultCode1>>1)&0x00000001;
    PMSM.FaultNow.M3_FAULT_OBJ.DcOverVolt2Err     = (App_Output.fault.FaultCode1>>2)&0x00000001;
    PMSM.FaultNow.M3_FAULT_OBJ.DcUnderVolt1Err    = (App_Output.fault.FaultCode1>>3)&0x00000001;
    PMSM.FaultNow.M3_FAULT_OBJ.DcUnderVolt2Err    = (App_Output.fault.FaultCode1>>4)&0x00000001;
    PMSM.FaultNow.M3_FAULT_OBJ.OverSpeed1Err      = (App_Output.fault.FaultCode1>>5)&0x00000001;
    PMSM.FaultNow.M3_FAULT_OBJ.OverSpeed2Err      = (App_Output.fault.FaultCode1>>6)&0x00000001;
    PMSM.FaultNow.M3_FAULT_OBJ.MotOverTemp1Err    = (App_Output.fault.FaultCode1>>7)&0x00000001;
    PMSM.FaultNow.M3_FAULT_OBJ.MotOverTemp2Err    = (App_Output.fault.FaultCode1>>8)&0x00000001;
    PMSM.FaultNow.M3_FAULT_OBJ.MotOverTemp3Err    = (App_Output.fault.FaultCode1>>9)&0x00000001;
    PMSM.FaultNow.M3_FAULT_OBJ.InvOverTemp1Err    = (App_Output.fault.FaultCode1>>10)&0x00000001;
    PMSM.FaultNow.M3_FAULT_OBJ.InvOverTemp2Err    = (App_Output.fault.FaultCode1>>11)&0x00000001;
    PMSM.FaultNow.M3_FAULT_OBJ.InvOverTemp3Err    = (App_Output.fault.FaultCode1>>12)&0x00000001;
    PMSM.FaultNow.M3_FAULT_OBJ.MotTempSensorErr1  = (App_Output.fault.FaultCode1>>13)&0x00000001;
    PMSM.FaultNow.M3_FAULT_OBJ.MotTempSensorErr2  = (App_Output.fault.FaultCode1>>14)&0x00000001;
    PMSM.FaultNow.M3_FAULT_OBJ.InvTempSensorErr1  = (App_Output.fault.FaultCode1>>15)&0x00000001;
    PMSM.FaultNow.M3_FAULT_OBJ.InvTempSensorErr2  = (App_Output.fault.FaultCode1>>16)&0x00000001;
    PMSM.FaultNow.M3_FAULT_OBJ.InvTempSensorErr3  = (App_Output.fault.FaultCode1>>17)&0x00000001;
    PMSM.FaultNow.M3_FAULT_OBJ.Msg1LostErr        = (App_Output.fault.FaultCode1>>18)&0x00000001;
    PMSM.FaultNow.M3_FAULT_OBJ.DisChgOverTmErr    = (App_Output.fault.FaultCode1>>19)&0x00000001;
    PMSM.FaultNow.M3_FAULT_OBJ.PwrMdlErr          = (Algo_Output.Fault.IGBT)&0x00000001;
    PMSM.FaultNow.M3_FAULT_OBJ.AcOverCur2Err      = (Algo_Output.Fault.OC2)&0x00000001;
    PMSM.FaultNow.M3_FAULT_OBJ.AcOverCur1Err      = (Algo_Output.Fault.OC1)&0x00000001;
    PMSM.FaultNow.M3_FAULT_OBJ.DcOverVolt3Err     = (Algo_Output.Fault.OV3)&0x00000001;
    PMSM.FaultNow.M3_FAULT_OBJ.DcUnderVolt3Err    = (Algo_Output.Fault.LV3)&0x00000001;
    PMSM.FaultNow.M3_FAULT_OBJ.PosSensorErr       = (Algo_Output.Fault.PosSen)&0x00000001;
    PMSM.FaultNow.M3_FAULT_OBJ.PhaseBrkErr        = (App_Output.fault.FaultCode1>>26)&0x00000001;

}
// ================================================================================================
// end of MainLoop.c
