#include "ATSerial.h"

ATSerial::ATSerial(uint8_t receivePin, uint8_t transmitPin)
: SoftwareSerial(receivePin,transmitPin)
{
}

bool ATSerial::at_get_ok()
{
    while(available()){} // wait for the beginning of an answer in the pipe
    return readString().indexOf("OK") != -1; // text cannot be in progmem here
}

bool ATSerial::at_get_tag(const char* tag, uint8_t* value)
{
    while(!available()){} // wait for the beginning of an answer in the pipe
    String rsp = readString(); // some copy happens here, not the best...
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

bool at_stop_messages()
{
    return true;
//AT+EXUNSOL=SQ, 0
}

bool at_resume_messages()
{
    return true;
}
