#include "module_display.h"

#ifdef USE_ADAFRUIT
#include <adafruit_wrapper.h>
#endif

#ifdef USE_U8G2
#include <u8g2_wrapper.h>
#endif

namespace ModuleDisplay
{
  void setup()
  {
#ifdef USE_ADAFRUIT
    adafruit_setup(SH1106_ADDRESS);
#endif

#ifdef USE_U8G2
    u8g2_setup();
#endif
  }

uint8_t getScreenWidth()
{
#ifdef USE_ADAFRUIT
    return adafruit_get_width();
#endif
}

uint8_t getScreenHeight()
{
#ifdef USE_ADAFRUIT
    return adafruit_get_height();
#endif
}

void getTextSize(const char * text, bool progmem, uint8_t* width, uint8_t* height, uint8_t size)
{
#ifdef USE_ADAFRUIT
    adafruit_setfontsize(size);
    uint16_t w, h;
    adafruit_get_text_size(text, progmem, &w, &h);
    *width = w;
    *height = h;
    return;
#endif
}

void begin()
{
#ifdef USE_ADAFRUIT
    adafruit_begin();
#endif      
  }

  void end()
  {
#ifdef USE_ADAFRUIT
    adafruit_end();
#endif      
  }

  void drawText(uint8_t x, uint8_t y, const char * text, bool progmem, uint8_t size)
  {
#ifdef USE_ADAFRUIT
    adafruit_setfontsize(size);
    adafruit_drawtext(x, y, text, progmem);
#endif
  }

  void drawLine(uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1)
  {
#ifdef USE_ADAFRUIT
    adafruit_drawline(x0, y0, x1, y1);
#endif      
  }

  void drawRect(uint8_t x, uint8_t y, uint8_t w, uint8_t h)
  {
#ifdef USE_ADAFRUIT
    adafruit_drawrect(x, y, w, h);
#endif      
  }

  void fillRect(uint8_t x, uint8_t y, uint8_t w, uint8_t h)
  {
#ifdef USE_ADAFRUIT
    adafruit_fillrect(x, y, w, h);
#endif
  }

  void drawCircle(uint8_t x, uint8_t y, uint8_t r)
  {
#ifdef USE_ADAFRUIT
    adafruit_drawcircle(x, y, r);
#endif
  }

void drawBitmap(uint8_t x, uint8_t y, uint8_t w, uint8_t h, const uint8_t data[])
{
#ifdef USE_ADAFRUIT
    adafruit_drawbitmap(x, y, w, h, data);
#endif
}

}
