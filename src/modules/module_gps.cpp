#include "module_gps.h"
#if defined(PLATFORM_ststm32)
#include <HardwareSerial.h>
#elif defined(PLATFORM_atmelavr)
#include <SoftwareSerial.h>
#endif
#include "TinyGPS++.h"
#include "hardware_config.h"

#if defined(HARDWARE_ENABLE_GPS)

namespace ModuleGps
{
    TinyGPSPlus gps;
#if defined(PLATFORM_ststm32)
    HardwareSerial& serial = Serial2;
#elif defined(PLATFORM_atmelavr)
    SoftwareSerial serial(GPS_SS_RX, GPS_SS_TX);
#endif

    void setup()
    {
        serial.begin(9600);
    }

    void update()
    {
         while (serial.available() > 0)
         {
            int val = serial.read();
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

#endif
