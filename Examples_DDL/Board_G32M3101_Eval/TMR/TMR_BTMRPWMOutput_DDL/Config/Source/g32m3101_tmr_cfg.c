/**
 * @file        g32m3101_tmr_cfg.c
 *
 * @brief       This file provides configuration support for TMR
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
#include "g32m3101_tmr_cfg.h"

/* Private includes *******************************************************/

/* Private macro **********************************************************/

/* Private typedef ********************************************************/

/* Private variables ******************************************************/
DDL_BTMR_InitTypeDef BTMR_InitStruct;
DDL_BTMR_OC_InitTypeDef BTMR_OC_InitStruct;

/* Private function prototypes ********************************************/

/* External variables *****************************************************/

/* External functions *****************************************************/

/**
 * @brief   BTMR configuration
 *
 * @param   None
 *
 * @retval  None
 */
void BTMR_Config(void)
{
    DDL_GPIO_InitTypeDef GPIO_InitStruct = {0U};

    DDL_SCU_Unlock();
    DDL_SCU_EnableAHBPeripheralClock(DDL_SCU_AHB_PERIPHERAL_GPIOB);
    DDL_SCU_EnableAPBPeripheralClock(DDL_SCU_APB_PERIPHERAL_BTMR);
    DDL_SCU_Lock();

    /* TMR channel pin configuration */
    GPIO_InitStruct.Mode = DDL_GPIO_MODE_ALTERNATE;
    GPIO_InitStruct.Drive = DDL_GPIO_DRIVE_HIGH;
    GPIO_InitStruct.Pull = DDL_GPIO_PULL_UP;
    GPIO_InitStruct.Alternate = DDL_GPIO_AF_5;

    /* TMR channel 0 */
    GPIO_InitStruct.Pin = DDL_GPIO_PIN_5;
    DDL_GPIO_LockKey(GPIOB, DDL_GPIO_LOCK_DISABLE);
    DDL_GPIO_Init(GPIOB, &GPIO_InitStruct);
    DDL_GPIO_LockKey(GPIOB, DDL_GPIO_LOCK_ENABLE);

    BTMR_InitStruct.Prescaler = 63U;
    BTMR_InitStruct.CounterMode = DDL_BTMR_COUNTERMODE_UP;
    BTMR_InitStruct.Autoreload = 999U;

    DDL_BTMR_DisableARRPreload(BTMR);
    DDL_BTMR_Init(BTMR, &BTMR_InitStruct);
    BTMR->CEG = BTMR_CEG_UEG;
    if (DDL_BTMR_IsActiveFlag_UPDATE(BTMR))
    {
        DDL_BTMR_ClearFlag_UPDATE(BTMR);
    }

    /* Configure output channel 1 */
    BTMR_OC_InitStruct.OCMode = DDL_BTMR_OCMODE_PWM1;
    BTMR_OC_InitStruct.OCState = DDL_BTMR_OCSTATE_ENABLE;
    BTMR_OC_InitStruct.OCPolarity = DDL_BTMR_POLARITY_HIGH;
    BTMR_OC_InitStruct.CompareValue = 500U;
    DDL_BTMR_OC_Init(BTMR, DDL_BTMR_CHANNEL_CH0, &BTMR_OC_InitStruct);
}
