#include "module_gsm.h"
#include <gsm.h>
#include "hardware_config.h"

#if defined(HARDWARE_ENABLE_GSM)

namespace ModuleGsm
{
    uint8_t signal_level = 0;
    ATSerial atserial(GSM_SS_RX, GSM_SS_TX);
    COMMANDCALLBACK callback = nullptr;
    bool reset = false;

    unsigned long update_time = 0;
    unsigned long last_time = 0;

    void setup()
    {
        atserial.begin(9600);
        reset = true;
        last_time = micros();
    }

    void update()
    {
        update_time += (micros() - last_time);
        last_time = micros();

        if(reset)
        {
            reset = !at_init(&atserial);
            if(!reset)
                callback = at_init_gsm(&atserial);

            return;
        }

        if(callback)
        {
            if(atserial.at_is_response_available())
            {
                reset = !callback(&atserial);
                if(!reset)
                {
                    Serial.println("Callback succeeded");
                }
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

    bool set_microphone_gain(uint8_t value)
    {
        if(is_command_running())
            return false;
        
        return at_set_microphone_gain(&atserial, value);
    }

    uint8_t get_signal_level()
    {
        return signal_level;
    }
}

#endif
