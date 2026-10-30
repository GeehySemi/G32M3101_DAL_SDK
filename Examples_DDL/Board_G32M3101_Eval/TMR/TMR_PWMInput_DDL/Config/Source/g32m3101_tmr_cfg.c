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
DDL_GTMR_InitTypeDef GTMR_InitStruct;
DDL_GTMR_IC_InitTypeDef GTMR_IC_InitStruct;

/* Private function prototypes ********************************************/

/* External variables *****************************************************/

/* External functions *****************************************************/

/**
 * @brief   GTMR configuration
 *
 * @param   None
 *
 * @retval  None
 */
void GTMR_Config(void)
{
    DDL_GPIO_InitTypeDef GPIO_InitStruct = {0U};

    DDL_SCU_Unlock();
    DDL_SCU_EnableAHBPeripheralClock(DDL_SCU_AHB_PERIPHERAL_GPIOB);
    DDL_SCU_EnableAPBPeripheralClock(DDL_SCU_APB_PERIPHERAL_GTMR);
    DDL_SCU_Lock();

    /* TMR channel pin configuration */
    GPIO_InitStruct.Mode = DDL_GPIO_MODE_ALTERNATE;
    GPIO_InitStruct.InputEnable = DDL_GPIO_INPUT_ENABLE;
    GPIO_InitStruct.InputType = DDL_GPIO_INPUT_TYPE_SCHMITT;
    GPIO_InitStruct.Alternate = DDL_GPIO_AF_4;

    /* TMR channel 1 */
    GPIO_InitStruct.Pin = DDL_GPIO_PIN_10;
    DDL_GPIO_LockKey(GPIOB, DDL_GPIO_LOCK_DISABLE);
    DDL_GPIO_Init(GPIOB, &GPIO_InitStruct);
    DDL_GPIO_LockKey(GPIOB, DDL_GPIO_LOCK_ENABLE);

    GTMR_InitStruct.Prescaler = TMR_PSC;
    GTMR_InitStruct.CounterMode = DDL_GTMR_COUNTERMODE_UP;
    GTMR_InitStruct.Autoreload = TMR_AUTORELOAD_CNT;
    GTMR_InitStruct.ClockDivision = DDL_GTMR_CLOCKDIVISION_DIV1;

    DDL_GTMR_DisableARRPreload(GTMR);
    DDL_GTMR_Init(GTMR, &GTMR_InitStruct);
    if (DDL_GTMR_IsActiveFlag_UPDATE(GTMR))
    {
        DDL_GTMR_ClearFlag_UPDATE(GTMR);
    }

    /* Configure output channel 0 */
    GTMR_IC_InitStruct.ICActiveInput = DDL_GTMR_ACTIVEINPUT_INDIRECTTI;
    GTMR_IC_InitStruct.ICPolarity = DDL_GTMR_IC_POLARITY_FALLING;
    GTMR_IC_InitStruct.ICPrescaler = DDL_GTMR_ICPSC_DIV1;
    GTMR_IC_InitStruct.ICFilter = 0U;
    DDL_GTMR_IC_Init(GTMR, DDL_GTMR_CHANNEL_CH0, &GTMR_IC_InitStruct);

    /* Configure output channel 1 */
    GTMR_IC_InitStruct.ICActiveInput = DDL_GTMR_ACTIVEINPUT_DIRECTTI;
    GTMR_IC_InitStruct.ICPolarity = DDL_GTMR_IC_POLARITY_RISING;
    GTMR_IC_InitStruct.ICPrescaler = DDL_GTMR_ICPSC_DIV1;
    GTMR_IC_InitStruct.ICFilter = 0U;
    DDL_GTMR_IC_Init(GTMR, DDL_GTMR_CHANNEL_CH1, &GTMR_IC_InitStruct);

    DDL_GTMR_SetSlaveMode(GTMR, DDL_GTMR_SLAVEMODE_RESET);
    DDL_GTMR_SetTriggerInput(GTMR, DDL_GTMR_TS_TI0FP1);

    DDL_GTMR_EnableIT_CC0(GTMR);
    DDL_GTMR_EnableIT_CC1(GTMR);
    NVIC_SetPriority((IRQn_Type)(GTMR_IRQn),
                     NVIC_EncodePriority(NVIC_GetPriorityGrouping(), 0U, 0U));
    NVIC_EnableIRQ((IRQn_Type)(GTMR_IRQn));
}
