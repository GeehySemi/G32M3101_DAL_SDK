/**
 * @file        g32m3101_lptmr_cfg.c
 *
 * @brief       This file provides configuration support for RCM
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
#include "g32m3101_lptmr_cfg.h"

/* Private includes *******************************************************/

/* Private macro **********************************************************/

/* Private typedef ********************************************************/

/* Private variables ******************************************************/

/* Private function prototypes ********************************************/

/* External variables *****************************************************/
DDL_LPTMR_InitTypeDef LPTMR_InitStruct;
/* External functions *****************************************************/

/**
 * @brief   Peripheral LPTMR configuration
 *
 * @param   None
 *
 * @retval  None
 */
void LPTMR_Config(void)
{
    DDL_SCU_Unlock();
    DDL_SCU_EnableAPBPeripheralClock(DDL_SCU_APB_PERIPHERAL_LPTMR);
    DDL_SCU_EnableAPBPeripheralClock(DDL_SCU_APB_PERIPHERAL_EINT);
    DDL_SCU_LSI_Enable();
    while (!DDL_SCU_LSI_IsReady())
    {
    }
    DDL_SCU_Lock();

    LPTMR_InitStruct.Prescaler = 32;
    LPTMR_InitStruct.WakeUpValue = 5000;
    DDL_LPTMR_Init(LPTMR, &LPTMR_InitStruct);
    CLEAR_BIT(LPTMR->STS, DDL_LPTMR_STS_WKF);

    DDL_EINT_EnableRisingTrig_0_31(DDL_EINT_LINE_17);
    DDL_EINT_EnableIT_0_31(DDL_EINT_LINE_17);
    NVIC_SetPriority((IRQn_Type)(LPTMR_IRQn),
                     NVIC_EncodePriority(NVIC_GetPriorityGrouping(), 0U, 0U));
    NVIC_EnableIRQ((IRQn_Type)(LPTMR_IRQn));
}
