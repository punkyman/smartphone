#include "immediates.h"
#include "../ATSerial.h"

bool at_init(ATSerial* as)
{
    as->print(F("AT\r\n")); // global test command
    if(!as->at_wait_for_ok())
        return false;

    as->print(F("AT+CFUN=1\r\n")); // query full phone functionality
    if(!as->at_wait_for_ok())
        return false;
    
    as->print(F("AT+CPIN?\r\n")); // query sim unlocked
    if(!as->at_wait_for_ok())
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
