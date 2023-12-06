// ================================================================================================
//! \file       CanUpper.c
//! \brief      与松正上位机通讯
//! \author     xjh
//! \version    1.0.0
//! \date       2019年10月08日
//! \copyright  SANTROLL.
// ================================================================================================
MONSOFT_OBJ MonSoft = MONSOFT_OBJ_DEFAULTS;                  //!< 上位机通讯Object
WATCH_OBJ Watch = WATCH_OBJ_DEFAULTS;                        //!< 上位机监控变量

#ifdef NEWMONSOFT

void NewMonSoft_Comm(MONSOFT_OBJ* M)
{
    static uint16_t Cmd = 0;
    if((M->Step == 0)&&(ECanaBoxRxRdy(M1_CAN_HANDLE,M->RxBox)))
    {
        M->Step = 1;
        ECanaBoxRxMsg(M1_CAN_HANDLE,&M->Msg,M->RxBox);
        Cmd = M->Msg.Data.D8.MD0;
    }

    if((M->Step>0)&&(ECanaBoxTxBsy(M1_CAN_HANDLE,M->TxBox)==0))
    {
        switch(Cmd)
        {
            case 0x5A:
            {
                M->Watch(M);
                break;
            }
            case 0x51:
            {
                M->ReadAll(M);
                break;
            }
            case 0x52:
            {
                M->ReadOne(M);
                break;
            }
            case 0x53:
            {
                M->Write(M);
                break;
            }
            case 0x54:
            {
                M->ClrFault(M);
                break;
            }
            case 0x55:
            {
                M->DrawRt(M);
                break;
            }
            default :
            {
                M->Step = 0;
            }
        }
    }
    M->MonDraw.DrawTx(M);

}
void NewMonSoft_Watch(MONSOFT_OBJ* M)
{
    static uint16_t Index = 0;
    static uint16_t Delay = 0;

    if(Delay < 5)
    {
        Delay++;
        return;
    }
#if Watch_TripleIndex == 1
    if((Index * 3) < WATCH_NUM)
    {
        M->Msg.Data.D8.MD0   = 0x05;  // 指令
        M->Msg.Data.D8.MD1   = Index;  // 索引号
        M->Msg.Data.D16.MD23 = Watch.VarPnt[3 *Index];
        M->Msg.Data.D16.MD45 = Watch.VarPnt[3 *Index + 1];
        M->Msg.Data.D16.MD67 = Watch.VarPnt[3 *Index + 2];
        ECanaBoxTxMsg(M1_CAN_HANDLE,&M->Msg,M->TxBox);
        Index++;
    }
#else
    if(Index < WATCH_NUM)
    {
        M->Msg.Data.D8.MD0   = 0x05;  // 指令
        M->Msg.Data.D8.MD1   = Index;  // 索引号
        M->Msg.Data.D16.MD23 = Watch.VarPnt[Index];
        M->Msg.Data.D16.MD45 = 0;
        M->Msg.Data.D16.MD67 = 0;
        ECanaBoxTxMsg(M1_CAN_HANDLE,&M->Msg,M->TxBox);
        Index++;
    }
#endif
    else if(Index < WATCH_NUM)
    {
        Index = WATCH_NUM;
    }
    else if(Index < (WATCH_NUM+1))
    {
        M->Msg.Data.D8.MD0   = 0x02;    // 指令 实时故障
        M->Msg.Data.D8.MD1   = 0;
        M->Msg.Data.D16.MD23 = PMSM.FaultNow.All[0];
        M->Msg.Data.D16.MD45 = PMSM.FaultNow.All[2];
        M->Msg.Data.D16.MD67 = PMSM.FaultNow.All[3];
        ECanaBoxTxMsg(M1_CAN_HANDLE,&M->Msg,M->TxBox);
        Index++;
    }
    else if(Index < (WATCH_NUM+2))
    {
        M->Msg.Data.D8.MD0   = 0x02;    // 指令 实时故障
        M->Msg.Data.D8.MD1   = 0x01;
        M->Msg.Data.D16.MD23 = 0;
        M->Msg.Data.D16.MD45 = 0;
        M->Msg.Data.D16.MD67 = 0;
        ECanaBoxTxMsg(M1_CAN_HANDLE,&M->Msg,M->TxBox);
        Index++;
    }
    else if(Index < (WATCH_NUM+3))
    {
        M->Msg.Data.D8.MD0   = 0x03;    // 指令 历史故障
        M->Msg.Data.D8.MD1   = 0;
        M->Msg.Data.D16.MD23 = UserParm.Var.FaultHis[0];
        M->Msg.Data.D16.MD45 = UserParm.Var.FaultHis[2];
        M->Msg.Data.D16.MD67 = UserParm.Var.FaultHis[3];
        ECanaBoxTxMsg(M1_CAN_HANDLE,&M->Msg,M->TxBox);
        Index++;
    }
    else if(Index < (WATCH_NUM+4))
    {
        M->Msg.Data.D8.MD0   = 0x03;    // 指令 历史故障
        M->Msg.Data.D8.MD1   = 0x01;
        M->Msg.Data.D16.MD23 = UserParm.Var.FaultHis[7];
        M->Msg.Data.D16.MD45 = UserParm.Var.FaultHis[8];
        M->Msg.Data.D16.MD67 = UserParm.Var.FaultHis[9];
        ECanaBoxTxMsg(M1_CAN_HANDLE,&M->Msg,M->TxBox);
        Index++;
    }
    else if(Index < (WATCH_NUM+5))     // 总运行时间
    {
        M->Msg.Data.D8.MD0   = 0x00;    // 指令 总运行时间
        M->Msg.Data.D8.MD1   = 0x00;
        M->Msg.Data.D16.MD23 = 0;
        M->Msg.Data.D16.MD45 = TotalRunTime & 0xFFFF;
        M->Msg.Data.D16.MD67 = TotalRunTime >> 16;
        ECanaBoxTxMsg(M1_CAN_HANDLE,&M->Msg,M->TxBox);
        Index++;
    }
    else if(Index < (WATCH_NUM+6))      // 单次运行时间
    {
        M->Msg.Data.D8.MD0   = 0x01;    // 指令 单词运行时间
        M->Msg.Data.D8.MD1   = 0x00;
        M->Msg.Data.D16.MD23 = 0;
        M->Msg.Data.D16.MD45 = SingleRunTime & 0xFFFF;
        M->Msg.Data.D16.MD67 = SingleRunTime >> 16;
        ECanaBoxTxMsg(M1_CAN_HANDLE,&M->Msg,M->TxBox);
        Index++;
    }
    else if(Index < (WATCH_NUM + 7))    // 发送故障发生时间
    {
        Index++;
    }
    else
    {
        Index = 0;
        Delay = 0;
        M->Step = 0;
    }
}

/*********************************
 * 将输入的Uint16数据的十六进制表示转换为字符串
 *********************************/
void Hex2String(Uint16 In , char *pOut)
{
    Uint16 Input;
    char Dig;
    char *pChar;
    char i;
    Input = In;
    pChar = pOut + 3;
    for(i = 0;i<4;i++)
    {
        Dig = Input & 0xf;
        if(Dig < 10)
        {
            *pChar = Dig + 0x30;
        }else
        {
            *pChar = Dig + 0x37;
        }
        Input = Input >> 4;
        pChar--;
    }
    *(pOut + 4) = 0;
}

#define CONTYPE   0x0000

void NewMonSoft_ReadAll(MONSOFT_OBJ* M)
{
    static uint16_t Index = 0;
    static uint16_t VerTxFlg = 0;  // 版本发送标志

    if(Index < (PARM_NUM - 16))
    {
        M->Msg.Data.D16.MD01 = UserParm.VarPnt[16+Index];
        M->Msg.Data.D16.MD23 = 0;
        M->Msg.Data.D16.MD45 = 0;
        M->Msg.Data.D8.MD6 = Index++;
        M->Msg.Data.D8.MD7 = M->ID;
        ECanaBoxTxMsg(M1_CAN_HANDLE,&M->Msg,M->TxBox);
    }
    else if(!VerTxFlg)
    {
#if Soft_Version
        char VersionStr[60] = VER_CHARS;
#else
        char Str[5];
        Uint16 HWVer;
        Uint16 j;
        char VersionStr[30] = "0000_0000_0000_0000_0000";

        VersionStr[0] = 0x20;      //" "
        VersionStr[1] = 0x20;      //" "
        VersionStr[2] = 0x20;      //" "
        VersionStr[3] = 0x4d;      //"M"
        VersionStr[4] = 0x5f;      //"_"
        VersionStr[5] = 0x4d;      //"M"
        VersionStr[6] = 0x4f;      //"O"
        VersionStr[7] = 0x54;      //"T"
        VersionStr[8] = 0x5f;      //"_"
        VersionStr[13] = 0x5f;     //"_"
        VersionStr[18] = 0x5f;     //"_"
        VersionStr[23] = 0x5f;     //"_"

        //算法版本号(旋变零点)
        Hex2String(ELECZERO , Str);
//        Hex2String(0x05 , Str);
        for(j = 0;j < 4;j++)
        {
            VersionStr[j+9] = Str[j];
        }
        //硬件版本
        HWVer = (EVCBD_ID << 11) + (CONTYPE << 6) + MOTOR_ID;   //硬件版本号=控制板代码高5位+功率部分代码中间5位+电机代码低6位
        Hex2String(HWVer , Str);
        for(j = 0;j < 4;j++)
        {
            VersionStr[j+14] = Str[j];
        }
        //客户厂家代码
        Hex2String(COUST_ID , Str);
        for(j = 0;j < 4;j++)
        {
            VersionStr[j+19] = Str[j];
        }
        //功能协议版本号
        Hex2String((FUNCVER << 8) + (PROTTYPE << 4) + PROTVER , Str);
        for(j = 0;j < 4;j++)
        {
            VersionStr[j+24] = Str[j];
        }


        VersionStr[28] = 0;
        VersionStr[29] = 0;
#endif
        static uint16_t i = 0;
        if(i < 10)
        {
            M->Msg.Data.D16.MD01 = VersionStr[6*i]  + (VersionStr[6*i+1] << 8);
            M->Msg.Data.D16.MD23 = VersionStr[6*i+2] + (VersionStr[6*i+3] << 8);
            M->Msg.Data.D16.MD45 = VersionStr[6*i+4] + (VersionStr[6*i+5] << 8);
            M->Msg.Data.D8.MD6 = 245 + i;
            M->Msg.Data.D8.MD7 = M->ID;
            ECanaBoxTxMsg(M1_CAN_HANDLE,&M->Msg,M->TxBox);
            i++;
        }
        else
        {
            VerTxFlg = 1;
            i = 0;
        }
    }
    else
    {
        Index    = 0;
        VerTxFlg = 0;
        M->Step  = 0;
    }
}
void NewMonSoft_ReadOne(MONSOFT_OBJ* M)
{
    static uint16_t Index = 0;

    Index = M->Msg.Data.D8.MD2;
    M->Msg.Data.D16.MD01 = UserParm.VarPnt[16+Index];
    M->Msg.Data.D16.MD23 = 0;
    M->Msg.Data.D16.MD45 = 0;
    M->Msg.Data.D8.MD6 = Index;
    M->Msg.Data.D8.MD7 = M->ID;
    ECanaBoxTxMsg(M1_CAN_HANDLE,&M->Msg,M->TxBox);
    M->Step = 0;
}

void NewMonSoft_Write(MONSOFT_OBJ* M)
{
    static uint16_t Index = 0;
    static uint16_t Value = 0;

    if(M->Step == 1)
    {
        Index = M->Msg.Data.D8.MD2;
        Value = M->Msg.Data.D16.MD45;
        if(( Value>=UserConst[16 + Index].Min)
          &&(Value<=UserConst[16 + Index].Max)
          &&(PARM_NUM >       (16 + Index))
          &&(M->Msg.Data.D8.MD1 == M->ID))
        {
            M->Step++;
            UserParm.StsPnt[16 + Index] = PARM_WRITING;
            UserParm.VarPnt[16 + Index] = Value;
        }
        else
        {
            M->Msg.Data.D8.MD4   = 0;
            M->Step              = 0;
            ECanaBoxTxMsg(M1_CAN_HANDLE,&M->Msg,M->TxBox);
        }

        // 参数版本
        if(Index == 32)
        {
            PMSM.Var.Flags.Bit.ParChangeErr = 1;
        }

        // 旋变零点
        if(Index == 35)
        {
            PMSM.Var.Flags.Bit.ParChangeErr = 1;
        }

        //电流和转速
        if((Index == 49) || (Index == 50))
        {
            PMSM.Var.Flags.Bit.ParChangeErr = 1;
        }

        //电机极对数，旋变极对数，旋变线数，旋变方向
        if((Index == 78) || (Index == 79) || (Index == 80) || (Index == 81))
        {
            PMSM.Var.Flags.Bit.ParChangeErr = 1;
        }


    }
    else if(M->Step == 2)
    {
        if(UserParm.StsPnt[16 + Index] == PARM_IDLE)
        {
            M->Step            = 0;
            M->Msg.Data.D8.MD4 = 1;
            ECanaBoxTxMsg(M1_CAN_HANDLE,&M->Msg,M->TxBox);
        }
        else if(UserParm.StsPnt[16 + Index] == PARM_WRITING)
        {

        }
        else
        {
            M->Step            = 0;
            M->Msg.Data.D8.MD4 = 0;
            ECanaBoxTxMsg(M1_CAN_HANDLE,&M->Msg,M->TxBox);
        }
    }
}

void NewMonSoft_ClrFault(MONSOFT_OBJ* M)
{
    //mark MBD清除历史故障
    MbdTest.HisFaultCode1 = App_Output.fault.FaultCode1;
    if(M->Step == 1)
    {
        if(UserParm.StsPnt[0x00] == PARM_IDLE)
        {
            uint16_t Index = 0;
            M->Step++;
            for(Index = 0; Index < 4 ;Index++)
            {
                UserParm.Var.FaultHis[Index] = PMSM.FaultNow.All[Index];
            }
            UserParm.StsPnt[0x00] = PARM_WRITING;
        }
    }
    else if(M->Step == 2)
    {
        if(UserParm.StsPnt[0x00] == PARM_IDLE)
        {
            M->Msg.Data.D8.MD0 = 0x54;
            M->Msg.Data.D8.MD1 = M->ID;
            M->Msg.Data.D8.MD2 = 0x01;
            M->Step    = 0;
            ECanaBoxTxMsg(M1_CAN_HANDLE,&M->Msg,M->TxBox);
        }
        else if(UserParm.StsPnt[0x00] == PARM_WRITING)
        {
        }
        else
        {
            M->Msg.Data.D8.MD0 = 0x54;
            M->Msg.Data.D8.MD1 = M->ID;
            M->Msg.Data.D8.MD2 = 0x00;
            M->Step    = 0;
            ECanaBoxTxMsg(M1_CAN_HANDLE,&M->Msg,M->TxBox);
        }
    }
}

void NewMonSoft_DrawRt(MONSOFT_OBJ* M)
{
    static uint16_t Index = 0;      // 帧号

    Index = M->Msg.Data.D8.MD1;     // 帧号
    if(M->Step == 1)
    {
        if(Index == 0)
        {
          M->MonDraw.Index0 = M->Msg.Data.D8.MD2;
          M->MonDraw.Index1 = M->Msg.Data.D8.MD3;
          M->MonDraw.Index2 = M->Msg.Data.D8.MD4;
          M->MonDraw.Index3 = M->Msg.Data.D8.MD5;
          M->MonDraw.Index4 = M->Msg.Data.D8.MD6;
          M->MonDraw.Index5 = M->Msg.Data.D8.MD7;
          M->Step = 0;

          if(M->MonDraw.Index0 > (WATCH_NUM - 1)) M->MonDraw.Index0 = WATCH_NUM - 1;
          if(M->MonDraw.Index1 > (WATCH_NUM - 1)) M->MonDraw.Index1 = WATCH_NUM - 1;
          if(M->MonDraw.Index2 > (WATCH_NUM - 1)) M->MonDraw.Index2 = WATCH_NUM - 1;
          if(M->MonDraw.Index3 > (WATCH_NUM - 1)) M->MonDraw.Index3 = WATCH_NUM - 1;
          if(M->MonDraw.Index4 > (WATCH_NUM - 1)) M->MonDraw.Index4 = WATCH_NUM - 1;
          if(M->MonDraw.Index5 > (WATCH_NUM - 1)) M->MonDraw.Index5 = WATCH_NUM - 1;
        }
        else if(Index == 1)
        {
            M->MonDraw.Index6    = M->Msg.Data.D8.MD2;
            M->MonDraw.Index7    = M->Msg.Data.D8.MD3;
            M->MonDraw.TotalNum  = M->Msg.Data.D8.MD6;
            M->MonDraw.RefreshTm = M->Msg.Data.D8.MD7;
            M->Step = 0;

            M->MonDraw.TxTmCnt   = 0;
            M->MonDraw.PeriTmCnt = 0;

            if(M->MonDraw.Index6 > (WATCH_NUM - 1)) M->MonDraw.Index6 = WATCH_NUM - 1;
            if(M->MonDraw.Index7 > (WATCH_NUM - 1)) M->MonDraw.Index7 = WATCH_NUM - 1;

        }
        else
        {
            ;
        }
    }

}

void DrawTx(MONSOFT_OBJ* M)
{
    if(M->MonDraw.TxTmCnt < 1000)    // 发送1S的数据
    {
        M->MonDraw.TxTmCnt++;

        if(M->MonDraw.PeriTmCnt < M->MonDraw.RefreshTm * 10)
        {
            M->MonDraw.PeriTmCnt++;
        }
        else
        {
            M->MonDraw.PeriTmCnt = 0;

            if(M->MonDraw.TotalNum < 2)
            {
                M->MonDraw.Msg1.Data.D16.MD01 = Watch.VarPnt[M->MonDraw.Index0];
                M->MonDraw.Msg1.Data.D16.MD23 = 0;
                M->MonDraw.Msg1.Data.D32.MDH  = 0;
                M->MonDraw.Msg2.Data.D32.MDL  = 0;
                M->MonDraw.Msg2.Data.D32.MDH  = 0;
            }
            else if(M->MonDraw.TotalNum < 3)
            {
                M->MonDraw.Msg1.Data.D16.MD01 = Watch.VarPnt[M->MonDraw.Index0];
                M->MonDraw.Msg1.Data.D16.MD23 = Watch.VarPnt[M->MonDraw.Index1];
                M->MonDraw.Msg1.Data.D32.MDH  = 0;
                M->MonDraw.Msg2.Data.D32.MDL  = 0;
                M->MonDraw.Msg2.Data.D32.MDH  = 0;
            }
            else if(M->MonDraw.TotalNum < 4)
            {
                M->MonDraw.Msg1.Data.D16.MD01 = Watch.VarPnt[M->MonDraw.Index0];
                M->MonDraw.Msg1.Data.D16.MD23 = Watch.VarPnt[M->MonDraw.Index1];
                M->MonDraw.Msg1.Data.D16.MD45 = Watch.VarPnt[M->MonDraw.Index2];
                M->MonDraw.Msg1.Data.D16.MD67 = 0;
                M->MonDraw.Msg2.Data.D32.MDH  = 0;
                M->MonDraw.Msg2.Data.D32.MDL  = 0;
            }
            else if(M->MonDraw.TotalNum < 5)
            {
                M->MonDraw.Msg1.Data.D16.MD01 = Watch.VarPnt[M->MonDraw.Index0];
                M->MonDraw.Msg1.Data.D16.MD23 = Watch.VarPnt[M->MonDraw.Index1];
                M->MonDraw.Msg1.Data.D16.MD45 = Watch.VarPnt[M->MonDraw.Index2];
                M->MonDraw.Msg1.Data.D16.MD67 = Watch.VarPnt[M->MonDraw.Index3];
                M->MonDraw.Msg2.Data.D32.MDH  = 0;
                M->MonDraw.Msg2.Data.D32.MDL  = 0;
            }
            else if(M->MonDraw.TotalNum < 6)
            {
                M->MonDraw.Msg1.Data.D16.MD01 = Watch.VarPnt[M->MonDraw.Index0];
                M->MonDraw.Msg1.Data.D16.MD23 = Watch.VarPnt[M->MonDraw.Index1];
                M->MonDraw.Msg1.Data.D16.MD45 = Watch.VarPnt[M->MonDraw.Index2];
                M->MonDraw.Msg1.Data.D16.MD67 = Watch.VarPnt[M->MonDraw.Index3];
                M->MonDraw.Msg2.Data.D16.MD01 = Watch.VarPnt[M->MonDraw.Index4];
                M->MonDraw.Msg2.Data.D16.MD23 = 0;
                M->MonDraw.Msg2.Data.D32.MDH  = 0;
            }
            else if(M->MonDraw.TotalNum < 7)
            {
                M->MonDraw.Msg1.Data.D16.MD01 = Watch.VarPnt[M->MonDraw.Index0];
                M->MonDraw.Msg1.Data.D16.MD23 = Watch.VarPnt[M->MonDraw.Index1];
                M->MonDraw.Msg1.Data.D16.MD45 = Watch.VarPnt[M->MonDraw.Index2];
                M->MonDraw.Msg1.Data.D16.MD67 = Watch.VarPnt[M->MonDraw.Index3];
                M->MonDraw.Msg2.Data.D16.MD01 = Watch.VarPnt[M->MonDraw.Index4];
                M->MonDraw.Msg2.Data.D16.MD23 = Watch.VarPnt[M->MonDraw.Index5];
                M->MonDraw.Msg2.Data.D32.MDH  = 0;
            }
            else if(M->MonDraw.TotalNum < 8)
            {
                M->MonDraw.Msg1.Data.D16.MD01 = Watch.VarPnt[M->MonDraw.Index0];
                M->MonDraw.Msg1.Data.D16.MD23 = Watch.VarPnt[M->MonDraw.Index1];
                M->MonDraw.Msg1.Data.D16.MD45 = Watch.VarPnt[M->MonDraw.Index2];
                M->MonDraw.Msg1.Data.D16.MD67 = Watch.VarPnt[M->MonDraw.Index3];
                M->MonDraw.Msg2.Data.D16.MD01 = Watch.VarPnt[M->MonDraw.Index4];
                M->MonDraw.Msg2.Data.D16.MD23 = Watch.VarPnt[M->MonDraw.Index5];
                M->MonDraw.Msg2.Data.D16.MD45 = Watch.VarPnt[M->MonDraw.Index6];
                M->MonDraw.Msg2.Data.D16.MD67 = 0;
            }
            else
            {
                M->MonDraw.Msg1.Data.D16.MD01 = Watch.VarPnt[M->MonDraw.Index0];
                M->MonDraw.Msg1.Data.D16.MD23 = Watch.VarPnt[M->MonDraw.Index1];
                M->MonDraw.Msg1.Data.D16.MD45 = Watch.VarPnt[M->MonDraw.Index2];
                M->MonDraw.Msg1.Data.D16.MD67 = Watch.VarPnt[M->MonDraw.Index3];
                M->MonDraw.Msg2.Data.D16.MD01 = Watch.VarPnt[M->MonDraw.Index4];
                M->MonDraw.Msg2.Data.D16.MD23 = Watch.VarPnt[M->MonDraw.Index5];
                M->MonDraw.Msg2.Data.D16.MD45 = Watch.VarPnt[M->MonDraw.Index6];
                M->MonDraw.Msg2.Data.D16.MD67 = Watch.VarPnt[M->MonDraw.Index7];
            }
#if New_Mon_Test
            ECanaBoxTxMsg(M1_CAN_HANDLE,&M->MonDraw.Msg1,M->TxBox1);
#else
            ECanaBoxTxMsg(M1_CAN_HANDLE,&M->MonDraw.Msg1,M->TxBox);
#endif
        }
#if New_Mon_Test
        if(M->MonDraw.PeriTmCnt == 5)
        {
            ECanaBoxTxMsg(M1_CAN_HANDLE,&M->MonDraw.Msg2,M->TxBox2);
        }
#endif
    }
    else
    {
        ;
    }
}
#else
void MonSoft_Comm(MONSOFT_OBJ* M)
{
    static uint16_t Cmd = 0;
    if((M->Step == 0)&&(ECanaBoxRxRdy(M1_CAN_HANDLE,M->RxBox)))
    {
        M->Step = 1;
        ECanaBoxRxMsg(M1_CAN_HANDLE,&M->Msg,M->RxBox);
        Cmd = M->Msg.Data.D8.MD0;
    }

    if((M->Step>0)&&(ECanaBoxTxBsy(M1_CAN_HANDLE,M->TxBox)==0))
    {
        switch(Cmd)
        {
            case 0x5A:
            {
                M->Watch(M);
                break;
            }
            case 0x51:
            {
                M->ReadAll(M);
                break;
            }
            case 0x52:
            {
                M->ReadOne(M);
                break;
            }
            case 0x53:
            {
                M->Write(M);
                break;
            }
            case 0x54:
            {
                M->ClrFault(M);
                break;
            }
            default :
            {
                M->Step = 0;
            }
        }
    }

}
void MonSoft_Watch(MONSOFT_OBJ* M)
{
    static uint16_t Index = 0;
    static uint16_t Delay = 0;

    if(Delay < 5)
    {
        Delay++;
        return;
    }

    if(Index < WATCH_NUM)
    {
        M->Msg.Data.D16.MD01 = Watch.VarPnt[Index];
        M->Msg.Data.D16.MD23 = 0;
        M->Msg.Data.D16.MD45 = 0;
        M->Msg.Data.D8.MD6 = Index++;
        M->Msg.Data.D8.MD7 = M->ID;
        ECanaBoxTxMsg(M1_CAN_HANDLE,&M->Msg,M->TxBox);
    }
    else if(Index < (WATCH_NUM+1))
    {
        M->Msg.Data.D16.MD01 = PMSM.FaultNow.All[0];
        M->Msg.Data.D16.MD23 = PMSM.FaultNow.All[1];
        M->Msg.Data.D16.MD45 = PMSM.FaultNow.All[2];
        M->Msg.Data.D8.MD6 = 0xE0;            /*当前故障索引*/
        M->Msg.Data.D8.MD7 = M->ID;
        ECanaBoxTxMsg(M1_CAN_HANDLE,&M->Msg,M->TxBox);
        Index++;
    }
    else if(Index < (WATCH_NUM+2))
    {
        M->Msg.Data.D16.MD01 = 0;
        M->Msg.Data.D16.MD23 = 0;
        M->Msg.Data.D16.MD45 = 0;
        M->Msg.Data.D8.MD6 = 0xE1;            /*当前故障索引*/
        M->Msg.Data.D8.MD7 = M->ID;
        ECanaBoxTxMsg(M1_CAN_HANDLE,&M->Msg,M->TxBox);
        Index++;
    }
    else if(Index < (WATCH_NUM+3))
    {
        M->Msg.Data.D16.MD01 = UserParm.Var.FaultHis[0];
        M->Msg.Data.D16.MD23 = UserParm.Var.FaultHis[1];
        M->Msg.Data.D16.MD45 = UserParm.Var.FaultHis[2];
        M->Msg.Data.D8.MD6 = 0xF0;            /*历史故障索引*/
        M->Msg.Data.D8.MD7 = M->ID;
        ECanaBoxTxMsg(M1_CAN_HANDLE,&M->Msg,M->TxBox);
        Index++;
    }
    else if(Index < (WATCH_NUM+4))
    {
        M->Msg.Data.D16.MD01 = UserParm.Var.FaultHis[8];
        M->Msg.Data.D16.MD23 = UserParm.Var.FaultHis[9];
        M->Msg.Data.D16.MD45 = UserParm.Var.FaultHis[10];
        M->Msg.Data.D8.MD6 = 0xF1;            /*历史故障索引*/
        M->Msg.Data.D8.MD7 = M->ID;
        ECanaBoxTxMsg(M1_CAN_HANDLE,&M->Msg,M->TxBox);
        Index++;
    }
    else
    {
        Index = 0;
        Delay = 0;
        M->Step = 0;
    }
}

void MonSoft_ReadAll(MONSOFT_OBJ* M)
{
    static uint16_t Index = 0;
    static uint16_t VerTxFlg = 0;  // 版本发送标志

    if(Index < (PARM_NUM - 16))
    {
        M->Msg.Data.D16.MD01 = UserParm.VarPnt[16+Index];
        M->Msg.Data.D16.MD23 = 0;
        M->Msg.Data.D16.MD45 = 0;
        M->Msg.Data.D8.MD6 = Index++;
        M->Msg.Data.D8.MD7 = M->ID;
        ECanaBoxTxMsg(M1_CAN_HANDLE,&M->Msg,M->TxBox);
    }
    else if(!VerTxFlg)
    {
        char VersionStr[24] = VER_CHARS;
        static uint16_t i = 0;
        if(i < 5)
        {
            M->Msg.Data.D16.MD01 = VersionStr[6*i]  + (VersionStr[6*i+1] << 8);
            M->Msg.Data.D16.MD23 = VersionStr[6*i+2] + (VersionStr[6*i+3] << 8);
            M->Msg.Data.D16.MD45 = VersionStr[6*i+4] + (VersionStr[6*i+5] << 8);
            M->Msg.Data.D8.MD6 = 245 + i;
            M->Msg.Data.D8.MD7 = M->ID;
            ECanaBoxTxMsg(M1_CAN_HANDLE,&M->Msg,M->TxBox);
            i++;
        }
        else
        {
            VerTxFlg = 1;
            i = 0;
        }
    }
    else
    {
        Index    = 0;
        VerTxFlg = 0;
        M->Step  = 0;

    }
}
void MonSoft_ReadOne(MONSOFT_OBJ* M)
{
    static uint16_t Index = 0;

    Index = M->Msg.Data.D8.MD1;
    M->Msg.Data.D16.MD01 = UserParm.VarPnt[16+Index];
    M->Msg.Data.D16.MD23 = 0;
    M->Msg.Data.D16.MD45 = 0;
    M->Msg.Data.D8.MD6 = Index;
    M->Msg.Data.D8.MD7 = M->ID;
    ECanaBoxTxMsg(M1_CAN_HANDLE,&M->Msg,M->TxBox);
    M->Step = 0;
}

void MonSoft_Write(MONSOFT_OBJ* M)
{
    static uint16_t Index = 0;
    static uint16_t Value = 0;

    if(M->Step == 1)
    {
        Index = M->Msg.Data.D8.MD2;
        Value = M->Msg.Data.D16.MD45;
        if(( Value>=UserConst[16 + Index].Min)
          &&(Value<=UserConst[16 + Index].Max)
          &&(PARM_NUM >       (16 + Index))
          &&(M->Msg.Data.D8.MD1 == M->ID))
        {
            M->Step++;
            UserParm.StsPnt[16 + Index] = PARM_WRITING;
            UserParm.VarPnt[16 + Index] = Value;
        }
        else
        {
            M->Msg.Data.D8.MD4   = 0;
            M->Step              = 0;
            ECanaBoxTxMsg(M1_CAN_HANDLE,&M->Msg,M->TxBox);
        }
    }
    else if(M->Step == 2)
    {
        if(UserParm.StsPnt[16 + Index] == PARM_IDLE)
        {
            M->Step            = 0;
            M->Msg.Data.D8.MD4 = 1;
            ECanaBoxTxMsg(M1_CAN_HANDLE,&M->Msg,M->TxBox);
        }
        else if(UserParm.StsPnt[16 + Index] == PARM_WRITING)
        {

        }
        else
        {
            M->Step            = 0;
            M->Msg.Data.D8.MD4 = 0;
            ECanaBoxTxMsg(M1_CAN_HANDLE,&M->Msg,M->TxBox);
        }
    }
}

void MonSoft_ClrFault(MONSOFT_OBJ* M)
{
    if(M->Step == 1)
    {
        if(UserParm.StsPnt[0x00] == PARM_IDLE)
        {
            uint16_t Index = 0;
            M->Step++;
            for(Index = 0; Index < 4 ;Index++)
            {
                UserParm.Var.FaultHis[Index] = PMSM.FaultNow.All[Index];
            }
            UserParm.StsPnt[0x00] = PARM_WRITING;
        }
    }
    else if(M->Step == 2)
    {
        if(UserParm.StsPnt[0x00] == PARM_IDLE)
        {
            M->Msg.Data.D8.MD0 = 0x54;
            M->Msg.Data.D8.MD1 = M->ID;
            M->Msg.Data.D8.MD2 = 0x01;
            M->Step    = 0;
            ECanaBoxTxMsg(M1_CAN_HANDLE,&M->Msg,M->TxBox);
        }
        else if(UserParm.StsPnt[0x00] == PARM_WRITING)
        {
        }
        else
        {
            M->Msg.Data.D8.MD0 = 0x54;
            M->Msg.Data.D8.MD1 = M->ID;
            M->Msg.Data.D8.MD2 = 0x00;
            M->Step    = 0;
            ECanaBoxTxMsg(M1_CAN_HANDLE,&M->Msg,M->TxBox);
        }
    }
}

#endif



void Watch_Init(WATCH_OBJ* W)
{
    W->VarPnt = (uint16_t *)&W->Var;
}

// ================================================================================================
// end of CanUpper.c
