#include "module_gps.h"
#include <SoftwareSerial.h>
#include "TinyGPS++.h"

namespace ModuleGps
{
    TinyGPSPlus gps;
    SoftwareSerial ss(GPS_RX_PIN, GPS_TX_PIN);

    void setup()
    {
        ss.begin(9600);
    }

    void update()
    {
         while (ss.available() > 0)
         {
            if (gps.encode(ss.read()))
            {
                // a sentence has been correctly decoded by the library
            }
         }
    }
}
