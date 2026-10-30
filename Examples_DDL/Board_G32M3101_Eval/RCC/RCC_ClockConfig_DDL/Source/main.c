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

/* Private includes *******************************************************/
#include "g32m3101_device_cfg.h"

/* Private macro **********************************************************/

/* Private typedef ********************************************************/

/* Private variables ******************************************************/

/* Private function prototypes ********************************************/
static void MCO_Config(void);

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

    /* MCO configuration */
    MCO_Config();

    /* Configures MCO output HSI / 64 */
    DDL_SCU_Unlock();
    DDL_SCU_EnableMCO();
    DDL_SCU_ConfigMCO(DDL_SCU_MCOSOURCE_HSI, DDL_SCU_MCO_DIV_64);
    DDL_SCU_Lock();

    /* Infinite loop */
    while (1)
    {
        BOARD_LED_Toggle(LED2);
        DDL_mDelay(500U);
    }
}

/**
 * @brief   MCO configuration
 *
 * @param   None
 *
 * @retval  None
 */
static void MCO_Config(void)
{
    DDL_GPIO_InitTypeDef GPIO_InitStruct;

    DDL_SCU_Unlock();
    DDL_SCU_EnableAHBPeripheralClock(DDL_SCU_AHB_PERIPHERAL_GPIOA);
    DDL_SCU_Lock();

    /* Configure the MCO1 pin in alternate function mode */
    GPIO_InitStruct.Pin = DDL_GPIO_PIN_7;
    GPIO_InitStruct.Mode = DDL_GPIO_MODE_ALTERNATE;
    GPIO_InitStruct.Drive = DDL_GPIO_DRIVE_LOW;
    GPIO_InitStruct.OutputType = DDL_GPIO_OUTPUT_PUSHPULL;
    GPIO_InitStruct.Pull = DDL_GPIO_PULL_NO;
    GPIO_InitStruct.Alternate = DDL_GPIO_AF_7;

    DDL_GPIO_LockKey(GPIOA, DDL_GPIO_LOCK_DISABLE);
    DDL_GPIO_Init(GPIOA, &GPIO_InitStruct);
    DDL_GPIO_LockKey(GPIOA, DDL_GPIO_LOCK_ENABLE);
}
