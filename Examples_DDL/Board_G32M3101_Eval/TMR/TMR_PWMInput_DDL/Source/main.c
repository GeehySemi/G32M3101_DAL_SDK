/**
 * @file        main.c
 *
 * @brief       Main program body
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
#include "main.h"
#include <stdio.h>

/* Private includes *******************************************************/
#include "g32m3101_device_cfg.h"

/* Private macro **********************************************************/

/* Private typedef ********************************************************/

/* Private variables ******************************************************/
uint32_t captureVal[2] = {0U};
__IO uint32_t captureFreq = 0U;
__IO uint32_t captureIndex = 0U;
__IO uint32_t captureDuty = 0U;
DDL_SCU_ClocksTypeDef sysClock;

/* Private function prototypes ********************************************/

/* External variables *****************************************************/

/* External functions *****************************************************/

/**
 * @brief   Main program
 *
 * @param   None
 *
 * @retval  None
 */
int main(void)
{
    /* Device configuration */
    Device_Config();

    DDL_GTMR_EnableCounter(GTMR);

    /* Infinite loop */
    while (1)
    {
        printf("Frequency: %ld Hz\r\n", (long)captureFreq);
        printf("Duty: %ld %%\r\n", (long)captureDuty);
        DDL_mDelay(500U);
    }
}

/**
 * @brief  GTMR interrupt callback
 *
 * @param  None
 *
 * @retval None
 */
void GTMR_Isr(void)
{
    uint32_t cntValue = 0U;
    if (DDL_GTMR_IsActiveFlag_CC1(GTMR))
    {
        DDL_GTMR_ClearFlag_CC1(GTMR);
        captureVal[captureIndex] = DDL_GTMR_IC_GetCaptureCH1(GTMR);

        if (DDL_GTMR_IsActiveFlag_CC1OVR(GTMR))
        {
            DDL_GTMR_ClearFlag_CC1OVR(GTMR);
        }
        else
        {
            if (captureIndex != 0U)
            {
                captureIndex = 0U;

                /* Capture computation */
                if (captureVal[1] > captureVal[0])
                {
                    cntValue = captureVal[1] - captureVal[0];
                }
                else if (captureVal[1] < captureVal[0])
                {
                    cntValue = TMR_AUTORELOAD_CNT - captureVal[0] + captureVal[1];
                }
                else
                {
                    cntValue = 0U;
                }

                if (cntValue != 0)
                {
                    /* Frequency computation */
                    DDL_SCU_GetSysctrlClocksFreq(&sysClock);
                    captureFreq = ((sysClock.HCLK_Frequency) / (TMR_PSC + 1)) / cntValue;
                }

                /* Duty computation */
                if (DDL_GTMR_IC_GetCaptureCH0(GTMR) > captureVal[0])
                {
                    captureDuty =
                        ((DDL_GTMR_IC_GetCaptureCH0(GTMR))-captureVal[0]) * 100 / cntValue;
                }
            }
            else
            {
                captureIndex++;
            }
        }
    }
}
