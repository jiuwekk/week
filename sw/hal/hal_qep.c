//! \file       hal_qep.c
//! \brief      Contains various functions related to the QEP object
//! \author     sunyanjun
//! \version    1.0
//! \date       2017.03.21
//! \copyright  SANTROLL

void HAL_setupQEP(QEP_Handle qepHandle)
{
  // hold the counter in reset
  QEP_reset_counter(qepHandle);

  // set the QPOSINIT register
  QEP_set_posn_init_count(qepHandle, 0);

  // disable all interrupts
  QEP_disable_all_interrupts(qepHandle);

  // clear the interrupt flags
  QEP_clear_all_interrupt_flags(qepHandle);

  // clear the position counter
  QEP_clear_posn_counter(qepHandle);

  // setup the max position
  QEP_set_max_posn_count(qepHandle, 0xFFFFFFFF);

  // setup the QDECCTL register
  QEP_set_QEP_source(qepHandle, QEP_Qsrc_Quad_Count_Mode);
  QEP_disable_sync_out(qepHandle);
  QEP_set_swap_quad_inputs(qepHandle, QEP_Swap_Not_Swapped);
  QEP_disable_gate_index(qepHandle);
  QEP_set_ext_clock_rate(qepHandle, QEP_Xcr_2x_Res);
  QEP_set_A_polarity(qepHandle, QEP_Qap_No_Effect);
  QEP_set_B_polarity(qepHandle, QEP_Qbp_No_Effect);
  QEP_set_index_polarity(qepHandle, QEP_Qip_No_Effect);

  // setup the QUPRD register
  QEP_set_unit_period(qepHandle,EQEP_QCPRD);

  // setup the QEPCTL register
  QEP_set_emu_control(qepHandle, QEPCTL_Freesoft_Unaffected_Halt);
  QEP_set_posn_count_reset_mode(qepHandle, QEPCTL_Pcrm_Max_Reset);
  QEP_set_strobe_event_init(qepHandle, QEPCTL_Sei_Nothing);
  QEP_set_index_event_init(qepHandle, QEPCTL_Iei_Nothing);
  QEP_set_index_event_latch(qepHandle, QEPCTL_Iel_Rising_Edge);
  QEP_set_soft_init(qepHandle, QEPCTL_Swi_Nothing);
  QEP_set_capture_latch_mode (qepHandle, QEPCTL_Qclm_Latch_on_Unit_Timeout);
  QEP_enable_unit_timer(qepHandle);
  QEP_disable_watchdog(qepHandle);

  // setup the QPOSCTL register
  QEP_disable_posn_compare(qepHandle);

  // setup the QCAPCTL register
  QEP_disable_capture(qepHandle);

  // renable the position counter
  QEP_enable_counter(qepHandle);

  return;
}


void SpeedMeasMInit(QEP_Handle qepHandle,SPEED_MEAS_M* spdHandle)
{
	spdHandle->PosMax = (int32_t)(2*4*spdHandle->Lines)-1;
	spdHandle->TurnMax = spdHandle->PosMax>>1;
	spdHandle->K = EQEP_SPEED_MAX/spdHandle->TurnMax;

	// setup the max position
	QEP_set_max_posn_count(qepHandle, spdHandle->PosMax);
}


#ifdef FLASH
#pragma CODE_SECTION(SpeedMeasM,"ramfuncs");
#endif /* FLASH */

void SpeedMeasM(QEP_Handle qepHandle,SPEED_MEAS_M* spdHandle)
{
	if(QEP_read_interrupt_flag(qepHandle,QEINT_Uto))
	{
		QEP_clear_interrupt_flag(qepHandle,QEINT_Uto);
		spdHandle->Pos = (int32_t)QEP_read_posn_latch(qepHandle);

		spdHandle->PosDelta = spdHandle->Pos - spdHandle->PosOld;
		if(spdHandle->PosDelta > spdHandle->TurnMax)
		{
			spdHandle->PosDelta -= spdHandle->PosMax;
		}
		if(spdHandle->PosDelta < -spdHandle->TurnMax)
		{
			spdHandle->PosDelta += spdHandle->PosMax;
		}
		spdHandle->PosOld = spdHandle->Pos;
		spdHandle->Direction = QEP_get_status(qepHandle, QDF);
		spdHandle->Speedrpm = spdHandle->PosDelta * spdHandle->K;
	}
}

