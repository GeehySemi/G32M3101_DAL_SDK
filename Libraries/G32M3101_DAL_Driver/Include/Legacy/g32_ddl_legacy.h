/**
  *
  * @file        g32_ddl_legacy.h
  * @brief       This file contains aliases definition for the DDL constants
  *              macros and functions maintained for legacy purpose.
  * @version     V1.0.0
  * @date        2026-10-13
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
 *  Copyright (C) 2026 Geehy Semiconductor
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file in
  * the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef G32_DDL_LEGACY_H
#define G32_DDL_LEGACY_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private constants ---------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/
/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/** @addtogroup DDL_Legacy_Constants
  * @{
  */

/** @defgroup DDL_Legacy_SCU_PREDRV_Slope SCU pre-drive slope (deprecated ns names)
  * @brief  Former ns-suffixed macros. Prefer LEVEL0..LEVEL3; ns differ for LO vs HO.
  * @{
  */
/* Falling: LEVEL0..3  (LO 160/110/80/60 ns; HO 630/350/200/170 ns) */
#define DDL_SCU_PREDRV_FALLING_SLOPE_160NS         DDL_SCU_PREDRV_FALLING_SLOPE_LEVEL0
#define DDL_SCU_PREDRV_FALLING_SLOPE_110NS         DDL_SCU_PREDRV_FALLING_SLOPE_LEVEL1
#define DDL_SCU_PREDRV_FALLING_SLOPE_80NS          DDL_SCU_PREDRV_FALLING_SLOPE_LEVEL2
#define DDL_SCU_PREDRV_FALLING_SLOPE_60NS          DDL_SCU_PREDRV_FALLING_SLOPE_LEVEL3
/* Older incorrect ns labels (same encodings) */
#define DDL_SCU_PREDRV_FALLING_SLOPE_230NS         DDL_SCU_PREDRV_FALLING_SLOPE_LEVEL0
#define DDL_SCU_PREDRV_FALLING_SLOPE_120NS         DDL_SCU_PREDRV_FALLING_SLOPE_LEVEL1
#define DDL_SCU_PREDRV_FALLING_SLOPE_40NS          DDL_SCU_PREDRV_FALLING_SLOPE_LEVEL3

/* Rising: LEVEL0..3  (LO 870/450/290/250 ns; HO 140/90/55/45 ns) */
#define DDL_SCU_PREDRV_RISING_SLOPE_870NS          DDL_SCU_PREDRV_RISING_SLOPE_LEVEL0
#define DDL_SCU_PREDRV_RISING_SLOPE_450NS          DDL_SCU_PREDRV_RISING_SLOPE_LEVEL1
#define DDL_SCU_PREDRV_RISING_SLOPE_290NS          DDL_SCU_PREDRV_RISING_SLOPE_LEVEL2
#define DDL_SCU_PREDRV_RISING_SLOPE_250NS          DDL_SCU_PREDRV_RISING_SLOPE_LEVEL3
/* Older incorrect ns labels (same encodings) */
#define DDL_SCU_PREDRV_RISING_SLOPE_750NS          DDL_SCU_PREDRV_RISING_SLOPE_LEVEL0
#define DDL_SCU_PREDRV_RISING_SLOPE_500NS          DDL_SCU_PREDRV_RISING_SLOPE_LEVEL1
#define DDL_SCU_PREDRV_RISING_SLOPE_230NS          DDL_SCU_PREDRV_RISING_SLOPE_LEVEL2
#define DDL_SCU_PREDRV_RISING_SLOPE_100NS          DDL_SCU_PREDRV_RISING_SLOPE_LEVEL3
/**
  * @}
  */

/** @defgroup DDL_ATMR_Aliased_Defines ATMR Aliased Defines maintained for legacy purpose
  * @{
  */
#define DDL_ATMR_OC_ConfigOutput          DDL_ATMR_OC_Config
/**
  * @}
  */

/** @defgroup DDL_BTMR_Aliased_Defines BTMR Aliased Defines maintained for legacy purpose
  * @{
  */
#define DDL_BTMR_OC_ConfigOutput          DDL_BTMR_OC_Config
/**
  * @}
  */

/** @defgroup DDL_GTMR_Aliased_Defines GTMR Aliased Defines maintained for legacy purpose
  * @{
  */
#define DDL_GTMR_OC_ConfigOutput          DDL_GTMR_OC_Config
/**
  * @}
  */

/** @defgroup DDL_FLASH_Aliased_Defines FLASH Aliased Defines maintained for legacy purpose
  * @{
  */
#define DDL_FLASH_RKEY_Unlock             DDL_FLASH_REG_Unlock
#define DDL_FLASH_RKEY_Lock               DDL_FLASH_REG_Lock
#define DDL_FLASH_RKEY_IsLocked           DDL_FLASH_REG_IsLocked
#define DDL_FLASH_MKEY_Unlock             DDL_FLASH_MAIN_Unlock
#define DDL_FLASH_MKEY_Lock               DDL_FLASH_MAIN_Lock
#define DDL_FLASH_MKEY_IsLocked           DDL_FLASH_MAIN_IsLocked
#define DDL_FLASH_NVRCKEY_Unlock          DDL_FLASH_NVRC_Unlock
#define DDL_FLASH_NVRCKEY_Lock            DDL_FLASH_NVRC_Lock
#define DDL_FLASH_NVRCKEY_IsLocked        DDL_FLASH_NVRC_IsLocked

#define DDL_FLASH_IsActiveFlag_KEY        DDL_FLASH_IsActiveFlag_KEYERR
#define DDL_FLASH_ClearFlag_KEY           DDL_FLASH_ClearFlag_KEYERR
#define DDL_FLASH_IsActiveFlag_RPT        DDL_FLASH_IsActiveFlag_RPTERR
#define DDL_FLASH_ClearFlag_RPT           DDL_FLASH_ClearFlag_RPTERR
/**
  * @}
  */

/** @defgroup DDL_PMU_Aliased_Defines PMU Aliased Defines maintained for legacy purpose
  * @{
  */
#define DDL_PMU_Unlock                     DDL_PMU_REG_Unlock
#define DDL_PMU_Lock                       DDL_PMU_REG_Lock
#define DDL_PMU_IsActiveFlag_LOCK          DDL_PMU_REG_IsLocked
/**
  * @}
  */

/** @defgroup DDL_COMP0_Aliased_Defines COMP0 Aliased Defines maintained for legacy purpose
  * @{
  */
#define DDL_COMP0_EnableSWINT                     DDL_COMP0_GenerateSWINT
/**
  * @}
  */

/** @defgroup DDL_COMP1_Aliased_Defines COMP1 Aliased Defines maintained for legacy purpose
  * @{
  */
#define DDL_COMP1_EnableSWINT                     DDL_COMP1_GenerateSWINT
/**
  * @}
  */

/** @defgroup DDL_RCC_Aliased_Defines RCC Aliased Defines maintained for legacy purpose
  * @{
  */
#define DDL_RCC_Unlock                    DDL_RCC_REG_Unlock
#define DDL_RCC_Lock                      DDL_RCC_REG_Lock
#define DDL_RCC_IsActiveFlag_LOCK         DDL_RCC_REG_IsLocked
/**
  * @}
  */

/** @defgroup DDL_SCU_Aliased_Defines SCU Aliased Defines maintained for legacy purpose
  * @{
  */
#define DDL_SCU_Unlock                    DDL_SCU_REG_Unlock
#define DDL_SCU_Lock                      DDL_SCU_REG_Lock
#define DDL_SCU_IsActiveFlag_LOCK         DDL_SCU_REG_IsLocked
/**
  * @}
  */

/** @defgroup DDL_Peripheral_Aliased_Defines Peripheral instance aliases maintained for legacy purpose
  * @{
  */
#define SPI1                          SPI
#define SPI1_BASE                     SPI_BASE
#define ADC1                          ADC
#define ADC1_BASE                     ADC_BASE
#define DMA1                          DMA
#define DMA1_BASE                     DMA_BASE
#define DMA1_Channel0                 DMA_Channel0
#define DMA1_Channel1                 DMA_Channel1
#define DMA1_Channel2                 DMA_Channel2
#define DMA1_Channel0_BASE            DMA_Channel0_BASE
#define DMA1_Channel1_BASE            DMA_Channel1_BASE
#define DMA1_Channel2_BASE            DMA_Channel2_BASE

#define DDL_APB_GRP1_PERIPH_SPI1      DDL_APB_GRP1_PERIPH_SPI
#define DDL_SCU_APB_RESET_SPI1        DDL_SCU_APB_RESET_SPI
#define DDL_SCU_APB_PERIPHERAL_SPI1   DDL_SCU_APB_PERIPHERAL_SPI
#define DDL_AHB_GRP1_PERIPH_DMA1      DDL_AHB_GRP1_PERIPH_DMA
#define DDL_APB_GRP1_PERIPH_ADC1      DDL_APB_GRP1_PERIPH_ADC
#define DDL_SCU_AHB_RESET_DMA1        DDL_SCU_AHB_RESET_DMA
#define DDL_SCU_APB_RESET_ADC1        DDL_SCU_APB_RESET_ADC
#define DDL_SCU_AHB_PERIPHERAL_DMA1   DDL_SCU_AHB_PERIPHERAL_DMA
#define DDL_SCU_APB_PERIPHERAL_ADC1   DDL_SCU_APB_PERIPHERAL_ADC
/**
  * @}
  */

/**
  * @}
  */

/* Exported macro ------------------------------------------------------------*/
/* Exported functions --------------------------------------------------------*/

#ifdef __cplusplus
}
#endif

#endif /* G32_DDL_LEGACY_H */
