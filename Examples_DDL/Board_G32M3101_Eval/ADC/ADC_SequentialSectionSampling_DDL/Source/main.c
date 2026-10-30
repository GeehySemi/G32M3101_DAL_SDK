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
uint8_t seg1Flg = 0U;
uint8_t seg2Flg = 0U;
static volatile uint8_t sec2Count = 0U;
static volatile uint8_t seqRestart = 0U;
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

    BOARD_LED_On(LED2);

    DDL_ADC_StartConversion(ADC);

    DDL_ATMR_EnableCounter(ATMR);

    /* Infinite loop */
    while (1)
    {
        if ((seqRestart != 0U) && (DDL_ADC_IsConversionOngoing(ADC) == 0U))
        {
            seqRestart = 0U;
            DDL_ADC_StartConversion(ADC);
        }

        if (seg1Flg == 1)
        {
            seg1Flg = 0;
            /* Read ADC conversion value */
            printf(
                "ADC CH4(PB1) Value: %ld mV\r\n",
                (unsigned long)(DDL_ADC_SEQ_ReadConversionData(ADC, DDL_ADC_REG_RANK_1) * 5000U) /
                    4095U);
        }
        if (seg2Flg == 1)
        {
            seg2Flg = 0;
            /* Read ADC conversion value */
            printf(
                "ADC CH5(PB2) Value: %ld mV\r\n",
                (unsigned long)(DDL_ADC_SEQ_ReadConversionData(ADC, DDL_ADC_REG_RANK_2) * 5000U) /
                    4095U);
            printf(
                "ADC CH4(PB1) Value: %ld mV\r\n",
                (unsigned long)(DDL_ADC_SEQ_ReadConversionData(ADC, DDL_ADC_REG_RANK_3) * 5000U) /
                    4095U);
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
    if (DDL_ADC_IsActiveFlag_EOSMP_SEQ_NUM1(ADC) != 0U)
    {
        DDL_ADC_ClearFlag_EOSMP_SEQ_NUM1(ADC);
        seg1Flg = 1;
        BOARD_LED_Toggle(LED2);
    }
    if (DDL_ADC_IsActiveFlag_EOSMP_SEQ_NUM2(ADC) != 0U)
    {
        DDL_ADC_ClearFlag_EOSMP_SEQ_NUM2(ADC);
        seg2Flg = 1;
        BOARD_LED_Toggle(LED2);
        sec2Count++;
        if (sec2Count >= 2U)
        {
            sec2Count = 0U;
            seqRestart = 1U;
        }
    }
}
