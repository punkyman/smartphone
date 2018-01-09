#include "text.h"
#include "hardware_config.h"

#if defined(HARDWARE_ENABLE_SENSORS)
#include "modules/module_barometer.h"
#include "modules/module_compass.h"
#endif
#if defined(HARDWARE_ENABLE_GPS)
#include "modules/module_gps.h"
#endif
#if defined(HARDWARE_ENABLE_RTC)
#include "modules/module_rtc.h"
#endif

// temporary string for all the operations; keep it low!
// also consider that snprintf functions support passing identical destination and source  
char str[16];

const char* g_get_temperature()
{
#if defined(HARDWARE_ENABLE_SENSORS)
    dtostrf(ModuleBarometer::baroTemperature / 100.0f, 2, 2, str); // according to module_barometer.cpp
    snprintf_P(str, 16, PSTR("%s C"), str);
#elif defined(HARDWARE_ENABLE_RTC)
    dtostrf(ModuleRtc::get_temperature(), 2, 2, str);
    snprintf_P(str, 16, PSTR("%s C"), str);
#else
    strcpy_P(str, PSTR("No sensor"));
#endif
    return str; 
}

const char* g_get_pressure()
{
#if defined(HARDWARE_ENABLE_SENSORS)
    dtostrf(ModuleBarometer::baroPressure / 100.0f, 4, 0, str); // according to module_barometer.cpp
    snprintf_P(str, 16, PSTR("%s hPa"), str);
#else
    strcpy_P(str, PSTR("No sensor"));
#endif
    return str;
}


const char* g_get_clock()
{
#if defined(HARDWARE_ENABLE_RTC)
    uint8_t hours, minutes;
    ModuleRtc::get_time(&hours, &minutes);
    snprintf_P(str, 16, PSTR("%02i:%02i"), hours, minutes);
#elif defined(HARDWARE_ENABLE_GPS)
    uint8_t hours, minutes;
    ModuleGps::get_time(&hours, &minutes);
    snprintf_P(str, 16, PSTR("%02i:%02i"), hours, minutes);
#else
    snprintf_P(str, 16, PSTR("%02i:%02i"), 12, 59);
#endif

    return str;
}

const char* g_get_date()
{
#if defined(HARDWARE_ENABLE_RTC)
    uint8_t day, month;
    uint16_t year;
    ModuleRtc::get_date(&day, &month, &year);
    snprintf_P(str, 16, PSTR("%02i/%02i/%i"), day, month, year);
#elif defined(HARDWARE_ENABLE_GPS)
    uint8_t day, month;
    uint16_t year;
    ModuleGps::get_date(&day, &month, &year);
    snprintf_P(str, 16, PSTR("%02i/%02i/%i"), day, month, year);
#else
    snprintf_P(str, 16, PSTR("%02i/%02i/%i"), 21, 01, 2018);
#endif

    return str;
}


const char* g_get_location()
{
#ifdef HARDWARE_ENABLE_GPS
    double latitude, longitude;
    char str_double[8];

    if(ModuleGps::get_location(&latitude,&longitude))
    {
        dtostrf(latitude, 2, 2, str_double);
        snprintf_P(str, 16, PSTR("N%s"), str_double);
        dtostrf(longitude, 2, 2, str_double);
        snprintf_P(str, 16, PSTR("%s E%s"), str, str_double);
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
#if defined(HARDWARE_ENABLE_GPS)
    snprintf_P(str, 16, PSTR("%i"), ModuleGps::get_satellites());
#else
    strcpy_P(str, PSTR("No Gps"));
#endif
    return str;
}

const char* g_get_altitude()
{
#if defined(HARDWARE_ENABLE_GPS)
    snprintf_P(str, 16, PSTR("%i m"), (uint32_t)ModuleGps::get_altitude());
#else
    strcpy_P(str, PSTR("No Gps"));
#endif
    return str;
}

const char* g_get_speed()
{
#if defined(HARDWARE_ENABLE_GPS)
    snprintf_P(str, 16, PSTR("%i km/h"), (uint32_t)ModuleGps::get_speed());
#else
    strcpy_P(str, PSTR("No Gps"));
#endif
    return str;
}

