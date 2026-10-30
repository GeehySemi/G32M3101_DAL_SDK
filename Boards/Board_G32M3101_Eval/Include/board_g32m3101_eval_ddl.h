/**
 * @file        board_g32m3101_eval_ddl.h
 *
 * @brief       This file contains definitions for G32M3101_EVAL's Leds, push-buttons hardware
 * resources
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

/* Define to prevent recursive inclusion */
#ifndef BOARD_G32M3101_EVAL_DDL_H
#define BOARD_G32M3101_EVAL_DDL_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ***************************************************************/
#include "g32m3101_ddl_scu.h"
#include "g32m3101_ddl_gpio.h"
#include "g32m3101_ddl_eint.h"

/* Exported macro *********************************************************/

/**
 * @brief LED2
 */
#define LED2_PIN                DDL_GPIO_PIN_0
#define LED2_GPIO_PORT          GPIOB
#define LED2_GPIO_CLK_ENABLE()  DDL_SCU_EnableAHBPeripheralClock(DDL_SCU_AHB_PERIPHERAL_GPIOB)
#define LED2_GPIO_CLK_DISABLE() DDL_SCU_DisableAHBPeripheralClock(DDL_SCU_AHB_PERIPHERAL_GPIOB)

/**
 * @brief Key1 push-button
 */
#define KEY1_BUTTON_PIN               DDL_GPIO_PIN_10
#define KEY1_BUTTON_GPIO_PORT         GPIOB
#define KEY1_BUTTON_GPIO_CLK_ENABLE() DDL_SCU_EnableAHBPeripheralClock(DDL_SCU_AHB_PERIPHERAL_GPIOB)
#define KEY1_BUTTON_GPIO_CLK_DISABLE()                                                             \
    DDL_SCU_DisableAHBPeripheralClock(DDL_SCU_AHB_PERIPHERAL_GPIOB)
#define KEY1_BUTTON_EINT_IRQ_NUM EINT4_13_IRQn

/* Exported typedef *******************************************************/

/**
 * @brief  DAL Status structures definition
 */

/**
 * @brief LED type
 */
typedef enum {
    LED2 = 0U,
} BOARD_LED_T;

/**
 * @brief Button type
 */
typedef enum {
    BUTTON_KEY1 = 0U,
} BOARD_BUTTON_T;

/**
 * @brief Button mode
 */
typedef enum {
    BUTTON_MODE_GPIO = 0U,
    BUTTON_MODE_EINT = 1U
} BOARD_BUTTON_MODE_T;

/* Exported function prototypes *******************************************/

/* Peripheral initialization functions */
uint32_t BOARD_LED_Config(BOARD_LED_T led);
uint32_t BOARD_BUTTON_Config(BOARD_BUTTON_T button, BOARD_BUTTON_MODE_T mode);

/* Peripheral control functions */
void BOARD_LED_On(BOARD_LED_T led);
void BOARD_LED_Off(BOARD_LED_T led);
void BOARD_LED_Toggle(BOARD_LED_T led);
uint32_t BOARD_BUTTON_GetState(BOARD_BUTTON_T button);

#ifdef __cplusplus
}
#endif

#endif /* BOARD_G32M3101_EVAL_DDL_H */
