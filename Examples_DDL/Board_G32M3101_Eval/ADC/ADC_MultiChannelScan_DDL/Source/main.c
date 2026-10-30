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
volatile uint16_t adc1ConvValue[2] = {0U};
volatile uint16_t dmaFinishFlg = 0U;

/* Private function prototypes ********************************************/
static void ADC_OVR_IntRequest(void);

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

    /* Infinite loop */
    while (1)
    {
        if (dmaFinishFlg)
        {
            dmaFinishFlg = 0;
            printf("ADC CH3 Value: %d mV\r\n", (adc1ConvValue[0] * 5000U) / 4095U);
            printf("ADC CH4 Value: %d mV\r\n", (adc1ConvValue[1] * 5000U) / 4095U);
            DDL_ADC_StartConversion(ADC);
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
    if (DDL_DMA_IsActiveFlag_TC1(DMA))
    {
        DDL_DMA_ClearFlag_TC1(DMA);
        dmaFinishFlg = 1;
    }
}

/**
 * @brief  ADC interrupt callback
 *
 * @retval None
 */
void ADC_Isr(void)
{
    if (DDL_ADC_IsActiveFlag_OVR(ADC))
    {
        DDL_ADC_ClearFlag_OVR(ADC);
        DDL_ADC_Disable(ADC);
        ADC_OVR_IntRequest();
    }
}

/**
 * @brief  Regular conversion over error
 *
 * @retval None
 */
static void ADC_OVR_IntRequest(void)
{
    printf("ADC OVER ERROR \r\n");
}
