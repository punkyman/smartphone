#include "immediates.h"
#include "../ATSerial.h"

bool at_init(ATSerial* as)
{
    as->print(F("AT\r")); // global test command, apparently also used for autobauding
    if(!as->at_get_ok())
        return false;

    as->print(F("AT&F0\r")); // reset to factory defined configuration
    if(!as->at_get_ok())
        return false;

    as->print(F("AT+CFUN=1\r")); // query full phone functionality, can take up to 10s...
    if(!as->at_get_ok())
        return false;
    
    as->print(F("AT+CPIN?\r")); // query sim unlocked, can take up to 5s...
    if(!as->at_get_ok())
        return false;
    
    return true;
}

bool at_get_signal_level(ATSerial* as, uint8_t* value)
{
    const char* tag = "+SCQ: ";
    as->print(F("AT+CSQ\r\n"));

    if(!as->at_get_tag(tag, value))
        return false;

    return true;
}
