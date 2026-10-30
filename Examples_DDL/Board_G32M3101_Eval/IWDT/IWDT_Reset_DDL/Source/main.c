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

/* Private macro **********************************************************/

/* Private typedef ********************************************************/

/* Private variables ******************************************************/

/* Private function prototypes ********************************************/
void DDL_Init1usTick(uint32_t HCLKFrequency);
void DDL_uDelay(uint32_t Delay);
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
    DDL_Init1usTick(SystemCoreClock);

    if (DDL_SCU_IsActiveFlag_IWDTRST())
    {
        printf("IWDT System Reset\r\n");
        DDL_SCU_Unlock();
        DDL_SCU_ClearFlag_IWDTRST();
        DDL_SCU_Lock();
    }
    /* Infinite loop */
    while (1)
    {
        BOARD_LED_Toggle(LED2);

        /*
        Note:
        Each time the dog is fed, there must be at least a 160us delay.
        */
        DDL_uDelay(160U);
        DDL_IWDT_ReloadCounter(IWDT);
    }
}

/**
 * @brief  This function configures the Cortex-M SysTick source to have 1ms time base.
 * @note   When a RTOS is used, it is recommended to avoid changing the Systick
 *         configuration by calling this function, for a delay use rather osDelay RTOS service.
 * @param  HCLKFrequency HCLK frequency in Hz
 * @note   HCLK frequency can be calculated thanks to function @ref DDL_SCU_GetSysctrlClocksFreq
 * @retval None
 */
void DDL_Init1usTick(uint32_t HCLKFrequency)
{
    /* Use frequency provided in argument */
    DDL_InitTick(HCLKFrequency, 1000000U);
}

/**
 * @brief  This function provides accurate delay (in milliseconds) based
 *         on SysTick counter flag
 * @note   When a RTOS is used, it is recommended to avoid using blocking delay
 *         and use rather osDelay service.
 * @note   To respect 1ms timebase, user should call @ref DDL_Init1msTick function which
 *         will configure Systick to 1ms
 * @param  Delay specifies the delay time length, in milliseconds.
 * @retval None
 */
void DDL_uDelay(uint32_t Delay)
{
    __IO uint32_t tmp = SysTick->CTRL; /* Clear the COUNTFLAG first */
    /* Add this code to indicate that local variable is not used */
    ((void)tmp);

    /* Add a period to guaranty minimum wait */
    if (Delay < DDL_MAX_DELAY)
    {
        Delay++;
    }

    while (Delay)
    {
        if ((SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk) != 0U)
        {
            Delay--;
        }
    }
}
