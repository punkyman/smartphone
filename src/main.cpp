#include <Arduino.h>

#include "module_display.h"

void setup(void) {
  ModuleDisplay::setup();
}

void loop(void) {
  ModuleDisplay::draw_frame();
  // deley between each page
  delay(100);

}