/**
  *
   * @file        g32m3101_ddl_usart.h
  *
  * @brief       Header file of USART DDL module.
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
#ifndef G32M3101_DDL_USART_H
#define G32M3101_DDL_USART_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "g32m3xxx.h"
#include "Legacy/g32_ddl_legacy.h"

/** @addtogroup G32M3101_DDL_Driver
  * @{
  */

#if defined (UART0) || defined (UART1)

/** @defgroup USART_DDL USART
  * @{
  */

/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/

/* Private constants ---------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/
/* Exported types ------------------------------------------------------------*/
#if defined(USE_FULL_DDL_DRIVER)
/** @defgroup USART_DDL_ES_INIT USART Exported Init structures
  * @{
  */

/**
  * @brief LL USART Init Structure definition
  */
typedef struct
{
  uint32_t BaudRate;                  /*!< This field defines expected Usart communication baud rate.

                                           This feature can be modified afterwards using unitary function @ref DDL_USART_SetBaudRate().*/

  uint32_t DataWidth;                 /*!< Specifies the number of data bits transmitted or received in a frame.
                                           This parameter can be a value of @ref USART_DDL_EC_DATAWIDTH.

                                           This feature can be modified afterwards using unitary function @ref DDL_USART_SetDataWidth().*/

  uint32_t StopBits;                  /*!< Specifies the number of stop bits transmitted.
                                           This parameter can be a value of @ref USART_DDL_EC_STOPBITS.

                                           This feature can be modified afterwards using unitary function @ref DDL_USART_SetStopBitsLength().*/

  uint32_t Parity;                    /*!< Specifies the parity mode.
                                           This parameter can be a value of @ref USART_DDL_EC_PARITY.

                                           This feature can be modified afterwards using unitary function @ref DDL_USART_SetParity().*/

  uint32_t TransferDirection;         /*!< Specifies whether the Receive and/or Transmit mode is enabled or disabled.
                                           This parameter can be a value of @ref USART_DDL_EC_DIRECTION.

                                           This feature can be modified afterwards using unitary function @ref DDL_USART_SetTransferDirection().*/

} DDL_USART_InitTypeDef;

/**
  * @}
  */
#endif /* USE_FULL_DDL_DRIVER */

/* Exported constants --------------------------------------------------------*/
/** @defgroup USART_DDL_Exported_Constants USART Exported Constants
  * @{
  */

/** @defgroup USART_DDL_EC_GET_FLAG Get Flags Defines
  * @brief    Flags defines which can be used with DDL_USART_ReadReg function
  * @{
  */
#define DDL_USART_STS_PEFLG                          USART_STS_PEFLG                   /*!< Parity error flag */
#define DDL_USART_STS_FEFLG                          USART_STS_FEFLG                   /*!< Framing error flag */
#define DDL_USART_STS_NEFLG                          USART_STS_NEFLG                   /*!< Noise detected flag */
#define DDL_USART_STS_OVREFLG                        USART_STS_OVREFLG                 /*!< Overrun error flag */
#define DDL_USART_STS_IDLEFLG                        USART_STS_IDLEFLG                 /*!< Idle line detected flag */
#define DDL_USART_STS_RXBNEFLG                       USART_STS_RXNEFLG                 /*!< Read data register not empty flag */
#define DDL_USART_STS_TXCFLG                         USART_STS_TXCFLG                  /*!< Transmission complete flag */
#define DDL_USART_STS_TXBEFLG                        USART_STS_TXEFLG                  /*!< Transmit data register empty flag */
#define DDL_USART_STS_LBDFLG                         USART_STS_LBDFLG                  /*!< LIN break detection flag */
#define DDL_USART_STS_RXTOFLG                        USART_STS_RXTOFLG                 /*!< RXTO flag */
#define DDL_USART_STS_ABCFLG                         USART_STS_ABRDFLG                 /*!< ABC flag */
#define DDL_USART_STS_ABERRFLG                       USART_STS_ABRDEFLG                /*!< ABERR flag */
/**
  * @}
  */

/** @defgroup USART_DDL_EC_IT IT Defines
  * @brief    IT defines which can be used with DDL_USART_ReadReg and  DDL_USART_WriteReg functions
  * @{
  */
#define DDL_USART_CTRL1_IDLEIENN                  USART_CTRL1_IDLEIEN                 /*!< IDLE interrupt enable */
#define DDL_USART_CR1_RXBNEIEN                    USART_CTRL1_RXNEIEN                 /*!< Read data register not empty interrupt enable */
#define DDL_USART_CR1_TXCIEN                      USART_CTRL1_TXCIEN                  /*!< Transmission complete interrupt enable */
#define DDL_USART_CR1_TXBEIEN                     USART_CTRL1_TXEIEN                  /*!< Transmit data register empty interrupt enable */
#define DDL_USART_CTRL1_PEIENN                    USART_CTRL1_PEIEN                   /*!< Parity error */
#define DDL_USART_CTRL2_LBDIENN                   USART_CTRL2_LBDIEN                  /*!< LIN break detection interrupt enable */
#define DDL_USART_CTRL2_ABRCIENN                  USART_CTRL2_ABRCIEN                 /*!< Automic baud rate complete interrupt enable */
#define DDL_USART_CTRL2_ADREIENN                  USART_CTRL2_ADREIEN                 /*!< Automic baud rate error interrupt enable */
#define DDL_USART_CTRL3_ERRIEN                      USART_CTRL3_ERRIEN                  /*!< Error interrupt enable */
/**
  * @}
  */

/** @defgroup USART_DDL_EC_DIRECTION Communication Direction
  * @{
  */
#define DDL_USART_DIRECTION_NONE                 0x00000000U                            /*!< Transmitter and Receiver are disabled */
#define DDL_USART_DIRECTION_RX                   USART_CTRL1_RXEN                       /*!< Transmitter is disabled and Receiver is enabled */
#define DDL_USART_DIRECTION_TX                   USART_CTRL1_TXEN                       /*!< Transmitter is enabled and Receiver is disabled */
#define DDL_USART_DIRECTION_TX_RX                (USART_CTRL1_TXEN |USART_CTRL1_RXEN)   /*!< Transmitter and Receiver are enabled */
/**
  * @}
  */

/** @defgroup USART_DDL_EC_PARITY Parity Control
  * @{
  */
#define DDL_USART_PARITY_NONE                    0x00000000U                             /*!< Parity control disabled */
#define DDL_USART_PARITY_EVEN                    USART_CTRL1_PCEN                        /*!< Parity control enabled and Even Parity is selected */
#define DDL_USART_PARITY_ODD                     (USART_CTRL1_PCEN | USART_CTRL1_PCFG)   /*!< Parity control enabled and Odd Parity is selected */
/**
  * @}
  */

/** @defgroup USART_DDL_EC_DATAWIDTH Datawidth
  * @{
  */
#define DDL_USART_DATAWIDTH_8B                   0x00000000U             /*!< 8 bits word length : Start bit, 8 data bits, n stop bits */
#define DDL_USART_DATAWIDTH_9B                   USART_CTRL1_DBLCFG      /*!< 9 bits word length : Start bit, 9 data bits, n stop bits */
/**
  * @}
  */

/** @defgroup USART_DDL_EC_STOPBITS Stop Bits
  * @{
  */
#define DDL_USART_STOPBITS_1                     0x00000000U                                /*!< 1 stop bit */
#define DDL_USART_STOPBITS_2                     USART_CTRL2_STOPCFG                        /*!< 2 stop bits */
/**
  * @}
  */

/** @defgroup USART_DDL_EC_TXRX TX RX Pins Swap
  * @{
  */
#define DDL_USART_TXRX_STANDARD                  0x00000000U               /*!< TX/RX pins are used as defined in standard pinout */
#define DDL_USART_TXRX_SWAPPED                   (USART_CTRL1_SWAPEN)      /*!< TX and RX pins functions are swapped.             */
/**
  * @}
  */

/** @defgroup USART_DDL_EC_LINBREAK_DETECT LIN Break Detection Length
  * @{
  */
#define DDL_USART_LINBREAK_DETECT_10B            0x00000000U                /*!< 10-bit break detection method selected */
#define DDL_USART_LINBREAK_DETECT_11B            USART_CTRL2_LBDLCFG        /*!< 11-bit break detection method selected */
/**
  * @}
  */

/**
  * @}
  */

/* Exported macro ------------------------------------------------------------*/
/** @defgroup USART_DDL_Exported_Macros USART Exported Macros
  * @{
  */

/** @defgroup USART_DDL_EM_WRITE_READ Common Write and read registers Macros
  * @{
  */

/**
  * @brief  Write a value in USART register
  * @param  __INSTANCE__ USART Instance
  * @param  __REG__ Register to be written
  * @param  __VALUE__ Value to be written in the register
  * @retval None
  */
#define DDL_USART_WriteReg(__INSTANCE__, __REG__, __VALUE__) WRITE_REG(__INSTANCE__->__REG__, (__VALUE__))

/**
  * @brief  Read a value in USART register
  * @param  __INSTANCE__ USART Instance
  * @param  __REG__ Register to be read
  * @retval Register value
  */
#define DDL_USART_ReadReg(__INSTANCE__, __REG__) READ_REG(__INSTANCE__->__REG__)
/**
  * @}
  */

/** @defgroup USART_DDL_EM_Exported_Macros_Helper Exported_Macros_Helper
  * @{
  */

/**
  * @brief  Compute USARTDIV value according to Peripheral Clock and
  *         expected Baud Rate in 16 bits sampling mode (32 bits value of USARTDIV is returned)
  * @param  __PERIPHCLK__ Peripheral Clock frequency used for USART instance
  * @param  __BAUDRATE__ Baud rate value to achieve
  * @retval USARTDIV value to be used for BRR register filling in OverSampling_16 case
  */
#define __DDL_USART_DIV_SAMPLING16_100(__PERIPHCLK__, __BAUDRATE__)     ((uint32_t)((((uint64_t)(__PERIPHCLK__))*25)/(4*((uint64_t)(__BAUDRATE__)))))
#define __DDL_USART_DIVMANT_SAMPLING16(__PERIPHCLK__, __BAUDRATE__)     (__DDL_USART_DIV_SAMPLING16_100((__PERIPHCLK__), (__BAUDRATE__))/100)
#define __DDL_USART_DIVFRAQ_SAMPLING16(__PERIPHCLK__, __BAUDRATE__)     ((((__DDL_USART_DIV_SAMPLING16_100((__PERIPHCLK__), (__BAUDRATE__)) - (__DDL_USART_DIVMANT_SAMPLING16((__PERIPHCLK__), (__BAUDRATE__)) * 100)) * 16)\
                                                                         + 50) / 100)
/* USART BRR = mantissa + overflow + fraction
             = (USART DIVMANT << 4) + (USART DIVFRAQ & 0xF0) + (USART DIVFRAQ & 0x0F) */
#define __DDL_USART_DIV_SAMPLING16(__PERIPHCLK__, __BAUDRATE__)            (((__DDL_USART_DIVMANT_SAMPLING16((__PERIPHCLK__), (__BAUDRATE__)) << 4) + \
                                                                            (__DDL_USART_DIVFRAQ_SAMPLING16((__PERIPHCLK__), (__BAUDRATE__)) & 0xF0)) + \
                                                                           (__DDL_USART_DIVFRAQ_SAMPLING16((__PERIPHCLK__), (__BAUDRATE__)) & 0x0F))

/**
  * @}
  */

/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/

/** @defgroup USART_DDL_Exported_Functions USART Exported Functions
  * @{
  */

/** @defgroup USART_DDL_EF_Configuration Configuration functions
  * @{
  */

/**
  * @brief  USART Enable
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void DDL_USART_Enable(USART_TypeDef *USARTx)
{
  SET_BIT(USARTx->CTRL1, USART_CTRL1_UEN);
}

/**
  * @brief  USART Disable (all USART prescalers and outputs are disabled)
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void DDL_USART_Disable(USART_TypeDef *USARTx)
{
  CLEAR_BIT(USARTx->CTRL1, USART_CTRL1_UEN);
}

/**
  * @brief  Indicate if USART is enabled
  * @param  USARTx USART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_USART_IsEnabled(USART_TypeDef *USARTx)
{
  return (READ_BIT(USARTx->CTRL1, USART_CTRL1_UEN) == (USART_CTRL1_UEN));
}

/**
  * @brief  Receiver Enable (Receiver is enabled and begins searching for a start bit)
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void DDL_USART_EnableDirectionRx(USART_TypeDef *USARTx)
{
  SET_BIT(USARTx->CTRL1, USART_CTRL1_RXEN);
}

/**
  * @brief  Receiver Disable
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void DDL_USART_DisableDirectionRx(USART_TypeDef *USARTx)
{
  CLEAR_BIT(USARTx->CTRL1, USART_CTRL1_RXEN);
}

/**
  * @brief  Transmitter Enable
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void DDL_USART_EnableDirectionTx(USART_TypeDef *USARTx)
{
  SET_BIT(USARTx->CTRL1, USART_CTRL1_TXEN);
}

/**
  * @brief  Transmitter Disable
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void DDL_USART_DisableDirectionTx(USART_TypeDef *USARTx)
{
  CLEAR_BIT(USARTx->CTRL1, USART_CTRL1_TXEN);
}

/**
  * @brief  Configure simultaneously enabled/disabled states
  *         of Transmitter and Receiver
  * @param  USARTx USART Instance
  * @param  TransferDirection This parameter can be one of the following values:
  *         @arg @ref DDL_USART_DIRECTION_NONE
  *         @arg @ref DDL_USART_DIRECTION_RX
  *         @arg @ref DDL_USART_DIRECTION_TX
  *         @arg @ref DDL_USART_DIRECTION_TX_RX
  * @retval None
  */
__STATIC_INLINE void DDL_USART_SetTransferDirection(USART_TypeDef *USARTx, uint32_t TransferDirection)
{
  MODIFY_REG(USARTx->CTRL1, USART_CTRL1_RXEN | USART_CTRL1_TXEN, TransferDirection);
}

/**
  * @brief  Return enabled/disabled states of Transmitter and Receiver
  * @param  USARTx USART Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref DDL_USART_DIRECTION_NONE
  *         @arg @ref DDL_USART_DIRECTION_RX
  *         @arg @ref DDL_USART_DIRECTION_TX
  *         @arg @ref DDL_USART_DIRECTION_TX_RX
  */
__STATIC_INLINE uint32_t DDL_USART_GetTransferDirection(USART_TypeDef *USARTx)
{
  return (uint32_t)(READ_BIT(USARTx->CTRL1, USART_CTRL1_RXEN | USART_CTRL1_TXEN));
}

/**
  * @brief  Configure Parity (enabled/disabled and parity mode if enabled).
  * @param  USARTx USART Instance
  * @param  Parity This parameter can be one of the following values:
  *         @arg @ref DDL_USART_PARITY_NONE
  *         @arg @ref DDL_USART_PARITY_EVEN
  *         @arg @ref DDL_USART_PARITY_ODD
  * @retval None
  */
__STATIC_INLINE void DDL_USART_SetParity(USART_TypeDef *USARTx, uint32_t Parity)
{
  MODIFY_REG(USARTx->CTRL1, USART_CTRL1_PCFG | USART_CTRL1_PCEN, Parity);
}

/**
  * @brief  Return Parity configuration (enabled/disabled and parity mode if enabled)
  * @param  USARTx USART Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref DDL_USART_PARITY_NONE
  *         @arg @ref DDL_USART_PARITY_EVEN
  *         @arg @ref DDL_USART_PARITY_ODD
  */
__STATIC_INLINE uint32_t DDL_USART_GetParity(USART_TypeDef *USARTx)
{
  return (uint32_t)(READ_BIT(USARTx->CTRL1, USART_CTRL1_PCFG | USART_CTRL1_PCEN));
}

/**
  * @brief  Set Word length (i.e. nb of data bits, excluding start and stop bits)
  * @param  USARTx USART Instance
  * @param  DataWidth This parameter can be one of the following values:
  *         @arg @ref DDL_USART_DATAWIDTH_8B
  *         @arg @ref DDL_USART_DATAWIDTH_9B
  * @retval None
  */
__STATIC_INLINE void DDL_USART_SetDataWidth(USART_TypeDef *USARTx, uint32_t DataWidth)
{
  MODIFY_REG(USARTx->CTRL1, USART_CTRL1_DBLCFG, DataWidth);
}

/**
  * @brief  Return Word length (i.e. nb of data bits, excluding start and stop bits)
  * @param  USARTx USART Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref DDL_USART_DATAWIDTH_8B
  *         @arg @ref DDL_USART_DATAWIDTH_9B
  */
__STATIC_INLINE uint32_t DDL_USART_GetDataWidth(USART_TypeDef *USARTx)
{
  return (uint32_t)(READ_BIT(USARTx->CTRL1, USART_CTRL1_DBLCFG));
}

/**
  * @brief  Set the length of the stop bits
  * @param  USARTx USART Instance
  * @param  StopBits This parameter can be one of the following values:
  *         @arg @ref DDL_USART_STOPBITS_1
  *         @arg @ref DDL_USART_STOPBITS_2
  * @retval None
  */
__STATIC_INLINE void DDL_USART_SetStopBitsLength(USART_TypeDef *USARTx, uint32_t StopBits)
{
  MODIFY_REG(USARTx->CTRL2, USART_CTRL2_STOPCFG, StopBits);
}

/**
  * @brief  Retrieve the length of the stop bits
  * @param  USARTx USART Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref DDL_USART_STOPBITS_1
  *         @arg @ref DDL_USART_STOPBITS_2
  */
__STATIC_INLINE uint32_t DDL_USART_GetStopBitsLength(USART_TypeDef *USARTx)
{
  return (uint32_t)(READ_BIT(USARTx->CTRL2, USART_CTRL2_STOPCFG));
}

/**
  * @brief  Configure Character frame format (Datawidth, Parity control, Stop Bits)
  * @note   Call of this function is equivalent to following function call sequence :
  *         - Data Width configuration using @ref DDL_USART_SetDataWidth() function
  *         - Parity Control and mode configuration using @ref DDL_USART_SetParity() function
  *         - Stop bits configuration using @ref DDL_USART_SetStopBitsLength() function
  * @param  USARTx USART Instance
  * @param  DataWidth This parameter can be one of the following values:
  *         @arg @ref DDL_USART_DATAWIDTH_8B
  *         @arg @ref DDL_USART_DATAWIDTH_9B
  * @param  Parity This parameter can be one of the following values:
  *         @arg @ref DDL_USART_PARITY_NONE
  *         @arg @ref DDL_USART_PARITY_EVEN
  *         @arg @ref DDL_USART_PARITY_ODD
  * @param  StopBits This parameter can be one of the following values:
  *         @arg @ref DDL_USART_STOPBITS_1
  *         @arg @ref DDL_USART_STOPBITS_2
  * @retval None
  */
__STATIC_INLINE void DDL_USART_ConfigCharacter(USART_TypeDef *USARTx, uint32_t DataWidth, uint32_t Parity,
                                              uint32_t StopBits)
{
  MODIFY_REG(USARTx->CTRL1, USART_CTRL1_PCFG | USART_CTRL1_PCEN | USART_CTRL1_DBLCFG, Parity | DataWidth);
  MODIFY_REG(USARTx->CTRL2, USART_CTRL2_STOPCFG, StopBits);
}

/**
  * @brief  Swap TX/RX Pins Function Enable
  * @param  USARTx USART Instance
  * @param  SwapConfig This parameter can be one of the following values:
  *         @arg @ref DDL_USART_TXRX_STANDARD
  *         @arg @ref DDL_USART_TXRX_SWAPPED
  * @retval None
  */
__STATIC_INLINE void DDL_USART_SetTXRXSwap(USART_TypeDef *USARTx, uint32_t SwapConfig)
{
  MODIFY_REG(USARTx->CTRL1, USART_CTRL1_SWAPEN, SwapConfig);
}

/**
  * @brief  Swap TX/RX Pins Function Disable
  * @param  USARTx USART Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref DDL_USART_TXRX_STANDARD
  *         @arg @ref DDL_USART_TXRX_SWAPPED
  */
__STATIC_INLINE uint32_t DDL_USART_GetTXRXSwap(USART_TypeDef *USARTx)
{
  return (uint32_t)(READ_BIT(USARTx->CTRL1, USART_CTRL1_SWAPEN));
}

/**
  * @brief  Enable Auto Baud-Rate Detection
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void DDL_USART_EnableAutoBaudRate(USART_TypeDef *USARTx)
{
  SET_BIT(USARTx->CTRL2, USART_CTRL2_ABRDEN);
}

/**
  * @brief  Disable Auto Baud-Rate Detection
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void DDL_USART_DisableAutoBaudRate(USART_TypeDef *USARTx)
{
  CLEAR_BIT(USARTx->CTRL2, USART_CTRL2_ABRDEN);
}

/**
  * @brief  Indicate if Auto Baud-Rate Detection mechanism is enabled
  * @param  USARTx USART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_USART_IsEnabledAutoBaud(USART_TypeDef *USARTx)
{
  return ((READ_BIT(USARTx->CTRL2, USART_CTRL2_ABRDEN) == (USART_CTRL2_ABRDEN)) ? 1UL : 0UL);
}

/**
  * @brief  Receiver Timeout Enable
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void DDL_USART_EnableRXTimeout(USART_TypeDef *USARTx)
{
  SET_BIT(USARTx->CTRL1, USART_CTRL1_RXTODEN);
}

/**
  * @brief  Receiver Timeout Disable
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void DDL_USART_DisableRXTimeout(USART_TypeDef *USARTx)
{
  CLEAR_BIT(USARTx->CTRL1, USART_CTRL1_RXTODEN);
}

/**
  * @brief  Indicate if Receiver Timeout feature is enabled
  * @param  USARTx USART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_USART_IsEnabledRxTimeout(USART_TypeDef *USARTx)
{
  return ((READ_BIT(USARTx->CTRL1, USART_CTRL1_RXTODEN) == (USART_CTRL1_RXTODEN)) ? 1UL : 0UL);
}

/**
  * @brief  Enable One bit sampling method
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void DDL_USART_EnableOneBitSamp(USART_TypeDef *USARTx)
{
  SET_BIT(USARTx->CTRL3, USART_CTRL3_SAMCFG);
}

/**
  * @brief  Disable One bit sampling method
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void DDL_USART_DisableOneBitSamp(USART_TypeDef *USARTx)
{
  CLEAR_BIT(USARTx->CTRL3, USART_CTRL3_SAMCFG);
}

/**
  * @brief  Indicate if One bit sampling method is enabled
  * @param  USARTx USART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_USART_IsEnabledOneBitSamp(const USART_TypeDef *USARTx)
{
  return ((READ_BIT(USARTx->CTRL3, USART_CTRL3_SAMCFG) == (USART_CTRL3_SAMCFG)) ? 1UL : 0UL);
}

/**
  * @brief  Configure USART BRR register for achieving expected Baud Rate value.
  * @note   Compute and set USARTDIV value in BRR Register (full BRR content)
  *         according to used Peripheral Clock and expected Baud Rate values
  * @note   Peripheral clock and Baud rate values provided as function parameters should be valid
  *         (Baud rate value != 0)
  * @param  USARTx USART Instance
  * @param  PeriphClk Peripheral Clock
  * @param  BaudRate Baud Rate
  * @retval None
  */
__STATIC_INLINE void DDL_USART_SetBaudRate(USART_TypeDef *USARTx, uint32_t PeriphClk, uint32_t BaudRate)
{
  USARTx->BR = (uint16_t)(__DDL_USART_DIV_SAMPLING16(PeriphClk, BaudRate));
}

/**
  * @brief  Return current Baud Rate value, according to USARTDIV present in BRR register
  *         (full BRR content), and to used Peripheral Clock
  * @note   In case of non-initialized or invalid value stored in BRR register, value 0 will be returned.
  * @param  USARTx USART Instance
  * @param  PeriphClk Peripheral Clock
  * @retval Baud Rate
  */
__STATIC_INLINE uint32_t DDL_USART_GetBaudRate(USART_TypeDef *USARTx, uint32_t PeriphClk)
{
  uint32_t usartdiv = 0x0U;
  uint32_t brrresult = 0x0U;

  usartdiv = USARTx->BR;

  if ((usartdiv & 0xFFFFU) != 0U)
  {
    brrresult = PeriphClk / usartdiv;
  }

  return (brrresult);
}

/**
  * @brief  Set Receiver Time Out Value (expressed in nb of bits duration)
  * @param  USARTx USART Instance
  * @param  Timeout Value between Min_Data=0x00 and Max_Data=0x00FFFFFF
  * @retval None
  */
__STATIC_INLINE void DDL_USART_SetRxTimeout(USART_TypeDef *USARTx, uint32_t Timeout)
{
  MODIFY_REG(USARTx->RXTO, USART_RXTO_RXTO, Timeout);
}

/**
  * @brief  Get Receiver Time Out Value (expressed in nb of bits duration)
  * @param  USARTx USART Instance
  * @retval Value between Min_Data=0x00 and Max_Data=0x00FFFFFF
  */
__STATIC_INLINE uint32_t DDL_USART_GetRxTimeout(const USART_TypeDef *USARTx)
{
  return (uint32_t)(READ_BIT(USARTx->RXTO, USART_RXTO_RXTO));
}

/**
  * @}
  */

/** @defgroup USART_DDL_EF_Configuration_HalfDuplex Configuration functions related to Half Duplex feature
  * @{
  */

/**
  * @brief  Enable Single Wire Half-Duplex mode
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void DDL_USART_EnableHalfDuplex(USART_TypeDef *USARTx)
{
  SET_BIT(USARTx->CTRL3, USART_CTRL3_HDEN);
}

/**
  * @brief  Disable Single Wire Half-Duplex mode
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void DDL_USART_DisableHalfDuplex(USART_TypeDef *USARTx)
{
  CLEAR_BIT(USARTx->CTRL3, USART_CTRL3_HDEN);
}

/**
  * @brief  Indicate if Single Wire Half-Duplex mode is enabled
  * @param  USARTx USART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_USART_IsEnabledHalfDuplex(USART_TypeDef *USARTx)
{
  return (READ_BIT(USARTx->CTRL3, USART_CTRL3_HDEN) == (USART_CTRL3_HDEN));
}

/**
  * @}
  */

/** @defgroup USART_DDL_EF_Configuration_LIN Configuration functions related to LIN feature
  * @{
  */

/**
  * @brief  Set LIN Break Detection Length
  * @param  USARTx USART Instance
  * @param  LINBDLength This parameter can be one of the following values:
  *         @arg @ref DDL_USART_LINBREAK_DETECT_10B
  *         @arg @ref DDL_USART_LINBREAK_DETECT_11B
  * @retval None
  */
__STATIC_INLINE void DDL_USART_SetLINBrkDetectionLen(USART_TypeDef *USARTx, uint32_t LINBDLength)
{
  MODIFY_REG(USARTx->CTRL2, USART_CTRL2_LBDLCFG, LINBDLength);
}

/**
  * @brief  Return LIN Break Detection Length
  * @param  USARTx USART Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref DDL_USART_LINBREAK_DETECT_10B
  *         @arg @ref DDL_USART_LINBREAK_DETECT_11B
  */
__STATIC_INLINE uint32_t DDL_USART_GetLINBrkDetectionLen(USART_TypeDef *USARTx)
{
  return (uint32_t)(READ_BIT(USARTx->CTRL2, USART_CTRL2_LBDLCFG));
}

/**
  * @brief  Enable LIN mode
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void DDL_USART_EnableLIN(USART_TypeDef *USARTx)
{
  SET_BIT(USARTx->CTRL2, USART_CTRL2_LINMEN);
}

/**
  * @brief  Disable LIN mode
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void DDL_USART_DisableLIN(USART_TypeDef *USARTx)
{
  CLEAR_BIT(USARTx->CTRL2, USART_CTRL2_LINMEN);
}

/**
  * @brief  Indicate if LIN mode is enabled
  * @param  USARTx USART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_USART_IsEnabledLIN(USART_TypeDef *USARTx)
{
  return (READ_BIT(USARTx->CTRL2, USART_CTRL2_LINMEN) == (USART_CTRL2_LINMEN));
}

/**
  * @}
  */

/** @defgroup USART_DDL_EF_AdvancedConfiguration Advanced Configurations services
  * @{
  */

/**
  * @brief  Perform basic configuration of USART for enabling use in Asynchronous Mode (USART)
  * @note   In USART mode, the following bits must be kept cleared:
  *           - LINMEN bit in the USART_CTRL2 register,
  *           - HDEN bit in the USART_CTRL3 register.
  * @note   Call of this function is equivalent to following function call sequence :
  *         - Clear LINMEN in CTRL2 using @ref DDL_USART_DisableLIN() function
  *         - Clear HDEN in CTRL3 using @ref DDL_USART_DisableHalfDuplex() function
  * @note   Other remaining configurations items related to Asynchronous Mode
  *         (as Baud Rate, Word length, Parity, ...) should be set using
  *         dedicated functions
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void DDL_USART_ConfigAsyncMode(USART_TypeDef *USARTx)
{
  /* In Asynchronous mode, the following bits must be kept cleared:
  - LINMEN bits in the USART_CTRL2 register,
  - HDEN bits in the USART_CTRL3 register.*/
  CLEAR_BIT(USARTx->CTRL2, USART_CTRL2_LINMEN);
  CLEAR_BIT(USARTx->CTRL3, USART_CTRL3_HDEN);
}

/**
  * @brief  Perform basic configuration of USART for enabling use in LIN Mode
  * @note   In LIN mode, the following bits must be kept cleared:
  *           - HDEN bit in the USART_CTRL3 register.
  *         This function also set the USART in LIN mode.
  * @note   Call of this function is equivalent to following function call sequence :
  *         - Clear HDEN in CTRL3 using @ref DDL_USART_DisableHalfDuplex() function
  *         - Set LINMEN in CTRL2 using @ref DDL_USART_EnableLIN() function
  * @note   Other remaining configurations items related to LIN Mode
  *         (as Baud Rate, Word length, LIN Break Detection Length, ...) should be set using
  *         dedicated functions
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void DDL_USART_ConfigLINMode(USART_TypeDef *USARTx)
{
  /* In LIN mode, the following bits must be kept cleared:
  - HDEN bits in the USART_CTRL3 register.*/
  CLEAR_BIT(USARTx->CTRL3, USART_CTRL3_HDEN);
  /* Set the USART in LIN mode */
  SET_BIT(USARTx->CTRL2, USART_CTRL2_LINMEN);
}

/**
  * @brief  Perform basic configuration of USART for enabling use in Half Duplex Mode
  * @note   In Half Duplex mode, the following bits must be kept cleared:
  *           - LINMEN bit in the USART_CTRL2 register,
  *         This function also sets the USART in Half Duplex mode.
  * @note   Call of this function is equivalent to following function call sequence :
  *         - Clear LINMEN in CTRL2 using @ref DDL_USART_DisableLIN() function
  *         - Set HDEN in CTRL3 using @ref DDL_USART_EnableHalfDuplex() function
  * @note   Other remaining configurations items related to Half Duplex Mode
  *         (as Baud Rate, Word length, Parity, ...) should be set using
  *         dedicated functions
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void DDL_USART_ConfigHalfDuplexMode(USART_TypeDef *USARTx)
{
  /* In Half Duplex mode, the following bits must be kept cleared:
  - LINMEN bits in the USART_CTRL2 register.*/
  CLEAR_BIT(USARTx->CTRL2, (USART_CTRL2_LINMEN));
  /* set the USART in Half Duplex mode */
  SET_BIT(USARTx->CTRL3, USART_CTRL3_HDEN);
}

/**
  * @}
  */

/** @defgroup USART_DDL_EF_FLAG_Management FLAG_Management
  * @{
  */

/**
  * @brief  Check if the USART Parity Error Flag is set or not
  * @param  USARTx USART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_USART_IsActiveFlag_PE(USART_TypeDef *USARTx)
{
  return (READ_BIT(USARTx->STS, USART_STS_PEFLG) == (USART_STS_PEFLG));
}

/**
  * @brief  Check if the USART Framing Error Flag is set or not
  * @param  USARTx USART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_USART_IsActiveFlag_FE(USART_TypeDef *USARTx)
{
  return (READ_BIT(USARTx->STS, USART_STS_FEFLG) == (USART_STS_FEFLG));
}

/**
  * @brief  Check if the USART Noise error detected Flag is set or not
  * @param  USARTx USART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_USART_IsActiveFlag_NE(USART_TypeDef *USARTx)
{
  return (READ_BIT(USARTx->STS, USART_STS_NEFLG) == (USART_STS_NEFLG));
}

/**
  * @brief  Check if the USART OverRun Error Flag is set or not
  * @param  USARTx USART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_USART_IsActiveFlag_ORE(USART_TypeDef *USARTx)
{
  return (READ_BIT(USARTx->STS, USART_STS_OVREFLG) == (USART_STS_OVREFLG));
}

/**
  * @brief  Check if the USART IDLE line detected Flag is set or not
  * @param  USARTx USART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_USART_IsActiveFlag_IDLE(USART_TypeDef *USARTx)
{
  return (READ_BIT(USARTx->STS, USART_STS_IDLEFLG) == (USART_STS_IDLEFLG));
}

/**
  * @brief  Check if the USART Read Data Register Not Empty Flag is set or not
  * @param  USARTx USART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_USART_IsActiveFlag_RXNE(USART_TypeDef *USARTx)
{
  return (READ_BIT(USARTx->STS, USART_STS_RXNEFLG) == (USART_STS_RXNEFLG));
}

/**
  * @brief  Check if the USART Transmission Complete Flag is set or not
  * @param  USARTx USART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_USART_IsActiveFlag_TC(USART_TypeDef *USARTx)
{
  return (READ_BIT(USARTx->STS, USART_STS_TXCFLG) == (USART_STS_TXCFLG));
}

/**
  * @brief  Check if the USART Transmit Data Register Empty Flag is set or not
  * @param  USARTx USART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_USART_IsActiveFlag_TXE(USART_TypeDef *USARTx)
{
  return (READ_BIT(USARTx->STS, USART_STS_TXEFLG) == (USART_STS_TXEFLG));
}

/**
  * @brief  Check if the USART LIN Break Detection Flag is set or not
  * @param  USARTx USART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_USART_IsActiveFlag_LBD(USART_TypeDef *USARTx)
{
  return (READ_BIT(USARTx->STS, USART_STS_LBDFLG) == (USART_STS_LBDFLG));
}

/**
  * @brief  Check if the USART Receive timeout Flag is set or not
  * @param  USARTx USART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_USART_IsActiveFlag_RXTO(USART_TypeDef *USARTx)
{
  return (READ_BIT(USARTx->STS, USART_STS_RXTOFLG) == (USART_STS_RXTOFLG));
}

/**
  * @brief  Check if the USART automic baud rate complete Flag is set or not
  * @param  USARTx USART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_USART_IsActiveFlag_ABC(USART_TypeDef *USARTx)
{
  return (READ_BIT(USARTx->STS, USART_STS_ABRDFLG) == (USART_STS_ABRDFLG));
}

/**
  * @brief  Check if the USART automic baud rate error Flag is set or not
  * @param  USARTx USART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_USART_IsActiveFlag_ABERR(USART_TypeDef *USARTx)
{
  return (READ_BIT(USARTx->STS, USART_STS_ABRDEFLG) == (USART_STS_ABRDEFLG));
}

/**
  * @brief  Check if the USART Send Break Flag is set or not
  * @param  USARTx USART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_USART_IsActiveFlag_SBK(USART_TypeDef *USARTx)
{
  return (READ_BIT(USARTx->CTRL1, USART_CTRL1_TXBF) == (USART_CTRL1_TXBF));
}

/**
  * @brief  Clear Parity Error Flag
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void DDL_USART_ClearFlag_PE(USART_TypeDef *USARTx)
{
  __IO uint32_t tmpreg;
  tmpreg = USARTx->STS;
  (void) tmpreg;
  tmpreg = USARTx->DATA;
  (void) tmpreg;
}

/**
  * @brief  Clear Framing Error Flag
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void DDL_USART_ClearFlag_FE(USART_TypeDef *USARTx)
{
  __IO uint32_t tmpreg;
  tmpreg = USARTx->STS;
  (void) tmpreg;
  tmpreg = USARTx->DATA;
  (void) tmpreg;
}

/**
  * @brief  Clear Noise detected Flag
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void DDL_USART_ClearFlag_NE(USART_TypeDef *USARTx)
{
  __IO uint32_t tmpreg;
  tmpreg = USARTx->STS;
  (void) tmpreg;
  tmpreg = USARTx->DATA;
  (void) tmpreg;
}

/**
  * @brief  Clear OverRun Error Flag
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void DDL_USART_ClearFlag_ORE(USART_TypeDef *USARTx)
{
  __IO uint32_t tmpreg;
  tmpreg = USARTx->STS;
  (void) tmpreg;
  tmpreg = USARTx->DATA;
  (void) tmpreg;
}

/**
  * @brief  Clear IDLE line detected Flag
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void DDL_USART_ClearFlag_IDLE(USART_TypeDef *USARTx)
{
  __IO uint32_t tmpreg;
  tmpreg = USARTx->STS;
  (void) tmpreg;
  tmpreg = USARTx->DATA;
  (void) tmpreg;
}

/**
  * @brief  Clear Transmission Complete Flag
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void DDL_USART_ClearFlag_TC(USART_TypeDef *USARTx)
{
  WRITE_REG(USARTx->STS, ~(USART_STS_TXCFLG));
}

/**
  * @brief  Clear RX Not Empty Flag
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void DDL_USART_ClearFlag_RXNE(USART_TypeDef *USARTx)
{
  WRITE_REG(USARTx->STS, ~(USART_STS_RXNEFLG));
}

/**
  * @brief  Clear LIN Break Detection Flag
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void DDL_USART_ClearFlag_LBD(USART_TypeDef *USARTx)
{
  WRITE_REG(USARTx->STS, ~(USART_STS_LBDFLG));
}

/**
  * @brief  Clear RX Time out Flag
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void DDL_USART_ClearFlag_RXTO(USART_TypeDef *USARTx)
{
  WRITE_REG(USARTx->STS, ~(USART_STS_RXTOFLG));
}

/**
  * @brief  Clear Automatic bps complete Flag
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void DDL_USART_ClearFlag_ABC(USART_TypeDef *USARTx)
{
  WRITE_REG(USARTx->STS, ~(USART_STS_ABRDFLG));
}

/**
  * @brief  Clear Automatic bps error Flag
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void DDL_USART_ClearFlag_ABERR(USART_TypeDef *USARTx)
{
  WRITE_REG(USARTx->STS, ~(USART_STS_ABRDEFLG));
}

/**
  * @}
  */

/** @defgroup USART_DDL_EF_IT_Management IT_Management
  * @{
  */

/**
  * @brief  Enable IDLE Interrupt
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void DDL_USART_EnableIT_IDLE(USART_TypeDef *USARTx)
{
  SET_BIT(USARTx->CTRL1, USART_CTRL1_IDLEIEN);
}

/**
  * @brief  Enable RX Not Empty Interrupt
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void DDL_USART_EnableIT_RXNE(USART_TypeDef *USARTx)
{
  SET_BIT(USARTx->CTRL1, USART_CTRL1_RXNEIEN);
}

/**
  * @brief  Enable Transmission Complete Interrupt
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void DDL_USART_EnableIT_TC(USART_TypeDef *USARTx)
{
  SET_BIT(USARTx->CTRL1, USART_CTRL1_TXCIEN);
}

/**
  * @brief  Enable TX Empty Interrupt
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void DDL_USART_EnableIT_TXE(USART_TypeDef *USARTx)
{
  SET_BIT(USARTx->CTRL1, USART_CTRL1_TXEIEN);
}

/**
  * @brief  Enable Parity Error Interrupt
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void DDL_USART_EnableIT_PE(USART_TypeDef *USARTx)
{
  SET_BIT(USARTx->CTRL1, USART_CTRL1_PEIEN);
}

/**
  * @brief  Enable Receiver Timeout Interrupt
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void DDL_USART_EnableIT_RTO(USART_TypeDef *USARTx)
{
  SET_BIT(USARTx->CTRL1, USART_CTRL1_RXTOIEN);
}

/**
  * @brief  Enable LIN Break Detection Interrupt
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void DDL_USART_EnableIT_LBD(USART_TypeDef *USARTx)
{
  SET_BIT(USARTx->CTRL2, USART_CTRL2_LBDIEN);
}

/**
  * @brief  Enable Automatic bps complete Interrupt
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void DDL_USART_EnableIT_ABC(USART_TypeDef *USARTx)
{
  SET_BIT(USARTx->CTRL2, USART_CTRL2_ABRCIEN);
}

/**
  * @brief  Enable Automatic bps detection error Interrupt
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void DDL_USART_EnableIT_ADE(USART_TypeDef *USARTx)
{
  SET_BIT(USARTx->CTRL2, USART_CTRL2_ADREIEN);
}

/**
  * @brief  Enable Error Interrupt
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void DDL_USART_EnableIT_ERROR(USART_TypeDef *USARTx)
{
  SET_BIT(USARTx->CTRL3, USART_CTRL3_ERRIEN);
}

/**
  * @brief  Disable IDLE Interrupt
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void DDL_USART_DisableIT_IDLE(USART_TypeDef *USARTx)
{
  CLEAR_BIT(USARTx->CTRL1, USART_CTRL1_IDLEIEN);
}

/**
  * @brief  Disable RX Not Empty Interrupt
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void DDL_USART_DisableIT_RXNE(USART_TypeDef *USARTx)
{
  CLEAR_BIT(USARTx->CTRL1, USART_CTRL1_RXNEIEN);
}

/**
  * @brief  Disable Transmission Complete Interrupt
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void DDL_USART_DisableIT_TC(USART_TypeDef *USARTx)
{
  CLEAR_BIT(USARTx->CTRL1, USART_CTRL1_TXCIEN);
}

/**
  * @brief  Disable TX Empty Interrupt
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void DDL_USART_DisableIT_TXE(USART_TypeDef *USARTx)
{
  CLEAR_BIT(USARTx->CTRL1, USART_CTRL1_TXEIEN);
}

/**
  * @brief  Disable Parity Error Interrupt
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void DDL_USART_DisableIT_PE(USART_TypeDef *USARTx)
{
  CLEAR_BIT(USARTx->CTRL1, USART_CTRL1_PEIEN);
}

/**
  * @brief  Disable Receiver Timeout Interrupt
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void DDL_USART_DisableIT_RTO(USART_TypeDef *USARTx)
{
  CLEAR_BIT(USARTx->CTRL1, USART_CTRL1_RXTOIEN);
}

/**
  * @brief  Disable LIN Break Detection Interrupt
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void DDL_USART_DisableIT_LBD(USART_TypeDef *USARTx)
{
  CLEAR_BIT(USARTx->CTRL2, USART_CTRL2_LBDIEN);
}

/**
  * @brief  Disable Automatic bps complete Interrupt
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void DDL_USART_DisableIT_ABC(USART_TypeDef *USARTx)
{
  CLEAR_BIT(USARTx->CTRL2, USART_CTRL2_ABRCIEN);
}

/**
  * @brief  Disable Automatic bps detection error Interrupt
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void DDL_USART_DisableIT_ADE(USART_TypeDef *USARTx)
{
  CLEAR_BIT(USARTx->CTRL2, USART_CTRL2_ADREIEN);
}

/**
  * @brief  Disable Error Interrupt
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void DDL_USART_DisableIT_ERROR(USART_TypeDef *USARTx)
{
  CLEAR_BIT(USARTx->CTRL3, USART_CTRL3_ERRIEN);
}

/**
  * @brief  Check if the USART IDLE Interrupt  source is enabled or disabled.
  * @param  USARTx USART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_USART_IsEnabledIT_IDLE(USART_TypeDef *USARTx)
{
  return (READ_BIT(USARTx->CTRL1, USART_CTRL1_IDLEIEN) == (USART_CTRL1_IDLEIEN));
}

/**
  * @brief  Check if the USART RX Not Empty Interrupt is enabled or disabled.
  * @param  USARTx USART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_USART_IsEnabledIT_RXNE(USART_TypeDef *USARTx)
{
  return (READ_BIT(USARTx->CTRL1, USART_CTRL1_RXNEIEN) == (USART_CTRL1_RXNEIEN));
}

/**
  * @brief  Check if the USART Transmission Complete Interrupt is enabled or disabled.
  * @param  USARTx USART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_USART_IsEnabledIT_TC(USART_TypeDef *USARTx)
{
  return (READ_BIT(USARTx->CTRL1, USART_CTRL1_TXCIEN) == (USART_CTRL1_TXCIEN));
}

/**
  * @brief  Check if the USART TX Empty Interrupt is enabled or disabled.
  * @param  USARTx USART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_USART_IsEnabledIT_TXE(USART_TypeDef *USARTx)
{
  return (READ_BIT(USARTx->CTRL1, USART_CTRL1_TXEIEN) == (USART_CTRL1_TXEIEN));
}

/**
  * @brief  Check if the USART Parity Error Interrupt is enabled or disabled.
  * @param  USARTx USART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_USART_IsEnabledIT_PE(USART_TypeDef *USARTx)
{
  return (READ_BIT(USARTx->CTRL1, USART_CTRL1_PEIEN) == (USART_CTRL1_PEIEN));
}

/**
  * @brief  Check if the USART Receiver Timeout Interrupt is enabled or disabled.
  * @param  USARTx USART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_USART_IsEnabledIT_RTO(USART_TypeDef *USARTx)
{
  return ((READ_BIT(USARTx->CTRL1, USART_CTRL1_RXTOIEN) == (USART_CTRL1_RXTOIEN)) ? 1UL : 0UL);
}

/**
  * @brief  Check if the USART LIN Break Detection Interrupt is enabled or disabled.
  * @param  USARTx USART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_USART_IsEnabledIT_LBD(USART_TypeDef *USARTx)
{
  return (READ_BIT(USARTx->CTRL2, USART_CTRL2_LBDIEN) == (USART_CTRL2_LBDIEN));
}

/**
  * @brief  Check if the USART Error Interrupt is enabled or disabled.
  * @param  USARTx USART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_USART_IsEnabledIT_ERROR(USART_TypeDef *USARTx)
{
  return (READ_BIT(USARTx->CTRL3, USART_CTRL3_ERRIEN) == (USART_CTRL3_ERRIEN));
}

/**
  * @}
  */

/** @defgroup USART_DDL_EF_DMA_Management DMA_Management
  * @{
  */

/**
  * @brief  Enable DMA Mode for reception
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void DDL_USART_EnableDMAReq_RX(USART_TypeDef *USARTx)
{
  SET_BIT(USARTx->CTRL3, USART_CTRL3_DMARXEN);
}

/**
  * @brief  Disable DMA Mode for reception
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void DDL_USART_DisableDMAReq_RX(USART_TypeDef *USARTx)
{
  CLEAR_BIT(USARTx->CTRL3, USART_CTRL3_DMARXEN);
}

/**
  * @brief  Check if DMA Mode is enabled for reception
  * @param  USARTx USART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_USART_IsEnabledDMAReq_RX(USART_TypeDef *USARTx)
{
  return (READ_BIT(USARTx->CTRL3, USART_CTRL3_DMARXEN) == (USART_CTRL3_DMARXEN));
}

/**
  * @brief  Enable DMA Mode for transmission
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void DDL_USART_EnableDMAReq_TX(USART_TypeDef *USARTx)
{
  SET_BIT(USARTx->CTRL3, USART_CTRL3_DMATXEN);
}

/**
  * @brief  Disable DMA Mode for transmission
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void DDL_USART_DisableDMAReq_TX(USART_TypeDef *USARTx)
{
  CLEAR_BIT(USARTx->CTRL3, USART_CTRL3_DMATXEN);
}

/**
  * @brief  Check if DMA Mode is enabled for transmission
  * @param  USARTx USART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_USART_IsEnabledDMAReq_TX(USART_TypeDef *USARTx)
{
  return (READ_BIT(USARTx->CTRL3, USART_CTRL3_DMATXEN) == (USART_CTRL3_DMATXEN));
}

/**
  * @brief  Get the data register address used for DMA transfer
  * @param  USARTx USART Instance
  * @retval Address of data register
  */
__STATIC_INLINE uint32_t DDL_USART_DMA_GetRegAddr(USART_TypeDef *USARTx)
{
  /* return address of DR register */
  return ((uint32_t) &(USARTx->DATA));
}

/**
  * @}
  */

/** @defgroup USART_DDL_EF_Data_Management Data_Management
  * @{
  */

/**
  * @brief  Read Receiver Data register (Receive Data value, 8 bits)
  * @param  USARTx USART Instance
  * @retval Value between Min_Data=0x00 and Max_Data=0xFF
  */
__STATIC_INLINE uint8_t DDL_USART_ReceiveData8(USART_TypeDef *USARTx)
{
  return (uint8_t)(READ_BIT(USARTx->DATA, USART_DATA_DATA));
}

/**
  * @brief  Read Receiver Data register (Receive Data value, 9 bits)
  * @param  USARTx USART Instance
  * @retval Value between Min_Data=0x00 and Max_Data=0x1FF
  */
__STATIC_INLINE uint16_t DDL_USART_ReceiveData9(USART_TypeDef *USARTx)
{
  return (uint16_t)(READ_BIT(USARTx->DATA, USART_DATA_DATA));
}

/**
  * @brief  Write in Transmitter Data Register (Transmit Data value, 8 bits)
  * @param  USARTx USART Instance
  * @param  Value between Min_Data=0x00 and Max_Data=0xFF
  * @retval None
  */
__STATIC_INLINE void DDL_USART_TransmitData8(USART_TypeDef *USARTx, uint8_t Value)
{
  USARTx->DATA = Value;
}

/**
  * @brief  Write in Transmitter Data Register (Transmit Data value, 9 bits)
  * @param  USARTx USART Instance
  * @param  Value between Min_Data=0x00 and Max_Data=0x1FF
  * @retval None
  */
__STATIC_INLINE void DDL_USART_TransmitData9(USART_TypeDef *USARTx, uint16_t Value)
{
  USARTx->DATA = Value & 0x1FFU;
}

/**
  * @}
  */

/** @defgroup USART_DDL_EF_Execution Execution
  * @{
  */

/**
  * @brief  Request Break sending
  * @param  USARTx USART Instance
  * @retval None
  */
__STATIC_INLINE void DDL_USART_RequestBreakSending(USART_TypeDef *USARTx)
{
  SET_BIT(USARTx->CTRL1, USART_CTRL1_TXBF);
}

/**
  * @}
  */

#if defined(USE_FULL_DDL_DRIVER)
/** @defgroup USART_DDL_EF_Init Initialization and de-initialization functions
  * @{
  */
ErrorStatus DDL_USART_DeInit(USART_TypeDef *USARTx);
ErrorStatus DDL_USART_Init(USART_TypeDef *USARTx, DDL_USART_InitTypeDef *USART_InitStruct);
void        DDL_USART_StructInit(DDL_USART_InitTypeDef *USART_InitStruct);
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

#endif /* UART0 || UART1 */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* G32M3101_DDL_USART_H */
