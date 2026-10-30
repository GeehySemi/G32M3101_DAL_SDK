/**
  *
  * @file        g32m3101_ddl_gpio.h
  *
  * @brief       Header file of GPIO DDL module.
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
  * Copyright (c) 2017 STMicroelectronics.
  * Copyright (C) 2026 Geehy Semiconductor.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef G32M3101_DDL_GPIO_H
#define G32M3101_DDL_GPIO_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "g32m3xxx.h"
#include "Legacy/g32_ddl_legacy.h"

/** @addtogroup G32M3101_DDL_Driver
  * @{
  */

#if defined (GPIOA) || defined (GPIOB)

/** @defgroup GPIO_DDL GPIO
  * @{
  */

/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private constants ---------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/
/* Exported types ------------------------------------------------------------*/
#if defined(USE_FULL_DDL_DRIVER)
/** @defgroup GPIO_DDL_ES_INIT GPIO Exported Init structures
  * @{
  */

/**
  * @brief LL GPIO Init Structure definition
  */
typedef struct
{
  uint32_t Pin;          /*!< Specifies the GPIO pins to be configured.
                              This parameter can be any value of @ref GPIO_DDL_EC_PIN */

  uint32_t Mode;         /*!< Specifies the operating mode for the selected pins.
                              This parameter can be a value of @ref GPIO_DDL_EC_MODE.

                              GPIO HW configuration can be modified afterwards using unitary function @ref DDL_GPIO_SetPinMode().*/

  uint32_t Drive;        /*!< Specifies the drive for the selected pins.
                              This parameter can be a value of @ref GPIO_DDL_EC_DRIVE.

                              GPIO HW configuration can be modified afterwards using unitary function @ref DDL_GPIO_SetPinOutputDriverType().*/

  uint32_t OutputType;   /*!< Specifies the operating output type for the selected pins.
                              This parameter can be a value of @ref GPIO_DDL_EC_OUTPUT.

                              GPIO HW configuration can be modified afterwards using unitary function @ref DDL_GPIO_SetPinOutputType().*/

  uint32_t InputEnable;  /*!< Specifies enable/disable the input type for the selected pins.
                              This parameter can be a value of @ref GPIO_DDL_EC_IER.

                              GPIO HW configuration can be modified afterwards using unitary function @ref DDL_GPIO_SetPinInputMode().*/

  uint32_t InputType;    /*!< Specifies the operating input type for the selected pins.
                              This parameter can be a value of @ref GPIO_DDL_EC_CSR.

                              GPIO HW configuration can be modified afterwards using unitary function @ref DDL_GPIO_SetPinInputType().*/

  uint32_t Pull;         /*!< Specifies the operating Pull-up/Pull down for the selected pins.
                              This parameter can be a value of @ref GPIO_DDL_EC_PULL.

                              GPIO HW configuration can be modified afterwards using unitary function @ref DDL_GPIO_SetPinPull().*/

  uint32_t Alternate;    /*!< Specifies the Peripheral to be connected to the selected pins.
                              This parameter can be a value of @ref GPIO_DDL_EC_AF.

                              GPIO HW configuration can be modified afterwards using unitary function @ref DDL_GPIO_SetAFPin().*/
} DDL_GPIO_InitTypeDef;

/**
  * @}
  */
#endif /* USE_FULL_DDL_DRIVER */

/* Exported constants --------------------------------------------------------*/
/** @defgroup GPIO_DDL_Exported_Constants GPIO Exported Constants
  * @{
  */

/** @defgroup GPIO_DDL_EC_PIN PIN
  * @{
  */
#define DDL_GPIO_PIN_0                      GPIO_BSC_BS0 /*!< Select pin 0 */
#define DDL_GPIO_PIN_1                      GPIO_BSC_BS1 /*!< Select pin 1 */
#define DDL_GPIO_PIN_2                      GPIO_BSC_BS2 /*!< Select pin 2 */
#define DDL_GPIO_PIN_3                      GPIO_BSC_BS3 /*!< Select pin 3 */
#define DDL_GPIO_PIN_4                      GPIO_BSC_BS4 /*!< Select pin 4 */
#define DDL_GPIO_PIN_5                      GPIO_BSC_BS5 /*!< Select pin 5 */
#define DDL_GPIO_PIN_6                      GPIO_BSC_BS6 /*!< Select pin 6 */
#define DDL_GPIO_PIN_7                      GPIO_BSC_BS7 /*!< Select pin 7 */
#define DDL_GPIO_PIN_8                      GPIO_BSC_BS8 /*!< Select pin 8 */
#define DDL_GPIO_PIN_9                      GPIO_BSC_BS9 /*!< Select pin 9 */
#define DDL_GPIO_PIN_10                     GPIO_BSC_BS10 /*!< Select pin 10 */
#define DDL_GPIO_PIN_11                     GPIO_BSC_BS11 /*!< Select pin 11 */
#define DDL_GPIO_PIN_12                     GPIO_BSC_BS12 /*!< Select pin 12 */
#define DDL_GPIO_PIN_13                     GPIO_BSC_BS13 /*!< Select pin 13 */
#define DDL_GPIO_PIN_ALL                    (GPIO_BSC_BS0  | GPIO_BSC_BS1  | GPIO_BSC_BS2  | \
                                             GPIO_BSC_BS3  | GPIO_BSC_BS4  | GPIO_BSC_BS5  | \
                                             GPIO_BSC_BS6  | GPIO_BSC_BS7  | GPIO_BSC_BS8  | \
                                             GPIO_BSC_BS9  | GPIO_BSC_BS10 | GPIO_BSC_BS11 | \
                                             GPIO_BSC_BS12 | GPIO_BSC_BS13) /*!< Select all pins */
/**
  * @}
  */

/** @defgroup GPIO_DDL_EC_MODE Mode
  * @{
  */
#define DDL_GPIO_MODE_ANALOG                (0x00000000U)      /*!< Select analog mode */
#define DDL_GPIO_MODE_INPUT                 GPIO_MODE_MODE0_0  /*!< Select input mode */
#define DDL_GPIO_MODE_OUTPUT                GPIO_MODE_MODE0_1  /*!< Select output mode */
#define DDL_GPIO_MODE_ALTERNATE             GPIO_MODE_MODE0    /*!< Select alternate function mode */
/**
  * @}
  */

/** @defgroup GPIO_DDL_EC_IER Enalbe/Disable input configuration
  * @{
  */
#define DDL_GPIO_INPUT_DISABLE               (0x00000000U)     /*!< Select input disable mode */
#define DDL_GPIO_INPUT_ENABLE                GPIO_IEN_IEN0      /*!< Select input enable mode */
/**
  * @}
  */

/** @defgroup GPIO_DDL_EC_CSR Input type
  * @{
  */
#define DDL_GPIO_INPUT_TYPE_SCHMITT               (0x00000000U)     /*!< Select input type */
#define DDL_GPIO_INPUT_TYPE_CMOS                  GPIO_ITYPCFG_ITYPCFG0      /*!< Select input type */
/**
  * @}
  */

/** @defgroup GPIO_DDL_EC_PULL Pull Up Pull Down
  * @{
  */
#define DDL_GPIO_PULL_NO                    (0x00000000U)    /*!< Select I/O no pull */
#define DDL_GPIO_PULL_UP                    GPIO_PUPD_PUPDEN0  /*!< Select I/O pull up */
#define DDL_GPIO_PULL_DOWN                  (GPIO_PUPD_PUPDEN0 | GPIO_PUPD_PUPD0) /*!< Select I/O pull down */
/**
  * @}
  */

/** @defgroup GPIO_DDL_EC_OUTPUT Output Type
  * @{
  */
#define DDL_GPIO_OUTPUT_PUSHPULL            (0x00000000U) /*!< Select push-pull as output type */
#define DDL_GPIO_OUTPUT_OPENDRAIN           GPIO_OTYPCFG_OTYPCFG0 /*!< Select open-drain as output type */
/**
  * @}
  */

/** @defgroup GPIO_DDL_EC_DRIVE Mode
  * @{
  */
#define DDL_GPIO_DRIVE_LOW                  (0x00000000U)      /*!< Select Low output driver type */
#define DDL_GPIO_DRIVE_HIGH                  GPIO_DCFG_DCFG0      /*!< Select high output driver type */
/**
  * @}
  */

/** @defgroup GPIO_DDL_EC_AF Alternate Function
  * @{
  */
#define DDL_GPIO_AF_0                       (0x0000000U) /*!< Select alternate function 0 */
#define DDL_GPIO_AF_1                       (0x0000001U) /*!< Select alternate function 1 */
#define DDL_GPIO_AF_2                       (0x0000002U) /*!< Select alternate function 2 */
#define DDL_GPIO_AF_3                       (0x0000003U) /*!< Select alternate function 3 */
#define DDL_GPIO_AF_4                       (0x0000004U) /*!< Select alternate function 4 */
#define DDL_GPIO_AF_5                       (0x0000005U) /*!< Select alternate function 5 */
#define DDL_GPIO_AF_6                       (0x0000006U) /*!< Select alternate function 6 */
#define DDL_GPIO_AF_7                       (0x0000007U) /*!< Select alternate function 7 */
/**
  * @}
  */

/** @defgroup GPIO_DDL_FITR_PIN Mode
  * @{
  */
#define DDL_GPIO_FITR_PA6_DISABLE                 0x00000000U
#define DDL_GPIO_FITR_PA6_ENABLE                  GPIO_FLT_FLTEN6      /*!< Select GPIOA Pin 6 Filter  */
/**
  * @}
  */

/** @defgroup GPIO_DDL_EC_LOCK Mode
  * @{
  */
#define DDL_GPIO_LOCK_DISABLE               (0xA5A55A5AU)    /*!< Select Lock disable mode */
#define DDL_GPIO_LOCK_ENABLE                (0x55555555U)    /*!< Select Lock enable mode */
/**
  * @}
  */

/**
  * @}
  */

/* Exported macro ------------------------------------------------------------*/
/** @defgroup GPIO_DDL_Exported_Macros GPIO Exported Macros
  * @{
  */

/** @defgroup GPIO_DDL_EM_WRITE_READ Common Write and read registers Macros
  * @{
  */

/**
  * @brief  Write a value in GPIO register
  * @param  __INSTANCE__ GPIO Instance
  * @param  __REG__ Register to be written
  * @param  __VALUE__ Value to be written in the register
  * @retval None
  */
#define DDL_GPIO_WriteReg(__INSTANCE__, __REG__, __VALUE__) WRITE_REG(__INSTANCE__->__REG__, (__VALUE__))

/**
  * @brief  Read a value in GPIO register
  * @param  __INSTANCE__ GPIO Instance
  * @param  __REG__ Register to be read
  * @retval Register value
  */
#define DDL_GPIO_ReadReg(__INSTANCE__, __REG__) READ_REG(__INSTANCE__->__REG__)
/**
  * @}
  */

/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/** @defgroup GPIO_DDL_Exported_Functions GPIO Exported Functions
  * @{
  */

/** @defgroup GPIO_DDL_EF_Port_Configuration Port Configuration
  * @{
  */

/**
  * @brief  Configure gpio mode for a dedicated pin on dedicated port.
  * @note   Warning: only one pin can be passed as parameter.
  * @param  GPIOx GPIO Port
  * @param  Pin This parameter can be one of the following values:
  *         @arg @ref DDL_GPIO_PIN_0
  *         @arg @ref DDL_GPIO_PIN_1
  *         @arg @ref DDL_GPIO_PIN_2
  *         @arg @ref DDL_GPIO_PIN_3
  *         @arg @ref DDL_GPIO_PIN_4
  *         @arg @ref DDL_GPIO_PIN_5
  *         @arg @ref DDL_GPIO_PIN_6
  *         @arg @ref DDL_GPIO_PIN_7
  *         @arg @ref DDL_GPIO_PIN_8
  *         @arg @ref DDL_GPIO_PIN_9
  *         @arg @ref DDL_GPIO_PIN_10
  *         @arg @ref DDL_GPIO_PIN_11
  *         @arg @ref DDL_GPIO_PIN_12
  *         @arg @ref DDL_GPIO_PIN_13
  * @param  Mode This parameter can be one of the following values:
  *         @arg @ref DDL_GPIO_MODE_ANALOG
  *         @arg @ref DDL_GPIO_MODE_INPUT
  *         @arg @ref DDL_GPIO_MODE_OUTPUT
  *         @arg @ref DDL_GPIO_MODE_ALTERNATE
  * @retval None
  */
__STATIC_INLINE void DDL_GPIO_SetPinMode(GPIO_TypeDef *GPIOx, uint32_t Pin, uint32_t Mode)
{
  MODIFY_REG(GPIOx->MODE, (GPIO_MODE_MODE0 << (POSITION_VAL(Pin) * 2U)), (Mode << (POSITION_VAL(Pin) * 2U)));
}

/**
  * @brief  Return gpio mode for a dedicated pin on dedicated port.
  * @note   Warning: only one pin can be passed as parameter.
  * @param  GPIOx GPIO Port
  * @param  Pin This parameter can be one of the following values:
  *         @arg @ref DDL_GPIO_PIN_0
  *         @arg @ref DDL_GPIO_PIN_1
  *         @arg @ref DDL_GPIO_PIN_2
  *         @arg @ref DDL_GPIO_PIN_3
  *         @arg @ref DDL_GPIO_PIN_4
  *         @arg @ref DDL_GPIO_PIN_5
  *         @arg @ref DDL_GPIO_PIN_6
  *         @arg @ref DDL_GPIO_PIN_7
  *         @arg @ref DDL_GPIO_PIN_8
  *         @arg @ref DDL_GPIO_PIN_9
  *         @arg @ref DDL_GPIO_PIN_10
  *         @arg @ref DDL_GPIO_PIN_11
  *         @arg @ref DDL_GPIO_PIN_12
  *         @arg @ref DDL_GPIO_PIN_13
  * @retval Returned value can be one of the following values:
  *         @arg @ref DDL_GPIO_MODE_ANALOG
  *         @arg @ref DDL_GPIO_MODE_INPUT
  *         @arg @ref DDL_GPIO_MODE_OUTPUT
  *         @arg @ref DDL_GPIO_MODE_ALTERNATE
  */
__STATIC_INLINE uint32_t DDL_GPIO_GetPinMode(GPIO_TypeDef *GPIOx, uint32_t Pin)
{
  return (uint32_t)(READ_BIT(GPIOx->MODE,
                             (GPIO_MODE_MODE0 << (POSITION_VAL(Pin) * 2U))) >> (POSITION_VAL(Pin) * 2U));
}

/**
  * @brief  Configure gpio input mode for several pins on dedicated port.
  * @param  GPIOx GPIO Port
  * @param  PinMask This parameter can be a combination of the following values:
  *         @arg @ref DDL_GPIO_PIN_0
  *         @arg @ref DDL_GPIO_PIN_1
  *         @arg @ref DDL_GPIO_PIN_2
  *         @arg @ref DDL_GPIO_PIN_3
  *         @arg @ref DDL_GPIO_PIN_4
  *         @arg @ref DDL_GPIO_PIN_5
  *         @arg @ref DDL_GPIO_PIN_6
  *         @arg @ref DDL_GPIO_PIN_7
  *         @arg @ref DDL_GPIO_PIN_8
  *         @arg @ref DDL_GPIO_PIN_9
  *         @arg @ref DDL_GPIO_PIN_10
  *         @arg @ref DDL_GPIO_PIN_11
  *         @arg @ref DDL_GPIO_PIN_12
  *         @arg @ref DDL_GPIO_PIN_13
  *         @arg @ref DDL_GPIO_PIN_ALL
  * @param  Input This parameter can be one of the following values:
  *         @arg @ref DDL_GPIO_INPUT_DISABLE
  *         @arg @ref DDL_GPIO_INPUT_ENABLE
  * @retval None
  */
__STATIC_INLINE void DDL_GPIO_SetPinInputMode(GPIO_TypeDef *GPIOx, uint32_t PinMask, uint32_t InputMode)
{
  MODIFY_REG(GPIOx->IEN, PinMask, (PinMask * InputMode));
}

/**
  * @brief  Return gpio input mode for several pins on dedicated port.
  * @note   Warning: only one pin can be passed as parameter.
  * @param  GPIOx GPIO Port
  * @param  Pin This parameter can be one of the following values:
  *         @arg @ref DDL_GPIO_PIN_0
  *         @arg @ref DDL_GPIO_PIN_1
  *         @arg @ref DDL_GPIO_PIN_2
  *         @arg @ref DDL_GPIO_PIN_3
  *         @arg @ref DDL_GPIO_PIN_4
  *         @arg @ref DDL_GPIO_PIN_5
  *         @arg @ref DDL_GPIO_PIN_6
  *         @arg @ref DDL_GPIO_PIN_7
  *         @arg @ref DDL_GPIO_PIN_8
  *         @arg @ref DDL_GPIO_PIN_9
  *         @arg @ref DDL_GPIO_PIN_10
  *         @arg @ref DDL_GPIO_PIN_11
  *         @arg @ref DDL_GPIO_PIN_12
  *         @arg @ref DDL_GPIO_PIN_13
  *         @arg @ref DDL_GPIO_PIN_ALL
  * @retval Returned value can be one of the following values:
  *         @arg @ref DDL_GPIO_INPUT_DISABLE
  *         @arg @ref DDL_GPIO_INPUT_ENABLE
  */
__STATIC_INLINE uint32_t DDL_GPIO_GetPinInputMode(GPIO_TypeDef *GPIOx, uint32_t Pin)
{
  return (uint32_t)(READ_BIT(GPIOx->IEN, Pin) >> POSITION_VAL(Pin));
}

/**
  * @brief  Configure gpio input type for several pins on dedicated port.
  * @note   Input type as to be set when gpio pin is in input or
  *         alternate modes. Possible type are Schmitt or Cmos.
  * @param  GPIOx GPIO Port
  * @param  PinMask This parameter can be a combination of the following values:
  *         @arg @ref DDL_GPIO_PIN_0
  *         @arg @ref DDL_GPIO_PIN_1
  *         @arg @ref DDL_GPIO_PIN_2
  *         @arg @ref DDL_GPIO_PIN_3
  *         @arg @ref DDL_GPIO_PIN_4
  *         @arg @ref DDL_GPIO_PIN_5
  *         @arg @ref DDL_GPIO_PIN_6
  *         @arg @ref DDL_GPIO_PIN_7
  *         @arg @ref DDL_GPIO_PIN_8
  *         @arg @ref DDL_GPIO_PIN_9
  *         @arg @ref DDL_GPIO_PIN_10
  *         @arg @ref DDL_GPIO_PIN_11
  *         @arg @ref DDL_GPIO_PIN_12
  *         @arg @ref DDL_GPIO_PIN_13
  *         @arg @ref DDL_GPIO_PIN_ALL
  * @param  InputType This parameter can be one of the following values:
  *         @arg @ref DDL_GPIO_INPUT_TYPE_SCHMITT
  *         @arg @ref DDL_GPIO_INPUT_TYPE_CMOS
  * @retval None
  */
__STATIC_INLINE void DDL_GPIO_SetPinInputType(GPIO_TypeDef *GPIOx, uint32_t PinMask, uint32_t InputType)
{
  MODIFY_REG(GPIOx->ITYPCFG, PinMask, (PinMask * InputType));
}

/**
  * @brief  Return gpio input type for several pins on dedicated port.
  * @note   Warning: only one pin can be passed as parameter.
  * @param  GPIOx GPIO Port
  * @param  Pin This parameter can be one of the following values:
  *         @arg @ref DDL_GPIO_PIN_0
  *         @arg @ref DDL_GPIO_PIN_1
  *         @arg @ref DDL_GPIO_PIN_2
  *         @arg @ref DDL_GPIO_PIN_3
  *         @arg @ref DDL_GPIO_PIN_4
  *         @arg @ref DDL_GPIO_PIN_5
  *         @arg @ref DDL_GPIO_PIN_6
  *         @arg @ref DDL_GPIO_PIN_7
  *         @arg @ref DDL_GPIO_PIN_8
  *         @arg @ref DDL_GPIO_PIN_9
  *         @arg @ref DDL_GPIO_PIN_10
  *         @arg @ref DDL_GPIO_PIN_11
  *         @arg @ref DDL_GPIO_PIN_12
  *         @arg @ref DDL_GPIO_PIN_13
  *         @arg @ref DDL_GPIO_PIN_ALL
  * @retval Returned value can be one of the following values:
  *         @arg @ref DDL_GPIO_INPUT_TYPE_SCHMITT
  *         @arg @ref DDL_GPIO_INPUT_TYPE_CMOS
  */
__STATIC_INLINE uint32_t DDL_GPIO_GetPinInputType(GPIO_TypeDef *GPIOx, uint32_t Pin)
{
  return (uint32_t)(READ_BIT(GPIOx->ITYPCFG, Pin) >> POSITION_VAL(Pin));
}

/**
  * @brief  Configure gpio output type for several pins on dedicated port.
  * @param  GPIOx GPIO Port
  * @param  PinMask This parameter can be a combination of the following values:
  *         @arg @ref DDL_GPIO_PIN_0
  *         @arg @ref DDL_GPIO_PIN_1
  *         @arg @ref DDL_GPIO_PIN_2
  *         @arg @ref DDL_GPIO_PIN_3
  *         @arg @ref DDL_GPIO_PIN_4
  *         @arg @ref DDL_GPIO_PIN_5
  *         @arg @ref DDL_GPIO_PIN_6
  *         @arg @ref DDL_GPIO_PIN_7
  *         @arg @ref DDL_GPIO_PIN_8
  *         @arg @ref DDL_GPIO_PIN_9
  *         @arg @ref DDL_GPIO_PIN_10
  *         @arg @ref DDL_GPIO_PIN_11
  *         @arg @ref DDL_GPIO_PIN_12
  *         @arg @ref DDL_GPIO_PIN_13
  *         @arg @ref DDL_GPIO_PIN_ALL
  * @param  OutputType This parameter can be one of the following values:
  *         @arg @ref DDL_GPIO_OUTPUT_PUSHPULL
  *         @arg @ref DDL_GPIO_OUTPUT_OPENDRAIN
  * @retval None
  */
__STATIC_INLINE void DDL_GPIO_SetPinOutputType(GPIO_TypeDef *GPIOx, uint32_t PinMask, uint32_t OutputType)
{
  MODIFY_REG(GPIOx->OTYPCFG, PinMask, (PinMask * OutputType));
}

/**
  * @brief  Return gpio output type for several pins on dedicated port.
  * @note   Warning: only one pin can be passed as parameter.
  * @param  GPIOx GPIO Port
  * @param  Pin This parameter can be one of the following values:
  *         @arg @ref DDL_GPIO_PIN_0
  *         @arg @ref DDL_GPIO_PIN_1
  *         @arg @ref DDL_GPIO_PIN_2
  *         @arg @ref DDL_GPIO_PIN_3
  *         @arg @ref DDL_GPIO_PIN_4
  *         @arg @ref DDL_GPIO_PIN_5
  *         @arg @ref DDL_GPIO_PIN_6
  *         @arg @ref DDL_GPIO_PIN_7
  *         @arg @ref DDL_GPIO_PIN_8
  *         @arg @ref DDL_GPIO_PIN_9
  *         @arg @ref DDL_GPIO_PIN_10
  *         @arg @ref DDL_GPIO_PIN_11
  *         @arg @ref DDL_GPIO_PIN_12
  *         @arg @ref DDL_GPIO_PIN_13
  *         @arg @ref DDL_GPIO_PIN_ALL
  * @retval Returned value can be one of the following values:
  *         @arg @ref DDL_GPIO_OUTPUT_PUSHPULL
  *         @arg @ref DDL_GPIO_OUTPUT_OPENDRAIN
  */
__STATIC_INLINE uint32_t DDL_GPIO_GetPinOutputType(GPIO_TypeDef *GPIOx, uint32_t Pin)
{
  return (uint32_t)(READ_BIT(GPIOx->OTYPCFG, Pin) >> POSITION_VAL(Pin));
}

/**
  * @brief  Configure gpio pull-up or pull-down for a dedicated pin on a dedicated port.
  * @note   Warning: only one pin can be passed as parameter.
  * @param  GPIOx GPIO Port
  * @param  Pin This parameter can be one of the following values:
  *         @arg @ref DDL_GPIO_PIN_0
  *         @arg @ref DDL_GPIO_PIN_1
  *         @arg @ref DDL_GPIO_PIN_2
  *         @arg @ref DDL_GPIO_PIN_3
  *         @arg @ref DDL_GPIO_PIN_4
  *         @arg @ref DDL_GPIO_PIN_5
  *         @arg @ref DDL_GPIO_PIN_6
  *         @arg @ref DDL_GPIO_PIN_7
  *         @arg @ref DDL_GPIO_PIN_8
  *         @arg @ref DDL_GPIO_PIN_9
  *         @arg @ref DDL_GPIO_PIN_10
  *         @arg @ref DDL_GPIO_PIN_11
  *         @arg @ref DDL_GPIO_PIN_12
  *         @arg @ref DDL_GPIO_PIN_13
  * @param  Pull This parameter can be one of the following values:
  *         @arg @ref DDL_GPIO_PULL_NO
  *         @arg @ref DDL_GPIO_PULL_UP
  *         @arg @ref DDL_GPIO_PULL_DOWN
  * @retval None
  */
__STATIC_INLINE void DDL_GPIO_SetPinPull(GPIO_TypeDef *GPIOx, uint32_t Pin, uint32_t Pull)
{
  MODIFY_REG(GPIOx->PUPD, ((GPIO_PUPD_PUPDEN0 | GPIO_PUPD_PUPD0) << (POSITION_VAL(Pin) * 2U)), (Pull << (POSITION_VAL(Pin) * 2U)));
}

/**
  * @brief  Return gpio pull-up or pull-down for a dedicated pin on a dedicated port
  * @note   Warning: only one pin can be passed as parameter.
  * @param  GPIOx GPIO Port
  * @param  Pin This parameter can be one of the following values:
  *         @arg @ref DDL_GPIO_PIN_0
  *         @arg @ref DDL_GPIO_PIN_1
  *         @arg @ref DDL_GPIO_PIN_2
  *         @arg @ref DDL_GPIO_PIN_3
  *         @arg @ref DDL_GPIO_PIN_4
  *         @arg @ref DDL_GPIO_PIN_5
  *         @arg @ref DDL_GPIO_PIN_6
  *         @arg @ref DDL_GPIO_PIN_7
  *         @arg @ref DDL_GPIO_PIN_8
  *         @arg @ref DDL_GPIO_PIN_9
  *         @arg @ref DDL_GPIO_PIN_10
  *         @arg @ref DDL_GPIO_PIN_11
  *         @arg @ref DDL_GPIO_PIN_12
  *         @arg @ref DDL_GPIO_PIN_13
  * @retval Returned value can be one of the following values:
  *         @arg @ref DDL_GPIO_PULL_NO
  *         @arg @ref DDL_GPIO_PULL_UP
  *         @arg @ref DDL_GPIO_PULL_DOWN
  */
__STATIC_INLINE uint32_t DDL_GPIO_GetPinPull(GPIO_TypeDef *GPIOx, uint32_t Pin)
{
  return (uint32_t)(READ_BIT(GPIOx->PUPD,
                             ((GPIO_PUPD_PUPDEN0 | GPIO_PUPD_PUPD0) << (POSITION_VAL(Pin) * 2U))) >> (POSITION_VAL(Pin) * 2U));
}

/**
  * @brief  Configure gpio output drive type for several pins on dedicated port.
  * @param  GPIOx GPIO Port
  * @param  PinMask This parameter can be a combination of the following values:
  *         @arg @ref DDL_GPIO_PIN_0
  *         @arg @ref DDL_GPIO_PIN_1
  *         @arg @ref DDL_GPIO_PIN_2
  *         @arg @ref DDL_GPIO_PIN_3
  *         @arg @ref DDL_GPIO_PIN_4
  *         @arg @ref DDL_GPIO_PIN_5
  *         @arg @ref DDL_GPIO_PIN_6
  *         @arg @ref DDL_GPIO_PIN_7
  *         @arg @ref DDL_GPIO_PIN_8
  *         @arg @ref DDL_GPIO_PIN_9
  *         @arg @ref DDL_GPIO_PIN_10
  *         @arg @ref DDL_GPIO_PIN_11
  *         @arg @ref DDL_GPIO_PIN_12
  *         @arg @ref DDL_GPIO_PIN_13
  *         @arg @ref DDL_GPIO_PIN_ALL
  * @param  OutputDriverType This parameter can be one of the following values:
  *         @arg @ref DDL_GPIO_DRIVE_LOW
  *         @arg @ref DDL_GPIO_DRIVE_HIGH
  * @retval None
  */
__STATIC_INLINE void DDL_GPIO_SetPinOutputDriverType(GPIO_TypeDef *GPIOx, uint32_t PinMask, uint32_t OutputDriverType)
{
  MODIFY_REG(GPIOx->DCFG, PinMask, (PinMask * OutputDriverType));
}

/**
  * @brief  Return gpio output drive type for several pins on dedicated port.
  * @note   Warning: only one pin can be passed as parameter.
  * @param  GPIOx GPIO Port
  * @param  Pin This parameter can be one of the following values:
  *         @arg @ref DDL_GPIO_PIN_0
  *         @arg @ref DDL_GPIO_PIN_1
  *         @arg @ref DDL_GPIO_PIN_2
  *         @arg @ref DDL_GPIO_PIN_3
  *         @arg @ref DDL_GPIO_PIN_4
  *         @arg @ref DDL_GPIO_PIN_5
  *         @arg @ref DDL_GPIO_PIN_6
  *         @arg @ref DDL_GPIO_PIN_7
  *         @arg @ref DDL_GPIO_PIN_8
  *         @arg @ref DDL_GPIO_PIN_9
  *         @arg @ref DDL_GPIO_PIN_10
  *         @arg @ref DDL_GPIO_PIN_11
  *         @arg @ref DDL_GPIO_PIN_12
  *         @arg @ref DDL_GPIO_PIN_13
  *         @arg @ref DDL_GPIO_PIN_ALL
  * @retval Returned value can be one of the following values:
  *         @arg @ref DDL_GPIO_DRIVE_LOW
  *         @arg @ref DDL_GPIO_DRIVE_HIGH
  */
__STATIC_INLINE uint32_t DDL_GPIO_GetPinOutputDriverType(GPIO_TypeDef *GPIOx, uint32_t Pin)
{
  return (uint32_t)(READ_BIT(GPIOx->DCFG, Pin) >> POSITION_VAL(Pin));
}

/**
  * @brief  Configure gpio alternate function of a dedicated pin from 0 to 13 for a dedicated port.
  * @note   Possible values are from AF0 to AF7 depending on target.
  * @note   For GPIOA pin 6-9, for GPIOB pin 0-13.
  * @note   Warning: only one pin can be passed as parameter.
  * @param  GPIOx GPIO Port
  * @param  Pin This parameter can be one of the following values:
  *         @arg @ref DDL_GPIO_PIN_0
  *         @arg @ref DDL_GPIO_PIN_1
  *         @arg @ref DDL_GPIO_PIN_2
  *         @arg @ref DDL_GPIO_PIN_3
  *         @arg @ref DDL_GPIO_PIN_4
  *         @arg @ref DDL_GPIO_PIN_5
  *         @arg @ref DDL_GPIO_PIN_6
  *         @arg @ref DDL_GPIO_PIN_7
  *         @arg @ref DDL_GPIO_PIN_8
  *         @arg @ref DDL_GPIO_PIN_9
  *         @arg @ref DDL_GPIO_PIN_10
  *         @arg @ref DDL_GPIO_PIN_11
  *         @arg @ref DDL_GPIO_PIN_12
  *         @arg @ref DDL_GPIO_PIN_13
  * @param  Alternate This parameter can be one of the following values:
  *         @arg @ref DDL_GPIO_AF_0
  *         @arg @ref DDL_GPIO_AF_1
  *         @arg @ref DDL_GPIO_AF_2
  *         @arg @ref DDL_GPIO_AF_3
  *         @arg @ref DDL_GPIO_AF_4
  *         @arg @ref DDL_GPIO_AF_5
  *         @arg @ref DDL_GPIO_AF_6
  *         @arg @ref DDL_GPIO_AF_7
  * @retval None
  */
__STATIC_INLINE void DDL_GPIO_SetAFPin(GPIO_TypeDef *GPIOx, uint32_t Pin, uint32_t Alternate)
{
  if(POSITION_VAL(Pin) < 0x00000008U || GPIOx == GPIOA)
  {
      MODIFY_REG(GPIOx->ALFSEL[0], (GPIO_ALFSEL0_ALFSEL0 << (POSITION_VAL(Pin) * 3U)),
             (Alternate << (POSITION_VAL(Pin) * 3U)));
  }
  else
  {
      MODIFY_REG(GPIOx->ALFSEL[1], (GPIO_ALFSEL1_ALFSEL8 << (POSITION_VAL(Pin >> 8U) * 3U)),
            (Alternate << (POSITION_VAL(Pin >> 8U) * 3U)));
  }
}

/**
  * @brief  Return gpio alternate function of a dedicated pin from 0 to 13 for a dedicated port.
  * @note   Possible values are from AF0 to AF7 depending on target.
  * @note   For GPIOA pin 6-9, for GPIOB pin 0-13.
  * @param  GPIOx GPIO Port
  * @param  Pin This parameter can be one of the following values:
  *         @arg @ref DDL_GPIO_PIN_0
  *         @arg @ref DDL_GPIO_PIN_1
  *         @arg @ref DDL_GPIO_PIN_2
  *         @arg @ref DDL_GPIO_PIN_3
  *         @arg @ref DDL_GPIO_PIN_4
  *         @arg @ref DDL_GPIO_PIN_5
  *         @arg @ref DDL_GPIO_PIN_6
  *         @arg @ref DDL_GPIO_PIN_7
  *         @arg @ref DDL_GPIO_PIN_8
  *         @arg @ref DDL_GPIO_PIN_9
  *         @arg @ref DDL_GPIO_PIN_10
  *         @arg @ref DDL_GPIO_PIN_11
  *         @arg @ref DDL_GPIO_PIN_12
  *         @arg @ref DDL_GPIO_PIN_13
  * @retval Returned value can be one of the following values:
  *         @arg @ref DDL_GPIO_AF_0
  *         @arg @ref DDL_GPIO_AF_1
  *         @arg @ref DDL_GPIO_AF_2
  *         @arg @ref DDL_GPIO_AF_3
  *         @arg @ref DDL_GPIO_AF_4
  *         @arg @ref DDL_GPIO_AF_5
  *         @arg @ref DDL_GPIO_AF_6
  *         @arg @ref DDL_GPIO_AF_7
  */
__STATIC_INLINE uint32_t DDL_GPIO_GetAFPin(GPIO_TypeDef *GPIOx, uint32_t Pin)
{
  if(POSITION_VAL(Pin) < 0x00000008U || GPIOx == GPIOA)
  {
      return (uint32_t)(READ_BIT(GPIOx->ALFSEL[0],
                             (GPIO_ALFSEL0_ALFSEL0 << (POSITION_VAL(Pin) * 3U))) >> (POSITION_VAL(Pin) * 3U));
  }
  else
  {
      return (uint32_t)(READ_BIT(GPIOx->ALFSEL[1],
                             (GPIO_ALFSEL1_ALFSEL8 << (POSITION_VAL(Pin >> 8U) * 3U))) >> (POSITION_VAL(Pin >> 8U) * 3U));
  }
}


/**
  * @brief  Lock key configuration of several port.
  * @param  GPIOx GPIO Port
  * @note   DDL_GPIO_LOCK_DISABLE allows other GPIO registers to be written.
  *         Any other value prohibits writes.
  * @param  LockMode This parameter can be one of the following values:
  *         @arg @ref DDL_GPIO_LOCK_DISABLE
  *         @arg @ref DDL_GPIO_LOCK_ENABLE
  * @retval None
  */
__STATIC_INLINE void DDL_GPIO_LockKey(GPIO_TypeDef *GPIOx, uint32_t LockMode)
{
  WRITE_REG(GPIOx->LOCK, LockMode);
}

/**
  * @brief  Check if the gpio is locked or not.
  * @param  GPIOx GPIO Port
  * @retval Return 1 if locked, 0 if unlocked.
  */
__STATIC_INLINE uint32_t DDL_GPIO_IsPinLocked(GPIO_TypeDef *GPIOx)
{
  return (READ_REG(GPIOx->LOCK) != DDL_GPIO_LOCK_DISABLE);
}

/**
  * @brief  Filter configuration of several pins for a dedicated port.
  * @note   Warning: only one pin can be passed as parameter.
  * @param  GPIOx GPIO Port
  * @param  Pin This parameter can be one of the following values:
  *         @arg @ref DDL_GPIO_PIN_6
  * @param  FilterMode This parameter can be one of the following values:
  *         @arg @ref DDL_GPIO_FITR_PA6_DISABLE
  *         @arg @ref DDL_GPIO_FITR_PA6_ENABLE
  * @retval None
  */
__STATIC_INLINE void DDL_GPIO_SetPinFilter(GPIO_TypeDef *GPIOx, uint32_t Pin, uint32_t FilterMode)
{
  MODIFY_REG(GPIOx->FLT, Pin, FilterMode);
}

/**
  * @brief  Return gpio filter mode for several pins on dedicated port.
  * @note   Warning: only one pin can be passed as parameter.
  * @param  GPIOx GPIO Port
  * @param  Pin This parameter can be one of the following values:
  *         @arg @ref DDL_GPIO_PIN_6
  * @retval Returned value can be one of the following values:
  *         @arg @ref DDL_GPIO_FITR_PA6_DISABLE
  *         @arg @ref DDL_GPIO_FITR_PA6_ENABLE
  */
__STATIC_INLINE uint32_t DDL_GPIO_GetPinFilter(GPIO_TypeDef *GPIOx, uint32_t Pin)
{
  return (uint32_t)READ_BIT(GPIOx->FLT, Pin);
}

/**
  * @}
  */

/** @defgroup GPIO_DDL_EF_Data_Access Data Access
  * @{
  */

/**
  * @brief  Return full input data register value for a dedicated port.
  * @param  GPIOx GPIO Port
  * @retval Input data register value of port
  */
__STATIC_INLINE uint32_t DDL_GPIO_ReadInputPort(GPIO_TypeDef *GPIOx)
{
  return (uint32_t)(READ_REG(GPIOx->IDATA));
}

/**
  * @brief  Return if input data level for several pins of dedicated port is high or low.
  * @param  GPIOx GPIO Port
  * @param  PinMask This parameter can be a combination of the following values:
  *         @arg @ref DDL_GPIO_PIN_0
  *         @arg @ref DDL_GPIO_PIN_1
  *         @arg @ref DDL_GPIO_PIN_2
  *         @arg @ref DDL_GPIO_PIN_3
  *         @arg @ref DDL_GPIO_PIN_4
  *         @arg @ref DDL_GPIO_PIN_5
  *         @arg @ref DDL_GPIO_PIN_6
  *         @arg @ref DDL_GPIO_PIN_7
  *         @arg @ref DDL_GPIO_PIN_8
  *         @arg @ref DDL_GPIO_PIN_9
  *         @arg @ref DDL_GPIO_PIN_10
  *         @arg @ref DDL_GPIO_PIN_11
  *         @arg @ref DDL_GPIO_PIN_12
  *         @arg @ref DDL_GPIO_PIN_13
  *         @arg @ref DDL_GPIO_PIN_ALL
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_GPIO_IsInputPinSet(GPIO_TypeDef *GPIOx, uint32_t PinMask)
{
  return (READ_BIT(GPIOx->IDATA, PinMask) == (PinMask));
}

/**
  * @brief  Write output data register for the port.
  * @param  GPIOx GPIO Port
  * @param  PortValue Level value for each pin of the port
  * @retval None
  */
__STATIC_INLINE void DDL_GPIO_WriteOutputPort(GPIO_TypeDef *GPIOx, uint32_t PortValue)
{
  WRITE_REG(GPIOx->ODATA, PortValue);
}

/**
  * @brief  Return full output data register value for a dedicated port.
  * @param  GPIOx GPIO Port
  * @retval Output data register value of port
  */
__STATIC_INLINE uint32_t DDL_GPIO_ReadOutputPort(GPIO_TypeDef *GPIOx)
{
  return (uint32_t)(READ_REG(GPIOx->ODATA));
}

/**
  * @brief  Return if input data level for several pins of dedicated port is high or low.
  * @param  GPIOx GPIO Port
  * @param  PinMask This parameter can be a combination of the following values:
  *         @arg @ref DDL_GPIO_PIN_0
  *         @arg @ref DDL_GPIO_PIN_1
  *         @arg @ref DDL_GPIO_PIN_2
  *         @arg @ref DDL_GPIO_PIN_3
  *         @arg @ref DDL_GPIO_PIN_4
  *         @arg @ref DDL_GPIO_PIN_5
  *         @arg @ref DDL_GPIO_PIN_6
  *         @arg @ref DDL_GPIO_PIN_7
  *         @arg @ref DDL_GPIO_PIN_8
  *         @arg @ref DDL_GPIO_PIN_9
  *         @arg @ref DDL_GPIO_PIN_10
  *         @arg @ref DDL_GPIO_PIN_11
  *         @arg @ref DDL_GPIO_PIN_12
  *         @arg @ref DDL_GPIO_PIN_13
  *         @arg @ref DDL_GPIO_PIN_ALL
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_GPIO_IsOutputPinSet(GPIO_TypeDef *GPIOx, uint32_t PinMask)
{
  return (READ_BIT(GPIOx->ODATA, PinMask) == (PinMask));
}

/**
  * @brief  Set several pins to high level on dedicated gpio port.
  * @param  GPIOx GPIO Port
  * @param  PinMask This parameter can be a combination of the following values:
  *         @arg @ref DDL_GPIO_PIN_0
  *         @arg @ref DDL_GPIO_PIN_1
  *         @arg @ref DDL_GPIO_PIN_2
  *         @arg @ref DDL_GPIO_PIN_3
  *         @arg @ref DDL_GPIO_PIN_4
  *         @arg @ref DDL_GPIO_PIN_5
  *         @arg @ref DDL_GPIO_PIN_6
  *         @arg @ref DDL_GPIO_PIN_7
  *         @arg @ref DDL_GPIO_PIN_8
  *         @arg @ref DDL_GPIO_PIN_9
  *         @arg @ref DDL_GPIO_PIN_10
  *         @arg @ref DDL_GPIO_PIN_11
  *         @arg @ref DDL_GPIO_PIN_12
  *         @arg @ref DDL_GPIO_PIN_13
  *         @arg @ref DDL_GPIO_PIN_ALL
  * @retval None
  */
__STATIC_INLINE void DDL_GPIO_SetOutputPin(GPIO_TypeDef *GPIOx, uint32_t PinMask)
{
  WRITE_REG(GPIOx->BSC, PinMask);
}

/**
  * @brief  Set several pins to low level on dedicated gpio port.
  * @param  GPIOx GPIO Port
  * @param  PinMask This parameter can be a combination of the following values:
  *         @arg @ref DDL_GPIO_PIN_0
  *         @arg @ref DDL_GPIO_PIN_1
  *         @arg @ref DDL_GPIO_PIN_2
  *         @arg @ref DDL_GPIO_PIN_3
  *         @arg @ref DDL_GPIO_PIN_4
  *         @arg @ref DDL_GPIO_PIN_5
  *         @arg @ref DDL_GPIO_PIN_6
  *         @arg @ref DDL_GPIO_PIN_7
  *         @arg @ref DDL_GPIO_PIN_8
  *         @arg @ref DDL_GPIO_PIN_9
  *         @arg @ref DDL_GPIO_PIN_10
  *         @arg @ref DDL_GPIO_PIN_11
  *         @arg @ref DDL_GPIO_PIN_12
  *         @arg @ref DDL_GPIO_PIN_13
  *         @arg @ref DDL_GPIO_PIN_ALL
  * @retval None
  */
__STATIC_INLINE void DDL_GPIO_ResetOutputPin(GPIO_TypeDef *GPIOx, uint32_t PinMask)
{
  WRITE_REG(GPIOx->RST, PinMask);
}

/**
  * @brief  Toggle data value for several pin of dedicated port.
  * @param  GPIOx GPIO Port
  * @param  PinMask This parameter can be a combination of the following values:
  *         @arg @ref DDL_GPIO_PIN_0
  *         @arg @ref DDL_GPIO_PIN_1
  *         @arg @ref DDL_GPIO_PIN_2
  *         @arg @ref DDL_GPIO_PIN_3
  *         @arg @ref DDL_GPIO_PIN_4
  *         @arg @ref DDL_GPIO_PIN_5
  *         @arg @ref DDL_GPIO_PIN_6
  *         @arg @ref DDL_GPIO_PIN_7
  *         @arg @ref DDL_GPIO_PIN_8
  *         @arg @ref DDL_GPIO_PIN_9
  *         @arg @ref DDL_GPIO_PIN_10
  *         @arg @ref DDL_GPIO_PIN_11
  *         @arg @ref DDL_GPIO_PIN_12
  *         @arg @ref DDL_GPIO_PIN_13
  *         @arg @ref DDL_GPIO_PIN_ALL
  * @retval None
  */
__STATIC_INLINE void DDL_GPIO_TogglePin(GPIO_TypeDef *GPIOx, uint32_t PinMask)
{
  uint32_t odr = READ_REG(GPIOx->ODATA);
  WRITE_REG(GPIOx->BSC, ((odr & PinMask) << 16u) | (~odr & PinMask));
}

/**
  * @}
  */

#if defined(USE_FULL_DDL_DRIVER)
/** @defgroup GPIO_DDL_EF_Init Initialization and de-initialization functions
  * @{
  */

ErrorStatus DDL_GPIO_DeInit(GPIO_TypeDef *GPIOx);
ErrorStatus DDL_GPIO_Init(GPIO_TypeDef *GPIOx, DDL_GPIO_InitTypeDef *GPIO_InitStruct);
void        DDL_GPIO_StructInit(DDL_GPIO_InitTypeDef *GPIO_InitStruct);

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

#endif /* GPIOA || GPIOB */
/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* G32M3101_DDL_GPIO_H */
