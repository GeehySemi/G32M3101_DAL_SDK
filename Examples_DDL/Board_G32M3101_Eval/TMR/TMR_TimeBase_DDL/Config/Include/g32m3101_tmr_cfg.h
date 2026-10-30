/**
 * @file        g32m3101_tmr_cfg.h
 *
 * @brief       This file provides configuration support for TMR
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
#ifndef G32M3101_TMR_CFG_H
#define G32M3101_TMR_CFG_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ***************************************************************/
#include "g32m3101_ddl_atmr.h"
#include "g32m3101_ddl_scu.h"

/* Exported macro *********************************************************/

/* Exported typedef *******************************************************/

/* Exported function prototypes *******************************************/
void ATMR_Config(void);

#ifdef __cplusplus
}
#endif

#endif /* G32M3101_TMR_CFG_H */
