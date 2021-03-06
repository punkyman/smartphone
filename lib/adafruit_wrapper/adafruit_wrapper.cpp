#include "adafruit_wrapper.h"

#include <Wire.h>
#include "Adafruit_GFX.h"

#ifdef USE_SH1106
#include "Adafruit_SH1106.h"
// random reset pin, not used anyway
#define OLED_RESET 4
Adafruit_SH1106 display(OLED_RESET);
#endif

#ifdef USE_PCD8544
#include "Adafruit_PCD8544.h"
// on arduino mini pinout is :
// SCK : 13, MOSI : 11
#define DIGITAL_PIN_DC 7
#define DIGITAL_PIN_CS 8
#define DIGITAL_PIN_RST 9
Adafruit_PCD8544 display(DIGITAL_PIN_DC, DIGITAL_PIN_CS, DIGITAL_PIN_RST);
#endif

#define ADA_WHITE 1
#define ADA_BLACK 0
#define ADA_INVERSE 2

void adafruit_setup(uint8_t address)
{
#ifdef USE_SH1106
  // the display does not have any reset pin
  display.begin(SH1106_SWITCHCAPVCC, address, false);
#endif
#ifdef USE_PCD8544
    display.begin();
#endif

  display.setTextColor(ADA_INVERSE); // write in inverse, so that composing with fillrect always works
}

uint16_t adafruit_get_width()
{
  return display.width();
}

uint16_t adafruit_get_height()
{
  return display.height();
}

void adafruit_setfontsize(uint8_t size)
{
  display.setTextSize(size);
}

void adafruit_get_text_size(const char* text, bool progmem, uint16_t* width, uint16_t* height)
{
  
  int16_t x, y;
  uint16_t w, h;
  if(progmem)
    display.getTextBounds((const __FlashStringHelper*) text, 0, 0, &x, &y, &w, &h);  
  else
    display.getTextBounds((char*) text, 0, 0, &x, &y, &w, &h); // beurk...

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

void adafruit_drawtext(uint16_t x, uint16_t y, const char* text, bool progmem)
{
  display.setCursor(x,y);
  if(progmem)
    display.print((const __FlashStringHelper*) text);
  else
    display.print(text);
}

void adafruit_drawline(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1)
{
  display.drawLine(x0, y0, x1, y1, ADA_WHITE);
}

void adafruit_drawrect(uint16_t x, uint16_t y, uint16_t w, uint16_t h)
{
  display.drawRect(x, y, w, h, ADA_WHITE);
}

void adafruit_fillrect(uint16_t x, uint16_t y, uint16_t w, uint16_t h)
{
  display.fillRect(x, y, w, h, ADA_WHITE);
}

void adafruit_eraserect(uint16_t x, uint16_t y, uint16_t w, uint16_t h)
{
  display.fillRect(x, y, w, h, ADA_BLACK);
}

void adafruit_drawcircle(uint16_t x, uint16_t y, uint16_t r)
{
  display.drawCircle(x, y, r, ADA_WHITE);
}

void adafruit_drawbitmap(uint16_t x, uint16_t y, uint16_t w, uint16_t h, const uint8_t data[])
{
  display.drawBitmap(x, y, data, w, h, ADA_WHITE);
}
