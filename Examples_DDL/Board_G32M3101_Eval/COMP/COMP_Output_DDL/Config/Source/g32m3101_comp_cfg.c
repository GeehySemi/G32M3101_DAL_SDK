/**
 * @file        g32m3101_comp_cfg.c
 *
 * @brief       This file provides configuration support for GPIO
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
#include "g32m3101_comp_cfg.h"

/* Private includes *******************************************************/

/* Private macro **********************************************************/

/* Private typedef ********************************************************/

/* Private variables ******************************************************/

/* Private function prototypes ********************************************/

/* External variables *****************************************************/

/* External functions *****************************************************/

/**
 * @brief   COMP configuration
 *
 * @param   None
 *
 * @retval  None
 */
void COMP0_Config(void)
{
    DDL_GPIO_InitTypeDef GPIO_InitStruct = {0};
    DDL_COMP_InitTypeDef COMP_InitStruct = {0};

    DDL_SCU_Unlock();
    DDL_SCU_EnableAPBPeripheralClock(DDL_SCU_APB_PERIPHERAL_COMP);
    DDL_SCU_EnableAHBPeripheralClock(DDL_SCU_AHB_PERIPHERAL_GPIOA);
    DDL_SCU_Lock();

    GPIO_InitStruct.Pin = DDL_GPIO_PIN_7 | DDL_GPIO_PIN_8;
    GPIO_InitStruct.Mode = DDL_GPIO_MODE_ANALOG;
    GPIO_InitStruct.Pull = DDL_GPIO_PULL_NO;
    GPIO_InitStruct.Drive = DDL_GPIO_DRIVE_LOW;

    DDL_GPIO_LockKey(GPIOA, DDL_GPIO_LOCK_DISABLE);
    DDL_GPIO_Init(GPIOA, &GPIO_InitStruct);
    DDL_GPIO_LockKey(GPIOA, DDL_GPIO_LOCK_ENABLE);

    GPIO_InitStruct.Pin = DDL_GPIO_PIN_9;
    GPIO_InitStruct.Mode = DDL_GPIO_MODE_ALTERNATE;
    GPIO_InitStruct.Pull = DDL_GPIO_PULL_NO;
    GPIO_InitStruct.Drive = DDL_GPIO_DRIVE_HIGH;
    GPIO_InitStruct.Alternate = DDL_GPIO_AF_7;

    DDL_GPIO_LockKey(GPIOA, DDL_GPIO_LOCK_DISABLE);
    DDL_GPIO_Init(GPIOA, &GPIO_InitStruct);
    DDL_GPIO_LockKey(GPIOA, DDL_GPIO_LOCK_ENABLE);

    COMP_InitStruct.InputPlus = DDL_COMP_INPUT_PLUS_PA7_COMP0;
    COMP_InitStruct.InputMinus = DDL_COMP_INPUT_MINUS_PA8_COMP0;
    COMP_InitStruct.OutputPol = DDL_COMP_OUTPUTPOL_NONINVERTED;
    COMP_InitStruct.TmrSel = DDL_COMP_TMR_SEL_NONE;
    COMP_InitStruct.PositiveHsy = DDL_COMP_HYS_DISABLE;
    COMP_InitStruct.FilterPsc = DDL_COMP_FILTER_CLOCK_DIV_0;
    COMP_InitStruct.FilterCnt = DDL_COMP_FILTER_CLOCK_COUNT_0;

    DDL_COMP_Init(COMP0, &COMP_InitStruct);
}
