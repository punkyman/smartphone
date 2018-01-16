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
