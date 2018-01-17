#include "longterms.h"
#include "../ATSerial.h"

bool send_sms_callback(String str)
{
    return (str.indexOf("CMGS") != -1);
}

COMMANDCALLBACK at_send_sms(ATSerial* as, const char* number, const char* text)
{
    as->print(F("AT+CMGF=1")); // set sms system into text mode
    if(!as->at_wait_for_ok())
        return nullptr;

    as->print(F("AT+CSCS=1")); // set charset to GSM 7 bit default alphabet
    if(!as->at_wait_for_ok())
        return nullptr;
    
    as->print(F("AT+CMGS=\""));
    as->print(number);
    as->print(F("\"\r"));
    as->print(text);
    as->print((char)26); // seems to be equivalent to <Ctrl+Z>

    return send_sms_callback;
}
