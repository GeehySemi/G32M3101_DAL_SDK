/**
 * @file        g32m3101_dma_cfg.c
 *
 * @brief       This file provides configuration support for DMA
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
#include "g32m3101_dma_cfg.h"

/* Private includes *******************************************************/

/* Private macro **********************************************************/

/* Private typedef ********************************************************/

/* Private variables ******************************************************/

/* Private function prototypes ********************************************/

/* External variables *****************************************************/

/* External functions *****************************************************/

/**
 * @brief   DMA configuration
 *
 * @param   None
 *
 * @retval  None
 */
void DMA_Config(void)
{
    DDL_DMA_InitTypeDef DMA_InitStruct = {0};

    /* Unlock SCU register */
    DDL_SCU_Unlock();
    DDL_SCU_EnableAHBPeripheralClock(DDL_SCU_AHB_PERIPHERAL_DMA);
    /* Lock SCU register */
    DDL_SCU_Lock();

    /* Configure DMA_Channel1 */
    DMA_InitStruct.Direction = DDL_DMA_DIRECTION_MEMORY_TO_MEMORY;
    DMA_InitStruct.Mode = DDL_DMA_MODE_NORMAL;
    DMA_InitStruct.PeriphOrM2MSrcIncMode = DDL_DMA_PERIPH_INCREMENT;
    DMA_InitStruct.MemoryOrM2MDstIncMode = DDL_DMA_MEMORY_INCREMENT;
    DMA_InitStruct.PeriphOrM2MSrcDataSize = DDL_DMA_PDATAALIGN_WORD;
    DMA_InitStruct.MemoryOrM2MDstDataSize = DDL_DMA_MDATAALIGN_WORD;
    DMA_InitStruct.Priority = DDL_DMA_PRIORITY_LOW;
    DDL_DMA_Init(DMA, DDL_DMA_CHANNEL_1, &DMA_InitStruct);

    DDL_DMA_EnableIT_TC(DMA, DDL_DMA_CHANNEL_1);
    DDL_DMA_EnableIT_DME(DMA, DDL_DMA_CHANNEL_1);
    /* Enable DMA interrupt */
    NVIC_SetPriority(DMA_Channel1_IRQn, 0U);
    NVIC_EnableIRQ(DMA_Channel1_IRQn);
}
