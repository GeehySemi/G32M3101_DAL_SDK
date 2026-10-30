/**
  *

  * @file        g32m3101_ddl_comp.c
  *
  * @brief       COMP DDL module driver.
  *
  * @version     V1.0.1
  *
  * @date        2026-05-15
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
  *
  */
#if defined(USE_FULL_DDL_DRIVER)

/* Includes ------------------------------------------------------------------*/
#include "g32m3101_ddl_comp.h"
#include "g32m3101_ddl_scu.h"

#ifdef  USE_FULL_ASSERT
#include "g32_assert.h"
#else
#define ASSERT_PARAM(_PARAM_) ((void)0U)
#endif /* USE_FULL_ASSERT */

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

/** @defgroup COMP_DDL_Private_Macros COMP Private Macros
  * @{
  */

 /* Check of parameters for configuration of COMP hierarchical scope:          */
    /* COMP instance.                                                             */

#define IS_COMP_ALL_SUBMODULE_INSTANCE(__COMP_SUBMODULE__)      \
    (   ((__COMP_SUBMODULE__) == COMP0) ||            \
        ((__COMP_SUBMODULE__) == COMP1)               \
    )

#define IS_DDL_COMP_INPUT_PLUS(__COMP_SUBMODULE__, __INPUT_PLUS__)     \
    (   ((__INPUT_PLUS__) == DDL_COMP_INPUT_PLUS_PA5_COMP0) ||       \
        ((__INPUT_PLUS__) == DDL_COMP_INPUT_PLUS_BG_1_4) ||        \
        ((__INPUT_PLUS__) == DDL_COMP_INPUT_PLUS_BG_1_2) ||        \
        ((__INPUT_PLUS__) == DDL_COMP_INPUT_PLUS_BG_3_4) ||        \
        ((__INPUT_PLUS__) == DDL_COMP_INPUT_PLUS_BG) ||            \
        ((__INPUT_PLUS__) == DDL_COMP_INPUT_PLUS_PA7_COMP0) ||           \
        ((__INPUT_PLUS__) == DDL_COMP_INPUT_PLUS_PB7_COMP0) ||           \
        ((__INPUT_PLUS__) == DDL_COMP_INPUT_PLUS_PA0_COMP1) ||       \
        ((__INPUT_PLUS__) == DDL_COMP_INPUT_PLUS_PB3_COMP1) ||           \
        ((__INPUT_PLUS__) == DDL_COMP_INPUT_PLUS_PB8_COMP1)              \
    )

#define IS_DDL_COMP_INPUT_MINUS(__COMP_SUBMODULE__, __INPUT_MINUS__)   \
    (   ((__INPUT_MINUS__) == DDL_COMP_INPUT_MINUS_PA9_COMP0) ||     \
        ((__INPUT_MINUS__) == DDL_COMP_INPUT_MINUS_PA8_COMP0) ||         \
        ((__INPUT_MINUS__) == DDL_COMP_INPUT_MINUS_PB0_COMP0) ||         \
        ((__INPUT_MINUS__) == DDL_COMP_INPUT_MINUS_PB1_COMP0) ||         \
        ((__INPUT_MINUS__) == DDL_COMP_INPUT_MINUS_PB2_COMP0) ||         \
        ((__INPUT_MINUS__) == DDL_COMP_INPUT_MINUS_OPAMP0_OUT_COMP0) ||    \
        ((__INPUT_MINUS__) == DDL_COMP_INPUT_MINUS_OPAMP1_OUT_COMP0) ||    \
        ((__INPUT_MINUS__) == DDL_COMP_INPUT_MINUS_PA1_COMP1) ||     \
        ((__INPUT_MINUS__) == DDL_COMP_INPUT_MINUS_PA2_COMP1) ||         \
        ((__INPUT_MINUS__) == DDL_COMP_INPUT_MINUS_PA5_COMP1) ||         \
        ((__INPUT_MINUS__) == DDL_COMP_INPUT_MINUS_OPAMP0_OUT_COMP1) ||    \
        ((__INPUT_MINUS__) == DDL_COMP_INPUT_MINUS_OPAMP1_OUT_COMP1) ||    \
        ((__INPUT_MINUS__) == DDL_COMP_INPUT_MINUS_PB4_COMP1) ||         \
        ((__INPUT_MINUS__) == DDL_COMP_INPUT_MINUS_PB5_COMP1) ||         \
        ((__INPUT_MINUS__) == DDL_COMP_INPUT_MINUS_PB6_COMP1)            \
    )

#define IS_DDL_COMP_OUTPUT_POLARITY(__POLARITY__)               \
    (   ((__POLARITY__) == DDL_COMP_OUTPUTPOL_NONINVERTED) ||   \
        ((__POLARITY__) == DDL_COMP_OUTPUTPOL_INVERTED)         \
    )

#define IS_DDL_COMP_OUTPUT_HYS(__HSY__)           \
    (   ((__HSY__) == DDL_COMP_HYS_DISABLE) ||    \
        ((__HSY__) == DDL_COMP_HYS_20MV) ||       \
        ((__HSY__) == DDL_COMP_HYS_40MV) ||       \
        ((__HSY__) == DDL_COMP_HYS_80MV)          \
    )

#define IS_DDL_COMP_OUTPUT_TMR_SEL(__TMRSEL__)             \
    (   ((__TMRSEL__) == DDL_COMP_TMR_SEL_NONE) ||         \
        ((__TMRSEL__) == DDL_COMP_TMR_SEL_ATMRBKIN) ||     \
        ((__TMRSEL__) == DDL_COMP_TMR_SEL_GTMRCC0) ||      \
        ((__TMRSEL__) == DDL_COMP_TMR_SEL_GTMRCC1) ||      \
        ((__TMRSEL__) == DDL_COMP_TMR_SEL_GTMRCC2) ||      \
        ((__TMRSEL__) == DDL_COMP_TMR_SEL_GTMRCC3) ||      \
        ((__TMRSEL__) == DDL_COMP_TMR_SEL_GTMRETR)         \
    )

#define IS_DDL_COMP_FILTER_CLOCK_DIV(__TMRSEL__)             \
    (   ((__TMRSEL__) == DDL_COMP_FILTER_CLOCK_DIV_0) ||     \
        ((__TMRSEL__) == DDL_COMP_FILTER_CLOCK_DIV_2) ||     \
        ((__TMRSEL__) == DDL_COMP_FILTER_CLOCK_DIV_4) ||     \
        ((__TMRSEL__) == DDL_COMP_FILTER_CLOCK_DIV_8) ||     \
        ((__TMRSEL__) == DDL_COMP_FILTER_CLOCK_DIV_16) ||    \
        ((__TMRSEL__) == DDL_COMP_FILTER_CLOCK_DIV_32) ||    \
        ((__TMRSEL__) == DDL_COMP_FILTER_CLOCK_DIV_64) ||    \
        ((__TMRSEL__) == DDL_COMP_FILTER_CLOCK_DIV_128)      \
    )

#define IS_DDL_COMP_FILTER_CLOCK_COUNT(__TMRSEL__)                 \
    (   ((__TMRSEL__) == DDL_COMP_FILTER_CLOCK_COUNT_0) ||       \
        ((__TMRSEL__) == DDL_COMP_FILTER_CLOCK_COUNT_2) ||       \
        ((__TMRSEL__) == DDL_COMP_FILTER_CLOCK_COUNT_4) ||       \
        ((__TMRSEL__) == DDL_COMP_FILTER_CLOCK_COUNT_8) ||       \
        ((__TMRSEL__) == DDL_COMP_FILTER_CLOCK_COUNT_16) ||      \
        ((__TMRSEL__) == DDL_COMP_FILTER_CLOCK_COUNT_32) ||      \
        ((__TMRSEL__) == DDL_COMP_FILTER_CLOCK_COUNT_64) ||      \
        ((__TMRSEL__) == DDL_COMP_FILTER_CLOCK_COUNT_128) ||     \
        ((__TMRSEL__) == DDL_COMP_FILTER_CLOCK_COUNT_256) ||     \
        ((__TMRSEL__) == DDL_COMP_FILTER_CLOCK_COUNT_512)        \
    )

/**
  * @}
  */

/* Private function prototypes -----------------------------------------------*/

/* Exported functions --------------------------------------------------------*/
/** @addtogroup COMP_DDL_Exported_Functions
  * @{
  */

/** @addtogroup COMP_DDL_EF_Init
  * @{
  */

/**
 * @brief  Initialize COMP function.
 * @param  COMPx COMP instance
 * @param  COMP_InitStruct Pointer to a @ref DDL_COMP_InitTypeDef structure
 * @retval An ErrorStatus enumeration value:
 *          - SUCCESS: COMP registers are initialized
 *          - ERROR: COMP registers are not initialized
 */
ErrorStatus DDL_COMP_Init(COMP_TypeDef *COMPx, DDL_COMP_InitTypeDef *COMP_InitStruct)
{
    ErrorStatus status = SUCCESS;

    /* Check parameters */
    ASSERT_PARAM(IS_COMP_ALL_SUBMODULE_INSTANCE(COMPx));
    ASSERT_PARAM(IS_DDL_COMP_INPUT_PLUS(COMPx, COMP_InitStruct->InputPlus));
    ASSERT_PARAM(IS_DDL_COMP_INPUT_MINUS(COMPx, COMP_InitStruct->InputMinus));
    ASSERT_PARAM(IS_DDL_COMP_OUTPUT_POLARITY(COMP_InitStruct->OutputPol));
    ASSERT_PARAM(IS_DDL_COMP_OUTPUT_HYS(COMP_InitStruct->PositiveHsy));
    ASSERT_PARAM(IS_DDL_COMP_OUTPUT_TMR_SEL(COMP_InitStruct->TmrSel));
    ASSERT_PARAM(IS_DDL_COMP_FILTER_CLOCK_DIV(COMP_InitStruct->FilterPsc));
    ASSERT_PARAM(IS_DDL_COMP_FILTER_CLOCK_COUNT(COMP_InitStruct->FilterCnt));

    /* COMP instance must not be locked */
    if (DDL_COMP_IsLocked(COMPx) == 0UL)
    {
        /* Configuration of comparator instance */
        MODIFY_REG(COMPx->CSTS,
                    COMP_CSTS_VP_EN |
                    COMP_CSTS_VN_EN |
                    COMP_CSTS_POL |
                    COMP_CSTS_HYS_EN |
                    COMP_CSTS_TMR_SEL |
                    COMP_CSTS_PSC |
                    COMP_CSTS_CFG,
                    COMP_InitStruct->InputPlus |
                    COMP_InitStruct->InputMinus |
                    COMP_InitStruct->OutputPol |
                    COMP_InitStruct->TmrSel |
                    COMP_InitStruct->PositiveHsy |
                    COMP_InitStruct->FilterPsc |
                    COMP_InitStruct->FilterCnt
        );
    }
    else
    {
        status = ERROR;
    }

    return status;
}

/**
 * @brief  De-Initialize COMP function.
 * @param  COMPx COMP instance
 * @retval An ErrorStatus enumeration value:
 *         - SUCCESS: COMP registers are de-initialized
 *         - ERROR: COMP registers are not de-initialized
 * @note   If COMP instance is locked, de-initialization can't be performed.
 *         The only way to unlock the COMP instance is to perform a system reset.
 */
ErrorStatus DDL_COMP_DeInit(COMP_TypeDef *COMPx)
{
    ErrorStatus status = SUCCESS;

    /* Check parameters */
    ASSERT_PARAM(IS_COMP_ALL_SUBMODULE_INSTANCE(COMPx));

    /* COMP instance must not be locked */
    if (DDL_COMP_IsLocked(COMPx) == 0UL)
    {
        /* De-initialize the COMP registers to the reset values */
        DDL_COMP_WriteReg((COMPx), CSTS, 0x00000000UL);
    }
    else
    {
        /* COMP instance is locked */
        /* The only way to unlock the COMP instance is to perform a system reset */
        status = ERROR;
    }

    return status;
}

/**
 * @brief  Set the fields of structure COMP_InitStruct to default values.
 * @param  COMP_InitStruct Pointer to a @ref DDL_COMP_InitTypeDef structure
 *                          whose fields will be set to default values.
 * @retval None
 */
void DDL_COMP_StructInit(DDL_COMP_InitTypeDef *COMP_InitStruct)
{
    /* Set COMP_InitStruct fields to default values */
    COMP_InitStruct->InputPlus      = DDL_COMP_INPUT_PLUS_PA5_COMP0;
    COMP_InitStruct->InputMinus     = DDL_COMP_INPUT_MINUS_PA9_COMP0;
    COMP_InitStruct->OutputPol      = DDL_COMP_OUTPUTPOL_NONINVERTED;
    COMP_InitStruct->TmrSel         = DDL_COMP_TMR_SEL_NONE;
    COMP_InitStruct->PositiveHsy    = DDL_COMP_HYS_DISABLE;
    COMP_InitStruct->FilterPsc      = DDL_COMP_FILTER_CLOCK_DIV_0;
    COMP_InitStruct->FilterCnt      = DDL_COMP_FILTER_CLOCK_COUNT_0;
}

/**
  * @}
  */

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

#endif /* USE_FULL_DDL_DRIVER */
