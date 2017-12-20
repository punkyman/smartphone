#include <Arduino.h>
#include <Wire.h>
#include <MemoryFree.h>

#include "hardware.h"
#include "phone_menu.h"

PhoneMenu menu;

void setup(void) {
  Serial.begin(9600);

  Hardware::setup();
}

void loop(void) {
  Hardware::update();
  menu.update();
  
  menu.draw();
  
  Serial.print(F("Free memory : "));
  Serial.println(freeMemory());
  delay(100);
}