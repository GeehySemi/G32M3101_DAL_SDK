/**
  *
  * @file        g32m3101_ddl_flash.h
  *
  * @brief       Header file of FLASH DDL module.
  *
  * @version     V1.0.2
  *
  * @date        2026-10-19
  *
  * @attention
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *
  * 1. Redistributions of source code must retain the above copyright notice,
  *    this list of conditions and the following disclaimer.
  * 2. Redistributions in binary form must reproduce the above copyright notice,
  *    this list of conditions and the following disclaimer in the documentation
  *    and/or other materials provided with the distribution.
  * 3. Neither the name of the copyright holder nor the names of its contributors
  *    may be used to endorse or promote products derived from this software without
  *    specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
  * IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
  * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
  * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
  * OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  * The original code has been modified by Geehy Semiconductor.
  *
  * Copyright (c) 2016 STMicroelectronics.
  * Copyright (C) 2026 Geehy Semiconductor.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef G32M3101_DDL_FLASH_H
#define G32M3101_DDL_FLASH_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "g32m3xxx.h"
#include "Legacy/g32_ddl_legacy.h"

/** @addtogroup G32M3101_DDL_Driver
  * @{
  */

#if defined(FLASH)

/** @defgroup FLASH_DDL FLASH
  * @{
  */

/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private constants ---------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/
/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/** @defgroup FLASH_DDL_Exported_Macros FLASH Exported Macros
  * @{
  */

/** @defgroup FLASH_DDL_EF_KEY FLASH KEY
 * @{
 */
#define DDL_FLASH_RPT_KEY_UNLOCK          (0x3399AA55)
#define DDL_FLASH_MFLASH_KEY_UNLOCK       (0xABCD6789)
#define DDL_FLASH_NVR5_KEY_UNLOCK         (0x33AADD55)
#define DDL_FLASH_RPT_KEY_LOCK            (0x00000000)
#define DDL_FLASH_MFLASH_KEY_LOCK         (0x00000000)
#define DDL_FLASH_NVR_KEY_LOCK            (0x00000000)
/**
 * @}
 */

/** @defgroup FLASH_DDL_EF_FORCE_OPTLOAD FLASH Force Optload
 * @{
 */
#define DDL_FLASH_FORCE_OPTLOAD           (0xA5A58000)
/**
 * @}
 */

/** @defgroup FLASH_DDL_EF_READONLY FLASH READONLY
 * @{
 */
#define DDL_FLASH_READONLY                (FLASH_CR_READONLY)

/**
 * @}
 */

/** @defgroup FLASH_DDL_EF_LATENCY FLASH LATENCY
 * @{
 */
#define DDL_FLASH_LATENCY0                (0x00000000)
#define DDL_FLASH_LATENCY1                (FLASH_CR_LATENCY_1WS)
#define DDL_FLASH_LATENCY2                (FLASH_CR_LATENCY_2WS)
#define DDL_FLASH_LATENCY3                (FLASH_CR_LATENCY_3WS)
/**
 * @}
 */

/** @defgroup FLASH_DDL_EF_OPERATE FLASH OPERATE
 * @{
 */
#define DDL_FLASH_OPERATE_READ            (0x00000000)
#define DDL_FLASH_OPERATE_SECTORERASE     (FLASH_CR_OPERATE_0)
#define DDL_FLASH_OPERATE_CHIPERASE       (FLASH_CR_OPERATE_1)
#define DDL_FLASH_OPERATE_WRITE           (FLASH_CR_OPERATE_Msk)
/**
 * @}
 */

/** @defgroup FLASH_DDL_EF_ERROR FLASH ERROR
 * @{
 */
#define DDL_FLASH_KEY_ERR                 (FLASH_SR_KEYERR)
#define DDL_FLASH_RDPRT_ERR               (FLASH_SR_RPTERR)
#define DDL_FLASH_LSI_ERR                 (FLASH_SR_LSIERR)
#define DDL_FLASH_PG_ERR                  (DDL_FLASH_KEY_ERR | DDL_FLASH_RDPRT_ERR | DDL_FLASH_LSI_ERR)
/**
 * @}
 */

/** @defgroup FLASH_DDL_EF_TIMEOUT FLASH busy-wait loop limits
 * @{
 */
#ifndef DDL_FLASH_TIMEOUT_VALUE
#define DDL_FLASH_TIMEOUT_VALUE          (2000000UL)
#endif
#ifndef DDL_FLASH_TIMEOUT_PROGRAM
#define DDL_FLASH_TIMEOUT_PROGRAM        (200000UL)
#endif
#ifndef DDL_FLASH_TIMEOUT_ERASE_SECTOR
#define DDL_FLASH_TIMEOUT_ERASE_SECTOR   (800000UL)
#endif
#ifndef DDL_FLASH_TIMEOUT_ERASE_CHIP
#define DDL_FLASH_TIMEOUT_ERASE_CHIP     (4000000UL)
#endif
/**
 * @}
 */

/** @defgroup FLASH_DDL_EM_WRITE_READ Common Write and read registers Macros
  * @{
  */

/**
  * @brief  Write a value in FLASH register
  * @param  __INSTANCE__ FLASH Instance
  * @param  __REG__ Register to be written
  * @param  __VALUE__ Value to be written in the register
  * @retval None
  */
#define DDL_FLASH_WriteReg(__INSTANCE__, __REG__, __VALUE__) WRITE_REG(__INSTANCE__->__REG__, __VALUE__)

/**
  * @brief  Read a value in FLASH register
  * @param  __INSTANCE__ FLASH Instance
  * @param  __REG__ Register to be read
  * @retval Register value
  */
#define DDL_FLASH_ReadReg(__INSTANCE__, __REG__) READ_REG(__INSTANCE__->__REG__)
/**
  * @}
  */

/**
  * @}
  */


/* Exported functions --------------------------------------------------------*/
/** @defgroup FLASH_DDL_Exported_Functions FLASH Exported Functions
  * @{
  */


/** @defgroup FLASH_DDL_EF FLASH Driver Functions
  * @{
  */

/**
  * @brief  Unlock FLASH RKEY Register.
  */
__STATIC_INLINE void DDL_FLASH_RKEY_Unlock(void)
{
  WRITE_REG(FLASH->RKEY, DDL_FLASH_RPT_KEY_UNLOCK);
}

/**
  * @brief  Lock FLASH RKEY Register.
  */
__STATIC_INLINE void DDL_FLASH_RKEY_Lock(void)
{
  WRITE_REG(FLASH->RKEY, DDL_FLASH_RPT_KEY_LOCK);
}

/**
  * @brief  Get FLASH RKEY Lock Status.
  * @retval 1: RKEY is locked, 0: RKEY is unlocked.
  */
__STATIC_INLINE uint32_t DDL_FLASH_RKEY_IsLocked(void)
{
  return ((uint32_t)(READ_BIT(FLASH->RKEY, FLASH_RKEY_RKEY) == 0U) ? 1UL : 0UL);
}

/**
  * @brief  Unlock FLASH MKEY Register.
  */
__STATIC_INLINE void DDL_FLASH_MKEY_Unlock(void)
{
  WRITE_REG(FLASH->MKEY, DDL_FLASH_MFLASH_KEY_UNLOCK);
}

/**
  * @brief  Lock FLASH MKEY Register.
  */
__STATIC_INLINE void DDL_FLASH_MKEY_Lock(void)
{
  WRITE_REG(FLASH->MKEY, DDL_FLASH_MFLASH_KEY_LOCK);
}

/**
  * @brief  Get FLASH MKEY Lock Status.
  * @retval 1: MKEY is locked, 0: MKEY is unlocked.
  */
__STATIC_INLINE uint32_t DDL_FLASH_MKEY_IsLocked(void)
{
  return ((uint32_t)(READ_BIT(FLASH->MKEY, FLASH_MKEY_MKEY) == 0U) ? 1UL : 0UL);
}

/**
  * @brief  Unlock FLASH NVR5KEY Register.
  */
__STATIC_INLINE void DDL_FLASH_NVR5KEY_Unlock(void)
{
  WRITE_REG(FLASH->NVR5KEY, DDL_FLASH_NVR5_KEY_UNLOCK);
}

/**
  * @brief  Lock FLASH NVR5KEY Register.
  */
__STATIC_INLINE void DDL_FLASH_NVR5KEY_Lock(void)
{
  WRITE_REG(FLASH->NVR5KEY, DDL_FLASH_NVR_KEY_LOCK);
}

/**
  * @brief  Set Flash operation mode.
  * @param  mode This parameter can be one of the following values:
  *         @arg @ref DDL_FLASH_OPERATE_READ
  *         @arg @ref DDL_FLASH_OPERATE_SECTORERASE
  *         @arg @ref DDL_FLASH_OPERATE_CHIPERASE
  *         @arg @ref DDL_FLASH_OPERATE_WRITE
  */
__STATIC_INLINE void DDL_FLASH_SetOperationMode(uint32_t mode)
{
  MODIFY_REG(FLASH->CR, FLASH_CR_OPERATE, mode);
}

/**
  * @brief  Get Flash operation mode.
  * @retval Returned value can be one of the following values:
  *         @arg @ref DDL_FLASH_OPERATE_READ
  *         @arg @ref DDL_FLASH_OPERATE_SECTORERASE
  *         @arg @ref DDL_FLASH_OPERATE_CHIPERASE
  *         @arg @ref DDL_FLASH_OPERATE_WRITE
  */
__STATIC_INLINE uint32_t DDL_FLASH_GetOperationMode(void)
{
  return (uint32_t)(READ_BIT(FLASH->CR, FLASH_CR_OPERATE));
}

/**
  * @brief  Enable Flash readonly.
  */
__STATIC_INLINE void DDL_FLASH_EnableReadOnly(void)
{
  SET_BIT(FLASH->CR, FLASH_CR_READONLY);
}

/**
  * @brief  Disable Flash readonly.
  */
__STATIC_INLINE void DDL_FLASH_DisableReadOnly(void)
{
  CLEAR_BIT(FLASH->CR, FLASH_CR_READONLY);
}

/**
  * @brief  Set Flash Latency.
  * @param  mode This parameter can be one of the following values:
  *         @arg @ref DDL_FLASH_LATENCY0
  *         @arg @ref DDL_FLASH_LATENCY1
  *         @arg @ref DDL_FLASH_LATENCY2
  *         @arg @ref DDL_FLASH_LATENCY3
  */
__STATIC_INLINE void DDL_FLASH_SetLatency(uint32_t latency)
{
  MODIFY_REG(FLASH->CR, FLASH_CR_LATENCY, latency);
}

/**
  * @brief  Get Flash Latency.
  * @retval Returned value can be one of the following values:
  *         @arg @ref DDL_FLASH_LATENCY0
  *         @arg @ref DDL_FLASH_LATENCY1
  *         @arg @ref DDL_FLASH_LATENCY2
  *         @arg @ref DDL_FLASH_LATENCY3
  */
__STATIC_INLINE uint32_t DDL_FLASH_GetLatency(void)
{
  return (uint32_t)(READ_BIT(FLASH->CR, FLASH_CR_LATENCY));
}

/**
  * @brief  Enable Flash Force Optload.
  */
__STATIC_INLINE void DDL_FLASH_EnableForceOptload(void)
{
  SET_BIT(FLASH->CR, DDL_FLASH_FORCE_OPTLOAD);
}

/**
  * @brief  Enable Flash Operation End Interrupt.
  */
__STATIC_INLINE void DDL_FLASH_EnableIT_OPE(void)
{
  SET_BIT(FLASH->ER, FLASH_ER_OPEIE);
}

/**
  * @brief  Disable Flash Operation End Interrupt.
  */
__STATIC_INLINE void DDL_FLASH_DisableIT_OPE(void)
{
  CLEAR_BIT(FLASH->ER, FLASH_ER_OPEIE);
}

/**
  * @brief  Check Flash Operation End Interrupt is enabled or disabled.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_FLASH_IsEnabledIT_OPE(void)
{
  return (uint32_t)(READ_BIT(FLASH->ER, FLASH_ER_OPEIE) == (FLASH_ER_OPEIE));
}

/**
  * @brief  Enable Flash KEY Error Interrupt.
  */
__STATIC_INLINE void DDL_FLASH_EnableIT_KEY(void)
{
  SET_BIT(FLASH->ER, FLASH_ER_KEYIE);
}

/**
  * @brief  Disable Flash KEY Error Interrupt.
  */
__STATIC_INLINE void DDL_FLASH_DisableIT_KEY(void)
{
  CLEAR_BIT(FLASH->ER, FLASH_ER_KEYIE);
}

/**
  * @brief  Check Flash KEY Error Interrupt is enabled or disabled.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_FLASH_IsEnabledIT_KEY(void)
{
  return (uint32_t)(READ_BIT(FLASH->ER, FLASH_ER_KEYIE) == (FLASH_ER_KEYIE));
}

/**
  * @brief  Enable Flash Read/Write Protection Interrupt.
  */
__STATIC_INLINE void DDL_FLASH_EnableIT_RPT(void)
{
  SET_BIT(FLASH->ER, FLASH_ER_RPTIE);
}

/**
  * @brief  Disable Flash Read/Write Protection Interrupt.
  */
__STATIC_INLINE void DDL_FLASH_DisableIT_RPT(void)
{
  CLEAR_BIT(FLASH->ER, FLASH_ER_RPTIE);
}

/**
  * @brief  Check Flash Read/Write Protection Interrupt is enabled or disabled.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_FLASH_IsEnabledIT_RPT(void)
{
  return (uint32_t)(READ_BIT(FLASH->ER, FLASH_ER_RPTIE) == (FLASH_ER_RPTIE));
}

/**
  * @brief  Enable Flash LSI Error Interrupt.
  */
__STATIC_INLINE void DDL_FLASH_EnableIT_LSIE(void)
{
  SET_BIT(FLASH->ER, FLASH_ER_LSIIE);
}

/**
  * @brief  Disable Flash LSI Error Interrupt.
  */
__STATIC_INLINE void DDL_FLASH_DisableIT_LSIE(void)
{
  CLEAR_BIT(FLASH->ER, FLASH_ER_LSIIE);
}

/**
  * @brief  Check Flash LSI Error Interrupt is enabled or disabled.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_FLASH_IsEnabledIT_LSIE(void)
{
  return (uint32_t)(READ_BIT(FLASH->ER, FLASH_ER_LSIIE) == (FLASH_ER_LSIIE));
}

/**
  * @brief  Check if Flash Erase/Program BUSY Status.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_FLASH_IsActiveFlag_BUSY(void)
{
  return (uint32_t)(READ_BIT(FLASH->SR, FLASH_SR_BUSY) == (FLASH_SR_BUSY));
}

/**
  * @brief  Check if Flash Operation End Interrupt Flag Is Occured.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_FLASH_IsActiveFlag_OPE(void)
{
  return (uint32_t)(READ_BIT(FLASH->SR, FLASH_SR_OPENDR) == (FLASH_SR_OPENDR));
}

/**
  * @brief  Clear Flash Operation End Interrupt Flag.
  * @retval None.
  */
__STATIC_INLINE void DDL_FLASH_ClearFlag_OPE(void)
{
  WRITE_REG(FLASH->SR, FLASH_SR_OPENDR);
}

/**
  * @brief  Check if Flash KEY Error Interrupt Flag Is Occured.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_FLASH_IsActiveFlag_KEY(void)
{
  return (uint32_t)(READ_BIT(FLASH->SR, FLASH_SR_KEYERR) == (FLASH_SR_KEYERR));
}

/**
  * @brief  Clear Flash KEY Error Interrupt Flag.
  * @retval None.
  */
__STATIC_INLINE void DDL_FLASH_ClearFlag_KEY(void)
{
  WRITE_REG(FLASH->SR, FLASH_SR_KEYERR);
}

/**
  * @brief  Check if Flash Read And Write Protection Interrupt Flag Is Occured.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_FLASH_IsActiveFlag_RPT(void)
{
  return (uint32_t)(READ_BIT(FLASH->SR, FLASH_SR_RPTERR) == (FLASH_SR_RPTERR));
}

/**
  * @brief  Clear Flash Read And Write Protection Interrupt Flag.
  * @retval None.
  */
__STATIC_INLINE void DDL_FLASH_ClearFlag_RPT(void)
{
  WRITE_REG(FLASH->SR, FLASH_SR_RPTERR);
}

/**
  * @brief  Check if LSI Error Interrupt Flag Is Occured.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_FLASH_IsActiveFlag_LSIE(void)
{
  return (uint32_t)((READ_BIT(FLASH->SR, FLASH_SR_LSIERR) == (FLASH_SR_LSIERR)) ? 1UL : 0UL);
}

/**
  * @brief  Clear LSI Error Interrupt Flag.
  * @retval None.
  */
__STATIC_INLINE void DDL_FLASH_ClearFlag_LSIE(void)
{
  WRITE_REG(FLASH->SR, FLASH_SR_LSIERR);
}

/**
  * @}
  */

#if defined(USE_FULL_DDL_DRIVER)
/** @defgroup FLASH_DDL_EF_Init Initialization and de-initialization functions
  * @{
  */

ErrorStatus DDL_FLASH_DeInit(void);
ErrorStatus DDL_FLASH_Write(uint32_t addr, uint8_t *buf, uint32_t size);
ErrorStatus DDL_FLASH_EraseChip(void);
ErrorStatus DDL_FLASH_EraseSector(uint32_t addr);

/**
  * @}
  */
#endif /* USE_FULL_DDL_DRIVER */

/**
  * @}
  */

/**
  * @}
  */

#endif /* FLASH */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* G32M3101_DDL_FLASH_H */
