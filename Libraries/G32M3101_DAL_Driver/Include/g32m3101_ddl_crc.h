/**
  *
  * @file        g32m3101_ddl_crc.h
  *
  * @brief       Header file of CRC DDL module.
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
#ifndef G32M3101_DDL_CRC_H
#define G32M3101_DDL_CRC_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "g32m3xxx.h"
#include "Legacy/g32_ddl_legacy.h"

/** @addtogroup G32M3101_DDL_Driver
  * @{
  */

#if defined(CRC)

/** @defgroup CRC_DDL CRC
  * @{
  */

/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private constants ---------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/** @defgroup CRC_DDL_Exported_Constants CRC Exported Constants
  * @{
  */

/** @defgroup CRC_DDL_EC_SELECT CRC Selection
 * @{
 */
#define DDL_CRC_SELECT_CRC32              (0x00000000UL)                  /*!< CRC calculation Select with CRC32. */
#define DDL_CRC_SELECT_CRC16              (CRC_CTRL_CRCSEL)               /*!< CRC calculation Select with CRC16. */
/**
 * @}
 */

/** @defgroup CRC_DDL_EC_INPUT_FLIP_MODE CRC calculation Input Flip mode
 * @{
 */
#define DDL_CRC_INDATA_REVERSE_NONE       (0x00000000UL)                     /*!< CRC calculation Input Flip mode with none. */
#define DDL_CRC_INDATA_REVERSE_BYTE       (CRC_CTRL_REVI_0)                  /*!< CRC calculation Input Flip mode with BYTE. */
#define DDL_CRC_INDATA_REVERSE_HALFWORD   (CRC_CTRL_REVI_1)                  /*!< CRC calculation Input Flip mode with HALF WORD. */
#define DDL_CRC_INDATA_REVERSE_WORD       (CRC_CTRL_REVI)                    /*!< CRC calculation Input Flip mode with WORD. */
/**
 * @}
 */

/** @defgroup CRC_DDL_EC_OUTPUT_FLIP_MODE CRC calculation Output Flip mode
 * @{
 */
#define DDL_CRC_OUTDATA_REVERSE_DISABLE   (0x00000000UL)                     /*!< Disable CRC calculation Output Flip mode. */
#define DDL_CRC_OUTDATA_REVERSE_ENABLE    (CRC_CTRL_REVO)                    /*!< Enable CRC calculation Output Flip mode. */
/**
 * @}
 */

/**
 * @}
 */

/* Exported macro ------------------------------------------------------------*/
/** @defgroup CRC_DDL_Exported_Macros CRC Exported Macros
  * @{
  */

/** @defgroup CRC_DDL_EM_WRITE_READ Common Write and read registers Macros
  * @{
  */

/**
  * @brief  Write a value in CRC register
  * @param  __INSTANCE__ CRC Instance
  * @param  __REG__ Register to be written
  * @param  __VALUE__ Value to be written in the register
  * @retval None
  */
#define DDL_CRC_WriteReg(__INSTANCE__, __REG__, __VALUE__) WRITE_REG(__INSTANCE__->__REG__, __VALUE__)

/**
  * @brief  Read a value in CRC register
  * @param  __INSTANCE__ CRC Instance
  * @param  __REG__ Register to be read
  * @retval Register value
  */
#define DDL_CRC_ReadReg(__INSTANCE__, __REG__) READ_REG(__INSTANCE__->__REG__)
/**
  * @}
  */

/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/** @defgroup CRC_DDL_Exported_Functions CRC Exported Functions
  * @{
  */

/** @defgroup CRC_DDL_EF_SELECT CRC Selection
  * @{
  */
/**
  * @brief  Set the CRC selection.
  * @param  CRCx CRC Instance.
  * @param  Select This parameter can be one of the following values:
  *         @arg @ref DDL_CRC_SELECT_CRC32
  *         @arg @ref DDL_CRC_SELECT_CRC16
  */
__STATIC_INLINE void DDL_CRC_SetCRCSelect(CRC_TypeDef *CRCx, uint32_t Select)
{
  MODIFY_REG(CRCx->CTRL, CRC_CTRL_CRCSEL, Select);
}

/**
  * @brief  Get the CRC selection.
  * @param  CRCx CRC Instance.
  * @retval Returned value can be one of the following values:
  *         @arg @ref DDL_CRC_SELECT_CRC32
  *         @arg @ref DDL_CRC_SELECT_CRC16
  */
__STATIC_INLINE uint32_t DDL_CRC_GetCRCSelect(CRC_TypeDef *CRCx)
{
  return (uint32_t)(READ_REG(CRCx->CTRL) & CRC_CTRL_CRCSEL);
}
/**
  * @}
  */

/** @defgroup CRC_DDL_EF_OutputToggle CRC calculation Output Flip
  * @{
  */

/**
  * @brief  Configure the reversal of the bit order of the Output data.
  * @param  CRCx CRC Instance.
  * @param  ReverseMode This parameter can be one of the following values:
  *         @arg @ref DDL_CRC_OUTDATA_REVERSE_DISABLE
  *         @arg @ref DDL_CRC_OUTDATA_REVERSE_ENABLE
  */
__STATIC_INLINE void DDL_CRC_SetOutputDataReverseMode(CRC_TypeDef *CRCx, uint32_t ReverseMode)
{
  MODIFY_REG(CRCx->CTRL, CRC_CTRL_REVO, ReverseMode);
}

/**
  * @brief  Get the reversal of the bit order of the Output data.
  * @param  CRCx CRC Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref DDL_CRC_OUTDATA_REVERSE_DISABLE
  *         @arg @ref DDL_CRC_OUTDATA_REVERSE_ENABLE
  */
__STATIC_INLINE uint32_t DDL_CRC_GetOutputDataReverseMode(CRC_TypeDef *CRCx)
{
  return (uint32_t)(READ_BIT(CRCx->CTRL, CRC_CTRL_REVO));
}

/**
  * @brief  Set CRC calculation input flip mode.
  * @param  CRCx CRC Instance.
  * @param  inMode This parameter can be one of the following values:
  *         @arg @ref DDL_CRC_INDATA_REVERSE_NONE
  *         @arg @ref DDL_CRC_INDATA_REVERSE_BYTE
  *         @arg @ref DDL_CRC_INDATA_REVERSE_HALFWORD
  *         @arg @ref DDL_CRC_INDATA_REVERSE_WORD
  */
__STATIC_INLINE void DDL_CRC_SetInputDataReverseMode(CRC_TypeDef *CRCx, uint32_t inMode)
{
  MODIFY_REG(CRCx->CTRL, CRC_CTRL_REVI, inMode);
}

/**
  * @brief  Get CRC calculation input flip mode.
  * @param  CRCx CRC Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref DDL_CRC_INDATA_REVERSE_NONE
  *         @arg @ref DDL_CRC_INDATA_REVERSE_BYTE
  *         @arg @ref DDL_CRC_INDATA_REVERSE_HALFWORD
  *         @arg @ref DDL_CRC_INDATA_REVERSE_WORD
  */
__STATIC_INLINE uint32_t DDL_CRC_GetInputDataReverseMode(CRC_TypeDef *CRCx)
{
  return (uint32_t)(READ_BIT(CRCx->CTRL, CRC_CTRL_REVI));
}

/**
  * @}
  */

/** @defgroup CRC_DDL_EF_ResetValue Reset_Value
  * @{
  */

/**
  * @brief  Set CRC unit initial value
  * @param  CRCx CRC Instance
  * @param  RstData value to be provided for unit initial value between Min_Data=0 and Max_Data=0xFFFFFFFF
  * @retval None
  */
__STATIC_INLINE void DDL_CRC_SetInitialData(CRC_TypeDef *CRCx, uint32_t Data)
{
  WRITE_REG(CRCx->INITVAL, Data);
}

/**
  * @brief  Get CRC unit initial value
  * @param  CRCx CRC Instance
  * @retval CRC unit initial value as stored in CRC_INITVAL register (32 bits).
  */
__STATIC_INLINE uint32_t DDL_CRC_GetInitialData(CRC_TypeDef *CRCx)
{
  return (uint32_t)(READ_REG(CRCx->INITVAL));
}

/**
  * @}
  */


/** @defgroup CRC_DDL_EF_Data_Management Data_Management
  * @{
  */

/**
  * @brief  Write given 32-bit data to the CRC calculator
  * @param  CRCx CRC Instance
  * @param  InData value to be provided to CRC calculator between Min_Data=0 and Max_Data=0xFFFFFFFF
  * @retval None
  */
__STATIC_INLINE void DDL_CRC_FeedData32(CRC_TypeDef *CRCx, uint32_t InData)
{
  WRITE_REG(CRCx->DATA, InData);
}

/**
  * @brief  Write given 16-bit data to the CRC calculator
  * @param  CRCx CRC Instance
  * @param  InData value to be provided to CRC calculator between Min_Data=0 and Max_Data=0xFFFF
  * @retval None
  */
__STATIC_INLINE void DDL_CRC_FeedData16(CRC_TypeDef *CRCx, uint16_t InData)
{
  __IO uint16_t *pReg;

  pReg = (__IO uint16_t *)(__IO void*)(&CRCx->DATA);

  *pReg = InData;
}

/**
  * @brief  Return current CRC calculation result. 32 bits value is returned.
  * @param  CRCx CRC Instance
  * @retval Current CRC calculation result as stored in CRC_DATA register (32 bits).
  */
__STATIC_INLINE uint32_t DDL_CRC_ReadData32(CRC_TypeDef *CRCx)
{
  return (uint32_t)(READ_REG(CRCx->DATA));
}

/**
  * @brief  Return current CRC calculation result. 16-bits value is returned.
  * @param  CRCx CRC Instance
  * @retval Current CRC calculation result as stored in CRC_DATA register (16-bits).
  */
__STATIC_INLINE uint16_t DDL_CRC_ReadData16(CRC_TypeDef *CRCx)
{
  return (uint16_t)(READ_REG(CRCx->DATA));
}


/**
  * @}
  */

#if defined(USE_FULL_DDL_DRIVER)
/** @defgroup CRC_DDL_EF_Init Initialization and de-initialization functions
  * @{
  */

ErrorStatus DDL_CRC_DeInit(CRC_TypeDef *CRCx);

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

#endif /* CRC */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* G32M3101_DDL_CRC_H */
