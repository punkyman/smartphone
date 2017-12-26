#include "module_battery.h"
#include <Battery.h>
#include "globals.h"


namespace ModuleBattery
{
    uint8_t batterylevel;
    Battery battery(CURRENT_MIN, CURRENT_MAX, ANALOG_PIN_BATTERY);

    void setup()
    {
        batterylevel = 0;
        battery.begin();
    }

    void update()
    {
        batterylevel = battery.level();
    }
};

