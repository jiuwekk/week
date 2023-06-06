/*
 * functions.c
 *
 *  Created on: 2022年2月12日
 *      Author: sz-p783
 */
/* ......................我佛慈悲......................
 *
 *                       _oo0oo_
 *                      o8888888o
 *                      88" . "88
 *                      (| -_- |)
 *                      0\  =  /0
 *                    ___/`---'\___
 *                  .' \\|     |// '.
 *                 / \\|||  :  |||// \
 *                / _||||| -卍-|||||- \
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
 *.....................佛祖开光 ,永无BUG...................
 *         佛曰:
 *                 写字楼里写字间，写字间里程序员；
 *                 程序人员写程序，又拿程序换酒钱。
 *                 酒醒只在网上坐，酒醉还来网下眠；
 *                 酒醉酒醒日复日，网上网下年复年。
 *                 但愿老死电脑间，不愿鞠躬老板前；
 *                 奔驰宝马贵者趣，公交自行程序员。
 *                 别人笑我忒疯癫，我笑自己命太贱；
 *                 不见满街漂亮妹，哪个归得程序员？
 */
/*
 *-------------------|-----------------------------------------------
 *FunctionName       |Mono_Limit_Num
 *-------------------|-----------------------------------------------
 *FunctionDescription|单向限幅函数,达到最大值等于最大值,达到最小值等于最小值
 *-------------------|-----------------------------------------------
 *InputParam         |param1:参与限幅的参数
 *                   |param2:下限最小值
 *                   |param3:上限最大值
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
 *FunctionDescription|循环计数限制函数,达到最大值等于最小值,达到最小值等于最大值
 *-------------------|-----------------------------------------------
 *InputParam         |param1:参与限幅的参数
 *                   |param2:下限最小值
 *                   |param3:上限最大值
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
 *FunctionName       |Schmidt(以函数形式出现还不能实现)
 *-------------------|-----------------------------------------------
 *FunctionDescription|施密特滞环;大于最大值返回1;小于最小值返回0;
 *                   |当最大值与最小值相等时无滞环功能
 *-------------------|-----------------------------------------------
 *InputParam         |param1:参与判断的参数
 *                   |param2:上限最大值
 *                   |param3:下线最小值
 *-------------------|-----------------------------------------------
 *ReturnValue        |有效或无效状态
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
 *FunctionDescription|有效无效状态判定;大于判定值返回1;小于判定值返回0;
 *-------------------|-----------------------------------------------
 *InputParam         |param1:参与判断的参数
 *                   |param2:判定值
 *-------------------|-----------------------------------------------
 *ReturnValue        |有效或无效状态
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
 *FunctionDescription|开关量滤波
 *-------------------|-----------------------------------------------
 *InputParam         |param1:滤波位置,共四个
 *                   |param2:滤波深度,1-8
 *                   |param3:滤波钱参数
 *                   |param4:滤波后参数
 *-------------------|-----------------------------------------------
 *ReturnValue        |滤波后参数
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
 *FunctionDescription|获取故障码函数;轮巡查询故障列表内的故障位,当前位有故障计算得到位数
 *                   |存放在数组内,每帧发送一个故障码
 *-------------------|-----------------------------------------------
 *InputParam         |param1:钥匙信号
 *                   |param2:原始故障码列表
 *                   |param3:故障列表类型:0松正电控故障列表
 *                   |                1外部客户定义的故障列表,选用此选项后需要
 *                   |                       手动将ErrCode结构体内容修改
 *-------------------|-----------------------------------------------
 *ReturnValue        |None
 *-------------------|-----------------------------------------------
 */
void GetFaultCode(uint16_t KSIst,FAULT_OBJ *F,uint16_t Tablestyle)
{
    if(KSIst == 1)
    {
        if(ErrCode.Flags.ui_FaultSndFlag == 0)          //故障一圈发送完成
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
            //故障计数
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
 *FunctionDescription|故障码发送程序,在获取故障位后用此函数的给CAN相关位赋值发送出去,
 *                   |发送速度取决于发送周期,轮巡发送故障码
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
 *FunctionDescription|双组因数交叉判定取值函数,当两个判定条件均生效时返回default
 *                   |当有一个条件生效时取对侧结果值返回,当两个判定条件均不满足时返
 *                   |回两个结果值的最大值
 *-------------------|-----------------------------------------------
 *InputParam         |Param1:判定条件1
 *                   |Param2:判定条件2
 *                   |Param3:判定条件1所对应的结果1
 *                   |Param4:判定条件2所对应的结果2
 *                   |Param5:两个判定条件均生效后的返回值
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
 *FunctionDescription|三组因数交叉判定取值函数,当三个判定条件均生效时返回default
 *                   |当有一个条件生效时对剩余两个判定条件进行判定,其余两个条件再有生效
 *                   |去对侧结果,若余下两个条件都没有生效去的两个结果的最大值,若三个条
 *                   |件均未生效,则取得三个条件对应结果的最大值
 *-------------------|-----------------------------------------------
 *InputParam         |Param1:判定条件1
 *                   |Param2:判定条件2
 *                   |Param3:判定条件3
 *                   |Param4:判定条件1所对应的结果1
 *                   |Param5:判定条件2所对应的结果2
 *                   |Param6:判定条件3所对应的结果3
 *                   |Param7:三个判定条件均生效后的返回值
 *-------------------|-----------------------------------------------
 *ReturnValue        |defaultvalue or Param4 or Param5 or Param6
 *-------------------|-----------------------------------------------
 */
float TripleErrCheck(uint16_t Err1,uint16_t Err2,uint16_t Err3,float Temp1,float Temp2,float Temp3,float defaultvalue)
{
    float TempCache = 0;  // 三个温度比较缓存
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
 *FunctionDescription|交叉取值函数,条件1生效返回结果2,条件2生效返回结果1,两个条件均
 *                   |未生效返回两个结果最大值
 *-------------------|-----------------------------------------------
 *InputParam         |Param1:判定条件1
 *                   |Param2:判定条件2
 *                   |Param3:结果1
 *                   |Param4:结果2
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
