#include "module_gsm.h"
#include <SoftwareSerial.h>
#include <sim800l.h>
#include "hardware_config.h"

namespace ModuleGsm
{
    uint8_t signal_level = 0;
    SoftwareSerial ss(GSM_SS_RX, GSM_SS_TX);
    COMMANDCALLBACK callback = nullptr;
    
    unsigned long update_time = 0;
    unsigned long last_time = 0;

    void setup()
    {
        ss.begin(9600);
        Sim800l_init(&ss);

        last_time = micros();
    }

    void update()
    {
        update_time += (micros() - last_time);
        last_time = micros();

        if(callback)
        {
            if(ss.available())
            {
                callback(ss.readString().c_str());
                callback = nullptr;
            }
        }
        else if(SIGNAL_UPDATE)
        {
            if(update_time >= SIGNAL_UPDATE)
            {
                Sim800l_get_signal_level(&ss, &signal_level);
                update_time -= SIGNAL_UPDATE;
            }
        }
    }

    bool is_command_running()
    {
        return callback != nullptr;
    }

    uint8_t get_signal_level()
    {
        return signal_level;
    }
}
