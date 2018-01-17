#include "module_gsm.h"
#include <gsm.h>
#include "hardware_config.h"

namespace ModuleGsm
{
    uint8_t signal_level = 0;
    ATSerial atserial(GSM_SS_RX, GSM_SS_TX);
    COMMANDCALLBACK callback = nullptr;

    unsigned long update_time = 0;
    unsigned long last_time = 0;

    void setup()
    {
        atserial.begin(9600);
        at_init(&atserial);

        last_time = micros();
    }

    void update()
    {
        update_time += (micros() - last_time);
        last_time = micros();

        if(callback)
        {
            if(atserial.available())
            {
                bool result = callback(&atserial);
                callback = nullptr;
            }
        }
        else if(update_time >= SIGNAL_UPDATE)
        {
            at_get_signal_level(&atserial, &signal_level);
            update_time -= SIGNAL_UPDATE;
        }
   }

    bool is_command_running()
    {
        return callback != nullptr;
    }

    bool send_sms(const char* number, const char* text)
    {
        if(is_command_running())
            return false;

        callback = at_send_sms(&atserial, number, text);

        return callback != nullptr;
    }

    uint8_t get_signal_level()
    {
        return signal_level;
    }
}
