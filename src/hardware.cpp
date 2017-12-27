#include "hardware.h"

#include "i2c_communication.h"
#include "modules/module_compass.h"
#include "modules/module_barometer.h"
#include "modules/module_acceleration.h"
#include "modules/module_gyroscope.h"
#include "modules/module_display.h"
#include "modules/module_battery.h"
#include "modules/module_input.h"
#include "modules/module_gps.h"

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
        ModuleBattery::setup();
        ModuleInput::setup();
        ModuleGps::setup();
    }

    void update()
    {
        ModuleGyroscope::update();
        ModuleCompass::update();
        ModuleAcceleration::update();
        ModuleBarometer::update();
        ModuleBattery::update();
        ModuleInput::update();
        ModuleGps::update();
    }
}
