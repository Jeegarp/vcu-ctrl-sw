/******************************************************************************
*
* Copyright (C) 2018 Allegro DVT2.  All rights reserved.
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
*
* Use of the Software is limited solely to applications:
* (a) running on a Xilinx device, or
* (b) that interact with a Xilinx device through a bus or interconnect.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
* XILINX OR ALLEGRO DVT2 BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
* WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF
* OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*
* Except as contained in this notice, the name of  Xilinx shall not be used
* in advertising or otherwise to promote the sale, use or other dealings in
* this Software without prior written authorization from Xilinx.
*
*
* Except as contained in this notice, the name of Allegro DVT2 shall not be used
* in advertising or otherwise to promote the sale, use or other dealings in
* this Software without prior written authorization from Allegro DVT2.
*
******************************************************************************/

/****************************************************************************
   -----------------------------------------------------------------------------
 **************************************************************************//*!
   \addtogroup lib_base
   @{
   \file
 *****************************************************************************/
#pragma once

#include "common_syntax_elements.h"

static uint8_t const SEI_PREFIX_USER_DATA_UNREGISTERED_UUID[16] = { 0xb1, 0xe1, 0x67, 0xa4, 0xd9, 0xca, 0x11, 0xe7, 0xb1, 0x9b, 0x00, 0x50, 0xc2, 0x49, 0x00, 0x48 };

/*************************************************************************//*!
   \brief Mimics structure for AVC SEI buffering period
*****************************************************************************/
typedef struct t_avc_sei_buffering_period
{
  uint8_t seq_parameter_set_id;
  uint32_t initial_cpb_removal_delay[32]; // E.2.2 : cpb_cnt_minus1 shall be in the range of 0 to 31, inclusive
  uint32_t initial_cpb_removal_delay_offset[32];
}AL_TAvcBufPeriod;

/*************************************************************************//*!
   \brief Mimics structure for HEVC SEI buffering period
*****************************************************************************/
typedef struct t_hevc_buffering_period_s
{
  uint8_t bp_seq_parameter_set_id;
  uint8_t rap_cpb_params_present_flag;

  uint32_t cpb_delay_offset;
  uint32_t dpb_delay_offset;

  uint8_t concatenation_flag;
  uint32_t au_cpb_removal_delay_delta_minus1;

  uint32_t nal_initial_cpb_removal_delay[6]; // E.2.2 : cpb_cnt_minus1 shall be in the range of 0 to 31, inclusive
  uint32_t nal_initial_cpb_removal_delay_offset[6];
  uint32_t nal_initial_alt_cpb_removal_delay[6];
  uint32_t nal_initial_alt_cpb_removal_delay_offset[6];

  uint32_t vcl_initial_cpb_removal_delay[6]; // E.2.2 : cpb_cnt_minus1 shall be in the range of 0 to 31, inclusive
  uint32_t vcl_initial_cpb_removal_delay_offset[6];
  uint32_t vcl_initial_alt_cpb_removal_delay[6];
  uint32_t vcl_initial_alt_cpb_removal_delay_offset[6];
}AL_THevcBufPeriod;

/*************************************************************************//*!
   \brief Mimics structure for AVC picture timing
*****************************************************************************/
typedef struct t_sei_clock_ts
{
  uint8_t clock_time_stamp_flag;
  uint8_t ct_type;

  uint8_t nuit_field_based_flag;
  uint8_t counting_type;
  uint8_t full_time_stamp_flag;
  uint8_t discontinuity_flag;
  uint8_t cnt_dropped_flag;
  uint8_t n_frames;

  uint8_t seconds_value;
  uint8_t minutes_value;
  uint8_t hours_value;

  uint8_t seconds_flag;
  uint8_t minutes_flag;
  uint8_t hours_flag;

  int32_t time_offset;
}AL_TSeiClockTS;

/*************************************************************************/
typedef struct t_avc_sei_pic_timing
{
  uint32_t cpb_removal_delay;
  uint32_t dpb_output_delay;
  uint8_t pic_struct;
  AL_TSeiClockTS clock_ts[4];
}AL_TAvcPicTiming;

/*************************************************************************/
typedef struct t_sei_recovery_point
{
  int32_t recovery_cnt;
  bool exact_match;
  bool broken_link;
}AL_TRecoveryPoint;

/*************************************************************************//*!
   \brief Mimics structure for HEVC picture timing
*****************************************************************************/
typedef struct t_hevc_pic_timing_s
{
  uint8_t pic_struct;
  uint8_t source_scan_type;
  uint8_t duplicate_flag;

  uint32_t au_cpb_removal_delay_minus1;
  uint32_t pic_dpb_output_delay;
  uint32_t pic_dpb_output_du_delay;

  uint32_t num_decoding_units_minus1;
  uint8_t du_common_cpb_removal_delay_flag;
  uint32_t du_common_cpb_removal_delay_increment_minus1;
  uint32_t* num_nalus_in_du_minus1;
  uint32_t* du_cpb_removal_delay_increment_minus1;
}AL_THevcPicTiming;

/*************************************************************************//*!
   \brief AVC Supplemental enhancement information structure
*****************************************************************************/
typedef struct t_avc_sei
{
  AL_TAvcPicTiming picture_timing;
  AL_TAvcBufPeriod buffering_period;
  AL_TRecoveryPoint recovery_point;
  uint32_t present_flags;
}AL_TAvcSei;

/*************************************************************************//*!
   \brief HEVC Supplemental enhancement information structure
*****************************************************************************/
typedef struct t_Hevc_Sei
{
  AL_THevcPicTiming picture_timing;
  AL_THevcBufPeriod buffering_period;
  AL_TRecoveryPoint recovery_point;
  uint32_t present_flags;
}AL_THevcSei;

/****************************************************************************/

/*@}*/

