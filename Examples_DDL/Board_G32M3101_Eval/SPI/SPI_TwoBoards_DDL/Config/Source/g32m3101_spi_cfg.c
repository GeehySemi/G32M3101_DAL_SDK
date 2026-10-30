/**
 * @file        g32m3101_spi_cfg.c
 *
 * @brief       This file provides configuration support for SPI
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
#include "g32m3101_spi_cfg.h"

/* Private includes *******************************************************/

/* Private macro **********************************************************/

/* Private typedef ********************************************************/

/* Private variables ******************************************************/

/* Private function prototypes ********************************************/
#if SPI_MASTER
static void DDL_SPI_Master_Config(void);
#endif

#if SPI_SLAVER
static void DDL_SPI_Slaver_Config(void);
#endif

/* External variables *****************************************************/

/* External functions *****************************************************/

/**
 * @brief   GPIO configuration
 *
 * @param   None
 *
 * @retval  None
 */
void SPI_Config(void)
{
#if SPI_MASTER
    DDL_SPI_Master_Config();
#endif
#if SPI_SLAVER
    DDL_SPI_Slaver_Config();
#endif
}

#if SPI_MASTER
/**
 * @brief   SPI master configuration
 *
 * @param   None
 *
 * @retval  None
 */
static void DDL_SPI_Master_Config(void)
{
    DDL_SPI_InitTypeDef SPI_InitStruct = {0U};
    DDL_GPIO_InitTypeDef GPIO_InitStruct = {0U};

    DDL_SCU_Unlock();
    DDL_SCU_EnableAHBPeripheralClock(DDL_SCU_AHB_PERIPHERAL_GPIOB);
    DDL_SCU_EnableAPBPeripheralClock(DDL_SCU_APB_PERIPHERAL_SPI);
    DDL_SCU_Lock();

    /* SPI pin configuration */
    /* CS PB9*/
    GPIO_InitStruct.Mode = DDL_GPIO_MODE_ALTERNATE;
    GPIO_InitStruct.InputEnable = DDL_GPIO_INPUT_ENABLE;
    GPIO_InitStruct.Alternate = DDL_GPIO_AF_1;
    GPIO_InitStruct.Pin = DDL_GPIO_PIN_9;
    DDL_GPIO_LockKey(GPIOB, DDL_GPIO_LOCK_DISABLE);
    DDL_GPIO_Init(GPIOB, &GPIO_InitStruct);
    DDL_GPIO_LockKey(GPIOB, DDL_GPIO_LOCK_ENABLE);

    /* SCK PB10*/
    GPIO_InitStruct.Mode = DDL_GPIO_MODE_ALTERNATE;
    GPIO_InitStruct.OutputType = DDL_GPIO_OUTPUT_PUSHPULL;
    GPIO_InitStruct.Alternate = DDL_GPIO_AF_1;
    GPIO_InitStruct.Pin = DDL_GPIO_PIN_10;
    DDL_GPIO_LockKey(GPIOB, DDL_GPIO_LOCK_DISABLE);
    DDL_GPIO_Init(GPIOB, &GPIO_InitStruct);
    DDL_GPIO_LockKey(GPIOB, DDL_GPIO_LOCK_ENABLE);

    /* MISO PB11*/
    GPIO_InitStruct.Mode = DDL_GPIO_MODE_ALTERNATE;
    GPIO_InitStruct.InputEnable = DDL_GPIO_INPUT_ENABLE;
    GPIO_InitStruct.Alternate = DDL_GPIO_AF_1;
    GPIO_InitStruct.Pin = DDL_GPIO_PIN_11;
    DDL_GPIO_LockKey(GPIOB, DDL_GPIO_LOCK_DISABLE);
    DDL_GPIO_Init(GPIOB, &GPIO_InitStruct);
    DDL_GPIO_LockKey(GPIOB, DDL_GPIO_LOCK_ENABLE);

    /* MOSI PB12*/
    GPIO_InitStruct.Mode = DDL_GPIO_MODE_ALTERNATE;
    GPIO_InitStruct.OutputType = DDL_GPIO_OUTPUT_PUSHPULL;
    GPIO_InitStruct.Alternate = DDL_GPIO_AF_1;
    GPIO_InitStruct.Pin = DDL_GPIO_PIN_12;
    DDL_GPIO_LockKey(GPIOB, DDL_GPIO_LOCK_DISABLE);
    DDL_GPIO_Init(GPIOB, &GPIO_InitStruct);
    DDL_GPIO_LockKey(GPIOB, DDL_GPIO_LOCK_ENABLE);

    SPI_InitStruct.Mode = DDL_SPI_MODE_MASTER;
    SPI_InitStruct.TransferDirection = DDL_SPI_FULL_DUPLEX;
    SPI_InitStruct.NSS = DDL_SPI_NSS_HARD_INPUT;
    SPI_InitStruct.BaudRate = DDL_SPI_BAUDRATEPRESCALER_DIV256;
    SPI_InitStruct.ClockPolarity = DDL_SPI_POLARITY_HIGH;
    SPI_InitStruct.ClockPhase = DDL_SPI_PHASE_1EDGE;
    SPI_InitStruct.DataWidth = DDL_SPI_DATAWIDTH_8BIT;
    SPI_InitStruct.BitOrder = DDL_SPI_MSB_FIRST;
    DDL_SPI_Init(SPI, &SPI_InitStruct);

    DDL_SPI_EnableIT_OVR(SPI);
    NVIC_SetPriority((IRQn_Type)(SPI_IRQn),
                     NVIC_EncodePriority(NVIC_GetPriorityGrouping(), 0U, 0U));
    NVIC_EnableIRQ((IRQn_Type)(SPI_IRQn));
}
#endif

#if SPI_SLAVER
/**
 * @brief   SPI slaver configuration
 *
 * @param   None
 *
 * @retval  None
 */
static void DDL_SPI_Slaver_Config(void)
{
    DDL_SPI_InitTypeDef SPI_InitStruct = {0U};
    DDL_GPIO_InitTypeDef GPIO_InitStruct = {0U};

    DDL_SCU_Unlock();
    DDL_SCU_EnableAHBPeripheralClock(DDL_SCU_AHB_PERIPHERAL_GPIOB);
    DDL_SCU_EnableAPBPeripheralClock(DDL_SCU_APB_PERIPHERAL_SPI);
    DDL_SCU_Lock();

    /* SPI pin configuration */
    /* CS PB9*/
    GPIO_InitStruct.Mode = DDL_GPIO_MODE_ALTERNATE;
    GPIO_InitStruct.InputEnable = DDL_GPIO_INPUT_ENABLE;
    GPIO_InitStruct.Alternate = DDL_GPIO_AF_1;
    GPIO_InitStruct.Pin = DDL_GPIO_PIN_9;
    DDL_GPIO_LockKey(GPIOB, DDL_GPIO_LOCK_DISABLE);
    DDL_GPIO_Init(GPIOB, &GPIO_InitStruct);
    DDL_GPIO_LockKey(GPIOB, DDL_GPIO_LOCK_ENABLE);

    /* SCK PB10*/
    GPIO_InitStruct.Mode = DDL_GPIO_MODE_ALTERNATE;
    GPIO_InitStruct.InputEnable = DDL_GPIO_INPUT_ENABLE;
    GPIO_InitStruct.Alternate = DDL_GPIO_AF_1;
    GPIO_InitStruct.Pin = DDL_GPIO_PIN_10;
    DDL_GPIO_LockKey(GPIOB, DDL_GPIO_LOCK_DISABLE);
    DDL_GPIO_Init(GPIOB, &GPIO_InitStruct);
    DDL_GPIO_LockKey(GPIOB, DDL_GPIO_LOCK_ENABLE);

    /* MISO PB11*/
    GPIO_InitStruct.Mode = DDL_GPIO_MODE_ALTERNATE;
    GPIO_InitStruct.OutputType = DDL_GPIO_OUTPUT_PUSHPULL;
    GPIO_InitStruct.Alternate = DDL_GPIO_AF_1;
    GPIO_InitStruct.Pin = DDL_GPIO_PIN_11;
    DDL_GPIO_LockKey(GPIOB, DDL_GPIO_LOCK_DISABLE);
    DDL_GPIO_Init(GPIOB, &GPIO_InitStruct);
    DDL_GPIO_LockKey(GPIOB, DDL_GPIO_LOCK_ENABLE);

    /* MOSI PB12*/
    GPIO_InitStruct.Mode = DDL_GPIO_MODE_ALTERNATE;
    GPIO_InitStruct.InputEnable = DDL_GPIO_INPUT_ENABLE;
    GPIO_InitStruct.Alternate = DDL_GPIO_AF_1;
    GPIO_InitStruct.Pin = DDL_GPIO_PIN_12;
    DDL_GPIO_LockKey(GPIOB, DDL_GPIO_LOCK_DISABLE);
    DDL_GPIO_Init(GPIOB, &GPIO_InitStruct);
    DDL_GPIO_LockKey(GPIOB, DDL_GPIO_LOCK_ENABLE);

    SPI_InitStruct.Mode = DDL_SPI_MODE_SLAVE;
    SPI_InitStruct.TransferDirection = DDL_SPI_FULL_DUPLEX;
    SPI_InitStruct.NSS = DDL_SPI_NSS_HARD_INPUT;
    SPI_InitStruct.BaudRate = DDL_SPI_BAUDRATEPRESCALER_DIV256;
    SPI_InitStruct.ClockPolarity = DDL_SPI_POLARITY_HIGH;
    SPI_InitStruct.ClockPhase = DDL_SPI_PHASE_1EDGE;
    SPI_InitStruct.DataWidth = DDL_SPI_DATAWIDTH_8BIT;
    SPI_InitStruct.BitOrder = DDL_SPI_MSB_FIRST;
    DDL_SPI_Init(SPI, &SPI_InitStruct);

    DDL_SPI_EnableIT_OVR(SPI);
    NVIC_SetPriority((IRQn_Type)(SPI_IRQn),
                     NVIC_EncodePriority(NVIC_GetPriorityGrouping(), 0U, 0U));
    NVIC_EnableIRQ((IRQn_Type)(SPI_IRQn));
}
#endif
