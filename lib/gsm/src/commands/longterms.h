#pragma once
#include <Arduino.h>
class ATSerial;

///////////////////////////////////////////////////////////////////////////////
// long delay commands
// each command will return either nullptr or a function pointer of this kind
// the function can parse the answer once it's received by the serial
///////////////////////////////////////////////////////////////////////////////
typedef bool (*COMMANDCALLBACK)(ATSerial* as);

COMMANDCALLBACK at_send_sms(ATSerial* as, const char* number,const char* text);
COMMANDCALLBACK at_call_number(ATSerial* as, const char* number);
