#include "module_gsm.h"
#include <gsm.h>
#include <hal.h>
#include "hardware_config.h"

#if defined(HARDWARE_ENABLE_GSM)

namespace ModuleGsm
{
    uint8_t signal_level = 0;
    ATSerial atserial(GSM_SS_RX, GSM_SS_TX);
    COMMANDCALLBACK callback = nullptr;

    unsigned long callback_timeout = 0;
    unsigned long signal_time = 0;

    void reset()
    {
        gsm_hard_reset(GSM_RESET);
        while(at_init(&atserial) != GSM_OK);

        at_init_gsm(&atserial, &callback);
        callback_timeout = millis() + AT_INIT_GSM_TIMEOUT;
    }

    void setup()
    {
        reset();
        signal_time = SIGNAL_UPDATE;
    }

    void update()
    {
        if(callback)
        {
            if(millis() > callback_timeout)
            {
                reset();
            }
            else if(atserial.at_is_response_available())
            {
                if(callback(&atserial) == GSM_OK)
                {
                    callback = nullptr;
                    Serial.println("Callback succeeded");
                }
                else
                {
                    reset();
                }
            }
        }
        else if(millis() >= signal_time)
        {
            if(at_get_signal_level(&atserial, &signal_level) != GSM_OK)
                reset();
            signal_time = millis() + SIGNAL_UPDATE;
        }
   }

    bool is_command_running()
    {
        return callback != nullptr;
    }

    bool call_number(const char* number)
    {
        if(is_command_running())
            return false;

        callback_timeout = millis() + AT_CALL_NUMBER_TIMEOUT;
        return at_call_number(&atserial, number, &callback) == GSM_OK;
    }

    bool send_sms(const char* number, const char* text)
    {
        if(is_command_running())
            return false;

        callback_timeout = millis() + AT_SEND_SMS_TIMEOUT;
        return at_send_sms(&atserial, number, text, &callback) == GSM_OK;
    }

    bool set_microphone_gain(uint8_t value)
    {
        if(is_command_running())
            return false;
        
        return at_set_microphone_gain(&atserial, value) == GSM_OK;
    }

    uint8_t get_signal_level()
    {
        return signal_level;
    }
}

#endif
