/**
  *
  * @file        g32m3101_ddl_atmr.h
  *
  * @brief       Header file of ATMR DDL module.
  *
  * @version     V1.0.1
  *
  * @date        2026-06-15
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
  * Copyright (c) 2016 STMicroelectronics.
  * Copyright (C) 2026 Geehy Semiconductor.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef G32M3101_DDL_ATMR_H
#define G32M3101_DDL_ATMR_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "g32m3xxx.h"
#include "Legacy/g32_ddl_legacy.h"

/** @addtogroup G32M3101_DDL_Driver
  * @{
  */

#if defined (ATMR)

/** @defgroup ATMR_DDL ATMR
  * @{
  */

/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/** @defgroup ATMR_DDL_Private_Variables ATMR Private Variables
  * @{
  */
static const uint8_t DDL_ATMR_OFFSET_TAB_CCMRx[] =
{
  0x00U,         /* 0: TMRx_CH0  */
  0x00U,         /* 1: TMRx_CH0N */
  0x00U,         /* 2: TMRx_CH1  */
  0x00U,         /* 3: TMRx_CH1N */
  0x04U,         /* 4: TMRx_CH2  */
  0x04U,         /* 5: TMRx_CH2N */
  0x04U,         /* 6: TMRx_CH3  */
  0x38U,         /* 7: TMRx_CH4  */
};

static const uint8_t DDL_ATMR_OFFSET_TAB_CCENRx[] =
{
  0x00U,         /* 0: TMRx_CH0  */
  0x00U,         /* 1: TMRx_CH0N */
  0x00U,         /* 2: TMRx_CH1  */
  0x00U,         /* 3: TMRx_CH1N */
  0x00U,         /* 4: TMRx_CH2  */
  0x00U,         /* 5: TMRx_CH2N */
  0x00U,         /* 6: TMRx_CH3  */
  0x30U,         /* 7: TMRx_CH4  */
};

static const uint8_t DDL_ATMR_SHIFT_TAB_OCxx[] =
{
  0U,            /* 0: OC0M, OC0PE, OC0CE */
  0U,            /* 1: - NA */
  8U,            /* 2: OC1M, OC1PE, OC1CE */
  0U,            /* 3: - NA */
  0U,            /* 4: OC2M, OC2PE, OC2CE */
  0U,            /* 5: - NA */
  8U,            /* 6: OC3M, OC3PE, OC3CE */
  6U,            /* 7: OC4M */
  13U,           /* 8: OC4PE */
  2U,            /* 9: OC4CE */
};

static const uint8_t DDL_ATMR_SHIFT_TAB_CCxP[] =
{
  0U,            /* 0: CC0P */
  2U,            /* 1: CC0NP */
  4U,            /* 2: CC1P */
  6U,            /* 3: CC1NP */
  8U,            /* 4: CC2P */
  10U,           /* 5: CC2NP */
  12U,           /* 6: CC3P */
  12U,           /* 7: CC4P */
};

static const uint8_t DDL_ATMR_SHIFT_TAB_OISx[] =
{
  0U,            /* 0: OIS0 */
  1U,            /* 1: OIS0N */
  2U,            /* 2: OIS1 */
  3U,            /* 3: OIS1N */
  4U,            /* 4: OIS2 */
  5U,            /* 5: OIS2N */
  6U             /* 6: OIS3 */
};
/**
  * @}
  */

/* Private constants ---------------------------------------------------------*/
/** @defgroup ATMR_DDL_Private_Constants ATMR Private Constants
  * @{
  */

/* Mask used to set the TDG[x:0] of the DTG bits of the ATMRx_BDT register */
#define DT_DELAY_1 ((uint8_t)0x7F)
#define DT_DELAY_2 ((uint8_t)0x3F)
#define DT_DELAY_3 ((uint8_t)0x1F)
#define DT_DELAY_4 ((uint8_t)0x1F)

/* Mask used to set the DTG[7:5] bits of the DTG bits of the ATMRx_BDT register */
#define DT_RANGE_1 ((uint8_t)0x00)
#define DT_RANGE_2 ((uint8_t)0x80)
#define DT_RANGE_3 ((uint8_t)0xC0)
#define DT_RANGE_4 ((uint8_t)0xE0)


/**
  * @}
  */

/* Private macros ------------------------------------------------------------*/
/** @defgroup ATMR_DDL_Private_Macros ATMR Private Macros
  * @{
  */
/** @brief  Convert channel id into channel index.
  * @param  __CHANNEL__ This parameter can be one of the following values:
  *         @arg @ref DDL_ATMR_CHANNEL_CH0
  *         @arg @ref DDL_ATMR_CHANNEL_CH0N
  *         @arg @ref DDL_ATMR_CHANNEL_CH1
  *         @arg @ref DDL_ATMR_CHANNEL_CH1N
  *         @arg @ref DDL_ATMR_CHANNEL_CH2
  *         @arg @ref DDL_ATMR_CHANNEL_CH2N
  *         @arg @ref DDL_ATMR_CHANNEL_CH3
  *         @arg @ref DDL_ATMR_CHANNEL_CH4
  * @retval none
  */
#define ATMR_GET_CHANNEL_INDEX( __CHANNEL__) \
  (((__CHANNEL__) == DDL_ATMR_CHANNEL_CH0) ? 0U :\
   ((__CHANNEL__) == DDL_ATMR_CHANNEL_CH0N) ? 1U :\
   ((__CHANNEL__) == DDL_ATMR_CHANNEL_CH1) ? 2U :\
   ((__CHANNEL__) == DDL_ATMR_CHANNEL_CH1N) ? 3U :\
   ((__CHANNEL__) == DDL_ATMR_CHANNEL_CH2) ? 4U :\
   ((__CHANNEL__) == DDL_ATMR_CHANNEL_CH2N) ? 5U :\
   ((__CHANNEL__) == DDL_ATMR_CHANNEL_CH3) ? 6U : 7U)

/** @brief  Calculate the deadtime sampling period(in ps).
  * @param  __ATMRCLK__ timer input clock frequency (in Hz).
  * @param  __CKD__ This parameter can be one of the following values:
  *         @arg @ref DDL_ATMR_CLOCKDIVISION_DIV1
  *         @arg @ref DDL_ATMR_CLOCKDIVISION_DIV2
  *         @arg @ref DDL_ATMR_CLOCKDIVISION_DIV4
  * @retval none
  */
#define ATMR_CALC_DTS(__ATMRCLK__, __CKD__)                                                        \
  (((__CKD__) == DDL_ATMR_CLOCKDIVISION_DIV1) ? ((uint64_t)1000000000000U/(__ATMRCLK__))         : \
   ((__CKD__) == DDL_ATMR_CLOCKDIVISION_DIV2) ? ((uint64_t)1000000000000U/((__ATMRCLK__) >> 1U)) : \
   ((uint64_t)1000000000000U/((__ATMRCLK__) >> 2U)))
/**
  * @}
  */


/* Exported types ------------------------------------------------------------*/
#if defined(USE_FULL_DDL_DRIVER)
/** @defgroup ATMR_DDL_ES_INIT ATMR Exported Init structure
  * @{
  */

/**
  * @brief  ATMR Time Base configuration structure definition.
  */
typedef struct
{
  uint16_t Prescaler;         /*!< Specifies the prescaler value used to divide the ATMR clock.
                                   This parameter can be a number between Min_Data=0x0000 and Max_Data=0xFFFF.

                                   This feature can be modified afterwards using unitary function
                                   @ref DDL_ATMR_SetPrescaler().*/

  uint32_t CounterMode;       /*!< Specifies the counter mode.
                                   This parameter can be a value of @ref ATMR_DDL_EC_COUNTERMODE.

                                   This feature can be modified afterwards using unitary function
                                   @ref DDL_ATMR_SetCounterMode().*/

  uint32_t Autoreload;        /*!< Specifies the auto reload value to be loaded into the active
                                   Auto-Reload Register at the next update event.
                                   This parameter must be a number between Min_Data=0x0000 and Max_Data=0xFFFF.
                                   Some timer instances may support 32 bits counters. In that case this parameter must
                                   be a number between 0x0000 and 0xFFFFFFFF.

                                   This feature can be modified afterwards using unitary function
                                   @ref DDL_ATMR_SetAutoReload().*/

  uint32_t ClockDivision;     /*!< Specifies the clock division.
                                   This parameter can be a value of @ref ATMR_DDL_EC_CLOCKDIVISION.

                                   This feature can be modified afterwards using unitary function
                                   @ref DDL_ATMR_SetClockDivision().*/

  uint32_t RepetitionCounter;  /*!< Specifies the repetition counter value. Each time the REPCNT downcounter
                                   reaches zero, an update event is generated and counting restarts
                                   from the REPCNT value (N).
                                   This means in PWM mode that (N+1) corresponds to:
                                      - the number of PWM periods in edge-aligned mode
                                      - the number of half PWM period in center-aligned mode
                                   GP timers: this parameter must be a number between Min_Data = 0x00 and
                                   Max_Data = 0xFF.
                                   Advanced timers: this parameter must be a number between Min_Data = 0x0000 and
                                   Max_Data = 0xFFFF.

                                   This feature can be modified afterwards using unitary function
                                   @ref DDL_ATMR_SetRepetitionCounter().*/
} DDL_ATMR_InitTypeDef;

/**
  * @brief  ATMR Output Compare configuration structure definition.
  */
typedef struct
{
  uint32_t OCMode;        /*!< Specifies the output mode.
                               This parameter can be a value of @ref ATMR_DDL_EC_OCMODE.

                               This feature can be modified afterwards using unitary function
                               @ref DDL_ATMR_OC_SetMode().*/

  uint32_t OCState;       /*!< Specifies the ATMR Output Compare state.
                               This parameter can be a value of @ref ATMR_DDL_EC_OCSTATE.

                               This feature can be modified afterwards using unitary functions
                               @ref DDL_ATMR_CC_EnableChannel() or @ref DDL_ATMR_CC_DisableChannel().*/

  uint32_t OCNState;      /*!< Specifies the ATMR complementary Output Compare state.
                               This parameter can be a value of @ref ATMR_DDL_EC_OCSTATE.

                               This feature can be modified afterwards using unitary functions
                               @ref DDL_ATMR_CC_EnableChannel() or @ref DDL_ATMR_CC_DisableChannel().*/

  uint32_t CompareValue;  /*!< Specifies the Compare value to be loaded into the Capture Compare Register.
                               This parameter can be a number between Min_Data=0x0000 and Max_Data=0xFFFF.

                               This feature can be modified afterwards using unitary function
                               DDL_ATMR_OC_SetCompareCHx (x=1..6).*/

  uint32_t OCPolarity;    /*!< Specifies the output polarity.
                               This parameter can be a value of @ref ATMR_DDL_EC_OCPOLARITY.

                               This feature can be modified afterwards using unitary function
                               @ref DDL_ATMR_OC_SetPolarity().*/

  uint32_t OCNPolarity;   /*!< Specifies the complementary output polarity.
                               This parameter can be a value of @ref ATMR_DDL_EC_OCPOLARITY.

                               This feature can be modified afterwards using unitary function
                               @ref DDL_ATMR_OC_SetPolarity().*/


  uint32_t OCIdleState;   /*!< Specifies the ATMR Output Compare pin state during Idle state.
                               This parameter can be a value of @ref ATMR_DDL_EC_OCIDLESTATE.

                               This feature can be modified afterwards using unitary function
                               @ref DDL_ATMR_OC_SetIdleState().*/

  uint32_t OCNIdleState;  /*!< Specifies the ATMR Output Compare pin state during Idle state.
                               This parameter can be a value of @ref ATMR_DDL_EC_OCIDLESTATE.

                               This feature can be modified afterwards using unitary function
                               @ref DDL_ATMR_OC_SetIdleState().*/
} DDL_ATMR_OC_InitTypeDef;

/**
  * @brief  BDTR (Break and Dead Time) structure definition
  */
typedef struct
{
  uint32_t OSSRState;            /*!< Specifies the Off-State selection used in Run mode.
                                      This parameter can be a value of @ref ATMR_DDL_EC_OSSR

                                      This feature can be modified afterwards using unitary function
                                      @ref DDL_ATMR_SetOffStates()

                                      @note This bit-field cannot be modified as long as LOCK level 2 has been
                                       programmed. */

  uint32_t OSSIState;            /*!< Specifies the Off-State used in Idle state.
                                      This parameter can be a value of @ref ATMR_DDL_EC_OSSI

                                      This feature can be modified afterwards using unitary function
                                      @ref DDL_ATMR_SetOffStates()

                                      @note This bit-field cannot be modified as long as LOCK level 2 has been
                                      programmed. */

  uint32_t LockLevel;            /*!< Specifies the LOCK level parameters.
                                      This parameter can be a value of @ref ATMR_DDL_EC_LOCKLEVEL

                                      @note The LOCK bits can be written only once after the reset. Once the ATMRx_BDT
                                      register has been written, their content is frozen until the next reset.*/

  uint8_t DeadTime;              /*!< Specifies the delay time between the switching-off and the
                                      switching-on of the outputs.
                                      This parameter can be a number between Min_Data = 0x00 and Max_Data = 0xFF.

                                      This feature can be modified afterwards using unitary function
                                      @ref DDL_ATMR_OC_SetDeadTime()

                                      @note This bit-field can not be modified as long as LOCK level 1, 2 or 3 has been
                                       programmed. */

  uint16_t BreakState;           /*!< Specifies whether the ATMR Break input is enabled or not.
                                      This parameter can be a value of @ref ATMR_DDL_EC_BREAK_ENABLE

                                      This feature can be modified afterwards using unitary functions
                                      @ref DDL_ATMR_EnableBRK() or @ref DDL_ATMR_DisableBRK()

                                      @note This bit-field can not be modified as long as LOCK level 1 has been
                                      programmed. */

  uint32_t BreakPolarity;        /*!< Specifies the ATMR Break Input pin polarity.
                                      This parameter can be a value of @ref ATMR_DDL_EC_BREAK_POLARITY

                                      This feature can be modified afterwards using unitary function
                                      @ref DDL_ATMR_ConfigBRK()

                                      @note This bit-field can not be modified as long as LOCK level 1 has been
                                      programmed. */

  uint32_t AutomaticOutput;      /*!< Specifies whether the ATMR Automatic Output feature is enabled or not.
                                      This parameter can be a value of @ref ATMR_DDL_EC_AUTOMATICOUTPUT_ENABLE

                                      This feature can be modified afterwards using unitary functions
                                      @ref DDL_ATMR_EnableAutomaticOutput() or @ref DDL_ATMR_DisableAutomaticOutput()

                                      @note This bit-field can not be modified as long as LOCK level 1 has been
                                      programmed. */
} DDL_ATMR_BDT_InitTypeDef;

/**
  * @}
  */
#endif /* USE_FULL_DDL_DRIVER */

/* Exported constants --------------------------------------------------------*/
/** @defgroup ATMR_DDL_Exported_Constants ATMR Exported Constants
  * @{
  */

/** @defgroup ATMR_DDL_EC_GET_FLAG Get Flags Defines
  * @brief    Flags defines which can be used with DDL_ATMR_ReadReg function.
  * @{
  */
#define DDL_ATMR_STS_UIFLG                      ATMR_STS_UIFLG        /*!< Update interrupt flag */
#define DDL_ATMR_STS_CC0IFLG                    ATMR_STS_CC0IFLG      /*!< Capture/compare 0 interrupt flag */
#define DDL_ATMR_STS_CC1IFLG                    ATMR_STS_CC1IFLG      /*!< Capture/compare 1 interrupt flag */
#define DDL_ATMR_STS_CC2IFLG                    ATMR_STS_CC2IFLG      /*!< Capture/compare 2 interrupt flag */
#define DDL_ATMR_STS_CC3IFLG                    ATMR_STS_CC3IFLG      /*!< Capture/compare 3 interrupt flag */
#define DDL_ATMR_STS_COMIFLG                    ATMR_STS_COMIFLG      /*!< COM interrupt flag */
#define DDL_ATMR_STS_TRGIFLG                    ATMR_STS_TRGIFLG      /*!< Trigger interrupt flag */
#define DDL_ATMR_STS_BRKIFLG                    ATMR_STS_BRKIFLG      /*!< Break interrupt flag */
/**
  * @}
  */

#if defined(USE_FULL_DDL_DRIVER)
/** @defgroup ATMR_DDL_EC_BREAK_ENABLE Break Enable
  * @{
  */
#define DDL_ATMR_BREAK_DISABLE                  0x00000000U           /*!< Break function disabled */
#define DDL_ATMR_BREAK_ENABLE                   ATMR_BDT_BRKEN        /*!< Break function enabled */
/**
  * @}
  */

/** @defgroup ATMR_DDL_EC_AUTOMATICOUTPUT_ENABLE Automatic output enable
  * @{
  */
#define DDL_ATMR_AUTOMATICOUTPUT_DISABLE        0x00000000U           /*!< MOE can be set only by software */
#define DDL_ATMR_AUTOMATICOUTPUT_ENABLE         ATMR_BDT_AOEN         /*!< MOE can be set by software or automatically at the next update event */
/**
  * @}
  */
#endif /* USE_FULL_DDL_DRIVER */

/** @defgroup ATMR_DDL_EC_IT IT Defines
  * @brief    IT defines which can be used with DDL_ATMR_ReadReg and  DDL_ATMR_WriteReg functions.
  * @{
  */
#define DDL_ATMR_DIEN_UIEN                      ATMR_DIEN_UIEN        /*!< Update interrupt enable */
#define DDL_ATMR_DIEN_CC0IEN                    ATMR_DIEN_CC0IEN      /*!< Capture/compare 0 interrupt enable */
#define DDL_ATMR_DIEN_CC1IEN                    ATMR_DIEN_CC1IEN      /*!< Capture/compare 1 interrupt enable */
#define DDL_ATMR_DIEN_CC2IEN                    ATMR_DIEN_CC2IEN      /*!< Capture/compare 2 interrupt enable */
#define DDL_ATMR_DIEN_CC3IEN                    ATMR_DIEN_CC3IEN      /*!< Capture/compare 3 interrupt enable */
#define DDL_ATMR_DIEN_COMIEN                    ATMR_DIEN_COMIEN      /*!< COM interrupt enable */
#define DDL_ATMR_DIEN_TRGIEN                    ATMR_DIEN_TRGIEN      /*!< Trigger interrupt enable */
#define DDL_ATMR_DIEN_BRKIEN                    ATMR_DIEN_BRKIEN      /*!< Break interrupt enable */
/**
  * @}
  */

/** @defgroup ATMR_DDL_EC_UPDATESOURCE Update Source
  * @{
  */
#define DDL_ATMR_UPDATESOURCE_REGULAR           0x00000000U           /*!< Counter overflow/underflow, Setting the UG bit or Update generation through the slave mode controller generates an update request */
#define DDL_ATMR_UPDATESOURCE_COUNTER           ATMR_CTRL1_URSSEL     /*!< Only counter overflow/underflow generates an update request */
/**
  * @}
  */

/** @defgroup ATMR_DDL_EC_ONEPULSEMODE One Pulse Mode
  * @{
  */
#define DDL_ATMR_ONEPULSEMODE_SINGLE            ATMR_CTRL1_SPMEN      /*!< Counter stops counting at the next update event */
#define DDL_ATMR_ONEPULSEMODE_REPETITIVE        0x00000000U           /*!< Counter is not stopped at update event */
/**
  * @}
  */

/** @defgroup ATMR_DDL_EC_COUNTERMODE Counter Mode
  * @{
  */
#define DDL_ATMR_COUNTERMODE_UP                 0x00000000U           /*!< Counter used as upcounter */
#define DDL_ATMR_COUNTERMODE_DOWN               ATMR_CTRL1_CNTDIR     /*!< Counter used as downcounter */
#define DDL_ATMR_COUNTERMODE_CENTER_DOWN        ATMR_CTRL1_CAMSEL_0   /*!< The counter counts up and down alternatively. Output compare interrupt flags of output channels  are set only when the counter is counting down. */
#define DDL_ATMR_COUNTERMODE_CENTER_UP          ATMR_CTRL1_CAMSEL_1   /*!< The counter counts up and down alternatively. Output compare interrupt flags of output channels  are set only when the counter is counting up */
#define DDL_ATMR_COUNTERMODE_CENTER_UP_DOWN     ATMR_CTRL1_CAMSEL     /*!< The counter counts up and down alternatively. Output compare interrupt flags of output channels  are set only when the counter is counting up or down. */
/**
  * @}
  */

/** @defgroup ATMR_DDL_EC_CLOCKDIVISION Clock Division
  * @{
  */
#define DDL_ATMR_CLOCKDIVISION_DIV1             0x00000000U           /*!< tDTS=tCK_INT */
#define DDL_ATMR_CLOCKDIVISION_DIV2             ATMR_CTRL1_CLKDIV_0   /*!< tDTS=2*tCK_INT */
#define DDL_ATMR_CLOCKDIVISION_DIV4             ATMR_CTRL1_CLKDIV_1   /*!< tDTS=4*tCK_INT */
/**
  * @}
  */

/** @defgroup ATMR_DDL_EC_COUNTERDIRECTION Counter Direction
  * @{
  */
#define DDL_ATMR_COUNTERDIRECTION_UP            0x00000000U           /*!< Timer counter counts up */
#define DDL_ATMR_COUNTERDIRECTION_DOWN          ATMR_CTRL1_CNTDIR     /*!< Timer counter counts down */
/**
  * @}
  */

/** @defgroup ATMR_DDL_EC_CCUPDATESOURCE Capture Compare  Update Source
  * @{
  */
#define DDL_ATMR_CCUPDATESOURCE_COMG_ONLY       0x00000000U           /*!< Capture/compare control bits are updated by setting the COMG bit only */
#define DDL_ATMR_CCUPDATESOURCE_COMG_AND_TRGI   ATMR_CTRL2_CCUSEL     /*!< Capture/compare control bits are updated by setting the COMG bit or when a rising edge occurs on trigger input (TRGI) */
/**
  * @}
  */

/** @defgroup ATMR_DDL_EC_LOCKLEVEL Lock Level
  * @{
  */
#define DDL_ATMR_LOCKLEVEL_OFF                  0x00000000U           /*!< LOCK OFF - No bit is write protected */
#define DDL_ATMR_LOCKLEVEL_1                    ATMR_BDT_LOCKCFG_0    /*!< LOCK Level 1 */
#define DDL_ATMR_LOCKLEVEL_2                    ATMR_BDT_LOCKCFG_1    /*!< LOCK Level 2 */
#define DDL_ATMR_LOCKLEVEL_3                    ATMR_BDT_LOCKCFG      /*!< LOCK Level 3 */
/**
  * @}
  */

/** @defgroup ATMR_DDL_EC_CHANNEL Channel
  * @{
  */
#define DDL_ATMR_CHANNEL_CH0                    ATMR_CCEN_CC0EN                   /*!< Timer input/output channel 0 */
#define DDL_ATMR_CHANNEL_CH0N                   ATMR_CCEN_CC0NEN                  /*!< Timer complementary output channel 0 */
#define DDL_ATMR_CHANNEL_CH1                    ATMR_CCEN_CC1EN                   /*!< Timer input/output channel 1 */
#define DDL_ATMR_CHANNEL_CH1N                   ATMR_CCEN_CC1NEN                  /*!< Timer complementary output channel 1 */
#define DDL_ATMR_CHANNEL_CH2                    ATMR_CCEN_CC2EN                   /*!< Timer input/output channel 2 */
#define DDL_ATMR_CHANNEL_CH2N                   ATMR_CCEN_CC2NEN                  /*!< Timer complementary output channel 2 */
#define DDL_ATMR_CHANNEL_CH3                    ATMR_CCEN_CC3EN                   /*!< Timer input/output channel 3 */
#define DDL_ATMR_CHANNEL_CH4                    (ATMR_CH4CFG_CC4E << 16U)         /*!< Timer input/output channel 4 (CC4E in CH4CFG; shifted to avoid clash with CC2EN) */
/**
  * @}
  */

#if defined(USE_FULL_DDL_DRIVER)
/** @defgroup ATMR_DDL_EC_OCSTATE Output Configuration State
  * @{
  */
#define DDL_ATMR_OCSTATE_DISABLE                0x00000000U           /*!< OCx is not active */
#define DDL_ATMR_OCSTATE_ENABLE                 ATMR_CCEN_CC0EN       /*!< OCx signal is output on the corresponding output pin */
/**
  * @}
  */
#endif /* USE_FULL_DDL_DRIVER */

/** @defgroup ATMR_DDL_EC_OCMODE Output Configuration Mode
  * @{
  */
#define DDL_ATMR_OCMODE_FROZEN                   0x00000000U                                              /*!<The comparison between the output compare register TMRx_CCRy and the counter TMRx_CNT has no effect on the output channel level */
#define DDL_ATMR_OCMODE_ACTIVE                   ATMR_CCM1_OC0MOD_0                                         /*!<OCyREF is forced high on compare match*/
#define DDL_ATMR_OCMODE_INACTIVE                 ATMR_CCM1_OC0MOD_1                                         /*!<OCyREF is forced low on compare match*/
#define DDL_ATMR_OCMODE_TOGGLE                   (ATMR_CCM1_OC0MOD_1 | ATMR_CCM1_OC0MOD_0)                    /*!<OCyREF toggles on compare match*/
#define DDL_ATMR_OCMODE_FORCED_INACTIVE          ATMR_CCM1_OC0MOD_2                                         /*!<OCyREF is forced low*/
#define DDL_ATMR_OCMODE_FORCED_ACTIVE            (ATMR_CCM1_OC0MOD_2 | ATMR_CCM1_OC0MOD_0)                    /*!<OCyREF is forced high*/
#define DDL_ATMR_OCMODE_PWM1                     (ATMR_CCM1_OC0MOD_2 | ATMR_CCM1_OC0MOD_1)                    /*!<In upcounting, channel y is active as long as TMRx_CNT<TMRx_CCRy else inactive.  In downcounting, channel y is inactive as long as TMRx_CNT>TMRx_CCRy else active.*/
#define DDL_ATMR_OCMODE_PWM2                     (ATMR_CCM1_OC0MOD_2 | ATMR_CCM1_OC0MOD_1 | ATMR_CCM1_OC0MOD_0) /*!<In upcounting, channel y is inactive as long as TMRx_CNT<TMRx_CCRy else active.  In downcounting, channel y is active as long as TMRx_CNT>TMRx_CCRy else inactive*/
/**
  * @}
  */


/** @defgroup ATMR_DDL_EC_OCPOLARITY Output Configuration Polarity
  * @{
  */
#define DDL_ATMR_OCPOLARITY_HIGH                0x00000000U           /*!< OCxactive high */
#define DDL_ATMR_OCPOLARITY_LOW                 ATMR_CCEN_CC0POL      /*!< OCxactive low */
/**
  * @}
  */

/** @defgroup ATMR_DDL_EC_OCIDLESTATE Output Configuration Idle State
  * @{
  */
#define DDL_ATMR_OCIDLESTATE_LOW                0x00000000U           /*!<OCx=0 (after a dead-time if OC is implemented) when MOE=0 */
#define DDL_ATMR_OCIDLESTATE_HIGH               ATMR_CTRL2_OC0OIS     /*!<OCx=1 (after a dead-time if OC is implemented) when MOE=0 */
/**
  * @}
  */

/** @defgroup ATMR_DDL_EC_TRGO Trigger Output
  * @{
  */
#define DDL_ATMR_TRGO_RESET                     (0x00000000U)  /*!< UG bit from the TMRx_EGR register is used as trigger output */
#define DDL_ATMR_TRGO_ENABLE                    (0x00000001U)  /*!< Counter Enable signal (CNT_EN) is used as trigger output */
#define DDL_ATMR_TRGO_UPDATE                    (0x00000002U)  /*!< Update event is used as trigger output */
#define DDL_ATMR_TRGO_CCIF_EVENT                (0x00000003U)  /*!< CCx capture or a compare match is used as trigger output */
#define DDL_ATMR_TRGO_OC0REF                    (0x00000004U)  /*!< OC0REF signal is used as trigger output */
#define DDL_ATMR_TRGO_OC1REF                    (0x00000005U)  /*!< OC1REF signal is used as trigger output */
#define DDL_ATMR_TRGO_OC2REF                    (0x00000006U)  /*!< OC2REF signal is used as trigger output */
#define DDL_ATMR_TRGO_OC3REF                    (0x00000007U)  /*!< OC3REF signal is used as trigger output */
#define DDL_ATMR_TRGO_OC4REF                    (0x00000008U)  /*!< OC4REF signal is used as trigger output */
#define DDL_ATMR_TRGO_SZE_SPE                   (0x00000008U)  /*!< MMSZE and MMSPE signal are used as trigger output */
#define DDL_ATMR_TRGO_OC3UP_OC3DOWN             (0x0000000AU)  /*!< OC3REF up edge signal and OC3REF down edge signal are used as trigger output */
#define DDL_ATMR_TRGO_OC4UP_OC4DOWN             (0x0000000BU)  /*!< OC4REF up edge signal and OC4REF down edge signal are used as trigger output */
#define DDL_ATMR_TRGO_OC3UP_OC4UP               (0x0000000CU)  /*!< OC3REF up edge signal and OC4REF up edge signal are used as trigger output */
#define DDL_ATMR_TRGO_OC3DOWN_OC4DOWN           (0x0000000DU)  /*!< OC3REF down edge signal and OC4REF down edge signal are used as trigger output */
#define DDL_ATMR_TRGO_OC3UP_OC4DOWN             (0x0000000EU)  /*!< OC3REF up edge signal and OC4REF down edge signal are used as trigger output */
#define DDL_ATMR_TRGO_OC3DOWN_OC4UP             (0x0000000FU)  /*!< OC3REF down edge signal and OC4REF up edge signal are used as trigger output */
/**
  * @}
  */


/** @defgroup ATMR_DDL_EC_SLAVEMODE Slave Mode
  * @{
  */
#define DDL_ATMR_SLAVEMODE_DISABLED             0x00000000U                                     /*!< Slave mode disabled */
#define DDL_ATMR_SLAVEMODE_RESET                ATMR_SMCTRL_SMFSEL_2                            /*!< Reset Mode - Rising edge of the selected trigger input (TRGI) reinitializes the counter */
#define DDL_ATMR_SLAVEMODE_GATED               (ATMR_SMCTRL_SMFSEL_2 | ATMR_SMCTRL_SMFSEL_0)    /*!< Gated Mode - The counter clock is enabled when the trigger input (TRGI) is high */
#define DDL_ATMR_SLAVEMODE_TRIGGER             (ATMR_SMCTRL_SMFSEL_2 | ATMR_SMCTRL_SMFSEL_1)    /*!< Trigger Mode - The counter starts at a rising edge of the trigger TRGI */
/**
  * @}
  */

/** @defgroup ATMR_DDL_EC_TS Trigger Selection
  * @{
  */
#define DDL_ATMR_TS_ITR0                        0x00000000U                                     /*!< Internal Trigger 0 (ITR0) is used as trigger input */
#define DDL_ATMR_TS_ETRF                       (ATMR_SMCTRL_TRGSEL)                             /*!< Filtered external Trigger (ETRF) is used as trigger input */
/**
  * @}
  */

/** @defgroup ATMR_DDL_EC_ETR_POLARITY External Trigger Polarity
  * @{
  */
#define DDL_ATMR_ETR_POLARITY_NONINVERTED       0x00000000U           /*!< ETR is non-inverted, active at high level or rising edge */
#define DDL_ATMR_ETR_POLARITY_INVERTED          ATMR_SMCTRL_ETPOL     /*!< ETR is inverted, active at low level or falling edge */
/**
  * @}
  */

/** @defgroup ATMR_DDL_EC_ETR_PRESCALER External Trigger Prescaler
  * @{
  */
#define DDL_ATMR_ETR_PRESCALER_DIV1             0x00000000U           /*!< ETR prescaler OFF */
#define DDL_ATMR_ETR_PRESCALER_DIV2             ATMR_SMCTRL_ETPCFG_0  /*!< ETR frequency is divided by 2 */
#define DDL_ATMR_ETR_PRESCALER_DIV4             ATMR_SMCTRL_ETPCFG_1  /*!< ETR frequency is divided by 4 */
#define DDL_ATMR_ETR_PRESCALER_DIV8             ATMR_SMCTRL_ETPCFG    /*!< ETR frequency is divided by 8 */
/**
  * @}
  */

/** @defgroup ATMR_DDL_EC_ETR_FILTER External Trigger Filter
  * @{
  */
#define DDL_ATMR_ETR_FILTER_FDIV1               0x00000000U                                                         /*!< No filter, sampling is done at fDTS */
#define DDL_ATMR_ETR_FILTER_FDIV1_N2            ATMR_SMCTRL_ETFCFG_0                                                /*!< fSAMPLING=fCK_INT, N=2 */
#define DDL_ATMR_ETR_FILTER_FDIV1_N4            ATMR_SMCTRL_ETFCFG_1                                                /*!< fSAMPLING=fCK_INT, N=4 */
#define DDL_ATMR_ETR_FILTER_FDIV1_N8           (ATMR_SMCTRL_ETFCFG_1 | ATMR_SMCTRL_ETFCFG_0)                        /*!< fSAMPLING=fCK_INT, N=8 */
#define DDL_ATMR_ETR_FILTER_FDIV2_N6            ATMR_SMCTRL_ETFCFG_2                                                /*!< fSAMPLING=fDTS/2, N=6 */
#define DDL_ATMR_ETR_FILTER_FDIV2_N8           (ATMR_SMCTRL_ETFCFG_2 | ATMR_SMCTRL_ETFCFG_0)                        /*!< fSAMPLING=fDTS/2, N=8 */
#define DDL_ATMR_ETR_FILTER_FDIV4_N6           (ATMR_SMCTRL_ETFCFG_2 | ATMR_SMCTRL_ETFCFG_1)                        /*!< fSAMPLING=fDTS/4, N=6 */
#define DDL_ATMR_ETR_FILTER_FDIV4_N8           (ATMR_SMCTRL_ETFCFG_2 | ATMR_SMCTRL_ETFCFG_1 | ATMR_SMCTRL_ETFCFG_0) /*!< fSAMPLING=fDTS/4, N=8 */
#define DDL_ATMR_ETR_FILTER_FDIV8_N6            ATMR_SMCTRL_ETFCFG_3                                                /*!< fSAMPLING=fDTS/8, N=8 */
#define DDL_ATMR_ETR_FILTER_FDIV8_N8           (ATMR_SMCTRL_ETFCFG_3 | ATMR_SMCTRL_ETFCFG_0)                        /*!< fSAMPLING=fDTS/16, N=5 */
#define DDL_ATMR_ETR_FILTER_FDIV16_N5          (ATMR_SMCTRL_ETFCFG_3 | ATMR_SMCTRL_ETFCFG_1)                        /*!< fSAMPLING=fDTS/16, N=6 */
#define DDL_ATMR_ETR_FILTER_FDIV16_N6          (ATMR_SMCTRL_ETFCFG_3 | ATMR_SMCTRL_ETFCFG_1 | ATMR_SMCTRL_ETFCFG_0) /*!< fSAMPLING=fDTS/16, N=8 */
#define DDL_ATMR_ETR_FILTER_FDIV16_N8          (ATMR_SMCTRL_ETFCFG_3 | ATMR_SMCTRL_ETFCFG_2)                        /*!< fSAMPLING=fDTS/16, N=5 */
#define DDL_ATMR_ETR_FILTER_FDIV32_N5          (ATMR_SMCTRL_ETFCFG_3 | ATMR_SMCTRL_ETFCFG_2 | ATMR_SMCTRL_ETFCFG_0) /*!< fSAMPLING=fDTS/32, N=5 */
#define DDL_ATMR_ETR_FILTER_FDIV32_N6          (ATMR_SMCTRL_ETFCFG_3 | ATMR_SMCTRL_ETFCFG_2 | ATMR_SMCTRL_ETFCFG_1) /*!< fSAMPLING=fDTS/32, N=6 */
#define DDL_ATMR_ETR_FILTER_FDIV32_N8           ATMR_SMCTRL_ETFCFG                                                  /*!< fSAMPLING=fDTS/32, N=8 */
/**
  * @}
  */


/** @defgroup ATMR_DDL_EC_BREAK_POLARITY break polarity
  * @{
  */
#define DDL_ATMR_BREAK_POLARITY_LOW             0x00000000U           /*!< Break input BRK is active low */
#define DDL_ATMR_BREAK_POLARITY_HIGH            ATMR_BDT_BRKPOL       /*!< Break input BRK is active high */
/**
  * @}
  */

/** @defgroup ATMR_DDL_EC_OSSI OSSI
  * @{
  */
#define DDL_ATMR_OSSI_DISABLE                   0x00000000U           /*!< When inactive, OCx/OCxN outputs are disabled */
#define DDL_ATMR_OSSI_ENABLE                    ATMR_BDT_IMOS         /*!< When inactive, OxC/OCxN outputs are first forced with their inactive level then forced to their idle level after the deadtime */
/**
  * @}
  */

/** @defgroup ATMR_DDL_EC_OSSR OSSR
  * @{
  */
#define DDL_ATMR_OSSR_DISABLE                   0x00000000U           /*!< When inactive, OCx/OCxN outputs are disabled */
#define DDL_ATMR_OSSR_ENABLE                    ATMR_BDT_RMOS         /*!< When inactive, OC/OCN outputs are enabled with their inactive level as soon as CCxE=1 or CCxNE=1 */
/**
  * @}
  */

/** @defgroup ATMR_DDL_EC_FORCE_OUTPUT_CHANNEL Force Output channel
  * @{
  */
#define DDL_ATMR_FORCE_OUTPUT_CH0               ATMR_OUTPUTCTRL1_CH0_FORCE_EN_Pos   /*!< Force Output for channel 0 */
#define DDL_ATMR_FORCE_OUTPUT_CH0N              ATMR_OUTPUTCTRL1_CH0N_FORCE_EN_Pos  /*!< Force Output for complementary channel 0 */
#define DDL_ATMR_FORCE_OUTPUT_CH1               ATMR_OUTPUTCTRL1_CH1_FORCE_EN_Pos   /*!< Force Output for channel 1 */
#define DDL_ATMR_FORCE_OUTPUT_CH1N              ATMR_OUTPUTCTRL1_CH1N_FORCE_EN_Pos  /*!< Force Output for complementary channel 1 */
#define DDL_ATMR_FORCE_OUTPUT_CH2               ATMR_OUTPUTCTRL1_CH2_FORCE_EN_Pos   /*!< Force Output for channel 2 */
#define DDL_ATMR_FORCE_OUTPUT_CH2N              ATMR_OUTPUTCTRL1_CH2N_FORCE_EN_Pos  /*!< Force Output for complementary channel 2 */
#define DDL_ATMR_FORCE_OUTPUT_CH3               ATMR_OUTPUTCTRL1_CH3_FORCE_EN_Pos   /*!< Force Output for channel 3 */
#define DDL_ATMR_FORCE_OUTPUT_CH4               ATMR_OUTPUTCTRL1_CH4_FORCE_EN_Pos   /*!< Force Output for channel 4 */
/**
  * @}
  */

/** @defgroup ATMR_DDL_EC_FORCE_OUTPUT_VALUE Force Output Value
  * @{
  */
#define DDL_ATMR_FORCE_OUTPUT_LOW           0x00000000U                         /*!< Force Output LOW */
#define DDL_ATMR_FORCE_OUTPUT_HIGH          ATMR_OUTPUTCTRL2_CH0_FORCE_VALUE    /*!< Force Output HIGH */

/**
  * @}
  */


/** @defgroup ATMR_DDL_EC_PWM_ASYMMETRIC_OUTPUT_MODE PWM asymmtric output mode
  * @{
  */
#define DDL_ATMR_PWMASYMMETRIC_OC0              ATMR_OCXAEN_OC0AEN
#define DDL_ATMR_PWMASYMMETRIC_OC1              ATMR_OCXAEN_OC1AEN
#define DDL_ATMR_PWMASYMMETRIC_OC2              ATMR_OCXAEN_OC2AEN
/**
  * @}
  */


/**
  * @}
  */

/* Exported macro ------------------------------------------------------------*/
/** @defgroup ATMR_DDL_Exported_Macros ATMR Exported Macros
  * @{
  */

/** @defgroup ATMR_DDL_EM_WRITE_READ Common Write and read registers Macros
  * @{
  */
/**
  * @brief  Write a value in ATMR register.
  * @param  __INSTANCE__ ATMR Instance
  * @param  __REG__ Register to be written
  * @param  __VALUE__ Value to be written in the register
  * @retval None
  */
#define DDL_ATMR_WriteReg(__INSTANCE__, __REG__, __VALUE__) WRITE_REG((__INSTANCE__)->__REG__, (__VALUE__))

/**
  * @brief  Read a value in ATMR register.
  * @param  __INSTANCE__ ATMR Instance
  * @param  __REG__ Register to be read
  * @retval Register value
  */
#define DDL_ATMR_ReadReg(__INSTANCE__, __REG__) READ_REG((__INSTANCE__)->__REG__)
/**
  * @}
  */

/** @defgroup ATMR_DDL_EM_Exported_Macros Exported_Macros
  * @{
  */

/**
  * @brief  HELPER macro calculating DTG[0:7] in the ATMRx_BDT register to achieve the requested dead time duration.
  * @note ex: @ref __DDL_ATMR_CALC_DEADATMRE (80000000, @ref DDL_ATMR_GetClockDivision (), 120);
  * @param  __ATMRCLK__ timer input clock frequency (in Hz)
  * @param  __CKD__ This parameter can be one of the following values:
  *         @arg @ref DDL_ATMR_CLOCKDIVISION_DIV1
  *         @arg @ref DDL_ATMR_CLOCKDIVISION_DIV2
  *         @arg @ref DDL_ATMR_CLOCKDIVISION_DIV4
  * @param  __DT__ deadtime duration (in ns)
  * @retval DTG[0:7]
  */
#define __DDL_ATMR_CALC_DEADATMRE(__ATMRCLK__, __CKD__, __DT__)  \
  ( (((uint64_t)((__DT__)*1000U)) < ((DT_DELAY_1+1U) * ATMR_CALC_DTS((__ATMRCLK__), (__CKD__))))    ?  \
    (uint8_t)(((uint64_t)((__DT__)*1000U) / ATMR_CALC_DTS((__ATMRCLK__), (__CKD__)))  & DT_DELAY_1) :      \
    (((uint64_t)((__DT__)*1000U)) < ((64U + (DT_DELAY_2+1U)) * 2U * ATMR_CALC_DTS((__ATMRCLK__), (__CKD__))))  ?  \
    (uint8_t)(DT_RANGE_2 | ((uint8_t)((uint8_t)((((uint64_t)((__DT__)*1000U))/ ATMR_CALC_DTS((__ATMRCLK__),   \
                                                 (__CKD__))) >> 1U) - (uint8_t) 64) & DT_DELAY_2)) :\
    (((uint64_t)((__DT__)*1000U)) < ((32U + (DT_DELAY_3+1U)) * 8U * ATMR_CALC_DTS((__ATMRCLK__), (__CKD__))))  ?  \
    (uint8_t)(DT_RANGE_3 | ((uint8_t)((uint8_t)(((((uint64_t)(__DT__)*1000U))/ ATMR_CALC_DTS((__ATMRCLK__),  \
                                                 (__CKD__))) >> 3U) - (uint8_t) 32) & DT_DELAY_3)) :\
    (((uint64_t)((__DT__)*1000U)) < ((32U + (DT_DELAY_4+1U)) * 16U * ATMR_CALC_DTS((__ATMRCLK__), (__CKD__)))) ?  \
    (uint8_t)(DT_RANGE_4 | ((uint8_t)((uint8_t)(((((uint64_t)(__DT__)*1000U))/ ATMR_CALC_DTS((__ATMRCLK__),  \
                                                 (__CKD__))) >> 4U) - (uint8_t) 32) & DT_DELAY_4)) :\
    0U)

/**
  * @brief  HELPER macro calculating the prescaler value to achieve the required counter clock frequency.
  * @note ex: @ref __DDL_ATMR_CALC_PSC (80000000, 1000000);
  * @param  __ATMRCLK__ timer input clock frequency (in Hz)
  * @param  __CNTCLK__ counter clock frequency (in Hz)
  * @retval Prescaler value  (between Min_Data=0 and Max_Data=65535)
  */
#define __DDL_ATMR_CALC_PSC(__ATMRCLK__, __CNTCLK__)   \
  (((__ATMRCLK__) >= (__CNTCLK__)) ? (uint32_t)((((__ATMRCLK__) + (__CNTCLK__)/2U)/(__CNTCLK__)) - 1U) : 0U)

/**
  * @brief  HELPER macro calculating the auto-reload value to achieve the required output signal frequency.
  * @note ex: @ref __DDL_ATMR_CALC_ARR (1000000, @ref DDL_ATMR_GetPrescaler (), 10000);
  * @param  __ATMRCLK__ timer input clock frequency (in Hz)
  * @param  __PSC__ prescaler
  * @param  __FREQ__ output signal frequency (in Hz)
  * @retval  Auto-reload value  (between Min_Data=0 and Max_Data=65535)
  */
#define __DDL_ATMR_CALC_ARR(__ATMRCLK__, __PSC__, __FREQ__) \
  ((((__ATMRCLK__)/((__PSC__) + 1U)) >= (__FREQ__)) ? (((__ATMRCLK__)/((__FREQ__) * ((__PSC__) + 1U))) - 1U) : 0U)

/**
  * @brief  HELPER macro calculating the compare value required to achieve the required timer output compare
  *         active/inactive delay.
  * @note ex: @ref __DDL_ATMR_CALC_DELAY (1000000, @ref DDL_ATMR_GetPrescaler (), 10);
  * @param  __ATMRCLK__ timer input clock frequency (in Hz)
  * @param  __PSC__ prescaler
  * @param  __DELAY__ timer output compare active/inactive delay (in us)
  * @retval Compare value  (between Min_Data=0 and Max_Data=65535)
  */
#define __DDL_ATMR_CALC_DELAY(__ATMRCLK__, __PSC__, __DELAY__)  \
  ((uint32_t)(((uint64_t)(__ATMRCLK__) * (uint64_t)(__DELAY__)) \
              / ((uint64_t)1000000U * (uint64_t)((__PSC__) + 1U))))

/**
  * @brief  HELPER macro calculating the auto-reload value to achieve the required pulse duration
  *         (when the timer operates in one pulse mode).
  * @note ex: @ref __DDL_ATMR_CALC_PULSE (1000000, @ref DDL_ATMR_GetPrescaler (), 10, 20);
  * @param  __ATMRCLK__ timer input clock frequency (in Hz)
  * @param  __PSC__ prescaler
  * @param  __DELAY__ timer output compare active/inactive delay (in us)
  * @param  __PULSE__ pulse duration (in us)
  * @retval Auto-reload value  (between Min_Data=0 and Max_Data=65535)
  */
#define __DDL_ATMR_CALC_PULSE(__ATMRCLK__, __PSC__, __DELAY__, __PULSE__)  \
  ((uint32_t)(__DDL_ATMR_CALC_DELAY((__ATMRCLK__), (__PSC__), (__PULSE__)) \
              + __DDL_ATMR_CALC_DELAY((__ATMRCLK__), (__PSC__), (__DELAY__))))

/**
  * @}
  */


/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/** @defgroup ATMR_DDL_Exported_Functions ATMR Exported Functions
  * @{
  */

/** @defgroup ATMR_DDL_EF_Time_Base Time Base configuration
  * @{
  */
/**
  * @brief  Enable timer counter.
  * @param  ATMRx Timer instance
  * @retval None
  */
__STATIC_INLINE void DDL_ATMR_EnableCounter(ATMR_TypeDef *ATMRx)
{
  SET_BIT(ATMRx->CTRL1, ATMR_CTRL1_CNTEN);
}

/**
  * @brief  Disable timer counter.
  * @param  ATMRx Timer instance
  * @retval None
  */
__STATIC_INLINE void DDL_ATMR_DisableCounter(ATMR_TypeDef *ATMRx)
{
  CLEAR_BIT(ATMRx->CTRL1, ATMR_CTRL1_CNTEN);
}

/**
  * @brief  Indicates whether the timer counter is enabled.
  * @param  ATMRx Timer instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_ATMR_IsEnabledCounter(ATMR_TypeDef *ATMRx)
{
  return ((READ_BIT(ATMRx->CTRL1, ATMR_CTRL1_CNTEN) == (ATMR_CTRL1_CNTEN)) ? 1UL : 0UL);
}

/**
  * @brief  Enable update event generation.
  * @param  ATMRx Timer instance
  * @retval None
  */
__STATIC_INLINE void DDL_ATMR_EnableUpdateEvent(ATMR_TypeDef *ATMRx)
{
  CLEAR_BIT(ATMRx->CTRL1, ATMR_CTRL1_UD);
}

/**
  * @brief  Disable update event generation.
  * @param  ATMRx Timer instance
  * @retval None
  */
__STATIC_INLINE void DDL_ATMR_DisableUpdateEvent(ATMR_TypeDef *ATMRx)
{
  SET_BIT(ATMRx->CTRL1, ATMR_CTRL1_UD);
}

/**
  * @brief  Indicates whether update event generation is enabled.
  * @param  ATMRx Timer instance
  * @retval Inverted state of bit (0 or 1).
  */
__STATIC_INLINE uint32_t DDL_ATMR_IsEnabledUpdateEvent(ATMR_TypeDef *ATMRx)
{
  return ((READ_BIT(ATMRx->CTRL1, ATMR_CTRL1_UD) == (uint32_t)RESET) ? 1UL : 0UL);
}

/**
  * @brief  Set update event source
  * @note Update event source set to DDL_ATMR_UPDATESOURCE_REGULAR: any of the following events
  *       generate an update interrupt or DMA request if enabled:
  *        - Counter overflow/underflow
  *        - Setting the UG bit
  *        - Update generation through the slave mode controller
  * @note Update event source set to DDL_ATMR_UPDATESOURCE_COUNTER: only counter
  *       overflow/underflow generates an update interrupt or DMA request if enabled.
  * @param  ATMRx Timer instance
  * @param  UpdateSource This parameter can be one of the following values:
  *         @arg @ref DDL_ATMR_UPDATESOURCE_REGULAR
  *         @arg @ref DDL_ATMR_UPDATESOURCE_COUNTER
  * @retval None
  */
__STATIC_INLINE void DDL_ATMR_SetUpdateSource(ATMR_TypeDef *ATMRx, uint32_t UpdateSource)
{
  MODIFY_REG(ATMRx->CTRL1, ATMR_CTRL1_URSSEL, UpdateSource);
}

/**
  * @brief  Get actual event update source
  * @param  ATMRx Timer instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref DDL_ATMR_UPDATESOURCE_REGULAR
  *         @arg @ref DDL_ATMR_UPDATESOURCE_COUNTER
  */
__STATIC_INLINE uint32_t DDL_ATMR_GetUpdateSource(ATMR_TypeDef *ATMRx)
{
  return (uint32_t)(READ_BIT(ATMRx->CTRL1, ATMR_CTRL1_URSSEL));
}

/**
  * @brief  Set one pulse mode (one shot v.s. repetitive).
  * @param  ATMRx Timer instance
  * @param  OnePulseMode This parameter can be one of the following values:
  *         @arg @ref DDL_ATMR_ONEPULSEMODE_SINGLE
  *         @arg @ref DDL_ATMR_ONEPULSEMODE_REPETITIVE
  * @retval None
  */
__STATIC_INLINE void DDL_ATMR_SetOnePulseMode(ATMR_TypeDef *ATMRx, uint32_t OnePulseMode)
{
  MODIFY_REG(ATMRx->CTRL1, ATMR_CTRL1_SPMEN, OnePulseMode);
}

/**
  * @brief  Get actual one pulse mode.
  * @param  ATMRx Timer instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref DDL_ATMR_ONEPULSEMODE_SINGLE
  *         @arg @ref DDL_ATMR_ONEPULSEMODE_REPETITIVE
  */
__STATIC_INLINE uint32_t DDL_ATMR_GetOnePulseMode(ATMR_TypeDef *ATMRx)
{
  return (uint32_t)(READ_BIT(ATMRx->CTRL1, ATMR_CTRL1_SPMEN));
}

/**
  * @brief  Set the timer counter counting mode.
  * @note Switching from Center Aligned counter mode to Edge counter mode (or reverse)
  *       requires a timer reset to avoid unexpected direction
  *       due to CNTDIR bit readonly in center aligned mode.
  * @param  ATMRx Timer instance
  * @param  CounterMode This parameter can be one of the following values:
  *         @arg @ref DDL_ATMR_COUNTERMODE_UP
  *         @arg @ref DDL_ATMR_COUNTERMODE_DOWN
  *         @arg @ref DDL_ATMR_COUNTERMODE_CENTER_UP
  *         @arg @ref DDL_ATMR_COUNTERMODE_CENTER_DOWN
  *         @arg @ref DDL_ATMR_COUNTERMODE_CENTER_UP_DOWN
  * @retval None
  */
__STATIC_INLINE void DDL_ATMR_SetCounterMode(ATMR_TypeDef *ATMRx, uint32_t CounterMode)
{
  MODIFY_REG(ATMRx->CTRL1, (ATMR_CTRL1_CNTDIR | ATMR_CTRL1_CAMSEL), CounterMode);
}

/**
  * @brief  Get actual counter mode.
  * @param  ATMRx Timer instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref DDL_ATMR_COUNTERMODE_UP
  *         @arg @ref DDL_ATMR_COUNTERMODE_DOWN
  *         @arg @ref DDL_ATMR_COUNTERMODE_CENTER_UP
  *         @arg @ref DDL_ATMR_COUNTERMODE_CENTER_DOWN
  *         @arg @ref DDL_ATMR_COUNTERMODE_CENTER_UP_DOWN
  */
__STATIC_INLINE uint32_t DDL_ATMR_GetCounterMode(ATMR_TypeDef *ATMRx)
{
  uint32_t counter_mode;

  counter_mode = (uint32_t)(READ_BIT(ATMRx->CTRL1, ATMR_CTRL1_CAMSEL));

  if (counter_mode == 0U)
  {
    counter_mode = (uint32_t)(READ_BIT(ATMRx->CTRL1, ATMR_CTRL1_CNTDIR));
  }

  return counter_mode;
}

/**
  * @brief  Enable auto-reload (ARR) preload.
  * @param  ATMRx Timer instance
  * @retval None
  */
__STATIC_INLINE void DDL_ATMR_EnableARRPreload(ATMR_TypeDef *ATMRx)
{
  SET_BIT(ATMRx->CTRL1, ATMR_CTRL1_ARPEN);
}

/**
  * @brief  Disable auto-reload (ARR) preload.
  * @param  ATMRx Timer instance
  * @retval None
  */
__STATIC_INLINE void DDL_ATMR_DisableARRPreload(ATMR_TypeDef *ATMRx)
{
  CLEAR_BIT(ATMRx->CTRL1, ATMR_CTRL1_ARPEN);
}

/**
  * @brief  Indicates whether auto-reload (ARR) preload is enabled.
  * @param  ATMRx Timer instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_ATMR_IsEnabledARRPreload(ATMR_TypeDef *ATMRx)
{
  return ((READ_BIT(ATMRx->CTRL1, ATMR_CTRL1_ARPEN) == (ATMR_CTRL1_ARPEN)) ? 1UL : 0UL);
}

/**
  * @brief  Set the division ratio between the timer clock and the sampling clock used by the dead-time generators
  *         (when supported) and the digital filters.
  * @param  ATMRx Timer instance
  * @param  ClockDivision This parameter can be one of the following values:
  *         @arg @ref DDL_ATMR_CLOCKDIVISION_DIV1
  *         @arg @ref DDL_ATMR_CLOCKDIVISION_DIV2
  *         @arg @ref DDL_ATMR_CLOCKDIVISION_DIV4
  * @retval None
  */
__STATIC_INLINE void DDL_ATMR_SetClockDivision(ATMR_TypeDef *ATMRx, uint32_t ClockDivision)
{
  MODIFY_REG(ATMRx->CTRL1, ATMR_CTRL1_CLKDIV, ClockDivision);
}

/**
  * @brief  Get the actual division ratio between the timer clock  and the sampling clock used by the dead-time
  *         generators (when supported) and the digital filters.
  * @param  ATMRx Timer instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref DDL_ATMR_CLOCKDIVISION_DIV1
  *         @arg @ref DDL_ATMR_CLOCKDIVISION_DIV2
  *         @arg @ref DDL_ATMR_CLOCKDIVISION_DIV4
  */
__STATIC_INLINE uint32_t DDL_ATMR_GetClockDivision(ATMR_TypeDef *ATMRx)
{
  return (uint32_t)(READ_BIT(ATMRx->CTRL1, ATMR_CTRL1_CLKDIV));
}

/**
  * @brief  Set the counter value.
  * @param  ATMRx Timer instance
  * @param  Counter Counter value (between Min_Data=0 and Max_Data=0xFFFF)
  * @retval None
  */
__STATIC_INLINE void DDL_ATMR_SetCounter(ATMR_TypeDef *ATMRx, uint32_t Counter)
{
  WRITE_REG(ATMRx->CNT, Counter);
}

/**
  * @brief  Get the counter value.
  * @param  ATMRx Timer instance
  * @retval Counter value (between Min_Data=0 and Max_Data=0xFFFF)
  */
__STATIC_INLINE uint16_t DDL_ATMR_GetCounter(ATMR_TypeDef *ATMRx)
{
  return (uint16_t)(READ_REG(ATMRx->CNT));
}

/**
  * @brief  Get the current direction of the counter
  * @param  ATMRx Timer instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref DDL_ATMR_COUNTERDIRECTION_UP
  *         @arg @ref DDL_ATMR_COUNTERDIRECTION_DOWN
  */
__STATIC_INLINE uint32_t DDL_ATMR_GetDirection(ATMR_TypeDef *ATMRx)
{
  return (uint32_t)(READ_BIT(ATMRx->CTRL1, ATMR_CTRL1_CNTDIR));
}

/**
  * @brief  Set the prescaler value.
  * @note The counter clock frequency CK_CNT is equal to fCK_PSC / (PSC[15:0] + 1).
  * @note The prescaler can be changed on the fly as this control register is buffered. The new
  *       prescaler ratio is taken into account at the next update event.
  * @note Helper macro @ref __DDL_ATMR_CALC_PSC can be used to calculate the Prescaler parameter
  * @param  ATMRx Timer instance
  * @param  Prescaler between Min_Data=0 and Max_Data=65535
  * @retval None
  */
__STATIC_INLINE void DDL_ATMR_SetPrescaler(ATMR_TypeDef *ATMRx, uint32_t Prescaler)
{
  WRITE_REG(ATMRx->PSC, Prescaler);
}

/**
  * @brief  Get the prescaler value.
  * @param  ATMRx Timer instance
  * @retval  Prescaler value between Min_Data=0 and Max_Data=65535
  */
__STATIC_INLINE uint16_t DDL_ATMR_GetPrescaler(ATMR_TypeDef *ATMRx)
{
  return (uint16_t)(READ_REG(ATMRx->PSC));
}

/**
  * @brief  Set the auto-reload value.
  * @note The counter is blocked while the auto-reload value is null.
  * @note Helper macro @ref __DDL_ATMR_CALC_ARR can be used to calculate the AutoReload parameter
  * @param  ATMRx Timer instance
  * @param  AutoReload between Min_Data=0 and Max_Data=65535
  * @retval None
  */
__STATIC_INLINE void DDL_ATMR_SetAutoReload(ATMR_TypeDef *ATMRx, uint32_t AutoReload)
{
  WRITE_REG(ATMRx->AUTORLD, AutoReload);
}

/**
  * @brief  Get the auto-reload value.
  * @param  ATMRx Timer instance
  * @retval Auto-reload value
  */
__STATIC_INLINE uint16_t DDL_ATMR_GetAutoReload(ATMR_TypeDef *ATMRx)
{
  return (uint16_t)(READ_REG(ATMRx->AUTORLD));
}

/**
  * @brief  Set the repetition counter value.
  * @note Macro IS_ATMR_REPETITION_COUNTER_INSTANCE(ATMRx) can be used to check
  *       whether or not a timer instance supports a repetition counter.
  * @param  ATMRx Timer instance
  * @param  RepetitionCounter between Min_Data=0 and Max_Data=255.
  * @retval None
  */
__STATIC_INLINE void DDL_ATMR_SetRepetitionCounter(ATMR_TypeDef *ATMRx, uint32_t RepetitionCounter)
{
  WRITE_REG(ATMRx->REPCNT, RepetitionCounter);
}

/**
  * @brief  Get the repetition counter value.
  * @note Macro IS_ATMR_REPETITION_COUNTER_INSTANCE(ATMRx) can be used to check
  *       whether or not a timer instance supports a repetition counter.
  * @param  ATMRx Timer instance
  * @retval Repetition counter value
  */
__STATIC_INLINE uint8_t DDL_ATMR_GetRepetitionCounter(ATMR_TypeDef *ATMRx)
{
  return (uint8_t)(READ_REG(ATMRx->REPCNT));
}

/**
  * @}
  */

/** @defgroup ATMR_DDL_EF_Capture_Compare Capture Compare configuration
  * @{
  */
/**
  * @brief  Enable  the capture/compare control bits (CCxE, CCxNE and OCxM) preload.
  * @note CCxE, CCxNE and OCxM bits are preloaded, after having been written,
  *       they are updated only when a commutation event (COM) occurs.
  * @note Only on channels that have a complementary output.
  * @note Macro IS_ATMR_COMMUTATION_EVENT_INSTANCE(ATMRx) can be used to check
  *       whether or not a timer instance is able to generate a commutation event.
  * @param  ATMRx Timer instance
  * @retval None
  */
__STATIC_INLINE void DDL_ATMR_CC_EnablePreload(ATMR_TypeDef *ATMRx)
{
  SET_BIT(ATMRx->CTRL2, ATMR_CTRL2_CCPEN);
}

/**
  * @brief  Disable  the capture/compare control bits (CCxE, CCxNE and OCxM) preload.
  * @note Macro IS_ATMR_COMMUTATION_EVENT_INSTANCE(ATMRx) can be used to check
  *       whether or not a timer instance is able to generate a commutation event.
  * @param  ATMRx Timer instance
  * @retval None
  */
__STATIC_INLINE void DDL_ATMR_CC_DisablePreload(ATMR_TypeDef *ATMRx)
{
  CLEAR_BIT(ATMRx->CTRL2, ATMR_CTRL2_CCPEN);
}

/**
  * @brief  Set the updated source of the capture/compare control bits (CCxE, CCxNE and OCxM).
  * @note Macro IS_ATMR_COMMUTATION_EVENT_INSTANCE(ATMRx) can be used to check
  *       whether or not a timer instance is able to generate a commutation event.
  * @param  ATMRx Timer instance
  * @param  CCUpdateSource This parameter can be one of the following values:
  *         @arg @ref DDL_ATMR_CCUPDATESOURCE_COMG_ONLY
  *         @arg @ref DDL_ATMR_CCUPDATESOURCE_COMG_AND_TRGI
  * @retval None
  */
__STATIC_INLINE void DDL_ATMR_CC_SetUpdate(ATMR_TypeDef *ATMRx, uint32_t CCUpdateSource)
{
  MODIFY_REG(ATMRx->CTRL2, ATMR_CTRL2_CCUSEL, CCUpdateSource);
}

/**
  * @brief  Get the updated source of the capture/compare control bits (CCxE, CCxNE and OCxM).
  * @note Macro IS_ATMR_COMMUTATION_EVENT_INSTANCE(ATMRx) can be used to check
  *       whether or not a timer instance is able to generate a commutation event.
  * @param  ATMRx Timer instance
  * @retval This parameter can be one of the following values:
  *         @arg @ref DDL_ATMR_CCUPDATESOURCE_COMG_ONLY
  *         @arg @ref DDL_ATMR_CCUPDATESOURCE_COMG_AND_TRGI
  */
__STATIC_INLINE uint32_t DDL_ATMR_CC_GetUpdate(ATMR_TypeDef *ATMRx)
{
  return (uint32_t)(READ_BIT(ATMRx->CTRL2, ATMR_CTRL2_CCUSEL));
}

/**
  * @brief  Set the lock level to freeze the
  *         configuration of several capture/compare parameters.
  * @note Macro IS_ATMR_BREAK_INSTANCE(ATMRx) can be used to check whether or not
  *       the lock mechanism is supported by a timer instance.
  * @param  ATMRx Timer instance
  * @param  LockLevel This parameter can be one of the following values:
  *         @arg @ref DDL_ATMR_LOCKLEVEL_OFF
  *         @arg @ref DDL_ATMR_LOCKLEVEL_1
  *         @arg @ref DDL_ATMR_LOCKLEVEL_2
  *         @arg @ref DDL_ATMR_LOCKLEVEL_3
  * @retval None
  */
__STATIC_INLINE void DDL_ATMR_CC_SetLockLevel(ATMR_TypeDef *ATMRx, uint32_t LockLevel)
{
  MODIFY_REG(ATMRx->BDT, ATMR_BDT_LOCKCFG, LockLevel);
}

/**
  * @brief  Get the lock level to freeze the
  *         configuration of several capture/compare parameters.
  * @note Macro IS_ATMR_BREAK_INSTANCE(ATMRx) can be used to check whether or not
  *       the lock mechanism is supported by a timer instance.
  * @param  ATMRx Timer instance
  * @param  LockLevel This parameter can be one of the following values:
  *         @arg @ref DDL_ATMR_LOCKLEVEL_OFF
  *         @arg @ref DDL_ATMR_LOCKLEVEL_1
  *         @arg @ref DDL_ATMR_LOCKLEVEL_2
  *         @arg @ref DDL_ATMR_LOCKLEVEL_3
  * @retval None
  */
__STATIC_INLINE uint32_t DDL_ATMR_CC_GetLockLevel(ATMR_TypeDef *ATMRx)
{
  return (uint32_t)(READ_BIT(ATMRx->BDT, ATMR_BDT_LOCKCFG));
}

/**
  * @brief  Enable capture/compare channels.
  * @param  ATMRx Timer instance
  * @param  Channels This parameter can be a combination of the following values:
  *         @arg @ref DDL_ATMR_CHANNEL_CH0
  *         @arg @ref DDL_ATMR_CHANNEL_CH0N
  *         @arg @ref DDL_ATMR_CHANNEL_CH1
  *         @arg @ref DDL_ATMR_CHANNEL_CH1N
  *         @arg @ref DDL_ATMR_CHANNEL_CH2
  *         @arg @ref DDL_ATMR_CHANNEL_CH2N
  *         @arg @ref DDL_ATMR_CHANNEL_CH3
  *         @arg @ref DDL_ATMR_CHANNEL_CH4
  * @retval None
  */
__STATIC_INLINE void DDL_ATMR_CC_EnableChannel(ATMR_TypeDef *ATMRx, uint32_t Channels)
{
  if ((Channels & DDL_ATMR_CHANNEL_CH4) != 0U)
  {
    SET_BIT(ATMRx->CH4CFG, Channels >> 16U);
  }
  SET_BIT(ATMRx->CCEN, Channels & 0xFFFFU);
}

/**
  * @brief  Disable capture/compare channels.
  * @param  ATMRx Timer instance
  * @param  Channels This parameter can be a combination of the following values:
  *         @arg @ref DDL_ATMR_CHANNEL_CH0
  *         @arg @ref DDL_ATMR_CHANNEL_CH0N
  *         @arg @ref DDL_ATMR_CHANNEL_CH1
  *         @arg @ref DDL_ATMR_CHANNEL_CH1N
  *         @arg @ref DDL_ATMR_CHANNEL_CH2
  *         @arg @ref DDL_ATMR_CHANNEL_CH2N
  *         @arg @ref DDL_ATMR_CHANNEL_CH3
  *         @arg @ref DDL_ATMR_CHANNEL_CH4
  * @retval None
  */
__STATIC_INLINE void DDL_ATMR_CC_DisableChannel(ATMR_TypeDef *ATMRx, uint32_t Channels)
{
  if ((Channels & DDL_ATMR_CHANNEL_CH4) != 0U)
  {
    CLEAR_BIT(ATMRx->CH4CFG, Channels >> 16U);
  }
  CLEAR_BIT(ATMRx->CCEN, Channels & 0xFFFFU);

}

/**
  * @brief  Indicate whether channel(s) is(are) enabled.
  * @param  ATMRx Timer instance
  * @param  Channels This parameter can be a combination of the following values:
  *         @arg @ref DDL_ATMR_CHANNEL_CH0
  *         @arg @ref DDL_ATMR_CHANNEL_CH0N
  *         @arg @ref DDL_ATMR_CHANNEL_CH1
  *         @arg @ref DDL_ATMR_CHANNEL_CH1N
  *         @arg @ref DDL_ATMR_CHANNEL_CH2
  *         @arg @ref DDL_ATMR_CHANNEL_CH2N
  *         @arg @ref DDL_ATMR_CHANNEL_CH3
  *         @arg @ref DDL_ATMR_CHANNEL_CH4
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_ATMR_CC_IsEnabledChannel(ATMR_TypeDef *ATMRx, uint32_t Channels)
{
  uint32_t status = 1UL;

  if ((Channels & DDL_ATMR_CHANNEL_CH4) != 0U)
  {
    status = ((READ_BIT(ATMRx->CH4CFG, ((Channels & 0xFFFF0000) >> 16)) << 16) == (Channels & 0xFFFF0000)) ? 1UL : 0UL;
  }

  status &= (READ_BIT(ATMRx->CCEN, (Channels & 0xFFFFU)) == (Channels & 0xFFFFU)) ? 1UL : 0UL;

  return status;
}

/**
  * @}
  */

/** @defgroup ATMR_DDL_EF_Output_Channel Output channel configuration
  * @{
  */
/**
  * @brief  Define the behavior of the output reference signal OCxREF from which
  *         OCx and OCxN (when relevant) are derived.
  * @param  ATMRx Timer instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref DDL_ATMR_CHANNEL_CH0
  *         @arg @ref DDL_ATMR_CHANNEL_CH1
  *         @arg @ref DDL_ATMR_CHANNEL_CH2
  *         @arg @ref DDL_ATMR_CHANNEL_CH3
  *         @arg @ref DDL_ATMR_CHANNEL_CH4
  * @param  Mode This parameter can be one of the following values:
  *         @arg @ref DDL_ATMR_OCMODE_FROZEN
  *         @arg @ref DDL_ATMR_OCMODE_ACTIVE
  *         @arg @ref DDL_ATMR_OCMODE_INACTIVE
  *         @arg @ref DDL_ATMR_OCMODE_TOGGLE
  *         @arg @ref DDL_ATMR_OCMODE_FORCED_INACTIVE
  *         @arg @ref DDL_ATMR_OCMODE_FORCED_ACTIVE
  *         @arg @ref DDL_ATMR_OCMODE_PWM1
  *         @arg @ref DDL_ATMR_OCMODE_PWM2
  * @retval None
  */
__STATIC_INLINE void DDL_ATMR_OC_SetMode(ATMR_TypeDef *ATMRx, uint32_t Channel, uint32_t Mode)
{
  uint8_t iChannel = ATMR_GET_CHANNEL_INDEX(Channel);
  __IO uint32_t *pReg = (__IO uint32_t *)((uintptr_t)((uintptr_t)(&ATMRx->CCM1) + DDL_ATMR_OFFSET_TAB_CCMRx[iChannel]));
  MODIFY_REG(*pReg, (ATMR_CCM1_OC0MOD << DDL_ATMR_SHIFT_TAB_OCxx[iChannel]), Mode << DDL_ATMR_SHIFT_TAB_OCxx[iChannel]);
}

/**
  * @brief  Get the output compare mode of an output channel.
  * @param  ATMRx Timer instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref DDL_ATMR_CHANNEL_CH0
  *         @arg @ref DDL_ATMR_CHANNEL_CH1
  *         @arg @ref DDL_ATMR_CHANNEL_CH2
  *         @arg @ref DDL_ATMR_CHANNEL_CH3
  *         @arg @ref DDL_ATMR_CHANNEL_CH4
  * @retval Returned value can be one of the following values:
  *         @arg @ref DDL_ATMR_OCMODE_FROZEN
  *         @arg @ref DDL_ATMR_OCMODE_ACTIVE
  *         @arg @ref DDL_ATMR_OCMODE_INACTIVE
  *         @arg @ref DDL_ATMR_OCMODE_TOGGLE
  *         @arg @ref DDL_ATMR_OCMODE_FORCED_INACTIVE
  *         @arg @ref DDL_ATMR_OCMODE_FORCED_ACTIVE
  *         @arg @ref DDL_ATMR_OCMODE_PWM1
  *         @arg @ref DDL_ATMR_OCMODE_PWM2
  */
__STATIC_INLINE uint32_t DDL_ATMR_OC_GetMode(ATMR_TypeDef *ATMRx, uint32_t Channel)
{
  uint8_t iChannel = ATMR_GET_CHANNEL_INDEX(Channel);
  const __IO uint32_t *pReg = (__IO uint32_t *)((uintptr_t)((uintptr_t)(&ATMRx->CCM1) + DDL_ATMR_OFFSET_TAB_CCMRx[iChannel]));
  return (READ_BIT(*pReg, (ATMR_CCM1_OC0MOD << DDL_ATMR_SHIFT_TAB_OCxx[iChannel])) >> DDL_ATMR_SHIFT_TAB_OCxx[iChannel]);
}

/**
  * @brief  Set the polarity of an output channel.
  * @param  ATMRx Timer instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref DDL_ATMR_CHANNEL_CH0
  *         @arg @ref DDL_ATMR_CHANNEL_CH0N
  *         @arg @ref DDL_ATMR_CHANNEL_CH1
  *         @arg @ref DDL_ATMR_CHANNEL_CH1N
  *         @arg @ref DDL_ATMR_CHANNEL_CH2
  *         @arg @ref DDL_ATMR_CHANNEL_CH2N
  *         @arg @ref DDL_ATMR_CHANNEL_CH3
  *         @arg @ref DDL_ATMR_CHANNEL_CH4
  * @param  Polarity This parameter can be one of the following values:
  *         @arg @ref DDL_ATMR_OCPOLARITY_HIGH
  *         @arg @ref DDL_ATMR_OCPOLARITY_LOW
  * @retval None
  */
__STATIC_INLINE void DDL_ATMR_OC_SetPolarity(ATMR_TypeDef *ATMRx, uint32_t Channel, uint32_t Polarity)
{
  uint8_t iChannel = ATMR_GET_CHANNEL_INDEX(Channel);
  __IO uint32_t *pReg = (__IO uint32_t *)((uintptr_t)((uintptr_t)(&ATMRx->CCEN) + DDL_ATMR_OFFSET_TAB_CCENRx[iChannel]));
  MODIFY_REG(*pReg, (ATMR_CCEN_CC0POL << DDL_ATMR_SHIFT_TAB_CCxP[iChannel]), Polarity << DDL_ATMR_SHIFT_TAB_CCxP[iChannel]);
}

/**
  * @brief  Get the polarity of an output channel.
  * @param  ATMRx Timer instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref DDL_ATMR_CHANNEL_CH0
  *         @arg @ref DDL_ATMR_CHANNEL_CH0N
  *         @arg @ref DDL_ATMR_CHANNEL_CH1
  *         @arg @ref DDL_ATMR_CHANNEL_CH1N
  *         @arg @ref DDL_ATMR_CHANNEL_CH2
  *         @arg @ref DDL_ATMR_CHANNEL_CH2N
  *         @arg @ref DDL_ATMR_CHANNEL_CH3
  *         @arg @ref DDL_ATMR_CHANNEL_CH4
  * @retval Returned value can be one of the following values:
  *         @arg @ref DDL_ATMR_OCPOLARITY_HIGH
  *         @arg @ref DDL_ATMR_OCPOLARITY_LOW
  */
__STATIC_INLINE uint32_t DDL_ATMR_OC_GetPolarity(ATMR_TypeDef *ATMRx, uint32_t Channel)
{
  uint8_t iChannel = ATMR_GET_CHANNEL_INDEX(Channel);
  __IO uint32_t *pReg = (__IO uint32_t *)((uintptr_t)((uintptr_t)(&ATMRx->CCEN) + DDL_ATMR_OFFSET_TAB_CCENRx[iChannel]));
  return (READ_BIT(*pReg, (ATMR_CCEN_CC0POL << DDL_ATMR_SHIFT_TAB_CCxP[iChannel])) >> DDL_ATMR_SHIFT_TAB_CCxP[iChannel]);
}

/**
  * @brief  Set the IDLE state of an output channel
  * @note This function is significant only for the timer instances
  *       supporting the break feature. Macro IS_ATMR_BREAK_INSTANCE(ATMRx)
  *       can be used to check whether or not a timer instance provides
  *       a break input.
  * @param  ATMRx Timer instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref DDL_ATMR_CHANNEL_CH0
  *         @arg @ref DDL_ATMR_CHANNEL_CH0N
  *         @arg @ref DDL_ATMR_CHANNEL_CH1
  *         @arg @ref DDL_ATMR_CHANNEL_CH1N
  *         @arg @ref DDL_ATMR_CHANNEL_CH2
  *         @arg @ref DDL_ATMR_CHANNEL_CH2N
  *         @arg @ref DDL_ATMR_CHANNEL_CH3
  * @param  IdleState This parameter can be one of the following values:
  *         @arg @ref DDL_ATMR_OCIDLESTATE_LOW
  *         @arg @ref DDL_ATMR_OCIDLESTATE_HIGH
  * @retval None
  */
__STATIC_INLINE void DDL_ATMR_OC_SetIdleState(ATMR_TypeDef *ATMRx, uint32_t Channel, uint32_t IdleState)
{
  uint8_t iChannel = ATMR_GET_CHANNEL_INDEX(Channel);
  MODIFY_REG(ATMRx->CTRL2, (ATMR_CTRL2_OC0OIS << DDL_ATMR_SHIFT_TAB_OISx[iChannel]),  IdleState << DDL_ATMR_SHIFT_TAB_OISx[iChannel]);
}

/**
  * @brief  Get the IDLE state of an output channel
  * @param  ATMRx Timer instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref DDL_ATMR_CHANNEL_CH0
  *         @arg @ref DDL_ATMR_CHANNEL_CH0N
  *         @arg @ref DDL_ATMR_CHANNEL_CH1
  *         @arg @ref DDL_ATMR_CHANNEL_CH1N
  *         @arg @ref DDL_ATMR_CHANNEL_CH2
  *         @arg @ref DDL_ATMR_CHANNEL_CH2N
  *         @arg @ref DDL_ATMR_CHANNEL_CH3
  * @retval Returned value can be one of the following values:
  *         @arg @ref DDL_ATMR_OCIDLESTATE_LOW
  *         @arg @ref DDL_ATMR_OCIDLESTATE_HIGH
  */
__STATIC_INLINE uint32_t DDL_ATMR_OC_GetIdleState(ATMR_TypeDef *ATMRx, uint32_t Channel)
{
  uint8_t iChannel = ATMR_GET_CHANNEL_INDEX(Channel);
  return (READ_BIT(ATMRx->CTRL2, (ATMR_CTRL2_OC0OIS << DDL_ATMR_SHIFT_TAB_OISx[iChannel])) >> DDL_ATMR_SHIFT_TAB_OISx[iChannel]);
}

/**
  * @brief  Enable compare register (ATMRx_CCx) preload for the output channel.
  * @param  ATMRx Timer instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref DDL_ATMR_CHANNEL_CH0
  *         @arg @ref DDL_ATMR_CHANNEL_CH1
  *         @arg @ref DDL_ATMR_CHANNEL_CH2
  *         @arg @ref DDL_ATMR_CHANNEL_CH3
  *         @arg @ref DDL_ATMR_CHANNEL_CH4
  * @retval None
  */
__STATIC_INLINE void DDL_ATMR_OC_EnablePreload(ATMR_TypeDef *ATMRx, uint32_t Channel)
{
  uint8_t iChannel = ATMR_GET_CHANNEL_INDEX(Channel);
  __IO uint32_t *pReg = (__IO uint32_t *)((uintptr_t)((uintptr_t)(&ATMRx->CCM1) + DDL_ATMR_OFFSET_TAB_CCMRx[iChannel]));
  if(Channel == DDL_ATMR_CHANNEL_CH4)
  {
      iChannel += 1;
  }
  SET_BIT(*pReg, (ATMR_CCM1_OC0PEN << DDL_ATMR_SHIFT_TAB_OCxx[iChannel]));
}

/**
  * @brief  Disable compare register (ATMRx_CCx) preload for the output channel.
  * @param  ATMRx Timer instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref DDL_ATMR_CHANNEL_CH0
  *         @arg @ref DDL_ATMR_CHANNEL_CH1
  *         @arg @ref DDL_ATMR_CHANNEL_CH2
  *         @arg @ref DDL_ATMR_CHANNEL_CH3
  *         @arg @ref DDL_ATMR_CHANNEL_CH4
  * @retval None
  */
__STATIC_INLINE void DDL_ATMR_OC_DisablePreload(ATMR_TypeDef *ATMRx, uint32_t Channel)
{
  uint8_t iChannel = ATMR_GET_CHANNEL_INDEX(Channel);
  __IO uint32_t *pReg = (__IO uint32_t *)((uintptr_t)((uintptr_t)(&ATMRx->CCM1) + DDL_ATMR_OFFSET_TAB_CCMRx[iChannel]));
  if(Channel == DDL_ATMR_CHANNEL_CH4)
  {
      iChannel += 1;
  }
  CLEAR_BIT(*pReg, (ATMR_CCM1_OC0PEN << DDL_ATMR_SHIFT_TAB_OCxx[iChannel]));
}

/**
  * @brief  Indicates whether compare register (ATMRx_CCx) preload is enabled for the output channel.
  * @param  ATMRx Timer instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref DDL_ATMR_CHANNEL_CH0
  *         @arg @ref DDL_ATMR_CHANNEL_CH1
  *         @arg @ref DDL_ATMR_CHANNEL_CH2
  *         @arg @ref DDL_ATMR_CHANNEL_CH3
  *         @arg @ref DDL_ATMR_CHANNEL_CH4
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_ATMR_OC_IsEnabledPreload(ATMR_TypeDef *ATMRx, uint32_t Channel)
{
  uint8_t iChannel = ATMR_GET_CHANNEL_INDEX(Channel);
  const __IO uint32_t *pReg = (__IO uint32_t *)((uintptr_t)((uintptr_t)(&ATMRx->CCM1) + DDL_ATMR_OFFSET_TAB_CCMRx[iChannel]));
  if(Channel == DDL_ATMR_CHANNEL_CH4)
  {
      iChannel += 1;
  }
  uint32_t bitfield = ATMR_CCM1_OC0PEN << DDL_ATMR_SHIFT_TAB_OCxx[iChannel];
  return ((READ_BIT(*pReg, bitfield) == bitfield) ? 1UL : 0UL);
}

/**
  * @brief  Enable clearing the output channel on an external event.
  * @note This function can only be used in Output compare and PWM modes. It does not work in Forced mode.
  * @note Macro IS_ATMR_OCXREF_CLEAR_INSTANCE(ATMRx) can be used to check whether
  *       or not a timer instance can clear the OCxREF signal on an external event.
  * @param  ATMRx Timer instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref DDL_ATMR_CHANNEL_CH0
  *         @arg @ref DDL_ATMR_CHANNEL_CH1
  *         @arg @ref DDL_ATMR_CHANNEL_CH2
  *         @arg @ref DDL_ATMR_CHANNEL_CH3
  *         @arg @ref DDL_ATMR_CHANNEL_CH4
  * @retval None
  */
__STATIC_INLINE void DDL_ATMR_OC_EnableClear(ATMR_TypeDef *ATMRx, uint32_t Channel)
{
  uint8_t iChannel = ATMR_GET_CHANNEL_INDEX(Channel);
  __IO uint32_t *pReg = (__IO uint32_t *)((uintptr_t)((uintptr_t)(&ATMRx->CCM1) + DDL_ATMR_OFFSET_TAB_CCMRx[iChannel]));
  if(Channel == DDL_ATMR_CHANNEL_CH4)
  {
      iChannel += 2;
  }
  SET_BIT(*pReg, (ATMR_CCM1_OC0CEN << DDL_ATMR_SHIFT_TAB_OCxx[iChannel]));
}

/**
  * @brief  Disable clearing the output channel on an external event.
  * @note Macro IS_ATMR_OCXREF_CLEAR_INSTANCE(ATMRx) can be used to check whether
  *       or not a timer instance can clear the OCxREF signal on an external event.
  * @param  ATMRx Timer instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref DDL_ATMR_CHANNEL_CH0
  *         @arg @ref DDL_ATMR_CHANNEL_CH1
  *         @arg @ref DDL_ATMR_CHANNEL_CH2
  *         @arg @ref DDL_ATMR_CHANNEL_CH3
  *         @arg @ref DDL_ATMR_CHANNEL_CH4
  * @retval None
  */
__STATIC_INLINE void DDL_ATMR_OC_DisableClear(ATMR_TypeDef *ATMRx, uint32_t Channel)
{
  uint8_t iChannel = ATMR_GET_CHANNEL_INDEX(Channel);
  __IO uint32_t *pReg = (__IO uint32_t *)((uintptr_t)((uintptr_t)(&ATMRx->CCM1) + DDL_ATMR_OFFSET_TAB_CCMRx[iChannel]));
  if(Channel == DDL_ATMR_CHANNEL_CH4)
  {
      iChannel += 2;
  }
  CLEAR_BIT(*pReg, (ATMR_CCM1_OC0CEN << DDL_ATMR_SHIFT_TAB_OCxx[iChannel]));
}

/**
  * @brief  Indicates clearing the output channel on an external event is enabled for the output channel.
  * @note This function enables clearing the output channel on an external event.
  * @note This function can only be used in Output compare and PWM modes. It does not work in Forced mode.
  * @note Macro IS_ATMR_OCXREF_CLEAR_INSTANCE(ATMRx) can be used to check whether
  *       or not a timer instance can clear the OCxREF signal on an external event.
  * @param  ATMRx Timer instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref DDL_ATMR_CHANNEL_CH0
  *         @arg @ref DDL_ATMR_CHANNEL_CH1
  *         @arg @ref DDL_ATMR_CHANNEL_CH2
  *         @arg @ref DDL_ATMR_CHANNEL_CH3
  *         @arg @ref DDL_ATMR_CHANNEL_CH4
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_ATMR_OC_IsEnabledClear(ATMR_TypeDef *ATMRx, uint32_t Channel)
{
  uint8_t iChannel = ATMR_GET_CHANNEL_INDEX(Channel);
  const __IO uint32_t *pReg = (__IO uint32_t *)((uintptr_t)((uintptr_t)(&ATMRx->CCM1) + DDL_ATMR_OFFSET_TAB_CCMRx[iChannel]));
  if(Channel == DDL_ATMR_CHANNEL_CH4)
  {
      iChannel += 2;
  }
  uint32_t bitfield = ATMR_CCM1_OC0CEN << DDL_ATMR_SHIFT_TAB_OCxx[iChannel];
  return ((READ_BIT(*pReg, bitfield) == bitfield) ? 1UL : 0UL);
}

/**
  * @brief  Set the dead-time delay (delay inserted between the rising edge of the OCxREF signal and the rising edge of
  *         the Ocx and OCxN signals).
  * @note Macro IS_ATMR_BREAK_INSTANCE(ATMRx) can be used to check whether or not
  *       dead-time insertion feature is supported by a timer instance.
  * @note Helper macro @ref __DDL_ATMR_CALC_DEADATMRE can be used to calculate the DeadTime parameter
  * @param  ATMRx Timer instance
  * @param  DeadTime between Min_Data=0 and Max_Data=255
  * @retval None
  */
__STATIC_INLINE void DDL_ATMR_OC_SetDeadTime(ATMR_TypeDef *ATMRx, uint32_t DeadTime)
{
  MODIFY_REG(ATMRx->BDT, ATMR_BDT_DTS, DeadTime);
}

/**
  * @brief  Set compare value for output channel 0 (ATMRx_CC0).
  * @note In 32-bit timer implementations compare value can be between 0x00000000 and 0xFFFFFFFF.
  * @note Macro IS_ATMR_32B_COUNTER_INSTANCE(ATMRx) can be used to check
  *       whether or not a timer instance supports a 32 bits counter.
  * @note Macro IS_ATMR_CC0_INSTANCE(ATMRx) can be used to check whether or not
  *       output channel 0 is supported by a timer instance.
  * @param  ATMRx Timer instance
  * @param  CompareValue between Min_Data=0 and Max_Data=65535
  * @retval None
  */
__STATIC_INLINE void DDL_ATMR_OC_SetCompareCH0(ATMR_TypeDef *ATMRx, uint32_t CompareValue)
{
  WRITE_REG(ATMRx->CC0, CompareValue);
}

/**
  * @brief  Set compare value for output channel 1 (ATMRx_CC1).
  * @note In 32-bit timer implementations compare value can be between 0x00000000 and 0xFFFFFFFF.
  * @note Macro IS_ATMR_32B_COUNTER_INSTANCE(ATMRx) can be used to check
  *       whether or not a timer instance supports a 32 bits counter.
  * @note Macro IS_ATMR_CC1_INSTANCE(ATMRx) can be used to check whether or not
  *       output channel is supported by a timer instance.
  * @param  ATMRx Timer instance
  * @param  CompareValue between Min_Data=0 and Max_Data=65535
  * @retval None
  */
__STATIC_INLINE void DDL_ATMR_OC_SetCompareCH1(ATMR_TypeDef *ATMRx, uint32_t CompareValue)
{
  WRITE_REG(ATMRx->CC1, CompareValue);
}

/**
  * @brief  Set compare value for output channel 2 (ATMRx_CC2).
  * @note In 32-bit timer implementations compare value can be between 0x00000000 and 0xFFFFFFFF.
  * @note Macro IS_ATMR_32B_COUNTER_INSTANCE(ATMRx) can be used to check
  *       whether or not a timer instance supports a 32 bits counter.
  * @note Macro IS_ATMR_CC2_INSTANCE(ATMRx) can be used to check whether or not
  *       output channel 1 is supported by a timer instance.
  * @param  ATMRx Timer instance
  * @param  CompareValue between Min_Data=0 and Max_Data=65535
  * @retval None
  */
__STATIC_INLINE void DDL_ATMR_OC_SetCompareCH2(ATMR_TypeDef *ATMRx, uint32_t CompareValue)
{
  WRITE_REG(ATMRx->CC2, CompareValue);
}

/**
  * @brief  Set compare value for output channel 3 (ATMRx_CC3).
  * @note In 32-bit timer implementations compare value can be between 0x00000000 and 0xFFFFFFFF.
  * @note Macro IS_ATMR_32B_COUNTER_INSTANCE(ATMRx) can be used to check
  *       whether or not a timer instance supports a 32 bits counter.
  * @note Macro IS_ATMR_CC3_INSTANCE(ATMRx) can be used to check whether or not
  *       output channel is supported by a timer instance.
  * @param  ATMRx Timer instance
  * @param  CompareValue between Min_Data=0 and Max_Data=65535
  * @retval None
  */
__STATIC_INLINE void DDL_ATMR_OC_SetCompareCH3(ATMR_TypeDef *ATMRx, uint32_t CompareValue)
{
  WRITE_REG(ATMRx->CC3, CompareValue);
}

/**
  * @brief  Set compare value for output channel 4 (ATMRx_CC4).
  * @note In 32-bit timer implementations compare value can be between 0x00000000 and 0xFFFFFFFF.
  * @note Macro IS_ATMR_32B_COUNTER_INSTANCE(ATMRx) can be used to check
  *       whether or not a timer instance supports a 32 bits counter.
  * @note Macro IS_ATMR_CC4_INSTANCE(ATMRx) can be used to check whether or not
  *       output channel is supported by a timer instance.
  * @param  ATMRx Timer instance
  * @param  CompareValue between Min_Data=0 and Max_Data=65535
  * @retval None
  */
__STATIC_INLINE void DDL_ATMR_OC_SetCompareCH4(ATMR_TypeDef *ATMRx, uint32_t CompareValue)
{
  WRITE_REG(ATMRx->CC4, CompareValue);
}

/**
  * @brief  Get compare value (ATMRx_CC0) set for output channel 0.
  * @note Macro IS_ATMR_CC0_INSTANCE(ATMRx) can be used to check whether or not
  *       output channel 0 is supported by a timer instance.
  * @param  ATMRx Timer instance
  * @retval CompareValue (between Min_Data=0 and Max_Data=65535)
  */
__STATIC_INLINE uint16_t DDL_ATMR_OC_GetCompareCH0(ATMR_TypeDef *ATMRx)
{
  return (uint16_t)(READ_REG(ATMRx->CC0));
}

/**
  * @brief  Get compare value (ATMRx_CC1) set for output channel 1.
  * @note Macro IS_ATMR_CC1_INSTANCE(ATMRx) can be used to check whether or not
  *       output channel 1 is supported by a timer instance.
  * @param  ATMRx Timer instance
  * @retval CompareValue (between Min_Data=0 and Max_Data=65535)
  */
__STATIC_INLINE uint16_t DDL_ATMR_OC_GetCompareCH1(ATMR_TypeDef *ATMRx)
{
  return (uint16_t)(READ_REG(ATMRx->CC1));
}

/**
  * @brief  Get compare value (ATMRx_CC2) set for output channel 2.
  * @note Macro IS_ATMR_CC2_INSTANCE(ATMRx) can be used to check whether or not
  *       output channel 2 is supported by a timer instance.
  * @param  ATMRx Timer instance
  * @retval CompareValue (between Min_Data=0 and Max_Data=65535)
  */
__STATIC_INLINE uint16_t DDL_ATMR_OC_GetCompareCH2(ATMR_TypeDef *ATMRx)
{
  return (uint16_t)(READ_REG(ATMRx->CC2));
}

/**
  * @brief  Get compare value (ATMRx_CC3) set for output channel 3.
  * @note Macro IS_ATMR_CC3_INSTANCE(ATMRx) can be used to check whether or not
  *       output channel 3 is supported by a timer instance.
  * @param  ATMRx Timer instance
  * @retval CompareValue (between Min_Data=0 and Max_Data=65535)
  */
__STATIC_INLINE uint16_t DDL_ATMR_OC_GetCompareCH3(ATMR_TypeDef *ATMRx)
{
  return (uint16_t)(READ_REG(ATMRx->CC3));
}

/**
  * @brief  Get compare value (ATMRx_CC4) set for output channel 4.
  * @note Macro IS_ATMR_CC4_INSTANCE(ATMRx) can be used to check whether or not
  *       output channel 4 is supported by a timer instance.
  * @param  ATMRx Timer instance
  * @retval CompareValue (between Min_Data=0 and Max_Data=65535)
  */
__STATIC_INLINE uint16_t DDL_ATMR_OC_GetCompareCH4(ATMR_TypeDef *ATMRx)
{
  return (uint16_t)(READ_REG(ATMRx->CC4));
}

/**
  * @}
  */

/** @defgroup ATMR_DDL_EF_Timer_Synchronization Timer synchronisation configuration
  * @{
  */
/**
  * @brief  Set the trigger output (TRGO) used for timer synchronization .
  * @note Macro IS_ATMR_MASTER_INSTANCE(ATMRx) can be used to check
  *       whether or not a timer instance can operate as a master timer.
  * @param  ATMRx Timer instance
  * @param  TimerSynchronization This parameter can be one of the following values:
  *         @arg @ref DDL_ATMR_TRGO_RESET
  *         @arg @ref DDL_ATMR_TRGO_ENABLE
  *         @arg @ref DDL_ATMR_TRGO_UPDATE
  *         @arg @ref DDL_ATMR_TRGO_CCIF_EVENT
  *         @arg @ref DDL_ATMR_TRGO_OC0REF
  *         @arg @ref DDL_ATMR_TRGO_OC1REF
  *         @arg @ref DDL_ATMR_TRGO_OC2REF
  *         @arg @ref DDL_ATMR_TRGO_OC3REF
  *         @arg @ref DDL_ATMR_TRGO_SZE_SPE
  *         @arg @ref DDL_ATMR_TRGO_OC3UP_OC3DOWN
  *         @arg @ref DDL_ATMR_TRGO_OC4UP_OC4DOWN
  *         @arg @ref DDL_ATMR_TRGO_OC3UP_OC4UP
  *         @arg @ref DDL_ATMR_TRGO_OC3DOWN_OC4DOWN
  *         @arg @ref DDL_ATMR_TRGO_OC3UP_OC4DOWN
  *         @arg @ref DDL_ATMR_TRGO_OC3DOWN_OC4UP
  * @retval None
  */
__STATIC_INLINE void DDL_ATMR_SetTriggerOutputMode0(ATMR_TypeDef *ATMRx, uint32_t TimerSynchronization)
{
  MODIFY_REG(ATMRx->CTRL2, ATMR_CTRL2_MMSEL, (TimerSynchronization << ATMR_CTRL2_MMSEL_Pos));
}

/**
  * @brief  Get the trigger output (TRGO) used for timer synchronization .
  * @note Macro IS_ATMR_MASTER_INSTANCE(ATMRx) can be used to check
  *       whether or not a timer instance can operate as a master timer.
  * @param  ATMRx Timer instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref DDL_ATMR_TRGO_RESET
  *         @arg @ref DDL_ATMR_TRGO_ENABLE
  *         @arg @ref DDL_ATMR_TRGO_UPDATE
  *         @arg @ref DDL_ATMR_TRGO_CCIF_EVENT
  *         @arg @ref DDL_ATMR_TRGO_OC0REF
  *         @arg @ref DDL_ATMR_TRGO_OC1REF
  *         @arg @ref DDL_ATMR_TRGO_OC2REF
  *         @arg @ref DDL_ATMR_TRGO_OC3REF
  *         @arg @ref DDL_ATMR_TRGO_SZE_SPE
  *         @arg @ref DDL_ATMR_TRGO_OC3UP_OC3DOWN
  *         @arg @ref DDL_ATMR_TRGO_OC4UP_OC4DOWN
  *         @arg @ref DDL_ATMR_TRGO_OC3UP_OC4UP
  *         @arg @ref DDL_ATMR_TRGO_OC3DOWN_OC4DOWN
  *         @arg @ref DDL_ATMR_TRGO_OC3UP_OC4DOWN
  *         @arg @ref DDL_ATMR_TRGO_OC3DOWN_OC4UP
  */
__STATIC_INLINE uint32_t DDL_ATMR_GetTriggerOutputMode0(ATMR_TypeDef *ATMRx)
{
  return (uint32_t)(READ_BIT(ATMRx->CTRL2, ATMR_CTRL2_MMSEL) >> ATMR_CTRL2_MMSEL_Pos);
}

/**
  * @brief  Enable the generation of a TRGO signal when the counter matches the auto-reload register.
  * @note This function can only be used in center alignment mode.
  * @param  ATMRx Timer instance
  * @retval None
  */
__STATIC_INLINE void DDL_ATMR_EnableCounterMatchAutoReloadTrigger(ATMR_TypeDef *ATMRx)
{
  SET_BIT(ATMRx->CTRL2, ATMR_CTRL2_MMSPE);
}

/**
  * @brief  Disable the generation of a TRGO signal when the counter matches the auto-reload register.
  * @note This function can only be used in center alignment mode.
  * @param  ATMRx Timer instance
  * @retval None
  */
__STATIC_INLINE void DDL_ATMR_DisableCounterMatchAutoReloadTrigger(ATMR_TypeDef *ATMRx)
{
  CLEAR_BIT(ATMRx->CTRL2, ATMR_CTRL2_MMSPE);
}

/**
  * @brief  Indicates the generation of a TRGO signal when the counter matches the auto-reload register is enabled.
  * @param  ATMRx Timer instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_ATMR_IsEnabledCounterMatchAutoReloadTrigger(ATMR_TypeDef *ATMRx)
{
  return ((READ_BIT(ATMRx->CTRL2, ATMR_CTRL2_MMSPE) == (ATMR_CTRL2_MMSPE)) ? 1UL : 0UL);
}

/**
  * @brief  Enable the generation of a TRGO signal when the counter reset to zero.
  * @note This function can only be used in center alignment mode.
  * @param  ATMRx Timer instance
  * @retval None
  */
__STATIC_INLINE void DDL_ATMR_EnableCounterResetToZeroTrigger(ATMR_TypeDef *ATMRx)
{
  SET_BIT(ATMRx->CTRL2, ATMR_CTRL2_MMSZE);
}

/**
  * @brief  Disable the generation of a TRGO signal when the counter reset to zero.
  * @note This function can only be used in center alignment mode.
  * @param  ATMRx Timer instance
  * @retval None
  */
__STATIC_INLINE void DDL_ATMR_DisableCounterResetToZeroTrigger(ATMR_TypeDef *ATMRx)
{
  CLEAR_BIT(ATMRx->CTRL2, ATMR_CTRL2_MMSZE);
}

/**
  * @brief  Indicates the generation of a TRGO signal when the counter reset to zero is enabled.
  * @param  ATMRx Timer instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_ATMR_IsEnabledCounterResetToZeroTrigger(ATMR_TypeDef *ATMRx)
{
  return ((READ_BIT(ATMRx->CTRL2, ATMR_CTRL2_MMSZE) == (ATMR_CTRL2_MMSZE)) ? 1UL : 0UL);
}

/**
  * @brief  Set the synchronization mode of a slave timer.
  * @note Macro IS_ATMR_SLAVE_INSTANCE(ATMRx) can be used to check whether or not
  *       a timer instance can operate as a slave timer.
  * @param  ATMRx Timer instance
  * @param  SlaveMode This parameter can be one of the following values:
  *         @arg @ref DDL_ATMR_SLAVEMODE_DISABLED
  *         @arg @ref DDL_ATMR_SLAVEMODE_RESET
  *         @arg @ref DDL_ATMR_SLAVEMODE_GATED
  *         @arg @ref DDL_ATMR_SLAVEMODE_TRIGGER
  * @retval None
  */
__STATIC_INLINE void DDL_ATMR_SetSlaveMode(ATMR_TypeDef *ATMRx, uint32_t SlaveMode)
{
  MODIFY_REG(ATMRx->SMCTRL, ATMR_SMCTRL_SMFSEL, SlaveMode);
}

/**
  * @brief  Set the selects the trigger input to be used to synchronize the counter.
  * @note Macro IS_ATMR_SLAVE_INSTANCE(ATMRx) can be used to check whether or not
  *       a timer instance can operate as a slave timer.
  * @param  ATMRx Timer instance
  * @param  TriggerInput This parameter can be one of the following values:
  *         @arg @ref DDL_ATMR_TS_ITR0
  *         @arg @ref DDL_ATMR_TS_ETRF
  * @retval None
  */
__STATIC_INLINE void DDL_ATMR_SetTriggerInput(ATMR_TypeDef *ATMRx, uint32_t TriggerInput)
{
  MODIFY_REG(ATMRx->SMCTRL, ATMR_SMCTRL_TRGSEL, TriggerInput);
}

/**
  * @brief  Enable the Master/Slave mode.
  * @note Macro IS_ATMR_SLAVE_INSTANCE(ATMRx) can be used to check whether or not
  *       a timer instance can operate as a slave timer.
  * @param  ATMRx Timer instance
  * @retval None
  */
__STATIC_INLINE void DDL_ATMR_EnableMasterSlaveMode(ATMR_TypeDef *ATMRx)
{
  SET_BIT(ATMRx->SMCTRL, ATMR_SMCTRL_MSMEN);
}

/**
  * @brief  Disable the Master/Slave mode.
  * @note Macro IS_ATMR_SLAVE_INSTANCE(ATMRx) can be used to check whether or not
  *       a timer instance can operate as a slave timer.
  * @param  ATMRx Timer instance
  * @retval None
  */
__STATIC_INLINE void DDL_ATMR_DisableMasterSlaveMode(ATMR_TypeDef *ATMRx)
{
  CLEAR_BIT(ATMRx->SMCTRL, ATMR_SMCTRL_MSMEN);
}

/**
  * @brief Indicates whether the Master/Slave mode is enabled.
  * @note Macro IS_ATMR_SLAVE_INSTANCE(ATMRx) can be used to check whether or not
  * a timer instance can operate as a slave timer.
  * @param  ATMRx Timer instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_ATMR_IsEnabledMasterSlaveMode(ATMR_TypeDef *ATMRx)
{
  return ((READ_BIT(ATMRx->SMCTRL, ATMR_SMCTRL_MSMEN) == (ATMR_SMCTRL_MSMEN)) ? 1UL : 0UL);
}

/**
  * @brief  Configure the external trigger (ETR) input.
  * @note Macro IS_ATMR_ETR_INSTANCE(ATMRx) can be used to check whether or not
  *       a timer instance provides an external trigger input.
  * @param  ATMRx Timer instance
  * @param  ETRPolarity This parameter can be one of the following values:
  *         @arg @ref DDL_ATMR_ETR_POLARITY_NONINVERTED
  *         @arg @ref DDL_ATMR_ETR_POLARITY_INVERTED
  * @param  ETRPrescaler This parameter can be one of the following values:
  *         @arg @ref DDL_ATMR_ETR_PRESCALER_DIV1
  *         @arg @ref DDL_ATMR_ETR_PRESCALER_DIV2
  *         @arg @ref DDL_ATMR_ETR_PRESCALER_DIV4
  *         @arg @ref DDL_ATMR_ETR_PRESCALER_DIV8
  * @param  ETRFilter This parameter can be one of the following values:
  *         @arg @ref DDL_ATMR_ETR_FILTER_FDIV1
  *         @arg @ref DDL_ATMR_ETR_FILTER_FDIV1_N2
  *         @arg @ref DDL_ATMR_ETR_FILTER_FDIV1_N4
  *         @arg @ref DDL_ATMR_ETR_FILTER_FDIV1_N8
  *         @arg @ref DDL_ATMR_ETR_FILTER_FDIV2_N6
  *         @arg @ref DDL_ATMR_ETR_FILTER_FDIV2_N8
  *         @arg @ref DDL_ATMR_ETR_FILTER_FDIV4_N6
  *         @arg @ref DDL_ATMR_ETR_FILTER_FDIV4_N8
  *         @arg @ref DDL_ATMR_ETR_FILTER_FDIV8_N6
  *         @arg @ref DDL_ATMR_ETR_FILTER_FDIV8_N8
  *         @arg @ref DDL_ATMR_ETR_FILTER_FDIV16_N5
  *         @arg @ref DDL_ATMR_ETR_FILTER_FDIV16_N6
  *         @arg @ref DDL_ATMR_ETR_FILTER_FDIV16_N8
  *         @arg @ref DDL_ATMR_ETR_FILTER_FDIV32_N5
  *         @arg @ref DDL_ATMR_ETR_FILTER_FDIV32_N6
  *         @arg @ref DDL_ATMR_ETR_FILTER_FDIV32_N8
  * @retval None
  */
__STATIC_INLINE void DDL_ATMR_ConfigETR(ATMR_TypeDef *ATMRx, uint32_t ETRPolarity, uint32_t ETRPrescaler,
                                      uint32_t ETRFilter)
{
  MODIFY_REG(ATMRx->SMCTRL, ATMR_SMCTRL_ETPOL | ATMR_SMCTRL_ETPCFG | ATMR_SMCTRL_ETFCFG, ETRPolarity | ETRPrescaler | ETRFilter);
}

/**
  * @}
  */

/** @defgroup ATMR_DDL_EF_Break_Function Break function configuration
  * @{
  */
/**
  * @brief  Enable the break function.
  * @note Macro IS_ATMR_BREAK_INSTANCE(ATMRx) can be used to check whether or not
  *       a timer instance provides a break input.
  * @param  ATMRx Timer instance
  * @retval None
  */
__STATIC_INLINE void DDL_ATMR_EnableBRK(ATMR_TypeDef *ATMRx)
{
  __IO uint32_t tmpreg;
  SET_BIT(ATMRx->BDT, ATMR_BDT_BRKEN);
  /* Note: Any write operation to this bit takes a delay of 1 APB clock cycle to become effective. */
  tmpreg = READ_REG(ATMRx->BDT);
  (void)(tmpreg);
}

/**
  * @brief  Disable the break function.
  * @param  ATMRx Timer instance
  * @note Macro IS_ATMR_BREAK_INSTANCE(ATMRx) can be used to check whether or not
  *       a timer instance provides a break input.
  * @retval None
  */
__STATIC_INLINE void DDL_ATMR_DisableBRK(ATMR_TypeDef *ATMRx)
{
  __IO uint32_t tmpreg;
  CLEAR_BIT(ATMRx->BDT, ATMR_BDT_BRKEN);
  /* Note: Any write operation to this bit takes a delay of 1 APB clock cycle to become effective. */
  tmpreg = READ_REG(ATMRx->BDT);
  (void)(tmpreg);
}

/**
  * @brief  Configure the break input.
  * @note Macro IS_ATMR_BREAK_INSTANCE(ATMRx) can be used to check whether or not
  *       a timer instance provides a break input.
  * @param  ATMRx Timer instance
  * @param  BreakPolarity This parameter can be one of the following values:
  *         @arg @ref DDL_ATMR_BREAK_POLARITY_LOW
  *         @arg @ref DDL_ATMR_BREAK_POLARITY_HIGH
  * @retval None
  */
__STATIC_INLINE void DDL_ATMR_ConfigBRK(ATMR_TypeDef *ATMRx, uint32_t BreakPolarity)
{
  __IO uint32_t tmpreg;
  MODIFY_REG(ATMRx->BDT, ATMR_BDT_BRKPOL, BreakPolarity);
  /* Note: Any write operation to BKP bit takes a delay of 1 APB clock cycle to become effective. */
  tmpreg = READ_REG(ATMRx->BDT);
  (void)(tmpreg);
}

/**
  * @brief  Select the outputs off state (enabled v.s. disabled) in Idle and Run modes.
  * @note Macro IS_ATMR_BREAK_INSTANCE(ATMRx) can be used to check whether or not
  *       a timer instance provides a break input.
  * @param  ATMRx Timer instance
  * @param  OffStateIdle This parameter can be one of the following values:
  *         @arg @ref DDL_ATMR_OSSI_DISABLE
  *         @arg @ref DDL_ATMR_OSSI_ENABLE
  * @param  OffStateRun This parameter can be one of the following values:
  *         @arg @ref DDL_ATMR_OSSR_DISABLE
  *         @arg @ref DDL_ATMR_OSSR_ENABLE
  * @retval None
  */
__STATIC_INLINE void DDL_ATMR_SetOffStates(ATMR_TypeDef *ATMRx, uint32_t OffStateIdle, uint32_t OffStateRun)
{
  MODIFY_REG(ATMRx->BDT, ATMR_BDT_IMOS | ATMR_BDT_RMOS, OffStateIdle | OffStateRun);
}

/**
  * @brief  Enable automatic output (MOE can be set by software or automatically when a break input is active).
  * @note Macro IS_ATMR_BREAK_INSTANCE(ATMRx) can be used to check whether or not
  *       a timer instance provides a break input.
  * @param  ATMRx Timer instance
  * @retval None
  */
__STATIC_INLINE void DDL_ATMR_EnableAutomaticOutput(ATMR_TypeDef *ATMRx)
{
  SET_BIT(ATMRx->BDT, ATMR_BDT_AOEN);
}

/**
  * @brief  Disable automatic output (MOE can be set only by software).
  * @note Macro IS_ATMR_BREAK_INSTANCE(ATMRx) can be used to check whether or not
  *       a timer instance provides a break input.
  * @param  ATMRx Timer instance
  * @retval None
  */
__STATIC_INLINE void DDL_ATMR_DisableAutomaticOutput(ATMR_TypeDef *ATMRx)
{
  CLEAR_BIT(ATMRx->BDT, ATMR_BDT_AOEN);
}

/**
  * @brief  Indicate whether automatic output is enabled.
  * @note Macro IS_ATMR_BREAK_INSTANCE(ATMRx) can be used to check whether or not
  *       a timer instance provides a break input.
  * @param  ATMRx Timer instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_ATMR_IsEnabledAutomaticOutput(ATMR_TypeDef *ATMRx)
{
  return ((READ_BIT(ATMRx->BDT, ATMR_BDT_AOEN) == (ATMR_BDT_AOEN)) ? 1UL : 0UL);
}

/**
  * @brief  Enable the outputs (set the MOE bit in ATMRx_BDT register).
  * @note The MOEN bit in ATMRx_BDT register allows to enable /disable the outputs by
  *       software and is reset in case of break or break2 event
  * @note Macro IS_ATMR_BREAK_INSTANCE(ATMRx) can be used to check whether or not
  *       a timer instance provides a break input.
  * @param  ATMRx Timer instance
  * @retval None
  */
__STATIC_INLINE void DDL_ATMR_EnablePWMOutputs(ATMR_TypeDef *ATMRx)
{
  SET_BIT(ATMRx->BDT, ATMR_BDT_MOEN);
}

/**
  * @brief  Disable the outputs (reset the MOEN bit in ATMRx_BDT register).
  * @note The MOEN bit in ATMRx_BDT register allows to enable /disable the outputs by
  *       software and is reset in case of break or break2 event.
  * @note Macro IS_ATMR_BREAK_INSTANCE(ATMRx) can be used to check whether or not
  *       a timer instance provides a break input.
  * @param  ATMRx Timer instance
  * @retval None
  */
__STATIC_INLINE void DDL_ATMR_DisablePWMOutputs(ATMR_TypeDef *ATMRx)
{
  CLEAR_BIT(ATMRx->BDT, ATMR_BDT_MOEN);
}

/**
  * @brief  Indicates whether outputs are enabled.
  * @note Macro IS_ATMR_BREAK_INSTANCE(ATMRx) can be used to check whether or not
  *       a timer instance provides a break input.
  * @param  ATMRx Timer instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_ATMR_IsEnabledPWMOutputs(ATMR_TypeDef *ATMRx)
{
  return ((READ_BIT(ATMRx->BDT, ATMR_BDT_MOEN) == (ATMR_BDT_MOEN)) ? 1UL : 0UL);
}

/**
  * @}
  */

/** @defgroup ATMR_DDL_EF_Channel_Force_Output_CTRL Channel Force Output control
  * @{
  */
/**
  * @brief  Enable channels force output.
  * @param  ATMRx Timer instance(ATMR)
  * @param  Channels This parameter can be a combination of the following values:
  *         @arg @ref DDL_ATMR_FORCE_OUTPUT_CH0
  *         @arg @ref DDL_ATMR_FORCE_OUTPUT_CH0N
  *         @arg @ref DDL_ATMR_FORCE_OUTPUT_CH1
  *         @arg @ref DDL_ATMR_FORCE_OUTPUT_CH1N
  *         @arg @ref DDL_ATMR_FORCE_OUTPUT_CH2
  *         @arg @ref DDL_ATMR_FORCE_OUTPUT_CH2N
  *         @arg @ref DDL_ATMR_FORCE_OUTPUT_CH3
  *         @arg @ref DDL_ATMR_FORCE_OUTPUT_CH4
  * @retval None
  */
__STATIC_INLINE void DDL_ATMR_CHAN_EnableForceOutput(ATMR_TypeDef *ATMRx, uint32_t Channels)
{
  SET_BIT(ATMRx->OUTPUTCTRL1, ATMR_OUTPUTCTRL1_CH0_FORCE_EN << Channels);
}

/**
  * @brief  Disable channels force output.
  * @param  ATMRx Timer instance(ATMR)
  * @param  Channels This parameter can be a combination of the following values:
  *         @arg @ref DDL_ATMR_FORCE_OUTPUT_CH0
  *         @arg @ref DDL_ATMR_FORCE_OUTPUT_CH0N
  *         @arg @ref DDL_ATMR_FORCE_OUTPUT_CH1
  *         @arg @ref DDL_ATMR_FORCE_OUTPUT_CH1N
  *         @arg @ref DDL_ATMR_FORCE_OUTPUT_CH2
  *         @arg @ref DDL_ATMR_FORCE_OUTPUT_CH2N
  *         @arg @ref DDL_ATMR_FORCE_OUTPUT_CH3
  *         @arg @ref DDL_ATMR_FORCE_OUTPUT_CH4
  * @retval None
  */
__STATIC_INLINE void DDL_ATMR_CHAN_DisableForceOutput(ATMR_TypeDef *ATMRx, uint32_t Channels)
{
  CLEAR_BIT(ATMRx->OUTPUTCTRL1, ATMR_OUTPUTCTRL1_CH0_FORCE_EN << Channels);
}

/**
  * @brief  Indicate whether channel(s) force output is(are) enabled.
  * @param  ATMRx Timer instance(ATMR)
  * @param  Channels This parameter can be a combination of the following values:
  *         @arg @ref DDL_ATMR_FORCE_OUTPUT_CH0
  *         @arg @ref DDL_ATMR_FORCE_OUTPUT_CH0N
  *         @arg @ref DDL_ATMR_FORCE_OUTPUT_CH1
  *         @arg @ref DDL_ATMR_FORCE_OUTPUT_CH1N
  *         @arg @ref DDL_ATMR_FORCE_OUTPUT_CH2
  *         @arg @ref DDL_ATMR_FORCE_OUTPUT_CH2N
  *         @arg @ref DDL_ATMR_FORCE_OUTPUT_CH3
  *         @arg @ref DDL_ATMR_FORCE_OUTPUT_CH4
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_ATMR_CHAN_IsEnabledForceOutput(ATMR_TypeDef *ATMRx, uint32_t Channels)
{
  return ((READ_BIT(ATMRx->OUTPUTCTRL1, ATMR_OUTPUTCTRL1_CH0_FORCE_EN << Channels) == (ATMR_OUTPUTCTRL1_CH0_FORCE_EN << Channels)) ? 1UL : 0UL);
}

/**
  * @}
  */

/** @defgroup ATMR_DDL_EF_Output_Control_Buffering Output Control Buffering
  * @{
  */
/**
  * @brief  Enable output control buffering.
  * @param  ATMRx Timer instance(ATMR)
  * @retval None
  */
__STATIC_INLINE void DDL_ATMR_EnableOutputCtrlBuf(ATMR_TypeDef *ATMRx)
{
  SET_BIT(ATMRx->OUTPUTCTRL1, ATMR_OUTPUTCTRL1_OUTPUTCTRL_BUF);
}

/**
  * @brief  Disable output control buffering.
  * @param  ATMRx Timer instance(ATMR)
  * @retval None
  */
__STATIC_INLINE void DDL_ATMR_DisableOutputCtrlBuf(ATMR_TypeDef *ATMRx)
{
  CLEAR_BIT(ATMRx->OUTPUTCTRL1, ATMR_OUTPUTCTRL1_OUTPUTCTRL_BUF);
}

/**
  * @brief  Indicate whether output control buffering is enabled.
  * @param  ATMRx Timer instance(ATMR)
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_ATMR_IsEnabledOutputCtrlBuf(ATMR_TypeDef *ATMRx)
{
  return ((READ_BIT(ATMRx->OUTPUTCTRL1, ATMR_OUTPUTCTRL1_OUTPUTCTRL_BUF) == (ATMR_OUTPUTCTRL1_OUTPUTCTRL_BUF)) ? 1UL : 0UL);
}

/**
  * @}
  */

/** @defgroup ATMR_DDL_EF_Channel_Force_Output_Value Channel Force Output Value
  * @{
  */
/**
  * @brief  Set channels force output value.
  * @param  ATMRx Timer instance(ATMR)
  * @param  Channels This parameter can be a combination of the following values:
  *         @arg @ref DDL_ATMR_FORCE_OUTPUT_CH0
  *         @arg @ref DDL_ATMR_FORCE_OUTPUT_CH0N
  *         @arg @ref DDL_ATMR_FORCE_OUTPUT_CH1
  *         @arg @ref DDL_ATMR_FORCE_OUTPUT_CH1N
  *         @arg @ref DDL_ATMR_FORCE_OUTPUT_CH2
  *         @arg @ref DDL_ATMR_FORCE_OUTPUT_CH2N
  *         @arg @ref DDL_ATMR_FORCE_OUTPUT_CH3
  *         @arg @ref DDL_ATMR_FORCE_OUTPUT_CH4
  * @param  Value This parameter can be a combination of the following values:
  *         @arg @ref DDL_ATMR_FORCE_OUTPUT_LOW
  *         @arg @ref DDL_ATMR_FORCE_OUTPUT_HIGH
  * @retval None
  */
__STATIC_INLINE void DDL_ATMR_CHAN_SetForceOutputValue(ATMR_TypeDef *ATMRx, uint32_t Channels, uint32_t Value)
{
  MODIFY_REG(ATMRx->OUTPUTCTRL2, ATMR_OUTPUTCTRL2_CH0_FORCE_VALUE << Channels, Value << Channels);
}

/**
  * @brief  Get channels force output value.
  * @param  ATMRx Timer instance(ATMR)
  * @param  Channels This parameter can be a combination of the following values:
  *         @arg @ref DDL_ATMR_FORCE_OUTPUT_CH0
  *         @arg @ref DDL_ATMR_FORCE_OUTPUT_CH0N
  *         @arg @ref DDL_ATMR_FORCE_OUTPUT_CH1
  *         @arg @ref DDL_ATMR_FORCE_OUTPUT_CH1N
  *         @arg @ref DDL_ATMR_FORCE_OUTPUT_CH2
  *         @arg @ref DDL_ATMR_FORCE_OUTPUT_CH2N
  *         @arg @ref DDL_ATMR_FORCE_OUTPUT_CH3
  *         @arg @ref DDL_ATMR_FORCE_OUTPUT_CH4
  * @retval
  *         @arg @ref DDL_ATMR_FORCE_OUTPUT_LOW
  *         @arg @ref DDL_ATMR_FORCE_OUTPUT_HIGH
  */
__STATIC_INLINE uint32_t DDL_ATMR_CHAN_GetForceOutputValue(ATMR_TypeDef *ATMRx, uint32_t Channels)
{
  return (READ_BIT(ATMRx->OUTPUTCTRL2, ATMR_OUTPUTCTRL2_CH0_FORCE_VALUE << Channels) >> Channels);
}

/**
  * @}
  */

/** @defgroup ATMR_DDL_EF_TRGO_Mode triggle output configuration
  * @{
  */
/**
  * @brief  Set the trigger output (TRGO) configuration used for timer synchronization.
  * @param  ATMRx Timer instance(ATMR)
  * @param  TriggleMode This parameter can be one of the following values:
  *         @arg @ref DDL_ATMR_TRGO_RESET
  *         @arg @ref DDL_ATMR_TRGO_ENABLE
  *         @arg @ref DDL_ATMR_TRGO_UPDATE
  *         @arg @ref DDL_ATMR_TRGO_CCIF_EVENT
  *         @arg @ref DDL_ATMR_TRGO_OC0REF
  *         @arg @ref DDL_ATMR_TRGO_OC1REF
  *         @arg @ref DDL_ATMR_TRGO_OC2REF
  *         @arg @ref DDL_ATMR_TRGO_OC3REF
  *         @arg @ref DDL_ATMR_TRGO_OC4REF
  *         @arg @ref DDL_ATMR_TRGO_OC3UP_OC3DOWN
  *         @arg @ref DDL_ATMR_TRGO_OC4UP_OC4DOWN
  *         @arg @ref DDL_ATMR_TRGO_OC3UP_OC4UP
  *         @arg @ref DDL_ATMR_TRGO_OC3DOWN_OC4DOWN
  *         @arg @ref DDL_ATMR_TRGO_OC3UP_OC4DOWN
  *         @arg @ref DDL_ATMR_TRGO_OC3DOWN_OC4UP
  * @retval None
  */
__STATIC_INLINE void DDL_ATMR_SetTriggerOutputMode1(ATMR_TypeDef *ATMRx, uint32_t TriggleMode)
{
  MODIFY_REG(ATMRx->TRGOCR, ATMR_TRGOCR_MMS1, (TriggleMode << ATMR_TRGOCR_MMS1_Pos));
}

/**
  * @brief  Get trigger output(TRGO) configuration.
  * @param  ATMRx Timer instance(ATMR)
  * @retval Returned value can be one of the following values:
  *         @arg @ref DDL_ATMR_TRGO_RESET
  *         @arg @ref DDL_ATMR_TRGO_ENABLE
  *         @arg @ref DDL_ATMR_TRGO_UPDATE
  *         @arg @ref DDL_ATMR_TRGO_CCIF_EVENT
  *         @arg @ref DDL_ATMR_TRGO_OC0REF
  *         @arg @ref DDL_ATMR_TRGO_OC1REF
  *         @arg @ref DDL_ATMR_TRGO_OC2REF
  *         @arg @ref DDL_ATMR_TRGO_OC3REF
  *         @arg @ref DDL_ATMR_TRGO_OC4REF
  *         @arg @ref DDL_ATMR_TRGO_OC3UP_OC3DOWN
  *         @arg @ref DDL_ATMR_TRGO_OC4UP_OC4DOWN
  *         @arg @ref DDL_ATMR_TRGO_OC3UP_OC4UP
  *         @arg @ref DDL_ATMR_TRGO_OC3DOWN_OC4DOWN
  *         @arg @ref DDL_ATMR_TRGO_OC3UP_OC4DOWN
  *         @arg @ref DDL_ATMR_TRGO_OC3DOWN_OC4UP
  */
__STATIC_INLINE uint32_t DDL_ATMR_GetTriggerOutputMode1(ATMR_TypeDef *ATMRx)
{
  return (uint32_t)(READ_BIT(ATMRx->TRGOCR, ATMR_TRGOCR_MMS1) >> ATMR_TRGOCR_MMS1_Pos);
}

/**
  * @brief  Set the trigger output (TRGO) configuration used for timer synchronization.
  * @param  ATMRx Timer instance(ATMR)
  * @param  TriggleMode This parameter can be one of the following values:
  *         @arg @ref DDL_ATMR_TRGO_RESET
  *         @arg @ref DDL_ATMR_TRGO_ENABLE
  *         @arg @ref DDL_ATMR_TRGO_UPDATE
  *         @arg @ref DDL_ATMR_TRGO_CCIF_EVENT
  *         @arg @ref DDL_ATMR_TRGO_OC0REF
  *         @arg @ref DDL_ATMR_TRGO_OC1REF
  *         @arg @ref DDL_ATMR_TRGO_OC2REF
  *         @arg @ref DDL_ATMR_TRGO_OC3REF
  *         @arg @ref DDL_ATMR_TRGO_OC4REF
  *         @arg @ref DDL_ATMR_TRGO_OC3UP_OC3DOWN
  *         @arg @ref DDL_ATMR_TRGO_OC4UP_OC4DOWN
  *         @arg @ref DDL_ATMR_TRGO_OC3UP_OC4UP
  *         @arg @ref DDL_ATMR_TRGO_OC3DOWN_OC4DOWN
  *         @arg @ref DDL_ATMR_TRGO_OC3UP_OC4DOWN
  *         @arg @ref DDL_ATMR_TRGO_OC3DOWN_OC4UP
  * @retval None
  */
__STATIC_INLINE void DDL_ATMR_SetTriggerOutputMode2(ATMR_TypeDef *ATMRx, uint32_t TriggleMode)
{
  MODIFY_REG(ATMRx->TRGOCR, ATMR_TRGOCR_MMS2, (TriggleMode << ATMR_TRGOCR_MMS2_Pos));
}

/**
  * @brief  Get trigger output(TRGO) configuration.
  * @param  ATMRx Timer instance(ATMR)
  * @retval Returned value can be one of the following values:
  *         @arg @ref DDL_ATMR_TRGO_RESET
  *         @arg @ref DDL_ATMR_TRGO_ENABLE
  *         @arg @ref DDL_ATMR_TRGO_UPDATE
  *         @arg @ref DDL_ATMR_TRGO_CCIF_EVENT
  *         @arg @ref DDL_ATMR_TRGO_OC0REF
  *         @arg @ref DDL_ATMR_TRGO_OC1REF
  *         @arg @ref DDL_ATMR_TRGO_OC2REF
  *         @arg @ref DDL_ATMR_TRGO_OC3REF
  *         @arg @ref DDL_ATMR_TRGO_OC4REF
  *         @arg @ref DDL_ATMR_TRGO_OC3UP_OC3DOWN
  *         @arg @ref DDL_ATMR_TRGO_OC4UP_OC4DOWN
  *         @arg @ref DDL_ATMR_TRGO_OC3UP_OC4UP
  *         @arg @ref DDL_ATMR_TRGO_OC3DOWN_OC4DOWN
  *         @arg @ref DDL_ATMR_TRGO_OC3UP_OC4DOWN
  *         @arg @ref DDL_ATMR_TRGO_OC3DOWN_OC4UP
  */
__STATIC_INLINE uint32_t DDL_ATMR_GetTriggerOutputMode2(ATMR_TypeDef *ATMRx)
{
  return (uint32_t)(READ_BIT(ATMRx->TRGOCR, ATMR_TRGOCR_MMS2) >> ATMR_TRGOCR_MMS2_Pos);
}

/**
  * @}
  */


/** @defgroup ATMR_DDL_EF_BREAK_Filter BREAK Filter
  * @{
  */

/**
  * @brief  Enable analog break filter.
  * @param  ATMRx Timer instance(ATMR)
  * @retval None.
  */
__STATIC_INLINE void DDL_ATMR_EnableAnalogBrkFilter(ATMR_TypeDef *ATMRx)
{
  SET_BIT(ATMRx->BREAK, ATMR_BREAK_ANA_BRK_FILT_EN);
}

/**
  * @brief  Disable analog break filter.
  * @param  ATMRx Timer instance(ATMR)
  * @retval None.

  */
__STATIC_INLINE void DDL_ATMR_DisableAnalogBrkFilter(ATMR_TypeDef *ATMRx)
{
  CLEAR_BIT(ATMRx->BREAK, ATMR_BREAK_ANA_BRK_FILT_EN);
}

/**
  * @brief  Indicates whether analog break filter is enabled.
  * @param  ATMRx Timer instance(ATMR)
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_ATMR_IsEnabledAnalogBrkFilter(ATMR_TypeDef *ATMRx)
{
  return ((READ_BIT(ATMRx->BREAK, ATMR_BREAK_ANA_BRK_FILT_EN) == (ATMR_BREAK_ANA_BRK_FILT_EN)) ? 1UL : 0UL);
}

/**
  * @brief  Enable break filter.
  * @param  ATMRx Timer instance(ATMR)
  * @retval None.
  */
__STATIC_INLINE void DDL_ATMR_EnableBrkFilter(ATMR_TypeDef *ATMRx)
{
  SET_BIT(ATMRx->BREAK, ATMR_BREAK_BRK_FILT_EN);
}

/**
  * @brief  Disable break filter.
  * @param  ATMRx Timer instance(ATMR)
  * @retval None.
  */
__STATIC_INLINE void DDL_ATMR_DisableBrkFilter(ATMR_TypeDef *ATMRx)
{
  CLEAR_BIT(ATMRx->BREAK, ATMR_BREAK_BRK_FILT_EN);
}

/**
  * @brief  Indicates whether break filter is enabled.
  * @param  ATMRx Timer instance(ATMR)
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_ATMR_IsEnabledBrkFilter(ATMR_TypeDef *ATMRx)
{
  return ((READ_BIT(ATMRx->BREAK, ATMR_BREAK_BRK_FILT_EN) == (ATMR_BREAK_BRK_FILT_EN)) ? 1UL : 0UL);
}

/**
  * @brief  Set break filter coefficient.
  * @param  ATMRx Timer instance(ATMR)
  * @param  filter This parameter can be the value between 0x00000000 to 0x0000003F.
  * @retval None
  */
__STATIC_INLINE void DDL_ATMR_SetBrkFilter(ATMR_TypeDef *ATMRx, uint32_t filter)
{
  MODIFY_REG(ATMRx->BREAK, ATMR_BREAK_BRK_FILT, filter << ATMR_BREAK_BRK_FILT_Pos);
}

/**
  * @brief  Get break filter coefficient.
  * @param  ATMRx Timer instance(ATMR)
  * @retval Returned value between 0x00000000 to 0x0000003F.
  */
__STATIC_INLINE uint32_t DDL_ATMR_GetBrkFilter(ATMR_TypeDef *ATMRx)
{
  return (uint32_t)(READ_BIT(ATMRx->BREAK, ATMR_BREAK_BRK_FILT) >> ATMR_BREAK_BRK_FILT_Pos);
}

/**
  * @}
  */

/** @defgroup ATMR_DDL_EF_PWM_OUTPUT_MODE PWM output mode
  * @{
  */
/**
  * @brief  Enable asymmetric PWM output mode.
  * @param  ATMRx Timer instance(ATMR)
  * @param  Channel This value can be one of the following values:
  *         @arg @ref DDL_ATMR_PWMASYMMETRIC_OC0
  *         @arg @ref DDL_ATMR_PWMASYMMETRIC_OC1
  *         @arg @ref DDL_ATMR_PWMASYMMETRIC_OC2
  * @retval None.
  */
__STATIC_INLINE void DDL_ATMR_EnableAsymmetricPWMOutputMode(ATMR_TypeDef *ATMRx, uint32_t Channel)
{
  SET_BIT(ATMRx->OCXAEN, Channel);
}

/**
  * @brief  Disable asymmetric PWM output mode.
  * @param  ATMRx Timer instance(ATMR)
  * @param  Channel This value can be one of the following values:
  *         @arg @ref DDL_ATMR_PWMASYMMETRIC_OC0
  *         @arg @ref DDL_ATMR_PWMASYMMETRIC_OC1
  *         @arg @ref DDL_ATMR_PWMASYMMETRIC_OC2
  * @retval None.
  */
__STATIC_INLINE void DDL_ATMR_DisableAsymmetricPWMOutputMode(ATMR_TypeDef *ATMRx, uint32_t Channel)
{
  CLEAR_BIT(ATMRx->OCXAEN, Channel);
}

/**
  * @brief  Indicates whether break filter is enabled.
  * @param  ATMRx Timer instance(ATMR)
  * @param  Channel This value can be one of the following values:
  *         @arg @ref DDL_ATMR_PWMASYMMETRIC_OC1
  *         @arg @ref DDL_ATMR_PWMASYMMETRIC_OC2
  *         @arg @ref DDL_ATMR_PWMASYMMETRIC_OC3
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_ATMR_IsEnabledAsymmetricPWMOutputMode(ATMR_TypeDef *ATMRx, uint32_t Channel)
{
  return ((READ_BIT(ATMRx->OCXAEN, Channel) == (Channel)) ? 1UL : 0UL);
}
/**
  * @}
  */

/** @defgroup ATMR_DDL_EF_CHANNEL_COMPLEMENTARY channel complementary
  * @{
  */

/**
  * @brief  Set complementary value (ATMRx_CC0C) set for output channel 0.
  * @note Only be used in PWM output mode and center-aligned mode.
  * @param  ATMRx Timer instance
  * @param  Value between Min_Data=0 and Max_Data=65535
  * @retval None
  */
__STATIC_INLINE void DDL_ATMR_SetComplementaryCH0(ATMR_TypeDef *ATMRx, uint32_t Value)
{
  MODIFY_REG(ATMRx->CC0C, ATMR_CC0C_CC0C, Value);
}

/**
  * @brief  Get compare value (ATMRx_CC0C) set for  output channel 0.
  * @note Only be used in PWM output mode and center-aligned mode.
  * @param  ATMRx Timer instance
  * @retval CompareValue (between Min_Data=0 and Max_Data=65535)
  */
__STATIC_INLINE uint16_t DDL_ATMR_GetComplementaryCH0(ATMR_TypeDef *ATMRx)
{
  return (uint16_t)(READ_REG(ATMRx->CC0C));
}

/**
  * @brief  Set complementary value (ATMRx_CC1C) set for output channel 1.
  * @note Only be used in PWM output mode and center-aligned mode.
  * @param  ATMRx Timer instance
  * @param  Value between Min_Data=0 and Max_Data=65535
  * @retval None
  */
__STATIC_INLINE void DDL_ATMR_SetComplementaryCH1(ATMR_TypeDef *ATMRx, uint32_t Value)
{
  MODIFY_REG(ATMRx->CC1C, ATMR_CC1C_CC1C, Value);
}

/**
  * @brief  Get compare value (ATMRx_CC1C) set for  output channel 1.
  * @note Only be used in PWM output mode and center-aligned mode.
  * @param  ATMRx Timer instance
  * @retval CompareValue (between Min_Data=0 and Max_Data=65535)
  */
__STATIC_INLINE uint16_t DDL_ATMR_GetComplementaryCH1(ATMR_TypeDef *ATMRx)
{
  return (uint16_t)(READ_REG(ATMRx->CC1C));
}

/**
  * @brief  Set complementary value (ATMRx_CC2) set for output channel 2.
  * @note Only be used in PWM output mode and center-aligned mode.
  * @param  ATMRx Timer instance
  * @param  Value between Min_Data=0 and Max_Data=65535
  * @retval None
  */
__STATIC_INLINE void DDL_ATMR_SetComplementaryCH2(ATMR_TypeDef *ATMRx, uint32_t Value)
{
  MODIFY_REG(ATMRx->CC2C, ATMR_CC2C_CC2C, Value);
}

/**
  * @brief  Get compare value (ATMRx_CC2C) set for output channel 2.
  * @note Only be used in PWM output mode and center-aligned mode.
  * @param  ATMRx Timer instance
  * @retval CompareValue (between Min_Data=0 and Max_Data=65535)
  */
__STATIC_INLINE uint16_t DDL_ATMR_GetComplementaryCH2(ATMR_TypeDef *ATMRx)
{
  return (uint16_t)(READ_REG(ATMRx->CC2C));
}

/**
  * @}
  */

/** @defgroup ATMR_DDL_EF_FLAG_Management FLAG-Management
  * @{
  */
/**
  * @brief  Clear the update interrupt flag (UIF).
  * @param  ATMRx Timer instance
  * @retval None
  */
__STATIC_INLINE void DDL_ATMR_ClearFlag_UPDATE(ATMR_TypeDef *ATMRx)
{
  WRITE_REG(ATMRx->STS, ~(ATMR_STS_UIFLG));
}

/**
  * @brief  Clear the Capture/Compare 0 interrupt flag (CC0F).
  * @param  ATMRx Timer instance
  * @retval None
  */
__STATIC_INLINE void DDL_ATMR_ClearFlag_CC0(ATMR_TypeDef *ATMRx)
{
  WRITE_REG(ATMRx->STS, ~(ATMR_STS_CC0IFLG));
}

/**
  * @brief  Indicate whether Capture/Compare 0 interrupt flag (CC0F) is set (Capture/Compare 0 interrupt is pending).
  * @param  ATMRx Timer instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_ATMR_IsActiveFlag_CC0(ATMR_TypeDef *ATMRx)
{
  return ((READ_BIT(ATMRx->STS, ATMR_STS_CC0IFLG) == (ATMR_STS_CC0IFLG)) ? 1UL : 0UL);
}

/**
  * @brief  Indicate whether update interrupt flag (UIF) is set (update interrupt is pending).
  * @param  ATMRx Timer instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_ATMR_IsActiveFlag_UPDATE(ATMR_TypeDef *ATMRx)
{
  return ((READ_BIT(ATMRx->STS, ATMR_STS_UIFLG) == (ATMR_STS_UIFLG)) ? 1UL : 0UL);
}

/**
  * @brief  Clear the Capture/Compare 1 interrupt flag (CC1F).
  * @param  ATMRx Timer instance
  * @retval None
  */
__STATIC_INLINE void DDL_ATMR_ClearFlag_CC1(ATMR_TypeDef *ATMRx)
{
  WRITE_REG(ATMRx->STS, ~(ATMR_STS_CC1IFLG));
}

/**
  * @brief  Indicate whether Capture/Compare 1 interrupt flag (CC1F) is set (Capture/Compare 1 interrupt is pending).
  * @param  ATMRx Timer instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_ATMR_IsActiveFlag_CC1(ATMR_TypeDef *ATMRx)
{
  return ((READ_BIT(ATMRx->STS, ATMR_STS_CC1IFLG) == (ATMR_STS_CC1IFLG)) ? 1UL : 0UL);
}

/**
  * @brief  Clear the Capture/Compare 1 interrupt flag (CC2F).
  * @param  ATMRx Timer instance
  * @retval None
  */
__STATIC_INLINE void DDL_ATMR_ClearFlag_CC2(ATMR_TypeDef *ATMRx)
{
  WRITE_REG(ATMRx->STS, ~(ATMR_STS_CC2IFLG));
}

/**
  * @brief  Indicate whether Capture/Compare 2 interrupt flag (CC2F) is set (Capture/Compare 2 interrupt is pending).
  * @param  ATMRx Timer instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_ATMR_IsActiveFlag_CC2(ATMR_TypeDef *ATMRx)
{
  return ((READ_BIT(ATMRx->STS, ATMR_STS_CC2IFLG) == (ATMR_STS_CC2IFLG)) ? 1UL : 0UL);
}

/**
  * @brief  Clear the Capture/Compare 3 interrupt flag (CC3F).
  * @param  ATMRx Timer instance
  * @retval None
  */
__STATIC_INLINE void DDL_ATMR_ClearFlag_CC3(ATMR_TypeDef *ATMRx)
{
  WRITE_REG(ATMRx->STS, ~(ATMR_STS_CC3IFLG));
}

/**
  * @brief  Indicate whether Capture/Compare 3 interrupt flag (CC3F) is set (Capture/Compare 3 interrupt is pending).
  * @param  ATMRx Timer instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_ATMR_IsActiveFlag_CC3(ATMR_TypeDef *ATMRx)
{
  return ((READ_BIT(ATMRx->STS, ATMR_STS_CC3IFLG) == (ATMR_STS_CC3IFLG)) ? 1UL : 0UL);
}

/**
  * @brief  Clear the Capture/Compare 4 interrupt flag (CC4F).
  * @param  ATMRx Timer instance
  * @retval None
  */
__STATIC_INLINE void DDL_ATMR_ClearFlag_CC4(ATMR_TypeDef *ATMRx)
{
  WRITE_REG(ATMRx->STS, ~(ATMR_STS_CC4IFLG));
}

/**
  * @brief  Indicate whether Capture/Compare 4 interrupt flag (CC4F) is set (Capture/Compare 4 interrupt is pending).
  * @param  ATMRx Timer instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_ATMR_IsActiveFlag_CC4(ATMR_TypeDef *ATMRx)
{
  return ((READ_BIT(ATMRx->STS, ATMR_STS_CC4IFLG) == (ATMR_STS_CC4IFLG)) ? 1UL : 0UL);
}

/**
  * @brief  Clear the commutation interrupt flag (COMIF).
  * @param  ATMRx Timer instance
  * @retval None
  */
__STATIC_INLINE void DDL_ATMR_ClearFlag_COM(ATMR_TypeDef *ATMRx)
{
  WRITE_REG(ATMRx->STS, ~(ATMR_STS_COMIFLG));
}

/**
  * @brief  Indicate whether commutation interrupt flag (COMIF) is set (commutation interrupt is pending).
  * @param  ATMRx Timer instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_ATMR_IsActiveFlag_COM(ATMR_TypeDef *ATMRx)
{
  return ((READ_BIT(ATMRx->STS, ATMR_STS_COMIFLG) == (ATMR_STS_COMIFLG)) ? 1UL : 0UL);
}

/**
  * @brief  Clear the trigger interrupt flag (TIF).
  * @param  ATMRx Timer instance
  * @retval None
  */
__STATIC_INLINE void DDL_ATMR_ClearFlag_TRIG(ATMR_TypeDef *ATMRx)
{
  WRITE_REG(ATMRx->STS, ~(ATMR_STS_TRGIFLG));
}

/**
  * @brief  Indicate whether trigger interrupt flag (TIF) is set (trigger interrupt is pending).
  * @param  ATMRx Timer instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_ATMR_IsActiveFlag_TRIG(ATMR_TypeDef *ATMRx)
{
  return ((READ_BIT(ATMRx->STS, ATMR_STS_TRGIFLG) == (ATMR_STS_TRGIFLG)) ? 1UL : 0UL);
}

/**
  * @brief  Clear the break interrupt flag (BIF).
  * @param  ATMRx Timer instance
  * @retval None
  */
__STATIC_INLINE void DDL_ATMR_ClearFlag_BRK(ATMR_TypeDef *ATMRx)
{
  WRITE_REG(ATMRx->STS, ~(ATMR_STS_BRKIFLG));
}

/**
  * @brief  Indicate whether break interrupt flag (BIF) is set (break interrupt is pending).
  * @param  ATMRx Timer instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_ATMR_IsActiveFlag_BRK(ATMR_TypeDef *ATMRx)
{
  return ((READ_BIT(ATMRx->STS, ATMR_STS_BRKIFLG) == (ATMR_STS_BRKIFLG)) ? 1UL : 0UL);
}

/**
  * @}
  */

/** @defgroup ATMR_DDL_EF_IT_Management IT-Management
  * @{
  */
/**
  * @brief  Enable update interrupt (UIE).
  * @param  ATMRx Timer instance
  * @retval None
  */
__STATIC_INLINE void DDL_ATMR_EnableIT_UPDATE(ATMR_TypeDef *ATMRx)
{
  SET_BIT(ATMRx->DIEN, ATMR_DIEN_UIEN);
}

/**
  * @brief  Disable update interrupt (UIE).
  * @param  ATMRx Timer instance
  * @retval None
  */
__STATIC_INLINE void DDL_ATMR_DisableIT_UPDATE(ATMR_TypeDef *ATMRx)
{
  CLEAR_BIT(ATMRx->DIEN, ATMR_DIEN_UIEN);
}

/**
  * @brief  Indicates whether the update interrupt (UIE) is enabled.
  * @param  ATMRx Timer instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_ATMR_IsEnabledIT_UPDATE(ATMR_TypeDef *ATMRx)
{
  return ((READ_BIT(ATMRx->DIEN, ATMR_DIEN_UIEN) == (ATMR_DIEN_UIEN)) ? 1UL : 0UL);
}

/**
  * @brief  Enable capture/compare 0 interrupt (CC0IE).
  * @param  ATMRx Timer instance
  * @retval None
  */
__STATIC_INLINE void DDL_ATMR_EnableIT_CC0(ATMR_TypeDef *ATMRx)
{
  SET_BIT(ATMRx->DIEN, ATMR_DIEN_CC0IEN);
}

/**
  * @brief  Disable capture/compare 0 interrupt (CC0IE).
  * @param  ATMRx Timer instance
  * @retval None
  */
__STATIC_INLINE void DDL_ATMR_DisableIT_CC0(ATMR_TypeDef *ATMRx)
{
  CLEAR_BIT(ATMRx->DIEN, ATMR_DIEN_CC0IEN);
}

/**
  * @brief  Indicates whether the capture/compare 0 interrupt (CC0IE) is enabled.
  * @param  ATMRx Timer instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_ATMR_IsEnabledIT_CC0(ATMR_TypeDef *ATMRx)
{
  return ((READ_BIT(ATMRx->DIEN, ATMR_DIEN_CC0IEN) == (ATMR_DIEN_CC0IEN)) ? 1UL : 0UL);
}

/**
  * @brief  Enable capture/compare 1 interrupt (CC1IE).
  * @param  ATMRx Timer instance
  * @retval None
  */
__STATIC_INLINE void DDL_ATMR_EnableIT_CC1(ATMR_TypeDef *ATMRx)
{
  SET_BIT(ATMRx->DIEN, ATMR_DIEN_CC1IEN);
}

/**
  * @brief  Disable capture/compare 1 interrupt (CC1IE).
  * @param  ATMRx Timer instance
  * @retval None
  */
__STATIC_INLINE void DDL_ATMR_DisableIT_CC1(ATMR_TypeDef *ATMRx)
{
  CLEAR_BIT(ATMRx->DIEN, ATMR_DIEN_CC1IEN);
}

/**
  * @brief  Indicates whether the capture/compare 1 interrupt (CC1IE) is enabled.
  * @param  ATMRx Timer instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_ATMR_IsEnabledIT_CC1(ATMR_TypeDef *ATMRx)
{
  return ((READ_BIT(ATMRx->DIEN, ATMR_DIEN_CC1IEN) == (ATMR_DIEN_CC1IEN)) ? 1UL : 0UL);
}

/**
  * @brief  Enable capture/compare 2 interrupt (CC2IE).
  * @param  ATMRx Timer instance
  * @retval None
  */
__STATIC_INLINE void DDL_ATMR_EnableIT_CC2(ATMR_TypeDef *ATMRx)
{
  SET_BIT(ATMRx->DIEN, ATMR_DIEN_CC2IEN);
}

/**
  * @brief  Disable capture/compare 2 interrupt (CC2IE).
  * @param  ATMRx Timer instance
  * @retval None
  */
__STATIC_INLINE void DDL_ATMR_DisableIT_CC2(ATMR_TypeDef *ATMRx)
{
  CLEAR_BIT(ATMRx->DIEN, ATMR_DIEN_CC2IEN);
}

/**
  * @brief  Indicates whether the capture/compare 2 interrupt (CC2IE) is enabled.
  * @param  ATMRx Timer instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_ATMR_IsEnabledIT_CC2(ATMR_TypeDef *ATMRx)
{
  return ((READ_BIT(ATMRx->DIEN, ATMR_DIEN_CC2IEN) == (ATMR_DIEN_CC2IEN)) ? 1UL : 0UL);
}

/**
  * @brief  Enable capture/compare 3 interrupt (CC3IE).
  * @param  ATMRx Timer instance
  * @retval None
  */
__STATIC_INLINE void DDL_ATMR_EnableIT_CC3(ATMR_TypeDef *ATMRx)
{
  SET_BIT(ATMRx->DIEN, ATMR_DIEN_CC3IEN);
}

/**
  * @brief  Disable capture/compare 3 interrupt (CC3IE).
  * @param  ATMRx Timer instance
  * @retval None
  */
__STATIC_INLINE void DDL_ATMR_DisableIT_CC3(ATMR_TypeDef *ATMRx)
{
  CLEAR_BIT(ATMRx->DIEN, ATMR_DIEN_CC3IEN);
}

/**
  * @brief  Indicates whether the capture/compare 3 interrupt (CC3IE) is enabled.
  * @param  ATMRx Timer instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_ATMR_IsEnabledIT_CC3(ATMR_TypeDef *ATMRx)
{
  return ((READ_BIT(ATMRx->DIEN, ATMR_DIEN_CC3IEN) == (ATMR_DIEN_CC3IEN)) ? 1UL : 0UL);
}

/**
  * @brief  Enable commutation interrupt (COMIE).
  * @param  ATMRx Timer instance
  * @retval None
  */
__STATIC_INLINE void DDL_ATMR_EnableIT_COM(ATMR_TypeDef *ATMRx)
{
  SET_BIT(ATMRx->DIEN, ATMR_DIEN_COMIEN);
}

/**
  * @brief  Disable commutation interrupt (COMIE).
  * @param  ATMRx Timer instance
  * @retval None
  */
__STATIC_INLINE void DDL_ATMR_DisableIT_COM(ATMR_TypeDef *ATMRx)
{
  CLEAR_BIT(ATMRx->DIEN, ATMR_DIEN_COMIEN);
}

/**
  * @brief  Indicates whether the commutation interrupt (COMIE) is enabled.
  * @param  ATMRx Timer instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_ATMR_IsEnabledIT_COM(ATMR_TypeDef *ATMRx)
{
  return ((READ_BIT(ATMRx->DIEN, ATMR_DIEN_COMIEN) == (ATMR_DIEN_COMIEN)) ? 1UL : 0UL);
}

/**
  * @brief  Enable trigger interrupt (TIE).
  * @param  ATMRx Timer instance
  * @retval None
  */
__STATIC_INLINE void DDL_ATMR_EnableIT_TRIG(ATMR_TypeDef *ATMRx)
{
  SET_BIT(ATMRx->DIEN, ATMR_DIEN_TRGIEN);
}

/**
  * @brief  Disable trigger interrupt (TIE).
  * @param  ATMRx Timer instance
  * @retval None
  */
__STATIC_INLINE void DDL_ATMR_DisableIT_TRIG(ATMR_TypeDef *ATMRx)
{
  CLEAR_BIT(ATMRx->DIEN, ATMR_DIEN_TRGIEN);
}

/**
  * @brief  Indicates whether the trigger interrupt (TIE) is enabled.
  * @param  ATMRx Timer instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_ATMR_IsEnabledIT_TRIG(ATMR_TypeDef *ATMRx)
{
  return ((READ_BIT(ATMRx->DIEN, ATMR_DIEN_TRGIEN) == (ATMR_DIEN_TRGIEN)) ? 1UL : 0UL);
}

/**
  * @brief  Enable break interrupt (BIE).
  * @param  ATMRx Timer instance
  * @retval None
  */
__STATIC_INLINE void DDL_ATMR_EnableIT_BRK(ATMR_TypeDef *ATMRx)
{
  SET_BIT(ATMRx->DIEN, ATMR_DIEN_BRKIEN);
}

/**
  * @brief  Disable break interrupt (BIE).
  * @param  ATMRx Timer instance
  * @retval None
  */
__STATIC_INLINE void DDL_ATMR_DisableIT_BRK(ATMR_TypeDef *ATMRx)
{
  CLEAR_BIT(ATMRx->DIEN, ATMR_DIEN_BRKIEN);
}

/**
  * @brief  Indicates whether the break interrupt (BIE) is enabled.
  * @param  ATMRx Timer instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_ATMR_IsEnabledIT_BRK(ATMR_TypeDef *ATMRx)
{
  return ((READ_BIT(ATMRx->DIEN, ATMR_DIEN_BRKIEN) == (ATMR_DIEN_BRKIEN)) ? 1UL : 0UL);
}

/**
  * @}
  */

/** @defgroup ATMR_DDL_EF_EVENT_Management EVENT-Management
  * @{
  */
/**
  * @brief  Generate an update event.
  * @param  ATMRx Timer instance
  * @retval None
  */
__STATIC_INLINE void DDL_ATMR_GenerateEvent_UPDATE(ATMR_TypeDef *ATMRx)
{
  WRITE_REG(ATMRx->CEG, ATMR_CEG_UEG);
}

/**
  * @brief  Generate Capture/Compare 0 event.
  * @param  ATMRx Timer instance
  * @retval None
  */
__STATIC_INLINE void DDL_ATMR_GenerateEvent_CC0(ATMR_TypeDef *ATMRx)
{
  WRITE_REG(ATMRx->CEG, ATMR_CEG_CC0EG);
}

/**
  * @brief  Generate Capture/Compare 1 event.
  * @param  ATMRx Timer instance
  * @retval None
  */
__STATIC_INLINE void DDL_ATMR_GenerateEvent_CC1(ATMR_TypeDef *ATMRx)
{
  WRITE_REG(ATMRx->CEG, ATMR_CEG_CC1EG);
}

/**
  * @brief  Generate Capture/Compare 2 event.
  * @param  ATMRx Timer instance
  * @retval None
  */
__STATIC_INLINE void DDL_ATMR_GenerateEvent_CC2(ATMR_TypeDef *ATMRx)
{
  WRITE_REG(ATMRx->CEG, ATMR_CEG_CC2EG);
}

/**
  * @brief  Generate Capture/Compare 3 event.
  * @param  ATMRx Timer instance
  * @retval None
  */
__STATIC_INLINE void DDL_ATMR_GenerateEvent_CC3(ATMR_TypeDef *ATMRx)
{
  WRITE_REG(ATMRx->CEG, ATMR_CEG_CC3EG);
}

/**
  * @brief  Generate Capture/Compare 4 event.
  * @param  TMRx Timer instance(ATMR)
  * @retval None
  */
__STATIC_INLINE void DDL_ATMR_GenerateEvent_CC4(ATMR_TypeDef *ATMRx)
{
  SET_BIT(ATMRx->CH4CFG, ATMR_CH4CFG_CC4G);
}

/**
  * @brief  Generate commutation event.
  * @param  ATMRx Timer instance
  * @retval None
  */
__STATIC_INLINE void DDL_ATMR_GenerateEvent_COM(ATMR_TypeDef *ATMRx)
{
  WRITE_REG(ATMRx->CEG, ATMR_CEG_COMG);
}

/**
  * @brief  Generate trigger event.
  * @param  ATMRx Timer instance
  * @retval None
  */
__STATIC_INLINE void DDL_ATMR_GenerateEvent_TRIG(ATMR_TypeDef *ATMRx)
{
  WRITE_REG(ATMRx->CEG, ATMR_CEG_TEG);
}

/**
  * @brief  Generate break event.
  * @param  ATMRx Timer instance
  * @retval None
  */
__STATIC_INLINE void DDL_ATMR_GenerateEvent_BRK(ATMR_TypeDef *ATMRx)
{
  WRITE_REG(ATMRx->CEG, ATMR_CEG_BEG);
}

/**
  * @}
  */


#if defined(USE_FULL_DDL_DRIVER)
/** @defgroup ATMR_DDL_EF_Init Initialisation and deinitialisation functions
  * @{
  */

ErrorStatus DDL_ATMR_DeInit(ATMR_TypeDef *ATMRx);
void DDL_ATMR_StructInit(DDL_ATMR_InitTypeDef *ATMR_InitStruct);
ErrorStatus DDL_ATMR_Init(ATMR_TypeDef *ATMRx, DDL_ATMR_InitTypeDef *ATMR_InitStruct);
void DDL_ATMR_OC_StructInit(DDL_ATMR_OC_InitTypeDef *ATMR_OC_InitStruct);
ErrorStatus DDL_ATMR_OC_Init(ATMR_TypeDef *ATMRx, uint32_t Channel, DDL_ATMR_OC_InitTypeDef *ATMR_OC_InitStruct);
void DDL_ATMR_BDT_StructInit(DDL_ATMR_BDT_InitTypeDef *ATMR_BDTInitStruct);
ErrorStatus DDL_ATMR_BDT_Init(ATMR_TypeDef *ATMRx, DDL_ATMR_BDT_InitTypeDef *ATMR_BDTInitStruct);
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

#endif /* ATMR */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* G32M3101_DDL_ATMR_H */
