/**
  *
  * @file        g32m3101_ddl_scu.c
  *
  * @brief       SCU DDL module driver.
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
  * This software is licensed under terms that can be found in the LICENSE file in
  * the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  */
#if defined(USE_FULL_DDL_DRIVER)

/* Includes ------------------------------------------------------------------*/
#include "g32m3101_ddl_scu.h"

#ifdef  USE_FULL_ASSERT
#include "g32_assert.h"
#else
#define ASSERT_PARAM(_PARAM_) ((void)0U)
#endif /* USE_FULL_ASSERT */

/** @addtogroup G32M3101_DDL_Driver
  * @{
  */

#if defined(SCU)

/** @addtogroup SCU_DDL
  * @{
  */

/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private constants ---------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/
/** @addtogroup SCU_DDL_Private_Macros
  * @{
  */

/**
  * @}
  */

/* Private function prototypes -----------------------------------------------*/
/** @defgroup SCU_DDL_Private_Functions SCU Private functions
  * @{
  */
static uint32_t SCU_GetSystemClockFreq(void);
static uint32_t SCU_GetHCLKClockFreq(uint32_t SYSCLK_Frequency);
static uint32_t SCU_GetPCLKClockFreq(uint32_t HCLK_Frequency);
/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/** @addtogroup SCU_DDL_Exported_Functions
  * @{
  */

/** @addtogroup SCU_DDL_EF_Init
  * @{
  */

/**
  * @brief  Reset the SCU clock configuration to the default reset state.
  * @note   The default reset state of the clock configuration is given below:
  *         - HSI clock is ON and used as system clock source
  *         - AHB, APB prescaler are divided by 1.
  *         - MCO OFF
  *         - All interrupts disabled
  * @note   This function doesn't modify the configuration of the
  *         - Peripheral clocks
  *         - LSI, RTC clocks
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS: SCU registers are de-initialized
  *          - ERROR: not applicable
  */
ErrorStatus DDL_SCU_DeInit(void)
{
  DDL_SCU_Unlock();

  /* If LSI clock is set as system clock source, switch to HSI clock*/
  if(DDL_SCU_GetSysClkSource())
  {
    if(!DDL_SCU_HSI_IsReady())
    {
      /* Enable HSI clock */
      DDL_SCU_HSI_Enable();
      /* Wait for HSI clock ready */
      while(DDL_SCU_HSI_IsReady() != 1U)
      {}
    }
    /* Set HSI clock as system source clock */
    DDL_SCU_SetSysClkSource(DDL_SCU_SYSCLK_SOURCE_HSI);
    while(DDL_SCU_GetSysClkSource() != SCU_SCCR_SWST_HSI)
    {}
  }
  else
  {
  }

  /* Disable all interrupts */
  WRITE_REG(SCU->CIER, 0x00000000U);
  /* Clear all interrupt flags */
  WRITE_REG(SCU->CICR, 0x00000000U);
  /* Clear all reset flags, disable PVD reset, disable LOCKUP reset */
  WRITE_REG(SCU->RSTCSR, 0x00000000U);
  /* Clear all division and MCO configuration */
  WRITE_REG(SCU->SCCR, 0x00000000U);

  DDL_SCU_Lock();
  return SUCCESS;
}

/**
  * @}
  */

/** @addtogroup SCU_DDL_EF_Get_Freq
  * @{
  */

/**
  * @brief  Return the frequencies of different on chip clocks;  System, AHB, APB buses clocks
  * @note   Each time SYSCLK, HCLK, PCLK clock changes, this function
  *         must be called to update structure fields. Otherwise, any
  *         configuration based on this function will be incorrect.
  * @param  SCU_Clocks pointer to a @ref DDL_SCU_ClocksTypeDef structure which will hold the clocks frequencies
  * @retval None
  */
void DDL_SCU_GetSysctrlClocksFreq(DDL_SCU_ClocksTypeDef *SCU_Clocks)
{
  /* Get SYSCLK frequency */
  SCU_Clocks->SYSCLK_Frequency = SCU_GetSystemClockFreq();

  /* HCLK clock frequency */
  SCU_Clocks->HCLK_Frequency   = SCU_GetHCLKClockFreq(SCU_Clocks->SYSCLK_Frequency);

  /* PCLK clock frequency */
  SCU_Clocks->PCLK_Frequency  = SCU_GetPCLKClockFreq(SCU_Clocks->HCLK_Frequency);
}

/**
  * @}
  */



/** @addtogroup SCU_DDL_Private_Functions
  * @{
  */

/**
  * @brief  Return SYSTEM clock frequency
  * @retval SYSTEM clock frequency (in Hz)
  */
static uint32_t SCU_GetSystemClockFreq(void)
{
  uint32_t frequency = 0U;

  /* Get SYSCLK source -------------------------------------------------------*/
  switch (DDL_SCU_GetSysClkSource())
  {
    case DDL_SCU_SYSCLK_SOURCE_HSI:  /* HSI used as system clock source */
      frequency = HSI_VALUE;
      break;

    case DDL_SCU_SYSCLK_SOURCE_LSI:  /* LSI used as system clock source */
      frequency = LSI_VALUE;
      break;

    default:
      frequency = HSI_VALUE;
      break;
  }

  return frequency;
}

/**
  * @brief  Return HCLK clock frequency
  * @param  SYSCLK_Frequency SYSCLK clock frequency
  * @retval HCLK clock frequency (in Hz)
  */
static uint32_t SCU_GetHCLKClockFreq(uint32_t SYSCLK_Frequency)
{
  /* HCLK clock frequency */
  return __DDL_SCU_CALC_HCLK_FREQ(SYSCLK_Frequency, DDL_SCU_GetAHBPrescaler());
}

/**
  * @brief  Return PCLK clock frequency
  * @param  HCLK_Frequency HCLK clock frequency
  * @retval PCLK clock frequency (in Hz)
  */
static uint32_t SCU_GetPCLKClockFreq(uint32_t HCLK_Frequency)
{
  /* PCLK clock frequency */
  return __DDL_SCU_CALC_PCLK_FREQ(HCLK_Frequency, DDL_SCU_GetAPBPrescaler());
}


/**
  * @}
  */

/**
  * @}
  */

#endif /* SCU */

/**
  * @}
  */

#endif /* USE_FULL_DDL_DRIVER */
