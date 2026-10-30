/**
  *
  * @file        g32m3101_ddl_usart.c
  *
  * @brief       USART DDL module driver.
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
  *
  */

#if defined(USE_FULL_DDL_DRIVER)

/* Includes ------------------------------------------------------------------*/
#include "g32m3101_ddl_usart.h"
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

#if defined (UART0) || defined (UART1)

/** @addtogroup USART_DDL
  * @{
  */

/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private constants ---------------------------------------------------------*/
/** @addtogroup USART_DDL_Private_Constants
  * @{
  */

/**
  * @}
  */


/* Private macros ------------------------------------------------------------*/
/** @addtogroup USART_DDL_Private_Macros
  * @{
  */

/* __BAUDRATE__ The maximum Baud Rate is derived from the maximum clock available
 *              divided by the smallest oversampling used on the USART (i.e. 8)    */
#define IS_DDL_USART_BAUDRATE(__BAUDRATE__) ((__BAUDRATE__) <= 12500000U)

/* __VALUE__ In case of oversampling by 16 and 8, BRR content must be greater than or equal to 16d. */
#define IS_DDL_USART_BR_MIN(__VALUE__) ((__VALUE__) >= 16U)

#define IS_DDL_USART_DIRECTION(__VALUE__) (((__VALUE__) == DDL_USART_DIRECTION_NONE) \
                                          || ((__VALUE__) == DDL_USART_DIRECTION_RX) \
                                          || ((__VALUE__) == DDL_USART_DIRECTION_TX) \
                                          || ((__VALUE__) == DDL_USART_DIRECTION_TX_RX))

#define IS_DDL_USART_PARITY(__VALUE__) (((__VALUE__) == DDL_USART_PARITY_NONE) \
                                       || ((__VALUE__) == DDL_USART_PARITY_EVEN) \
                                       || ((__VALUE__) == DDL_USART_PARITY_ODD))

#define IS_DDL_USART_DATAWIDTH(__VALUE__) (((__VALUE__) == DDL_USART_DATAWIDTH_8B) \
                                          || ((__VALUE__) == DDL_USART_DATAWIDTH_9B))

#define IS_DDL_USART_STOPBITS(__VALUE__) (((__VALUE__) == DDL_USART_STOPBITS_1)\
                                         || ((__VALUE__) == DDL_USART_STOPBITS_2))

/**
  * @}
  */

/* Private function prototypes -----------------------------------------------*/

/* Exported functions --------------------------------------------------------*/
/** @addtogroup USART_DDL_Exported_Functions
  * @{
  */

/** @addtogroup USART_DDL_EF_Init
  * @{
  */

/**
  * @brief  De-initialize USART registers (Registers restored to their default values).
  * @param  USARTx USART Instance
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS: USART registers are de-initialized
  *          - ERROR: USART registers are not de-initialized
  */
ErrorStatus DDL_USART_DeInit(USART_TypeDef *USARTx)
{
  ErrorStatus status = SUCCESS;

  /* Check the parameters */
  ASSERT_PARAM(IS_UART_INSTANCE(USARTx));

  DDL_SCU_Unlock();

  if (USARTx == UART0)
  {
    DDL_APB_GRP1_ForceReset(DDL_APB_GRP1_PERIPH_UART0);
    DDL_APB_GRP1_ReleaseReset(DDL_APB_GRP1_PERIPH_UART0);
  }
  else if (USARTx == UART1)
  {
    DDL_APB_GRP1_ForceReset(DDL_APB_GRP1_PERIPH_UART1);
    DDL_APB_GRP1_ReleaseReset(DDL_APB_GRP1_PERIPH_UART1);
  }
  else
  {
    status = ERROR;
  }

  DDL_SCU_Lock();
  return (status);
}

/**
  * @brief  Initialize USART registers according to the specified
  *         parameters in USART_InitStruct.
  * @param  USARTx USART Instance
  * @param  USART_InitStruct pointer to a DDL_USART_InitTypeDef structure
  *         that contains the configuration information for the specified USART peripheral.
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS: USART registers are initialized according to USART_InitStruct content
  *          - ERROR: Problem occurred during USART Registers initialization
  */
ErrorStatus DDL_USART_Init(USART_TypeDef *USARTx, DDL_USART_InitTypeDef *USART_InitStruct)
{
  ErrorStatus status = ERROR;
  uint32_t periphclk = DDL_SCU_PERIPH_FREQUENCY_NO;
  DDL_SCU_ClocksTypeDef rcc_clocks;

  /* Check the parameters */
  ASSERT_PARAM(IS_UART_INSTANCE(USARTx));
  ASSERT_PARAM(IS_DDL_USART_BAUDRATE(USART_InitStruct->BaudRate));
  ASSERT_PARAM(IS_DDL_USART_DATAWIDTH(USART_InitStruct->DataWidth));
  ASSERT_PARAM(IS_DDL_USART_STOPBITS(USART_InitStruct->StopBits));
  ASSERT_PARAM(IS_DDL_USART_PARITY(USART_InitStruct->Parity));
  ASSERT_PARAM(IS_DDL_USART_DIRECTION(USART_InitStruct->TransferDirection));

  /* USART needs to be in disabled state, in order to be able to configure some bits in
     CTRLx registers */
  if (DDL_USART_IsEnabled(USARTx) == 0U)
  {
    /*---------------------------- USART CTRL1 Configuration -----------------------
     * Configure USARTx CTRL1 (USART Word Length, Parity, Mode bits) with parameters:
     * - DataWidth:          USART_CTRL1_DBLCFG bits according to USART_InitStruct->DataWidth value
     * - Parity:             USART_CTRL1_PCFG, USART_CTRL1_PCEN bits according to USART_InitStruct->Parity value
     * - TransferDirection:  USART_CTRL1_TXEN, USART_CTRL1_RXEN bits according to USART_InitStruct->TransferDirection value
     */
    MODIFY_REG(USARTx->CTRL1,
               (USART_CTRL1_DBLCFG | USART_CTRL1_PCFG | USART_CTRL1_PCEN |
                USART_CTRL1_TXEN | USART_CTRL1_RXEN),
               (USART_InitStruct->DataWidth | USART_InitStruct->Parity |
                USART_InitStruct->TransferDirection));

    /*---------------------------- USART CTRL2 Configuration -----------------------
     * Configure USARTx CTRL2 (Stop bits) with parameters:
     * - Stop Bits:          USART_CTRL2_STOPCFG bits according to USART_InitStruct->StopBits value.
     */
    DDL_USART_SetStopBitsLength(USARTx, USART_InitStruct->StopBits);

    /*---------------------------- USART BRR Configuration -----------------------
     * Retrieve Clock frequency used for USART Peripheral
     */
    DDL_SCU_GetSysctrlClocksFreq(&rcc_clocks);

    periphclk = rcc_clocks.PCLK_Frequency;

    /* Configure the USART Baud Rate :
       - valid baud rate value (different from 0) is required
       - Peripheral clock as returned by RCM service, should be valid (different from 0).
    */
    if ((periphclk != DDL_SCU_PERIPH_FREQUENCY_NO)
        && (USART_InitStruct->BaudRate != 0U))
    {
      status = SUCCESS;
      DDL_USART_SetBaudRate(USARTx,
                           periphclk,
                           USART_InitStruct->BaudRate);

      /* Check BR is greater than or equal to 16d */
      ASSERT_PARAM(IS_DDL_USART_BR_MIN(USARTx->BR));
    }
  }

  return (status);
}

/**
  * @brief Set each @ref DDL_USART_InitTypeDef field to default value.
  * @param USART_InitStruct Pointer to a @ref DDL_USART_InitTypeDef structure
  *                         whose fields will be set to default values.
  * @retval None
  */

void DDL_USART_StructInit(DDL_USART_InitTypeDef *USART_InitStruct)
{
  /* Set USART_InitStruct fields to default values */
  USART_InitStruct->BaudRate            = 9600U;
  USART_InitStruct->DataWidth           = DDL_USART_DATAWIDTH_8B;
  USART_InitStruct->StopBits            = DDL_USART_STOPBITS_1;
  USART_InitStruct->Parity              = DDL_USART_PARITY_NONE ;
  USART_InitStruct->TransferDirection   = DDL_USART_DIRECTION_TX_RX;
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

#endif /* UART0 || UART1 */

/**
  * @}
  */

#endif /* USE_FULL_DDL_DRIVER */
