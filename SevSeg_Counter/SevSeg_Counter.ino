/* SevSeg Counter Example
 
 Copyright 2014 Dean Reading
 
 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at 
 http://www.apache.org/licenses/LICENSE-2.0
 
 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
 
 
 This example demonstrates a very simple use of the SevSeg library with a 4
 digit display. It displays a counter that counts up, showing deci-seconds.
 */

#include "SevSeg.h"
#include <TimeLib.h>

SevSeg sevseg; //Instantiate a seven segment controller object

void setup() {
  byte numDigits = 4;   
  byte digitPins[] = {12, 9, 8, 6}; //Digits: 1,2,3,4 <--put one resistor (ex: 220 Ohms, or 330 Ohms, etc, on each digit pin)
  byte segmentPins[] = {11, 7, 4, 2, 1, 10, 5, 3}; //Segments: A,B,C,D,E,F,G,Period

  sevseg.begin(COMMON_CATHODE, numDigits, digitPins, segmentPins);
  sevseg.setBrightness(90);
}

void loop() {
  static unsigned long timer = millis();
  static int deciSeconds = 0;

  sevseg.setNumber(minute()*100 + second(), 2);
//  if (millis() >= timer) {
//    deciSeconds++; // 100 milliSeconds is equal to 1 deciSecond
//    timer += 100; 
//    if (deciSeconds == 10000) { // Reset to 0 after counting for 1000 seconds.
//      deciSeconds=0;
//    }
//    sevseg.setNumber(deciSeconds, 1);
//  }

  sevseg.refreshDisplay(); // Must run repeatedly
}

/// END ///
