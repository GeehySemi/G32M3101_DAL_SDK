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

This example describes show how to how to use CMSIS FreeRTOS create multiple tasks.

Usart test task : USART send a string

Led toggle task : The IO of LED2 is configed to toggle constantly

&par Directory contents

  - RTOS/CMSIS_FreeRTOS/Source/main.c                  Main program
  - RTOS/CMSIS_FreeRTOS/Source/g32m3101_int.c         Interrupt handlers

&par IDE environment

  - MDK-ARM V5.36
  - EWARM V8.50.5.26295
  - ECLIPSE-EMB V4.24.0

&par Hardware and Software environment

  - This example runs on G32M3101 EVAL Devices.
