;/**
; * @file       startup_g32m3101xx.s
; *
; * @brief      CMSIS Cortex-M0+ based Core Device Startup File for Device startup_g32m3101xx
; *
; * @version    V1.0.0
; *
; * @date       2025-06-01
; *
; * @attention
; *
; *  Copyright (C) 2025 Geehy Semiconductor
; *
; *  You may not use this file except in compliance with the
; *  GEEHY COPYRIGHT NOTICE (GEEHY SOFTWARE PACKAGE LICENSE).
; *
; *  The program is only for reference, which is distributed in the hope
; *  that it will be useful and instructional for customers to develop
; *  their software. Unless required by applicable law or agreed to in
; *  writing, the program is distributed on an "AS IS" BASIS, WITHOUT
; *  ANY WARRANTY OR CONDITIONS OF ANY KIND, either express or implied.
; *  See the GEEHY SOFTWARE PACKAGE LICENSE for the governing permissions
; *  and limitations under the License.
; */

        MODULE  ?cstartup

        ;; Forward declaration of sections.
        SECTION CSTACK:DATA:NOROOT(3)

        SECTION .intvec:CODE:NOROOT(2)

        EXTERN  __iar_program_start
        EXTERN  SystemInit
        PUBLIC  __vector_table

        DATA
__vector_table
        DCD     sfe(CSTACK)
        DCD     Reset_Handler             ; Reset Handler

                DCD     NMI_Handler                ; NMI Handler
                DCD     HardFault_Handler          ; Hard Fault Handler
                DCD     0                          ; Reserved
                DCD     0                          ; Reserved
                DCD     0                          ; Reserved
                DCD     0                          ; Reserved
                DCD     0                          ; Reserved
                DCD     0                          ; Reserved
                DCD     0                          ; Reserved
                DCD     SVC_Handler                ; SVCall Handler
                DCD     0                          ; Reserved
                DCD     0                          ; Reserved
                DCD     PendSV_Handler             ; PendSV Handler
                DCD     SysTick_Handler            ; SysTick Handler

                ; External Interrupts
                DCD     WWDT_IRQHandler                 ; Window WatchDog
                DCD     PVD_IRQHandler                  ; PVD through EINT Line detection
                DCD     LVD_IRQHandler                  ; LVD
                DCD     FLASH_IRQHandler                ; FLASH
                DCD     RCM_IRQHandler                  ; RCM
                DCD     EINT0_1_IRQHandler              ; EINT Line 0 and 1
                DCD     EINT2_3_IRQHandler              ; EINT Line 2 and 3
                DCD     EINT4_13_IRQHandler             ; EINT Line 4 to 13
                DCD     0                               ; Reserved
                DCD     DMA_Channel0_IRQHandler        ; DMA Channel 0
                DCD     DMA_Channel1_IRQHandler        ; DMA Channel 1
                DCD     DMA_Channel2_IRQHandler        ; DMA Channel 2
                DCD     ADC_IRQHandler                 ; ADC
                DCD     ATMR_BRK_UP_TRG_COM_IRQHandler  ; Advanced Timer Break, Update, Trigger and Commutation
                DCD     ATMR_CC_IRQHandler              ; Advanced Timer Capture Compare
                DCD     GTMR_IRQHandler                 ; General Timer
                DCD     0                               ; 0
                DCD     BTMR_IRQHandler                 ; Basic timer
                DCD     0                               ; Reserved
                DCD     LPTMR_IRQHandler                ; Low power timer
                DCD     0                               ; Reserved
                DCD     COMP0_1_IRQHandler                 ; COMP0 COMP1
                DCD     0                               ; Reserved
                DCD     0                               ; Reserved
                DCD     0                               ; Reserved
                DCD     SPI_IRQHandler                 ; SPI
                DCD     0                               ; Reserved
                DCD     UART0_IRQHandler                ; UART0
                DCD     UART1_IRQHandler                ; UART1
                DCD     0                               ; Reserved
                DCD     0                               ; Reserved
                DCD     0                               ; Reserved

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; Default interrupt handlers.
;;
        THUMB
        PUBWEAK Reset_Handler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reset_Handler

        LDR     R0, =SystemInit
        BLX     R0
        LDR     R0, =__iar_program_start
        BX      R0

        PUBWEAK NMI_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
NMI_Handler
        B NMI_Handler

        PUBWEAK HardFault_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
HardFault_Handler
        B HardFault_Handler

        PUBWEAK SVC_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
SVC_Handler
        B SVC_Handler

        PUBWEAK PendSV_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
PendSV_Handler
        B PendSV_Handler

        PUBWEAK SysTick_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
SysTick_Handler
        B SysTick_Handler

        PUBWEAK WWDT_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
WWDT_IRQHandler
        B WWDT_IRQHandler

        PUBWEAK PVD_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
PVD_IRQHandler
        B PVD_IRQHandler

        PUBWEAK LVD_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
LVD_IRQHandler
        B LVD_IRQHandler

        PUBWEAK FLASH_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
FLASH_IRQHandler
        B FLASH_IRQHandler

        PUBWEAK RCM_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
RCM_IRQHandler
        B RCM_IRQHandler

        PUBWEAK EINT0_1_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EINT0_1_IRQHandler
        B EINT0_1_IRQHandler

        PUBWEAK EINT2_3_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EINT2_3_IRQHandler
        B EINT2_3_IRQHandler

        PUBWEAK EINT4_13_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EINT4_13_IRQHandler
        B EINT4_13_IRQHandler

        PUBWEAK DMA_Channel0_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
DMA_Channel0_IRQHandler
        B DMA_Channel0_IRQHandler

        PUBWEAK DMA_Channel1_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
DMA_Channel1_IRQHandler
        B DMA_Channel1_IRQHandler

        PUBWEAK DMA_Channel2_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
DMA_Channel2_IRQHandler
        B DMA_Channel2_IRQHandler

        PUBWEAK ADC_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
ADC_IRQHandler
        B ADC_IRQHandler

        PUBWEAK ATMR_BRK_UP_TRG_COM_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
ATMR_BRK_UP_TRG_COM_IRQHandler
        B ATMR_BRK_UP_TRG_COM_IRQHandler

        PUBWEAK ATMR_CC_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
ATMR_CC_IRQHandler
        B ATMR_CC_IRQHandler

        PUBWEAK GTMR_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
GTMR_IRQHandler
        B GTMR_IRQHandler

        PUBWEAK BTMR_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
BTMR_IRQHandler
        B BTMR_IRQHandler

        PUBWEAK LPTMR_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
LPTMR_IRQHandler
        B LPTMR_IRQHandler

        PUBWEAK COMP0_1_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
COMP0_1_IRQHandler
        B COMP0_1_IRQHandler

        PUBWEAK SPI_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
SPI_IRQHandler
        B SPI_IRQHandler

        PUBWEAK UART0_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
UART0_IRQHandler
        B UART0_IRQHandler

        PUBWEAK UART1_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
UART1_IRQHandler
        B UART1_IRQHandler

        END
