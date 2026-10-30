/**
  *
  * @file        g32m3101_ddl_bus.h
  * 
  * @brief       Header file of BUS DDL module.
  * 
  * @version     V1.0.1
  * 
  * @date        2026-06-15
  *
  * @attention

  @verbatim
                      ##### SCU Limitations #####
  ==============================================================================
    [..]
      A delay between an SCU peripheral clock enable and the effective peripheral
      enabling should be taken into account in order to manage the peripheral read/write
      from/to registers.
      (+) This delay depends on the peripheral mapping.
        (++) AHB & APB peripherals, 1 dummy read is necessary

    [..]
      Workarounds:
      (#) For AHB & APB peripherals, a dummy read to the peripheral register has been
          inserted in each DDL_{BUS}_GRP{x}_EnableClock() function.

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
#ifndef G32M3101_DDL_BUS_H
#define G32M3101_DDL_BUS_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "g32m3xxx.h"
#include "Legacy/g32_ddl_legacy.h"

/** @addtogroup G32M3101_DDL_Driver
  * @{
  */

#if defined(SCU)

/** @defgroup BUS_DDL BUS
  * @{
  */

/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private constants ---------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/
/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/** @defgroup BUS_DDL_Exported_Constants BUS Exported Constants
  * @{
  */

/** @defgroup BUS_DDL_EC_AHB_GRP1_PERIPH  AHB GRP1 PERIPH
  * @{
  */
#define DDL_AHB_GRP1_PERIPH_ALL             0xFFFFFFFFU
#define DDL_AHB_GRP1_PERIPH_GPIOA           SCU_AHBCG_GPIOAEN
#define DDL_AHB_GRP1_PERIPH_GPIOB           SCU_AHBCG_GPIOBEN
#define DDL_AHB_GRP1_PERIPH_DMA            SCU_AHBCG_DMA1EN
#define DDL_AHB_GRP1_PERIPH_CRC             SCU_AHBCG_CRCEN
#define DDL_AHB_GRP1_PERIPH_DIV             SCU_AHBCG_DIVSHIFTEN
#define DDL_AHB_GRP1_PERIPH_FLASH           SCU_AHBRST_FLASHRST
/**
  * @}
  */


/** @defgroup BUS_DDL_EC_APB_GRP1_PERIPH  APB GRP1 PERIPH
  * @{
  */
#define DDL_APB_GRP1_PERIPH_ALL             0xFFFFFFFFU
#define DDL_APB_GRP1_PERIPH_ATMR            SCU_APBCG_ATMREN
#define DDL_APB_GRP1_PERIPH_GTMR            SCU_APBCG_GTMREN
#define DDL_APB_GRP1_PERIPH_BTMR            SCU_APBCG_BTMREN
#define DDL_APB_GRP1_PERIPH_SPI             SCU_APBCG_SPI1EN
#define DDL_APB_GRP1_PERIPH_UART0           SCU_APBCG_UART0EN
#define DDL_APB_GRP1_PERIPH_UART1           SCU_APBCG_UART1EN
#define DDL_APB_GRP1_PERIPH_WWDT            SCU_APBCG_WWDTEN
#define DDL_APB_GRP1_PERIPH_EINT            SCU_APBCG_EINTEN
#define DDL_APB_GRP1_PERIPH_COMP            SCU_APBCG_COMPEN
#define DDL_APB_GRP1_PERIPH_ADC            SCU_APBCG_ADC1EN
#define DDL_APB_GRP1_PERIPH_LPTMR           SCU_APBCG_LPTMREN
/**
  * @}
  */


/**
  * @}
  */

/* Exported macro ------------------------------------------------------------*/
/* Exported functions --------------------------------------------------------*/
/** @defgroup BUS_DDL_Exported_Functions BUS Exported Functions
  * @{
  */

/** @defgroup BUS_DDL_EF_AHB AHB
  * @{
  */

/**
  * @brief  Enable AHB peripherals clock.
  * @param  Periphs This parameter can be a combination of the following values:
  *         @arg @ref DDL_AHB_GRP1_PERIPH_GPIOA
  *         @arg @ref DDL_AHB_GRP1_PERIPH_GPIOB
  *         @arg @ref DDL_AHB_GRP1_PERIPH_DMA
  *         @arg @ref DDL_AHB_GRP1_PERIPH_CRC
  *         @arg @ref DDL_AHB_GRP1_PERIPH_DIV
  *         @arg @ref DDL_AHB_GRP1_PERIPH_FLASH
  * @retval None
*/
__STATIC_INLINE void DDL_AHB_GRP1_EnableClock(uint32_t Periphs)
{
  __IO uint32_t tmpreg;
  SET_BIT(SCU->AHBCG, Periphs);
  /* Delay after an SCU peripheral clock enabling */
  tmpreg = READ_BIT(SCU->AHBCG, Periphs);
  (void)tmpreg;
}

/**
  * @brief  Check if AHB peripheral clock is enabled or not
  * @param  Periphs This parameter can be a combination of the following values:
  *         @arg @ref DDL_AHB_GRP1_PERIPH_GPIOA
  *         @arg @ref DDL_AHB_GRP1_PERIPH_GPIOB
  *         @arg @ref DDL_AHB_GRP1_PERIPH_DMA
  *         @arg @ref DDL_AHB_GRP1_PERIPH_CRC
  *         @arg @ref DDL_AHB_GRP1_PERIPH_DIV
  *         @arg @ref DDL_AHB_GRP1_PERIPH_FLASH
  * @retval State of Periphs (1 or 0).
*/
__STATIC_INLINE uint32_t DDL_AHB_GRP1_IsEnabledClock(uint32_t Periphs)
{
  return (READ_BIT(SCU->AHBCG, Periphs) == Periphs);
}

/**
  * @brief  Disable AHB peripherals clock.
  * @param  Periphs This parameter can be a combination of the following values:
  *         @arg @ref DDL_AHB_GRP1_PERIPH_GPIOA
  *         @arg @ref DDL_AHB_GRP1_PERIPH_GPIOB
  *         @arg @ref DDL_AHB_GRP1_PERIPH_DMA
  *         @arg @ref DDL_AHB_GRP1_PERIPH_CRC
  *         @arg @ref DDL_AHB_GRP1_PERIPH_DIV
  *         @arg @ref DDL_AHB_GRP1_PERIPH_FLASH
  * @retval None
*/
__STATIC_INLINE void DDL_AHB_GRP1_DisableClock(uint32_t Periphs)
{
  CLEAR_BIT(SCU->AHBCG, Periphs);
}

/**
  * @brief  Force AHB peripherals reset.
  * @param  Periphs This parameter can be a combination of the following values:
  *         @arg @ref DDL_AHB_GRP1_PERIPH_GPIOA
  *         @arg @ref DDL_AHB_GRP1_PERIPH_GPIOB
  *         @arg @ref DDL_AHB_GRP1_PERIPH_DMA
  *         @arg @ref DDL_AHB_GRP1_PERIPH_CRC
  *         @arg @ref DDL_AHB_GRP1_PERIPH_DIV
  *         @arg @ref DDL_AHB_GRP1_PERIPH_FLASH
  * @retval None
*/
__STATIC_INLINE void DDL_AHB_GRP1_ForceReset(uint32_t Periphs)
{
  SET_BIT(SCU->AHBRST, Periphs);
}

/**
  * @brief  Release AHB peripherals reset.
  * @param  Periphs This parameter can be a combination of the following values:
  *         @arg @ref DDL_AHB_GRP1_PERIPH_GPIOA
  *         @arg @ref DDL_AHB_GRP1_PERIPH_GPIOB
  *         @arg @ref DDL_AHB_GRP1_PERIPH_DMA
  *         @arg @ref DDL_AHB_GRP1_PERIPH_CRC
  *         @arg @ref DDL_AHB_GRP1_PERIPH_DIV
  *         @arg @ref DDL_AHB_GRP1_PERIPH_FLASH
  * @retval None
*/
__STATIC_INLINE void DDL_AHB_GRP1_ReleaseReset(uint32_t Periphs)
{
  CLEAR_BIT(SCU->AHBRST, Periphs);
}


/**
  * @}
  */


/** @defgroup BUS_DDL_EF_APB APB
  * @{
  */

/**
  * @brief  Enable APB peripherals clock.
  * @param  Periphs This parameter can be a combination of the following values:
  *         @arg @ref DDL_APB_GRP1_PERIPH_ATMR
  *         @arg @ref DDL_APB_GRP1_PERIPH_GTMR
  *         @arg @ref DDL_APB_GRP1_PERIPH_BTMR
  *         @arg @ref DDL_APB_GRP1_PERIPH_SPI
  *         @arg @ref DDL_APB_GRP1_PERIPH_UART0
  *         @arg @ref DDL_APB_GRP1_PERIPH_UART1
  *         @arg @ref DDL_APB_GRP1_PERIPH_WWDT
  *         @arg @ref DDL_APB_GRP1_PERIPH_EINT
  *         @arg @ref DDL_APB_GRP1_PERIPH_COMP
  *         @arg @ref DDL_APB_GRP1_PERIPH_ADC
  *         @arg @ref DDL_APB_GRP1_PERIPH_LPTMR
  * @retval None
*/
__STATIC_INLINE void DDL_APB_GRP1_EnableClock(uint32_t Periphs)
{
  __IO uint32_t tmpreg;
  SET_BIT(SCU->APBCG, Periphs);
  /* Delay after an SCU peripheral clock enabling */
  tmpreg = READ_BIT(SCU->APBCG, Periphs);
  (void)tmpreg;
}

/**
  * @brief  Check if APB peripheral clock is enabled or not
  * @param  Periphs This parameter can be a combination of the following values:
  *         @arg @ref DDL_APB_GRP1_PERIPH_ATMR
  *         @arg @ref DDL_APB_GRP1_PERIPH_GTMR
  *         @arg @ref DDL_APB_GRP1_PERIPH_BTMR
  *         @arg @ref DDL_APB_GRP1_PERIPH_SPI
  *         @arg @ref DDL_APB_GRP1_PERIPH_UART0
  *         @arg @ref DDL_APB_GRP1_PERIPH_UART1
  *         @arg @ref DDL_APB_GRP1_PERIPH_WWDT
  *         @arg @ref DDL_APB_GRP1_PERIPH_EINT
  *         @arg @ref DDL_APB_GRP1_PERIPH_COMP
  *         @arg @ref DDL_APB_GRP1_PERIPH_ADC
  *         @arg @ref DDL_APB_GRP1_PERIPH_LPTMR
  * @retval State of Periphs (1 or 0).
*/
__STATIC_INLINE uint32_t DDL_APB_GRP1_IsEnabledClock(uint32_t Periphs)
{
  return (READ_BIT(SCU->APBCG, Periphs) == Periphs);
}

/**
  * @brief  Disable APB peripherals clock.
  * @param  Periphs This parameter can be a combination of the following values:
  *         @arg @ref DDL_APB_GRP1_PERIPH_ATMR
  *         @arg @ref DDL_APB_GRP1_PERIPH_GTMR
  *         @arg @ref DDL_APB_GRP1_PERIPH_BTMR
  *         @arg @ref DDL_APB_GRP1_PERIPH_SPI
  *         @arg @ref DDL_APB_GRP1_PERIPH_UART0
  *         @arg @ref DDL_APB_GRP1_PERIPH_UART1
  *         @arg @ref DDL_APB_GRP1_PERIPH_WWDT
  *         @arg @ref DDL_APB_GRP1_PERIPH_EINT
  *         @arg @ref DDL_APB_GRP1_PERIPH_COMP
  *         @arg @ref DDL_APB_GRP1_PERIPH_ADC
  *         @arg @ref DDL_APB_GRP1_PERIPH_LPTMR
  * @retval None
*/
__STATIC_INLINE void DDL_APB_GRP1_DisableClock(uint32_t Periphs)
{
  CLEAR_BIT(SCU->APBCG, Periphs);
}

/**
  * @brief  Force APB peripherals reset.
  * @param  Periphs This parameter can be a combination of the following values:
  *         @arg @ref DDL_APB_GRP1_PERIPH_ATMR
  *         @arg @ref DDL_APB_GRP1_PERIPH_GTMR
  *         @arg @ref DDL_APB_GRP1_PERIPH_BTMR
  *         @arg @ref DDL_APB_GRP1_PERIPH_SPI
  *         @arg @ref DDL_APB_GRP1_PERIPH_UART0
  *         @arg @ref DDL_APB_GRP1_PERIPH_UART1
  *         @arg @ref DDL_APB_GRP1_PERIPH_WWDT
  *         @arg @ref DDL_APB_GRP1_PERIPH_EINT
  *         @arg @ref DDL_APB_GRP1_PERIPH_COMP
  *         @arg @ref DDL_APB_GRP1_PERIPH_ADC
  *         @arg @ref DDL_APB_GRP1_PERIPH_LPTMR
  * @retval None
*/
__STATIC_INLINE void DDL_APB_GRP1_ForceReset(uint32_t Periphs)
{
  SET_BIT(SCU->APBRST, Periphs);
}

/**
  * @brief  Release APB peripherals reset.
  * @param  Periphs This parameter can be a combination of the following values:
  *         @arg @ref DDL_APB_GRP1_PERIPH_ATMR
  *         @arg @ref DDL_APB_GRP1_PERIPH_GTMR
  *         @arg @ref DDL_APB_GRP1_PERIPH_BTMR
  *         @arg @ref DDL_APB_GRP1_PERIPH_SPI
  *         @arg @ref DDL_APB_GRP1_PERIPH_UART0
  *         @arg @ref DDL_APB_GRP1_PERIPH_UART1
  *         @arg @ref DDL_APB_GRP1_PERIPH_WWDT
  *         @arg @ref DDL_APB_GRP1_PERIPH_EINT
  *         @arg @ref DDL_APB_GRP1_PERIPH_COMP
  *         @arg @ref DDL_APB_GRP1_PERIPH_ADC
  *         @arg @ref DDL_APB_GRP1_PERIPH_LPTMR
  * @retval None
*/
__STATIC_INLINE void DDL_APB_GRP1_ReleaseReset(uint32_t Periphs)
{
  CLEAR_BIT(SCU->APBRST, Periphs);
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

#endif /* defined(SCU) */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* G32M3101_DDL_BUS_H */

