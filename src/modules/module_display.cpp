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

  void drawText(uint8_t x, uint8_t y, const char* text)
  {
#ifdef USE_ADAFRUIT
    adafruit_drawtext(x, y, text);
#endif
  }

}
