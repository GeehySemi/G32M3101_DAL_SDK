/**
  *
  * @file        g32m3101_ddl_comp.h
  *
  * @brief       Header file of COMP DDL module.
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
#ifndef _G32M3101_DDL_COMP_H__
#define _G32M3101_DDL_COMP_H__

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "g32m3xxx.h"
#include "Legacy/g32_ddl_legacy.h"

/** @addtogroup G32M3101_DDL_Driver
  * @{
  */

#if defined (COMP0) || defined (COMP1)

/** @addtogroup COMP_DDL COMP
  * @{
  */

/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private constants ---------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/
/* Exported types ------------------------------------------------------------*/
#if defined(USE_FULL_DDL_DRIVER)
/** @defgroup COMP_DDL_ES_INIT COMP Exported Init Structure
  * @{
  */

/**
 * @brief COMP Init structure definition
 */
typedef struct
{
    uint32_t InputPlus;             /*!< Set comparator input plus.
                                        This parameter can be a value of @ref COMP_DDL_EC_INPUT_PLUS

                                        This feature can be modified afterwards using unitary function @ref DDL_COMP_SetInputPlus(). */

    uint32_t InputMinus;            /*!< Set comparator input minus.
                                        This parameter can be a value of @ref COMP_DDL_EC_INPUT_MINUS

                                        This feature can be modified afterwards using unitary function @ref DDL_COMP_SetInputMinus(). */

    uint32_t OutputPol;             /*!< Set comparator output polarity.
                                        This parameter can be a value of @ref COMP_DDL_EC_OUTPUT_POLARITY

                                        This feature can be modified afterwards using unitary function @ref DDL_COMP_SetOutputPolarity(). */

    uint32_t TmrSel;                /*!< Set comparator output timer select.
                                        This parameter can be a value of @ref COMP_DDL_EC_OUTPUT_TMR_SEL

                                        This feature can be modified afterwards using unitary function @ref DDL_COMP_SetTimerSelect(). */

    uint32_t PositiveHsy;           /*!< Set comparator output hysteresis.
                                        This parameter can be a value of @ref COMP_DDL_EC_OUTPUT_HYS

                                        This feature can be modified afterwards using unitary function @ref DDL_COMP_SetHysteresis(). */

    uint32_t FilterPsc;                /*!< Set comparator clock division.
                                        This parameter can be a value of @ref COMP_DDL_EC_FILTER_CLOCK_DIV

                                        This feature can be modified afterwards using unitary function @ref DDL_COMP_SetClockDivision(). */

    uint32_t FilterCnt;                /*!< Set comparator counter clock division.
                                        This parameter can be a value of @ref COMP_DDL_EC_FILTER_CLOCK_COUNT

                                        This feature can be modified afterwards using unitary function @ref DDL_COMP_SetCounterClockDivision(). */

} DDL_COMP_InitTypeDef;

/**
  * @}
  */
#endif /* USE_FULL_DDL_DRIVER */

/* Exported constants --------------------------------------------------------*/
/** @defgroup COMP_DDL_Exported_Constants COMP Exported Constants
  * @{
  */

/** @defgroup COMP_DDL_EC_INPUT_PLUS COMP input plus
 * @{
 */
#define DDL_COMP_INPUT_PLUS_PA5_COMP0           (0x00000000UL)                           /*!< Input plus: PA5 output. */
#define DDL_COMP_INPUT_PLUS_PA0_COMP1           (0x00000000UL)                           /*!< Input plus: PA0 output. */
#define DDL_COMP_INPUT_PLUS_BG_1_4              (COMP_CSTS_VP_EN_0)                      /*!< Input plus: 1/4 BG output. */
#define DDL_COMP_INPUT_PLUS_BG_1_2              (COMP_CSTS_VP_EN_1)                      /*!< Input plus: 1/2 BG output. */
#define DDL_COMP_INPUT_PLUS_BG_3_4              (COMP_CSTS_VP_EN_0 | COMP_CSTS_VP_EN_1)  /*!< Input plus: 3/4 BG output. */
#define DDL_COMP_INPUT_PLUS_BG                  (COMP_CSTS_VP_EN_2)                      /*!< Input plus: BG output. */

#define DDL_COMP_INPUT_PLUS_PA7_COMP0           (COMP_CSTS_VP_EN_2 | COMP_CSTS_VP_EN_0)  /*!< Input plus: PA7 output. */
#define DDL_COMP_INPUT_PLUS_PB7_COMP0           (COMP_CSTS_VP_EN_2 | COMP_CSTS_VP_EN_1)  /*!< Input plus: PB7 output. */

#define DDL_COMP_INPUT_PLUS_PB3_COMP1           (COMP_CSTS_VP_EN_2 | COMP_CSTS_VP_EN_0)  /*!< Input plus: PB3 output. */
#define DDL_COMP_INPUT_PLUS_PB8_COMP1           (COMP_CSTS_VP_EN_2 | COMP_CSTS_VP_EN_1)  /*!< Input plus: PB8 output. */
/**
 * @}
 */

/** @defgroup COMP_DDL_EC_INPUT_MINUS COMP input minus
 * @{
 */
#define DDL_COMP_INPUT_MINUS_PA9_COMP0          (0x00000000UL)
#define DDL_COMP_INPUT_MINUS_PA8_COMP0          (COMP_CSTS_VN_EN_0)
#define DDL_COMP_INPUT_MINUS_PB0_COMP0          (COMP_CSTS_VN_EN_1)
#define DDL_COMP_INPUT_MINUS_PB1_COMP0          (COMP_CSTS_VN_EN_0 | COMP_CSTS_VN_EN_1)
#define DDL_COMP_INPUT_MINUS_PB2_COMP0          (COMP_CSTS_VN_EN_2)
#define DDL_COMP_INPUT_MINUS_OPAMP0_OUT_COMP0   (COMP_CSTS_VN_EN_2 | COMP_CSTS_VN_EN_0)
#define DDL_COMP_INPUT_MINUS_OPAMP1_OUT_COMP0   (COMP_CSTS_VN_EN_2 | COMP_CSTS_VN_EN_1)

#define DDL_COMP_INPUT_MINUS_PA1_COMP1          (0x00000000UL)
#define DDL_COMP_INPUT_MINUS_PA2_COMP1          (COMP_CSTS_VN_EN_0)
#define DDL_COMP_INPUT_MINUS_PA5_COMP1          (COMP_CSTS_VN_EN_1)
#define DDL_COMP_INPUT_MINUS_OPAMP0_OUT_COMP1   (COMP_CSTS_VN_EN_0 | COMP_CSTS_VN_EN_1)
#define DDL_COMP_INPUT_MINUS_OPAMP1_OUT_COMP1   (COMP_CSTS_VN_EN_2)
#define DDL_COMP_INPUT_MINUS_PB4_COMP1          (COMP_CSTS_VN_EN_2 | COMP_CSTS_VN_EN_0)
#define DDL_COMP_INPUT_MINUS_PB5_COMP1          (COMP_CSTS_VN_EN_2 | COMP_CSTS_VN_EN_1)
#define DDL_COMP_INPUT_MINUS_PB6_COMP1          (COMP_CSTS_VN_EN)
/**
 * @}
 */

/** @defgroup COMP_DDL_EC_OUTPUT_POLARITY COMP output polarity
 * @{
 */
#define DDL_COMP_OUTPUTPOL_NONINVERTED          (0x00000000UL)              /*!< Comparator output is non-inverted. */
#define DDL_COMP_OUTPUTPOL_INVERTED             (COMP_CSTS_POL)             /*!< Comparator output is inverted. */
/**
 * @}
 */

/** @defgroup COMP_DDL_EC_OUTPUT_LEVEL COMP output level
 * @{
 */
#define DDL_COMP_OUTPUT_LEVEL_LOW               (0x00000000UL)              /*!< Comparator output level is low. */
#define DDL_COMP_OUTPUT_LEVEL_HIGH              (COMP_CSTS_VALUE)           /*!< Comparator output level is high. */
/**
 * @}
 */

/** @defgroup COMP_DDL_EC_OUTPUT_HYS COMP hysteresis
 * @{
 */
#define DDL_COMP_HYS_DISABLE                    (0x00000000UL)              /*!< Comparator hysteresis disable. */
#define DDL_COMP_HYS_20MV                       (COMP_CSTS_HYS_EN_0)        /*!< Comparator hysteresis 20mv. */
#define DDL_COMP_HYS_40MV                       (COMP_CSTS_HYS_EN_1)        /*!< Comparator hysteresis 40mv. */
#define DDL_COMP_HYS_80MV                       (COMP_CSTS_HYS_EN_0 | COMP_CSTS_HYS_EN_1)      /*!< Comparator hysteresis 80mv. */
/**
 * @}
 */

/** @defgroup COMP_DDL_EC_OUTPUT_TMR_SEL COMP Timer Select
 * @{
 */
#define DDL_COMP_TMR_SEL_NONE                   (0x00000000UL)
#define DDL_COMP_TMR_SEL_ATMRBKIN               (COMP_CSTS_TMR_SEL_0)
#define DDL_COMP_TMR_SEL_GTMRCC0                (COMP_CSTS_TMR_SEL_1)
#define DDL_COMP_TMR_SEL_GTMRCC1                (COMP_CSTS_TMR_SEL_0 | COMP_CSTS_TMR_SEL_1)
#define DDL_COMP_TMR_SEL_GTMRCC2                (COMP_CSTS_TMR_SEL_2)
#define DDL_COMP_TMR_SEL_GTMRCC3                (COMP_CSTS_TMR_SEL_2 | COMP_CSTS_TMR_SEL_0)
#define DDL_COMP_TMR_SEL_GTMRETR                (COMP_CSTS_TMR_SEL_2 | COMP_CSTS_TMR_SEL_1)
/**
 * @}
 */


/** @defgroup COMP_DDL_EC_HW_DELAYS COMP hardware delay
 * @{
 */

/* Delay for comparator startup time */
#define DDL_COMP_DELAY_STARTUP_US               (80UL)                /*!< Comparator startup time. */
/**
 * @}
 */


/** @defgroup COMP_DDL_EC_FILTER_CLOCK_COUNT COMP Filter Clock Count
 * @{
 */
#define DDL_COMP_FILTER_CLOCK_COUNT_0           (0x00000000UL)                                         /*!< Division with 0 */
#define DDL_COMP_FILTER_CLOCK_COUNT_2           (COMP_CSTS_CFG_0)                                      /*!< Division with 2 */
#define DDL_COMP_FILTER_CLOCK_COUNT_4           (COMP_CSTS_CFG_1)                                      /*!< Division with 4 */
#define DDL_COMP_FILTER_CLOCK_COUNT_8           (COMP_CSTS_CFG_1 | COMP_CSTS_CFG_0)                    /*!< Division with 8 */
#define DDL_COMP_FILTER_CLOCK_COUNT_16          (COMP_CSTS_CFG_2)                                      /*!< Division with 16 */
#define DDL_COMP_FILTER_CLOCK_COUNT_32          (COMP_CSTS_CFG_2 | COMP_CSTS_CFG_0)                    /*!< Division with 32 */
#define DDL_COMP_FILTER_CLOCK_COUNT_64          (COMP_CSTS_CFG_2 | COMP_CSTS_CFG_1)                    /*!< Division with 64 */
#define DDL_COMP_FILTER_CLOCK_COUNT_128         (COMP_CSTS_CFG_2 | COMP_CSTS_CFG_1 | COMP_CSTS_CFG_0)  /*!< Division with 128*/
#define DDL_COMP_FILTER_CLOCK_COUNT_256         (COMP_CSTS_CFG_3)                                      /*!< Division with 256*/
#define DDL_COMP_FILTER_CLOCK_COUNT_512         (COMP_CSTS_CFG_3 | COMP_CSTS_CFG_0)                    /*!< Division with 512*/
/**
 * @}
 */

/** @defgroup COMP_DDL_EC_FILTER_CLOCK_DIV COMP Filter Clock Division
 * @{
 */
#define DDL_COMP_FILTER_CLOCK_DIV_0             (0x00000000UL)                         /*!< Division with 0 */
#define DDL_COMP_FILTER_CLOCK_DIV_2             (COMP_CSTS_PSC_0)                      /*!< Division with 2 */
#define DDL_COMP_FILTER_CLOCK_DIV_4             (COMP_CSTS_PSC_1)                      /*!< Division with 4 */
#define DDL_COMP_FILTER_CLOCK_DIV_8             (COMP_CSTS_PSC_1 | COMP_CSTS_PSC_0)    /*!< Division with 8 */
#define DDL_COMP_FILTER_CLOCK_DIV_16            (COMP_CSTS_PSC_2)                      /*!< Division with 16 */
#define DDL_COMP_FILTER_CLOCK_DIV_32            (COMP_CSTS_PSC_2 | COMP_CSTS_PSC_0)    /*!< Division with 32 */
#define DDL_COMP_FILTER_CLOCK_DIV_64            (COMP_CSTS_PSC_2 | COMP_CSTS_PSC_1)    /*!< Division with 64 */
#define DDL_COMP_FILTER_CLOCK_DIV_128           (COMP_CSTS_PSC)                        /*!< Division with 128*/
/**
 * @}
 */

/**
  * @}
  */

/* Exported macro ------------------------------------------------------------*/
/** @defgroup COMP_DDL_Exported_Macros COMP Exported Macros
  * @{
  */
/** @defgroup COMP_DDL_EM_WRITE_READ Common write and read registers macro
  * @{
  */

/**
 * @brief  Write a value in COMP register.
 * @param  __INSTANCE__ COMP submodule instance.
 * @param  __REG__ COMP register.
 * @param  __VALUE__ Value to be written.
 * @retval None
 */
#define DDL_COMP_WriteReg(__INSTANCE__, __REG__, __VALUE__)     WRITE_REG(__INSTANCE__->__REG__, (__VALUE__))

/**
 * @brief  Read a value in COMP register.
 * @param  __INSTANCE__ COMP submodule instance.
 * @param  __REG__ COMP register.
 * @retval Register value
 */
#define DDL_COMP_ReadReg(__INSTANCE__, __REG__)                 READ_REG(__INSTANCE__->__REG__)
/**
  * @}
  */

/**
 * @}
 */

/* Exported functions --------------------------------------------------------*/
/** @defgroup COMP_DDL_Exported_Functions COMP Exported Functions
  * @{
  */

/** @defgroup COMP_DDL_EF_Configuration_comparator_modes Configuration of comparator instance mode
 * @{
 */

/**
 * @brief  Set comparator filter configuration.
 * @param  COMPx COMP submodule instance.
 * @param  TmrSel This parameter can be one of the following values:
 *         @arg @ref DDL_COMP_TMR_SEL_NONE
 *         @arg @ref DDL_COMP_TMR_SEL_ATMRBKIN
 *         @arg @ref DDL_COMP_TMR_SEL_GTMRCC0
 *         @arg @ref DDL_COMP_TMR_SEL_GTMRCC1
 *         @arg @ref DDL_COMP_TMR_SEL_GTMRCC2
 *         @arg @ref DDL_COMP_TMR_SEL_GTMRCC3
 *         @arg @ref DDL_COMP_TMR_SEL_GTMRETR
 * @retval None
 */
__STATIC_INLINE void DDL_COMP_SetTimerSelect(COMP_TypeDef *COMPx,
                                            uint32_t TmrSel)
{
  MODIFY_REG(COMPx->CSTS, COMP_CSTS_TMR_SEL, TmrSel);
}

/**
 * @brief Get comparator filter configuration.
 * @param  COMPx COMP submodule instance.
 * @retval Returned value can be one of the following values:
 *         @arg @ref DDL_COMP_TMR_SEL_NONE
 *         @arg @ref DDL_COMP_TMR_SEL_ATMRBKIN
 *         @arg @ref DDL_COMP_TMR_SEL_GTMRCC0
 *         @arg @ref DDL_COMP_TMR_SEL_GTMRCC1
 *         @arg @ref DDL_COMP_TMR_SEL_GTMRCC2
 *         @arg @ref DDL_COMP_TMR_SEL_GTMRCC3
 *         @arg @ref DDL_COMP_TMR_SEL_GTMRETR
 */
__STATIC_INLINE uint32_t DDL_COMP_GetTimerSelect(COMP_TypeDef *COMPx)
{
  return (uint32_t)(READ_BIT(COMPx->CSTS, COMP_CSTS_TMR_SEL));
}


/**
 * @brief  Set comparator hysteresis.
 * @param  COMPx COMP submodule instance.
 * @param  Hsy This parameter can be one of the following values:
 *         @arg @ref DDL_COMP_HYS_DISABLE
 *         @arg @ref DDL_COMP_HYS_20MV
 *         @arg @ref DDL_COMP_HYS_40MV
 *         @arg @ref DDL_COMP_HYS_80MV
 * @retval None
 */
__STATIC_INLINE void DDL_COMP_SetPositiveHysteresis(COMP_TypeDef *COMPx,
                                                        uint32_t Hsy)
{
  MODIFY_REG(COMPx->CSTS, COMP_CSTS_HYS_EN, Hsy);
}

/**
 * @brief Get comparator hysteresis.
 * @param  COMPx COMP submodule instance.
 * @retval Returned value can be one of the following values:
 *         @arg @ref DDL_COMP_HYS_DISABLE
 *         @arg @ref DDL_COMP_HYS_20MV
 *         @arg @ref DDL_COMP_HYS_40MV
 *         @arg @ref DDL_COMP_HYS_80MV
 */
__STATIC_INLINE uint32_t DDL_COMP_GetPositiveHysteresis(COMP_TypeDef *COMPx)
{
  return (uint32_t)(READ_BIT(COMPx->CSTS, COMP_CSTS_HYS_EN));
}

/**
 * @brief  Set comparator counter clock division.
 * @param  COMPx COMP submodule instance.
 * @param  Div This parameter can be one of the following values:
 *         @arg @ref DDL_COMP_FILTER_CLOCK_COUNT_0
 *         @arg @ref DDL_COMP_FILTER_CLOCK_COUNT_2
 *         @arg @ref DDL_COMP_FILTER_CLOCK_COUNT_4
 *         @arg @ref DDL_COMP_FILTER_CLOCK_COUNT_8
 *         @arg @ref DDL_COMP_FILTER_CLOCK_COUNT_16
 *         @arg @ref DDL_COMP_FILTER_CLOCK_COUNT_32
 *         @arg @ref DDL_COMP_FILTER_CLOCK_COUNT_64
 *         @arg @ref DDL_COMP_FILTER_CLOCK_COUNT_128
 *         @arg @ref DDL_COMP_FILTER_CLOCK_COUNT_256
 *         @arg @ref DDL_COMP_FILTER_CLOCK_COUNT_512
 * @retval None
 */
__STATIC_INLINE void DDL_COMP_SetFilterClockCount(COMP_TypeDef *COMPx,
                                                        uint32_t count)
{
  MODIFY_REG(COMPx->CSTS, COMP_CSTS_CFG, count);
}

/**
 * @brief Get comparator counter clock division.
 * @param  COMPx COMP submodule instance.
 * @retval Returned value can be one of the following values:
 *         @arg @ref DDL_COMP_FILTER_CLOCK_COUNT_0
 *         @arg @ref DDL_COMP_FILTER_CLOCK_COUNT_2
 *         @arg @ref DDL_COMP_FILTER_CLOCK_COUNT_4
 *         @arg @ref DDL_COMP_FILTER_CLOCK_COUNT_8
 *         @arg @ref DDL_COMP_FILTER_CLOCK_COUNT_16
 *         @arg @ref DDL_COMP_FILTER_CLOCK_COUNT_32
 *         @arg @ref DDL_COMP_FILTER_CLOCK_COUNT_64
 *         @arg @ref DDL_COMP_FILTER_CLOCK_COUNT_128
 *         @arg @ref DDL_COMP_FILTER_CLOCK_COUNT_256
 *         @arg @ref DDL_COMP_FILTER_CLOCK_COUNT_512
 */
__STATIC_INLINE uint32_t DDL_COMP_GetFilterClockCount(COMP_TypeDef *COMPx)
{
  return (uint32_t)(READ_BIT(COMPx->CSTS, COMP_CSTS_CFG));
}

/**
 * @brief  Set comparator clock division.
 * @param  COMPx COMP submodule instance.
 * @param  Div This parameter can be one of the following values:
 *         @arg @ref DDL_COMP_FILTER_CLOCK_DIV_0
 *         @arg @ref DDL_COMP_FILTER_CLOCK_DIV_2
 *         @arg @ref DDL_COMP_FILTER_CLOCK_DIV_4
 *         @arg @ref DDL_COMP_FILTER_CLOCK_DIV_8
 *         @arg @ref DDL_COMP_FILTER_CLOCK_DIV_16
 *         @arg @ref DDL_COMP_FILTER_CLOCK_DIV_32
 *         @arg @ref DDL_COMP_FILTER_CLOCK_DIV_64
 *         @arg @ref DDL_COMP_FILTER_CLOCK_DIV_128
 * @retval None
 */
__STATIC_INLINE void DDL_COMP_SetClockDivision(COMP_TypeDef *COMPx,
                                                        uint32_t Div)
{
  MODIFY_REG(COMPx->CSTS, COMP_CSTS_PSC, Div);
}

/**
 * @brief Get comparator clock division.
 * @param  COMPx COMP submodule instance.
 * @retval Returned value can be one of the following values:
 *         @arg @ref DDL_COMP_FILTER_CLOCK_DIV_0
 *         @arg @ref DDL_COMP_FILTER_CLOCK_DIV_2
 *         @arg @ref DDL_COMP_FILTER_CLOCK_DIV_4
 *         @arg @ref DDL_COMP_FILTER_CLOCK_DIV_8
 *         @arg @ref DDL_COMP_FILTER_CLOCK_DIV_16
 *         @arg @ref DDL_COMP_FILTER_CLOCK_DIV_32
 *         @arg @ref DDL_COMP_FILTER_CLOCK_DIV_64
 *         @arg @ref DDL_COMP_FILTER_CLOCK_DIV_128
 */
__STATIC_INLINE uint32_t DDL_COMP_GetClockDivision(COMP_TypeDef *COMPx)
{
  return (uint32_t)(READ_BIT(COMPx->CSTS, COMP_CSTS_PSC));
}

/**
  * @}
  */

/** @defgroup COMP_DDL_EF_Configuration_comparator_inputs Configuration of comparator inputs
 * @{
 */

/**
 * @brief  Set comparator input plus.
 * @param  COMPx COMP submodule instance.
 * @param  InputPlus This parameter can be one of the following values:
 *         @arg @ref DDL_COMP_INPUT_PLUS_PA5_COMP0
 *         @arg @ref DDL_COMP_INPUT_PLUS_PA0_COMP1
 *         @arg @ref DDL_COMP_INPUT_PLUS_BG_1_4
 *         @arg @ref DDL_COMP_INPUT_PLUS_BG_1_2
 *         @arg @ref DDL_COMP_INPUT_PLUS_BG_3_4
 *         @arg @ref DDL_COMP_INPUT_PLUS_BG
 *         @arg @ref DDL_COMP_INPUT_PLUS_PA7_COMP0
 *         @arg @ref DDL_COMP_INPUT_PLUS_PB7_COMP0
 *
 *         @arg @ref DDL_COMP_INPUT_PLUS_PB3_COMP1
 *         @arg @ref DDL_COMP_INPUT_PLUS_PB8_COMP1
 * @retval None
 */
__STATIC_INLINE void DDL_COMP_SetInputPlus(COMP_TypeDef *COMPx,
                                            uint32_t InputPlus)
{
  MODIFY_REG(COMPx->CSTS, COMP_CSTS_VP_EN, InputPlus);
}

/**
 * @brief Get comparator input plus.
 * @param  COMPx COMP submodule instance.
 * @retval Returned value can be one of the following values:
 *         @arg @ref DDL_COMP_INPUT_PLUS_PA5_COMP0
 *         @arg @ref DDL_COMP_INPUT_PLUS_PA0_COMP1
 *         @arg @ref DDL_COMP_INPUT_PLUS_BG_1_4
 *         @arg @ref DDL_COMP_INPUT_PLUS_BG_1_2
 *         @arg @ref DDL_COMP_INPUT_PLUS_BG_3_4
 *         @arg @ref DDL_COMP_INPUT_PLUS_BG
 *         @arg @ref DDL_COMP_INPUT_PLUS_PA7_COMP0
 *         @arg @ref DDL_COMP_INPUT_PLUS_PB7_COMP0
 *
 *         @arg @ref DDL_COMP_INPUT_PLUS_PB3_COMP1
 *         @arg @ref DDL_COMP_INPUT_PLUS_PB8_COMP1
 */
__STATIC_INLINE uint32_t DDL_COMP_GetInputPlus(COMP_TypeDef *COMPx)
{
  return (uint32_t)(READ_BIT(COMPx->CSTS, COMP_CSTS_VP_EN));
}

/**
 * @brief  Set comparator input minus.
 * @param  COMPx COMP submodule instance.
 * @param  InputMinus This parameter can be one of the following values:
 *         @arg @ref DDL_COMP_INPUT_MINUS_PA9_COMP0
 *         @arg @ref DDL_COMP_INPUT_MINUS_PA8_COMP0
 *         @arg @ref DDL_COMP_INPUT_MINUS_PB0_COMP0
 *         @arg @ref DDL_COMP_INPUT_MINUS_PB1_COMP0
 *         @arg @ref DDL_COMP_INPUT_MINUS_PB2_COMP0
 *         @arg @ref DDL_COMP_INPUT_MINUS_OPAMP0_OUT_COMP0
 *         @arg @ref DDL_COMP_INPUT_MINUS_OPAMP1_OUT_COMP0
 *
 *         @arg @ref DDL_COMP_INPUT_MINUS_PA1_COMP1
 *         @arg @ref DDL_COMP_INPUT_MINUS_PA2_COMP1
 *         @arg @ref DDL_COMP_INPUT_MINUS_PA5_COMP1
 *         @arg @ref DDL_COMP_INPUT_MINUS_OPAMP0_OUT_COMP1
 *         @arg @ref DDL_COMP_INPUT_MINUS_OPAMP1_OUT_COMP1
 *         @arg @ref DDL_COMP_INPUT_MINUS_PB4_COMP1
 *         @arg @ref DDL_COMP_INPUT_MINUS_PB5_COMP1
 *         @arg @ref DDL_COMP_INPUT_MINUS_PB6_COMP1
 * @retval None
 */
__STATIC_INLINE void DDL_COMP_SetInputMinus(COMP_TypeDef *COMPx,
                                            uint32_t InputMinus)
{
  /* Note: Input minus is available only for COMP0 and COMP1. */
  MODIFY_REG(COMPx->CSTS, COMP_CSTS_VN_EN, InputMinus);
}

/**
 * @brief Get comparator input minus.
 * @param  COMPx COMP submodule instance.
 * @retval Returned value can be one of the following values:
 *         @arg @ref DDL_COMP_INPUT_MINUS_PA9_COMP0
 *         @arg @ref DDL_COMP_INPUT_MINUS_PA8_COMP0
 *         @arg @ref DDL_COMP_INPUT_MINUS_PB0_COMP0
 *         @arg @ref DDL_COMP_INPUT_MINUS_PB1_COMP0
 *         @arg @ref DDL_COMP_INPUT_MINUS_PB2_COMP0
 *         @arg @ref DDL_COMP_INPUT_MINUS_OPAMP0_OUT_COMP0
 *         @arg @ref DDL_COMP_INPUT_MINUS_OPAMP1_OUT_COMP0
 *
 *         @arg @ref DDL_COMP_INPUT_MINUS_PA1_COMP1
 *         @arg @ref DDL_COMP_INPUT_MINUS_PA2_COMP1
 *         @arg @ref DDL_COMP_INPUT_MINUS_PA5_COMP1
 *         @arg @ref DDL_COMP_INPUT_MINUS_OPAMP0_OUT_COMP1
 *         @arg @ref DDL_COMP_INPUT_MINUS_OPAMP1_OUT_COMP1
 *         @arg @ref DDL_COMP_INPUT_MINUS_PB4_COMP1
 *         @arg @ref DDL_COMP_INPUT_MINUS_PB5_COMP1
 *         @arg @ref DDL_COMP_INPUT_MINUS_PB6_COMP1
 */
__STATIC_INLINE uint32_t DDL_COMP_GetInputMinus(COMP_TypeDef *COMPx)
{
  return (uint32_t)(READ_BIT(COMPx->CSTS, COMP_CSTS_VN_EN));
}

/**
  * @}
  */

/** @defgroup COMP_DDL_EF_Configuration_comparator_output Configuration of comparator output
 * @{
 */

/**
 * @brief  Set comparator output polarity.
 * @param  COMPx COMP submodule instance.
 * @param  OutputPol This parameter can be one of the following values:
 *        @arg @ref DDL_COMP_OUTPUTPOL_NONINVERTED
 *        @arg @ref DDL_COMP_OUTPUTPOL_INVERTED
 * @retval None
 */
__STATIC_INLINE void DDL_COMP_SetOutputPolarity(COMP_TypeDef *COMPx,
                                                uint32_t OutputPol)
{
  MODIFY_REG(COMPx->CSTS, COMP_CSTS_POL, OutputPol);
}

/**
 * @brief Get comparator output polarity.
 * @param  COMPx COMP submodule instance.
 * @retval Returned value can be one of the following values:
 *       @arg @ref DDL_COMP_OUTPUTPOL_NONINVERTED
 *       @arg @ref DDL_COMP_OUTPUTPOL_INVERTED
 */
__STATIC_INLINE uint32_t DDL_COMP_GetOutputPolarity(COMP_TypeDef *COMPx)
{
  return (uint32_t)(READ_BIT(COMPx->CSTS, COMP_CSTS_POL));
}

/**
  * @}
  */

/** @defgroup COMP_DDL_EF_Operation Operation on comparator instance
 * @{
 */

/**
 * @brief  Enable comparator instance.
 * @param  COMPx COMP submodule instance.
 * @retval None
 * @note   After enable from off state, comparator startup time is needed.
 */
__STATIC_INLINE void DDL_COMP_Enable(COMP_TypeDef *COMPx)
{
  SET_BIT(COMPx->CSTS, COMP_CSTS_EN_LV);
}

/**
 * @brief  Disable comparator instance.
 * @param  COMPx COMP submodule instance.
 * @retval None
 */
__STATIC_INLINE void DDL_COMP_Disable(COMP_TypeDef *COMPx)
{
  CLEAR_BIT(COMPx->CSTS, COMP_CSTS_EN_LV);
}

/**
 * @brief  Get comparator enable state.
 * @param  COMPx COMP submodule instance.
 * @retval State of bit (1 or 0).
 *        - 0: comparator instance is disabled.
 *        - 1: comparator instance is enabled.
 */
__STATIC_INLINE uint32_t DDL_COMP_IsEnabled(COMP_TypeDef *COMPx)
{
  return ((READ_BIT(COMPx->CSTS, COMP_CSTS_EN_LV) == (COMP_CSTS_EN_LV)) ? 1UL : 0UL);
}

/**
 * @brief  Lock comparator instance.
 * @param  COMPx COMP submodule instance.
 * @retval None
 * @note   Once locked, comparator configuration can no longer be modified until next reset.
 * @note   The only way to unlock the comparator is a device hardware reset.
 */
__STATIC_INLINE void DDL_COMP_Lock(COMP_TypeDef *COMPx)
{
  SET_BIT(COMPx->CSTS, COMP_CSTS_LOCK);
}

/**
 * @brief  Get comparator lock state.
 * @param  COMPx COMP submodule instance.
 * @retval State of bit (1 or 0).
 *       - 0: comparator instance is unlocked.
 *       - 1: comparator instance is locked.
 */
__STATIC_INLINE uint32_t DDL_COMP_IsLocked(COMP_TypeDef *COMPx)
{
  return ((READ_BIT(COMPx->CSTS, COMP_CSTS_LOCK) == (COMP_CSTS_LOCK)) ? 1UL : 0UL);
}

/**
 * @brief  Read comparator output level.
 * @param  COMPx COMP submodule instance.
 * @retval Returned value can be one of the following values:
 *       @arg @ref DDL_COMP_OUTPUT_LEVEL_LOW
 *       @arg @ref DDL_COMP_OUTPUT_LEVEL_HIGH
 * @note   The comparator output level depends on the selected polarity.
 *         If the polarity is not inverted:
 *         - Comparator output is low level when the input plus is lower than the input minus.
 *         - Comparator output is high level when the input plus is higher than the input minus.
 *         If the polarity is inverted:
 *         - Comparator output is high level when the input plus is lower than the input minus.
 *         - Comparator output is low level when the input plus is higher than the input minus.
 */
__STATIC_INLINE uint32_t DDL_COMP_ReadOutputLevel(COMP_TypeDef *COMPx)
{
  return (uint32_t)(READ_BIT(COMPx->CSTS, COMP_CSTS_VALUE));
}

/**
  * @}
  */

/** @defgroup COMP_DDL_EF_FLAG_Management FLAG-Management
 * @{
 */

/**
  * @brief  Clear the interrupt flag.
  * @param  COMPx COMP submodule instance.
  * @retval None
  */
__STATIC_INLINE void DDL_COMP_ClearFlag_IT(COMP_TypeDef *COMPx)
{
  SET_BIT(COMPx->STS, COMP_STS_STS);
}

/**
  * @brief  Indicate whether interrupt flag is set.
  * @param  COMPx COMP submodule instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_COMP_IsActiveFlag_IT(COMP_TypeDef *COMPx)
{
  return ((READ_BIT(COMPx->STS, COMP_STS_STS) == (COMP_STS_STS)) ? 1UL : 0UL);
}

/**
  * @}
  */

/** @defgroup COMP_DDL_EF_IT_Management IT Management
 * @{
 */

/**
 * @brief  Enable comparator interrupt for rising edge.
 * @param  COMPx COMP submodule instance.
 * @retval None.
 */
__STATIC_INLINE void DDL_COMP_EnableIT_RisingEdge(COMP_TypeDef *COMPx)
{
  SET_BIT(COMPx->CSTS, COMP_CSTS_R_EN);
}

/**
 * @brief  Disable comparator interrupt for rising edge.
 * @param  COMPx COMP submodule instance.
 * @retval None.
 */
__STATIC_INLINE void DDL_COMP_DisableIT_RisingEdge(COMP_TypeDef *COMPx)
{
  CLEAR_BIT(COMPx->CSTS, COMP_CSTS_R_EN);
}

/**
 * @brief  Check if comparator interrupt for rising edge is enabled.
 * @param  COMPx COMP submodule instance.
 * @retval State of bit (1 or 0).
 */
__STATIC_INLINE uint32_t DDL_COMP_IsEnabledIT_RisingEdge(COMP_TypeDef *COMPx)
{
  return ((READ_BIT(COMPx->CSTS, COMP_CSTS_R_EN) == (COMP_CSTS_R_EN)) ? 1UL : 0UL);
}

/**
 * @brief  Enable comparator interrupt for falling edge.
 * @param  COMPx COMP submodule instance.
 * @retval None.
 */
__STATIC_INLINE void DDL_COMP_EnableIT_FallingEdge(COMP_TypeDef *COMPx)
{
  SET_BIT(COMPx->CSTS, COMP_CSTS_F_EN);
}

/**
 * @brief  Disable comparator interrupt for falling edge.
 * @param  COMPx COMP submodule instance.
 * @retval None.
 */
__STATIC_INLINE void DDL_COMP_DisableIT_FallingEdge(COMP_TypeDef *COMPx)
{
  CLEAR_BIT(COMPx->CSTS, COMP_CSTS_F_EN);
}

/**
 * @brief  Check if comparator interrupt for falling edge is enabled.
 * @param  COMPx COMP submodule instance.
 * @retval State of bit (1 or 0).
 */
__STATIC_INLINE uint32_t DDL_COMP_IsEnabledIT_FallingEdge(COMP_TypeDef *COMPx)
{
  return ((READ_BIT(COMPx->CSTS, COMP_CSTS_F_EN) == (COMP_CSTS_F_EN)) ? 1UL : 0UL);
}

/**
 * @brief  Enable comparator interrupt for both rising and falling edge.
 * @param  COMPx COMP submodule instance.
 * @retval None.
 */
__STATIC_INLINE void DDL_COMP_EnableIT_BothEdges(COMP_TypeDef *COMPx)
{
  SET_BIT(COMPx->CSTS, COMP_CSTS_RF_EN);
}

/**
 * @brief  Disable comparator interrupt for both rising and falling edge.
 * @param  COMPx COMP submodule instance.
 * @retval None.
 */
__STATIC_INLINE void DDL_COMP_DisableIT_BothEdges(COMP_TypeDef *COMPx)
{
  CLEAR_BIT(COMPx->CSTS, COMP_CSTS_RF_EN);
}

/**
 * @brief  Check if comparator interrupt for both rising and falling edge that is enabled.
 * @param  COMPx COMP submodule instance.
 * @retval State of bit (1 or 0).
 */
__STATIC_INLINE uint32_t DDL_COMP_IsEnabledIT_BothEdges(COMP_TypeDef *COMPx)
{
  return ((READ_BIT(COMPx->CSTS, COMP_CSTS_RF_EN) == (COMP_CSTS_RF_EN)) ? 1UL : 0UL);
}

/**
 * @brief  Enable comparator software interrupt.
 * @param  COMPx COMP submodule instance.
 * @retval None.
 */
__STATIC_INLINE void DDL_COMP_EnableIT_SW(COMP_TypeDef *COMPx)
{
  SET_BIT(COMPx->CSTS, COMP_CSTS_SWINT);
}

/**
 * @brief  Disable comparator software interrupt.
 * @param  COMPx COMP submodule instance.
 * @retval None.
 */
__STATIC_INLINE void DDL_COMP_DisableIT_SW(COMP_TypeDef *COMPx)
{
  SET_BIT(COMPx->STS, COMP_STS_STS);
}

/**
 * @brief  Check if comparator software interrupt is enabled.
 * @param  COMPx COMP submodule instance.
 * @retval State of bit (1 or 0).
 */
__STATIC_INLINE uint32_t DDL_COMP_IsEnabledIT_SW(COMP_TypeDef *COMPx)
{
  return ((READ_BIT(COMPx->CSTS, COMP_CSTS_SWINT) == (COMP_CSTS_SWINT)) ? 1UL : 0UL);
}

/**
  * @}
  */

#if defined(USE_FULL_DDL_DRIVER)
/** @defgroup COMP_DDL_EF_Init Initialization and de-initialization functions
 * @{
 */

ErrorStatus DDL_COMP_Init(COMP_TypeDef *COMPx, DDL_COMP_InitTypeDef *COMP_InitStruct);
ErrorStatus DDL_COMP_DeInit(COMP_TypeDef *COMPx);
void        DDL_COMP_StructInit(DDL_COMP_InitTypeDef *COMP_InitStruct);

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

 #endif /* COMP0 || COMP1 */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* _G32M3101_DDL_COMP_H__ */
