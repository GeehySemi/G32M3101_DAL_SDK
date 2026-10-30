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
DDL_ATMR_InitTypeDef ATMR_InitStruct;

/* Private function prototypes ********************************************/

/* External variables *****************************************************/

/* External functions *****************************************************/

/**
 * @brief   ATMR configuration
 *
 * @param   None
 *
 * @retval  None
 */
void ATMR_Config(void)
{
    DDL_SCU_Unlock();
    DDL_SCU_EnableAPBPeripheralClock(DDL_SCU_APB_PERIPHERAL_ATMR);
    DDL_SCU_Lock();

    ATMR_InitStruct.Prescaler = 6399U;
    ATMR_InitStruct.CounterMode = DDL_ATMR_COUNTERMODE_UP;
    ATMR_InitStruct.Autoreload = 4999U;
    ATMR_InitStruct.ClockDivision = DDL_ATMR_CLOCKDIVISION_DIV1;
    ATMR_InitStruct.RepetitionCounter = 0U;

    DDL_ATMR_DisableARRPreload(ATMR);
    DDL_ATMR_Init(ATMR, &ATMR_InitStruct);
    if (DDL_ATMR_IsActiveFlag_UPDATE(ATMR))
    {
        DDL_ATMR_ClearFlag_UPDATE(ATMR);
    }

    DDL_ATMR_EnableIT_UPDATE(ATMR);
    /* Enable and set ATMR Interrupt priority */
    NVIC_SetPriority((IRQn_Type)(ATMR_BRK_UP_TRG_COM_IRQn),
                     NVIC_EncodePriority(NVIC_GetPriorityGrouping(), 0U, 0U));
    NVIC_EnableIRQ((IRQn_Type)(ATMR_BRK_UP_TRG_COM_IRQn));
}
