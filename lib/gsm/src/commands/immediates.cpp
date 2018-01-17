#include "immediates.h"
#include <SoftwareSerial.h>
#include "../ATSerial.h"

bool at_init(SoftwareSerial* ss)
{
    ss->print(F("AT\r\n")); // global test command
    if(!serial_wait_for_ok(ss))
        return false;

    ss->print(F("AT+CFUN=1\r\n")); // query full phone functionality
    if(!serial_wait_for_ok(ss))
        return false;
    
    ss->print(F("AT+CPIN?\r\n")); // query sim unlocked
    if(!serial_wait_for_ok(ss))
        return false;
    
    return true;
}

bool at_get_signal_level(SoftwareSerial* ss, uint8_t* value)
{
    const char* tag = "+SCQ: ";
    ss->print(F("AT+CSQ\r\n"));

    if(!serial_get_tag(ss, tag, value))
        return false;

    return true;
}
