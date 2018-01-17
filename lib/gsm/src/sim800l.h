#pragma once
class SoftwareSerial;
#include <Arduino.h>

///////////////////////////////////////////////////////////////////////////////
// long delay commands
// each command will return either nullptr or a function pointer of this kind
// the function can parse the answer once it's received by the serial
///////////////////////////////////////////////////////////////////////////////
typedef bool (*COMMANDCALLBACK)(String);
COMMANDCALLBACK Sim800l_send_sms(SoftwareSerial* ss, const char* number,const char* text);

///////////////////////////////////////////////////////////////////////////////
// immediate commands
///////////////////////////////////////////////////////////////////////////////
bool Sim800l_init(SoftwareSerial* ss); // init is blocking, but we can accept that
bool Sim800l_get_signal_level(SoftwareSerial* ss, uint8_t* value);
