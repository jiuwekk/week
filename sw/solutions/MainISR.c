// ================================================================================================
//! \file       MainISR.c
//! \brief      包含主中断主体函数
//! \author     sunyanjun
//! \version    1.0
//! \date       2017.03.21
//! \copyright  SANTROLL
// ================================================================================================

#ifdef FLASH
#pragma CODE_SECTION(Main_ISR,"ramfuncs");
#endif /* FLASH */
float ELCUCMsg[10000] = {0};
//uint16_t ElcErrCount = 0 ;
//uint16_t BlcdeAAACount = 0 ;
//float CurMax = 0;
extern ECANMSG      DbgMsg[6];;
//static uint16_t count = 0;
void Main_ISR(void)
{

#if 0
    static uint16_t PwrOnFlg = 0;
    if(!PwrOnFlg)// 上电读取一次
    {
        PwrOnFlg = 1;
    #if EVCBD_ID == 0x08 || EVCBD_ID == 0x09 || EVCBD_ID == 0x0D
        Rdc.Data = AD2S1205_Read(M1_SPI_HANDLE) ;
        PMSM.Var.ThetaRT =Rdc.M1.Loc;
    #else
        HAL_WriteResolver(M1_SPI_HANDLE);         // 旋变位置读取触发
        PMSM.Var.ThetaRT = HAL_ReadResolver(M1_SPI_HANDLE); // 旋变位置读取
    #endif
        M1_QEP_HANDLE->QPOSCNT = PMSM.Var.ThetaRT;                          // 初始值赋给QPOSCNT
        M1_QEP_HANDLE->QUTMR = EQEP_QCPRD;                                  // 计算转速，防止上电时候速度跃变
        spdM.PosOld = PMSM.Var.ThetaRT;
    }else
    {
        PMSM.Var.ThetaRT = (int32_t)QEP_read_posn_count(M1_QEP_HANDLE)  & 0xFFF;
    }
#else
    PMSM.Var.ThetaRT = (int32_t)QEP_read_posn_count(M1_QEP_HANDLE)  & 0xFFF;//0.11u
#endif

    // 电流采样计算
    PMSM.Sens.ValueCalc(&PMSM.Sens);

    // 电压采样计算
    VoltsSampISR();

    // 速度采样计算
    spdM.SpeedMeasM(M1_QEP_HANDLE,&spdM);

    if(UserParm.Var.SwapEncoderDir)
    {
        PMSM.Var.Nm    = -spdM.Speedrpm;
    }else
    {
        PMSM.Var.Nm    = spdM.Speedrpm;
    }

#if Loose_DM == 1
    //MARK MBD                                                                          模型算法输入
    PMSM_Input.AgoSample.Speed = 0;//PMSM.Var.Nm;
    PMSM_Input.AgoSample.ThetaRT = 0;//PMSM.Var.ThetaRT;
    PMSM_Input.AgoSample.CurUPu = 0;
    PMSM_Input.AgoSample.CurVPu = 0;
    PMSM_Input.AgoSample.CurWPu = 0;
    PMSM.Sens.CurU = 0;
    PMSM.Sens.CurV = 0;
    PMSM.Sens.CurW = 0;
#else
    //MARK MBD                                                                          模型算法输入
    PMSM_Input.AgoSample.Speed = PMSM.Var.Nm;
    PMSM_Input.AgoSample.ThetaRT = PMSM.Var.ThetaRT;
    PMSM_Input.AgoSample.CurUPu = PMSM.Sens.CurU;// * UserParm.Var.CurBase / 10.0 / SQRT2;
    PMSM_Input.AgoSample.CurVPu = PMSM.Sens.CurV;// * UserParm.Var.CurBase / 10.0 / SQRT2;
    PMSM_Input.AgoSample.CurWPu = PMSM.Sens.CurW;// * UserParm.Var.CurBase / 10.0 / SQRT2;
#endif
//    PMSM_Input.AgoSample.CurBus = 0;  // 母线电流传感器没有，不采集
    PMSM_Input.AgoSample.PosSenFaultState1 =0; //HAL_Coder_Err(halHandle);
    PMSM_Input.AgoSample.PosSenFaultState2 =0; //HAL_Coder_Err(halHandle);
    PMSM_Input.AgoSample.IGBT1FaultState = HAL_Pwm_Fault1(halHandle);
    PMSM_Input.AgoSample.IGBT2FaultState = HAL_Pwm_Fault2(halHandle);
    PMSM_Input.AgoSample.IGBT3FaultState = HAL_Pwm_Fault3(halHandle);

//    检测过压欠压过流程序
//    CurMax = fmaxf(fmaxf(fabsf(PMSM.Sens.CurU), fabsf(PMSM.Sens.CurV)), fabsf(PMSM.Sens.CurW));
//
//    if( PMSM.Var.CurBus > UserParm.Var.DcOverVolt3)
//    {
//        PMSM.FauErr.M3_FAULT_OBJ.DcOverVolt3Err = 1UL;
//        ElcErrCount = 2;
//        HAL_disablePwm(halHandle);
//    }
//    if( CurMax > PMSM_Param.OC2 )
//    {
//        PMSM.FauErr.M3_FAULT_OBJ.AcOverCur2Err = 1UL;
//        ElcErrCount = 2;
//        HAL_disablePwm(halHandle);
//    }

    AgoCall();                                                       // 运行模型函数

    MbdTest.HisFaultCode1 |= App_Output.fault.FaultCode1;
    PwmsParm.Prd = App_Output.ctrl.PwmT * 1000000;//Algo_Output.IGBT_ctrl.PwmPeriod;                  // 电机拖动状态机更新
    if(UserParm.Var.ElecZeroStudyType == 1 && UserParm.Var.CalibratStep == 0)                          // PWM_Test
    {
        Algo_Output.IGBT_ctrl.Svpwm_Ta = 0.47;//0.5
        Algo_Output.IGBT_ctrl.Svpwm_Tb = 0.5;//0.5
        Algo_Output.IGBT_ctrl.Svpwm_Tc = 0.5;//0.47
    }
    PwmsParm.Duty_A = Algo_Output.IGBT_ctrl.Svpwm_Ta;
    PwmsParm.Duty_B = Algo_Output.IGBT_ctrl.Svpwm_Tb;
    PwmsParm.Duty_C = Algo_Output.IGBT_ctrl.Svpwm_Tc;
    PwmsParm.Set(halHandle,&PwmsParm);                               // 执行正常的程序
    if(Algo_Output.IGBT_ctrl.PwmWorkMode == 0)//(  || (ElcErrCount == 2) )                       // 开关管控制
    {
        HAL_disablePwm(halHandle);
//        BlcdeAAACount = 3 ;
    }
    else
    {
        HAL_enablePwm(halHandle);
//        BlcdeAAACount = 1 ;
    }

//    VCU_Comm.Rx(&VCU_Comm);
}



// ================================================================================================
// end of MainISR.c
