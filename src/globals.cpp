#include "globals.h"
#include "hardware_config.h"

#include "modules/module_barometer.h"
#include "modules/module_compass.h"
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
#ifdef HARDWARE_ENABLE_BATTERY
    return ModuleBattery::batterylevel;
#else
    return 100;
#endif
}

bool g_get_compass_data(float* roll, float* pitch/*, float* yaw*/)
{
    *roll = ModuleCompass::magADC[ModuleCompass::ROLL];
    *pitch = -ModuleCompass::magADC[ModuleCompass::PITCH]; // board placement correction
    /* *yaw = ModuleCompass::magADC[ModuleCompass::YAW]; */
    
    float norm = sqrt((*roll * *roll) + (*pitch * *pitch) /*+ (*yaw * *yaw) */);
    *roll /= norm;
    *pitch /= norm;
    /* *yaw /= norm; */

    return !ModuleCompass::calibrateMag;
}

const char* g_get_clock()
{
#ifdef HARDWARE_ENABLE_CLOCK
// TODO CR3231
#else
    snprintf(str, 16, "%i:%i", 12, 59);
    return str;
#endif
}

uint8_t g_get_rssi()
{
#ifdef HARDWARE_ENABLE_GSM
    // 0             -115  dBm  or  less    
    // 1             -111  dBm  
    // 2...30      -110... -54 dBm 
    // 31            -52  dBm  or  greater  
    // 99            not  known  or  not  detectable  
#else
    return 31;
#endif
}
