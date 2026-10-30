/**
  *
  * @file        g32m3101_ddl_div.h
  *
  * @brief       Header file of DIV DDL module.
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
#ifndef G32M3101_DDL_DIV_H
#define G32M3101_DDL_DIV_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "g32m3xxx.h"
#include "Legacy/g32_ddl_legacy.h"

/** @addtogroup G32M3101_DDL_Driver
  * @{
  */

#if defined(DIV)

/** @defgroup DIV_DDL DIV
  * @{
  */

/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private constants ---------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/
/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/** @defgroup DIV_DDL_Exported_Macros DIV Exported Macros
  * @{
  */

/** @defgroup DIV_DDL_EM_WRITE_READ Common Write and read registers Macros
  * @{
  */

/**
  * @brief  Write a value in DIV register
  * @param  __REG__ Register to be written
  * @param  __VALUE__ Value to be written in the register
  * @retval None
  */
#define DDL_DIV_WriteReg(__REG__, __VALUE__) WRITE_REG(DIV->__REG__, __VALUE__)

/**
  * @brief  Read a value in DIV register
  * @param  __REG__ Register to be read
  * @retval Register value
  */
#define DDL_DIV_ReadReg(__REG__) READ_REG(DIV->__REG__)
/**
  * @}
  */

/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/** @defgroup DIV_DDL_Exported_Functions DIV Exported Functions
  * @{
  */

/** @defgroup DIV_DDL_EF_Configuration DIV configuration functions
  * @{
  */

/**
  * @brief  Start DIV Signed Division.
  * @param  Dividend value to be provided for dividend value between Min_Data=0x80000000 and Max_Data=0x7FFFFFFF.
  * @param  DivisorValue value to be provided for divisor value between Min_Data=0x80000000 and Max_Data=0x7FFFFFFF.(cannot be 0).
  * @retval value to be provided for quotient value between Min_Data=0x80000000 and Max_Data=0x7FFFFFFF.
  */
__STATIC_INLINE int32_t DDL_DIV_SignedComputeQuotient(int32_t Dividend, int32_t Divisor)
{
  CLEAR_BIT(DIV->CR, DIV_CR_USIGNEN);
  WRITE_REG(DIV->DVDR, Dividend);
  WRITE_REG(DIV->DVSR, Divisor);
  __NOP();__NOP();__NOP();__NOP();
  __NOP();__NOP();__NOP();__NOP();
  return (int32_t)(READ_REG(DIV->QUOTR));
}

/**
  * @brief  Start DIV Unsigned Division.
  * @param  Dividend value to be provided for dividend value between Min_Data=0 and Max_Data=0xFFFFFFFF.
  * @param  DivisorValue value to be provided for divisor value between Min_Data=1 and Max_Data=0xFFFFFFFF.
  * @retval value to be provided for quotient value between Min_Data=0 and Max_Data=0xFFFFFFFF..
  */
__STATIC_INLINE uint32_t DDL_DIV_UnsignedComputeQuotient(uint32_t Dividend, uint32_t Divisor)
{
  SET_BIT(DIV->CR, DIV_CR_USIGNEN);
  WRITE_REG(DIV->DVDR, Dividend);
  WRITE_REG(DIV->DVSR, Divisor);
  __NOP();__NOP();__NOP();__NOP();
  __NOP();__NOP();__NOP();__NOP();
  return (uint32_t)(READ_REG(DIV->QUOTR));
}

/**
  * @brief  Set DIV Signed Dividend Value.
  * @param  DividendValue value to be provided for dividend value between Min_Data=0x80000000 and Max_Data=0x7FFFFFFF.
  * @retval None.
  */
__STATIC_INLINE void DDL_DIV_SetSignedDividend(int32_t DividendValue)
{
  WRITE_REG(DIV->DVDR, DividendValue);
}

/**
  * @brief  Set DIV Unsigned Dividend Value.
  * @param  DividendValue value to be provided for dividend value between Min_Data=0 and Max_Data=0xFFFFFFFF.
  * @retval None.
  */
__STATIC_INLINE void DDL_DIV_SetUnsignedDividend(uint32_t DividendValue)
{
  WRITE_REG(DIV->DVDR, DividendValue);
}

/**
  * @brief  Get DIV Signed Dividend Value.
  * @param  None.
  * @retval Returned value can be one of the following values:
            Min_Data=0x80000000
            Max_Data=0x7FFFFFFF
  */
__STATIC_INLINE int32_t DDL_DIV_GetSignedDividend(void)
{
  return (int32_t)(READ_REG(DIV->DVDR));
}

/**
  * @brief  Get DIV Unsigned Dividend Value.
  * @param  None.
  * @retval Returned value can be one of the following values:
            Min_Data=0
            Max_Data=0xFFFFFFFF
  */
__STATIC_INLINE uint32_t DDL_DIV_GetUnsignedDividend(void)
{
  return (uint32_t)(READ_REG(DIV->DVDR));
}

/**
  * @brief  Set DIV Signed Divisor Value.
  * @param  DivisorValue value to be provided for divisor value between Min_Data=0x80000000 and Max_Data=0x7FFFFFFF(cannot be 0).
  * @retval None.
  */
__STATIC_INLINE void DDL_DIV_SetSignedDivisor(int32_t DivisorValue)
{
  WRITE_REG(DIV->DVSR, DivisorValue);
}

/**
  * @brief  Set DIV Unsigned Divisor Value.
  * @param  DivisorValue value to be provided for divisor value between Min_Data=1 and Max_Data=0xFFFFFFFF.
  * @retval None.
  */
__STATIC_INLINE void DDL_DIV_SetUnsignedDivisor(uint32_t DivisorValue)
{
  WRITE_REG(DIV->DVSR, DivisorValue);
}

/**
  * @brief  Get DIV Signed Divisor Value.
  * @param  None.
  * @retval Returned value can be one of the following values:
            Min_Data=0x80000000
            Max_Data=0x7FFFFFFF
  */
__STATIC_INLINE int32_t DDL_DIV_GetSignedDivisor(void)
{
  return (int32_t)(READ_REG(DIV->DVSR));
}

/**
  * @brief  Get DIV Unsigned Divisor Value.
  * @param  None.
  * @retval Returned value can be one of the following values:
            Min_Data=1
            Max_Data=0xFFFFFFFF
  */
__STATIC_INLINE uint32_t DDL_DIV_GetUnsignedDivisor(void)
{
  return (uint32_t)(READ_REG(DIV->DVSR));
}

/**
  * @brief  Get DIV Signed Quotient Value.
  * @param  None.
  * @retval Returned value can be one of the following values:
            Min_Data=0x80000000
            Max_Data=0x7FFFFFFF
  */
__STATIC_INLINE int32_t DDL_DIV_GetSignedQuotient(void)
{
  return (int32_t)(READ_REG(DIV->QUOTR));
}

/**
  * @brief  Get DIV Unsigned Quotient Value.
  * @param  None.
  * @retval Returned value can be one of the following values:
            Min_Data=0
            Max_Data=0xFFFFFFFF
  */
__STATIC_INLINE uint32_t DDL_DIV_GetUnsignedQuotient(void)
{
  return (uint32_t)(READ_REG(DIV->QUOTR));
}

/**
  * @brief  Get DIV Signed Remainder Value.
  * @param  None.
  * @retval Returned value can be one of the following values:
            Min_Data=0x80000000
            Max_Data=0x7FFFFFFF
  */
__STATIC_INLINE int32_t DDL_DIV_GetSignedRemainder(void)
{
  return (int32_t)(READ_REG(DIV->RMDR));
}

/**
  * @brief  Get DIV Unsigned Remainder Value.
  * @param  None.
  * @retval Returned value can be one of the following values:
            Min_Data=0
            Max_Data=0xFFFFFFFF
  */
__STATIC_INLINE uint32_t DDL_DIV_GetUnsignedRemainder(void)
{
  return (uint32_t)(READ_REG(DIV->RMDR));
}

/**
  * @brief  Enable DIV Unsigned Division.
  * @param  None.
  * @retval None.
  */
__STATIC_INLINE void DDL_DIV_EnableUnsignedDiv(void)
{
  SET_BIT(DIV->CR, DIV_CR_USIGNEN);
}

/**
  * @brief  Disable DIV Unsigned Division.
  * @param  None.
  * @retval None.
  */
__STATIC_INLINE void DDL_DIV_DisableUnsignedDiv(void)
{
  CLEAR_BIT(DIV->CR, DIV_CR_USIGNEN);
}

/**
  * @brief  Check if DIV Unsigned Division is enable or not.
  * @param  None.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_DIV_IsEnabledUnsignedDiv(void)
{
  return (READ_BIT(DIV->CR, DIV_CR_USIGNEN) == DIV_CR_USIGNEN);
}

/**
  * @}
  */

#if defined(USE_FULL_DDL_DRIVER)
/** @defgroup DIV_DDL_EF_Init Initialization and de-initialization functions
  * @{
  */

ErrorStatus DDL_DIV_DeInit(void);

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

#endif /* DIV */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* G32M3101_DDL_DIV_H */
