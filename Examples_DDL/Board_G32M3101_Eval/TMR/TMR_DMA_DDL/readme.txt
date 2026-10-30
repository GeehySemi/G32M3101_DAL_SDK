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

The program to show how to use DMA to transfer Data from
memory to GTMR Capture Compare Register1 to change the Duty Cycle.

  - SystemCoreClock = 64 MHz.
  - GTMRCLK = SystemCoreClock, Prescaler = 64, GTMR counter clock = 1 MHz
  - GTMR_Period = (1000000 / 1000) - 1

GTMR channel 1 generate complementary PWM signal at 1 KHz, and a variable
duty cycle changed by the DMA after an update DMA request.

each an update requests, the GTMR Channel 2 Duty Cycle changes to the next new value:
  - value1 = 800
  - Channel 1 duty cycle = 80%
  - value2 = 600
  - Channel 1 duty cycle = 60%
  - value3 = 400
  - Channel 1 duty cycle = 40%

Display GTMR waveform by oscilloscope.

&par Hardware Description

  - using GTMR Channel 1 (PB10) to output PWM

&par Directory contents

  - TMR/TMR_DMA/Source/main.c                 Main program
  - TMR/TMR_DMA/Source/g32m3101_int.c       Interrupt handlers

&par IDE environment

  - MDK-ARM V5.36
  - EWARM V8.50.5.26295
  - ECLIPSE-EMB V4.24.0

&par Hardware and Software environment

  - This example runs on G32M3101 EVAL Devices.
