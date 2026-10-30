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
uint8_t lptmrITFlg = 0;
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

    BOARD_LED_Off(LED2);

    /* Infinite loop */
    while (1)
    {
        if (BOARD_BUTTON_GetState(BUTTON_KEY1) == 0U)
        {
            DDL_LPTMR_Enable(LPTMR);
            printf("Enter low power mode\r\n");
            /* Disable SysTick Interrupt */
            SysTick->CTRL &= ~SysTick_CTRL_TICKINT_Msk;

            /* Enter stop */
            /* Set SLEEPDEEP bit of Cortex System Control Register */
            SET_BIT(SCB->SCR, ((uint32_t)SCB_SCR_SLEEPDEEP_Msk));
            __SEV();
            __WFI();

            /* Reset SLEEPDEEP bit of Cortex System Control Register */
            CLEAR_BIT(SCB->SCR, ((uint32_t)SCB_SCR_SLEEPDEEP_Msk));

            /* Enable SysTick Interrupt */
            SysTick->CTRL |= SysTick_CTRL_TICKINT_Msk;

            DDL_LPTMR_Disable(LPTMR);

            printf("WakeUp from low power mode\r\n");

            BOARD_LED_On(LED2);
        }

        if (lptmrITFlg)
        {
            BOARD_LED_Toggle(LED2);
            DDL_mDelay(500);
        }
    }
}

/**
 * @brief     This function handles LPTMR request
 *
 * @param     None
 *
 * @retval    None
 *
 */
void LPTMR_IRQHandler(void)
{
    if (DDL_LPTMR_IsActiveFlag_WakeUp(LPTMR))
    {
        DDL_EINT_ClearFlag_0_31(DDL_EINT_LINE_17); // Clear pending bit
        CLEAR_BIT(LPTMR->STS, DDL_LPTMR_STS_WKF);
        lptmrITFlg = 1;
    }
}
