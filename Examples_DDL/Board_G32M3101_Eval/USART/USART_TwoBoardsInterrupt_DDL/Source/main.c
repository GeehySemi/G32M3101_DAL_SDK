/**
 * @file        main.c
 *
 * @brief       Main program body
 *
 * @version     V1.0.0
 *
 * @date        2025-01-01
 *
 * @attention
 *
 *  Copyright (C) 2025 Geehy Semiconductor
 *
 *  You may not use this file except in compliance with the
 *  GEEHY COPYRIGHT NOTICE (GEEHY SOFTWARE PACKAGE LICENSE).
 *
 *  The program is only for reference, which is distributed in the hope
 *  that it will be useful and instructional for customers to develop
 *  their software. Unless required by applicable law or agreed to in
 *  writing, the program is distributed on an "AS IS" BASIS, WITHOUT
 *  ANY WARRANTY OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the GEEHY SOFTWARE PACKAGE LICENSE for the governing permissions
 *  and limitations under the License.
 */

/* Includes ***************************************************************/
#include "main.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/* Private includes *******************************************************/
#include "g32m3101_device_cfg.h"

/* Private macro **********************************************************/

/* Define firmware to switch between 1st board or 2nd board */
#define IS_FIRST_BOARD

/* Private typedef ********************************************************/

/* Private variables ******************************************************/
static char txBuffer[] = "UART_TwoBoardsInterrupt\r\n";
static char rxBuffer[50U];
static volatile uint32_t uartTxEventFlag = 0U;
static volatile uint32_t uartRxEventFlag = 0U;
static volatile uint32_t uartTxConut = 0U;
static char *pTxData;
static volatile uint32_t uartRxConut = 0U;
static char *pRxData;

/* Private function prototypes ********************************************/
static bool BufferCmp(uint8_t *buf1, uint8_t *buf2, uint32_t size);
static void Error_Handler(void);

/* External variables *****************************************************/

/* External functions *****************************************************/

/**
 * @brief   Main program
 *
 * @param   None
 *
 * @retval  None
 */
int main(void)
{
    /* Device configuration */
    Device_Config();

#if defined(IS_FIRST_BOARD)
    pTxData = txBuffer;
    uartTxConut = strlen(txBuffer);
    DDL_USART_EnableIT_TC(UART0);

    while (uartTxConut)
    {
        while (DDL_USART_IsActiveFlag_TXE(UART0) == 0)
        {
        }
        UART0->DATA = *pTxData;
        pTxData++;
        uartTxConut--;
    }

    /* Wait for the end of UART send */
    while (uartTxEventFlag != 1U)
    {
    }

    DDL_USART_DisableIT_TC(UART0);

    pRxData = rxBuffer;
    uartRxConut = strlen(txBuffer);
    /* Enable the UART DATA Register Not Empty Interrupt */
    DDL_USART_EnableIT_RXNE(UART0);

    /* Wait for the end of UART send */
    while (uartRxEventFlag != 1U)
    {
    }

    DDL_USART_DisableIT_RXNE(UART0);
#else

    pRxData = rxBuffer;
    uartRxConut = strlen(txBuffer);
    /* Enable the UART DATA Register Not Empty Interrupt */
    DDL_USART_EnableIT_RXNE(UART0);

    /* Wait for the end of UART send */
    while (uartRxEventFlag != 1U)
    {
    }

    DDL_USART_DisableIT_RXNE(UART0);

    pTxData = txBuffer;
    uartTxConut = strlen(txBuffer);
    DDL_USART_EnableIT_TC(UART0);
    while (uartTxConut)
    {
        UART0->DATA = *pTxData;
        pTxData++;
        uartTxConut--;
    }

    /* Wait for the end of UART send */
    while (uartTxEventFlag != 1U)
    {
    }

    DDL_USART_DisableIT_TC(UART0);

#endif

    if (BufferCmp((uint8_t *)txBuffer, (uint8_t *)rxBuffer, strlen(txBuffer)) != true)
    {
        BOARD_LED_On(LED2);
        Error_Handler();
    }

    /* Infinite loop */
    while (1)
    {
        BOARD_LED_Toggle(LED2);
        DDL_mDelay(500U);
    }
}

/*!
 * @brief       UART0 interrupt callback
 *
 * @param       None
 *
 * @retval      None.
 *
 */
void UART0_Isr(void)
{
    if (DDL_USART_IsActiveFlag_RXNE(UART0))
    {
        DDL_USART_ClearFlag_RXNE(UART0);

        if (uartRxConut)
        {
            *pRxData = UART0->DATA;
            pRxData++;
            uartRxConut--;
        }

        if (uartRxConut == 0)
        {
            uartRxEventFlag = 1U;
        }
    }

    if (DDL_USART_IsActiveFlag_TC(UART0))
    {
        DDL_USART_ClearFlag_TC(UART0);
        uartTxEventFlag = 1U;
    }
}

/* Private functions ******************************************************/

/**
 * @brief   Buffer compare
 *
 * @param   buf1: First buffer to be compared
 *
 * @param   buf2: Second buffer to be compared
 *
 * @param   size: Buffer size
 *
 * @retval  Comparison result(ture or false)
 */
static bool BufferCmp(uint8_t *buf1, uint8_t *buf2, uint32_t size)
{
    uint32_t i;

    bool status = true;

    for (i = 0U; i < size; i++)
    {
        if (buf1[i] != buf2[i])
        {
            status = false;
            break;
        }
    }

    return status;
}

/**
 * @brief     Error handler
 *
 * @param     None
 *
 * @retval    None
 */
static void Error_Handler(void)
{
    /* When the function is needed, this function
       could be implemented in the user file
    */
    __disable_irq();
    while (1)
    {
    }
}
