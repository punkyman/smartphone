#include "globals.h"

namespace Globals
{
    int16_t g_temperature;

}; // namespace Globals

float g_get_temperature()
{
    return Globals::g_temperature / 100.0f; // according to module_barometer.cpp
}

void g_set_temperature(int16_t value)
{
    Globals::g_temperature = value;
}
