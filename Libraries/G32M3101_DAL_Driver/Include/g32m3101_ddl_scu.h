/**
  *
   * @file        g32m3101_ddl_scu.h
  *
  * @brief       Header file of SCU DDL module.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef G32M3101_DDL_SCU_H
#define G32M3101_DDL_SCU_H

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

/** @defgroup SCU_DDL SCU
  * @{
  */

/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/** @defgroup SCU_DDL_Private_Variables SCU Private Variables
  * @{
  */

static const uint8_t OFFSET_TAB_OPAx[] =
{
  SCU_OPAMPCR_OPAMP0_EN_Pos,                                /* 0: OPA0  */
  (SCU_OPAMPCR_OPAMP1_EN_Pos-SCU_OPAMPCR_OPAMP0_EN_Pos),    /* 1: OPA1  */
};

static const uint8_t OFFSET_TAB_FallingSlope[] =
{
  0U,                                                                           /* 0: LO  */
  (SCU_PREDRVCR_PREDRV_HO_FALL_SEL_Pos-SCU_PREDRVCR_PREDRV_LO_FALL_SEL_Pos),    /* 1: HO  */
};
static const uint8_t OFFSET_TAB_RisingSlope[] =
{
  0U,                                                                           /* 0: LO  */
  (SCU_PREDRVCR_PREDRV_HO_RISE_SEL_Pos-SCU_PREDRVCR_PREDRV_LO_RISE_SEL_Pos),    /* 1: HO  */
};

/**
  * @}
  */
/* Private constants ---------------------------------------------------------*/
/** @defgroup SCU_DDL_Exported_Constants SCU Exported Constants
  * @{
  */

/** @defgroup SCU_DDL_EC_OSC_VALUES Oscillator Values adaptation
  * @brief    Defines used to adapt values of different oscillators
  * @note     These values could be modified in the user environment according to
  *           HW set-up.
  * @{
  */

#if !defined  (HSI_VALUE)
#define HSI_VALUE    64000000U  /*!< Value of the HSI oscillator in Hz */
#endif /* HSI_VALUE */

#if !defined  (LSI_VALUE)
#define LSI_VALUE    32768U     /*!< Value of the LSI oscillator in Hz */
#endif /* LSI_VALUE */
/**
  * @}
  */

/**
  * @}
  */

/* Private macros ------------------------------------------------------------*/
#if defined(USE_FULL_DDL_DRIVER)
/** @defgroup SCU_DDL_Private_Macros SCU Private Macros
  * @{
  */
/**
  * @}
  */
#endif /*USE_FULL_DDL_DRIVER*/
/* Exported types ------------------------------------------------------------*/
#if defined(USE_FULL_DDL_DRIVER)
/** @defgroup SCU_DDL_Exported_Types SCU Exported Types
  * @{
  */

/** @defgroup DDL_ES_CLOCK_FREQ Clocks Frequency Structure
  * @{
  */

/**
  * @brief  SCU Clocks Frequency Structure
  */
typedef struct
{
  uint32_t SYSCLK_Frequency;        /*!< SYSCLK clock frequency */
  uint32_t HCLK_Frequency;          /*!< HCLK clock frequency */
  uint32_t PCLK_Frequency;          /*!< PCLK clock frequency */
} DDL_SCU_ClocksTypeDef;

/**
  * @}
  */

/**
  * @}
  */
#endif /* USE_FULL_DDL_DRIVER */

/* Exported constants --------------------------------------------------------*/
/** @defgroup SCU_DDL_Exported_Constants SCU Exported Constants
  * @{
  */

/** @defgroup SCU_DDL_EC_OSC_VALUES Oscillator Values adaptation
  * @brief    Defines used to adapt values of different oscillators
  * @note     These values could be modified in the user environment according to
  *           HW set-up.
  * @{
  */

#if !defined  (HSI_VALUE)
#define HSI_VALUE    64000000U  /*!< Value of the HSI oscillator in Hz */
#endif /* HSI_VALUE */

#if !defined  (LSI_VALUE)
#define LSI_VALUE    32768U     /*!< Value of the LSI oscillator in Hz */
#endif /* LSI_VALUE */
/**
  * @}
  */

/** @defgroup SCU_DDL_EC_IT_FLAG Interrupt Flags Defines
  * @{
  */
#define DDL_SCU_INT_LSIRDYFLG                SCU_CICR_LSIRDYF        /*!< LSI Ready Interrupt flag */
#define DDL_SCU_INT_HSIRDYFLG                SCU_CICR_HSIRDYF        /*!< HSI Ready Interrupt flag */

/**
  * @}
  */

/** @defgroup SCU_DDL_EC_IT_EN Interrupt Defines
  * @{
  */
#define DDL_SCU_INT_LSIRDYEN                 SCU_CIER_LSIRDYIE       /*!< LSI Ready Interrupt Enable */
#define DDL_SCU_INT_HSIRDYEN                 SCU_CIER_HSIRDYIE       /*!< HSI Ready Interrupt Enable */

/**
  * @}
  */

/** @defgroup SCU_DDL_EC_RESET_FLAG Reset Flags Defines
  * @{
  */
#define DDL_SCU_RSTCSR_OPRSTFLG              SCU_RSTCSR_OPRSTF       /*!< Opload reset flag */
#define DDL_SCU_RSTCSR_PINRSTFLG             SCU_RSTCSR_NRSTRSTF     /*!< PIN reset flag */
#define DDL_SCU_RSTCSR_PVDRSTFLG             SCU_RSTCSR_PVDRSTF      /*!< PVD reset flag */
#define DDL_SCU_RSTCSR_SFTRSTFLG             SCU_RSTCSR_SFTRSTF      /*!< Software Reset flag */
#define DDL_SCU_RSTCSR_IWDTRSTFLG            SCU_RSTCSR_IWDTRSTF     /*!< Independent Watchdog reset flag */
#define DDL_SCU_RSTCSR_WWDTRSTFLG            SCU_RSTCSR_WWDTRSTF     /*!< Window watchdog reset flag */
#define DDL_SCU_RSTCSR_LOCKUPRSTFLG          SCU_RSTCSR_LOCKUPRSTF   /*!< Lockup reset flag */
#define DDL_SCU_RSTCSR_PORRSTFLG             SCU_RSTCSR_PORRSTF      /*!< Power reset flag */

/**
  * @}
  */

/** @defgroup SCU_DDL_EC_RESET_EN Reset flag enable
  * @{
  */
#define DDL_SCU_RSTCSR_PVDRSTEN                 SCU_RSTCSR_PVDRST_EN       /*!< PVD reset enable */
#define DDL_SCU_RSTCSR_LOCKUPRSTEN              SCU_RSTCSR_LOCKUPRST_EN    /*!< Lockup reset enable */

/**
  * @}
  */

/** @defgroup SCU_DDL_EC_SYS_CLKSOURCE  System clock switch
  * @{
  */
#define DDL_SCU_SYSCLK_SOURCE_HSI            SCU_SCCR_SW_HSI         /*!< HSI selection as system clock */
#define DDL_SCU_SYSCLK_SOURCE_LSI            SCU_SCCR_SW_LSI         /*!< LSI selection as system clock */
/**
  * @}
  */

/** @defgroup SCU_DDL_EC_SYSCLK_DIV  AHB prescaler
  * @{
  */
#define DDL_SCU_AHB_DIV_1                    SCU_SCCR_HDIV_DIV1      /*!< SYSCLK not divided */
#define DDL_SCU_AHB_DIV_2                    SCU_SCCR_HDIV_DIV2      /*!< SYSCLK divided by 2 */
#define DDL_SCU_AHB_DIV_4                    SCU_SCCR_HDIV_DIV4      /*!< SYSCLK divided by 4 */
#define DDL_SCU_AHB_DIV_8                    SCU_SCCR_HDIV_DIV8      /*!< SYSCLK divided by 8 */
#define DDL_SCU_AHB_DIV_16                   SCU_SCCR_HDIV_DIV16     /*!< SYSCLK divided by 16 */
#define DDL_SCU_AHB_DIV_32                   SCU_SCCR_HDIV_DIV32     /*!< SYSCLK divided by 32 */
#define DDL_SCU_AHB_DIV_64                   SCU_SCCR_HDIV_DIV64     /*!< SYSCLK divided by 64 */
#define DDL_SCU_AHB_DIV_128                  SCU_SCCR_HDIV_DIV128    /*!< SYSCLK divided by 128 */
/**
  * @}
  */

/** @defgroup SCU_DDL_EC_APB_DIV  APB low-speed prescaler (APB)
  * @{
  */
#define DDL_SCU_APB_DIV_1                    SCU_SCCR_PDIV_DIV1      /*!< HCLK not divided */
#define DDL_SCU_APB_DIV_2                    SCU_SCCR_PDIV_DIV2      /*!< HCLK divided by 2 */
#define DDL_SCU_APB_DIV_4                    SCU_SCCR_PDIV_DIV4      /*!< HCLK divided by 4 */
#define DDL_SCU_APB_DIV_8                    SCU_SCCR_PDIV_DIV8      /*!< HCLK divided by 8 */
#define DDL_SCU_APB_DIV_16                   SCU_SCCR_PDIV_DIV16     /*!< HCLK divided by 16 */
#define DDL_SCU_APB_DIV_32                   SCU_SCCR_PDIV_DIV32     /*!< HCLK divided by 32 */
#define DDL_SCU_APB_DIV_64                   SCU_SCCR_PDIV_DIV64     /*!< HCLK divided by 64 */
#define DDL_SCU_APB_DIV_128                  SCU_SCCR_PDIV_DIV128    /*!< HCLK divided by 128 */
/**
  * @}
  */


/** @defgroup SCU_DDL_EC_AHB_RESET AHB reset
  * @{
  */
#define DDL_SCU_AHB_RESET_GPIOA              SCU_AHBRST_GPIOARST
#define DDL_SCU_AHB_RESET_GPIOB              SCU_AHBRST_GPIOBRST
#define DDL_SCU_AHB_RESET_DMA               SCU_AHBRST_DMA1RST
#define DDL_SCU_AHB_RESET_CRC                SCU_AHBRST_CRCRST
#define DDL_SCU_AHB_RESET_DIV                SCU_AHBRST_DIVSHIFTRST
#define DDL_SCU_AHB_RESET_FLASH              SCU_AHBRST_FLASHRST
/**
  * @}
  */

/** @defgroup SCU_DDL_EC_APB_RESET APB reset
  * @{
  */
#define DDL_SCU_APB_RESET_ATMR               SCU_APBRST_ATMRRST
#define DDL_SCU_APB_RESET_GTMR               SCU_APBRST_GTMRRST
#define DDL_SCU_APB_RESET_BTMR               SCU_APBRST_BTMRRST
#define DDL_SCU_APB_RESET_SPI               SCU_APBRST_SPI1RST
#define DDL_SCU_APB_RESET_UART0              SCU_APBRST_UART0RST
#define DDL_SCU_APB_RESET_UART1              SCU_APBRST_UART1RST
#define DDL_SCU_APB_RESET_EINT               SCU_APBRST_EINTRST
#define DDL_SCU_APB_RESET_COMP               SCU_APBRST_COMPRST
#define DDL_SCU_APB_RESET_ADC               SCU_APBRST_ADC1RST
#define DDL_SCU_APB_RESET_LPTMR              SCU_APBRST_LPTMRRST

/**
  * @}
  */

/** @defgroup SCU_DDL_EC_AHB_Peripheral AHB peripheral
  * @{
  */
#define DDL_SCU_AHB_PERIPHERAL_GPIOA         SCU_AHBCG_GPIOAEN
#define DDL_SCU_AHB_PERIPHERAL_GPIOB         SCU_AHBCG_GPIOBEN
#define DDL_SCU_AHB_PERIPHERAL_DMA          SCU_AHBCG_DMA1EN
#define DDL_SCU_AHB_PERIPHERAL_CRC           SCU_AHBCG_CRCEN
#define DDL_SCU_AHB_PERIPHERAL_DIV           SCU_AHBCG_DIVSHIFTEN

/**
  * @}
  */

/** @defgroup SCU_DDL_EC_APB_PERIPHERAL APB peripheral
  * @{
  */
#define DDL_SCU_APB_PERIPHERAL_ATMR          SCU_APBCG_ATMREN
#define DDL_SCU_APB_PERIPHERAL_GTMR          SCU_APBCG_GTMREN
#define DDL_SCU_APB_PERIPHERAL_BTMR          SCU_APBCG_BTMREN
#define DDL_SCU_APB_PERIPHERAL_SPI          SCU_APBCG_SPI1EN
#define DDL_SCU_APB_PERIPHERAL_UART0         SCU_APBCG_UART0EN
#define DDL_SCU_APB_PERIPHERAL_UART1         SCU_APBCG_UART1EN
#define DDL_SCU_APB_PERIPHERAL_WWDT          SCU_APBCG_WWDTEN
#define DDL_SCU_APB_PERIPHERAL_EINT          SCU_APBCG_EINTEN
#define DDL_SCU_APB_PERIPHERAL_COMP          SCU_APBCG_COMPEN
#define DDL_SCU_APB_PERIPHERAL_ADC          SCU_APBCG_ADC1EN
#define DDL_SCU_APB_PERIPHERAL_LPTMR         SCU_APBCG_LPTMREN
/**
  * @}
  */

/** @defgroup SCU_DDL_EC_MCOSOURCE MCO source selection
  * @{
  */
#define DDL_SCU_MCOSOURCE_SYSCLK             SCU_SCCR_CLKOUTSEL_SYSCLK /*!< SYSCLK selection as MCO source */
#define DDL_SCU_MCOSOURCE_HSI                SCU_SCCR_CLKOUTSEL_HSI    /*!< HSI selection as MCO source */
#define DDL_SCU_MCOSOURCE_LSI                SCU_SCCR_CLKOUTSEL_LSI    /*!< LSI selection as MCO source */
#define DDL_SCU_MCOSOURCE_HCLK               SCU_SCCR_CLKOUTSEL_HCLK   /*!< HCLK selection as MCO source */
/**
  * @}
  */

/** @defgroup SCU_DDL_EC_MCO_DIV  MCO prescaler
  * @{
  */
#define DDL_SCU_MCO_DIV_1                    SCU_SCCR_CLKOUTDIV_DIV1  /*!< MCO not divided */
#define DDL_SCU_MCO_DIV_2                    SCU_SCCR_CLKOUTDIV_DIV2  /*!< MCO divided by 2 */
#define DDL_SCU_MCO_DIV_4                    SCU_SCCR_CLKOUTDIV_DIV4  /*!< MCO divided by 4 */
#define DDL_SCU_MCO_DIV_8                    SCU_SCCR_CLKOUTDIV_DIV8  /*!< MCO divided by 8 */
#define DDL_SCU_MCO_DIV_16                   SCU_SCCR_CLKOUTDIV_DIV16 /*!< MCO divided by 16 */
#define DDL_SCU_MCO_DIV_32                   SCU_SCCR_CLKOUTDIV_DIV32 /*!< MCO divided by 32 */
#define DDL_SCU_MCO_DIV_64                   SCU_SCCR_CLKOUTDIV_DIV64 /*!< MCO divided by 64 */
#define DDL_SCU_MCO_DIV_128                  SCU_SCCR_CLKOUTDIV_DIV128 /*!< MCO divided by 128 */
/**
  * @}
  */

/** @defgroup SCU_DDL_EC_ADCCLK_Division  ADCCLK Division
  * @{
  */
#define DDL_SCU_ADCCLK_DIVISION_2                    0x00000000U                 /*!< ADCCLK Division with 2 */
#define DDL_SCU_ADCCLK_DIVISION_4                    SCU_ADCCR_ADCCLK_DIV_0      /*!< ADCCLK Division with 4 */
#define DDL_SCU_ADCCLK_DIVISION_8                    SCU_ADCCR_ADCCLK_DIV_1      /*!< ADCCLK Division with 8 */
#define DDL_SCU_ADCCLK_DIVISION_16                   SCU_ADCCR_ADCCLK_DIV        /*!< ADCCLK Division with 16 */
/**
  * @}
  */

#if defined(USE_FULL_DDL_DRIVER)
/** @defgroup SCU_DDL_EC_PERIPH_FREQUENCY Peripheral clock frequency
  * @{
  */
#define DDL_SCU_PERIPH_FREQUENCY_NO          0x00000000U                 /*!< No clock enabled for the peripheral            */
#define DDL_SCU_PERIPH_FREQUENCY_NA          0xFFFFFFFFU                 /*!< Frequency cannot be provided as external clock */
/**
  * @}
  */
#endif /* USE_FULL_DDL_DRIVER */

/** @defgroup SCU_DDL_OPA  OPAx
  * @{
  */
#define DDL_SCU_OPA0             0U
#define DDL_SCU_OPA1             1U
/**
  * @}
  */

/** @defgroup SCU_DDL_OPA_SEL_GAIN  OPAx gain selection signal
  * @{
  */
#define DDL_SCU_OPA_SEL_GAIN_0             0U                                                                 /*!< OPAx selection signal by external resistance            */
#define DDL_SCU_OPA_SEL_GAIN_1             (SCU_OPAMPCR_OPAMP0_SEL_GAIN_0)                                    /*!< OPAx selection signal by internal resistance, Gain 1    */
#define DDL_SCU_OPA_SEL_GAIN_4             (SCU_OPAMPCR_OPAMP0_SEL_GAIN_1)                                    /*!< OPAx selection signal by internal resistance, Gain 4    */
#define DDL_SCU_OPA_SEL_GAIN_6             (SCU_OPAMPCR_OPAMP0_SEL_GAIN_1 | SCU_OPAMPCR_OPAMP0_SEL_GAIN_0)    /*!< OPAx selection signal by internal resistance, Gain 6    */
#define DDL_SCU_OPA_SEL_GAIN_8             (SCU_OPAMPCR_OPAMP0_SEL_GAIN_2)                                    /*!< OPAx selection signal by internal resistance, Gain 8    */
#define DDL_SCU_OPA_SEL_GAIN_10            (SCU_OPAMPCR_OPAMP0_SEL_GAIN_2 | SCU_OPAMPCR_OPAMP0_SEL_GAIN_0)    /*!< OPAx selection signal by internal resistance, Gain 10    */
#define DDL_SCU_OPA_SEL_GAIN_12            (SCU_OPAMPCR_OPAMP0_SEL_GAIN_2 | SCU_OPAMPCR_OPAMP0_SEL_GAIN_1)    /*!< OPAx selection signal by internal resistance, Gain 12    */
#define DDL_SCU_OPA_SEL_GAIN_16            (SCU_OPAMPCR_OPAMP0_SEL_GAIN)                                      /*!< OPAx selection signal by internal resistance, Gain 16    */

/**
  * @}
  */

/** @defgroup SCU_DDL_OPA_VCM  OPAx voltage selection
  * @{
  */
#define DDL_SCU_OPA_VCM_0                  0x00000000U                                                     /*!< OPAx VCM without input voltage   */
#define DDL_SCU_OPA_VCM_AVDD_0_5           (SCU_OPAMPCR_OPAMP_SEL_MUX_2)                                   /*!< OPAx VCM with 0.5*AVDD           */
#define DDL_SCU_OPA_VCM_AVDD_0_25          (SCU_OPAMPCR_OPAMP_SEL_MUX_2 | SCU_OPAMPCR_OPAMP_SEL_MUX_0)     /*!< OPAx VCM with 0.25*AVDD          */
#define DDL_SCU_OPA_VCM_VBG                (SCU_OPAMPCR_OPAMP_SEL_MUX_2 | SCU_OPAMPCR_OPAMP_SEL_MUX_1)     /*!< OPAx VCM with VBG                */
#define DDL_SCU_OPA_VCM_VBG_0_25           (SCU_OPAMPCR_OPAMP_SEL_MUX)                                     /*!< OPAx VCM with 0.25*VBG            */

/**
  * @}
  */

/** @defgroup SCU_DDL_Drive_Output_Slope  Drive Output Slope
  * @{
  */
#define DDL_SCU_PREDRV_LO             0U
#define DDL_SCU_PREDRV_HO             1U

#define DDL_SCU_PREDRV_FALLING_SLOPE_LEVEL0        0x00000000U                                            /*!< LO fall 160ns / HO fall 630ns */
#define DDL_SCU_PREDRV_FALLING_SLOPE_LEVEL1       (SCU_PREDRVCR_PREDRV_LO_FALL_SEL_0)                     /*!< LO fall 110ns / HO fall 350ns */
#define DDL_SCU_PREDRV_FALLING_SLOPE_LEVEL2       (SCU_PREDRVCR_PREDRV_LO_FALL_SEL_1)                     /*!< LO fall 80ns  / HO fall 200ns */
#define DDL_SCU_PREDRV_FALLING_SLOPE_LEVEL3       (SCU_PREDRVCR_PREDRV_LO_FALL_SEL)                       /*!< LO fall 60ns  / HO fall 170ns */

#define DDL_SCU_PREDRV_RISING_SLOPE_LEVEL0         0x00000000U                                            /*!< LO rise 870ns / HO rise 140ns */
#define DDL_SCU_PREDRV_RISING_SLOPE_LEVEL1        (SCU_PREDRVCR_PREDRV_LO_RISE_SEL_0)                     /*!< LO rise 450ns / HO rise 90ns */
#define DDL_SCU_PREDRV_RISING_SLOPE_LEVEL2        (SCU_PREDRVCR_PREDRV_LO_RISE_SEL_1)                     /*!< LO rise 290ns / HO rise 55ns */
#define DDL_SCU_PREDRV_RISING_SLOPE_LEVEL3        (SCU_PREDRVCR_PREDRV_LO_RISE_SEL)                       /*!< LO rise 250ns / HO rise 45ns */

/**
  * @}
  */


/**
  * @}
  */

/* Exported macro ------------------------------------------------------------*/
/** @defgroup SCU_DDL_Exported_Macros SCU Exported Macros
  * @{
  */

/** @defgroup SCU_DDL_EM_WRITE_READ Common Write and read registers Macros
  * @{
  */

/**
  * @brief  Write a value in SCU register
  * @param  __REG__ Register to be written
  * @param  __VALUE__ Value to be written in the register
  * @retval None
  */
#define DDL_SCU_WriteReg(__REG__, __VALUE__) WRITE_REG(SCU->__REG__, (__VALUE__))

/**
  * @brief  Read a value in SCU register
  * @param  __REG__ Register to be read
  * @retval Register value
  */
#define DDL_SCU_ReadReg(__REG__) READ_REG(SCU->__REG__)
/**
  * @}
  */

/** @defgroup SCU_DDL_EM_CALC_FREQ Calculate frequencies
  * @{
  */

/**
  * @brief  Helper macro to calculate the HCLK frequency
  * @param  __SYSCLKFREQ__ SYSCLK frequency (based on HSI/lSI)
  * @param  __AHBPRESCALER__ This parameter can be one of the following values:
  *         @arg @ref DDL_SCU_AHB_DIV_1
  *         @arg @ref DDL_SCU_AHB_DIV_2
  *         @arg @ref DDL_SCU_AHB_DIV_4
  *         @arg @ref DDL_SCU_AHB_DIV_8
  *         @arg @ref DDL_SCU_AHB_DIV_16
  *         @arg @ref DDL_SCU_AHB_DIV_32
  *         @arg @ref DDL_SCU_AHB_DIV_64
  *         @arg @ref DDL_SCU_AHB_DIV_128
  * @retval HCLK clock frequency (in Hz)
  */
#define __DDL_SCU_CALC_HCLK_FREQ(__SYSCLKFREQ__, __AHBPRESCALER__) ((__SYSCLKFREQ__) >> AHBPrescTable[((__AHBPRESCALER__) & SCU_SCCR_HDIV) >>  SCU_SCCR_HDIV_Pos])

/**
  * @brief  Helper macro to calculate the PCLK frequency (ABP)
  * @param  __HCLKFREQ__ HCLK frequency
  * @param  __APBPRESCALER__ This parameter can be one of the following values:
  *         @arg @ref DDL_SCU_APB_DIV_1
  *         @arg @ref DDL_SCU_APB_DIV_2
  *         @arg @ref DDL_SCU_APB_DIV_4
  *         @arg @ref DDL_SCU_APB_DIV_8
  *         @arg @ref DDL_SCU_APB_DIV_16
  *         @arg @ref DDL_SCU_APB_DIV_32
  *         @arg @ref DDL_SCU_APB_DIV_64
  *         @arg @ref DDL_SCU_APB_DIV_128
  * @retval PCLK1 clock frequency (in Hz)
  */
#define __DDL_SCU_CALC_PCLK_FREQ(__HCLKFREQ__, __APBPRESCALER__) ((__HCLKFREQ__) >> APBPrescTable[(__APBPRESCALER__) >>  SCU_SCCR_PDIV_Pos])

/**
  * @}
  */

/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/** @defgroup SCU_DDL_Exported_Functions SCU Exported Functions
  * @{
  */

/** @defgroup SCU_DDL_EF_Lock Lock
  * @{
  */

/**
  * @brief  Lock the SCU register.
  * @retval None
  */
__STATIC_INLINE void DDL_SCU_Lock(void)
{
  SET_BIT(SCU->KEY, SCU_KEY_KEYST);
}

/**
  * @brief  Unlock the SCU register.
  * @param  None
  * @retval None
  */
__STATIC_INLINE void DDL_SCU_Unlock(void)
{
  WRITE_REG(SCU->KEY, (0xFFFFU & SCU_KEY_VALUE));
}

/**
  * @brief  Check if the SCU KEY status is locked.
  * @param  None
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_SCU_IsActiveFlag_LOCK(void)
{
  return (READ_BIT(SCU->KEY, SCU_KEY_KEYST) != (SCU_KEY_KEYST));
}

/**
  * @}
  */

/** @defgroup SCU_DDL_EF_LSI LSI
  * @{
  */

/**
  * @brief  Enable LSI oscillator
  * @retval None
  */
__STATIC_INLINE void DDL_SCU_LSI_Enable(void)
{
  SET_BIT(SCU->RCCR, SCU_RCCR_LSION);
}

/**
  * @brief  Disable LSI oscillator
  * @retval None
  */
__STATIC_INLINE void DDL_SCU_LSI_Disable(void)
{
  CLEAR_BIT(SCU->RCCR, SCU_RCCR_LSION);
}

/**
  * @brief  Check if LSI clock is ready
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_SCU_LSI_IsReady(void)
{
  return (uint32_t)(READ_BIT(SCU->RCCR, SCU_RCCR_LSIRDYFLG) == (SCU_RCCR_LSIRDYFLG));
}

/**
  * @}
  */

/** @defgroup SCU_DDL_EF_HSI HSI
  * @{
  */

/**
  * @brief  Enable HSI oscillator
  * @retval None
  */
__STATIC_INLINE void DDL_SCU_HSI_Enable(void)
{
  SET_BIT(SCU->RCCR, SCU_RCCR_HSION);
}

/**
  * @brief  Disable HSI oscillator
  * @retval None
  */
__STATIC_INLINE void DDL_SCU_HSI_Disable(void)
{
  CLEAR_BIT(SCU->RCCR, SCU_RCCR_HSION);
}

/**
  * @brief  Check if HSI clock is ready
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_SCU_HSI_IsReady(void)
{
  return (uint32_t)(READ_BIT(SCU->RCCR, SCU_RCCR_HSIRDYFLG) == (SCU_RCCR_HSIRDYFLG));
}

/**
  * @}
  */


/** @defgroup SCU_DDL_EF_System_Clock System Clock
  * @{
  */
/**
  * @brief  Configure System clock source
  * @param Source this parameter can be one of the following values:
  *        @arg @ref DDL_SCU_SYSCLK_SOURCE_HSI
  *        @arg @ref DDL_SCU_SYSCLK_SOURCE_LSI
  * @retval None
  */
__STATIC_INLINE void DDL_SCU_SetSysClkSource(uint32_t Source)
{
  MODIFY_REG(SCU->SCCR, SCU_SCCR_SW, Source);
}

/**
  * @brief  Get System clock source
  * @retval return values can be one of the following values:
  *        @arg @ref DDL_SCU_SYSCLK_SOURCE_HSI
  *        @arg @ref DDL_SCU_SYSCLK_SOURCE_LSI
  */
__STATIC_INLINE uint32_t DDL_SCU_GetSysClkSource(void)
{
  return (uint32_t)(READ_BIT(SCU->SCCR, SCU_SCCR_SWST) >> SCU_SCCR_SWST_Pos);
}

/**
  * @}
  */

/** @defgroup SCU_DDL_EF_Prescaler Prescaler
  * @{
  */
/**
  * @brief  Set AHB prescaler
  * @param  Prescaler This parameter can be one of the following values:
  *         @arg @ref DDL_SCU_AHB_DIV_1
  *         @arg @ref DDL_SCU_AHB_DIV_2
  *         @arg @ref DDL_SCU_AHB_DIV_4
  *         @arg @ref DDL_SCU_AHB_DIV_8
  *         @arg @ref DDL_SCU_AHB_DIV_16
  *         @arg @ref DDL_SCU_AHB_DIV_32
  *         @arg @ref DDL_SCU_AHB_DIV_64
  *         @arg @ref DDL_SCU_AHB_DIV_128
  * @retval None
  */
__STATIC_INLINE void DDL_SCU_SetAHBPrescaler(uint32_t Prescaler)
{
  MODIFY_REG(SCU->SCCR, SCU_SCCR_HDIV, Prescaler);
}

/**
  * @brief  Get AHB prescaler
  * @retval Returned value can be one of the following values:
  *         @arg @ref DDL_SCU_AHB_DIV_1
  *         @arg @ref DDL_SCU_AHB_DIV_2
  *         @arg @ref DDL_SCU_AHB_DIV_4
  *         @arg @ref DDL_SCU_AHB_DIV_8
  *         @arg @ref DDL_SCU_AHB_DIV_16
  *         @arg @ref DDL_SCU_AHB_DIV_32
  *         @arg @ref DDL_SCU_AHB_DIV_64
  *         @arg @ref DDL_SCU_AHB_DIV_128
  */
__STATIC_INLINE uint32_t DDL_SCU_GetAHBPrescaler(void)
{
  return (uint32_t)(READ_BIT(SCU->SCCR, SCU_SCCR_HDIV));
}

/**
  * @brief  Set APB prescaler
  * @param  Prescaler This parameter can be one of the following values:
  *         @arg @ref DDL_SCU_APB_DIV_1
  *         @arg @ref DDL_SCU_APB_DIV_2
  *         @arg @ref DDL_SCU_APB_DIV_4
  *         @arg @ref DDL_SCU_APB_DIV_8
  *         @arg @ref DDL_SCU_APB_DIV_16
  *         @arg @ref DDL_SCU_APB_DIV_32
  *         @arg @ref DDL_SCU_APB_DIV_64
  *         @arg @ref DDL_SCU_APB_DIV_128
  * @retval None
  */
__STATIC_INLINE void DDL_SCU_SetAPBPrescaler(uint32_t Prescaler)
{
  MODIFY_REG(SCU->SCCR, SCU_SCCR_PDIV, Prescaler);
}

/**
  * @brief  Get APB prescaler
  * @retval Returned value can be one of the following values:
  *         @arg @ref DDL_SCU_APB_DIV_1
  *         @arg @ref DDL_SCU_APB_DIV_2
  *         @arg @ref DDL_SCU_APB_DIV_4
  *         @arg @ref DDL_SCU_APB_DIV_8
  *         @arg @ref DDL_SCU_APB_DIV_16
  *         @arg @ref DDL_SCU_APB_DIV_32
  *         @arg @ref DDL_SCU_APB_DIV_64
  *         @arg @ref DDL_SCU_APB_DIV_128
  */
__STATIC_INLINE uint32_t DDL_SCU_GetAPBPrescaler(void)
{
  return (uint32_t)(READ_BIT(SCU->SCCR, SCU_SCCR_PDIV));
}

/**
  * @}
  */

/** @defgroup SCU_DDL_EF_MCO MCO
  * @{
  */
/**
  * @brief  Enable clock output
  * @retval None
  */
__STATIC_INLINE void DDL_SCU_EnableMCO(void)
{
  SET_BIT(SCU->SCCR, SCU_SCCR_CLKOUTEN);
}

/**
  * @brief  Disable clock output
  * @retval None
  */
__STATIC_INLINE void DDL_SCU_DisableMCO(void)
{
  CLEAR_BIT(SCU->SCCR, SCU_SCCR_CLKOUTEN);
}

/**
  * @brief  Configure MCOx
  * @param  Source This parameter can be one of the following values:
  *         @arg @ref DDL_SCU_MCOSOURCE_SYSCLK
  *         @arg @ref DDL_SCU_MCOSOURCE_HSI
  *         @arg @ref DDL_SCU_MCOSOURCE_LSI
  *         @arg @ref DDL_SCU_MCOSOURCE_HCLK
  * @param  Prescaler This parameter can be one of the following values:
  *         @arg @ref DDL_SCU_MCO_DIV_1
  *         @arg @ref DDL_SCU_MCO_DIV_2
  *         @arg @ref DDL_SCU_MCO_DIV_4
  *         @arg @ref DDL_SCU_MCO_DIV_8
  *         @arg @ref DDL_SCU_MCO_DIV_16
  *         @arg @ref DDL_SCU_MCO_DIV_32
  *         @arg @ref DDL_SCU_MCO_DIV_64
  *         @arg @ref DDL_SCU_MCO_DIV_128
  * @retval None
  */
__STATIC_INLINE void DDL_SCU_ConfigMCO(uint32_t Source, uint32_t Prescaler)
{
  MODIFY_REG(SCU->SCCR, (SCU_SCCR_CLKOUTSEL | SCU_SCCR_CLKOUTDIV), (Source | Prescaler));
}
/**
  * @}
  */

/** @defgroup SCU_DDL_EF_Peripheral_Reset Reset Peripheral Module
  * @{
  */
/**
  * @brief  Force reset the AHB peripheral module.
  * @param  Peripheral This parameter can be one of the following values:
  *         @arg @ref DDL_SCU_AHB_RESET_GPIOA
  *         @arg @ref DDL_SCU_AHB_RESET_GPIOB
  *         @arg @ref DDL_SCU_AHB_RESET_DMA
  *         @arg @ref DDL_SCU_AHB_RESET_CRC
  *         @arg @ref DDL_SCU_AHB_RESET_DIV
  *         @arg @ref DDL_SCU_AHB_RESET_FLASH
  * @retval None
  */
__STATIC_INLINE void DDL_SCU_ForceResetAHBPeripheral(uint32_t Peripheral)
{
  SET_BIT(SCU->AHBRST, Peripheral);
}
/**
  * @brief  Release Reset the AHB peripheral module.
  * @param  Peripheral This parameter can be one of the following values:
  *         @arg @ref DDL_SCU_AHB_RESET_GPIOA
  *         @arg @ref DDL_SCU_AHB_RESET_GPIOB
  *         @arg @ref DDL_SCU_AHB_RESET_DMA
  *         @arg @ref DDL_SCU_AHB_RESET_CRC
  *         @arg @ref DDL_SCU_AHB_RESET_DIV
  *         @arg @ref DDL_SCU_AHB_RESET_FLASH
  * @retval None
  */
__STATIC_INLINE void DDL_SCU_ReleaseResetAHBPeripheral(uint32_t Peripheral)
{
  CLEAR_BIT(SCU->AHBRST, Peripheral);
}

/**
  * @brief  Force reset the APB peripheral module.
  * @param  Peripheral This parameter can be one of the following values:
  *         @arg @ref DDL_SCU_APB_RESET_ATMR
  *         @arg @ref DDL_SCU_APB_RESET_GTMR
  *         @arg @ref DDL_SCU_APB_RESET_BTMR
  *         @arg @ref DDL_SCU_APB_RESET_SPI
  *         @arg @ref DDL_SCU_APB_RESET_UART0
  *         @arg @ref DDL_SCU_APB_RESET_UART1
  *         @arg @ref DDL_SCU_APB_RESET_EINT
  *         @arg @ref DDL_SCU_APB_RESET_COMP
  *         @arg @ref DDL_SCU_APB_RESET_ADC
  *         @arg @ref DDL_SCU_APB_RESET_LPTMR
  * @retval None
  */
__STATIC_INLINE void DDL_SCU_ForceResetAPBPeripheral(uint32_t Peripheral)
{
  SET_BIT(SCU->APBRST, Peripheral);
}

/**
  * @brief  Release Reset the APB peripheral module.
  * @param  Peripheral This parameter can be one of the following values:
  *         @arg @ref DDL_SCU_APB_RESET_ATMR
  *         @arg @ref DDL_SCU_APB_RESET_GTMR
  *         @arg @ref DDL_SCU_APB_RESET_BTMR
  *         @arg @ref DDL_SCU_APB_RESET_SPI
  *         @arg @ref DDL_SCU_APB_RESET_UART0
  *         @arg @ref DDL_SCU_APB_RESET_UART1
  *         @arg @ref DDL_SCU_APB_RESET_EINT
  *         @arg @ref DDL_SCU_APB_RESET_COMP
  *         @arg @ref DDL_SCU_APB_RESET_ADC
  *         @arg @ref DDL_SCU_APB_RESET_LPTMR
  * @retval None
  */
__STATIC_INLINE void DDL_SCU_ReleaseResetAPBPeripheral(uint32_t Peripheral)
{
  CLEAR_BIT(SCU->APBRST, Peripheral);
}
/**
  * @}
  */

/** @defgroup SCU_DDL_EF_Peripheral_Clock Enable Peripheral Clock
  * @{
  */
/**
  * @brief  Enable the AHB peripheral Clock.
  * @param  Peripheral This parameter can be one of the following values:
  *         @arg @ref DDL_SCU_AHB_PERIPHERAL_DMA
  *         @arg @ref DDL_SCU_AHB_PERIPHERAL_GPIOA
  *         @arg @ref DDL_SCU_AHB_PERIPHERAL_GPIOB
  *         @arg @ref DDL_SCU_AHB_PERIPHERAL_CRC
  *         @arg @ref DDL_SCU_AHB_PERIPHERAL_DIV
  * @retval None
  */
__STATIC_INLINE void DDL_SCU_EnableAHBPeripheralClock(uint32_t Peripheral)
{
  SET_BIT(SCU->AHBCG, Peripheral);
}

/**
  * @brief  Disable the AHB peripheral Clock.
  * @param  Peripheral This parameter can be one of the following values:
  *         @arg @ref DDL_SCU_AHB_PERIPHERAL_DMA
  *         @arg @ref DDL_SCU_AHB_PERIPHERAL_GPIOA
  *         @arg @ref DDL_SCU_AHB_PERIPHERAL_GPIOB
  *         @arg @ref DDL_SCU_AHB_PERIPHERAL_CRC
  *         @arg @ref DDL_SCU_AHB_PERIPHERAL_DIV
  * @retval None
  */
__STATIC_INLINE void DDL_SCU_DisableAHBPeripheralClock(uint32_t Peripheral)
{
  CLEAR_BIT(SCU->AHBCG, Peripheral);
}

/**
  * @brief  Check if AHB peripheral clock is enabled or not
  * @param  Peripheral This parameter can be a combination of the following values:
  *         @arg @ref DDL_SCU_AHB_PERIPHERAL_DMA
  *         @arg @ref DDL_SCU_AHB_PERIPHERAL_GPIOA
  *         @arg @ref DDL_SCU_AHB_PERIPHERAL_GPIOB
  *         @arg @ref DDL_SCU_AHB_PERIPHERAL_CRC
  *         @arg @ref DDL_SCU_AHB_PERIPHERAL_DIV
  *
  *         (*) value not defined in all devices.
  * @retval State of Peripheral clock (1 or 0).
*/
__STATIC_INLINE uint32_t DDL_SCU_IsEnabledAHBPeripheralClock(uint32_t Peripheral)
{
  return (READ_BIT(SCU->AHBCG, Peripheral) == Peripheral);
}

/**
  * @brief  Enable the APB peripheral Clock.
  * @param  Peripheral This parameter can be one of the following values:
  *         @arg @ref DDL_SCU_APB_PERIPHERAL_ATMR
  *         @arg @ref DDL_SCU_APB_PERIPHERAL_GTMR
  *         @arg @ref DDL_SCU_APB_PERIPHERAL_BTMR
  *         @arg @ref DDL_SCU_APB_PERIPHERAL_SPI
  *         @arg @ref DDL_SCU_APB_PERIPHERAL_UART0
  *         @arg @ref DDL_SCU_APB_PERIPHERAL_UART1
  *         @arg @ref DDL_SCU_APB_PERIPHERAL_WWDT
  *         @arg @ref DDL_SCU_APB_PERIPHERAL_EINT
  *         @arg @ref DDL_SCU_APB_PERIPHERAL_COMP
  *         @arg @ref DDL_SCU_APB_PERIPHERAL_ADC
  *         @arg @ref DDL_SCU_APB_PERIPHERAL_LPTMR
  * @retval None
  */
__STATIC_INLINE void DDL_SCU_EnableAPBPeripheralClock(uint32_t Peripheral)
{
  SET_BIT(SCU->APBCG, Peripheral);
}

/**
  * @brief  Disable the APB peripheral Clock.
  * @param  Peripheral This parameter can be one of the following values:
  *         @arg @ref DDL_SCU_APB_PERIPHERAL_ATMR
  *         @arg @ref DDL_SCU_APB_PERIPHERAL_GTMR
  *         @arg @ref DDL_SCU_APB_PERIPHERAL_BTMR
  *         @arg @ref DDL_SCU_APB_PERIPHERAL_SPI
  *         @arg @ref DDL_SCU_APB_PERIPHERAL_UART0
  *         @arg @ref DDL_SCU_APB_PERIPHERAL_UART1
  *         @arg @ref DDL_SCU_APB_PERIPHERAL_EINT
  *         @arg @ref DDL_SCU_APB_PERIPHERAL_COMP
  *         @arg @ref DDL_SCU_APB_PERIPHERAL_ADC
  *         @arg @ref DDL_SCU_APB_PERIPHERAL_LPTMR
  * @retval None
  */
__STATIC_INLINE void DDL_SCU_DisableAPBPeripheralClock(uint32_t Peripheral)
{
  CLEAR_BIT(SCU->APBCG, Peripheral);
}

/**
  * @brief  Check if APB peripheral clock is enabled or not
  * @param  Peripheral This parameter can be a combination of the following values:
  *         @arg @ref DDL_SCU_APB_PERIPHERAL_ATMR
  *         @arg @ref DDL_SCU_APB_PERIPHERAL_GTMR
  *         @arg @ref DDL_SCU_APB_PERIPHERAL_BTMR
  *         @arg @ref DDL_SCU_APB_PERIPHERAL_SPI
  *         @arg @ref DDL_SCU_APB_PERIPHERAL_UART0
  *         @arg @ref DDL_SCU_APB_PERIPHERAL_UART1
  *         @arg @ref DDL_SCU_APB_PERIPHERAL_WWDT
  *         @arg @ref DDL_SCU_APB_PERIPHERAL_EINT
  *         @arg @ref DDL_SCU_APB_PERIPHERAL_COMP
  *         @arg @ref DDL_SCU_APB_PERIPHERAL_ADC
  *         @arg @ref DDL_SCU_APB_PERIPHERAL_LPTMR
  *
  *         (*) value not defined in all devices.
  * @retval State of Peripheral clock (1 or 0).
*/
__STATIC_INLINE uint32_t DDL_SCU_IsEnabledAPBPeripheralClock(uint32_t Peripheral)
{
  return (READ_BIT(SCU->APBCG, Peripheral) == Peripheral);
}

/**
  * @}
  */


/** @defgroup SCU_DDL_EF_IT_SOURCE_Control IT SOURCE Control
  * @{
  */
/**
  * @brief  Enable LSI ready interrupt
  * @retval None
  */
__STATIC_INLINE void DDL_SCU_EnableIT_LSIRDY(void)
{
  SET_BIT(SCU->CIER, DDL_SCU_INT_LSIRDYEN);
}

/**
  * @brief  Disable LSI ready interrupt
  * @retval None
  */
__STATIC_INLINE void DDL_SCU_DisableIT_LSIRDY(void)
{
  CLEAR_BIT(SCU->CIER, DDL_SCU_INT_LSIRDYEN);
}

/**
  * @brief  Enable HSI ready interrupt
  * @retval None
  */
__STATIC_INLINE void DDL_SCU_EnableIT_HSIRDY(void)
{
  SET_BIT(SCU->CIER, DDL_SCU_INT_HSIRDYEN);
}

/**
  * @brief  Disable HSI ready interrupt
  * @retval None
  */
__STATIC_INLINE void DDL_SCU_DisableIT_HSIRDY(void)
{
  CLEAR_BIT(SCU->CIER, DDL_SCU_INT_HSIRDYEN);
}

/**
  * @brief  Checks if LSI ready interrupt source is enabled or disabled.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_SCU_IsEnabledIT_LSIRDY(void)
{
  return (READ_BIT(SCU->CIER, DDL_SCU_INT_LSIRDYEN) == (DDL_SCU_INT_LSIRDYEN));
}

/**
  * @brief  Checks if HSI ready interrupt source is enabled or disabled.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_SCU_IsEnabledIT_HSIRDY(void)
{
  return (READ_BIT(SCU->CIER, DDL_SCU_INT_HSIRDYEN) == (DDL_SCU_INT_HSIRDYEN));
}


/** @defgroup SCU_DDL_EF_IT_FLAG_Control IT FLAG Control
  * @{
  */
/**
  * @brief  Clear LSI ready interrupt flag
  * @retval None
  */
__STATIC_INLINE void DDL_SCU_ClearFlag_LSIRDY(void)
{
  CLEAR_BIT(SCU->CICR, DDL_SCU_INT_LSIRDYFLG);
}

/**
  * @brief  Clear HSI ready interrupt flag
  * @retval None
  */
__STATIC_INLINE void DDL_SCU_ClearFlag_HSIRDY(void)
{
  CLEAR_BIT(SCU->CICR, DDL_SCU_INT_HSIRDYFLG);
}

/**
  * @brief  Check if LSI ready interrupt occurred or not
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_SCU_IsActiveFlag_LSIRDY(void)
{
  return (READ_BIT(SCU->CICR, DDL_SCU_INT_LSIRDYFLG) == (DDL_SCU_INT_LSIRDYFLG));
}

/**
  * @brief  Check if HSI ready interrupt occurred or not
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_SCU_IsActiveFlag_HSIRDY(void)
{
  return (READ_BIT(SCU->CICR, DDL_SCU_INT_HSIRDYFLG) == (DDL_SCU_INT_HSIRDYFLG));
}

/**
  * @}
  */


/**
  * @}
  */

/** @defgroup SCU_DDL_EF_RESET_SOURCE_Control Reset SOURCE Control
  * @{
  */
/**
  * @brief  Enable PVD reset
  * @retval None
  */
__STATIC_INLINE void DDL_SCU_EnablePVDRST(void)
{
  SET_BIT(SCU->RSTCSR, SCU_RSTCSR_PVDRST_EN);
}

/**
  * @brief  Disable PVD reset
  * @retval None
  */
__STATIC_INLINE void DDL_SCU_DisablePVDRST(void)
{
  CLEAR_BIT(SCU->RSTCSR, SCU_RSTCSR_PVDRST_EN);
}

/**
  * @brief  Enable LOCKUP reset
  * @retval None
  */
__STATIC_INLINE void DDL_SCU_EnableLOCKUPRST(void)
{
  SET_BIT(SCU->RSTCSR, SCU_RSTCSR_LOCKUPRST_EN);
}

/**
  * @brief  Disable LOCKUP reset
  * @retval None
  */
__STATIC_INLINE void DDL_SCU_DisableLOCKUPRST(void)
{
  CLEAR_BIT(SCU->RSTCSR, SCU_RSTCSR_LOCKUPRST_EN);
}

/**
  * @brief  Checks if PVD reset source is enabled or disabled.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_SCU_IsEnabledPVDRST(void)
{
  return (READ_BIT(SCU->RSTCSR, SCU_RSTCSR_PVDRST_EN) == (SCU_RSTCSR_PVDRST_EN));
}

/**
  * @brief  Checks if LOCKUP reset source is enabled or disabled.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_SCU_IsEnabledLOCKUPRST(void)
{
  return (READ_BIT(SCU->RSTCSR, SCU_RSTCSR_LOCKUPRST_EN) == (SCU_RSTCSR_LOCKUPRST_EN));
}

/**
  * @}
  */


/** @defgroup SCU_DDL_EF_RESET_FLAG_Control Reset FLAG Control
  * @{
  */

/**
  * @brief  Clear opload reset flag
  * @retval None
  */
__STATIC_INLINE void DDL_SCU_ClearFlag_OPRST(void)
{
  CLEAR_BIT(SCU->RSTCSR, DDL_SCU_RSTCSR_OPRSTFLG);
}

/**
  * @brief  Clear pin reset flag
  * @retval None
  */
__STATIC_INLINE void DDL_SCU_ClearFlag_PINRST(void)
{
  CLEAR_BIT(SCU->RSTCSR, DDL_SCU_RSTCSR_PINRSTFLG);
}

/**
  * @brief  Clear porrst reset flag
  * @retval None
  */
__STATIC_INLINE void DDL_SCU_ClearFlag_PORRST(void)
{
  CLEAR_BIT(SCU->RSTCSR, DDL_SCU_RSTCSR_PORRSTFLG);
}

/**
  * @brief  Clear software reset flag
  * @retval None
  */
__STATIC_INLINE void DDL_SCU_ClearFlag_SFTRST(void)
{
  CLEAR_BIT(SCU->RSTCSR, DDL_SCU_RSTCSR_SFTRSTFLG);
}

/**
  * @brief  Clear iwdt reset flag
  * @retval None
  */
__STATIC_INLINE void DDL_SCU_ClearFlag_IWDTRST(void)
{
  CLEAR_BIT(SCU->RSTCSR, DDL_SCU_RSTCSR_IWDTRSTFLG);
}

/**
  * @brief  Clear wwdt reset flag
  * @retval None
  */
__STATIC_INLINE void DDL_SCU_ClearFlag_WWDTRST(void)
{
  CLEAR_BIT(SCU->RSTCSR, DDL_SCU_RSTCSR_WWDTRSTFLG);
}

/**
  * @brief  Clear pvd reset flag
  * @retval None
  */
__STATIC_INLINE void DDL_SCU_ClearFlag_PVDRST(void)
{
  CLEAR_BIT(SCU->RSTCSR, DDL_SCU_RSTCSR_PVDRSTFLG);
}

/**
  * @brief  Clear lockup reset flag
  * @retval None
  */
__STATIC_INLINE void DDL_SCU_ClearFlag_LOCKUPRST(void)
{
  CLEAR_BIT(SCU->RSTCSR, DDL_SCU_RSTCSR_LOCKUPRSTFLG);
}


/**
  * @brief  Check if opload reset flag is set or not.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_SCU_IsActiveFlag_OPRST(void)
{
  return (READ_BIT(SCU->RSTCSR, DDL_SCU_RSTCSR_OPRSTFLG) == (DDL_SCU_RSTCSR_OPRSTFLG));
}

/**
  * @brief  Check if pin reset flag is set or not.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_SCU_IsActiveFlag_PINRST(void)
{
  return (READ_BIT(SCU->RSTCSR, DDL_SCU_RSTCSR_PINRSTFLG) == (DDL_SCU_RSTCSR_PINRSTFLG));
}

/**
  * @brief  Check if Porrst reset flag is set or not.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_SCU_IsActiveFlag_PORRST(void)
{
  return (READ_BIT(SCU->RSTCSR, DDL_SCU_RSTCSR_PORRSTFLG) == (DDL_SCU_RSTCSR_PORRSTFLG));
}

/**
  * @brief  Check if Software reset flag is set or not.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_SCU_IsActiveFlag_SFTRST(void)
{
  return (READ_BIT(SCU->RSTCSR, DDL_SCU_RSTCSR_SFTRSTFLG) == (DDL_SCU_RSTCSR_SFTRSTFLG));
}

/**
  * @brief  Check if Independent Watchdog reset flag is set or not.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_SCU_IsActiveFlag_IWDTRST(void)
{
  return (READ_BIT(SCU->RSTCSR, DDL_SCU_RSTCSR_IWDTRSTFLG) == (DDL_SCU_RSTCSR_IWDTRSTFLG));
}

/**
  * @brief  Check if Window Watchdog reset flag is set or not.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_SCU_IsActiveFlag_WWDTRST(void)
{
  return (READ_BIT(SCU->RSTCSR, DDL_SCU_RSTCSR_WWDTRSTFLG) == (DDL_SCU_RSTCSR_WWDTRSTFLG));
}

/**
  * @brief  Check if PVD reset flag is set or not.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_SCU_IsActiveFlag_PVDRST(void)
{
  return (READ_BIT(SCU->RSTCSR, DDL_SCU_RSTCSR_PVDRSTFLG) == (DDL_SCU_RSTCSR_PVDRSTFLG));
}

/**
  * @brief  Check if LOCKUP reset flag is set or not.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_SCU_IsActiveFlag_LOCKUPRST(void)
{
  return (READ_BIT(SCU->RSTCSR, DDL_SCU_RSTCSR_LOCKUPRSTFLG) == (DDL_SCU_RSTCSR_LOCKUPRSTFLG));
}

/**
  * @}
  */

/** @defgroup SCU_DDL_EF_ADCCLK_DIV ADC module clock division
  * @{
  */

/**
  * @brief  Set ADC module clock division
  * @param  Div This parameter can be one of the following values:
  *         @arg @ref DDL_SCU_ADCCLK_DIVISION_2
  *         @arg @ref DDL_SCU_ADCCLK_DIVISION_4
  *         @arg @ref DDL_SCU_ADCCLK_DIVISION_8
  *         @arg @ref DDL_SCU_ADCCLK_DIVISION_16
  * @retval None
  */
__STATIC_INLINE void DDL_SCU_SetADCClkDiv(uint32_t Div)
{
  MODIFY_REG(SCU->ADCCR, SCU_ADCCR_ADCCLK_DIV, Div);
}

/**
  * @brief  Get ADC module clock division
  * @retval Can be one of the following values:
  *         @arg @ref DDL_SCU_ADCCLK_DIVISION_2
  *         @arg @ref DDL_SCU_ADCCLK_DIVISION_4
  *         @arg @ref DDL_SCU_ADCCLK_DIVISION_8
  *         @arg @ref DDL_SCU_ADCCLK_DIVISION_16
  */
__STATIC_INLINE uint32_t DDL_SCU_GetADCClkDiv(void)
{
  return (READ_BIT(SCU->ADCCR, SCU_ADCCR_ADCCLK_DIV));
}

/**
  * @}
  */

/** @defgroup SCU_DDL_EF_OPA Op-amp
  * @{
  */
/**
  * @brief  Enable OPA
  * @param  OPAx This parameter can be one of the following values:
  *         @arg @ref DDL_SCU_OPA0
  *         @arg @ref DDL_SCU_OPA1
  * @retval None
  */
__STATIC_INLINE void DDL_SCU_EnableOPAx(uint32_t OPAx)
{
  SET_BIT(SCU->OPAMPCR, (SCU_OPAMPCR_OPAMP0_EN << OFFSET_TAB_OPAx[OPAx]));
}

/**
  * @brief  Disable OPA
  * @param  OPAx This parameter can be one of the following values:
  *         @arg @ref DDL_SCU_OPA0
  *         @arg @ref DDL_SCU_OPA1
  * @retval None
  */
__STATIC_INLINE void DDL_SCU_DisableOPAx(uint32_t OPAx)
{
  CLEAR_BIT(SCU->OPAMPCR, (SCU_OPAMPCR_OPAMP0_EN << OFFSET_TAB_OPAx[OPAx]));
}

/**
  * @brief  Check if OPAx is already enabled or not.
  * @param  OPAx This parameter can be one of the following values:
  *         @arg @ref DDL_SCU_OPA0
  *         @arg @ref DDL_SCU_OPA1
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_SCU_IsEnabledOPAx(uint32_t OPAx)
{
  return (READ_BIT(SCU->OPAMPCR, (SCU_OPAMPCR_OPAMP0_EN << OFFSET_TAB_OPAx[OPAx])) == (SCU_OPAMPCR_OPAMP0_EN << OFFSET_TAB_OPAx[OPAx]));
}

/**
  * @brief  Set OPA gain selection
  * @param  OPAx This parameter can be one of the following values:
  *         @arg @ref DDL_SCU_OPA0
  *         @arg @ref DDL_SCU_OPA1
  * @param  Gain This parameter can be one of the following values:
  *         @arg @ref DDL_SCU_OPA_SEL_GAIN_0
  *         @arg @ref DDL_SCU_OPA_SEL_GAIN_1
  *         @arg @ref DDL_SCU_OPA_SEL_GAIN_4
  *         @arg @ref DDL_SCU_OPA_SEL_GAIN_6
  *         @arg @ref DDL_SCU_OPA_SEL_GAIN_8
  *         @arg @ref DDL_SCU_OPA_SEL_GAIN_10
  *         @arg @ref DDL_SCU_OPA_SEL_GAIN_12
  *         @arg @ref DDL_SCU_OPA_SEL_GAIN_16
  * @retval None
  */
__STATIC_INLINE void DDL_SCU_SetOPAxSelGain(uint32_t OPAx, uint32_t Gain)
{
  MODIFY_REG(SCU->OPAMPCR, (SCU_OPAMPCR_OPAMP0_SEL_GAIN << OFFSET_TAB_OPAx[OPAx]), (Gain << OFFSET_TAB_OPAx[OPAx]));
}

/**
  * @brief  Get OPA gain selection
  * @param  OPAx This parameter can be one of the following values:
  *         @arg @ref DDL_SCU_OPA0
  *         @arg @ref DDL_SCU_OPA1
  * @retval  Can be one of the following values:
  *         @arg @ref DDL_SCU_OPA_SEL_GAIN_0
  *         @arg @ref DDL_SCU_OPA_SEL_GAIN_1
  *         @arg @ref DDL_SCU_OPA_SEL_GAIN_4
  *         @arg @ref DDL_SCU_OPA_SEL_GAIN_6
  *         @arg @ref DDL_SCU_OPA_SEL_GAIN_8
  *         @arg @ref DDL_SCU_OPA_SEL_GAIN_10
  *         @arg @ref DDL_SCU_OPA_SEL_GAIN_12
  *         @arg @ref DDL_SCU_OPA_SEL_GAIN_16
  */
__STATIC_INLINE uint32_t DDL_SCU_GetOPAxSelGain(uint32_t OPAx)
{
  return (READ_BIT(SCU->OPAMPCR, (SCU_OPAMPCR_OPAMP0_SEL_GAIN << OFFSET_TAB_OPAx[OPAx])) >> OFFSET_TAB_OPAx[OPAx]);
}

/**
  * @brief  Enable OPA input control
  * @param  OPAx This parameter can be one of the following values:
  *         @arg @ref DDL_SCU_OPA0
  *         @arg @ref DDL_SCU_OPA1
  * @retval None
  */
__STATIC_INLINE void DDL_SCU_EnableOPAxInputCtrl(uint32_t OPAx)
{
  SET_BIT(SCU->OPAMPCR, (SCU_OPAMPCR_OPAMP0_IN_CTRL << OFFSET_TAB_OPAx[OPAx]));
}

/**
  * @brief  Disable OPA input control
  * @param  OPAx This parameter can be one of the following values:
  *         @arg @ref DDL_SCU_OPA0
  *         @arg @ref DDL_SCU_OPA1
  * @retval None
  */
__STATIC_INLINE void DDL_SCU_DisableOPAxInputCtrl(uint32_t OPAx)
{
  CLEAR_BIT(SCU->OPAMPCR, (SCU_OPAMPCR_OPAMP0_IN_CTRL << OFFSET_TAB_OPAx[OPAx]));
}

/**
  * @brief  Check if OPAx input control is already enabled or not.
  * @param  OPAx This parameter can be one of the following values:
  *         @arg @ref DDL_SCU_OPA0
  *         @arg @ref DDL_SCU_OPA1
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_SCU_IsEnabledOPAxInputCtrl(uint32_t OPAx)
{
  return (READ_BIT(SCU->OPAMPCR, (SCU_OPAMPCR_OPAMP0_IN_CTRL << OFFSET_TAB_OPAx[OPAx])) == (SCU_OPAMPCR_OPAMP0_IN_CTRL << OFFSET_TAB_OPAx[OPAx]));
}

/**
  * @brief  Enable OPA output control
  * @param  OPAx This parameter can be one of the following values:
  *         @arg @ref DDL_SCU_OPA0
  *         @arg @ref DDL_SCU_OPA1
  * @retval None
  */
__STATIC_INLINE void DDL_SCU_EnableOPAxOutputCtrl(uint32_t OPAx)
{
  SET_BIT(SCU->OPAMPCR, (SCU_OPAMPCR_OPAMP0_OUT_CTRL << OFFSET_TAB_OPAx[OPAx]));
}

/**
  * @brief  Disable OPA output control
  * @param  OPAx This parameter can be one of the following values:
  *         @arg @ref DDL_SCU_OPA0
  *         @arg @ref DDL_SCU_OPA1
  * @retval None
  */
__STATIC_INLINE void DDL_SCU_DisableOPAxOutputCtrl(uint32_t OPAx)
{
  CLEAR_BIT(SCU->OPAMPCR, (SCU_OPAMPCR_OPAMP0_OUT_CTRL << OFFSET_TAB_OPAx[OPAx]));
}

/**
  * @brief  Check if OPAx output control is already enabled or not.
  * @param  OPAx This parameter can be one of the following values:
  *         @arg @ref DDL_SCU_OPA0
  *         @arg @ref DDL_SCU_OPA1
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_SCU_IsEnabledOPAxOutputCtrl(uint32_t OPAx)
{
  return (READ_BIT(SCU->OPAMPCR, (SCU_OPAMPCR_OPAMP0_OUT_CTRL << OFFSET_TAB_OPAx[OPAx])) == (SCU_OPAMPCR_OPAMP0_OUT_CTRL << OFFSET_TAB_OPAx[OPAx]));
}

/**
  * @brief  Set OPA vcm
  * @param  Vcm This parameter can be one of the following values:
  *         @arg @ref DDL_SCU_OPA_VCM_0
  *         @arg @ref DDL_SCU_OPA_VCM_AVDD_0_5
  *         @arg @ref DDL_SCU_OPA_VCM_AVDD_0_25
  *         @arg @ref DDL_SCU_OPA_VCM_VBG
  *         @arg @ref DDL_SCU_OPA_VCM_VBG_0_25
  * @retval None
  */
__STATIC_INLINE void DDL_SCU_SetOPAxVCM(uint32_t Vcm)
{
  MODIFY_REG(SCU->OPAMPCR, SCU_OPAMPCR_OPAMP_SEL_MUX, Vcm);
}

/**
  * @brief  Get OPA vcm
  * @retval Can be one of the following values:
  *         @arg @ref DDL_SCU_OPA_VCM_0
  *         @arg @ref DDL_SCU_OPA_VCM_AVDD_0_5
  *         @arg @ref DDL_SCU_OPA_VCM_AVDD_0_25
  *         @arg @ref DDL_SCU_OPA_VCM_VBG
  *         @arg @ref DDL_SCU_OPA_VCM_VBG_0_25
  */
__STATIC_INLINE uint32_t DDL_SCU_GetOPAxVCM(void)
{
  return (READ_BIT(SCU->OPAMPCR, SCU_OPAMPCR_OPAMP_SEL_MUX));
}

/**
  * @}
  */

/** @defgroup SCU_DDL_EF_PVD PVD
  * @{
  */

/**
  * @brief  Enable Power Voltage Detector.
  * @retval None
  */
__STATIC_INLINE void DDL_SCU_EnablePVD(void)
{
  SET_BIT(SCU->PVDCSR, SCU_PVDCSR_PVDEN);
}

/**
  * @brief  Disable Power Voltage Detector.
  * @retval None
  */
__STATIC_INLINE void DDL_SCU_DisablePVD(void)
{
  CLEAR_BIT(SCU->PVDCSR, SCU_PVDCSR_PVDEN);
}

/**
  * @brief  Check if Power Voltage Detector is enabled
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_SCU_IsEnabledPVD(void)
{
  return (READ_BIT(SCU->PVDCSR, SCU_PVDCSR_PVDEN) == (SCU_PVDCSR_PVDEN));
}

/**
  * @brief  Set PVD threshold voltage configuration.
  * @param Threshold this parameter can between 0x0 to 0x7.
  * @retval None
  */
__STATIC_INLINE void DDL_SCU_SetPVDThreshold(uint32_t Threshold)
{
  MODIFY_REG(SCU->PVDCSR, SCU_PVDCSR_PVDTHSEL, (Threshold << SCU_PVDCSR_PVDTHSEL_Pos));
}

/**
  * @brief  Get PVD threshold voltage configuration.
  * @retval return values can between 0x0 to 0x7.
  */
__STATIC_INLINE uint32_t DDL_SCU_GetPVDThreshold(void)
{
  return (uint32_t)(READ_BIT(SCU->PVDCSR, SCU_PVDCSR_PVDTHSEL) >> SCU_PVDCSR_PVDTHSEL_Pos);
}

/**
  * @brief  Enable PVD low threshold voltage event detect.
  * @retval None
  */
__STATIC_INLINE void DDL_SCU_EnablePVDLowThresholdDetect(void)
{
  SET_BIT(SCU->PVDCSR, SCU_PVDCSR_PVD_LT);
}

/**
  * @brief  Disable PVD low threshold voltage event detect.
  * @retval None
  */
__STATIC_INLINE void DDL_SCU_DisablePVDLowThresholdDetect(void)
{
  CLEAR_BIT(SCU->PVDCSR, SCU_PVDCSR_PVD_LT);
}

/**
  * @brief  Check if PVD low threshold voltage event detect is already enabled or not.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_SCU_IsEnabledPVDLowThresholdDetect(void)
{
  return (READ_BIT(SCU->PVDCSR, SCU_PVDCSR_PVD_LT) == (SCU_PVDCSR_PVD_LT));
}

/**
  * @brief  Enable PVD high threshold voltage event detect.
  * @retval None
  */
__STATIC_INLINE void DDL_SCU_EnablePVDHighThresholdDetect(void)
{
  SET_BIT(SCU->PVDCSR, SCU_PVDCSR_PVD_HT);
}

/**
  * @brief  Disable PVD high threshold voltage event detect.
  * @retval None
  */
__STATIC_INLINE void DDL_SCU_DisablePVDHighThresholdDetect(void)
{
  CLEAR_BIT(SCU->PVDCSR, SCU_PVDCSR_PVD_HT);
}

/**
  * @brief  Check if PVD high threshold voltage event detect is already enabled or not.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_SCU_IsEnabledPVDHighThresholdDetect(void)
{
  return (READ_BIT(SCU->PVDCSR, SCU_PVDCSR_PVD_HT) == (SCU_PVDCSR_PVD_HT));
}

/**
  * @brief  Check if PVD interrupt event occurred or not
  * @retval State of PVD interrupt event occurred:
            1 : interrupt event has occurred
            0 : interrupt event has not occurred
  */
__STATIC_INLINE uint32_t DDL_SCU_IsActiveFlag_PVDIT(void)
{
  return (uint32_t)(READ_BIT(SCU->PVDCSR, SCU_PVDCSR_PVDF) == SCU_PVDCSR_PVDF);
}

/**
  * @brief  Clear PVD interrupt flag.
  * @retval None
  */
__STATIC_INLINE void DDL_SCU_ClearFlag_PVDIT(void)
{
  SET_BIT(SCU->PVDCSR, SCU_PVDCSR_PVDF);
}

/**
  * @brief  Get PVD monitoring results
  * @retval State of PVD Output:
            1 : VDD is higher than PVD Threshold
            0 : VDD is lower than PVD Threshold
  */
__STATIC_INLINE uint32_t DDL_SCU_IsActiveFlag_PVDO(void)
{
  return (uint32_t)(READ_BIT(SCU->PVDCSR, SCU_PVDCSR_PVDO) == SCU_PVDCSR_PVDO_Msk);
}

/**
  * @}
  */

/** @defgroup SCU_DDL_EF_Pre_Drive_Control Pre-drive control
  * @{
  */

/**
  * @brief  Enable Pre-drive
  * @retval None
  */
__STATIC_INLINE void DDL_SCU_EnablePreDrive(void)
{
  SET_BIT(SCU->PREDRVCR, SCU_PREDRVCR_PREDRV_EN);
}

/**
  * @brief  Disable Pre-drive
  * @retval None
  */
__STATIC_INLINE void DDL_SCU_DisablePreDrive(void)
{
  CLEAR_BIT(SCU->PREDRVCR, SCU_PREDRVCR_PREDRV_EN);
}

/**
  * @brief  Check if Pre-drive is already enabled or not.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_SCU_IsEnabledPreDrive(void)
{
  return (READ_BIT(SCU->PREDRVCR, SCU_PREDRVCR_PREDRV_EN) == (SCU_PREDRVCR_PREDRV_EN));
}

/**
  * @brief  Enable Pre-drive switch
  * @retval None
  */
__STATIC_INLINE void DDL_SCU_EnablePreDriveSW(void)
{
  SET_BIT(SCU->PREDRVCR, SCU_PREDRVCR_PREDRV_SW);
}

/**
  * @brief  Disable Pre-drive switch
  * @retval None
  */
__STATIC_INLINE void DDL_SCU_DisablePreDriveSW(void)
{
  CLEAR_BIT(SCU->PREDRVCR, SCU_PREDRVCR_PREDRV_SW);
}

/**
  * @brief  Check if Pre-drive switch is already enabled or not.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_SCU_IsEnabledPreDriveSW(void)
{
  return (READ_BIT(SCU->PREDRVCR, SCU_PREDRVCR_PREDRV_SW) == (SCU_PREDRVCR_PREDRV_SW));
}


/**
  * @brief  Set falling drive output slope time.
  * @param  Edge This parameter can be one of the following values:
  *         @arg @ref DDL_SCU_PREDRV_LO
  *         @arg @ref DDL_SCU_PREDRV_HO
  * @note   Absolute slope time depends on Edge (LO vs HO); see LEVEL macro comments.
  * @param  SlopeTime This parameter can be one of the following values:
  *         @arg @ref DDL_SCU_PREDRV_FALLING_SLOPE_LEVEL0
  *         @arg @ref DDL_SCU_PREDRV_FALLING_SLOPE_LEVEL1
  *         @arg @ref DDL_SCU_PREDRV_FALLING_SLOPE_LEVEL2
  *         @arg @ref DDL_SCU_PREDRV_FALLING_SLOPE_LEVEL3
  * @retval None
  */
__STATIC_INLINE void DDL_SCU_SetFallingSlopeTime(uint32_t Edge, uint32_t SlopeTime)
{
  MODIFY_REG(SCU->PREDRVCR, (SCU_PREDRVCR_PREDRV_LO_FALL_SEL << OFFSET_TAB_FallingSlope[Edge]), (SlopeTime << OFFSET_TAB_FallingSlope[Edge]));
}

/**
  * @brief  Get falling drive output slope time.
  * @param  Edge This parameter can be one of the following values:
  *         @arg @ref DDL_SCU_PREDRV_LO
  *         @arg @ref DDL_SCU_PREDRV_HO
  * @retval  Can be one of the following values:
  *         @arg @ref DDL_SCU_PREDRV_FALLING_SLOPE_LEVEL0
  *         @arg @ref DDL_SCU_PREDRV_FALLING_SLOPE_LEVEL1
  *         @arg @ref DDL_SCU_PREDRV_FALLING_SLOPE_LEVEL2
  *         @arg @ref DDL_SCU_PREDRV_FALLING_SLOPE_LEVEL3
  */
__STATIC_INLINE uint32_t DDL_SCU_GetFallingSlopeTime(uint32_t Edge)
{
  return (uint32_t)(READ_BIT(SCU->PREDRVCR, (SCU_PREDRVCR_PREDRV_LO_FALL_SEL << OFFSET_TAB_FallingSlope[Edge])) >> OFFSET_TAB_FallingSlope[Edge]);
}

/**
  * @brief  Set rising drive output slope time.
  * @param  Edge This parameter can be one of the following values:
  *         @arg @ref DDL_SCU_PREDRV_LO
  *         @arg @ref DDL_SCU_PREDRV_HO
  * @note   Absolute slope time depends on Edge (LO vs HO); see LEVEL macro comments.
  * @param  SlopeTime This parameter can be one of the following values:
  *         @arg @ref DDL_SCU_PREDRV_RISING_SLOPE_LEVEL0
  *         @arg @ref DDL_SCU_PREDRV_RISING_SLOPE_LEVEL1
  *         @arg @ref DDL_SCU_PREDRV_RISING_SLOPE_LEVEL2
  *         @arg @ref DDL_SCU_PREDRV_RISING_SLOPE_LEVEL3
  * @retval None
  */
__STATIC_INLINE void DDL_SCU_SetRisingSlopeTime(uint32_t Edge, uint32_t SlopeTime)
{
  MODIFY_REG(SCU->PREDRVCR, (SCU_PREDRVCR_PREDRV_LO_RISE_SEL << OFFSET_TAB_RisingSlope[Edge]), (SlopeTime << OFFSET_TAB_RisingSlope[Edge]));
}

/**
  * @brief  Get rising drive output slope time.
  * @param  Edge This parameter can be one of the following values:
  *         @arg @ref DDL_SCU_PREDRV_LO
  *         @arg @ref DDL_SCU_PREDRV_HO
  * @retval  Can be one of the following values:
  *         @arg @ref DDL_SCU_PREDRV_RISING_SLOPE_LEVEL0
  *         @arg @ref DDL_SCU_PREDRV_RISING_SLOPE_LEVEL1
  *         @arg @ref DDL_SCU_PREDRV_RISING_SLOPE_LEVEL2
  *         @arg @ref DDL_SCU_PREDRV_RISING_SLOPE_LEVEL3
  */
__STATIC_INLINE uint32_t DDL_SCU_GetRisingSlopeTime(uint32_t Edge)
{
  return (uint32_t)(READ_BIT(SCU->PREDRVCR, (SCU_PREDRVCR_PREDRV_LO_RISE_SEL << OFFSET_TAB_RisingSlope[Edge])) >> OFFSET_TAB_RisingSlope[Edge]);
}

/**
  * @}
  */

/** @defgroup SCU_DDL_EF_LVD LVD
  * @{
  */

/**
  * @brief  Check if LVD flag is already set or not.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_SCU_IsActiveFlag_LVD(void)
{
  return (READ_BIT(SCU->LVDCSR, SCU_LVDCSR_LVDF) == (SCU_LVDCSR_LVDF));
}

/**
  * @brief  Enable LVD interrupt
  * @retval None
  */
__STATIC_INLINE void DDL_SCU_EnableIT_LVD(void)
{
  SET_BIT(SCU->LVDCSR, SCU_LVDCSR_LVD_IE);
}

/**
  * @brief  Disable LVD interrupt
  * @retval None
  */
__STATIC_INLINE void DDL_SCU_DisableIT_LVD(void)
{
  CLEAR_BIT(SCU->LVDCSR, SCU_LVDCSR_LVD_IE);
}

/**
  * @brief  Check if LVD interrupt is already enabled or not.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_SCU_IsEnabledIT_LVD(void)
{
  return (READ_BIT(SCU->LVDCSR, SCU_LVDCSR_LVD_IE) == (SCU_LVDCSR_LVD_IE));
}


/**
  * @}
  */

#if defined(USE_FULL_DDL_DRIVER)
/** @defgroup SCU_DDL_EF_Init De-initialization function
  * @{
  */
ErrorStatus DDL_SCU_DeInit(void);
/**
  * @}
  */

/** @defgroup SCU_DDL_EF_Update_CLOCKs_Freq Update system and peripherals clocks frequency functions
  * @{
  */
void DDL_SCU_GetSysctrlClocksFreq(DDL_SCU_ClocksTypeDef *SCU_Clocks);
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

#endif  /* SCU */

/* Legacy aliases (e.g. former PREDRV_*NS slope names) */
#include "Legacy/g32_ddl_legacy.h"

/**
  * @}
  */
#ifdef __cplusplus
}
#endif

#endif /* G32M3101_DDL_SCU_H */
