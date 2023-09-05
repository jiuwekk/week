/*
 * File: APP_FluxWeak_GEAR2_private.h
 *
 * Code generated for Simulink model 'APP_FluxWeak_GEAR2'.
 *
 * Model version                  : 2.13
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Tue Aug 29 15:47:44 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_APP_FluxWeak_GEAR2_private_h_
#define RTW_HEADER_APP_FluxWeak_GEAR2_private_h_
#include "rtwtypes.h"
#include "APP_FluxWeak_GEAR2.h"

extern const App_Output_bus rtCP_pooled_gRVZbBD5ZDlH;
extern const real32_T rtCP_pooled_DfIv42sDr8HV[3];
extern const real32_T rtCP_pooled_YD7f4mcWNFMg[8];
extern const real32_T rtCP_pooled_vyfCfKRuBarb[50];
extern const real32_T rtCP_pooled_ByObWmDYvzKh[129];

#define rtCP_App_Output_InitialValue   rtCP_pooled_gRVZbBD5ZDlH  /* Expression: []
                                                                  * Referenced by: synthesized block
                                                                  */
#define rtCP_table_tableData           rtCP_pooled_DfIv42sDr8HV  /* Expression: single([0.9 0.92 0.96])
                                                                  * Referenced by: '<S151>/table'
                                                                  */
#define rtCP_table_tableData_o         rtCP_pooled_YD7f4mcWNFMg  /* Expression: single([0.68 0.8 0.85 0.85 0.88 0.9 0.915 0.93])
                                                                  * Referenced by: '<S157>/table'
                                                                  */
#define rtCP_table_tableData_f         rtCP_pooled_vyfCfKRuBarb  /* Expression: single([276,305.414285900371,335.151021151170,366.987754479177,398.387754865150,430.857142340241,464.628570958583,499.142856772346,534.163264882681,570.530612521764,607.167348090537,646.173469771499,685.234693375732,725.581631851890,766.357141994343,807.232652068594,851.608162688508,895.983673308421,940.359183928334,987.285714798385,1035.74285775806,1084.20000071774,1132.65714367742,1180.27142928693,1225.35714309564,1270.44285690436,1315.52857071307,1360.61428452178,1405.69999833050,1439.14285645624,1456.28571372865,1473.42857100106,1490.57142827346,1507.71428554587,1524.85714281828,1542.00000009068,1559.14285736309,1572.04081632949,1572.20408163537,1572.36734694124,1572.53061224712,1572.69387755299,1572.85714285887,1573.02040816475,1573.18367347062,1573.34693877650,1573.51020408237,1573.67346938825,1573.83673469412,1574])
                                                                  * Referenced by: '<S61>/table'
                                                                  */
#define rtCP_uDLookupTable_tableData   rtCP_pooled_ByObWmDYvzKh  /* Expression: single([1,1.00657152180000,1.01212177910000,1.01701406790000,1.02137942920000,1.02529425580000,1.02881050190000,1.03196659080000,1.03479249920000,1.03731250120000,1.03954680000000,1.04151256940000,1.04322465400000,1.04469606060000,1.04593831440000,1.04696172460000,1.04777558760000,1.04838834450000,1.04880770650000,1.04904075560000,1.04910086150000,1.04921556060000,1.04947573830000,1.04986051030000,1.05035193000000,1.05093451130000,1.05159484070000,1.05232126160000,1.05310361440000,1.05393302060000,1.05480170360000,1.05570283860000,1.05663042510000,1.05757917980000,1.05854444510000,1.05952211100000,1.06050854820000,1.06150054980000,1.06249528180000,1.06349023960000,1.06448321020000,1.06547223940000,1.06645560310000,1.06743178180000,1.06839943840000,1.06935739860000,1.07030463380000,1.07124024530000,1.07216345130000,1.07307357410000,1.07397003000000,1.07485231910000,1.07572001730000,1.07657276800000,1.07741027580000,1.07823230000000,1.07903864900000,1.07982917550000,1.08060377210000,1.08136236700000,1.08210492040000,1.08283142140000,1.08354188500000,1.08423634900000,1.08491487210000,1.08557753160000,1.08622442110000,1.08685564880000,1.08747133630000,1.08807161630000,1.08865663210000,1.08922653570000,1.08978148720000,1.09032165330000,1.09084720680000,1.09135832550000,1.09185519180000,1.09233799130000,1.09280691310000,1.09326214850000,1.09370389090000,1.09413233490000,1.09454767650000,1.09495011220000,1.09533983900000,1.09571705360000,1.09608195270000,1.09643473250000,1.09677558820000,1.09710471440000,1.09742230420000,1.09772854970000,1.09802364130000,1.09830776790000,1.09858111670000,1.09884387310000,1.09909622070000,1.09933834080000,1.09957041300000,1.09979261450000,1.10000512050000,1.10020810400000,1.10040173570000,1.10058618390000,1.10076161480000,1.10092819210000,1.10108607740000,1.10123542960000,1.10137640570000,1.10150915990000,1.10163384430000,1.10175060850000,1.10185960010000,1.10196096390000,1.10205484280000,1.10214137710000,1.10222070490000,1.10229296220000,1.10235828260000,1.10241679740000,1.10246863580000,1.10251392490000,1.10255278950000,1.10258535240000,1.10261173420000,1.10263205350000,1.10264642670000,1.10265496830000,1.10265779080000])
                                                                  * Referenced by: '<S175>/1-D Lookup Table'
                                                                  */

extern void LPF_App_Init(DW_LPF_App_T *localDW);
extern void LPF_App_Reset(DW_LPF_App_T *localDW);
extern void LPF_App(real32_T rtu_u, real32_T rtu_Ts, real32_T rtu_N, real32_T
                    *rty_Out1, DW_LPF_App_T *localDW);
extern void APP_FluxWeak_GEAR2_Initial(void);
extern void APP_FluxWeak_GEAR2_Update(const real32_T *rtu_Ctrl, real32_T
  rtu_Data, real32_T rtu_Data_d);
extern void APP_FluxWeak_GEAR2_Torque_Init(DW_Torque_APP_FluxWeak_GEAR2_T
  *localDW);
extern void APP_FluxWeak_GEAR2_Torque(real32_T rtu_data, uint16_T *rty_Out1,
  real32_T *rty_Out1_l, real32_T *rty_Out1_i, real32_T *rty_Out1_g, uint16_T
  *rty_Out1_c, uint16_T *rty_Out1_p, real32_T *rty_Out1_l2, real32_T
  *rty_Out1_gi, real32_T *rty_Tor, DW_Torque_APP_FluxWeak_GEAR2_T *localDW);
extern void APP_FluxWeak_GEAR2_Spd(real32_T rtu_Data, real32_T rtu_Data_o,
  uint16_T *rty_Out1, real32_T *rty_Out1_o, real32_T *rty_Out1_p, real32_T
  *rty_Out1_c, uint16_T *rty_Out1_h, uint16_T *rty_Out1_ox, real32_T *rty_Out1_m,
  real32_T *rty_Out1_mw, real32_T *rty_Tor, DW_Spd_APP_FluxWeak_GEAR2_T *localDW);
extern void PI_App(real32_T rtu_Err, real32_T rtu_Kp, real32_T rtu_KI, real32_T
                   rtu_T, real32_T *rty_PIOut, real32_T *rty_I_State,
                   DW_PI_App_T *localDW);
extern void APP_FluxWeak_GEAR2_Genrate(real32_T rtu_Data, real32_T rtu_Data_d,
  uint16_T *rty_Out1, real32_T *rty_Out1_d, real32_T *rty_Out1_n, real32_T
  *rty_Out1_ni, uint16_T *rty_Out1_g, uint16_T *rty_Out1_h, real32_T *rty_Out1_k,
  real32_T *rty_Out1_d4, real32_T *rty_Tor, DW_Genrate_APP_FluxWeak_GEAR2_T
  *localDW);
extern void APP_FluxWeak_GEAR2_Starter(real32_T rtu_Data, real32_T rtu_Data_c,
  uint16_T *rty_Out1, real32_T *rty_Out1_c, real32_T *rty_Out1_b, real32_T
  *rty_Out1_bt, uint16_T *rty_Out1_i, uint16_T *rty_Out1_cm, real32_T
  *rty_Out1_p, real32_T *rty_Out1_e, real32_T *rty_Tor,
  DW_Starter_APP_FluxWeak_GEAR2_T *localDW);
extern void APP__FunctionCallSubsystem_Init(DW_FunctionCallSubsystem_APP__T
  *localDW);
extern void APP_FunctionCallSubsystem_Reset(DW_FunctionCallSubsystem_APP__T
  *localDW);
extern void A_FunctionCallSubsystem_Disable(real32_T *rty_SlopeTime);
extern void APP_FluxW_FunctionCallSubsystem(real32_T rtu_SlopeLoopOut, uint16_T
  rtu_Gear, real32_T *rty_SlopeTime, DW_FunctionCallSubsystem_APP__T *localDW);
extern void APP_Flu_FunctionCallSubsystem_o(real32_T rtu_TorReq, real32_T
  rtu_Spd_loop, real32_T *rty_Out1);
extern void APP_Flux_FunctionCallSubsystem2(real32_T *rty_Out1,
  DW_FunctionCallSubsystem2_APP_T *localDW);
extern void APP_Flux_FunctionCallSubsystem1(real32_T rtu_TorReq, real32_T
  rtu_Spd_loop, real32_T *rty_Out1);
extern void APP_FluxWeak_GEAR2_Initial_e(const real32_T *rtu_out);
extern void APP_FluxWeak_GEAR2_Slope_Init(DW_Slope_APP_FluxWeak_GEAR2_T *localDW);
extern void APP_FluxWeak_GEAR2_Slope_Enable(DW_Slope_APP_FluxWeak_GEAR2_T
  *localDW);
extern void APP_FluxWeak_GEAR_Slope_Disable(DW_Slope_APP_FluxWeak_GEAR2_T
  *localDW);
extern void APP_FluxWeak_GEAR2_Slope(real32_T rtu_Data, real32_T rtu_Data_a,
  uint16_T rtu_Data_j, uint16_T rtu_Data_g, real32_T rtu_Data_l, real32_T
  rtu_Data_i, uint16_T *rty_Out1, real32_T *rty_Out1_a, real32_T *rty_Out1_j,
  real32_T *rty_Out1_g, uint16_T *rty_Out1_l, uint16_T *rty_Out1_i, real32_T
  *rty_Out1_c, real32_T *rty_Out1_o, real32_T *rty_Tor,
  DW_Slope_APP_FluxWeak_GEAR2_T *localDW);
extern void APP_FluxWeak_GEAR2_Sync(real32_T rtu_Data, real32_T rtu_Data_e,
  uint16_T *rty_Out1, real32_T *rty_Out1_e, real32_T *rty_Out1_g, real32_T
  *rty_Out1_g5, uint16_T *rty_Out1_c, uint16_T *rty_Out1_i, real32_T *rty_Out1_k,
  real32_T *rty_Out1_ed, real32_T *rty_Tor, DW_Sync_APP_FluxWeak_GEAR2_T
  *localDW);
extern void APP_FluxWeak_GEAR2_Dischg(real32_T rtu_Data, uint16_T *rty_Out1,
  real32_T *rty_Out1_d, real32_T *rty_Out1_j, real32_T *rty_Out1_b, uint16_T
  *rty_Out1_o, uint16_T *rty_Out1_k, real32_T *rty_Out1_c, real32_T *rty_Out1_l,
  DW_Dischg_APP_FluxWeak_GEAR2_T *localDW);
extern void APP_FluxWeak_GEAR2_ASC(uint16_T *rty_Out1, real32_T *rty_Out1_e,
  real32_T *rty_Out1_l, real32_T *rty_Out1_i, uint16_T *rty_Out1_f, uint16_T
  *rty_Out1_g, real32_T *rty_Out1_gu, real32_T *rty_Out1_k);
extern void APP_FluxWeak_GE_PhaseStudy_Init(DW_PhaseStudy_APP_FluxWeak_GE_T
  *localDW);
extern void APP_FluxWeak_GEAR2_PhaseStudy(real32_T rtu_Data, real32_T rtu_Data_g,
  uint16_T *rty_Out1, real32_T *rty_Out1_g, real32_T *rty_Out1_h, real32_T
  *rty_Out1_i, uint16_T *rty_Out1_a, uint16_T *rty_Out1_a3, real32_T
  *rty_Out1_at, real32_T *rty_Out1_gs, DW_PhaseStudy_APP_FluxWeak_GE_T *localDW);
extern void APP_FluxWeak_GEAR2_Hall_Init(DW_Hall_APP_FluxWeak_GEAR2_T *localDW);
extern void APP_FluxWeak_GEAR2_Hall_Reset(DW_Hall_APP_FluxWeak_GEAR2_T *localDW);
extern void APP_FluxWeak_GEAR2_Hall(real32_T rtu_Data, uint16_T *rty_Out1,
  real32_T *rty_Out1_c, real32_T *rty_Out1_h, real32_T *rty_Out1_d, uint16_T
  *rty_Out1_n, uint16_T *rty_Out1_p, real32_T *rty_Out1_db, real32_T *rty_Out1_b,
  DW_Hall_APP_FluxWeak_GEAR2_T *localDW);
extern void APP_FluxWeak_ElecZeroStudy_Init(DW_ElecZeroStudy_APP_FluxWeak_T
  *localDW);
extern void APP_FluxWeak_GEAR_ElecZeroStudy(uint16_T rtu_Data, real32_T
  rtu_Data_b, real32_T rtu_Data_n, real32_T rtu_Data_j, real32_T rtu_Data_o,
  uint16_T *rty_Out1, real32_T *rty_Out1_b, real32_T *rty_Out1_n, real32_T
  *rty_Out1_j, uint16_T *rty_Out1_o, uint16_T *rty_Out1_j3, real32_T *rty_Out1_k,
  real32_T *rty_Out1_e, DW_ElecZeroStudy_APP_FluxWeak_T *localDW);
extern void APP_FluxWeak_GEAR_IdqStudy_Init(DW_IdqStudy_APP_FluxWeak_GEAR_T
  *localDW);
extern void APP_FluxWeak_GEA_IdqStudy_Reset(DW_IdqStudy_APP_FluxWeak_GEAR_T
  *localDW);
extern void APP_FluxWeak_GEAR2_IdqStudy(real32_T rtu_Data, real32_T rtu_Data_p,
  uint16_T *rty_Out1, real32_T *rty_Out1_p, real32_T *rty_Out1_f, real32_T
  *rty_Out1_g, uint16_T *rty_Out1_o, uint16_T *rty_Out1_i, real32_T *rty_Out1_n,
  real32_T *rty_Out1_d, DW_IdqStudy_APP_FluxWeak_GEAR_T *localDW);
extern void APP_FluxWeak_G_FluxLinkage_Init(DW_FluxLinkage_APP_FluxWeak_G_T
  *localDW);
extern void APP_FluxWeak__FluxLinkage_Reset(DW_FluxLinkage_APP_FluxWeak_G_T
  *localDW);
extern void APP_FluxWeak_GEAR2_FluxLinkage(real32_T rtu_Data, uint16_T *rty_Out1,
  real32_T *rty_Out1_n, real32_T *rty_Out1_i, real32_T *rty_Out1_a, uint16_T
  *rty_Out1_h, uint16_T *rty_Out1_k, real32_T *rty_Out1_c, real32_T *rty_Out1_im,
  DW_FluxLinkage_APP_FluxWeak_G_T *localDW);
extern void APP_FluxWeak_GEA_MtpaStudy_Init(DW_MtpaStudy_APP_FluxWeak_GEA_T
  *localDW);
extern void APP_FluxWeak_GEAR2_MtpaStudy(real32_T rtu_Data, real32_T rtu_Data_c,
  real32_T rtu_Data_p, uint16_T *rty_Out1, real32_T *rty_Out1_c, real32_T
  *rty_Out1_p, real32_T *rty_Out1_l, uint16_T *rty_Out1_m, uint16_T *rty_Out1_f,
  real32_T *rty_Out1_h, real32_T *rty_Out1_cv, DW_MtpaStudy_APP_FluxWeak_GEA_T
  *localDW);
extern void APP_FluxWeak_GEAR2_Tlin(real32_T rtu_Data, uint16_T *rty_Out1,
  real32_T *rty_Out1_o, real32_T *rty_Out1_k, real32_T *rty_Out1_oy, uint16_T
  *rty_Out1_p, uint16_T *rty_Out1_d, real32_T *rty_Out1_km, real32_T *rty_Out1_i);
extern void APP_FluxWeak_GEAR2_Calib_Init(DW_Calib_APP_FluxWeak_GEAR2_T *localDW);
extern void APP_FluxWeak_GEAR2_Calib_Reset(DW_Calib_APP_FluxWeak_GEAR2_T
  *localDW);
extern void APP_FluxWeak_GEAR2_Calib_Enable(DW_Calib_APP_FluxWeak_GEAR2_T
  *localDW);
extern void APP_FluxWeak_GEAR2_Calib(uint16_T rtu_Data, real32_T rtu_Data_h,
  real32_T rtu_Data_b, uint16_T rtu_Data_c, real32_T rtu_Data_g, real32_T
  rtu_Data_hs, real32_T rtu_Data_l, real32_T rtu_Data_e, uint16_T *rty_Out1,
  real32_T *rty_Out1_h, real32_T *rty_Out1_b, real32_T *rty_Out1_c, uint16_T
  *rty_Out1_g, uint16_T *rty_Out1_hs, real32_T *rty_Out1_l, real32_T *rty_Out1_e,
  DW_Calib_APP_FluxWeak_GEAR2_T *localDW);
extern void APP_FluxWeak_GEAR2_Initial_D(void);
extern void APP_FluxWeak_GEA_UVW_check_Init(DW_UVW_check_APP_FluxWeak_GEA_T
  *localDW);
extern void APP_FluxWeak_GE_UVW_check_Reset(DW_UVW_check_APP_FluxWeak_GEA_T
  *localDW);
extern void APP_FluxWeak_GEAR2_UVW_check(real32_T rtu_Data, real32_T rtu_Data_l,
  real32_T rtu_Data_h, uint16_T *rty_UVWCheckOut, real32_T *rty_UVWCheckOut_l,
  real32_T *rty_UVWCheckOut_h, real32_T *rty_UVWCheckOut_p, uint16_T
  *rty_UVWCheckOut_j, uint16_T *rty_UVWCheckOut_b, real32_T *rty_UVWCheckOut_a,
  real32_T *rty_UVWCheckOut_b3, uint16_T *rty_UVWFault,
  DW_UVW_check_APP_FluxWeak_GEA_T *localDW);
extern void APP_FluxWeak_GEAR2_Lim_state(void);
extern void AP_FunctionCallSubsystem_a_Init(real32_T *rty_PIOut);
extern void APP_Flu_FunctionCallSubsystem_p(real32_T rtu_Err, real32_T
  *rty_PIOut, DW_FunctionCallSubsystem_AP_g_T *localDW);
extern void APP_FluxWeak_GEAR2_Chart_Init(real32_T *rty_0,
  DW_Chart_APP_FluxWeak_GEAR2_T *localDW);
extern void APP_FluxWeak_GEAR2_Chart_Reset(DW_Chart_APP_FluxWeak_GEAR2_T
  *localDW);
extern void APP_FluxWeak_GEAR2_Chart(real32_T rtu_0, real32_T *rty_0,
  DW_Chart_APP_FluxWeak_GEAR2_T *localDW);
extern void APP_FluxWeak_GEAR2_Lim_coef(real32_T rtu_u, real32_T rtu_up_p,
  real32_T rtu_down_p, real32_T *rty_coef);
extern void APP_FluxWeak_GEAR2_n2MaxT(real32_T rtu_Psi, real32_T *rty_Tmax);

#endif                                 /* RTW_HEADER_APP_FluxWeak_GEAR2_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
