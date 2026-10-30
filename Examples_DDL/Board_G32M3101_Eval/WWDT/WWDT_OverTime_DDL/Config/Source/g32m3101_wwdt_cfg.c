/**
 * @file        g32m3101_wwdt_cfg.c
 *
 * @brief       This file provides configuration support for WWDT
 *
 * @version     V1.0.0
 *
 * @date        2023-07-31
 *
 * @attention
 *
 *  Copyright (C) 2023 Geehy Semiconductor
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
#include "g32m3101_wwdt_cfg.h"

/* Private includes *******************************************************/

/* Private macro **********************************************************/

/* Private typedef ********************************************************/

/* Private variables ******************************************************/

/* Private function prototypes ********************************************/

/* External variables *****************************************************/

/* External functions *****************************************************/

/**
 * @brief   WWDT configuration
 *
 * @param   None
 *
 * @retval  None
 */
void DDL_WWDT_Config(void)
{
    DDL_SCU_Unlock();
    DDL_SCU_EnableAPBPeripheralClock(DDL_SCU_APB_PERIPHERAL_WWDT);
    DDL_SCU_Lock();

    /* WWDT TimeBase =  PCLK (64MHz / 4096) / 8 = 1953.125Hz (~0.512ms)
       Set Window value to 80; WWDT counter should be refreshed only when the counter
       is below 80 (and greater than 64) otherwise a reset will be generated.
       Enable WWDT and set counter value to 127, WWDT timeout = ~0.512ms * 64 = 64 us
       In this case the refresh window is: ~0.512ms * (127 - 80) = 24.064ms < refresh window <
       ~0.512ms * 64 = 32.768ms
    */
    DDL_WWDT_SetPrescaler(WWDT, DDL_WWDT_PRESCALER_8);
    DDL_WWDT_SetCounter(WWDT, 127U);
    DDL_WWDT_SetWindow(WWDT, 80U);
    DDL_WWDT_Enable(WWDT);
}
