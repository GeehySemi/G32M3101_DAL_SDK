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
DDL_GTMR_OC_InitTypeDef GTMR_OC_InitStruct;
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

    /* TMR channel 2 */
    GPIO_InitStruct.Mode = DDL_GPIO_MODE_ALTERNATE;
    GPIO_InitStruct.InputEnable = DDL_GPIO_INPUT_DISABLE;
    GPIO_InitStruct.Drive = DDL_GPIO_DRIVE_HIGH;
    GPIO_InitStruct.Pull = DDL_GPIO_PULL_UP;
    GPIO_InitStruct.Alternate = DDL_GPIO_AF_4;

    GPIO_InitStruct.Pin = DDL_GPIO_PIN_11;
    DDL_GPIO_LockKey(GPIOB, DDL_GPIO_LOCK_DISABLE);
    DDL_GPIO_Init(GPIOB, &GPIO_InitStruct);
    DDL_GPIO_LockKey(GPIOB, DDL_GPIO_LOCK_ENABLE);

    GTMR_InitStruct.Prescaler = 1U;
    GTMR_InitStruct.CounterMode = DDL_GTMR_COUNTERMODE_UP;
    GTMR_InitStruct.Autoreload = 32767U;
    GTMR_InitStruct.ClockDivision = DDL_GTMR_CLOCKDIVISION_DIV1;

    DDL_GTMR_DisableARRPreload(GTMR);
    DDL_GTMR_Init(GTMR, &GTMR_InitStruct);
    DDL_GTMR_SetOnePulseMode(GTMR, DDL_GTMR_ONEPULSEMODE_SINGLE);
    if (DDL_GTMR_IsActiveFlag_UPDATE(GTMR))
    {
        DDL_GTMR_ClearFlag_UPDATE(GTMR);
    }

    /* Configure input channel 1 */
    GTMR_IC_InitStruct.ICFilter = 0U;
    GTMR_IC_InitStruct.ICPolarity = DDL_GTMR_IC_POLARITY_RISING;
    GTMR_IC_InitStruct.ICActiveInput = DDL_GTMR_ACTIVEINPUT_DIRECTTI;
    DDL_GTMR_IC_Init(GTMR, DDL_GTMR_CHANNEL_CH1, &GTMR_IC_InitStruct);

    /* Configure output channel 2 */
    GTMR_OC_InitStruct.OCMode = DDL_GTMR_OCMODE_PWM2;
    GTMR_OC_InitStruct.OCState = DDL_GTMR_OCSTATE_ENABLE;
    GTMR_OC_InitStruct.OCPolarity = DDL_GTMR_OCPOLARITY_HIGH;
    GTMR_OC_InitStruct.CompareValue = 8191U;
    DDL_GTMR_OC_Init(GTMR, DDL_GTMR_CHANNEL_CH2, &GTMR_OC_InitStruct);

    /* Reset the IC2PSC Bits */
    GTMR->CCM1 &= ~GTMR_CCM1_IC1PSC;
    /* Select the Trigger source */
    DDL_GTMR_SetTriggerInput(GTMR, DDL_GTMR_TS_TI1FP2);
    /* Select the Slave Mode */
    DDL_GTMR_SetSlaveMode(GTMR, DDL_GTMR_SLAVEMODE_TRIGGER);
}
