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

The program to show how to configure the GTMR peripheral to generate 3 waveforms
with 3 different frequencies.

  - GTMRCLK = 64MHz. Prescaler = 63, TMR counter clock = 1 MHz
  - GTMR_Period = (1000000 / 1000) - 1
  - GTMR CH1 pulse = 800
  - GTMR CH1 duty = 800/1000 = 80%
  - GTMR CH2 pulse = 600
  - GTMR CH2 duty = 600/1000 = 60%
  - GTMR CH3 pulse = 400
  - GTMR CH3 duty = 400/1000 = 40%

The CHx delay correspond to the time difference between GTMR_CHx signal
rising edges. Reset system and display GTMR waveform by oscilloscope.

&par Hardware Description

  - using GTMR Channel 1 (PB10) to output signal
  - using GTMR Channel 2 (PB11) to output signal
  - using GTMR Channel 3 (PB12) to output signal

&par Directory contents

  - TMR/TMR_OCToggle/Source/main.c                 Main program
  - TMR/TMR_OCToggle/Source/g32m3101_int.c       Interrupt handlers

&par IDE environment

  - MDK-ARM V5.36
  - EWARM V8.50.5.26295
  - ECLIPSE-EMB V4.24.0

&par Hardware and Software environment

  - This example runs on G32M3101 EVAL Devices.
