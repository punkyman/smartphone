#include <Arduino.h>
#include <Wire.h>
#include "i2c_communication.h"

#include "globals.h"

#include "module_compass.h"
#include "module_barometer.h"
#include "module_acceleration.h"
#include "module_gyroscope.h"
#include "module_display.h"

#include "menu.h"

void setup(void) {
  Serial.begin(9600);
  i2c::setup();

  ModuleGyroscope::setup();
  ModuleCompass::setup();
  ModuleAcceleration::setup();
  ModuleBarometer::setup();
  ModuleDisplay::setup();

  Menu::RootPage rootMenu((uint8_t)1);
  Menu::DisplayFloatWidget(&rootMenu, "temperature", &Globals::g_get_temperature);
}

void loop(void) {
  ModuleGyroscope::update();
  ModuleCompass::update();
  ModuleAcceleration::update();
  if(ModuleBarometer::update() == 2)
  {
    Globals::g_temperature = ModuleBarometer::baroTemperature; 
  //   Serial.print((int)ModuleBarometer::baroTemperature);
  // Serial.print('\n');
  // Serial.print((int)ModuleBarometer::baroPressure & 0xffff);
  // Serial.print('\n');
  }
  ModuleDisplay::draw_frame();

  Serial.print(ModuleGyroscope::gyroADC[0]);
  Serial.print(' ');
  Serial.print(ModuleGyroscope::gyroADC[1]);
  Serial.print(' ');
  Serial.print(ModuleGyroscope::gyroADC[2]);
  Serial.print('\n');

  // deley between each page
  
  delay(100);

}