#include <Arduino.h>
#include <Wire.h>
#include <MemoryFree.h>

#include "i2c_communication.h"
#include "modules/module_compass.h"
#include "modules/module_barometer.h"
#include "modules/module_acceleration.h"
#include "modules/module_gyroscope.h"
#include "modules/module_display.h"
#include "modules/module_input.h"
#include "phone_menu.h"

PhoneMenu menu;

void setup(void) {
  Serial.begin(9600);
  i2c::setup();

  ModuleGyroscope::setup();
  ModuleCompass::setup();
  ModuleAcceleration::setup();
  ModuleBarometer::setup();
  ModuleDisplay::setup();
  ModuleInput::setup();
}

void loop(void) {
  ModuleGyroscope::update();
  ModuleCompass::update();
  ModuleAcceleration::update();
  if(ModuleBarometer::update() == 2)
  {
  //Serial.print((int)ModuleBarometer::baroTemperature);
  //Serial.print('\n');
  //Serial.print((int)ModuleBarometer::baroPressure);
  //Serial.print('\n');
  }

  ModuleInput::update();
  menu.update();
  
  ModuleDisplay::begin();
  menu.draw();
  ModuleDisplay::end();
  
  Serial.print(F("Free memory : "));
  Serial.println(freeMemory());
  delay(100);
}