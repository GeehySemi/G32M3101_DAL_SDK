/**
 *
 * @file        g32m3101xx.h
 *
 * @brief       CMSIS G32M3101xx Device Peripheral Access Layer Header File.
 *
 * @version     V1.0.0
 *
 * @date        2025-06-01
 *
 * @attention
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * The original code has been modified by Geehy Semiconductor.
 *
 * Copyright (c) 2017 STMicroelectronics.
 * Copyright (C) 2025 Geehy Semiconductor.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 */

/** @addtogroup CMSIS
  * @{
  */

/** @addtogroup g32m3101xx
  * @{
  */

#ifndef G32M3101_H
#define G32M3101_H

#ifdef __cplusplus
 extern "C" {
#endif /* __cplusplus */

/** @addtogroup Configuration_section_for_CMSIS
  * @{
  */
/**
 * @brief Configuration of the Cortex-M0 Processor and Core Peripherals
 */
#define __CM0PLUS_REV          0x0001U /*!< CM0PLUS Core Revision */
#define __NVIC_PRIO_BITS       2       /*!< Number of Bits used for Priority Levels */
#define __Vendor_SysTickConfig 0       /*!< Set to 1 if different SysTick Config is used      */
#define __VTOR_PRESENT         1       /*!< Set to 1 if cpu supports vector table offset register */
#define __MPU_PRESENT          0       /*!< MPU present */
#define __FPU_PRESENT          0       /*!< FPU present */
/**
  * @}
  */

/** @addtogroup Peripheral_interrupt_number_definition
  * @{
  */

/**
 * @brief Interrupt Number Definition, according to the selected device
 *        in @ref Library_configuration_section
 */
typedef enum
{
/******  Cortex-M0 Processor Exceptions Numbers **************************************************************/
  NonMaskableInt_IRQn         = -14,    /*!< 2 Non Maskable Interrupt                                        */
  HardFault_IRQn              = -13,    /*!< 3 Cortex-M0 Hard Fault Interrupt                                */
  SVC_IRQn                    = -5,     /*!< 11 Cortex-M0 SV Call Interrupt                                  */
  PendSV_IRQn                 = -2,     /*!< 14 Cortex-M0 Pend SV Interrupt                                  */
  SysTick_IRQn                = -1,     /*!< 15 Cortex-M0 System Tick Interrupt                              */
/******  Specific Interrupt Numbers **************************************************************************/
  WWDT_IRQn                   =   0,    /*!< 0  Window Watchdog global interrupt                             */
  PVD_IRQn                    =   1,    /*!< 1  PVD global interrupt                                         */
  LVD_IRQn                    =   2,    /*!< 2  LVD global interrupt                                         */
  FLASH_IRQn                  =   3,    /*!< 3  FLASH global interrupt                                       */
  RCM_IRQn                    =   4,    /*!< 4  RCM global interrupt                                         */
  EINT0_1_IRQn                =   5,    /*!< 5  EINT Line 0 to 1 global interrupt                            */
  EINT2_3_IRQn                =   6,    /*!< 6  EINT Line 2 to 3 global interrupt                            */
  EINT4_13_IRQn               =   7,    /*!< 7  EINT Line 4 to 13 global interrupts                          */
  DMA_Channel0_IRQn           =   9,    /*!< 9  DMA_Channel0 global interrupt                                */
  DMA_Channel1_IRQn           =  10,    /*!< 10 DMA_Channel1 global interrupts                               */
  DMA_Channel2_IRQn           =  11,    /*!< 11 DMA_Channel2 global interrupts                               */
  ADC_IRQn                    =  12,    /*!< 12 ADC global interrupt                                         */
  ATMR_BRK_UP_TRG_COM_IRQn    =  13,    /*!< 13 ATMR_BRK_UP_TRG_COM global interrupt                         */
  ATMR_CC_IRQn                =  14,    /*!< 14 ATMR_CC global interrupt                                     */
  GTMR_IRQn                   =  15,    /*!< 15 GTMR interrupt                                               */
  BTMR_IRQn                   =  17,    /*!< 17 BTMR interrupt                                               */
  LPTMR_IRQn                  =  19,    /*!< 19 LPGTMR interrupt                                             */
  COMP0_1_IRQn                =  21,    /*!< 21 COMP global interrupt                                        */
  SPI_IRQn                    =  25,    /*!< 25 SPI global interrupt                                         */
  UART0_IRQn                  =  27,    /*!< 27 UART0 global interrupt                                       */
  UART1_IRQn                  =  28     /*!< 28 UART1 global interrupt                                       */
} IRQn_Type;

/**
  * @}
  */

#include "core_cm0plus.h"         /* ARM Cortex-M0+ processor and core peripherals */
#include "system_g32m3101.h"      /* G32M3101 System */
#include <stdint.h>

/** @addtogroup Peripheral_registers_structures
  * @{
  */

/**
  * @brief Timer (TMR)
  */

typedef struct {                                /*!< (@ 0x40000000) TIMER Structure                                            */
  __IO uint32_t  CTRL1;                         /*!< (@ 0x00000000) control register 1                                         */
  __IO uint32_t  CTRL2;                         /*!< (@ 0x00000004) control register 2                                         */
  __IO uint32_t  SMCTRL;                        /*!< (@ 0x00000008) slave mode control register                                */
  __IO uint32_t  DIEN;                          /*!< (@ 0x0000000C) DMA/Interrupt enable register                              */
  __IO uint32_t  STS;                           /*!< (@ 0x00000010) status register                                            */
  __IO uint32_t  CEG;                           /*!< (@ 0x00000014) event generation register                                  */
  __IO uint32_t  CCM1;                          /*!< (@ 0x00000018) capture/compare mode register 1                            */
  __IO uint32_t  CCM2;                          /*!< (@ 0x0000001C) capture/compare mode register 2                            */
  __IO uint32_t  CCEN;                          /*!< (@ 0x00000020) capture/compare enable register                            */
  __IO uint32_t  CNT;                           /*!< (@ 0x00000024) counter                                                    */
  __IO uint32_t  PSC;                           /*!< (@ 0x00000028) prescaler                                                  */
  __IO uint32_t  AUTORLD;                       /*!< (@ 0x0000002C) auto-reload register                                       */
  __IO uint32_t  REPCNT;                        /*!< (@ 0x00000030) repetition counter register                                */
  __IO uint32_t  CC0;                           /*!< (@ 0x00000034) capture/compare register 0                                 */
  __IO uint32_t  CC1;                           /*!< (@ 0x00000038) capture/compare register 1                                 */
  __IO uint32_t  CC2;                           /*!< (@ 0x0000003C) capture/compare register 2                                 */
  __IO uint32_t  CC3;                           /*!< (@ 0x00000040) capture/compare register 3                                 */
  __IO uint32_t  BDT;                           /*!< (@ 0x00000044) break and dead-time register                               */
  __IO uint32_t  OUTPUTCTRL1;                   /*!< (@ 0x00000048) Output ctrl register 1                                     */
  __IO uint32_t  OUTPUTCTRL2;                   /*!< (@ 0x0000004C) Output ctrl register 2                                     */
  __IO uint32_t  CH4CFG;                        /*!< (@ 0x00000050) Channel 4 configuration                                    */
  __IO uint32_t  TRGOCR;                        /*!< (@ 0x00000054) TRGO control register                                      */
  __IO uint32_t  BREAK;                         /*!< (@ 0x00000058) BREAK Filter register                                      */
  __IO uint32_t  CC4;                           /*!< (@ 0x0000005C) Capture/Compare register 4                                 */
  __IO uint32_t  OCXAEN;                        /*!< (@ 0x00000060) Compare register to control register                       */
  __IO uint32_t  CC0C;                          /*!< (@ 0x00000064) Channel 0 comparison register                              */
  __IO uint32_t  CC1C;                          /*!< (@ 0x00000068) Channel 1 comparison register                              */
  __IO uint32_t  CC2C;                          /*!< (@ 0x0000006C) Channel 2 comparison register                              */
} ATMR_TypeDef;

/**
  * @brief Timer (TMR)
  */

typedef struct {                                /*!< (@ 0x40000000) TIMER Structure                                            */
  __IO uint32_t  CTRL1;                         /*!< (@ 0x00000000) control register 1                                         */
  __IO uint32_t  CTRL2;                         /*!< (@ 0x00000004) control register 2                                         */
  __IO uint32_t  SMCTRL;                        /*!< (@ 0x00000008) slave mode control register                                */
  __IO uint32_t  DIEN;                          /*!< (@ 0x0000000C) DMA/Interrupt enable register                              */
  __IO uint32_t  STS;                           /*!< (@ 0x00000010) status register                                            */
  __IO uint32_t  CEG;                           /*!< (@ 0x00000014) event generation register                                  */
  __IO uint32_t  CCM1;                          /*!< (@ 0x00000018) capture/compare mode register 1                            */
  __IO uint32_t  CCM2;                          /*!< (@ 0x0000001C) capture/compare mode register 2                            */
  __IO uint32_t  CCEN;                          /*!< (@ 0x00000020) capture/compare enable register                            */
  __IO uint32_t  CNT;                           /*!< (@ 0x00000024) counter                                                    */
  __IO uint32_t  PSC;                           /*!< (@ 0x00000028) prescaler                                                  */
  __IO uint32_t  AUTORLD;                       /*!< (@ 0x0000002C) auto-reload register                                       */
        uint32_t  RESERVED;                      /*!< (@ 0x00000030) reserved                                                   */
  __IO uint32_t  CC0;                           /*!< (@ 0x00000034) capture/compare register 0                                 */
  __IO uint32_t  CC1;                           /*!< (@ 0x00000038) capture/compare register 1                                 */
  __IO uint32_t  CC2;                           /*!< (@ 0x0000003C) capture/compare register 2                                 */
  __IO uint32_t  CC3;                           /*!< (@ 0x00000040) capture/compare register 3                                 */
} GTMR_TypeDef;

/**
  * @brief Base timer (BTMR)
  */

typedef struct
{
  __IO uint32_t  CTRL1;   /*!< BTMR control register 1,         Address offset: 0x00 */
  __IO uint32_t  CCM1;    /*!< BTMR channel control register 1, Address offset: 0x04 */
  __IO uint32_t  CCM2;    /*!< BTMR channel control register 2, Address offset: 0x08 */
  __IO uint32_t  CEG;     /*!< BTMR event generation register,  Address offset: 0x0C */
  __IO uint32_t  IEN;     /*!< BTMR interrupt enable register,  Address offset: 0x10 */
  __IO uint32_t  STS;     /*!< BTMR status register,            Address offset: 0x14 */
  __IO uint32_t  CNT;     /*!< BTMR counter,                    Address offset: 0x18 */
  __IO uint32_t  PSC;     /*!< BTMR prescaler,                  Address offset: 0x1C */
  __IO uint32_t  AUTORLD; /*!< BTMR auto-reload register,       Address offset: 0x20 */
  __IO uint32_t  CC0;     /*!< BTMR capture/compare register 0, Address offset: 0x24 */
  __IO uint32_t  CC1;     /*!< BTMR capture/compare register 1, Address offset: 0x28 */
  __IO uint32_t  CC2;     /*!< BTMR capture/compare register 2, Address offset: 0x2C */
} BTMR_TypeDef;

/**
  * @brief Serial peripheral interface (SPI)
  */

typedef struct
{
  __IO uint32_t  CTRL1; /*!< SPI control register 1, Address offset: 0x00 */
  __IO uint32_t  CTRL2; /*!< SPI control register 2, Address offset: 0x04 */
  __IO uint32_t  STS;   /*!< SPI status register,    Address offset: 0x08 */
  __IO uint32_t  DATA;  /*!< SPI data register,      Address offset: 0x0C */
} SPI_TypeDef;

/**
  * @brief Universal asynchronous receiver transmitter (USART)
  */

typedef struct
{
  __IO uint32_t  STS;     /*!< USART Status register,                   Address offset: 0x00 */
  __IO uint32_t  DATA;    /*!< USART Data register,                     Address offset: 0x04 */
  __IO uint32_t  BR;      /*!< USART Baud rate register,                Address offset: 0x08 */
  __IO uint32_t  CTRL1;   /*!< USART Control register 1,                Address offset: 0x0C */
  __IO uint32_t  CTRL2;   /*!< USART Control register 2,                Address offset: 0x10 */
  __IO uint32_t  CTRL3;   /*!< USART Control register 3,                Address offset: 0x14 */
        uint32_t  RESERVED;/*!< Reserved                                                      */
  __IO uint32_t  RXTO;    /*!< USART Guard time and prescaler register, Address offset: 0x1C */
} USART_TypeDef;

/**
  * @brief Comparator (COMP)
  */

typedef struct
{
  __IO uint32_t  CSTS;    /*!< COMP control register, Address offset: 0x00 */
        uint32_t RESERVED; /*!< Reserved                                    */
  __IO uint32_t  STS;     /*!< COMP status register,  Address offset: 0x08 */
} COMP_TypeDef;

/**
  * @brief Window watchdog (WWDT)
  */

typedef struct
{
  __IO uint32_t  CTRL;  /*!< WWDT control register,       Address offset: 0x00 */
  __IO uint32_t  CFG;   /*!< WWDT configuration register, Address offset: 0x04 */
  __IO uint32_t  STS;   /*!< WWDT status register,        Address offset: 0x08 */
} WWDT_TypeDef;

/**
  * @brief IWDG (IWDG)
  */

typedef struct
{
  __IO uint32_t  KEY;     /*!< IWDT key register,       Address offset: 0x00 */
  __IO uint32_t  PSC;     /*!< IWDT prescaler register, Address offset: 0x04 */
  __IO uint32_t  CNTRLD;  /*!< IWDT reload register,    Address offset: 0x08 */
  __IO uint32_t  STS;     /*!< IWDT status register,    Address offset: 0x0C */
} IWDT_TypeDef;

/**
  * @brief EINT (EINT)
  */

typedef struct
{
  __IO uint32_t  IMASK;  /*!< EINT interrupt mask register,                          Address offset: 0x00 */
  __IO uint32_t  EMASK;  /*!< EINT event mask register,                              Address offset: 0x04 */
  __IO uint32_t  RTEN;   /*!< EINT rising edge trigger select register,              Address offset: 0x08 */
  __IO uint32_t  FTEN;   /*!< EINT falling edge trigger select register,             Address offset: 0x0C */
  __IO uint32_t  SWINTE; /*!< EINT software interrupt event trigger select register, Address offset: 0x10 */
  __IO uint32_t  IPEND;  /*!< EINT interrupt pending register,                       Address offset: 0x14 */
  __IO uint32_t  CFG[2]; /*!< EINT configuration register,                           Address offset: 0x18 */
} EINT_TypeDef;

/**
  * @brief LPTMR (LPTMR)
  */

typedef struct
{
  __IO uint32_t  CTRL;  /*!< LPTMR control register,      Address offset: 0x00 */
  __IO uint32_t  PSC;   /*!< LPTMR prescaler register,    Address offset: 0x04 */
  __IO uint32_t  WUPV;  /*!< LPTMR wakeup value register, Address offset: 0x08 */
  __IO uint32_t  STS;   /*!< LPTMR status register,       Address offset: 0x0C */
  __IO uint32_t  CNT;   /*!< LPTMR count register,        Address offset: 0x10 */
} LPTMR_TypeDef;

/**
  * @brief Analog-to-digital converter (ADC)
  */

typedef struct
{
  __IO uint32_t  ISR;          /*!< ADC interrupt and status register,   Address offset: 0x00 */
  __IO uint32_t  IER;          /*!< ADC interrupt enable register,       Address offset: 0x04 */
  __IO uint32_t  CR;           /*!< ADC control register,                Address offset: 0x08 */
  __IO uint32_t  CFGR1;        /*!< ADC configuration register 1,        Address offset: 0x0C */
  __IO uint32_t  CFGR2;        /*!< ADC configuration register 2,        Address offset: 0x10 */
  __IO uint32_t  SMPR1;        /*!< ADC sampling time register 1,        Address offset: 0x14 */
        uint32_t  RESERVED1;    /*!< Reserved,                            Address offset: 0x18 */
  __IO uint32_t  CFGR3;        /*!< ADC configuration register 3,        Address offset: 0x1C */
        uint32_t  RESERVED2[3]; /*!< Reserved,                            Address offset: 0x20 */
  __IO uint32_t  SQR1;         /*!< ADC sequence register 1,             Address offset: 0x2C */
  __IO uint32_t  SQR2;         /*!< ADC sequence register 2,             Address offset: 0x30 */
  __IO uint32_t  SQR3;         /*!< ADC sequence register 3,             Address offset: 0x34 */
  __IO uint32_t  DR;           /*!< ADC regular data converted register, Address offset: 0x38 */
  __IO uint32_t  DATA0;        /*!< ADC data register 0,                 Address offset: 0x3C */
  __IO uint32_t  DATA1;        /*!< ADC data register 1,                 Address offset: 0x40 */
  __IO uint32_t  DATA2;        /*!< ADC data register 2,                 Address offset: 0x44 */
  __IO uint32_t  DATA3;        /*!< ADC data register 3,                 Address offset: 0x48 */
  __IO uint32_t  DATA4;        /*!< ADC data register 4,                 Address offset: 0x4C */
  __IO uint32_t  DATA5;        /*!< ADC data register 5,                 Address offset: 0x50 */
  __IO uint32_t  DATA6;        /*!< ADC data register 6,                 Address offset: 0x54 */
  __IO uint32_t  DATA7;        /*!< ADC data register 7,                 Address offset: 0x58 */
  __IO uint32_t  SEQ_NUM;      /*!< ADC sequence number register,        Address offset: 0x5C */
        uint32_t  RESERVED3[9]; /*!< Reserved,                            Address offset: 0x60 */
  __IO uint32_t  TMR;          /*!< ADC TMR register,                    Address offset: 0x84 */
} ADC_TypeDef;

/**
  * @brief DMA (DMA)
  */

typedef struct
{
  __IO uint32_t SCFG;   /*!< DMA channel x configuration register,      Address offset: 0x00 */
  __IO uint32_t NDATA;  /*!< DMA channel x number of data register,     Address offset: 0x04 */
  __IO uint32_t PADDR;  /*!< DMA channel x peripheral address register, Address offset: 0x08 */
  __IO uint32_t M0ADDR; /*!< DMA channel x memory 0 address register,   Address offset: 0x0C */
  __IO uint32_t M1ADDR; /*!< DMA channel x memory 1 address register,   Address offset: 0x10 */
  __IO uint32_t FCTRL;  /*!< DMA channel x FIFO control register,       Address offset: 0x14 */
} DMA_Channel_TypeDef;

typedef struct
{
  __IO uint32_t  LINTSTS;  /*!< DMA low interrupt status register,     Address offset: 0x00 */
        uint32_t  RESERVED; /*!< Reserved,                              Address offset: 0x04 */
  __IO uint32_t  LIFCLR;   /*!< DMA low interrupt flag clear register, Address offset: 0x08 */
} DMA_TypeDef;

/**
  * @brief SCU (SCU)
  */

typedef struct
{
  __IO uint32_t  KEY;          /*!< SCU KEY register,                      Address offset: 0x00 */
  __IO uint32_t  RCCR;         /*!< SCU clock control register,            Address offset: 0x04 */
  __IO uint32_t  SCCR;         /*!< SCU system clock control register,     Address offset: 0x08 */
  __IO uint32_t  CIER;         /*!< SCU clock interrupt enable register,   Address offset: 0x0C */
  __IO uint32_t  CICR;         /*!< SCU clock interrupt flag register,     Address offset: 0x10 */
  __IO uint32_t  AHBRST;       /*!< SCU AHBRST register,                   Address offset: 0x14 */
  __IO uint32_t  APBRST;       /*!< SCU APBRST register,                   Address offset: 0x18 */
  __IO uint32_t  AHBCG;        /*!< SCU AHBCG register,                    Address offset: 0x1C */
  __IO uint32_t  APBCG;        /*!< SCU APBCG register,                    Address offset: 0x20 */
        uint32_t  RESERVED;     /*!< Reserved,                              Address offset: 0x24 */
  __IO uint32_t  RSTCSR;       /*!< SCU reset control ans status register, Address offset: 0x28 */
  __IO uint32_t  ADCCR;        /*!< SCU ADC control register,              Address offset: 0x2C */
  __IO uint32_t  OPAMPCR;      /*!< SCU OPA control register,              Address offset: 0x30 */
        uint32_t  RESERVED1[2]; /*!< Reserved,                              Address offset: 0x34 */
  __IO uint32_t  PVDCSR;       /*!< SCU PVD control register,              Address offset: 0x3C */
  __IO uint32_t  PREDRVCR;     /*!< SCU PREDRV control register,           Address offset: 0x40 */
  __IO uint32_t  LVDCSR;       /*!< SCU LVD control and status register,   Address offset: 0x44 */
} SCU_TypeDef;

/**
  * @brief CRC (CRC)
  */

typedef struct
{
  __IO uint32_t  DATA;     /*!< CRC DATA register,         Address offset: 0x00 */
  __IO uint32_t  CTRL;     /*!< CRC control register,      Address offset: 0x04 */
  __IO uint32_t  INITVAL;  /*!< CRC initial data register, Address offset: 0x08 */
} CRC_TypeDef;

/**
  * @brief DIV (DIV)
  */

typedef struct
{
  __IO uint32_t  DVDR;  /*!<DIV Dividend register, Address offset: 0x00 */
  __IO uint32_t  DVSR;  /*!<DIV Divisor Register,  Address offset: 0x04 */
  __IO uint32_t  QUOTR; /*!<DIV Quotient register, Address offset: 0x08 */
  __IO uint32_t  RMDR;  /*!<DIV Residual register, Address offset: 0x0C */
        uint32_t  RESERVED;
  __IO uint32_t  CR;    /*!<DIV Control  register, Address offset: 0x14 */
} DIV_TypeDef;

/**
  * @brief GPIO (GPIO)
  */

typedef struct
{
  __IO uint32_t  MODE;      /*!< GPIO port mode register,               Address offset: 0x00 */
  __IO uint32_t  IEN;       /*!< GPIO port input enable register,       Address offset: 0x04 */
  __IO uint32_t  ITYPCFG;   /*!< GPIO port xxxxx        register,       Address offset: 0x08 */
  __IO uint32_t  PUPD;      /*!< GPIO port pull-up/pull-down register,  Address offset: 0x0C */
  __IO uint32_t  OTYPCFG;   /*!< GPIO port output type register,        Address offset: 0x10 */
  __IO uint32_t  DCFG;      /*!< GPIO port drive select register,       Address offset: 0x14 */
  __IO uint32_t  IDATA;     /*!< GPIO port input data register,         Address offset: 0x18 */
  __IO uint32_t  ODATA;     /*!< GPIO port output data register,        Address offset: 0x1C */
  __IO uint32_t  BSC;       /*!< GPIO port bit set/reset register,      Address offset: 0x20 */
  __IO uint32_t  RST;       /*!< GPIO port bit reset register,          Address offset: 0x24 */
  __IO uint32_t  LOCK;      /*!< GPIO port configuration lock register, Address offset: 0x28 */
  __IO uint32_t  ALFSEL[2]; /*!< GPIO alternate function low registers, Address offset: 0x2C */
  __IO uint32_t  FLT;       /*!< GPIO filter register,                  Address offset: 0x34 */
} GPIO_TypeDef;

/**
  * @brief Flash memory controller (FLASH)
  */

typedef struct
{
  __IO uint32_t  RKEY;      /*!< FLASH register key register, Address offset: 0x00 */
  __IO uint32_t  MKEY;      /*!< FLASH memory key register,   Address offset: 0x04 */
        uint32_t  RESERVED1; /*!< Reserved,                    Address offset: 0x08 */
  __IO uint32_t  NVR5KEY;   /*!< FLASH NVR5 key register,     Address offset: 0x0C */
        uint32_t  RESERVED2; /*!< Reserved,                    Address offset: 0x10 */
  __IO uint32_t  CR;        /*!< FLASH control register,      Address offset: 0x14 */
  __IO uint32_t  ER;        /*!< FLASH error register,        Address offset: 0x18 */
  __IO uint32_t  SR;        /*!< FLASH status register,       Address offset: 0x1C */
} FLASH_TypeDef;

/**
  * @}
  */

/** @addtogroup Peripheral_memory_map
  * @{
  */

#define FLASH_BASE              ((uint32_t)0x00000000)  /*!< FLASH base address in the alias region      */
#define FLASH_END               ((uint32_t)0x0000FFFF)  /*!< FLASH end address                           */
#define NVR0_4_BASE             ((uint32_t)0x00100000)  /*!< NVR0_4 base address in the alias region     */
#define NVR0_4_END              ((uint32_t)0x001009FF)  /*!< NVR0_4 end address                          */
#define NVR5_BASE               ((uint32_t)0x00100A00)  /*!< NVR5 base address in the alias region       */
#define NVR5_END                ((uint32_t)0x00100BFF)  /*!< NVR5 end address                            */
#define NVR6_BASE               ((uint32_t)0x00100C00)  /*!< NVR6 base address in the alias region       */
#define NVR6_END                ((uint32_t)0x00100DFF)  /*!< NVR6 end address                            */
#define NVR7_BASE               ((uint32_t)0x00100E00)  /*!< NVR7 base address in the alias region       */
#define NVR7_END                ((uint32_t)0x00100FFF)  /*!< NVR7 end address                            */
#define SRAM_BASE               ((uint32_t)0x20000000)  /*!< SRAM base address in the alias region       */
#define SRAM_END                ((uint32_t)0x20001FFF)  /*!< SRAM end address                            */
#define PERIPH_BASE             ((uint32_t)0x40000000)  /*!< Peripheral base address in the alias region */

/* Peripheral memory map */
#define APB1PERIPH_BASE           PERIPH_BASE
#define AHB1PERIPH_BASE          (PERIPH_BASE + 0x00020000)

/*!< APB peripherals */
#define ATIMER_BASE             (APB1PERIPH_BASE + 0x0000UL)
#define GTIMER_BASE             (APB1PERIPH_BASE + 0x1000UL)
#define BTIMER_BASE             (APB1PERIPH_BASE + 0x2000UL)
#define SPI_BASE                (APB1PERIPH_BASE + 0x3000UL)
#define UART0_BASE              (APB1PERIPH_BASE + 0x4000UL)
#define UART1_BASE              (APB1PERIPH_BASE + 0x5000UL)
#define COMP0_BASE              (APB1PERIPH_BASE + 0x6000UL)
#define COMP1_BASE              (APB1PERIPH_BASE + 0x6004UL)
#define WWDT_BASE               (APB1PERIPH_BASE + 0x7000UL)
#define IWDT_BASE               (APB1PERIPH_BASE + 0x8000UL)
#define EINT_BASE               (APB1PERIPH_BASE + 0x9000UL)
#define LPTMR_BASE              (APB1PERIPH_BASE + 0xA000UL)
#define ADC_BASE                (APB1PERIPH_BASE + 0xB000UL)

/*!< AHB peripherals */
#define DMA_BASE                (AHB1PERIPH_BASE + 0x0000UL)
#define DMA_Channel0_BASE       (DMA_BASE + 0x010UL)
#define DMA_Channel1_BASE       (DMA_BASE + 0x028UL)
#define DMA_Channel2_BASE       (DMA_BASE + 0x040UL)
#define SCU_BASE                (AHB1PERIPH_BASE + 0x0400UL)
#define FLASH_R_BASE            (AHB1PERIPH_BASE + 0x0800UL)
#define CRC_BASE                (AHB1PERIPH_BASE + 0x0C00UL)
#define DIV_BASE                (AHB1PERIPH_BASE + 0x1000UL)
#define GPIOA_BASE              (AHB1PERIPH_BASE + 0x1400UL)
#define GPIOB_BASE              (AHB1PERIPH_BASE + 0x1800UL)

#define UID_BASE                0x100E88           /*!< UID register base address */
#define PID_BASE                0x100D80           /*!< PID register base address */
#define VSENSOR_CAL_BASE        0x100C14           /*!< Vsensor calibration register base address */
/**
  * @}
  */


/** @addtogroup Peripheral_declaration
  * @{
  */
#define ATMR                    ((ATMR_TypeDef*)              ATIMER_BASE)
#define GTMR                    ((GTMR_TypeDef*)              GTIMER_BASE)
#define BTMR                    ((BTMR_TypeDef*)              BTIMER_BASE)
#define SPI                     ((SPI_TypeDef*)               SPI_BASE)
#define UART0                   ((USART_TypeDef*)             UART0_BASE)
#define UART1                   ((USART_TypeDef*)             UART1_BASE)
#define COMP0                   ((COMP_TypeDef*)              COMP0_BASE)
#define COMP1                   ((COMP_TypeDef*)              COMP1_BASE)
#define WWDT                    ((WWDT_TypeDef*)              WWDT_BASE)
#define IWDT                    ((IWDT_TypeDef*)              IWDT_BASE)
#define EINT                    ((EINT_TypeDef*)              EINT_BASE)
#define LPTMR                   ((LPTMR_TypeDef*)             LPTMR_BASE)
#define ADC                     ((ADC_TypeDef*)               ADC_BASE)
#define DMA                     ((DMA_TypeDef*)               DMA_BASE)
#define DMA_Channel0            ((DMA_Channel_TypeDef *)      DMA_Channel0_BASE)
#define DMA_Channel1            ((DMA_Channel_TypeDef *)      DMA_Channel1_BASE)
#define DMA_Channel2            ((DMA_Channel_TypeDef *)      DMA_Channel2_BASE)
#define SCU                     ((SCU_TypeDef*)               SCU_BASE)
#define CRC                     ((CRC_TypeDef*)               CRC_BASE)
#define DIV                     ((DIV_TypeDef*)               DIV_BASE)
#define GPIOA                   ((GPIO_TypeDef*)              GPIOA_BASE)
#define GPIOB                   ((GPIO_TypeDef*)              GPIOB_BASE)
#define FLASH                   ((FLASH_TypeDef*)             FLASH_R_BASE)

/**
  * @}
  */

/** @addtogroup Exported_constants
  * @{
  */

/** @addtogroup Hardware_Constant_Definition
  * @{
  */
#define LSI_STARTUP_TIME                130U /*!< LSI Maximum startup time in us */

/**
  * @}
  */

/** @addtogroup Peripheral_Registers_Bits_Definition
  * @{
  */

/******************************************************************************/
/*                         Peripheral Registers_Bits_Definition               */
/******************************************************************************/

/******************************************************************************/
/*                                                                            */
/*                        Analog to Digital Converter                         */
/*                                                                            */
/******************************************************************************/
/********************  Bit definition for ADC_ISR register  *******************/
#define ADC_ISR_RDY_Pos                       (0U)
#define ADC_ISR_RDY_Msk                       (0x1UL << ADC_ISR_RDY_Pos)                        /*!< 0x00000001 */
#define ADC_ISR_RDY                           ADC_ISR_RDY_Msk
#define ADC_ISR_EOSMP_Pos                     (1U)
#define ADC_ISR_EOSMP_Msk                     (0x1UL << ADC_ISR_EOSMP_Pos)                      /*!< 0x00000002 */
#define ADC_ISR_EOSMP                         ADC_ISR_EOSMP_Msk                                 /*!< ADC group regular end of sampling flag */
#define ADC_ISR_EOC_Pos                       (2U)
#define ADC_ISR_EOC_Msk                       (0x1UL << ADC_ISR_EOC_Pos)                        /*!< 0x00000004 */
#define ADC_ISR_EOC                           ADC_ISR_EOC_Msk                                   /*!< ADC group regular end of unitary conversion flag */
#define ADC_ISR_EOS_Pos                       (3U)
#define ADC_ISR_EOS_Msk                       (0x1UL << ADC_ISR_EOS_Pos)                        /*!< 0x00000008 */
#define ADC_ISR_EOS                           ADC_ISR_EOS_Msk                                   /*!< ADC group regular end of sequence conversions flag */
#define ADC_ISR_OVR_Pos                       (4U)
#define ADC_ISR_OVR_Msk                       (0x1UL << ADC_ISR_OVR_Pos)                        /*!< 0x00000010 */
#define ADC_ISR_OVR                           ADC_ISR_OVR_Msk                                   /*!< ADC group regular overrun flag */
#define ADC_ISR_SEQ_NUM1_FIN_Pos              (8U)
#define ADC_ISR_SEQ_NUM1_FIN_Msk              (0x1UL << ADC_ISR_SEQ_NUM1_FIN_Pos)               /*!< 0x00000100 */
#define ADC_ISR_SEQ_NUM1_FIN                  ADC_ISR_SEQ_NUM1_FIN_Msk                          /*!< NUM.1 of sequential section sampling finish */
#define ADC_ISR_SEQ_NUM2_FIN_Pos              (9U)
#define ADC_ISR_SEQ_NUM2_FIN_Msk              (0x1UL << ADC_ISR_SEQ_NUM2_FIN_Pos)               /*!< 0x00000200 */
#define ADC_ISR_SEQ_NUM2_FIN                  ADC_ISR_SEQ_NUM2_FIN_Msk                          /*!< NUM.2 of sequential section sampling finish */
#define ADC_ISR_SEQ_NUM3_FIN_Pos              (10U)
#define ADC_ISR_SEQ_NUM3_FIN_Msk              (0x1UL << ADC_ISR_SEQ_NUM3_FIN_Pos)               /*!< 0x00000400 */
#define ADC_ISR_SEQ_NUM3_FIN                  ADC_ISR_SEQ_NUM3_FIN_Msk                          /*!< NUM.3 of sequential section sampling finish */

/********************  Bit definition for ADC_IER register  *******************/
#define ADC_IER_RDYIE_Pos                     (0U)
#define ADC_IER_RDYIE_Msk                     (0x1UL << ADC_IER_RDYIE_Pos)                      /*!< 0x00000001 */
#define ADC_IER_RDYIE                         ADC_IER_RDYIE_Msk
#define ADC_IER_EOSMPIE_Pos                   (1U)
#define ADC_IER_EOSMPIE_Msk                   (0x1UL << ADC_IER_EOSMPIE_Pos)                    /*!< 0x00000002 */
#define ADC_IER_EOSMPIE                       ADC_IER_EOSMPIE_Msk                               /*!< ADC group regular end of sampling interrupt */
#define ADC_IER_EOCIE_Pos                     (2U)
#define ADC_IER_EOCIE_Msk                     (0x1UL << ADC_IER_EOCIE_Pos)                      /*!< 0x00000004 */
#define ADC_IER_EOCIE                         ADC_IER_EOCIE_Msk                                 /*!< ADC group regular end of unitary conversion interrupt */
#define ADC_IER_EOSIE_Pos                     (3U)
#define ADC_IER_EOSIE_Msk                     (0x1UL << ADC_IER_EOSIE_Pos)                      /*!< 0x00000008 */
#define ADC_IER_EOSIE                         ADC_IER_EOSIE_Msk                                 /*!< ADC group regular end of sequence conversions interrupt */
#define ADC_IER_OVRIE_Pos                     (4U)
#define ADC_IER_OVRIE_Msk                     (0x1UL << ADC_IER_OVRIE_Pos)                      /*!< 0x00000010 */
#define ADC_IER_OVRIE                         ADC_IER_OVRIE_Msk                                 /*!< ADC group regular overrun interrupt */
#define ADC_IER_SEQ_NUM1_FINIE_Pos            (8U)
#define ADC_IER_SEQ_NUM1_FINIE_Msk            (0x1UL << ADC_IER_SEQ_NUM1_FINIE_Pos)             /*!< 0x00000100 */
#define ADC_IER_SEQ_NUM1_FINIE                ADC_IER_SEQ_NUM1_FINIE_Msk                        /*!< NUM.1 of sequential section sampling finish interrupt*/
#define ADC_IER_SEQ_NUM2_FINIE_Pos            (9U)
#define ADC_IER_SEQ_NUM2_FINIE_Msk            (0x1UL << ADC_IER_SEQ_NUM2_FINIE_Pos)             /*!< 0x00000200 */
#define ADC_IER_SEQ_NUM2_FINIE                ADC_IER_SEQ_NUM2_FINIE_Msk                        /*!< NUM.2 of sequential section sampling finish interrupt*/
#define ADC_IER_SEQ_NUM3_FINIE_Pos            (10U)
#define ADC_IER_SEQ_NUM3_FINIE_Msk            (0x1UL << ADC_IER_SEQ_NUM3_FINIE_Pos)             /*!< 0x00000400 */
#define ADC_IER_SEQ_NUM3_FINIE                ADC_IER_SEQ_NUM3_FINIE_Msk                        /*!< NUM.3 of sequential section sampling finish interrupt*/

/********************  Bit definition for ADC_CR register  ********************/
#define ADC_CR_ADEN_Pos                       (0U)
#define ADC_CR_ADEN_Msk                       (0x1UL << ADC_CR_ADEN_Pos)                        /*!< 0x00000001 */
#define ADC_CR_ADEN                           ADC_CR_ADEN_Msk                                   /*!< ADC enable */
#define ADC_CR_ADSTART_Pos                    (2U)
#define ADC_CR_ADSTART_Msk                    (0x1UL << ADC_CR_ADSTART_Pos)                     /*!< 0x00000004 */
#define ADC_CR_ADSTART                        ADC_CR_ADSTART_Msk                                /*!< ADC group regular conversion start */
#define ADC_CR_ADSTP_Pos                      (4U)
#define ADC_CR_ADSTP_Msk                      (0x1UL << ADC_CR_ADSTP_Pos)                       /*!< 0x00000010 */
#define ADC_CR_ADSTP                          ADC_CR_ADSTP_Msk                                  /*!< ADC group regular conversion stop */
#define ADC_CR_VREF_SEL_Pos                   (31U)
#define ADC_CR_VREF_SEL_Msk                   (0x1UL << ADC_CR_VREF_SEL_Pos)                    /*!< 0x80000000 */
#define ADC_CR_VREF_SEL                       ADC_CR_VREF_SEL_Msk

/********************  Bit definition for ADC_CFGR1 register  ******************/
#define ADC_CFGR1_DMAEN_Pos                   (0U)
#define ADC_CFGR1_DMAEN_Msk                   (0x1UL << ADC_CFGR1_DMAEN_Pos)                    /*!< 0x00000001 */
#define ADC_CFGR1_DMAEN                       ADC_CFGR1_DMAEN_Msk                               /*!< ADC DMA transfer enable */
#define ADC_CFGR1_DMACFG_Pos                  (1U)
#define ADC_CFGR1_DMACFG_Msk                  (0x1UL << ADC_CFGR1_DMACFG_Pos)                   /*!< 0x00000002 */
#define ADC_CFGR1_DMACFG                      ADC_CFGR1_DMACFG_Msk                              /*!< ADC DMA transfer configuration */
#define ADC_CFGR1_ALIGN_Pos                   (5U)                                              /*!< 0x00000020>*/
#define ADC_CFGR1_ALIGN_Msk                   (0x1UL << ADC_CFGR1_ALIGN_Pos)                    /*!< Data alignment*/
#define ADC_CFGR1_ALIGN                       ADC_CFGR1_ALIGN_Msk
#define ADC_CFGR1_EXTSEL1_Pos                 (6U)
#define ADC_CFGR1_EXTSEL1_Msk                 (0x7UL << ADC_CFGR1_EXTSEL1_Pos)                  /*!< 0x000001C0 */
#define ADC_CFGR1_EXTSEL1                     ADC_CFGR1_EXTSEL1_Msk                             /*!< ADC group regular external trigger source */
#define ADC_CFGR1_EXTSEL1_0                   (0x1UL << ADC_CFGR1_EXTSEL1_Pos)                  /*!< 0x00000040 */
#define ADC_CFGR1_EXTSEL1_1                   (0x2UL << ADC_CFGR1_EXTSEL1_Pos)                  /*!< 0x00000080 */
#define ADC_CFGR1_EXTSEL1_2                   (0x4UL << ADC_CFGR1_EXTSEL1_Pos)                  /*!< 0x00000100 */
#define ADC_CFGR1_EXTEN1_Pos                  (10U)
#define ADC_CFGR1_EXTEN1_Msk                  (0x3UL << ADC_CFGR1_EXTEN1_Pos)                   /*!< 0x00000C00 */
#define ADC_CFGR1_EXTEN1                      ADC_CFGR1_EXTEN1_Msk                              /*!< ADC group regular external trigger polarity */
#define ADC_CFGR1_EXTEN1_0                    (0x1UL << ADC_CFGR1_EXTEN1_Pos)                   /*!< 0x00000400 */
#define ADC_CFGR1_EXTEN1_1                    (0x2UL << ADC_CFGR1_EXTEN1_Pos)                   /*!< 0x00000800 */
#define ADC_CFGR1_OVRMOD_Pos                  (12U)
#define ADC_CFGR1_OVRMOD_Msk                  (0x1UL << ADC_CFGR1_OVRMOD_Pos)                   /*!< 0x00001000 */
#define ADC_CFGR1_OVRMOD                      ADC_CFGR1_OVRMOD_Msk                              /*!< ADC group regular overrun configuration */
#define ADC_CFGR1_CONT_Pos                    (13U)
#define ADC_CFGR1_CONT_Msk                    (0x1UL << ADC_CFGR1_CONT_Pos)                     /*!< 0x00002000 */
#define ADC_CFGR1_CONT                        ADC_CFGR1_CONT_Msk                                /*!< ADC group regular continuous conversion mode */
#define ADC_CFGR1_AUTDLY_Pos                  (14U)
#define ADC_CFGR1_AUTDLY_Msk                  (0x1UL << ADC_CFGR1_AUTDLY_Pos)                   /*!< 0x00004000 */
#define ADC_CFGR1_AUTDLY                      ADC_CFGR1_AUTDLY_Msk                              /*!< ADC low power auto wait */
#define ADC_CFGR1_AUTOFF_Pos                  (15U)
#define ADC_CFGR1_AUTOFF_Msk                  (0x1UL << ADC_CFGR1_AUTOFF_Pos)                   /*!< 0x00008000 */
#define ADC_CFGR1_AUTOFF                      ADC_CFGR1_AUTOFF_Msk
#define ADC_CFGR1_DISCEN_Pos                  (16U)
#define ADC_CFGR1_DISCEN_Msk                  (0x1UL << ADC_CFGR1_DISCEN_Pos)                   /*!< 0x00010000 */
#define ADC_CFGR1_DISCEN                      ADC_CFGR1_DISCEN_Msk                              /*!< ADC group regular sequencer discontinuous mode */
#define ADC_CFGR1_DISCNUM_Pos                 (17U)
#define ADC_CFGR1_DISCNUM_Msk                 (0x7UL << ADC_CFGR1_DISCNUM_Pos)                  /*!< 0x000E0000 */
#define ADC_CFGR1_DISCNUM                     ADC_CFGR1_DISCNUM_Msk                             /*!< ADC group regular sequencer discontinuous number of ranks */
#define ADC_CFGR1_DISCNUM_0                   (0x1UL << ADC_CFGR1_DISCNUM_Pos)                  /*!< 0x00020000 */
#define ADC_CFGR1_DISCNUM_1                   (0x2UL << ADC_CFGR1_DISCNUM_Pos)                  /*!< 0x00040000 */
#define ADC_CFGR1_DISCNUM_2                   (0x4UL << ADC_CFGR1_DISCNUM_Pos)                  /*!< 0x00080000 */

/********************  Bit definition for ADC_CFGR2 register  *****************/
#define ADC_CFGR2_SEQEN_Pos                   (0U)
#define ADC_CFGR2_SEQEN_Msk                   (0x1UL << ADC_CFGR2_SEQEN_Pos)                    /*!< 0x00000001 */
#define ADC_CFGR2_SEQEN                       ADC_CFGR2_SEQEN_Msk                               /*!< Sequential Section Sampling Enable */
#define ADC_CFGR2_TGAP_Pos                    (8U)
#define ADC_CFGR2_TGAP_0                      (0x1UL << ADC_CFGR2_TGAP_Pos)
#define ADC_CFGR2_TGAP_1                      (0x2UL << ADC_CFGR2_TGAP_Pos)
#define ADC_CFGR2_TGAP_2                      (0x4UL << ADC_CFGR2_TGAP_Pos)
#define ADC_CFGR2_TGAP_3                      (0x8UL << ADC_CFGR2_TGAP_Pos)
#define ADC_CFGR2_TGAP_Msk                    (0xFUL << ADC_CFGR2_TGAP_Pos)                     /*!< 0x000007FFF */
#define ADC_CFGR2_TGAP                        ADC_CFGR2_TGAP_Msk                                /*!< Time of The Gap between Conversions in Sequential Section Configure */

/********************  Bit definition for ADC_SMPR1 register  *****************/
#define ADC_SMPR1_SMP1_FAST_Pos               (0U)
#define ADC_SMPR1_SMP1_FAST_Msk               (0x7UL << ADC_SMPR1_SMP1_FAST_Pos)                /*!< 0x00000007 */
#define ADC_SMPR1_SMP1_FAST                   ADC_SMPR1_SMP1_FAST_Msk                           /*!< ADC fast channel sampling time selection  */
#define ADC_SMPR1_SMP1_FAST_0                 (0x1UL << ADC_SMPR1_SMP1_FAST_Pos)                /*!< 0x00000001 */
#define ADC_SMPR1_SMP1_FAST_1                 (0x2UL << ADC_SMPR1_SMP1_FAST_Pos)                /*!< 0x00000002 */
#define ADC_SMPR1_SMP1_FAST_2                 (0x4UL << ADC_SMPR1_SMP1_FAST_Pos)                /*!< 0x00000004 */

#define ADC_SMPR1_SMP1_SLOW_Pos               (3U)
#define ADC_SMPR1_SMP1_SLOW_Msk               (0x7UL << ADC_SMPR1_SMP1_SLOW_Pos)                /*!< 0x00000007 */
#define ADC_SMPR1_SMP1_SLOW                   ADC_SMPR1_SMP1_SLOW_Msk                           /*!< ADC slow channel sampling time selection  */
#define ADC_SMPR1_SMP1_SLOW_0                 (0x1UL << ADC_SMPR1_SMP1_SLOW_Pos)                /*!< 0x00000001 */
#define ADC_SMPR1_SMP1_SLOW_1                 (0x2UL << ADC_SMPR1_SMP1_SLOW_Pos)                /*!< 0x00000002 */
#define ADC_SMPR1_SMP1_SLOW_2                 (0x4UL << ADC_SMPR1_SMP1_SLOW_Pos)                /*!< 0x00000004 */

/********************  Bit definition for ADC_CFGR3 register  *****************/
#define ADC_CFGR3_EXTEN2_Pos                  (0U)
#define ADC_CFGR3_EXTEN2_Msk                  (0x3UL << ADC_CFGR3_EXTEN2_Pos)                   /*!< 0x00000003 */
#define ADC_CFGR3_EXTEN2                      ADC_CFGR3_EXTEN2_Msk                              /*!< External trigger enable and polarity selection for regular channels */
#define ADC_CFGR3_EXTEN2_0                    (0x1UL << ADC_CFGR3_EXTEN2_Pos)                   /*!< 0x00100000 */
#define ADC_CFGR3_EXTEN2_1                    (0x2UL << ADC_CFGR3_EXTEN2_Pos)                   /*!< 0x00200000 */

#define ADC_CFGR3_EXTSEL2_Pos                 (2U)
#define ADC_CFGR3_EXTSEL2_Msk                 (0x7UL << ADC_CFGR3_EXTSEL2_Pos)                  /*!< 0x0000001C */
#define ADC_CFGR3_EXTSEL2                     ADC_CFGR3_EXTSEL2_Msk                             /*!< External trigger selection for regular group */
#define ADC_CFGR3_EXTSEL2_0                   (0x1UL << ADC_CFGR3_EXTSEL2_Pos)                  /*!< 0x00100000 */
#define ADC_CFGR3_EXTSEL2_1                   (0x2UL << ADC_CFGR3_EXTSEL2_Pos)                  /*!< 0x00200000 */
#define ADC_CFGR3_EXTSEL2_2                   (0x4UL << ADC_CFGR3_EXTSEL2_Pos)                  /*!< 0x00400000 */

#define ADC_CFGR3_EXTEN3_Pos                  (8U)
#define ADC_CFGR3_EXTEN3_Msk                  (0x3UL << ADC_CFGR3_EXTEN3_Pos)                   /*!< 0x00000300 */
#define ADC_CFGR3_EXTEN3                      ADC_CFGR3_EXTEN3_Msk                              /*!< External trigger enable and polarity selection for regular channels */
#define ADC_CFGR3_EXTEN3_0                    (0x1UL << ADC_CFGR3_EXTEN3_Pos)                   /*!< 0x00100000 */
#define ADC_CFGR3_EXTEN3_1                    (0x2UL << ADC_CFGR3_EXTEN3_Pos)                   /*!< 0x00200000 */

#define ADC_CFGR3_EXTSEL3_Pos                 (10U)
#define ADC_CFGR3_EXTSEL3_Msk                 (0x7UL << ADC_CFGR3_EXTSEL3_Pos)                  /*!< 0x00001C00 */
#define ADC_CFGR3_EXTSEL3                     ADC_CFGR3_EXTSEL3_Msk                             /*!< External trigger selection for regular group */
#define ADC_CFGR3_EXTSEL3_0                   (0x1UL << ADC_CFGR3_EXTSEL3_Pos)                  /*!< 0x00100000 */
#define ADC_CFGR3_EXTSEL3_1                   (0x2UL << ADC_CFGR3_EXTSEL3_Pos)                  /*!< 0x00200000 */
#define ADC_CFGR3_EXTSEL3_2                   (0x4UL << ADC_CFGR3_EXTSEL3_Pos)                  /*!< 0x00400000 */

/********************  Bit definition for ADC_SQR1 register  ******************/
#define ADC_SQR1_LT3_Pos                      (0U)
#define ADC_SQR1_LT3_Msk                      (0xFUL << ADC_SQR1_LT3_Pos)                       /*!< 0x0000000F */
#define ADC_SQR1_LT3                          ADC_SQR1_LT3_Msk                                  /*!< ADC group regular sequencer scan length */
#define ADC_SQR1_LT3_0                        (0x1UL << ADC_SQR1_LT3_Pos)                       /*!< 0x00000001 */
#define ADC_SQR1_LT3_1                        (0x2UL << ADC_SQR1_LT3_Pos)                       /*!< 0x00000002 */
#define ADC_SQR1_LT3_2                        (0x4UL << ADC_SQR1_LT3_Pos)                       /*!< 0x00000004 */
#define ADC_SQR1_LT3_3                        (0x8UL << ADC_SQR1_LT3_Pos)                       /*!< 0x00000008 */

#define ADC_SQR1_SQ1_Pos                      (4U)
#define ADC_SQR1_SQ1_Msk                      (0xFUL << ADC_SQR1_SQ1_Pos)                       /*!< 0x000000F0 */
#define ADC_SQR1_SQ1                          ADC_SQR1_SQ1_Msk                                  /*!< ADC group regular sequencer rank 1 */
#define ADC_SQR1_SQ1_0                        (0x01UL << ADC_SQR1_SQ1_Pos)                      /*!< 0x00000010 */
#define ADC_SQR1_SQ1_1                        (0x02UL << ADC_SQR1_SQ1_Pos)                      /*!< 0x00000020 */
#define ADC_SQR1_SQ1_2                        (0x04UL << ADC_SQR1_SQ1_Pos)                      /*!< 0x00000040 */
#define ADC_SQR1_SQ1_3                        (0x08UL << ADC_SQR1_SQ1_Pos)                      /*!< 0x00000080 */

#define ADC_SQR1_SQ2_Pos                      (8U)
#define ADC_SQR1_SQ2_Msk                      (0xFUL << ADC_SQR1_SQ2_Pos)                       /*!< 0x0000F00 */
#define ADC_SQR1_SQ2                          ADC_SQR1_SQ2_Msk                                  /*!< ADC group regular sequencer rank 2 */
#define ADC_SQR1_SQ2_0                        (0x01UL << ADC_SQR1_SQ2_Pos)                      /*!< 0x00000100 */
#define ADC_SQR1_SQ2_1                        (0x02UL << ADC_SQR1_SQ2_Pos)                      /*!< 0x00000200 */
#define ADC_SQR1_SQ2_2                        (0x04UL << ADC_SQR1_SQ2_Pos)                      /*!< 0x00000400 */
#define ADC_SQR1_SQ2_3                        (0x08UL << ADC_SQR1_SQ2_Pos)                      /*!< 0x00000800 */

#define ADC_SQR1_SQ3_Pos                      (12U)
#define ADC_SQR1_SQ3_Msk                      (0xFUL << ADC_SQR1_SQ3_Pos)                       /*!< 0x0000F000 */
#define ADC_SQR1_SQ3                          ADC_SQR1_SQ3_Msk                                  /*!< ADC group regular sequencer rank 3 */
#define ADC_SQR1_SQ3_0                        (0x01UL << ADC_SQR1_SQ3_Pos)                      /*!< 0x00001000 */
#define ADC_SQR1_SQ3_1                        (0x02UL << ADC_SQR1_SQ3_Pos)                      /*!< 0x00002000 */
#define ADC_SQR1_SQ3_2                        (0x04UL << ADC_SQR1_SQ3_Pos)                      /*!< 0x00004000 */
#define ADC_SQR1_SQ3_3                        (0x08UL << ADC_SQR1_SQ3_Pos)                      /*!< 0x00008000 */

#define ADC_SQR1_SQ4_Pos                      (16U)
#define ADC_SQR1_SQ4_Msk                      (0xFUL << ADC_SQR1_SQ4_Pos)                       /*!< 0x000F0000 */
#define ADC_SQR1_SQ4                          ADC_SQR1_SQ4_Msk                                  /*!< ADC group regular sequencer rank 4 */
#define ADC_SQR1_SQ4_0                        (0x01UL << ADC_SQR1_SQ4_Pos)                      /*!< 0x00010000 */
#define ADC_SQR1_SQ4_1                        (0x02UL << ADC_SQR1_SQ4_Pos)                      /*!< 0x00020000 */
#define ADC_SQR1_SQ4_2                        (0x04UL << ADC_SQR1_SQ4_Pos)                      /*!< 0x00040000 */
#define ADC_SQR1_SQ4_3                        (0x08UL << ADC_SQR1_SQ4_Pos)                      /*!< 0x00080000 */

#define ADC_SQR1_SQ5_Pos                      (20U)
#define ADC_SQR1_SQ5_Msk                      (0xFUL << ADC_SQR1_SQ5_Pos)                       /*!< 0x00F00000 */
#define ADC_SQR1_SQ5                          ADC_SQR1_SQ5_Msk                                  /*!< ADC group regular sequencer rank 5 */
#define ADC_SQR1_SQ5_0                        (0x01UL << ADC_SQR1_SQ5_Pos)                      /*!< 0x00100000 */
#define ADC_SQR1_SQ5_1                        (0x02UL << ADC_SQR1_SQ5_Pos)                      /*!< 0x002000000 */
#define ADC_SQR1_SQ5_2                        (0x04UL << ADC_SQR1_SQ5_Pos)                      /*!< 0x00400000 */
#define ADC_SQR1_SQ5_3                        (0x08UL << ADC_SQR1_SQ5_Pos)                      /*!< 0x00800000 */

#define ADC_SQR1_SQ6_Pos                      (24U)
#define ADC_SQR1_SQ6_Msk                      (0xFUL << ADC_SQR1_SQ6_Pos)                       /*!< 0x0F000000 */
#define ADC_SQR1_SQ6                          ADC_SQR1_SQ6_Msk                                  /*!< ADC group regular sequencer rank 6 */
#define ADC_SQR1_SQ6_0                        (0x01UL << ADC_SQR1_SQ6_Pos)                      /*!< 0x01000000 */
#define ADC_SQR1_SQ6_1                        (0x02UL << ADC_SQR1_SQ6_Pos)                      /*!< 0x02000000 */
#define ADC_SQR1_SQ6_2                        (0x04UL << ADC_SQR1_SQ6_Pos)                      /*!< 0x04000000 */
#define ADC_SQR1_SQ6_3                        (0x08UL << ADC_SQR1_SQ6_Pos)                      /*!< 0x08000000 */

#define ADC_SQR1_SQ7_Pos                      (28U)
#define ADC_SQR1_SQ7_Msk                      (0xFUL << ADC_SQR1_SQ7_Pos)                       /*!< 0xF0000000 */
#define ADC_SQR1_SQ7                          ADC_SQR1_SQ7_Msk                                  /*!< ADC group regular sequencer rank 7 */
#define ADC_SQR1_SQ7_0                        (0x01UL << ADC_SQR1_SQ7_Pos)                      /*!< 0x10000000 */
#define ADC_SQR1_SQ7_1                        (0x02UL << ADC_SQR1_SQ7_Pos)                      /*!< 0x20000000 */
#define ADC_SQR1_SQ7_2                        (0x04UL << ADC_SQR1_SQ7_Pos)                      /*!< 0x40000000 */
#define ADC_SQR1_SQ7_3                        (0x08UL << ADC_SQR1_SQ7_Pos)                      /*!< 0x80000000 */

/********************  Bit definition for ADC_SQR2 register  ******************/
#define ADC_SQR2_SQ8_Pos                      (0U)
#define ADC_SQR2_SQ8_Msk                      (0xFUL << ADC_SQR2_SQ8_Pos)                       /*!< 0x0000000F */
#define ADC_SQR2_SQ8                          ADC_SQR2_SQ8_Msk                                  /*!< ADC group regular sequencer rank 8 */
#define ADC_SQR2_SQ8_0                        (0x01UL << ADC_SQR2_SQ8_Pos)                      /*!< 0x00000001 */
#define ADC_SQR2_SQ8_1                        (0x02UL << ADC_SQR2_SQ8_Pos)                      /*!< 0x00000002 */
#define ADC_SQR2_SQ8_2                        (0x04UL << ADC_SQR2_SQ8_Pos)                      /*!< 0x00000004 */
#define ADC_SQR2_SQ8_3                        (0x08UL << ADC_SQR2_SQ8_Pos)                      /*!< 0x00000008 */

#define ADC_SQR2_SQ9_Pos                      (4U)
#define ADC_SQR2_SQ9_Msk                      (0xFUL << ADC_SQR2_SQ9_Pos)                       /*!< 0x000000F0*/
#define ADC_SQR2_SQ9                          ADC_SQR2_SQ9_Msk                                  /*!< ADC group regular sequencer rank 9 */
#define ADC_SQR2_SQ9_0                        (0x01UL << ADC_SQR2_SQ9_Pos)                      /*!< 0x00000010 */
#define ADC_SQR2_SQ9_1                        (0x02UL << ADC_SQR2_SQ9_Pos)                      /*!< 0x00000020 */
#define ADC_SQR2_SQ9_2                        (0x04UL << ADC_SQR2_SQ9_Pos)                      /*!< 0x00000040 */
#define ADC_SQR2_SQ9_3                        (0x08UL << ADC_SQR2_SQ9_Pos)                      /*!< 0x00000080 */

#define ADC_SQR2_SQ10_Pos                     (8U)
#define ADC_SQR2_SQ10_Msk                     (0xFUL << ADC_SQR2_SQ10_Pos)                      /*!< 0x00000F00 */
#define ADC_SQR2_SQ10                         ADC_SQR2_SQ10_Msk                                 /*!< ADC group regular sequencer rank 10 */
#define ADC_SQR2_SQ10_0                       (0x01UL << ADC_SQR2_SQ10_Pos)                     /*!< 0x00000100 */
#define ADC_SQR2_SQ10_1                       (0x02UL << ADC_SQR2_SQ10_Pos)                     /*!< 0x00000200 */
#define ADC_SQR2_SQ10_2                       (0x04UL << ADC_SQR2_SQ10_Pos)                     /*!< 0x00000400 */
#define ADC_SQR2_SQ10_3                       (0x08UL << ADC_SQR2_SQ10_Pos)                     /*!< 0x00000800 */

#define ADC_SQR2_SQ11_Pos                     (12U)
#define ADC_SQR2_SQ11_Msk                     (0xFUL << ADC_SQR2_SQ11_Pos)                      /*!< 0x0000F000 */
#define ADC_SQR2_SQ11                         ADC_SQR2_SQ11_Msk                                 /*!< ADC group regular sequencer rank 11 */
#define ADC_SQR2_SQ11_0                       (0x01UL << ADC_SQR2_SQ11_Pos)                     /*!< 0x00001000 */
#define ADC_SQR2_SQ11_1                       (0x02UL << ADC_SQR2_SQ11_Pos)                     /*!< 0x00002000 */
#define ADC_SQR2_SQ11_2                       (0x04UL << ADC_SQR2_SQ11_Pos)                     /*!< 0x00004000 */
#define ADC_SQR2_SQ11_3                       (0x08UL << ADC_SQR2_SQ11_Pos)                     /*!< 0x00008000 */

#define ADC_SQR2_SQ12_Pos                     (16U)
#define ADC_SQR2_SQ12_Msk                     (0xFUL << ADC_SQR2_SQ12_Pos)                      /*!< 0x000F0000 */
#define ADC_SQR2_SQ12                         ADC_SQR2_SQ12_Msk                                 /*!< ADC group regular sequencer rank 12 */
#define ADC_SQR2_SQ12_0                       (0x01UL << ADC_SQR2_SQ12_Pos)                     /*!< 0x00010000 */
#define ADC_SQR2_SQ12_1                       (0x02UL << ADC_SQR2_SQ12_Pos)                     /*!< 0x00020000 */
#define ADC_SQR2_SQ12_2                       (0x04UL << ADC_SQR2_SQ12_Pos)                     /*!< 0x00040000 */
#define ADC_SQR2_SQ12_3                       (0x08UL << ADC_SQR2_SQ12_Pos)                     /*!< 0x00080000 */

#define ADC_SQR2_SQ13_Pos                     (20U)
#define ADC_SQR2_SQ13_Msk                     (0xFUL << ADC_SQR2_SQ13_Pos)                      /*!< 0x00F00000 */
#define ADC_SQR2_SQ13                         ADC_SQR2_SQ13_Msk                                 /*!< ADC group regular sequencer rank 13 */
#define ADC_SQR2_SQ13_0                       (0x01UL << ADC_SQR2_SQ13_Pos)                     /*!< 0x00010000 */
#define ADC_SQR2_SQ13_1                       (0x02UL << ADC_SQR2_SQ13_Pos)                     /*!< 0x00020000 */
#define ADC_SQR2_SQ13_2                       (0x04UL << ADC_SQR2_SQ13_Pos)                     /*!< 0x00040000 */
#define ADC_SQR2_SQ13_3                       (0x08UL << ADC_SQR2_SQ13_Pos)                     /*!< 0x00080000 */

#define ADC_SQR2_SQ14_Pos                     (24)
#define ADC_SQR2_SQ14_Msk                     (0xFUL << ADC_SQR2_SQ14_Pos)                      /*!< 0x0F000000 */
#define ADC_SQR2_SQ14                         ADC_SQR2_SQ14_Msk                                 /*!< ADC group regular sequencer rank 14 */
#define ADC_SQR2_SQ14_0                       (0x01UL << ADC_SQR2_SQ14_Pos)                     /*!< 0x00010000 */
#define ADC_SQR2_SQ14_1                       (0x02UL << ADC_SQR2_SQ14_Pos)                     /*!< 0x00020000 */
#define ADC_SQR2_SQ14_2                       (0x04UL << ADC_SQR2_SQ14_Pos)                     /*!< 0x00040000 */
#define ADC_SQR2_SQ14_3                       (0x08UL << ADC_SQR2_SQ14_Pos)                     /*!< 0x00080000 */

/********************  Bit definition for ADC_SQR3 register  ******************/
#define ADC_SQR3_SQ15_Pos                     (0U)
#define ADC_SQR3_SQ15_Msk                     (0xFUL << ADC_SQR3_SQ15_Pos)                      /*!< 0x0000000F */
#define ADC_SQR3_SQ15                         ADC_SQR3_SQ15_Msk                                 /*!< ADC group regular sequencer rank 15 */
#define ADC_SQR3_SQ15_0                       (0x01UL << ADC_SQR3_SQ15_Pos)                     /*!< 0x00000001 */
#define ADC_SQR3_SQ15_1                       (0x02UL << ADC_SQR3_SQ15_Pos)                     /*!< 0x00000002 */
#define ADC_SQR3_SQ15_2                       (0x04UL << ADC_SQR3_SQ15_Pos)                     /*!< 0x00000004 */
#define ADC_SQR3_SQ15_3                       (0x08UL << ADC_SQR3_SQ15_Pos)                     /*!< 0x00000008 */

#define ADC_SQR3_SQ16_Pos                     (4U)
#define ADC_SQR3_SQ16_Msk                     (0xFUL << ADC_SQR3_SQ16_Pos)                      /*!< 0x000000F0*/
#define ADC_SQR3_SQ16                         ADC_SQR3_SQ16_Msk                                 /*!< ADC group regular sequencer rank 16 */
#define ADC_SQR3_SQ16_0                       (0x01UL << ADC_SQR3_SQ16_Pos)                     /*!< 0x00000010 */
#define ADC_SQR3_SQ16_1                       (0x02UL << ADC_SQR3_SQ16_Pos)                     /*!< 0x00000020 */
#define ADC_SQR3_SQ16_2                       (0x04UL << ADC_SQR3_SQ16_Pos)                     /*!< 0x00000040 */
#define ADC_SQR3_SQ16_3                       (0x08UL << ADC_SQR3_SQ16_Pos)                     /*!< 0x00000080 */

/********************  Bit definition for ADC_DR register  ********************/
#define ADC_DR_RDATA_Pos                      (0U)
#define ADC_DR_RDATA_Msk                      (0xFFFFUL << ADC_DR_RDATA_Pos)                    /*!< 0x0000FFFF */
#define ADC_DR_RDATA                          ADC_DR_RDATA_Msk                                  /*!< ADC group regular conversion data */

/********************  Bit definition for ADC_DATA0 register  *****************/
#define ADC_DATA0_RDATA0_Pos                  (0UL)                                             /*!< RDATA0 (Bit 0)                                        */
#define ADC_DATA0_RDATA0_Msk                  (0xFFFFUL << ADC_DATA0_RDATA0_Pos)                /*!< RDATA0 (Bitfield-Mask: 0xffff)                        */
#define ADC_DATA0_RDATA0                      ADC_DATA0_RDATA0_Msk

/********************  Bit definition for ADC_DATA1 register  *****************/
#define ADC_DATA1_RDATA1_Pos                  (0UL)                                             /*!< RDATA1 (Bit 0)                                        */
#define ADC_DATA1_RDATA1_Msk                  (0xFFFFUL << ADC_DATA1_RDATA1_Pos)                /*!< RDATA1 (Bitfield-Mask: 0xffff)                        */
#define ADC_DATA1_RDATA1                      ADC_DATA1_RDATA1_Msk

/********************  Bit definition for ADC_DATA2 register  *****************/
#define ADC_DATA2_RDATA2_Pos                  (0UL)                                             /*!< RDATA2 (Bit 0)                                        */
#define ADC_DATA2_RDATA2_Msk                  (0xFFFFUL << ADC_DATA2_RDATA2_Pos)                /*!< RDATA2 (Bitfield-Mask: 0xffff)                        */
#define ADC_DATA2_RDATA2                      ADC_DATA2_RDATA2_Msk

/********************  Bit definition for ADC_DATA3 register  *****************/
#define ADC_DATA3_RDATA3_Pos                  (0UL)                                             /*!< RDATA3 (Bit 0)                                        */
#define ADC_DATA3_RDATA3_Msk                  (0xFFFFUL << ADC_DATA3_RDATA3_Pos)                /*!< RDATA3 (Bitfield-Mask: 0xffff)                        */
#define ADC_DATA3_RDATA3                      ADC_DATA3_RDATA3_Msk

/********************  Bit definition for ADC_DATA4 register  *****************/
#define ADC_DATA4_RDATA4_Pos                  (0UL)                                             /*!< RDATA4 (Bit 0)                                        */
#define ADC_DATA4_RDATA4_Msk                  (0xFFFFUL << ADC_DATA4_RDATA4_Pos)                /*!< RDATA4 (Bitfield-Mask: 0xffff)                        */
#define ADC_DATA4_RDATA4                      ADC_DATA4_RDATA4_Msk

/********************  Bit definition for ADC_DATA5 register  *****************/
#define ADC_DATA5_RDATA5_Pos                  (0UL)                                             /*!< RDATA5 (Bit 0)                                        */
#define ADC_DATA5_RDATA5_Msk                  (0xFFFFUL << ADC_DATA5_RDATA5_Pos)                /*!< RDATA5 (Bitfield-Mask: 0xffff)                        */
#define ADC_DATA5_RDATA5                      ADC_DATA5_RDATA5_Msk

/********************  Bit definition for ADC_DATA6 register  *****************/
#define ADC_DATA6_RDATA6_Pos                  (0UL)                                             /*!< RDATA6 (Bit 0)                                        */
#define ADC_DATA6_RDATA6_Msk                  (0xFFFFUL << ADC_DATA6_RDATA6_Pos)                /*!< RDATA6 (Bitfield-Mask: 0xffff)                        */
#define ADC_DATA6_RDATA6                      ADC_DATA6_RDATA6_Msk

/********************  Bit definition for ADC_DATA7 register  *****************/
#define ADC_DATA7_RDATA7_Pos                  (0UL)                                             /*!< RDATA7 (Bit 0)                                        */
#define ADC_DATA7_RDATA7_Msk                  (0xFFFFUL << ADC_DATA7_RDATA7_Pos)                /*!< RDATA7 (Bitfield-Mask: 0xffff)                        */
#define ADC_DATA7_RDATA7                      ADC_DATA7_RDATA7_Msk

/********************  Bit definition for ADC_SEQ_NUM register  ****************/
#define ADC_SEQ_NUM_SEQ_NUM1_Pos              (0)
#define ADC_SEQ_NUM_SEQ_NUM1_0                (0x1UL << ADC_SEQ_NUM_SEQ_NUM1_Pos)
#define ADC_SEQ_NUM_SEQ_NUM1_1                (0x2UL << ADC_SEQ_NUM_SEQ_NUM1_Pos)
#define ADC_SEQ_NUM_SEQ_NUM1_2                (0x4UL << ADC_SEQ_NUM_SEQ_NUM1_Pos)
#define ADC_SEQ_NUM_SEQ_NUM1_Msk              (0x7UL << ADC_SEQ_NUM_SEQ_NUM1_Pos)
#define ADC_SEQ_NUM_SEQ_NUM1                  ADC_SEQ_NUM_SEQ_NUM1_Msk
#define ADC_SEQ_NUM_SEQ_NUM2_Pos              (4)
#define ADC_SEQ_NUM_SEQ_NUM2_0                (0x1UL << ADC_SEQ_NUM_SEQ_NUM2_Pos)
#define ADC_SEQ_NUM_SEQ_NUM2_1                (0x2UL << ADC_SEQ_NUM_SEQ_NUM2_Pos)
#define ADC_SEQ_NUM_SEQ_NUM2_2                (0x4UL << ADC_SEQ_NUM_SEQ_NUM2_Pos)
#define ADC_SEQ_NUM_SEQ_NUM2_Msk              (0x7UL << ADC_SEQ_NUM_SEQ_NUM2_Pos)
#define ADC_SEQ_NUM_SEQ_NUM2                  ADC_SEQ_NUM_SEQ_NUM2_Msk
#define ADC_SEQ_NUM_SEQ_NUM3_Pos              (8)
#define ADC_SEQ_NUM_SEQ_NUM3_0                (0x1UL << ADC_SEQ_NUM_SEQ_NUM3_Pos)
#define ADC_SEQ_NUM_SEQ_NUM3_1                (0x2UL << ADC_SEQ_NUM_SEQ_NUM3_Pos)
#define ADC_SEQ_NUM_SEQ_NUM3_2                (0x4UL << ADC_SEQ_NUM_SEQ_NUM3_Pos)
#define ADC_SEQ_NUM_SEQ_NUM3_Msk              (0x7UL << ADC_SEQ_NUM_SEQ_NUM3_Pos)
#define ADC_SEQ_NUM_SEQ_NUM3                  ADC_SEQ_NUM_SEQ_NUM3_Msk
#define ADC_SEQ_NUM_SG_NUM_Pos                (16)
#define ADC_SEQ_NUM_SG_NUM_0                  (0x1UL << ADC_SEQ_NUM_SG_NUM_Pos)
#define ADC_SEQ_NUM_SG_NUM_1                  (0x2UL << ADC_SEQ_NUM_SG_NUM_Pos)
#define ADC_SEQ_NUM_SG_NUM_Msk                (0x3UL << ADC_SEQ_NUM_SG_NUM_Pos)
#define ADC_SEQ_NUM_SG_NUM                    ADC_SEQ_NUM_SG_NUM_Msk

/********************  Bit definition for ADC_TMR register  ******************/
#define ADC_TMR_CALC_BYPASS_Pos               (0)
#define ADC_TMR_CALC_BYPASS_Msk               (0x1UL << ADC_TMR_CALC_BYPASS_Pos)                /*!< 0x00000002 */
#define ADC_TMR_CALC_BYPASS                   ADC_TMR_CALC_BYPASS_Msk

/******************************************************************************/
/*                                                                            */
/*                        Advanced timer control                              */
/*                                                                            */
/******************************************************************************/
/*******************  Bit definition for ATMR_CTRL1 register  *****************/
#define ATMR_CTRL1_CNTEN_Pos                  (0U)
#define ATMR_CTRL1_CNTEN_Msk                  (0x1UL << ATMR_CTRL1_CNTEN_Pos)                   /*!< 0x00000001 */
#define ATMR_CTRL1_CNTEN                      ATMR_CTRL1_CNTEN_Msk                              /*!<Counter enable */
#define ATMR_CTRL1_UD_Pos                     (1U)
#define ATMR_CTRL1_UD_Msk                     (0x1UL << ATMR_CTRL1_UD_Pos)                      /*!< 0x00000002 */
#define ATMR_CTRL1_UD                         ATMR_CTRL1_UD_Msk                                 /*!<Update disable */
#define ATMR_CTRL1_URSSEL_Pos                 (2U)
#define ATMR_CTRL1_URSSEL_Msk                 (0x1UL << ATMR_CTRL1_URSSEL_Pos)                  /*!< 0x00000004 */
#define ATMR_CTRL1_URSSEL                     ATMR_CTRL1_URSSEL_Msk                             /*!<Update request source */
#define ATMR_CTRL1_SPMEN_Pos                  (3U)
#define ATMR_CTRL1_SPMEN_Msk                  (0x1UL << ATMR_CTRL1_SPMEN_Pos)                   /*!< 0x00000008 */
#define ATMR_CTRL1_SPMEN                      ATMR_CTRL1_SPMEN_Msk                              /*!<One pulse mode */
#define ATMR_CTRL1_CNTDIR_Pos                 (4U)
#define ATMR_CTRL1_CNTDIR_Msk                 (0x1UL << ATMR_CTRL1_CNTDIR_Pos)                  /*!< 0x00000010 */
#define ATMR_CTRL1_CNTDIR                     ATMR_CTRL1_CNTDIR_Msk                             /*!<Direction */

#define ATMR_CTRL1_CAMSEL_Pos                 (5U)
#define ATMR_CTRL1_CAMSEL_Msk                 (0x3UL << ATMR_CTRL1_CAMSEL_Pos)                  /*!< 0x00000060 */
#define ATMR_CTRL1_CAMSEL                     ATMR_CTRL1_CAMSEL_Msk                             /*!<CMS[1:0] bits (Center-aligned mode selection) */
#define ATMR_CTRL1_CAMSEL_0                   (0x1UL << ATMR_CTRL1_CAMSEL_Pos)                  /*!< 0x0020 */
#define ATMR_CTRL1_CAMSEL_1                   (0x2UL << ATMR_CTRL1_CAMSEL_Pos)                  /*!< 0x0040 */

#define ATMR_CTRL1_ARPEN_Pos                  (7U)
#define ATMR_CTRL1_ARPEN_Msk                  (0x1UL << ATMR_CTRL1_ARPEN_Pos)                   /*!< 0x00000080 */
#define ATMR_CTRL1_ARPEN                      ATMR_CTRL1_ARPEN_Msk                              /*!<Auto-reload preload enable */

#define ATMR_CTRL1_CLKDIV_Pos                 (8U)
#define ATMR_CTRL1_CLKDIV_Msk                 (0x3UL << ATMR_CTRL1_CLKDIV_Pos)                  /*!< 0x00000300 */
#define ATMR_CTRL1_CLKDIV                     ATMR_CTRL1_CLKDIV_Msk                             /*!<CKD[1:0] bits (clock division) */
#define ATMR_CTRL1_CLKDIV_0                   (0x1UL << ATMR_CTRL1_CLKDIV_Pos)                  /*!< 0x0100 */
#define ATMR_CTRL1_CLKDIV_1                   (0x2UL << ATMR_CTRL1_CLKDIV_Pos)                  /*!< 0x0200 */

/*******************  Bit definition for ATMR_CTRL2 register  *****************/
#define ATMR_CTRL2_CCPEN_Pos                  (0U)
#define ATMR_CTRL2_CCPEN_Msk                  (0x1UL << ATMR_CTRL2_CCPEN_Pos)                   /*!< 0x00000001 */
#define ATMR_CTRL2_CCPEN                      ATMR_CTRL2_CCPEN_Msk                              /*!<Capture/Compare Preloaded Control */
#define ATMR_CTRL2_MMSZE_Pos                  (1U)
#define ATMR_CTRL2_MMSZE_Msk                  (0x1UL << ATMR_CTRL2_MMSZE_Pos)                   /*!< 0x00000002 */
#define ATMR_CTRL2_MMSZE                      ATMR_CTRL2_MMSZE_Msk
#define ATMR_CTRL2_CCUSEL_Pos                 (2U)
#define ATMR_CTRL2_CCUSEL_Msk                 (0x1UL << ATMR_CTRL2_CCUSEL_Pos)                  /*!< 0x00000004 */
#define ATMR_CTRL2_CCUSEL                     ATMR_CTRL2_CCUSEL_Msk                             /*!<Capture/Compare Control Update Selection */
#define ATMR_CTRL2_MMSPE_Pos                  (3U)
#define ATMR_CTRL2_MMSPE_Msk                  (0x1UL << ATMR_CTRL2_MMSPE_Pos)                   /*!< 0x00000008 */
#define ATMR_CTRL2_MMSPE                      ATMR_CTRL2_MMSPE_Msk

#define ATMR_CTRL2_MMSEL_Pos                  (4U)
#define ATMR_CTRL2_MMSEL_Msk                  (0xFUL << ATMR_CTRL2_MMSEL_Pos)                   /*!< 0x00000070 */
#define ATMR_CTRL2_MMSEL                      ATMR_CTRL2_MMSEL_Msk                              /*!<MMS[2:0] bits (Master Mode Selection) */
#define ATMR_CTRL2_MMSEL_0                    (0x1UL << ATMR_CTRL2_MMSEL_Pos)                   /*!< 0x0010 */
#define ATMR_CTRL2_MMSEL_1                    (0x2UL << ATMR_CTRL2_MMSEL_Pos)                   /*!< 0x0020 */
#define ATMR_CTRL2_MMSEL_2                    (0x4UL << ATMR_CTRL2_MMSEL_Pos)                   /*!< 0x0040 */
#define ATMR_CTRL2_MMSEL_3                    (0x8UL << ATMR_CTRL2_MMSEL_Pos)                   /*!< 0x0080 */

#define ATMR_CTRL2_OC0OIS_Pos                 (8U)
#define ATMR_CTRL2_OC0OIS_Msk                 (0x1UL << ATMR_CTRL2_OC0OIS_Pos)                  /*!< 0x00000100 */
#define ATMR_CTRL2_OC0OIS                     ATMR_CTRL2_OC0OIS_Msk                             /*!<Output Idle state 0 (OC0 output) */
#define ATMR_CTRL2_OC0NOIS_Pos                (9U)
#define ATMR_CTRL2_OC0NOIS_Msk                (0x1UL << ATMR_CTRL2_OC0NOIS_Pos)                 /*!< 0x00000200 */
#define ATMR_CTRL2_OC0NOIS                    ATMR_CTRL2_OC0NOIS_Msk                            /*!<Output Idle state 0 (OC0N output) */
#define ATMR_CTRL2_OC1OIS_Pos                 (10U)
#define ATMR_CTRL2_OC1OIS_Msk                 (0x1UL << ATMR_CTRL2_OC1OIS_Pos)                  /*!< 0x00000400 */
#define ATMR_CTRL2_OC1OIS                     ATMR_CTRL2_OC1OIS_Msk                             /*!<Output Idle state 1 (OC1 output) */
#define ATMR_CTRL2_OC1NOIS_Pos                (11U)
#define ATMR_CTRL2_OC1NOIS_Msk                (0x1UL << ATMR_CTRL2_OC1NOIS_Pos)                 /*!< 0x00000800 */
#define ATMR_CTRL2_OC1NOIS                    ATMR_CTRL2_OC1NOIS_Msk                            /*!<Output Idle state 1 (OC1N output) */
#define ATMR_CTRL2_OC2OIS_Pos                 (12U)
#define ATMR_CTRL2_OC2OIS_Msk                 (0x1UL << ATMR_CTRL2_OC2OIS_Pos)                  /*!< 0x00001000 */
#define ATMR_CTRL2_OC2OIS                     ATMR_CTRL2_OC2OIS_Msk                             /*!<Output Idle state 2 (OC2 output) */
#define ATMR_CTRL2_OC2NOIS_Pos                (13U)
#define ATMR_CTRL2_OC2NOIS_Msk                (0x1UL << ATMR_CTRL2_OC2NOIS_Pos)                 /*!< 0x00002000 */
#define ATMR_CTRL2_OC2NOIS                    ATMR_CTRL2_OC2NOIS_Msk                            /*!<Output Idle state 2 (OC2N output) */
#define ATMR_CTRL2_OC3OIS_Pos                 (14U)
#define ATMR_CTRL2_OC3OIS_Msk                 (0x1UL << ATMR_CTRL2_OC3OIS_Pos)                  /*!< 0x00004000 */
#define ATMR_CTRL2_OC3OIS                     ATMR_CTRL2_OC3OIS_Msk                             /*!<Output Idle state 3 (OC3 output) */

/*******************  Bit definition for ATMR_SMCTRL register  ****************/
#define ATMR_SMCTRL_SMFSEL_Pos                (0U)
#define ATMR_SMCTRL_SMFSEL_Msk                (0x7UL << ATMR_SMCTRL_SMFSEL_Pos)                 /*!< 0x00000007 */
#define ATMR_SMCTRL_SMFSEL                    ATMR_SMCTRL_SMFSEL_Msk                            /*!<SMS[2:0] bits (Slave mode selection) */
#define ATMR_SMCTRL_SMFSEL_0                  (0x1UL << ATMR_SMCTRL_SMFSEL_Pos)                 /*!< 0x0001 */
#define ATMR_SMCTRL_SMFSEL_1                  (0x2UL << ATMR_SMCTRL_SMFSEL_Pos)                 /*!< 0x0002 */
#define ATMR_SMCTRL_SMFSEL_2                  (0x4UL << ATMR_SMCTRL_SMFSEL_Pos)                 /*!< 0x0004 */

#define ATMR_SMCTRL_TRGSEL_Pos                (4U)
#define ATMR_SMCTRL_TRGSEL_Msk                (0x1UL << ATMR_SMCTRL_TRGSEL_Pos)                 /*!< 0x00000070 */
#define ATMR_SMCTRL_TRGSEL                    ATMR_SMCTRL_TRGSEL_Msk                            /*!<Trigger selection */
#define ATMR_SMCTRL_MSMEN_Pos                 (7U)
#define ATMR_SMCTRL_MSMEN_Msk                 (0x1UL << ATMR_SMCTRL_MSMEN_Pos)                  /*!< 0x00000080 */
#define ATMR_SMCTRL_MSMEN                     ATMR_SMCTRL_MSMEN_Msk                             /*!<Master/slave mode */

#define ATMR_SMCTRL_ETFCFG_Pos                (8U)
#define ATMR_SMCTRL_ETFCFG_Msk                (0xFUL << ATMR_SMCTRL_ETFCFG_Pos)                 /*!< 0x00000F00 */
#define ATMR_SMCTRL_ETFCFG                    ATMR_SMCTRL_ETFCFG_Msk                            /*!<ETF[3:0] bits (External trigger filter) */
#define ATMR_SMCTRL_ETFCFG_0                  (0x1UL << ATMR_SMCTRL_ETFCFG_Pos)                 /*!< 0x0100 */
#define ATMR_SMCTRL_ETFCFG_1                  (0x2UL << ATMR_SMCTRL_ETFCFG_Pos)                 /*!< 0x0200 */
#define ATMR_SMCTRL_ETFCFG_2                  (0x4UL << ATMR_SMCTRL_ETFCFG_Pos)                 /*!< 0x0400 */
#define ATMR_SMCTRL_ETFCFG_3                  (0x8UL << ATMR_SMCTRL_ETFCFG_Pos)                 /*!< 0x0800 */

#define ATMR_SMCTRL_ETPCFG_Pos                (12U)
#define ATMR_SMCTRL_ETPCFG_Msk                (0x3UL << ATMR_SMCTRL_ETPCFG_Pos)                 /*!< 0x00003000 */
#define ATMR_SMCTRL_ETPCFG                    ATMR_SMCTRL_ETPCFG_Msk                            /*!<ETPS[1:0] bits (External trigger prescaler) */
#define ATMR_SMCTRL_ETPCFG_0                  (0x1UL << ATMR_SMCTRL_ETPCFG_Pos)                 /*!< 0x1000 */
#define ATMR_SMCTRL_ETPCFG_1                  (0x2UL << ATMR_SMCTRL_ETPCFG_Pos)                 /*!< 0x2000 */

#define ATMR_SMCTRL_ETPOL_Pos                 (15U)
#define ATMR_SMCTRL_ETPOL_Msk                 (0x1UL << ATMR_SMCTRL_ETPOL_Pos)                  /*!< 0x00008000 */
#define ATMR_SMCTRL_ETPOL                     ATMR_SMCTRL_ETPOL_Msk                             /*!<External trigger polarity */

/*******************  Bit definition for ATMR_DIEN register  ******************/
#define ATMR_DIEN_UIEN_Pos                    (0U)
#define ATMR_DIEN_UIEN_Msk                    (0x1UL << ATMR_DIEN_UIEN_Pos)                     /*!< 0x00000001 */
#define ATMR_DIEN_UIEN                        ATMR_DIEN_UIEN_Msk                                /*!<Update interrupt enable */
#define ATMR_DIEN_CC0IEN_Pos                  (1U)
#define ATMR_DIEN_CC0IEN_Msk                  (0x1UL << ATMR_DIEN_CC0IEN_Pos)                   /*!< 0x00000002 */
#define ATMR_DIEN_CC0IEN                      ATMR_DIEN_CC0IEN_Msk                              /*!<Capture/Compare 0 interrupt enable   */
#define ATMR_DIEN_CC1IEN_Pos                  (2U)
#define ATMR_DIEN_CC1IEN_Msk                  (0x1UL << ATMR_DIEN_CC1IEN_Pos)                   /*!< 0x00000004 */
#define ATMR_DIEN_CC1IEN                      ATMR_DIEN_CC1IEN_Msk                              /*!<Capture/Compare 1 interrupt enable   */
#define ATMR_DIEN_CC2IEN_Pos                  (3U)
#define ATMR_DIEN_CC2IEN_Msk                  (0x1UL << ATMR_DIEN_CC2IEN_Pos)                   /*!< 0x00000008 */
#define ATMR_DIEN_CC2IEN                      ATMR_DIEN_CC2IEN_Msk                              /*!<Capture/Compare 2 interrupt enable   */
#define ATMR_DIEN_CC3IEN_Pos                  (4U)
#define ATMR_DIEN_CC3IEN_Msk                  (0x1UL << ATMR_DIEN_CC3IEN_Pos)                   /*!< 0x00000010 */
#define ATMR_DIEN_CC3IEN                      ATMR_DIEN_CC3IEN_Msk                              /*!<Capture/Compare 3 interrupt enable   */
#define ATMR_DIEN_COMIEN_Pos                  (5U)
#define ATMR_DIEN_COMIEN_Msk                  (0x1UL << ATMR_DIEN_COMIEN_Pos)                   /*!< 0x00000020 */
#define ATMR_DIEN_COMIEN                      ATMR_DIEN_COMIEN_Msk                              /*!<COM interrupt enable */
#define ATMR_DIEN_TRGIEN_Pos                  (6U)
#define ATMR_DIEN_TRGIEN_Msk                  (0x1UL << ATMR_DIEN_TRGIEN_Pos)                   /*!< 0x00000040 */
#define ATMR_DIEN_TRGIEN                      ATMR_DIEN_TRGIEN_Msk                              /*!<Trigger interrupt enable */
#define ATMR_DIEN_BRKIEN_Pos                  (7U)
#define ATMR_DIEN_BRKIEN_Msk                  (0x1UL << ATMR_DIEN_BRKIEN_Pos)                   /*!< 0x00000080 */
#define ATMR_DIEN_BRKIEN                      ATMR_DIEN_BRKIEN_Msk                              /*!<Break interrupt enable */

/********************  Bit definition for ATMR_STS register  ******************/
#define ATMR_STS_UIFLG_Pos                    (0U)
#define ATMR_STS_UIFLG_Msk                    (0x1UL << ATMR_STS_UIFLG_Pos)                     /*!< 0x00000001 */
#define ATMR_STS_UIFLG                        ATMR_STS_UIFLG_Msk                                /*!<Update interrupt Flag */
#define ATMR_STS_CC0IFLG_Pos                  (1U)
#define ATMR_STS_CC0IFLG_Msk                  (0x1UL << ATMR_STS_CC0IFLG_Pos)                   /*!< 0x00000002 */
#define ATMR_STS_CC0IFLG                      ATMR_STS_CC0IFLG_Msk                              /*!<Capture/Compare 0 interrupt Flag */
#define ATMR_STS_CC1IFLG_Pos                  (2U)
#define ATMR_STS_CC1IFLG_Msk                  (0x1UL << ATMR_STS_CC1IFLG_Pos)                   /*!< 0x00000004 */
#define ATMR_STS_CC1IFLG                      ATMR_STS_CC1IFLG_Msk                              /*!<Capture/Compare 1 interrupt Flag */
#define ATMR_STS_CC2IFLG_Pos                  (3U)
#define ATMR_STS_CC2IFLG_Msk                  (0x1UL << ATMR_STS_CC2IFLG_Pos)                   /*!< 0x00000008 */
#define ATMR_STS_CC2IFLG                      ATMR_STS_CC2IFLG_Msk                              /*!<Capture/Compare 2 interrupt Flag */
#define ATMR_STS_CC3IFLG_Pos                  (4U)
#define ATMR_STS_CC3IFLG_Msk                  (0x1UL << ATMR_STS_CC3IFLG_Pos)                   /*!< 0x00000010 */
#define ATMR_STS_CC3IFLG                      ATMR_STS_CC3IFLG_Msk                              /*!<Capture/Compare 3 interrupt Flag */
#define ATMR_STS_COMIFLG_Pos                  (5U)
#define ATMR_STS_COMIFLG_Msk                  (0x1UL << ATMR_STS_COMIFLG_Pos)                   /*!< 0x00000020 */
#define ATMR_STS_COMIFLG                      ATMR_STS_COMIFLG_Msk                              /*!<COM interrupt Flag */
#define ATMR_STS_TRGIFLG_Pos                  (6U)
#define ATMR_STS_TRGIFLG_Msk                  (0x1UL << ATMR_STS_TRGIFLG_Pos)                   /*!< 0x00000040 */
#define ATMR_STS_TRGIFLG                      ATMR_STS_TRGIFLG_Msk                              /*!<Trigger interrupt Flag */
#define ATMR_STS_BRKIFLG_Pos                  (7U)
#define ATMR_STS_BRKIFLG_Msk                  (0x1UL << ATMR_STS_BRKIFLG_Pos)                   /*!< 0x00000080 */
#define ATMR_STS_BRKIFLG                      ATMR_STS_BRKIFLG_Msk                              /*!<Break interrupt Flag */
#define ATMR_STS_CC4IFLG_Pos                  (14U)
#define ATMR_STS_CC4IFLG_Msk                  (0x1UL << ATMR_STS_CC4IFLG_Pos)                   /*!< 0x00004000 */
#define ATMR_STS_CC4IFLG                      ATMR_STS_CC4IFLG_Msk                              /*!<Capture/Compare 4 interrupt Flag */

/*******************  Bit definition for ATMR_CEG register  *******************/
#define ATMR_CEG_UEG_Pos                      (0U)
#define ATMR_CEG_UEG_Msk                      (0x1UL << ATMR_CEG_UEG_Pos)                       /*!< 0x00000001 */
#define ATMR_CEG_UEG                          ATMR_CEG_UEG_Msk                                  /*!<Update Generation */
#define ATMR_CEG_CC0EG_Pos                    (1U)
#define ATMR_CEG_CC0EG_Msk                    (0x1UL << ATMR_CEG_CC0EG_Pos)                     /*!< 0x00000002 */
#define ATMR_CEG_CC0EG                        ATMR_CEG_CC0EG_Msk                                /*!<Capture/Compare 0 Generation */
#define ATMR_CEG_CC1EG_Pos                    (2U)
#define ATMR_CEG_CC1EG_Msk                    (0x1UL << ATMR_CEG_CC1EG_Pos)                     /*!< 0x00000004 */
#define ATMR_CEG_CC1EG                        ATMR_CEG_CC1EG_Msk                                /*!<Capture/Compare 1 Generation */
#define ATMR_CEG_CC2EG_Pos                    (3U)
#define ATMR_CEG_CC2EG_Msk                    (0x1UL << ATMR_CEG_CC2EG_Pos)                     /*!< 0x00000008 */
#define ATMR_CEG_CC2EG                        ATMR_CEG_CC2EG_Msk                                /*!<Capture/Compare 2 Generation */
#define ATMR_CEG_CC3EG_Pos                    (4U)
#define ATMR_CEG_CC3EG_Msk                    (0x1UL << ATMR_CEG_CC3EG_Pos)                     /*!< 0x00000010 */
#define ATMR_CEG_CC3EG                        ATMR_CEG_CC3EG_Msk                                /*!<Capture/Compare 3 Generation */
#define ATMR_CEG_COMG_Pos                     (5U)
#define ATMR_CEG_COMG_Msk                     (0x1UL << ATMR_CEG_COMG_Pos)                      /*!< 0x00000020 */
#define ATMR_CEG_COMG                         ATMR_CEG_COMG_Msk                                 /*!<Capture/Compare Control Update Generation */
#define ATMR_CEG_TEG_Pos                      (6U)
#define ATMR_CEG_TEG_Msk                      (0x1UL << ATMR_CEG_TEG_Pos)                       /*!< 0x00000040 */
#define ATMR_CEG_TEG                          ATMR_CEG_TEG_Msk                                  /*!<Trigger Generation */
#define ATMR_CEG_BEG_Pos                      (7U)
#define ATMR_CEG_BEG_Msk                      (0x1UL << ATMR_CEG_BEG_Pos)                       /*!< 0x00000080 */
#define ATMR_CEG_BEG                          ATMR_CEG_BEG_Msk                                  /*!<Break Generation */

/******************  Bit definition for ATMR_CCM1 register  *******************/
#define ATMR_CCM1_OC0PEN_Pos                  (3U)
#define ATMR_CCM1_OC0PEN_Msk                  (0x1UL << ATMR_CCM1_OC0PEN_Pos)                   /*!< 0x00000008 */
#define ATMR_CCM1_OC0PEN                      ATMR_CCM1_OC0PEN_Msk                              /*!<Output Compare 0 Preload enable */
#define ATMR_CCM1_OC0MOD_Pos                  (4U)
#define ATMR_CCM1_OC0MOD_Msk                  (0x7UL << ATMR_CCM1_OC0MOD_Pos)                   /*!< 0x00000070 */
#define ATMR_CCM1_OC0MOD                      ATMR_CCM1_OC0MOD_Msk                              /*!<OC0M[2:0] bits (Output Compare 0 Mode) */
#define ATMR_CCM1_OC0MOD_0                    (0x1UL << ATMR_CCM1_OC0MOD_Pos)                   /*!< 0x0010 */
#define ATMR_CCM1_OC0MOD_1                    (0x2UL << ATMR_CCM1_OC0MOD_Pos)                   /*!< 0x0020 */
#define ATMR_CCM1_OC0MOD_2                    (0x4UL << ATMR_CCM1_OC0MOD_Pos)                   /*!< 0x0040 */
#define ATMR_CCM1_OC0CEN_Pos                  (7U)
#define ATMR_CCM1_OC0CEN_Msk                  (0x1UL << ATMR_CCM1_OC0CEN_Pos)                   /*!< 0x00000080 */
#define ATMR_CCM1_OC0CEN                      ATMR_CCM1_OC0CEN_Msk                              /*!<Output Compare 0 Clear Enable */
#define ATMR_CCM1_OC1PEN_Pos                  (11U)
#define ATMR_CCM1_OC1PEN_Msk                  (0x1UL << ATMR_CCM1_OC1PEN_Pos)                   /*!< 0x00000800 */
#define ATMR_CCM1_OC1PEN                      ATMR_CCM1_OC1PEN_Msk                              /*!<Output Compare 1 Preload enable */
#define ATMR_CCM1_OC1MOD_Pos                  (12U)
#define ATMR_CCM1_OC1MOD_Msk                  (0x7UL << ATMR_CCM1_OC1MOD_Pos)                   /*!< 0x00007000 */
#define ATMR_CCM1_OC1MOD                      ATMR_CCM1_OC1MOD_Msk                              /*!<OC1M[2:0] bits (Output Compare 1 Mode) */
#define ATMR_CCM1_OC1MOD_0                    (0x1UL << ATMR_CCM1_OC1MOD_Pos)                   /*!< 0x1000 */
#define ATMR_CCM1_OC1MOD_1                    (0x2UL << ATMR_CCM1_OC1MOD_Pos)                   /*!< 0x2000 */
#define ATMR_CCM1_OC1MOD_2                    (0x4UL << ATMR_CCM1_OC1MOD_Pos)                   /*!< 0x4000 */
#define ATMR_CCM1_OC1CEN_Pos                  (15U)
#define ATMR_CCM1_OC1CEN_Msk                  (0x1UL << ATMR_CCM1_OC1CEN_Pos)                   /*!< 0x00008000 */
#define ATMR_CCM1_OC1CEN                      ATMR_CCM1_OC1CEN_Msk                              /*!<Output Compare 1 Clear Enable */

/******************  Bit definition for ATMR_CCM2 register  *******************/
#define ATMR_CCM2_OC2PEN_Pos                  (3U)
#define ATMR_CCM2_OC2PEN_Msk                  (0x1UL << ATMR_CCM2_OC2PEN_Pos)                   /*!< 0x00000008 */
#define ATMR_CCM2_OC2PEN                      ATMR_CCM2_OC2PEN_Msk                              /*!<Output Compare 2 Preload enable */
#define ATMR_CCM2_OC2MOD_Pos                  (4U)
#define ATMR_CCM2_OC2MOD_Msk                  (0x7UL << ATMR_CCM2_OC2MOD_Pos)                   /*!< 0x00000070 */
#define ATMR_CCM2_OC2MOD                      ATMR_CCM2_OC2MOD_Msk                              /*!<OC2M[2:0] bits (Output Compare 2 Mode) */
#define ATMR_CCM2_OC2MOD_0                    (0x1UL << ATMR_CCM2_OC2MOD_Pos)                   /*!< 0x0010 */
#define ATMR_CCM2_OC2MOD_1                    (0x2UL << ATMR_CCM2_OC2MOD_Pos)                   /*!< 0x0020 */
#define ATMR_CCM2_OC2MOD_2                    (0x4UL << ATMR_CCM2_OC2MOD_Pos)                   /*!< 0x0040 */
#define ATMR_CCM2_OC2CEN_Pos                  (7U)
#define ATMR_CCM2_OC2CEN_Msk                  (0x1UL << ATMR_CCM2_OC2CEN_Pos)                   /*!< 0x00000080 */
#define ATMR_CCM2_OC2CEN                      ATMR_CCM2_OC2CEN_Msk                              /*!<Output Compare 2 Clear Enable */
#define ATMR_CCM2_OC3PEN_Pos                  (11U)
#define ATMR_CCM2_OC3PEN_Msk                  (0x1UL << ATMR_CCM2_OC3PEN_Pos)                   /*!< 0x00000800 */
#define ATMR_CCM2_OC3PEN                      ATMR_CCM2_OC3PEN_Msk                              /*!<Output Compare 3 Preload enable */
#define ATMR_CCM2_OC3MOD_Pos                  (12U)
#define ATMR_CCM2_OC3MOD_Msk                  (0x7UL << ATMR_CCM2_OC3MOD_Pos)                   /*!< 0x00007000 */
#define ATMR_CCM2_OC3MOD                      ATMR_CCM2_OC3MOD_Msk                              /*!<OC3M[2:0] bits (Output Compare 3 Mode) */
#define ATMR_CCM2_OC3MOD_0                    (0x1UL << ATMR_CCM2_OC3MOD_Pos)                   /*!< 0x1000 */
#define ATMR_CCM2_OC3MOD_1                    (0x2UL << ATMR_CCM2_OC3MOD_Pos)                   /*!< 0x2000 */
#define ATMR_CCM2_OC3MOD_2                    (0x4UL << ATMR_CCM2_OC3MOD_Pos)                   /*!< 0x4000 */
#define ATMR_CCM2_OC3CEN_Pos                  (15U)
#define ATMR_CCM2_OC3CEN_Msk                  (0x1UL << ATMR_CCM2_OC3CEN_Pos)                   /*!< 0x00008000 */
#define ATMR_CCM2_OC3CEN                      ATMR_CCM2_OC3CEN_Msk                              /*!<Output Compare 3 Clear Enable */

/*******************  Bit definition for ATMR_CCEN register  ******************/
#define ATMR_CCEN_CC0EN_Pos                   (0U)
#define ATMR_CCEN_CC0EN_Msk                   (0x1UL << ATMR_CCEN_CC0EN_Pos)                    /*!< 0x00000001 */
#define ATMR_CCEN_CC0EN                       ATMR_CCEN_CC0EN_Msk                               /*!<Capture/Compare 0 output enable */
#define ATMR_CCEN_CC0POL_Pos                  (1U)
#define ATMR_CCEN_CC0POL_Msk                  (0x1UL << ATMR_CCEN_CC0POL_Pos)                   /*!< 0x00000002 */
#define ATMR_CCEN_CC0POL                      ATMR_CCEN_CC0POL_Msk                              /*!<Capture/Compare 0 output Polarity */
#define ATMR_CCEN_CC0NEN_Pos                  (2U)
#define ATMR_CCEN_CC0NEN_Msk                  (0x1UL << ATMR_CCEN_CC0NEN_Pos)                   /*!< 0x00000004 */
#define ATMR_CCEN_CC0NEN                      ATMR_CCEN_CC0NEN_Msk                              /*!<Capture/Compare 0 Complementary output enable */
#define ATMR_CCEN_CC0NPOL_Pos                 (3U)
#define ATMR_CCEN_CC0NPOL_Msk                 (0x1UL << ATMR_CCEN_CC0NPOL_Pos)                  /*!< 0x00000008 */
#define ATMR_CCEN_CC0NPOL                     ATMR_CCEN_CC0NPOL_Msk                             /*!<Capture/Compare 0 Complementary output Polarity */
#define ATMR_CCEN_CC1EN_Pos                   (4U)
#define ATMR_CCEN_CC1EN_Msk                   (0x1UL << ATMR_CCEN_CC1EN_Pos)                    /*!< 0x00000010 */
#define ATMR_CCEN_CC1EN                       ATMR_CCEN_CC1EN_Msk                               /*!<Capture/Compare 1 output enable */
#define ATMR_CCEN_CC1POL_Pos                  (5U)
#define ATMR_CCEN_CC1POL_Msk                  (0x1UL << ATMR_CCEN_CC1POL_Pos)                   /*!< 0x00000020 */
#define ATMR_CCEN_CC1POL                      ATMR_CCEN_CC1POL_Msk                              /*!<Capture/Compare 1 output Polarity */
#define ATMR_CCEN_CC1NEN_Pos                  (6U)
#define ATMR_CCEN_CC1NEN_Msk                  (0x1UL << ATMR_CCEN_CC1NEN_Pos)                   /*!< 0x00000040 */
#define ATMR_CCEN_CC1NEN                      ATMR_CCEN_CC1NEN_Msk                              /*!<Capture/Compare 1 Complementary output enable */
#define ATMR_CCEN_CC1NPOL_Pos                 (7U)
#define ATMR_CCEN_CC1NPOL_Msk                 (0x1UL << ATMR_CCEN_CC1NPOL_Pos)                  /*!< 0x00000080 */
#define ATMR_CCEN_CC1NPOL                     ATMR_CCEN_CC1NPOL_Msk                             /*!<Capture/Compare 1 Complementary output Polarity */
#define ATMR_CCEN_CC2EN_Pos                   (8U)
#define ATMR_CCEN_CC2EN_Msk                   (0x1UL << ATMR_CCEN_CC2EN_Pos)                    /*!< 0x00000100 */
#define ATMR_CCEN_CC2EN                       ATMR_CCEN_CC2EN_Msk                               /*!<Capture/Compare 2 output enable */
#define ATMR_CCEN_CC2POL_Pos                  (9U)
#define ATMR_CCEN_CC2POL_Msk                  (0x1UL << ATMR_CCEN_CC2POL_Pos)                   /*!< 0x00000200 */
#define ATMR_CCEN_CC2POL                      ATMR_CCEN_CC2POL_Msk                              /*!<Capture/Compare 2 output Polarity */
#define ATMR_CCEN_CC2NEN_Pos                  (10U)
#define ATMR_CCEN_CC2NEN_Msk                  (0x1UL << ATMR_CCEN_CC2NEN_Pos)                   /*!< 0x00000400 */
#define ATMR_CCEN_CC2NEN                      ATMR_CCEN_CC2NEN_Msk                              /*!<Capture/Compare 2 Complementary output enable */
#define ATMR_CCEN_CC2NPOL_Pos                 (11U)
#define ATMR_CCEN_CC2NPOL_Msk                 (0x1UL << ATMR_CCEN_CC2NPOL_Pos)                  /*!< 0x00000800 */
#define ATMR_CCEN_CC2NPOL                     ATMR_CCEN_CC2NPOL_Msk                             /*!<Capture/Compare 2 Complementary output Polarity */
#define ATMR_CCEN_CC3EN_Pos                   (12U)
#define ATMR_CCEN_CC3EN_Msk                   (0x1UL << ATMR_CCEN_CC3EN_Pos)                    /*!< 0x00001000 */
#define ATMR_CCEN_CC3EN                       ATMR_CCEN_CC3EN_Msk                               /*!<Capture/Compare 3 output enable */
#define ATMR_CCEN_CC3POL_Pos                  (13U)
#define ATMR_CCEN_CC3POL_Msk                  (0x1UL << ATMR_CCEN_CC3POL_Pos)                   /*!< 0x00002000 */
#define ATMR_CCEN_CC3POL                      ATMR_CCEN_CC3POL_Msk                              /*!<Capture/Compare 3 output Polarity */

/*******************  Bit definition for ATMR_CNT register  *******************/
#define ATMR_CNT_CNT_Pos                      (0U)
#define ATMR_CNT_CNT_Msk                      (0xFFFFUL << ATMR_CNT_CNT_Pos)                    /*!< 0xFFFF */
#define ATMR_CNT_CNT                          ATMR_CNT_CNT_Msk                                  /*!<Counter Value */

/*******************  Bit definition for ATMR_PSC register  *******************/
#define ATMR_PSC_PSC_Pos                      (0U)
#define ATMR_PSC_PSC_Msk                      (0xFFFFUL << ATMR_PSC_PSC_Pos)                    /*!< 0x0000FFFF */
#define ATMR_PSC_PSC                          ATMR_PSC_PSC_Msk                                  /*!<Prescaler Value */

/*****************  Bit definition for ATMR_AUTORLD register  *****************/
#define ATMR_AUTORLD_AUTORLD_Pos              (0U)
#define ATMR_AUTORLD_AUTORLD_Msk              (0xFFFFUL << ATMR_AUTORLD_AUTORLD_Pos)            /*!< 0xFFFFFFFF */
#define ATMR_AUTORLD_AUTORLD                  ATMR_AUTORLD_AUTORLD_Msk                          /*!<actual auto-reload Value */

/*****************  Bit definition for ATMR_REPCNT register  ******************/
#define ATMR_REPCNT_REPCNT_Pos                (0U)
#define ATMR_REPCNT_REPCNT_Msk                (0xFFUL << ATMR_REPCNT_REPCNT_Pos)                /*!< 0x000000FF */
#define ATMR_REPCNT_REPCNT                    ATMR_REPCNT_REPCNT_Msk                            /*!<Repetition Counter Value */

/*******************  Bit definition for ATMR_CC0 register  *******************/
#define ATMR_CC0_CC0_Pos                      (0U)
#define ATMR_CC0_CC0_Msk                      (0xFFFFUL << ATMR_CC0_CC0_Pos)                    /*!< 0xFFFFFFFF */
#define ATMR_CC0_CC0                          ATMR_CC0_CC0_Msk                                  /*!<Capture/Compare 0 Value */

/*******************  Bit definition for ATMR_CC1 register  *******************/
#define ATMR_CC1_CC1_Pos                      (0U)
#define ATMR_CC1_CC1_Msk                      (0xFFFFUL << ATMR_CC1_CC1_Pos)                    /*!< 0xFFFF */
#define ATMR_CC1_CC1                          ATMR_CC1_CC1_Msk                                  /*!<Capture/Compare 1 Value */

/*******************  Bit definition for ATMR_CC2 register  *******************/
#define ATMR_CC2_CC2_Pos                      (0U)
#define ATMR_CC2_CC2_Msk                      (0xFFFFUL << ATMR_CC2_CC2_Pos)                    /*!< 0xFFFF */
#define ATMR_CC2_CC2                          ATMR_CC2_CC2_Msk                                  /*!<Capture/Compare 2 Value */

/*******************  Bit definition for ATMR_CC3 register  *******************/
#define ATMR_CC3_CC3_Pos                      (0U)
#define ATMR_CC3_CC3_Msk                      (0xFFFFUL << ATMR_CC3_CC3_Pos)                    /*!< 0xFFFF */
#define ATMR_CC3_CC3                          ATMR_CC3_CC3_Msk                                  /*!<Capture/Compare 3 Value */

/*******************  Bit definition for ATMR_BDT register  *******************/
#define ATMR_BDT_DTS_Pos                      (0U)
#define ATMR_BDT_DTS_Msk                      (0xFFUL << ATMR_BDT_DTS_Pos)                      /*!< 0x000000FF */
#define ATMR_BDT_DTS                          ATMR_BDT_DTS_Msk                                  /*!<DTG[0:7] bits (Dead-Time Generator set-up) */
#define ATMR_BDT_DTS_0                        (0x01UL << ATMR_BDT_DTS_Pos)                      /*!< 0x0001 */
#define ATMR_BDT_DTS_1                        (0x02UL << ATMR_BDT_DTS_Pos)                      /*!< 0x0002 */
#define ATMR_BDT_DTS_2                        (0x04UL << ATMR_BDT_DTS_Pos)                      /*!< 0x0004 */
#define ATMR_BDT_DTS_3                        (0x08UL << ATMR_BDT_DTS_Pos)                      /*!< 0x0008 */
#define ATMR_BDT_DTS_4                        (0x10UL << ATMR_BDT_DTS_Pos)                      /*!< 0x0010 */
#define ATMR_BDT_DTS_5                        (0x20UL << ATMR_BDT_DTS_Pos)                      /*!< 0x0020 */
#define ATMR_BDT_DTS_6                        (0x40UL << ATMR_BDT_DTS_Pos)                      /*!< 0x0040 */
#define ATMR_BDT_DTS_7                        (0x80UL << ATMR_BDT_DTS_Pos)                      /*!< 0x0080 */

#define ATMR_BDT_LOCKCFG_Pos                  (8U)
#define ATMR_BDT_LOCKCFG_Msk                  (0x3UL << ATMR_BDT_LOCKCFG_Pos)                   /*!< 0x00000300 */
#define ATMR_BDT_LOCKCFG                      ATMR_BDT_LOCKCFG_Msk                              /*!<LOCK[1:0] bits (Lock Configuration) */
#define ATMR_BDT_LOCKCFG_0                    (0x1UL << ATMR_BDT_LOCKCFG_Pos)                   /*!< 0x0100 */
#define ATMR_BDT_LOCKCFG_1                    (0x2UL << ATMR_BDT_LOCKCFG_Pos)                   /*!< 0x0200 */

#define ATMR_BDT_IMOS_Pos                     (10U)
#define ATMR_BDT_IMOS_Msk                     (0x1UL << ATMR_BDT_IMOS_Pos)                      /*!< 0x00000400 */
#define ATMR_BDT_IMOS                         ATMR_BDT_IMOS_Msk                                 /*!<Off-State Selection for Idle mode */
#define ATMR_BDT_RMOS_Pos                     (11U)
#define ATMR_BDT_RMOS_Msk                     (0x1UL << ATMR_BDT_RMOS_Pos)                      /*!< 0x00000800 */
#define ATMR_BDT_RMOS                         ATMR_BDT_RMOS_Msk                                 /*!<Off-State Selection for Run mode */
#define ATMR_BDT_BRKEN_Pos                    (12U)
#define ATMR_BDT_BRKEN_Msk                    (0x1UL << ATMR_BDT_BRKEN_Pos)                     /*!< 0x00001000 */
#define ATMR_BDT_BRKEN                        ATMR_BDT_BRKEN_Msk                                /*!<Break enable */
#define ATMR_BDT_BRKPOL_Pos                   (13U)
#define ATMR_BDT_BRKPOL_Msk                   (0x1UL << ATMR_BDT_BRKPOL_Pos)                    /*!< 0x00002000 */
#define ATMR_BDT_BRKPOL                       ATMR_BDT_BRKPOL_Msk                               /*!<Break Polarity */
#define ATMR_BDT_AOEN_Pos                     (14U)
#define ATMR_BDT_AOEN_Msk                     (0x1UL << ATMR_BDT_AOEN_Pos)                      /*!< 0x00004000 */
#define ATMR_BDT_AOEN                         ATMR_BDT_AOEN_Msk                                 /*!<Automatic Output enable */
#define ATMR_BDT_MOEN_Pos                     (15U)
#define ATMR_BDT_MOEN_Msk                     (0x1UL << ATMR_BDT_MOEN_Pos)                      /*!< 0x00008000 */
#define ATMR_BDT_MOEN                         ATMR_BDT_MOEN_Msk                                 /*!<Main Output enable */

/***************  Bit definition for ATMR_OUTPUTCTRL1 register  ***************/
#define ATMR_OUTPUTCTRL1_CH0_FORCE_EN_Pos     (0U)
#define ATMR_OUTPUTCTRL1_CH0_FORCE_EN_Msk     (0x01UL << ATMR_OUTPUTCTRL1_CH0_FORCE_EN_Pos)     /*!< 0x0001 */
#define ATMR_OUTPUTCTRL1_CH0_FORCE_EN         ATMR_OUTPUTCTRL1_CH0_FORCE_EN_Msk                 /*!<Outputs the Control Enable for Channel 0 */
#define ATMR_OUTPUTCTRL1_CH0N_FORCE_EN_Pos    (1U)
#define ATMR_OUTPUTCTRL1_CH0N_FORCE_EN_Msk    (0x01UL << ATMR_OUTPUTCTRL1_CH0N_FORCE_EN_Pos)    /*!< 0x0001 */
#define ATMR_OUTPUTCTRL1_CH0N_FORCE_EN        ATMR_OUTPUTCTRL1_CH0N_FORCE_EN_Msk                /*!<Complementary Channel Output Control Enable for Channel 0 */
#define ATMR_OUTPUTCTRL1_CH1_FORCE_EN_Pos     (2U)
#define ATMR_OUTPUTCTRL1_CH1_FORCE_EN_Msk     (0x01UL << ATMR_OUTPUTCTRL1_CH1_FORCE_EN_Pos)     /*!< 0x0001 */
#define ATMR_OUTPUTCTRL1_CH1_FORCE_EN         ATMR_OUTPUTCTRL1_CH1_FORCE_EN_Msk                 /*!<Outputs the Control Enable for Channel 1 */
#define ATMR_OUTPUTCTRL1_CH1N_FORCE_EN_Pos    (3U)
#define ATMR_OUTPUTCTRL1_CH1N_FORCE_EN_Msk    (0x01UL << ATMR_OUTPUTCTRL1_CH1N_FORCE_EN_Pos)    /*!< 0x0001 */
#define ATMR_OUTPUTCTRL1_CH1N_FORCE_EN        ATMR_OUTPUTCTRL1_CH1N_FORCE_EN_Msk                /*!<Complementary Channel Output Control Enable for Channel 1 */
#define ATMR_OUTPUTCTRL1_CH2_FORCE_EN_Pos     (4U)
#define ATMR_OUTPUTCTRL1_CH2_FORCE_EN_Msk     (0x01UL << ATMR_OUTPUTCTRL1_CH2_FORCE_EN_Pos)     /*!< 0x0001 */
#define ATMR_OUTPUTCTRL1_CH2_FORCE_EN         ATMR_OUTPUTCTRL1_CH2_FORCE_EN_Msk                 /*!<Outputs the Control Enable for Channel 2 */
#define ATMR_OUTPUTCTRL1_CH2N_FORCE_EN_Pos    (5U)
#define ATMR_OUTPUTCTRL1_CH2N_FORCE_EN_Msk    (0x01UL << ATMR_OUTPUTCTRL1_CH2N_FORCE_EN_Pos)    /*!< 0x0001 */
#define ATMR_OUTPUTCTRL1_CH2N_FORCE_EN        ATMR_OUTPUTCTRL1_CH2N_FORCE_EN_Msk                /*!<Complementary Channel Output Control Enable for Channel 2 */
#define ATMR_OUTPUTCTRL1_CH3_FORCE_EN_Pos     (6U)
#define ATMR_OUTPUTCTRL1_CH3_FORCE_EN_Msk     (0x01UL << ATMR_OUTPUTCTRL1_CH3_FORCE_EN_Pos)     /*!< 0x0001 */
#define ATMR_OUTPUTCTRL1_CH3_FORCE_EN         ATMR_OUTPUTCTRL1_CH3_FORCE_EN_Msk                 /*!<Outputs the Control Enable for Channel 3 */
#define ATMR_OUTPUTCTRL1_CH4_FORCE_EN_Pos     (7U)
#define ATMR_OUTPUTCTRL1_CH4_FORCE_EN_Msk     (0x01UL << ATMR_OUTPUTCTRL1_CH4_FORCE_EN_Pos)     /*!< 0x0001 */
#define ATMR_OUTPUTCTRL1_CH4_FORCE_EN         ATMR_OUTPUTCTRL1_CH4_FORCE_EN_Msk                 /*!<Outputs the Control Enable for Channel 4 */
#define ATMR_OUTPUTCTRL1_OUTPUTCTRL_BUF_Pos   (8U)
#define ATMR_OUTPUTCTRL1_OUTPUTCTRL_BUF_Msk   (0x01UL << ATMR_OUTPUTCTRL1_OUTPUTCTRL_BUF_Pos)   /*!< 0x0001 */
#define ATMR_OUTPUTCTRL1_OUTPUTCTRL_BUF       ATMR_OUTPUTCTRL1_OUTPUTCTRL_BUF_Msk               /*!<Output Control Buffering is Enable */

/***************  Bit definition for ATMR_OUTPUTCTRL2 register  ***************/
#define ATMR_OUTPUTCTRL2_CH0_FORCE_VALUE_Pos  (0U)
#define ATMR_OUTPUTCTRL2_CH0_FORCE_VALUE_Msk  (0x01UL << ATMR_OUTPUTCTRL2_CH0_FORCE_VALUE_Pos)  /*!< 0x0001 */
#define ATMR_OUTPUTCTRL2_CH0_FORCE_VALUE      ATMR_OUTPUTCTRL2_CH0_FORCE_VALUE_Msk              /*!<Outputs the Level for Channel 0 */
#define ATMR_OUTPUTCTRL2_CH0N_FORCE_VALUE_Pos (1U)
#define ATMR_OUTPUTCTRL2_CH0N_FORCE_VALUE_Msk (0x01UL << ATMR_OUTPUTCTRL2_CH0N_FORCE_VALUE_Pos) /*!< 0x0001 */
#define ATMR_OUTPUTCTRL2_CH0N_FORCE_VALUE     ATMR_OUTPUTCTRL2_CH0N_FORCE_VALUE_Msk             /*!<Complementary Channel Output Level for Channel 0 */
#define ATMR_OUTPUTCTRL2_CH1_FORCE_VALUE_Pos  (2U)
#define ATMR_OUTPUTCTRL2_CH1_FORCE_VALUE_Msk  (0x01UL << ATMR_OUTPUTCTRL2_CH1_FORCE_VALUE_Pos)  /*!< 0x0001 */
#define ATMR_OUTPUTCTRL2_CH1_FORCE_VALUE      ATMR_OUTPUTCTRL2_CH1_FORCE_VALUE_Msk              /*!<Outputs the Level for Channel 1 */
#define ATMR_OUTPUTCTRL2_CH1N_FORCE_VALUE_Pos (3U)
#define ATMR_OUTPUTCTRL2_CH1N_FORCE_VALUE_Msk (0x01UL << ATMR_OUTPUTCTRL2_CH1N_FORCE_VALUE_Pos) /*!< 0x0001 */
#define ATMR_OUTPUTCTRL2_CH1N_FORCE_VALUE     ATMR_OUTPUTCTRL2_CH1N_FORCE_VALUE_Msk             /*!<Complementary Channel Output Level for Channel 1 */
#define ATMR_OUTPUTCTRL2_CH2_FORCE_VALUE_Pos  (4U)
#define ATMR_OUTPUTCTRL2_CH2_FORCE_VALUE_Msk  (0x01UL << ATMR_OUTPUTCTRL2_CH2_FORCE_VALUE_Pos)  /*!< 0x0001 */
#define ATMR_OUTPUTCTRL2_CH2_FORCE_VALUE      ATMR_OUTPUTCTRL2_CH2_FORCE_VALUE_Msk              /*!<Outputs the Level for Channel 2 */
#define ATMR_OUTPUTCTRL2_CH2N_FORCE_VALUE_Pos (5U)
#define ATMR_OUTPUTCTRL2_CH2N_FORCE_VALUE_Msk (0x01UL << ATMR_OUTPUTCTRL2_CH2N_FORCE_VALUE_Pos) /*!< 0x0001 */
#define ATMR_OUTPUTCTRL2_CH2N_FORCE_VALUE     ATMR_OUTPUTCTRL2_CH2N_FORCE_VALUE_Msk             /*!<Complementary Channel Output Level for Channel 2 */
#define ATMR_OUTPUTCTRL2_CH3_FORCE_VALUE_Pos  (6U)
#define ATMR_OUTPUTCTRL2_CH3_FORCE_VALUE_Msk  (0x01UL << ATMR_OUTPUTCTRL2_CH3_FORCE_VALUE_Pos)  /*!< 0x0001 */
#define ATMR_OUTPUTCTRL2_CH3_FORCE_VALUE      ATMR_OUTPUTCTRL2_CH3_FORCE_VALUE_Msk              /*!<Outputs the Level for Channel 3 */
#define ATMR_OUTPUTCTRL2_CH4_FORCE_VALUE_Pos  (7U)
#define ATMR_OUTPUTCTRL2_CH4_FORCE_VALUE_Msk  (0x01UL << ATMR_OUTPUTCTRL2_CH4_FORCE_VALUE_Pos)  /*!< 0x0001 */
#define ATMR_OUTPUTCTRL2_CH4_FORCE_VALUE      ATMR_OUTPUTCTRL2_CH4_FORCE_VALUE_Msk              /*!<Outputs the Level for Channel 4 */

/****************  Bit definition for ATMR_CH4CFG register  *******************/
#define ATMR_CH4CFG_CC4E_Pos                  (8U)
#define ATMR_CH4CFG_CC4E_Msk                  (0x01UL << ATMR_CH4CFG_CC4E_Pos)                  /*!< 0x0001 */
#define ATMR_CH4CFG_CC4E                      ATMR_CH4CFG_CC4E_Msk                              /*!<Capture/Compare 4 output enable */
#define ATMR_CH4CFG_OC4CE_Pos                 (9U)
#define ATMR_CH4CFG_OC4CE_Msk                 (0x01UL << ATMR_CH4CFG_OC4CE_Pos)                 /*!< 0x0001 */
#define ATMR_CH4CFG_OC4CE                     ATMR_CH4CFG_OC4CE_Msk                             /*!<Output Compare 4 clear enable */

#define ATMR_CH4CFG_OC4M_Pos                  (10U)
#define ATMR_CH4CFG_OC4M_Msk                  (0x07UL << ATMR_CH4CFG_OC4M_Pos)                  /*!< 0x0001 */
#define ATMR_CH4CFG_OC4M                      ATMR_CH4CFG_OC4M_Msk                              /*!<Output Compare 4 mode */
#define ATMR_CH4CFG_OC4M_0                    (0x1UL << ATMR_CH4CFG_OC4M_Pos)
#define ATMR_CH4CFG_OC4M_1                    (0x2UL << ATMR_CH4CFG_OC4M_Pos)
#define ATMR_CH4CFG_OC4M_2                    (0x4UL << ATMR_CH4CFG_OC4M_Pos)

#define ATMR_CH4CFG_OC4P_Pos                  (13U)
#define ATMR_CH4CFG_OC4P_Msk                  (0x01UL << ATMR_CH4CFG_OC4P_Pos)                  /*!< 0x0001 */
#define ATMR_CH4CFG_OC4P                      ATMR_CH4CFG_OC4P_Msk                              /*!<Capture/Compare 4 output polarity */
#define ATMR_CH4CFG_OC4PE_Pos                 (16U)
#define ATMR_CH4CFG_OC4PE_Msk                 (0x01UL << ATMR_CH4CFG_OC4PE_Pos)                 /*!< 0x0001 */
#define ATMR_CH4CFG_OC4PE                     ATMR_CH4CFG_OC4PE_Msk                             /*!<Output compare 4 preload enable */
#define ATMR_CH4CFG_CC4G_Pos                  (17U)
#define ATMR_CH4CFG_CC4G_Msk                  (0x01UL << ATMR_CH4CFG_CC4G_Pos)                  /*!< 0x0001 */
#define ATMR_CH4CFG_CC4G                      ATMR_CH4CFG_CC4G_Msk                              /*!<Capture/compare 4 generation */

/*******************  Bit definition for ATMR_TRGOCR register  ****************/
#define ATMR_TRGOCR_MMS1_Pos                  (0U)
#define ATMR_TRGOCR_MMS1_Msk                  (0xFUL << ATMR_TRGOCR_MMS1_Pos)                   /*!< 0xF */
#define ATMR_TRGOCR_MMS1                      ATMR_TRGOCR_MMS1_Msk                              /*!<Master mode selection 1 */
#define ATMR_TRGOCR_MMS2_Pos                  (4U)
#define ATMR_TRGOCR_MMS2_Msk                  (0xFUL << ATMR_TRGOCR_MMS2_Pos)                   /*!< 0xFFFF */
#define ATMR_TRGOCR_MMS2                      ATMR_TRGOCR_MMS2_Msk                              /*!<Master mode selection 2 */

/*******************  Bit definition for ATMR_BREAK register  *****************/
#define ATMR_BREAK_ANA_BRK_FILT_EN_Pos        (0U)
#define ATMR_BREAK_ANA_BRK_FILT_EN_Msk        (0x01UL << ATMR_BREAK_ANA_BRK_FILT_EN_Pos)        /*!< 0x0001 */
#define ATMR_BREAK_ANA_BRK_FILT_EN            ATMR_BREAK_ANA_BRK_FILT_EN_Msk                    /*!<Analog Break_in Fliter Enable */
#define ATMR_BREAK_BRK_FILT_EN_Pos            (1U)
#define ATMR_BREAK_BRK_FILT_EN_Msk            (0x01UL << ATMR_BREAK_BRK_FILT_EN_Pos)            /*!< 0x0001 */
#define ATMR_BREAK_BRK_FILT_EN                ATMR_BREAK_BRK_FILT_EN_Msk                        /*!<Break_in Fliter Enable */
#define ATMR_BREAK_BRK_FILT_Pos               (2U)
#define ATMR_BREAK_BRK_FILT_Msk               (0x3FUL << ATMR_BREAK_BRK_FILT_Pos)               /*!< 0x003F */
#define ATMR_BREAK_BRK_FILT                   ATMR_BREAK_BRK_FILT_Msk                           /*!<Filter coefficient */

/*******************  Bit definition for ATMR_CC4 register  *******************/
#define ATMR_CC4_CC4_Pos                      (0U)
#define ATMR_CC4_CC4_Msk                      (0xFFFFUL << ATMR_CC4_CC4_Pos)                    /*!< 0xFFFF */
#define ATMR_CC4_CC4                          ATMR_CC4_CC4_Msk                                  /*!<Capture/Compare 4 Value  */

/*******************  Bit definition for ATMR_OCXAEN register  ****************/
#define ATMR_OCXAEN_OC0AEN_Pos                (0U)
#define ATMR_OCXAEN_OC0AEN_Msk                (0x01UL << ATMR_OCXAEN_OC0AEN_Pos)                /*!< 0x00000001 */
#define ATMR_OCXAEN_OC0AEN                    ATMR_OCXAEN_OC0AEN_Msk                            /*!<Channel 0 Asymmetric PWM Output Mode Enable  */
#define ATMR_OCXAEN_OC1AEN_Pos                (1U)
#define ATMR_OCXAEN_OC1AEN_Msk                (0x01UL << ATMR_OCXAEN_OC1AEN_Pos)                /*!< 0x00000002 */
#define ATMR_OCXAEN_OC1AEN                    ATMR_OCXAEN_OC1AEN_Msk                            /*!<Channel 1 Asymmetric PWM Output Mode Enable  */
#define ATMR_OCXAEN_OC2AEN_Pos                (2U)
#define ATMR_OCXAEN_OC2AEN_Msk                (0x01UL << ATMR_OCXAEN_OC2AEN_Pos)                /*!< 0x00000004 */
#define ATMR_OCXAEN_OC2AEN                    ATMR_OCXAEN_OC2AEN_Msk                            /*!<Channel 2 Asymmetric PWM Output Mode Enable  */

/*******************  Bit definition for ATMR_CC0C register  ******************/
#define ATMR_CC0C_CC0C_Pos                    (0U)
#define ATMR_CC0C_CC0C_Msk                    (0xFFFFUL << ATMR_CC0C_CC0C_Pos)                  /*!< 0xFFFF */
#define ATMR_CC0C_CC0C                        ATMR_CC0C_CC0C_Msk                                /*!<Channel 0 Capture/Compare Register Complementary Register  */

/*******************  Bit definition for ATMR_CC1C register  ******************/
#define ATMR_CC1C_CC1C_Pos                    (0U)
#define ATMR_CC1C_CC1C_Msk                    (0xFFFFUL << ATMR_CC1C_CC1C_Pos)                  /*!< 0xFFFF */
#define ATMR_CC1C_CC1C                        ATMR_CC1C_CC1C_Msk                                /*!<Channel 1 Capture/Compare Register Complementary Register  */

/*******************  Bit definition for ATMR_CC2C register  ******************/
#define ATMR_CC2C_CC2C_Pos                    (0U)
#define ATMR_CC2C_CC2C_Msk                    (0xFFFFUL << ATMR_CC2C_CC2C_Pos)                  /*!< 0xFFFF */
#define ATMR_CC2C_CC2C                        ATMR_CC2C_CC2C_Msk                                /*!<Channel 2 Capture/Compare Register Complementary Register  */

/******************************************************************************/
/*                                                                            */
/*                          Basic timer control                               */
/*                                                                            */
/******************************************************************************/
/*******************  Bit definition for BTMR_CTRL1 register  *****************/
#define BTMR_CTRL1_CNTEN_Pos                  (0UL)                                             /*!< CNTEN (Bit 0) */
#define BTMR_CTRL1_CNTEN_Msk                  (0x1UL << BTMR_CTRL1_CNTEN_Pos)                   /*!< CNTEN (Bitfield-Mask: 0x01) */
#define BTMR_CTRL1_CNTEN                      BTMR_CTRL1_CNTEN_Msk
#define BTMR_CTRL1_CNTDIR_Pos                 (1UL)                                             /*!< CNTDIR (Bit 1) */
#define BTMR_CTRL1_CNTDIR_Msk                 (0x1UL << BTMR_CTRL1_CNTDIR_Pos)                  /*!< CNTDIR (Bitfield-Mask: 0x01) */
#define BTMR_CTRL1_CNTDIR                     BTMR_CTRL1_CNTDIR_Msk
#define BTMR_CTRL1_SPMEN_Pos                  (2UL)                                             /*!< SPMEN (Bit 2) */
#define BTMR_CTRL1_SPMEN_Msk                  (0x1UL << BTMR_CTRL1_SPMEN_Pos)                   /*!< SPMEN (Bitfield-Mask: 0x01) */
#define BTMR_CTRL1_SPMEN                      BTMR_CTRL1_SPMEN_Msk
#define BTMR_CTRL1_UPEN_Pos                   (3UL)                                             /*!< UPEN (Bit 3) */
#define BTMR_CTRL1_UPEN_Msk                   (0x1UL << BTMR_CTRL1_UPEN_Pos)                    /*!< UPEN (Bitfield-Mask: 0x01) */
#define BTMR_CTRL1_UPEN                       BTMR_CTRL1_UPEN_Msk
#define BTMR_CTRL1_CAMSEL_Pos                 (4UL)                                             /*!< CAMSEL (Bit 4) */
#define BTMR_CTRL1_CAMSEL_Msk                 (0x3UL << BTMR_CTRL1_CAMSEL_Pos)                  /*!< CAMSEL (Bitfield-Mask: 0x03) */
#define BTMR_CTRL1_CAMSEL                     BTMR_CTRL1_CAMSEL_Msk
#define BTMR_CTRL1_CAMSEL_0                   (0x1UL << BTMR_CTRL1_CAMSEL_Pos)
#define BTMR_CTRL1_CAMSEL_1                   (0x2UL << BTMR_CTRL1_CAMSEL_Pos)

#define BTMR_CTRL1_ALD_BUFF_EN_Pos            (6UL)                                             /*!< ALD_BUFF_EN (Bit 6) */
#define BTMR_CTRL1_ALD_BUFF_EN_Msk            (0x1UL << BTMR_CTRL1_ALD_BUFF_EN_Pos)             /*!< ALD_BUFF_EN (Bitfield-Mask: 0x01) */
#define BTMR_CTRL1_ALD_BUFF_EN                BTMR_CTRL1_ALD_BUFF_EN_Msk
#define BTMR_CTRL1_PSC_BUFF_EN_Pos            (7UL)                                             /*!< PSC_BUFF_EN (Bit 7) */
#define BTMR_CTRL1_PSC_BUFF_EN_Msk            (0x1UL << BTMR_CTRL1_PSC_BUFF_EN_Pos)             /*!< PSC_BUFF_EN (Bitfield-Mask: 0x01) */
#define BTMR_CTRL1_PSC_BUFF_EN                BTMR_CTRL1_PSC_BUFF_EN_Msk

/*******************  Bit definition for BTMR_CCM1 register  ****************/
#define BTMR_CCM1_CC0EN_Pos                   (0UL)                                             /*!< CC0EN (Bit 0) */
#define BTMR_CCM1_CC0EN_Msk                   (0x1UL << BTMR_CCM1_CC0EN_Pos)                    /*!< CC0EN (Bitfield-Mask: 0x01) */
#define BTMR_CCM1_CC0EN                       BTMR_CCM1_CC0EN_Msk
#define BTMR_CCM1_CC0POL_Pos                  (1UL)                                             /*!< CC0POL (Bit 1) */
#define BTMR_CCM1_CC0POL_Msk                  (0x1UL << BTMR_CCM1_CC0POL_Pos)                   /*!< CC0POL (Bitfield-Mask: 0x01) */
#define BTMR_CCM1_CC0POL                      BTMR_CCM1_CC0POL_Msk
#define BTMR_CCM1_CC0_EDGE_SEL_Pos            (2UL)                                             /*!< CC0_EDGE_SEL (Bit 2) */
#define BTMR_CCM1_CC0_EDGE_SEL_Msk            (0x3UL << BTMR_CCM1_CC0_EDGE_SEL_Pos)             /*!< CC0_EDGE_SEL (Bitfield-Mask: 0x03) */
#define BTMR_CCM1_CC0_EDGE_SEL                BTMR_CCM1_CC0_EDGE_SEL_Msk
#define BTMR_CCM1_CC0_EDGE_SEL_0              (0x1UL << BTMR_CCM1_CC0_EDGE_SEL_Pos)
#define BTMR_CCM1_CC0_EDGE_SEL_1              (0x2UL << BTMR_CCM1_CC0_EDGE_SEL_Pos)
#define BTMR_CCM1_IC0F_Pos                    (4UL)                                             /*!< IC0F (Bit 4) */
#define BTMR_CCM1_IC0F_Msk                    (0x7UL << BTMR_CCM1_IC0F_Pos)                     /*!< IC0F (Bitfield-Mask: 0x07) */
#define BTMR_CCM1_IC0F                        BTMR_CCM1_IC0F_Msk
#define BTMR_CCM1_IC0F_0                      (0x1UL << BTMR_CCM1_IC0F_Pos)
#define BTMR_CCM1_IC0F_1                      (0x2UL << BTMR_CCM1_IC0F_Pos)
#define BTMR_CCM1_IC0F_2                      (0x4UL << BTMR_CCM1_IC0F_Pos)
#define BTMR_CCM1_OC0MOD_Pos                  (7UL)                                             /*!< OC0MOD (Bit 7) */
#define BTMR_CCM1_OC0MOD_Msk                  (0x7UL << BTMR_CCM1_OC0MOD_Pos)                   /*!< OC0MOD (Bitfield-Mask: 0x07) */
#define BTMR_CCM1_OC0MOD                      BTMR_CCM1_OC0MOD_Msk
#define BTMR_CCM1_OC0MOD_0                    (0x1UL << BTMR_CCM1_OC0MOD_Pos)
#define BTMR_CCM1_OC0MOD_1                    (0x2UL << BTMR_CCM1_OC0MOD_Pos)
#define BTMR_CCM1_OC0MOD_2                    (0x4UL << BTMR_CCM1_OC0MOD_Pos)
#define BTMR_CCM1_CC1EN_Pos                   (10UL)                                            /*!< CC1EN (Bit 10) */
#define BTMR_CCM1_CC1EN_Msk                   (0x1UL << BTMR_CCM1_CC1EN_Pos)                    /*!< CC1EN (Bitfield-Mask: 0x01) */
#define BTMR_CCM1_CC1EN                       BTMR_CCM1_CC1EN_Msk
#define BTMR_CCM1_CC1POL_Pos                  (11UL)                                            /*!< CC1POL (Bit 11) */
#define BTMR_CCM1_CC1POL_Msk                  (0x1UL << BTMR_CCM1_CC1POL_Pos)                   /*!< CC1POL (Bitfield-Mask: 0x01) */
#define BTMR_CCM1_CC1POL                      BTMR_CCM1_CC1POL_Msk
#define BTMR_CCM1_CC1_EDGE_SEL_Pos            (12UL)                                            /*!< CC1_EDGE_SEL (Bit 12) */
#define BTMR_CCM1_CC1_EDGE_SEL_Msk            (0x3UL << BTMR_CCM1_CC1_EDGE_SEL_Pos)             /*!< CC1_EDGE_SEL (Bitfield-Mask: 0x03) */
#define BTMR_CCM1_CC1_EDGE_SEL                BTMR_CCM1_CC1_EDGE_SEL_Msk
#define BTMR_CCM1_IC1F_Pos                    (14UL)                                            /*!< IC1F (Bit 14) */
#define BTMR_CCM1_IC1F_Msk                    (0x7UL << BTMR_CCM1_IC1F_Pos)                     /*!< IC1F (Bitfield-Mask: 0x07) */
#define BTMR_CCM1_IC1F                        BTMR_CCM1_IC1F_Msk
#define BTMR_CCM1_OC1MOD_Pos                  (17UL)                                            /*!< OC1MOD (Bit 17) */
#define BTMR_CCM1_OC1MOD_Msk                  (0x7UL << BTMR_CCM1_OC1MOD_Pos)                   /*!< OC1MOD (Bitfield-Mask: 0x07) */
#define BTMR_CCM1_OC1MOD                      BTMR_CCM1_OC1MOD_Msk
#define BTMR_CCM1_CC2EN_Pos                   (20UL)                                            /*!< CC2EN (Bit 20) */
#define BTMR_CCM1_CC2EN_Msk                   (0x1UL << BTMR_CCM1_CC2EN_Pos)                    /*!< CC2EN (Bitfield-Mask: 0x01) */
#define BTMR_CCM1_CC2EN                       BTMR_CCM1_CC2EN_Msk
#define BTMR_CCM1_CC2POL_Pos                  (21UL)                                            /*!< CC2POL (Bit 21) */
#define BTMR_CCM1_CC2POL_Msk                  (0x1UL << BTMR_CCM1_CC2POL_Pos)                   /*!< CC2POL (Bitfield-Mask: 0x01) */
#define BTMR_CCM1_CC2POL                      BTMR_CCM1_CC2POL_Msk
#define BTMR_CCM1_CC2_EDGE_SEL_Pos            (22UL)                                            /*!< CC2_EDGE_SEL (Bit 22) */
#define BTMR_CCM1_CC2_EDGE_SEL_Msk            (0x3UL << BTMR_CCM1_CC2_EDGE_SEL_Pos)             /*!< CC2_EDGE_SEL (Bitfield-Mask: 0x03) */
#define BTMR_CCM1_CC2_EDGE_SEL                BTMR_CCM1_CC2_EDGE_SEL_Msk
#define BTMR_CCM1_IC2F_Pos                    (24UL)                                            /*!< IC2F (Bit 24) */
#define BTMR_CCM1_IC2F_Msk                    (0x7UL << BTMR_CCM1_IC2F_Pos)                     /*!< IC2F (Bitfield-Mask: 0x07) */
#define BTMR_CCM1_IC2F                        BTMR_CCM1_IC2F_Msk
#define BTMR_CCM1_OC2MOD_Pos                  (27UL)                                            /*!< OC2MOD (Bit 27) */
#define BTMR_CCM1_OC2MOD_Msk                  (0x7UL << BTMR_CCM1_OC2MOD_Pos)                   /*!< OC2MOD (Bitfield-Mask: 0x07) */
#define BTMR_CCM1_OC2MOD                      BTMR_CCM1_OC2MOD_Msk

/*******************  Bit definition for BTMR_CCM2 register  ****************/
#define BTMR_CCM2_CC0_BUFF_EN_Pos             (0UL)                                             /*!< CC0_BUFF_EN (Bit 0) */
#define BTMR_CCM2_CC0_BUFF_EN_Msk             (0x1UL << BTMR_CCM2_CC0_BUFF_EN_Pos)              /*!< CC0_BUFF_EN (Bitfield-Mask: 0x01) */
#define BTMR_CCM2_CC0_BUFF_EN                 BTMR_CCM2_CC0_BUFF_EN_Msk
#define BTMR_CCM2_CC1_BUFF_EN_Pos             (1UL)                                             /*!< CC1_BUFF_EN (Bit 1) */
#define BTMR_CCM2_CC1_BUFF_EN_Msk             (0x1UL << BTMR_CCM2_CC1_BUFF_EN_Pos)              /*!< CC1_BUFF_EN (Bitfield-Mask: 0x01) */
#define BTMR_CCM2_CC1_BUFF_EN                 BTMR_CCM2_CC1_BUFF_EN_Msk
#define BTMR_CCM2_CC2_BUFF_EN_Pos             (2UL)                                             /*!< CC2_BUFF_EN (Bit 2) */
#define BTMR_CCM2_CC2_BUFF_EN_Msk             (0x1UL << BTMR_CCM2_CC2_BUFF_EN_Pos)              /*!< CC2_BUFF_EN (Bitfield-Mask: 0x01) */
#define BTMR_CCM2_CC2_BUFF_EN                 BTMR_CCM2_CC2_BUFF_EN_Msk
#define BTMR_CCM2_CC0_IOSEL_Pos               (3UL)                                             /*!< CC0_IOSEL (Bit 3) */
#define BTMR_CCM2_CC0_IOSEL_Msk               (0x1UL << BTMR_CCM2_CC0_IOSEL_Pos)                /*!< CC0_IOSEL (Bitfield-Mask: 0x01) */
#define BTMR_CCM2_CC0_IOSEL                   BTMR_CCM2_CC0_IOSEL_Msk
#define BTMR_CCM2_CC1_IOSEL_Pos               (4UL)                                             /*!< CC1_IOSEL (Bit 4) */
#define BTMR_CCM2_CC1_IOSEL_Msk               (0x1UL << BTMR_CCM2_CC1_IOSEL_Pos)                /*!< CC1_IOSEL (Bitfield-Mask: 0x01) */
#define BTMR_CCM2_CC1_IOSEL                   BTMR_CCM2_CC1_IOSEL_Msk
#define BTMR_CCM2_CC2_IOSEL_Pos               (5UL)                                             /*!< CC2_IOSEL (Bit 5) */
#define BTMR_CCM2_CC2_IOSEL_Msk               (0x1UL << BTMR_CCM2_CC2_IOSEL_Pos)                /*!< CC2_IOSEL (Bitfield-Mask: 0x01) */
#define BTMR_CCM2_CC2_IOSEL                   BTMR_CCM2_CC2_IOSEL_Msk

/*******************  Bit definition for BTMR_CEG register  *******************/
#define BTMR_CEG_UEG_Pos                      (0UL)                                             /*!< UEG (Bit 0) */
#define BTMR_CEG_UEG_Msk                      (0x1UL << BTMR_CEG_UEG_Pos)                       /*!< UEG (Bitfield-Mask: 0x01) */
#define BTMR_CEG_UEG                          BTMR_CEG_UEG_Msk
#define BTMR_CEG_CC0EG_Pos                    (1UL)                                             /*!< CC0EG (Bit 1) */
#define BTMR_CEG_CC0EG_Msk                    (0x1UL << BTMR_CEG_CC0EG_Pos)                     /*!< CC0EG (Bitfield-Mask: 0x01) */
#define BTMR_CEG_CC0EG                        BTMR_CEG_CC0EG_Msk
#define BTMR_CEG_CC1EG_Pos                    (2UL)                                             /*!< CC1EG (Bit 2) */
#define BTMR_CEG_CC1EG_Msk                    (0x1UL << BTMR_CEG_CC1EG_Pos)                     /*!< CC1EG (Bitfield-Mask: 0x01) */
#define BTMR_CEG_CC1EG                        BTMR_CEG_CC1EG_Msk
#define BTMR_CEG_CC2EG_Pos                    (3UL)                                             /*!< CC2EG (Bit 3) */
#define BTMR_CEG_CC2EG_Msk                    (0x1UL << BTMR_CEG_CC2EG_Pos)                     /*!< CC2EG (Bitfield-Mask: 0x01) */
#define BTMR_CEG_CC2EG                        BTMR_CEG_CC2EG_Msk

/*******************  Bit definition for BTMR_IEN register  *******************/
#define BTMR_IEN_UIEN_Pos                     (0UL)                                             /*!< UIEN (Bit 0) */
#define BTMR_IEN_UIEN_Msk                     (0x1UL << BTMR_IEN_UIEN_Pos)                      /*!< UIEN (Bitfield-Mask: 0x01) */
#define BTMR_IEN_UIEN                         BTMR_IEN_UIEN_Msk
#define BTMR_IEN_CC0IEN_Pos                   (1UL)                                             /*!< CC0IEN (Bit 1) */
#define BTMR_IEN_CC0IEN_Msk                   (0x1UL << BTMR_IEN_CC0IEN_Pos)                    /*!< CC0IEN (Bitfield-Mask: 0x01) */
#define BTMR_IEN_CC0IEN                       BTMR_IEN_CC0IEN_Msk
#define BTMR_IEN_CC1IEN_Pos                   (2UL)                                             /*!< CC1IEN (Bit 2) */
#define BTMR_IEN_CC1IEN_Msk                   (0x1UL << BTMR_IEN_CC1IEN_Pos)                    /*!< CC1IEN (Bitfield-Mask: 0x01) */
#define BTMR_IEN_CC1IEN                       BTMR_IEN_CC1IEN_Msk
#define BTMR_IEN_CC2IEN_Pos                   (3UL)                                             /*!< CC2IEN (Bit 3) */
#define BTMR_IEN_CC2IEN_Msk                   (0x1UL << BTMR_IEN_CC2IEN_Pos)                    /*!< CC2IEN (Bitfield-Mask: 0x01) */
#define BTMR_IEN_CC2IEN                       BTMR_IEN_CC2IEN_Msk

/*******************  Bit definition for BTMR_STS register  *******************/
#define BTMR_STS_CC0IFLG_Pos                  (0UL)                                             /*!< CC0IFLG (Bit 0) */
#define BTMR_STS_CC0IFLG_Msk                  (0x1UL << BTMR_STS_CC0IFLG_Pos)                   /*!< CC0IFLG (Bitfield-Mask: 0x01) */
#define BTMR_STS_CC0IFLG                      BTMR_STS_CC0IFLG_Msk
#define BTMR_STS_CC1IFLG_Pos                  (1UL)                                             /*!< CC1IFLG (Bit 1) */
#define BTMR_STS_CC1IFLG_Msk                  (0x1UL << BTMR_STS_CC1IFLG_Pos)                   /*!< CC1IFLG (Bitfield-Mask: 0x01) */
#define BTMR_STS_CC1IFLG                      BTMR_STS_CC1IFLG_Msk
#define BTMR_STS_CC2IFLG_Pos                  (2UL)                                             /*!< CC2IFLG (Bit 2) */
#define BTMR_STS_CC2IFLG_Msk                  (0x1UL << BTMR_STS_CC2IFLG_Pos)                   /*!< CC2IFLG (Bitfield-Mask: 0x01) */
#define BTMR_STS_CC2IFLG                      BTMR_STS_CC2IFLG_Msk
#define BTMR_STS_UIFLG_Pos                    (3UL)                                             /*!< UIFLG (Bit 3) */
#define BTMR_STS_UIFLG_Msk                    (0x1UL << BTMR_STS_UIFLG_Pos)                     /*!< UIFLG (Bitfield-Mask: 0x01) */
#define BTMR_STS_UIFLG                        BTMR_STS_UIFLG_Msk
#define BTMR_STS_CC0RCFLG_Pos                 (4UL)                                             /*!< CC0RCFLG (Bit 4) */
#define BTMR_STS_CC0RCFLG_Msk                 (0x1UL << BTMR_STS_CC0RCFLG_Pos)                  /*!< CC0RCFLG (Bitfield-Mask: 0x01) */
#define BTMR_STS_CC0RCFLG                     BTMR_STS_CC0RCFLG_Msk
#define BTMR_STS_CC1RCFLG_Pos                 (5UL)                                             /*!< CC1RCFLG (Bit 5) */
#define BTMR_STS_CC1RCFLG_Msk                 (0x1UL << BTMR_STS_CC1RCFLG_Pos)                  /*!< CC1RCFLG (Bitfield-Mask: 0x01) */
#define BTMR_STS_CC1RCFLG                     BTMR_STS_CC1RCFLG_Msk
#define BTMR_STS_CC2RCFLG_Pos                 (6UL)                                             /*!< CC2RCFLG (Bit 6) */
#define BTMR_STS_CC2RCFLG_Msk                 (0x1UL << BTMR_STS_CC2RCFLG_Pos)                  /*!< CC2RCFLG (Bitfield-Mask: 0x01) */
#define BTMR_STS_CC2RCFLG                     BTMR_STS_CC2RCFLG_Msk

/*******************  Bit definition for BTMR_CNT register  *******************/
#define BTMR_CNT_CNT_Pos                      (0UL)                                             /*!< CNT (Bit 0) */
#define BTMR_CNT_CNT_Msk                      (0xFFFFUL << BTMR_CNT_CNT_Pos)                    /*!< CNT (Bitfield-Mask: 0xffff) */
#define BTMR_CNT_CNT                          BTMR_CNT_CNT_Msk

/*******************  Bit definition for BTMR_PSC register  *******************/
#define BTMR_PSC_PSC_Pos                      (0UL)                                             /*!< PSC (Bit 0) */
#define BTMR_PSC_PSC_Msk                      (0xFFFFUL << BTMR_PSC_PSC_Pos)                    /*!< PSC (Bitfield-Mask: 0xffff) */
#define BTMR_PSC_PSC                          BTMR_PSC_PSC_Msk

/*******************  Bit definition for BTMR_AUTORLD register  ***************/
#define BTMR_AUTORLD_AUTORLD_Pos              (0UL)                                             /*!< AUTORLD (Bit 0) */
#define BTMR_AUTORLD_AUTORLD_Msk              (0xFFFFUL << BTMR_AUTORLD_AUTORLD_Pos)            /*!< AUTORLD (Bitfield-Mask: 0xffff) */
#define BTMR_AUTORLD_AUTORLD                  BTMR_AUTORLD_AUTORLD_Msk

/*******************  Bit definition for BTMR_CC0 register  *******************/
#define BTMR_CC0_CC0_Pos                      (0UL)                                             /*!< CC0 (Bit 0) */
#define BTMR_CC0_CC0_Msk                      (0xFFFFUL << BTMR_CC0_CC0_Pos)                    /*!< CC0 (Bitfield-Mask: 0xffff) */
#define BTMR_CC0_CC0                          BTMR_CC0_CC0_Msk

/*******************  Bit definition for BTMR_CC1 register  *******************/
#define BTMR_CC1_CC1_Pos                      (0UL)                                             /*!< CC1 (Bit 0) */
#define BTMR_CC1_CC1_Msk                      (0xFFFFUL << BTMR_CC1_CC1_Pos)                    /*!< CC1 (Bitfield-Mask: 0xffff) */
#define BTMR_CC1_CC1                          BTMR_CC1_CC1_Msk

/*******************  Bit definition for BTMR_CC2 register  *******************/
#define BTMR_CC2_CC2_Pos                      (0UL)                                             /*!< CC2 (Bit 0) */
#define BTMR_CC2_CC2_Msk                      (0xFFFFUL << BTMR_CC2_CC2_Pos)                    /*!< CC2 (Bitfield-Mask: 0xffff) */
#define BTMR_CC2_CC2                          BTMR_CC2_CC2_Msk

/******************************************************************************/
/*                                                                            */
/*                                  Comparer                                  */
/*                                                                            */
/******************************************************************************/
/********************  Bit definition for COMP_CSTS register  *****************/
#define COMP_CSTS_EN_LV_Pos                   (0UL)                                             /*!< EN_LV (Bit 0) */
#define COMP_CSTS_EN_LV_Msk                   (0x1UL << COMP_CSTS_EN_LV_Pos)                    /*!< EN_LV (Bitfield-Mask: 0x01) */
#define COMP_CSTS_EN_LV                       COMP_CSTS_EN_LV_Msk                               /*!< Comparator enable bit */
#define COMP_CSTS_VN_EN_Pos                   (4UL)                                             /*!< VN_EN (Bit 4) */
#define COMP_CSTS_VN_EN_0                     (0x1UL << COMP_CSTS_VN_EN_Pos)
#define COMP_CSTS_VN_EN_1                     (0x2UL << COMP_CSTS_VN_EN_Pos)
#define COMP_CSTS_VN_EN_2                     (0x4UL << COMP_CSTS_VN_EN_Pos)
#define COMP_CSTS_VN_EN_Msk                   (0x7UL << COMP_CSTS_VN_EN_Pos)                    /*!< VN_EN (Bitfield-Mask: 0x07) */
#define COMP_CSTS_VN_EN                       COMP_CSTS_VN_EN_Msk                               /*!< Comparator VN source bit bit */
#define COMP_CSTS_VP_EN_Pos                   (7UL)                                             /*!< VP_EN (Bit 7) */
#define COMP_CSTS_VP_EN_0                     (0x1UL << COMP_CSTS_VP_EN_Pos)
#define COMP_CSTS_VP_EN_1                     (0x2UL << COMP_CSTS_VP_EN_Pos)
#define COMP_CSTS_VP_EN_2                     (0x4UL << COMP_CSTS_VP_EN_Pos)
#define COMP_CSTS_VP_EN_Msk                   (0x7UL << COMP_CSTS_VP_EN_Pos)                    /*!< VP_EN (Bitfield-Mask: 0x07) */
#define COMP_CSTS_VP_EN                       COMP_CSTS_VP_EN_Msk                               /*!< Comparator VP source bit */
#define COMP_CSTS_TMR_SEL_Pos                 (10UL)                                            /*!< TMR_SEL (Bit 8) */
#define COMP_CSTS_TMR_SEL_0                   (0x1UL << COMP_CSTS_TMR_SEL_Pos)
#define COMP_CSTS_TMR_SEL_1                   (0x2UL << COMP_CSTS_TMR_SEL_Pos)
#define COMP_CSTS_TMR_SEL_2                   (0x4UL << COMP_CSTS_TMR_SEL_Pos)
#define COMP_CSTS_TMR_SEL_Msk                 (0x7UL << COMP_CSTS_TMR_SEL_Pos)                  /*!< TMR_SEL (Bitfield-Mask: 0x07) */
#define COMP_CSTS_TMR_SEL                     COMP_CSTS_TMR_SEL_Msk
#define COMP_CSTS_POL_Pos                     (13UL)                                            /*!< POL (Bit 13) */
#define COMP_CSTS_POL_Msk                     (0x1UL << COMP_CSTS_POL_Pos)                      /*!< POL (Bitfield-Mask: 0x01) */
#define COMP_CSTS_POL                         COMP_CSTS_POL_Msk
#define COMP_CSTS_HYS_EN_Pos                  (14UL)                                            /*!< HYS_EN (Bit 14) */
#define COMP_CSTS_HYS_EN_0                    (0x1UL << COMP_CSTS_HYS_EN_Pos)
#define COMP_CSTS_HYS_EN_1                    (0x2UL << COMP_CSTS_HYS_EN_Pos)
#define COMP_CSTS_HYS_EN_Msk                  (0x3UL << COMP_CSTS_HYS_EN_Pos)                   /*!< HYS_EN (Bitfield-Mask: 0x03) */
#define COMP_CSTS_HYS_EN                      COMP_CSTS_HYS_EN_Msk
#define COMP_CSTS_R_EN_Pos                    (18UL)                                            /*!< R_EN (Bit 18) */
#define COMP_CSTS_R_EN_Msk                    (0x1UL << COMP_CSTS_R_EN_Pos)                     /*!< R_EN (Bitfield-Mask: 0x01) */
#define COMP_CSTS_R_EN                        COMP_CSTS_R_EN_Msk
#define COMP_CSTS_F_EN_Pos                    (19UL)                                            /*!< F_EN (Bit 19) */
#define COMP_CSTS_F_EN_Msk                    (0x1UL << COMP_CSTS_F_EN_Pos)                     /*!< F_EN (Bitfield-Mask: 0x01) */
#define COMP_CSTS_F_EN                        COMP_CSTS_F_EN_Msk
#define COMP_CSTS_RF_EN_Pos                   (20UL)                                            /*!< RF_EN (Bit 20) */
#define COMP_CSTS_RF_EN_Msk                   (0x1UL << COMP_CSTS_RF_EN_Pos)                    /*!< RF_EN (Bitfield-Mask: 0x01) */
#define COMP_CSTS_RF_EN                       COMP_CSTS_RF_EN_Msk
#define COMP_CSTS_SWINT_Pos                   (21UL)                                            /*!< SWINT (Bit 21) */
#define COMP_CSTS_SWINT_Msk                   (0x1UL << COMP_CSTS_SWINT_Pos)                    /*!< SWINT (Bitfield-Mask: 0x01) */
#define COMP_CSTS_SWINT                       COMP_CSTS_SWINT_Msk
#define COMP_CSTS_CFG_Pos                     (22UL)                                            /*!< CFG (Bit 22) */
#define COMP_CSTS_CFG_0                       (0x1UL << COMP_CSTS_CFG_Pos)
#define COMP_CSTS_CFG_1                       (0x2UL << COMP_CSTS_CFG_Pos)
#define COMP_CSTS_CFG_2                       (0x4UL << COMP_CSTS_CFG_Pos)
#define COMP_CSTS_CFG_3                       (0x8UL << COMP_CSTS_CFG_Pos)
#define COMP_CSTS_CFG_Msk                     (0xFUL << COMP_CSTS_CFG_Pos)                      /*!< CFG (Bitfield-Mask: 0x0F) */
#define COMP_CSTS_CFG                         COMP_CSTS_CFG_Msk
#define COMP_CSTS_PSC_Pos                     (26UL)                                            /*!< PSC (Bit 26) */
#define COMP_CSTS_PSC_0                       (0x1UL << COMP_CSTS_PSC_Pos)
#define COMP_CSTS_PSC_1                       (0x2UL << COMP_CSTS_PSC_Pos)
#define COMP_CSTS_PSC_2                       (0x4UL << COMP_CSTS_PSC_Pos)
#define COMP_CSTS_PSC_Msk                     (0x7UL << COMP_CSTS_PSC_Pos)                      /*!< PSC (Bitfield-Mask: 0x07) */
#define COMP_CSTS_PSC                         COMP_CSTS_PSC_Msk
#define COMP_CSTS_VALUE_Pos                   (30UL)                                            /*!< VALUE (Bit 30) */
#define COMP_CSTS_VALUE_Msk                   (0x1UL << COMP_CSTS_VALUE_Pos)                    /*!< VALUE (Bitfield-Mask: 0x01) */
#define COMP_CSTS_VALUE                       COMP_CSTS_VALUE_Msk
#define COMP_CSTS_LOCK_Pos                    (31UL)                                            /*!< LOCK (Bit 31) */
#define COMP_CSTS_LOCK_Msk                    (0x1UL << COMP_CSTS_LOCK_Pos)                     /*!< LOCK (Bitfield-Mask: 0x01) */
#define COMP_CSTS_LOCK                        COMP_CSTS_LOCK_Msk
/********************  Bit definition for COMP_CSTS register  ******************/
#define COMP_STS_STS_Pos                      (0UL)                                             /*!< STS (Bit 0) */
#define COMP_STS_STS_Msk                      (0x1UL << COMP_STS_STS_Pos)                       /*!< STS (Bitfield-Mask: 0x01) */
#define COMP_STS_STS                          COMP_STS_STS_Msk

/******************************************************************************/
/*                                                                            */
/*                                 CRC control                                */
/*                                                                            */
/******************************************************************************/
/*******************  Bit definition for CRC_DATA register  *******************/
#define CRC_DATA_DATA_Pos                     (0UL)                                             /*!< DATA (Bit 0) */
#define CRC_DATA_DATA_Msk                     (0xFFFFFFFFUL << CRC_DATA_DATA_Pos)               /*!< DATA (Bitfield-Mask: 0xFFFFFFFF) */
#define CRC_DATA_DATA                         CRC_DATA_DATA_Msk

/*******************  Bit definition for CRC_CTRL register  *******************/
#define CRC_CTRL_CRCSEL_Pos                   (0UL)                                             /*!< CTRL (Bit 0) */
#define CRC_CTRL_CRCSEL_Msk                   (0x1UL << CRC_CTRL_CRCSEL_Pos)                    /*!< CRCSEL (Bitfield-Mask: 0x01) */
#define CRC_CTRL_CRCSEL                       CRC_CTRL_CRCSEL_Msk
#define CRC_CTRL_REVI_Pos                     (1UL)                                             /*!< INFLIP (Bit 1) */
#define CRC_CTRL_REVI_0                       (0x1UL << CRC_CTRL_REVI_Pos)
#define CRC_CTRL_REVI_1                       (0x2UL << CRC_CTRL_REVI_Pos)
#define CRC_CTRL_REVI_Msk                     (0x3UL << CRC_CTRL_REVI_Pos)                      /*!< INFLIP (Bitfield-Mask: 0x03) */
#define CRC_CTRL_REVI                         CRC_CTRL_REVI_Msk
#define CRC_CTRL_REVO_Pos                     (3UL)                                             /*!< OUTFLIP (Bit 3) */
#define CRC_CTRL_REVO_Msk                     (0x1UL << CRC_CTRL_REVO_Pos)                      /*!< OUTFLIP (Bitfield-Mask: 0x01) */
#define CRC_CTRL_REVO                         CRC_CTRL_REVO_Msk

/*******************  Bit definition for CRC_INITVAL register  ****************/
#define CRC_INITVAL_VALUE_Pos                 (0UL)                                             /*!< VALUE (Bit 0) */
#define CRC_INITVAL_VALUE_Msk                 (0xFFFFFFFFUL << CRC_INITVAL_VALUE_Pos)           /*!< VALUE (Bitfield-Mask: 0xFFFFFFFF) */
#define CRC_INITVAL_VALUE                     CRC_INITVAL_VALUE_Msk


/******************************************************************************/
/*                                                                            */
/*                                 DIV control                                */
/*                                                                            */
/******************************************************************************/
/*******************  Bit definition for DIV_DVDR register  *******************/
#define DIV_DVDR_DIVIDEND_Pos                 (0UL)                                             /*!< Dividend (Bit 0) */
#define DIV_DVDR_DIVIDEND_Msk                 (0xFFFFFFFFUL << DIV_DVDR_DIVIDEND_Pos)           /*!< Dividend (Bitfield-Mask: 0xFFFFFFFF) */
#define DIV_DVDR_DIVIDEND                     DIV_DVDR_DIVIDEND_Msk

/*******************  Bit definition for DIV_DVSR register  *******************/
#define DIV_DVSR_DIVISOR_Pos                  (0UL)                                             /*!< Divisor (Bit 0) */
#define DIV_DVSR_DIVISOR_Msk                  (0xFFFFFFFFUL << DIV_DVSR_DIVISOR_Pos)            /*!< Divisor (Bitfield-Mask: 0xFFFFFFFF) */
#define DIV_DVSR_DIVISOR                      DIV_DVSR_DIVISOR_Msk

/*******************  Bit definition for DIV_QUOTR register  ******************/
#define DIV_QUOTR_QUOTIENT_Pos                (0UL)                                             /*!< Quotient (Bit 0) */
#define DIV_QUOTR_QUOTIENT_Msk                (0xFFFFFFFFUL << DIV_QUOTR_QUOTIENT_Pos)          /*!< Quotient (Bitfield-Mask: 0xFFFFFFFF) */
#define DIV_QUOTR_QUOTIENT                    DIV_QUOTR_QUOTIENT_Msk

/*******************  Bit definition for DIV_RMDR register  *******************/
#define DIV_RMDR_REMAINDER_Pos                (0UL)                                             /*!< Remainder (Bit 0) */
#define DIV_RMDR_REMAINDER_Msk                (0xFFFFFFFFUL << DIV_RMDR_REMAINDER_Pos)          /*!< Remainder (Bitfield-Mask: 0xFFFFFFFF) */
#define DIV_RMDR_REMAINDER                    DIV_RMDR_REMAINDER_Msk

/*******************  Bit definition for DIV_CR register  *********************/
#define DIV_CR_USIGNEN_Pos                    (0UL)                                             /*!< Unsigned enable (Bit 0) */
#define DIV_CR_USIGNEN_Msk                    (0x1UL << DIV_CR_USIGNEN_Pos)                     /*!< Unsigned enable (Bitfield-Mask: 0x01) */
#define DIV_CR_USIGNEN                        DIV_CR_USIGNEN_Msk

/******************************************************************************/
/*                                                                            */
/*                             DMA Controller                                 */
/*                                                                            */
/******************************************************************************/
/********************  Bits definition for DMA_SCFGx register  ****************/
#define DMA_SCFGx_PSEL_Pos                    (25U)
#define DMA_SCFGx_PSEL_Msk                    (0x7UL << DMA_SCFGx_PSEL_Pos)                     /*!< 0x0E000000 */
#define DMA_SCFGx_PSEL                        DMA_SCFGx_PSEL_Msk
#define DMA_SCFGx_PSEL_0                      (0x1UL << DMA_SCFGx_PSEL_Pos)
#define DMA_SCFGx_PSEL_1                      (0x2UL << DMA_SCFGx_PSEL_Pos)
#define DMA_SCFGx_PSEL_2                      (0x4UL << DMA_SCFGx_PSEL_Pos)
#define DMA_SCFGx_MBCFG_Pos                   (23U)
#define DMA_SCFGx_MBCFG_Msk                   (0x3UL << DMA_SCFGx_MBCFG_Pos)                    /*!< 0x01800000 */
#define DMA_SCFGx_MBCFG                       DMA_SCFGx_MBCFG_Msk
#define DMA_SCFGx_MBCFG_0                     (0x1UL << DMA_SCFGx_MBCFG_Pos)                    /*!< 0x00800000 */
#define DMA_SCFGx_MBCFG_1                     (0x2UL << DMA_SCFGx_MBCFG_Pos)                    /*!< 0x01000000 */
#define DMA_SCFGx_PBCFG_Pos                   (21U)
#define DMA_SCFGx_PBCFG_Msk                   (0x3UL << DMA_SCFGx_PBCFG_Pos)                    /*!< 0x00600000 */
#define DMA_SCFGx_PBCFG                       DMA_SCFGx_PBCFG_Msk
#define DMA_SCFGx_PBCFG_0                     (0x1UL << DMA_SCFGx_PBCFG_Pos)                    /*!< 0x00200000 */
#define DMA_SCFGx_PBCFG_1                     (0x2UL << DMA_SCFGx_PBCFG_Pos)                    /*!< 0x00400000 */
#define DMA_SCFGx_CTARG_Pos                   (19U)
#define DMA_SCFGx_CTARG_Msk                   (0x1UL << DMA_SCFGx_CTARG_Pos)                    /*!< 0x00080000 */
#define DMA_SCFGx_CTARG                       DMA_SCFGx_CTARG_Msk
#define DMA_SCFGx_DBM_Pos                     (18U)
#define DMA_SCFGx_DBM_Msk                     (0x1UL << DMA_SCFGx_DBM_Pos)                      /*!< 0x00040000 */
#define DMA_SCFGx_DBM                         DMA_SCFGx_DBM_Msk
#define DMA_SCFGx_PRILCFG_Pos                 (16U)
#define DMA_SCFGx_PRILCFG_Msk                 (0x3UL << DMA_SCFGx_PRILCFG_Pos)                  /*!< 0x00030000 */
#define DMA_SCFGx_PRILCFG                     DMA_SCFGx_PRILCFG_Msk
#define DMA_SCFGx_PRILCFG_0                   (0x1UL << DMA_SCFGx_PRILCFG_Pos)
#define DMA_SCFGx_PRILCFG_1                   (0x2UL << DMA_SCFGx_PRILCFG_Pos)
#define DMA_SCFGx_PERIOSIZE_Pos               (15U)
#define DMA_SCFGx_PERIOSIZE_Msk               (0x1UL << DMA_SCFGx_PERIOSIZE_Pos)                /*!< 0x00008000 */
#define DMA_SCFGx_PERIOSIZE                   DMA_SCFGx_PERIOSIZE_Msk
#define DMA_SCFGx_MEMSIZECFG_Pos              (13U)
#define DMA_SCFGx_MEMSIZECFG_Msk              (0x3UL << DMA_SCFGx_MEMSIZECFG_Pos)               /*!< 0x00006000 */
#define DMA_SCFGx_MEMSIZECFG                  DMA_SCFGx_MEMSIZECFG_Msk
#define DMA_SCFGx_MEMSIZECFG_0                (0x1UL << DMA_SCFGx_MEMSIZECFG_Pos)               /*!< 0x00002000 */
#define DMA_SCFGx_MEMSIZECFG_1                (0x2UL << DMA_SCFGx_MEMSIZECFG_Pos)               /*!< 0x00004000 */
#define DMA_SCFGx_PERSIZECFG_Pos              (11U)
#define DMA_SCFGx_PERSIZECFG_Msk              (0x3UL << DMA_SCFGx_PERSIZECFG_Pos)               /*!< 0x00001800 */
#define DMA_SCFGx_PERSIZECFG                  DMA_SCFGx_PERSIZECFG_Msk
#define DMA_SCFGx_PERSIZECFG_0                (0x1UL << DMA_SCFGx_PERSIZECFG_Pos)               /*!< 0x00000800 */
#define DMA_SCFGx_PERSIZECFG_1                (0x2UL << DMA_SCFGx_PERSIZECFG_Pos)               /*!< 0x00001000 */
#define DMA_SCFGx_MEMIM_Pos                   (10U)
#define DMA_SCFGx_MEMIM_Msk                   (0x1UL << DMA_SCFGx_MEMIM_Pos)                    /*!< 0x00000400 */
#define DMA_SCFGx_MEMIM                       DMA_SCFGx_MEMIM_Msk
#define DMA_SCFGx_PERIM_Pos                   (9U)
#define DMA_SCFGx_PERIM_Msk                   (0x1UL << DMA_SCFGx_PERIM_Pos)                    /*!< 0x00000200 */
#define DMA_SCFGx_PERIM                       DMA_SCFGx_PERIM_Msk
#define DMA_SCFGx_CIRCMEN_Pos                 (8U)
#define DMA_SCFGx_CIRCMEN_Msk                 (0x1UL << DMA_SCFGx_CIRCMEN_Pos)                  /*!< 0x00000100 */
#define DMA_SCFGx_CIRCMEN                     DMA_SCFGx_CIRCMEN_Msk
#define DMA_SCFGx_DIRCFG_Pos                  (6U)
#define DMA_SCFGx_DIRCFG_Msk                  (0x3UL << DMA_SCFGx_DIRCFG_Pos)                   /*!< 0x000000C0 */
#define DMA_SCFGx_DIRCFG                      DMA_SCFGx_DIRCFG_Msk
#define DMA_SCFGx_DIRCFG_0                    (0x1UL << DMA_SCFGx_DIRCFG_Pos)                   /*!< 0x00000040 */
#define DMA_SCFGx_DIRCFG_1                    (0x2UL << DMA_SCFGx_DIRCFG_Pos)                   /*!< 0x00000080 */
#define DMA_SCFGx_TXCIEN_Pos                  (4U)
#define DMA_SCFGx_TXCIEN_Msk                  (0x1UL << DMA_SCFGx_TXCIEN_Pos)                   /*!< 0x00000010 */
#define DMA_SCFGx_TXCIEN                      DMA_SCFGx_TXCIEN_Msk
#define DMA_SCFGx_HTXIEN_Pos                  (3U)
#define DMA_SCFGx_HTXIEN_Msk                  (0x1UL << DMA_SCFGx_HTXIEN_Pos)                   /*!< 0x00000008 */
#define DMA_SCFGx_HTXIEN                      DMA_SCFGx_HTXIEN_Msk
#define DMA_SCFGx_TXEIEN_Pos                  (2U)
#define DMA_SCFGx_TXEIEN_Msk                  (0x1UL << DMA_SCFGx_TXEIEN_Pos)                   /*!< 0x00000004 */
#define DMA_SCFGx_TXEIEN                      DMA_SCFGx_TXEIEN_Msk
#define DMA_SCFGx_DMEIEN_Pos                  (1U)
#define DMA_SCFGx_DMEIEN_Msk                  (0x1UL << DMA_SCFGx_DMEIEN_Pos)                   /*!< 0x00000002 */
#define DMA_SCFGx_DMEIEN                      DMA_SCFGx_DMEIEN_Msk
#define DMA_SCFGx_EN_Pos                      (0U)
#define DMA_SCFGx_EN_Msk                      (0x1UL << DMA_SCFGx_EN_Pos)                       /*!< 0x00000001 */
#define DMA_SCFGx_EN                          DMA_SCFGx_EN_Msk

/* Legacy defines */
#define DMA_SCFGx_ACK_Pos                     (20U)
#define DMA_SCFGx_ACK_Msk                     (0x1UL << DMA_SCFGx_ACK_Pos)                      /*!< 0x00100000 */
#define DMA_SCFGx_ACK                         DMA_SCFGx_ACK_Msk

/********************  Bits definition for DMA_NDATAx register  ***************/
#define DMA_NDATAx_Pos                        (0U)
#define DMA_NDATAx_Msk                        (0xFFFFUL << DMA_NDATAx_Pos)                      /*!< 0x0000FFFF */
#define DMA_NDATAx                            DMA_NDATAx_Msk

/******************  Bit definition for DMA_PADDRx register  *******************/
#define DMA_PADDRx_PADDR_Pos                  (0U)
#define DMA_PADDRx_PADDR_Msk                  (0xFFFFFFFFUL << DMA_PADDRx_PADDR_Pos)            /*!< 0xFFFFFFFF */
#define DMA_PADDRx_PADDR                      DMA_PADDRx_PADDR_Msk                              /*!< Peripheral Address */

/******************  Bit definition for DMA_SxM0AR register  ******************/
#define DMA_M0ADDRx_M0ADDR_Pos                (0U)
#define DMA_M0ADDRx_M0ADDR_Msk                (0xFFFFFFFFUL << DMA_M0ADDRx_M0ADDR_Pos)          /*!< 0xFFFFFFFF */
#define DMA_M0ADDRx_M0ADDR                    DMA_M0ADDRx_M0ADDR_Msk                            /*!< Memory Address */

/******************  Bit definition for DMA_SxM1AR register  ******************/
#define DMA_M1ADDRx_M1ADDR_Pos                (0U)
#define DMA_M1ADDRx_M1ADDR_Msk                (0xFFFFFFFFUL << DMA_M1ADDRx_M1ADDR_Pos)          /*!< 0xFFFFFFFF */
#define DMA_M1ADDRx_M1ADDR                    DMA_M1ADDRx_M1ADDR_Msk                            /*!< Memory Address */

/********************  Bits definition for DMA_FCTRLx register  ***************/
#define DMA_FCTRLx_FEIEN_Pos                  (7U)
#define DMA_FCTRLx_FEIEN_Msk                  (0x1UL << DMA_FCTRLx_FEIEN_Pos)                   /*!< 0x00000080 */
#define DMA_FCTRLx_FEIEN                      DMA_FCTRLx_FEIEN_Msk
#define DMA_FCTRLx_FSTS_Pos                   (3U)
#define DMA_FCTRLx_FSTS_Msk                   (0x7UL << DMA_FCTRLx_FSTS_Pos)                    /*!< 0x00000038 */
#define DMA_FCTRLx_FSTS                       DMA_FCTRLx_FSTS_Msk
#define DMA_FCTRLx_FSTS_0                     (0x1UL << DMA_FCTRLx_FSTS_Pos)                    /*!< 0x00000008 */
#define DMA_FCTRLx_FSTS_1                     (0x2UL << DMA_FCTRLx_FSTS_Pos)                    /*!< 0x00000010 */
#define DMA_FCTRLx_FSTS_2                     (0x4UL << DMA_FCTRLx_FSTS_Pos)                    /*!< 0x00000020 */
#define DMA_FCTRLx_DMDEN_Pos                  (2U)
#define DMA_FCTRLx_DMDEN_Msk                  (0x1UL << DMA_FCTRLx_DMDEN_Pos)                   /*!< 0x00000004 */
#define DMA_FCTRLx_DMDEN                      DMA_FCTRLx_DMDEN_Msk
#define DMA_FCTRLx_FTHSEL_Pos                 (0U)
#define DMA_FCTRLx_FTHSEL_Msk                 (0x3UL << DMA_FCTRLx_FTHSEL_Pos)                  /*!< 0x00000003 */
#define DMA_FCTRLx_FTHSEL                     DMA_FCTRLx_FTHSEL_Msk
#define DMA_FCTRLx_FTHSEL_0                   (0x1UL << DMA_FCTRLx_FTHSEL_Pos)                  /*!< 0x00000001 */
#define DMA_FCTRLx_FTHSEL_1                   (0x2UL << DMA_FCTRLx_FTHSEL_Pos)                  /*!< 0x00000002 */

/********************  Bits definition for DMA_LINTSTS register  **************/
#define DMA_LINTSTS_TXCIFLG2_Pos              (21U)
#define DMA_LINTSTS_TXCIFLG2_Msk              (0x1UL << DMA_LINTSTS_TXCIFLG2_Pos)               /*!< 0x00200000 */
#define DMA_LINTSTS_TXCIFLG2                  DMA_LINTSTS_TXCIFLG2_Msk
#define DMA_LINTSTS_HTXIFLG2_Pos              (20U)
#define DMA_LINTSTS_HTXIFLG2_Msk              (0x1UL << DMA_LINTSTS_HTXIFLG2_Pos)               /*!< 0x00100000 */
#define DMA_LINTSTS_HTXIFLG2                  DMA_LINTSTS_HTXIFLG2_Msk
#define DMA_LINTSTS_TXEIFLG2_Pos              (19U)
#define DMA_LINTSTS_TXEIFLG2_Msk              (0x1UL << DMA_LINTSTS_TXEIFLG2_Pos)               /*!< 0x00080000 */
#define DMA_LINTSTS_TXEIFLG2                  DMA_LINTSTS_TXEIFLG2_Msk
#define DMA_LINTSTS_DMEIFLG2_Pos              (18U)
#define DMA_LINTSTS_DMEIFLG2_Msk              (0x1UL << DMA_LINTSTS_DMEIFLG2_Pos)               /*!< 0x00040000 */
#define DMA_LINTSTS_DMEIFLG2                  DMA_LINTSTS_DMEIFLG2_Msk
#define DMA_LINTSTS_FEIFLG2_Pos               (16U)
#define DMA_LINTSTS_FEIFLG2_Msk               (0x1UL << DMA_LINTSTS_FEIFLG2_Pos)                /*!< 0x00010000 */
#define DMA_LINTSTS_FEIFLG2                   DMA_LINTSTS_FEIFLG2_Msk
#define DMA_LINTSTS_TXCIFLG1_Pos              (11U)
#define DMA_LINTSTS_TXCIFLG1_Msk              (0x1UL << DMA_LINTSTS_TXCIFLG1_Pos)               /*!< 0x00000800 */
#define DMA_LINTSTS_TXCIFLG1                  DMA_LINTSTS_TXCIFLG1_Msk
#define DMA_LINTSTS_HTXIFLG1_Pos              (10U)
#define DMA_LINTSTS_HTXIFLG1_Msk              (0x1UL << DMA_LINTSTS_HTXIFLG1_Pos)               /*!< 0x00000400 */
#define DMA_LINTSTS_HTXIFLG1                  DMA_LINTSTS_HTXIFLG1_Msk
#define DMA_LINTSTS_TXEIFLG1_Pos              (9U)
#define DMA_LINTSTS_TXEIFLG1_Msk              (0x1UL << DMA_LINTSTS_TXEIFLG1_Pos)               /*!< 0x00000200 */
#define DMA_LINTSTS_TXEIFLG1                  DMA_LINTSTS_TXEIFLG1_Msk
#define DMA_LINTSTS_DMEIFLG1_Pos              (8U)
#define DMA_LINTSTS_DMEIFLG1_Msk              (0x1UL << DMA_LINTSTS_DMEIFLG1_Pos)               /*!< 0x00000100 */
#define DMA_LINTSTS_DMEIFLG1                  DMA_LINTSTS_DMEIFLG1_Msk
#define DMA_LINTSTS_FEIFLG1_Pos               (6U)
#define DMA_LINTSTS_FEIFLG1_Msk               (0x1UL << DMA_LINTSTS_FEIFLG1_Pos)                /*!< 0x00000040 */
#define DMA_LINTSTS_FEIFLG1                   DMA_LINTSTS_FEIFLG1_Msk
#define DMA_LINTSTS_TXCIFLG0_Pos              (5U)
#define DMA_LINTSTS_TXCIFLG0_Msk              (0x1UL << DMA_LINTSTS_TXCIFLG0_Pos)               /*!< 0x00000020 */
#define DMA_LINTSTS_TXCIFLG0                  DMA_LINTSTS_TXCIFLG0_Msk
#define DMA_LINTSTS_HTXIFLG0_Pos              (4U)
#define DMA_LINTSTS_HTXIFLG0_Msk              (0x1UL << DMA_LINTSTS_HTXIFLG0_Pos)               /*!< 0x00000010 */
#define DMA_LINTSTS_HTXIFLG0                  DMA_LINTSTS_HTXIFLG0_Msk
#define DMA_LINTSTS_TXEIFLG0_Pos              (3U)
#define DMA_LINTSTS_TXEIFLG0_Msk              (0x1UL << DMA_LINTSTS_TXEIFLG0_Pos)               /*!< 0x00000008 */
#define DMA_LINTSTS_TXEIFLG0                  DMA_LINTSTS_TXEIFLG0_Msk
#define DMA_LINTSTS_DMEIFLG0_Pos              (2U)
#define DMA_LINTSTS_DMEIFLG0_Msk              (0x1UL << DMA_LINTSTS_DMEIFLG0_Pos)               /*!< 0x00000004 */
#define DMA_LINTSTS_DMEIFLG0                  DMA_LINTSTS_DMEIFLG0_Msk
#define DMA_LINTSTS_FEIFLG0_Pos               (0U)
#define DMA_LINTSTS_FEIFLG0_Msk               (0x1UL << DMA_LINTSTS_FEIFLG0_Pos)                /*!< 0x00000001 */
#define DMA_LINTSTS_FEIFLG0                   DMA_LINTSTS_FEIFLG0_Msk

/********************  Bits definition for DMA_LIFCLR register  ***************/
#define DMA_LIFCLR_CTXCIFLG2_Pos              (21U)
#define DMA_LIFCLR_CTXCIFLG2_Msk              (0x1UL << DMA_LIFCLR_CTXCIFLG2_Pos)               /*!< 0x00200000 */
#define DMA_LIFCLR_CTXCIFLG2                  DMA_LIFCLR_CTXCIFLG2_Msk
#define DMA_LIFCLR_CHTXIFLG2_Pos              (20U)
#define DMA_LIFCLR_CHTXIFLG2_Msk              (0x1UL << DMA_LIFCLR_CHTXIFLG2_Pos)               /*!< 0x00100000 */
#define DMA_LIFCLR_CHTXIFLG2                  DMA_LIFCLR_CHTXIFLG2_Msk
#define DMA_LIFCLR_CTXEIFLG2_Pos              (19U)
#define DMA_LIFCLR_CTXEIFLG2_Msk              (0x1UL << DMA_LIFCLR_CTXEIFLG2_Pos)               /*!< 0x00080000 */
#define DMA_LIFCLR_CTXEIFLG2                  DMA_LIFCLR_CTXEIFLG2_Msk
#define DMA_LIFCLR_CDMEIFLG2_Pos              (18U)
#define DMA_LIFCLR_CDMEIFLG2_Msk              (0x1UL << DMA_LIFCLR_CDMEIFLG2_Pos)               /*!< 0x00040000 */
#define DMA_LIFCLR_CDMEIFLG2                  DMA_LIFCLR_CDMEIFLG2_Msk
#define DMA_LIFCLR_CFEIFLG2_Pos               (16U)
#define DMA_LIFCLR_CFEIFLG2_Msk               (0x1UL << DMA_LIFCLR_CFEIFLG2_Pos)                /*!< 0x00010000 */
#define DMA_LIFCLR_CFEIFLG2                   DMA_LIFCLR_CFEIFLG2_Msk
#define DMA_LIFCLR_CTXCIFLG1_Pos              (11U)
#define DMA_LIFCLR_CTXCIFLG1_Msk              (0x1UL << DMA_LIFCLR_CTXCIFLG1_Pos)               /*!< 0x00000800 */
#define DMA_LIFCLR_CTXCIFLG1                  DMA_LIFCLR_CTXCIFLG1_Msk
#define DMA_LIFCLR_CHTXIFLG1_Pos              (10U)
#define DMA_LIFCLR_CHTXIFLG1_Msk              (0x1UL << DMA_LIFCLR_CHTXIFLG1_Pos)               /*!< 0x00000400 */
#define DMA_LIFCLR_CHTXIFLG1                  DMA_LIFCLR_CHTXIFLG1_Msk
#define DMA_LIFCLR_CTXEIFLG1_Pos              (9U)
#define DMA_LIFCLR_CTXEIFLG1_Msk              (0x1UL << DMA_LIFCLR_CTXEIFLG1_Pos)               /*!< 0x00000200 */
#define DMA_LIFCLR_CTXEIFLG1                  DMA_LIFCLR_CTXEIFLG1_Msk
#define DMA_LIFCLR_CDMEIFLG1_Pos              (8U)
#define DMA_LIFCLR_CDMEIFLG1_Msk              (0x1UL << DMA_LIFCLR_CDMEIFLG1_Pos)               /*!< 0x00000100 */
#define DMA_LIFCLR_CDMEIFLG1                  DMA_LIFCLR_CDMEIFLG1_Msk
#define DMA_LIFCLR_CFEIFLG1_Pos               (6U)
#define DMA_LIFCLR_CFEIFLG1_Msk               (0x1UL << DMA_LIFCLR_CFEIFLG1_Pos)                /*!< 0x00000040 */
#define DMA_LIFCLR_CFEIFLG1                   DMA_LIFCLR_CFEIFLG1_Msk
#define DMA_LIFCLR_CTXCIFLG0_Pos              (5U)
#define DMA_LIFCLR_CTXCIFLG0_Msk              (0x1UL << DMA_LIFCLR_CTXCIFLG0_Pos)               /*!< 0x00000020 */
#define DMA_LIFCLR_CTXCIFLG0                  DMA_LIFCLR_CTXCIFLG0_Msk
#define DMA_LIFCLR_CHTXIFLG0_Pos              (4U)
#define DMA_LIFCLR_CHTXIFLG0_Msk              (0x1UL << DMA_LIFCLR_CHTXIFLG0_Pos)               /*!< 0x00000010 */
#define DMA_LIFCLR_CHTXIFLG0                  DMA_LIFCLR_CHTXIFLG0_Msk
#define DMA_LIFCLR_CTXEIFLG0_Pos              (3U)
#define DMA_LIFCLR_CTXEIFLG0_Msk              (0x1UL << DMA_LIFCLR_CTXEIFLG0_Pos)               /*!< 0x00000008 */
#define DMA_LIFCLR_CTXEIFLG0                  DMA_LIFCLR_CTXEIFLG0_Msk
#define DMA_LIFCLR_CDMEIFLG0_Pos              (2U)
#define DMA_LIFCLR_CDMEIFLG0_Msk              (0x1UL << DMA_LIFCLR_CDMEIFLG0_Pos)               /*!< 0x00000004 */
#define DMA_LIFCLR_CDMEIFLG0                  DMA_LIFCLR_CDMEIFLG0_Msk
#define DMA_LIFCLR_CFEIFLG0_Pos               (0U)
#define DMA_LIFCLR_CFEIFLG0_Msk               (0x1UL << DMA_LIFCLR_CFEIFLG0_Pos)                /*!< 0x00000001 */
#define DMA_LIFCLR_CFEIFLG0                   DMA_LIFCLR_CFEIFLG0_Msk


/******************************************************************************/
/*                                                                            */
/*                    External Interrupt/Event Controller                     */
/*                                                                            */
/******************************************************************************/
/*******************  Bit definition for EINT_IMASK register  *****************/
#define EINT_IMASK_IMASK0_Pos                 (0U)
#define EINT_IMASK_IMASK0_Msk                 (0x1UL << EINT_IMASK_IMASK0_Pos)                  /*!< 0x00000001 */
#define EINT_IMASK_IMASK0                     EINT_IMASK_IMASK0_Msk                             /*!< Interrupt Mask on line 0 */
#define EINT_IMASK_IMASK1_Pos                 (1U)
#define EINT_IMASK_IMASK1_Msk                 (0x1UL << EINT_IMASK_IMASK1_Pos)                  /*!< 0x00000002 */
#define EINT_IMASK_IMASK1                     EINT_IMASK_IMASK1_Msk                             /*!< Interrupt Mask on line 1 */
#define EINT_IMASK_IMASK2_Pos                 (2U)
#define EINT_IMASK_IMASK2_Msk                 (0x1UL << EINT_IMASK_IMASK2_Pos)                  /*!< 0x00000004 */
#define EINT_IMASK_IMASK2                     EINT_IMASK_IMASK2_Msk                             /*!< Interrupt Mask on line 2 */
#define EINT_IMASK_IMASK3_Pos                 (3U)
#define EINT_IMASK_IMASK3_Msk                 (0x1UL << EINT_IMASK_IMASK3_Pos)                  /*!< 0x00000008 */
#define EINT_IMASK_IMASK3                     EINT_IMASK_IMASK3_Msk                             /*!< Interrupt Mask on line 3 */
#define EINT_IMASK_IMASK4_Pos                 (4U)
#define EINT_IMASK_IMASK4_Msk                 (0x1UL << EINT_IMASK_IMASK4_Pos)                  /*!< 0x00000010 */
#define EINT_IMASK_IMASK4                     EINT_IMASK_IMASK4_Msk                             /*!< Interrupt Mask on line 4 */
#define EINT_IMASK_IMASK5_Pos                 (5U)
#define EINT_IMASK_IMASK5_Msk                 (0x1UL << EINT_IMASK_IMASK5_Pos)                  /*!< 0x00000020 */
#define EINT_IMASK_IMASK5                     EINT_IMASK_IMASK5_Msk                             /*!< Interrupt Mask on line 5 */
#define EINT_IMASK_IMASK6_Pos                 (6U)
#define EINT_IMASK_IMASK6_Msk                 (0x1UL << EINT_IMASK_IMASK6_Pos)                  /*!< 0x00000040 */
#define EINT_IMASK_IMASK6                     EINT_IMASK_IMASK6_Msk                             /*!< Interrupt Mask on line 6 */
#define EINT_IMASK_IMASK7_Pos                 (7U)
#define EINT_IMASK_IMASK7_Msk                 (0x1UL << EINT_IMASK_IMASK7_Pos)                  /*!< 0x00000080 */
#define EINT_IMASK_IMASK7                     EINT_IMASK_IMASK7_Msk                             /*!< Interrupt Mask on line 7 */
#define EINT_IMASK_IMASK8_Pos                 (8U)
#define EINT_IMASK_IMASK8_Msk                 (0x1UL << EINT_IMASK_IMASK8_Pos)                  /*!< 0x00000100 */
#define EINT_IMASK_IMASK8                     EINT_IMASK_IMASK8_Msk                             /*!< Interrupt Mask on line 8 */
#define EINT_IMASK_IMASK9_Pos                 (9U)
#define EINT_IMASK_IMASK9_Msk                 (0x1UL << EINT_IMASK_IMASK9_Pos)                  /*!< 0x00000200 */
#define EINT_IMASK_IMASK9                     EINT_IMASK_IMASK9_Msk                             /*!< Interrupt Mask on line 9 */
#define EINT_IMASK_IMASK10_Pos                (10U)
#define EINT_IMASK_IMASK10_Msk                (0x1UL << EINT_IMASK_IMASK10_Pos)                 /*!< 0x00000400 */
#define EINT_IMASK_IMASK10                    EINT_IMASK_IMASK10_Msk                            /*!< Interrupt Mask on line 10 */
#define EINT_IMASK_IMASK11_Pos                (11U)
#define EINT_IMASK_IMASK11_Msk                (0x1UL << EINT_IMASK_IMASK11_Pos)                 /*!< 0x00000800 */
#define EINT_IMASK_IMASK11                    EINT_IMASK_IMASK11_Msk                            /*!< Interrupt Mask on line 11 */
#define EINT_IMASK_IMASK12_Pos                (12U)
#define EINT_IMASK_IMASK12_Msk                (0x1UL << EINT_IMASK_IMASK12_Pos)                 /*!< 0x00001000 */
#define EINT_IMASK_IMASK12                    EINT_IMASK_IMASK12_Msk                            /*!< Interrupt Mask on line 12 */
#define EINT_IMASK_IMASK13_Pos                (13U)
#define EINT_IMASK_IMASK13_Msk                (0x1UL << EINT_IMASK_IMASK13_Pos)                 /*!< 0x00002000 */
#define EINT_IMASK_IMASK13                    EINT_IMASK_IMASK13_Msk                            /*!< Interrupt Mask on line 13 */
#define EINT_IMASK_IMASK16_Pos                (16U)
#define EINT_IMASK_IMASK16_Msk                (0x1UL << EINT_IMASK_IMASK16_Pos)                 /*!< 0x00010000 */
#define EINT_IMASK_IMASK16                    EINT_IMASK_IMASK16_Msk                            /*!< Interrupt Mask on line 16 */
#define EINT_IMASK_IMASK17_Pos                (17U)
#define EINT_IMASK_IMASK17_Msk                (0x1UL << EINT_IMASK_IMASK17_Pos)                 /*!< 0x00020000 */
#define EINT_IMASK_IMASK17                    EINT_IMASK_IMASK17_Msk                            /*!< Interrupt Mask on line 17 */

/* Reference Defines */
#define EINT_IMASK_IM0                        EINT_IMASK_IMASK0
#define EINT_IMASK_IM1                        EINT_IMASK_IMASK1
#define EINT_IMASK_IM2                        EINT_IMASK_IMASK2
#define EINT_IMASK_IM3                        EINT_IMASK_IMASK3
#define EINT_IMASK_IM4                        EINT_IMASK_IMASK4
#define EINT_IMASK_IM5                        EINT_IMASK_IMASK5
#define EINT_IMASK_IM6                        EINT_IMASK_IMASK6
#define EINT_IMASK_IM7                        EINT_IMASK_IMASK7
#define EINT_IMASK_IM8                        EINT_IMASK_IMASK8
#define EINT_IMASK_IM9                        EINT_IMASK_IMASK9
#define EINT_IMASK_IM10                       EINT_IMASK_IMASK10
#define EINT_IMASK_IM11                       EINT_IMASK_IMASK11
#define EINT_IMASK_IM12                       EINT_IMASK_IMASK12
#define EINT_IMASK_IM13                       EINT_IMASK_IMASK13
#define EINT_IMASK_IM16                       EINT_IMASK_IMASK16
#define EINT_IMASK_IM17                       EINT_IMASK_IMASK17
#define EINT_IMASK_IM_Pos                     (0U)
#define EINT_IMASK_IM_Msk                     (0x33FFFUL << EINT_IMASK_IM_Pos)                  /*!< 0x007FFFFF */
#define EINT_IMASK_IM                         EINT_IMASK_IM_Msk                                 /*!< Interrupt Mask All */

/*******************  Bit definition for EINT_EMASK register  *****************/
#define EINT_EMASK_EMASK0_Pos                 (0U)
#define EINT_EMASK_EMASK0_Msk                 (0x1UL << EINT_EMASK_EMASK0_Pos)                  /*!< 0x00000001 */
#define EINT_EMASK_EMASK0                     EINT_EMASK_EMASK0_Msk                             /*!< Event Mask on line 0 */
#define EINT_EMASK_EMASK1_Pos                 (1U)
#define EINT_EMASK_EMASK1_Msk                 (0x1UL << EINT_EMASK_EMASK1_Pos)                  /*!< 0x00000002 */
#define EINT_EMASK_EMASK1                     EINT_EMASK_EMASK1_Msk                             /*!< Event Mask on line 1 */
#define EINT_EMASK_EMASK2_Pos                 (2U)
#define EINT_EMASK_EMASK2_Msk                 (0x1UL << EINT_EMASK_EMASK2_Pos)                  /*!< 0x00000004 */
#define EINT_EMASK_EMASK2                     EINT_EMASK_EMASK2_Msk                             /*!< Event Mask on line 2 */
#define EINT_EMASK_EMASK3_Pos                 (3U)
#define EINT_EMASK_EMASK3_Msk                 (0x1UL << EINT_EMASK_EMASK3_Pos)                  /*!< 0x00000008 */
#define EINT_EMASK_EMASK3                     EINT_EMASK_EMASK3_Msk                             /*!< Event Mask on line 3 */
#define EINT_EMASK_EMASK4_Pos                 (4U)
#define EINT_EMASK_EMASK4_Msk                 (0x1UL << EINT_EMASK_EMASK4_Pos)                  /*!< 0x00000010 */
#define EINT_EMASK_EMASK4                     EINT_EMASK_EMASK4_Msk                             /*!< Event Mask on line 4 */
#define EINT_EMASK_EMASK5_Pos                 (5U)
#define EINT_EMASK_EMASK5_Msk                 (0x1UL << EINT_EMASK_EMASK5_Pos)                  /*!< 0x00000020 */
#define EINT_EMASK_EMASK5                     EINT_EMASK_EMASK5_Msk                             /*!< Event Mask on line 5 */
#define EINT_EMASK_EMASK6_Pos                 (6U)
#define EINT_EMASK_EMASK6_Msk                 (0x1UL << EINT_EMASK_EMASK6_Pos)                  /*!< 0x00000040 */
#define EINT_EMASK_EMASK6                     EINT_EMASK_EMASK6_Msk                             /*!< Event Mask on line 6 */
#define EINT_EMASK_EMASK7_Pos                 (7U)
#define EINT_EMASK_EMASK7_Msk                 (0x1UL << EINT_EMASK_EMASK7_Pos)                  /*!< 0x00000080 */
#define EINT_EMASK_EMASK7                     EINT_EMASK_EMASK7_Msk                             /*!< Event Mask on line 7 */
#define EINT_EMASK_EMASK8_Pos                 (8U)
#define EINT_EMASK_EMASK8_Msk                 (0x1UL << EINT_EMASK_EMASK8_Pos)                  /*!< 0x00000100 */
#define EINT_EMASK_EMASK8                     EINT_EMASK_EMASK8_Msk                             /*!< Event Mask on line 8 */
#define EINT_EMASK_EMASK9_Pos                 (9U)
#define EINT_EMASK_EMASK9_Msk                 (0x1UL << EINT_EMASK_EMASK9_Pos)                  /*!< 0x00000200 */
#define EINT_EMASK_EMASK9                     EINT_EMASK_EMASK9_Msk                             /*!< Event Mask on line 9 */
#define EINT_EMASK_EMASK10_Pos                (10U)
#define EINT_EMASK_EMASK10_Msk                (0x1UL << EINT_EMASK_EMASK10_Pos)                 /*!< 0x00000400 */
#define EINT_EMASK_EMASK10                    EINT_EMASK_EMASK10_Msk                            /*!< Event Mask on line 10 */
#define EINT_EMASK_EMASK11_Pos                (11U)
#define EINT_EMASK_EMASK11_Msk                (0x1UL << EINT_EMASK_EMASK11_Pos)                 /*!< 0x00000800 */
#define EINT_EMASK_EMASK11                    EINT_EMASK_EMASK11_Msk                            /*!< Event Mask on line 11 */
#define EINT_EMASK_EMASK12_Pos                (12U)
#define EINT_EMASK_EMASK12_Msk                (0x1UL << EINT_EMASK_EMASK12_Pos)                 /*!< 0x00001000 */
#define EINT_EMASK_EMASK12                    EINT_EMASK_EMASK12_Msk                            /*!< Event Mask on line 12 */
#define EINT_EMASK_EMASK13_Pos                (13U)
#define EINT_EMASK_EMASK13_Msk                (0x1UL << EINT_EMASK_EMASK13_Pos)                 /*!< 0x00002000 */
#define EINT_EMASK_EMASK13                    EINT_EMASK_EMASK13_Msk                            /*!< Event Mask on line 13 */
#define EINT_EMASK_EMASK16_Pos                (16U)
#define EINT_EMASK_EMASK16_Msk                (0x1UL << EINT_EMASK_EMASK16_Pos)                 /*!< 0x00010000 */
#define EINT_EMASK_EMASK16                    EINT_EMASK_EMASK16_Msk                            /*!< Event Mask on line 16 */
#define EINT_EMASK_EMASK17_Pos                (17U)
#define EINT_EMASK_EMASK17_Msk                (0x1UL << EINT_EMASK_EMASK17_Pos)                 /*!< 0x00020000 */
#define EINT_EMASK_EMASK17                    EINT_EMASK_EMASK17_Msk                            /*!< Event Mask on line 17 */

/* Reference Defines */
#define EINT_EMASK_EM0                        EINT_EMASK_EMASK0
#define EINT_EMASK_EM1                        EINT_EMASK_EMASK1
#define EINT_EMASK_EM2                        EINT_EMASK_EMASK2
#define EINT_EMASK_EM3                        EINT_EMASK_EMASK3
#define EINT_EMASK_EM4                        EINT_EMASK_EMASK4
#define EINT_EMASK_EM5                        EINT_EMASK_EMASK5
#define EINT_EMASK_EM6                        EINT_EMASK_EMASK6
#define EINT_EMASK_EM7                        EINT_EMASK_EMASK7
#define EINT_EMASK_EM8                        EINT_EMASK_EMASK8
#define EINT_EMASK_EM9                        EINT_EMASK_EMASK9
#define EINT_EMASK_EM10                       EINT_EMASK_EMASK10
#define EINT_EMASK_EM11                       EINT_EMASK_EMASK11
#define EINT_EMASK_EM12                       EINT_EMASK_EMASK12
#define EINT_EMASK_EM13                       EINT_EMASK_EMASK13
#define EINT_EMASK_EM16                       EINT_EMASK_EMASK16
#define EINT_EMASK_EM17                       EINT_EMASK_EMASK17

/******************  Bit definition for EINT_RTEN register  *******************/
#define EINT_RTEN_RTEN0_Pos                   (0U)
#define EINT_RTEN_RTEN0_Msk                   (0x1UL << EINT_RTEN_RTEN0_Pos)                    /*!< 0x00000001 */
#define EINT_RTEN_RTEN0                       EINT_RTEN_RTEN0_Msk                               /*!< Rising trigger event configuration bit of line 0 */
#define EINT_RTEN_RTEN1_Pos                   (1U)
#define EINT_RTEN_RTEN1_Msk                   (0x1UL << EINT_RTEN_RTEN1_Pos)                    /*!< 0x00000002 */
#define EINT_RTEN_RTEN1                       EINT_RTEN_RTEN1_Msk                               /*!< Rising trigger event configuration bit of line 1 */
#define EINT_RTEN_RTEN2_Pos                   (2U)
#define EINT_RTEN_RTEN2_Msk                   (0x1UL << EINT_RTEN_RTEN2_Pos)                    /*!< 0x00000004 */
#define EINT_RTEN_RTEN2                       EINT_RTEN_RTEN2_Msk                               /*!< Rising trigger event configuration bit of line 2 */
#define EINT_RTEN_RTEN3_Pos                   (3U)
#define EINT_RTEN_RTEN3_Msk                   (0x1UL << EINT_RTEN_RTEN3_Pos)                    /*!< 0x00000008 */
#define EINT_RTEN_RTEN3                       EINT_RTEN_RTEN3_Msk                               /*!< Rising trigger event configuration bit of line 3 */
#define EINT_RTEN_RTEN4_Pos                   (4U)
#define EINT_RTEN_RTEN4_Msk                   (0x1UL << EINT_RTEN_RTEN4_Pos)                    /*!< 0x00000010 */
#define EINT_RTEN_RTEN4                       EINT_RTEN_RTEN4_Msk                               /*!< Rising trigger event configuration bit of line 4 */
#define EINT_RTEN_RTEN5_Pos                   (5U)
#define EINT_RTEN_RTEN5_Msk                   (0x1UL << EINT_RTEN_RTEN5_Pos)                    /*!< 0x00000020 */
#define EINT_RTEN_RTEN5                       EINT_RTEN_RTEN5_Msk                               /*!< Rising trigger event configuration bit of line 5 */
#define EINT_RTEN_RTEN6_Pos                   (6U)
#define EINT_RTEN_RTEN6_Msk                   (0x1UL << EINT_RTEN_RTEN6_Pos)                    /*!< 0x00000040 */
#define EINT_RTEN_RTEN6                       EINT_RTEN_RTEN6_Msk                               /*!< Rising trigger event configuration bit of line 6 */
#define EINT_RTEN_RTEN7_Pos                   (7U)
#define EINT_RTEN_RTEN7_Msk                   (0x1UL << EINT_RTEN_RTEN7_Pos)                    /*!< 0x00000080 */
#define EINT_RTEN_RTEN7                       EINT_RTEN_RTEN7_Msk                               /*!< Rising trigger event configuration bit of line 7 */
#define EINT_RTEN_RTEN8_Pos                   (8U)
#define EINT_RTEN_RTEN8_Msk                   (0x1UL << EINT_RTEN_RTEN8_Pos)                    /*!< 0x00000100 */
#define EINT_RTEN_RTEN8                       EINT_RTEN_RTEN8_Msk                               /*!< Rising trigger event configuration bit of line 8 */
#define EINT_RTEN_RTEN9_Pos                   (9U)
#define EINT_RTEN_RTEN9_Msk                   (0x1UL << EINT_RTEN_RTEN9_Pos)                    /*!< 0x00000200 */
#define EINT_RTEN_RTEN9                       EINT_RTEN_RTEN9_Msk                               /*!< Rising trigger event configuration bit of line 9 */
#define EINT_RTEN_RTEN10_Pos                  (10U)
#define EINT_RTEN_RTEN10_Msk                  (0x1UL << EINT_RTEN_RTEN10_Pos)                   /*!< 0x00000400 */
#define EINT_RTEN_RTEN10                      EINT_RTEN_RTEN10_Msk                              /*!< Rising trigger event configuration bit of line 10 */
#define EINT_RTEN_RTEN11_Pos                  (11U)
#define EINT_RTEN_RTEN11_Msk                  (0x1UL << EINT_RTEN_RTEN11_Pos)                   /*!< 0x00000800 */
#define EINT_RTEN_RTEN11                      EINT_RTEN_RTEN11_Msk                              /*!< Rising trigger event configuration bit of line 11 */
#define EINT_RTEN_RTEN12_Pos                  (12U)
#define EINT_RTEN_RTEN12_Msk                  (0x1UL << EINT_RTEN_RTEN12_Pos)                   /*!< 0x00001000 */
#define EINT_RTEN_RTEN12                      EINT_RTEN_RTEN12_Msk                              /*!< Rising trigger event configuration bit of line 12 */
#define EINT_RTEN_RTEN13_Pos                  (13U)
#define EINT_RTEN_RTEN13_Msk                  (0x1UL << EINT_RTEN_RTEN13_Pos)                   /*!< 0x00002000 */
#define EINT_RTEN_RTEN13                      EINT_RTEN_RTEN13_Msk                              /*!< Rising trigger event configuration bit of line 13 */
#define EINT_RTEN_RTEN16_Pos                  (16U)
#define EINT_RTEN_RTEN16_Msk                  (0x1UL << EINT_RTEN_RTEN16_Pos)                   /*!< 0x00010000 */
#define EINT_RTEN_RTEN16                      EINT_RTEN_RTEN16_Msk                              /*!< Rising trigger event configuration bit of line 16 */
#define EINT_RTEN_RTEN17_Pos                  (17U)
#define EINT_RTEN_RTEN17_Msk                  (0x1UL << EINT_RTEN_RTEN17_Pos)                   /*!< 0x00020000 */
#define EINT_RTEN_RTEN17                      EINT_RTEN_RTEN17_Msk                              /*!< Rising trigger event configuration bit of line 17 */

/******************  Bit definition for EINT_FTEN register  *******************/
#define EINT_FTEN_FTEN0_Pos                   (0U)
#define EINT_FTEN_FTEN0_Msk                   (0x1UL << EINT_FTEN_FTEN0_Pos)                    /*!< 0x00000001 */
#define EINT_FTEN_FTEN0                       EINT_FTEN_FTEN0_Msk                               /*!< Falling trigger event configuration bit of line 0 */
#define EINT_FTEN_FTEN1_Pos                   (1U)
#define EINT_FTEN_FTEN1_Msk                   (0x1UL << EINT_FTEN_FTEN1_Pos)                    /*!< 0x00000002 */
#define EINT_FTEN_FTEN1                       EINT_FTEN_FTEN1_Msk                               /*!< Falling trigger event configuration bit of line 1 */
#define EINT_FTEN_FTEN2_Pos                   (2U)
#define EINT_FTEN_FTEN2_Msk                   (0x1UL << EINT_FTEN_FTEN2_Pos)                    /*!< 0x00000004 */
#define EINT_FTEN_FTEN2                       EINT_FTEN_FTEN2_Msk                               /*!< Falling trigger event configuration bit of line 2 */
#define EINT_FTEN_FTEN3_Pos                   (3U)
#define EINT_FTEN_FTEN3_Msk                   (0x1UL << EINT_FTEN_FTEN3_Pos)                    /*!< 0x00000008 */
#define EINT_FTEN_FTEN3                       EINT_FTEN_FTEN3_Msk                               /*!< Falling trigger event configuration bit of line 3 */
#define EINT_FTEN_FTEN4_Pos                   (4U)
#define EINT_FTEN_FTEN4_Msk                   (0x1UL << EINT_FTEN_FTEN4_Pos)                    /*!< 0x00000010 */
#define EINT_FTEN_FTEN4                       EINT_FTEN_FTEN4_Msk                               /*!< Falling trigger event configuration bit of line 4 */
#define EINT_FTEN_FTEN5_Pos                   (5U)
#define EINT_FTEN_FTEN5_Msk                   (0x1UL << EINT_FTEN_FTEN5_Pos)                    /*!< 0x00000020 */
#define EINT_FTEN_FTEN5                       EINT_FTEN_FTEN5_Msk                               /*!< Falling trigger event configuration bit of line 5 */
#define EINT_FTEN_FTEN6_Pos                   (6U)
#define EINT_FTEN_FTEN6_Msk                   (0x1UL << EINT_FTEN_FTEN6_Pos)                    /*!< 0x00000040 */
#define EINT_FTEN_FTEN6                       EINT_FTEN_FTEN6_Msk                               /*!< Falling trigger event configuration bit of line 6 */
#define EINT_FTEN_FTEN7_Pos                   (7U)
#define EINT_FTEN_FTEN7_Msk                   (0x1UL << EINT_FTEN_FTEN7_Pos)                    /*!< 0x00000080 */
#define EINT_FTEN_FTEN7                       EINT_FTEN_FTEN7_Msk                               /*!< Falling trigger event configuration bit of line 7 */
#define EINT_FTEN_FTEN8_Pos                   (8U)
#define EINT_FTEN_FTEN8_Msk                   (0x1UL << EINT_FTEN_FTEN8_Pos)                    /*!< 0x00000100 */
#define EINT_FTEN_FTEN8                       EINT_FTEN_FTEN8_Msk                               /*!< Falling trigger event configuration bit of line 8 */
#define EINT_FTEN_FTEN9_Pos                   (9U)
#define EINT_FTEN_FTEN9_Msk                   (0x1UL << EINT_FTEN_FTEN9_Pos)                    /*!< 0x00000200 */
#define EINT_FTEN_FTEN9                       EINT_FTEN_FTEN9_Msk                               /*!< Falling trigger event configuration bit of line 9 */
#define EINT_FTEN_FTEN10_Pos                  (10U)
#define EINT_FTEN_FTEN10_Msk                  (0x1UL << EINT_FTEN_FTEN10_Pos)                   /*!< 0x00000400 */
#define EINT_FTEN_FTEN10                      EINT_FTEN_FTEN10_Msk                              /*!< Falling trigger event configuration bit of line 10 */
#define EINT_FTEN_FTEN11_Pos                  (11U)
#define EINT_FTEN_FTEN11_Msk                  (0x1UL << EINT_FTEN_FTEN11_Pos)                   /*!< 0x00000800 */
#define EINT_FTEN_FTEN11                      EINT_FTEN_FTEN11_Msk                              /*!< Falling trigger event configuration bit of line 11 */
#define EINT_FTEN_FTEN12_Pos                  (12U)
#define EINT_FTEN_FTEN12_Msk                  (0x1UL << EINT_FTEN_FTEN12_Pos)                   /*!< 0x00001000 */
#define EINT_FTEN_FTEN12                      EINT_FTEN_FTEN12_Msk                              /*!< Falling trigger event configuration bit of line 12 */
#define EINT_FTEN_FTEN13_Pos                  (13U)
#define EINT_FTEN_FTEN13_Msk                  (0x1UL << EINT_FTEN_FTEN13_Pos)                   /*!< 0x00002000 */
#define EINT_FTEN_FTEN13                      EINT_FTEN_FTEN13_Msk                              /*!< Falling trigger event configuration bit of line 13 */
#define EINT_FTEN_FTEN16_Pos                  (16U)
#define EINT_FTEN_FTEN16_Msk                  (0x1UL << EINT_FTEN_FTEN16_Pos)                   /*!< 0x00010000 */
#define EINT_FTEN_FTEN16                      EINT_FTEN_FTEN16_Msk                              /*!< Falling trigger event configuration bit of line 16 */
#define EINT_FTEN_FTEN17_Pos                  (17U)
#define EINT_FTEN_FTEN17_Msk                  (0x1UL << EINT_FTEN_FTEN17_Pos)                   /*!< 0x00020000 */
#define EINT_FTEN_FTEN17                      EINT_FTEN_FTEN17_Msk                              /*!< Falling trigger event configuration bit of line 17 */

/******************  Bit definition for EINT_SWINTE register  *****************/
#define EINT_SWINTE_SWINTE0_Pos               (0U)
#define EINT_SWINTE_SWINTE0_Msk               (0x1UL << EINT_SWINTE_SWINTE0_Pos)                /*!< 0x00000001 */
#define EINT_SWINTE_SWINTE0                   EINT_SWINTE_SWINTE0_Msk                           /*!< Software Interrupt on line 0 */
#define EINT_SWINTE_SWINTE1_Pos               (1U)
#define EINT_SWINTE_SWINTE1_Msk               (0x1UL << EINT_SWINTE_SWINTE1_Pos)                /*!< 0x00000002 */
#define EINT_SWINTE_SWINTE1                   EINT_SWINTE_SWINTE1_Msk                           /*!< Software Interrupt on line 1 */
#define EINT_SWINTE_SWINTE2_Pos               (2U)
#define EINT_SWINTE_SWINTE2_Msk               (0x1UL << EINT_SWINTE_SWINTE2_Pos)                /*!< 0x00000004 */
#define EINT_SWINTE_SWINTE2                   EINT_SWINTE_SWINTE2_Msk                           /*!< Software Interrupt on line 2 */
#define EINT_SWINTE_SWINTE3_Pos               (3U)
#define EINT_SWINTE_SWINTE3_Msk               (0x1UL << EINT_SWINTE_SWINTE3_Pos)                /*!< 0x00000008 */
#define EINT_SWINTE_SWINTE3                   EINT_SWINTE_SWINTE3_Msk                           /*!< Software Interrupt on line 3 */
#define EINT_SWINTE_SWINTE4_Pos               (4U)
#define EINT_SWINTE_SWINTE4_Msk               (0x1UL << EINT_SWINTE_SWINTE4_Pos)                /*!< 0x00000010 */
#define EINT_SWINTE_SWINTE4                   EINT_SWINTE_SWINTE4_Msk                           /*!< Software Interrupt on line 4 */
#define EINT_SWINTE_SWINTE5_Pos               (5U)
#define EINT_SWINTE_SWINTE5_Msk               (0x1UL << EINT_SWINTE_SWINTE5_Pos)                /*!< 0x00000020 */
#define EINT_SWINTE_SWINTE5                   EINT_SWINTE_SWINTE5_Msk                           /*!< Software Interrupt on line 5 */
#define EINT_SWINTE_SWINTE6_Pos               (6U)
#define EINT_SWINTE_SWINTE6_Msk               (0x1UL << EINT_SWINTE_SWINTE6_Pos)                /*!< 0x00000040 */
#define EINT_SWINTE_SWINTE6                   EINT_SWINTE_SWINTE6_Msk                           /*!< Software Interrupt on line 6 */
#define EINT_SWINTE_SWINTE7_Pos               (7U)
#define EINT_SWINTE_SWINTE7_Msk               (0x1UL << EINT_SWINTE_SWINTE7_Pos)                /*!< 0x00000080 */
#define EINT_SWINTE_SWINTE7                   EINT_SWINTE_SWINTE7_Msk                           /*!< Software Interrupt on line 7 */
#define EINT_SWINTE_SWINTE8_Pos               (8U)
#define EINT_SWINTE_SWINTE8_Msk               (0x1UL << EINT_SWINTE_SWINTE8_Pos)                /*!< 0x00000100 */
#define EINT_SWINTE_SWINTE8                   EINT_SWINTE_SWINTE8_Msk                           /*!< Software Interrupt on line 8 */
#define EINT_SWINTE_SWINTE9_Pos               (9U)
#define EINT_SWINTE_SWINTE9_Msk               (0x1UL << EINT_SWINTE_SWINTE9_Pos)                /*!< 0x00000200 */
#define EINT_SWINTE_SWINTE9                   EINT_SWINTE_SWINTE9_Msk                           /*!< Software Interrupt on line 9 */
#define EINT_SWINTE_SWINTE10_Pos              (10U)
#define EINT_SWINTE_SWINTE10_Msk              (0x1UL << EINT_SWINTE_SWINTE10_Pos)               /*!< 0x00000400 */
#define EINT_SWINTE_SWINTE10                  EINT_SWINTE_SWINTE10_Msk                          /*!< Software Interrupt on line 10 */
#define EINT_SWINTE_SWINTE11_Pos              (11U)
#define EINT_SWINTE_SWINTE11_Msk              (0x1UL << EINT_SWINTE_SWINTE11_Pos)               /*!< 0x00000800 */
#define EINT_SWINTE_SWINTE11                  EINT_SWINTE_SWINTE11_Msk                          /*!< Software Interrupt on line 11 */
#define EINT_SWINTE_SWINTE12_Pos              (12U)
#define EINT_SWINTE_SWINTE12_Msk              (0x1UL << EINT_SWINTE_SWINTE12_Pos)               /*!< 0x00001000 */
#define EINT_SWINTE_SWINTE12                  EINT_SWINTE_SWINTE12_Msk                          /*!< Software Interrupt on line 12 */
#define EINT_SWINTE_SWINTE13_Pos              (13U)
#define EINT_SWINTE_SWINTE13_Msk              (0x1UL << EINT_SWINTE_SWINTE13_Pos)               /*!< 0x00002000 */
#define EINT_SWINTE_SWINTE13                  EINT_SWINTE_SWINTE13_Msk                          /*!< Software Interrupt on line 13 */
#define EINT_SWINTE_SWINTE16_Pos              (16U)
#define EINT_SWINTE_SWINTE16_Msk              (0x1UL << EINT_SWINTE_SWINTE16_Pos)               /*!< 0x00010000 */
#define EINT_SWINTE_SWINTE16                  EINT_SWINTE_SWINTE16_Msk                          /*!< Software Interrupt on line 16 */
#define EINT_SWINTE_SWINTE17_Pos              (17U)
#define EINT_SWINTE_SWINTE17_Msk              (0x1UL << EINT_SWINTE_SWINTE17_Pos)               /*!< 0x00020000 */
#define EINT_SWINTE_SWINTE17                  EINT_SWINTE_SWINTE17_Msk                          /*!< Software Interrupt on line 17 */

/*******************  Bit definition for EINT_IPEND register  *****************/
#define EINT_IPEND_IPEND0_Pos                 (0U)
#define EINT_IPEND_IPEND0_Msk                 (0x1UL << EINT_IPEND_IPEND0_Pos)                  /*!< 0x00000001 */
#define EINT_IPEND_IPEND0                     EINT_IPEND_IPEND0_Msk                             /*!< Pending bit for line 0 */
#define EINT_IPEND_IPEND1_Pos                 (1U)
#define EINT_IPEND_IPEND1_Msk                 (0x1UL << EINT_IPEND_IPEND1_Pos)                  /*!< 0x00000002 */
#define EINT_IPEND_IPEND1                     EINT_IPEND_IPEND1_Msk                             /*!< Pending bit for line 1 */
#define EINT_IPEND_IPEND2_Pos                 (2U)
#define EINT_IPEND_IPEND2_Msk                 (0x1UL << EINT_IPEND_IPEND2_Pos)                  /*!< 0x00000004 */
#define EINT_IPEND_IPEND2                     EINT_IPEND_IPEND2_Msk                             /*!< Pending bit for line 2 */
#define EINT_IPEND_IPEND3_Pos                 (3U)
#define EINT_IPEND_IPEND3_Msk                 (0x1UL << EINT_IPEND_IPEND3_Pos)                  /*!< 0x00000008 */
#define EINT_IPEND_IPEND3                     EINT_IPEND_IPEND3_Msk                             /*!< Pending bit for line 3 */
#define EINT_IPEND_IPEND4_Pos                 (4U)
#define EINT_IPEND_IPEND4_Msk                 (0x1UL << EINT_IPEND_IPEND4_Pos)                  /*!< 0x00000010 */
#define EINT_IPEND_IPEND4                     EINT_IPEND_IPEND4_Msk                             /*!< Pending bit for line 4 */
#define EINT_IPEND_IPEND5_Pos                 (5U)
#define EINT_IPEND_IPEND5_Msk                 (0x1UL << EINT_IPEND_IPEND5_Pos)                  /*!< 0x00000020 */
#define EINT_IPEND_IPEND5                     EINT_IPEND_IPEND5_Msk                             /*!< Pending bit for line 5 */
#define EINT_IPEND_IPEND6_Pos                 (6U)
#define EINT_IPEND_IPEND6_Msk                 (0x1UL << EINT_IPEND_IPEND6_Pos)                  /*!< 0x00000040 */
#define EINT_IPEND_IPEND6                     EINT_IPEND_IPEND6_Msk                             /*!< Pending bit for line 6 */
#define EINT_IPEND_IPEND7_Pos                 (7U)
#define EINT_IPEND_IPEND7_Msk                 (0x1UL << EINT_IPEND_IPEND7_Pos)                  /*!< 0x00000080 */
#define EINT_IPEND_IPEND7                     EINT_IPEND_IPEND7_Msk                             /*!< Pending bit for line 7 */
#define EINT_IPEND_IPEND8_Pos                 (8U)
#define EINT_IPEND_IPEND8_Msk                 (0x1UL << EINT_IPEND_IPEND8_Pos)                  /*!< 0x00000100 */
#define EINT_IPEND_IPEND8                     EINT_IPEND_IPEND8_Msk                             /*!< Pending bit for line 8 */
#define EINT_IPEND_IPEND9_Pos                 (9U)
#define EINT_IPEND_IPEND9_Msk                 (0x1UL << EINT_IPEND_IPEND9_Pos)                  /*!< 0x00000200 */
#define EINT_IPEND_IPEND9                     EINT_IPEND_IPEND9_Msk                             /*!< Pending bit for line 9 */
#define EINT_IPEND_IPEND10_Pos                (10U)
#define EINT_IPEND_IPEND10_Msk                (0x1UL << EINT_IPEND_IPEND10_Pos)                 /*!< 0x00000400 */
#define EINT_IPEND_IPEND10                    EINT_IPEND_IPEND10_Msk                            /*!< Pending bit for line 10 */
#define EINT_IPEND_IPEND11_Pos                (11U)
#define EINT_IPEND_IPEND11_Msk                (0x1UL << EINT_IPEND_IPEND11_Pos)                 /*!< 0x00000800 */
#define EINT_IPEND_IPEND11                    EINT_IPEND_IPEND11_Msk                            /*!< Pending bit for line 11 */
#define EINT_IPEND_IPEND12_Pos                (12U)
#define EINT_IPEND_IPEND12_Msk                (0x1UL << EINT_IPEND_IPEND12_Pos)                 /*!< 0x00001000 */
#define EINT_IPEND_IPEND12                    EINT_IPEND_IPEND12_Msk                            /*!< Pending bit for line 12 */
#define EINT_IPEND_IPEND13_Pos                (13U)
#define EINT_IPEND_IPEND13_Msk                (0x1UL << EINT_IPEND_IPEND13_Pos)                 /*!< 0x00002000 */
#define EINT_IPEND_IPEND13                    EINT_IPEND_IPEND13_Msk                            /*!< Pending bit for line 13 */
#define EINT_IPEND_IPEND16_Pos                (16U)
#define EINT_IPEND_IPEND16_Msk                (0x1UL << EINT_IPEND_IPEND16_Pos)                 /*!< 0x00010000 */
#define EINT_IPEND_IPEND16                    EINT_IPEND_IPEND16_Msk                            /*!< Pending bit for line 16 */
#define EINT_IPEND_IPEND17_Pos                (17U)
#define EINT_IPEND_IPEND17_Msk                (0x1UL << EINT_IPEND_IPEND17_Pos)                 /*!< 0x00020000 */
#define EINT_IPEND_IPEND17                    EINT_IPEND_IPEND17_Msk                            /*!< Pending bit for line 17 */

/*******************  Bit definition for EINT_CFG0 register  ******************/
#define EINT_CFG0_EINT0_Pos                   (0U)
#define EINT_CFG0_EINT0_Msk                   (0xFUL << EINT_CFG0_EINT0_Pos)                    /*!< 0x0000000F */
#define EINT_CFG0_EINT0                       EINT_CFG0_EINT0_Msk
#define EINT_CFG0_EINT1_Pos                   (4U)
#define EINT_CFG0_EINT1_Msk                   (0xFUL << EINT_CFG0_EINT1_Pos)                    /*!< 0x000000F0 */
#define EINT_CFG0_EINT1                       EINT_CFG0_EINT1_Msk
#define EINT_CFG0_EINT2_Pos                   (8U)
#define EINT_CFG0_EINT2_Msk                   (0xFUL << EINT_CFG0_EINT2_Pos)                    /*!< 0x00000F00 */
#define EINT_CFG0_EINT2                       EINT_CFG0_EINT2_Msk
#define EINT_CFG0_EINT3_Pos                   (12U)
#define EINT_CFG0_EINT3_Msk                   (0xFUL << EINT_CFG0_EINT3_Pos)                    /*!< 0x0000F000 */
#define EINT_CFG0_EINT3                       EINT_CFG0_EINT3_Msk
#define EINT_CFG0_EINT4_Pos                   (16U)
#define EINT_CFG0_EINT4_Msk                   (0xFUL << EINT_CFG0_EINT4_Pos)                    /*!< 0x000F0000 */
#define EINT_CFG0_EINT4                       EINT_CFG0_EINT4_Msk
#define EINT_CFG0_EINT5_Pos                   (20U)
#define EINT_CFG0_EINT5_Msk                   (0xFUL << EINT_CFG0_EINT5_Pos)                    /*!< 0x00F00000 */
#define EINT_CFG0_EINT5                       EINT_CFG0_EINT5_Msk
#define EINT_CFG0_EINT6_Pos                   (24U)
#define EINT_CFG0_EINT6_Msk                   (0xFUL << EINT_CFG0_EINT6_Pos)                    /*!< 0x0F000000 */
#define EINT_CFG0_EINT6                       EINT_CFG0_EINT6_Msk
#define EINT_CFG0_EINT7_Pos                   (28U)
#define EINT_CFG0_EINT7_Msk                   (0xFUL << EINT_CFG0_EINT7_Pos)                    /*!< 0xF0000000 */
#define EINT_CFG0_EINT7                       EINT_CFG0_EINT7_Msk
/*******************  Bit definition for EINT_CFG0 register  ******************/
#define EINT_CFG1_EINT8_Pos                   (0U)
#define EINT_CFG1_EINT8_Msk                   (0xFUL << EINT_CFG1_EINT8_Pos)                    /*!< 0x0000000F */
#define EINT_CFG1_EINT8                       EINT_CFG1_EINT8_Msk
#define EINT_CFG1_EINT9_Pos                   (4U)
#define EINT_CFG1_EINT9_Msk                   (0xFUL << EINT_CFG1_EINT9_Pos)                    /*!< 0x000000F0 */
#define EINT_CFG1_EINT9                       EINT_CFG1_EINT9_Msk
#define EINT_CFG1_EINT10_Pos                  (8U)
#define EINT_CFG1_EINT10_Msk                  (0xFUL << EINT_CFG1_EINT10_Pos)                   /*!< 0x00000F00 */
#define EINT_CFG1_EINT10                      EINT_CFG1_EINT10_Msk
#define EINT_CFG1_EINT11_Pos                  (12U)
#define EINT_CFG1_EINT11_Msk                  (0xFUL << EINT_CFG1_EINT11_Pos)                   /*!< 0x0000F000 */
#define EINT_CFG1_EINT11                      EINT_CFG1_EINT11_Msk
#define EINT_CFG1_EINT12_Pos                  (16U)
#define EINT_CFG1_EINT12_Msk                  (0xFUL << EINT_CFG1_EINT12_Pos)                   /*!< 0x000F0000 */
#define EINT_CFG1_EINT12                      EINT_CFG1_EINT12_Msk
#define EINT_CFG1_EINT13_Pos                  (20U)
#define EINT_CFG1_EINT13_Msk                  (0xFUL << EINT_CFG1_EINT13_Pos)                   /*!< 0x00F00000 */
#define EINT_CFG1_EINT13                      EINT_CFG1_EINT13_Msk

/******************************************************************************/
/*                                                                            */
/*                                    FLASH                                   */
/*                                                                            */
/******************************************************************************/
/*******************  Bits definition for FLASH_RKEY register  ****************/
#define FLASH_RKEY_RKEY_Pos                   (0UL)                                             /*!< RKEY (Bit 0) */
#define FLASH_RKEY_RKEY_Msk                   (0x1UL << FLASH_RKEY_RKEY_Pos)                    /*!< RKEY (Bitfield-Mask: 0x01) */
#define FLASH_RKEY_RKEY                       FLASH_RKEY_RKEY_Msk

/*******************  Bits definition for FLASH_MKEY register  ****************/
#define FLASH_MKEY_MKEY_Pos                   (0UL)                                             /*!< MKEY (Bit 0) */
#define FLASH_MKEY_MKEY_Msk                   (0x1UL << FLASH_MKEY_MKEY_Pos)                    /*!< MKEY (Bitfield-Mask: 0x01) */
#define FLASH_MKEY_MKEY                       FLASH_MKEY_MKEY_Msk

/*******************  Bits definition for FLASH_NVR5KEY register  *************/
#define FLASH_NVR5KEY_NVR5KEY_Pos             (0UL)                                             /*!< NVR5KEY (Bit 0) */
#define FLASH_NVR5KEY_NVR5KEY_Msk             (0x1UL << FLASH_NVR5KEY_NVR5KEY_Pos)              /*!< NVR5KEY (Bitfield-Mask: 0x01) */
#define FLASH_NVR5KEY_NVR5KEY                 FLASH_NVR5KEY_NVR5KEY_Msk

/*******************  Bits definition for FLASH_CR register  ******************/
#define FLASH_CR_OPERATE_Pos                  (0UL)                                             /*!< OPERATE (Bit 0) */
#define FLASH_CR_OPERATE_Msk                  (0x3UL << FLASH_CR_OPERATE_Pos)                   /*!< OPERATE (Bitfield-Mask: 0x01) */
#define FLASH_CR_OPERATE                      FLASH_CR_OPERATE_Msk
#define FLASH_CR_OPERATE_0                    (0x1UL << FLASH_CR_OPERATE_Pos)
#define FLASH_CR_OPERATE_1                    (0x2UL << FLASH_CR_OPERATE_Pos)

#define FLASH_CR_READONLY_Pos                 (4UL)                                             /*!< READONLY (Bit 4) */
#define FLASH_CR_READONLY_Msk                 (0x1UL << FLASH_CR_READONLY_Pos)                  /*!< READONLY (Bitfield-Mask: 0x01) */
#define FLASH_CR_READONLY                     FLASH_CR_READONLY_Msk
#define FLASH_CR_LATENCY_Pos                  (8UL)                                             /*!< LATENCY (Bit 8) */
#define FLASH_CR_LATENCY_Msk                  (0x3UL << FLASH_CR_LATENCY_Pos)                   /*!< LATENCY (Bitfield-Mask: 0x03) */
#define FLASH_CR_LATENCY                      FLASH_CR_LATENCY_Msk
#define FLASH_CR_LATENCY_0WS                  (0x00000000UL)
#define FLASH_CR_LATENCY_1WS                  (0x1UL << FLASH_CR_LATENCY_Pos)
#define FLASH_CR_LATENCY_2WS                  (0x2UL << FLASH_CR_LATENCY_Pos)
#define FLASH_CR_LATENCY_3WS                  (0x3UL << FLASH_CR_LATENCY_Pos)
#define FLASH_CR_FORCE_OPTLOAD_Pos            (15UL)                                            /*!< FORCE_OPTLOAD (Bit 15) */
#define FLASH_CR_FORCE_OPTLOAD_Msk            (0x1UL << FLASH_CR_FORCE_OPTLOAD_Pos)             /*!< FORCE_OPTLOAD (Bitfield-Mask: 0x01) */
#define FLASH_CR_FORCE_OPTLOAD                FLASH_CR_FORCE_OPTLOAD_Msk

/*******************  Bits definition for FLASH_ER register  ******************/
#define FLASH_ER_OPEIE_Pos                    (4UL)                                             /*!< OPEIE (Bit 4) */
#define FLASH_ER_OPEIE_Msk                    (0x1UL << FLASH_ER_OPEIE_Pos)                     /*!< OPEIE (Bitfield-Mask: 0x01) */
#define FLASH_ER_OPEIE                        FLASH_ER_OPEIE_Msk
#define FLASH_ER_KEYIE_Pos                    (5UL)                                             /*!< KEYIE (Bit 5) */
#define FLASH_ER_KEYIE_Msk                    (0x1UL << FLASH_ER_KEYIE_Pos)                     /*!< KEYIE (Bitfield-Mask: 0x01) */
#define FLASH_ER_KEYIE                        FLASH_ER_KEYIE_Msk
#define FLASH_ER_RPTIE_Pos                    (6UL)                                             /*!< RPTIE (Bit 6) */
#define FLASH_ER_RPTIE_Msk                    (0x1UL << FLASH_ER_RPTIE_Pos)                     /*!< RPTIE (Bitfield-Mask: 0x01) */
#define FLASH_ER_RPTIE                        FLASH_ER_RPTIE_Msk
#define FLASH_ER_LSIIE_Pos                    (7UL)                                             /*!< LSIIE (Bit 7) */
#define FLASH_ER_LSIIE_Msk                    (0x1UL << FLASH_ER_LSIIE_Pos)                     /*!< LSIIE (Bitfield-Mask: 0x01) */
#define FLASH_ER_LSIIE                        FLASH_ER_LSIIE_Msk

/*******************  Bits definition for FLASH_SR register  ******************/
#define FLASH_SR_BUSY_Pos                     (0UL)                                             /*!< BUSY (Bit 0) */
#define FLASH_SR_BUSY_Msk                     (0x1UL << FLASH_SR_BUSY_Pos)                      /*!< BUSY (Bitfield-Mask: 0x01) */
#define FLASH_SR_BUSY                         FLASH_SR_BUSY_Msk
#define FLASH_SR_OPENDR_Pos                   (4UL)                                             /*!< OPENDR (Bit 4) */
#define FLASH_SR_OPENDR_Msk                   (0x1UL << FLASH_SR_OPENDR_Pos)                    /*!< OPENDR (Bitfield-Mask: 0x01) */
#define FLASH_SR_OPENDR                       FLASH_SR_OPENDR_Msk
#define FLASH_SR_KEYERR_Pos                   (5UL)                                             /*!< KEYERR (Bit 5) */
#define FLASH_SR_KEYERR_Msk                   (0x1UL << FLASH_SR_KEYERR_Pos)                    /*!< KEYERR (Bitfield-Mask: 0x01) */
#define FLASH_SR_KEYERR                       FLASH_SR_KEYERR_Msk
#define FLASH_SR_RPTERR_Pos                   (6UL)                                             /*!< RPTERR (Bit 6) */
#define FLASH_SR_RPTERR_Msk                   (0x1UL << FLASH_SR_RPTERR_Pos)                    /*!< RPTERR (Bitfield-Mask: 0x01) */
#define FLASH_SR_RPTERR                       FLASH_SR_RPTERR_Msk
#define FLASH_SR_LSIERR_Pos                   (7UL)                                             /*!< LSIERR (Bit 7) */
#define FLASH_SR_LSIERR_Msk                   (0x1UL << FLASH_SR_LSIERR_Pos)                    /*!< LSIERR (Bitfield-Mask: 0x01) */
#define FLASH_SR_LSIERR                       FLASH_SR_LSIERR_Msk


/******************************************************************************/
/*                                                                            */
/*                            General Purpose I/O                             */
/*                                                                            */
/******************************************************************************/
/*******************  Bit definition for GPIO_MODE register  *******************/
#define GPIO_MODE_MODE0_Pos                   (0U)
#define GPIO_MODE_MODE0_Msk                   (0x3UL << GPIO_MODE_MODE0_Pos)                    /*!< 0x00000003 */
#define GPIO_MODE_MODE0                       GPIO_MODE_MODE0_Msk
#define GPIO_MODE_MODE0_0                     (0x1UL << GPIO_MODE_MODE0_Pos)                    /*!< 0x00000001 */
#define GPIO_MODE_MODE0_1                     (0x2UL << GPIO_MODE_MODE0_Pos)                    /*!< 0x00000002 */
#define GPIO_MODE_MODE1_Pos                   (2U)
#define GPIO_MODE_MODE1_Msk                   (0x3UL << GPIO_MODE_MODE1_Pos)                    /*!< 0x0000000C */
#define GPIO_MODE_MODE1                       GPIO_MODE_MODE1_Msk
#define GPIO_MODE_MODE1_0                     (0x1UL << GPIO_MODE_MODE1_Pos)                    /*!< 0x00000004 */
#define GPIO_MODE_MODE1_1                     (0x2UL << GPIO_MODE_MODE1_Pos)                    /*!< 0x00000008 */
#define GPIO_MODE_MODE2_Pos                   (4U)
#define GPIO_MODE_MODE2_Msk                   (0x3UL << GPIO_MODE_MODE2_Pos)                    /*!< 0x00000030 */
#define GPIO_MODE_MODE2                       GPIO_MODE_MODE2_Msk
#define GPIO_MODE_MODE2_0                     (0x1UL << GPIO_MODE_MODE2_Pos)                    /*!< 0x00000010 */
#define GPIO_MODE_MODE2_1                     (0x2UL << GPIO_MODE_MODE2_Pos)                    /*!< 0x00000020 */
#define GPIO_MODE_MODE3_Pos                   (6U)
#define GPIO_MODE_MODE3_Msk                   (0x3UL << GPIO_MODE_MODE3_Pos)                    /*!< 0x000000C0 */
#define GPIO_MODE_MODE3                       GPIO_MODE_MODE3_Msk
#define GPIO_MODE_MODE3_0                     (0x1UL << GPIO_MODE_MODE3_Pos)                    /*!< 0x00000040 */
#define GPIO_MODE_MODE3_1                     (0x2UL << GPIO_MODE_MODE3_Pos)                    /*!< 0x00000080 */
#define GPIO_MODE_MODE4_Pos                   (8U)
#define GPIO_MODE_MODE4_Msk                   (0x3UL << GPIO_MODE_MODE4_Pos)                    /*!< 0x00000300 */
#define GPIO_MODE_MODE4                       GPIO_MODE_MODE4_Msk
#define GPIO_MODE_MODE4_0                     (0x1UL << GPIO_MODE_MODE4_Pos)                    /*!< 0x00000100 */
#define GPIO_MODE_MODE4_1                     (0x2UL << GPIO_MODE_MODE4_Pos)                    /*!< 0x00000200 */
#define GPIO_MODE_MODE5_Pos                   (10U)
#define GPIO_MODE_MODE5_Msk                   (0x3UL << GPIO_MODE_MODE5_Pos)                    /*!< 0x00000C00 */
#define GPIO_MODE_MODE5                       GPIO_MODE_MODE5_Msk
#define GPIO_MODE_MODE5_0                     (0x1UL << GPIO_MODE_MODE5_Pos)                    /*!< 0x00000400 */
#define GPIO_MODE_MODE5_1                     (0x2UL << GPIO_MODE_MODE5_Pos)                    /*!< 0x00000800 */
#define GPIO_MODE_MODE6_Pos                   (12U)
#define GPIO_MODE_MODE6_Msk                   (0x3UL << GPIO_MODE_MODE6_Pos)                    /*!< 0x00003000 */
#define GPIO_MODE_MODE6                       GPIO_MODE_MODE6_Msk
#define GPIO_MODE_MODE6_0                     (0x1UL << GPIO_MODE_MODE6_Pos)                    /*!< 0x00001000 */
#define GPIO_MODE_MODE6_1                     (0x2UL << GPIO_MODE_MODE6_Pos)                    /*!< 0x00002000 */
#define GPIO_MODE_MODE7_Pos                   (14U)
#define GPIO_MODE_MODE7_Msk                   (0x3UL << GPIO_MODE_MODE7_Pos)                    /*!< 0x0000C000 */
#define GPIO_MODE_MODE7                       GPIO_MODE_MODE7_Msk
#define GPIO_MODE_MODE7_0                     (0x1UL << GPIO_MODE_MODE7_Pos)                    /*!< 0x00004000 */
#define GPIO_MODE_MODE7_1                     (0x2UL << GPIO_MODE_MODE7_Pos)                    /*!< 0x00008000 */
#define GPIO_MODE_MODE8_Pos                   (16U)
#define GPIO_MODE_MODE8_Msk                   (0x3UL << GPIO_MODE_MODE8_Pos)                    /*!< 0x00030000 */
#define GPIO_MODE_MODE8                       GPIO_MODE_MODE8_Msk
#define GPIO_MODE_MODE8_0                     (0x1UL << GPIO_MODE_MODE8_Pos)                    /*!< 0x00010000 */
#define GPIO_MODE_MODE8_1                     (0x2UL << GPIO_MODE_MODE8_Pos)                    /*!< 0x00020000 */
#define GPIO_MODE_MODE9_Pos                   (18U)
#define GPIO_MODE_MODE9_Msk                   (0x3UL << GPIO_MODE_MODE9_Pos)                    /*!< 0x000C0000 */
#define GPIO_MODE_MODE9                       GPIO_MODE_MODE9_Msk
#define GPIO_MODE_MODE9_0                     (0x1UL << GPIO_MODE_MODE9_Pos)                    /*!< 0x00040000 */
#define GPIO_MODE_MODE9_1                     (0x2UL << GPIO_MODE_MODE9_Pos)                    /*!< 0x00080000 */
#define GPIO_MODE_MODE10_Pos                  (20U)
#define GPIO_MODE_MODE10_Msk                  (0x3UL << GPIO_MODE_MODE10_Pos)                   /*!< 0x00300000 */
#define GPIO_MODE_MODE10                      GPIO_MODE_MODE10_Msk
#define GPIO_MODE_MODE10_0                    (0x1UL << GPIO_MODE_MODE10_Pos)                   /*!< 0x00100000 */
#define GPIO_MODE_MODE10_1                    (0x2UL << GPIO_MODE_MODE10_Pos)                   /*!< 0x00200000 */
#define GPIO_MODE_MODE11_Pos                  (22U)
#define GPIO_MODE_MODE11_Msk                  (0x3UL << GPIO_MODE_MODE11_Pos)                   /*!< 0x00C00000 */
#define GPIO_MODE_MODE11                      GPIO_MODE_MODE11_Msk
#define GPIO_MODE_MODE11_0                    (0x1UL << GPIO_MODE_MODE11_Pos)                   /*!< 0x00400000 */
#define GPIO_MODE_MODE11_1                    (0x2UL << GPIO_MODE_MODE11_Pos)                   /*!< 0x00800000 */
#define GPIO_MODE_MODE12_Pos                  (24U)
#define GPIO_MODE_MODE12_Msk                  (0x3UL << GPIO_MODE_MODE12_Pos)                   /*!< 0x03000000 */
#define GPIO_MODE_MODE12                      GPIO_MODE_MODE12_Msk
#define GPIO_MODE_MODE12_0                    (0x1UL << GPIO_MODE_MODE12_Pos)                   /*!< 0x01000000 */
#define GPIO_MODE_MODE12_1                    (0x2UL << GPIO_MODE_MODE12_Pos)                   /*!< 0x02000000 */
#define GPIO_MODE_MODE13_Pos                  (26U)
#define GPIO_MODE_MODE13_Msk                  (0x3UL << GPIO_MODE_MODE13_Pos)                   /*!< 0x0C000000 */
#define GPIO_MODE_MODE13                      GPIO_MODE_MODE13_Msk
#define GPIO_MODE_MODE13_0                    (0x1UL << GPIO_MODE_MODE13_Pos)                   /*!< 0x04000000 */
#define GPIO_MODE_MODE13_1                    (0x2UL << GPIO_MODE_MODE13_Pos)                   /*!< 0x08000000 */
/******************  Bits definition for GPIO_IEN register  *******************/
#define GPIO_IEN_IEN0_Pos                     (0U)
#define GPIO_IEN_IEN0_Msk                     (0x1UL << GPIO_IEN_IEN0_Pos)                      /*!< 0x00000001 */
#define GPIO_IEN_IEN0                         GPIO_IEN_IEN0_Msk
#define GPIO_IEN_IEN1_Pos                     (1U)
#define GPIO_IEN_IEN1_Msk                     (0x1UL << GPIO_IEN_IEN1_Pos)                      /*!< 0x00000002 */
#define GPIO_IEN_IEN1                         GPIO_IEN_IEN1_Msk
#define GPIO_IEN_IEN2_Pos                     (2U)
#define GPIO_IEN_IEN2_Msk                     (0x1UL << GPIO_IEN_IEN2_Pos)                      /*!< 0x00000004 */
#define GPIO_IEN_IEN2                         GPIO_IEN_IEN2_Msk
#define GPIO_IEN_IEN3_Pos                     (3U)
#define GPIO_IEN_IEN3_Msk                     (0x1UL << GPIO_IEN_IEN3_Pos)                      /*!< 0x00000008 */
#define GPIO_IEN_IEN3                         GPIO_IEN_IEN3_Msk
#define GPIO_IEN_IEN4_Pos                     (4U)
#define GPIO_IEN_IEN4_Msk                     (0x1UL << GPIO_IEN_IEN4_Pos)                      /*!< 0x00000010 */
#define GPIO_IEN_IEN4                         GPIO_IEN_IEN4_Msk
#define GPIO_IEN_IEN5_Pos                     (5U)
#define GPIO_IEN_IEN5_Msk                     (0x1UL << GPIO_IEN_IEN5_Pos)                      /*!< 0x00000020 */
#define GPIO_IEN_IEN5                         GPIO_IEN_IEN5_Msk
#define GPIO_IEN_IEN6_Pos                     (6U)
#define GPIO_IEN_IEN6_Msk                     (0x1UL << GPIO_IEN_IEN6_Pos)                      /*!< 0x00000040 */
#define GPIO_IEN_IEN6                         GPIO_IEN_IEN6_Msk
#define GPIO_IEN_IEN7_Pos                     (7U)
#define GPIO_IEN_IEN7_Msk                     (0x1UL << GPIO_IEN_IEN7_Pos)                      /*!< 0x00000080 */
#define GPIO_IEN_IEN7                         GPIO_IEN_IEN7_Msk
#define GPIO_IEN_IEN8_Pos                     (8U)
#define GPIO_IEN_IEN8_Msk                     (0x1UL << GPIO_IEN_IEN8_Pos)                      /*!< 0x00000100 */
#define GPIO_IEN_IEN8                         GPIO_IEN_IEN8_Msk
#define GPIO_IEN_IEN9_Pos                     (9U)
#define GPIO_IEN_IEN9_Msk                     (0x1UL << GPIO_IEN_IEN9_Pos)                      /*!< 0x00000200 */
#define GPIO_IEN_IEN9                         GPIO_IEN_IEN9_Msk
#define GPIO_IEN_IEN10_Pos                    (10U)
#define GPIO_IEN_IEN10_Msk                    (0x1UL << GPIO_IEN_IEN10_Pos)                     /*!< 0x00000400 */
#define GPIO_IEN_IEN10                        GPIO_IEN_IEN10_Msk
#define GPIO_IEN_IEN11_Pos                    (11U)
#define GPIO_IEN_IEN11_Msk                    (0x1UL << GPIO_IEN_IEN11_Pos)                     /*!< 0x00000800 */
#define GPIO_IEN_IEN11                        GPIO_IEN_IEN11_Msk
#define GPIO_IEN_IEN12_Pos                    (12U)
#define GPIO_IEN_IEN12_Msk                    (0x1UL << GPIO_IEN_IEN12_Pos)                     /*!< 0x00001000 */
#define GPIO_IEN_IEN12                        GPIO_IEN_IEN12_Msk
#define GPIO_IEN_IEN13_Pos                    (13U)
#define GPIO_IEN_IEN13_Msk                    (0x1UL << GPIO_IEN_IEN13_Pos)                     /*!< 0x00002000 */
#define GPIO_IEN_IEN13                        GPIO_IEN_IEN13_Msk
/******************  Bits definition for GPIO_ITYPCFG register  *******************/
#define GPIO_ITYPCFG_ITYPCFG0_Pos             (0U)
#define GPIO_ITYPCFG_ITYPCFG0_Msk             (0x1UL << GPIO_ITYPCFG_ITYPCFG0_Pos)              /*!< 0x00000001 */
#define GPIO_ITYPCFG_ITYPCFG0                 GPIO_ITYPCFG_ITYPCFG0_Msk
#define GPIO_ITYPCFG_ITYPCFG1_Pos             (1U)
#define GPIO_ITYPCFG_ITYPCFG1_Msk             (0x1UL << GPIO_ITYPCFG_ITYPCFG1_Pos)              /*!< 0x00000002 */
#define GPIO_ITYPCFG_ITYPCFG1                 GPIO_ITYPCFG_ITYPCFG1_Msk
#define GPIO_ITYPCFG_ITYPCFG2_Pos             (2U)
#define GPIO_ITYPCFG_ITYPCFG2_Msk             (0x1UL << GPIO_ITYPCFG_ITYPCFG2_Pos)              /*!< 0x00000004 */
#define GPIO_ITYPCFG_ITYPCFG2                 GPIO_ITYPCFG_ITYPCFG2_Msk
#define GPIO_ITYPCFG_ITYPCFG3_Pos             (3U)
#define GPIO_ITYPCFG_ITYPCFG3_Msk             (0x1UL << GPIO_ITYPCFG_ITYPCFG3_Pos)              /*!< 0x00000008 */
#define GPIO_ITYPCFG_ITYPCFG3                 GPIO_ITYPCFG_ITYPCFG3_Msk
#define GPIO_ITYPCFG_ITYPCFG4_Pos             (4U)
#define GPIO_ITYPCFG_ITYPCFG4_Msk             (0x1UL << GPIO_ITYPCFG_ITYPCFG4_Pos)              /*!< 0x00000010 */
#define GPIO_ITYPCFG_ITYPCFG4                 GPIO_ITYPCFG_ITYPCFG4_Msk
#define GPIO_ITYPCFG_ITYPCFG5_Pos             (5U)
#define GPIO_ITYPCFG_ITYPCFG5_Msk             (0x1UL << GPIO_ITYPCFG_ITYPCFG5_Pos)              /*!< 0x00000020 */
#define GPIO_ITYPCFG_ITYPCFG5                 GPIO_ITYPCFG_ITYPCFG5_Msk
#define GPIO_ITYPCFG_ITYPCFG6_Pos             (6U)
#define GPIO_ITYPCFG_ITYPCFG6_Msk             (0x1UL << GPIO_ITYPCFG_ITYPCFG6_Pos)              /*!< 0x00000040 */
#define GPIO_ITYPCFG_ITYPCFG6                 GPIO_ITYPCFG_ITYPCFG6_Msk
#define GPIO_ITYPCFG_ITYPCFG7_Pos             (7U)
#define GPIO_ITYPCFG_ITYPCFG7_Msk             (0x1UL << GPIO_ITYPCFG_ITYPCFG7_Pos)              /*!< 0x00000080 */
#define GPIO_ITYPCFG_ITYPCFG7                 GPIO_ITYPCFG_ITYPCFG7_Msk
#define GPIO_ITYPCFG_ITYPCFG8_Pos             (8U)
#define GPIO_ITYPCFG_ITYPCFG8_Msk             (0x1UL << GPIO_ITYPCFG_ITYPCFG8_Pos)              /*!< 0x00000100 */
#define GPIO_ITYPCFG_ITYPCFG8                 GPIO_ITYPCFG_ITYPCFG8_Msk
#define GPIO_ITYPCFG_ITYPCFG9_Pos             (9U)
#define GPIO_ITYPCFG_ITYPCFG9_Msk             (0x1UL << GPIO_ITYPCFG_ITYPCFG9_Pos)              /*!< 0x00000200 */
#define GPIO_ITYPCFG_ITYPCFG9                 GPIO_ITYPCFG_ITYPCFG9_Msk
#define GPIO_ITYPCFG_ITYPCFG10_Pos            (10U)
#define GPIO_ITYPCFG_ITYPCFG10_Msk            (0x1UL << GPIO_ITYPCFG_ITYPCFG10_Pos)             /*!< 0x00000400 */
#define GPIO_ITYPCFG_ITYPCFG10                GPIO_ITYPCFG_ITYPCFG10_Msk
#define GPIO_ITYPCFG_ITYPCFG11_Pos            (11U)
#define GPIO_ITYPCFG_ITYPCFG11_Msk            (0x1UL << GPIO_ITYPCFG_ITYPCFG11_Pos)             /*!< 0x00000800 */
#define GPIO_ITYPCFG_ITYPCFG11                GPIO_ITYPCFG_ITYPCFG11_Msk
#define GPIO_ITYPCFG_ITYPCFG12_Pos            (12U)
#define GPIO_ITYPCFG_ITYPCFG12_Msk            (0x1UL << GPIO_ITYPCFG_ITYPCFG12_Pos)             /*!< 0x00001000 */
#define GPIO_ITYPCFG_ITYPCFG12                GPIO_ITYPCFG_ITYPCFG12_Msk
#define GPIO_ITYPCFG_ITYPCFG13_Pos            (13U)
#define GPIO_ITYPCFG_ITYPCFG13_Msk            (0x1UL << GPIO_ITYPCFG_ITYPCFG13_Pos)             /*!< 0x00002000 */
#define GPIO_ITYPCFG_ITYPCFG13                GPIO_ITYPCFG_ITYPCFG13_Msk
/******************  Bits definition for GPIO_PUPD register  *****************/
#define GPIO_PUPD_PUPDEN0_Pos                 (0U)
#define GPIO_PUPD_PUPDEN0_Msk                 (0x1UL << GPIO_PUPD_PUPDEN0_Pos)                  /*!< 0x00000001 */
#define GPIO_PUPD_PUPDEN0                     GPIO_PUPD_PUPDEN0_Msk
#define GPIO_PUPD_PUPD0_Pos                   (1U)
#define GPIO_PUPD_PUPD0_Msk                   (0x1UL << GPIO_PUPD_PUPD0_Pos)                    /*!< 0x00000002 */
#define GPIO_PUPD_PUPD0                       GPIO_PUPD_PUPD0_Msk
#define GPIO_PUPD_PUPDEN1_Pos                 (2U)
#define GPIO_PUPD_PUPDEN1_Msk                 (0x1UL << GPIO_PUPD_PUPDEN1_Pos)                  /*!< 0x00000004 */
#define GPIO_PUPD_PUPDEN1                     GPIO_PUPD_PUPDEN1_Msk
#define GPIO_PUPD_PUPD1_Pos                   (3U)
#define GPIO_PUPD_PUPD1_Msk                   (0x1UL << GPIO_PUPD_PUPD1_Pos)                    /*!< 0x00000008 */
#define GPIO_PUPD_PUPD1                       GPIO_PUPD_PUPD1_Msk
#define GPIO_PUPD_PUPDEN2_Pos                 (4U)
#define GPIO_PUPD_PUPDEN2_Msk                 (0x1UL << GPIO_PUPD_PUPDEN2_Pos)                  /*!< 0x00000010 */
#define GPIO_PUPD_PUPDEN2                     GPIO_PUPD_PUPDEN2_Msk
#define GPIO_PUPD_PUPD2_Pos                   (5U)
#define GPIO_PUPD_PUPD2_Msk                   (0x1UL << GPIO_PUPD_PUPD2_Pos)                    /*!< 0x00000020 */
#define GPIO_PUPD_PUPD2                       GPIO_PUPD_PUPD2_Msk
#define GPIO_PUPD_PUPDEN3_Pos                 (6U)
#define GPIO_PUPD_PUPDEN3_Msk                 (0x1UL << GPIO_PUPD_PUPDEN3_Pos)                  /*!< 0x00000040 */
#define GPIO_PUPD_PUPDEN3                     GPIO_PUPD_PUPDEN3_Msk
#define GPIO_PUPD_PUPD3_Pos                   (7U)
#define GPIO_PUPD_PUPD3_Msk                   (0x1UL << GPIO_PUPD_PUPD3_Pos)                    /*!< 0x00000080 */
#define GPIO_PUPD_PUPD3                       GPIO_PUPD_PUPD3_Msk
#define GPIO_PUPD_PUPDEN4_Pos                 (8U)
#define GPIO_PUPD_PUPDEN4_Msk                 (0x1UL << GPIO_PUPD_PUPDEN4_Pos)                  /*!< 0x00000100 */
#define GPIO_PUPD_PUPDEN4                     GPIO_PUPD_PUPDEN4_Msk
#define GPIO_PUPD_PUPD4_Pos                   (9U)
#define GPIO_PUPD_PUPD4_Msk                   (0x1UL << GPIO_PUPD_PUPD4_Pos)                    /*!< 0x00000200 */
#define GPIO_PUPD_PUPD4                       GPIO_PUPD_PUPD4_Msk
#define GPIO_PUPD_PUPDEN5_Pos                 (10U)
#define GPIO_PUPD_PUPDEN5_Msk                 (0x1UL << GPIO_PUPD_PUPDEN5_Pos)                  /*!< 0x00000400 */
#define GPIO_PUPD_PUPDEN5                     GPIO_PUPD_PUPDEN5_Msk
#define GPIO_PUPD_PUPD5_Pos                   (11U)
#define GPIO_PUPD_PUPD5_Msk                   (0x1UL << GPIO_PUPD_PUPD5_Pos)                    /*!< 0x00000800 */
#define GPIO_PUPD_PUPD5                       GPIO_PUPD_PUPD5_Msk
#define GPIO_PUPD_PUPDEN6_Pos                 (12U)
#define GPIO_PUPD_PUPDEN6_Msk                 (0x1UL << GPIO_PUPD_PUPDEN6_Pos)                  /*!< 0x00001000 */
#define GPIO_PUPD_PUPDEN6                     GPIO_PUPD_PUPDEN6_Msk
#define GPIO_PUPD_PUPD6_Pos                   (13U)
#define GPIO_PUPD_PUPD6_Msk                   (0x1UL << GPIO_PUPD_PUPD6_Pos)                    /*!< 0x00002000 */
#define GPIO_PUPD_PUPD6                       GPIO_PUPD_PUPD6_Msk
#define GPIO_PUPD_PUPDEN7_Pos                 (14U)
#define GPIO_PUPD_PUPDEN7_Msk                 (0x1UL << GPIO_PUPD_PUPDEN7_Pos)                  /*!< 0x00004000 */
#define GPIO_PUPD_PUPDEN7                     GPIO_PUPD_PUPDEN7_Msk
#define GPIO_PUPD_PUPD7_Pos                   (15U)
#define GPIO_PUPD_PUPD7_Msk                   (0x1UL << GPIO_PUPD_PUPD7_Pos)                    /*!< 0x00008000 */
#define GPIO_PUPD_PUPD7                       GPIO_PUPD_PUPD7_Msk
#define GPIO_PUPD_PUPDEN8_Pos                 (16U)
#define GPIO_PUPD_PUPDEN8_Msk                 (0x1UL << GPIO_PUPD_PUPDEN8_Pos)                  /*!< 0x00010000 */
#define GPIO_PUPD_PUPDEN8                     GPIO_PUPD_PUPDEN8_Msk
#define GPIO_PUPD_PUPD8_Pos                   (17U)
#define GPIO_PUPD_PUPD8_Msk                   (0x1UL << GPIO_PUPD_PUPD8_Pos)                    /*!< 0x00020000 */
#define GPIO_PUPD_PUPD8                       GPIO_PUPD_PUPD8_Msk
#define GPIO_PUPD_PUPDEN9_Pos                 (18U)
#define GPIO_PUPD_PUPDEN9_Msk                 (0x1UL << GPIO_PUPD_PUPDEN9_Pos)                  /*!< 0x00040000 */
#define GPIO_PUPD_PUPDEN9                     GPIO_PUPD_PUPDEN9_Msk
#define GPIO_PUPD_PUPD9_Pos                   (19U)
#define GPIO_PUPD_PUPD9_Msk                   (0x1UL << GPIO_PUPD_PUPD9_Pos)                    /*!< 0x00080000 */
#define GPIO_PUPD_PUPD9                       GPIO_PUPD_PUPD9_Msk
#define GPIO_PUPD_PUPDEN10_Pos                (20U)
#define GPIO_PUPD_PUPDEN10_Msk                (0x1UL << GPIO_PUPD_PUPDEN10_Pos)                 /*!< 0x00100000 */
#define GPIO_PUPD_PUPDEN10                    GPIO_PUPD_PUPDEN10_Msk
#define GPIO_PUPD_PUPD10_Pos                  (21U)
#define GPIO_PUPD_PUPD10_Msk                  (0x1UL << GPIO_PUPD_PUPD10_Pos)                   /*!< 0x00200000 */
#define GPIO_PUPD_PUPD10                      GPIO_PUPD_PUPD10_Msk
#define GPIO_PUPD_PUPDEN11_Pos                (22U)
#define GPIO_PUPD_PUPDEN11_Msk                (0x1UL << GPIO_PUPD_PUPDEN11_Pos)                 /*!< 0x00400000 */
#define GPIO_PUPD_PUPDEN11                    GPIO_PUPD_PUPDEN11_Msk
#define GPIO_PUPD_PUPD11_Pos                  (23U)
#define GPIO_PUPD_PUPD11_Msk                  (0x1UL << GPIO_PUPD_PUPD11_Pos)                   /*!< 0x00800000 */
#define GPIO_PUPD_PUPD11                      GPIO_PUPD_PUPD11_Msk
#define GPIO_PUPD_PUPDEN12_Pos                (24U)
#define GPIO_PUPD_PUPDEN12_Msk                (0x1UL << GPIO_PUPD_PUPDEN12_Pos)                 /*!< 0x01000000 */
#define GPIO_PUPD_PUPDEN12                    GPIO_PUPD_PUPDEN12_Msk
#define GPIO_PUPD_PUPD12_Pos                  (25U)
#define GPIO_PUPD_PUPD12_Msk                  (0x1UL << GPIO_PUPD_PUPD12_Pos)                   /*!< 0x02000000 */
#define GPIO_PUPD_PUPD12                      GPIO_PUPD_PUPD12_Msk
#define GPIO_PUPD_PUPDEN13_Pos                (26U)
#define GPIO_PUPD_PUPDEN13_Msk                (0x1UL << GPIO_PUPD_PUPDEN13_Pos)                 /*!< 0x04000000 */
#define GPIO_PUPD_PUPDEN13                    GPIO_PUPD_PUPDEN13_Msk
#define GPIO_PUPD_PUPD13_Pos                  (27U)
#define GPIO_PUPD_PUPD13_Msk                  (0x1UL << GPIO_PUPD_PUPD13_Pos)                   /*!< 0x08000000 */
#define GPIO_PUPD_PUPD13                      GPIO_PUPD_PUPD13_Msk

/******************  Bits definition for GPIO_OTYPCFG register  ****************/
#define GPIO_OTYPCFG_OTYPCFG0_Pos             (0U)
#define GPIO_OTYPCFG_OTYPCFG0_Msk             (0x1UL << GPIO_OTYPCFG_OTYPCFG0_Pos)              /*!< 0x00000001 */
#define GPIO_OTYPCFG_OTYPCFG0                 GPIO_OTYPCFG_OTYPCFG0_Msk
#define GPIO_OTYPCFG_OTYPCFG1_Pos             (1U)
#define GPIO_OTYPCFG_OTYPCFG1_Msk             (0x1UL << GPIO_OTYPCFG_OTYPCFG1_Pos)              /*!< 0x00000002 */
#define GPIO_OTYPCFG_OTYPCFG1                 GPIO_OTYPCFG_OTYPCFG1_Msk
#define GPIO_OTYPCFG_OTYPCFG2_Pos             (2U)
#define GPIO_OTYPCFG_OTYPCFG2_Msk             (0x1UL << GPIO_OTYPCFG_OTYPCFG2_Pos)              /*!< 0x00000004 */
#define GPIO_OTYPCFG_OTYPCFG2                 GPIO_OTYPCFG_OTYPCFG2_Msk
#define GPIO_OTYPCFG_OTYPCFG3_Pos             (3U)
#define GPIO_OTYPCFG_OTYPCFG3_Msk             (0x1UL << GPIO_OTYPCFG_OTYPCFG3_Pos)              /*!< 0x00000008 */
#define GPIO_OTYPCFG_OTYPCFG3                 GPIO_OTYPCFG_OTYPCFG3_Msk
#define GPIO_OTYPCFG_OTYPCFG4_Pos             (4U)
#define GPIO_OTYPCFG_OTYPCFG4_Msk             (0x1UL << GPIO_OTYPCFG_OTYPCFG4_Pos)              /*!< 0x00000010 */
#define GPIO_OTYPCFG_OTYPCFG4                 GPIO_OTYPCFG_OTYPCFG4_Msk
#define GPIO_OTYPCFG_OTYPCFG5_Pos             (5U)
#define GPIO_OTYPCFG_OTYPCFG5_Msk             (0x1UL << GPIO_OTYPCFG_OTYPCFG5_Pos)              /*!< 0x00000020 */
#define GPIO_OTYPCFG_OTYPCFG5                 GPIO_OTYPCFG_OTYPCFG5_Msk
#define GPIO_OTYPCFG_OTYPCFG6_Pos             (6U)
#define GPIO_OTYPCFG_OTYPCFG6_Msk             (0x1UL << GPIO_OTYPCFG_OTYPCFG6_Pos)              /*!< 0x00000040 */
#define GPIO_OTYPCFG_OTYPCFG6                 GPIO_OTYPCFG_OTYPCFG6_Msk
#define GPIO_OTYPCFG_OTYPCFG7_Pos             (7U)
#define GPIO_OTYPCFG_OTYPCFG7_Msk             (0x1UL << GPIO_OTYPCFG_OTYPCFG7_Pos)              /*!< 0x00000080 */
#define GPIO_OTYPCFG_OTYPCFG7                 GPIO_OTYPCFG_OTYPCFG7_Msk
#define GPIO_OTYPCFG_OTYPCFG8_Pos             (8U)
#define GPIO_OTYPCFG_OTYPCFG8_Msk             (0x1UL << GPIO_OTYPCFG_OTYPCFG8_Pos)              /*!< 0x00000100 */
#define GPIO_OTYPCFG_OTYPCFG8                 GPIO_OTYPCFG_OTYPCFG8_Msk
#define GPIO_OTYPCFG_OTYPCFG9_Pos             (9U)
#define GPIO_OTYPCFG_OTYPCFG9_Msk             (0x1UL << GPIO_OTYPCFG_OTYPCFG9_Pos)              /*!< 0x00000200 */
#define GPIO_OTYPCFG_OTYPCFG9                 GPIO_OTYPCFG_OTYPCFG9_Msk
#define GPIO_OTYPCFG_OTYPCFG10_Pos            (10U)
#define GPIO_OTYPCFG_OTYPCFG10_Msk            (0x1UL << GPIO_OTYPCFG_OTYPCFG10_Pos)             /*!< 0x00000400 */
#define GPIO_OTYPCFG_OTYPCFG10                GPIO_OTYPCFG_OTYPCFG10_Msk
#define GPIO_OTYPCFG_OTYPCFG11_Pos            (11U)
#define GPIO_OTYPCFG_OTYPCFG11_Msk            (0x1UL << GPIO_OTYPCFG_OTYPCFG11_Pos)             /*!< 0x00000800 */
#define GPIO_OTYPCFG_OTYPCFG11                GPIO_OTYPCFG_OTYPCFG11_Msk
#define GPIO_OTYPCFG_OTYPCFG12_Pos            (12U)
#define GPIO_OTYPCFG_OTYPCFG12_Msk            (0x1UL << GPIO_OTYPCFG_OTYPCFG12_Pos)             /*!< 0x00001000 */
#define GPIO_OTYPCFG_OTYPCFG12                GPIO_OTYPCFG_OTYPCFG12_Msk
#define GPIO_OTYPCFG_OTYPCFG13_Pos            (13U)
#define GPIO_OTYPCFG_OTYPCFG13_Msk            (0x1UL << GPIO_OTYPCFG_OTYPCFG13_Pos)             /*!< 0x00002000 */
#define GPIO_OTYPCFG_OTYPCFG13                GPIO_OTYPCFG_OTYPCFG13_Msk

/******************  Bits definition for GPIO_DCFG register  ****************/
#define GPIO_DCFG_DCFG0_Pos                   (0U)
#define GPIO_DCFG_DCFG0_Msk                   (0x1UL << GPIO_DCFG_DCFG0_Pos)                    /*!< 0x00000001 */
#define GPIO_DCFG_DCFG0                       GPIO_DCFG_DCFG0_Msk
#define GPIO_DCFG_DCFG1_Pos                   (1U)
#define GPIO_DCFG_DCFG1_Msk                   (0x1UL << GPIO_DCFG_DCFG1_Pos)                    /*!< 0x00000002 */
#define GPIO_DCFG_DCFG1                       GPIO_DCFG_DCFG1_Msk
#define GPIO_DCFG_DCFG2_Pos                   (2U)
#define GPIO_DCFG_DCFG2_Msk                   (0x1UL << GPIO_DCFG_DCFG2_Pos)                    /*!< 0x00000004 */
#define GPIO_DCFG_DCFG2                       GPIO_DCFG_DCFG2_Msk
#define GPIO_DCFG_DCFG3_Pos                   (3U)
#define GPIO_DCFG_DCFG3_Msk                   (0x1UL << GPIO_DCFG_DCFG3_Pos)                    /*!< 0x00000008 */
#define GPIO_DCFG_DCFG3                       GPIO_DCFG_DCFG3_Msk
#define GPIO_DCFG_DCFG4_Pos                   (4U)
#define GPIO_DCFG_DCFG4_Msk                   (0x1UL << GPIO_DCFG_DCFG4_Pos)                    /*!< 0x00000010 */
#define GPIO_DCFG_DCFG4                       GPIO_DCFG_DCFG4_Msk
#define GPIO_DCFG_DCFG5_Pos                   (5U)
#define GPIO_DCFG_DCFG5_Msk                   (0x1UL << GPIO_DCFG_DCFG5_Pos)                    /*!< 0x00000020 */
#define GPIO_DCFG_DCFG5                       GPIO_DCFG_DCFG5_Msk
#define GPIO_DCFG_DCFG6_Pos                   (6U)
#define GPIO_DCFG_DCFG6_Msk                   (0x1UL << GPIO_DCFG_DCFG6_Pos)                    /*!< 0x00000040 */
#define GPIO_DCFG_DCFG6                       GPIO_DCFG_DCFG6_Msk
#define GPIO_DCFG_DCFG7_Pos                   (7U)
#define GPIO_DCFG_DCFG7_Msk                   (0x1UL << GPIO_DCFG_DCFG7_Pos)                    /*!< 0x00000080 */
#define GPIO_DCFG_DCFG7                       GPIO_DCFG_DCFG7_Msk
#define GPIO_DCFG_DCFG8_Pos                   (8U)
#define GPIO_DCFG_DCFG8_Msk                   (0x1UL << GPIO_DCFG_DCFG8_Pos)                    /*!< 0x00000100 */
#define GPIO_DCFG_DCFG8                       GPIO_DCFG_DCFG8_Msk
#define GPIO_DCFG_DCFG9_Pos                   (9U)
#define GPIO_DCFG_DCFG9_Msk                   (0x1UL << GPIO_DCFG_DCFG9_Pos)                    /*!< 0x00000200 */
#define GPIO_DCFG_DCFG9                       GPIO_DCFG_DCFG9_Msk
#define GPIO_DCFG_DCFG10_Pos                  (10U)
#define GPIO_DCFG_DCFG10_Msk                  (0x1UL << GPIO_DCFG_DCFG10_Pos)                   /*!< 0x00000400 */
#define GPIO_DCFG_DCFG10                      GPIO_DCFG_DCFG10_Msk
#define GPIO_DCFG_DCFG11_Pos                  (11U)
#define GPIO_DCFG_DCFG11_Msk                  (0x1UL << GPIO_DCFG_DCFG11_Pos)                   /*!< 0x00000800 */
#define GPIO_DCFG_DCFG11                      GPIO_DCFG_DCFG11_Msk
#define GPIO_DCFG_DCFG12_Pos                  (12U)
#define GPIO_DCFG_DCFG12_Msk                  (0x1UL << GPIO_DCFG_DCFG12_Pos)                   /*!< 0x00001000 */
#define GPIO_DCFG_DCFG12                      GPIO_DCFG_DCFG12_Msk
#define GPIO_DCFG_DCFG13_Pos                  (13U)
#define GPIO_DCFG_DCFG13_Msk                  (0x1UL << GPIO_DCFG_DCFG13_Pos)                   /*!< 0x00002000 */
#define GPIO_DCFG_DCFG13                      GPIO_DCFG_DCFG13_Msk
/******************  Bits definition for GPIO_IDATA register  *******************/
#define GPIO_IDATA_IDATA0_Pos                 (0U)
#define GPIO_IDATA_IDATA0_Msk                 (0x1UL << GPIO_IDATA_IDATA0_Pos)                  /*!< 0x00000001 */
#define GPIO_IDATA_IDATA0                     GPIO_IDATA_IDATA0_Msk
#define GPIO_IDATA_IDATA1_Pos                 (1U)
#define GPIO_IDATA_IDATA1_Msk                 (0x1UL << GPIO_IDATA_IDATA1_Pos)                  /*!< 0x00000002 */
#define GPIO_IDATA_IDATA1                     GPIO_IDATA_IDATA1_Msk
#define GPIO_IDATA_IDATA2_Pos                 (2U)
#define GPIO_IDATA_IDATA2_Msk                 (0x1UL << GPIO_IDATA_IDATA2_Pos)                  /*!< 0x00000004 */
#define GPIO_IDATA_IDATA2                     GPIO_IDATA_IDATA2_Msk
#define GPIO_IDATA_IDATA3_Pos                 (3U)
#define GPIO_IDATA_IDATA3_Msk                 (0x1UL << GPIO_IDATA_IDATA3_Pos)                  /*!< 0x00000008 */
#define GPIO_IDATA_IDATA3                     GPIO_IDATA_IDATA3_Msk
#define GPIO_IDATA_IDATA4_Pos                 (4U)
#define GPIO_IDATA_IDATA4_Msk                 (0x1UL << GPIO_IDATA_IDATA4_Pos)                  /*!< 0x00000010 */
#define GPIO_IDATA_IDATA4                     GPIO_IDATA_IDATA4_Msk
#define GPIO_IDATA_IDATA5_Pos                 (5U)
#define GPIO_IDATA_IDATA5_Msk                 (0x1UL << GPIO_IDATA_IDATA5_Pos)                  /*!< 0x00000020 */
#define GPIO_IDATA_IDATA5                     GPIO_IDATA_IDATA5_Msk
#define GPIO_IDATA_IDATA6_Pos                 (6U)
#define GPIO_IDATA_IDATA6_Msk                 (0x1UL << GPIO_IDATA_IDATA6_Pos)                  /*!< 0x00000040 */
#define GPIO_IDATA_IDATA6                     GPIO_IDATA_IDATA6_Msk
#define GPIO_IDATA_IDATA7_Pos                 (7U)
#define GPIO_IDATA_IDATA7_Msk                 (0x1UL << GPIO_IDATA_IDATA7_Pos)                  /*!< 0x00000080 */
#define GPIO_IDATA_IDATA7                     GPIO_IDATA_IDATA7_Msk
#define GPIO_IDATA_IDATA8_Pos                 (8U)
#define GPIO_IDATA_IDATA8_Msk                 (0x1UL << GPIO_IDATA_IDATA8_Pos)                  /*!< 0x00000100 */
#define GPIO_IDATA_IDATA8                     GPIO_IDATA_IDATA8_Msk
#define GPIO_IDATA_IDATA9_Pos                 (9U)
#define GPIO_IDATA_IDATA9_Msk                 (0x1UL << GPIO_IDATA_IDATA9_Pos)                  /*!< 0x00000200 */
#define GPIO_IDATA_IDATA9                     GPIO_IDATA_IDATA9_Msk
#define GPIO_IDATA_IDATA10_Pos                (10U)
#define GPIO_IDATA_IDATA10_Msk                (0x1UL << GPIO_IDATA_IDATA10_Pos)                 /*!< 0x00000400 */
#define GPIO_IDATA_IDATA10                    GPIO_IDATA_IDATA10_Msk
#define GPIO_IDATA_IDATA11_Pos                (11U)
#define GPIO_IDATA_IDATA11_Msk                (0x1UL << GPIO_IDATA_IDATA11_Pos)                 /*!< 0x00000800 */
#define GPIO_IDATA_IDATA11                    GPIO_IDATA_IDATA11_Msk
#define GPIO_IDATA_IDATA12_Pos                (12U)
#define GPIO_IDATA_IDATA12_Msk                (0x1UL << GPIO_IDATA_IDATA12_Pos)                 /*!< 0x00001000 */
#define GPIO_IDATA_IDATA12                    GPIO_IDATA_IDATA12_Msk
#define GPIO_IDATA_IDATA13_Pos                (13U)
#define GPIO_IDATA_IDATA13_Msk                (0x1UL << GPIO_IDATA_IDATA13_Pos)                 /*!< 0x00002000 */
#define GPIO_IDATA_IDATA13                    GPIO_IDATA_IDATA13_Msk

/******************  Bits definition for GPIO_ODATA register  *****************/
#define GPIO_ODATA_ODATA0_Pos                 (0U)
#define GPIO_ODATA_ODATA0_Msk                 (0x1UL << GPIO_ODATA_ODATA0_Pos)                  /*!< 0x00000001 */
#define GPIO_ODATA_ODATA0                     GPIO_ODATA_ODATA0_Msk
#define GPIO_ODATA_ODATA1_Pos                 (1U)
#define GPIO_ODATA_ODATA1_Msk                 (0x1UL << GPIO_ODATA_ODATA1_Pos)                  /*!< 0x00000002 */
#define GPIO_ODATA_ODATA1                     GPIO_ODATA_ODATA1_Msk
#define GPIO_ODATA_ODATA2_Pos                 (2U)
#define GPIO_ODATA_ODATA2_Msk                 (0x1UL << GPIO_ODATA_ODATA2_Pos)                  /*!< 0x00000004 */
#define GPIO_ODATA_ODATA2                     GPIO_ODATA_ODATA2_Msk
#define GPIO_ODATA_ODATA3_Pos                 (3U)
#define GPIO_ODATA_ODATA3_Msk                 (0x1UL << GPIO_ODATA_ODATA3_Pos)                  /*!< 0x00000008 */
#define GPIO_ODATA_ODATA3                     GPIO_ODATA_ODATA3_Msk
#define GPIO_ODATA_ODATA4_Pos                 (4U)
#define GPIO_ODATA_ODATA4_Msk                 (0x1UL << GPIO_ODATA_ODATA4_Pos)                  /*!< 0x00000010 */
#define GPIO_ODATA_ODATA4                     GPIO_ODATA_ODATA4_Msk
#define GPIO_ODATA_ODATA5_Pos                 (5U)
#define GPIO_ODATA_ODATA5_Msk                 (0x1UL << GPIO_ODATA_ODATA5_Pos)                  /*!< 0x00000020 */
#define GPIO_ODATA_ODATA5                     GPIO_ODATA_ODATA5_Msk
#define GPIO_ODATA_ODATA6_Pos                 (6U)
#define GPIO_ODATA_ODATA6_Msk                 (0x1UL << GPIO_ODATA_ODATA6_Pos)                  /*!< 0x00000040 */
#define GPIO_ODATA_ODATA6                     GPIO_ODATA_ODATA6_Msk
#define GPIO_ODATA_ODATA7_Pos                 (7U)
#define GPIO_ODATA_ODATA7_Msk                 (0x1UL << GPIO_ODATA_ODATA7_Pos)                  /*!< 0x00000080 */
#define GPIO_ODATA_ODATA7                     GPIO_ODATA_ODATA7_Msk
#define GPIO_ODATA_ODATA8_Pos                 (8U)
#define GPIO_ODATA_ODATA8_Msk                 (0x1UL << GPIO_ODATA_ODATA8_Pos)                  /*!< 0x00000100 */
#define GPIO_ODATA_ODATA8                     GPIO_ODATA_ODATA8_Msk
#define GPIO_ODATA_ODATA9_Pos                 (9U)
#define GPIO_ODATA_ODATA9_Msk                 (0x1UL << GPIO_ODATA_ODATA9_Pos)                  /*!< 0x00000200 */
#define GPIO_ODATA_ODATA9                     GPIO_ODATA_ODATA9_Msk
#define GPIO_ODATA_ODATA10_Pos                (10U)
#define GPIO_ODATA_ODATA10_Msk                (0x1UL << GPIO_ODATA_ODATA10_Pos)                 /*!< 0x00000400 */
#define GPIO_ODATA_ODATA10                    GPIO_ODATA_ODATA10_Msk
#define GPIO_ODATA_ODATA11_Pos                (11U)
#define GPIO_ODATA_ODATA11_Msk                (0x1UL << GPIO_ODATA_ODATA11_Pos)                 /*!< 0x00000800 */
#define GPIO_ODATA_ODATA11                    GPIO_ODATA_ODATA11_Msk
#define GPIO_ODATA_ODATA12_Pos                (12U)
#define GPIO_ODATA_ODATA12_Msk                (0x1UL << GPIO_ODATA_ODATA12_Pos)                 /*!< 0x00001000 */
#define GPIO_ODATA_ODATA12                    GPIO_ODATA_ODATA12_Msk
#define GPIO_ODATA_ODATA13_Pos                (13U)
#define GPIO_ODATA_ODATA13_Msk                (0x1UL << GPIO_ODATA_ODATA13_Pos)                 /*!< 0x00002000 */
#define GPIO_ODATA_ODATA13                    GPIO_ODATA_ODATA13_Msk

/******************  Bits definition for GPIO_BSC register  ******************/
#define GPIO_BSC_BS0_Pos                      (0U)
#define GPIO_BSC_BS0_Msk                      (0x1UL << GPIO_BSC_BS0_Pos)                       /*!< 0x00000001 */
#define GPIO_BSC_BS0                          GPIO_BSC_BS0_Msk
#define GPIO_BSC_BS1_Pos                      (1U)
#define GPIO_BSC_BS1_Msk                      (0x1UL << GPIO_BSC_BS1_Pos)                       /*!< 0x00000002 */
#define GPIO_BSC_BS1                          GPIO_BSC_BS1_Msk
#define GPIO_BSC_BS2_Pos                      (2U)
#define GPIO_BSC_BS2_Msk                      (0x1UL << GPIO_BSC_BS2_Pos)                       /*!< 0x00000004 */
#define GPIO_BSC_BS2                          GPIO_BSC_BS2_Msk
#define GPIO_BSC_BS3_Pos                      (3U)
#define GPIO_BSC_BS3_Msk                      (0x1UL << GPIO_BSC_BS3_Pos)                       /*!< 0x00000008 */
#define GPIO_BSC_BS3                          GPIO_BSC_BS3_Msk
#define GPIO_BSC_BS4_Pos                      (4U)
#define GPIO_BSC_BS4_Msk                      (0x1UL << GPIO_BSC_BS4_Pos)                       /*!< 0x00000010 */
#define GPIO_BSC_BS4                          GPIO_BSC_BS4_Msk
#define GPIO_BSC_BS5_Pos                      (5U)
#define GPIO_BSC_BS5_Msk                      (0x1UL << GPIO_BSC_BS5_Pos)                       /*!< 0x00000020 */
#define GPIO_BSC_BS5                          GPIO_BSC_BS5_Msk
#define GPIO_BSC_BS6_Pos                      (6U)
#define GPIO_BSC_BS6_Msk                      (0x1UL << GPIO_BSC_BS6_Pos)                       /*!< 0x00000040 */
#define GPIO_BSC_BS6                          GPIO_BSC_BS6_Msk
#define GPIO_BSC_BS7_Pos                      (7U)
#define GPIO_BSC_BS7_Msk                      (0x1UL << GPIO_BSC_BS7_Pos)                       /*!< 0x00000080 */
#define GPIO_BSC_BS7                          GPIO_BSC_BS7_Msk
#define GPIO_BSC_BS8_Pos                      (8U)
#define GPIO_BSC_BS8_Msk                      (0x1UL << GPIO_BSC_BS8_Pos)                       /*!< 0x00000100 */
#define GPIO_BSC_BS8                          GPIO_BSC_BS8_Msk
#define GPIO_BSC_BS9_Pos                      (9U)
#define GPIO_BSC_BS9_Msk                      (0x1UL << GPIO_BSC_BS9_Pos)                       /*!< 0x00000200 */
#define GPIO_BSC_BS9                          GPIO_BSC_BS9_Msk
#define GPIO_BSC_BS10_Pos                     (10U)
#define GPIO_BSC_BS10_Msk                     (0x1UL << GPIO_BSC_BS10_Pos)                      /*!< 0x00000400 */
#define GPIO_BSC_BS10                         GPIO_BSC_BS10_Msk
#define GPIO_BSC_BS11_Pos                     (11U)
#define GPIO_BSC_BS11_Msk                     (0x1UL << GPIO_BSC_BS11_Pos)                      /*!< 0x00000800 */
#define GPIO_BSC_BS11                         GPIO_BSC_BS11_Msk
#define GPIO_BSC_BS12_Pos                     (12U)
#define GPIO_BSC_BS12_Msk                     (0x1UL << GPIO_BSC_BS12_Pos)                      /*!< 0x00001000 */
#define GPIO_BSC_BS12                         GPIO_BSC_BS12_Msk
#define GPIO_BSC_BS13_Pos                     (13U)
#define GPIO_BSC_BS13_Msk                     (0x1UL << GPIO_BSC_BS13_Pos)                      /*!< 0x00002000 */
#define GPIO_BSC_BS13                         GPIO_BSC_BS13_Msk
#define GPIO_BSC_BC0_Pos                      (16U)
#define GPIO_BSC_BC0_Msk                      (0x1UL << GPIO_BSC_BC0_Pos)                       /*!< 0x00010000 */
#define GPIO_BSC_BC0                          GPIO_BSC_BC0_Msk
#define GPIO_BSC_BC1_Pos                      (17U)
#define GPIO_BSC_BC1_Msk                      (0x1UL << GPIO_BSC_BC1_Pos)                       /*!< 0x00020000 */
#define GPIO_BSC_BC1                          GPIO_BSC_BC1_Msk
#define GPIO_BSC_BC2_Pos                      (18U)
#define GPIO_BSC_BC2_Msk                      (0x1UL << GPIO_BSC_BC2_Pos)                       /*!< 0x00040000 */
#define GPIO_BSC_BC2                          GPIO_BSC_BC2_Msk
#define GPIO_BSC_BC3_Pos                      (19U)
#define GPIO_BSC_BC3_Msk                      (0x1UL << GPIO_BSC_BC3_Pos)                       /*!< 0x00080000 */
#define GPIO_BSC_BC3                          GPIO_BSC_BC3_Msk
#define GPIO_BSC_BC4_Pos                      (20U)
#define GPIO_BSC_BC4_Msk                      (0x1UL << GPIO_BSC_BC4_Pos)                       /*!< 0x00100000 */
#define GPIO_BSC_BC4                          GPIO_BSC_BC4_Msk
#define GPIO_BSC_BC5_Pos                      (21U)
#define GPIO_BSC_BC5_Msk                      (0x1UL << GPIO_BSC_BC5_Pos)                       /*!< 0x00200000 */
#define GPIO_BSC_BC5                          GPIO_BSC_BC5_Msk
#define GPIO_BSC_BC6_Pos                      (22U)
#define GPIO_BSC_BC6_Msk                      (0x1UL << GPIO_BSC_BC6_Pos)                       /*!< 0x00400000 */
#define GPIO_BSC_BC6                          GPIO_BSC_BC6_Msk
#define GPIO_BSC_BC7_Pos                      (23U)
#define GPIO_BSC_BC7_Msk                      (0x1UL << GPIO_BSC_BC7_Pos)                       /*!< 0x00800000 */
#define GPIO_BSC_BC7                          GPIO_BSC_BC7_Msk
#define GPIO_BSC_BC8_Pos                      (24U)
#define GPIO_BSC_BC8_Msk                      (0x1UL << GPIO_BSC_BC8_Pos)                       /*!< 0x01000000 */
#define GPIO_BSC_BC8                          GPIO_BSC_BC8_Msk
#define GPIO_BSC_BC9_Pos                      (25U)
#define GPIO_BSC_BC9_Msk                      (0x1UL << GPIO_BSC_BC9_Pos)                       /*!< 0x02000000 */
#define GPIO_BSC_BC9                          GPIO_BSC_BC9_Msk
#define GPIO_BSC_BC10_Pos                     (26U)
#define GPIO_BSC_BC10_Msk                     (0x1UL << GPIO_BSC_BC10_Pos)                      /*!< 0x04000000 */
#define GPIO_BSC_BC10                         GPIO_BSC_BC10_Msk
#define GPIO_BSC_BC11_Pos                     (27U)
#define GPIO_BSC_BC11_Msk                     (0x1UL << GPIO_BSC_BC11_Pos)                      /*!< 0x08000000 */
#define GPIO_BSC_BC11                         GPIO_BSC_BC11_Msk
#define GPIO_BSC_BC12_Pos                     (28U)
#define GPIO_BSC_BC12_Msk                     (0x1UL << GPIO_BSC_BC12_Pos)                      /*!< 0x10000000 */
#define GPIO_BSC_BC12                         GPIO_BSC_BC12_Msk
#define GPIO_BSC_BC13_Pos                     (29U)
#define GPIO_BSC_BC13_Msk                     (0x1UL << GPIO_BSC_BC13_Pos)                      /*!< 0x20000000 */
#define GPIO_BSC_BC13                         GPIO_BSC_BC13_Msk

/******************  Bits definition for GPIO_RST register  ******************/
#define GPIO_RST_BC0_Pos                      (0U)
#define GPIO_RST_BC0_Msk                      (0x1UL << GPIO_RST_BC0_Pos)                       /*!< 0x00000001 */
#define GPIO_RST_BC0                          GPIO_RST_BC0_Msk
#define GPIO_RST_BC1_Pos                      (1U)
#define GPIO_RST_BC1_Msk                      (0x1UL << GPIO_RST_BC1_Pos)                       /*!< 0x00000002 */
#define GPIO_RST_BC1                          GPIO_RST_BC1_Msk
#define GPIO_RST_BC2_Pos                      (2U)
#define GPIO_RST_BC2_Msk                      (0x1UL << GPIO_RST_BC2_Pos)                       /*!< 0x00000004 */
#define GPIO_RST_BC2                          GPIO_RST_BC2_Msk
#define GPIO_RST_BC3_Pos                      (3U)
#define GPIO_RST_BC3_Msk                      (0x1UL << GPIO_RST_BC3_Pos)                       /*!< 0x00000008 */
#define GPIO_RST_BC3                          GPIO_RST_BC3_Msk
#define GPIO_RST_BC4_Pos                      (4U)
#define GPIO_RST_BC4_Msk                      (0x1UL << GPIO_RST_BC4_Pos)                       /*!< 0x00000010 */
#define GPIO_RST_BC4                          GPIO_RST_BC4_Msk
#define GPIO_RST_BC5_Pos                      (5U)
#define GPIO_RST_BC5_Msk                      (0x1UL << GPIO_RST_BC5_Pos)                       /*!< 0x00000020 */
#define GPIO_RST_BC5                          GPIO_RST_BC5_Msk
#define GPIO_RST_BC6_Pos                      (6U)
#define GPIO_RST_BC6_Msk                      (0x1UL << GPIO_RST_BC6_Pos)                       /*!< 0x00000040 */
#define GPIO_RST_BC6                          GPIO_RST_BC6_Msk
#define GPIO_RST_BC7_Pos                      (7U)
#define GPIO_RST_BC7_Msk                      (0x1UL << GPIO_RST_BC7_Pos)                       /*!< 0x00000080 */
#define GPIO_RST_BC7                          GPIO_RST_BC7_Msk
#define GPIO_RST_BC8_Pos                      (8U)
#define GPIO_RST_BC8_Msk                      (0x1UL << GPIO_RST_BC8_Pos)                       /*!< 0x00000100 */
#define GPIO_RST_BC8                          GPIO_RST_BC8_Msk
#define GPIO_RST_BC9_Pos                      (9U)
#define GPIO_RST_BC9_Msk                      (0x1UL << GPIO_RST_BC9_Pos)                       /*!< 0x00000200 */
#define GPIO_RST_BC9                          GPIO_RST_BC9_Msk
#define GPIO_RST_BC10_Pos                     (10U)
#define GPIO_RST_BC10_Msk                     (0x1UL << GPIO_RST_BC10_Pos)                      /*!< 0x00000400 */
#define GPIO_RST_BC10                         GPIO_RST_BC10_Msk
#define GPIO_RST_BC11_Pos                     (11U)
#define GPIO_RST_BC11_Msk                     (0x1UL << GPIO_RST_BC11_Pos)                      /*!< 0x00000800 */
#define GPIO_RST_BC11                         GPIO_RST_BC11_Msk
#define GPIO_RST_BC12_Pos                     (12U)
#define GPIO_RST_BC12_Msk                     (0x1UL << GPIO_RST_BC12_Pos)                      /*!< 0x00001000 */
#define GPIO_RST_BC12                         GPIO_RST_BC12_Msk
#define GPIO_RST_BC13_Pos                     (13U)
#define GPIO_RST_BC13_Msk                     (0x1UL << GPIO_RST_BC13_Pos)                      /*!< 0x00002000 */
#define GPIO_RST_BC13                         GPIO_RST_BC13_Msk

/******************  Bits definition for GPIO_LOCK register  ******************/
#define GPIO_LOCK_LOCKKEY_Pos                 (0U)
#define GPIO_LOCK_LOCKKEY_Msk                 (0xFFFFFFFFUL << GPIO_LOCK_LOCKKEY_Pos)           /*!< 0xFFFFFFFF */
#define GPIO_LOCK_LOCKKEY                     GPIO_LOCK_LOCKKEY_Msk

/****************** Bit definition for GPIO_ALFSEL0 register ******************/
#define GPIO_ALFSEL0_ALFSEL0_Pos              (0U)
#define GPIO_ALFSEL0_ALFSEL0_Msk              (0x7UL << GPIO_ALFSEL0_ALFSEL0_Pos)               /*!< 0x00000007 */
#define GPIO_ALFSEL0_ALFSEL0                  GPIO_ALFSEL0_ALFSEL0_Msk
#define GPIO_ALFSEL0_ALFSEL0_0                (0x1UL << GPIO_ALFSEL0_ALFSEL0_Pos)               /*!< 0x00000001 */
#define GPIO_ALFSEL0_ALFSEL0_1                (0x2UL << GPIO_ALFSEL0_ALFSEL0_Pos)               /*!< 0x00000002 */
#define GPIO_ALFSEL0_ALFSEL0_2                (0x4UL << GPIO_ALFSEL0_ALFSEL0_Pos)               /*!< 0x00000004 */
#define GPIO_ALFSEL0_ALFSEL1_Pos              (3U)
#define GPIO_ALFSEL0_ALFSEL1_Msk              (0x7UL << GPIO_ALFSEL0_ALFSEL1_Pos)               /*!< 0x00000038 */
#define GPIO_ALFSEL0_ALFSEL1                  GPIO_ALFSEL0_ALFSEL1_Msk
#define GPIO_ALFSEL0_ALFSEL1_0                (0x1UL << GPIO_ALFSEL0_ALFSEL1_Pos)               /*!< 0x00000008 */
#define GPIO_ALFSEL0_ALFSEL1_1                (0x2UL << GPIO_ALFSEL0_ALFSEL1_Pos)               /*!< 0x00000010 */
#define GPIO_ALFSEL0_ALFSEL1_2                (0x4UL << GPIO_ALFSEL0_ALFSEL1_Pos)               /*!< 0x00000020 */
#define GPIO_ALFSEL0_ALFSEL2_Pos              (6U)
#define GPIO_ALFSEL0_ALFSEL2_Msk              (0x7UL << GPIO_ALFSEL0_ALFSEL2_Pos)               /*!< 0x000001C0 */
#define GPIO_ALFSEL0_ALFSEL2                  GPIO_ALFSEL0_ALFSEL2_Msk
#define GPIO_ALFSEL0_ALFSEL2_0                (0x1UL << GPIO_ALFSEL0_ALFSEL2_Pos)               /*!< 0x00000040 */
#define GPIO_ALFSEL0_ALFSEL2_1                (0x2UL << GPIO_ALFSEL0_ALFSEL2_Pos)               /*!< 0x00000080 */
#define GPIO_ALFSEL0_ALFSEL2_2                (0x4UL << GPIO_ALFSEL0_ALFSEL2_Pos)               /*!< 0x00000100 */
#define GPIO_ALFSEL0_ALFSEL3_Pos              (9U)
#define GPIO_ALFSEL0_ALFSEL3_Msk              (0x7UL << GPIO_ALFSEL0_ALFSEL3_Pos)               /*!< 0x00000E00 */
#define GPIO_ALFSEL0_ALFSEL3                  GPIO_ALFSEL0_ALFSEL3_Msk
#define GPIO_ALFSEL0_ALFSEL3_0                (0x1UL << GPIO_ALFSEL0_ALFSEL3_Pos)               /*!< 0x00000200 */
#define GPIO_ALFSEL0_ALFSEL3_1                (0x2UL << GPIO_ALFSEL0_ALFSEL3_Pos)               /*!< 0x00000400 */
#define GPIO_ALFSEL0_ALFSEL3_2                (0x4UL << GPIO_ALFSEL0_ALFSEL3_Pos)               /*!< 0x00000800 */
#define GPIO_ALFSEL0_ALFSEL4_Pos              (12U)
#define GPIO_ALFSEL0_ALFSEL4_Msk              (0x7UL << GPIO_ALFSEL0_ALFSEL4_Pos)               /*!< 0x00007000 */
#define GPIO_ALFSEL0_ALFSEL4                  GPIO_ALFSEL0_ALFSEL4_Msk
#define GPIO_ALFSEL0_ALFSEL4_0                (0x1UL << GPIO_ALFSEL0_ALFSEL4_Pos)               /*!< 0x00001000 */
#define GPIO_ALFSEL0_ALFSEL4_1                (0x2UL << GPIO_ALFSEL0_ALFSEL4_Pos)               /*!< 0x00002000 */
#define GPIO_ALFSEL0_ALFSEL4_2                (0x4UL << GPIO_ALFSEL0_ALFSEL4_Pos)               /*!< 0x00004000 */
#define GPIO_ALFSEL0_ALFSEL5_Pos              (15U)
#define GPIO_ALFSEL0_ALFSEL5_Msk              (0x7UL << GPIO_ALFSEL0_ALFSEL5_Pos)               /*!< 0x00038000 */
#define GPIO_ALFSEL0_ALFSEL5                  GPIO_ALFSEL0_ALFSEL5_Msk
#define GPIO_ALFSEL0_ALFSEL5_0                (0x1UL << GPIO_ALFSEL0_ALFSEL5_Pos)               /*!< 0x00008000 */
#define GPIO_ALFSEL0_ALFSEL5_1                (0x2UL << GPIO_ALFSEL0_ALFSEL5_Pos)               /*!< 0x00010000 */
#define GPIO_ALFSEL0_ALFSEL5_2                (0x4UL << GPIO_ALFSEL0_ALFSEL5_Pos)               /*!< 0x00020000 */
#define GPIO_ALFSEL0_ALFSEL6_Pos              (18U)
#define GPIO_ALFSEL0_ALFSEL6_Msk              (0x7UL << GPIO_ALFSEL0_ALFSEL6_Pos)               /*!< 0x001C0000 */
#define GPIO_ALFSEL0_ALFSEL6                  GPIO_ALFSEL0_ALFSEL6_Msk
#define GPIO_ALFSEL0_ALFSEL6_0                (0x1UL << GPIO_ALFSEL0_ALFSEL6_Pos)               /*!< 0x00040000 */
#define GPIO_ALFSEL0_ALFSEL6_1                (0x2UL << GPIO_ALFSEL0_ALFSEL6_Pos)               /*!< 0x00080000 */
#define GPIO_ALFSEL0_ALFSEL6_2                (0x4UL << GPIO_ALFSEL0_ALFSEL6_Pos)               /*!< 0x00100000 */
#define GPIO_ALFSEL0_ALFSEL7_Pos              (21U)
#define GPIO_ALFSEL0_ALFSEL7_Msk              (0x7UL << GPIO_ALFSEL0_ALFSEL7_Pos)               /*!< 0x00E00000 */
#define GPIO_ALFSEL0_ALFSEL7                  GPIO_ALFSEL0_ALFSEL7_Msk
#define GPIO_ALFSEL0_ALFSEL7_0                (0x1UL << GPIO_ALFSEL0_ALFSEL7_Pos)               /*!< 0x00200000 */
#define GPIO_ALFSEL0_ALFSEL7_1                (0x2UL << GPIO_ALFSEL0_ALFSEL7_Pos)               /*!< 0x00400000 */
#define GPIO_ALFSEL0_ALFSEL7_2                (0x4UL << GPIO_ALFSEL0_ALFSEL7_Pos)               /*!< 0x00800000 */
#define GPIO_ALFSEL0_ALFSEL8_Pos              (24U)
#define GPIO_ALFSEL0_ALFSEL8_Msk              (0x7UL << GPIO_ALFSEL0_ALFSEL8_Pos)               /*!< 0x07000000 */
#define GPIO_ALFSEL0_ALFSEL8                  GPIO_ALFSEL0_ALFSEL8_Msk
#define GPIO_ALFSEL0_ALFSEL8_0                (0x1UL << GPIO_ALFSEL0_ALFSEL8_Pos)               /*!< 0x01000000 */
#define GPIO_ALFSEL0_ALFSEL8_1                (0x2UL << GPIO_ALFSEL0_ALFSEL8_Pos)               /*!< 0x02000000 */
#define GPIO_ALFSEL0_ALFSEL8_2                (0x4UL << GPIO_ALFSEL0_ALFSEL8_Pos)               /*!< 0x04000000 */
#define GPIO_ALFSEL0_ALFSEL9_Pos              (27U)
#define GPIO_ALFSEL0_ALFSEL9_Msk              (0x7UL << GPIO_ALFSEL0_ALFSEL9_Pos)               /*!< 0x38000000 */
#define GPIO_ALFSEL0_ALFSEL9                  GPIO_ALFSEL0_ALFSEL9_Msk
#define GPIO_ALFSEL0_ALFSEL9_0                (0x1UL << GPIO_ALFSEL0_ALFSEL9_Pos)               /*!< 0x08000000 */
#define GPIO_ALFSEL0_ALFSEL9_1                (0x2UL << GPIO_ALFSEL0_ALFSEL9_Pos)               /*!< 0x10000000 */
#define GPIO_ALFSEL0_ALFSEL9_2                (0x4UL << GPIO_ALFSEL0_ALFSEL9_Pos)               /*!< 0x20000000 */

/****************** Bit definition for GPIO_ALFSEL1 register ******************/
#define GPIO_ALFSEL1_ALFSEL8_Pos              (0U)
#define GPIO_ALFSEL1_ALFSEL8_Msk              (0x7UL << GPIO_ALFSEL1_ALFSEL8_Pos)               /*!< 0x00000007 */
#define GPIO_ALFSEL1_ALFSEL8                  GPIO_ALFSEL1_ALFSEL8_Msk
#define GPIO_ALFSEL1_ALFSEL8_0                (0x1UL << GPIO_ALFSEL1_ALFSEL8_Pos)               /*!< 0x00000001 */
#define GPIO_ALFSEL1_ALFSEL8_1                (0x2UL << GPIO_ALFSEL1_ALFSEL8_Pos)               /*!< 0x00000002 */
#define GPIO_ALFSEL1_ALFSEL8_2                (0x4UL << GPIO_ALFSEL1_ALFSEL8_Pos)               /*!< 0x00000004 */
#define GPIO_ALFSEL1_ALFSEL9_Pos              (3U)
#define GPIO_ALFSEL1_ALFSEL9_Msk              (0x7UL << GPIO_ALFSEL1_ALFSEL9_Pos)               /*!< 0x00000038 */
#define GPIO_ALFSEL1_ALFSEL9                  GPIO_ALFSEL1_ALFSEL9_Msk
#define GPIO_ALFSEL1_ALFSEL9_0                (0x1UL << GPIO_ALFSEL1_ALFSEL9_Pos)               /*!< 0x00000008 */
#define GPIO_ALFSEL1_ALFSEL9_1                (0x2UL << GPIO_ALFSEL1_ALFSEL9_Pos)               /*!< 0x00000010 */
#define GPIO_ALFSEL1_ALFSEL9_2                (0x4UL << GPIO_ALFSEL1_ALFSEL9_Pos)               /*!< 0x00000020 */
#define GPIO_ALFSEL1_ALFSEL10_Pos             (6U)
#define GPIO_ALFSEL1_ALFSEL10_Msk             (0x7UL << GPIO_ALFSEL1_ALFSEL10_Pos)              /*!< 0x000001C0 */
#define GPIO_ALFSEL1_ALFSEL10                 GPIO_ALFSEL1_ALFSEL10_Msk
#define GPIO_ALFSEL1_ALFSEL10_0               (0x1UL << GPIO_ALFSEL1_ALFSEL10_Pos)              /*!< 0x00000040 */
#define GPIO_ALFSEL1_ALFSEL10_1               (0x2UL << GPIO_ALFSEL1_ALFSEL10_Pos)              /*!< 0x00000080 */
#define GPIO_ALFSEL1_ALFSEL10_2               (0x4UL << GPIO_ALFSEL1_ALFSEL10_Pos)              /*!< 0x00000100 */
#define GPIO_ALFSEL1_ALFSEL11_Pos             (9U)
#define GPIO_ALFSEL1_ALFSEL11_Msk             (0x7UL << GPIO_ALFSEL1_ALFSEL11_Pos)              /*!< 0x00000E00 */
#define GPIO_ALFSEL1_ALFSEL11                 GPIO_ALFSEL1_ALFSEL11_Msk
#define GPIO_ALFSEL1_ALFSEL11_0               (0x1UL << GPIO_ALFSEL1_ALFSEL11_Pos)              /*!< 0x00000200 */
#define GPIO_ALFSEL1_ALFSEL11_1               (0x2UL << GPIO_ALFSEL1_ALFSEL11_Pos)              /*!< 0x00000400 */
#define GPIO_ALFSEL1_ALFSEL11_2               (0x4UL << GPIO_ALFSEL1_ALFSEL11_Pos)              /*!< 0x00000800 */
#define GPIO_ALFSEL1_ALFSEL12_Pos             (12U)
#define GPIO_ALFSEL1_ALFSEL12_Msk             (0x7UL << GPIO_ALFSEL1_ALFSEL12_Pos)              /*!< 0x00007000 */
#define GPIO_ALFSEL1_ALFSEL12                 GPIO_ALFSEL1_ALFSEL12_Msk
#define GPIO_ALFSEL1_ALFSEL12_0               (0x1UL << GPIO_ALFSEL1_ALFSEL12_Pos)              /*!< 0x00001000 */
#define GPIO_ALFSEL1_ALFSEL12_1               (0x2UL << GPIO_ALFSEL1_ALFSEL12_Pos)              /*!< 0x00002000 */
#define GPIO_ALFSEL1_ALFSEL12_2               (0x4UL << GPIO_ALFSEL1_ALFSEL12_Pos)              /*!< 0x00004000 */
#define GPIO_ALFSEL1_ALFSEL13_Pos             (15U)
#define GPIO_ALFSEL1_ALFSEL13_Msk             (0x7UL << GPIO_ALFSEL1_ALFSEL13_Pos)              /*!< 0x00380000 */
#define GPIO_ALFSEL1_ALFSEL13                 GPIO_ALFSEL1_ALFSEL13_Msk
#define GPIO_ALFSEL1_ALFSEL13_0               (0x1UL << GPIO_ALFSEL1_ALFSEL13_Pos)              /*!< 0x00080000 */
#define GPIO_ALFSEL1_ALFSEL13_1               (0x2UL << GPIO_ALFSEL1_ALFSEL13_Pos)              /*!< 0x00100000 */
#define GPIO_ALFSEL1_ALFSEL13_2               (0x4UL << GPIO_ALFSEL1_ALFSEL13_Pos)              /*!< 0x00200000 */
#define GPIO_ALFSEL1_ALFSEL14_Pos             (18U)
#define GPIO_ALFSEL1_ALFSEL14_Msk             (0x7UL << GPIO_ALFSEL1_ALFSEL14_Pos)              /*!< 0x01C00000 */
#define GPIO_ALFSEL1_ALFSEL14                 GPIO_ALFSEL1_ALFSEL14_Msk
#define GPIO_ALFSEL1_ALFSEL14_0               (0x1UL << GPIO_ALFSEL1_ALFSEL14_Pos)              /*!< 0x00400000 */
#define GPIO_ALFSEL1_ALFSEL14_1               (0x2UL << GPIO_ALFSEL1_ALFSEL14_Pos)              /*!< 0x00800000 */
#define GPIO_ALFSEL1_ALFSEL14_2               (0x4UL << GPIO_ALFSEL1_ALFSEL14_Pos)              /*!< 0x01000000 */
#define GPIO_ALFSEL1_ALFSEL15_Pos             (21U)
#define GPIO_ALFSEL1_ALFSEL15_Msk             (0x7UL << GPIO_ALFSEL1_ALFSEL15_Pos)              /*!< 0x0E000000 */
#define GPIO_ALFSEL1_ALFSEL15                 GPIO_ALFSEL1_ALFSEL15_Msk
#define GPIO_ALFSEL1_ALFSEL15_0               (0x1UL << GPIO_ALFSEL1_ALFSEL15_Pos)              /*!< 0x02000000 */
#define GPIO_ALFSEL1_ALFSEL15_1               (0x2UL << GPIO_ALFSEL1_ALFSEL15_Pos)              /*!< 0x04000000 */
#define GPIO_ALFSEL1_ALFSEL15_2               (0x4UL << GPIO_ALFSEL1_ALFSEL15_Pos)              /*!< 0x08000000 */

/******************  Bits definition for GPIO_FLT register  ****************/
#define GPIO_FLT_FLTEN6_Pos                   (6U)
#define GPIO_FLT_FLTEN6_Msk                   (0x1UL << GPIO_FLT_FLTEN6_Pos)                    /*!< 0x00000040 */
#define GPIO_FLT_FLTEN6                       GPIO_FLT_FLTEN6_Msk

/******************************************************************************/
/*                                                                            */
/*                        General timer control                               */
/*                                                                            */
/******************************************************************************/
/*******************  Bit definition for GTMR_CTRL1 register  *****************/
#define GTMR_CTRL1_CNTEN_Pos                  (0U)
#define GTMR_CTRL1_CNTEN_Msk                  (0x1UL << GTMR_CTRL1_CNTEN_Pos)
#define GTMR_CTRL1_CNTEN                      GTMR_CTRL1_CNTEN_Msk
#define GTMR_CTRL1_UD_Pos                     (1U)
#define GTMR_CTRL1_UD_Msk                     (0x1UL << GTMR_CTRL1_UD_Pos)
#define GTMR_CTRL1_UD                         GTMR_CTRL1_UD_Msk
#define GTMR_CTRL1_URSSEL_Pos                 (2U)
#define GTMR_CTRL1_URSSEL_Msk                 (0x1UL << GTMR_CTRL1_URSSEL_Pos)
#define GTMR_CTRL1_URSSEL                     GTMR_CTRL1_URSSEL_Msk
#define GTMR_CTRL1_SPMEN_Pos                  (3U)
#define GTMR_CTRL1_SPMEN_Msk                  (0x1UL << GTMR_CTRL1_SPMEN_Pos)
#define GTMR_CTRL1_SPMEN                      GTMR_CTRL1_SPMEN_Msk
#define GTMR_CTRL1_CNTDIR_Pos                 (4U)
#define GTMR_CTRL1_CNTDIR_Msk                 (0x1UL << GTMR_CTRL1_CNTDIR_Pos)
#define GTMR_CTRL1_CNTDIR                     GTMR_CTRL1_CNTDIR_Msk
#define GTMR_CTRL1_CAMSEL_Pos                 (5U)
#define GTMR_CTRL1_CAMSEL_Msk                 (0x3UL << GTMR_CTRL1_CAMSEL_Pos)
#define GTMR_CTRL1_CAMSEL                     GTMR_CTRL1_CAMSEL_Msk
#define GTMR_CTRL1_CAMSEL_0                   (0x1UL << GTMR_CTRL1_CAMSEL_Pos)
#define GTMR_CTRL1_CAMSEL_1                   (0x2UL << GTMR_CTRL1_CAMSEL_Pos)
#define GTMR_CTRL1_ARPEN_Pos                  (7U)
#define GTMR_CTRL1_ARPEN_Msk                  (0x1UL << GTMR_CTRL1_ARPEN_Pos)
#define GTMR_CTRL1_ARPEN                      GTMR_CTRL1_ARPEN_Msk
#define GTMR_CTRL1_CLKDIV_Pos                 (8U)
#define GTMR_CTRL1_CLKDIV_Msk                 (0x3UL << GTMR_CTRL1_CLKDIV_Pos)
#define GTMR_CTRL1_CLKDIV                     GTMR_CTRL1_CLKDIV_Msk
#define GTMR_CTRL1_CLKDIV_0                   (0x1UL << GTMR_CTRL1_CLKDIV_Pos)
#define GTMR_CTRL1_CLKDIV_1                   (0x2UL << GTMR_CTRL1_CLKDIV_Pos)

/*******************  Bit definition for GTMR_CTRL2 register  *****************/
#define GTMR_CTRL2_CCDSEL_Pos                 (3U)
#define GTMR_CTRL2_CCDSEL_Msk                 (0x1UL << GTMR_CTRL2_CCDSEL_Pos)
#define GTMR_CTRL2_CCDSEL                     GTMR_CTRL2_CCDSEL_Msk
#define GTMR_CTRL2_MMSEL_Pos                  (4U)
#define GTMR_CTRL2_MMSEL_Msk                  (0x7UL << GTMR_CTRL2_MMSEL_Pos)
#define GTMR_CTRL2_MMSEL                      GTMR_CTRL2_MMSEL_Msk
#define GTMR_CTRL2_MMSEL_0                    (0x1UL << GTMR_CTRL2_MMSEL_Pos)
#define GTMR_CTRL2_MMSEL_1                    (0x2UL << GTMR_CTRL2_MMSEL_Pos)
#define GTMR_CTRL2_MMSEL_2                    (0x4UL << GTMR_CTRL2_MMSEL_Pos)
#define GTMR_CTRL2_TI0SEL_Pos                 (7U)
#define GTMR_CTRL2_TI0SEL_Msk                 (0x1UL << GTMR_CTRL2_TI0SEL_Pos)
#define GTMR_CTRL2_TI0SEL                     GTMR_CTRL2_TI0SEL_Msk

/*******************  Bit definition for GTMR_SMCTRL register  ****************/
#define GTMR_SMCTRL_SMFSEL_Pos                (0U)
#define GTMR_SMCTRL_SMFSEL_Msk                (0x7UL << GTMR_SMCTRL_SMFSEL_Pos)
#define GTMR_SMCTRL_SMFSEL                    GTMR_SMCTRL_SMFSEL_Msk
#define GTMR_SMCTRL_SMFSEL_0                  (0x1UL << GTMR_SMCTRL_SMFSEL_Pos)
#define GTMR_SMCTRL_SMFSEL_1                  (0x2UL << GTMR_SMCTRL_SMFSEL_Pos)
#define GTMR_SMCTRL_SMFSEL_2                  (0x4UL << GTMR_SMCTRL_SMFSEL_Pos)
#define GTMR_SMCTRL_TRGSEL_Pos                (4U)
#define GTMR_SMCTRL_TRGSEL_Msk                (0x7UL << GTMR_SMCTRL_TRGSEL_Pos)
#define GTMR_SMCTRL_TRGSEL                    GTMR_SMCTRL_TRGSEL_Msk
#define GTMR_SMCTRL_TRGSEL_0                  (0x1UL << GTMR_SMCTRL_TRGSEL_Pos)
#define GTMR_SMCTRL_TRGSEL_1                  (0x2UL << GTMR_SMCTRL_TRGSEL_Pos)
#define GTMR_SMCTRL_TRGSEL_2                  (0x4UL << GTMR_SMCTRL_TRGSEL_Pos)
#define GTMR_SMCTRL_MSMEN_Pos                 (7U)
#define GTMR_SMCTRL_MSMEN_Msk                 (0x1UL << GTMR_SMCTRL_MSMEN_Pos)
#define GTMR_SMCTRL_MSMEN                     GTMR_SMCTRL_MSMEN_Msk
#define GTMR_SMCTRL_ETFCFG_Pos                (8U)
#define GTMR_SMCTRL_ETFCFG_Msk                (0xFUL << GTMR_SMCTRL_ETFCFG_Pos)
#define GTMR_SMCTRL_ETFCFG                    GTMR_SMCTRL_ETFCFG_Msk
#define GTMR_SMCTRL_ETFCFG_0                  (0x1UL << GTMR_SMCTRL_ETFCFG_Pos)
#define GTMR_SMCTRL_ETFCFG_1                  (0x2UL << GTMR_SMCTRL_ETFCFG_Pos)
#define GTMR_SMCTRL_ETFCFG_2                  (0x4UL << GTMR_SMCTRL_ETFCFG_Pos)
#define GTMR_SMCTRL_ETFCFG_3                  (0x8UL << GTMR_SMCTRL_ETFCFG_Pos)
#define GTMR_SMCTRL_ETPCFG_Pos                (12U)
#define GTMR_SMCTRL_ETPCFG_Msk                (0x3UL << GTMR_SMCTRL_ETPCFG_Pos)
#define GTMR_SMCTRL_ETPCFG                    GTMR_SMCTRL_ETPCFG_Msk
#define GTMR_SMCTRL_ETPCFG_0                  (0x1UL << GTMR_SMCTRL_ETPCFG_Pos)
#define GTMR_SMCTRL_ETPCFG_1                  (0x2UL << GTMR_SMCTRL_ETPCFG_Pos)
#define GTMR_SMCTRL_ECEN_Pos                  (14U)
#define GTMR_SMCTRL_ECEN_Msk                  (0x1UL << GTMR_SMCTRL_ECEN_Pos)
#define GTMR_SMCTRL_ECEN                      GTMR_SMCTRL_ECEN_Msk
#define GTMR_SMCTRL_ETPOL_Pos                 (15U)
#define GTMR_SMCTRL_ETPOL_Msk                 (0x1UL << GTMR_SMCTRL_ETPOL_Pos)
#define GTMR_SMCTRL_ETPOL                     GTMR_SMCTRL_ETPOL_Msk

/*******************  Bit definition for GTMR_DIEN register  ******************/
#define GTMR_DIEN_UIEN_Pos                    (0U)
#define GTMR_DIEN_UIEN_Msk                    (0x1UL << GTMR_DIEN_UIEN_Pos)
#define GTMR_DIEN_UIEN                        GTMR_DIEN_UIEN_Msk
#define GTMR_DIEN_CC0IEN_Pos                  (1U)
#define GTMR_DIEN_CC0IEN_Msk                  (0x1UL << GTMR_DIEN_CC0IEN_Pos)
#define GTMR_DIEN_CC0IEN                      GTMR_DIEN_CC0IEN_Msk
#define GTMR_DIEN_CC1IEN_Pos                  (2U)
#define GTMR_DIEN_CC1IEN_Msk                  (0x1UL << GTMR_DIEN_CC1IEN_Pos)
#define GTMR_DIEN_CC1IEN                      GTMR_DIEN_CC1IEN_Msk
#define GTMR_DIEN_CC2IEN_Pos                  (3U)
#define GTMR_DIEN_CC2IEN_Msk                  (0x1UL << GTMR_DIEN_CC2IEN_Pos)
#define GTMR_DIEN_CC2IEN                      GTMR_DIEN_CC2IEN_Msk
#define GTMR_DIEN_CC3IEN_Pos                  (4U)
#define GTMR_DIEN_CC3IEN_Msk                  (0x1UL << GTMR_DIEN_CC3IEN_Pos)
#define GTMR_DIEN_CC3IEN                      GTMR_DIEN_CC3IEN_Msk
#define GTMR_DIEN_TRGIEN_Pos                  (6U)
#define GTMR_DIEN_TRGIEN_Msk                  (0x1UL << GTMR_DIEN_TRGIEN_Pos)
#define GTMR_DIEN_TRGIEN                      GTMR_DIEN_TRGIEN_Msk
#define GTMR_DIEN_UDIEN_Pos                   (8U)
#define GTMR_DIEN_UDIEN_Msk                   (0x1UL << GTMR_DIEN_UDIEN_Pos)
#define GTMR_DIEN_UDIEN                       GTMR_DIEN_UDIEN_Msk
#define GTMR_DIEN_CC0DEN_Pos                  (9U)
#define GTMR_DIEN_CC0DEN_Msk                  (0x1UL << GTMR_DIEN_CC0DEN_Pos)
#define GTMR_DIEN_CC0DEN                      GTMR_DIEN_CC0DEN_Msk
#define GTMR_DIEN_CC1DEN_Pos                  (10U)
#define GTMR_DIEN_CC1DEN_Msk                  (0x1UL << GTMR_DIEN_CC1DEN_Pos)
#define GTMR_DIEN_CC1DEN                      GTMR_DIEN_CC1DEN_Msk
#define GTMR_DIEN_CC2DEN_Pos                  (11U)
#define GTMR_DIEN_CC2DEN_Msk                  (0x1UL << GTMR_DIEN_CC2DEN_Pos)
#define GTMR_DIEN_CC2DEN                      GTMR_DIEN_CC2DEN_Msk
#define GTMR_DIEN_CC3DEN_Pos                  (12U)
#define GTMR_DIEN_CC3DEN_Msk                  (0x1UL << GTMR_DIEN_CC3DEN_Pos)
#define GTMR_DIEN_CC3DEN                      GTMR_DIEN_CC3DEN_Msk
#define GTMR_DIEN_TRGDEN_Pos                  (14U)
#define GTMR_DIEN_TRGDEN_Msk                  (0x1UL << GTMR_DIEN_TRGDEN_Pos)
#define GTMR_DIEN_TRGDEN                      GTMR_DIEN_TRGDEN_Msk

/*******************  Bit definition for GTMR_STS register  *******************/
#define GTMR_STS_UIFLG_Pos                    (0U)
#define GTMR_STS_UIFLG_Msk                    (0x1UL << GTMR_STS_UIFLG_Pos)
#define GTMR_STS_UIFLG                        GTMR_STS_UIFLG_Msk
#define GTMR_STS_CC0IFLG_Pos                  (1U)
#define GTMR_STS_CC0IFLG_Msk                  (0x1UL << GTMR_STS_CC0IFLG_Pos)
#define GTMR_STS_CC0IFLG                      GTMR_STS_CC0IFLG_Msk
#define GTMR_STS_CC1IFLG_Pos                  (2U)
#define GTMR_STS_CC1IFLG_Msk                  (0x1UL << GTMR_STS_CC1IFLG_Pos)
#define GTMR_STS_CC1IFLG                      GTMR_STS_CC1IFLG_Msk
#define GTMR_STS_CC2IFLG_Pos                  (3U)
#define GTMR_STS_CC2IFLG_Msk                  (0x1UL << GTMR_STS_CC2IFLG_Pos)
#define GTMR_STS_CC2IFLG                      GTMR_STS_CC2IFLG_Msk
#define GTMR_STS_CC3IFLG_Pos                  (4U)
#define GTMR_STS_CC3IFLG_Msk                  (0x1UL << GTMR_STS_CC3IFLG_Pos)
#define GTMR_STS_CC3IFLG                      GTMR_STS_CC3IFLG_Msk
#define GTMR_STS_TRGIFLG_Pos                  (6U)
#define GTMR_STS_TRGIFLG_Msk                  (0x1UL << GTMR_STS_TRGIFLG_Pos)
#define GTMR_STS_TRGIFLG                      GTMR_STS_TRGIFLG_Msk
#define GTMR_STS_CC0RCFLG_Pos                 (9U)
#define GTMR_STS_CC0RCFLG_Msk                 (0x1UL << GTMR_STS_CC0RCFLG_Pos)
#define GTMR_STS_CC0RCFLG                     GTMR_STS_CC0RCFLG_Msk
#define GTMR_STS_CC1RCFLG_Pos                 (10U)
#define GTMR_STS_CC1RCFLG_Msk                 (0x1UL << GTMR_STS_CC1RCFLG_Pos)
#define GTMR_STS_CC1RCFLG                     GTMR_STS_CC1RCFLG_Msk
#define GTMR_STS_CC2RCFLG_Pos                 (11U)
#define GTMR_STS_CC2RCFLG_Msk                 (0x1UL << GTMR_STS_CC2RCFLG_Pos)
#define GTMR_STS_CC2RCFLG                     GTMR_STS_CC2RCFLG_Msk
#define GTMR_STS_CC3RCFLG_Pos                 (12U)
#define GTMR_STS_CC3RCFLG_Msk                 (0x1UL << GTMR_STS_CC3RCFLG_Pos)
#define GTMR_STS_CC3RCFLG                     GTMR_STS_CC3RCFLG_Msk

/*******************  Bit definition for GTMR_CEG register  *******************/
#define GTMR_CEG_UEG_Pos                      (0U)
#define GTMR_CEG_UEG_Msk                      (0x1UL << GTMR_CEG_UEG_Pos)
#define GTMR_CEG_UEG                          GTMR_CEG_UEG_Msk
#define GTMR_CEG_CC0EG_Pos                    (1U)
#define GTMR_CEG_CC0EG_Msk                    (0x1UL << GTMR_CEG_CC0EG_Pos)
#define GTMR_CEG_CC0EG                        GTMR_CEG_CC0EG_Msk
#define GTMR_CEG_CC1EG_Pos                    (2U)
#define GTMR_CEG_CC1EG_Msk                    (0x1UL << GTMR_CEG_CC1EG_Pos)
#define GTMR_CEG_CC1EG                        GTMR_CEG_CC1EG_Msk
#define GTMR_CEG_CC2EG_Pos                    (3U)
#define GTMR_CEG_CC2EG_Msk                    (0x1UL << GTMR_CEG_CC2EG_Pos)
#define GTMR_CEG_CC2EG                        GTMR_CEG_CC2EG_Msk
#define GTMR_CEG_CC3EG_Pos                    (4U)
#define GTMR_CEG_CC3EG_Msk                    (0x1UL << GTMR_CEG_CC3EG_Pos)
#define GTMR_CEG_CC3EG                        GTMR_CEG_CC3EG_Msk
#define GTMR_CEG_TEG_Pos                      (6U)
#define GTMR_CEG_TEG_Msk                      (0x1UL << GTMR_CEG_TEG_Pos)
#define GTMR_CEG_TEG                          GTMR_CEG_TEG_Msk

/*******************  Bit definition for GTMR_CCM1 register  ******************/
#define GTMR_CCM1_CC0SEL_Pos                  (0U)
#define GTMR_CCM1_CC0SEL_Msk                  (0x3UL << GTMR_CCM1_CC0SEL_Pos)
#define GTMR_CCM1_CC0SEL                      GTMR_CCM1_CC0SEL_Msk
#define GTMR_CCM1_CC0SEL_0                    (0x1UL << GTMR_CCM1_CC0SEL_Pos)
#define GTMR_CCM1_CC0SEL_1                    (0x2UL << GTMR_CCM1_CC0SEL_Pos)
#define GTMR_CCM1_OC0PEN_Pos                  (3U)
#define GTMR_CCM1_OC0PEN_Msk                  (0x1UL << GTMR_CCM1_OC0PEN_Pos)
#define GTMR_CCM1_OC0PEN                      GTMR_CCM1_OC0PEN_Msk
#define GTMR_CCM1_OC0MOD_Pos                  (4U)
#define GTMR_CCM1_OC0MOD_Msk                  (0x7UL << GTMR_CCM1_OC0MOD_Pos)
#define GTMR_CCM1_OC0MOD                      GTMR_CCM1_OC0MOD_Msk
#define GTMR_CCM1_OC0MOD_0                    (0x1UL << GTMR_CCM1_OC0MOD_Pos)
#define GTMR_CCM1_OC0MOD_1                    (0x2UL << GTMR_CCM1_OC0MOD_Pos)
#define GTMR_CCM1_OC0MOD_2                    (0x4UL << GTMR_CCM1_OC0MOD_Pos)
#define GTMR_CCM1_OC0CEN_Pos                  (7U)
#define GTMR_CCM1_OC0CEN_Msk                  (0x1UL << GTMR_CCM1_OC0CEN_Pos)
#define GTMR_CCM1_OC0CEN                      GTMR_CCM1_OC0CEN_Msk
#define GTMR_CCM1_CC1SEL_Pos                  (8U)
#define GTMR_CCM1_CC1SEL_Msk                  (0x3UL << GTMR_CCM1_CC1SEL_Pos)
#define GTMR_CCM1_CC1SEL                      GTMR_CCM1_CC1SEL_Msk
#define GTMR_CCM1_CC1SEL_0                    (0x1UL << GTMR_CCM1_CC1SEL_Pos)
#define GTMR_CCM1_CC1SEL_1                    (0x2UL << GTMR_CCM1_CC1SEL_Pos)
#define GTMR_CCM1_OC1PEN_Pos                  (11U)
#define GTMR_CCM1_OC1PEN_Msk                  (0x1UL << GTMR_CCM1_OC1PEN_Pos)
#define GTMR_CCM1_OC1PEN                      GTMR_CCM1_OC1PEN_Msk
#define GTMR_CCM1_OC1MOD_Pos                  (12U)
#define GTMR_CCM1_OC1MOD_Msk                  (0x7UL << GTMR_CCM1_OC1MOD_Pos)
#define GTMR_CCM1_OC1MOD                      GTMR_CCM1_OC1MOD_Msk
#define GTMR_CCM1_OC1MOD_0                    (0x1UL << GTMR_CCM1_OC1MOD_Pos)
#define GTMR_CCM1_OC1MOD_1                    (0x2UL << GTMR_CCM1_OC1MOD_Pos)
#define GTMR_CCM1_OC1MOD_2                    (0x4UL << GTMR_CCM1_OC1MOD_Pos)
#define GTMR_CCM1_OC1CEN_Pos                  (15U)
#define GTMR_CCM1_OC1CEN_Msk                  (0x1UL << GTMR_CCM1_OC1CEN_Pos)
#define GTMR_CCM1_OC1CEN                      GTMR_CCM1_OC1CEN_Msk

// Input mode (CCM1_CAPTURE)
#define GTMR_CCM1_IC0PSC_Pos                  (2U)
#define GTMR_CCM1_IC0PSC_Msk                  (0x3UL << GTMR_CCM1_IC0PSC_Pos)
#define GTMR_CCM1_IC0PSC                      GTMR_CCM1_IC0PSC_Msk
#define GTMR_CCM1_IC0PSC_0                    (0x1UL << GTMR_CCM1_IC0PSC_Pos)
#define GTMR_CCM1_IC0PSC_1                    (0x2UL << GTMR_CCM1_IC0PSC_Pos)
#define GTMR_CCM1_IC0F_Pos                    (4U)
#define GTMR_CCM1_IC0F_Msk                    (0xFUL << GTMR_CCM1_IC0F_Pos)
#define GTMR_CCM1_IC0F                        GTMR_CCM1_IC0F_Msk
#define GTMR_CCM1_IC0F_0                      (0x1UL << GTMR_CCM1_IC0F_Pos)
#define GTMR_CCM1_IC0F_1                      (0x2UL << GTMR_CCM1_IC0F_Pos)
#define GTMR_CCM1_IC0F_2                      (0x4UL << GTMR_CCM1_IC0F_Pos)
#define GTMR_CCM1_IC0F_3                      (0x8UL << GTMR_CCM1_IC0F_Pos)
#define GTMR_CCM1_IC1PSC_Pos                  (10U)
#define GTMR_CCM1_IC1PSC_Msk                  (0x3UL << GTMR_CCM1_IC1PSC_Pos)
#define GTMR_CCM1_IC1PSC                      GTMR_CCM1_IC1PSC_Msk
#define GTMR_CCM1_IC1PSC_0                    (0x1UL << GTMR_CCM1_IC1PSC_Pos)
#define GTMR_CCM1_IC1PSC_1                    (0x2UL << GTMR_CCM1_IC1PSC_Pos)
#define GTMR_CCM1_IC1F_Pos                    (12U)
#define GTMR_CCM1_IC1F_Msk                    (0xFUL << GTMR_CCM1_IC1F_Pos)
#define GTMR_CCM1_IC1F                        GTMR_CCM1_IC1F_Msk
#define GTMR_CCM1_IC1F_0                      (0x1UL << GTMR_CCM1_IC1F_Pos)
#define GTMR_CCM1_IC1F_1                      (0x2UL << GTMR_CCM1_IC1F_Pos)
#define GTMR_CCM1_IC1F_2                      (0x4UL << GTMR_CCM1_IC1F_Pos)
#define GTMR_CCM1_IC1F_3                      (0x8UL << GTMR_CCM1_IC1F_Pos)

/*******************  Bit definition for GTMR_CCM2 register  ******************/
#define GTMR_CCM2_CC2SEL_Pos                  (0U)
#define GTMR_CCM2_CC2SEL_Msk                  (0x3UL << GTMR_CCM2_CC2SEL_Pos)
#define GTMR_CCM2_CC2SEL                      GTMR_CCM2_CC2SEL_Msk
#define GTMR_CCM2_CC2SEL_0                    (0x1UL << GTMR_CCM2_CC2SEL_Pos)
#define GTMR_CCM2_CC2SEL_1                    (0x2UL << GTMR_CCM2_CC2SEL_Pos)
#define GTMR_CCM2_OC2PEN_Pos                  (3U)
#define GTMR_CCM2_OC2PEN_Msk                  (0x1UL << GTMR_CCM2_OC2PEN_Pos)
#define GTMR_CCM2_OC2PEN                      GTMR_CCM2_OC2PEN_Msk
#define GTMR_CCM2_OC2MOD_Pos                  (4U)
#define GTMR_CCM2_OC2MOD_Msk                  (0x7UL << GTMR_CCM2_OC2MOD_Pos)
#define GTMR_CCM2_OC2MOD                      GTMR_CCM2_OC2MOD_Msk
#define GTMR_CCM2_OC2MOD_0                    (0x1UL << GTMR_CCM2_OC2MOD_Pos)
#define GTMR_CCM2_OC2MOD_1                    (0x2UL << GTMR_CCM2_OC2MOD_Pos)
#define GTMR_CCM2_OC2MOD_2                    (0x4UL << GTMR_CCM2_OC2MOD_Pos)
#define GTMR_CCM2_OC2CEN_Pos                  (7U)
#define GTMR_CCM2_OC2CEN_Msk                  (0x1UL << GTMR_CCM2_OC2CEN_Pos)
#define GTMR_CCM2_OC2CEN                      GTMR_CCM2_OC2CEN_Msk
#define GTMR_CCM2_CC3SEL_Pos                  (8U)
#define GTMR_CCM2_CC3SEL_Msk                  (0x3UL << GTMR_CCM2_CC3SEL_Pos)
#define GTMR_CCM2_CC3SEL                      GTMR_CCM2_CC3SEL_Msk
#define GTMR_CCM2_CC3SEL_0                    (0x1UL << GTMR_CCM2_CC3SEL_Pos)
#define GTMR_CCM2_CC3SEL_1                    (0x2UL << GTMR_CCM2_CC3SEL_Pos)
#define GTMR_CCM2_OC3PEN_Pos                  (11U)
#define GTMR_CCM2_OC3PEN_Msk                  (0x1UL << GTMR_CCM2_OC3PEN_Pos)
#define GTMR_CCM2_OC3PEN                      GTMR_CCM2_OC3PEN_Msk
#define GTMR_CCM2_OC3MOD_Pos                  (12U)
#define GTMR_CCM2_OC3MOD_Msk                  (0x7UL << GTMR_CCM2_OC3MOD_Pos)
#define GTMR_CCM2_OC3MOD                      GTMR_CCM2_OC3MOD_Msk
#define GTMR_CCM2_OC3MOD_0                    (0x1UL << GTMR_CCM2_OC3MOD_Pos)
#define GTMR_CCM2_OC3MOD_1                    (0x2UL << GTMR_CCM2_OC3MOD_Pos)
#define GTMR_CCM2_OC3MOD_2                    (0x4UL << GTMR_CCM2_OC3MOD_Pos)
#define GTMR_CCM2_OC3CEN_Pos                  (15U)
#define GTMR_CCM2_OC3CEN_Msk                  (0x1UL << GTMR_CCM2_OC3CEN_Pos)
#define GTMR_CCM2_OC3CEN                      GTMR_CCM2_OC3CEN_Msk

// Input mode (CCM2_CAPTURE)
#define GTMR_CCM2_IC2PSC_Pos                  (2U)
#define GTMR_CCM2_IC2PSC_Msk                  (0x3UL << GTMR_CCM2_IC2PSC_Pos)
#define GTMR_CCM2_IC2PSC                      GTMR_CCM2_IC2PSC_Msk
#define GTMR_CCM2_IC2PSC_0                    (0x1UL << GTMR_CCM2_IC2PSC_Pos)
#define GTMR_CCM2_IC2PSC_1                    (0x2UL << GTMR_CCM2_IC2PSC_Pos)
#define GTMR_CCM2_IC2F_Pos                    (4U)
#define GTMR_CCM2_IC2F_Msk                    (0xFUL << GTMR_CCM2_IC2F_Pos)
#define GTMR_CCM2_IC2F                        GTMR_CCM2_IC2F_Msk
#define GTMR_CCM2_IC2F_0                      (0x1UL << GTMR_CCM2_IC2F_Pos)
#define GTMR_CCM2_IC2F_1                      (0x2UL << GTMR_CCM2_IC2F_Pos)
#define GTMR_CCM2_IC2F_2                      (0x4UL << GTMR_CCM2_IC2F_Pos)
#define GTMR_CCM2_IC2F_3                      (0x8UL << GTMR_CCM2_IC2F_Pos)
#define GTMR_CCM2_IC3PSC_Pos                  (10U)
#define GTMR_CCM2_IC3PSC_Msk                  (0x3UL << GTMR_CCM2_IC3PSC_Pos)
#define GTMR_CCM2_IC3PSC                      GTMR_CCM2_IC3PSC_Msk
#define GTMR_CCM2_IC3PSC_0                    (0x1UL << GTMR_CCM2_IC3PSC_Pos)
#define GTMR_CCM2_IC3PSC_1                    (0x2UL << GTMR_CCM2_IC3PSC_Pos)
#define GTMR_CCM2_IC3F_Pos                    (12U)
#define GTMR_CCM2_IC3F_Msk                    (0xFUL << GTMR_CCM2_IC3F_Pos)
#define GTMR_CCM2_IC3F                        GTMR_CCM2_IC3F_Msk
#define GTMR_CCM2_IC3F_0                      (0x1UL << GTMR_CCM2_IC3F_Pos)
#define GTMR_CCM2_IC3F_1                      (0x2UL << GTMR_CCM2_IC3F_Pos)
#define GTMR_CCM2_IC3F_2                      (0x4UL << GTMR_CCM2_IC3F_Pos)
#define GTMR_CCM2_IC3F_3                      (0x8UL << GTMR_CCM2_IC3F_Pos)

/*******************  Bit definition for GTMR_CCEN register  ******************/
#define GTMR_CCEN_CC0EN_Pos                   (0U)
#define GTMR_CCEN_CC0EN_Msk                   (0x1UL << GTMR_CCEN_CC0EN_Pos)
#define GTMR_CCEN_CC0EN                       GTMR_CCEN_CC0EN_Msk
#define GTMR_CCEN_CC0POL_Pos                  (1U)
#define GTMR_CCEN_CC0POL_Msk                  (0x1UL << GTMR_CCEN_CC0POL_Pos)
#define GTMR_CCEN_CC0POL                      GTMR_CCEN_CC0POL_Msk
#define GTMR_CCEN_CC1EN_Pos                   (4U)
#define GTMR_CCEN_CC1EN_Msk                   (0x1UL << GTMR_CCEN_CC1EN_Pos)
#define GTMR_CCEN_CC1EN                       GTMR_CCEN_CC1EN_Msk
#define GTMR_CCEN_CC1POL_Pos                  (5U)
#define GTMR_CCEN_CC1POL_Msk                  (0x1UL << GTMR_CCEN_CC1POL_Pos)
#define GTMR_CCEN_CC1POL                      GTMR_CCEN_CC1POL_Msk
#define GTMR_CCEN_CC2EN_Pos                   (8U)
#define GTMR_CCEN_CC2EN_Msk                   (0x1UL << GTMR_CCEN_CC2EN_Pos)
#define GTMR_CCEN_CC2EN                       GTMR_CCEN_CC2EN_Msk
#define GTMR_CCEN_CC2POL_Pos                  (9U)
#define GTMR_CCEN_CC2POL_Msk                  (0x1UL << GTMR_CCEN_CC2POL_Pos)
#define GTMR_CCEN_CC2POL                      GTMR_CCEN_CC2POL_Msk
#define GTMR_CCEN_CC3EN_Pos                   (12U)
#define GTMR_CCEN_CC3EN_Msk                   (0x1UL << GTMR_CCEN_CC3EN_Pos)
#define GTMR_CCEN_CC3EN                       GTMR_CCEN_CC3EN_Msk
#define GTMR_CCEN_CC3POL_Pos                  (13U)
#define GTMR_CCEN_CC3POL_Msk                  (0x1UL << GTMR_CCEN_CC3POL_Pos)
#define GTMR_CCEN_CC3POL                      GTMR_CCEN_CC3POL_Msk

/*******************  Bit definition for GTMR_CNT register  *******************/
#define GTMR_CNT_CNT_Pos                      (0U)
#define GTMR_CNT_CNT_Msk                      (0xFFFFFFFFUL << GTMR_CNT_CNT_Pos)
#define GTMR_CNT_CNT                          GTMR_CNT_CNT_Msk

/*******************  Bit definition for GTMR_PSC register  *******************/
#define GTMR_PSC_PSC_Pos                      (0U)
#define GTMR_PSC_PSC_Msk                      (0xFFFFUL << GTMR_PSC_PSC_Pos)
#define GTMR_PSC_PSC                          GTMR_PSC_PSC_Msk

/*******************  Bit definition for GTMR_AUTORLD register  ***************/
#define GTMR_AUTORLD_AUTORLD_Pos              (0U)
#define GTMR_AUTORLD_AUTORLD_Msk              (0xFFFFFFFFUL << GTMR_AUTORLD_AUTORLD_Pos)
#define GTMR_AUTORLD_AUTORLD                  GTMR_AUTORLD_AUTORLD_Msk

/*******************  Bit definition for GTMR_CC0 register  *******************/
#define GTMR_CC0_CC0_Pos                      (0U)
#define GTMR_CC0_CC0_Msk                      (0xFFFFFFFFUL << GTMR_CC0_CC0_Pos)
#define GTMR_CC0_CC0                          GTMR_CC0_CC0_Msk

/*******************  Bit definition for GTMR_CC1 register  *******************/
#define GTMR_CC1_CC1_Pos                      (0U)
#define GTMR_CC1_CC1_Msk                      (0xFFFFUL << GTMR_CC1_CC1_Pos)
#define GTMR_CC1_CC1                          GTMR_CC1_CC1_Msk

/*******************  Bit definition for GTMR_CC2 register  *******************/
#define GTMR_CC2_CC2_Pos                      (0U)
#define GTMR_CC2_CC2_Msk                      (0xFFFFFFFFUL << GTMR_CC2_CC2_Pos)
#define GTMR_CC2_CC2                          GTMR_CC2_CC2_Msk

/*******************  Bit definition for GTMR_CC3 register  *******************/
#define GTMR_CC3_CC3_Pos                      (0U)
#define GTMR_CC3_CC3_Msk                      (0xFFFFFFFFUL << GTMR_CC3_CC3_Pos)
#define GTMR_CC3_CC3                          GTMR_CC3_CC3_Msk

/******************************************************************************/
/*                                                                            */
/*                        Independent watchdog timer                          */
/*                                                                            */
/******************************************************************************/
/********************  Bit definition for IWDT_KEY register  ******************/
#define IWDT_KEY_KEY_Pos                      (0UL)                                             /*!< KEY (Bit 0) */
#define IWDT_KEY_KEY_Msk                      (0xFFFFUL << IWDT_KEY_KEY_Pos)                    /*!< KEY (Bitfield-Mask: 0xffff) */
#define IWDT_KEY_KEY                          IWDT_KEY_KEY_Msk                                  /*!<Key value (write only, read 0000h) */
/********************  Bit definition for IWDT_PSC register  *******************/
#define IWDT_PSC_PSC_Pos                      (0UL)                                             /*!< PSC (Bit 0) */
#define IWDT_PSC_PSC_0                        (0x1UL << IWDT_PSC_PSC_Pos)                       /*!< 0x01 */
#define IWDT_PSC_PSC_1                        (0x2UL << IWDT_PSC_PSC_Pos)                       /*!< 0x02 */
#define IWDT_PSC_PSC_2                        (0x4UL << IWDT_PSC_PSC_Pos)                       /*!< 0x04 */
#define IWDT_PSC_PSC_Msk                      (0x7UL << IWDT_PSC_PSC_Pos)                       /*!< PSC (Bitfield-Mask: 0x07) */
#define IWDT_PSC_PSC                          IWDT_PSC_PSC_Msk                                  /*!<PSC[2:0] (Prescaler divider) */

/********************  Bit definition for IWDT_CNTRLD register  *******************/
#define IWDT_CNTRLD_CNTRLD_Pos                (0UL)                                             /*!< CNTRLD (Bit 0) */
#define IWDT_CNTRLD_CNTRLD_Msk                (0xFFFUL << IWDT_CNTRLD_CNTRLD_Pos)               /*!< CNTRLD (Bitfield-Mask: 0xfff) */
#define IWDT_CNTRLD_CNTRLD                    IWDT_CNTRLD_CNTRLD_Msk                            /*!<Watchdog counter reload value */
/********************  Bit definition for IWDT_STS register  *******************/
#define IWDT_STS_PSCUFLG_Pos                  (0UL)                                             /*!< PSCUFLG (Bit 0) */
#define IWDT_STS_PSCUFLG_Msk                  (0x1UL << IWDT_STS_PSCUFLG_Pos)                   /*!< PSCUFLG (Bitfield-Mask: 0x01) */
#define IWDT_STS_PSCUFLG                      IWDT_STS_PSCUFLG_Msk                              /*!<Watchdog prescaler value update */
#define IWDT_STS_CNTUFLG_Pos                  (1UL)                                             /*!< CNTUFLG (Bit 1) */
#define IWDT_STS_CNTUFLG_Msk                  (0x1UL << IWDT_STS_CNTUFLG_Pos)                   /*!< CNTUFLG (Bitfield-Mask: 0x01) */
#define IWDT_STS_CNTUFLG                      IWDT_STS_CNTUFLG_Msk                              /*!<Watchdog counter reload value update */


/******************************************************************************/
/*                                                                            */
/*                         Low power timer control                            */
/*                                                                            */
/******************************************************************************/
/*******************  Bit definition for LPTMR_CTRL register  *******************/
#define LPTMR_CTRL_EN_Pos                     (0UL)                                             /*!< EN (Bit 0)                           */
#define LPTMR_CTRL_EN_Msk                     (0x1UL << LPTMR_CTRL_EN_Pos)                      /*!< EN (Bitfield-Mask: 0x01)             */
#define LPTMR_CTRL_EN                         LPTMR_CTRL_EN_Msk
/*******************  Bit definition for LPTMR_PSC register  *******************/
#define LPTMR_PSC_PSC_Pos                     (0UL)                                             /*!< PS (Bit 0)                           */
#define LPTMR_PSC_PSC_Msk                     (0xFFFFUL << LPTMR_PSC_PSC_Pos)                   /*!< PS (Bitfield-Mask: 0xffff)             */
#define LPTMR_PSC_PSC                         LPTMR_PSC_PSC_Msk
/*******************  Bit definition for LPTMR_WUPV register  *******************/
#define LPTMR_WUPV_WUPV_Pos                   (0UL)                                             /*!< RV (Bit 0)                           */
#define LPTMR_WUPV_WUPV_Msk                   (0xFFFFUL << LPTMR_WUPV_WUPV_Pos)                 /*!< RV (Bitfield-Mask: 0xFFFF)           */
#define LPTMR_WUPV_WUPV                       LPTMR_WUPV_WUPV_Msk
/*******************  Bit definition for LPTMR_STS register  *******************/
#define LPTMR_STS_INTSTS_Pos                  (0UL)                                             /*!< WK_STS (Bit 0)                       */
#define LPTMR_STS_INTSTS_Msk                  (0x1UL << LPTMR_STS_INTSTS_Pos)                   /*!< WK_STS (Bitfield-Mask: 0x01)         */
#define LPTMR_STS_INTSTS                      LPTMR_STS_INTSTS_Msk
#define LPTMR_STS_PSCUFLG_Pos                 (1UL)                                             /*!< PU (Bit 1)                           */
#define LPTMR_STS_PSCUFLG_Msk                 (0x1UL << LPTMR_STS_PSCUFLG_Pos)                  /*!< PU (Bitfield-Mask: 0x01)             */
#define LPTMR_STS_PSCUFLG                     LPTMR_STS_PSCUFLG_Msk
#define LPTMR_STS_CNTUFLG_Pos                 (2UL)                                             /*!< RU (Bit 2)                           */
#define LPTMR_STS_CNTUFLG_Msk                 (0x1UL << LPTMR_STS_CNTUFLG_Pos)                  /*!< RU (Bitfield-Mask: 0x01)             */
#define LPTMR_STS_CNTUFLG                     LPTMR_STS_CNTUFLG_Msk
/*******************  Bit definition for LPTMR_CNT register  ******************/
#define LPTMR_CNT_CNT_Pos                     (0UL)                                             /*!< CNT (Bit 0)                           */
#define LPTMR_CNT_CNT_Msk                     (0xFFFFUL << LPTMR_CNT_CNT_Pos)                   /*!< CNT (Bitfield-Mask: 0xFFFF)           */
#define LPTMR_CNT_CNT                         LPTMR_CNT_CNT_Msk

/******************************************************************************/
/*                                                                            */
/*                          Serial Peripheral Interface                       */
/*                                                                            */
/******************************************************************************/
/*******************  Bit definition for SPI_CTRL1 register  ******************/
#define SPI_CTRL1_CPHA_Pos                    (0U)
#define SPI_CTRL1_CPHA_Msk                    (0x1UL << SPI_CTRL1_CPHA_Pos)                     /*!< 0x00000001 */
#define SPI_CTRL1_CPHA                        SPI_CTRL1_CPHA_Msk                                /*!<Clock Phase      */
#define SPI_CTRL1_CPOL_Pos                    (1U)
#define SPI_CTRL1_CPOL_Msk                    (0x1UL << SPI_CTRL1_CPOL_Pos)                     /*!< 0x00000002 */
#define SPI_CTRL1_CPOL                        SPI_CTRL1_CPOL_Msk                                /*!<Clock Polarity   */
#define SPI_CTRL1_MSMCFG_Pos                  (2U)
#define SPI_CTRL1_MSMCFG_Msk                  (0x1UL << SPI_CTRL1_MSMCFG_Pos)                   /*!< 0x00000004 */
#define SPI_CTRL1_MSMCFG                      SPI_CTRL1_MSMCFG_Msk                              /*!<Master Selection */

#define SPI_CTRL1_BRSEL_Pos                   (3U)
#define SPI_CTRL1_BRSEL_Msk                   (0x7UL << SPI_CTRL1_BRSEL_Pos)                    /*!< 0x00000038 */
#define SPI_CTRL1_BRSEL                       SPI_CTRL1_BRSEL_Msk                               /*!<BR[2:0] bits (Baud Rate Control) */
#define SPI_CTRL1_BRSEL_0                     (0x1UL << SPI_CTRL1_BRSEL_Pos)                    /*!< 0x00000008 */
#define SPI_CTRL1_BRSEL_1                     (0x2UL << SPI_CTRL1_BRSEL_Pos)                    /*!< 0x00000010 */
#define SPI_CTRL1_BRSEL_2                     (0x4UL << SPI_CTRL1_BRSEL_Pos)                    /*!< 0x00000020 */

#define SPI_CTRL1_SPIEN_Pos                   (6U)
#define SPI_CTRL1_SPIEN_Msk                   (0x1UL << SPI_CTRL1_SPIEN_Pos)                    /*!< 0x00000040 */
#define SPI_CTRL1_SPIEN                       SPI_CTRL1_SPIEN_Msk                               /*!<SPI Enable                          */
#define SPI_CTRL1_LSBSEL_Pos                  (7U)
#define SPI_CTRL1_LSBSEL_Msk                  (0x1UL << SPI_CTRL1_LSBSEL_Pos)                   /*!< 0x00000080 */
#define SPI_CTRL1_LSBSEL                      SPI_CTRL1_LSBSEL_Msk                              /*!<Frame Format                        */
#define SPI_CTRL1_ISSEL_Pos                   (8U)
#define SPI_CTRL1_ISSEL_Msk                   (0x1UL << SPI_CTRL1_ISSEL_Pos)                    /*!< 0x00000100 */
#define SPI_CTRL1_ISSEL                       SPI_CTRL1_ISSEL_Msk                               /*!<Internal slave select               */
#define SPI_CTRL1_SSEN_Pos                    (9U)
#define SPI_CTRL1_SSEN_Msk                    (0x1UL << SPI_CTRL1_SSEN_Pos)                     /*!< 0x00000200 */
#define SPI_CTRL1_SSEN                        SPI_CTRL1_SSEN_Msk                                /*!<Software slave management           */
#define SPI_CTRL1_DFLSEL_Pos                  (10U)
#define SPI_CTRL1_DFLSEL_Msk                  (0x1UL << SPI_CTRL1_DFLSEL_Pos)                   /*!< 0x00000400 */
#define SPI_CTRL1_DFLSEL                      SPI_CTRL1_DFLSEL_Msk                              /*!<Data Frame Format                   */                                        /*!<Hardware CRC calculation enable     */
#define SPI_CTRL1_BMOEN_Pos                   (11U)
#define SPI_CTRL1_BMOEN_Msk                   (0x1UL << SPI_CTRL1_BMOEN_Pos)                    /*!< 0x00004000 */
#define SPI_CTRL1_BMOEN                       SPI_CTRL1_BMOEN_Msk                               /*!<Output enable in bidirectional mode */
#define SPI_CTRL1_BMEN_Pos                    (12U)
#define SPI_CTRL1_BMEN_Msk                    (0x1UL << SPI_CTRL1_BMEN_Pos)                     /*!< 0x00008000 */
#define SPI_CTRL1_BMEN                        SPI_CTRL1_BMEN_Msk                                /*!<Bidirectional data mode enable      */

/*******************  Bit definition for SPI_CTRL2 register  ******************/
#define SPI_CTRL2_RXDEN_Pos                   (0U)
#define SPI_CTRL2_RXDEN_Msk                   (0x1UL << SPI_CTRL2_RXDEN_Pos)                    /*!< 0x00000001 */
#define SPI_CTRL2_RXDEN                       SPI_CTRL2_RXDEN_Msk                               /*!<Rx Buffer DMA Enable                 */
#define SPI_CTRL2_TXDEN_Pos                   (1U)
#define SPI_CTRL2_TXDEN_Msk                   (0x1UL << SPI_CTRL2_TXDEN_Pos)                    /*!< 0x00000002 */
#define SPI_CTRL2_TXDEN                       SPI_CTRL2_TXDEN_Msk                               /*!<Tx Buffer DMA Enable                 */                                       /*!<Error Interrupt Enable               */
#define SPI_CTRL2_RXBNEIEN_Pos                (2U)
#define SPI_CTRL2_RXBNEIEN_Msk                (0x1UL << SPI_CTRL2_RXBNEIEN_Pos)                 /*!< 0x00000040 */
#define SPI_CTRL2_RXBNEIEN                    SPI_CTRL2_RXBNEIEN_Msk                            /*!<RX buffer Not Empty Interrupt Enable */
#define SPI_CTRL2_TXBEIEN_Pos                 (3U)
#define SPI_CTRL2_TXBEIEN_Msk                 (0x1UL << SPI_CTRL2_TXBEIEN_Pos)                  /*!< 0x00000080 */
#define SPI_CTRL2_TXBEIEN                     SPI_CTRL2_TXBEIEN_Msk                             /*!<Tx buffer Empty Interrupt Enable     */
#define SPI_CTRL2_OVRIEN_Pos                  (4U)
#define SPI_CTRL2_OVRIEN_Msk                  (0x1UL << SPI_CTRL2_OVRIEN_Pos)                   /*!< 0x00000080 */
#define SPI_CTRL2_OVRIEN                      SPI_CTRL2_OVRIEN_Msk                              /*!<overflow Interrupt Enable            */

/********************  Bit definition for SPI_STS register  *******************/
#define SPI_STS_RXBNEFLG_Pos                  (0U)
#define SPI_STS_RXBNEFLG_Msk                  (0x1UL << SPI_STS_RXBNEFLG_Pos)                   /*!< 0x00000001 */
#define SPI_STS_RXBNEFLG                      SPI_STS_RXBNEFLG_Msk                              /*!<Receive buffer Not Empty */
#define SPI_STS_TXBEFLG_Pos                   (1U)
#define SPI_STS_TXBEFLG_Msk                   (0x1UL << SPI_STS_TXBEFLG_Pos)                    /*!< 0x00000002 */
#define SPI_STS_TXBEFLG                       SPI_STS_TXBEFLG_Msk                               /*!<Transmit buffer Empty    */
#define SPI_STS_FRLSEL_Pos                    (2U)
#define SPI_STS_FRLSEL_Msk                    (0x3UL << SPI_STS_FRLSEL_Pos)
#define SPI_STS_FRLSEL                        SPI_STS_FRLSEL_Msk
#define SPI_STS_FRLSEL_0                      (0x1UL << SPI_STS_FRLSEL_Pos)                     /*!< 0x00000004 */
#define SPI_STS_FRLSEL_1                      (0x2UL << SPI_STS_FRLSEL_Pos)                     /*!< 0x00000008 */
#define SPI_STS_FTLSEL_Pos                    (4U)
#define SPI_STS_FTLSEL_Msk                    (0x3UL << SPI_STS_FTLSEL_Pos)
#define SPI_STS_FTLSEL                        SPI_STS_FTLSEL_Msk
#define SPI_STS_FTLSEL_0                      (0x1UL << SPI_STS_FTLSEL_Pos)                     /*!< 0x00000010 */
#define SPI_STS_FTLSEL_1                      (0x2UL << SPI_STS_FTLSEL_Pos)                     /*!< 0x00000020 */
#define SPI_STS_OVRFLG_Pos                    (6U)
#define SPI_STS_OVRFLG_Msk                    (0x1UL << SPI_STS_OVRFLG_Pos)
#define SPI_STS_OVRFLG                        SPI_STS_OVRFLG_Msk
#define SPI_STS_BSYFLG_Pos                    (7U)
#define SPI_STS_BSYFLG_Msk                    (0x1UL << SPI_STS_BSYFLG_Pos)
#define SPI_STS_BSYFLG                        SPI_STS_BSYFLG_Msk

/********************  Bit definition for SPI_DATA register  ******************/
#define SPI_DATA_DATA_Pos                     (0U)
#define SPI_DATA_DATA_Msk                     (0xFFFFUL << SPI_DATA_DATA_Pos)                   /*!< 0x0000FFFF */
#define SPI_DATA_DATA                         SPI_DATA_DATA_Msk                                 /*!<Data Register */

/******************************************************************************/
/*                                                                            */
/*                             System Controller                              */
/*                                                                            */
/******************************************************************************/
/********************  Bits definition for SCU_KEY register  ******************/
#define SCU_KEY_LOCKKEY_Pos                   (0U)
#define SCU_KEY_LOCKKEY_Msk                   (0xFFFFUL << SCU_KEY_LOCKKEY_Pos)                 /*!< 0x0000FFFF */
#define SCU_KEY_LOCKKEY                       SCU_KEY_LOCKKEY_Msk
#define SCU_KEY_KEYST_Pos                     (16U)
#define SCU_KEY_KEYST_Msk                     (0x1UL << SCU_KEY_KEYST_Pos)                      /*!< 0x00010000 */
#define SCU_KEY_KEYST                         SCU_KEY_KEYST_Msk

#define SCU_KEY_VALUE                         (0x87E4U)

/********************  Bits definition for SCU_RCCR register  *************/
#define SCU_RCCR_HSION_Pos                    (0U)
#define SCU_RCCR_HSION_Msk                    (0x1UL << SCU_RCCR_HSION_Pos)                     /*!< 0x00000001 */
#define SCU_RCCR_HSION                        SCU_RCCR_HSION_Msk
#define SCU_RCCR_HSIRDYFLG_Pos                (1U)
#define SCU_RCCR_HSIRDYFLG_Msk                (0x1UL << SCU_RCCR_HSIRDYFLG_Pos)                 /*!< 0x00000002 */
#define SCU_RCCR_HSIRDYFLG                    SCU_RCCR_HSIRDYFLG_Msk
#define SCU_RCCR_LSION_Pos                    (2U)
#define SCU_RCCR_LSION_Msk                    (0x1UL << SCU_RCCR_LSION_Pos)                     /*!< 0x00000001 */
#define SCU_RCCR_LSION                        SCU_RCCR_LSION_Msk
#define SCU_RCCR_LSIRDYFLG_Pos                (3U)
#define SCU_RCCR_LSIRDYFLG_Msk                (0x1UL << SCU_RCCR_LSIRDYFLG_Pos)                 /*!< 0x00000002 */
#define SCU_RCCR_LSIRDYFLG                    SCU_RCCR_LSIRDYFLG_Msk

/********************  Bits definition for SCU_SCCR register  *************/
#define SCU_SCCR_SW_Pos                       (0U)
#define SCU_SCCR_SW_Msk                       (0x1UL << SCU_SCCR_SW_Pos)                        /*!< 0x00000001 */
#define SCU_SCCR_SW                           SCU_SCCR_SW_Msk
#define SCU_SCCR_SW_HSI                       0x00000000U
#define SCU_SCCR_SW_LSI                       0x00000001U
#define SCU_SCCR_SWST_Pos                     (1U)
#define SCU_SCCR_SWST_Msk                     (0x1UL << SCU_SCCR_SWST_Pos)                      /*!< 0x00000002 */
#define SCU_SCCR_SWST                         SCU_SCCR_SWST_Msk
#define SCU_SCCR_SWST_HSI                     0x00000000U
#define SCU_SCCR_SWST_LSI                     0x00000002U

#define SCU_SCCR_HDIV_Pos                     (4U)
#define SCU_SCCR_HDIV_Msk                     (0x7UL << SCU_SCCR_HDIV_Pos)                      /*!< 0x00000070 */
#define SCU_SCCR_HDIV                         SCU_SCCR_HDIV_Msk
#define SCU_SCCR_HDIV_0                       (0x1UL << SCU_SCCR_HDIV_Pos)                      /*!< 0x00000010 */
#define SCU_SCCR_HDIV_1                       (0x2UL << SCU_SCCR_HDIV_Pos)                      /*!< 0x00000020 */
#define SCU_SCCR_HDIV_2                       (0x4UL << SCU_SCCR_HDIV_Pos)                      /*!< 0x00000040 */
#define SCU_SCCR_HDIV_DIV1                    0x00000000U
#define SCU_SCCR_HDIV_DIV2                    0x00000010U
#define SCU_SCCR_HDIV_DIV4                    0x00000020U
#define SCU_SCCR_HDIV_DIV8                    0x00000030U
#define SCU_SCCR_HDIV_DIV16                   0x00000040U
#define SCU_SCCR_HDIV_DIV32                   0x00000050U
#define SCU_SCCR_HDIV_DIV64                   0x00000060U
#define SCU_SCCR_HDIV_DIV128                  0x00000070U

#define SCU_SCCR_PDIV_Pos                     (8U)
#define SCU_SCCR_PDIV_Msk                     (0x7UL << SCU_SCCR_PDIV_Pos)                      /*!< 0x00000700 */
#define SCU_SCCR_PDIV                         SCU_SCCR_PDIV_Msk
#define SCU_SCCR_PDIV_0                       (0x1UL << SCU_SCCR_PDIV_Pos)                      /*!< 0x00000100 */
#define SCU_SCCR_PDIV_1                       (0x2UL << SCU_SCCR_PDIV_Pos)                      /*!< 0x00000200 */
#define SCU_SCCR_PDIV_2                       (0x4UL << SCU_SCCR_PDIV_Pos)                      /*!< 0x00000400 */
#define SCU_SCCR_PDIV_DIV1                    0x00000000U
#define SCU_SCCR_PDIV_DIV2                    0x00000100U
#define SCU_SCCR_PDIV_DIV4                    0x00000200U
#define SCU_SCCR_PDIV_DIV8                    0x00000300U
#define SCU_SCCR_PDIV_DIV16                   0x00000400U
#define SCU_SCCR_PDIV_DIV32                   0x00000500U
#define SCU_SCCR_PDIV_DIV64                   0x00000600U
#define SCU_SCCR_PDIV_DIV128                  0x00000700U

#define SCU_SCCR_CLKOUTSEL_Pos                (16U)
#define SCU_SCCR_CLKOUTSEL_Msk                (0x3UL << SCU_SCCR_CLKOUTSEL_Pos)                 /*!< 0x00030000 */
#define SCU_SCCR_CLKOUTSEL                    SCU_SCCR_CLKOUTSEL_Msk
#define SCU_SCCR_CLKOUTSEL_0                  (0x1UL << SCU_SCCR_CLKOUTSEL_Pos)                 /*!< 0x00010000 */
#define SCU_SCCR_CLKOUTSEL_1                  (0x2UL << SCU_SCCR_CLKOUTSEL_Pos)                 /*!< 0x00020000 */
#define SCU_SCCR_CLKOUTSEL_SYSCLK             0x00000000U
#define SCU_SCCR_CLKOUTSEL_HSI                SCU_SCCR_CLKOUTSEL_0
#define SCU_SCCR_CLKOUTSEL_LSI                SCU_SCCR_CLKOUTSEL_1
#define SCU_SCCR_CLKOUTSEL_HCLK               (SCU_SCCR_CLKOUTSEL_0 | SCU_SCCR_CLKOUTSEL_1)


#define SCU_SCCR_CLKOUTEN_Pos                 (19U)
#define SCU_SCCR_CLKOUTEN_Msk                 (0x1UL << SCU_SCCR_CLKOUTEN_Pos)                  /*!< 0x00080000 */
#define SCU_SCCR_CLKOUTEN                     SCU_SCCR_CLKOUTEN_Msk
#define SCU_SCCR_CLKOUTDIV_Pos                (20U)
#define SCU_SCCR_CLKOUTDIV_Msk                (0x7UL << SCU_SCCR_CLKOUTDIV_Pos)                 /*!< 0x00700000 */
#define SCU_SCCR_CLKOUTDIV                    SCU_SCCR_CLKOUTDIV_Msk
#define SCU_SCCR_CLKOUTDIV_0                  (0x1UL << SCU_SCCR_CLKOUTDIV_Pos)                 /*!< 0x00100000 */
#define SCU_SCCR_CLKOUTDIV_1                  (0x2UL << SCU_SCCR_CLKOUTDIV_Pos)                 /*!< 0x00200000 */
#define SCU_SCCR_CLKOUTDIV_2                  (0x4UL << SCU_SCCR_CLKOUTDIV_Pos)                 /*!< 0x00400000 */
#define SCU_SCCR_CLKOUTDIV_DIV1               0x00000000U
#define SCU_SCCR_CLKOUTDIV_DIV2               0x00100000U
#define SCU_SCCR_CLKOUTDIV_DIV4               0x00200000U
#define SCU_SCCR_CLKOUTDIV_DIV8               0x00300000U
#define SCU_SCCR_CLKOUTDIV_DIV16              0x00400000U
#define SCU_SCCR_CLKOUTDIV_DIV32              0x00500000U
#define SCU_SCCR_CLKOUTDIV_DIV64              0x00600000U
#define SCU_SCCR_CLKOUTDIV_DIV128             0x00700000U

/********************  Bits definition for SCU_CIER register  *************/
#define SCU_CIER_LSIRDYIE_Pos                 (0U)
#define SCU_CIER_LSIRDYIE_Msk                 (0x1UL << SCU_CIER_LSIRDYIE_Pos)                  /*!< 0x00000001 */
#define SCU_CIER_LSIRDYIE                     SCU_CIER_LSIRDYIE_Msk
#define SCU_CIER_HSIRDYIE_Pos                 (2U)
#define SCU_CIER_HSIRDYIE_Msk                 (0x1UL << SCU_CIER_HSIRDYIE_Pos)                  /*!< 0x00000004 */
#define SCU_CIER_HSIRDYIE                     SCU_CIER_HSIRDYIE_Msk

/********************  Bits definition for SCU_CICR register  *************/
#define SCU_CICR_LSIRDYF_Pos                  (0U)
#define SCU_CICR_LSIRDYF_Msk                  (0x1UL << SCU_CICR_LSIRDYF_Pos)                   /*!< 0x00000001 */
#define SCU_CICR_LSIRDYF                      SCU_CICR_LSIRDYF_Msk
#define SCU_CICR_HSIRDYF_Pos                  (2U)
#define SCU_CICR_HSIRDYF_Msk                  (0x1UL << SCU_CICR_HSIRDYF_Pos)                   /*!< 0x00000004 */
#define SCU_CICR_HSIRDYF                      SCU_CICR_HSIRDYF_Msk

/********************  Bits definition for SCU_AHBRST register  ***********/
#define SCU_AHBRST_GPIOARST_Pos               (0U)
#define SCU_AHBRST_GPIOARST_Msk               (0x1UL << SCU_AHBRST_GPIOARST_Pos)                /*!< 0x00000001 */
#define SCU_AHBRST_GPIOARST                   SCU_AHBRST_GPIOARST_Msk
#define SCU_AHBRST_GPIOBRST_Pos               (1U)
#define SCU_AHBRST_GPIOBRST_Msk               (0x1UL << SCU_AHBRST_GPIOBRST_Pos)                /*!< 0x00000002 */
#define SCU_AHBRST_GPIOBRST                   SCU_AHBRST_GPIOBRST_Msk
#define SCU_AHBRST_DMA1RST_Pos                (4U)
#define SCU_AHBRST_DMA1RST_Msk                (0x1UL << SCU_AHBRST_DMA1RST_Pos)                 /*!< 0x00000008 */
#define SCU_AHBRST_DMA1RST                    SCU_AHBRST_DMA1RST_Msk
#define SCU_AHBRST_CRCRST_Pos                 (5U)
#define SCU_AHBRST_CRCRST_Msk                 (0x1UL << SCU_AHBRST_CRCRST_Pos)                  /*!< 0x00000020 */
#define SCU_AHBRST_CRCRST                     SCU_AHBRST_CRCRST_Msk
#define SCU_AHBRST_DIVSHIFTRST_Pos            (6U)
#define SCU_AHBRST_DIVSHIFTRST_Msk            (0x1UL << SCU_AHBRST_DIVSHIFTRST_Pos)             /*!< 0x00000040 */
#define SCU_AHBRST_DIVSHIFTRST                SCU_AHBRST_DIVSHIFTRST_Msk
#define SCU_AHBRST_FLASHRST_Pos               (8U)
#define SCU_AHBRST_FLASHRST_Msk               (0x1UL << SCU_AHBRST_FLASHRST_Pos)                /*!< 0x00000100 */
#define SCU_AHBRST_FLASHRST                   SCU_AHBRST_FLASHRST_Msk

/********************  Bits definition for SCU_APBRST register  ***********/
#define SCU_APBRST_ATMRRST_Pos                (0U)
#define SCU_APBRST_ATMRRST_Msk                (0x1UL << SCU_APBRST_ATMRRST_Pos)                 /*!< 0x00000001 */
#define SCU_APBRST_ATMRRST                    SCU_APBRST_ATMRRST_Msk
#define SCU_APBRST_GTMRRST_Pos                (1U)
#define SCU_APBRST_GTMRRST_Msk                (0x1UL << SCU_APBRST_GTMRRST_Pos)                 /*!< 0x00000002 */
#define SCU_APBRST_GTMRRST                    SCU_APBRST_GTMRRST_Msk
#define SCU_APBRST_BTMRRST_Pos                (2U)
#define SCU_APBRST_BTMRRST_Msk                (0x1UL << SCU_APBRST_BTMRRST_Pos)                 /*!< 0x00000004 */
#define SCU_APBRST_BTMRRST                    SCU_APBRST_BTMRRST_Msk
#define SCU_APBRST_SPI1RST_Pos                (4U)
#define SCU_APBRST_SPI1RST_Msk                (0x1UL << SCU_APBRST_SPI1RST_Pos)                 /*!< 0x00000010 */
#define SCU_APBRST_SPI1RST                    SCU_APBRST_SPI1RST_Msk
#define SCU_APBRST_UART0RST_Pos               (5U)
#define SCU_APBRST_UART0RST_Msk               (0x1UL << SCU_APBRST_UART0RST_Pos)                /*!< 0x00000020 */
#define SCU_APBRST_UART0RST                   SCU_APBRST_UART0RST_Msk
#define SCU_APBRST_UART1RST_Pos               (6U)
#define SCU_APBRST_UART1RST_Msk               (0x1UL << SCU_APBRST_UART1RST_Pos)                /*!< 0x00000040 */
#define SCU_APBRST_UART1RST                   SCU_APBRST_UART1RST_Msk
#define SCU_APBRST_EINTRST_Pos                (10U)
#define SCU_APBRST_EINTRST_Msk                (0x1UL << SCU_APBRST_EINTRST_Pos)                 /*!< 0x00000400 */
#define SCU_APBRST_EINTRST                    SCU_APBRST_EINTRST_Msk
#define SCU_APBRST_COMPRST_Pos                (13U)
#define SCU_APBRST_COMPRST_Msk                (0x1UL << SCU_APBRST_COMPRST_Pos)                 /*!< 0x00002000 */
#define SCU_APBRST_COMPRST                    SCU_APBRST_COMPRST_Msk
#define SCU_APBRST_ADC1RST_Pos                (14U)
#define SCU_APBRST_ADC1RST_Msk                (0x1UL << SCU_APBRST_ADC1RST_Pos)                 /*!< 0x00004000 */
#define SCU_APBRST_ADC1RST                    SCU_APBRST_ADC1RST_Msk
#define SCU_APBRST_LPTMRRST_Pos               (15U)
#define SCU_APBRST_LPTMRRST_Msk               (0x1UL << SCU_APBRST_LPTMRRST_Pos)                /*!< 0x00008000 */
#define SCU_APBRST_LPTMRRST                   SCU_APBRST_LPTMRRST_Msk

/********************  Bits definition for SCU_AHBCG register  ************/
#define SCU_AHBCG_GPIOAEN_Pos                 (0U)
#define SCU_AHBCG_GPIOAEN_Msk                 (0x1UL << SCU_AHBCG_GPIOAEN_Pos)                  /*!< 0x00000002 */
#define SCU_AHBCG_GPIOAEN                     SCU_AHBCG_GPIOAEN_Msk
#define SCU_AHBCG_GPIOBEN_Pos                 (1U)
#define SCU_AHBCG_GPIOBEN_Msk                 (0x1UL << SCU_AHBCG_GPIOBEN_Pos)                  /*!< 0x00000002 */
#define SCU_AHBCG_GPIOBEN                     SCU_AHBCG_GPIOBEN_Msk
#define SCU_AHBCG_DMA1EN_Pos                  (4U)
#define SCU_AHBCG_DMA1EN_Msk                  (0x1UL << SCU_AHBCG_DMA1EN_Pos)                   /*!< 0x00000001 */
#define SCU_AHBCG_DMA1EN                      SCU_AHBCG_DMA1EN_Msk
#define SCU_AHBCG_CRCEN_Pos                   (5U)
#define SCU_AHBCG_CRCEN_Msk                   (0x1UL << SCU_AHBCG_CRCEN_Pos)                    /*!< 0x00000004 */
#define SCU_AHBCG_CRCEN                       SCU_AHBCG_CRCEN_Msk
#define SCU_AHBCG_DIVSHIFTEN_Pos              (6U)
#define SCU_AHBCG_DIVSHIFTEN_Msk              (0x1UL << SCU_AHBCG_DIVSHIFTEN_Pos)               /*!< 0x00000008 */
#define SCU_AHBCG_DIVSHIFTEN                  SCU_AHBCG_DIVSHIFTEN_Msk

/********************  Bits definition for SCU_APBCG register  ************/
#define SCU_APBCG_ATMREN_Pos                  (0U)
#define SCU_APBCG_ATMREN_Msk                  (0x1UL << SCU_APBCG_ATMREN_Pos)                   /*!< 0x00000001 */
#define SCU_APBCG_ATMREN                      SCU_APBCG_ATMREN_Msk
#define SCU_APBCG_GTMREN_Pos                  (1U)
#define SCU_APBCG_GTMREN_Msk                  (0x1UL << SCU_APBCG_GTMREN_Pos)                   /*!< 0x00000002 */
#define SCU_APBCG_GTMREN                      SCU_APBCG_GTMREN_Msk
#define SCU_APBCG_BTMREN_Pos                  (2U)
#define SCU_APBCG_BTMREN_Msk                  (0x1UL << SCU_APBCG_BTMREN_Pos)                   /*!< 0x00000004 */
#define SCU_APBCG_BTMREN                      SCU_APBCG_BTMREN_Msk
#define SCU_APBCG_SPI1EN_Pos                  (4U)
#define SCU_APBCG_SPI1EN_Msk                  (0x1UL << SCU_APBCG_SPI1EN_Pos)                   /*!< 0x00000010 */
#define SCU_APBCG_SPI1EN                      SCU_APBCG_SPI1EN_Msk
#define SCU_APBCG_UART0EN_Pos                 (5U)
#define SCU_APBCG_UART0EN_Msk                 (0x1UL << SCU_APBCG_UART0EN_Pos)                  /*!< 0x00000020 */
#define SCU_APBCG_UART0EN                     SCU_APBCG_UART0EN_Msk
#define SCU_APBCG_UART1EN_Pos                 (6U)
#define SCU_APBCG_UART1EN_Msk                 (0x1UL << SCU_APBCG_UART1EN_Pos)                  /*!< 0x00000040 */
#define SCU_APBCG_UART1EN                     SCU_APBCG_UART1EN_Msk
#define SCU_APBCG_WWDTEN_Pos                  (8U)
#define SCU_APBCG_WWDTEN_Msk                  (0x1UL << SCU_APBCG_WWDTEN_Pos)
#define SCU_APBCG_WWDTEN                      SCU_APBCG_WWDTEN_Msk
#define SCU_APBCG_EINTEN_Pos                  (10U)
#define SCU_APBCG_EINTEN_Msk                  (0x1UL << SCU_APBCG_EINTEN_Pos)                   /*!< 0x00000400 */
#define SCU_APBCG_EINTEN                      SCU_APBCG_EINTEN_Msk
#define SCU_APBCG_COMPEN_Pos                  (13U)
#define SCU_APBCG_COMPEN_Msk                  (0x1UL << SCU_APBCG_COMPEN_Pos)                   /*!< 0x00002000 */
#define SCU_APBCG_COMPEN                      SCU_APBCG_COMPEN_Msk
#define SCU_APBCG_ADC1EN_Pos                  (14U)
#define SCU_APBCG_ADC1EN_Msk                  (0x1UL << SCU_APBCG_ADC1EN_Pos)                   /*!< 0x00004000 */
#define SCU_APBCG_ADC1EN                      SCU_APBCG_ADC1EN_Msk
#define SCU_APBCG_LPTMREN_Pos                 (15U)
#define SCU_APBCG_LPTMREN_Msk                 (0x1UL << SCU_APBCG_LPTMREN_Pos)                  /*!< 0x00008000 */
#define SCU_APBCG_LPTMREN                     SCU_APBCG_LPTMREN_Msk

/********************  Bits definition for SCU_RSTCSR register  ***********/
#define SCU_RSTCSR_OPRSTF_Pos                 (0U)
#define SCU_RSTCSR_OPRSTF_Msk                 (0x1UL << SCU_RSTCSR_OPRSTF_Pos)                  /*!< 0x00000001 */
#define SCU_RSTCSR_OPRSTF                     SCU_RSTCSR_OPRSTF_Msk
#define SCU_RSTCSR_NRSTRSTF_Pos               (1U)
#define SCU_RSTCSR_NRSTRSTF_Msk               (0x1UL << SCU_RSTCSR_NRSTRSTF_Pos)                /*!< 0x00000002 */
#define SCU_RSTCSR_NRSTRSTF                   SCU_RSTCSR_NRSTRSTF_Msk
#define SCU_RSTCSR_PVDRSTF_Pos                (2U)
#define SCU_RSTCSR_PVDRSTF_Msk                (0x1UL << SCU_RSTCSR_PVDRSTF_Pos)                 /*!< 0x00000004 */
#define SCU_RSTCSR_PVDRSTF                    SCU_RSTCSR_PVDRSTF_Msk
#define SCU_RSTCSR_SFTRSTF_Pos                (3U)
#define SCU_RSTCSR_SFTRSTF_Msk                (0x1UL << SCU_RSTCSR_SFTRSTF_Pos)                 /*!< 0x00000008 */
#define SCU_RSTCSR_SFTRSTF                    SCU_RSTCSR_SFTRSTF_Msk
#define SCU_RSTCSR_IWDTRSTF_Pos               (4U)
#define SCU_RSTCSR_IWDTRSTF_Msk               (0x1UL << SCU_RSTCSR_IWDTRSTF_Pos)                /*!< 0x00000010 */
#define SCU_RSTCSR_IWDTRSTF                   SCU_RSTCSR_IWDTRSTF_Msk
#define SCU_RSTCSR_WWDTRSTF_Pos               (5U)
#define SCU_RSTCSR_WWDTRSTF_Msk               (0x1UL << SCU_RSTCSR_WWDTRSTF_Pos)                /*!< 0x00000020 */
#define SCU_RSTCSR_WWDTRSTF                   SCU_RSTCSR_WWDTRSTF_Msk
#define SCU_RSTCSR_LOCKUPRSTF_Pos             (6U)
#define SCU_RSTCSR_LOCKUPRSTF_Msk             (0x1UL << SCU_RSTCSR_LOCKUPRSTF_Pos)              /*!< 0x00000040 */
#define SCU_RSTCSR_LOCKUPRSTF                 SCU_RSTCSR_LOCKUPRSTF_Msk
#define SCU_RSTCSR_PORRSTF_Pos                (7U)
#define SCU_RSTCSR_PORRSTF_Msk                (0x1UL << SCU_RSTCSR_PORRSTF_Pos)                 /*!< 0x00000080 */
#define SCU_RSTCSR_PORRSTF                    SCU_RSTCSR_PORRSTF_Msk
#define SCU_RSTCSR_PVDRST_EN_Pos              (14U)
#define SCU_RSTCSR_PVDRST_EN_Msk              (0x1UL << SCU_RSTCSR_PVDRST_EN_Pos)               /*!< 0x00004000 */
#define SCU_RSTCSR_PVDRST_EN                  SCU_RSTCSR_PVDRST_EN_Msk
#define SCU_RSTCSR_LOCKUPRST_EN_Pos           (15U)
#define SCU_RSTCSR_LOCKUPRST_EN_Msk           (0x1UL << SCU_RSTCSR_LOCKUPRST_EN_Pos)            /*!< 0x00008000 */
#define SCU_RSTCSR_LOCKUPRST_EN               SCU_RSTCSR_LOCKUPRST_EN_Msk

/********************  Bits definition for SCU_ADCCR register  ************/
#define SCU_ADCCR_ADCCLK_DIV_Pos              (0UL)                                             /*!< ADCCLK_DIV (Bit 0) */
#define SCU_ADCCR_ADCCLK_DIV_0                (0x1UL << SCU_ADCCR_ADCCLK_DIV_Pos)
#define SCU_ADCCR_ADCCLK_DIV_1                (0x2UL << SCU_ADCCR_ADCCLK_DIV_Pos)
#define SCU_ADCCR_ADCCLK_DIV_Msk              (0x3UL << SCU_ADCCR_ADCCLK_DIV_Pos)               /*!< ADCCLK_DIV (Bitfield-Mask: 0x03) */
#define SCU_ADCCR_ADCCLK_DIV                  SCU_ADCCR_ADCCLK_DIV_Msk

/********************  Bits definition for SCU_OPAMPCR register  **************/
#define SCU_OPAMPCR_OPAMP0_EN_Pos             (0UL)                                             /*!< OPA0_EN (Bit 0) */
#define SCU_OPAMPCR_OPAMP0_EN_Msk             (0x1UL << SCU_OPAMPCR_OPAMP0_EN_Pos)              /*!< OPA0_EN (Bitfield-Mask: 0x01) */
#define SCU_OPAMPCR_OPAMP0_EN                 SCU_OPAMPCR_OPAMP0_EN_Msk
#define SCU_OPAMPCR_OPAMP0_SEL_GAIN_Pos       (1UL)                                             /*!< OPA0_SEL_GAIN (Bit 1) */
#define SCU_OPAMPCR_OPAMP0_SEL_GAIN_0         (0x1UL << SCU_OPAMPCR_OPAMP0_SEL_GAIN_Pos)
#define SCU_OPAMPCR_OPAMP0_SEL_GAIN_1         (0x2UL << SCU_OPAMPCR_OPAMP0_SEL_GAIN_Pos)
#define SCU_OPAMPCR_OPAMP0_SEL_GAIN_2         (0x4UL << SCU_OPAMPCR_OPAMP0_SEL_GAIN_Pos)
#define SCU_OPAMPCR_OPAMP0_SEL_GAIN_Msk       (0x7UL << SCU_OPAMPCR_OPAMP0_SEL_GAIN_Pos)        /*!< OPA0_SEL_GAIN (Bitfield-Mask: 0x07) */
#define SCU_OPAMPCR_OPAMP0_SEL_GAIN           SCU_OPAMPCR_OPAMP0_SEL_GAIN_Msk
#define SCU_OPAMPCR_OPAMP0_IN_CTRL_Pos        (4UL)                                             /*!< OPA0_IN_CTRL (Bit 4) */
#define SCU_OPAMPCR_OPAMP0_IN_CTRL_Msk        (0x1UL << SCU_OPAMPCR_OPAMP0_IN_CTRL_Pos)         /*!< OPA0_IN_CTRL (Bitfield-Mask: 0x01) */
#define SCU_OPAMPCR_OPAMP0_IN_CTRL            SCU_OPAMPCR_OPAMP0_IN_CTRL_Msk
#define SCU_OPAMPCR_OPAMP0_OUT_CTRL_Pos       (5UL)                                             /*!< OPA0_OUT_CTRL (Bit 5) */
#define SCU_OPAMPCR_OPAMP0_OUT_CTRL_Msk       (0x1UL << SCU_OPAMPCR_OPAMP0_OUT_CTRL_Pos)        /*!< OPA0_OUT_CTRL (Bitfield-Mask: 0x01) */
#define SCU_OPAMPCR_OPAMP0_OUT_CTRL           SCU_OPAMPCR_OPAMP0_OUT_CTRL_Msk

#define SCU_OPAMPCR_OPAMP1_EN_Pos             (8UL)                                             /*!< OPA1_EN (Bit 8) */
#define SCU_OPAMPCR_OPAMP1_EN_Msk             (0x1UL << SCU_OPAMPCR_OPAMP1_EN_Pos)              /*!< OPA1_EN (Bitfield-Mask: 0x01) */
#define SCU_OPAMPCR_OPAMP1_EN                 SCU_OPAMPCR_OPAMP1_EN_Msk
#define SCU_OPAMPCR_OPAMP1_SEL_GAIN_Pos       (9UL)                                             /*!< OPA1_SEL_GAIN (Bit 9) */
#define SCU_OPAMPCR_OPAMP1_SEL_GAIN_0         (0x1UL << SCU_OPAMPCR_OPAMP1_SEL_GAIN_Pos)
#define SCU_OPAMPCR_OPAMP1_SEL_GAIN_1         (0x2UL << SCU_OPAMPCR_OPAMP1_SEL_GAIN_Pos)
#define SCU_OPAMPCR_OPAMP1_SEL_GAIN_2         (0x4UL << SCU_OPAMPCR_OPAMP1_SEL_GAIN_Pos)
#define SCU_OPAMPCR_OPAMP1_SEL_GAIN_Msk       (0x7UL << SCU_OPAMPCR_OPAMP1_SEL_GAIN_Pos)        /*!< OPA1_SEL_GAIN (Bitfield-Mask: 0x07) */
#define SCU_OPAMPCR_OPAMP1_SEL_GAIN           SCU_OPAMPCR_OPAMP1_SEL_GAIN_Msk
#define SCU_OPAMPCR_OPAMP1_IN_CTRL_Pos        (12UL)                                            /*!< OPA1_IN_CTRL (Bit 12) */
#define SCU_OPAMPCR_OPAMP1_IN_CTRL_Msk        (0x1UL << SCU_OPAMPCR_OPAMP1_IN_CTRL_Pos)         /*!< OPA1_IN_CTRL (Bitfield-Mask: 0x01) */
#define SCU_OPAMPCR_OPAMP1_IN_CTRL            SCU_OPAMPCR_OPAMP1_IN_CTRL_Msk
#define SCU_OPAMPCR_OPAMP1_OUT_CTRL_Pos       (13UL)                                            /*!< OPA1_OUT_CTRL (Bit 13) */
#define SCU_OPAMPCR_OPAMP1_OUT_CTRL_Msk       (0x1UL << SCU_OPAMPCR_OPAMP1_OUT_CTRL_Pos)        /*!< OPA1_OUT_CTRL (Bitfield-Mask: 0x01) */
#define SCU_OPAMPCR_OPAMP1_OUT_CTRL           SCU_OPAMPCR_OPAMP1_OUT_CTRL_Msk

#define SCU_OPAMPCR_OPAMP_SEL_MUX_Pos         (16UL)                                            /*!< OPA_SEL_MUX (Bit 9) */
#define SCU_OPAMPCR_OPAMP_SEL_MUX_0           (0x1UL << SCU_OPAMPCR_OPAMP_SEL_MUX_Pos)
#define SCU_OPAMPCR_OPAMP_SEL_MUX_1           (0x2UL << SCU_OPAMPCR_OPAMP_SEL_MUX_Pos)
#define SCU_OPAMPCR_OPAMP_SEL_MUX_2           (0x4UL << SCU_OPAMPCR_OPAMP_SEL_MUX_Pos)
#define SCU_OPAMPCR_OPAMP_SEL_MUX_Msk         (0x7UL << SCU_OPAMPCR_OPAMP_SEL_MUX_Pos)          /*!< OPA_SEL_MUX (Bitfield-Mask: 0x07) */
#define SCU_OPAMPCR_OPAMP_SEL_MUX             SCU_OPAMPCR_OPAMP_SEL_MUX_Msk

/********************  Bits definition for SCU_PVDCSR register  ***********/
#define SCU_PVDCSR_PVDEN_Pos                  (0UL)                                             /*!< PVD_EN (Bit 0) */
#define SCU_PVDCSR_PVDEN_Msk                  (0x1UL << SCU_PVDCSR_PVDEN_Pos)                   /*!< PVD_EN (Bitfield-Mask: 0x01) */
#define SCU_PVDCSR_PVDEN                      SCU_PVDCSR_PVDEN_Msk
#define SCU_PVDCSR_PVDTHSEL_Pos               (1UL)                                             /*!< PVDTHSEL (Bit 1) */
#define SCU_PVDCSR_PVDTHSEL_0                 (0x1UL << SCU_PVDCSR_PVDTHSEL_Pos)
#define SCU_PVDCSR_PVDTHSEL_1                 (0x2UL << SCU_PVDCSR_PVDTHSEL_Pos)
#define SCU_PVDCSR_PVDTHSEL_2                 (0x4UL << SCU_PVDCSR_PVDTHSEL_Pos)
#define SCU_PVDCSR_PVDTHSEL_Msk               (0x7UL << SCU_PVDCSR_PVDTHSEL_Pos)                /*!< PVDTHSEL (Bitfield-Mask: 0x07) */
#define SCU_PVDCSR_PVDTHSEL                   SCU_PVDCSR_PVDTHSEL_Msk
#define SCU_PVDCSR_PVD_LT_Pos                 (4UL)                                             /*!< PVD_LT (Bit 4) */
#define SCU_PVDCSR_PVD_LT_Msk                 (0x1UL << SCU_PVDCSR_PVD_LT_Pos)                  /*!< PVD_LT (Bitfield-Mask: 0x01) */
#define SCU_PVDCSR_PVD_LT                     SCU_PVDCSR_PVD_LT_Msk
#define SCU_PVDCSR_PVD_HT_Pos                 (5UL)                                             /*!< PVD_HT (Bit 5) */
#define SCU_PVDCSR_PVD_HT_Msk                 (0x1UL << SCU_PVDCSR_PVD_HT_Pos)                  /*!< PVD_HT (Bitfield-Mask: 0x01) */
#define SCU_PVDCSR_PVD_HT                     SCU_PVDCSR_PVD_HT_Msk
#define SCU_PVDCSR_PVDF_Pos                   (14UL)                                            /*!< PVDF (Bit 14) */
#define SCU_PVDCSR_PVDF_Msk                   (0x1UL << SCU_PVDCSR_PVDF_Pos)                    /*!< PVDF (Bitfield-Mask: 0x01) */
#define SCU_PVDCSR_PVDF                       SCU_PVDCSR_PVDF_Msk
#define SCU_PVDCSR_PVDO_Pos                   (15UL)                                            /*!< PVDO (Bit 15) */
#define SCU_PVDCSR_PVDO_Msk                   (0x1UL << SCU_PVDCSR_PVDO_Pos)                    /*!< PVDO (Bitfield-Mask: 0x01) */
#define SCU_PVDCSR_PVDO                       SCU_PVDCSR_PVDO_Msk

/********************  Bits definition for SCU_KEY register  **************/
#define SCU_PREDRVCR_PREDRV_EN_Pos            (0UL)                                             /*!< PREDRV_EN (Bit 0) */
#define SCU_PREDRVCR_PREDRV_EN_Msk            (0x1UL << SCU_PREDRVCR_PREDRV_EN_Pos)             /*!< PREDRV_EN (Bitfield-Mask: 0x01) */
#define SCU_PREDRVCR_PREDRV_EN                SCU_PREDRVCR_PREDRV_EN_Msk
#define SCU_PREDRVCR_PREDRV_SW_Pos            (1UL)                                             /*!< PREDRV_SW (Bit 1) */
#define SCU_PREDRVCR_PREDRV_SW_Msk            (0x1UL << SCU_PREDRVCR_PREDRV_SW_Pos)             /*!< PREDRV_SW (Bitfield-Mask: 0x01) */
#define SCU_PREDRVCR_PREDRV_SW                SCU_PREDRVCR_PREDRV_SW_Msk
#define SCU_PREDRVCR_PREDRV_LO_FALL_SEL_Pos   (4UL)                                             /*!< PREDRV_LO_FALL_SEL (Bit 4) */
#define SCU_PREDRVCR_PREDRV_LO_FALL_SEL_0     (0x1UL << SCU_PREDRVCR_PREDRV_LO_FALL_SEL_Pos)
#define SCU_PREDRVCR_PREDRV_LO_FALL_SEL_1     (0x2UL << SCU_PREDRVCR_PREDRV_LO_FALL_SEL_Pos)
#define SCU_PREDRVCR_PREDRV_LO_FALL_SEL_Msk   (0x3UL << SCU_PREDRVCR_PREDRV_LO_FALL_SEL_Pos)    /*!< PREDRV_LO_FALL_SEL (Bitfield-Mask: 0x03) */
#define SCU_PREDRVCR_PREDRV_LO_FALL_SEL       SCU_PREDRVCR_PREDRV_LO_FALL_SEL_Msk
#define SCU_PREDRVCR_PREDRV_LO_RISE_SEL_Pos   (6UL)                                             /*!< PREDRV_LO_RISE_SEL (Bit 6) */
#define SCU_PREDRVCR_PREDRV_LO_RISE_SEL_0     (0x1UL << SCU_PREDRVCR_PREDRV_LO_RISE_SEL_Pos)
#define SCU_PREDRVCR_PREDRV_LO_RISE_SEL_1     (0x2UL << SCU_PREDRVCR_PREDRV_LO_RISE_SEL_Pos)
#define SCU_PREDRVCR_PREDRV_LO_RISE_SEL_Msk   (0x3UL << SCU_PREDRVCR_PREDRV_LO_RISE_SEL_Pos)    /*!< PREDRV_LO_RISE_SEL (Bitfield-Mask: 0x03) */
#define SCU_PREDRVCR_PREDRV_LO_RISE_SEL       SCU_PREDRVCR_PREDRV_LO_RISE_SEL_Msk
#define SCU_PREDRVCR_PREDRV_HO_FALL_SEL_Pos   (8UL)                                             /*!< PREDRV_HO_FALL_SEL (Bit 8) */
#define SCU_PREDRVCR_PREDRV_HO_FALL_SEL_0     (0x1UL << SCU_PREDRVCR_PREDRV_HO_FALL_SEL_Pos)
#define SCU_PREDRVCR_PREDRV_HO_FALL_SEL_1     (0x2UL << SCU_PREDRVCR_PREDRV_HO_FALL_SEL_Pos)
#define SCU_PREDRVCR_PREDRV_HO_FALL_SEL_Msk   (0x3UL << SCU_PREDRVCR_PREDRV_HO_FALL_SEL_Pos)    /*!< PREDRV_HO_FALL_SEL (Bitfield-Mask: 0x03) */
#define SCU_PREDRVCR_PREDRV_HO_FALL_SEL       SCU_PREDRVCR_PREDRV_HO_FALL_SEL_Msk
#define SCU_PREDRVCR_PREDRV_HO_RISE_SEL_Pos   (10UL)                                            /*!< PREDRV_HO_RISE_SEL (Bit 10) */
#define SCU_PREDRVCR_PREDRV_HO_RISE_SEL_0     (0x1UL << SCU_PREDRVCR_PREDRV_HO_RISE_SEL_Pos)
#define SCU_PREDRVCR_PREDRV_HO_RISE_SEL_1     (0x2UL << SCU_PREDRVCR_PREDRV_HO_RISE_SEL_Pos)
#define SCU_PREDRVCR_PREDRV_HO_RISE_SEL_Msk   (0x3UL << SCU_PREDRVCR_PREDRV_HO_RISE_SEL_Pos)    /*!< PREDRV_HO_RISE_SEL (Bitfield-Mask: 0x03) */
#define SCU_PREDRVCR_PREDRV_HO_RISE_SEL       SCU_PREDRVCR_PREDRV_HO_RISE_SEL_Msk

/********************  Bits definition for SCU_KEY register  **************/
#define SCU_LVDCSR_LVDF_Pos                   (0UL)                                             /*!< LVDF (Bit 0) */
#define SCU_LVDCSR_LVDF_Msk                   (0x1UL << SCU_LVDCSR_LVDF_Pos)                    /*!< LVDF (Bitfield-Mask: 0x01) */
#define SCU_LVDCSR_LVDF                       SCU_LVDCSR_LVDF_Msk
#define SCU_LVDCSR_LVD_IE_Pos                 (4UL)                                             /*!< LVD_IE (Bit 4) */
#define SCU_LVDCSR_LVD_IE_Msk                 (0x1UL << SCU_LVDCSR_LVD_IE_Pos)                  /*!< LVD_IE (Bitfield-Mask: 0x01) */
#define SCU_LVDCSR_LVD_IE                     SCU_LVDCSR_LVD_IE_Msk

/******************************************************************************/
/*                                                                            */
/*         Universal Synchronous Asynchronous Receiver Transmitter            */
/*                                                                            */
/******************************************************************************/
/*******************  Bit definition for USART_STS register  *******************/
#define USART_STS_PEFLG_Pos                   (0U)
#define USART_STS_PEFLG_Msk                   (0x1UL << USART_STS_PEFLG_Pos)                    /*!< 0x00000001 */
#define USART_STS_PEFLG                       USART_STS_PEFLG_Msk                               /*!<Parity Error                 */
#define USART_STS_FEFLG_Pos                   (1U)
#define USART_STS_FEFLG_Msk                   (0x1UL << USART_STS_FEFLG_Pos)                    /*!< 0x00000002 */
#define USART_STS_FEFLG                       USART_STS_FEFLG_Msk                               /*!<Framing Error                */
#define USART_STS_NEFLG_Pos                   (2U)
#define USART_STS_NEFLG_Msk                   (0x1UL << USART_STS_NEFLG_Pos)                    /*!< 0x00000004 */
#define USART_STS_NEFLG                       USART_STS_NEFLG_Msk                               /*!<Noise Error Flag             */
#define USART_STS_OVREFLG_Pos                 (3U)
#define USART_STS_OVREFLG_Msk                 (0x1UL << USART_STS_OVREFLG_Pos)                  /*!< 0x00000008 */
#define USART_STS_OVREFLG                     USART_STS_OVREFLG_Msk                             /*!<OverRun Error                */
#define USART_STS_IDLEFLG_Pos                 (4U)
#define USART_STS_IDLEFLG_Msk                 (0x1UL << USART_STS_IDLEFLG_Pos)                  /*!< 0x00000010 */
#define USART_STS_IDLEFLG                     USART_STS_IDLEFLG_Msk                             /*!<IDLE line detected           */
#define USART_STS_RXNEFLG_Pos                 (5U)
#define USART_STS_RXNEFLG_Msk                 (0x1UL << USART_STS_RXNEFLG_Pos)                  /*!< 0x00000020 */
#define USART_STS_RXNEFLG                     USART_STS_RXNEFLG_Msk                             /*!<Read Data Register Not Empty */
#define USART_STS_TXCFLG_Pos                  (6U)
#define USART_STS_TXCFLG_Msk                  (0x1UL << USART_STS_TXCFLG_Pos)                   /*!< 0x00000040 */
#define USART_STS_TXCFLG                      USART_STS_TXCFLG_Msk                              /*!<Transmission Complete        */
#define USART_STS_TXEFLG_Pos                  (7U)
#define USART_STS_TXEFLG_Msk                  (0x1UL << USART_STS_TXEFLG_Pos)                   /*!< 0x00000080 */
#define USART_STS_TXEFLG                      USART_STS_TXEFLG_Msk                              /*!<Transmit Data Register Empty */
#define USART_STS_LBDFLG_Pos                  (8U)
#define USART_STS_LBDFLG_Msk                  (0x1UL << USART_STS_LBDFLG_Pos)                   /*!< 0x00000100 */
#define USART_STS_LBDFLG                      USART_STS_LBDFLG_Msk                              /*!<LIN Break Detection Flag     */
#define USART_STS_RXTOFLG_Pos                 (10U)
#define USART_STS_RXTOFLG_Msk                 (0x1UL << USART_STS_RXTOFLG_Pos)                  /*!< 0x00000400 */
#define USART_STS_RXTOFLG                     USART_STS_RXTOFLG_Msk                             /*!<RXTO Flag                     */
#define USART_STS_ABRDFLG_Pos                 (11U)
#define USART_STS_ABRDFLG_Msk                 (0x1UL << USART_STS_ABRDFLG_Pos)                  /*!< 0x00000800 */
#define USART_STS_ABRDFLG                     USART_STS_ABRDFLG_Msk                             /*!<ABC Flag                     */
#define USART_STS_ABRDEFLG_Pos                (12U)
#define USART_STS_ABRDEFLG_Msk                (0x1UL << USART_STS_ABRDEFLG_Pos)                 /*!< 0x00001000 */
#define USART_STS_ABRDEFLG                    USART_STS_ABRDEFLG_Msk                            /*!<ABERR Flag                     */


/*******************  Bit definition for USART_DATA register  *******************/
#define USART_DATA_DATA_Pos                   (0U)
#define USART_DATA_DATA_Msk                   (0x1FFUL << USART_DATA_DATA_Pos)                  /*!< 0x000001FF */
#define USART_DATA_DATA                       USART_DATA_DATA_Msk                               /*!<Data value */

/******************  Bit definition for USART_BR register  ********************/
#define USART_BR_FBR_Pos                      (0U)
#define USART_BR_FBR_Msk                      (0xFUL << USART_BR_FBR_Pos)                       /*!< 0x0000000F */
#define USART_BR_FBR                          USART_BR_FBR_Msk                                  /*!<Fraction of USARTDIV */
#define USART_BR_IBR_Pos                      (4U)
#define USART_BR_IBR_Msk                      (0xFFFUL << USART_BR_IBR_Pos)                     /*!< 0x0000FFF0 */
#define USART_BR_IBR                          USART_BR_IBR_Msk                                  /*!<Mantissa of USARTDIV */

/******************  Bit definition for USART_CR1 register  *******************/
#define USART_CTRL1_TXBF_Pos                  (0U)
#define USART_CTRL1_TXBF_Msk                  (0x1UL << USART_CTRL1_TXBF_Pos)                   /*!< 0x00000001 */
#define USART_CTRL1_TXBF                      USART_CTRL1_TXBF_Msk                              /*!<Send Break                             */
#define USART_CTRL1_RXEN_Pos                  (2U)
#define USART_CTRL1_RXEN_Msk                  (0x1UL << USART_CTRL1_RXEN_Pos)                   /*!< 0x00000004 */
#define USART_CTRL1_RXEN                      USART_CTRL1_RXEN_Msk                              /*!<Receiver Enable                        */
#define USART_CTRL1_TXEN_Pos                  (3U)
#define USART_CTRL1_TXEN_Msk                  (0x1UL << USART_CTRL1_TXEN_Pos)                   /*!< 0x00000008 */
#define USART_CTRL1_TXEN                      USART_CTRL1_TXEN_Msk                              /*!<Transmitter Enable                     */
#define USART_CTRL1_IDLEIEN_Pos               (4U)
#define USART_CTRL1_IDLEIEN_Msk               (0x1UL << USART_CTRL1_IDLEIEN_Pos)                /*!< 0x00000010 */
#define USART_CTRL1_IDLEIEN                   USART_CTRL1_IDLEIEN_Msk                           /*!<IDLE Interrupt Enable                  */
#define USART_CTRL1_RXNEIEN_Pos               (5U)
#define USART_CTRL1_RXNEIEN_Msk               (0x1UL << USART_CTRL1_RXNEIEN_Pos)                /*!< 0x00000020 */
#define USART_CTRL1_RXNEIEN                   USART_CTRL1_RXNEIEN_Msk                           /*!<RXNE Interrupt Enable                  */
#define USART_CTRL1_TXCIEN_Pos                (6U)
#define USART_CTRL1_TXCIEN_Msk                (0x1UL << USART_CTRL1_TXCIEN_Pos)                 /*!< 0x00000040 */
#define USART_CTRL1_TXCIEN                    USART_CTRL1_TXCIEN_Msk                            /*!<Transmission Complete Interrupt Enable */
#define USART_CTRL1_TXEIEN_Pos                (7U)
#define USART_CTRL1_TXEIEN_Msk                (0x1UL << USART_CTRL1_TXEIEN_Pos)                 /*!< 0x00000080 */
#define USART_CTRL1_TXEIEN                    USART_CTRL1_TXEIEN_Msk                            /*!<TXE Interrupt Enable                   */
#define USART_CTRL1_PEIEN_Pos                 (8U)
#define USART_CTRL1_PEIEN_Msk                 (0x1UL << USART_CTRL1_PEIEN_Pos)                  /*!< 0x00000100 */
#define USART_CTRL1_PEIEN                     USART_CTRL1_PEIEN_Msk                             /*!<PE Interrupt Enable                    */
#define USART_CTRL1_PCFG_Pos                  (9U)
#define USART_CTRL1_PCFG_Msk                  (0x1UL << USART_CTRL1_PCFG_Pos)                   /*!< 0x00000200 */
#define USART_CTRL1_PCFG                      USART_CTRL1_PCFG_Msk                              /*!<Parity Selection                       */
#define USART_CTRL1_PCEN_Pos                  (10U)
#define USART_CTRL1_PCEN_Msk                  (0x1UL << USART_CTRL1_PCEN_Pos)                   /*!< 0x00000400 */
#define USART_CTRL1_PCEN                      USART_CTRL1_PCEN_Msk                              /*!<Parity Control Enable                  */
#define USART_CTRL1_DBLCFG_Pos                (12U)
#define USART_CTRL1_DBLCFG_Msk                (0x1UL << USART_CTRL1_DBLCFG_Pos)                 /*!< 0x00001000 */
#define USART_CTRL1_DBLCFG                    USART_CTRL1_DBLCFG_Msk                            /*!<Word length                            */
#define USART_CTRL1_UEN_Pos                   (13U)
#define USART_CTRL1_UEN_Msk                   (0x1UL << USART_CTRL1_UEN_Pos)                    /*!< 0x00002000 */
#define USART_CTRL1_UEN                       USART_CTRL1_UEN_Msk                               /*!<USART Enable                           */
#define USART_CTRL1_RXTODEN_Pos               (26U)
#define USART_CTRL1_RXTODEN_Msk               (0x1UL << USART_CTRL1_RXTODEN_Pos)                /*!< 0x00008000 */
#define USART_CTRL1_RXTODEN                   USART_CTRL1_RXTODEN_Msk                           /*!<USART Receive Timeout Detection Function Enable     */
#define USART_CTRL1_RXTOIEN_Pos               (27U)
#define USART_CTRL1_RXTOIEN_Msk               (0x1UL << USART_CTRL1_RXTOIEN_Pos)                /*!< 0x04000000 */
#define USART_CTRL1_RXTOIEN                   USART_CTRL1_RXTOIEN_Msk                           /*!<USART Receive Timeout Detection Function Enable       */
#define USART_CTRL1_SWAPEN_Pos                (28U)
#define USART_CTRL1_SWAPEN_Msk                (0x1UL << USART_CTRL1_SWAPEN_Pos)                 /*!< 0x08000000 */
#define USART_CTRL1_SWAPEN                    USART_CTRL1_SWAPEN_Msk                            /*!<USART Swap TX/RX Pins Function Enable        */

/******************  Bit definition for USART_CTRL2 register  *******************/
#define USART_CTRL2_LBDLCFG_Pos               (5U)
#define USART_CTRL2_LBDLCFG_Msk               (0x1UL << USART_CTRL2_LBDLCFG_Pos)                /*!< 0x00000020 */
#define USART_CTRL2_LBDLCFG                   USART_CTRL2_LBDLCFG_Msk                           /*!<LIN Break Detection Length           */
#define USART_CTRL2_LBDIEN_Pos                (6U)
#define USART_CTRL2_LBDIEN_Msk                (0x1UL << USART_CTRL2_LBDIEN_Pos)                 /*!< 0x00000040 */
#define USART_CTRL2_LBDIEN                    USART_CTRL2_LBDIEN_Msk                            /*!<LIN Break Detection Interrupt Enable */
#define USART_CTRL2_STOPCFG_Pos               (13U)
#define USART_CTRL2_STOPCFG_Msk               (0x1UL << USART_CTRL2_STOPCFG_Pos)                /*!< 0x00002000 */
#define USART_CTRL2_STOPCFG                   USART_CTRL2_STOPCFG_Msk                           /*!< STOP bits (STOP bits) */
#define USART_CTRL2_LINMEN_Pos                (14U)
#define USART_CTRL2_LINMEN_Msk                (0x1UL << USART_CTRL2_LINMEN_Pos)                 /*!< 0x00004000 */
#define USART_CTRL2_LINMEN                    USART_CTRL2_LINMEN_Msk                            /*!<LIN mode enable */
#define USART_CTRL2_ABRDEN_Pos                (16U)
#define USART_CTRL2_ABRDEN_Msk                (0x1UL << USART_CTRL2_ABRDEN_Pos)                 /*!< 0x00010000 */
#define USART_CTRL2_ABRDEN                    USART_CTRL2_ABRDEN_Msk                            /*!<Automatic porter rate mode enable */
#define USART_CTRL2_ABRCIEN_Pos               (17U)
#define USART_CTRL2_ABRCIEN_Msk               (0x1UL << USART_CTRL2_ABRCIEN_Pos)                /*!< 0x00020000 */
#define USART_CTRL2_ABRCIEN                   USART_CTRL2_ABRCIEN_Msk                           /*!<Automatic porter rate interrupt mode enable */
#define USART_CTRL2_ADREIEN_Pos               (18U)
#define USART_CTRL2_ADREIEN_Msk               (0x1UL << USART_CTRL2_ADREIEN_Pos)                /*!< 0x00040000 */
#define USART_CTRL2_ADREIEN                   USART_CTRL2_ADREIEN_Msk                           /*!<Automatic porter rate error interrupt mode enable */

/******************  Bit definition for USART_CTRL3 register  *******************/
#define USART_CTRL3_ERRIEN_Pos                (0U)
#define USART_CTRL3_ERRIEN_Msk                (0x1UL << USART_CTRL3_ERRIEN_Pos)                 /*!< 0x00000001 */
#define USART_CTRL3_ERRIEN                    USART_CTRL3_ERRIEN_Msk                            /*!<Error Interrupt Enable      */
#define USART_CTRL3_HDEN_Pos                  (3U)
#define USART_CTRL3_HDEN_Msk                  (0x1UL << USART_CTRL3_HDEN_Pos)                   /*!< 0x00000008 */
#define USART_CTRL3_HDEN                      USART_CTRL3_HDEN_Msk                              /*!<Half-Duplex Selection       */
#define USART_CTRL3_DMARXEN_Pos               (6U)
#define USART_CTRL3_DMARXEN_Msk               (0x1UL << USART_CTRL3_DMARXEN_Pos)                /*!< 0x00000040 */
#define USART_CTRL3_DMARXEN                   USART_CTRL3_DMARXEN_Msk                           /*!<DMA Enable Receiver         */
#define USART_CTRL3_DMATXEN_Pos               (7U)
#define USART_CTRL3_DMATXEN_Msk               (0x1UL << USART_CTRL3_DMATXEN_Pos)                /*!< 0x00000080 */
#define USART_CTRL3_DMATXEN                   USART_CTRL3_DMATXEN_Msk                           /*!<DMA Enable Transmitter      */
#define USART_CTRL3_SAMCFG_Pos                (11U)
#define USART_CTRL3_SAMCFG_Msk                (0x1UL << USART_CTRL3_SAMCFG_Pos)                 /*!< 0x00000800 */
#define USART_CTRL3_SAMCFG                    USART_CTRL3_SAMCFG_Msk                            /*!<USART Driver enable mode) */

/******************  Bit definition for USART_RXTO register  ******************/
#define USART_RXTO_RXTO_Pos                   (0U)
#define USART_RXTO_RXTO_Msk                   (0xFFFFFFUL << USART_RXTO_RXTO_Pos)               /*!< 0x00FFFFFF */
#define USART_RXTO_RXTO                       USART_RXTO_RXTO_Msk                               /*!<Data value */

/******************************************************************************/
/*                                                                            */
/*                          Window watchdog timer                             */
/*                                                                            */
/******************************************************************************/
/********************  Bit definition for WWDT_CTRL register  *******************/
#define WWDT_CTRL_CNT_Pos                     (0UL)                                             /*!< t_out (Bit 0) */
#define WWDT_CTRL_CNT_0                       (0x1UL << WWDT_CTRL_CNT_Pos)
#define WWDT_CTRL_CNT_1                       (0x2UL << WWDT_CTRL_CNT_Pos)
#define WWDT_CTRL_CNT_2                       (0x4UL << WWDT_CTRL_CNT_Pos)
#define WWDT_CTRL_CNT_3                       (0x8UL << WWDT_CTRL_CNT_Pos)
#define WWDT_CTRL_CNT_4                       (0x10UL << WWDT_CTRL_CNT_Pos)
#define WWDT_CTRL_CNT_5                       (0x20UL << WWDT_CTRL_CNT_Pos)
#define WWDT_CTRL_CNT_6                       (0x40UL << WWDT_CTRL_CNT_Pos)
#define WWDT_CTRL_CNT_Msk                     (0x7fUL << WWDT_CTRL_CNT_Pos)                     /*!< t_out (Bitfield-Mask: 0x7f) */
#define WWDT_CTRL_CNT                         WWDT_CTRL_CNT_Msk
#define WWDT_CTRL_WWDTEN_Pos                  (7UL)                                             /*!< WWDG_en (Bit 7) */
#define WWDT_CTRL_WWDTEN_Msk                  (0x1UL << WWDT_CTRL_WWDTEN_Pos)                   /*!< WWDG_en (Bitfield-Mask: 0x01) */
#define WWDT_CTRL_WWDTEN                      WWDT_CTRL_WWDTEN_Msk
/********************  Bit definition for WWDT_CFG register  ******************/
#define WWDT_CFG_WIN_Pos                      (0UL)                                             /*!< wind (Bit 0) */
#define WWDT_CFG_WIN_0                        (0x1UL << WWDT_CFG_WIN_Pos)
#define WWDT_CFG_WIN_1                        (0x2UL << WWDT_CFG_WIN_Pos)
#define WWDT_CFG_WIN_2                        (0x4UL << WWDT_CFG_WIN_Pos)
#define WWDT_CFG_WIN_3                        (0x8UL << WWDT_CFG_WIN_Pos)
#define WWDT_CFG_WIN_4                        (0x10UL << WWDT_CFG_WIN_Pos)
#define WWDT_CFG_WIN_5                        (0x20UL << WWDT_CFG_WIN_Pos)
#define WWDT_CFG_WIN_6                        (0x40UL << WWDT_CFG_WIN_Pos)
#define WWDT_CFG_WIN_Msk                      (0x7fUL << WWDT_CFG_WIN_Pos)                      /*!< wind (Bitfield-Mask: 0x7f) */
#define WWDT_CFG_WIN                          WWDT_CFG_WIN_Msk
#define WWDT_CFG_TBPSC_Pos                    (7UL)                                             /*!< Time_base (Bit 7) */
#define WWDT_CFG_TBPSC_0                      (0x1UL << WWDT_CFG_TBPSC_Pos)
#define WWDT_CFG_TBPSC_1                      (0x2UL << WWDT_CFG_TBPSC_Pos)
#define WWDT_CFG_TBPSC_Msk                    (0x3UL << WWDT_CFG_TBPSC_Pos)                     /*!< Time_base (Bitfield-Mask: 0x03) */
#define WWDT_CFG_TBPSC                        WWDT_CFG_TBPSC_Msk
#define WWDT_CFG_EWIEN_Pos                    (9UL)                                             /*!< EWIEN (Bit 9) */
#define WWDT_CFG_EWIEN_Msk                    (0x1UL << WWDT_CFG_EWIEN_Pos)                     /*!< EWIEN (Bitfield-Mask: 0x01) */
#define WWDT_CFG_EWIEN                        WWDT_CFG_EWIEN_Msk
/********************  Bit definition for WWDT_SR register  *******************/
#define WWDT_STS_EWIFLG_Pos                   (0UL)                                             /*!< EWIFLG (Bit 0) */
#define WWDT_STS_EWIFLG_Msk                   (0x1UL << WWDT_STS_EWIFLG_Pos)                    /*!< EWIFLG (Bitfield-Mask: 0x01) */
#define WWDT_STS_EWIFLG                       WWDT_STS_EWIFLG_Msk


/**
  * @}
  */

 /**
  * @}
  */


/** @addtogroup Exported_macro
  * @{
  */

/******************************* FLASH Instances ******************************/
#define IS_FLASH_ALL_INSTANCE(INSTANCE) (((INSTANCE) == FLASH))

/******************************* ADC Instances ********************************/
#define IS_ADC_ALL_INSTANCE(INSTANCE) (((INSTANCE) == ADC))

#define IS_ADC_MULTIMODE_MASTER_INSTANCE(INSTANCE) ((INSTANCE) == ADC)

/******************************* COMP Instances *******************************/
#define IS_COMP_ALL_INSTANCE(INSTANCE) (((INSTANCE) == COMP0) || \
                                        ((INSTANCE) == COMP1))

/******************************* CRC Instances ********************************/
#define IS_CRC_ALL_INSTANCE(INSTANCE) ((INSTANCE) == CRC)

/******************************* DIV Instances ********************************/
#define IS_DIV_ALL_INSTANCE(INSTANCE) ((INSTANCE) == DIV)

/******************************** DMA Instances *******************************/
#define IS_DMA_CHANNEL_ALL_INSTANCE(INSTANCE) (((INSTANCE) == DMA_Channel0) || \
                                               ((INSTANCE) == DMA_Channel1) || \
                                               ((INSTANCE) == DMA_Channel2))

/******************************* GPIO Instances *******************************/
#define IS_GPIO_ALL_INSTANCE(INSTANCE) (((INSTANCE) == GPIOA) || \
                                        ((INSTANCE) == GPIOB))

/******************************* GPIO AF Instances ****************************/
#define IS_GPIO_AF_INSTANCE(INSTANCE)   IS_GPIO_ALL_INSTANCE(INSTANCE)

/******************************** SPI Instances *******************************/
#define IS_SPI_ALL_INSTANCE(INSTANCE) (((INSTANCE) == SPI))

/******************************** LPTMR Instances *****************************/
#define IS_LPTMR_INSTANCE(INSTANCE) (((INSTANCE) == LPTMR))

/****************** TMR Instances : All supported instances *******************/
#define IS_ATMR_INSTANCE(INSTANCE)  (((INSTANCE) == ATMR))
#define IS_BTMR_INSTANCE(INSTANCE)  (((INSTANCE) == BTMR))
#define IS_GTMR_INSTANCE(INSTANCE)  (((INSTANCE) == GTMR))

/************* TMR Instances : at least 1 capture/compare channel *************/
#define IS_ATMR_CC0_INSTANCE(INSTANCE)  (((INSTANCE) == ATMR))
#define IS_BTMR_CC0_INSTANCE(INSTANCE)  (((INSTANCE) == BTMR))
#define IS_GTMR_CC0_INSTANCE(INSTANCE)  (((INSTANCE) == GTMR))

/************ TMR Instances : at least 2 capture/compare channels *************/
#define IS_ATMR_CC1_INSTANCE(INSTANCE)  (((INSTANCE) == ATMR))
#define IS_BTMR_CC1_INSTANCE(INSTANCE)  (((INSTANCE) == BTMR))
#define IS_GTMR_CC1_INSTANCE(INSTANCE)  (((INSTANCE) == GTMR))

/************ TMR Instances : at least 3 capture/compare channels *************/
#define IS_ATMR_CC2_INSTANCE(INSTANCE)  (((INSTANCE) == ATMR))
#define IS_BTMR_CC2_INSTANCE(INSTANCE)  (((INSTANCE) == BTMR))
#define IS_GTMR_CC2_INSTANCE(INSTANCE)  (((INSTANCE) == GTMR))

/************ TMR Instances : at least 4 capture/compare channels *************/
#define IS_ATMR_CC3_INSTANCE(INSTANCE)  (((INSTANCE) == ATMR))
#define IS_GTMR_CC3_INSTANCE(INSTANCE)  (((INSTANCE) == GTMR))

/************ TMR Instances : at least 5 capture/compare channels *************/
#define IS_ATMR_CC4_INSTANCE(INSTANCE)  (((INSTANCE) == ATMR))

/******************** TMR Instances : Advanced-control timers *****************/
#define IS_ATMR_ADVANCED_INSTANCE(INSTANCE) (((INSTANCE) == ATMR))

/******************* TMR Instances : Timer input XOR function *****************/
#define IS_GTMR_XOR_INSTANCE(INSTANCE)   ((INSTANCE) == GTMR)

/****************** TMR Instances : DMA requests generation (UDE) *************/
#define IS_GTMR_DMA_INSTANCE(INSTANCE) ((INSTANCE) == GTMR)

/************ TMR Instances : DMA requests generation (CCxDE) *****************/
#define IS_GTMR_DMA_CC_INSTANCE(INSTANCE) ((INSTANCE) == GTMR)

/******************** TMR Instances : DMA burst feature ***********************/
#define IS_GTMR_DMABURST_INSTANCE(INSTANCE)  ((INSTANCE) == GTMR)

/****** TMR Instances : master mode available (TMRx_CR2.MMS available )********/
#define IS_ATMR_MASTER_INSTANCE(INSTANCE) (((INSTANCE) == ATMR))
#define IS_GTMR_MASTER_INSTANCE(INSTANCE) (((INSTANCE) == GTMR))

/*********** TMR Instances : Slave mode available (TMRx_SMCR available )*******/
#define IS_ATMR_SLAVE_INSTANCE(INSTANCE) (((INSTANCE) == ATMR))
#define IS_GTMR_SLAVE_INSTANCE(INSTANCE) (((INSTANCE) == GTMR))

/********************** TMR Instances : 32 bit Counter ************************/
#define IS_GTMR_32B_COUNTER_INSTANCE(INSTANCE) (((INSTANCE) == GTMR))

/***************** TMR Instances : external trigger input available ************/
#define IS_ATMR_ETR_INSTANCE(INSTANCE)  (((INSTANCE) == ATMR))
#define IS_GTMR_ETR_INSTANCE(INSTANCE)  (((INSTANCE) == GTMR))

/******************* TMR Instances : output(s) available **********************/
#define IS_TMR_CCX_INSTANCE(INSTANCE, CHANNEL) \
    ((((INSTANCE) == ATMR) &&                  \
     (((CHANNEL) == TMR_CHANNEL_0) ||          \
      ((CHANNEL) == TMR_CHANNEL_1) ||          \
      ((CHANNEL) == TMR_CHANNEL_2) ||          \
      ((CHANNEL) == TMR_CHANNEL_3)))           \
    ||                                         \
    (((INSTANCE) == GTMR) &&                   \
     (((CHANNEL) == TMR_CHANNEL_0) ||          \
      ((CHANNEL) == TMR_CHANNEL_1) ||          \
      ((CHANNEL) == TMR_CHANNEL_2) ||          \
      ((CHANNEL) == TMR_CHANNEL_3))))
#define IS_BTMR_CCX_INSTANCE(INSTANCE, CHANNEL) \
    (((INSTANCE) == BTMR) &&                  \
     (((CHANNEL) == TMR_CHANNEL_0) ||          \
      ((CHANNEL) == TMR_CHANNEL_1) ||          \
      ((CHANNEL) == TMR_CHANNEL_2)))
/************ TMR Instances : complementary output(s) available ***************/
#define IS_TMR_CCXN_INSTANCE(INSTANCE, CHANNEL) \
   ((((INSTANCE) == ATMR) &&                    \
     (((CHANNEL) == TMR_CHANNEL_0) ||           \
      ((CHANNEL) == TMR_CHANNEL_1) ||           \
      ((CHANNEL) == TMR_CHANNEL_2))))

/****************** TMR Instances : supporting counting mode selection ********/
#define IS_ATMR_COUNTER_MODE_SELECT_INSTANCE(INSTANCE)  (((INSTANCE) == ATMR))
#define IS_GTMR_COUNTER_MODE_SELECT_INSTANCE(INSTANCE)  (((INSTANCE) == GTMR))
#define IS_BTMR_COUNTER_MODE_SELECT_INSTANCE(INSTANCE)  (((INSTANCE) == BTMR))

/****************** TMR Instances : supporting clock division *****************/
#define IS_ATMR_CLOCK_DIVISION_INSTANCE(INSTANCE) (((INSTANCE) == ATMR))
#define IS_GTMR_CLOCK_DIVISION_INSTANCE(INSTANCE) (((INSTANCE) == GTMR))

/****************** TMR Instances : supporting commutation event generation ***/
#define IS_ATMR_COMMUTATION_EVENT_INSTANCE(INSTANCE) ((INSTANCE) == ATMR)

/****************** TMR Instances : supporting OCxREF clear *******************/
#define IS_ATMR_OCXREF_CLEAR_INSTANCE(INSTANCE)        (((INSTANCE) == ATMR))
#define IS_GTMR_OCXREF_CLEAR_INSTANCE(INSTANCE)        (((INSTANCE) == GTMR))

/****** TMR Instances : supporting external clock mode 1 for ETRF input *******/
#define IS_ATMR_CLOCKSOURCE_ETRMODE1_INSTANCE(INSTANCE) (((INSTANCE) == ATMR))
#define IS_GTMR_CLOCKSOURCE_ETRMODE1_INSTANCE(INSTANCE) (((INSTANCE) == GTMR))

/****** TMR Instances : supporting external clock mode 2 for ETRF input *******/
#define IS_ATMR_CLOCKSOURCE_ETRMODE2_INSTANCE(INSTANCE) (((INSTANCE) == ATMR))
#define IS_GTMR_CLOCKSOURCE_ETRMODE2_INSTANCE(INSTANCE) (((INSTANCE) == GTMR))

/****** TMR Instances : supporting external clock mode 1 for TIX inputs *******/
#define IS_ATMR_CLOCKSOURCE_TIX_INSTANCE(INSTANCE)      (((INSTANCE) == ATMR))
#define IS_GTMR_CLOCKSOURCE_TIX_INSTANCE(INSTANCE)      (((INSTANCE) == GTMR))

/********** TMR Instances : supporting internal trigger inputs(ITRX) **********/
#define IS_ATMR_CLOCKSOURCE_ITRX_INSTANCE(INSTANCE)     (((INSTANCE) == ATMR))
#define IS_GTMR_CLOCKSOURCE_ITRX_INSTANCE(INSTANCE)     (((INSTANCE) == GTMR))

/****************** TMR Instances : supporting repetition counter *************/
#define IS_ATMR_REPETITION_COUNTER_INSTANCE(INSTANCE)  (((INSTANCE) == ATMR))

/****************** TMR Instances : supporting encoder interface **************/
#define IS_GTMR_ENCODER_INTERFACE_INSTANCE(INSTANCE)  ((INSTANCE) == GTMR)

/****************** TMR Instances : supporting Hall sensor interface **********/
#define IS_GTMR_HALL_SENSOR_INTERFACE_INSTANCE(INSTANCE)  ((INSTANCE) == GTMR)

/****************** TMR Instances : supporting the break function *************/
#define IS_ATMR_BREAK_INSTANCE(INSTANCE)  (((INSTANCE) == ATMR))

/******************** UART Instances : Synchronous mode ***********************/
#define IS_UART_INSTANCE(INSTANCE)  (((INSTANCE) == UART0) || \
                                     ((INSTANCE) == UART1))

/****************** UART Instances : Auto Baud Rate detection *****************/
#define IS_UART_AUTOBAUDRATE_DETECTION_INSTANCE(INSTANCE) (((INSTANCE) == UART0) || \
                                                            ((INSTANCE) == UART1))

/******************** UART Instances : Half-Duplex mode ***********************/
#define IS_UART_HALFDUPLEX_INSTANCE(INSTANCE)   (((INSTANCE) == UART0) || \
                                                 ((INSTANCE) == UART1))

/******************** UART Instances : LIN mode **********************/
#define IS_UART_LIN_INSTANCE(INSTANCE)   (((INSTANCE) == UART0) || \
                                          ((INSTANCE) == UART1))

/****************************** IWDG Instances ********************************/
#define IS_IWDG_ALL_INSTANCE(INSTANCE)  ((INSTANCE) == IWDT)

/****************************** WWDG Instances ********************************/
#define IS_WWDG_ALL_INSTANCE(INSTANCE)  ((INSTANCE) == WWDT)


#define RCM_MAX_FREQUENCY           64000000U         /*!< Max frequency of family in Hz */
#define RCM_MAX_FREQUENCY_SCALE1    RCM_MAX_FREQUENCY /*!< Maximum frequency for system clock at power scale1, in Hz */

#define FLASH_SCALE1_LATENCY1_FREQ   32000000U      /*!< HCLK frequency to set FLASH latency 1 in power scale 1  */
#define FLASH_SCALE1_LATENCY2_FREQ   48000000U      /*!< HCLK frequency to set FLASH latency 2 in power scale 1  */
#define FLASH_SCALE1_LATENCY3_FREQ   64000000U      /*!< HCLK frequency to set FLASH latency 3 in power scale 1  */

/******************************************************************************/
/*  For a painless codes migration between the G32M3101xx device product     */
/*  lines, the aliases defined below are put in place to overcome the         */
/*  differences in the interrupt handlers and IRQn definitions.               */
/*  No need to update developed interrupt code when moving across             */
/*  product lines within the same G32M3xxx Family                           */
/******************************************************************************/

/**
  * @}
  */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __G32M3101xx_H */

/**
  * @}
  */

  /**
  * @}
  */

/************************ (C) COPYRIGHT Geehy Semiconductor *****END OF FILE****/
