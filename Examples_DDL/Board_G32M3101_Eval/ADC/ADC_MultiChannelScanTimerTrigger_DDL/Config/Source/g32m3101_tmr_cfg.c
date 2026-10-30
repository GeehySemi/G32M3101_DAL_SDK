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

/* Private function prototypes ********************************************/

/* External variables *****************************************************/

/* External functions *****************************************************/

/**
 * @brief   TMR configuration
 *
 * @param   None
 *
 * @retval  None
 */
void ATMR_Config(void)
{
    DDL_ATMR_InitTypeDef ATMR_InitStruct;
    DDL_ATMR_OC_InitTypeDef ATMR_OC_InitStruct;

    DDL_SCU_Unlock();
    DDL_SCU_EnableAPBPeripheralClock(DDL_SCU_APB_PERIPHERAL_ATMR);
    DDL_SCU_Lock();

    ATMR_InitStruct.Prescaler = 63U;
    ATMR_InitStruct.CounterMode = DDL_ATMR_COUNTERMODE_UP;
    ATMR_InitStruct.Autoreload = 999U;
    ATMR_InitStruct.ClockDivision = DDL_ATMR_CLOCKDIVISION_DIV1;
    ATMR_InitStruct.RepetitionCounter = 0U;

    DDL_ATMR_DisableARRPreload(ATMR);
    DDL_ATMR_Init(ATMR, &ATMR_InitStruct);
    if (DDL_ATMR_IsActiveFlag_UPDATE(ATMR))
    {
        DDL_ATMR_ClearFlag_UPDATE(ATMR);
    }

    /* Configure output channel 1 (needed for TRGO = CCIF_EVENT) */
    ATMR_OC_InitStruct.OCMode = DDL_ATMR_OCMODE_PWM1;
    ATMR_OC_InitStruct.OCState = DDL_ATMR_OCSTATE_ENABLE;
    ATMR_OC_InitStruct.OCNState = DDL_ATMR_OCSTATE_DISABLE;
    ATMR_OC_InitStruct.OCPolarity = DDL_ATMR_OCPOLARITY_HIGH;
    ATMR_OC_InitStruct.OCNPolarity = DDL_ATMR_OCPOLARITY_HIGH;
    ATMR_OC_InitStruct.OCIdleState = DDL_ATMR_OCIDLESTATE_HIGH;
    ATMR_OC_InitStruct.OCNIdleState = DDL_ATMR_OCIDLESTATE_HIGH;
    ATMR_OC_InitStruct.CompareValue = 499U;
    DDL_ATMR_OC_Init(ATMR, DDL_ATMR_CHANNEL_CH1, &ATMR_OC_InitStruct);

    DDL_ATMR_SetTriggerOutputMode0(ATMR, DDL_ATMR_TRGO_CCIF_EVENT);
    DDL_ATMR_DisableMasterSlaveMode(ATMR);
}
