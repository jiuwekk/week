/*
 * functions.c
 *
 *  Created on: 2022��2��12��
 *      Author: sz-p783
 */
/* ......................�ҷ�ȱ�......................
 *
 *                       _oo0oo_
 *                      o8888888o
 *                      88" . "88
 *                      (| -_- |)
 *                      0\  =  /0
 *                    ___/`---'\___
 *                  .' \\|     |// '.
 *                 / \\|||  :  |||// \
 *                / _||||| -�d-|||||- \
 *               |   | \\\  -  /// |   |
 *               | \_|  ''\---/''  |_/ |
 *               \  .-\__  '-'  ___/-. /
 *             ___'. .'  /--.--\  `. .'___
 *          ."" '<  `.___\_<|>_/___.' >' "".
 *         | | :  `- \`.;`\ _ /`;.`/ - ` : | |
 *         \  \ `_.   \_ __\ /__ _/   .-` /  /
 *     =====`-.____`.___ \_____/___.-`___.-'=====
 *                       `=---='
 *
 *.....................���濪�� ,����BUG...................
 *         ��Ի:
 *                 д��¥��д�ּ䣬д�ּ������Ա��
 *                 ������Աд�������ó��򻻾�Ǯ��
 *                 ����ֻ���������������������ߣ�
 *                 ��������ո��գ����������긴�ꡣ
 *                 ��Ը�������Լ䣬��Ը�Ϲ��ϰ�ǰ��
 *                 ���۱������Ȥ���������г���Ա��
 *                 ����Ц��߯��񲣬��Ц�Լ���̫����
 *                 ��������Ư���ã��ĸ���ó���Ա��
 */
/*
 *-------------------|-----------------------------------------------
 *FunctionName       |Mono_Limit_Num
 *-------------------|-----------------------------------------------
 *FunctionDescription|�����޷�����,�ﵽ���ֵ�������ֵ,�ﵽ��Сֵ������Сֵ
 *-------------------|-----------------------------------------------
 *InputParam         |param1:�����޷��Ĳ���
 *                   |param2:������Сֵ
 *                   |param3:�������ֵ
 *-------------------|-----------------------------------------------
 *ReturnValue        |None
 *-------------------|-----------------------------------------------
 */
void Mono_Limit_Num(int16_t *Num,int16_t MinLim,int16_t MaxLim)
{
    if(*Num>=MaxLim)
    {
        *Num = MaxLim;
    }
    else if(*Num<=MinLim)
    {
        *Num = MinLim;
    }
}
//void Mono_Up_Limit_Num(int16_t *Num,int16_t Lim)
//{
//    if(*Num>Lim) *Num = Lim;
//}
//void Mono_Down_Limit_Num(int16_t *Num,int16_t Lim)
//{
//    if(*Num<Lim) *Num = Lim;
//}
/*
 *-------------------|-----------------------------------------------
 *FunctionName       |Loop_Limit_Num
 *-------------------|-----------------------------------------------
 *FunctionDescription|ѭ���������ƺ���,�ﵽ���ֵ������Сֵ,�ﵽ��Сֵ�������ֵ
 *-------------------|-----------------------------------------------
 *InputParam         |param1:�����޷��Ĳ���
 *                   |param2:������Сֵ
 *                   |param3:�������ֵ
 *-------------------|-----------------------------------------------
 *ReturnValue        |None
 *-------------------|-----------------------------------------------
 */
void Loop_Limit_Num(int16_t *Num,int16_t MinLim,int16_t MaxLim)
{
    if(*Num>=MaxLim)
    {
        *Num = MinLim;
    }
    else if(*Num<=MinLim)
    {
        *Num = MaxLim;
    }
}
//void Loop_Up_Limit_Num(int16_t *Num,int16_t MinLim,int16_t MaxLim)
//{
//    if(*Num>=MaxLim) *Num = MinLim;
//}
//void Loop_Down_Limit_Num(int16_t *Num,int16_t MinLim,int16_t MaxLim)
//{
//    if(*Num<=MinLim) *Num = MaxLim;
//}
/*
 *-------------------|-----------------------------------------------
 *FunctionName       |Schmidt(�Ժ�����ʽ���ֻ�����ʵ��)
 *-------------------|-----------------------------------------------
 *FunctionDescription|ʩ�����ͻ�;�������ֵ����1;С����Сֵ����0;
 *                   |�����ֵ����Сֵ���ʱ���ͻ�����
 *-------------------|-----------------------------------------------
 *InputParam         |param1:�����жϵĲ���
 *                   |param2:�������ֵ
 *                   |param3:������Сֵ
 *-------------------|-----------------------------------------------
 *ReturnValue        |��Ч����Ч״̬
 *-------------------|-----------------------------------------------
 */
uint16_t Schmidt(int16_t cnt,uint16_t maxcnt,uint16_t mincnt)
{
    static uint16_t state = 0;
    if(cnt>=maxcnt)
    {
        state = 1;
    }
    else if(cnt<mincnt)
    {
        state = 0;
    }
    return state;
}
/*
 *-------------------|-----------------------------------------------
 *FunctionName       |On_Off_Judge
 *-------------------|-----------------------------------------------
 *FunctionDescription|��Ч��Ч״̬�ж�;�����ж�ֵ����1;С���ж�ֵ����0;
 *-------------------|-----------------------------------------------
 *InputParam         |param1:�����жϵĲ���
 *                   |param2:�ж�ֵ
 *-------------------|-----------------------------------------------
 *ReturnValue        |��Ч����Ч״̬
 *-------------------|-----------------------------------------------
 */
uint16_t On_Off_Judge(int16_t cnt,uint16_t judgevalue)
{
    uint16_t state = 0;
    if(cnt>=judgevalue)
    {
        state = 1;
    }
    else if(cnt<judgevalue)
    {
        state = 0;
    }
    return state;
}




/*
 *-------------------|-----------------------------------------------
 *FunctionName       |SW_Filter
 *-------------------|-----------------------------------------------
 *FunctionDescription|�������˲�
 *-------------------|-----------------------------------------------
 *InputParam         |param1:�˲�λ��,���ĸ�
 *                   |param2:�˲����,1-8
 *                   |param3:�˲�Ǯ����
 *                   |param4:�˲������
 *-------------------|-----------------------------------------------
 *ReturnValue        |�˲������
 *-------------------|-----------------------------------------------
 */
uint16_t SW_Filter(uint16_t Index,uint16_t FilterTimes,uint16_t IO_NewSta,uint16_t IO_OldSta)
{
    static uint16_t IO_State[4]={0,0,0,0};
    uint16_t TempState;
    if(FilterTimes>8)
    {
        FilterTimes=8;
    }
    else
    {;}
    TempState   =   IO_State[Index];
    TempState <<=   1;
    TempState  +=   IO_NewSta;
    TempState  &=   (0XFF>>(8-FilterTimes));
    IO_State[Index]=TempState;
    if(TempState==0)
    {
        return(0);
    }
    else if(TempState==(0XFF>>(8-FilterTimes)))
    {
        return(1);
    }
    else
    {
        return(IO_OldSta);
    }
}




ERR_CODE_OBJ ErrCode = ERR_CODE_OBJ_DEFAULTS;
unsigned char g_uiFaultCode[344];
/*
 *-------------------|-----------------------------------------------
 *FunctionName       |GetFaultCode
 *-------------------|-----------------------------------------------
 *FunctionDescription|��ȡ�����뺯��;��Ѳ��ѯ�����б��ڵĹ���λ,��ǰλ�й��ϼ���õ�λ��
 *                   |�����������,ÿ֡����һ��������
 *-------------------|-----------------------------------------------
 *InputParam         |param1:Կ���ź�
 *                   |param2:ԭʼ�������б�
 *                   |param3:�����б�����:0������ع����б�
 *                   |                1�ⲿ�ͻ�����Ĺ����б�,ѡ�ô�ѡ�����Ҫ
 *                   |                       �ֶ���ErrCode�ṹ�������޸�
 *-------------------|-----------------------------------------------
 *ReturnValue        |None
 *-------------------|-----------------------------------------------
 */
void GetFaultCode(uint16_t KSIst,FAULT_OBJ *F,uint16_t Tablestyle)
{
    if(KSIst == 1)
    {
        if(ErrCode.Flags.ui_FaultSndFlag == 0)          //����һȦ�������
        {
            if(Tablestyle)
            {
                uint16_t Index = 0;
                for(Index = 0; Index < 4; Index++)
                {
                    ErrCode.Fault.All[Index] = 0;
                }
                ErrCode.Fault.All[0] = F->All[0];
                ErrCode.Fault.All[1] = F->All[1];
                ErrCode.Fault.All[2] = F->All[2];
                ErrCode.Fault.All[3] = F->All[3];
            }
            //���ϼ���
            ErrCode.Flags.ui_FaultFlag = 0;
            ErrCode.Flags.ui_FaultSndFlag = 1;
            uint16_t l_uiBytCount = 0;
            uint16_t l_uiBitCount = 0;
            for(l_uiBytCount = 0; l_uiBytCount < 4; l_uiBytCount++)
            {
                if((F->All[l_uiBytCount]&&(~Tablestyle))||(ErrCode.Fault.All[l_uiBytCount]&&Tablestyle))//
                {
                    for(l_uiBitCount = 0; l_uiBitCount < 16; l_uiBitCount++)
                    {
                        if((((F->All[l_uiBytCount]>>l_uiBitCount)&0x01)&&(~Tablestyle))||((ErrCode.Fault.All[l_uiBytCount]>>l_uiBitCount)&0x01)&&Tablestyle)
                        {
                            g_uiFaultCode[ErrCode.Flags.uiFaultNum] = l_uiBytCount*16 + l_uiBitCount + 1;
                            ErrCode.Flags.uiFaultNum++;
                            ErrCode.Flags.ui_FaultFlag = 1;
                        }
                    }
                }
            }
        }
    }
}
/*
 *-------------------|-----------------------------------------------
 *FunctionName       |Err_Code_SendState
 *-------------------|-----------------------------------------------
 *FunctionDescription|�����뷢�ͳ���,�ڻ�ȡ����λ���ô˺����ĸ�CAN���λ��ֵ���ͳ�ȥ,
 *                   |�����ٶ�ȡ���ڷ�������,��Ѳ���͹�����
 *-------------------|-----------------------------------------------
 *InputParam         |None
 *-------------------|-----------------------------------------------
 *ReturnValue        |Err_Code
 *-------------------|-----------------------------------------------
 */
uint16_t Err_Code_SendState(void)
{
    uint16_t codeout = 0;
    if(ErrCode.Flags.uiFaultNum > 0)
    {
        codeout = g_uiFaultCode[ErrCode.Flags.uiFaultNum-1];
        ErrCode.Flags.uiFaultNum--;
    }
    else
    {
        if(ErrCode.Flags.ui_FaultFlag == 0)
        {
            codeout = 0;
        }
    }
    if(ErrCode.Flags.uiFaultNum == 0)
    {
        ErrCode.Flags.ui_FaultSndFlag = 0;
    }
    else
    {
        ErrCode.Flags.ui_FaultSndFlag = 1;
    }
    return codeout;
}





/*
 *-------------------|-----------------------------------------------
 *FunctionName       |DoubleErrCheck
 *-------------------|-----------------------------------------------
 *FunctionDescription|˫�����������ж�ȡֵ����,�������ж���������Чʱ����default
 *                   |����һ��������Чʱȡ�Բ���ֵ����,�������ж�������������ʱ��
 *                   |���������ֵ�����ֵ
 *-------------------|-----------------------------------------------
 *InputParam         |Param1:�ж�����1
 *                   |Param2:�ж�����2
 *                   |Param3:�ж�����1����Ӧ�Ľ��1
 *                   |Param4:�ж�����2����Ӧ�Ľ��2
 *                   |Param5:�����ж���������Ч��ķ���ֵ
 *-------------------|-----------------------------------------------
 *ReturnValue        |defaultvalue or Param3 or Param4
 *-------------------|-----------------------------------------------
 */
float DoubleErrCheck(uint16_t Err1,uint16_t Err2,float Temp1,float Temp2,float defaultvalue)
{
    float Temptemp = 0;
    if(Err1 && Err2)
        Temptemp = defaultvalue;
    else
        Temptemp = CrossValueFCN(Err1,Err2,Temp1,Temp2);
    return Temptemp;
}
/*
 *-------------------|-----------------------------------------------
 *FunctionName       |TripleErrCheck
 *-------------------|-----------------------------------------------
 *FunctionDescription|�������������ж�ȡֵ����,�������ж���������Чʱ����default
 *                   |����һ��������Чʱ��ʣ�������ж����������ж�,������������������Ч
 *                   |ȥ�Բ���,����������������û����Чȥ��������������ֵ,��������
 *                   |����δ��Ч,��ȡ������������Ӧ��������ֵ
 *-------------------|-----------------------------------------------
 *InputParam         |Param1:�ж�����1
 *                   |Param2:�ж�����2
 *                   |Param3:�ж�����3
 *                   |Param4:�ж�����1����Ӧ�Ľ��1
 *                   |Param5:�ж�����2����Ӧ�Ľ��2
 *                   |Param6:�ж�����3����Ӧ�Ľ��3
 *                   |Param7:�����ж���������Ч��ķ���ֵ
 *-------------------|-----------------------------------------------
 *ReturnValue        |defaultvalue or Param4 or Param5 or Param6
 *-------------------|-----------------------------------------------
 */
float TripleErrCheck(uint16_t Err1,uint16_t Err2,uint16_t Err3,float Temp1,float Temp2,float Temp3,float defaultvalue)
{
    float TempCache = 0;  // �����¶ȱȽϻ���
    float Temptemp = 0;
    if(Err1 && Err2 && Err3)
        Temptemp = defaultvalue;
    else if(Err1)
        Temptemp = CrossValueFCN(Err2,Err3,Temp2,Temp3);
    else if(Err2)
        Temptemp = CrossValueFCN(Err1,Err3,Temp1,Temp3);
    else if(Err3)
        Temptemp = CrossValueFCN(Err1,Err2,Temp1,Temp2);
    else
    {
        TempCache = (Temp1 > Temp2)?Temp1:Temp2;
        Temptemp = (TempCache > Temp3)?TempCache:Temp3;
    }
    return Temptemp;
}
/*
 *-------------------|-----------------------------------------------
 *FunctionName       |CrossValueFCN
 *-------------------|-----------------------------------------------
 *FunctionDescription|����ȡֵ����,����1��Ч���ؽ��2,����2��Ч���ؽ��1,����������
 *                   |δ��Ч��������������ֵ
 *-------------------|-----------------------------------------------
 *InputParam         |Param1:�ж�����1
 *                   |Param2:�ж�����2
 *                   |Param3:���1
 *                   |Param4:���2
 *-------------------|-----------------------------------------------
 *ReturnValue        |The Max value between Param3 and Param4 or
 *                   |Param3 or Param4
 *-------------------|-----------------------------------------------
 */
float CrossValueFCN(uint16_t fault1,uint16_t fault2,float Tempin1,float Tempin2)
{
    float Temptemp = 0;
    if(fault1)
        Temptemp = Tempin2;
    else if(fault2)
        Temptemp = Tempin1;
    else
        Temptemp = (Tempin1 > Tempin2)?Tempin1:Tempin2;
    return Temptemp;
}
