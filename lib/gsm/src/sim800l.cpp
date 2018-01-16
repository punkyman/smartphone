#include "sim800l.h"
#include <SoftwareSerial.h>

char internal_buffer[64];

bool serial_wait_for_ok(SoftwareSerial* ss)
{
    while(!ss->available()){} // wait for the beginning of an answer in the pipe
    return ss->readString().indexOf("OK") != -1; // text cannot be in progmem here
}

bool serial_get_tag(SoftwareSerial* ss, const char* tag, uint8_t* value)
{
    while(!ss->available()){} // wait for the beginning of an answer in the pipe
    String rsp = ss->readString(); // some copy happens here, not the best...
    int index = rsp.indexOf(tag);
    if(index == -1)
    {
        return false;
    }
    else
    {
        uint8_t len = strlen(tag);
        int end_index = rsp.indexOf(',', index);
        end_index = (end_index == -1? rsp.length() : end_index);
        *value = rsp.substring(index + len, end_index).toInt();

        return true;
    }
}

uint8_t send_sms_callback(String str)
{
    if(str.indexOf("CMSG") == -1)
    {
        return SIM800L_FAILURE;
    }
    else
    {
        return SIM800L_OK;
    }
}

COMMANDCALLBACK Sim800l_send_sms(SoftwareSerial* ss, const char* number, const char* text)
{
    ss->print(F("AT+CMGF=1")); // set sms system into text mode
    if(!serial_wait_for_ok(ss))
        return nullptr;

    ss->print(F("AT+CSCS=1")); // set charset to GSM 7 bit default alphabet
    if(!serial_wait_for_ok(ss))
        return nullptr;
    
    ss->print(F("AT+CGMS=\""));
    ss->print(number);
    ss->print(F("\"\r"));
    ss->print(text);
    ss->print((char)26); // seems to be equivalent to <Ctrl+Z>

    return send_sms_callback;
}

uint8_t Sim800l_init(SoftwareSerial* ss)
{
    ss->print(F("AT\r\n")); // global test command
    if(!serial_wait_for_ok(ss))
        return SIM800L_FAILURE;

    ss->print(F("AT+CFUN=1\r\n")); // query full phone functionality
    if(!serial_wait_for_ok(ss))
        return SIM800L_FAILURE;
    
    ss->print(F("AT+CPIN?\r\n")); // query sim unlocked
    if(!serial_wait_for_ok(ss))
        return SIM800L_FAILURE;
    
    return SIM800L_OK;
}

uint8_t Sim800l_get_signal_level(SoftwareSerial* ss, uint8_t* value)
{
    const char* tag = "+SCQ: ";
    ss->print(F("AT+CSQ\r\n"));

    if(!serial_get_tag(ss, tag, value))
        return SIM800L_FAILURE;

    return SIM800L_OK;
}
