#include <Arduino.h>
#include <Wire.h>
#include "i2c_communication.h"

#include "globals.h"

#include "module_compass.h"
#include "module_barometer.h"
#include "module_acceleration.h"
#include "module_gyroscope.h"
#include "module_display.h"
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
}

void loop(void) {
  ModuleGyroscope::update();
  ModuleCompass::update();
  ModuleAcceleration::update();
  if(ModuleBarometer::update() == 2)
  {
  //   Serial.print((int)ModuleBarometer::baroTemperature);
  // Serial.print('\n');
  // Serial.print((int)ModuleBarometer::baroPressure & 0xffff);
  // Serial.print('\n');
  }
  
  menu.update();
  
  Serial.print(ModuleGyroscope::gyroADC[0]);
  Serial.print(' ');
  Serial.print(ModuleGyroscope::gyroADC[1]);
  Serial.print(' ');
  Serial.print(ModuleGyroscope::gyroADC[2]);
  Serial.print('\n');

  // deley between each page
  ModuleDisplay::begin();
  menu.draw();
  ModuleDisplay::end();

  delay(100);
}