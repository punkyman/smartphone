#include "hardware.h"
#include "hardware_config.h"

#include "i2c_communication.h"

#if defined(HARDWARE_ENABLE_SENSORS)
#include "modules/module_compass.h"
#include "modules/module_barometer.h"
#include "modules/module_acceleration.h"
#include "modules/module_gyroscope.h"
#endif

#include "modules/module_display.h"
#include "modules/module_input.h"

#if defined(HARDWARE_ENABLE_BATTERY)
#include "modules/module_battery.h"
#endif

#if defined(HARDWARE_ENABLE_GPS)
#include "modules/module_gps.h"
#endif

namespace Hardware
{
    void setup()
    {
        i2c::setup();
#if defined(HARDWARE_ENABLE_SENSORS)
        ModuleGyroscope::setup();
        ModuleCompass::setup();
        ModuleAcceleration::setup();
        ModuleBarometer::setup();
#endif

        ModuleDisplay::setup();
        ModuleInput::setup();

#if defined(HARDWARE_ENABLE_BATTERY)
        ModuleBattery::setup();
#endif
#if defined(HARDWARE_ENABLE_GPS)
        ModuleGps::setup();
#endif
    }

    void update()
    {
#if defined(HARDWARE_ENABLE_SENSORS)
        ModuleGyroscope::update();
        ModuleCompass::update();
        ModuleAcceleration::update();
        ModuleBarometer::update();
#endif
        ModuleInput::update();
#ifdef HARDWARE_ENABLE_BATTERY
        ModuleBattery::update();
#endif
#ifdef HARDWARE_ENABLE_GPS
        ModuleGps::update();
#endif
    }
}
