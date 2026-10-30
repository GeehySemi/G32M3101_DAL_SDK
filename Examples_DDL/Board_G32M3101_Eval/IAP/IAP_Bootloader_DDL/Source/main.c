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
#include "iap_flash.h"
#include "iap_menu.h"
#include "iap_common.h"

/* Private macro **********************************************************/

/* Private typedef ********************************************************/

/* Private variables ******************************************************/

/* Private function prototypes ********************************************/

/* External variables *****************************************************/
extern pFunction Jump_To_Application;
extern uint32_t JumpAddress;

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
    uint32_t address;

    /* Device configuration */
    Device_Config();

    /* Display Select menu */
    Select_Menu();

    /* Jump to user application 1 */
    Serial_SendString((uint8_t *)">> Jump to user application 1\r\n");

    /* Lock the Program memory */
    DDL_FLASH_MKEY_Lock();
    DDL_FLASH_RKEY_Lock();

    address = USER_APP1_START_ADDRESS;

    /* Jump to user application */
    JumpAddress = *(__IO uint32_t *)(address + 4U);
    Jump_To_Application = (pFunction)JumpAddress;

    /* Initialize user application's Stack Pointer */
    __set_MSP(*(__IO uint32_t *)address);

    /* Jump to application */
    Jump_To_Application();

    /* Infinite loop */
    while (1)
    {
    }
}
