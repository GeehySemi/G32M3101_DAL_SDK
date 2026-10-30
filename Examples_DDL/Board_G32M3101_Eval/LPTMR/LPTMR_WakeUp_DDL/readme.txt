/**
 * @file        readme.txt
 *
 * @brief       This file is routine instruction
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

&par Example Description

This demo is show how to use LPTMR to wake up from low power mode.
Press KEY1(PB10) to enalbe LPTMR, and enter low power mode.
Then trigger the LPTMR interrupt to wake up from low power mode.
User can view the infomation through serial terminal.

&par Hardware Description

using UART0(TX:PA7、RX:PA8).
  - UART0 configured as follow:
  - BaudRate = 115200
  - Word Length = UART_WordLength_8b
  - Stop Bit = UART_StopBits_1
  - Parity = UART_Parity_No
  - Hardware flow control disabled (RTS and CTS signals)
  - Receive and transmit enabled

&par Directory contents

  - LPTMR/LPTMR_WakeUp/Source/main.c                 Main program
  - LPTMR/LPTMR_WakeUp/Source/g32m3101_int.c       Interrupt handlers

&par IDE environment

  - MDK-ARM V5.36
  - EWARM V8.50.5.26295
  - ECLIPSE-EMB V4.24.0

&par Hardware and Software environment

  - This example runs on G32M3101 EVAL Devices.
