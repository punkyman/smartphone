#include "module_rtc.h"
#include <ds3231.h>

namespace ModuleRtc
{
    struct ts t;
    float temperature;

    void setup()
    {
        DS3231_init(DS3231_INTCN);
    }

    void update()
    {
        DS3231_get(&t);
        temperature = DS3231_get_treg();
    }

    void get_time(uint8_t* hour, uint8_t* minutes)
    {
        *hour = t.hour;
        *minutes = t.min;
    }

    void get_date(uint8_t* day,uint8_t* month, uint16_t* year)
    {
        *day = t.mday;
        *month = t.mon;
        *year = t.year;
    }

    void set_time(uint8_t hour, uint8_t minutes)
    {
        DS3231_get(&t); // need to refresh here because t contains more than what we want to change
        t.hour = hour;
        t.min = minutes;
        DS3231_set(t);
    }

    void set_date(uint8_t day,uint8_t month, uint16_t year)
    {
        DS3231_get(&t);
        t.mday = day;
        t.mon = month;
        t.year = year;
        DS3231_set(t);
    }

    float get_temperature()
    {
        return temperature;
    }
}
