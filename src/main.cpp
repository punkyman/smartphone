#include <Arduino.h>
#include <Wire.h>
#include <MemoryFree.h>

#include "hardware.h"
#include "phone_menu.h"

// tick every 66 ms, that makes it 15fps
#define TIME_FRAME 66

PhoneMenu menu;

void setup(void) {
  Serial.begin(9600);

  Hardware::setup();
}

void loop(void) {

  unsigned long startTime = micros();

  Hardware::update();
  menu.update();
  
  menu.draw();

  unsigned long endTime = micros();
  
  Serial.print(F("Update time : "));
  Serial.println(endTime - startTime);
  Serial.print(F("Free memory : "));
  Serial.println(freeMemory());

  int timeframe = TIME_FRAME - ((endTime - startTime) / 1000);
  if(timeframe > 0)
    delay(timeframe);
}