/**
 * @file        readme.txt
 *
 * @brief       This file is routine instruction
 *
 * @version     V1.0.0
 *
 * @date        2025-01-01
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

This example shows how to configure external interrupt lines.
In this example, 1 EINT lines (KEY1) when using the board are
configured to generate an interrupt on each falling edge. In the
interrupt routine a led connected to a specific GPIO pin is toggled.

In this example
    - EINT10  is mapped to PB10(KEY1)

After EINT configuration
  when falling edge is detected on EINT10 , LED2 toggles

&par Directory contents

  - ENIT/EINT_Config_DDL/Source/main.c                   Main program
  - ENIT/EINT_Config_DDL/Source/g32m3101_int.c         Interrupt handlers

&par IDE environment

  - MDK-ARM V5.36
  - EWARM V8.50.5.26295
  - ECLIPSE-EMB V4.24.0

&par Hardware and Software environment

  - This example runs on G32M3101 EVAL Devices.
