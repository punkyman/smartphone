#include "module_gsm.h"
#include <SoftwareSerial.h>
#include <sim800l.h>
#include "hardware_config.h"

namespace ModuleGsm
{
    uint8_t signal_level = 0;
    SoftwareSerial ss(GSM_SS_RX, GSM_SS_TX);
    COMMANDCALLBACK callback = nullptr;

    void setup()
    {
        ss.begin(9600);
        callback = Sim800l_init(&ss);
    }

    void update()
    {
        if(callback)
        {
            if(ss.available())
            {
                callback(ss.readString().c_str());
                callback = nullptr;
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
