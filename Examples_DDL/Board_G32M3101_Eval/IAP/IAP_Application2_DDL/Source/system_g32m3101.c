/**
 *
 * @file        system_g32m3101.c
 *
 * @brief       CMSIS Cortex-M0 Device Peripheral Access Layer System Source File.
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
#include "g32m3xxx.h"

/* Private macro **********************************************************/

/* Value of the internal oscillator in Hz */
#if !defined(HSI_VALUE)
#define HSI_VALUE ((uint32_t)64000000U)
#endif /* HSI_VALUE */

#if !defined(LSI_VALUE)
#define LSI_VALUE 32768U
#endif /* LSI_VALUE */

/* Uncomment the following line if you need to relocate your vector table in internal SRAM */
/* #define VECT_TAB_SRAM */

/* Vector table base offset field. This value must be a multiple of 0x200 */
#define VECT_TAB_OFFSET 0x6000U

/* Private variables ******************************************************/
uint32_t SystemCoreClock = 64000000;
const uint8_t AHBPrescTable[8] = {0, 1, 2, 3, 4, 5, 6, 7};
const uint8_t APBPrescTable[8] = {0, 1, 2, 3, 4, 5, 6, 7};

/* External functions *****************************************************/

static void SystemReset(void);

/**
 * @brief     Setup the microcontroller system
 *
 * @param     None
 *
 * @retval    None
 */
void SystemInit(void)
{
    uint8_t i;

    /* Disable global interrupt */
    __disable_irq();

    SysTick->CTRL = 0U;
    SysTick->LOAD = 0U;
    SysTick->VAL = 0U;

    for (i = 0U; i < 1U; i++)
    {
        NVIC->ICER[i] = 0xFFFFFFFFU;
        NVIC->ICPR[i] = 0xFFFFFFFFU;
    }

    /* FPU settings */
#if (__FPU_PRESENT == 1U) && (__FPU_USED == 1U)
    SCB->CPACR |= ((3UL << 10U * 2U) | (3UL << 11U * 2U)); /* set CP10 and CP11 Full Access */
#endif
    /* Reset the scu configuration to the default reset state:
       - HSI clock is ON and used as system clock source
       - AHB, APB prescaler are divided by 1.
       - MCO OFF
       - All interrupts disabled
       - Reset all wakeup-configuration
    */
    SystemReset();

    /* Configure the Vector Table location add offset address */
#ifdef VECT_TAB_SRAM
    SCB->VTOR = SRAM_BASE | VECT_TAB_OFFSET; /* Vector Table Relocation in Internal SRAM */
#else
    SCB->VTOR = FLASH_BASE | VECT_TAB_OFFSET; /* Vector Table Relocation in Internal FLASH */
#endif

    /* Enable global interrupt */
    __enable_irq();
}

/**
 * @brief Update SystemCoreClock variable according to clock register values
 *          The SystemCoreClock variable contains the core clock (HCLK)
 *
 * @param  None
 * @retval None
 */
void SystemCoreClockUpdate(void)
{
    uint32_t sysClock = 0U;

    sysClock = (SCU->SCCR & SCU_SCCR_SWST) >> SCU_SCCR_SWST_Pos;

    /* Get SYSCLK source */
    switch (sysClock)
    {
        case 0x00: /* HSI used as system clock source */
            SystemCoreClock = HSI_VALUE;
            break;

        case 0x01: /* LSI used as system clock source */
            SystemCoreClock = LSI_VALUE;
            break;

        default:
            SystemCoreClock = HSI_VALUE;
            break;
    }

    SystemCoreClock >>= AHBPrescTable[(SCU->SCCR & SCU_SCCR_HDIV) >> SCU_SCCR_HDIV_Pos];
}

/*!
 * @brief     Reset the SCU configurations.
 *               - HSI clock is ON and used as system clock source
 *               - AHB, APB prescaler are divided by 1.
 *               - MCO OFF
 *               - All interrupts disabled
 *               - Reset all wakeup-configuration
 *
 * @param     None
 *
 * @retval    None
 */
static void SystemReset(void)
{
    uint32_t RegValue;
    /* Unlock the SCU register. */
    SCU->KEY = SCU_KEY_VALUE;

    /* If LSI clock is set as system clock source, switch to HSI clock*/
    if (SCU->SCCR & SCU_SCCR_SWST)
    {
        if (!(SCU->RCCR & SCU_RCCR_HSIRDYFLG))
        {
            /* Enalbe HSICLK */
            RegValue = SCU->RCCR;
            RegValue |= SCU_RCCR_HSION;
            SCU->RCCR = RegValue;

            /* Wait for HSI_ON READY */
            while ((SCU->RCCR & SCU_RCCR_HSIRDYFLG) != SCU_RCCR_HSIRDYFLG)
            {
            }
        }
        /* Set HSI clock as system source clock */
        RegValue = SCU->SCCR;
        RegValue &= SCU_SCCR_SW;
        RegValue |= SCU_SCCR_SW_HSI;
        SCU->SCCR = RegValue;

        /* Wait for system clock source READY */
        while ((SCU->SCCR & SCU_SCCR_SWST) != SCU_SCCR_SWST_HSI)
        {
        }
    }
    /* AHB, APB prescaler are divided by 1 */
    SCU->SCCR = 0x00000000U;

    /* Disable all interrupts */
    SCU->CIER = 0x00000000U;

    /* Reset all digital module */
    SCU->APBRST = 0x8477;
    SCU->APBRST = 0x00000000U;
    SCU->AHBRST = 0x73;
    SCU->AHBRST = 0x00000000U;

    /* Lock the SCU register. */
    SCU->KEY = SCU_KEY_KEYST;
}
