#include "globals.h"

namespace Globals
{
    int16_t g_temperature = 0;
    int32_t g_pressure = 0;

}; // namespace Globals

float g_get_temperature()
{
    return Globals::g_temperature / 100.0f; // according to module_barometer.cpp
}

void g_set_temperature(int16_t value)
{
    Globals::g_temperature = value;
}

uint32_t g_get_pressure()
{
    return Globals::g_pressure;
}

void g_set_pressure(int32_t value)
{
    Globals::g_pressure = value;
}
