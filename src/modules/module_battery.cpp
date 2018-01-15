#include "module_battery.h"
#include <Battery.h>
#include "hardware_config.h"

namespace ModuleBattery
{
    uint8_t batterylevel;
    Battery battery(CURRENT_MIN, CURRENT_MAX, BATTERY_ANALOG_READ);

    void setup()
    {
        batterylevel = 0;
        battery.begin(3300, 1.47);
    }

    void update()
    {
        batterylevel = battery.level();
    }
};

