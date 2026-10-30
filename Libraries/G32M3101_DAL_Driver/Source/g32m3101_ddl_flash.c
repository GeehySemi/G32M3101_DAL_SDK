/**
 *
  * @file        g32m3101_ddl_flash.c
  *
  * @brief       FLASH DDL module driver.
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
 * Copyright (C) 2025 Geehy Semiconductor.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 *
 */
#if defined(USE_FULL_DDL_DRIVER)

/* Includes ------------------------------------------------------------------*/
#include "g32m3101_ddl_flash.h"
#include "g32m3101_ddl_scu.h"
#include "g32m3101_ddl_bus.h"

#ifdef USE_FULL_ASSERT
#include "g32_assert.h"
#else
#define ASSERT_PARAM(_PARAM_) ((void)0U)
#endif /* USE_FULL_ASSERT */

/** @addtogroup G32M3101_DDL_Driver
 * @{
 */

#if defined(FLASH)

/** @addtogroup FLASH_DDL
 * @{
 */

/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private constants ---------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
static ErrorStatus FLASH_WaitNotBusy(uint32_t Timeout);

/**
  * @brief  Wait until BUSYFLG clears or OPENDFLG sets, with timeout.
  * @note   User manual Ch3: poll BUSYFLG==0 or OPENDFLG==1.
  */
static ErrorStatus FLASH_WaitNotBusy(uint32_t Timeout)
{
  while (DDL_FLASH_IsActiveFlag_BUSY() != 0U)
  {
    if (DDL_FLASH_IsActiveFlag_OPE() != 0U)
    {
      break;
    }
    if (Timeout == 0U)
    {
      return ERROR;
    }
    Timeout--;
  }

  return SUCCESS;
}

/* Exported functions --------------------------------------------------------*/
/** @addtogroup FLASH_DDL_Exported_Functions
 * @{
 */

/** @addtogroup FLASH_DDL_EF_Init
 * @{
 */

/**
 * @brief  De-initialize FLASH registers (Registers restored to their default values).
 * @retval An ErrorStatus enumeration value:
 *          - SUCCESS: FLASH de-initialize success
 */
ErrorStatus DDL_FLASH_DeInit(void)
{
    ErrorStatus status = SUCCESS;

    DDL_SCU_Unlock();

    DDL_AHB_GRP1_ForceReset(DDL_AHB_GRP1_PERIPH_FLASH);
    DDL_AHB_GRP1_ReleaseReset(DDL_AHB_GRP1_PERIPH_FLASH);

    DDL_SCU_Lock();

    return (status);
}

/**
 * @brief  Flash write.
 * @note   Use DDL_FLASH_RKEY_Unlock to unlock the registers before writing.
 * @note   After writing, MKEY is still unlocked.
 *         Can use DDL_FLASH_MKEY_Lock to lock the flash.
 * @note   On busy-wait timeout, FLASH may still be busy and OPERATE may remain
 *         non-read (CR is not writable while BUSY). Wait until BUSY clears, then
 *         set OPERATE to read, or call this API again (entry waits then resets to read).
 * @param  addr The address of data to download
 * @param  size The size of data to download
 * @param  buf  Data to download
 * @retval An ErrorStatus enumeration value:
 *          - SUCCESS: FLASH write success
 *          - ERROR: FLASH write error
 */
ErrorStatus DDL_FLASH_Write(uint32_t addr, uint8_t *buf, uint32_t size)
{
    ErrorStatus status = SUCCESS;

    if ((size == 0U) || ((size & 3U) != 0U) || (buf == NULL) || ((addr & 3U) != 0U))
    {
      return ERROR;
    }

    status = FLASH_WaitNotBusy(DDL_FLASH_TIMEOUT_VALUE);
    if (status != SUCCESS)
    {
        return ERROR;
    }

    /* Reset operation mode */
    DDL_FLASH_SetOperationMode(DDL_FLASH_OPERATE_READ);

    DDL_FLASH_MKEY_Unlock();

    DDL_FLASH_SetOperationMode(DDL_FLASH_OPERATE_WRITE);

    /* word alignment */
    size &= ~3;

    while (size)
    {
        (*(uint32_t *)(addr)) = *(uint32_t *)buf;

        status = FLASH_WaitNotBusy(DDL_FLASH_TIMEOUT_VALUE);
        if (status != SUCCESS)
        {
            return ERROR;
        }

        if (DDL_FLASH_IsActiveFlag_KEY() ||
            DDL_FLASH_IsActiveFlag_RPT() ||
            DDL_FLASH_IsActiveFlag_LSIE())
        {
            DDL_FLASH_ClearFlag_KEY();
            DDL_FLASH_ClearFlag_RPT();
            DDL_FLASH_ClearFlag_LSIE();
            DDL_FLASH_ClearFlag_OPE();
            DDL_FLASH_SetOperationMode(DDL_FLASH_OPERATE_READ);
            return ERROR;
        }

        DDL_FLASH_ClearFlag_OPE();

        addr += 4;
        buf += 4;
        size -= 4;
    }

    DDL_FLASH_SetOperationMode(DDL_FLASH_OPERATE_READ);
    return (status);
}

/**
 * @brief  Flash erase chip.
 * @note   Use DDL_FLASH_RKEY_Unlock to unlock the registers before erasing.
 * @note   After erasing, MKEY is still unlocked.
 *         Can use DDL_FLASH_MKEY_Lock to lock the flash.
 * @note   On busy-wait timeout, FLASH may still be busy and OPERATE may remain
 *         non-read (CR is not writable while BUSY). Wait until BUSY clears, then
 *         set OPERATE to read, or call this API again (entry waits then resets to read).
 * @retval An ErrorStatus enumeration value:
 *          - SUCCESS: FLASH erase chip success
 *          - ERROR: FLASH erase chip error
 */
ErrorStatus DDL_FLASH_EraseChip(void)
{
    ErrorStatus status = SUCCESS;

    status = FLASH_WaitNotBusy(DDL_FLASH_TIMEOUT_VALUE);
    if (status != SUCCESS)
    {
        return ERROR;
    }

    /* Reset operation mode */
    DDL_FLASH_SetOperationMode(DDL_FLASH_OPERATE_READ);

    DDL_FLASH_MKEY_Unlock();

    DDL_FLASH_SetOperationMode(DDL_FLASH_OPERATE_CHIPERASE);

    *(__IO uint32_t *)(uintptr_t)(FLASH_BASE) = 0xA5A5;

    status = FLASH_WaitNotBusy(DDL_FLASH_TIMEOUT_VALUE);
    if (status != SUCCESS)
    {
        return ERROR;
    }

    if (DDL_FLASH_IsActiveFlag_KEY() ||
        DDL_FLASH_IsActiveFlag_RPT() ||
        DDL_FLASH_IsActiveFlag_LSIE())
    {
        DDL_FLASH_ClearFlag_KEY();
        DDL_FLASH_ClearFlag_RPT();
        DDL_FLASH_ClearFlag_LSIE();
        status = ERROR;
    }

    DDL_FLASH_ClearFlag_OPE();

    DDL_FLASH_SetOperationMode(DDL_FLASH_OPERATE_READ);
    return (status);
}

/**
 * @brief  Flash erase sector.
 * @note   Use DDL_FLASH_RKEY_Unlock to unlock the registers before erasing.
 * @note   After erasing, MKEY is still unlocked.
 *         Can use DDL_FLASH_MKEY_Lock to lock the flash.
 * @note   On busy-wait timeout, FLASH may still be busy and OPERATE may remain
 *         non-read (CR is not writable while BUSY). Wait until BUSY clears, then
 *         set OPERATE to read, or call this API again (entry waits then resets to read).
 * @param  addr   The address of data to erase
 * @retval An ErrorStatus enumeration value:
 *          - SUCCESS: FLASH erase sector success
 *          - ERROR: FLASH erase sector error
 */
ErrorStatus DDL_FLASH_EraseSector(uint32_t addr)
{
    ErrorStatus status = SUCCESS;

    status = FLASH_WaitNotBusy(DDL_FLASH_TIMEOUT_VALUE);
    if (status != SUCCESS)
    {
        return ERROR;
    }

    /* Reset operation mode */
    DDL_FLASH_SetOperationMode(DDL_FLASH_OPERATE_READ);

    DDL_FLASH_MKEY_Unlock();

    DDL_FLASH_SetOperationMode(DDL_FLASH_OPERATE_SECTORERASE);

    *(uint32_t *)(addr) = 0xA5A5;

    status = FLASH_WaitNotBusy(DDL_FLASH_TIMEOUT_VALUE);
    if (status != SUCCESS)
    {
        return ERROR;
    }

    if (DDL_FLASH_IsActiveFlag_KEY() ||
        DDL_FLASH_IsActiveFlag_RPT() ||
        DDL_FLASH_IsActiveFlag_LSIE())
    {
        DDL_FLASH_ClearFlag_KEY();
        DDL_FLASH_ClearFlag_RPT();
        DDL_FLASH_ClearFlag_LSIE();
        status = ERROR;
    }

    DDL_FLASH_ClearFlag_OPE();

    DDL_FLASH_SetOperationMode(DDL_FLASH_OPERATE_READ);
    return (status);
}

/**
 * @}
 */

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

#endif /* USE_FULL_DDL_DRIVER */
