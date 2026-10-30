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

/* Private includes *******************************************************/
#include "g32m3101_device_cfg.h"
#include <string.h>
#include <stdbool.h>

/* Private macro **********************************************************/

/* Define firmware to switch between 1st board or 2nd board */
#define IS_FIRST_BOARD

/* Private typedef ********************************************************/

/* Private variables ******************************************************/
static char txBuffer[] = "UART_TwoBoardsPolling\r\n";
static char rxBuffer[50U];
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
    while (uartTxConut)
    {
        while (DDL_USART_IsActiveFlag_TXE(UART0) == 0)
        {
        }
        UART0->DATA = *pTxData;
        pTxData++;
        uartTxConut--;
    }

    pRxData = rxBuffer;
    uartRxConut = strlen(txBuffer);
    while (uartRxConut)
    {
        while (DDL_USART_IsActiveFlag_RXNE(UART0) == 0)
        {
        }
        *pRxData = UART0->DATA;
        pRxData++;
        uartRxConut--;
    }

#else
    pRxData = rxBuffer;
    uartRxConut = strlen(txBuffer);
    while (uartRxConut)
    {
        while (DDL_USART_IsActiveFlag_RXNE(UART0) == 0)
        {
        }
        *pRxData = UART0->DATA;
        pRxData++;
        uartRxConut--;
    }

    pTxData = txBuffer;
    uartTxConut = strlen(txBuffer);
    while (uartTxConut)
    {
        while (DDL_USART_IsActiveFlag_TXE(UART0) == 0)
        {
        }
        UART0->DATA = *pTxData;
        pTxData++;
        uartTxConut--;
    }
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
