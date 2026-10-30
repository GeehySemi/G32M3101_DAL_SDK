/**
 * @file        g32m3101_adc_cfg.c
 *
 * @brief       This file provides configuration support for ADC
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
#include "g32m3101_adc_cfg.h"

/* Private includes *******************************************************/

/* Private macro **********************************************************/

/* Private typedef ********************************************************/

/* Private variables ******************************************************/

/* Private function prototypes ********************************************/

/* External variables *****************************************************/

/* External functions *****************************************************/

/**
 * @brief   ADC configuration
 *
 * @param   None
 *
 * @retval  None
 */
void ADC_Config(void)
{
    DDL_GPIO_InitTypeDef GPIO_InitStruct = {0U};
    DDL_ADC_InitTypeDef ADC_InitStruct = {0U};
    DDL_ADC_REG_InitTypeDef ADC_REG_InitStruct = {0U};

    DDL_SCU_Unlock();
    DDL_SCU_EnableAHBPeripheralClock(DDL_SCU_AHB_PERIPHERAL_GPIOB);
    DDL_SCU_EnableAPBPeripheralClock(DDL_SCU_APB_PERIPHERAL_ADC);
    DDL_SCU_Lock();

    /* Configure the ADC pin */
    GPIO_InitStruct.Pin = DDL_GPIO_PIN_1;
    GPIO_InitStruct.Mode = DDL_GPIO_MODE_ANALOG;
    GPIO_InitStruct.Drive = DDL_GPIO_DRIVE_LOW;
    GPIO_InitStruct.OutputType = DDL_GPIO_OUTPUT_PUSHPULL;
    GPIO_InitStruct.InputEnable = DDL_GPIO_INPUT_ENABLE;
    GPIO_InitStruct.InputType = DDL_GPIO_INPUT_TYPE_SCHMITT;
    GPIO_InitStruct.Pull = DDL_GPIO_PULL_UP;
    GPIO_InitStruct.Alternate = DDL_GPIO_AF_0;
    DDL_GPIO_LockKey(GPIOB, DDL_GPIO_LOCK_DISABLE);
    DDL_GPIO_Init(GPIOB, &GPIO_InitStruct);
    DDL_GPIO_LockKey(GPIOB, DDL_GPIO_LOCK_ENABLE);

    /* Set ADC Prescaler value */
    DDL_SCU_Unlock();
    DDL_SCU_SetADCClkDiv(DDL_SCU_ADCCLK_DIVISION_2);
    DDL_SCU_Lock();

    /* Set ADC configuration, must be called after ADC enable */
    DDL_ADC_Enable(ADC);
    while (!DDL_ADC_IsActiveFlag_RDY(ADC))
    {
    }

    DDL_ADC_StructInit(&ADC_InitStruct);
    ADC_InitStruct.DataAlignment = DDL_ADC_ALIGNMENT_RIGHT;
    DDL_ADC_Init(ADC, &ADC_InitStruct);

    DDL_ADC_REG_StructInit(&ADC_REG_InitStruct);
    ADC_REG_InitStruct.TriggerSource = DDL_ADC_REG_TRIG_SOFTWARE;
    ADC_REG_InitStruct.TriggerEdge = DDL_ADC_REG_TRIG_EXTEDGE_RISING;
    ADC_REG_InitStruct.SequencerLength = DDL_ADC_REG_SEQ_SCAN_DISABLE;
    ADC_REG_InitStruct.SequencerDiscont = DDL_ADC_REG_SEQ_DISCONT_DISABLE;
    ADC_REG_InitStruct.ContinuousMode = DDL_ADC_REG_CONV_CONTINUOUS;
    ADC_REG_InitStruct.DMATransfer = DDL_ADC_REG_DMA_TRANSFER_DISABLE;
    ADC_REG_InitStruct.FastChannelSamplingTime = DDL_ADC_SAMPLINGTIME_FAST_256CYCLES;
    ADC_REG_InitStruct.SlowChannelSamplingTime = DDL_ADC_SAMPLINGTIME_SLOW_256CYCLES;
    ADC_REG_InitStruct.Overrun = DDL_ADC_OVERMODE_KEEP;
    DDL_ADC_REG_Init(ADC, &ADC_REG_InitStruct);

    /* Configure for the selected ADC regular channel */
    DDL_ADC_REG_SetSequencerRanks(ADC, DDL_ADC_REG_RANK_1, DDL_ADC_CHANNEL_4);

    DDL_ADC_ClearFlag_EOC(ADC);
    DDL_ADC_ClearFlag_EOS(ADC);
    DDL_ADC_ClearFlag_OVR(ADC);
    DDL_ADC_EnableIT_EOC(ADC);
    DDL_ADC_EnableIT_EOS(ADC);
    DDL_ADC_EnableIT_OVR(ADC);

    /* Enable and set ADC Interrupt priority */
    NVIC_SetPriority((IRQn_Type)(ADC_IRQn),
                     NVIC_EncodePriority(NVIC_GetPriorityGrouping(), 0U, 0U));
    NVIC_EnableIRQ((IRQn_Type)(ADC_IRQn));
}
