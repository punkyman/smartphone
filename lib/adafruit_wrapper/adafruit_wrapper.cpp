#include "adafruit_wrapper.h"

#include <Wire.h>
#include "Adafruit_GFX.h"
#include "Adafruit_SH1106.h"

// random reset pin, not used anyway
#define OLED_RESET 4
Adafruit_SH1106 display(OLED_RESET);

void adafruit_setup(uint8_t address)
{
  // the display does not have any reset pin
  display.begin(SH1106_SWITCHCAPVCC, address, false);
}

void adafruit_draw_frame()
{
  display.display();
}
