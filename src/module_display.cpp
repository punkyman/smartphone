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

  void draw_frame()
  {
#ifdef USE_ADAFRUIT
    adafruit_draw_frame();
#endif

#ifdef USE_U8G2
    u8g2_draw_frame();
#endif
  }
}
