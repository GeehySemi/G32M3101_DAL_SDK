/**
 * @file        g32m3101_uart_cfg.c
 *
 * @brief       This file provides configuration support for UART
 *
 * @version     V1.0.0
 *
 * @date        2025-06-01
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
#include "g32m3101_usart_cfg.h"

/* Private includes *******************************************************/
#include <stdio.h>

/* Private macro **********************************************************/

/* Private typedef ********************************************************/

/* Private variables ******************************************************/
DDL_USART_InitTypeDef UART0_InitStruct;

/* Private function prototypes ********************************************/

/* External variables *****************************************************/

/* External functions *****************************************************/

/**
 * @brief   UART0 configuration
 *
 * @param   None
 *
 * @retval  None
 */
void UART0_Config(void)
{
    DDL_GPIO_InitTypeDef GPIO_InitStruct = {0U};

    DDL_SCU_Unlock();
    DDL_SCU_EnableAHBPeripheralClock(DDL_SCU_AHB_PERIPHERAL_GPIOA);
    DDL_SCU_EnableAPBPeripheralClock(DDL_SCU_APB_PERIPHERAL_UART0);
    DDL_SCU_Lock();

    /* Configure the UART TX pin */
    GPIO_InitStruct.Pin = DDL_GPIO_PIN_7;
    GPIO_InitStruct.Mode = DDL_GPIO_MODE_ALTERNATE;
    GPIO_InitStruct.Drive = DDL_GPIO_DRIVE_LOW;
    GPIO_InitStruct.Pull = DDL_GPIO_PULL_NO;
    GPIO_InitStruct.Alternate = DDL_GPIO_AF_0;

    DDL_GPIO_LockKey(GPIOA, DDL_GPIO_LOCK_DISABLE);
    DDL_GPIO_Init(GPIOA, &GPIO_InitStruct);
    DDL_GPIO_LockKey(GPIOA, DDL_GPIO_LOCK_ENABLE);

    /* Configure the UART RX pin */
    GPIO_InitStruct.Pin = DDL_GPIO_PIN_8;
    GPIO_InitStruct.Mode = DDL_GPIO_MODE_ALTERNATE;
    GPIO_InitStruct.Drive = DDL_GPIO_DRIVE_LOW;
    GPIO_InitStruct.Pull = DDL_GPIO_PULL_NO;
    GPIO_InitStruct.InputEnable = DDL_GPIO_INPUT_ENABLE;
    GPIO_InitStruct.Alternate = DDL_GPIO_AF_0;

    DDL_GPIO_LockKey(GPIOA, DDL_GPIO_LOCK_DISABLE);
    DDL_GPIO_Init(GPIOA, &GPIO_InitStruct);
    DDL_GPIO_LockKey(GPIOA, DDL_GPIO_LOCK_ENABLE);

    UART0_InitStruct.BaudRate = 115200U;
    UART0_InitStruct.DataWidth = DDL_USART_DATAWIDTH_8B;
    UART0_InitStruct.StopBits = DDL_USART_STOPBITS_1;
    UART0_InitStruct.Parity = DDL_USART_PARITY_NONE;
    UART0_InitStruct.TransferDirection = DDL_USART_DIRECTION_TX_RX;
    DDL_USART_Init(UART0, &UART0_InitStruct);

    DDL_USART_Enable(UART0);
}

#if defined(__CC_ARM) || defined(__ICCARM__) ||                                                    \
    (defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050))

/*!
 * @brief       Redirect C Library function printf to serial port.
 *              After Redirection, you can use printf function.
 *
 * @param       ch:  The characters that need to be send.
 *
 * @param       *f:  pointer to a FILE that can recording all information
 *              needed to control a stream
 *
 * @retval      The characters that need to be send.
 *
 * @note
 */
int fputc(int ch, FILE *f)
{
    /* send a byte of data to the serial port */
    DDL_USART_TransmitData8(UART0, (uint8_t)ch);
    while (DDL_USART_IsActiveFlag_TXE(UART0) == RESET)
    {
    }

    return (ch);
}

#elif defined(__GNUC__)

/*!
 * @brief       Redirect C Library function printf to serial port.
 *              After Redirection, you can use printf function.
 *
 * @param       ch:  The characters that need to be send.
 *
 * @retval      The characters that need to be send.
 *
 * @note
 */
int __io_putchar(int ch)
{
    /* send a byte of data to the serial port */
    DDL_USART_TransmitData8(UART0, (uint8_t)ch);
    while (DDL_USART_IsActiveFlag_TXE(UART0) == RESET)
    {
    }

    return ch;
}

/*!
 * @brief       Redirect C Library function printf to serial port.
 *              After Redirection, you can use printf function.
 *
 * @param       file:  Meaningless in this function.
 *
 * @param       *ptr:  Buffer pointer for data to be sent.
 *
 * @param       len:  Length of data to be sent.
 *
 * @retval      The characters that need to be send.
 *
 * @note
 */
int _write(int file, char *ptr, int len)
{
    int i;
    for (i = 0; i < len; i++)
    {
        __io_putchar(*ptr++);
    }

    return len;
}

#else
#warning Not supported compiler type
#endif
