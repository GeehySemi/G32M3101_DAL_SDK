/**
 * @file        g32m3101_eint_cfg.c
 *
 * @brief       This file provides configuration support for EINT
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
#include "g32m3101_eint_cfg.h"

/* Private includes *******************************************************/

/* Private macro **********************************************************/

/* Private typedef ********************************************************/

/* Private variables ******************************************************/

/* Private function prototypes ********************************************/

/* External variables *****************************************************/

/* External functions *****************************************************/

/**
 * @brief   GPIO configuration
 *
 * @param   None
 *
 * @retval  None
 */
void EINT_Config(void)
{
    DDL_GPIO_InitTypeDef GPIO_InitStruct = {0};
    DDL_EINT_InitTypeDef EINT_InitStruct = {0};

    DDL_SCU_Unlock();
    DDL_SCU_EnableAPBPeripheralClock(DDL_SCU_APB_PERIPHERAL_EINT);
    DDL_SCU_EnableAHBPeripheralClock(DDL_SCU_AHB_PERIPHERAL_GPIOB);
    DDL_SCU_Lock();

    /* Configure the EINT 10 pin */
    GPIO_InitStruct.Pin = DDL_GPIO_PIN_10;
    GPIO_InitStruct.Mode = DDL_GPIO_MODE_INPUT;
    GPIO_InitStruct.InputEnable = DDL_GPIO_INPUT_ENABLE;
    GPIO_InitStruct.InputType = DDL_GPIO_INPUT_TYPE_SCHMITT;
    GPIO_InitStruct.Pull = DDL_GPIO_PULL_UP;
    DDL_GPIO_LockKey(GPIOB, DDL_GPIO_LOCK_DISABLE);
    DDL_GPIO_Init(GPIOB, &GPIO_InitStruct);
    DDL_GPIO_LockKey(GPIOB, DDL_GPIO_LOCK_ENABLE);

    EINT_InitStruct.Line_0_31 = DDL_EINT_LINE_10;
    EINT_InitStruct.LineCommand = ENABLE;
    EINT_InitStruct.Mode = DDL_EINT_MODE_IT;
    EINT_InitStruct.Trigger = DDL_EINT_TRIGGER_FALLING;
    DDL_EINT_SetEINTSource(DDL_EINT_SOURCE_PORTB, DDL_EINT_LINE_10);
    DDL_EINT_Init(&EINT_InitStruct);

    NVIC_SetPriority(EINT4_13_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(), 3U, 0U));
    NVIC_EnableIRQ(EINT4_13_IRQn);
}
