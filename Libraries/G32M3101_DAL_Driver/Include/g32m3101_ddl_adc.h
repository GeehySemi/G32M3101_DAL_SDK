/**
  *
  * @file        g32m3101_ddl_adc.h
  *
  * @brief       Header file of ADC DDL module.
  *
  * @version     V1.0.2
  *
  * @date        2026-10-19
  *
  * @attention
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *
  * 1. Redistributions of source code must retain the above copyright notice,
  *    this list of conditions and the following disclaimer.
  * 2. Redistributions in binary form must reproduce the above copyright notice,
  *    this list of conditions and the following disclaimer in the documentation
  *    and/or other materials provided with the distribution.
  * 3. Neither the name of the copyright holder nor the names of its contributors
  *    may be used to endorse or promote products derived from this software without
  *    specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
  * IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
  * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
  * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
  * OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  * The original code has been modified by Geehy Semiconductor.
  *
  * Copyright (c) 2017 STMicroelectronics.
  * Copyright (C) 2026 Geehy Semiconductor.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef G32M3101_DDL_ADC_H
#define G32M3101_DDL_ADC_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "g32m3xxx.h"
#include "Legacy/g32_ddl_legacy.h"

/** @addtogroup G32M3101_DDL_Driver
  * @{
  */

#if defined (ADC)

/** @defgroup ADC_DDL ADC
  * @{
  */

/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/** @defgroup ADC_DDL_Private_Variables ADC Private Variables
  * @{
  */
static const uint16_t OFFSET_TAB_Reg_Rank[] =
{
  (0x00UL | (ADC_SQR1_SQ1_Pos-ADC_SQR2_SQ8_Pos)),   /* Regular Rank1:(register | pos) */
  (0x00UL | (ADC_SQR1_SQ2_Pos-ADC_SQR2_SQ8_Pos)),   /* Regular Rank2:(register | pos) */
  (0x00UL | (ADC_SQR1_SQ3_Pos-ADC_SQR2_SQ8_Pos)),   /* Regular Rank3:(register | pos) */
  (0x00UL | (ADC_SQR1_SQ4_Pos-ADC_SQR2_SQ8_Pos)),   /* Regular Rank4:(register | pos) */
  (0x00UL | (ADC_SQR1_SQ5_Pos-ADC_SQR2_SQ8_Pos)),   /* Regular Rank5:(register | pos) */
  (0x00UL | (ADC_SQR1_SQ6_Pos-ADC_SQR2_SQ8_Pos)),   /* Regular Rank6:(register | pos) */
  (0x00UL | (ADC_SQR1_SQ7_Pos-ADC_SQR2_SQ8_Pos)),   /* Regular Rank7:(register | pos) */
  (0x100UL | (ADC_SQR2_SQ8_Pos-ADC_SQR2_SQ8_Pos)),  /* Regular Rank8:(register | pos) */
  (0x100UL | (ADC_SQR2_SQ9_Pos-ADC_SQR2_SQ8_Pos)),   /* Regular Rank9: (register | pos) */
  (0x100UL | (ADC_SQR2_SQ10_Pos-ADC_SQR2_SQ8_Pos)),  /* Regular Rank10:(register | pos) */
  (0x100UL | (ADC_SQR2_SQ11_Pos-ADC_SQR2_SQ8_Pos)),  /* Regular Rank11:(register | pos) */
  (0x100UL | (ADC_SQR2_SQ12_Pos-ADC_SQR2_SQ8_Pos)),  /* Regular Rank12:(register | pos) */
  (0x100UL | (ADC_SQR2_SQ13_Pos-ADC_SQR2_SQ8_Pos)),  /* Regular Rank13:(register | pos) */
  (0x100UL | (ADC_SQR2_SQ14_Pos-ADC_SQR2_SQ8_Pos)),  /* Regular Rank14:(register | pos) */
  (0x200UL | (ADC_SQR3_SQ15_Pos-ADC_SQR2_SQ8_Pos)),  /* Regular Rank15:(register | pos) */
  (0x200UL | (ADC_SQR3_SQ16_Pos-ADC_SQR2_SQ8_Pos)),  /* Regular Rank16:(register | pos) */
};

static const uint16_t OFFSET_TAB_SEQ_TrigExtselx[] =
{
  (0x00UL | (ADC_CFGR1_EXTSEL1_Pos-ADC_CFGR3_EXTSEL2_Pos)),   /* Regular TrigExtsel 1:(register | pos) */
  (0x400UL | (ADC_CFGR3_EXTSEL2_Pos-ADC_CFGR3_EXTSEL2_Pos)),  /* Regular TrigExtsel 2:(register | pos) */
  (0x400UL | (ADC_CFGR3_EXTSEL3_Pos-ADC_CFGR3_EXTSEL2_Pos)),  /* Regular TrigExtsel 3:(register | pos) */
};

static const uint16_t OFFSET_TAB_SEQ_TrigExtedge[] =
{
  (0x00UL | (ADC_CFGR1_EXTEN1_Pos-ADC_CFGR3_EXTEN2_Pos)),   /* Regular TrigExt edge 1:(register | pos) */
  (0x400UL | (ADC_CFGR3_EXTEN2_Pos-ADC_CFGR3_EXTEN2_Pos)),  /* Regular TrigExt edge 2:(register | pos) */
  (0x400UL | (ADC_CFGR3_EXTEN3_Pos-ADC_CFGR3_EXTEN2_Pos)),  /* Regular TrigExt edge 3:(register | pos) */
};

static const uint16_t OFFSET_TAB_SEQ_TransTime[] =
{
  ADC_SEQ_NUM_SEQ_NUM1_Pos,
  ADC_SEQ_NUM_SEQ_NUM2_Pos,
  ADC_SEQ_NUM_SEQ_NUM3_Pos
};

/**
  * @}
  */

/* Private constants ---------------------------------------------------------*/
/** @defgroup ADC_DDL_Private_Constants ADC Private Constants
  * @{
  */
#define ADC_SQRX_REGOFFSET_POS         (8UL)
#define ADC_SQRX_REGOFFSET_MASK        (0xFUL<<ADC_SQRX_REGOFFSET_POS)
#define ADC_RANK_ID_SQRX_MASK          (0x1FUL)

#define ADC_CFGRX_REGOFFSET_POS        (8UL)
#define ADC_CFGRX_REGOFFSET_MASK       (0xFUL<<ADC_CFGRX_REGOFFSET_POS)
#define ADC_EXTEN_POS_CFGRX_MASK       (0xFUL)
#define ADC_EXTSEL_POS_CFGRX_MASK      (0xFUL)

/* Equivalent mask of ADC_CHANNEL_NUMBER_MASK aligned on register LSB (bit 0) */
#define ADC_CHANNEL_ID_NUMBER_MASK_POSBIT0 (ADC_SQR2_SQ8) /* Equivalent to shift: (ADC_CHANNEL_NUMBER_MASK >> [Position of bitfield "ADC_CHANNEL_NUMBER_MASK" in register]) */

/* ADC registers bits groups */
#define ADC_CR_BITS_PROPERTY_RS            (ADC_CR_ADSTP | ADC_CR_ADSTART | ADC_CR_ADEN) /* ADC register CR bits with HW property "rs": Software can read as well as set this bit. Writing '0' has no effect on the bit value. */

/* Internal mask for ADC group regular trigger:                               */
/* To select into literal LL_ADC_REG_TRIG_x the relevant bits for:            */
/* - regular trigger source                                                   */
/* - regular trigger edge                                                     */
#define ADC_REG_TRIG_EXT_EDGE_DEFAULT       (ADC_CFGR1_EXTEN1_0) /* Trigger edge set to rising edge (default setting) */
/**
  * @}
  */

/* Private macros ------------------------------------------------------------*/
/** @defgroup ADC_DDL_Private_Macros ADC Private Macros
  * @{
  */
/** @defgroup ADC_DDL_EC_REG_TRIGGER_SOURCE  ADC group regular - Trigger source
  * @{
  */
#define DDL_ADC_REG_TRIG_SOFTWARE               (0x00000000UL)                                                                   /*!< ADC group regular conversion trigger internal: SW start. */
#define DDL_ADC_REG_TRIG_EXTSEL_ATMR_TRGO0      (0x00000000UL                              | ADC_REG_TRIG_EXT_EDGE_DEFAULT)      /*!< ADC group regular conversion trigger from external peripheral: ATMR_CC0. */
#define DDL_ADC_REG_TRIG_EXTSEL_ATMR_TRGO1      (ADC_CFGR1_EXTSEL1_0                       | ADC_REG_TRIG_EXT_EDGE_DEFAULT)      /*!< ADC group regular conversion trigger from external peripheral: ATMR_CC1. */
#define DDL_ADC_REG_TRIG_EXTSEL_ATMR_TRGO2      (ADC_CFGR1_EXTSEL1_1                       | ADC_REG_TRIG_EXT_EDGE_DEFAULT)      /*!< ADC group regular conversion trigger from external peripheral: ATMR_CC2. */
#define DDL_ADC_REG_TRIG_EXTSEL_GTMR_TRGO0      (ADC_CFGR1_EXTSEL1_1 | ADC_CFGR1_EXTSEL1_0 | ADC_REG_TRIG_EXT_EDGE_DEFAULT)      /*!< ADC group regular conversion trigger from external peripheral: GTMR_CC0. */
/**
  * @}
  */

/** @defgroup ADC_DDL_EC_REG_TRIGGER_EDGE  ADC group regular - Trigger edge
  * @{
  */
#define DDL_ADC_REG_TRIG_EXTEDGE_RISING         (ADC_CFGR1_EXTEN1_0)       /*!< ADC group regular conversion trigger polarity set to rising edge */
#define DDL_ADC_REG_TRIG_EXTEDGE_FALLING        (ADC_CFGR1_EXTEN1_1)       /*!< ADC group regular conversion trigger polarity set to falling edge */
#define DDL_ADC_REG_TRIG_EXTEDGE_RISING_FALLING (ADC_CFGR1_EXTEN1)         /*!< ADC group regular conversion trigger polarity set to rising edge or falling edge */
/**
  * @}
  */

/** @defgroup ADC_DDL_EC_REG_SEQ_SCAN_LENGTH  ADC group regular - Sequencer scan length
  * @{
  */
#define DDL_ADC_REG_SEQ_SCAN_DISABLE        (0x00000000UL)                                                    /*!< ADC group regular sequencer disable (equivalent to sequencer of 1 rank: ADC conversion on only 1 channel) */
#define DDL_ADC_REG_SEQ_SCAN_ENABLE_2RANKS  (                                             ADC_SQR1_LT3_0)     /*!< ADC group regular sequencer enable with 2 ranks in the sequence */
#define DDL_ADC_REG_SEQ_SCAN_ENABLE_3RANKS  (                              ADC_SQR1_LT3_1               )     /*!< ADC group regular sequencer enable with 3 ranks in the sequence */
#define DDL_ADC_REG_SEQ_SCAN_ENABLE_4RANKS  (                              ADC_SQR1_LT3_1 | ADC_SQR1_LT3_0)   /*!< ADC group regular sequencer enable with 4 ranks in the sequence */
#define DDL_ADC_REG_SEQ_SCAN_ENABLE_5RANKS  (               ADC_SQR1_LT3_2                              )     /*!< ADC group regular sequencer enable with 5 ranks in the sequence */
#define DDL_ADC_REG_SEQ_SCAN_ENABLE_6RANKS  (               ADC_SQR1_LT3_2                | ADC_SQR1_LT3_0)   /*!< ADC group regular sequencer enable with 6 ranks in the sequence */
#define DDL_ADC_REG_SEQ_SCAN_ENABLE_7RANKS  (               ADC_SQR1_LT3_2 | ADC_SQR1_LT3_1               )   /*!< ADC group regular sequencer enable with 7 ranks in the sequence */
#define DDL_ADC_REG_SEQ_SCAN_ENABLE_8RANKS  (               ADC_SQR1_LT3_2 | ADC_SQR1_LT3_1 | ADC_SQR1_LT3_0) /*!< ADC group regular sequencer enable with 8 ranks in the sequence */
#define DDL_ADC_REG_SEQ_SCAN_ENABLE_9RANKS  (ADC_SQR1_LT3_3                                              )    /*!< ADC group regular sequencer enable with 9 ranks in the sequence */
#define DDL_ADC_REG_SEQ_SCAN_ENABLE_10RANKS (ADC_SQR1_LT3_3                               | ADC_SQR1_LT3_0)   /*!< ADC group regular sequencer enable with 10 ranks in the sequence */
#define DDL_ADC_REG_SEQ_SCAN_ENABLE_11RANKS (ADC_SQR1_LT3_3                | ADC_SQR1_LT3_1               )   /*!< ADC group regular sequencer enable with 11 ranks in the sequence */
#define DDL_ADC_REG_SEQ_SCAN_ENABLE_12RANKS (ADC_SQR1_LT3_3                | ADC_SQR1_LT3_1 | ADC_SQR1_LT3_0) /*!< ADC group regular sequencer enable with 12 ranks in the sequence */
#define DDL_ADC_REG_SEQ_SCAN_ENABLE_13RANKS (ADC_SQR1_LT3_3 | ADC_SQR1_LT3_2                              )   /*!< ADC group regular sequencer enable with 13 ranks in the sequence */
#define DDL_ADC_REG_SEQ_SCAN_ENABLE_14RANKS (ADC_SQR1_LT3_3 | ADC_SQR1_LT3_2               | ADC_SQR1_LT3_0)  /*!< ADC group regular sequencer enable with 14 ranks in the sequence */
#define DDL_ADC_REG_SEQ_SCAN_ENABLE_15RANKS (ADC_SQR1_LT3_3 | ADC_SQR1_LT3_2               | ADC_SQR1_LT3_1)  /*!< ADC group regular sequencer enable with 15 ranks in the sequence */
#define DDL_ADC_REG_SEQ_SCAN_ENABLE_16RANKS (ADC_SQR1_LT3_3 | ADC_SQR1_LT3_2 | ADC_SQR1_LT3_1 | ADC_SQR1_LT3_0) /*!< ADC group regular sequencer enable with 16 ranks in the sequence */
/**
  * @}
  */

/** @defgroup ADC_DDL_EC_SEQ_DISCONT_MODE  ADC group regular - Sequencer discontinuous mode
  * @{
  */
#define DDL_ADC_REG_SEQ_DISCONT_DISABLE     (0x00000000UL)                                                                       /*!< ADC group regular sequencer discontinuous mode disable */
#define DDL_ADC_REG_SEQ_DISCONT_1RANK       (                                                               ADC_CFGR1_DISCEN)    /*!< ADC group regular sequencer discontinuous mode enable with sequence interruption every rank */
#define DDL_ADC_REG_SEQ_DISCONT_2RANKS      (                                          ADC_CFGR1_DISCNUM_0 | ADC_CFGR1_DISCEN)   /*!< ADC group regular sequencer discontinuous mode enabled with sequence interruption every 2 ranks */
#define DDL_ADC_REG_SEQ_DISCONT_3RANKS      (                     ADC_CFGR1_DISCNUM_1                      | ADC_CFGR1_DISCEN)   /*!< ADC group regular sequencer discontinuous mode enable with sequence interruption every 3 ranks */
#define DDL_ADC_REG_SEQ_DISCONT_4RANKS      (                     ADC_CFGR1_DISCNUM_1 | ADC_CFGR1_DISCNUM_0 | ADC_CFGR1_DISCEN)  /*!< ADC group regular sequencer discontinuous mode enable with sequence interruption every 4 ranks */
#define DDL_ADC_REG_SEQ_DISCONT_5RANKS      (ADC_CFGR1_DISCNUM_2                                           | ADC_CFGR1_DISCEN)   /*!< ADC group regular sequencer discontinuous mode enable with sequence interruption every 5 ranks */
#define DDL_ADC_REG_SEQ_DISCONT_6RANKS      (ADC_CFGR1_DISCNUM_2                      | ADC_CFGR1_DISCNUM_0 | ADC_CFGR1_DISCEN)  /*!< ADC group regular sequencer discontinuous mode enable with sequence interruption every 6 ranks */
#define DDL_ADC_REG_SEQ_DISCONT_7RANKS      (ADC_CFGR1_DISCNUM_2 | ADC_CFGR1_DISCNUM_1                      | ADC_CFGR1_DISCEN)  /*!< ADC group regular sequencer discontinuous mode enable with sequence interruption every 7 ranks */
#define DDL_ADC_REG_SEQ_DISCONT_8RANKS      (ADC_CFGR1_DISCNUM_2 | ADC_CFGR1_DISCNUM_1 | ADC_CFGR1_DISCNUM_0 | ADC_CFGR1_DISCEN) /*!< ADC group regular sequencer discontinuous mode enable with sequence interruption every 8 ranks */
/**
  * @}
  */

/** @defgroup ADC_DDL_EC_REG_RANKS  ADC group regular - Sequencer ranks
  * @{
  */
#define DDL_ADC_REG_RANK_1                 0       /*!< ADC group regular sequencer rank 1 */
#define DDL_ADC_REG_RANK_2                 1       /*!< ADC group regular sequencer rank 2 */
#define DDL_ADC_REG_RANK_3                 2       /*!< ADC group regular sequencer rank 3 */
#define DDL_ADC_REG_RANK_4                 3       /*!< ADC group regular sequencer rank 4 */
#define DDL_ADC_REG_RANK_5                 4       /*!< ADC group regular sequencer rank 5 */
#define DDL_ADC_REG_RANK_6                 5       /*!< ADC group regular sequencer rank 6 */
#define DDL_ADC_REG_RANK_7                 6       /*!< ADC group regular sequencer rank 7 */
#define DDL_ADC_REG_RANK_8                 7       /*!< ADC group regular sequencer rank 8 */
#define DDL_ADC_REG_RANK_9                 8       /*!< ADC group regular sequencer rank 9 */
#define DDL_ADC_REG_RANK_10                9       /*!< ADC group regular sequencer rank 10 */
#define DDL_ADC_REG_RANK_11                10      /*!< ADC group regular sequencer rank 11 */
#define DDL_ADC_REG_RANK_12                11      /*!< ADC group regular sequencer rank 12 */
#define DDL_ADC_REG_RANK_13                12      /*!< ADC group regular sequencer rank 13 */
#define DDL_ADC_REG_RANK_14                13      /*!< ADC group regular sequencer rank 14 */
#define DDL_ADC_REG_RANK_15                14      /*!< ADC group regular sequencer rank 15 */
#define DDL_ADC_REG_RANK_16                15      /*!< ADC group regular sequencer rank 16 */
/**
  * @}
  */


/** @defgroup ADC_DDL_EC_SEQ_TRIGGER_SOURCE  ADC sequential section - Trigger source
  * @{
  */
#define DDL_ADC_SEQ_TRIG_EXTSEL_ATMR_TRGO0      (0x00000000UL                             )      /*!< ADC sequential section conversion trigger from external peripheral: ATMR_CC0. */
#define DDL_ADC_SEQ_TRIG_EXTSEL_ATMR_TRGO1      (ADC_CFGR3_EXTSEL2_0                      )      /*!< ADC sequential section conversion trigger from external peripheral: ATMR_CC1. */
#define DDL_ADC_SEQ_TRIG_EXTSEL_ATMR_TRGO2      (ADC_CFGR3_EXTSEL2_1                      )      /*!< ADC sequential section conversion trigger from external peripheral: ATMR_CC2. */
#define DDL_ADC_SEQ_TRIG_EXTSEL_GTMR_TRGO0      (ADC_CFGR3_EXTSEL2_1 | ADC_CFGR3_EXTSEL2_0)      /*!< ADC sequential section conversion trigger from external peripheral: GTMR_CC0. */
/**
  * @}
  */

/** @defgroup ADC_DDL_EC_SEQ_TRIGGER_EDGE  ADC sequential section - Trigger edge
  * @{
  */
#define DDL_ADC_SEQ_TRIG_EXTEDGE_RISING         (ADC_CFGR3_EXTEN2_0)       /*!< ADC sequential section conversion trigger polarity set to rising edge */
#define DDL_ADC_SEQ_TRIG_EXTEDGE_FALLING        (ADC_CFGR3_EXTEN2_1)       /*!< ADC sequential section conversion trigger polarity set to falling edge */
#define DDL_ADC_SEQ_TRIG_EXTEDGE_RISING_FALLING (ADC_CFGR3_EXTEN2)         /*!< ADC sequential section conversion trigger polarity set to rising edge or falling edge */
/**
  * @}
  */

/**
  * @}
  */

/* Exported types ------------------------------------------------------------*/
#if defined(USE_FULL_DDL_DRIVER)
/** @defgroup ADC_DDL_ES_INIT ADC Exported Init structure
  * @{
  */

/**
  * @brief  Structure definition of some features of ADC instance.
  * @note   These parameters have an impact on ADC scope: ADC instance.
  *         Affects both group regular and group injected (availability
  *         of ADC group injected depends on G32 families).
  *         Refer to corresponding unitary functions into
  *         @ref ADC_DDL_EF_Configuration_ADC_Instance .
  * @note   The setting of these parameters by function @ref DDL_ADC_Init()
  *         is conditioned to ADC state:
  *         ADC instance must be disabled.
  *         This condition is applied to all ADC features, for efficiency
  *         and compatibility over all G32 families. However, the different
  *         features can be set under different ADC state conditions
  *         (setting possible with ADC enabled without conversion on going,
  *         ADC enabled with conversion on going, ...)
  *         Each feature can be updated afterwards with a unitary function
  *         and potentially with ADC in a different state than disabled,
  *         refer to description of each function for setting
  *         conditioned to ADC state.
  */
typedef struct
{
  uint32_t DataAlignment;               /*!< Set ADC conversion data alignment.
                                            This parameter can be a value of @ref ADC_DDL_EC_ALIGMENT

                                            This feature can be modified afterwards using unitary function @ref DDL_ADC_SetDataAlignment(). */


} DDL_ADC_InitTypeDef;

/**
  * @brief  Structure definition of some features of ADC group regular.
  * @note   These parameters have an impact on ADC scope: ADC group regular.
  *         Refer to corresponding unitary functions into
  *         @ref ADC_DDL_EF_Configuration_ADC_Group_Regular
  *         (functions with prefix "REG").
  * @note   The setting of these parameters by function @ref DDL_ADC_Init()
  *         is conditioned to ADC state:
  *         ADC instance must be disabled.
  *         This condition is applied to all ADC features, for efficiency
  *         and compatibility over all G32 families. However, the different
  *         features can be set under different ADC state conditions
  *         (setting possible with ADC enabled without conversion on going,
  *         ADC enabled with conversion on going, ...)
  *         Each feature can be updated afterwards with a unitary function
  *         and potentially with ADC in a different state than disabled,
  *         refer to description of each function for setting
  *         conditioned to ADC state.
  */
typedef struct
{
  uint32_t TriggerSource;               /*!< Set ADC group regular conversion trigger source: internal (SW start) or from external peripheral (timer event, external interrupt line).
                                            This parameter can be a value of @ref ADC_DDL_EC_REG_TRIGGER_SOURCE

                                            This feature can be modified afterwards using unitary function @ref DDL_ADC_REG_SetTriggerSource(). */

  uint32_t TriggerEdge;               /*!< Set ADC group regular conversion trigger edge: rising, falling or both.
                                            This parameter can be a value of @ref ADC_DDL_EC_REG_TRIGGER_EDGE

                                            This feature can be modified afterwards using unitary function @ref DDL_ADC_REG_SetTriggerEdge(). */

  uint32_t SequencerLength;             /*!< Set ADC group regular sequencer length.
                                            This parameter can be a value of @ref ADC_DDL_EC_REG_SEQ_SCAN_LENGTH

                                            This feature can be modified afterwards using unitary function @ref DDL_ADC_REG_SetSequencerLength(). */

  uint32_t SequencerDiscont;            /*!< Set ADC group regular sequencer discontinuous mode: sequence subdivided and scan conversions interrupted every selected number of ranks.
                                            This parameter can be a value of @ref ADC_DDL_EC_SEQ_DISCONT_MODE

                                            This feature can be modified afterwards using unitary function @ref DDL_ADC_REG_SetSequencerDiscont(). */

  uint32_t ContinuousMode;              /*!< Set ADC continuous conversion mode on ADC group regular, whether ADC conversions are performed in single mode (one conversion per trigger) or
                                             in continuous mode (after the first trigger, following conversions launched successively automatically).
                                            This parameter can be a value of @ref ADC_DDL_EC_REG_CONTINUOUS_MODE

                                            This feature can be modified afterwards using unitary function @ref DDL_ADC_REG_SetContinuousMode(). */

  uint32_t DMATransfer;                 /*!< Set ADC group regular conversion data transfer: no transfer or transfer by DMA, and DMA requests mode.
                                            This parameter can be a value of @ref ADC_DDL_EC_REG_DMA_TRANSFER

                                            This feature can be modified afterwards using unitary function @ref DDL_ADC_REG_SetDMATransfer(). */

  uint32_t FastChannelSamplingTime;     /*!< Set ADC group regular sampling time for fast channel.
                                            This parameter can be a value of @ref ADC_DDL_EC_CHANNEL_SAMPLINGTIME

                                            This feature can be modified afterwards using unitary function @ref DDL_ADC_SetFastChannelSamplingTime(). */

  uint32_t SlowChannelSamplingTime;          /*!< Set ADC group regular sampling time for slow channel.
                                            This parameter can be a value of @ref ADC_DDL_EC_CHANNEL_SAMPLINGTIME

                                            This feature can be modified afterwards using unitary function @ref DDL_ADC_SetSlowChannelSamplingTime(). */

  uint32_t Overrun;                     /*!< Set ADC group regular behavior
                                            This parameter can be a value of @ref ADC_DDL_EC_OVERFLOW_MODE

                                            This feature can be modified afterwards using unitary function @ref DDL_ADC_SetOverflowMode(). */

} DDL_ADC_REG_InitTypeDef;

typedef struct
{
  uint32_t NumSec;                        /*!< Set ADC sequential section number.
                                            This parameter can be a value of @ref ADC_DDL_SEQ_NUMBER

                                            This feature can be modified afterwards using unitary function @ref DDL_ADC_SEQ_SetSectionNumber(). */

  uint32_t TimesSec1;                    /*!< Set ADC sequential section1 transmission time.
                                            This parameter can be a value of @ref ADC_DDL_SEQ_TRS_TIME

                                            This feature can be modified afterwards using unitary function @ref DDL_ADC_SEQ_SetSectionTimes(). */

  uint32_t TimesSec2;                    /*!< Set ADC sequential section2 transmission time.
                                            This parameter can be a value of @ref ADC_DDL_SEQ_TRS_TIME

                                            This feature can be modified afterwards using unitary function @ref DDL_ADC_SEQ_SetSectionTimes(). */

  uint32_t TimesSec3;                    /*!< Set ADC sequential section3 transmission time.
                                            This parameter can be a value of @ref ADC_DDL_SEQ_TRS_TIME

                                            This feature can be modified afterwards using unitary function @ref DDL_ADC_SEQ_SetSectionTimes(). */

  uint32_t GapTime;                       /*!< Set ADC sequential section sequencer gap time.
                                            This parameter can be a value of @ref ADC_DDL_EC_GAPTIME

                                            This feature can be modified afterwards using unitary function @ref DDL_ADC_SEQ_SetGapTime(). */

  uint32_t TriggerSourceSec1;               /*!< Set ADC sequential section1 conversion trigger source: from external peripheral (timer event, external interrupt line).
                                            This parameter can be a value of @ref ADC_DDL_EC_SEQ_TRIGGER_SOURCE

                                            This feature can be modified afterwards using unitary function @ref DDL_ADC_SEQ_SetTriggerSource(). */

  uint32_t TriggerEdgeSec1;               /*!< Set ADC sequential section conversion trigger edge: rising, falling or both.
                                            This parameter can be a value of @ref ADC_DDL_EC_SEQ_TRIGGER_EDGE

                                            This feature can be modified afterwards using unitary function @ref DDL_ADC_SEQ_SetTriggerEdge(). */

  uint32_t TriggerSourceSec2;               /*!< Set ADC sequential section2 conversion trigger source: from external peripheral (timer event, external interrupt line).
                                            This parameter can be a value of @ref ADC_DDL_EC_SEQ_TRIGGER_SOURCE

                                            This feature can be modified afterwards using unitary function @ref DDL_ADC_SEQ_SetTriggerSource(). */

  uint32_t TriggerEdgeSec2;               /*!< Set ADC sequential section2 conversion trigger edge: rising, falling or both.
                                            This parameter can be a value of @ref ADC_DDL_EC_SEQ_TRIGGER_EDGE

                                            This feature can be modified afterwards using unitary function @ref DDL_ADC_SEQ_SetTriggerEdge(). */

  uint32_t TriggerSourceSec3;               /*!< Set ADC sequential section3 conversion trigger source: from external peripheral (timer event, external interrupt line).
                                            This parameter can be a value of @ref ADC_DDL_EC_SEQ_TRIGGER_SOURCE

                                            This feature can be modified afterwards using unitary function @ref DDL_ADC_SEQ_SetTriggerSource(). */

  uint32_t TriggerEdgeSec3;               /*!< Set ADC sequential section3 conversion trigger edge: rising, falling or both.
                                            This parameter can be a value of @ref ADC_DDL_EC_SEQ_TRIGGER_EDGE

                                            This feature can be modified afterwards using unitary function @ref DDL_ADC_SEQ_SetTriggerEdge(). */

  uint32_t FastChannelSamplingTime;     /*!< Set ADC group regular sampling time for fast channel.
                                            This parameter can be a value of @ref ADC_DDL_EC_CHANNEL_SAMPLINGTIME

                                            This feature can be modified afterwards using unitary function @ref DDL_ADC_SetFastChannelSamplingTime(). */

  uint32_t SlowChannelSamplingTime;          /*!< Set ADC group regular sampling time for slow channel.
                                            This parameter can be a value of @ref ADC_DDL_EC_CHANNEL_SAMPLINGTIME

                                            This feature can be modified afterwards using unitary function @ref DDL_ADC_SetSlowChannelSamplingTime(). */

} DDL_ADC_SEQ_InitTypeDef;

/**
  * @}
  */
#endif /* USE_FULL_DDL_DRIVER */


/* Exported constants ------------------------------------------------------------*/
/** @defgroup ADC_DDL_Exported_Constants ADC Exported Constants
  * @{
  */
/** @defgroup ADC_DDL_EC_REGISTERS  ADC registers compliant with specific purpose
  * @{
  */
/* List of ADC registers intended to be used (most commonly) with             */
/* DMA transfer.                                                              */
/* Refer to function @ref DDL_ADC_DMA_GetRegAddr().                            */
#define DDL_ADC_DMA_REG_REGULAR_DATA          (0x00000000UL) /* ADC group regular conversion data register (corresponding to register DR) to be used with ADC configured in independent mode. Without DMA transfer*/
/**
  * @}
  */

/** @defgroup ADC_DDL_EC_CHANNEL  ADC instance - Channel number
  * @{
  */
#define DDL_ADC_CHANNEL_0                   0   /*!< ADC external channel (channel connected to GPIO pin) ADCx_IN0  */
#define DDL_ADC_CHANNEL_1                   1   /*!< ADC external channel (channel connected to GPIO pin) ADCx_IN1  */
#define DDL_ADC_CHANNEL_2                   2   /*!< ADC external channel (channel connected to GPIO pin) ADCx_IN2  */
#define DDL_ADC_CHANNEL_3                   3   /*!< ADC external channel (channel connected to GPIO pin) ADCx_IN3  */
#define DDL_ADC_CHANNEL_4                   4   /*!< ADC external channel (channel connected to GPIO pin) ADCx_IN4  */
#define DDL_ADC_CHANNEL_5                   5   /*!< ADC external channel (channel connected to GPIO pin) ADCx_IN5  */
#define DDL_ADC_CHANNEL_6                   6   /*!< ADC external channel (channel connected to GPIO pin) ADCx_IN6  */
#define DDL_ADC_CHANNEL_7                   7   /*!< ADC external channel (channel connected to GPIO pin) ADCx_IN7  */
#define DDL_ADC_CHANNEL_8                   8   /*!< ADC internal channel (channel connected to TS) ADCx_IN8  */
#define DDL_ADC_CHANNEL_9                   9   /*!< ADC internal channel (channel connected to VBG) ADCx_IN9  */
#define DDL_ADC_CHANNEL_10                  10  /*!< ADC internal channel (channel connected to 1/12 VDD) ADCx_IN10  */
#define DDL_ADC_CHANNEL_11                  11  /*!< ADC internal channel (channel connected to VDD 5) ADCx_IN11  */
#define DDL_ADC_CHANNEL_12                  12  /*!< ADC internal channel (channel connected to OPA1) ADCx_IN12  */
#define DDL_ADC_CHANNEL_13                  13  /*!< ADC internal channel (channel connected to OPA2) ADCx_IN13  */
/**
  * @}
  */

/** @defgroup ADC_DDL_EC_REG_CONTINUOUS_MODE  ADC group regular - Continuous mode
  * @{
  */
#define DDL_ADC_REG_CONV_SINGLE             (0x00000000UL)          /*!< ADC conversions are performed in single mode: one conversion per trigger */
#define DDL_ADC_REG_CONV_CONTINUOUS         (ADC_CFGR1_CONT)         /*!< ADC conversions are performed in continuous mode: after the first trigger, following conversions launched successively automatically */
/**
  * @}
  */

/** @defgroup ADC_DDL_EC_REG_DMA_TRANSFER  ADC group regular - DMA transfer of ADC conversion data
  * @{
  */
#define DDL_ADC_REG_DMA_TRANSFER_DISABLE          (0x00000000UL)                        /*!< ADC conversions are not transferred by DMA */
#define DDL_ADC_REG_DMA_TRANSFER_ONESHOT_MODE     (ADC_CFGR1_DMAEN)                     /*!< ADC conversion data are transferred by DMA, in limited mode (one shot mode): DMA transfer requests are stopped when number of DMA data transfers (number of ADC conversions) is reached. This ADC mode is intended to be used with DMA mode non-circular. */
#define DDL_ADC_REG_DMA_TRANSFER_CIRCULAR_MODE    (ADC_CFGR1_DMAEN | ADC_CFGR1_DMACFG)  /*!< ADC conversion data are transferred by DMA, in unlimited mode */
/**
  * @}
  */


/** @defgroup ADC_DDL_EC_CHANNEL_SAMPLINGTIME  Channel - Sampling time
  * @{
  */
#define DDL_ADC_SAMPLINGTIME_FAST_3CYCLES     (0x00000000)
#define DDL_ADC_SAMPLINGTIME_FAST_8CYCLES     (ADC_SMPR1_SMP1_FAST_0)
#define DDL_ADC_SAMPLINGTIME_FAST_16CYCLES    (ADC_SMPR1_SMP1_FAST_1)
#define DDL_ADC_SAMPLINGTIME_FAST_32CYCLES    (ADC_SMPR1_SMP1_FAST_1 | ADC_SMPR1_SMP1_FAST_0)
#define DDL_ADC_SAMPLINGTIME_FAST_64CYCLES    (ADC_SMPR1_SMP1_FAST_2)
#define DDL_ADC_SAMPLINGTIME_FAST_96CYCLES    (ADC_SMPR1_SMP1_FAST_2 | ADC_SMPR1_SMP1_FAST_0)
#define DDL_ADC_SAMPLINGTIME_FAST_128CYCLES   (ADC_SMPR1_SMP1_FAST_2 | ADC_SMPR1_SMP1_FAST_1)
#define DDL_ADC_SAMPLINGTIME_FAST_256CYCLES   (ADC_SMPR1_SMP1_FAST_2 | ADC_SMPR1_SMP1_FAST_1 | ADC_SMPR1_SMP1_FAST_0)

#define DDL_ADC_SAMPLINGTIME_SLOW_128CYCLES   (0x00000000)
#define DDL_ADC_SAMPLINGTIME_SLOW_160CYCLES   (ADC_SMPR1_SMP1_SLOW_0)
#define DDL_ADC_SAMPLINGTIME_SLOW_192CYCLES   (ADC_SMPR1_SMP1_SLOW_1)
#define DDL_ADC_SAMPLINGTIME_SLOW_224CYCLES   (ADC_SMPR1_SMP1_SLOW_1 | ADC_SMPR1_SMP1_SLOW_0)
#define DDL_ADC_SAMPLINGTIME_SLOW_256CYCLES   (ADC_SMPR1_SMP1_SLOW_2)

/**
  * @}
  */

/**
 * @defgroup ADC_DDL_EC_ALIGMENT Data alignment
  * @{
  */
#define DDL_ADC_ALIGNMENT_LEFT              ADC_CFGR1_ALIGN
#define DDL_ADC_ALIGNMENT_RIGHT             (0x00000000UL)
/**
  * @}
  */

/**
 * @defgroup ADC_DDL_EC_OVERFLOW_MODE OverData Behavior
  * @{
  */
#define DDL_ADC_OVERMODE_KEEP              0x00000000UL
#define DDL_ADC_OVERMODE_OVER              ADC_CFGR1_OVRMOD
/**
  * @}
  */

/**
 * @defgroup ADC_DDL_EC_GAPTIME GapTime
  * @{
  */
#define DDL_ADC_GAPTIME_ADCCLK_0              0x00000000UL
#define DDL_ADC_GAPTIME_ADCCLK_2              ADC_CFGR2_TGAP_0
#define DDL_ADC_GAPTIME_ADCCLK_4              ADC_CFGR2_TGAP_1
#define DDL_ADC_GAPTIME_ADCCLK_8             (ADC_CFGR2_TGAP_1 | ADC_CFGR2_TGAP_0)
#define DDL_ADC_GAPTIME_ADCCLK_16            (ADC_CFGR2_TGAP_2)
#define DDL_ADC_GAPTIME_ADCCLK_32            (ADC_CFGR2_TGAP_2 | ADC_CFGR2_TGAP_0)
#define DDL_ADC_GAPTIME_ADCCLK_64            (ADC_CFGR2_TGAP_2 | ADC_CFGR2_TGAP_1)
#define DDL_ADC_GAPTIME_ADCCLK_128           (ADC_CFGR2_TGAP_2 |ADC_CFGR2_TGAP_1 | ADC_CFGR2_TGAP_0)
#define DDL_ADC_GAPTIME_ADCCLK_256           (ADC_CFGR2_TGAP_3)
#define DDL_ADC_GAPTIME_ADCCLK_512           (ADC_CFGR2_TGAP_3 | ADC_CFGR2_TGAP_0)
#define DDL_ADC_GAPTIME_ADCCLK_1024          (ADC_CFGR2_TGAP_3 | ADC_CFGR2_TGAP_1)
#define DDL_ADC_GAPTIME_ADCCLK_2048          (ADC_CFGR2_TGAP_3 | ADC_CFGR2_TGAP_1 | ADC_CFGR2_TGAP_0)
#define DDL_ADC_GAPTIME_ADCCLK_4096          (ADC_CFGR2_TGAP_3 | ADC_CFGR2_TGAP_2)
#define DDL_ADC_GAPTIME_ADCCLK_8192          (ADC_CFGR2_TGAP_3 | ADC_CFGR2_TGAP_2 | ADC_CFGR2_TGAP_0)
#define DDL_ADC_GAPTIME_ADCCLK_16384         (ADC_CFGR2_TGAP_3 | ADC_CFGR2_TGAP_2 | ADC_CFGR2_TGAP_1)
#define DDL_ADC_GAPTIME_ADCCLK_32768         (ADC_CFGR2_TGAP)

/**
  * @}
  */

/**
 * @defgroup ADC_DDL_SEQ_NUMBER Sequence number
  * @{
  */
#define DDL_ADC_SEQ_NUMBER_1              0x00000000UL
#define DDL_ADC_SEQ_NUMBER_2              ADC_SEQ_NUM_SG_NUM_0
#define DDL_ADC_SEQ_NUMBER_3              ADC_SEQ_NUM_SG_NUM_1
/**
  * @}
  */

/**
 * @defgroup ADC_DDL_SEQ_SECTION Sequence section
  * @{
  */
#define DDL_ADC_SEQ_SECTION_1              0U
#define DDL_ADC_SEQ_SECTION_2              1U
#define DDL_ADC_SEQ_SECTION_3              2U
/**
  * @}
  */

/**
 * @defgroup ADC_DDL_SEQ_TRS_TIME Sequence transmission timr
  * @{
  */
#define DDL_ADC_SEQ_TRS_TIME_1              0x00000000UL
#define DDL_ADC_SEQ_TRS_TIME_2              ADC_SEQ_NUM_SEQ_NUM1_0
#define DDL_ADC_SEQ_TRS_TIME_3              ADC_SEQ_NUM_SEQ_NUM1_1
#define DDL_ADC_SEQ_TRS_TIME_4              (ADC_SEQ_NUM_SEQ_NUM1_1 | ADC_SEQ_NUM_SEQ_NUM1_0)
#define DDL_ADC_SEQ_TRS_TIME_5              ADC_SEQ_NUM_SEQ_NUM1_2
#define DDL_ADC_SEQ_TRS_TIME_6              (ADC_SEQ_NUM_SEQ_NUM1_2 | ADC_SEQ_NUM_SEQ_NUM1_0)
#define DDL_ADC_SEQ_TRS_TIME_7              (ADC_SEQ_NUM_SEQ_NUM1_2 | ADC_SEQ_NUM_SEQ_NUM1_1)
#define DDL_ADC_SEQ_TRS_TIME_8              (ADC_SEQ_NUM_SEQ_NUM1_2 | ADC_SEQ_NUM_SEQ_NUM1_1 |ADC_SEQ_NUM_SEQ_NUM1_0)
/**
  * @}
  */


/** @defgroup ADC_DDL_EC_SEQ_RANK_RESULT  ADC Sequencer rank result
  * @{
  */
#define DDL_ADC_SEQ_RANK_RESULT_1                 0
#define DDL_ADC_SEQ_RANK_RESULT_2                 1
#define DDL_ADC_SEQ_RANK_RESULT_3                 2
#define DDL_ADC_SEQ_RANK_RESULT_4                 3
#define DDL_ADC_SEQ_RANK_RESULT_5                 4
#define DDL_ADC_SEQ_RANK_RESULT_6                 5
#define DDL_ADC_SEQ_RANK_RESULT_7                 6
#define DDL_ADC_SEQ_RANK_RESULT_8                 7
/**
  * @}
  */

/**
 * @defgroup ADC_DDL_EC_VREF_SEL VREF Selection
  * @{
  */
#define DDL_ADC_VREF_SEL_VDD5              0x00000000UL
#define DDL_ADC_VREF_SEL_GPIO_INPUT        ADC_CR_VREF_SEL
/**
  * @}
  */

/**
 * @defgroup ADC_DDL_EC_CALIBRATION Calibration Bypass
  * @{
  */
#define DDL_ADC_CALC_NOT_BYPASS              0x00000000UL
#define DDL_ADC_CALC_BYPASS                  ADC_TMR_CALC_BYPASS
/**
  * @}
  */

/**
  * @}
  */


/* Exported macros ------------------------------------------------------------*/
/** @defgroup ADC_DDL_Private_Macros ADC Exported Macros
  * @{
  */

/**
  * @brief  Driver macro reserved for internal use: set a pointer to
  *         a register from a register basis from which an offset
  *         is applied.
  * @param  __REG__ Register basis from which the offset is applied.
  * @param  __REG_OFFFSET__ Offset to be applied (unit: number of registers).
  * @retval Pointer to register address
  */
#define __ADC_PTR_REG_OFFSET(__REG__, __REG_OFFFSET__)                         \
  ((__IO uint32_t *)((uintptr_t)(&(__REG__)) + ((__REG_OFFFSET__) << 2UL)))

/**
  * @brief  Helper macro to get ADC channel number in decimal format
  *         from literals DDL_ADC_CHANNEL_x.
  * @note   Example:
  *           __DDL_ADC_CHANNEL_TO_DECIMAL_NB(DDL_ADC_CHANNEL_4)
  *           will return decimal number "4".
  * @note   The input can be a value from functions where a channel
  *         number is returned, either defined with number
  *         or with bitfield (only one bit must be set).
  * @param  __CHANNEL__ This parameter can be one of the following values:
  *          @arg @ref DDL_ADC_CHANNEL_0
             @arg @ref DDL_ADC_CHANNEL_1
             @arg @ref DDL_ADC_CHANNEL_2
             @arg @ref DDL_ADC_CHANNEL_3
             @arg @ref DDL_ADC_CHANNEL_4
             @arg @ref DDL_ADC_CHANNEL_5
             @arg @ref DDL_ADC_CHANNEL_6
             @arg @ref DDL_ADC_CHANNEL_7
             @arg @ref DDL_ADC_CHANNEL_8
             @arg @ref DDL_ADC_CHANNEL_9
             @arg @ref DDL_ADC_CHANNEL_10
             @arg @ref DDL_ADC_CHANNEL_11
             @arg @ref DDL_ADC_CHANNEL_12
             @arg @ref DDL_ADC_CHANNEL_13
  * @retval Value between Min_Data=0 and Max_Data=13
  */
#define __DDL_ADC_CHANNEL_TO_DECIMAL_NB(__CHANNEL__)  ((uint32_t)(__CHANNEL__))

/**
  * @}
  */


/* Exported functions --------------------------------------------------------*/
/** @defgroup ADC_DDL_Exported_Functions ADC Exported Functions
  * @{
  */
/** @defgroup ADC_DDL_EF_DMA_Management ADC DMA management
  * @{
  */
/* Note: DDL ADC functions to set DMA transfer are located into sections of    */
/*       configuration of ADC instance, groups and multimode (if available):  */
/*       @ref DDL_ADC_REG_SetDMATransfer(), ...                                */

/**
  * @brief  Function to help to configure DMA transfer from ADC: retrieve the
  *         ADC register address from ADC instance and a list of ADC registers
  *         intended to be used (most commonly) with DMA transfer.
  * @note   These ADC registers are data registers:
  *         when ADC conversion data is available in ADC data registers,
  *         ADC generates a DMA transfer request.
  * @note   This macro is intended to be used with DDL DMA driver, refer to
  *         function "DDL_DMA_ConfigAddresses()".
  *         Example:
  *           DDL_DMA_ConfigAddresses(DMA,
  *                                  DDL_DMA_CHANNEL_1,
  *                                  DDL_ADC_DMA_GetRegAddr(ADC, DDL_ADC_DMA_REG_REGULAR_DATA),
  *                                  (uint32_t)&< array or variable >,
  *                                  DDL_DMA_DIRECTION_PERIPH_TO_MEMORY);
  * @note   For devices with several ADC: in multimode, some devices
  *         use a different data register outside of ADC instance scope
  *         (common data register). This macro manages this register difference,
  *         only ADC instance has to be set as parameter.
  * @param  ADCx ADC instance
  * @param  Register This parameter can be one of the following values:
  *         @arg @ref DDL_ADC_DMA_REG_REGULAR_DATA

  * @retval ADC register address
  */
__STATIC_INLINE uint32_t DDL_ADC_DMA_GetRegAddr(ADC_TypeDef *ADCx, uint32_t Register)
{
  /* Prevent unused argument(s) compilation warning */
  (void)(Register);

  /* Retrieve address of register DR */
  return (uint32_t) &(ADCx->DR);
}

/**
  * @}
  */


/** @defgroup ADC_DDL_EF_Configuration_ADC_Group_Regular Configuration of ADC hierarchical scope: group regular
  * @{
  */
/**
  * @brief  Set ADC group regular conversion trigger source:
  *         internal (SW start) or from external peripheral (timer event,
  *         external interrupt line).
  *         Trigger edge set to rising edge (default setting).
  * @note   Availability of parameters of trigger sources from timer
  *         depends on timers availability on the selected device.
  * @param  ADCx ADC instance
  * @param  TriggerSource This parameter can be one of the following values:
  *         @arg @ref DDL_ADC_REG_TRIG_SOFTWARE
  *         @arg @ref DDL_ADC_REG_TRIG_EXTSEL_ATMR_TRGO0
  *         @arg @ref DDL_ADC_REG_TRIG_EXTSEL_ATMR_TRGO1
  *         @arg @ref DDL_ADC_REG_TRIG_EXTSEL_ATMR_TRGO2
  *         @arg @ref DDL_ADC_REG_TRIG_EXTSEL_GTMR_TRGO0
  * @retval None
  */
__STATIC_INLINE void DDL_ADC_REG_SetTriggerSource(ADC_TypeDef *ADCx, uint32_t TriggerSource)
{
  MODIFY_REG(ADCx->CFGR1, ADC_CFGR1_EXTSEL1 | ADC_CFGR1_EXTEN1, TriggerSource);
}

/**
  * @brief  Get ADC group regular conversion trigger source:
  *         internal (SW start) or from external peripheral (timer event,
  *         external interrupt line).
  * @note   Availability of parameters of trigger sources from timer
  *         depends on timers availability on the selected device.
  * @param  ADCx ADC instance
  * @param  TriggerSource This parameter can be one of the following values:
  *         @arg @ref DDL_ADC_REG_TRIG_SOFTWARE
  *         @arg @ref DDL_ADC_REG_TRIG_EXTSEL_ATMR_TRGO0
  *         @arg @ref DDL_ADC_REG_TRIG_EXTSEL_ATMR_TRGO1
  *         @arg @ref DDL_ADC_REG_TRIG_EXTSEL_ATMR_TRGO2
  *         @arg @ref DDL_ADC_REG_TRIG_EXTSEL_GTMR_TRGO0
  *
  * @retval None
  */
__STATIC_INLINE uint32_t DDL_ADC_REG_GetTriggerSource(ADC_TypeDef *ADCx)
{
  uint32_t TriggerExtEn = READ_BIT(ADCx->CFGR1, ADC_CFGR1_EXTEN1);
  if(TriggerExtEn == 0U)
  {
    return DDL_ADC_REG_TRIG_SOFTWARE;
  }
  else
  {
    return (uint32_t)(READ_BIT(ADCx->CFGR1, ADC_CFGR1_EXTSEL1 ) | ADC_REG_TRIG_EXT_EDGE_DEFAULT);
  }
}

/**
  * @brief  Get ADC group regular conversion trigger source internal (SW start)
  *         or external.
  * @param  ADCx ADC instance
  * @param  ExtIndex External trigger selection
  *         @arg @ref DDL_ADC_REG_TRIG_EXTINDEX_1
  *         @arg @ref DDL_ADC_REG_TRIG_EXTINDEX_2
  *         @arg @ref DDL_ADC_REG_TRIG_EXTINDEX_3
  * @retval Value "0" if trigger source external trigger
  *         Value "1" if trigger source SW start.
  */
__STATIC_INLINE uint32_t DDL_ADC_REG_IsTriggerSourceSWStart(ADC_TypeDef *ADCx)
{
  return (uint32_t)(READ_BIT(ADCx->CFGR1, ADC_CFGR1_EXTEN1 ) == 0U);
}

/**
  * @brief  Set ADC group regular conversion trigger polarity.
  * @note   Applicable only for trigger source set to external trigger.
  * @note
  *         ADC must be disabled or enabled without conversion on going
  *         on group regular.
  * @param  ADCx ADC instance
  * @param  ExternalTriggerEdge This parameter can be one of the following values:
  *         @arg @ref DDL_ADC_REG_TRIG_EXTEDGE_RISING
  *         @arg @ref DDL_ADC_REG_TRIG_EXTEDGE_FALLING
  *         @arg @ref DDL_ADC_REG_TRIG_EXTEDGE_RISING_FALLING

  * @retval None
  */
__STATIC_INLINE void DDL_ADC_REG_SetTriggerEdge(ADC_TypeDef *ADCx, uint32_t ExternalTriggerEdge)
{
  MODIFY_REG(ADCx->CFGR1, ADC_CFGR1_EXTEN1, ExternalTriggerEdge);
}

/**
  * @brief  Get ADC group regular conversion trigger polarity.
  * @note   Applicable only for trigger source set to external trigger.
  * @param  ADCx ADC instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref DDL_ADC_REG_TRIG_EXTEDGE_RISING
  *         @arg @ref DDL_ADC_REG_TRIG_EXTEDGE_FALLING
  *         @arg @ref DDL_ADC_REG_TRIG_EXTEDGE_RISING_FALLING
  */
__STATIC_INLINE uint32_t DDL_ADC_REG_GetTriggerEdge(ADC_TypeDef *ADCx)
{
  return (uint32_t)(READ_BIT(ADCx->CFGR1, ADC_CFGR1_EXTEN1));
}

/**
  * @brief  Set ADC group regular sequencer length and scan direction.
  * @note   Description of ADC group regular sequencer features:
  *         - For devices with sequencer fully configurable
  *           (function "DDL_ADC_REG_SetSequencerRanks()" available):
  *           sequencer length and each rank affectation to a channel
  *           are configurable.
  *           This function performs configuration of:
  *           - Sequence length: Number of ranks in the scan sequence.
  *           - Sequence direction: Unless specified in parameters, sequencer
  *             scan direction is forward (from rank 1 to rank n).
  *           Sequencer ranks are selected using
  *           function "DDL_ADC_REG_SetSequencerRanks()".
  *         - For devices with sequencer not fully configurable
  *           (function "DDL_ADC_SetSequencerChannels()" available):
  *           sequencer length and each rank affectation to a channel
  *           are defined by channel number.
  *           This function performs configuration of:
  *           - Sequence length: Number of ranks in the scan sequence is
  *             defined by number of channels set in the sequence,
  *             rank of each channel is fixed by channel HW number.
  *             (channel 0 fixed on rank 0, channel 1 fixed on rank1, ...).
  *           - Sequence direction: Unless specified in parameters, sequencer
  *             scan direction is forward (from lowest channel number to
  *             highest channel number).
  *           Sequencer ranks are selected using
  *           function "DDL_ADC_SetSequencerChannels()".
  * @note   Sequencer disabled is equivalent to sequencer of 1 rank:
  *         ADC conversion on only 1 channel.
  * @note
  *         ADC must be disabled or enabled without conversion on going
  *         on group regular.
  * @param  ADCx ADC instance
  * @param  SequencerNbRanks This parameter can be one of the following values:
  *         @arg @ref DDL_ADC_REG_SEQ_SCAN_DISABLE
  *         @arg @ref DDL_ADC_REG_SEQ_SCAN_ENABLE_2RANKS
  *         @arg @ref DDL_ADC_REG_SEQ_SCAN_ENABLE_3RANKS
  *         @arg @ref DDL_ADC_REG_SEQ_SCAN_ENABLE_4RANKS
  *         @arg @ref DDL_ADC_REG_SEQ_SCAN_ENABLE_5RANKS
  *         @arg @ref DDL_ADC_REG_SEQ_SCAN_ENABLE_6RANKS
  *         @arg @ref DDL_ADC_REG_SEQ_SCAN_ENABLE_7RANKS
  *         @arg @ref DDL_ADC_REG_SEQ_SCAN_ENABLE_8RANKS
  *         @arg @ref DDL_ADC_REG_SEQ_SCAN_ENABLE_9RANKS
  *         @arg @ref DDL_ADC_REG_SEQ_SCAN_ENABLE_10RANKS
  *         @arg @ref DDL_ADC_REG_SEQ_SCAN_ENABLE_11RANKS
  *         @arg @ref DDL_ADC_REG_SEQ_SCAN_ENABLE_12RANKS
  *         @arg @ref DDL_ADC_REG_SEQ_SCAN_ENABLE_13RANKS
  *         @arg @ref DDL_ADC_REG_SEQ_SCAN_ENABLE_14RANKS
  *         @arg @ref DDL_ADC_REG_SEQ_SCAN_ENABLE_15RANKS
  *         @arg @ref DDL_ADC_REG_SEQ_SCAN_ENABLE_16RANKS
  * @retval None
  */
__STATIC_INLINE void DDL_ADC_REG_SetSequencerLength(ADC_TypeDef *ADCx, uint32_t SequencerNbRanks)
{
  MODIFY_REG(ADCx->SQR1, ADC_SQR1_LT3, SequencerNbRanks);
}

/**
  * @brief  Get ADC group regular sequencer length and scan direction.
  * @note   Description of ADC group regular sequencer features:
  *         - For devices with sequencer fully configurable
  *           (function "DDL_ADC_REG_SetSequencerRanks()" available):
  *           sequencer length and each rank affectation to a channel
  *           are configurable.
  *           This function retrieves:
  *           - Sequence length: Number of ranks in the scan sequence.
  *           - Sequence direction: Unless specified in parameters, sequencer
  *             scan direction is forward (from rank 1 to rank n).
  *           Sequencer ranks are selected using
  *           function "DDL_ADC_REG_SetSequencerRanks()".
  *         - For devices with sequencer not fully configurable
  *           (function "DDL_ADC_SetSequencerChannels()" available):
  *           sequencer length and each rank affectation to a channel
  *           are defined by channel number.
  *           This function retrieves:
  *           - Sequence length: Number of ranks in the scan sequence is
  *             defined by number of channels set in the sequence,
  *             rank of each channel is fixed by channel HW number.
  *             (channel 0 fixed on rank 0, channel 1 fixed on rank1, ...).
  *           - Sequence direction: Unless specified in parameters, sequencer
  *             scan direction is forward (from lowest channel number to
  *             highest channel number).
  *           Sequencer ranks are selected using
  *           function "DDL_ADC_SetSequencerChannels()".
  * @note   Sequencer disabled is equivalent to sequencer of 1 rank:
  *         ADC conversion on only 1 channel.
  * @param  ADCx ADC instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref DDL_ADC_REG_SEQ_SCAN_DISABLE
  *         @arg @ref DDL_ADC_REG_SEQ_SCAN_ENABLE_2RANKS
  *         @arg @ref DDL_ADC_REG_SEQ_SCAN_ENABLE_3RANKS
  *         @arg @ref DDL_ADC_REG_SEQ_SCAN_ENABLE_4RANKS
  *         @arg @ref DDL_ADC_REG_SEQ_SCAN_ENABLE_5RANKS
  *         @arg @ref DDL_ADC_REG_SEQ_SCAN_ENABLE_6RANKS
  *         @arg @ref DDL_ADC_REG_SEQ_SCAN_ENABLE_7RANKS
  *         @arg @ref DDL_ADC_REG_SEQ_SCAN_ENABLE_8RANKS
  *         @arg @ref DDL_ADC_REG_SEQ_SCAN_ENABLE_9RANKS
  *         @arg @ref DDL_ADC_REG_SEQ_SCAN_ENABLE_10RANKS
  *         @arg @ref DDL_ADC_REG_SEQ_SCAN_ENABLE_11RANKS
  *         @arg @ref DDL_ADC_REG_SEQ_SCAN_ENABLE_12RANKS
  *         @arg @ref DDL_ADC_REG_SEQ_SCAN_ENABLE_13RANKS
  *         @arg @ref DDL_ADC_REG_SEQ_SCAN_ENABLE_14RANKS
  *         @arg @ref DDL_ADC_REG_SEQ_SCAN_ENABLE_15RANKS
  *         @arg @ref DDL_ADC_REG_SEQ_SCAN_ENABLE_16RANKS
  */
__STATIC_INLINE uint32_t DDL_ADC_REG_GetSequencerLength(ADC_TypeDef *ADCx)
{
  return (uint32_t)(READ_BIT(ADCx->SQR1, ADC_SQR1_LT3));
}

/**
  * @brief  Set ADC group regular sequencer discontinuous mode:
  *         sequence subdivided and scan conversions interrupted every selected
  *         number of ranks.
  * @note   It is not possible to enable both ADC group regular
  *         continuous mode and sequencer discontinuous mode.
  * @note   It is not possible to enable both ADC auto-injected mode
  *         and ADC group regular sequencer discontinuous mode.
  * @param  ADCx ADC instance
  * @param  SeqDiscont This parameter can be one of the following values:
  *         @arg @ref DDL_ADC_REG_SEQ_DISCONT_DISABLE
  *         @arg @ref DDL_ADC_REG_SEQ_DISCONT_1RANK
  *         @arg @ref DDL_ADC_REG_SEQ_DISCONT_2RANKS
  *         @arg @ref DDL_ADC_REG_SEQ_DISCONT_3RANKS
  *         @arg @ref DDL_ADC_REG_SEQ_DISCONT_4RANKS
  *         @arg @ref DDL_ADC_REG_SEQ_DISCONT_5RANKS
  *         @arg @ref DDL_ADC_REG_SEQ_DISCONT_6RANKS
  *         @arg @ref DDL_ADC_REG_SEQ_DISCONT_7RANKS
  *         @arg @ref DDL_ADC_REG_SEQ_DISCONT_8RANKS
  * @retval None
  */
__STATIC_INLINE void DDL_ADC_REG_SetSequencerDiscont(ADC_TypeDef *ADCx, uint32_t SeqDiscont)
{
  MODIFY_REG(ADCx->CFGR1, ADC_CFGR1_DISCEN | ADC_CFGR1_DISCNUM, SeqDiscont);
}

/**
  * @brief  Get ADC group regular sequencer discontinuous mode:
  *         sequence subdivided and scan conversions interrupted every selected
  *         number of ranks.
  * @param  ADCx ADC instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref DDL_ADC_REG_SEQ_DISCONT_DISABLE
  *         @arg @ref DDL_ADC_REG_SEQ_DISCONT_1RANK
  *         @arg @ref DDL_ADC_REG_SEQ_DISCONT_2RANKS
  *         @arg @ref DDL_ADC_REG_SEQ_DISCONT_3RANKS
  *         @arg @ref DDL_ADC_REG_SEQ_DISCONT_4RANKS
  *         @arg @ref DDL_ADC_REG_SEQ_DISCONT_5RANKS
  *         @arg @ref DDL_ADC_REG_SEQ_DISCONT_6RANKS
  *         @arg @ref DDL_ADC_REG_SEQ_DISCONT_7RANKS
  *         @arg @ref DDL_ADC_REG_SEQ_DISCONT_8RANKS
  */
__STATIC_INLINE uint32_t DDL_ADC_REG_GetSequencerDiscont(ADC_TypeDef *ADCx)
{
  return (uint32_t)(READ_BIT(ADCx->CFGR1, (ADC_CFGR1_DISCEN | ADC_CFGR1_DISCNUM)));
}

/**
  * @brief  Set ADC group regular sequence: channel on the selected
  *         scan sequence rank.
  * @note   This function performs configuration of:
  *         - Channels ordering into each rank of scan sequence:
  *           whatever channel can be placed into whatever rank.
  * @param  ADCx ADC instance
  * @param  Rank This parameter can be one of the following values:
  *         @arg @ref DDL_ADC_REG_RANK_1
  *         @arg @ref DDL_ADC_REG_RANK_2
  *         @arg @ref DDL_ADC_REG_RANK_3
  *         @arg @ref DDL_ADC_REG_RANK_4
  *         @arg @ref DDL_ADC_REG_RANK_5
  *         @arg @ref DDL_ADC_REG_RANK_6
  *         @arg @ref DDL_ADC_REG_RANK_7
  *         @arg @ref DDL_ADC_REG_RANK_8
  *         @arg @ref DDL_ADC_REG_RANK_9
  *         @arg @ref DDL_ADC_REG_RANK_10
  *         @arg @ref DDL_ADC_REG_RANK_11
  *         @arg @ref DDL_ADC_REG_RANK_12
  *         @arg @ref DDL_ADC_REG_RANK_13
  *         @arg @ref DDL_ADC_REG_RANK_14
  *         @arg @ref DDL_ADC_REG_RANK_15
  *         @arg @ref DDL_ADC_REG_RANK_16
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref DDL_ADC_CHANNEL_0
  *         @arg @ref DDL_ADC_CHANNEL_1
  *         @arg @ref DDL_ADC_CHANNEL_2
  *         @arg @ref DDL_ADC_CHANNEL_3
  *         @arg @ref DDL_ADC_CHANNEL_4
  *         @arg @ref DDL_ADC_CHANNEL_5
  *         @arg @ref DDL_ADC_CHANNEL_6
  *         @arg @ref DDL_ADC_CHANNEL_7
  *         @arg @ref DDL_ADC_CHANNEL_8
  *         @arg @ref DDL_ADC_CHANNEL_9
  *         @arg @ref DDL_ADC_CHANNEL_10
  *         @arg @ref DDL_ADC_CHANNEL_11
  *         @arg @ref DDL_ADC_CHANNEL_12
  *         @arg @ref DDL_ADC_CHANNEL_13
  * @retval None
  */
__STATIC_INLINE void DDL_ADC_REG_SetSequencerRanks(ADC_TypeDef *ADCx, uint32_t Rank, uint32_t Channel)
{
  /* Set bits with content of parameter "Rank" with bits position in register and register position. */
  __IO uint32_t *preg = __ADC_PTR_REG_OFFSET(ADCx->SQR1, ((OFFSET_TAB_Reg_Rank[Rank] & ADC_SQRX_REGOFFSET_MASK) >> ADC_SQRX_REGOFFSET_POS));

  MODIFY_REG(*preg,
             ADC_CHANNEL_ID_NUMBER_MASK_POSBIT0 << (OFFSET_TAB_Reg_Rank[Rank] & ADC_RANK_ID_SQRX_MASK),
             Channel << (OFFSET_TAB_Reg_Rank[Rank] & ADC_RANK_ID_SQRX_MASK));
}

/**
  * @brief  Get ADC group regular sequence: channel on the selected
  *         scan sequence rank.
  *         Refer to description of function @ref DDL_ADC_REG_SetSequencerLength().
  * @note   Depending on devices and packages, some channels may not be available.
  *         Refer to device datasheet for channels availability.
  * @note   Usage of the returned channel number:
  *         - To reinject this channel into another function DDL_ADC_xxx:
  *           the returned channel number is only partly formatted on definition
  *           of literals DDL_ADC_CHANNEL_x. Therefore, it has to be compared
  *           with parts of literals DDL_ADC_CHANNEL_x or using
  *           helper macro @ref __DDL_ADC_CHANNEL_TO_DECIMAL_NB().
  *           Then the selected literal DDL_ADC_CHANNEL_x can be used
  *           as parameter for another function.
  *         - To get the channel number in decimal format:
  *           process the returned value with the helper macro
  *           @ref __DDL_ADC_CHANNEL_TO_DECIMAL_NB().
  * @param  ADCx ADC instance
  * @param  Rank This parameter can be one of the following values:
  *         @arg @ref DDL_ADC_REG_RANK_1
  *         @arg @ref DDL_ADC_REG_RANK_2
  *         @arg @ref DDL_ADC_REG_RANK_3
  *         @arg @ref DDL_ADC_REG_RANK_4
  *         @arg @ref DDL_ADC_REG_RANK_5
  *         @arg @ref DDL_ADC_REG_RANK_6
  *         @arg @ref DDL_ADC_REG_RANK_7
  *         @arg @ref DDL_ADC_REG_RANK_8
  *         @arg @ref DDL_ADC_REG_RANK_9
  *         @arg @ref DDL_ADC_REG_RANK_10
  *         @arg @ref DDL_ADC_REG_RANK_11
  *         @arg @ref DDL_ADC_REG_RANK_12
  *         @arg @ref DDL_ADC_REG_RANK_13
  *         @arg @ref DDL_ADC_REG_RANK_14
  *         @arg @ref DDL_ADC_REG_RANK_15
  *         @arg @ref DDL_ADC_REG_RANK_16
  * @retval Returned value can be one of the following values:
  *         @arg @ref DDL_ADC_CHANNEL_0
  *         @arg @ref DDL_ADC_CHANNEL_1
  *         @arg @ref DDL_ADC_CHANNEL_2
  *         @arg @ref DDL_ADC_CHANNEL_3
  *         @arg @ref DDL_ADC_CHANNEL_4
  *         @arg @ref DDL_ADC_CHANNEL_5
  *         @arg @ref DDL_ADC_CHANNEL_6
  *         @arg @ref DDL_ADC_CHANNEL_7
  *         @arg @ref DDL_ADC_CHANNEL_8
  *         @arg @ref DDL_ADC_CHANNEL_9
  *         @arg @ref DDL_ADC_CHANNEL_10
  *         @arg @ref DDL_ADC_CHANNEL_11
  *         @arg @ref DDL_ADC_CHANNEL_12
  *         @arg @ref DDL_ADC_CHANNEL_13
  */
__STATIC_INLINE uint32_t DDL_ADC_REG_GetSequencerRanks(ADC_TypeDef *ADCx, uint32_t Rank)
{
  const __IO uint32_t *preg = __ADC_PTR_REG_OFFSET(ADCx->SQR1, ((OFFSET_TAB_Reg_Rank[Rank] & ADC_SQRX_REGOFFSET_MASK) >> ADC_SQRX_REGOFFSET_POS));

  return (uint32_t)(READ_BIT(*preg, ADC_CHANNEL_ID_NUMBER_MASK_POSBIT0 << (OFFSET_TAB_Reg_Rank[Rank] & ADC_RANK_ID_SQRX_MASK))>>(OFFSET_TAB_Reg_Rank[Rank] & ADC_RANK_ID_SQRX_MASK));
}

/**
  * @brief  Set ADC continuous conversion mode on ADC group regular.
  * @note   Description of ADC continuous conversion mode:
  *         - single mode: one conversion per trigger
  *         - continuous mode: after the first trigger, following
  *           conversions launched successively automatically.
  * @note   It is not possible to enable both ADC group regular
  *         continuous mode and sequencer discontinuous mode.
  * @note
  *         ADC must be disabled or enabled without conversion on going
  *         on group regular.
  * @param  ADCx ADC instance
  * @param  Continuous This parameter can be one of the following values:
  *         @arg @ref DDL_ADC_REG_CONV_SINGLE
  *         @arg @ref DDL_ADC_REG_CONV_CONTINUOUS
  * @retval None
  */
__STATIC_INLINE void DDL_ADC_REG_SetContinuousMode(ADC_TypeDef *ADCx, uint32_t Continuous)
{
  MODIFY_REG(ADCx->CFGR1, ADC_CFGR1_CONT, Continuous);
}

/**
  * @brief  Get ADC continuous conversion mode on ADC group regular.
  * @note   Description of ADC continuous conversion mode:
  *         - single mode: one conversion per trigger
  *         - continuous mode: after the first trigger, following
  *           conversions launched successively automatically.
  * @param  ADCx ADC instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref DDL_ADC_REG_CONV_SINGLE
  *         @arg @ref DDL_ADC_REG_CONV_CONTINUOUS
  */
__STATIC_INLINE uint32_t DDL_ADC_REG_GetContinuousMode(ADC_TypeDef *ADCx)
{
  return (uint32_t)(READ_BIT(ADCx->CFGR1, ADC_CFGR1_CONT));
}

/**
  * @brief  Set ADC group regular conversion data transfer: no transfer or
  *         transfer by DMA, and DMA requests mode.
  * @note   If transfer by DMA selected, specifies the DMA requests
  *         mode:
  *         - Limited mode (One shot mode): DMA transfer requests are stopped
  *           when number of DMA data transfers (number of
  *           ADC conversions) is reached.
  *           This ADC mode is intended to be used with DMA mode non-circular.
  *         - Unlimited mode: DMA transfer requests are unlimited,
  *           whatever number of DMA data transfers (number of
  *           ADC conversions).
  *           This ADC mode is intended to be used with DMA mode circular.
  * @note   If ADC DMA requests mode is set to unlimited and DMA is set to
  *         mode non-circular:
  *         when DMA transfers size will be reached, DMA will stop transfers of
  *         ADC conversions data ADC will raise an overrun error
  *        (overrun flag and interruption if enabled).
  * @note   To configure DMA source address (peripheral address),
  *         use function @ref DDL_ADC_DMA_GetRegAddr().
  * @note
  *         ADC must be disabled or enabled without conversion on going
  *         on either groups regular or injected.
  * @param  ADCx ADC instance
  * @param  DMATransfer This parameter can be one of the following values:
  *         @arg @ref DDL_ADC_REG_DMA_TRANSFER_DISABLE
  *         @arg @ref DDL_ADC_REG_DMA_TRANSFER_ONESHOT_MODE
  *         @arg @ref DDL_ADC_REG_DMA_TRANSFER_CIRCULAR_MODE
  * @retval None
  */
__STATIC_INLINE void DDL_ADC_REG_SetDMATransfer(ADC_TypeDef *ADCx, uint32_t DMATransfer)
{
  MODIFY_REG(ADCx->CFGR1, (ADC_CFGR1_DMAEN | ADC_CFGR1_DMACFG), DMATransfer);
}

/**
  * @brief  Get ADC group regular conversion data transfer: no transfer or
  *         transfer by DMA, and DMA requests mode.
  * @note   If transfer by DMA selected, specifies the DMA requests
  *         mode:
  *         - Limited mode (One shot mode): DMA transfer requests are stopped
  *           when number of DMA data transfers (number of
  *           ADC conversions) is reached.
  *           This ADC mode is intended to be used with DMA mode non-circular.
  *         - Unlimited mode: DMA transfer requests are unlimited,
  *           whatever number of DMA data transfers (number of
  *           ADC conversions).
  *           This ADC mode is intended to be used with DMA mode circular.
  * @note   If ADC DMA requests mode is set to unlimited and DMA is set to
  *         mode non-circular:
  *         when DMA transfers size will be reached, DMA will stop transfers of
  *         ADC conversions data ADC will raise an overrun error
  *         (overrun flag and interruption if enabled).
  * @note   To configure DMA source address (peripheral address),
  *         use function @ref DDL_ADC_DMA_GetRegAddr().
  * @param  ADCx ADC instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref DDL_ADC_REG_DMA_TRANSFER_DISABLE
  *         @arg @ref DDL_ADC_REG_DMA_TRANSFER_ONESHOT_MODE
  *         @arg @ref DDL_ADC_REG_DMA_TRANSFER_CIRCULAR_MODE
  */
__STATIC_INLINE uint32_t DDL_ADC_REG_GetDMATransfer(ADC_TypeDef *ADCx)
{
  return (uint32_t)(READ_BIT(ADCx->CFGR1, ADC_CFGR1_DMAEN | ADC_CFGR1_DMACFG));
}

/**
  * @}
  */


/** @defgroup ADC_DDL_EF_Configuration_ADC_Sequencial_Section Configuration of ADC hierarchical scope: sequential section
  * @{
  */
/**
  * @brief  Set ADC sequential section conversion trigger source:
  *         from external peripheral (timer event,
  *         external interrupt line).
  *         Trigger edge set to rising edge (default setting).
  * @note   Availability of parameters of trigger sources from timer
  *         depends on timers availability on the selected device.
  * @param  ADCx ADC instance
  * @param  SectionIndex External trigger for selection x
  *         @arg @ref DDL_ADC_SEQ_SECTION_1
  *         @arg @ref DDL_ADC_SEQ_SECTION_2
  *         @arg @ref DDL_ADC_SEQ_SECTION_3
  * @param  TriggerSource This parameter can be one of the following values:
  *         @arg @ref DDL_ADC_SEQ_TRIG_EXTSEL_ATMR_TRGO0
  *         @arg @ref DDL_ADC_SEQ_TRIG_EXTSEL_ATMR_TRGO1
  *         @arg @ref DDL_ADC_SEQ_TRIG_EXTSEL_ATMR_TRGO2
  *         @arg @ref DDL_ADC_SEQ_TRIG_EXTSEL_GTMR_TRGO0
  * @retval None
  */
__STATIC_INLINE void DDL_ADC_SEQ_SetTriggerSource(ADC_TypeDef *ADCx, uint32_t SectionIndex, uint32_t TriggerSource)
{
  __IO uint32_t *preg = __ADC_PTR_REG_OFFSET(ADCx->CFGR1, ((OFFSET_TAB_SEQ_TrigExtselx[SectionIndex] & ADC_CFGRX_REGOFFSET_MASK) >> ADC_CFGRX_REGOFFSET_POS));

  MODIFY_REG(*preg,
             (ADC_CFGR3_EXTSEL2 << (OFFSET_TAB_SEQ_TrigExtselx[SectionIndex] & ADC_EXTSEL_POS_CFGRX_MASK)),
             (((TriggerSource & ADC_CFGR3_EXTSEL2) << (OFFSET_TAB_SEQ_TrigExtselx[SectionIndex] & ADC_EXTSEL_POS_CFGRX_MASK))));
}

/**
  * @brief  Get ADC group regular conversion trigger source:
  *         internal (SW start) or from external peripheral (timer event,
  *         external interrupt line).
  * @note   Availability of parameters of trigger sources from timer
  *         depends on timers availability on the selected device.
  * @param  ADCx ADC instance
  * @param  SectionIndex External trigger for selection x
  *         @arg @ref DDL_ADC_SEQ_SECTION_1
  *         @arg @ref DDL_ADC_SEQ_SECTION_2
  *         @arg @ref DDL_ADC_SEQ_SECTION_3
  * @param  TriggerSource This parameter can be one of the following values:
  *         @arg @ref DDL_ADC_SEQ_TRIG_EXTSEL_ATMR_TRGO0
  *         @arg @ref DDL_ADC_SEQ_TRIG_EXTSEL_ATMR_TRGO1
  *         @arg @ref DDL_ADC_SEQ_TRIG_EXTSEL_ATMR_TRGO2
  *         @arg @ref DDL_ADC_SEQ_TRIG_EXTSEL_GTMR_TRGO0
  *
  * @retval None
  */
__STATIC_INLINE uint32_t DDL_ADC_SEQ_GetTriggerSource(ADC_TypeDef *ADCx, uint32_t SectionIndex)
{
  const __IO uint32_t *preg = __ADC_PTR_REG_OFFSET(ADCx->CFGR1, ((OFFSET_TAB_SEQ_TrigExtselx[SectionIndex] & ADC_CFGRX_REGOFFSET_MASK) >> ADC_CFGRX_REGOFFSET_POS));

  uint32_t TriggerSource = READ_BIT(*preg, ADC_CFGR3_EXTSEL2 << (OFFSET_TAB_SEQ_TrigExtselx[SectionIndex] & ADC_EXTSEL_POS_CFGRX_MASK)) >>
                                                                 (OFFSET_TAB_SEQ_TrigExtselx[SectionIndex] & ADC_EXTSEL_POS_CFGRX_MASK);

  return (TriggerSource & ADC_CFGR3_EXTSEL2);
}

/**
  * @brief  Set ADC group regular conversion trigger polarity.
  * @note   Applicable only for trigger source set to external trigger.
  * @note
  *         ADC must be disabled or enabled without conversion on going
  *         on group regular.
  * @param  ADCx ADC instance
  * @param  SectionIndex External trigger selection
  *         @arg @ref DDL_ADC_SEQ_SECTION_1
  *         @arg @ref DDL_ADC_SEQ_SECTION_2
  *         @arg @ref DDL_ADC_SEQ_SECTION_3
  * @param  ExternalTriggerEdge This parameter can be one of the following values:
  *         @arg @ref DDL_ADC_SEQ_TRIG_EXTEDGE_RISING
  *         @arg @ref DDL_ADC_SEQ_TRIG_EXTEDGE_FALLING
  *         @arg @ref DDL_ADC_SEQ_TRIG_EXTEDGE_RISING_FALLING

  * @retval None
  */
__STATIC_INLINE void DDL_ADC_SEQ_SetTriggerEdge(ADC_TypeDef *ADCx, uint32_t SectionIndex, uint32_t ExternalTriggerEdge)
{
  __IO uint32_t *preg = __ADC_PTR_REG_OFFSET(ADCx->CFGR1, ((OFFSET_TAB_SEQ_TrigExtedge[SectionIndex] & ADC_CFGRX_REGOFFSET_MASK) >> ADC_CFGRX_REGOFFSET_POS));

  MODIFY_REG(*preg,
             ADC_CFGR3_EXTEN2 << (OFFSET_TAB_SEQ_TrigExtedge[SectionIndex] & ADC_EXTEN_POS_CFGRX_MASK),
             ExternalTriggerEdge << (OFFSET_TAB_SEQ_TrigExtedge[SectionIndex] & ADC_EXTEN_POS_CFGRX_MASK));
}

/**
  * @brief  Get ADC group regular conversion trigger polarity.
  * @note   Applicable only for trigger source set to external trigger.
  * @param  ADCx ADC instance
  * @param  SectionIndex External trigger selection
  *         @arg @ref DDL_ADC_SEQ_SECTION_1
  *         @arg @ref DDL_ADC_SEQ_SECTION_2
  *         @arg @ref DDL_ADC_SEQ_SECTION_3
  * @retval Returned value can be one of the following values:
  *         @arg @ref DDL_ADC_SEQ_TRIG_EXTEDGE_RISING
  *         @arg @ref DDL_ADC_SEQ_TRIG_EXTEDGE_FALLING
  *         @arg @ref DDL_ADC_SEQ_TRIG_EXTEDGE_RISING_FALLING
  */
__STATIC_INLINE uint32_t DDL_ADC_SEQ_GetTriggerEdge(ADC_TypeDef *ADCx, uint32_t SectionIndex)
{
  const __IO uint32_t *preg = __ADC_PTR_REG_OFFSET(ADCx->CFGR1, ((OFFSET_TAB_SEQ_TrigExtedge[SectionIndex] & ADC_CFGRX_REGOFFSET_MASK) >> ADC_CFGRX_REGOFFSET_POS));

  return (uint32_t)(READ_BIT(*preg, ADC_CFGR3_EXTEN2 << (OFFSET_TAB_SEQ_TrigExtedge[SectionIndex] & ADC_EXTEN_POS_CFGRX_MASK)) >>
                                                        (OFFSET_TAB_SEQ_TrigExtedge[SectionIndex] & ADC_EXTEN_POS_CFGRX_MASK));
}
/**
  * @}
  */

/** @defgroup ADC_DDL_EF_Configuration_Channels Configuration of ADC hierarchical scope: channels
  * @{
  */
/**
  * @brief  Set sampling time of the selected ADC fast channel
  *         Unit: ADC clock cycles.
  * @note   On this device, sampling time is on channel scope: independently
  *         of channel mapped on ADC group regular or injected.
  * @note   In case of internal channel (VrefInt, TempSensor, ...) to be
  *         converted:
  *         sampling time constraints must be respected (sampling time can be
  *         adjusted in function of ADC clock frequency and sampling time
  *         setting).
  *         Refer to device datasheet for timings values (parameters TS_vrefint,
  *         TS_temp, ...).
  * @note   In case of ADC conversion of internal channel (VrefInt,
  *         temperature sensor, ...), a sampling time minimum value
  *         is required.
  *         Refer to device datasheet.
  * @param  ADCx ADC instance
  * @param  SamplingTime This parameter can be one of the following values:
  *         @arg @ref DDL_ADC_SAMPLINGTIME_FAST_3CYCLES
  *         @arg @ref DDL_ADC_SAMPLINGTIME_FAST_8CYCLES
  *         @arg @ref DDL_ADC_SAMPLINGTIME_FAST_16CYCLES
  *         @arg @ref DDL_ADC_SAMPLINGTIME_FAST_32CYCLES
  *         @arg @ref DDL_ADC_SAMPLINGTIME_FAST_64CYCLES
  *         @arg @ref DDL_ADC_SAMPLINGTIME_FAST_96CYCLES
  *         @arg @ref DDL_ADC_SAMPLINGTIME_FAST_128CYCLES
  *         @arg @ref DDL_ADC_SAMPLINGTIME_FAST_256CYCLES
  *
  * @retval None
  */
__STATIC_INLINE void DDL_ADC_SetFastChannelSamplingTime(ADC_TypeDef *ADCx, uint32_t SamplingTime)
{
  MODIFY_REG(ADCx->SMPR1, ADC_SMPR1_SMP1_FAST, SamplingTime);
}

/**
  * @brief  Get sampling time of the selected ADC fast channel
  *         Unit: ADC clock cycles.
  * @note   On this device, sampling time is on channel scope: independently
  *         of channel mapped on ADC group regular or injected.
  * @param  ADCx ADC instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref DDL_ADC_SAMPLINGTIME_FAST_3CYCLES
  *         @arg @ref DDL_ADC_SAMPLINGTIME_FAST_8CYCLES
  *         @arg @ref DDL_ADC_SAMPLINGTIME_FAST_16CYCLES
  *         @arg @ref DDL_ADC_SAMPLINGTIME_FAST_32CYCLES
  *         @arg @ref DDL_ADC_SAMPLINGTIME_FAST_64CYCLES
  *         @arg @ref DDL_ADC_SAMPLINGTIME_FAST_96CYCLES
  *         @arg @ref DDL_ADC_SAMPLINGTIME_FAST_128CYCLES
  *         @arg @ref DDL_ADC_SAMPLINGTIME_FAST_256CYCLES
  */
__STATIC_INLINE uint32_t DDL_ADC_GetFastChannelSamplingTime(ADC_TypeDef *ADCx)
{
  return (uint32_t)(READ_BIT(ADCx->SMPR1, ADC_SMPR1_SMP1_FAST));
}

/**
  * @brief  Set sampling time of the selected ADC fast channel
  *         Unit: ADC clock cycles.
  * @note   On this device, sampling time is on channel scope: independently
  *         of channel mapped on ADC group regular or injected.
  * @note   In case of internal channel (VrefInt, TempSensor, ...) to be
  *         converted:
  *         sampling time constraints must be respected (sampling time can be
  *         adjusted in function of ADC clock frequency and sampling time
  *         setting).
  *         Refer to device datasheet for timings values (parameters TS_vrefint,
  *         TS_temp, ...).
  * @note   In case of ADC conversion of internal channel (VrefInt,
  *         temperature sensor, ...), a sampling time minimum value
  *         is required.
  *         Refer to device datasheet.
  * @param  ADCx ADC instance
  * @param  SamplingTime This parameter can be one of the following values:
  *         @arg @ref DDL_ADC_SAMPLINGTIME_SLOW_128CYCLES
  *         @arg @ref DDL_ADC_SAMPLINGTIME_SLOW_160CYCLES
  *         @arg @ref DDL_ADC_SAMPLINGTIME_SLOW_192CYCLES
  *         @arg @ref DDL_ADC_SAMPLINGTIME_SLOW_224CYCLES
  *         @arg @ref DDL_ADC_SAMPLINGTIME_SLOW_256CYCLES
  *
  * @retval None
  */
__STATIC_INLINE void DDL_ADC_SetSlowChannelSamplingTime(ADC_TypeDef *ADCx, uint32_t SamplingTime)
{
  MODIFY_REG(ADCx->SMPR1, ADC_SMPR1_SMP1_SLOW, SamplingTime);
}

/**
  * @brief  Get sampling time of the selected ADC fast channel
  *         Unit: ADC clock cycles.
  * @note   On this device, sampling time is on channel scope: independently
  *         of channel mapped on ADC group regular or injected.
  * @param  ADCx ADC instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref DDL_ADC_SAMPLINGTIME_SLOW_128CYCLES
  *         @arg @ref DDL_ADC_SAMPLINGTIME_SLOW_160CYCLES
  *         @arg @ref DDL_ADC_SAMPLINGTIME_SLOW_192CYCLES
  *         @arg @ref DDL_ADC_SAMPLINGTIME_SLOW_224CYCLES
  *         @arg @ref DDL_ADC_SAMPLINGTIME_SLOW_256CYCLES
  */
__STATIC_INLINE uint32_t DDL_ADC_GetSlowChannelSamplingTime(ADC_TypeDef *ADCx)
{
  return (uint32_t)(READ_BIT(ADCx->SMPR1, ADC_SMPR1_SMP1_SLOW));
}

/**
  * @}
  */

/** @defgroup ADC_DDL_EF_Operation_ADC_Instance Operation on ADC hierarchical scope: ADC instance
  * @{
  */
/**
  * @brief  Enable the selected ADC instance.
  * @param  ADCx ADC instance
  * @retval None
  */
__STATIC_INLINE void DDL_ADC_Enable(ADC_TypeDef *ADCx)
{
  /* Note: Write register with some additional bits forced to state reset     */
  /*       instead of modifying only the selected bit for this function,      */
  /*       to not interfere with bits with HW property "rs".                  */
  MODIFY_REG(ADCx->CR,
             ADC_CR_BITS_PROPERTY_RS,
             ADC_CR_ADEN);
}

/**
  * @brief  Disable the selected ADC instance.
  * @param  ADCx ADC instance
  * @retval None
  */
__STATIC_INLINE void DDL_ADC_Disable(ADC_TypeDef *ADCx)
{
  /* Note: Write register with some additional bits forced to state reset     */
  /*       instead of modifying only the selected bit for this function,      */
  /*       to not interfere with bits with HW property "rs".                  */
  MODIFY_REG(ADCx->CR,
             ADC_CR_BITS_PROPERTY_RS,
             0);
}

/**
  * @brief  Get the selected ADC instance enable state.
  * @param  ADCx ADC instance
  * @retval 0: ADC is disabled, 1: ADC is enabled.
  */
__STATIC_INLINE uint32_t DDL_ADC_IsEnabled(ADC_TypeDef *ADCx)
{
  return ((READ_BIT(ADCx->CR, ADC_CR_ADEN) == (ADC_CR_ADEN)) ? 1UL : 0UL);
}

/**
  * @brief  Set VREF selection.
  * @param  ADCx ADC instance
  * @param  Vref
  *         @arg @ref DDL_ADC_VREF_SEL_VDD5
  *         @arg @ref DDL_ADC_VREF_SEL_GPIO_INPUT
  * @retval None.
  */
__STATIC_INLINE void DDL_ADC_SetVREF(ADC_TypeDef *ADCx, uint32_t Vref)
{
    MODIFY_REG(ADCx->CR,
             ADC_CR_VREF_SEL,
             Vref);
}

/**
  * @brief  Get VREF selection.
  * @param  ADCx ADC instance
  * @retval VREF
  *         @arg @ref DDL_ADC_VREF_SEL_VDD5
  *         @arg @ref DDL_ADC_VREF_SEL_GPIO_INPUT
  */
__STATIC_INLINE uint32_t DDL_ADC_GetVREF(ADC_TypeDef *ADCx)
{
    return (uint32_t)READ_BIT(ADCx->CR, ADC_CR_VREF_SEL);
}

/**
  * @brief  Set ADC data alignment.
  * @param  ADCx ADC instance
  * @param  Data Alignment.
  *         @arg @ref DDL_ADC_ALIGNMENT_LEFT
  *         @arg @ref DDL_ADC_ALIGNMENT_RIGHT
  * @retval None.
  */
__STATIC_INLINE void DDL_ADC_SetDataAlignment(ADC_TypeDef *ADCx, uint32_t Alignment)
{
    MODIFY_REG(ADCx->CFGR1,
             ADC_CFGR1_ALIGN,
             Alignment);
}

/**
  * @brief  Get ADC data alignment.
  * @param  ADCx ADC instance
  * @retval Data Alignment.
  *         @arg @ref DDL_ADC_ALIGNMENT_LEFT
  *         @arg @ref DDL_ADC_ALIGNMENT_RIGHT
  */
__STATIC_INLINE uint32_t DDL_ADC_GetDataAlignment(ADC_TypeDef *ADCx)
{
    return (uint32_t)READ_BIT(ADCx->CFGR1, ADC_CFGR1_ALIGN);
}

/**
  * @brief  Set ADC overflow mode.
  * @param  ADCx ADC instance
  * @param  OverMode.
  *         @arg @ref DDL_ADC_OVERMODE_KEEP
  *         @arg @ref DDL_ADC_OVERMODE_OVER
  * @retval None.
  */
__STATIC_INLINE void DDL_ADC_SetOverflowMode(ADC_TypeDef *ADCx, uint32_t OverMode)
{
    MODIFY_REG(ADCx->CFGR1,
             ADC_CFGR1_OVRMOD,
             OverMode);
}

/**
  * @brief  Get ADC overflow mode.
  * @param  ADCx ADC instance
  * @retval Overflow mode.
  *         @arg @ref DDL_ADC_OVERMODE_KEEP
  *         @arg @ref DDL_ADC_OVERMODE_OVER
  */
__STATIC_INLINE uint32_t DDL_ADC_GetOverflowMode(ADC_TypeDef *ADCx)
{
    return (uint32_t)READ_BIT(ADCx->CFGR1, ADC_CFGR1_OVRMOD);
}

/**
  * @brief  Enable ADC delayed conversion mode.
  * @param  ADCx ADC instance
  * @retval None.
  */
__STATIC_INLINE void DDL_ADC_EnableDelayedConversionMode(ADC_TypeDef *ADCx)
{
    SET_BIT(ADCx->CFGR1, ADC_CFGR1_AUTDLY);
}

/**
  * @brief  Disable ADC delayed conversion mode.
  * @param  ADCx ADC instance
  * @retval None.
  */
__STATIC_INLINE void DDL_ADC_DisableDelayedConversionMode(ADC_TypeDef *ADCx)
{
    CLEAR_BIT(ADCx->CFGR1, ADC_CFGR1_AUTDLY);
}

/**
  * @brief  Check if ADC delayed conversion mode is already enabled.
  * @param  ADCx ADC instance
  * @retval 0: disable.
            1: enable.
  */
__STATIC_INLINE uint32_t DDL_ADC_IsEnabled_DelayedConversionMode(ADC_TypeDef *ADCx)
{
  return ((READ_BIT(ADCx->CFGR1, ADC_CFGR1_AUTDLY) == (ADC_CFGR1_AUTDLY)) ? 1UL : 0UL);
}

/**
  * @brief  Enable ADC Auto-Off mode.
  * @param  ADCx ADC instance
  * @retval None.
  */
__STATIC_INLINE void DDL_ADC_EnableAutoOffMode(ADC_TypeDef *ADCx)
{
    SET_BIT(ADCx->CFGR1, ADC_CFGR1_AUTOFF);
}

/**
  * @brief  Disable ADC Auto-Off mode.
  * @param  ADCx ADC instance
  * @retval None.
  */
__STATIC_INLINE void DDL_ADC_DisableAutoOffMode(ADC_TypeDef *ADCx)
{
    CLEAR_BIT(ADCx->CFGR1, ADC_CFGR1_AUTOFF);
}

/**
  * @brief  Check if ADC Auto-Off mode is already enabled.
  * @param  ADCx ADC instance
  * @retval 0: disable.
            1: enable.
  */
__STATIC_INLINE uint32_t DDL_ADC_IsEnabled_AutoOffMode(ADC_TypeDef *ADCx)
{
  return ((READ_BIT(ADCx->CFGR1, ADC_CFGR1_AUTOFF) == (ADC_CFGR1_AUTOFF)) ? 1UL : 0UL);
}

/**
  * @brief  Enable ADC sequential section sampling.
  * @param  ADCx ADC instance
  * @retval None.
  */
__STATIC_INLINE void DDL_ADC_SEQ_Enable(ADC_TypeDef *ADCx)
{
    SET_BIT(ADCx->CFGR2, ADC_CFGR2_SEQEN);
}

/**
  * @brief  Disable ADC sequential section sampling.
  * @param  ADCx ADC instance
  * @retval None.
  */
__STATIC_INLINE void DDL_ADC_SEQ_Disable(ADC_TypeDef *ADCx)
{
    CLEAR_BIT(ADCx->CFGR2, ADC_CFGR2_SEQEN);
}

/**
  * @brief  Check if ADC sequential section sampling is already enabled.
  * @param  ADCx ADC instance
  * @retval 0: disable.
            1: enable.
  */
__STATIC_INLINE uint32_t DDL_ADC_SEQ_IsEnabled(ADC_TypeDef *ADCx)
{
  return ((READ_BIT(ADCx->CFGR2, ADC_CFGR2_SEQEN) == (ADC_CFGR2_SEQEN)) ? 1UL : 0UL);
}

/**
  * @brief  Set Time of the gap between conversions in sequential section configure.
  * @param  ADCx ADC instance
  * @param  GapTime
  *         @arg @ref DDL_ADC_GAPTIME_ADCCLK_0
  *         @arg @ref DDL_ADC_GAPTIME_ADCCLK_2
  *         @arg @ref DDL_ADC_GAPTIME_ADCCLK_4
  *         @arg @ref DDL_ADC_GAPTIME_ADCCLK_8
  *         @arg @ref DDL_ADC_GAPTIME_ADCCLK_16
  *         @arg @ref DDL_ADC_GAPTIME_ADCCLK_32
  *         @arg @ref DDL_ADC_GAPTIME_ADCCLK_64
  *         @arg @ref DDL_ADC_GAPTIME_ADCCLK_128
  *         @arg @ref DDL_ADC_GAPTIME_ADCCLK_256
  *         @arg @ref DDL_ADC_GAPTIME_ADCCLK_512
  *         @arg @ref DDL_ADC_GAPTIME_ADCCLK_1024
  *         @arg @ref DDL_ADC_GAPTIME_ADCCLK_2048
  *         @arg @ref DDL_ADC_GAPTIME_ADCCLK_4096
  *         @arg @ref DDL_ADC_GAPTIME_ADCCLK_8192
  *         @arg @ref DDL_ADC_GAPTIME_ADCCLK_16384
  *         @arg @ref DDL_ADC_GAPTIME_ADCCLK_32768
  * @retval None.
  */
__STATIC_INLINE void DDL_ADC_SEQ_SetGapTime(ADC_TypeDef *ADCx, uint32_t GapTime)
{
    MODIFY_REG(ADCx->CFGR2, ADC_CFGR2_TGAP, GapTime);
}

/**
  * @brief  Get Time of the gap between conversions in sequential section configure.
  * @param  ADCx ADC instance
  * @retval
  *         @arg @ref DDL_ADC_GAPTIME_ADCCLK_0
  *         @arg @ref DDL_ADC_GAPTIME_ADCCLK_2
  *         @arg @ref DDL_ADC_GAPTIME_ADCCLK_4
  *         @arg @ref DDL_ADC_GAPTIME_ADCCLK_8
  *         @arg @ref DDL_ADC_GAPTIME_ADCCLK_16
  *         @arg @ref DDL_ADC_GAPTIME_ADCCLK_32
  *         @arg @ref DDL_ADC_GAPTIME_ADCCLK_64
  *         @arg @ref DDL_ADC_GAPTIME_ADCCLK_128
  *         @arg @ref DDL_ADC_GAPTIME_ADCCLK_256
  *         @arg @ref DDL_ADC_GAPTIME_ADCCLK_512
  *         @arg @ref DDL_ADC_GAPTIME_ADCCLK_1024
  *         @arg @ref DDL_ADC_GAPTIME_ADCCLK_2048
  *         @arg @ref DDL_ADC_GAPTIME_ADCCLK_4096
  *         @arg @ref DDL_ADC_GAPTIME_ADCCLK_8192
  *         @arg @ref DDL_ADC_GAPTIME_ADCCLK_16384
  *         @arg @ref DDL_ADC_GAPTIME_ADCCLK_32768
  */
__STATIC_INLINE uint32_t DDL_ADC_SEQ_GetGapTime(ADC_TypeDef *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CFGR2, ADC_CFGR2_TGAP));
}

/**
  * @brief  Set the number of sequential section.
  * @param  ADCx ADC instance
  * @param  number
  *         @arg @ref DDL_ADC_SEQ_NUMBER_1
  *         @arg @ref DDL_ADC_SEQ_NUMBER_2
  *         @arg @ref DDL_ADC_SEQ_NUMBER_3
  * @retval None.
  */
__STATIC_INLINE void DDL_ADC_SEQ_SetSectionNumber(ADC_TypeDef *ADCx, uint32_t number)
{
    MODIFY_REG(ADCx->SEQ_NUM, ADC_SEQ_NUM_SG_NUM, number);
}

/**
  * @brief  Get the number of sequential section.
  * @param  ADCx ADC instance
  * @retval
  *         @arg @ref DDL_ADC_SEQ_NUMBER_1
  *         @arg @ref DDL_ADC_SEQ_NUMBER_2
  *         @arg @ref DDL_ADC_SEQ_NUMBER_3
  */
__STATIC_INLINE uint32_t DDL_ADC_SEQ_GetSectionNumber(ADC_TypeDef *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->SEQ_NUM, ADC_SEQ_NUM_SG_NUM));
}

/**
  * @brief  Set the number of sequential section.
  * @param  ADCx ADC instance
  * @param  section
  *         @arg @ref DDL_ADC_SEQ_SECTION_1
  *         @arg @ref DDL_ADC_SEQ_SECTION_2
  *         @arg @ref DDL_ADC_SEQ_SECTION_3
  * @param  time
  *         @arg @ref DDL_ADC_SEQ_TRS_TIME_1
  *         @arg @ref DDL_ADC_SEQ_TRS_TIME_2
  *         @arg @ref DDL_ADC_SEQ_TRS_TIME_3
  *         @arg @ref DDL_ADC_SEQ_TRS_TIME_4
  *         @arg @ref DDL_ADC_SEQ_TRS_TIME_5
  *         @arg @ref DDL_ADC_SEQ_TRS_TIME_6
  *         @arg @ref DDL_ADC_SEQ_TRS_TIME_7
  *         @arg @ref DDL_ADC_SEQ_TRS_TIME_8
  * @retval None.
  */
__STATIC_INLINE void DDL_ADC_SEQ_SetSectionTimes(ADC_TypeDef *ADCx, uint32_t section, uint32_t time)
{
    MODIFY_REG(ADCx->SEQ_NUM, (ADC_SEQ_NUM_SEQ_NUM1 << OFFSET_TAB_SEQ_TransTime[section]), (time << OFFSET_TAB_SEQ_TransTime[section]));
}

/**
  * @brief  Get the number of sequential section.
  * @param  ADCx ADC instance
  * @param  section
  *         @arg @ref DDL_ADC_SEQ_SECTION_1
  *         @arg @ref DDL_ADC_SEQ_SECTION_2
  *         @arg @ref DDL_ADC_SEQ_SECTION_3
  * @retval
  *         @arg @ref DDL_ADC_SEQ_TRS_TIME_1
  *         @arg @ref DDL_ADC_SEQ_TRS_TIME_2
  *         @arg @ref DDL_ADC_SEQ_TRS_TIME_3
  *         @arg @ref DDL_ADC_SEQ_TRS_TIME_4
  *         @arg @ref DDL_ADC_SEQ_TRS_TIME_5
  *         @arg @ref DDL_ADC_SEQ_TRS_TIME_6
  *         @arg @ref DDL_ADC_SEQ_TRS_TIME_7
  *         @arg @ref DDL_ADC_SEQ_TRS_TIME_8
  */
__STATIC_INLINE uint32_t DDL_ADC_SEQ_GetSectionTimes(ADC_TypeDef *ADCx, uint32_t section)
{
    return (uint32_t)(READ_BIT(ADCx->SEQ_NUM, (ADC_SEQ_NUM_SEQ_NUM1 << OFFSET_TAB_SEQ_TransTime[section])) >> OFFSET_TAB_SEQ_TransTime[section]);
}



/**
  * @}
  */

/** @defgroup ADC Calibration
  * @{
  */

/**
  * @brief  Set Calibration Bypass
  * @param  ADCx ADC instance
  * @param  Calc:
  *         @arg @ref DDL_ADC_CALC_NOT_BYPASS
  *         @arg @ref DDL_ADC_CALC_BYPASS
  * @retval None.
  */
__STATIC_INLINE void DDL_ADC_SetCalibrationBypass(ADC_TypeDef *ADCx, uint32_t Calc)
{
    MODIFY_REG(ADCx->TMR,
               ADC_TMR_CALC_BYPASS,
               Calc);
}
/**
  * @brief  Get Calibration Bypass.
  * @param  ADCx ADC instance
  * @retval
  *         @arg @ref DDL_ADC_CALC_NOT_BYPASS
  *         @arg @ref DDL_ADC_CALC_BYPASS
  */
__STATIC_INLINE uint32_t DDL_ADC_GetCalibrationBypass(ADC_TypeDef *ADCx)
{
    return (uint32_t)READ_BIT(ADCx->TMR, ADC_TMR_CALC_BYPASS);
}

/**
  * @}
  */

/** @defgroup ADC_DDL_EF_Operation_ADC_Group_Regular Operation on ADC hierarchical scope: group regular
  * @{
  */
/**
  * @brief  Start ADC group regular conversion.
  * @param  ADCx ADC instance
  * @retval None
  */
__STATIC_INLINE void DDL_ADC_StartConversion(ADC_TypeDef *ADCx)
{
  SET_BIT(ADCx->CR, ADC_CR_ADSTART);
}

/**
  * @brief  Stop ADC group regular conversion.
  * @param  ADCx ADC instance
  * @retval None
  */
__STATIC_INLINE void DDL_ADC_StopConversion(ADC_TypeDef *ADCx)
{
  SET_BIT(ADCx->CR, ADC_CR_ADSTP);
}

/**
  * @brief  Get ADC group regular conversion state.
  * @param  ADCx ADC instance
  * @retval 0: no conversion is on going on ADC group regular.
  */
__STATIC_INLINE uint32_t DDL_ADC_IsConversionOngoing(ADC_TypeDef *ADCx)
{
  return ((READ_BIT(ADCx->CR, ADC_CR_ADSTART) == (ADC_CR_ADSTART)) ? 1UL : 0UL);
}

/**
  * @brief  Get ADC group regular command of conversion stop state
  * @param  ADCx ADC instance
  * @retval 0: no command of conversion stop is on going on ADC group regular.
  */
__STATIC_INLINE uint32_t DDL_ADC_IsStopConversionOngoing(ADC_TypeDef *ADCx)
{
  return ((READ_BIT(ADCx->CR, ADC_CR_ADSTP) == (ADC_CR_ADSTP)) ? 1UL : 0UL);
}

/**
  * @brief  Get ADC group regular conversion data.
  * @param  ADCx ADC instance
  * @retval Value between Min_Data=0x0000 and Max_Data=0xFFFF
  */
__STATIC_INLINE uint32_t DDL_ADC_REG_ReadConversionData(ADC_TypeDef *ADCx)
{
  return (uint32_t)(READ_BIT(ADCx->DR, ADC_DR_RDATA));
}

/**
  * @brief  Get ADC group sequence conversion data.
  * @param  ADCx ADC instance
  * @param  rank
  *         @arg @ref DDL_ADC_SEQ_RANK_RESULT_1
  *         @arg @ref DDL_ADC_SEQ_RANK_RESULT_2
  *         @arg @ref DDL_ADC_SEQ_RANK_RESULT_3
  *         @arg @ref DDL_ADC_SEQ_RANK_RESULT_4
  *         @arg @ref DDL_ADC_SEQ_RANK_RESULT_5
  *         @arg @ref DDL_ADC_SEQ_RANK_RESULT_6
  *         @arg @ref DDL_ADC_SEQ_RANK_RESULT_7
  *         @arg @ref DDL_ADC_SEQ_RANK_RESULT_8
  * @retval Value between Min_Data=0x0000 and Max_Data=0xFFFF
  */
__STATIC_INLINE uint32_t DDL_ADC_SEQ_ReadConversionData(ADC_TypeDef *ADCx, uint32_t rank)
{
  __IO uint32_t *reg = (__IO uint32_t *)((uintptr_t)&(ADCx->DATA0) + 0x4u * rank);

  return (uint32_t)(READ_BIT(*reg, ADC_DATA0_RDATA0));
}

/**
  * @}
  */

/** @defgroup ADC_DDL_EF_FLAG_Management ADC flag management
  * @{
  */

/**
  * @brief  Get flag NUM.3 Sequential Section Sampling Finish.
  * @param  ADCx ADC instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_ADC_IsActiveFlag_EOSMP_SEQ_NUM3(ADC_TypeDef *ADCx)
{
  return ((READ_BIT(ADCx->ISR, ADC_ISR_SEQ_NUM3_FIN) == (ADC_ISR_SEQ_NUM3_FIN)) ? 1UL : 0UL);
}

/**
  * @brief  Get flag NUM.2 Sequential Section Sampling Finish.
  * @param  ADCx ADC instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_ADC_IsActiveFlag_EOSMP_SEQ_NUM2(ADC_TypeDef *ADCx)
{
  return ((READ_BIT(ADCx->ISR, ADC_ISR_SEQ_NUM2_FIN) == (ADC_ISR_SEQ_NUM2_FIN)) ? 1UL : 0UL);
}

/**
  * @brief  Get flag NUM.1 Sequential Section Sampling Finish.
  * @param  ADCx ADC instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_ADC_IsActiveFlag_EOSMP_SEQ_NUM1(ADC_TypeDef *ADCx)
{
  return ((READ_BIT(ADCx->ISR, ADC_ISR_SEQ_NUM1_FIN) == (ADC_ISR_SEQ_NUM1_FIN)) ? 1UL : 0UL);
}

/**
  * @brief  Get flag overrun of group regular conversions.
  * @param  ADCx ADC instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_ADC_IsActiveFlag_OVR(ADC_TypeDef *ADCx)
{
  return ((READ_BIT(ADCx->ISR, ADC_ISR_OVR) == (ADC_ISR_OVR)) ? 1UL : 0UL);
}

/**
  * @brief  Get flag ADC group regular end of unitary conversion.
  * @param  ADCx ADC instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_ADC_IsActiveFlag_EOC(ADC_TypeDef *ADCx)
{
  return ((READ_BIT(ADCx->ISR, ADC_ISR_EOC) == (ADC_ISR_EOC)) ? 1UL : 0UL);
}

/**
  * @brief  Get flag ADC group regular end of sequence conversions.
  * @param  ADCx ADC instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_ADC_IsActiveFlag_EOS(ADC_TypeDef *ADCx)
{
  return ((READ_BIT(ADCx->ISR, ADC_ISR_EOS) == (ADC_ISR_EOS)) ? 1UL : 0UL);
}

/**
  * @brief  Get flag ADC group regular end of sequence sampling.
  * @param  ADCx ADC instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_ADC_IsActiveFlag_EOSMP(ADC_TypeDef *ADCx)
{
  return ((READ_BIT(ADCx->ISR, ADC_ISR_EOSMP) == (ADC_ISR_EOSMP)) ? 1UL : 0UL);
}

/**
  * @brief  Get ADC ready flag.
  * @param  ADCx ADC instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_ADC_IsActiveFlag_RDY(ADC_TypeDef *ADCx)
{
  return ((READ_BIT(ADCx->ISR, ADC_ISR_RDY) == (ADC_ISR_RDY)) ? 1UL : 0UL);
}

/**
  * @brief  Clear flag of NUM.3 Sequential Section Sampling Finish.
  * @param  ADCx ADC instance
  * @retval None
  */
__STATIC_INLINE void DDL_ADC_ClearFlag_EOSMP_SEQ_NUM3(ADC_TypeDef *ADCx)
{
  WRITE_REG(ADCx->ISR, ADC_ISR_SEQ_NUM3_FIN);
}

/**
  * @brief  Clear flag of NUM.2 Sequential Section Sampling Finish.
  * @param  ADCx ADC instance
  * @retval None
  */
__STATIC_INLINE void DDL_ADC_ClearFlag_EOSMP_SEQ_NUM2(ADC_TypeDef *ADCx)
{
  WRITE_REG(ADCx->ISR, ADC_ISR_SEQ_NUM2_FIN);
}

/**
  * @brief  Clear flag of NUM.1 Sequential Section Sampling Finish.
  * @param  ADCx ADC instance
  * @retval None
  */
__STATIC_INLINE void DDL_ADC_ClearFlag_EOSMP_SEQ_NUM1(ADC_TypeDef *ADCx)
{
  WRITE_REG(ADCx->ISR, ADC_ISR_SEQ_NUM1_FIN);
}

/**
  * @brief  Clear flag overrun of group regular conversions.
  * @param  ADCx ADC instance
  * @retval None
  */
__STATIC_INLINE void DDL_ADC_ClearFlag_OVR(ADC_TypeDef *ADCx)
{
  WRITE_REG(ADCx->ISR, ADC_ISR_OVR);
}

/**
  * @brief  Clear flag ADC group regular end of unitary conversion.
  * @param  ADCx ADC instance
  * @retval None
  */
__STATIC_INLINE void DDL_ADC_ClearFlag_EOC(ADC_TypeDef *ADCx)
{
  WRITE_REG(ADCx->ISR, ADC_ISR_EOC);
}

/**
  * @brief  Clear flag ADC group regular end of sequence conversions.
  * @param  ADCx ADC instance
  * @retval None
  */
__STATIC_INLINE void DDL_ADC_ClearFlag_EOS(ADC_TypeDef *ADCx)
{
  WRITE_REG(ADCx->ISR, ADC_ISR_EOS);
}

/**
  * @brief  Clear flag ADC group regular end of sampling flag.
  * @param  ADCx ADC instance
  * @retval None
  */
__STATIC_INLINE void DDL_ADC_ClearFlag_EOSMP(ADC_TypeDef *ADCx)
{
  WRITE_REG(ADCx->ISR, ADC_ISR_EOSMP);
}

/**
  * @brief  Clear flag ADC ready flag.
  * @param  ADCx ADC instance
  * @retval None
  */
__STATIC_INLINE void DDL_ADC_ClearFlag_RDY(ADC_TypeDef *ADCx)
{
  WRITE_REG(ADCx->ISR, ADC_ISR_RDY);
}

/**
  * @}
  */

/** @defgroup ADC_DDL_EF_IT_Management ADC IT management
  * @{
  */

/**
  * @brief  Enable interruption ADC ready.
  * @param  ADCx ADC instance
  * @retval None
  */
__STATIC_INLINE void DDL_ADC_EnableIT_RDY(ADC_TypeDef *ADCx)
{
  SET_BIT(ADCx->IER, ADC_IER_RDYIE);
}

/**
  * @brief  Disable interruption ADC ready.
  * @param  ADCx ADC instance
  * @retval None
  */
__STATIC_INLINE void DDL_ADC_DisableIT_RDY(ADC_TypeDef *ADCx)
{
  CLEAR_BIT(ADCx->IER, ADC_IER_RDYIE);
}

/**
  * @brief  Get state of interruption ADC ready.
  *         (0: interrupt disabled, 1: interrupt enabled).
  * @param  ADCx ADC instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_ADC_IsEnabledIT_RDY(ADC_TypeDef *ADCx)
{
  return ((READ_BIT(ADCx->IER, ADC_IER_RDYIE) == (ADC_IER_RDYIE)) ? 1UL : 0UL);
}

/**
  * @brief  Enable interruption ADC group regular end of sampling.
  * @param  ADCx ADC instance
  * @retval None
  */
__STATIC_INLINE void DDL_ADC_EnableIT_EOSMP(ADC_TypeDef *ADCx)
{
  SET_BIT(ADCx->IER, ADC_IER_EOSMPIE);
}

/**
  * @brief  Disable interruption ADC group regular end of sampling.
  * @param  ADCx ADC instance
  * @retval None
  */
__STATIC_INLINE void DDL_ADC_DisableIT_EOSMP(ADC_TypeDef *ADCx)
{
  CLEAR_BIT(ADCx->IER, ADC_IER_EOSMPIE);
}

/**
  * @brief  Get state of interruption ADC group regular end of sampling.
  *         (0: interrupt disabled, 1: interrupt enabled).
  * @param  ADCx ADC instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_ADC_IsEnabledIT_EOSMP(ADC_TypeDef *ADCx)
{
  return ((READ_BIT(ADCx->IER, ADC_IER_EOSMPIE) == (ADC_IER_EOSMPIE)) ? 1UL : 0UL);
}

/**
  * @brief  Enable interruption ADC group regular end of unitary conversion.
  * @param  ADCx ADC instance
  * @retval None
  */
__STATIC_INLINE void DDL_ADC_EnableIT_EOC(ADC_TypeDef *ADCx)
{
  SET_BIT(ADCx->IER, ADC_IER_EOCIE);
}

/**
  * @brief  Disable interruption ADC group regular end of unitary conversion.
  * @param  ADCx ADC instance
  * @retval None
  */
__STATIC_INLINE void DDL_ADC_DisableIT_EOC(ADC_TypeDef *ADCx)
{
  CLEAR_BIT(ADCx->IER, ADC_IER_EOCIE);
}

/**
  * @brief  Get state of interruption ADC group regular end of unitary conversion
  *         (0: interrupt disabled, 1: interrupt enabled).
  * @param  ADCx ADC instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_ADC_IsEnabledIT_EOC(ADC_TypeDef *ADCx)
{
  return ((READ_BIT(ADCx->IER, ADC_IER_EOCIE) == (ADC_IER_EOCIE)) ? 1UL : 0UL);
}

/**
  * @brief  Enable interruption ADC group regular end of sequence conversions.
  * @param  ADCx ADC instance
  * @retval None
  */
__STATIC_INLINE void DDL_ADC_EnableIT_EOS(ADC_TypeDef *ADCx)
{
  SET_BIT(ADCx->IER, ADC_IER_EOSIE);
}

/**
  * @brief  Disable interruption ADC group regular end of sequence conversions.
  * @param  ADCx ADC instance
  * @retval None
  */
__STATIC_INLINE void DDL_ADC_DisableIT_EOS(ADC_TypeDef *ADCx)
{
  CLEAR_BIT(ADCx->IER, ADC_IER_EOSIE);
}

/**
  * @brief  Get state of interruption ADC group regular end of sequence conversions
  *         (0: interrupt disabled, 1: interrupt enabled).
  * @param  ADCx ADC instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_ADC_IsEnabledIT_EOS(ADC_TypeDef *ADCx)
{
  return ((READ_BIT(ADCx->IER, ADC_IER_EOSIE) == (ADC_IER_EOSIE)) ? 1UL : 0UL);
}

/**
  * @brief  Enable interruption ADC overrun of group regular conversions.
  * @param  ADCx ADC instance
  * @retval None
  */
__STATIC_INLINE void DDL_ADC_EnableIT_OVR(ADC_TypeDef *ADCx)
{
  SET_BIT(ADCx->IER, ADC_IER_OVRIE);
}

/**
  * @brief  Disable interruption ADC overrun of group regular conversions.
  * @param  ADCx ADC instance
  * @retval None
  */
__STATIC_INLINE void DDL_ADC_DisableIT_OVR(ADC_TypeDef *ADCx)
{
  CLEAR_BIT(ADCx->IER, ADC_IER_OVRIE);
}

/**
  * @brief  Get state of interruption ADC overrun of group regular conversions.
  *         (0: interrupt disabled, 1: interrupt enabled).
  * @param  ADCx ADC instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_ADC_IsEnabledIT_OVR(ADC_TypeDef *ADCx)
{
  return ((READ_BIT(ADCx->IER, ADC_IER_OVRIE) == (ADC_IER_OVRIE)) ? 1UL : 0UL);
}

/**
  * @brief  Enable interruption NUM.1 Sequential Section Sampling Finish.
  * @param  ADCx ADC instance
  * @retval None
  */
__STATIC_INLINE void DDL_ADC_EnableIT_EOSMP_SEQ_NUM1(ADC_TypeDef *ADCx)
{
  SET_BIT(ADCx->IER, ADC_IER_SEQ_NUM1_FINIE);
}

/**
  * @brief  Disable interruption NUM.1 Sequential Section Sampling Finish.
  * @param  ADCx ADC instance
  * @retval None
  */
__STATIC_INLINE void DDL_ADC_DisableIT_EOSMP_SEQ_NUM1(ADC_TypeDef *ADCx)
{
  CLEAR_BIT(ADCx->IER, ADC_IER_SEQ_NUM1_FINIE);
}

/**
  * @brief  Get state of interruption NUM.1 Sequential Section Sampling Finish.
  *         (0: interrupt disabled, 1: interrupt enabled).
  * @param  ADCx ADC instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_ADC_IsEnabledIT_EOSMP_SEQ_NUM1(ADC_TypeDef *ADCx)
{
  return ((READ_BIT(ADCx->IER, ADC_IER_SEQ_NUM1_FINIE) == (ADC_IER_SEQ_NUM1_FINIE)) ? 1UL : 0UL);
}

/**
  * @brief  Enable interruption NUM.2 Sequential Section Sampling Finish.
  * @param  ADCx ADC instance
  * @retval None
  */
__STATIC_INLINE void DDL_ADC_EnableIT_EOSMP_SEQ_NUM2(ADC_TypeDef *ADCx)
{
  SET_BIT(ADCx->IER, ADC_IER_SEQ_NUM2_FINIE);
}

/**
  * @brief  Disable interruption NUM.2 Sequential Section Sampling Finish.
  * @param  ADCx ADC instance
  * @retval None
  */
__STATIC_INLINE void DDL_ADC_DisableIT_EOSMP_SEQ_NUM2(ADC_TypeDef *ADCx)
{
  CLEAR_BIT(ADCx->IER, ADC_IER_SEQ_NUM2_FINIE);
}

/**
  * @brief  Get state of interruption NUM.2 Sequential Section Sampling Finish.
  *         (0: interrupt disabled, 1: interrupt enabled).
  * @param  ADCx ADC instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_ADC_IsEnabledIT_EOSMP_SEQ_NUM2(ADC_TypeDef *ADCx)
{
  return ((READ_BIT(ADCx->IER, ADC_IER_SEQ_NUM2_FINIE) == (ADC_IER_SEQ_NUM2_FINIE)) ? 1UL : 0UL);
}

/**
  * @brief  Enable interruption NUM.3 Sequential Section Sampling Finish.
  * @param  ADCx ADC instance
  * @retval None
  */
__STATIC_INLINE void DDL_ADC_EnableIT_EOSMP_SEQ_NUM3(ADC_TypeDef *ADCx)
{
  SET_BIT(ADCx->IER, ADC_IER_SEQ_NUM3_FINIE);
}

/**
  * @brief  Disable interruption NUM.3 Sequential Section Sampling Finish.
  * @param  ADCx ADC instance
  * @retval None
  */
__STATIC_INLINE void DDL_ADC_DisableIT_EOSMP_SEQ_NUM3(ADC_TypeDef *ADCx)
{
  CLEAR_BIT(ADCx->IER, ADC_IER_SEQ_NUM3_FINIE);
}

/**
  * @brief  Get state of interruption NUM.3 Sequential Section Sampling Finish.
  *         (0: interrupt disabled, 1: interrupt enabled).
  * @param  ADCx ADC instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_ADC_IsEnabledIT_EOSMP_SEQ_NUM3(ADC_TypeDef *ADCx)
{
  return ((READ_BIT(ADCx->IER, ADC_IER_SEQ_NUM3_FINIE) == (ADC_IER_SEQ_NUM3_FINIE)) ? 1UL : 0UL);
}

/**
* @}
*/

#if defined(USE_FULL_DDL_DRIVER)
/** @defgroup ADC_DDL_EF_Init Initialization and de-initialization functions
  * @{
  */

/* De-initialization of ADC instance, ADC group regular */
ErrorStatus DDL_ADC_DeInit(ADC_TypeDef *ADCx);

/* Initialization of some features of ADC instance */
ErrorStatus DDL_ADC_Init(ADC_TypeDef *ADCx, DDL_ADC_InitTypeDef *ADC_InitStruct);
void        DDL_ADC_StructInit(DDL_ADC_InitTypeDef *ADC_InitStruct);

/* Initialization of some features of ADC instance and ADC group regular */
ErrorStatus DDL_ADC_REG_Init(ADC_TypeDef *ADCx, DDL_ADC_REG_InitTypeDef *ADC_InitStruct);
void        DDL_ADC_REG_StructInit(DDL_ADC_REG_InitTypeDef *ADC_InitStruct);

/* Initialization of some features of ADC instance and ADC sequential section */
ErrorStatus DDL_ADC_SEQ_Init(ADC_TypeDef *ADCx, DDL_ADC_SEQ_InitTypeDef *ADC_SEQ_InitStruct);
void DDL_ADC_SEQ_StructInit(DDL_ADC_SEQ_InitTypeDef *ADC_SEQ_InitStruct);

/**
  * @}
  */
#endif /* USE_FULL_DDL_DRIVER */

/**
  * @}
  */

/**
  * @}
  */

#endif /* defined (ADC) */
/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif
