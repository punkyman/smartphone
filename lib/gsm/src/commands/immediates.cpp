#include "immediates.h"
#include "../ATSerial.h"

GSM_RESULT at_init(ATSerial* as)
{
    as->at_command(F("AT")); // global test command, used for autobauding
    if(!as->at_get_response())
        return GSM_TIMEOUT;
    if(!as->at_is_response_ok())
        return GSM_ERROR;

    as->at_command(F("AT&F0")); // reset to factory defined configuration
    if(!as->at_get_response())
        return GSM_TIMEOUT;
    if(!as->at_is_response_ok())
        return GSM_ERROR;

    as->at_command(F("ATE0")); // query no echo on serial output
    if(!as->at_get_response())
        return GSM_TIMEOUT;
    if(!as->at_is_response_ok())
        return GSM_ERROR;

    return GSM_OK;
}

GSM_RESULT at_get_signal_level(ATSerial* as, uint8_t* value)
{
    as->at_command(F("AT+CSQ"));
    if(!as->at_get_response())
        return GSM_TIMEOUT;

    if(!as->at_get_response_tag("+SCQ:", value))
        return GSM_ERROR;

    return GSM_OK;
}

GSM_RESULT at_set_microphone_gain(ATSerial* as, uint8_t value)
{
    if(value > 15)
    {
        return GSM_OK; // who cares
    }

    as->at_command(F("AT+CMIC=0,"), value);
    if(!as->at_get_response())
        return GSM_TIMEOUT;
    if(!as->at_is_response_ok())
        return GSM_ERROR;
    
    return GSM_OK;
}
