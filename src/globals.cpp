#include "globals.h"

namespace Globals
{
    int16_t g_temperature = 0;
    int32_t g_pressure = 0;
    //String str;
}; // namespace Globals

const char* g_get_temperature()
{
    //Globals::str = String(Globals::g_temperature / 100.0f) + String(" C"); // according to module_barometer.cpp
    return "";//Globals::str.c_str(); 
}

void g_set_temperature(int16_t value)
{
    Globals::g_temperature = value;
}

const char* g_get_pressure()
{
    //Globals::str = String(Globals::g_pressure / 10.0f) + String(" hPa"); // according to module_barometer.cpp
    return "";//Globals::str.c_str(); 
}

void g_set_pressure(int32_t value)
{
    Globals::g_pressure = value;
}
