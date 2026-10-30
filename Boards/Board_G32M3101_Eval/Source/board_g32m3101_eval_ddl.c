/**
 * @file        board_g32m3101_eval_ddl.c
 *
 * @brief       This file provides firmware functions to manage Leds and key buttons
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
#include "board_g32m3101_eval_ddl.h"

#if defined(BOARD_G32M3101_EVAL)

/* Private includes *******************************************************/

/* Private macro **********************************************************/
#define LED_NUM    1U
#define BUTTON_NUM 1U

/* Private typedef ********************************************************/

/* Private variables ******************************************************/
GPIO_TypeDef *LED_PORT[LED_NUM] = {LED2_GPIO_PORT};
const uint16_t LED_PIN[LED_NUM] = {LED2_PIN};

GPIO_TypeDef *BUTTON_PORT[BUTTON_NUM] = {KEY1_BUTTON_GPIO_PORT};
const uint16_t BUTTON_PIN[BUTTON_NUM] = {KEY1_BUTTON_PIN};
const IRQn_Type BUTTON_IRQn[BUTTON_NUM] = {KEY1_BUTTON_EINT_IRQ_NUM};

/* Private function prototypes ********************************************/

/* External variables *****************************************************/

/* External functions *****************************************************/

/**
 * @brief   Board LED configuration
 *
 * @param   led: Specifies the Led to be configured
 *              This parameter can be one of following parameters:
 *              @arg LED2
 *
 * @retval  BSP status
 */
uint32_t BOARD_LED_Config(BOARD_LED_T led)
{
    uint32_t status = 0U;

    DDL_GPIO_InitTypeDef GPIO_InitStruct = {0U};

    /* Unlock SCU register */
    DDL_SCU_Unlock();

    switch (led)
    {
        case LED2:
            LED2_GPIO_CLK_ENABLE();
            break;
        default:
            break;
    }

    /* Lock SCU register */
    DDL_SCU_Lock();

    /* Configure the LED pin */
    GPIO_InitStruct.Pin = LED_PIN[led];
    GPIO_InitStruct.Mode = DDL_GPIO_MODE_OUTPUT;
    GPIO_InitStruct.OutputType = DDL_GPIO_OUTPUT_PUSHPULL;
    GPIO_InitStruct.Pull = DDL_GPIO_PULL_UP;
    GPIO_InitStruct.Drive = DDL_GPIO_DRIVE_LOW;

    DDL_GPIO_LockKey(LED_PORT[led], DDL_GPIO_LOCK_DISABLE);
    DDL_GPIO_Init(LED_PORT[led], &GPIO_InitStruct);
    DDL_GPIO_LockKey(LED_PORT[led], DDL_GPIO_LOCK_ENABLE);

    DDL_GPIO_LockKey(LED_PORT[led], DDL_GPIO_LOCK_DISABLE);
    DDL_GPIO_SetOutputPin(LED_PORT[led], LED_PIN[led]);
    DDL_GPIO_LockKey(LED_PORT[led], DDL_GPIO_LOCK_ENABLE);

    return status;
}

/**
 * @brief   Board button configuration
 *
 * @param   button: Specifies the button to be configured
 *              This parameter can be one of following parameters:
 *              @arg BUTTON_KEY1: Key1 Push Button
 *
 * @param       Button_Mode: Specifies Button mode.
 *              This parameter can be one of following parameters:
 *              @arg BUTTON_MODE_GPIO: Button will be used as simple IO
 *              @arg BUTTON_MODE_EINT: Button will be connected to EINT line
 *                   with interrupt generation capability
 *
 * @retval  BSP status
 */
uint32_t BOARD_BUTTON_Config(BOARD_BUTTON_T button, BOARD_BUTTON_MODE_T mode)
{
    uint32_t status = 0U;

    DDL_GPIO_InitTypeDef GPIO_InitStruct = {0u};
    DDL_EINT_InitTypeDef EINT_InitStruct = {0U};

    /* Unlock SCU register */
    DDL_SCU_Unlock();

    switch (button)
    {
        case BUTTON_KEY1:
            KEY1_BUTTON_GPIO_CLK_ENABLE();
            break;
        default:
            break;
    }

    /* Lock SCU register */
    DDL_SCU_Lock();

    if (mode == BUTTON_MODE_GPIO)
    {
        /* Configure the BUTTON pin */
        GPIO_InitStruct.Pin = BUTTON_PIN[button];
        GPIO_InitStruct.Mode = DDL_GPIO_MODE_INPUT;
        GPIO_InitStruct.InputEnable = DDL_GPIO_INPUT_ENABLE;
        GPIO_InitStruct.Pull = DDL_GPIO_PULL_UP;
        GPIO_InitStruct.Drive = DDL_GPIO_DRIVE_HIGH;

        DDL_GPIO_LockKey(BUTTON_PORT[button], DDL_GPIO_LOCK_DISABLE);
        DDL_GPIO_Init(BUTTON_PORT[button], &GPIO_InitStruct);
        DDL_GPIO_LockKey(BUTTON_PORT[button], DDL_GPIO_LOCK_ENABLE);
    }

    if (mode == BUTTON_MODE_EINT)
    {
        /* Configure the BUTTON pin */
        GPIO_InitStruct.Pin = BUTTON_PIN[button];
        GPIO_InitStruct.Mode = DDL_GPIO_MODE_INPUT;
        GPIO_InitStruct.InputEnable = DDL_GPIO_INPUT_ENABLE;
        GPIO_InitStruct.Pull = DDL_GPIO_PULL_UP;

        DDL_GPIO_LockKey(BUTTON_PORT[button], DDL_GPIO_LOCK_DISABLE);
        DDL_GPIO_Init(BUTTON_PORT[button], &GPIO_InitStruct);
        DDL_GPIO_LockKey(BUTTON_PORT[button], DDL_GPIO_LOCK_ENABLE);

        /*--------------------- EINT Mode Configuration ------------------------*/
        EINT_InitStruct.Line_0_31 = DDL_EINT_LINE_10;
        EINT_InitStruct.LineCommand = ENABLE;
        EINT_InitStruct.Mode = DDL_EINT_MODE_IT;
        EINT_InitStruct.Trigger = DDL_EINT_TRIGGER_FALLING;

        DDL_EINT_SetEINTSource(DDL_EINT_SOURCE_PORTB, DDL_EINT_LINE_10);
        DDL_EINT_Init(&EINT_InitStruct);

        /* Enable and set Button EINT Interrupt to the lowest priority */
        NVIC_SetPriority((IRQn_Type)(BUTTON_IRQn[button]),
                         NVIC_EncodePriority(NVIC_GetPriorityGrouping(), 3U, 0U));
        NVIC_EnableIRQ((IRQn_Type)(BUTTON_IRQn[button]));
    }

    return status;
}

/**
 * @brief   Turn on the selected LED
 *
 * @param   led: Specifies the Led to be configured
 *              This parameter can be one of following parameters:
 *              @arg LED2
 *
 * @retval  None
 */
void BOARD_LED_On(BOARD_LED_T led)
{
    DDL_GPIO_LockKey(LED_PORT[led], DDL_GPIO_LOCK_DISABLE);
    DDL_GPIO_ResetOutputPin(LED_PORT[led], LED_PIN[led]);
    DDL_GPIO_LockKey(LED_PORT[led], DDL_GPIO_LOCK_ENABLE);
}

/**
 * @brief   Turn off the selected LED
 *
 * @param   led: Specifies the Led to be configured
 *              This parameter can be one of following parameters:
 *              @arg LED2
 *
 * @retval  None
 */
void BOARD_LED_Off(BOARD_LED_T led)
{
    DDL_GPIO_LockKey(LED_PORT[led], DDL_GPIO_LOCK_DISABLE);
    DDL_GPIO_SetOutputPin(LED_PORT[led], LED_PIN[led]);
    DDL_GPIO_LockKey(LED_PORT[led], DDL_GPIO_LOCK_ENABLE);
}

/**
 * @brief   Toggles the selected LED
 *
 * @param   led: Specifies the Led to be configured
 *              This parameter can be one of following parameters:
 *              @arg LED2
 *
 * @retval  None
 */
void BOARD_LED_Toggle(BOARD_LED_T led)
{
    DDL_GPIO_LockKey(LED_PORT[led], DDL_GPIO_LOCK_DISABLE);
    DDL_GPIO_TogglePin(LED_PORT[led], LED_PIN[led]);
    DDL_GPIO_LockKey(LED_PORT[led], DDL_GPIO_LOCK_ENABLE);
}

/**
 * @brief   Returns the selected button state
 *
 * @param   button: Specifies the button to be configured
 *              This parameter can be one of following parameters:
 *              @arg BUTTON_KEY1: Key1 Push Button
 *
 * @retval  0 if the button is pressed, 1 if the button is not pressed
 */
uint32_t BOARD_BUTTON_GetState(BOARD_BUTTON_T button)
{
    uint32_t bitstatus;

    if ((DDL_GPIO_ReadInputPort(BUTTON_PORT[button]) & BUTTON_PIN[button]) != 0U)
    {
        bitstatus = 1U;
    }
    else
    {
        bitstatus = 0U;
    }

    return bitstatus;
}

#endif /* BOARD_G32M3101_EVAL */
