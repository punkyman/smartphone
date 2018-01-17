#pragma once
#include <Arduino.h>
class ATSerial;

///////////////////////////////////////////////////////////////////////////////
// long delay commands
// each command will return either nullptr or a function pointer of this kind
// the function can parse the answer once it's received by the serial
///////////////////////////////////////////////////////////////////////////////
typedef bool (*COMMANDCALLBACK)(String);
COMMANDCALLBACK at_send_sms(ATSerial* as, const char* number,const char* text);
