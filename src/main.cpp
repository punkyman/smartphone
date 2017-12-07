#include <Arduino.h>
#include <Wire.h>

#include "i2c_communication.h"
#include "module_barometer.h"
#include "module_acceleration.h"
#include "module_display.h"

void setup(void) {
  i2c::setup();

  ModuleAcceleration::setup();
  ModuleBarometer::setup();
  ModuleDisplay::setup();
}

void loop(void) {
  ModuleBarometer::update();
  ModuleDisplay::draw_frame();
  // deley between each page
  delay(100);

}