#include "globals.h"

namespace Globals
{
    int16_t g_temperature = 0;
    int32_t g_pressure = 0;
}; // namespace Globals

// temporary string for all the operations; keep it low!
char str[16];

const char* g_get_temperature()
{
    dtostrf(Globals::g_temperature / 100.0f, 2, 2, str); // according to module_barometer.cpp
    snprintf(str, 16, "%s C", str);
    return str; 
}

void g_set_temperature(int16_t value)
{
    Globals::g_temperature = value;
}

const char* g_get_pressure()
{
    dtostrf(Globals::g_pressure / 100.0f, 4, 0, str); // according to module_barometer.cpp
    snprintf(str, 16, "%s hPa", str);
    return str;
}

void g_set_pressure(int32_t value)
{
    Globals::g_pressure = value;
}
