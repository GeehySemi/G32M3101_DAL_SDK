/**
 * @file        g32m3101_spi_cfg.h
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

/* Define to prevent recursive inclusion */
#ifndef G32M3101_SPI_CFG_H
#define G32M3101_SPI_CFG_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ***************************************************************/
#include "g32m3101_ddl_spi.h"
#include "g32m3101_ddl_gpio.h"
#include "g32m3101_ddl_scu.h"

/* Exported macro *********************************************************/
#define SPI_MASTER 1
#define SPI_SLAVER 0

#define SPI_CS_PORT GPIOB
#define SPI_CS_PIN  DDL_GPIO_PIN_9
#define SPI_CS_LOW                                                                                 \
    DDL_GPIO_LockKey(SPI_CS_PORT, DDL_GPIO_LOCK_DISABLE);                                          \
    DDL_GPIO_ResetOutputPin(SPI_CS_PORT, SPI_CS_PIN);                                              \
    DDL_GPIO_LockKey(SPI_CS_PORT, DDL_GPIO_LOCK_ENABLE);

#define SPI_CS_HIGH                                                                                \
    DDL_GPIO_LockKey(SPI_CS_PORT, DDL_GPIO_LOCK_DISABLE);                                          \
    DDL_GPIO_SetOutputPin(SPI_CS_PORT, SPI_CS_PIN);                                                \
    DDL_GPIO_LockKey(SPI_CS_PORT, DDL_GPIO_LOCK_ENABLE);

/* Exported typedef *******************************************************/

/* Exported function prototypes *******************************************/
void SPI_Config(void);

#ifdef __cplusplus
}
#endif

#endif /* G32M3101_SPI_CFG_H */
