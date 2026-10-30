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

    /* Configure board peripherals */
    BOARD_LED_Config(LED2);
    BOARD_BUTTON_Config(BUTTON_KEY1, BUTTON_MODE_GPIO);
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
    DDL_SCU_SetAHBPrescaler(DDL_SCU_AHB_DIV_2);

    /* Configure APB prescaler, APB_CLK = AHB_CLK/1 */
    DDL_SCU_SetAPBPrescaler(DDL_SCU_APB_DIV_2);

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
