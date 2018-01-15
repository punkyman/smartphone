#include "module_gps.h"
#include <SoftwareSerial.h>
#include "TinyGPS++.h"
#include "hardware_config.h"

namespace ModuleGps
{
    TinyGPSPlus gps;
    SoftwareSerial ss(GPS_SS_RX, GPS_SS_TX);

    void setup()
    {
        ss.begin(9600);
    }

    void update()
    {
         while (ss.available() > 0)
         {
            int val = ss.read();
            gps.encode(val);
         }
    }

    bool get_location(double* latitude, double* longitude)
    {
        if(!gps.location.isValid())
            return false;

        *latitude = gps.location.lat();
        *longitude = gps.location.lng();

        return true;
    }

    uint32_t get_satellites()
    {
        return gps.satellites.value();
    }

    void get_time(uint8_t* hour, uint8_t* minutes)
    {
        *hour = gps.time.hour();
        *minutes = gps.time.minute();
    }

    void get_date(uint8_t* day,uint8_t* month, uint16_t* year)
    {
        *day = gps.date.day();
        *month = gps.date.month();
        *year = gps.date.year();
    }

    double get_altitude()
    {
        return gps.altitude.meters();
    }

    double get_speed()
    {
        return gps.speed.kmph();
    }
}
