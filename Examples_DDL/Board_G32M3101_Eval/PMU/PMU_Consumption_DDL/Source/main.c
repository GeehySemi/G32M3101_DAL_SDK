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

/* Sets the macro of following low power mode to 1 to turn on
   the testing of the corresponding mode. Only one mode can set as 1
   at the same time.
*/
#define SYS_SLEEP_MODE 0U
#define SYS_STOP_MODE  1U

/* Private typedef ********************************************************/

/* Private variables ******************************************************/

/* Private function prototypes ********************************************/
#if (SYS_STOP_MODE)
static void PMU_Consumption_StopMode(void);
#elif (SYS_SLEEP_MODE)
static void PMU_Consumption_SleepMode(void);
#else
#endif

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

#if (SYS_STOP_MODE)
    PMU_Consumption_StopMode();
#elif (SYS_SLEEP_MODE)
    PMU_Consumption_SleepMode();
#else
    printf("Running normal mode\r\n");
#endif /* SYS_STANDBY_MODE | SYS_STOP_MODE | SYS_SLEEP_MODE */

    /* Infinite loop */
    while (1)
    {
        BOARD_LED_Toggle(LED2);
        DDL_mDelay(500U);
    }
}

#if (SYS_SLEEP_MODE)

/* Private functions ******************************************************/

/**
 * @brief   PMU sleep mode
 *
 * @param   None
 *
 * @retval  None
 */
static void PMU_Consumption_SleepMode(void)
{
    DDL_GPIO_InitTypeDef GPIO_InitStruct = {0};

    printf("Enter sleep mode\r\n");

    /* Unlock SCU register */
    DDL_SCU_Unlock();

    /* Configure all GPIO as analog to reduce current consumption */
    /* Enable GPIOs clock */
    DDL_SCU_EnableAHBPeripheralClock(DDL_SCU_AHB_PERIPHERAL_GPIOB);
    DDL_SCU_EnableAHBPeripheralClock(DDL_SCU_AHB_PERIPHERAL_GPIOA);

    GPIO_InitStruct.Pin = (DDL_GPIO_PIN_ALL & ~(DDL_GPIO_PIN_6));
    GPIO_InitStruct.Mode = DDL_GPIO_MODE_ANALOG;
    GPIO_InitStruct.Drive = DDL_GPIO_DRIVE_LOW;
    GPIO_InitStruct.Pull = DDL_GPIO_PULL_NO;
    DDL_GPIO_LockKey(GPIOA, DDL_GPIO_LOCK_DISABLE);
    DDL_GPIO_Init(GPIOA, &GPIO_InitStruct);
    DDL_GPIO_LockKey(GPIOA, DDL_GPIO_LOCK_ENABLE);

    GPIO_InitStruct.Pin =
        (DDL_GPIO_PIN_ALL & (~(DDL_GPIO_PIN_1 | DDL_GPIO_PIN_3 | DDL_GPIO_PIN_4)));
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

#endif /* SYS_SLEEP_MODE */

#if (SYS_STOP_MODE)

/**
 * @brief   Consumption measure in stop mode
 *
 * @param   None
 *
 * @retval  None
 */
static void PMU_Consumption_StopMode(void)
{
    DDL_GPIO_InitTypeDef GPIO_InitStruct = {0U};
    DDL_EINT_InitTypeDef EINT_InitStruct = {0U};

    printf("Enter stop mode\r\n");

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
    DDL_GPIO_Init(GPIOB, &GPIO_InitStruct);
    DDL_GPIO_LockKey(GPIOA, DDL_GPIO_LOCK_ENABLE);

    GPIO_InitStruct.Pin = DDL_GPIO_PIN_1;
    GPIO_InitStruct.Mode = DDL_GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = DDL_GPIO_PULL_UP;
    DDL_GPIO_LockKey(GPIOB, DDL_GPIO_LOCK_DISABLE);
    DDL_GPIO_Init(GPIOB, &GPIO_InitStruct);
    DDL_GPIO_LockKey(GPIOB, DDL_GPIO_LOCK_ENABLE);

    /* Configuration EINT */
    /* Configure the PB1 pin */
    GPIO_InitStruct.Pin = DDL_GPIO_PIN_1;
    GPIO_InitStruct.Mode = DDL_GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = DDL_GPIO_PULL_UP;
    DDL_GPIO_LockKey(GPIOB, DDL_GPIO_LOCK_DISABLE);
    DDL_GPIO_Init(GPIOB, &GPIO_InitStruct);
    DDL_GPIO_LockKey(GPIOB, DDL_GPIO_LOCK_ENABLE);

    /* Configuration EINT Mode */
    EINT_InitStruct.Line_0_31 = DDL_EINT_LINE_1;
    EINT_InitStruct.LineCommand = ENABLE;
    EINT_InitStruct.Mode = DDL_EINT_MODE_IT;
    EINT_InitStruct.Trigger = DDL_EINT_TRIGGER_FALLING;
    DDL_EINT_SetEINTSource(DDL_EINT_SOURCE_PORTB, DDL_EINT_LINE_1);
    DDL_EINT_Init(&EINT_InitStruct);

    NVIC_SetPriority(EINT0_1_IRQn, 0u);
    NVIC_EnableIRQ(EINT0_1_IRQn);

    /* Disable GPIOs clock */
    DDL_SCU_DisableAHBPeripheralClock(DDL_SCU_AHB_PERIPHERAL_GPIOB);

    /* Lock SCU register */
    DDL_SCU_Lock();

    /* Reset UART state for configure again and deinit UART */
    DDL_USART_DeInit(UART0);

    /* Enter stop */
    /* Set SLEEPDEEP bit of Cortex System Control Register */
    SET_BIT(SCB->SCR, ((uint32_t)SCB_SCR_SLEEPDEEP_Msk));
    __WFI();

    /* Reset SLEEPDEEP bit of Cortex System Control Register */
    CLEAR_BIT(SCB->SCR, ((uint32_t)SCB_SCR_SLEEPDEEP_Msk));

    UART0_Config();
    BOARD_LED_Config(LED2);
    printf("Exit stop mode\r\n");
}

#endif /* SYS_STOP_MODE */

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
    }
}

