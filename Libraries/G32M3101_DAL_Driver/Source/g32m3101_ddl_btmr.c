/**
  *
  * @file        g32m3101_ddl_btmr.c
  *
  * @brief       BTMR DDL module driver.
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
  * Copyright (c) 2016 STMicroelectronics.
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
#include "g32m3101_ddl_btmr.h"
#include "g32m3101_ddl_scu.h"
#include "g32m3101_ddl_bus.h"

#ifdef  USE_FULL_ASSERT
#include "g32_assert.h"
#else
#define ASSERT_PARAM(_PARAM_) ((void)0U)
#endif /* USE_FULL_ASSERT */

/** @addtogroup G32M3101_DDL_Driver
  * @{
  */

#if defined (BTMR)

/** @addtogroup BTMR_DDL
  * @{
  */

/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private constants ---------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/
/** @addtogroup BTMR_DDL_Private_Macros
  * @{
  */
#define IS_DDL_BTMR_COUNTERMODE(__VALUE__) (((__VALUE__) == DDL_BTMR_COUNTERMODE_UP) \
                                          || ((__VALUE__) == DDL_BTMR_COUNTERMODE_DOWN) \
                                          || ((__VALUE__) == DDL_BTMR_COUNTERMODE_CENTER_UP) \
                                          || ((__VALUE__) == DDL_BTMR_COUNTERMODE_CENTER_DOWN) \
                                          || ((__VALUE__) == DDL_BTMR_COUNTERMODE_CENTER_UP_DOWN))

#define IS_DDL_BTMR_OCMODE(__VALUE__) (((__VALUE__) == DDL_BTMR_OCMODE_FROZEN) \
                                     || ((__VALUE__) == DDL_BTMR_OCMODE_ACTIVE) \
                                     || ((__VALUE__) == DDL_BTMR_OCMODE_INACTIVE) \
                                     || ((__VALUE__) == DDL_BTMR_OCMODE_TOGGLE) \
                                     || ((__VALUE__) == DDL_BTMR_OCMODE_FORCED_INACTIVE) \
                                     || ((__VALUE__) == DDL_BTMR_OCMODE_FORCED_ACTIVE) \
                                     || ((__VALUE__) == DDL_BTMR_OCMODE_PWM1) \
                                     || ((__VALUE__) == DDL_BTMR_OCMODE_PWM2))

#define IS_DDL_BTMR_OCSTATE(__VALUE__) (((__VALUE__) == DDL_BTMR_OCSTATE_DISABLE) \
                                      || ((__VALUE__) == DDL_BTMR_OCSTATE_ENABLE))

#define IS_DDL_BTMR_OCPOLARITY(__VALUE__) (((__VALUE__) == DDL_BTMR_POLARITY_HIGH) \
                                         || ((__VALUE__) == DDL_BTMR_POLARITY_LOW))

#define IS_DDL_BTMR_IC_FILTER(__VALUE__) (((__VALUE__) == DDL_BTMR_IC_FILTER_PCLK_0) \
                                        || ((__VALUE__) == DDL_BTMR_IC_FILTER_PCLK_1) \
                                        || ((__VALUE__) == DDL_BTMR_IC_FILTER_PCLK_2) \
                                        || ((__VALUE__) == DDL_BTMR_IC_FILTER_PCLK_3) \
                                        || ((__VALUE__) == DDL_BTMR_IC_FILTER_PCLK_4) \
                                        || ((__VALUE__) == DDL_BTMR_IC_FILTER_PCLK_5) \
                                        || ((__VALUE__) == DDL_BTMR_IC_FILTER_PCLK_6) \
                                        || ((__VALUE__) == DDL_BTMR_IC_FILTER_PCLK_7))

#define IS_DDL_BTMR_ICPOLARITY(__VALUE__) (((__VALUE__) == DDL_BTMR_POLARITY_HIGH) \
                                         || ((__VALUE__) == DDL_BTMR_POLARITY_LOW))

#define IS_DDL_BTMR_IC_EDGE(__VALUE__) (((__VALUE__) == DDL_BTMR_IC_EDGE_RISING) \
                                          || ((__VALUE__) == DDL_BTMR_IC_EDGE_FALLING) \
                                          || ((__VALUE__) == DDL_BTMR_IC_EDGE_BOTHEDGE))

/**
  * @}
  */


/* Private function prototypes -----------------------------------------------*/
/** @defgroup BTMR_DDL_Private_Functions BTMR Private Functions
  * @{
  */
static ErrorStatus OC0Config(BTMR_TypeDef *BTMRx, DDL_BTMR_OC_InitTypeDef *BTMR_OCInitStruct);
static ErrorStatus OC1Config(BTMR_TypeDef *BTMRx, DDL_BTMR_OC_InitTypeDef *BTMR_OCInitStruct);
static ErrorStatus OC2Config(BTMR_TypeDef *BTMRx, DDL_BTMR_OC_InitTypeDef *BTMR_OCInitStruct);
static ErrorStatus IC0Config(BTMR_TypeDef *BTMRx, DDL_BTMR_IC_InitTypeDef *BTMR_ICInitStruct);
static ErrorStatus IC1Config(BTMR_TypeDef *BTMRx, DDL_BTMR_IC_InitTypeDef *BTMR_ICInitStruct);
static ErrorStatus IC2Config(BTMR_TypeDef *BTMRx, DDL_BTMR_IC_InitTypeDef *BTMR_ICInitStruct);
/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/** @addtogroup BTMR_DDL_Exported_Functions
  * @{
  */

/** @addtogroup BTMR_DDL_EF_Init
  * @{
  */

/**
  * @brief  Set BTMRx registers to their reset values.
  * @param  BTMRx Timer instance
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS: BTMRx registers are de-initialized
  *          - ERROR: invalid BTMRx instance
  */
ErrorStatus DDL_BTMR_DeInit(BTMR_TypeDef *BTMRx)
{
  ErrorStatus result = SUCCESS;

  /* Check the parameters */
  ASSERT_PARAM(IS_BTMR_INSTANCE(BTMRx));

  DDL_SCU_Unlock();
  if (BTMRx == BTMR)
  {
    DDL_APB_GRP1_ForceReset(DDL_APB_GRP1_PERIPH_BTMR);
    DDL_APB_GRP1_ReleaseReset(DDL_APB_GRP1_PERIPH_BTMR);
  }
  else
  {
    result = ERROR;
  }

  DDL_SCU_Lock();
  return result;
}

/**
  * @brief  Set the fields of the time base unit configuration data structure
  *         to their default values.
  * @param  BTMR_InitStruct pointer to a @ref DDL_BTMR_InitTypeDef structure (time base unit configuration data structure)
  * @retval None
  */
void DDL_BTMR_StructInit(DDL_BTMR_InitTypeDef *BTMR_InitStruct)
{
  /* Set the default configuration */
  BTMR_InitStruct->Prescaler         = (uint16_t)0x0000;
  BTMR_InitStruct->CounterMode       = DDL_BTMR_COUNTERMODE_UP;
  BTMR_InitStruct->Autoreload        = 0xFFFFU;
}

/**
  * @brief  Configure the BTMRx time base unit.
  * @param  BTMRx Timer Instance
  * @param  BTMR_InitStruct pointer to a @ref DDL_BTMR_InitTypeDef structure
  *         (BTMRx time base unit configuration data structure)
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS: BTMRx registers are initialized
  *          - ERROR: not applicable
  */
ErrorStatus DDL_BTMR_Init(BTMR_TypeDef *BTMRx, DDL_BTMR_InitTypeDef *BTMR_InitStruct)
{
  uint32_t tmpcr1;

  /* Check the parameters */
  ASSERT_PARAM(IS_BTMR_INSTANCE(BTMRx));
  ASSERT_PARAM(IS_DDL_BTMR_COUNTERMODE(BTMR_InitStruct->CounterMode));

  tmpcr1 = DDL_BTMR_ReadReg(BTMRx, CTRL1);

  if (IS_BTMR_COUNTER_MODE_SELECT_INSTANCE(BTMRx))
  {
    /* Select the Counter Mode */
    MODIFY_REG(tmpcr1, (BTMR_CTRL1_CNTDIR | BTMR_CTRL1_CAMSEL), BTMR_InitStruct->CounterMode);
  }

  /* Write to BTMRx CTRL1 */
  DDL_BTMR_WriteReg(BTMRx, CTRL1, tmpcr1);

  /* Set the Autoreload value */
  DDL_BTMR_SetAutoReload(BTMRx, BTMR_InitStruct->Autoreload);

  /* Set the Prescaler value */
  DDL_BTMR_SetPrescaler(BTMRx, BTMR_InitStruct->Prescaler);

  /* Generate an update event to reload the Prescaler
     and the autoreload value (if applicable) immediately */
  DDL_BTMR_GenerateEvent_UPDATE(BTMRx);

  return SUCCESS;
}

/**
  * @brief  Set the fields of the BTMRx output channel configuration data
  *         structure to their default values.
  * @param  BTMR_OC_InitStruct pointer to a @ref DDL_BTMR_OC_InitTypeDef structure
  *         (the output channel configuration data structure)
  * @retval None
  */
void DDL_BTMR_OC_StructInit(DDL_BTMR_OC_InitTypeDef *BTMR_OC_InitStruct)
{
  /* Set the default configuration */
  BTMR_OC_InitStruct->OCMode       = DDL_BTMR_OCMODE_FROZEN;
  BTMR_OC_InitStruct->OCState      = DDL_BTMR_OCSTATE_DISABLE;
  BTMR_OC_InitStruct->CompareValue = 0x00000000U;
  BTMR_OC_InitStruct->OCPolarity   = DDL_BTMR_POLARITY_HIGH;
}

/**
  * @brief  Configure the BTMRx output channel.
  * @param  BTMRx Timer Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref DDL_BTMR_CHANNEL_CH0
  *         @arg @ref DDL_BTMR_CHANNEL_CH1
  *         @arg @ref DDL_BTMR_CHANNEL_CH2
  * @param  BTMR_OC_InitStruct pointer to a @ref DDL_BTMR_OC_InitTypeDef structure (BTMRx output channel configuration
  *         data structure)
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS: BTMRx output channel is initialized
  *          - ERROR: BTMRx output channel is not initialized
  */
ErrorStatus DDL_BTMR_OC_Init(BTMR_TypeDef *BTMRx, uint32_t Channel, DDL_BTMR_OC_InitTypeDef *BTMR_OC_InitStruct)
{
  ErrorStatus result = ERROR;

  switch (Channel)
  {
    case DDL_BTMR_CHANNEL_CH0:
      result = OC0Config(BTMRx, BTMR_OC_InitStruct);
      break;
    case DDL_BTMR_CHANNEL_CH1:
      result = OC1Config(BTMRx, BTMR_OC_InitStruct);
      break;
    case DDL_BTMR_CHANNEL_CH2:
      result = OC2Config(BTMRx, BTMR_OC_InitStruct);
      break;
    default:
      break;
  }

  return result;
}

/**
  * @brief  Set the fields of the BTMRx input channel configuration data
  *         structure to their default values.
  * @param  BTMR_ICInitStruct pointer to a @ref DDL_BTMR_IC_InitTypeDef structure (the input channel configuration
  *         data structure)
  * @retval None
  */
void DDL_BTMR_IC_StructInit(DDL_BTMR_IC_InitTypeDef *BTMR_ICInitStruct)
{
  /* Set the default configuration */
  BTMR_ICInitStruct->ICPolarity    = DDL_BTMR_POLARITY_HIGH;
  BTMR_ICInitStruct->ICEdge        = DDL_BTMR_IC_EDGE_RISING;
  BTMR_ICInitStruct->ICFilter      = DDL_BTMR_IC_FILTER_PCLK_0;
}

/**
  * @brief  Configure the BTMRx input channel.
  * @param  BTMRx Timer Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref DDL_BTMR_CHANNEL_CH0
  *         @arg @ref DDL_BTMR_CHANNEL_CH1
  *         @arg @ref DDL_BTMR_CHANNEL_CH2
  * @param  BTMR_IC_InitStruct pointer to a @ref DDL_BTMR_IC_InitTypeDef structure (BTMRx input channel configuration data
  *         structure)
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS: BTMRx input channel is initialized
  *          - ERROR: BTMRx input channel is not initialized
  */
ErrorStatus DDL_BTMR_IC_Init(BTMR_TypeDef *BTMRx, uint32_t Channel, DDL_BTMR_IC_InitTypeDef *BTMR_IC_InitStruct)
{
  ErrorStatus result = ERROR;

  switch (Channel)
  {
    case DDL_BTMR_CHANNEL_CH0:
      result = IC0Config(BTMRx, BTMR_IC_InitStruct);
      break;
    case DDL_BTMR_CHANNEL_CH1:
      result = IC1Config(BTMRx, BTMR_IC_InitStruct);
      break;
    case DDL_BTMR_CHANNEL_CH2:
      result = IC2Config(BTMRx, BTMR_IC_InitStruct);
      break;
    default:
      break;
  }

  return result;
}

/**
  * @}
  */

/**
  * @}
  */

/** @addtogroup BTMR_DDL_Private_Functions BTMR Private Functions
  *  @brief   Private functions
  * @{
  */
/**
  * @brief  Configure the BTMRx output channel 0.
  * @param  BTMRx Timer Instance
  * @param  BTMR_OCInitStruct pointer to the the BTMRx output channel 0 configuration data structure
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS: BTMRx registers are initialized
  *          - ERROR: not applicable
  */
static ErrorStatus OC0Config(BTMR_TypeDef *BTMRx, DDL_BTMR_OC_InitTypeDef *BTMR_OCInitStruct)
{
  uint32_t tmpccm1;
  uint32_t tmpccm2;

  /* Check the parameters */
  ASSERT_PARAM(IS_BTMR_CC0_INSTANCE(BTMRx));
  ASSERT_PARAM(IS_DDL_BTMR_OCMODE(BTMR_OCInitStruct->OCMode));
  ASSERT_PARAM(IS_DDL_BTMR_OCSTATE(BTMR_OCInitStruct->OCState));
  ASSERT_PARAM(IS_DDL_BTMR_OCPOLARITY(BTMR_OCInitStruct->OCPolarity));

  /* Disable the Channel 0: Reset the CC0E Bit */
  CLEAR_BIT(BTMRx->CCM1, BTMR_CCM1_CC0EN);

  /* Get the BTMRx CCM1 register value */
  tmpccm1 = DDL_BTMR_ReadReg(BTMRx, CCM1);

  /* Get the BTMRx CCM2 register value */
  tmpccm2 = DDL_BTMR_ReadReg(BTMRx, CCM2);

  /* SET Capture/Compare selection Bits */
  SET_BIT(tmpccm2, BTMR_CCM2_CC0_IOSEL);

  /* Set the Output Compare Mode */
  MODIFY_REG(tmpccm1, BTMR_CCM1_OC0MOD, BTMR_OCInitStruct->OCMode << (BTMR_CCM1_OC0MOD_Pos-BTMR_CCM1_OC0MOD_Pos));

  /* Set the Output Compare Polarity */
  MODIFY_REG(tmpccm1, BTMR_CCM1_CC0POL, BTMR_OCInitStruct->OCPolarity << (BTMR_CCM1_CC0POL_Pos-BTMR_CCM1_CC0POL_Pos));

  /* Set the Output State */
  MODIFY_REG(tmpccm1, BTMR_CCM1_CC0EN, BTMR_OCInitStruct->OCState << (BTMR_CCM1_CC0EN_Pos-BTMR_CCM1_CC0EN_Pos));

  /* Write to BTMRx CCM2 */
  DDL_BTMR_WriteReg(BTMRx, CCM2, tmpccm2);

  /* Set the Capture Compare Register value */
  DDL_BTMR_OC_SetCompareCH0(BTMRx, BTMR_OCInitStruct->CompareValue);

  /* Write to BTMRx CCM1 */
  DDL_BTMR_WriteReg(BTMRx, CCM1, tmpccm1);

  return SUCCESS;
}

/**
  * @brief  Configure the BTMRx output channel 1.
  * @param  BTMRx Timer Instance
  * @param  BTMR_OCInitStruct pointer to the the BTMRx output channel 1 configuration data structure
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS: BTMRx registers are initialized
  *          - ERROR: not applicable
  */
static ErrorStatus OC1Config(BTMR_TypeDef *BTMRx, DDL_BTMR_OC_InitTypeDef *BTMR_OCInitStruct)
{
  uint32_t tmpccm1;
  uint32_t tmpccm2;

  /* Check the parameters */
  ASSERT_PARAM(IS_BTMR_CC1_INSTANCE(BTMRx));
  ASSERT_PARAM(IS_DDL_BTMR_OCMODE(BTMR_OCInitStruct->OCMode));
  ASSERT_PARAM(IS_DDL_BTMR_OCSTATE(BTMR_OCInitStruct->OCState));
  ASSERT_PARAM(IS_DDL_BTMR_OCPOLARITY(BTMR_OCInitStruct->OCPolarity));

  /* Disable the Channel 1: Reset the CC1E Bit */
  CLEAR_BIT(BTMRx->CCM1, BTMR_CCM1_CC1EN);

  /* Get the BTMRx CCM1 register value */
  tmpccm1 = DDL_BTMR_ReadReg(BTMRx, CCM1);

  /* Get the BTMRx CCM2 register value */
  tmpccm2 = DDL_BTMR_ReadReg(BTMRx, CCM2);

  /* SET Capture/Compare selection Bits */
  SET_BIT(tmpccm2, BTMR_CCM2_CC1_IOSEL);

  /* Set the Output Compare Mode */
  MODIFY_REG(tmpccm1, BTMR_CCM1_OC1MOD, BTMR_OCInitStruct->OCMode << (BTMR_CCM1_OC1MOD_Pos-BTMR_CCM1_OC0MOD_Pos));

  /* Set the Output Compare Polarity */
  MODIFY_REG(tmpccm1, BTMR_CCM1_CC1POL, BTMR_OCInitStruct->OCPolarity << (BTMR_CCM1_CC1POL_Pos-BTMR_CCM1_CC0POL_Pos));

  /* Set the Output State */
  MODIFY_REG(tmpccm1, BTMR_CCM1_CC1EN, BTMR_OCInitStruct->OCState << (BTMR_CCM1_CC1EN_Pos-BTMR_CCM1_CC0EN_Pos));

  /* Write to BTMRx CCM2 */
  DDL_BTMR_WriteReg(BTMRx, CCM2, tmpccm2);

  /* Set the Capture Compare Register value */
  DDL_BTMR_OC_SetCompareCH1(BTMRx, BTMR_OCInitStruct->CompareValue);

  /* Write to BTMRx CCM1 */
  DDL_BTMR_WriteReg(BTMRx, CCM1, tmpccm1);

  return SUCCESS;
}

/**
  * @brief  Configure the BTMRx output channel 2.
  * @param  BTMRx Timer Instance
  * @param  BTMR_OCInitStruct pointer to the the BTMRx output channel 2 configuration data structure
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS: BTMRx registers are initialized
  *          - ERROR: not applicable
  */
static ErrorStatus OC2Config(BTMR_TypeDef *BTMRx, DDL_BTMR_OC_InitTypeDef *BTMR_OCInitStruct)
{
  uint32_t tmpccm1;
  uint32_t tmpccm2;

  /* Check the parameters */
  ASSERT_PARAM(IS_BTMR_CC2_INSTANCE(BTMRx));
  ASSERT_PARAM(IS_DDL_BTMR_OCMODE(BTMR_OCInitStruct->OCMode));
  ASSERT_PARAM(IS_DDL_BTMR_OCSTATE(BTMR_OCInitStruct->OCState));
  ASSERT_PARAM(IS_DDL_BTMR_OCPOLARITY(BTMR_OCInitStruct->OCPolarity));

  /* Disable the Channel 2: Reset the CC2E Bit */
  CLEAR_BIT(BTMRx->CCM1, BTMR_CCM1_CC2EN);

  /* Get the BTMRx CCM1 register value */
  tmpccm1 = DDL_BTMR_ReadReg(BTMRx, CCM1);

  /* Get the BTMRx CCM2 register value */
  tmpccm2 = DDL_BTMR_ReadReg(BTMRx, CCM2);

  /* SET Capture/Compare selection Bits */
  SET_BIT(tmpccm2, BTMR_CCM2_CC2_IOSEL);

  /* Set the Output Compare Mode */
  MODIFY_REG(tmpccm1, BTMR_CCM1_OC2MOD, BTMR_OCInitStruct->OCMode << (BTMR_CCM1_OC2MOD_Pos-BTMR_CCM1_OC0MOD_Pos));

  /* Set the Output Compare Polarity */
  MODIFY_REG(tmpccm1, BTMR_CCM1_CC2POL, BTMR_OCInitStruct->OCPolarity << (BTMR_CCM1_CC2POL_Pos-BTMR_CCM1_CC0POL_Pos));

  /* Set the Output State */
  MODIFY_REG(tmpccm1, BTMR_CCM1_CC2EN, BTMR_OCInitStruct->OCState << (BTMR_CCM1_CC2EN_Pos-BTMR_CCM1_CC0EN_Pos));

  /* Write to BTMRx CCM2 */
  DDL_BTMR_WriteReg(BTMRx, CCM2, tmpccm2);

  /* Set the Capture Compare Register value */
  DDL_BTMR_OC_SetCompareCH2(BTMRx, BTMR_OCInitStruct->CompareValue);

  /* Write to BTMRx CCM1 */
  DDL_BTMR_WriteReg(BTMRx, CCM1, tmpccm1);

  return SUCCESS;
}

/**
  * @brief  Configure the BTMRx input channel 0.
  * @param  BTMRx Timer Instance
  * @param  BTMR_ICInitStruct pointer to the the BTMRx input channel 0 configuration data structure
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS: BTMRx registers are initialized
  *          - ERROR: not applicable
  */
static ErrorStatus IC0Config(BTMR_TypeDef *BTMRx, DDL_BTMR_IC_InitTypeDef *BTMR_ICInitStruct)
{
  uint8_t iChannel;
  /* Check the parameters */
  ASSERT_PARAM(IS_BTMR_CC0_INSTANCE(BTMRx));
  ASSERT_PARAM(IS_DDL_BTMR_ICPOLARITY(BTMR_ICInitStruct->ICPolarity));
  ASSERT_PARAM(IS_DDL_BTMR_IC_EDGE(BTMR_ICInitStruct->ICEdge));
  ASSERT_PARAM(IS_DDL_BTMR_IC_FILTER(BTMR_ICInitStruct->ICFilter));

  iChannel = BTMR_GET_CHANNEL_INDEX(DDL_BTMR_CHANNEL_CH0);
  /* Disable the Channel 0: Reset the CC0E Bit */
  BTMRx->CCM1 &= (uint32_t)~BTMR_CCM1_CC0EN;

  /* Reset Capture/Compare selection Bits */
  CLEAR_BIT(BTMRx->CCM2, BTMR_CCM2_CC0_IOSEL);

  /* Select the Input and set the filter and the active edge of the input signal */
  MODIFY_REG(BTMRx->CCM1,
             (BTMR_CCM1_IC0F | BTMR_CCM1_CC0_EDGE_SEL),
             (BTMR_ICInitStruct->ICFilter | BTMR_ICInitStruct->ICEdge) << SHIFT_TAB_BTMR_OCxx[iChannel]);

  /* Select the Polarity and set the CC0E Bit */
  MODIFY_REG(BTMRx->CCM1,
             (BTMR_CCM1_CC0POL),
             (BTMR_ICInitStruct->ICPolarity << SHIFT_TAB_BTMR_OCxx[iChannel]) | BTMR_CCM1_CC0EN);

  return SUCCESS;
}

/**
  * @brief  Configure the BTMRx input channel 1.
  * @param  BTMRx Timer Instance
  * @param  BTMR_ICInitStruct pointer to the the BTMRx input channel 1 configuration data structure
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS: BTMRx registers are initialized
  *          - ERROR: not applicable
  */
static ErrorStatus IC1Config(BTMR_TypeDef *BTMRx, DDL_BTMR_IC_InitTypeDef *BTMR_ICInitStruct)
{
  uint8_t iChannel;
  /* Check the parameters */
  ASSERT_PARAM(IS_BTMR_CC1_INSTANCE(BTMRx));
  ASSERT_PARAM(IS_DDL_BTMR_ICPOLARITY(BTMR_ICInitStruct->ICPolarity));
  ASSERT_PARAM(IS_DDL_BTMR_IC_EDGE(BTMR_ICInitStruct->ICEdge));
  ASSERT_PARAM(IS_DDL_BTMR_IC_FILTER(BTMR_ICInitStruct->ICFilter));

  iChannel = BTMR_GET_CHANNEL_INDEX(DDL_BTMR_CHANNEL_CH1);
  /* Disable the Channel 1: Reset the CC1E Bit */
  BTMRx->CCM1 &= (uint32_t)~BTMR_CCM1_CC1EN;

  /* Reset Capture/Compare selection Bits */
  CLEAR_BIT(BTMRx->CCM2, BTMR_CCM2_CC1_IOSEL);

  /* Select the Input and set the filter and the active edge of the input signal */
  MODIFY_REG(BTMRx->CCM1,
             (BTMR_CCM1_IC1F | BTMR_CCM1_CC1_EDGE_SEL),
             (BTMR_ICInitStruct->ICFilter | BTMR_ICInitStruct->ICEdge) << SHIFT_TAB_BTMR_OCxx[iChannel]);

  /* Select the Polarity and set the CC1E Bit */
  MODIFY_REG(BTMRx->CCM1,
             (BTMR_CCM1_CC1POL),
             (BTMR_ICInitStruct->ICPolarity << SHIFT_TAB_BTMR_OCxx[iChannel]) | BTMR_CCM1_CC1EN);

  return SUCCESS;
}

/**
  * @brief  Configure the BTMRx input channel 2.
  * @param  BTMRx Timer Instance
  * @param  BTMR_ICInitStruct pointer to the the BTMRx input channel 2 configuration data structure
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS: BTMRx registers are initialized
  *          - ERROR: not applicable
  */
static ErrorStatus IC2Config(BTMR_TypeDef *BTMRx, DDL_BTMR_IC_InitTypeDef *BTMR_ICInitStruct)
{
  uint8_t iChannel;
  /* Check the parameters */
  ASSERT_PARAM(IS_BTMR_CC2_INSTANCE(BTMRx));
  ASSERT_PARAM(IS_DDL_BTMR_ICPOLARITY(BTMR_ICInitStruct->ICPolarity));
  ASSERT_PARAM(IS_DDL_BTMR_IC_EDGE(BTMR_ICInitStruct->ICEdge));
  ASSERT_PARAM(IS_DDL_BTMR_IC_FILTER(BTMR_ICInitStruct->ICFilter));

  iChannel = BTMR_GET_CHANNEL_INDEX(DDL_BTMR_CHANNEL_CH2);
  /* Disable the Channel 2: Reset the CC2E Bit */
  BTMRx->CCM1 &= (uint32_t)~BTMR_CCM1_CC2EN;

  /* Reset Capture/Compare selection Bits */
  CLEAR_BIT(BTMRx->CCM2, BTMR_CCM2_CC2_IOSEL);

  /* Select the Input and set the filter and the active edge of the input signal */
  MODIFY_REG(BTMRx->CCM1,
             (BTMR_CCM1_IC2F | BTMR_CCM1_CC2_EDGE_SEL),
             (BTMR_ICInitStruct->ICFilter | BTMR_ICInitStruct->ICEdge) << SHIFT_TAB_BTMR_OCxx[iChannel]);

  /* Select the Polarity and set the CC2E Bit */
  MODIFY_REG(BTMRx->CCM1,
             (BTMR_CCM1_CC2POL),
             (BTMR_ICInitStruct->ICPolarity << SHIFT_TAB_BTMR_OCxx[iChannel]) | BTMR_CCM1_CC2EN);

  return SUCCESS;
}

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

#endif /* USE_FULL_DDL_DRIVER */
