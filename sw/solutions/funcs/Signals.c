// ================================================================================================
//! \file       Signals.c
//! \brief      
//! \author     sunyanjun
//! \version    1.0.0
//! \date       2017年5月2日
//! \copyright  SANTROLL.
// ================================================================================================

void SignalSamp(void)
{
    switch(App_Output.data_process.tick)
    {
        case 0: { KSI_Samp()     ; break; }
        case 1: { SWI_Samp()     ; break; }
        case 2: { MotTempSamp()  ; break; }
        case 3: { InvTempSamp()  ; break; }
        case 4: { VoltsSampLoop(); break; }
    }
}


void VoltsSampLoop(void)
{
	// 以下信号没有进行滤波，暂时没发现滤波的必要性。
	PMSM.Var.Brd05V   = M1_VOLT_05V*(1.0/4095.0) * M1_VOLT_05V_RANGE  ;
	PMSM.Var.Brd12V   = M1_VOLT_12V*(1.0/4095.0) * M1_VOLT_12V_RANGE  ;
	PMSM.Var.Brd24V   = M1_VOLT_24V*(1.0/4095.0) * M1_VOLT_24V_RANGE  ;
	PMSM.Var.Pot1Volt = M1_VOLT_POT1*(1.0/4095.0) * M1_VOLT_POT1_RANGE;
}

void VoltsSampISR(void)
{
	static uint16_t Index = 0;

	// 上电后的首次采样，不经过滤波器，直接赋值，提升跟踪速度。
#if Loose_DM == 1
    PMSM.Var.VoltCap = 3234;
    PMSM.Var.VoltBus = 3234;
#else
    PMSM.Var.VoltCap = M1_VOLT_CAP*(1.0/4095.0) * UserParm.Var.VoltCap_Range;
    PMSM.Var.VoltBus = M1_VOLT_BUS*(1.0/4095.0) * UserParm.Var.VoltBus_Range;
#endif
	if(Index > 1)
	{
		Macro_LPF(PMSM.Var.VoltCap,PMSM.Var.VoltCapFilted,PMSM.Lpf_Coef.VDC_Tr);
		Macro_LPF(PMSM.Var.VoltBus,PMSM.Var.VoltBusFilted,PMSM.Lpf_Coef.VDC_Tr);
	}
	else
	{
		PMSM.Var.VoltCapFilted = PMSM.Var.VoltCap;
		PMSM.Var.VoltBusFilted = PMSM.Var.VoltBus;
		Index++;
	}

    PMSM.Var.VoltBus_pu  = PMSM.Var.VoltBusFilted * PMSM.Var.VoltBase_reciprocal;/// UserParm.Var.VoltBase;//
    PMSM.Var.VoltCap_pu  = PMSM.Var.VoltCapFilted * PMSM.Var.VoltBase_reciprocal;/// UserParm.Var.VoltBase;//
	PMSM.Var.VoltCap_pui = UserParm.Var.VoltBase / PMSM.Var.VoltCapFilted;
//    PMSM.Var.VoltBus_pu  = _IQdiv(PMSM.Var.VoltBusFilted,UserParm.Var.VoltBase);
//    PMSM.Var.VoltCap_pu  = _IQdiv(PMSM.Var.VoltCapFilted,UserParm.Var.VoltBase);
//    PMSM.Var.VoltCap_pui = _IQdiv(UserParm.Var.VoltBase,PMSM.Var.VoltCapFilted);
	PMSM.Var.VoltMax_pu  = (PMSM.Var.VoltBus_pu > PMSM.Var.VoltCap_pu)?PMSM.Var.VoltBus_pu:PMSM.Var.VoltCap_pu;
	if(PMSM.Var.VoltCap_pui > 100.0) PMSM.Var.VoltCap_pui = 100.0;
}

void SWI_Samp(void)
{
//    PMSM.Var.Flags.Bit.SwIn1 = SW_Filter(0, 8, HAL_SW1_IN(halHandle), PMSM.Var.Flags.Bit.SwIn1);
//    PMSM.Var.Flags.Bit.SwIn2 = SW_Filter(1, 8, HAL_SW2_IN(halHandle), PMSM.Var.Flags.Bit.SwIn2);
//    PMSM.Var.Flags.Bit.SwIn3 = SW_Filter(2, 8, HAL_SW3_IN(halHandle), PMSM.Var.Flags.Bit.SwIn3);
//    PMSM.Var.Flags.Bit.SwIn4 = SW_Filter(3, 8, HAL_SW4_IN(halHandle), PMSM.Var.Flags.Bit.SwIn4);
}

void KSI_Samp(void)
{
    // 采用施密特方式
    static uint16_t KsiTmCnt = 0;      // 钥匙开关时间计数
    static uint16_t PosSenErrCnt = 0;  // 位置传感器问题，掉电钥匙保持计数时间
    static uint16_t FanWorkCnt = 0;    // 上电后风扇工作延时启动计数时间
    uint16_t TmThr1,TmThr2,TmThr3;

    TmThr1 = 10;                       // 钥匙开关10ms 施密特滤波
    TmThr2 = TmThr1 << 1;
    TmThr3 = TmThr1 + TmThr2;

    if(HAL_KSI_SW(halHandle))          // 钥匙开启
    {
        if(KsiTmCnt < TmThr3) KsiTmCnt++;
    }
    else
    {
        if(KsiTmCnt > 0) KsiTmCnt--;
    }

    // 施密特
    if(KsiTmCnt >= TmThr2) PMSM.Var.Flags.Bit.KSI_SW = 1;  // 开启
    if(KsiTmCnt <= TmThr1) PMSM.Var.Flags.Bit.KSI_SW = 0;  // 断开

    if(VCU_Comm.ID5.Bit.VcuKeyOn) PMSM.Var.Flags.Bit.KSI_SW = 1;

    if(PMSM.Var.Flags.Bit.KSI_SW)
    {
        HAL_KEEP_POWER_En(halHandle);
        PosSenErrCnt = 0;
        FanWorkCnt++;
    }
    else
    {
       if(PMSM.FaultNow.M3_FAULT_OBJ.PosSensorErr)
       {
           if(PosSenErrCnt > 20000)
           {
               HAL_KEEP_POWER_Dis(halHandle);
           }
           else
           {
               PosSenErrCnt++;
               HAL_KEEP_POWER_En(halHandle);
           }
       }
       else if(fabsf(App_Output.data_process.NmFil) > 500.0)
       {
           HAL_KEEP_POWER_En(halHandle);
           PosSenErrCnt = 0;
       }
       else if(fabsf(App_Output.data_process.NmFil) > 450.0){;}
       else
       {
           HAL_KEEP_POWER_Dis(halHandle);
           PosSenErrCnt = 0;
           FanWorkCnt = 0;
       }
    }
    if(FanWorkCnt >= 1000) FanWorkCnt = 1000;
}

void MotTempSamp(void)
{
	uint16_t MotTempType = UserParm.Var.MotTempType;

#if (PT100_1 == 0) && (PT100_2 == 0)
	MotTempType = 0;
#endif

	float Temp1 = 0;
	float Temp2 = 0;

	switch(MotTempType)
	{
		// 无温度传感器
		case 0:
		{
		    PMSM.Var.MotTemp1 = 25.0;
		    PMSM.Var.MotTemp2 = 25.0;
			PMSM.Var.Flags.Bit.MotTemp1Err = 0;
			PMSM.Var.Flags.Bit.MotTemp2Err = 0;
			break;
		}
		// PT100 电路1
		case 1:
		{
		    Temp1 = 0.116883037631095 * (float)M1_TEMP_MOT1 - 265.5598713124689;
			Temp2 = 0.116883037631095 * (float)M1_TEMP_MOT2 - 265.5598713124689;
		    Macro_LPF(Temp1,PMSM.Var.MotTemp1,0.1);
			Macro_LPF(Temp2,PMSM.Var.MotTemp2,0.1);

            PMSM.Var.Flags.Bit.MotTemp1Err = ((PMSM.Var.MotTemp1 > _IQ(200.0))||(PMSM.Var.MotTemp1 < _IQ(-50.0)))?1:0;
            PMSM.Var.Flags.Bit.MotTemp2Err = ((PMSM.Var.MotTemp2 > _IQ(200.0))||(PMSM.Var.MotTemp2 < _IQ(-50.0)))?1:0;
			break;
		}
		// PT100 电路2
		case 2:
		{
		    Temp1 = 0.075755629515044*(float)M1_TEMP_MOT1 -46.259252208738872;
			Temp2 = 0.075755629515044*(float)M1_TEMP_MOT2 -46.259252208738872;
		    Macro_LPF(Temp1,PMSM.Var.MotTemp1,0.1);
			Macro_LPF(Temp2,PMSM.Var.MotTemp2,0.1);

            PMSM.Var.Flags.Bit.MotTemp1Err = ((PMSM.Var.MotTemp1 > _IQ(200.0))||(PMSM.Var.MotTemp1 < _IQ(-50.0)))?1:0;
            PMSM.Var.Flags.Bit.MotTemp2Err = ((PMSM.Var.MotTemp2 > _IQ(200.0))||(PMSM.Var.MotTemp2 < _IQ(-50.0)))?1:0;
			break;
		}
		case 3:
		{
		    Temp1 = 0.19365*(float)M1_TEMP_MOT1 -258.81;
            Temp2 = 0.19365*(float)M1_TEMP_MOT2 -258.81;
		    Macro_LPF(Temp1,PMSM.Var.MotTemp1,0.1);
            Macro_LPF(Temp2,PMSM.Var.MotTemp2,0.1);

            PMSM.Var.Flags.Bit.MotTemp1Err = ((PMSM.Var.MotTemp1 > _IQ(200.0))||(PMSM.Var.MotTemp1 < _IQ(-50.0)))?1:0;
            PMSM.Var.Flags.Bit.MotTemp2Err = ((PMSM.Var.MotTemp2 > _IQ(200.0))||(PMSM.Var.MotTemp2 < _IQ(-50.0)))?1:0;
		    break;
		}
        case 4: //pt100 PWM控制恒流源 4mA
        {
            Temp1= (2.5962*(float)M1_TEMP_MOT1*3300)/(4095*4.0)-253.74;//281.74;//
            Temp2= (2.5962*(float)M1_TEMP_MOT2*3300)/(4095*4.0)-253.74;//281.74;//
            Macro_LPF(Temp1,PMSM.Var.MotTemp1,0.1);
            Macro_LPF(Temp2,PMSM.Var.MotTemp2,0.1);

            PMSM.Var.Flags.Bit.MotTemp1Err = ((PMSM.Var.MotTemp1 > _IQ(200.0))||(PMSM.Var.MotTemp1 < _IQ(-50.0)))?1:0;
            PMSM.Var.Flags.Bit.MotTemp2Err = ((PMSM.Var.MotTemp2 > _IQ(200.0))||(PMSM.Var.MotTemp2 < _IQ(-50.0)))?1:0;
            break;
        }
	}
	// PT100有无处理
#if PT100_1 == 0
	PMSM.Var.Flags.Bit.MotTemp1Err = 0;
	PMSM.Var.MotTemp1 = PMSM.Var.MotTemp2;
#endif
#if PT100_2 == 0
	PMSM.Var.Flags.Bit.MotTemp2Err = 0;
    PMSM.Var.MotTemp2 = PMSM.Var.MotTemp1;
#endif

    static uint16_t PwrOnFlg = 0;
    if(PwrOnFlg == 0)
    {
        PMSM.Var.MotTemp1His = PMSM.Var.MotTemp1;
        PMSM.Var.MotTemp2His = PMSM.Var.MotTemp2;
        PwrOnFlg = 1;
    }
    else
    {
        PMSM.Var.MotTemp1cal = (fabsf(PMSM.Var.MotTemp1His - PMSM.Var.MotTemp1) > 5.0)?PMSM.Var.MotTemp2:PMSM.Var.MotTemp1;
        PMSM.Var.MotTemp2cal = (fabsf(PMSM.Var.MotTemp2His - PMSM.Var.MotTemp2) > 5.0)?PMSM.Var.MotTemp1:PMSM.Var.MotTemp2;
        PMSM.Var.MotTemp1His = PMSM.Var.MotTemp1cal;
        PMSM.Var.MotTemp2His = PMSM.Var.MotTemp2cal;
    }
    PMSM.Var.MotTemp = DoubleErrCheck(PMSM.Var.Flags.Bit.MotTemp1Err,PMSM.Var.Flags.Bit.MotTemp2Err,\
                                      PMSM.Var.MotTemp1cal,PMSM.Var.MotTemp2cal,185.0);
}

void InvTempSamp(void)
{
	float Temp0 = 0;
	float Temp1 = 0;
	float Temp2 = 0;
	float InvTemp1 = 0;
	float InvTemp2 = 0;
	float InvTemp3 = 0;

	switch(UserParm.Var.InvTempType)
	{
		// 无温度传感器
		case 0:
		{
		    PMSM.Var.InvTemp1 = 25.0;
		    PMSM.Var.InvTemp2 = 25.0;
		    PMSM.Var.InvTemp3 = 25.0;
            PMSM.Var.Flags.Bit.InvTemp1Err = 0;
            PMSM.Var.Flags.Bit.InvTemp2Err = 0;
            PMSM.Var.Flags.Bit.InvTemp3Err = 0;
			break;
		}
		// NTC-473
		case 1:
		{
		    float R = 0;
            float B = 3950;
            // 对数反算IGBT温度
            R = 38477575.7576 / (float)M1_TEMP_INV1 - 6200;
            InvTemp1 = 1.0/(1.0/298.15 + logf(R/50000.0)/B) - 273.15;
            R = 38477575.7576 / (float)M1_TEMP_INV2 - 6200;
            InvTemp2 = 1.0/(1.0/298.15 + logf(R/50000.0)/B) - 273.15;
            R = 38477575.7576 / (float)M1_TEMP_INV3 - 6200;
            InvTemp3 = 1.0/(1.0/298.15 + logf(R/50000.0)/B) - 273.15;

            Macro_LPF(InvTemp1,PMSM.Var.InvTemp1,0.1);
            Macro_LPF(InvTemp2,PMSM.Var.InvTemp2,0.1);
            Macro_LPF(InvTemp3,PMSM.Var.InvTemp3,0.1);

            PMSM.Var.Flags.Bit.InvTemp1Err = ((PMSM.Var.InvTemp1 > _IQ(120.0))||(PMSM.Var.InvTemp1 < _IQ(-50.0)))?1:0;
            PMSM.Var.Flags.Bit.InvTemp2Err = ((PMSM.Var.InvTemp2 > _IQ(120.0))||(PMSM.Var.InvTemp2 < _IQ(-50.0)))?1:0;
            PMSM.Var.Flags.Bit.InvTemp3Err = ((PMSM.Var.InvTemp3 > _IQ(120.0))||(PMSM.Var.InvTemp3 < _IQ(-50.0)))?1:0;
            break;
		}
		// KTY82
		case 2:
		{
		    Temp0 = (float)M1_TEMP_INV1*(1/2048.0);
            Temp1 = Temp0*Temp0;
            Temp2 = Temp1*Temp0;
            InvTemp1 = 53.4378952738342*Temp2 - 206.2452562751326*Temp1 + 395.8908017584957*Temp0 - 176.1799196479099;

            Temp0 = (float)M1_TEMP_INV2*(1/2048.0);
            Temp1 = Temp0*Temp0;
            Temp2 = Temp1*Temp0;
            InvTemp2 = 53.4378952738342*Temp2 - 206.2452562751326*Temp1 + 395.8908017584957*Temp0 - 176.1799196479099;

            Temp0 = (float)M1_TEMP_INV3*(1/2048.0);
            Temp1 = Temp0*Temp0;
            Temp2 = Temp1*Temp0;
            InvTemp3 = 53.4378952738342*Temp2 - 206.2452562751326*Temp1 + 395.8908017584957*Temp0 - 176.1799196479099;

            Macro_LPF(InvTemp1,PMSM.Var.InvTemp1,0.1);
            Macro_LPF(InvTemp2,PMSM.Var.InvTemp2,0.1);
            Macro_LPF(InvTemp3,PMSM.Var.InvTemp3,0.1);

            PMSM.Var.Flags.Bit.InvTemp1Err = ((PMSM.Var.InvTemp1 > _IQ(120.0))||(PMSM.Var.InvTemp1 < _IQ(-50.0)))?1:0;
            PMSM.Var.Flags.Bit.InvTemp2Err = ((PMSM.Var.InvTemp2 > _IQ(120.0))||(PMSM.Var.InvTemp2 < _IQ(-50.0)))?1:0;
            PMSM.Var.Flags.Bit.InvTemp3Err = ((PMSM.Var.InvTemp3 > _IQ(120.0))||(PMSM.Var.InvTemp3 < _IQ(-50.0)))?1:0;
            break;
		}
		case 3:
		{
		    float R = 0;
		    float B = 3375;
		    // 对数反算IGBT温度
            R = 1241212 / (float)M1_TEMP_INV1 - 200;
            InvTemp1 = 1.0/(1.0/298.15 + logf(R/5000.0)/B) - 273.15;
            R = 1241212 / (float)M1_TEMP_INV2 - 200;
            InvTemp2 = 1.0/(1.0/298.15 + logf(R/5000.0)/B) - 273.15;
            R = 1241212 / (float)M1_TEMP_INV3 - 200;
            InvTemp3 = 1.0/(1.0/298.15 + logf(R/5000.0)/B) - 273.15;

            Macro_LPF(InvTemp1,PMSM.Var.InvTemp1,0.1);
            Macro_LPF(InvTemp2,PMSM.Var.InvTemp2,0.1);
            Macro_LPF(InvTemp3,PMSM.Var.InvTemp3,0.1);

            PMSM.Var.Flags.Bit.InvTemp1Err = ((PMSM.Var.InvTemp1 > _IQ(120.0))||(PMSM.Var.InvTemp1 < _IQ(-50.0)))?1:0;
            PMSM.Var.Flags.Bit.InvTemp2Err = ((PMSM.Var.InvTemp2 > _IQ(120.0))||(PMSM.Var.InvTemp2 < _IQ(-50.0)))?1:0;
            PMSM.Var.Flags.Bit.InvTemp3Err = ((PMSM.Var.InvTemp3 > _IQ(120.0))||(PMSM.Var.InvTemp3 < _IQ(-50.0)))?1:0;
		    break;
		}
        case 4: //150R 6.2K分压；
        {
            float R = 0;
            float B = 3375;
            // 对数反算IGBT温度
            R = (float)5.0/(((M1_TEMP_INV1*3.3/4095)*6350/6200)/200) -200;
            InvTemp1 = 1.0/(1.0/298.15 + logf(R/5000.0)/B) - 273.15;
            R = (float)5.0/(((M1_TEMP_INV2*3.3/4095)*6350/6200)/200) -200;
            InvTemp2 = 1.0/(1.0/298.15 + logf(R/5000.0)/B) - 273.15;
            R = (float)5.0/(((M1_TEMP_INV3*3.3/4095)*6350/6200)/200) -200;
            InvTemp3 = 1.0/(1.0/298.15 + logf(R/5000.0)/B) - 273.15;

            Macro_LPF(InvTemp1,PMSM.Var.InvTemp1,0.1);
            Macro_LPF(InvTemp2,PMSM.Var.InvTemp2,0.1);
            Macro_LPF(InvTemp3,PMSM.Var.InvTemp3,0.1);

            PMSM.Var.Flags.Bit.InvTemp1Err = ((PMSM.Var.InvTemp1 > _IQ(120.0))||(PMSM.Var.InvTemp1 < _IQ(-50.0)))?1:0;
            PMSM.Var.Flags.Bit.InvTemp2Err = ((PMSM.Var.InvTemp2 > _IQ(120.0))||(PMSM.Var.InvTemp2 < _IQ(-50.0)))?1:0;
            PMSM.Var.Flags.Bit.InvTemp3Err = ((PMSM.Var.InvTemp3 > _IQ(120.0))||(PMSM.Var.InvTemp3 < _IQ(-50.0)))?1:0;
            break;
        }
        case 5: //双芯片_主控制板
        {
            float R = 0;
            float B = 3375;

            // 对数反算IGBT温度
            R = 1861363.64 / (float)M1_TEMP_INV1 - 200;//(float)5.0/(((M1_TEMP_INV1*3.3/4095)*6350/6200)/200) -200;
            InvTemp1 = 1.0/(1.0/298.15 + logf(R/5000.0)/B) - 273.15;
            R = 1861363.64 / (float)M1_TEMP_INV2 - 200;//(float)5.0/(((M1_TEMP_INV2*3.3/4095)*6350/6200)/200) -200;
            InvTemp2 = 1.0/(1.0/298.15 + logf(R/5000.0)/B) - 273.15;
            R = 1861363.64 / (float)M1_TEMP_INV3 - 200;//(float)5.0/(((M1_TEMP_INV3*3.3/4095)*6350/6200)/200) -200;
            InvTemp3 = 1.0/(1.0/298.15 + logf(R/5000.0)/B) - 273.15;

            Macro_LPF(InvTemp1,PMSM.Var.InvTemp1,0.1);
            Macro_LPF(InvTemp2,PMSM.Var.InvTemp2,0.1);
            Macro_LPF(InvTemp3,PMSM.Var.InvTemp3,0.1);

            PMSM.Var.Flags.Bit.InvTemp1Err = ((PMSM.Var.InvTemp1 > _IQ(120.0))||(PMSM.Var.InvTemp1 < _IQ(-50.0)))?1:0;
            PMSM.Var.Flags.Bit.InvTemp2Err = ((PMSM.Var.InvTemp2 > _IQ(120.0))||(PMSM.Var.InvTemp2 < _IQ(-50.0)))?1:0;
            PMSM.Var.Flags.Bit.InvTemp3Err = ((PMSM.Var.InvTemp3 > _IQ(120.0))||(PMSM.Var.InvTemp3 < _IQ(-50.0)))?1:0;

            break;
        }
        case 6://05xb预留
        {break;}
	}
    PMSM.Var.InvTemp = TripleErrCheck(PMSM.Var.Flags.Bit.InvTemp1Err,\
                                      PMSM.Var.Flags.Bit.InvTemp2Err,\
                                      PMSM.Var.Flags.Bit.InvTemp3Err,\
                                      PMSM.Var.InvTemp1,\
                                      PMSM.Var.InvTemp2,\
                                      PMSM.Var.InvTemp3,105.0);
}



// ================================================================================================
// end of Signals.c
