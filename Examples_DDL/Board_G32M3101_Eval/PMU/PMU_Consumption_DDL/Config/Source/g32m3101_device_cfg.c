/**
 * @file        g32m3101_device_cfg.c
 *
 * @brief       This file provides all configuration support for device
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
#include "g32m3101_device_cfg.h"

/* Private includes *******************************************************/

/* Private macro **********************************************************/

/* Private typedef ********************************************************/

/* Private variables ******************************************************/

/* Private function prototypes ********************************************/
static void NVIC_Config(void);
static void RCC_PeripheralClkConfig(void);
static void GPIO_Config(void);

/* External variables *****************************************************/

/* External functions *****************************************************/

/**
 * @brief   Device configuration
 *
 * @param   None
 *
 * @retval  None
 */
void Device_Config(void)
{
    /* Configure system clock */
    SysClk_Config();

    /* Configure NVIC */
    NVIC_Config();

    /* Configure RCC */
    RCC_PeripheralClkConfig();

    /* Configure GPIO */
    GPIO_Config();

    /* Configure board peripherals */
    BOARD_LED_Config(LED2);
    BOARD_BUTTON_Config(BUTTON_KEY1, BUTTON_MODE_GPIO);

    /* Configure peripheral */
    UART0_Config();
}

/**
 * @brief   System clock configuration
 *
 * @param   None
 *
 * @retval  None
 */
void SysClk_Config(void)
{
    DDL_SCU_Unlock();
    /* Set HSIEN */
    DDL_SCU_HSI_Enable();
    /* Wait for HSI READY */
    while (DDL_SCU_HSI_IsReady() != 1U)
    {
    }

    /* Configure FLASH latency */
    DDL_FLASH_SetLatency(DDL_FLASH_LATENCY3);

    /* Set HSI clock as system source clock, SYS_CLK = 64MHz */
    DDL_SCU_SetSysClkSource(DDL_SCU_SYSCLK_SOURCE_HSI);
    while (DDL_SCU_GetSysClkSource() != DDL_SCU_SYSCLK_SOURCE_HSI)
    {
    }

    /* Configure AHB Prescaler, AHB_CLK = SYS_CLK/1 */
    DDL_SCU_SetAHBPrescaler(DDL_SCU_AHB_DIV_1);

    /* Configure APB prescaler, APB_CLK = AHB_CLK/1 */
    DDL_SCU_SetAPBPrescaler(DDL_SCU_APB_DIV_1);

    /* Update SystemCoreClock variable */
    SystemCoreClockUpdate();

    /* Set Systick to 1ms in using frequency set to SystemCoreClock */
    DDL_Init1msTick(SystemCoreClock);
    DDL_SCU_Lock();
}

/**
 * @brief   NVIC configuration
 *
 * @param   None
 *
 * @retval  None
 */
static void NVIC_Config(void)
{
    /* Set interrupt group priority */
    NVIC_SetPriorityGrouping(0x00000003U);

    /* Enable and set Button EINT Interrupt priority */
    NVIC_SetPriority((IRQn_Type)(EINT0_1_IRQn),
                     NVIC_EncodePriority(NVIC_GetPriorityGrouping(), 0U, 0U));
    NVIC_EnableIRQ((IRQn_Type)(EINT0_1_IRQn));
}

/**
 * @brief   Peripheral Clock configuration
 *
 * @param   None
 *
 * @retval  None
 */
static void RCC_PeripheralClkConfig(void)
{
    DDL_SCU_Unlock();
    DDL_SCU_EnableAHBPeripheralClock(DDL_SCU_AHB_PERIPHERAL_GPIOB);
    DDL_SCU_EnableAPBPeripheralClock(DDL_SCU_APB_PERIPHERAL_EINT);
    DDL_SCU_Lock();
}

/**
 * @brief   GPIO configuration
 *
 * @param   None
 *
 * @retval  None
 */
static void GPIO_Config(void)
{
    DDL_GPIO_InitTypeDef GPIO_InitStruct = {0U};
    DDL_EINT_InitTypeDef EINT_InitStruct = {0U};

    /* Configure the EINT1 pin */
    GPIO_InitStruct.Pin = DDL_GPIO_PIN_1;
    GPIO_InitStruct.Mode = DDL_GPIO_MODE_INPUT;
    GPIO_InitStruct.InputEnable = DDL_GPIO_INPUT_ENABLE;
    GPIO_InitStruct.Pull = DDL_GPIO_PULL_UP;
    DDL_GPIO_LockKey(GPIOB, DDL_GPIO_LOCK_DISABLE);
    DDL_GPIO_Init(GPIOB, &GPIO_InitStruct);
    DDL_GPIO_LockKey(GPIOB, DDL_GPIO_LOCK_ENABLE);

    /*--------------------- EINT Mode Configuration ------------------------*/
    EINT_InitStruct.Line_0_31 = DDL_EINT_LINE_1;
    EINT_InitStruct.LineCommand = ENABLE;
    EINT_InitStruct.Mode = DDL_EINT_MODE_IT;
    EINT_InitStruct.Trigger = DDL_EINT_TRIGGER_FALLING;
    DDL_EINT_SetEINTSource(DDL_EINT_SOURCE_PORTB, DDL_EINT_LINE_1);
    DDL_EINT_Init(&EINT_InitStruct);
}

#if defined(USE_FULL_ASSERT)
/**
 * @brief   Assert failed handler
 *
 * @param   file :Pointer to the source file name
 *
 * @param   line :Error line source number
 *
 * @retval  None
 */
void AssertFailedHandler(uint8_t *file, uint32_t line)
{
    /* When the function is needed, this function
       could be implemented in the user file
    */
    (void)(file);
    (void)(line);
    while (1)
    {
    }
}
#endif /* USE_FULL_ASSERT */
