#include "longterms.h"
#include "../ATSerial.h"
#include <SoftwareSerial.h>

bool send_sms_callback(String str)
{
    return (str.indexOf("CMGS") != -1);
}

COMMANDCALLBACK at_send_sms(SoftwareSerial* ss, const char* number, const char* text)
{
    ss->print(F("AT+CMGF=1")); // set sms system into text mode
    if(!serial_wait_for_ok(ss))
        return nullptr;

    ss->print(F("AT+CSCS=1")); // set charset to GSM 7 bit default alphabet
    if(!serial_wait_for_ok(ss))
        return nullptr;
    
    ss->print(F("AT+CMGS=\""));
    ss->print(number);
    ss->print(F("\"\r"));
    ss->print(text);
    ss->print((char)26); // seems to be equivalent to <Ctrl+Z>

    return send_sms_callback;
}
