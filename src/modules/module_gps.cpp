#include "module_gps.h"
#include <SoftwareSerial.h>
#include "TinyGPS++.h"

namespace ModuleGps
{
    TinyGPSPlus gps;
    SoftwareSerial ss(GPS_RX_PIN, GPS_TX_PIN);


void displayInfo()
{ 
  if (gps.location.isValid())
  {
      Serial.print(("Location: "));
    Serial.print(gps.location.lat(), 6);
    Serial.print((","));
    Serial.print(gps.location.lng(), 6);
  }

  Serial.println();
}

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
            //Serial.print((char)val);
            //if (gps.encode(val))
            //{
            //    Serial.println();
                //displayInfo();
            //}
         }
    }

    bool get_location(uint16_t* lat_deg, double* lat_bil, uint16_t* long_deg, double* long_bil)
    {
        if(!gps.location.isValid())
            return false;

        *lat_deg = gps.location.rawLat().deg;
        *lat_bil = gps.location.rawLat().billionths;
        *long_deg = gps.location.rawLng().deg;
        *long_bil = gps.location.rawLng().billionths;

        return true;
    }

    uint32_t get_satellites()
    {
        return gps.satellites.value();
    }
}
