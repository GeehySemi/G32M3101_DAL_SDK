/**
 * @file        g32m3101_pmu_cfg.c
 *
 * @brief       This file provides configuration support for PMU
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
#include "g32m3101_pmu_cfg.h"

/* Private includes *******************************************************/

/* Private macro **********************************************************/

/* Private typedef ********************************************************/

/* Private variables ******************************************************/

/* Private function prototypes ********************************************/

/* External variables *****************************************************/

/* External functions *****************************************************/

/**
 * @brief   PMU configuration
 *
 * @param   None
 *
 * @retval  None
 */
void PMU_Config(void)
{
    DDL_EINT_InitTypeDef EINT_InitStruct = {0U};

    /* Configure the PVD Level and mode */
    DDL_SCU_Unlock();
    /* Set PVDCSE[3:1] bits according to PVDLevel value */
    DDL_SCU_SetPVDThreshold(0x7);

    /* Enable the PVD Interrupt */
    DDL_SCU_EnablePVDLowThresholdDetect();
    DDL_SCU_EnablePVDHighThresholdDetect();
    DDL_SCU_Lock();

    /*--------------------- EINT Mode Configuration ------------------------*/
    DDL_SCU_Unlock();
    DDL_SCU_EnableAPBPeripheralClock(DDL_SCU_APB_PERIPHERAL_EINT);
    DDL_SCU_Lock();

    EINT_InitStruct.Line_0_31 = DDL_EINT_LINE_16;
    EINT_InitStruct.LineCommand = ENABLE;
    EINT_InitStruct.Mode = DDL_EINT_MODE_IT;
    EINT_InitStruct.Trigger = DDL_EINT_TRIGGER_RISING_FALLING;

    DDL_EINT_Init(&EINT_InitStruct);

    /* Enable Interrupt */
    NVIC_SetPriority(PVD_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(), 0U, 0U));
    NVIC_EnableIRQ(PVD_IRQn);

    /* Enable the PVD Output */
    DDL_SCU_Unlock();
    DDL_SCU_EnablePVD();
    DDL_SCU_Lock();
}
