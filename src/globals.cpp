#include "globals.h"
#include "modules/module_barometer.h"
#include "modules/module_battery.h"

// temporary string for all the operations; keep it low!
char str[16];

const char* g_get_temperature()
{
    dtostrf(ModuleBarometer::baroTemperature / 100.0f, 2, 2, str); // according to module_barometer.cpp
    snprintf(str, 16, "%s C", str);
    return str; 
}

const char* g_get_pressure()
{
    dtostrf(ModuleBarometer::baroPressure / 100.0f, 4, 0, str); // according to module_barometer.cpp
    snprintf(str, 16, "%s hPa", str);
    return str;
}

uint8_t g_get_battery_level()
{
    return ModuleBattery::batterylevel;
}
