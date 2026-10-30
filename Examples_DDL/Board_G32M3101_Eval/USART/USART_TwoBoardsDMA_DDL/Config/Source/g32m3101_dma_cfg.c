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
#include <string.h>

/* Private includes *******************************************************/

/* Private macro **********************************************************/

/* Private typedef ********************************************************/

/* Private variables ******************************************************/

/* Private function prototypes ********************************************/

/* External variables *****************************************************/
extern char txBuffer[];
extern char rxBuffer[50U];
/* External functions *****************************************************/

/**
 * @brief   DMA configuration
 *
 * @param   None
 *
 * @retval  None
 */
void DDL_DMA_Config(void)
{
    DDL_DMA_InitTypeDef DMA_InitStruct = {0U};

    DDL_SCU_Unlock();
    DDL_SCU_EnableAHBPeripheralClock(DDL_SCU_AHB_PERIPHERAL_DMA);
    DDL_SCU_Lock();

    /* Configure USART0 TX DMA */
    DMA_InitStruct.Peripheral = DDL_DMA_PERIPHERAL_5;
    DMA_InitStruct.Direction = DDL_DMA_DIRECTION_MEMORY_TO_PERIPH;
    DMA_InitStruct.PeriphOrM2MSrcAddress = (uint32_t)&(UART0->DATA);
    DMA_InitStruct.PeriphOrM2MSrcDataSize = DDL_DMA_PDATAALIGN_BYTE;
    DMA_InitStruct.PeriphOrM2MSrcIncMode = DDL_DMA_PERIPH_NOINCREMENT;
    DMA_InitStruct.MemoryOrM2MDstAddress = (uint32_t)txBuffer;
    DMA_InitStruct.MemoryOrM2MDstDataSize = DDL_DMA_MDATAALIGN_BYTE;
    DMA_InitStruct.MemoryOrM2MDstIncMode = DDL_DMA_MEMORY_INCREMENT;
    DMA_InitStruct.NbData = strlen(txBuffer);
    DMA_InitStruct.Mode = DDL_DMA_MODE_NORMAL;
    DMA_InitStruct.Priority = DDL_DMA_PRIORITY_LOW;
    DMA_InitStruct.FIFOMode = DDL_DMA_FIFOMODE_DISABLE;

    DDL_DMA_DisableChannel(DMA, DDL_DMA_CHANNEL_0);
    while (DDL_DMA_IsEnabledChannel(DMA, DDL_DMA_CHANNEL_0) != 0)
    {
    }

    DDL_DMA_Init(DMA, DDL_DMA_CHANNEL_0, &DMA_InitStruct);
    DMA->LIFCLR = 0;
    DDL_DMA_EnableIT_TC(DMA, DDL_DMA_CHANNEL_0);
    DDL_DMA_EnableIT_TE(DMA, DDL_DMA_CHANNEL_0);
    DDL_DMA_EnableIT_DME(DMA, DDL_DMA_CHANNEL_0);

    /* USART0 TX DMA interrupt */
    NVIC_SetPriority((IRQn_Type)(DMA_Channel0_IRQn),
                     NVIC_EncodePriority(NVIC_GetPriorityGrouping(), 3U, 0U));
    NVIC_EnableIRQ((IRQn_Type)(DMA_Channel0_IRQn));

    /* Configure USART0 RX DMA */
    DMA_InitStruct.Peripheral = DDL_DMA_PERIPHERAL_5;
    DMA_InitStruct.Direction = DDL_DMA_DIRECTION_PERIPH_TO_MEMORY;
    DMA_InitStruct.PeriphOrM2MSrcAddress = (uint32_t)&(UART0->DATA);
    DMA_InitStruct.PeriphOrM2MSrcDataSize = DDL_DMA_PDATAALIGN_BYTE;
    DMA_InitStruct.PeriphOrM2MSrcIncMode = DDL_DMA_PERIPH_NOINCREMENT;
    DMA_InitStruct.MemoryOrM2MDstAddress = (uint32_t)rxBuffer;
    DMA_InitStruct.MemoryOrM2MDstDataSize = DDL_DMA_MDATAALIGN_BYTE;
    DMA_InitStruct.MemoryOrM2MDstIncMode = DDL_DMA_MEMORY_INCREMENT;
    DMA_InitStruct.NbData = strlen(txBuffer);
    DMA_InitStruct.Mode = DDL_DMA_MODE_NORMAL;
    DMA_InitStruct.Priority = DDL_DMA_PRIORITY_LOW;
    DMA_InitStruct.FIFOMode = DDL_DMA_FIFOMODE_DISABLE;

    DDL_DMA_DisableChannel(DMA, DDL_DMA_CHANNEL_1);
    while (DDL_DMA_IsEnabledChannel(DMA, DDL_DMA_CHANNEL_1) != 0)
    {
    }

    DDL_DMA_Init(DMA, DDL_DMA_CHANNEL_1, &DMA_InitStruct);
    DMA->LIFCLR = 0;
    DDL_DMA_EnableIT_TC(DMA, DDL_DMA_CHANNEL_1);
    DDL_DMA_EnableIT_TE(DMA, DDL_DMA_CHANNEL_1);
    DDL_DMA_EnableIT_DME(DMA, DDL_DMA_CHANNEL_1);

    /* USART0 TX DMA interrupt */
    NVIC_SetPriority((IRQn_Type)(DMA_Channel1_IRQn),
                     NVIC_EncodePriority(NVIC_GetPriorityGrouping(), 3U, 0U));
    NVIC_EnableIRQ((IRQn_Type)(DMA_Channel1_IRQn));
}
