/**
  *
  * @file        g32m3101_ddl_utils.h
  *
  * @brief       Header file of UTILS DDL module.
  *
  * @version     V1.0.2
  *
  * @date        2026-10-19
  *
  @verbatim
  ==============================================================================
                     ##### How to use this driver #####
  ==============================================================================
    [..]
    The LL UTILS driver contains a set of generic APIs that can be
    used by user:
      (+) Device electronic signature
      (+) Timing functions
      (+) PLL configuration functions

  @endverbatim
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
#ifndef G32M3101_DDL_UTILS_H
#define G32M3101_DDL_UTILS_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "g32m3xxx.h"
#include "Legacy/g32_ddl_legacy.h"

/** @addtogroup G32M3101_DDL_Driver
  * @{
  */

/** @defgroup UTILS_DDL UTILS
  * @{
  */

/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/

/* Private constants ---------------------------------------------------------*/
/** @defgroup UTILS_DDL_Private_Constants UTILS Private Constants
  * @{
  */

/* Max delay can be used in DDL_mDelay */
#define DDL_MAX_DELAY                 0xFFFFFFFFU

/**
 * @brief Unique device ID register base address
 */
#define UID_BASE_ADDRESS              UID_BASE

/**
 * @brief PID register base address
 */
#define PID_BASE_ADDRESS              PID_BASE

/**
  * @}
  */

/* Private macros ------------------------------------------------------------*/
/** @defgroup UTILS_DDL_Private_Macros UTILS Private Macros
  * @{
  */
/**
  * @}
  */
/* Exported types ------------------------------------------------------------*/
/** @defgroup UTILS_DDL_ES_INIT UTILS Exported structures
  * @{
  */

/**
  * @brief  UTILS System, AHB and APB buses clock configuration structure definition
  */
typedef struct
{
  uint32_t AHBCLKDivider;         /*!< The AHB clock (HCLK) divider. This clock is derived from the system clock (SYSCLK).
                                       This parameter can be a value of @ref DDL_SCU_AHB_DIV

                                       This feature can be modified afterwards using unitary function
                                       @ref DDL_SCU_SetAHBPrescaler(). */

  uint32_t APBCLKDivider;        /*!< The APB1 clock (PCLK) divider. This clock is derived from the AHB clock (HCLK).
                                       This parameter can be a value of @ref DDL_SCU_APB_DIV

                                       This feature can be modified afterwards using unitary function
                                       @ref DDL_SCU_SetAPBPrescaler(). */

} DDL_UTILS_ClkInitTypeDef;

/**
  * @}
  */

/* Exported constants --------------------------------------------------------*/
/** @defgroup UTILS_DDL_Exported_Constants UTILS Exported Constants
  * @{
  */

/**
  * @}
  */

/* Exported macro ------------------------------------------------------------*/

/* Exported functions --------------------------------------------------------*/
/** @defgroup UTILS_DDL_Exported_Functions UTILS Exported Functions
  * @{
  */

/** @defgroup UTILS_EF_DEVICE_ELECTRONIC_SIGNATURE DEVICE ELECTRONIC SIGNATURE
  * @{
  */
/**
  * @brief  Get Word0 of the unique device identifier (UID based on 96 bits)
  * @retval UID[31:0]
  */
__STATIC_INLINE uint32_t DDL_GetUID_Word0(void)
{
  return (uint32_t)(READ_REG(*((uint32_t *)(uintptr_t)UID_BASE_ADDRESS)));
}

/**
  * @brief  Get Word1 of the unique device identifier (UID based on 96 bits)
  * @retval UID[63:32]
  */
__STATIC_INLINE uint32_t DDL_GetUID_Word1(void)
{
  return (uint32_t)(READ_REG(*((uint32_t *)(uintptr_t)(UID_BASE_ADDRESS + 4U))));
}

/**
  * @brief  Get Word2 of the unique device identifier (UID based on 96 bits)
  * @retval UID[95:64]
  */
__STATIC_INLINE uint32_t DDL_GetUID_Word2(void)
{
  return (uint32_t)(READ_REG(*((uint32_t *)(uintptr_t)(UID_BASE_ADDRESS + 8U))));
}

/**
  * @brief  Get Word3 of the unique device identifier (UID based on 128 bits)
  * @retval UID[127:96]
  */
__STATIC_INLINE uint32_t DDL_GetUID_Word3(void)
{
  return (uint32_t)(READ_REG(*((uint32_t *)(uintptr_t)(UID_BASE_ADDRESS + 0xCU))));
}

/**
  * @brief  Get Device ID
  * @retval 0x100 = 8  Kbytes
  *         0x200 = 16 Kbytes
  *         0x300 = 32 Kbytes
  *         0x400 = 64 Kbytes
  */
__STATIC_INLINE uint32_t DDL_GetDeviceID(void)
{
  return (uint32_t)((READ_REG(*((uint32_t *)(uintptr_t)PID_BASE_ADDRESS)) & 0xFF));
}

/**
  * @brief  Get Flash memory size
  * @retval 0x100 = 8  Kbytes
  *         0x200 = 16 Kbytes
  *         0x300 = 32 Kbytes
  *         0x400 = 64 Kbytes
  */
__STATIC_INLINE uint32_t DDL_GetFlashSize(void)
{
  return (uint32_t)((READ_REG(*((uint32_t *)(uintptr_t)PID_BASE_ADDRESS)) & 0xF00));
}

/**
  * @brief  Get SRAM memory size
  * @retval 0x1000 = 1  Kbytes
  *         0x2000 = 2  Kbytes
  *         0x3000 = 4  Kbytes
  *         0x4000 = 8  Kbytes
  *         0x4000 = 16 Kbytes
  */
__STATIC_INLINE uint32_t DDL_GetSRAMSize(void)
{
  return (uint32_t)((READ_REG(*((uint32_t *)(uintptr_t)PID_BASE_ADDRESS)) & 0xF000));
}

/**
  * @}
  */

/** @defgroup UTILS_DDL_EF_DELAY DELAY
  * @{
  */

/**
  * @brief  This function configures the Cortex-M SysTick source of the time base.
  * @param  HCLKFrequency HCLK frequency in Hz (can be calculated thanks to RCC helper macro)
  * @note   When a RTOS is used, it is recommended to avoid changing the SysTick
  *         configuration by calling this function, for a delay use rather osDelay RTOS service.
  * @param  Ticks Number of ticks
  * @retval None
  */
__STATIC_INLINE void DDL_InitTick(uint32_t HCLKFrequency, uint32_t Ticks)
{
  /* Configure the SysTick to have interrupt in 1ms time base */
  SysTick->LOAD  = (uint32_t)((HCLKFrequency / Ticks) - 1UL);  /* set reload register */
  SysTick->VAL   = 0UL;                                       /* Load the SysTick Counter Value */
  SysTick->CTRL  = SysTick_CTRL_CLKSOURCE_Msk |
                   SysTick_CTRL_ENABLE_Msk;                   /* Enable the Systick Timer */
}

void        DDL_Init1msTick(uint32_t HCLKFrequency);
void        DDL_mDelay(uint32_t Delay);

/**
  * @}
  */

/** @defgroup UTILS_EF_SYSTEM SYSTEM
  * @{
  */

void        DDL_SetSystemCoreClock(uint32_t HCLKFrequency);
ErrorStatus DDL_SetFlashLatency(uint32_t HCLK_Frequency);
/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* G32M3101_DDL_UTILS_H */
