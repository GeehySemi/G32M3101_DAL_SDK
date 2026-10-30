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
volatile uint16_t adc1ConvValue[5] = {0U};
volatile uint8_t loop = 0U;
volatile uint8_t eosFlg = 0U;

/* Private function prototypes ********************************************/
static void ADC_EOS_IntRequest(void);
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
    uint32_t adc1ConvResult = 0;
    uint8_t i = 0;
    float voltage;
    /* Device configuration */
    Device_Config();

    DDL_ADC_StartConversion(ADC);

    /* Infinite loop */
    while (1)
    {
        if (eosFlg)
        {
            eosFlg = 0;
            adc1ConvResult = 0;
            for (i = 0; i < 5; i++)
            {
                adc1ConvResult += adc1ConvValue[i];
            }
            voltage = (adc1ConvResult / 5 * 5.0f) / 4095U;
            printf("ADC CH4 Value: %.3f V\r\n", voltage);
        }
    }
}

/**
 * @brief  ADC interrupt callback
 *
 * @retval None
 */
void ADC_Isr(void)
{
    if (DDL_ADC_IsActiveFlag_EOS(ADC))
    {
        DDL_ADC_ClearFlag_EOS(ADC);
        ADC_EOS_IntRequest();
    }

    if (DDL_ADC_IsActiveFlag_OVR(ADC))
    {
        DDL_ADC_ClearFlag_OVR(ADC);
        DDL_ADC_Disable(ADC);
        ADC_OVR_IntRequest();
    }
}

/**
 * @brief  Regular conversion complete
 *
 * @retval None
 */
static void ADC_EOS_IntRequest(void)
{
    /* Get the converted value */
    adc1ConvValue[loop] = DDL_ADC_REG_ReadConversionData(ADC);
    loop++;
    if (loop > 5)
    {
        eosFlg = 1;
        loop = 0;
    }
}

/**
 * @brief  Regular conversion over error
 *
 * @retval None
 */
static void ADC_OVR_IntRequest(void)
{
    printf("ADC CH4 OVER ERROR \r\n");
}
