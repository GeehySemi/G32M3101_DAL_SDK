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

/* Private includes *******************************************************/
#include "g32m3101_device_cfg.h"
#include "g32m3101_usart_cfg.h"

/* Private macro **********************************************************/

/* Private typedef ********************************************************/

/* Private variables ******************************************************/
__IO uint32_t wakeupFlag = 0;

/* Private function prototypes ********************************************/
static void PMU_SleepMode(void);

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

    /* Wait until USER button is pressed to enter the Low Power mode */
    while (BOARD_BUTTON_GetState(BUTTON_KEY1) == 0U)
    {
        BOARD_LED_Toggle(LED2);
        DDL_mDelay(100);
    }

    /* Loop while USER Button is maintained pressed */
    while (BOARD_BUTTON_GetState(BUTTON_KEY1) != 0U)
    {
    }

    PMU_SleepMode();

    /* Infinite loop */
    while (1)
    {
        BOARD_LED_Toggle(LED2);
        DDL_mDelay(500U);
    }
}

/* Private functions ******************************************************/

/**
 * @brief   PMU sleep mode
 *
 * @param   None
 *
 * @retval  None
 */
static void PMU_SleepMode(void)
{
    DDL_GPIO_InitTypeDef GPIO_InitStruct = {0};

    printf("Enter sleep mode\r\n");

    /* Unlock SCU register */
    DDL_SCU_Unlock();

    /* Configure all GPIO as analog to reduce current consumption */
    /* Enable GPIOs clock */
    DDL_SCU_EnableAHBPeripheralClock(DDL_SCU_AHB_PERIPHERAL_GPIOB);
    DDL_SCU_EnableAHBPeripheralClock(DDL_SCU_AHB_PERIPHERAL_GPIOA);

    GPIO_InitStruct.Pin = DDL_GPIO_PIN_ALL;
    GPIO_InitStruct.Mode = DDL_GPIO_MODE_ANALOG;
    GPIO_InitStruct.Drive = DDL_GPIO_DRIVE_LOW;
    GPIO_InitStruct.Pull = DDL_GPIO_PULL_NO;
    DDL_GPIO_LockKey(GPIOA, DDL_GPIO_LOCK_DISABLE);
    DDL_GPIO_Init(GPIOA, &GPIO_InitStruct);
    DDL_GPIO_LockKey(GPIOA, DDL_GPIO_LOCK_ENABLE);

    GPIO_InitStruct.Pin = (DDL_GPIO_PIN_ALL & (~DDL_GPIO_PIN_1 | DDL_GPIO_PIN_3 | DDL_GPIO_PIN_4));
    DDL_GPIO_LockKey(GPIOB, DDL_GPIO_LOCK_DISABLE);
    DDL_GPIO_Init(GPIOB, &GPIO_InitStruct);
    DDL_GPIO_LockKey(GPIOB, DDL_GPIO_LOCK_ENABLE);

    /* Disable GPIOs clock */
    DDL_SCU_DisableAHBPeripheralClock(DDL_SCU_AHB_PERIPHERAL_GPIOA);

    /* Lock SCU register */
    DDL_SCU_Lock();

    /* Reset UART state for configure again and deinit UART */
    DDL_USART_DeInit(UART0);

    /* Suspend system tick */
    SysTick->CTRL &= ~SysTick_CTRL_TICKINT_Msk;

    /* Wait for interrupt */
    /* Clear SLEEPDEEP bit of Cortex System Control Register */
    CLEAR_BIT(SCB->SCR, ((uint32_t)SCB_SCR_SLEEPDEEP_Msk));
    /* Wait for interrupt */
    __SEV();
    __WFE();
    __WFE();

    /* Resume system tick */
    SysTick->CTRL |= SysTick_CTRL_TICKINT_Msk;

    UART0_Config();
    BOARD_LED_Config(LED2);
    printf("Exit sleep mode\r\n");
}

/**
 * @brief  EINT line detection callbacks
 *
 * @param  GPIO_Pin Specifies the pins connected EINT line
 *
 * @retval None
 */
void EINT_0_1_Isr(uint16_t GPIO_Pin)
{
    /* EINT line interrupt detected */
    if ((EINT->IPEND & (GPIO_Pin)) != 0x00u)
    {
        /* Clears the EINT's line pending bits. */
        EINT->IPEND = (GPIO_Pin);
        if (GPIO_Pin == DDL_GPIO_PIN_1)
        {
            wakeupFlag = 1;
        }
    }
}

