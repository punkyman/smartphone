#include "hardware.h"
#include "hardware_config.h"

#include "i2c_communication.h"
#include "modules/module_compass.h"
#include "modules/module_barometer.h"
#include "modules/module_acceleration.h"
#include "modules/module_gyroscope.h"
#include "modules/module_display.h"
#include "modules/module_input.h"

#ifdef HARDWARE_ENABLE_BATTERY
#include "modules/module_battery.h"
#endif

#ifdef HARDWARE_ENABLE_GPS
#include "modules/module_gps.h"
#endif
namespace Hardware
{
    void setup()
    {
      i2c::setup();

        ModuleGyroscope::setup();
        ModuleCompass::setup();
        ModuleAcceleration::setup();
        ModuleBarometer::setup();
        ModuleDisplay::setup();
        ModuleInput::setup();
#ifdef HARDWARE_ENABLE_BATTERY
        ModuleBattery::setup();
#endif
#ifdef HARDWARE_ENABLE_GPS
        ModuleGps::setup();
#endif
    }

    void update()
    {
        ModuleGyroscope::update();
        ModuleCompass::update();
        ModuleAcceleration::update();
        ModuleBarometer::update();
        ModuleInput::update();
#ifdef HARDWARE_ENABLE_BATTERY
        ModuleBattery::update();
#endif
#ifdef HARDWARE_ENABLE_GPS
        ModuleGps::update();
#endif
    }
}
