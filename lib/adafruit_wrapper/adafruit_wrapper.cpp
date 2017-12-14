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

uint16_t adafruit_get_width()
{
  return display.width();
}

uint16_t adafruit_get_height()
{
  return display.height();
}

void adafruit_get_text_size(const char* text, uint16_t* width, uint16_t* height)
{
  uint16_t x, y, w, h;
  display.getTextBounds(text, 0, 0, &x, &y, &w, &h);

  *width = x > w ? x : w;
  *height = y > h ? y : h;
}

void adafruit_begin()
{
  display.clearDisplay();
}

void adafruit_end()
{
  display.display();
}

void adafruit_drawtext(uint16_t x, uint16_t y, const char* text)
{
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(x,y);
  display.print(text);
}
