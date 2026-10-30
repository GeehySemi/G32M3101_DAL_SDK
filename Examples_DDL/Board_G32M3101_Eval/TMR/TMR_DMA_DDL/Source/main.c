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

/* Private function prototypes ********************************************/

/* External variables *****************************************************/
const uint32_t buf[3] = {800, 600, 400};
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

    BOARD_LED_Toggle(LED2);

    DDL_GTMR_EnableCounter(GTMR);

    /* Infinite loop */
    while (1)
    {
    }
}

/**
 * @brief     GTMR interrupt callback
 *
 * @param     None
 *
 * @retval    None
 *
 */
void GTMR_Isr(void)
{
    if (DDL_GTMR_IsActiveFlag_UPDATE(GTMR))
    {
        DDL_GTMR_ClearFlag_UPDATE(GTMR);
        BOARD_LED_Toggle(LED2);
    }
}

/**
 * @brief   DMA Channel1 interrupt callback
 *
 * @param   None
 *
 * @retval  None
 */
void DMA_Channel1_Isr(void)
{
    if (DDL_DMA_IsActiveFlag_TC1(DMA))
    {
        DDL_DMA_ClearFlag_TC1(DMA);
        printf("DMA Transfer Complete\r\n");
    }

    if (DDL_DMA_IsActiveFlag_DME1(DMA))
    {
        DDL_DMA_ClearFlag_DME1(DMA);
        printf("DMA Transfer Error\r\n");
    }
}
