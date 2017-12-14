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
  display.setTextSize(1);
  display.setTextColor(WHITE);
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
  char* str = (char*) text; // beurk...
  uint16_t x, y, w, h;
  display.getTextBounds(str, 0, 0, &x, &y, &w, &h);

  // according to comments, getTextBounds returns UL corner and W,H
  *width = w;
  *height = h;
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
  display.setCursor(x,y);
  display.print(text);
}

void adafruit_drawline(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1)
{
  display.drawLine(x0, y0, x1, y1, WHITE);
}

void adafruit_drawrect(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1)
{
  display.drawRect(x0, y0, x1, y1, WHITE);
}
