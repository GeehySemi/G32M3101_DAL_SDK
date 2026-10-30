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
/* DMA destination: one discontinuous group (2 ranks) per TC */
volatile uint16_t adc1ConvValue[2] = {0U};

/* Shadow latched in DMA ISR so printf cannot race with the next transfer */
volatile uint16_t adcPrintValue[2] = {0U};
/* 0: CH4/CH5, 1: CH2/CH3 */
volatile uint8_t adcConvGroup = 0U;
volatile uint8_t adcDataReady = 0U;

static uint16_t conv0;
static uint16_t conv1;
static uint8_t group;

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

    DDL_DMA_EnableChannel(DMA, DDL_DMA_CHANNEL_1);

    DDL_ADC_StartConversion(ADC);

    DDL_ATMR_EnableCounter(ATMR);

    /* Infinite loop */
    while (1)
    {
        /* Each DMA TC = one discontinuous group (2 samples) */
        if (adcDataReady != 0U)
        {
            __disable_irq();
            adcDataReady = 0U;
            conv0 = adcPrintValue[0];
            conv1 = adcPrintValue[1];
            group = adcConvGroup;
            __enable_irq();

            if (group == 0U)
            {
                printf("ADC1 CH4(PB1) Value: %d mV\r\n", (conv0 * 5000U) / 4095U);
                printf("ADC1 CH5(PB2) Value: %d mV\r\n", (conv1 * 5000U) / 4095U);
            }
            else
            {
                printf("ADC1 CH2(PB5) Value: %d mV\r\n", (conv0 * 5000U) / 4095U);
                printf("ADC1 CH3(PB6) Value: %d mV\r\n", (conv1 * 5000U) / 4095U);
            }
        }
    }
}

/**
 * @brief  DMA Channel1 interrupt callback
 *
 * @retval None
 */
void DMA_Channel1_Isr(void)
{
    static uint8_t seqPhase = 0U;

    if (DDL_DMA_IsActiveFlag_TC1(DMA1))
    {
        DDL_DMA_ClearFlag_TC1(DMA1);

        /* Copy out before next trigger overwrites adc1ConvValue[] */
        adcPrintValue[0] = adc1ConvValue[0];
        adcPrintValue[1] = adc1ConvValue[1];
        adcConvGroup = seqPhase;
        seqPhase ^= 1U;
        adcDataReady = 1U;
    }
}
