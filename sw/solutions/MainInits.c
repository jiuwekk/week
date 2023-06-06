// ================================================================================================
//! \file       MainInits.c
//! \brief      Ӧ�ò��ʼ����������
//! \author     sunyanjun
//! \version    1.0.0
//! \date       2017��3��23��
//! \copyright  SNATROLL.
// ================================================================================================

void MainInit(void)
{
    // �û�������ʼ��
    UserParm.Init(&UserParm);
    //  PMSM.Var.fRpmToSpdK = (float)UserParm.Var.uiWheelD * 2 * 3.141592653 * 60 / ((float)UserParm.Var.iVehicleRatio * 1000);

    // �ؼ�������ʼ��
    PMSM.FaultMask.All[0] = UserParm.Var.FaultMask1_0;
    PMSM.FaultMask.All[1] = UserParm.Var.FaultMask1_1;
    PMSM.FaultMask.All[2] = UserParm.Var.FaultMask1_2;
    PMSM.FaultMask.All[3] = UserParm.Var.FaultMask1_3;
    PMSM.Var.N_Base       = (float)UserParm.Var.SpeedBase;
    PMSM.Var.PolesRatio   = ((float)UserParm.Var.MotPolePairs) / ((float)UserParm.Var.EncoderPolePairs);
    PMSM_Param.PoleRatio    = PMSM.Var.PolesRatio;
    PMSM_Param.MotPole    = UserParm.Var.MotPolePairs;
    PMSM.Var.PwmOutFreq   = 2000;
    PMSM.Var.PwmOutPeriod = 2000;

    if(UserParm.Var.If > UserParm.Var.CurBase)
    {
        PMSM.Var.If = -1.0;
    }else
    {
        PMSM.Var.If = -(float)UserParm.Var.If / ((float)UserParm.Var.CurBase);
    }

    // ͨ�������ƺ�������������Ld
    PMSM.Var.Ld  = (float)UserParm.Var.Bemf / (float)UserParm.Var.VoltBase * (float)UserParm.Var.SpeedBase / 1000.0 \
                 / ((float)UserParm.Var.If / (float)UserParm.Var.CurBase);

    PMSM.Lpf_Coef.Calc(&PMSM.Lpf_Coef);

    // ���Object��ʼ��
    Watch.Init(&Watch);

    // �������������ٽṹ���ʼ��
    spdM.Lines = (float)UserParm.Var.EncoderSteps* ENCODERPOLEPAIRS;
    spdM.SpeedMeasMInit(M1_QEP_HANDLE,&spdM);

    // ����SVPWM
    if(UserParm.Var.SVPWM_SEGs == 0)
    {
        PMSM.svpwm.SEG57 = SVPWM_SEG5;
    }
    else
    {
        PMSM.svpwm.SEG57 = SVPWM_SEG7;
    }

    PMSM.Var.TabNStart = TABNSTART / (float)UserParm.Var.SpeedBase;
    PMSM.Var.TabNEnd   = TABNEND   / (float)UserParm.Var.SpeedBase;
    PMSM.Var.TabNStep  = (PMSM.Var.TabNEnd - PMSM.Var.TabNStart) / (TABNNUM - 1);
    PMSM.Var.TabNRefU  = TABNREFU;

    // �ϵ�ʱ�������в�����ʼ��
    TotalRunTimePwrOn  = ((uint32_t)UserParm.Var.HourMeterH << 16) + (UserParm.Var.HourMeterL);

    // ���õ���������
    PMSM.Sens.CurU_Coef   = (float)CUR_RANGE/(float)UserParm.Var.CurBase*(1.0/4095.0);
    PMSM.Sens.CurV_Coef   = (float)CUR_RANGE/(float)UserParm.Var.CurBase*(1.0/4095.0);
    PMSM.Sens.CurW_Coef   = (float)CUR_RANGE/(float)UserParm.Var.CurBase*(1.0/4095.0);
    PMSM.Sens.CurBus_Coef = (float)CURBUS_RANGE/(float)UserParm.Var.CurBase*(1.0/4095.0);

#if EVCBD_ID == 0x08 || EVCBD_ID == 0x09 || EVCBD_ID == 0x0D
    //����RDC�ϵ�ʱ��
    Delay_us(5000);
    RDC_RST_Dis(halHandle);
    Delay_us(10000);
    RDC_SAMPLE_L(halHandle);
    Delay_us(10000);
    RDC_SAMPLE_H(halHandle);

#endif
    Uint16 i = 0;
    for(i=0; i < 200; i++)
    {
        Delay_us(3500);// �ȴ�����һ���ٶȣ�
        spdM.SpeedMeasM(M1_QEP_HANDLE,&spdM);
        MotTempSamp();
        InvTempSamp();
    }

    if(fabsf(spdM.Speedrpm * 8.0) < PMSM.Var.N_Base)
    {
#if Loose_DM == 1
        PMSM.Sens.OffsetCalcEn = 0;
#else
        PMSM.Sens.OffsetCalcEn = 1;
#endif
    }
    PMSM.Sens.OffsetCalc(halHandle->adcHandle,&PMSM.Sens);

#if EVCBD_ID == 0x09
    HAL_MOTTEMP_EN1(halHandle);
#endif

    //MARK MBD ģ����س�ʼ��
    APP_FluxWeak_GEAR2_initialize();
    Algorithm_FluxWeak_GEAR2_initialize();


    PMSM.Var.VoltBase_reciprocal = 1.0 / UserParm.Var.VoltBase;
#if 1//��Ϊ�ж���û��ʹ��,���Է��ڳ�ʼ���и�0,����ʹ��֮��ȥ�ж��п���
    PMSM_Input.AgoSample.CurBus = 0;  // ĸ�ߵ���������û�У����ɼ�
    PMSM_Input.AgoSample.PosSenFaultState1 = 0;//HAL_Coder_Err(halHandle);
    PMSM_Input.AgoSample.PosSenFaultState2 = 0;//HAL_Coder_Err(halHandle);
#endif


#if 1
#if EVCBD_ID == 0x08 || EVCBD_ID == 0x09 || EVCBD_ID == 0x0D
    Rdc.Data = AD2S1205_Read(M1_SPI_HANDLE) ;
    PMSM.Var.ThetaRT =Rdc.M1.Loc;
#else
    HAL_WriteResolver(M1_SPI_HANDLE);         // ����λ�ö�ȡ����
    PMSM.Var.ThetaRT = HAL_ReadResolver(M1_SPI_HANDLE); // ����λ�ö�ȡ
#endif
    M1_QEP_HANDLE->QPOSCNT = PMSM.Var.ThetaRT;                          // ��ʼֵ����QPOSCNT
    M1_QEP_HANDLE->QUTMR = EQEP_QCPRD;                                  // ����ת�٣���ֹ�ϵ�ʱ���ٶ�Ծ��
    spdM.PosOld = PMSM.Var.ThetaRT;
#endif

    return;
}

// ================================================================================================
// end of MainInits.c
