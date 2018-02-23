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
#if defined(STM32_MCU_SERIES)
        // ADC has to be enabled per pin on the stm32
        // don't want to modify the lib code, so it's done outside
        pinMode(BATTERY_ANALOG_READ, INPUT_ANALOG);  
#endif
        battery.begin(3300, 1.47);
    }

    void update()
    {
        batterylevel = battery.level();
    }
};

