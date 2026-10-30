/**
 * @file        g32m3101_opa_cfg.c
 *
 * @brief       This file provides configuration support for OPA
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
#include "g32m3101_opa_cfg.h"

/* Private includes *******************************************************/

/* Private macro **********************************************************/

/* Private typedef ********************************************************/

/* Private variables ******************************************************/

/* Private function prototypes ********************************************/

/* External variables *****************************************************/

/* External functions *****************************************************/

/**
 * @brief   OPA configuration
 *
 * @param   None
 *
 * @retval  None
 */
void OPA_Config(void)
{
    DDL_GPIO_InitTypeDef GPIO_InitStruct = {0U};
    DDL_SCU_Unlock();
    DDL_SCU_EnableAHBPeripheralClock(DDL_SCU_AHB_PERIPHERAL_GPIOA);
    DDL_SCU_Lock();

    GPIO_InitStruct.Mode = DDL_GPIO_MODE_ANALOG;

    /* OPA0_OUT pin configuration */
    GPIO_InitStruct.Pin = DDL_GPIO_PIN_0;
    DDL_GPIO_LockKey(GPIOA, DDL_GPIO_LOCK_DISABLE);
    DDL_GPIO_Init(GPIOA, &GPIO_InitStruct);
    DDL_GPIO_LockKey(GPIOA, DDL_GPIO_LOCK_ENABLE);

    /* OPA0_INN pin configuration */
    GPIO_InitStruct.Pin = DDL_GPIO_PIN_1;
    DDL_GPIO_LockKey(GPIOA, DDL_GPIO_LOCK_DISABLE);
    DDL_GPIO_Init(GPIOA, &GPIO_InitStruct);
    DDL_GPIO_LockKey(GPIOA, DDL_GPIO_LOCK_ENABLE);

    /* OPA0_INP pin configuration */
    GPIO_InitStruct.Pin = DDL_GPIO_PIN_2;
    DDL_GPIO_LockKey(GPIOA, DDL_GPIO_LOCK_DISABLE);
    DDL_GPIO_Init(GPIOA, &GPIO_InitStruct);
    DDL_GPIO_LockKey(GPIOA, DDL_GPIO_LOCK_ENABLE);

    DDL_SCU_Unlock();
    DDL_SCU_SetOPAxSelGain(DDL_SCU_OPA0, DDL_SCU_OPA_SEL_GAIN_10); // gain = 10
    DDL_SCU_SetOPAxVCM(DDL_SCU_OPA_VCM_AVDD_0_25);
    DDL_SCU_EnableOPAxInputCtrl(DDL_SCU_OPA0);
    DDL_SCU_EnableOPAxOutputCtrl(DDL_SCU_OPA0);
    DDL_SCU_EnableOPAx(DDL_SCU_OPA0);
    DDL_SCU_Lock();
}
