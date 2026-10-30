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

/* Private macro **********************************************************/
/* Private typedef ********************************************************/
/* Private variables ******************************************************/
static volatile uint32_t uartRxData = 0U;

/* Private function prototypes ********************************************/

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

    /* Infinite loop */
    while (1)
    {
    }
}

/**
 * @brief   UART0 Rx interrupt callback
 *
 * @param   None
 *
 * @retval  None
 */
void UART0_RX_Isr(void)
{
    if (DDL_USART_IsActiveFlag_RXNE(UART0))
    {
        uartRxData = DDL_USART_ReceiveData8(UART0);
        if (DDL_USART_IsActiveFlag_TXE(UART0) != 0)
        {
            DDL_USART_TransmitData8(UART0, uartRxData);
            while (DDL_USART_IsActiveFlag_TXE(UART0) == 0)
            {
            }
        }
    }
}
