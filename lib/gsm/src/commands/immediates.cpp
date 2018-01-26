#include "immediates.h"
#include "../ATSerial.h"

bool at_init(ATSerial* as)
{
    as->at_command(F("AT")); // global test command, used for autobauding
    if(!as->at_get_response())
        return false;
    if(!as->at_is_response_ok())
        return false;

    as->at_command(F("AT&F0")); // reset to factory defined configuration
    if(!as->at_get_response())
        return false;
    if(!as->at_is_response_ok())
        return false;

    as->at_command(F("ATE0")); // query no echo on serial output
    if(!as->at_get_response())
        return false;
    if(!as->at_is_response_ok())
        return false;

    return true;
}

bool at_get_signal_level(ATSerial* as, uint8_t* value)
{
    as->at_command(F("AT+CSQ"));
    if(!as->at_get_response())
        return false;

    if(!as->at_get_response_tag("+SCQ:", value))
        return false;

    return true;
}

bool at_set_microphone_gain(ATSerial* as, uint8_t value)
{
    if(value > 15)
    {
        return true; // who cares
    }

    as->at_command(F("AT+CMIC=0,"), value);
    if(!as->at_get_response())
        return false;
    if(!as->at_is_response_ok())
        return false;
    
    return true;
}
