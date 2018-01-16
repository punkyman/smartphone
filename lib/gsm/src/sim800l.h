#pragma once
class SoftwareSerial;
#include <Arduino.h>

enum SIM800L_MESSAGES
{
    SIM800L_OK = 0,
    SIM800L_FAILURE = 1,
};

///////////////////////////////////////////////////////////////////////////////
// long delay commands
// each command will return either nullptr or a function pointer of this kind
// the function can parse the answer once it's received by the serial
///////////////////////////////////////////////////////////////////////////////
typedef uint8_t (*COMMANDCALLBACK)(String);
COMMANDCALLBACK send_sms(SoftwareSerial* ss, const char* number,const char* text);

///////////////////////////////////////////////////////////////////////////////
// immediate commands
///////////////////////////////////////////////////////////////////////////////
uint8_t Sim800l_init(SoftwareSerial* ss); // init is blocking, but we can accept that
uint8_t Sim800l_get_signal_level(SoftwareSerial* ss, uint8_t* value);
