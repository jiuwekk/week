// ================================================================================================
//! \file       Globals.c
//! \brief      Ӧ�ò�ȫ�ֱ�������
//! \author     sunyanjun
//! \version    1.0.0
//! \date       2017��3��23��
//! \copyright  SNATROLL.
// ================================================================================================

// ============================================================================
// the includes
#include"sw/config/config.h"

// ================================================================================================
// the globals

I2CMSG I2C_Msg = I2CMSG_DEFAULTS;                            //!< I2C EEPROMͨ��Object
SPEED_MEAS_M spdM = SPEED_MEAS_QEP_DEFAULTS;                 //!< �ٶȼ���Object
PMSM_OBJ PMSM = PMSM_OBJ_DEFAULTS;                           //!< ���ŵ��Object
USER_PARM_OBJ UserParm = USER_PARM_OBJ_DEFAULTS;             //!< �û�����
const CONSTANT_OBJ UserConst[PARM_NUM] = CONSTANT_DEFAULTS;  //!< �û�����Ĭ��ֵ����Сֵ�����ֵ
#if EVCBD_ID == 0x09
MAINDRV_OBJ MainDrv = MAINDRV_OBJ_DEFAULTS;                  //!< ���Ӵ���
#endif
float const TmTab[TABNNUM]            = TM_TAB;
float const IsmTab[TABNNUM]           = ISM_TAB;
float const TLinTab[TABNNUM][TABYNUM] = TLIN_TAB;
float const OmTab[129]                = OMTAB;
//App_Output_bus McuSt;
MBD_TEST_OBJ MbdTest = MBD_TEST_OBJ_DEFAULTS;

RDC_1205   Rdc = {0};

CAN_ISR_TX_OBJ CanIsrTxFlg = CAN_ISR_TX_OBJ_DEFAULTS;
// ================================================================================================
//MARK MBD cos sin sqrt
#if 1
//double cos(double);
//double sin(double);
//double sqrt(double);
float cosf(float x) { return cos(x); }
float sinf(float x) { return sin(x); }
float sqrtf(float x) { return sqrt(x); }
#endif

void ParmInit(USER_PARM_OBJ* v)
{
    uint16_t Value      = 0;
    uint16_t Index      = 0;
    uint32_t VerIndex   = 0;

    // 1. EEPORM ��λ����
    I2C_EEProm_Reset(halHandle->gpioHandle);

    // 2. USER_PARM ����ָ���ʼ����
    v->VarPnt = (uint16_t *)&v->Var;
    v->StsPnt = (uint16_t *)&v->Sts;
    VerIndex = ((uint32_t)&v->Var.ParamBlkVersion) - ((uint32_t)&v->Var);

    // 3. ��EEprom��ȡ����
    for(Index = 0; Index < PARM_NUM;)
    {
        I2C_Msg.ReadStatus = I2C_START;
        I2C_Msg.LowAddr    = Index<<1;
        I2C_Msg.HighAddr   = Index>>7;
        I2C_Msg.ValidBytes = 0x02;
        I2C_Msg.State      = I2C_STATE_READING;
        while(I2C_Msg.State != I2C_STATE_IDLE)
        {
            I2C_Stateflow(M1_I2C_HANDLE,&I2C_Msg);
            Delay_us(80);
        }
        if(I2C_Msg.ReadStatus == I2C_SUCCESS)
        {
            Value = (I2C_Msg.Buffer[1]<<8) + I2C_Msg.Buffer[0];
            if((Value>=UserConst[Index].Min)&&(Value<=UserConst[Index].Max))
            {
                v->VarPnt[Index] = (uint16_t)Value;
                v->StsPnt[Index] = PARM_IDLE; // ��ʼ��
                Index++;
            }
            else
            {
                v->VarPnt[Index] = (uint16_t)UserConst[Index].Var;
                v->StsPnt[Index] = PARM_IDLE; // ��ʼ��
                v->ErrCode = PARM_RANGE_ERR;
                v->ErrIndex = Index++;
            }
        }
        else
        {
            v->ErrCode = PARM_READ_ERR;
            v->ErrIndex = Index++;
        }
    }

    // 4. �������汾���󣬽��û�����Ĭ��ֵд�� EEprom
    if(v->Var.ParamBlkVersion != UserConst[VerIndex].Var)
    {
        // ��EEprom Ϊ��ʱ����������������籣������������
        if(v->Var.ParamBlkVersion == 0xFFFF)
        {
            VerIndex = 0;
        }

        for(Index = VerIndex; Index < PARM_NUM;)
        {
            v->VarPnt[Index]  = (uint16_t)UserConst[Index].Var;
            v->StsPnt[Index]  = PARM_IDLE;

            // д�����
            I2C_Msg.WriteStatus = I2C_START;
            I2C_Msg.LowAddr     = Index<<1;
            I2C_Msg.HighAddr    = Index>>7;
            I2C_Msg.ValidBytes  = 0x02;
            I2C_Msg.Buffer[0]   = UserConst[Index].Var;
            I2C_Msg.Buffer[1]   = UserConst[Index].Var>>8;
            I2C_Msg.State = I2C_STATE_WRITING;
            while(I2C_Msg.State != I2C_STATE_IDLE)
            {
                I2C_Stateflow(M1_I2C_HANDLE,&I2C_Msg);
                Delay_us(80);    // <<40usʱ���ֳ�ʱ����;
            }
            Delay_us(6000);

            // ��ȡ��д��Ĳ���
            I2C_Msg.ReadStatus = I2C_START;
            I2C_Msg.Buffer[0]  = 0;
            I2C_Msg.Buffer[1]  = 0;
            I2C_Msg.State      = I2C_STATE_READING;
            while(I2C_Msg.State != I2C_STATE_IDLE)
            {
                I2C_Stateflow(M1_I2C_HANDLE,&I2C_Msg);
                Delay_us(80);
            }
            if(I2C_Msg.ReadStatus == I2C_SUCCESS)
            {
                Value = (I2C_Msg.Buffer[1]<<8) + I2C_Msg.Buffer[0];
                if(Value == UserConst[Index].Var)
                {
                    Index++;
                }
                else
                {
                    v->StsPnt[Index] = PARM_WRITE_ERR;
                    v->ErrCode = PARM_WRITE_ERR;
                    v->ErrIndex = Index++;
                }
            }
            else
            {
                v->StsPnt[Index] = PARM_WRITE_ERR;
                v->ErrCode = PARM_WRITE_ERR;
                v->ErrIndex = Index++;
            }
        }
    }
}

void ParmStateflow(USER_PARM_OBJ* v)
{
    static uint16_t Step    = 0;
    static uint16_t Index   = 0;
           uint16_t Counter = 0;

    //��ǰ����������Ϻ�,Ѱ����һ���ȴ����µĲ���;
    if(Step == 0)
    {
        if(Index<(PARM_NUM-64))
        {
            for(Counter = Index;Counter<(Index+64);Counter++)
            {

                if(v->StsPnt[Counter]==PARM_WRITING)break;
            }
        }
        else
        {
            for(Counter = Index;Counter<PARM_NUM;Counter++)
            {
                if(v->StsPnt[Counter]==PARM_WRITING)break;
            }
        }
        Index = Counter;
        if(Index >=PARM_NUM) Index=0x00;
    }

    //��������״̬��,��ǰ����������Ϻ�,״̬��ֹͣ;
    if(Step == 0)
    {
        //д������ʼ����Ȼ��ʹ��д����
        uint16_t Temp = 0;
        if(v->StsPnt[Index]==PARM_WRITING)
        {
            Step++;
            I2C_Msg.WriteStatus = I2C_START;
            I2C_Msg.LowAddr     = Index<<1;
            I2C_Msg.HighAddr    = Index>>7;
            if((Index == 0x00)||(Index == 0x10))
            {
                I2C_Msg.ValidBytes = 0x20;
            }
            else
            {
                I2C_Msg.ValidBytes = 0x02;
            }
            for(Temp=0;Temp<I2C_Msg.ValidBytes;Temp+=2)
            {
                I2C_Msg.Buffer[Temp]   = v->VarPnt[Index + (Temp>>1)];
                I2C_Msg.Buffer[Temp+1] = v->VarPnt[Index + (Temp>>1)]>>8;
            }
            I2C_Msg.State = I2C_STATE_WRITING;
        }
    }
    else if(Step == 1)
    {
        //��д������ɺ�,ʹ�ܶ�;
        static uint16_t Delay = 0;
        if(I2C_Msg.State == I2C_STATE_IDLE)
        {
            if(Delay < 6)
            {
                Delay++;
            }
            else
            {
                Step++;
                Delay = 0;
                I2C_Msg.ReadStatus = I2C_START;
                I2C_Msg.LowAddr    = Index<<1;
                I2C_Msg.HighAddr   = Index>>7;
                I2C_Msg.ValidBytes = 0x02;
                I2C_Msg.Buffer[0]  = 0;
                I2C_Msg.Buffer[1]  = 0;
                I2C_Msg.State      = I2C_STATE_READING;
            }
        }
    }
    else if(Step == 2)
    {
        //��������ɺ�,��֮ǰ��д��ֵ�Ƚ�,�����رȽϽ��;
        if(I2C_Msg.State == I2C_STATE_IDLE)
        {
            Step = 0;
            if((I2C_Msg.ReadStatus == I2C_SUCCESS)
               &&(v->VarPnt[Index] == ((I2C_Msg.Buffer[1]<<8) + I2C_Msg.Buffer[0])))
            {
                v->StsPnt[Index] = PARM_IDLE;
            }
            else
            {
                v->StsPnt[Index] = PARM_WRITE_ERR;
                v->ErrCode = PARM_WRITE_ERR;
                v->ErrIndex = Index;
            }
        }
    }
    I2C_Stateflow(M1_I2C_HANDLE,&I2C_Msg);
}

void SensOffsetCalc(ADC_Handle adcHandle,SENSOR_OBJ* S)
{
    int32_t Timer = 0;

    if(S->OffsetCalcEn)
    {
        for(Timer = 0; Timer < 256; Timer++)
        {
            ADC_setSocFrcWord(adcHandle,0xFFFF);
            Delay_us(400);
        }

        for(Timer = 0; Timer < 256; Timer++)
        {
            ADC_setSocFrcWord(adcHandle,0xFFFF);
            Delay_us(400);
        }

        for(Timer = 0; Timer < 256; Timer++)
        {
            ADC_setSocFrcWord(adcHandle,0xFFFF);
            Delay_us(400);
            S->CurU_Offset += M1_CUR_U;
            S->CurV_Offset += M1_CUR_V;
            S->CurW_Offset += M1_CUR_W;
            S->CurBus_Offset += M1_CUR_BUS;
        }
        S->CurU_Offset /= 256;
        S->CurV_Offset /= 256;
        S->CurW_Offset /= 256;
        S->CurBus_Offset /= 256;
    }
    else
    {
        S->CurU_Offset = M1_CUR_U_OFFSET;
        S->CurV_Offset = M1_CUR_V_OFFSET;
        S->CurW_Offset = M1_CUR_W_OFFSET;
        S->CurBus_Offset = M1_CUR_BUS_OFFSET;
    }
}

void SensValueCalc(SENSOR_OBJ* S)
{
#if   CUR_SEN_TYPE == CUR_SEN_plusU_plusV_plusW           //!< [+U +V +W]
    S->CurU = ((float)M1_CUR_U - S->CurU_Offset) * S->CurU_Coef;
    S->CurV = ((float)M1_CUR_V - S->CurV_Offset) * S->CurV_Coef;
    S->CurW = ((float)M1_CUR_W - S->CurW_Offset) * S->CurW_Coef;
#elif CUR_SEN_TYPE == CUR_SEN_mnusU_mnusV_mnusW           //!< [-U -V -W]
    S->CurU = (S->CurU_Offset - (float)M1_CUR_U) * S->CurU_Coef;
    S->CurV = (S->CurV_Offset - (float)M1_CUR_V) * S->CurV_Coef;
    S->CurW = (S->CurW_Offset - (float)M1_CUR_W) * S->CurW_Coef;
#elif CUR_SEN_TYPE == CUR_SEN_plusU_plusV_noneW           //!< [+U +V   ]
    S->CurU = ((float)M1_CUR_U - S->CurU_Offset) * S->CurU_Coef;
    S->CurV = ((float)M1_CUR_V - S->CurV_Offset) * S->CurV_Coef;
    S->CurW = -(S->CurU + S->CurV);
#elif CUR_SEN_TYPE == CUR_SEN_plusU_mnusV_noneW           //!< [+U -V   ]
    S->CurU = ((float)M1_CUR_U - S->CurU_Offset) * S->CurU_Coef;
    S->CurV = (S->CurV_Offset - (float)M1_CUR_V) * S->CurV_Coef;
    S->CurW = -(S->CurU + S->CurV);
#elif CUR_SEN_TYPE == CUR_SEN_mnusU_plusV_noneW           //!< [-U +V   ]
    S->CurU = (S->CurU_Offset - (float)M1_CUR_U) * S->CurU_Coef;
    S->CurV = ((float)M1_CUR_V - S->CurV_Offset) * S->CurV_Coef;
    S->CurW = -(S->CurU + S->CurV);
#elif CUR_SEN_TYPE == CUR_SEN_mnusU_mnusV_noneW           //!< [-U -V   ]
    S->CurU = (S->CurU_Offset - (float)M1_CUR_U) * S->CurU_Coef;
    S->CurV = (S->CurV_Offset - (float)M1_CUR_V) * S->CurV_Coef;
    S->CurW = -(S->CurU + S->CurV);
#elif CUR_SEN_TYPE == CUR_SEN_plusU_noneV_plusW           //!< [+U    +W]
    S->CurU = ((float)M1_CUR_U - S->CurU_Offset) * S->CurU_Coef;
    S->CurW = ((float)M1_CUR_W - S->CurW_Offset) * S->CurW_Coef;
    S->CurV = -(S->CurU + S->CurW);
#elif CUR_SEN_TYPE == CUR_SEN_plusU_noneV_mnusW           //!< [+U    -W]
    S->CurU = ((float)M1_CUR_U - S->CurU_Offset) * S->CurU_Coef;
    S->CurW = (S->CurW_Offset - (float)M1_CUR_W) * S->CurW_Coef;
    S->CurV = -(S->CurU + S->CurW);
#elif CUR_SEN_TYPE == CUR_SEN_mnusU_noneV_plusW           //!< [-U    +W]
    S->CurU = (S->CurU_Offset - (float)M1_CUR_U) * S->CurU_Coef;
    S->CurW = ((float)M1_CUR_W - S->CurW_Offset) * S->CurW_Coef;
    S->CurV = -(S->CurU + S->CurW);
#elif CUR_SEN_TYPE == CUR_SEN_mnusU_noneV_mnusW           //!< [-U    -W]
    S->CurU = (S->CurU_Offset - (float)M1_CUR_U) * S->CurU_Coef;
    S->CurW = (S->CurW_Offset - (float)M1_CUR_W) * S->CurW_Coef;
    S->CurV = -(S->CurU + S->CurW);
#elif CUR_SEN_TYPE == CUR_SEN_noneU_plusV_plusW           //!< [   +V +W]
    S->CurV = ((float)M1_CUR_V - S->CurV_Offset) * S->CurV_Coef;
    S->CurW = ((float)M1_CUR_W - S->CurW_Offset) * S->CurW_Coef;
    S->CurU = -(S->CurV + S->CurW);
#elif CUR_SEN_TYPE == CUR_SEN_noneU_plusV_mnusW           //!< [   +V -W]
    S->CurV = ((float)M1_CUR_V - S->CurV_Offset) * S->CurV_Coef;
    S->CurW = (S->CurW_Offset - (float)M1_CUR_W) * S->CurW_Coef;
    S->CurU = -(S->CurV + S->CurW);
#elif CUR_SEN_TYPE == CUR_SEN_noneU_mnusV_plusW           //!< [   -V +W]
    S->CurV = (S->CurV_Offset - (float)M1_CUR_V) * S->CurV_Coef;
    S->CurW = ((float)M1_CUR_W - S->CurW_Offset) * S->CurW_Coef;
    S->CurU = -(S->CurV + S->CurW);
#elif CUR_SEN_TYPE == CUR_SEN_noneU_mnusV_mnusW           //!< [   -V -W]
    S->CurV = (S->CurV_Offset - (float)M1_CUR_V) * S->CurV_Coef;
    S->CurW = (S->CurW_Offset - (float)M1_CUR_W) * S->CurW_Coef;
    S->CurU = -(S->CurV + S->CurW);
#else
    S->CurU = 0;
    S->CurV = 0;
    S->CurW = 0;
#endif

    S->CurBus = (M1_CUR_BUS - S->CurBus_Offset) * S->CurBus_Coef;
}


void MotStateUpdate(MOT_STATE_OBJ* S)
{
       S->En.Bit.SW_En           = PMSM.Intf.Cmd.MotGateReq || PMSM.Var.Flags.Bit.ActiveDisChargeEn;
    #if EVCBD_ID == 0x09 && XB05_Precharge_En == 1
       S->En.Bit.HW_EN           = MainDrv.Sts.Bits.PreChargeRdy || PMSM.Var.Flags.Bit.ActiveDisChargeEn;
    #else
       S->En.Bit.HW_EN           = PMSM.Intf.Cmd.DCRelayState || PMSM.Var.Flags.Bit.ActiveDisChargeEn;
    #endif
   // ����ASC��״̬
   S->En.Bit.AcOverCur2ErrAsc  = PMSM.FaultNow.M3_FAULT_OBJ.AcOverCur2Err   && PMSM.Var.Flags.Bit.AscCondOk;
   S->En.Bit.DcOverVolt3ErrAsc = PMSM.FaultNow.M3_FAULT_OBJ.DcOverVolt3Err  && PMSM.Var.Flags.Bit.AscCondOk;
   S->En.Bit.DcUnderVolt3ErrAsc= PMSM.FaultNow.M3_FAULT_OBJ.DcUnderVolt3Err && PMSM.Var.Flags.Bit.AscCondOk;
   S->En.Bit.OverSpd2Asc       = PMSM.FaultNow.M3_FAULT_OBJ.OverSpeed2Err;
   S->En.Bit.PosSensorErr      = PMSM.FaultNow.M3_FAULT_OBJ.PosSensorErr;
   // �ع�״̬
   S->En.Bit.CurSensorErr    = PMSM.FaultNow.M3_FAULT_OBJ.CurSensorErr;
   S->En.Bit.PhaseBrkErr     = PMSM.FaultNow.M3_FAULT_OBJ.PhaseBrkErr;
   S->En.Bit.LogicPowerErr   = PMSM.FaultNow.M3_FAULT_OBJ.LogicPowerErr;
   S->En.Bit.MotStallErr     = 0;//PMSM.FaultNow.M3_FAULT_OBJ.MotStallErr; // ��ת�عܣ�
   S->En.Bit.DcOverVolt3Err  = PMSM.FaultNow.M3_FAULT_OBJ.DcOverVolt3Err && (!PMSM.Var.Flags.Bit.AscCondOk);
   S->En.Bit.DcUnderVolt3Err = PMSM.FaultNow.M3_FAULT_OBJ.DcUnderVolt3Err&& (!PMSM.Var.Flags.Bit.AscCondOk);
   S->En.Bit.AcOverCur2Err   = PMSM.FaultNow.M3_FAULT_OBJ.AcOverCur2Err  && (!PMSM.Var.Flags.Bit.AscCondOk);
   S->En.Bit.PwrMdlErr       = PMSM.FaultNow.M3_FAULT_OBJ.PwrMdlErr;
   S->En.Bit.ParErr          = PMSM.FaultNow.M3_FAULT_OBJ.ParErr;
   S->En.Bit.ParChangeErr    = PMSM.FaultNow.M3_FAULT_OBJ.ParChangeErr;

   S->StateHis = S->State;
   if(S->En.All < 0x02)
   {
       S->State = MOT_State_Idle;
   }
   else if(S->En.All < 0x03)
   {
       S->State = MOT_State_Ready;
   }
   else if(S->En.All < 0x04)
   {
       S->State = MOT_State_OnLine;
   }
   else if(S->En.Bit.AcOverCur2ErrAsc || S->En.Bit.DcOverVolt3ErrAsc || \
           S->En.Bit.DcUnderVolt3ErrAsc || S->En.Bit.OverSpd2Asc || S->En.Bit.PosSensorErr)
   {
       S->State = MOT_State_Asc;
   }
   else
   {
       S->State = MOT_State_OffLine;
   }
}

void Lpf_Calc(LPF_COEF_OBJ* B)
{
    B->Spd_Tr     = (PwmsParm.Prd*0.01)/(float)UserParm.Var.Spd_Tr;
    B->VDC_Tr     = (PwmsParm.Prd*0.01)/(float)UserParm.Var.VDC_Tr;
    B->IDC_Tr     = (PwmsParm.Prd*0.01)/(float)UserParm.Var.IDC_Tr;
    B->LogicV_Tr  = (HAL_MAINLOOP_PRD_us*0.01)/(float)UserParm.Var.LogicV_Tr;
    B->MotTemp_Tr = (HAL_MAINLOOP_PRD_us*0.01)/(float)UserParm.Var.MotTemp_Tr;
    B->InvTemp_Tr = (HAL_MAINLOOP_PRD_us*0.01)/(float)UserParm.Var.InvTemp_Tr;
    B->Is_Tr      = (PwmsParm.Prd*0.01)/(float)UserParm.Var.Is_Tr;
    B->Id_Tr      = (PwmsParm.Prd*0.01)/(float)UserParm.Var.Id_Tr;
    B->Iq_Tr      = (PwmsParm.Prd*0.01)/(float)UserParm.Var.Iq_Tr;
    B->Vs_Tr      = (PwmsParm.Prd*0.01)/(float)UserParm.Var.Vs_Tr;
    B->Vd_Tr      = (PwmsParm.Prd*0.01)/(float)UserParm.Var.Vd_Tr;
    B->Vq_Tr      = (PwmsParm.Prd*0.01)/(float)UserParm.Var.Vq_Tr;
    B->Beta_Tr    = (PwmsParm.Prd*0.01)/(float)UserParm.Var.Beta_Tr;
    B->CutBack_Tr = (HAL_MAINLOOP_PRD_us*0.01)/(float)UserParm.Var.CutBack_Tr;
    B->IpL_Tr     = (PwmsParm.Prd*0.01)/(float)UserParm.Var.IpL_Tr;
    B->nCt_Tr     = (PwmsParm.Prd*0.01)/(float)UserParm.Var.nCt_Tr;
    B->Ins_Tr     = (PwmsParm.Prd*0.01)/(float)UserParm.Var.Ins_Tr;
    B->IsL_Tr     = (PwmsParm.Prd*0.01)/(float)UserParm.Var.IsL_Tr;
    B->iWe_Tr     = (PwmsParm.Prd*0.01)/(float)UserParm.Var.iWe_Tr;
    B->Mr_Tr      = (PwmsParm.Prd*0.01)/(float)UserParm.Var.Mr_Tr;
    B->Vd0_Tr     = (PwmsParm.Prd*0.01)/(float)UserParm.Var.Vd0_Tr;
    B->Vq0_Tr     = (PwmsParm.Prd*0.01)/(float)UserParm.Var.Vq0_Tr;
    B->VdE_Tr     = (PwmsParm.Prd*0.01)/(float)UserParm.Var.VdE_Tr;
    B->VqE_Tr     = (PwmsParm.Prd*0.01)/(float)UserParm.Var.VqE_Tr;
}

#if EVCBD_ID == 0x09 && XB05_Precharge_En == 1
void MainDrvStateflow(void)
{

    static uint16_t TmCnt = 0;  // ������ʱ��
    static uint16_t PwrOnStep = 0;
    static uint16_t VoliDiffTmCnt = 0;  //

    // ���Ӵ�����ֹ���������ء�
//    MainDrv.Sts.Bits.MainDrvSet = PMSM.Intf.Cmd.DCRelayState;    //M3Э��
    MainDrv.Sts.Bits.MainDrvSet = PMSM.Intf.BMS_ST2_IN.BMSST == 3;    //������Э��
    if(!UserParm.Var.MainDrv_En)
    {
        MainDrv.MainOn = MainDrv.Sts.Bits.MainDrvSet;
#if EVCBD_ID == 0x09
            PMSM.Var.PWM1Duty = 1 - Pre_PWM_Hight_Duty;
            HAL_writeDacData(halHandle,PWM_Num_MainRelay, PMSM.Var.PWM1Duty);  // �ض�
#else
            HAL_DRV1_Dis(halHandle);
#endif
        HAL_DRV2_Dis(halHandle);
        PMSM.Var.Flags.Bit.Precharge_Relay_en = 0;
        return;
    }

    // �Ӵ�������ѹ�����
    MainDrv.VoltBus = PMSM.Var.VoltBusFilted;
    MainDrv.VoltCap = PMSM.Var.VoltCapFilted;

    switch(PwrOnStep)
    {
        case 0://Ԥ��׼���׶�
        {
            MainDrv.Sts.Bits.MainDrvSet =0 ; // ������Ԥ��
#if EVCBD_ID == 0x09
            PMSM.Var.PWM1Duty = 1 - Pre_PWM_Hight_Duty;
            HAL_writeDacData(halHandle,PWM_Num_MainRelay, PMSM.Var.PWM1Duty);  // �ض�
#else
            HAL_DRV1_Dis(halHandle);
#endif
            HAL_DRV2_Dis(halHandle);
            PMSM.Var.Flags.Bit.Precharge_Relay_en = 0;
            if(TmCnt < (INITTIME - 50))  // ʱ��ҪС�ڳ�ʼ��ʱ��
            {
                TmCnt++;
            }
            else
            {
                TmCnt = 0;
                PwrOnStep++;
            }
            break;
        }
        case 1://Ԥ�����ѹ���жϽ׶�,�жϳ�ʼ״̬���ѹ���С֤�����ݴ�ʱ�е�
        {
            MainDrv.Sts.Bits.MainDrvSet =0 ; // ������Ԥ��
#if EVCBD_ID == 0x09
            PMSM.Var.PWM1Duty = 1 - Pre_PWM_Hight_Duty;
            HAL_writeDacData(halHandle,PWM_Num_MainRelay, PMSM.Var.PWM1Duty);  // �ض�
#else
            HAL_DRV1_Dis(halHandle);
#endif
            HAL_DRV2_Dis(halHandle);
            PMSM.Var.Flags.Bit.Precharge_Relay_en = 0;
            if(fabsf(MainDrv.VoltBus - MainDrv.VoltCap) > 20) // ѹ�����2V
            {
                PwrOnStep++; // ����
            }
            else
            {
                PwrOnStep = 10; // ����
            }
            break;
        }
        case 2:
        {
            // ������֮�󣬲�����
            //    MainDrv.Sts.Bits.MainDrvSet = PMSM.Intf.Cmd.DCRelayState;    //M3Э��
                MainDrv.Sts.Bits.MainDrvSet = PMSM.Intf.BMS_ST2_IN.BMSST == 3;    //������Э��
            break;
        }
        case 10:
        {
            MainDrv.Sts.Bits.MainDrvSet =0 ; // �ϱ����ϣ�������Ԥ����
            break;
        }
        default:
            break;
    }
    if(PwrOnStep < 5)//ֻ�г�ʼ״̬����ѹ��,�ж�����û�е�,�Ž���Ԥ��
    {
        if((fabsf(MainDrv.VoltBus - MainDrv.VoltCap) > (UserParm.Var.MainDNC_Thr * 2.0)) && MainDrv.MainOn)
        {//�����Ӵ�������״̬��,���ѹ���������һ��ʱ��,����ΪԤ��ʧ��
            VoliDiffTmCnt++;
            if(VoliDiffTmCnt > 500)
            {
                VoliDiffTmCnt = 501;
                MainDrv.Sts.Bits.VoltDiff = 0x01;
            }
        }
        else
        {
            VoliDiffTmCnt = 0;
        }
        if((!MainDrv.Sts.Bits.MainDrvSet))//�����λ��û�и�Ԥ��ָ��
        {
//           MainDrv.Sts.Bits.VoltDiff = 0x00; // ����ط��ᵼ�����Ӵ����������ϲ��ϱ�
           HAL_DRV2_Dis(halHandle);     // û���������ܵ���2019��08.17Ԥ���ջٵ�ԭ��
           PMSM.Var.Flags.Bit.Precharge_Relay_en = 0;
        }
        // �Ӵ������Ͽ���
        if(MainDrv.Sts.Bits.MainDrvSet == 1 && MainDrv.Sts.Bits.PreChargeRdy == 1)//All == 0x03)
        {
           if(MainDrv.Delay3 < (uint16_t)(150000.0/HAL_MAINLOOP_PRD_us))
           {
#if EVCBD_ID == 0x09
        PMSM.Var.PWM1Duty = (float)(480/PMSM.Var.VoltBusFilted);//(UserParm.Var.MainDrvPullInVolt * 0.001);
        HAL_writeDacData(halHandle,PWM_Num_MainRelay, PMSM.Var.PWM1Duty);  // ��
#else
        HAL_DRV1_En(halHandle);
#endif
               MainDrv.Delay3++;
           }
           else
           {
               HAL_DRV2_Dis(halHandle); // xujinhua ��עӦ�����������Ӵ����ٶϿ�Ԥ��
               PMSM.Var.Flags.Bit.Precharge_Relay_en = 0;
               if(MainDrv.Delay3 < (uint16_t)(150000.0/HAL_MAINLOOP_PRD_us + 50))
               {
                   MainDrv.Delay3++; // �Ͽ��Ӵ�����ʱ50ms�ϱ�Ԥ�����
               }
               else
               {
                   MainDrv.MainOn = 0x01;
               }
           }
        }
        else
        {
            if((MainDrv.MainOn == 0x01) && (MainDrv.Sts.Bits.MainDrvSet))
            {;}
            else
            {
                MainDrv.Delay3  = 0x00;
                MainDrv.MainOn = 0x00;
#if EVCBD_ID == 0x09
                PMSM.Var.PWM1Duty = 1 - Pre_PWM_Hight_Duty;
                HAL_writeDacData(halHandle,PWM_Num_MainRelay, PMSM.Var.PWM1Duty);  // �ض�
#else
                HAL_DRV1_Dis(halHandle);
#endif
            }
        }

        // ���Ӵ����Ͽ�������ʶ�𵽹�ѹ3���ϣ�������Ԥ����
        if((MainDrv.MainOn == 0) && PMSM.FaultNow.M3_FAULT_OBJ.DcOverVolt3Err )
        {
            MainDrv.Sts.Bits.MainDrvSet = 0;
        }

        // Ԥ���׼��:
        // ������Ԥ����������Ԥ��;
        // ���Ӵ����Ͽ�,�ٴ�����ǰ�ܹ�����Ԥ��;
        if((!MainDrv.Sts.Bits.MainDrvSet)&&(!MainDrv.Sts.Bits.PreChargeFail))
        {
           MainDrv.State = 0;
           MainDrv.Sts.Bits.PreChargeRdy = 0x00;
        }

        // Ԥ���״̬��
        if(UserParm.Var.PreCharge_En)
        {
           if(MainDrv.Sts.Bits.MainDrvSet)
           {
               switch(MainDrv.State)
               {
                   case 0:// �ɼ���������ݵ�ѹ
                   {
                       MainDrv.State++;
                       MainDrv.Delay0 = 0;
                       MainDrv.Delay1 = 0;
                       MainDrv.Delay2 = 0;
                       MainDrv.VoltCapHis = MainDrv.VoltCap;
                       break;
                   }
                   case 1:// ��Դ���Ӳ���
                   {
                       if(MainDrv.VoltCap < 100)
                       {
                           if((MainDrv.VoltCap - MainDrv.VoltCapHis) < 30)
                           {
                               if(MainDrv.Delay0 < (uint16_t)((1000.0/HAL_MAINLOOP_PRD_us)*(float)UserParm.Var.PreChargeTim1))
                               {
                                   HAL_DRV2_En(halHandle);
                                   PMSM.Var.Flags.Bit.Precharge_Relay_en = 1;
                                   MainDrv.Delay0++;
                               }
                               else
                               {
                                   HAL_DRV2_Dis(halHandle);
                                   PMSM.Var.Flags.Bit.Precharge_Relay_en = 0;
                                   MainDrv.State += 2;
                                   MainDrv.Sts.Bits.PreChargeFail = 0x01;
                               }
                           }
                           else
                           {
                               MainDrv.State++;
                           }
                       }
                       else
                       {
                           MainDrv.State++;
                       }
                       break;
                   }
                   case 2: // ��ʼԤ��
                   {
                       if((MainDrv.VoltBus - MainDrv.VoltCap) > UserParm.Var.MainDNC_Thr)
                       {
                           if(MainDrv.Delay1 < (uint16_t)((1000.0/HAL_MAINLOOP_PRD_us)*(float)UserParm.Var.PreChargeTim2))
                           {
                               HAL_DRV2_En(halHandle);
                               PMSM.Var.Flags.Bit.Precharge_Relay_en = 1;
                               MainDrv.Delay1++;
                           }
                           else
                           {
                               MainDrv.State++;
                               HAL_DRV2_Dis(halHandle);
                               PMSM.Var.Flags.Bit.Precharge_Relay_en = 0;
                               MainDrv.Sts.Bits.PreChargeFail = 0x01;
                           }
                       }
                       else
                       {
                           if(MainDrv.Delay2 < (uint16_t)((1000.0/HAL_MAINLOOP_PRD_us)*(float)UserParm.Var.PreChargeTim3))
                           {
                               HAL_DRV2_En(halHandle);
                               PMSM.Var.Flags.Bit.Precharge_Relay_en = 1;
                               MainDrv.Delay2++;
                           }
                           else
                           {
                               MainDrv.State++;
    //                           HAL_DRV2_Dis(halHandle); // xujinhua ��עӦ�����������Ӵ����ٶϿ�Ԥ��
                               MainDrv.Sts.Bits.PreChargeRdy = 0x01;
                           }
                       }
                       break;
                   }
                   case 3:
                   {// ɶҲ����������ʧ��
                       break;
                   }
                   default:
                   {
                       HAL_DRV2_Dis(halHandle);
                       PMSM.Var.Flags.Bit.Precharge_Relay_en = 0;
                   }
               }
           }
           else
           {;}
        }
        else
        {
           HAL_DRV2_Dis(halHandle);
           PMSM.Var.Flags.Bit.Precharge_Relay_en = 0;
           MainDrv.Sts.Bits.PreChargeFail = 0x00;
           MainDrv.Sts.Bits.PreChargeRdy  = 0x01;
        }
    }
    else
    {
        MainDrv.Sts.Bits.VoltDiff = 0x01; // ���Ӵ���ѹ��������
    }
}

void SflMainVoltComp(void)
{
    static uint16_t TmCnt = 0;  // ���Ӵ������Ϻ����

    if((UserParm.Var.MainDrv_En == 1) && (MainDrv.MainOn == 1)) // �Ӵ�������
    {
        if(TmCnt < 1000) //1s���Ϻ�ʼ����
        {
            TmCnt++;
        }
        else
        {
            if(UserParm.Var.MainDrvCompEn)
            {
                if(PMSM.Var.VoltBusFilted > 480) // ��ѹ����48.0V
                {
                    PMSM.Var.PWM1Duty = (float)(480/PMSM.Var.VoltBusFilted);//UserParm.Var.VoltBase / PMSM.Var.VoltBusFilted * (float)UserParm.Var.MainDrvHoldVolt * 0.001;
                }
                else
                {
                    PMSM.Var.PWM1Duty = Pre_PWM_Hight_Duty;
                }
                if(PMSM.Var.PWM1Duty > 1.0) PMSM.Var.PWM1Duty = 1.0;
            }
            else
            {
                PMSM.Var.PWM1Duty = (float)UserParm.Var.MainDrvHoldVolt * 0.001;
            }
            HAL_writeDacData(halHandle,PWM_Num_MainRelay, PMSM.Var.PWM1Duty);
        }
    }
    else
    {
        TmCnt = 0;
    }
}
#endif

// ================================================================================================
// end of Globals.c
