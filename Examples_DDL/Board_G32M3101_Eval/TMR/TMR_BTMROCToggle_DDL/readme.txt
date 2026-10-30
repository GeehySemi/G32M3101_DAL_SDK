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

The program to show how to configure the BTMR peripheral to generate 3 waveforms
with 3 different frequencies.

  - BTMRCLK = 64MHz. Prescaler = 63, TMR counter clock = 1 MHz
  - BTMR_Period = (1000000 / 1000) - 1
  - BTMR CH0 pulse = 800
  - BTMR CH0 duty = 800/1000 = 80%
  - BTMR CH1 pulse = 600
  - BTMR CH1 duty = 600/1000 = 60%
  - BTMR CH2 pulse = 400
  - BTMR CH2 duty = 400/1000 = 40%

The CHx delay correspond to the time difference between BTMR_CHx signal
rising edges. Reset system and display BTMR waveform by oscilloscope.

&par Hardware Description

  - using BTMR Channel 0 (PB5) to output signal
  - using BTMR Channel 1 (PB6) to output signal
  - using BTMR Channel 2 (PB7) to output signal

&par Directory contents

  - TMR/TMR_BTMROCToggle/Source/main.c                 Main program
  - TMR/TMR_BTMROCToggle/Source/g32m3101_int.c       Interrupt handlers

&par IDE environment

  - MDK-ARM V5.36
  - EWARM V8.50.5.26295
  - ECLIPSE-EMB V4.24.0

&par Hardware and Software environment

  - This example runs on G32M3101 EVAL Devices.
