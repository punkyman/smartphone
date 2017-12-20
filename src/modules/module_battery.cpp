#include "module_battery.h"
#include <Battery.h>
#include "globals.h"


namespace ModuleBattery
{
    Battery battery(CURRENT_MIN, CURRENT_MAX, ANALOG_PIN_BATTERY);

    void setup()
    {
        battery.begin();
    }

    void update()
    {
        g_set_battery_level(battery.level());
    }
};

