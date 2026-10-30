/**
  *
  * @file        g32m3101_ddl_btmr.h
  *
  * @brief       Header file of BTMR DDL module.
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
#ifndef G32M3101_DDL_BTMR_H
#define G32M3101_DDL_BTMR_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "g32m3xxx.h"
#include "Legacy/g32_ddl_legacy.h"

/** @addtogroup G32M3101_DDL_Driver
  * @{
  */

#if defined (BTMR)

/** @defgroup BTMR_DDL BTMR
  * @{
  */

/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/** @defgroup BTMR_DDL_Private_Variables BTMR Private Variables
  * @{
  */
static const uint8_t SHIFT_TAB_BTMR_CCxsel[] =
{
  (BTMR_CCM2_CC0_IOSEL_Pos-BTMR_CCM2_CC0_IOSEL_Pos),            /* 0: OC0_IOSEL */
  (BTMR_CCM2_CC1_IOSEL_Pos-BTMR_CCM2_CC0_IOSEL_Pos),            /* 1: OC1_IOSEL */
  (BTMR_CCM2_CC2_IOSEL_Pos-BTMR_CCM2_CC0_IOSEL_Pos),            /* 2: OC2_IOSEL */
};

static const uint8_t SHIFT_TAB_BTMR_OCxx[] =
{
  (BTMR_CCM1_CC0POL_Pos-BTMR_CCM1_CC0POL_Pos),           /* 0 : CC0EN CC0POL CC0_EDGE_SEL IC0F OC0MOD */
  (BTMR_CCM1_CC1POL_Pos-BTMR_CCM1_CC0POL_Pos),           /* 10: CC1EN CC1POL CC1_EDGE_SEL IC1F OC1MOD */
  (BTMR_CCM1_CC2POL_Pos-BTMR_CCM1_CC0POL_Pos),           /* 20: CC2EN CC2POL CC2_EDGE_SEL IC2F OC2MOD */
};
/**
  * @}
  */


/* Private constants ---------------------------------------------------------*/


/* Private macros ------------------------------------------------------------*/
/** @defgroup BTMR_DDL_Private_Macros BTMR Private Macros
  * @{
  */
/** @brief  Convert channel id into channel index.
  * @param  __CHANNEL__ This parameter can be one of the following values:
  *         @arg @ref DDL_BTMR_CHANNEL_CH0
  *         @arg @ref DDL_BTMR_CHANNEL_CH1
  *         @arg @ref DDL_BTMR_CHANNEL_CH2
  * @retval none
  */
#define BTMR_GET_CHANNEL_INDEX( __CHANNEL__) \
  (((__CHANNEL__) == DDL_BTMR_CHANNEL_CH0) ? 0U :\
   ((__CHANNEL__) == DDL_BTMR_CHANNEL_CH1) ? 1U :\
   ((__CHANNEL__) == DDL_BTMR_CHANNEL_CH2) ? 2U : 3U)

/**
  * @}
  */


/* Exported types ------------------------------------------------------------*/
#if defined(USE_FULL_DDL_DRIVER)
/** @defgroup BTMR_DDL_ES_INIT BTMR Exported Init structure
  * @{
  */

/**
  * @brief  BTMR Time Base configuration structure definition.
  */
typedef struct
{
  uint16_t Prescaler;         /*!< Specifies the prescaler value used to divide the BTMR clock.
                                   This parameter can be a number between Min_Data=0x0000 and Max_Data=0xFFFF.

                                   This feature can be modified afterwards using unitary function
                                   @ref DDL_BTMR_SetPrescaler().*/

  uint32_t CounterMode;       /*!< Specifies the counter mode.
                                   This parameter can be a value of @ref BTMR_DDL_EC_COUNTERMODE.

                                   This feature can be modified afterwards using unitary function
                                   @ref DDL_BTMR_SetCounterMode().*/

  uint32_t Autoreload;        /*!< Specifies the auto reload value to be loaded into the active
                                   Auto-Reload Register at the next update event.
                                   This parameter must be a number between Min_Data=0x0000 and Max_Data=0xFFFF.
                                   Some timer instances may support 32 bits counters. In that case this parameter must
                                   be a number between 0x0000 and 0xFFFFFFFF.

                                   This feature can be modified afterwards using unitary function
                                   @ref DDL_BTMR_SetAutoReload().*/

} DDL_BTMR_InitTypeDef;

/**
  * @brief  BTMR Output Compare configuration structure definition.
  */
typedef struct
{
  uint32_t OCMode;        /*!< Specifies the output mode.
                               This parameter can be a value of @ref BTMR_DDL_EC_OCMODE.

                               This feature can be modified afterwards using unitary function
                               @ref DDL_BTMR_OC_SetMode().*/

  uint32_t OCState;       /*!< Specifies the BTMR Output Compare state.
                               This parameter can be a value of @ref BTMR_DDL_EC_OCSTATE.

                               This feature can be modified afterwards using unitary functions
                               @ref DDL_BTMR_CC_EnableChannel() or @ref DDL_BTMR_CC_DisableChannel().*/

  uint32_t CompareValue;  /*!< Specifies the Compare value to be loaded into the Capture Compare Register.
                               This parameter can be a number between Min_Data=0x0000 and Max_Data=0xFFFF.

                               This feature can be modified afterwards using unitary function
                               DDL_BTMR_OC_SetCompareCHx (x=1..6).*/

  uint32_t OCPolarity;    /*!< Specifies the output polarity.
                               This parameter can be a value of @ref BTMR_DDL_EC_POLARITY.

                               This feature can be modified afterwards using unitary function
                               @ref DDL_BTMR_OC_SetPolarity().*/

} DDL_BTMR_OC_InitTypeDef;

/**
  * @brief  BTMR Input Capture configuration structure definition.
  */

typedef struct
{

  uint32_t ICPolarity;    /*!< Specifies the active edge of the input signal.
                               This parameter can be a value of @ref BTMR_DDL_EC_POLARITY.

                               This feature can be modified afterwards using unitary function
                               @ref DDL_BTMR_IC_SetPolarity().*/

  uint32_t ICEdge;       /*!< Specifies the active edge of the input signal.
                               This parameter can be a value of @ref BTMR_DDL_EC_IC_EDGE.

                               This feature can be modified afterwards using unitary function
                               @ref DDL_BTMR_IC_SetEdge().*/

  uint32_t ICFilter;      /*!< Specifies the input capture filter.
                               This parameter can be a value of @ref BTMR_DDL_EC_IC_FILTER.

                               This feature can be modified afterwards using unitary function
                               @ref DDL_BTMR_IC_SetFilter().*/
} DDL_BTMR_IC_InitTypeDef;

/**
  * @}
  */
#endif /* USE_FULL_DDL_DRIVER */

/* Exported constants --------------------------------------------------------*/
/** @defgroup BTMR_DDL_Exported_Constants BTMR Exported Constants
  * @{
  */

/** @defgroup BTMR_DDL_EC_GET_FLAG Get Flags Defines
  * @brief    Flags defines which can be used with DDL_BTMR_ReadReg function.
  * @{
  */
#define DDL_BTMR_STS_UIFLG                          BTMR_STS_UIFLG           /*!< Update interrupt flag */
#define DDL_BTMR_STS_CC0IFLG                        BTMR_STS_CC0IFLG         /*!< Capture/compare 0 interrupt flag */
#define DDL_BTMR_STS_CC1IFLG                        BTMR_STS_CC1IFLG         /*!< Capture/compare 1 interrupt flag */
#define DDL_BTMR_STS_CC2IFLG                        BTMR_STS_CC2IFLG         /*!< Capture/compare 2 interrupt flag */
#define DDL_BTMR_STS_CC0RCFLG                       BTMR_STS_CC0RCFLG        /*!< Capture/Compare 0 overcapture flag */
#define DDL_BTMR_STS_CC1RCFLG                       BTMR_STS_CC1RCFLG        /*!< Capture/Compare 1 overcapture flag */
#define DDL_BTMR_STS_CC2RCFLG                       BTMR_STS_CC2RCFLG        /*!< Capture/Compare 2 overcapture flag */

/**
  * @}
  */

/** @defgroup BTMR_DDL_EC_IT IT Defines
  * @brief    IT defines which can be used with DDL_BTMR_ReadReg and  DDL_BTMR_WriteReg functions.
  * @{
  */
#define DDL_BTMR_DIEN_UIEN                        BTMR_IEN_UIEN         /*!< Update interrupt enable */
#define DDL_BTMR_DIEN_CC0IEN                      BTMR_IEN_CC0IEN       /*!< Capture/compare 0 interrupt enable */
#define DDL_BTMR_DIEN_CC1IEN                      BTMR_IEN_CC1IEN       /*!< Capture/compare 1 interrupt enable */
#define DDL_BTMR_DIEN_CC2IEN                      BTMR_IEN_CC2IEN       /*!< Capture/compare 2 interrupt enable */
/**
  * @}
  */

/** @defgroup BTMR_DDL_EC_ONEPULSEMODE One Pulse Mode
  * @{
  */
#define DDL_BTMR_ONEPULSEMODE_SINGLE             BTMR_CTRL1_SPMEN          /*!< Counter stops counting at the next update event */
#define DDL_BTMR_ONEPULSEMODE_REPETITIVE         0x00000000U               /*!< Counter is not stopped at update event */
/**
  * @}
  */

/** @defgroup BTMR_DDL_EC_COUNTERMODE Counter Mode
  * @{
  */
#define DDL_BTMR_COUNTERMODE_UP                  0x00000000U                /*!<Counter used as upcounter */
#define DDL_BTMR_COUNTERMODE_DOWN                BTMR_CTRL1_CNTDIR          /*!< Counter used as downcounter */
#define DDL_BTMR_COUNTERMODE_CENTER_DOWN         BTMR_CTRL1_CAMSEL_0        /*!< The counter counts up and down alternatively. Output compare interrupt flags of output channels  are set only when the counter is counting down. */
#define DDL_BTMR_COUNTERMODE_CENTER_UP           BTMR_CTRL1_CAMSEL_1        /*!<The counter counts up and down alternatively. Output compare interrupt flags of output channels  are set only when the counter is counting up */
#define DDL_BTMR_COUNTERMODE_CENTER_UP_DOWN      BTMR_CTRL1_CAMSEL          /*!< The counter counts up and down alternatively. Output compare interrupt flags of output channels  are set only when the counter is counting up or down. */
/**
  * @}
  */

/** @defgroup BTMR_DDL_EC_COUNTERDIRECTION Counter Direction
  * @{
  */
#define DDL_BTMR_COUNTERDIRECTION_UP             0x00000000U                /*!< Timer counter counts up */
#define DDL_BTMR_COUNTERDIRECTION_DOWN           BTMR_CTRL1_CNTDIR          /*!< Timer counter counts down */
/**
  * @}
  */

/** @defgroup BTMR_DDL_EC_CHANNEL Channel
  * @{
  */
#define DDL_BTMR_CHANNEL_CH0                     BTMR_CCM1_CC0EN     /*!< Timer input/output channel 0 */
#define DDL_BTMR_CHANNEL_CH1                     BTMR_CCM1_CC1EN     /*!< Timer input/output channel 1 */
#define DDL_BTMR_CHANNEL_CH2                     BTMR_CCM1_CC2EN     /*!< Timer input/output channel 2 */
/**
  * @}
  */

#if defined(USE_FULL_DDL_DRIVER)
/** @defgroup BTMR_DDL_EC_OCSTATE Output Configuration State
  * @{
  */
#define DDL_BTMR_OCSTATE_DISABLE                 0x00000000U             /*!< OCx is not active */
#define DDL_BTMR_OCSTATE_ENABLE                  BTMR_CCM1_CC0EN         /*!< OCx signal is output on the corresponding output pin */
/**
  * @}
  */
#endif /* USE_FULL_DDL_DRIVER */

/** @defgroup BTMR_DDL_EC_OCMODE Output Configuration Mode
  * @{
  */
#define DDL_BTMR_OCMODE_FROZEN                   0x00000000U                                                    /*!<The comparison between the output compare register BTMRx_CCRy and the counter BTMRx_CNT has no effect on the output channel level */
#define DDL_BTMR_OCMODE_ACTIVE                   BTMR_CCM1_OC0MOD_0                                             /*!<OCyREF is forced high on compare match*/
#define DDL_BTMR_OCMODE_INACTIVE                 BTMR_CCM1_OC0MOD_1                                             /*!<OCyREF is forced low on compare match*/
#define DDL_BTMR_OCMODE_TOGGLE                   (BTMR_CCM1_OC0MOD_1 | BTMR_CCM1_OC0MOD_0)                      /*!<OCyREF toggles on compare match*/
#define DDL_BTMR_OCMODE_FORCED_INACTIVE          BTMR_CCM1_OC0MOD_2                                             /*!<OCyREF is forced low*/
#define DDL_BTMR_OCMODE_FORCED_ACTIVE            (BTMR_CCM1_OC0MOD_2 | BTMR_CCM1_OC0MOD_0)                      /*!<OCyREF is forced high*/
#define DDL_BTMR_OCMODE_PWM1                     (BTMR_CCM1_OC0MOD_2 | BTMR_CCM1_OC0MOD_1)                      /*!<In upcounting, channel y is active as long as BTMRx_CNT<BTMRx_CCRy else inactive.  In downcounting, channel y is inactive as long as BTMRx_CNT>BTMRx_CCRy else active.*/
#define DDL_BTMR_OCMODE_PWM2                     (BTMR_CCM1_OC0MOD_2 | BTMR_CCM1_OC0MOD_1 | BTMR_CCM1_OC0MOD_0) /*!<In upcounting, channel y is inactive as long as BTMRx_CNT<BTMRx_CCRy else active.  In downcounting, channel y is active as long as BTMRx_CNT>BTMRx_CCRy else inactive*/
/**
  * @}
  */

/** @defgroup BTMR_DDL_EC_POLARITY Output Configuration Polarity
  * @{
  */
#define DDL_BTMR_POLARITY_HIGH                 0x00000000U               /*!< OCxactive high*/
#define DDL_BTMR_POLARITY_LOW                  BTMR_CCM1_CC0POL          /*!< OCxactive low*/
/**
  * @}
  */

/** @defgroup BTMR_DDL_EC_IC_EDGE Input Configuration Edge
  * @{
  */
#define DDL_BTMR_IC_EDGE_RISING              0x00000000U                               /*!< The circuit is sensitive to TIxFP1 rising edge, TIxFP1 is not inverted */
#define DDL_BTMR_IC_EDGE_FALLING             BTMR_CCM1_CC0_EDGE_SEL_0                  /*!< The circuit is sensitive to TIxFP1 falling edge, TIxFP1 is inverted */
#define DDL_BTMR_IC_EDGE_BOTHEDGE            BTMR_CCM1_CC0_EDGE_SEL_1                  /*!< The circuit is sensitive to both TIxFP1 rising and falling edges, TIxFP1 is not inverted */
/**
  * @}
  */

/** @defgroup BTMR_DDL_EC_IC_FILTER Input Configuration Filter
  * @{
  */
#define DDL_BTMR_IC_FILTER_PCLK_0            0x00000000U                                                /*!< No filter */
#define DDL_BTMR_IC_FILTER_PCLK_1           (BTMR_CCM1_IC0F_0)                                          /*!< 1 pclk */
#define DDL_BTMR_IC_FILTER_PCLK_2           (BTMR_CCM1_IC0F_1)                                          /*!< 2 pclk */
#define DDL_BTMR_IC_FILTER_PCLK_3           (BTMR_CCM1_IC0F_0 | BTMR_CCM1_IC0F_1)                       /*!< 3 pclk */
#define DDL_BTMR_IC_FILTER_PCLK_4           (BTMR_CCM1_IC0F_2)                                          /*!< 4 pclk */
#define DDL_BTMR_IC_FILTER_PCLK_5           (BTMR_CCM1_IC0F_2 | BTMR_CCM1_IC0F_0)                       /*!< 5 pclk */
#define DDL_BTMR_IC_FILTER_PCLK_6           (BTMR_CCM1_IC0F_2 | BTMR_CCM1_IC0F_1)                       /*!< 6 pclk */
#define DDL_BTMR_IC_FILTER_PCLK_7           (BTMR_CCM1_IC0F_2 | BTMR_CCM1_IC0F_1 | BTMR_CCM1_IC0F_0)    /*!< 7 pclk */

/**
  * @}
  */

/**
  * @}
  */

/* Exported macro ------------------------------------------------------------*/
/** @defgroup BTMR_DDL_Exported_Macros BTMR Exported Macros
  * @{
  */

/** @defgroup BTMR_DDL_EM_WRITE_READ Common Write and read registers Macros
  * @{
  */
/**
  * @brief  Write a value in BTMR register.
  * @param  __INSTANCE__ BTMR Instance
  * @param  __REG__ Register to be written
  * @param  __VALUE__ Value to be written in the register
  * @retval None
  */
#define DDL_BTMR_WriteReg(__INSTANCE__, __REG__, __VALUE__) WRITE_REG((__INSTANCE__)->__REG__, (__VALUE__))

/**
  * @brief  Read a value in BTMR register.
  * @param  __INSTANCE__ BTMR Instance
  * @param  __REG__ Register to be read
  * @retval Register value
  */
#define DDL_BTMR_ReadReg(__INSTANCE__, __REG__) READ_REG((__INSTANCE__)->__REG__)
/**
  * @}
  */

/** @defgroup BTMR_DDL_EM_Exported_Macros Exported_Macros
  * @{
  */

/**
  * @brief  HELPER macro calculating the prescaler value to achieve the required counter clock frequency.
  * @note ex: @ref __DDL_BTMR_CALC_PSC (80000000, 1000000);
  * @param  __BTMRCLK__ timer input clock frequency (in Hz)
  * @param  __CNTCLK__ counter clock frequency (in Hz)
  * @retval Prescaler value  (between Min_Data=0 and Max_Data=65535)
  */
#define __DDL_BTMR_CALC_PSC(__BTMRCLK__, __CNTCLK__)   \
  (((__BTMRCLK__) >= (__CNTCLK__)) ? (uint32_t)((((__BTMRCLK__) + (__CNTCLK__)/2U)/(__CNTCLK__)) - 1U) : 0U)

/**
  * @brief  HELPER macro calculating the auto-reload value to achieve the required output signal frequency.
  * @note ex: @ref __DDL_BTMR_CALC_ARR (1000000, @ref DDL_BTMR_GetPrescaler (), 10000);
  * @param  __BTMRCLK__ timer input clock frequency (in Hz)
  * @param  __PSC__ prescaler
  * @param  __FREQ__ output signal frequency (in Hz)
  * @retval  Auto-reload value  (between Min_Data=0 and Max_Data=65535)
  */
#define __DDL_BTMR_CALC_ARR(__BTMRCLK__, __PSC__, __FREQ__) \
  ((((__BTMRCLK__)/((__PSC__) + 1U)) >= (__FREQ__)) ? (((__BTMRCLK__)/((__FREQ__) * ((__PSC__) + 1U))) - 1U) : 0U)

/**
  * @}
  */


/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/** @defgroup BTMR_DDL_Exported_Functions BTMR Exported Functions
  * @{
  */

/** @defgroup BTMR_DDL_EF_Time_Base Time Base configuration
  * @{
  */
/**
  * @brief  Enable timer counter.
  * @param  BTMRx Timer instance
  * @retval None
  */
__STATIC_INLINE void DDL_BTMR_EnableCounter(BTMR_TypeDef *BTMRx)
{
  SET_BIT(BTMRx->CTRL1, BTMR_CTRL1_CNTEN);
}

/**
  * @brief  Disable timer counter.
  * @param  BTMRx Timer instance
  * @retval None
  */
__STATIC_INLINE void DDL_BTMR_DisableCounter(BTMR_TypeDef *BTMRx)
{
  CLEAR_BIT(BTMRx->CTRL1, BTMR_CTRL1_CNTEN);
}

/**
  * @brief  Indicates whether the timer counter is enabled.
  * @param  BTMRx Timer instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_BTMR_IsEnabledCounter(BTMR_TypeDef *BTMRx)
{
  return ((READ_BIT(BTMRx->CTRL1, BTMR_CTRL1_CNTEN) == (BTMR_CTRL1_CNTEN)) ? 1UL : 0UL);
}

/**
  * @brief  Enable update event generation.
  * @param  BTMRx Timer instance
  * @retval None
  */
__STATIC_INLINE void DDL_BTMR_EnableUpdateEvent(BTMR_TypeDef *BTMRx)
{
  CLEAR_BIT(BTMRx->CTRL1, BTMR_CTRL1_UPEN);
}

/**
  * @brief  Disable update event generation.
  * @param  BTMRx Timer instance
  * @retval None
  */
__STATIC_INLINE void DDL_BTMR_DisableUpdateEvent(BTMR_TypeDef *BTMRx)
{
  SET_BIT(BTMRx->CTRL1, BTMR_CTRL1_UPEN);
}

/**
  * @brief  Indicates whether update event generation is enabled.
  * @param  BTMRx Timer instance
  * @retval Inverted state of bit (0 or 1).
  */
__STATIC_INLINE uint32_t DDL_BTMR_IsEnabledUpdateEvent(BTMR_TypeDef *BTMRx)
{
  return ((READ_BIT(BTMRx->CTRL1, BTMR_CTRL1_UPEN) == (uint32_t)RESET) ? 1UL : 0UL);
}

/**
  * @brief  Set one pulse mode (one shot v.s. repetitive).
  * @param  BTMRx Timer instance
  * @param  OnePulseMode This parameter can be one of the following values:
  *         @arg @ref DDL_BTMR_ONEPULSEMODE_SINGLE
  *         @arg @ref DDL_BTMR_ONEPULSEMODE_REPETITIVE
  * @retval None
  */
__STATIC_INLINE void DDL_BTMR_SetOnePulseMode(BTMR_TypeDef *BTMRx, uint32_t OnePulseMode)
{
  MODIFY_REG(BTMRx->CTRL1, BTMR_CTRL1_SPMEN, OnePulseMode);
}

/**
  * @brief  Get actual one pulse mode.
  * @param  BTMRx Timer instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref DDL_BTMR_ONEPULSEMODE_SINGLE
  *         @arg @ref DDL_BTMR_ONEPULSEMODE_REPETITIVE
  */
__STATIC_INLINE uint32_t DDL_BTMR_GetOnePulseMode(BTMR_TypeDef *BTMRx)
{
  return (uint32_t)(READ_BIT(BTMRx->CTRL1, BTMR_CTRL1_SPMEN));
}

/**
  * @brief  Set the timer counter counting mode.
  * @note Switching from Center Aligned counter mode to Edge counter mode (or reverse)
  *       requires a timer reset to avoid unexpected direction
  *       due to DIR bit readonly in center aligned mode.
  * @param  BTMRx Timer instance
  * @param  CounterMode This parameter can be one of the following values:
  *         @arg @ref DDL_BTMR_COUNTERMODE_UP
  *         @arg @ref DDL_BTMR_COUNTERMODE_DOWN
  *         @arg @ref DDL_BTMR_COUNTERMODE_CENTER_UP
  *         @arg @ref DDL_BTMR_COUNTERMODE_CENTER_DOWN
  *         @arg @ref DDL_BTMR_COUNTERMODE_CENTER_UP_DOWN
  * @retval None
  */
__STATIC_INLINE void DDL_BTMR_SetCounterMode(BTMR_TypeDef *BTMRx, uint32_t CounterMode)
{
  MODIFY_REG(BTMRx->CTRL1, (BTMR_CTRL1_CNTDIR | BTMR_CTRL1_CAMSEL), CounterMode);
}

/**
  * @brief  Get actual counter mode.
  * @param  BTMRx Timer instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref DDL_BTMR_COUNTERMODE_UP
  *         @arg @ref DDL_BTMR_COUNTERMODE_DOWN
  *         @arg @ref DDL_BTMR_COUNTERMODE_CENTER_UP
  *         @arg @ref DDL_BTMR_COUNTERMODE_CENTER_DOWN
  *         @arg @ref DDL_BTMR_COUNTERMODE_CENTER_UP_DOWN
  */
__STATIC_INLINE uint32_t DDL_BTMR_GetCounterMode(BTMR_TypeDef *BTMRx)
{
  uint32_t counter_mode;

  counter_mode = (uint32_t)(READ_BIT(BTMRx->CTRL1, BTMR_CTRL1_CAMSEL));

  if (counter_mode == 0U)
  {
    counter_mode = (uint32_t)(READ_BIT(BTMRx->CTRL1, BTMR_CTRL1_CNTDIR));
  }

  return counter_mode;
}

/**
  * @brief  Enable auto-reload (ARR) preload.
  * @param  BTMRx Timer instance
  * @retval None
  */
__STATIC_INLINE void DDL_BTMR_EnableARRPreload(BTMR_TypeDef *BTMRx)
{
  SET_BIT(BTMRx->CTRL1, BTMR_CTRL1_ALD_BUFF_EN);
}

/**
  * @brief  Disable auto-reload (ARR) preload.
  * @param  BTMRx Timer instance
  * @retval None
  */
__STATIC_INLINE void DDL_BTMR_DisableARRPreload(BTMR_TypeDef *BTMRx)
{
  CLEAR_BIT(BTMRx->CTRL1, BTMR_CTRL1_ALD_BUFF_EN);
}

/**
  * @brief  Indicates whether auto-reload (ARR) preload is enabled.
  * @param  BTMRx Timer instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_BTMR_IsEnabledARRPreload(BTMR_TypeDef *BTMRx)
{
  return ((READ_BIT(BTMRx->CTRL1, BTMR_CTRL1_ALD_BUFF_EN) == (BTMR_CTRL1_ALD_BUFF_EN)) ? 1UL : 0UL);
}

/**
  * @brief  Set the counter value.
  * @param  BTMRx Timer instance
  * @param  Counter Counter value (between Min_Data=0 and Max_Data=0xFFFF)
  * @retval None
  */
__STATIC_INLINE void DDL_BTMR_SetCounter(BTMR_TypeDef *BTMRx, uint32_t Counter)
{
  WRITE_REG(BTMRx->CNT, Counter);
}

/**
  * @brief  Get the counter value.
  * @param  BTMRx Timer instance
  * @retval Counter value (between Min_Data=0 and Max_Data=0xFFFF)
  */
__STATIC_INLINE uint16_t DDL_BTMR_GetCounter(BTMR_TypeDef *BTMRx)
{
  return (uint16_t)(READ_REG(BTMRx->CNT));
}

/**
  * @brief  Get the current direction of the counter
  * @param  BTMRx Timer instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref DDL_BTMR_COUNTERDIRECTION_UP
  *         @arg @ref DDL_BTMR_COUNTERDIRECTION_DOWN
  */
__STATIC_INLINE uint32_t DDL_BTMR_GetDirection(BTMR_TypeDef *BTMRx)
{
  return (uint32_t)(READ_BIT(BTMRx->CTRL1, BTMR_CTRL1_CNTDIR));
}

/**
  * @brief  Set the prescaler value.
  * @note The counter clock frequency CK_CNT is equal to fCK_PSC / (PSC[15:0] + 1).
  * @note The prescaler can be changed on the fly as this control register is buffered. The new
  *       prescaler ratio is taken into account at the next update event.
  * @note Helper macro @ref __DDL_BTMR_CALC_PSC can be used to calculate the Prescaler parameter
  * @param  BTMRx Timer instance
  * @param  Prescaler between Min_Data=0 and Max_Data=65535
  * @retval None
  */
__STATIC_INLINE void DDL_BTMR_SetPrescaler(BTMR_TypeDef *BTMRx, uint32_t Prescaler)
{
  WRITE_REG(BTMRx->PSC, Prescaler);
}

/**
  * @brief  Get the prescaler value.
  * @param  BTMRx Timer instance
  * @retval  Prescaler value between Min_Data=0 and Max_Data=65535
  */
__STATIC_INLINE uint32_t DDL_BTMR_GetPrescaler(BTMR_TypeDef *BTMRx)
{
  return (uint32_t)(READ_REG(BTMRx->PSC));
}

/**
  * @brief  Set the auto-reload value.
  * @note The counter is blocked while the auto-reload value is null.
  * @note Helper macro @ref __DDL_BTMR_CALC_ARR can be used to calculate the AutoReload parameter
  * @param  BTMRx Timer instance
  * @param  AutoReload between Min_Data=0 and Max_Data=65535
  * @retval None
  */
__STATIC_INLINE void DDL_BTMR_SetAutoReload(BTMR_TypeDef *BTMRx, uint32_t AutoReload)
{
  WRITE_REG(BTMRx->AUTORLD, AutoReload);
}

/**
  * @brief  Get the auto-reload value.
  * @param  BTMRx Timer instance
  * @retval Auto-reload value
  */
__STATIC_INLINE uint16_t DDL_BTMR_GetAutoReload(BTMR_TypeDef *BTMRx)
{
  return (uint16_t)(READ_REG(BTMRx->AUTORLD));
}

/**
  * @}
  */

/** @defgroup BTMR_DDL_EF_Capture_Compare Capture Compare configuration
  * @{
  */
/**
  * @brief  Enable  the capture/compare control bits (CCxE and OCxM) preload.
  * @note CCxE and OCxM bits are preloaded, after having been written,
  *       they are updated only when a update event (UE) occurs.
  * @param  BTMRx Timer instance
  * @retval None
  */
__STATIC_INLINE void DDL_BTMR_EnablePSCPreload(BTMR_TypeDef *BTMRx)
{
  SET_BIT(BTMRx->CTRL1, BTMR_CTRL1_PSC_BUFF_EN);
}

/**
  * @brief  Disable  the capture/compare control bits (CCxE and OCxM) preload.
  * @param  BTMRx Timer instance
  * @retval None
  */
__STATIC_INLINE void DDL_BTMR_DisablePSCPreload(BTMR_TypeDef *BTMRx)
{
  CLEAR_BIT(BTMRx->CTRL1, BTMR_CTRL1_PSC_BUFF_EN);
}

/**
  * @}
  */

/** @defgroup BTMR_DDL_EF_Capture_Compare Capture Compare configuration
  * @{
  */
/**
  * @brief  Enable capture/compare channels.
  * @param  BTMRx Timer instance
  * @param  Channels This parameter can be a combination of the following values:
  *         @arg @ref DDL_BTMR_CHANNEL_CH0
  *         @arg @ref DDL_BTMR_CHANNEL_CH1
  *         @arg @ref DDL_BTMR_CHANNEL_CH2
  * @retval None
  */
__STATIC_INLINE void DDL_BTMR_CC_EnableChannel(BTMR_TypeDef *BTMRx, uint32_t Channels)
{
  SET_BIT(BTMRx->CCM1, Channels);
}

/**
  * @brief  Disable capture/compare channels.
  * @param  BTMRx Timer instance
  * @param  Channels This parameter can be a combination of the following values:
  *         @arg @ref DDL_BTMR_CHANNEL_CH0
  *         @arg @ref DDL_BTMR_CHANNEL_CH1
  *         @arg @ref DDL_BTMR_CHANNEL_CH2
  * @retval None
  */
__STATIC_INLINE void DDL_BTMR_CC_DisableChannel(BTMR_TypeDef *BTMRx, uint32_t Channels)
{
  CLEAR_BIT(BTMRx->CCM1, Channels);
}

/**
  * @brief  Indicate whether channel(s) is(are) enabled.
  * @param  BTMRx Timer instance
  * @param  Channels This parameter can be a combination of the following values:
  *         @arg @ref DDL_BTMR_CHANNEL_CH0
  *         @arg @ref DDL_BTMR_CHANNEL_CH1
  *         @arg @ref DDL_BTMR_CHANNEL_CH2
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_BTMR_CC_IsEnabledChannel(BTMR_TypeDef *BTMRx, uint32_t Channels)
{
  return ((READ_BIT(BTMRx->CCM1, Channels) == (Channels)) ? 1UL : 0UL);
}

/**
  * @brief  Enable channel preload .
  * @param  BTMRx Timer instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref DDL_BTMR_CHANNEL_CH0
  *         @arg @ref DDL_BTMR_CHANNEL_CH1
  *         @arg @ref DDL_BTMR_CHANNEL_CH2
  * @retval None
  */
__STATIC_INLINE void DDL_BTMR_CC_EnablePreload(BTMR_TypeDef *BTMRx, uint32_t Channel)
{
  uint8_t iChannel = BTMR_GET_CHANNEL_INDEX(Channel);
  SET_BIT(BTMRx->CCM2, BTMR_CCM2_CC0_BUFF_EN << iChannel);
}

/**
  * @brief  Disable channel preload .
  * @param  BTMRx Timer instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref DDL_BTMR_CHANNEL_CH0
  *         @arg @ref DDL_BTMR_CHANNEL_CH1
  *         @arg @ref DDL_BTMR_CHANNEL_CH2
  * @retval None
  */
__STATIC_INLINE void DDL_BTMR_CC_DisablePreload(BTMR_TypeDef *BTMRx, uint32_t Channel)
{
  uint8_t iChannel = BTMR_GET_CHANNEL_INDEX(Channel);
  CLEAR_BIT(BTMRx->CCM2, BTMR_CCM2_CC0_BUFF_EN << iChannel);
}

/**
  * @brief  Indicates whether compare register (CCx) preload is enabled for the output channel.
  * @param  BTMRx Timer instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref DDL_BTMR_CHANNEL_CH0
  *         @arg @ref DDL_BTMR_CHANNEL_CH1
  *         @arg @ref DDL_BTMR_CHANNEL_CH2
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_BTMR_CC_IsEnabledPreload(BTMR_TypeDef *BTMRx, uint32_t Channel)
{
  uint8_t iChannel = BTMR_GET_CHANNEL_INDEX(Channel);
  return ((READ_BIT(BTMRx->CCM2, (BTMR_CCM2_CC0_BUFF_EN << iChannel)) == (BTMR_CCM2_CC0_BUFF_EN << iChannel)) ? 1UL : 0UL);
}

/**
  * @}
  */

/** @defgroup BTMR_DDL_EF_Output_Channel Output channel configuration
  * @{
  */
/**
 * @brief  Set the active input.
 * @param  BTMRx Timer instance
 * @param  Channel This parameter can be one of the following values:
  *         @arg @ref DDL_BTMR_CHANNEL_CH0
  *         @arg @ref DDL_BTMR_CHANNEL_CH1
  *         @arg @ref DDL_BTMR_CHANNEL_CH2
 * @retval None
 */
__STATIC_INLINE void DDL_BTMR_OC_SetActiveOutput(BTMR_TypeDef *BTMRx, uint32_t Channel)
{
    uint8_t iChannel = BTMR_GET_CHANNEL_INDEX(Channel);
    SET_BIT(BTMRx->CCM2, (BTMR_CCM2_CC0_IOSEL << SHIFT_TAB_BTMR_CCxsel[iChannel]));
}

/**
  * @brief  Define the behavior of the output reference signal OCxREF from which
  *         OCx and OCxN (when relevant) are derived.
  * @param  BTMRx Timer instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref DDL_BTMR_CHANNEL_CH0
  *         @arg @ref DDL_BTMR_CHANNEL_CH1
  *         @arg @ref DDL_BTMR_CHANNEL_CH2
  * @param  Mode This parameter can be one of the following values:
  *         @arg @ref DDL_BTMR_OCMODE_FROZEN
  *         @arg @ref DDL_BTMR_OCMODE_ACTIVE
  *         @arg @ref DDL_BTMR_OCMODE_INACTIVE
  *         @arg @ref DDL_BTMR_OCMODE_TOGGLE
  *         @arg @ref DDL_BTMR_OCMODE_FORCED_INACTIVE
  *         @arg @ref DDL_BTMR_OCMODE_FORCED_ACTIVE
  *         @arg @ref DDL_BTMR_OCMODE_PWM1
  *         @arg @ref DDL_BTMR_OCMODE_PWM2
  * @retval None
  */
__STATIC_INLINE void DDL_BTMR_OC_SetMode(BTMR_TypeDef *BTMRx, uint32_t Channel, uint32_t Mode)
{
  uint8_t iChannel = BTMR_GET_CHANNEL_INDEX(Channel);
  MODIFY_REG(BTMRx->CCM1, (BTMR_CCM1_OC0MOD << SHIFT_TAB_BTMR_OCxx[iChannel]), Mode << SHIFT_TAB_BTMR_OCxx[iChannel]);
}

/**
  * @brief  Get the output compare mode of an output channel.
  * @param  BTMRx Timer instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref DDL_BTMR_CHANNEL_CH0
  *         @arg @ref DDL_BTMR_CHANNEL_CH1
  *         @arg @ref DDL_BTMR_CHANNEL_CH2
  * @retval Returned value can be one of the following values:
  *         @arg @ref DDL_BTMR_OCMODE_FROZEN
  *         @arg @ref DDL_BTMR_OCMODE_ACTIVE
  *         @arg @ref DDL_BTMR_OCMODE_INACTIVE
  *         @arg @ref DDL_BTMR_OCMODE_TOGGLE
  *         @arg @ref DDL_BTMR_OCMODE_FORCED_INACTIVE
  *         @arg @ref DDL_BTMR_OCMODE_FORCED_ACTIVE
  *         @arg @ref DDL_BTMR_OCMODE_PWM1
  *         @arg @ref DDL_BTMR_OCMODE_PWM2
  */
__STATIC_INLINE uint32_t DDL_BTMR_OC_GetMode(BTMR_TypeDef *BTMRx, uint32_t Channel)
{
  uint8_t iChannel = BTMR_GET_CHANNEL_INDEX(Channel);
  return (READ_BIT(BTMRx->CCM1, (BTMR_CCM1_OC0MOD << SHIFT_TAB_BTMR_OCxx[iChannel])) >> SHIFT_TAB_BTMR_OCxx[iChannel]);
}

/**
  * @brief  Set the polarity of an output channel.
  * @param  BTMRx Timer instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref DDL_BTMR_CHANNEL_CH0
  *         @arg @ref DDL_BTMR_CHANNEL_CH1
  *         @arg @ref DDL_BTMR_CHANNEL_CH2
  * @param  Polarity This parameter can be one of the following values:
  *         @arg @ref DDL_BTMR_POLARITY_HIGH
  *         @arg @ref DDL_BTMR_POLARITY_LOW
  * @retval None
  */
__STATIC_INLINE void DDL_BTMR_OC_SetPolarity(BTMR_TypeDef *BTMRx, uint32_t Channel, uint32_t Polarity)
{
  uint8_t iChannel = BTMR_GET_CHANNEL_INDEX(Channel);
  MODIFY_REG(BTMRx->CCM1, (BTMR_CCM1_CC0POL << SHIFT_TAB_BTMR_OCxx[iChannel]),  Polarity << SHIFT_TAB_BTMR_OCxx[iChannel]);
}

/**
  * @brief  Get the polarity of an output channel.
  * @param  BTMRx Timer instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref DDL_BTMR_CHANNEL_CH0
  *         @arg @ref DDL_BTMR_CHANNEL_CH1
  *         @arg @ref DDL_BTMR_CHANNEL_CH2
  * @retval Returned value can be one of the following values:
  *         @arg @ref DDL_BTMR_POLARITY_HIGH
  *         @arg @ref DDL_BTMR_POLARITY_LOW
  */
__STATIC_INLINE uint32_t DDL_BTMR_OC_GetPolarity(BTMR_TypeDef *BTMRx, uint32_t Channel)
{
  uint8_t iChannel = BTMR_GET_CHANNEL_INDEX(Channel);
  return (READ_BIT(BTMRx->CCM1, (BTMR_CCM1_CC0POL << SHIFT_TAB_BTMR_OCxx[iChannel])) >> SHIFT_TAB_BTMR_OCxx[iChannel]);
}


/**
  * @brief  Set compare value for output channel 0 (BTMRx_CC0).
  * @note Macro IS_BTMR_CC0_INSTANCE(BTMRx) can be used to check whether or not
  *       output channel is supported by a timer instance.
  * @param  BTMRx Timer instance
  * @param  CompareValue between Min_Data=0 and Max_Data=65535
  * @retval None
  */
__STATIC_INLINE void DDL_BTMR_OC_SetCompareCH0(BTMR_TypeDef *BTMRx, uint32_t CompareValue)
{
  WRITE_REG(BTMRx->CC0, CompareValue);
}

/**
  * @brief  Set compare value for output channel 1 (BTMRx_CC1).
  * @note Macro IS_BTMR_CC1_INSTANCE(BTMRx) can be used to check whether or not
  *       output channel 1 is supported by a timer instance.
  * @param  BTMRx Timer instance
  * @param  CompareValue between Min_Data=0 and Max_Data=65535
  * @retval None
  */
__STATIC_INLINE void DDL_BTMR_OC_SetCompareCH1(BTMR_TypeDef *BTMRx, uint32_t CompareValue)
{
  WRITE_REG(BTMRx->CC1, CompareValue);
}

/**
  * @brief  Set compare value for output channel 2 (BTMRx_CC2).
  * @note Macro IS_BTMR_CC2_INSTANCE(BTMRx) can be used to check whether or not
  *       output channel 2 is supported by a timer instance.
  * @param  BTMRx Timer instance
  * @param  CompareValue between Min_Data=0 and Max_Data=65535
  * @retval None
  */
__STATIC_INLINE void DDL_BTMR_OC_SetCompareCH2(BTMR_TypeDef *BTMRx, uint32_t CompareValue)
{
  WRITE_REG(BTMRx->CC2, CompareValue);
}

/**
  * @brief  Get compare value (BTMRx_CC0) set for  output channel 0.
  * @note Macro IS_BTMR_CC0_INSTANCE(BTMRx) can be used to check whether or not
  *       output channel 0 is supported by a timer instance.
  * @param  BTMRx Timer instance
  * @retval CompareValue (between Min_Data=0 and Max_Data=65535)
  */
__STATIC_INLINE uint16_t DDL_BTMR_OC_GetCompareCH0(BTMR_TypeDef *BTMRx)
{
  return (uint16_t)(READ_REG(BTMRx->CC0));
}

/**
  * @brief  Get compare value (BTMRx_CC1) set for  output channel 1.
  * @note Macro IS_BTMR_CC1_INSTANCE(BTMRx) can be used to check whether or not
  *       output channel 1 is supported by a timer instance.
  * @param  BTMRx Timer instance
  * @retval CompareValue (between Min_Data=0 and Max_Data=65535)
  */
__STATIC_INLINE uint16_t DDL_BTMR_OC_GetCompareCH1(BTMR_TypeDef *BTMRx)
{
  return (uint16_t)(READ_REG(BTMRx->CC1));
}

/**
  * @brief  Get compare value (BTMRx_CC2) set for  output channel 2.
  * @note Macro IS_BTMR_CC2_INSTANCE(BTMRx) can be used to check whether or not
  *       output channel 2 is supported by a timer instance.
  * @param  BTMRx Timer instance
  * @retval CompareValue (between Min_Data=0 and Max_Data=65535)
  */
__STATIC_INLINE uint16_t DDL_BTMR_OC_GetCompareCH2(BTMR_TypeDef *BTMRx)
{
  return (uint16_t)(READ_REG(BTMRx->CC2));
}

/**
  * @}
  */

/** @defgroup BTMR_DDL_EF_Input_Channel Input channel configuration
  * @{
  */
/**
 * @brief  Set the active input.
 * @param  BTMRx Timer instance
 * @param  Channel This parameter can be one of the following values:
  *         @arg @ref DDL_BTMR_CHANNEL_CH0
  *         @arg @ref DDL_BTMR_CHANNEL_CH1
  *         @arg @ref DDL_BTMR_CHANNEL_CH2
 * @retval None
 */
__STATIC_INLINE void DDL_BTMR_IC_SetActiveInput(BTMR_TypeDef *BTMRx, uint32_t Channel)
{
    uint8_t iChannel = BTMR_GET_CHANNEL_INDEX(Channel);
    CLEAR_BIT(BTMRx->CCM2, (BTMR_CCM2_CC0_IOSEL << SHIFT_TAB_BTMR_CCxsel[iChannel]));
}

/**
  * @brief  Set the input channel polarity.
  * @param  BTMRx Timer instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref DDL_BTMR_CHANNEL_CH0
  *         @arg @ref DDL_BTMR_CHANNEL_CH1
  *         @arg @ref DDL_BTMR_CHANNEL_CH2
  * @param  Edge This parameter can be one of the following values:
  *         @arg @ref DDL_BTMR_POLARITY_HIGH
  *         @arg @ref DDL_BTMR_POLARITY_LOW
  * @retval None
  */
__STATIC_INLINE void DDL_BTMR_IC_SetPolarity(BTMR_TypeDef *BTMRx, uint32_t Channel, uint32_t Edge)
{
  uint8_t iChannel = BTMR_GET_CHANNEL_INDEX(Channel);
  MODIFY_REG(BTMRx->CCM1, (BTMR_CCM1_CC0POL << SHIFT_TAB_BTMR_OCxx[iChannel]),  Edge << SHIFT_TAB_BTMR_OCxx[iChannel]);
}

/**
  * @brief  Get the current input channel polarity.
  * @param  BTMRx Timer instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref DDL_BTMR_CHANNEL_CH0
  *         @arg @ref DDL_BTMR_CHANNEL_CH1
  *         @arg @ref DDL_BTMR_CHANNEL_CH2
  * @retval Returned value can be one of the following values:
  *         @arg @ref DDL_BTMR_POLARITY_HIGH
  *         @arg @ref DDL_BTMR_POLARITY_LOW
  */
__STATIC_INLINE uint32_t DDL_BTMR_IC_GetPolarity(BTMR_TypeDef *BTMRx, uint32_t Channel)
{
  uint8_t iChannel = BTMR_GET_CHANNEL_INDEX(Channel);
  return (READ_BIT(BTMRx->CCM1, (BTMR_CCM1_CC0POL << SHIFT_TAB_BTMR_OCxx[iChannel])) >> SHIFT_TAB_BTMR_OCxx[iChannel]);
}

/**
  * @brief  Set the input channel edge.
  * @param  BTMRx Timer instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref DDL_BTMR_CHANNEL_CH0
  *         @arg @ref DDL_BTMR_CHANNEL_CH1
  *         @arg @ref DDL_BTMR_CHANNEL_CH2
  * @param  Edge This parameter can be one of the following values:
  *         @arg @ref DDL_BTMR_IC_EDGE_RISING
  *         @arg @ref DDL_BTMR_IC_EDGE_FALLING
  *         @arg @ref DDL_BTMR_IC_EDGE_BOTHEDGE
  * @retval None
  */
__STATIC_INLINE void DDL_BTMR_IC_SetEdge(BTMR_TypeDef *BTMRx, uint32_t Channel, uint32_t Edge)
{
  uint8_t iChannel = BTMR_GET_CHANNEL_INDEX(Channel);
  MODIFY_REG(BTMRx->CCM1, (BTMR_CCM1_CC0_EDGE_SEL << SHIFT_TAB_BTMR_OCxx[iChannel]),  Edge << SHIFT_TAB_BTMR_OCxx[iChannel]);
}

/**
  * @brief  Get the current input channel edge.
  * @param  BTMRx Timer instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref DDL_BTMR_CHANNEL_CH0
  *         @arg @ref DDL_BTMR_CHANNEL_CH1
  *         @arg @ref DDL_BTMR_CHANNEL_CH2
  * @retval Returned value can be one of the following values:
  *         @arg @ref DDL_BTMR_IC_EDGE_RISING
  *         @arg @ref DDL_BTMR_IC_EDGE_FALLING
  *         @arg @ref DDL_BTMR_IC_EDGE_BOTHEDGE
  */
__STATIC_INLINE uint32_t DDL_BTMR_IC_GetEdge(BTMR_TypeDef *BTMRx, uint32_t Channel)
{
  uint8_t iChannel = BTMR_GET_CHANNEL_INDEX(Channel);
  return (READ_BIT(BTMRx->CCM1, (BTMR_CCM1_CC0_EDGE_SEL << SHIFT_TAB_BTMR_OCxx[iChannel])) >> SHIFT_TAB_BTMR_OCxx[iChannel]);
}

/**
  * @brief  Set the filter for capturing.
  * @param  BTMRx Timer instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref DDL_BTMR_CHANNEL_CH0
  *         @arg @ref DDL_BTMR_CHANNEL_CH1
  *         @arg @ref DDL_BTMR_CHANNEL_CH2
  * @param  Edges This parameter can be one of the following values:
  *         @arg @ref DDL_BTMR_IC_FILTER_PCLK_0
  *         @arg @ref DDL_BTMR_IC_FILTER_PCLK_1
  *         @arg @ref DDL_BTMR_IC_FILTER_PCLK_2
  *         @arg @ref DDL_BTMR_IC_FILTER_PCLK_3
  *         @arg @ref DDL_BTMR_IC_FILTER_PCLK_4
  *         @arg @ref DDL_BTMR_IC_FILTER_PCLK_5
  *         @arg @ref DDL_BTMR_IC_FILTER_PCLK_6
  *         @arg @ref DDL_BTMR_IC_FILTER_PCLK_7
  * @retval None
  */
__STATIC_INLINE void DDL_BTMR_IC_SetFilter(BTMR_TypeDef *BTMRx, uint32_t Channel, uint32_t Edges)
{
  uint8_t iChannel = BTMR_GET_CHANNEL_INDEX(Channel);
  MODIFY_REG(BTMRx->CCM1, (BTMR_CCM1_IC0F << SHIFT_TAB_BTMR_OCxx[iChannel]),  Edges << SHIFT_TAB_BTMR_OCxx[iChannel]);
}

/**
  * @brief  Get the filter for capturing.
  * @param  BTMRx Timer instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref DDL_BTMR_CHANNEL_CH0
  *         @arg @ref DDL_BTMR_CHANNEL_CH1
  *         @arg @ref DDL_BTMR_CHANNEL_CH2
  * @retval Returned value can be one of the following values:
  *         @arg @ref DDL_BTMR_IC_FILTER_PCLK_0
  *         @arg @ref DDL_BTMR_IC_FILTER_PCLK_1
  *         @arg @ref DDL_BTMR_IC_FILTER_PCLK_2
  *         @arg @ref DDL_BTMR_IC_FILTER_PCLK_3
  *         @arg @ref DDL_BTMR_IC_FILTER_PCLK_4
  *         @arg @ref DDL_BTMR_IC_FILTER_PCLK_5
  *         @arg @ref DDL_BTMR_IC_FILTER_PCLK_6
  *         @arg @ref DDL_BTMR_IC_FILTER_PCLK_7
  */
__STATIC_INLINE uint32_t DDL_BTMR_IC_GetFilter(BTMR_TypeDef *BTMRx, uint32_t Channel)
{
  uint8_t iChannel = BTMR_GET_CHANNEL_INDEX(Channel);
  return (READ_BIT(BTMRx->CCM1, (BTMR_CCM1_IC0F << SHIFT_TAB_BTMR_OCxx[iChannel])) >> SHIFT_TAB_BTMR_OCxx[iChannel]);
}

/**
  * @brief  Get captured value for input channel 0.
  * @note Macro IS_BTMR_CC0_INSTANCE(BTMRx) can be used to check whether or not
  *       input channel 0 is supported by a timer instance.
  * @param  BTMRx Timer instance
  * @retval CapturedValue (between Min_Data=0 and Max_Data=65535)
  */
__STATIC_INLINE uint16_t DDL_BTMR_IC_GetCaptureCH0(BTMR_TypeDef *BTMRx)
{
  return (uint16_t)(READ_REG(BTMRx->CC0));
}

/**
  * @brief  Get captured value for input channel 1.
  * @note Macro IS_BTMR_CC1_INSTANCE(BTMRx) can be used to check whether or not
  *       input channel 1 is supported by a timer instance.
  * @param  BTMRx Timer instance
  * @retval CapturedValue (between Min_Data=0 and Max_Data=65535)
  */
__STATIC_INLINE uint16_t DDL_BTMR_IC_GetCaptureCH1(BTMR_TypeDef *BTMRx)
{
  return (uint16_t)(READ_REG(BTMRx->CC1));
}

/**
  * @brief  Get captured value for input channel 2.
  * @note Macro IS_BTMR_CC2_INSTANCE(BTMRx) can be used to check whether or not
  *       input channel 2 is supported by a timer instance.
  * @param  BTMRx Timer instance
  * @retval CapturedValue (between Min_Data=0 and Max_Data=65535)
  */
__STATIC_INLINE uint16_t DDL_BTMR_IC_GetCaptureCH2(BTMR_TypeDef *BTMRx)
{
  return (uint16_t)(READ_REG(BTMRx->CC2));
}

/**
  * @}
  */



/** @defgroup BTMR_DDL_EF_FLAG_Management FLAG-Management
  * @{
  */
/**
  * @brief  Clear the update interrupt flag (UIF).
  * @param  BTMRx Timer instance
  * @retval None
  */
__STATIC_INLINE void DDL_BTMR_ClearFlag_UPDATE(BTMR_TypeDef *BTMRx)
{
  WRITE_REG(BTMRx->STS, ~(BTMR_STS_UIFLG));
}

/**
  * @brief  Indicate whether update interrupt flag (UIF) is set (update interrupt is pending).
  * @param  BTMRx Timer instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_BTMR_IsActiveFlag_UPDATE(BTMR_TypeDef *BTMRx)
{
  return ((READ_BIT(BTMRx->STS, BTMR_STS_UIFLG) == (BTMR_STS_UIFLG)) ? 1UL : 0UL);
}

/**
  * @brief  Clear the Capture/Compare 0 interrupt flag (CC0F).
  * @param  BTMRx Timer instance
  * @retval None
  */
__STATIC_INLINE void DDL_BTMR_ClearFlag_CC0(BTMR_TypeDef *BTMRx)
{
  WRITE_REG(BTMRx->STS, ~(BTMR_STS_CC0IFLG));
}

/**
  * @brief  Indicate whether Capture/Compare 0 interrupt flag (CC0F) is set (Capture/Compare 0 interrupt is pending).
  * @param  BTMRx Timer instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_BTMR_IsActiveFlag_CC0(BTMR_TypeDef *BTMRx)
{
  return ((READ_BIT(BTMRx->STS, BTMR_STS_CC0IFLG) == (BTMR_STS_CC0IFLG)) ? 1UL : 0UL);
}

/**
  * @brief  Clear the Capture/Compare 1 interrupt flag (CC1F).
  * @param  BTMRx Timer instance
  * @retval None
  */
__STATIC_INLINE void DDL_BTMR_ClearFlag_CC1(BTMR_TypeDef *BTMRx)
{
  WRITE_REG(BTMRx->STS, ~(BTMR_STS_CC1IFLG));
}

/**
  * @brief  Indicate whether Capture/Compare 1 interrupt flag (CC1F) is set (Capture/Compare 1 interrupt is pending).
  * @param  BTMRx Timer instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_BTMR_IsActiveFlag_CC1(BTMR_TypeDef *BTMRx)
{
  return ((READ_BIT(BTMRx->STS, BTMR_STS_CC1IFLG) == (BTMR_STS_CC1IFLG)) ? 1UL : 0UL);
}

/**
  * @brief  Clear the Capture/Compare 2 interrupt flag (CC2F).
  * @param  BTMRx Timer instance
  * @retval None
  */
__STATIC_INLINE void DDL_BTMR_ClearFlag_CC2(BTMR_TypeDef *BTMRx)
{
  WRITE_REG(BTMRx->STS, ~(BTMR_STS_CC2IFLG));
}

/**
  * @brief  Indicate whether Capture/Compare 2 interrupt flag (CC2F) is set (Capture/Compare 2 interrupt is pending).
  * @param  BTMRx Timer instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_BTMR_IsActiveFlag_CC2(BTMR_TypeDef *BTMRx)
{
  return ((READ_BIT(BTMRx->STS, BTMR_STS_CC2IFLG) == (BTMR_STS_CC2IFLG)) ? 1UL : 0UL);
}

/**
  * @brief  Clear the Capture/Compare 0 over-capture interrupt flag (CC0OF).
  * @param  BTMRx Timer instance
  * @retval None
  */
__STATIC_INLINE void DDL_BTMR_ClearFlag_CC0OVR(BTMR_TypeDef *BTMRx)
{
  WRITE_REG(BTMRx->STS, ~(BTMR_STS_CC0RCFLG));
}

/**
  * @brief  Indicate whether Capture/Compare 0 over-capture interrupt flag (CC0OF) is set
  *         (Capture/Compare 0 over-capture interrupt is pending).
  * @param  BTMRx Timer instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_BTMR_IsActiveFlag_CC0OVR(BTMR_TypeDef *BTMRx)
{
  return ((READ_BIT(BTMRx->STS, BTMR_STS_CC0RCFLG) == (BTMR_STS_CC0RCFLG)) ? 1UL : 0UL);
}

/**
  * @brief  Clear the Capture/Compare 1 over-capture interrupt flag (CC1OF).
  * @param  BTMRx Timer instance
  * @retval None
  */
__STATIC_INLINE void DDL_BTMR_ClearFlag_CC1OVR(BTMR_TypeDef *BTMRx)
{
  WRITE_REG(BTMRx->STS, ~(BTMR_STS_CC1RCFLG));
}

/**
  * @brief  Indicate whether Capture/Compare 1 over-capture interrupt flag (CC1OF) is set
  *         (Capture/Compare 1 interrupt is pending).
  * @param  BTMRx Timer instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_BTMR_IsActiveFlag_CC1OVR(BTMR_TypeDef *BTMRx)
{
  return ((READ_BIT(BTMRx->STS, BTMR_STS_CC1RCFLG) == (BTMR_STS_CC1RCFLG)) ? 1UL : 0UL);
}

/**
  * @brief  Clear the Capture/Compare 2 over-capture interrupt flag (CC2OF).
  * @param  BTMRx Timer instance
  * @retval None
  */
__STATIC_INLINE void DDL_BTMR_ClearFlag_CC2OVR(BTMR_TypeDef *BTMRx)
{
  WRITE_REG(BTMRx->STS, ~(BTMR_STS_CC2RCFLG));
}

/**
  * @brief  Indicate whether Capture/Compare 2 over-capture interrupt flag (CC2OF) is set
  *         (Capture/Compare 2 over-capture interrupt is pending).
  * @param  BTMRx Timer instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_BTMR_IsActiveFlag_CC2OVR(BTMR_TypeDef *BTMRx)
{
  return ((READ_BIT(BTMRx->STS, BTMR_STS_CC2RCFLG) == (BTMR_STS_CC2RCFLG)) ? 1UL : 0UL);
}

/**
  * @}
  */

/** @defgroup BTMR_DDL_EF_IT_Management IT-Management
  * @{
  */
/**
  * @brief  Enable update interrupt (UIE).
  * @param  BTMRx Timer instance
  * @retval None
  */
__STATIC_INLINE void DDL_BTMR_EnableIT_UPDATE(BTMR_TypeDef *BTMRx)
{
  SET_BIT(BTMRx->IEN, BTMR_IEN_UIEN);
}

/**
  * @brief  Disable update interrupt (UIE).
  * @param  BTMRx Timer instance
  * @retval None
  */
__STATIC_INLINE void DDL_BTMR_DisableIT_UPDATE(BTMR_TypeDef *BTMRx)
{
  CLEAR_BIT(BTMRx->IEN, BTMR_IEN_UIEN);
}

/**
  * @brief  Indicates whether the update interrupt (UIE) is enabled.
  * @param  BTMRx Timer instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_BTMR_IsEnabledIT_UPDATE(BTMR_TypeDef *BTMRx)
{
  return ((READ_BIT(BTMRx->IEN, BTMR_IEN_UIEN) == (BTMR_IEN_UIEN)) ? 1UL : 0UL);
}

/**
  * @brief  Enable capture/compare 0 interrupt (CC0IE).
  * @param  BTMRx Timer instance
  * @retval None
  */
__STATIC_INLINE void DDL_BTMR_EnableIT_CC0(BTMR_TypeDef *BTMRx)
{
  SET_BIT(BTMRx->IEN, BTMR_IEN_CC0IEN);
}

/**
  * @brief  Disable capture/compare 0 interrupt (CC0IE).
  * @param  BTMRx Timer instance
  * @retval None
  */
__STATIC_INLINE void DDL_BTMR_DisableIT_CC0(BTMR_TypeDef *BTMRx)
{
  CLEAR_BIT(BTMRx->IEN, BTMR_IEN_CC0IEN);
}

/**
  * @brief  Indicates whether the capture/compare 0 interrupt (CC0IE) is enabled.
  * @param  BTMRx Timer instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_BTMR_IsEnabledIT_CC0(BTMR_TypeDef *BTMRx)
{
  return ((READ_BIT(BTMRx->IEN, BTMR_IEN_CC0IEN) == (BTMR_IEN_CC0IEN)) ? 1UL : 0UL);
}

/**
  * @brief  Enable capture/compare 1 interrupt (CC1IE).
  * @param  BTMRx Timer instance
  * @retval None
  */
__STATIC_INLINE void DDL_BTMR_EnableIT_CC1(BTMR_TypeDef *BTMRx)
{
  SET_BIT(BTMRx->IEN, BTMR_IEN_CC1IEN);
}

/**
  * @brief  Disable capture/compare 1  interrupt (CC1IE).
  * @param  BTMRx Timer instance
  * @retval None
  */
__STATIC_INLINE void DDL_BTMR_DisableIT_CC1(BTMR_TypeDef *BTMRx)
{
  CLEAR_BIT(BTMRx->IEN, BTMR_IEN_CC1IEN);
}

/**
  * @brief  Indicates whether the capture/compare 1 interrupt (CC1IE) is enabled.
  * @param  BTMRx Timer instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_BTMR_IsEnabledIT_CC1(BTMR_TypeDef *BTMRx)
{
  return ((READ_BIT(BTMRx->IEN, BTMR_IEN_CC1IEN) == (BTMR_IEN_CC1IEN)) ? 1UL : 0UL);
}

/**
  * @brief  Enable capture/compare 2 interrupt (CC2IE).
  * @param  BTMRx Timer instance
  * @retval None
  */
__STATIC_INLINE void DDL_BTMR_EnableIT_CC2(BTMR_TypeDef *BTMRx)
{
  SET_BIT(BTMRx->IEN, BTMR_IEN_CC2IEN);
}

/**
  * @brief  Disable capture/compare 2  interrupt (CC2IE).
  * @param  BTMRx Timer instance
  * @retval None
  */
__STATIC_INLINE void DDL_BTMR_DisableIT_CC2(BTMR_TypeDef *BTMRx)
{
  CLEAR_BIT(BTMRx->IEN, BTMR_IEN_CC2IEN);
}

/**
  * @brief  Indicates whether the capture/compare 2 interrupt (CC2IE) is enabled.
  * @param  BTMRx Timer instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_BTMR_IsEnabledIT_CC2(BTMR_TypeDef *BTMRx)
{
  return ((READ_BIT(BTMRx->IEN, BTMR_IEN_CC2IEN) == (BTMR_IEN_CC2IEN)) ? 1UL : 0UL);
}

/**
  * @}
  */


/** @defgroup BTMR_DDL_EF_EVENT_Management EVENT-Management
  * @{
  */
/**
  * @brief  Generate an update event.
  * @param  BTMRx Timer instance
  * @retval None
  */
__STATIC_INLINE void DDL_BTMR_GenerateEvent_UPDATE(BTMR_TypeDef *BTMRx)
{
  WRITE_REG(BTMRx->CEG, BTMR_CEG_UEG);
}

/**
  * @brief  Generate Capture/Compare 0 event.
  * @param  BTMRx Timer instance
  * @retval None
  */
__STATIC_INLINE void DDL_BTMR_GenerateEvent_CC0(BTMR_TypeDef *BTMRx)
{
  WRITE_REG(BTMRx->CEG, BTMR_CEG_CC0EG);
}
/**
  * @brief  Generate Capture/Compare 1 event.
  * @param  BTMRx Timer instance
  * @retval None
  */
__STATIC_INLINE void DDL_BTMR_GenerateEvent_CC1(BTMR_TypeDef *BTMRx)
{
  WRITE_REG(BTMRx->CEG, BTMR_CEG_CC1EG);
}

/**
  * @brief  Generate Capture/Compare 2 event.
  * @param  BTMRx Timer instance
  * @retval None
  */
__STATIC_INLINE void DDL_BTMR_GenerateEvent_CC2(BTMR_TypeDef *BTMRx)
{
  WRITE_REG(BTMRx->CEG, BTMR_CEG_CC2EG);
}

/**
  * @}
  */

#if defined(USE_FULL_DDL_DRIVER)
/** @defgroup BTMR_DDL_EF_Init Initialisation and deinitialisation functions
  * @{
  */

ErrorStatus DDL_BTMR_DeInit(BTMR_TypeDef *BTMRx);
void DDL_BTMR_StructInit(DDL_BTMR_InitTypeDef *BTMR_InitStruct);
ErrorStatus DDL_BTMR_Init(BTMR_TypeDef *BTMRx, DDL_BTMR_InitTypeDef *BTMR_InitStruct);
void DDL_BTMR_OC_StructInit(DDL_BTMR_OC_InitTypeDef *BTMR_OC_InitStruct);
ErrorStatus DDL_BTMR_OC_Init(BTMR_TypeDef *BTMRx, uint32_t Channel, DDL_BTMR_OC_InitTypeDef *BTMR_OC_InitStruct);
void DDL_BTMR_IC_StructInit(DDL_BTMR_IC_InitTypeDef *BTMR_ICInitStruct);
ErrorStatus DDL_BTMR_IC_Init(BTMR_TypeDef *BTMRx, uint32_t Channel, DDL_BTMR_IC_InitTypeDef *BTMR_IC_InitStruct);

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

#endif /* BTMR */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* G32M3101_DDL_BBTMR_H */
