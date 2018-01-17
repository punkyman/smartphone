#include "ATSerial.h"
#include <SoftwareSerial.h>

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