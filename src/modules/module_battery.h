#pragma once

#define ANALOG_PIN_BATTERY A2
#define CURRENT_MIN 3700
#define CURRENT_MAX 4200

namespace ModuleBattery
{
    void setup();

    void update();
}
