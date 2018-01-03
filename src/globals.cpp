#include "globals.h"
#include "hardware_config.h"

#include "modules/module_barometer.h"
#include "modules/module_compass.h"
#include "modules/module_battery.h"
#include "modules/module_gps.h"

// temporary string for all the operations; keep it low!
// also consider that snprintf functions support passing identical destination and source  
char str[16];

const char* g_get_temperature()
{
    dtostrf(ModuleBarometer::baroTemperature / 100.0f, 2, 2, str); // according to module_barometer.cpp
    snprintf_P(str, 16, PSTR("%s C"), str);
    return str; 
}

const char* g_get_pressure()
{
    dtostrf(ModuleBarometer::baroPressure / 100.0f, 4, 0, str); // according to module_barometer.cpp
    snprintf_P(str, 16, PSTR("%s hPa"), str);
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
    snprintf_P(str, 16, PSTR("%i:%i"), 12, 59);
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

const char* g_get_location()
{
#ifdef HARDWARE_ENABLE_GPS
    uint16_t lat_deg, long_deg;
    double lat_bil, long_bil;
    char str_double[8];

    if(ModuleGps::get_location(&lat_deg, &lat_bil, &long_deg, &long_bil))
    {
        dtostrf(lat_bil, 2, 2, str_double);
        snprintf_P(str, 16, PSTR("N %i/%s"), lat_deg, str_double);
        dtostrf(long_deg, 2, 2, str_double);
        snprintf_P(str, 16, PSTR("%s E %i/%s"), str, long_deg, str_double);
    }
    else
    {
        strcpy_P(str, PSTR("No fix"));
    }
#else
    strcpy_P(str, PSTR("No Gps"));
#endif

    return str;
}

const char* g_get_satellites()
{
    snprintf_P(str, 16, PSTR("%i"), ModuleGps::get_satellites());

    return str;
}