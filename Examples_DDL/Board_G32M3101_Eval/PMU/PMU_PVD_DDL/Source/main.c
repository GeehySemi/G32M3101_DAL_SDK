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

    /* Infinite loop */
    while (1)
    {
        BOARD_LED_Toggle(LED2);
        DDL_mDelay(500U);
    }
}

/**
 * @brief   PMU PVD interrupt callback
 *
 * @param   None
 *
 * @retval  None
 */
void PVD_Isr(void)
{
    if (DDL_SCU_IsActiveFlag_PVDIT())
    {
        printf("PVD detection level high than 4.8V\r\n");
    }
    else
    {
        printf("PVD detection level low than 4.7V\r\n");
    }
    DDL_SCU_Unlock();
    DDL_SCU_DisablePVD();
    DDL_SCU_ClearFlag_PVDIT();
    DDL_EINT_ClearFlag_0_31(DDL_EINT_LINE_16);
    DDL_SCU_Lock();
}
