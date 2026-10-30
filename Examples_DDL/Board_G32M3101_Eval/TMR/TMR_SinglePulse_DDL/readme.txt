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

This example shows how to config TMR peripherals to generate a Single Pulse
with an external trigger

  - GTMR Config Single Pulse Mode and Enable event is used as Trigger Output
  - The GTMR peripherals clock is 64MHz.
  - Config Timer GTMR counter clock at 32 MHz:
  - GTMR counter clock = (64M)/ (1 + 1) = 32MHz

  - GTMR->AUTORLD is 32767, so the trigger input max frequency value
  - is 32MHz/32767 = 1KHz .
  - GTMR pulse = 8191
  - Single Pulse delay value = 8191/(32MHz) = 250us
  - And the pulse value is fixed to single pulse value
  - Pulse value = (period - pulse)/counter clock
  - = (32767- 8191)/ 32MHz = 750us

&par Hardware Description

  - using GTMR CHANNEL1(PB10) to output Pulse by GTMR CHANNEL2(PB11)
  - using GTMR CHANNEL2(PB11) connect the external signal

&par Directory contents

  - TMR/TMR_SinglePulse/Source/main.c                 Main program
  - TMR/TMR_SinglePulse/Source/g32m3101_int.c       Interrupt handlers

&par IDE environment

  - MDK-ARM V5.36
  - EWARM V8.50.5.26295
  - ECLIPSE-EMB V4.24.0

&par Hardware and Software environment

  - This example runs on G32M3101 EVAL Devices.
