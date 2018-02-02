#include "ATSerial.h"

ATSerial::ATSerial(uint8_t receivePin, uint8_t transmitPin)
: SoftwareSerial(receivePin,transmitPin)
{
}

void ATSerial::at_flush()
{
#ifdef SERIAL_DEBUG
if(buffer.length())
{
    Serial.println(F("## Flushing :"));
    Serial.println(buffer);
    Serial.println(F("##"));
}
#endif
    buffer = "";
    while(available())
    {
        read();
    }
}

void ATSerial::at_command(const __FlashStringHelper * cmd)
{
    at_flush();
    print(cmd);
    print('\r');
#ifdef SERIAL_DEBUG
Serial.println(cmd);
#endif    
}

void ATSerial::at_command(const __FlashStringHelper * cmd, int arg)
{
    at_flush();
    print(cmd);
    print(arg);
    print('\r');
#ifdef SERIAL_DEBUG
Serial.print(cmd);
Serial.println(arg);
#endif    
}

void ATSerial::at_command(const __FlashStringHelper * cmd, const char* arg)
{
    at_flush();
    print(cmd);
    print(arg);
    print('\r');
#ifdef SERIAL_DEBUG
Serial.print(cmd);
Serial.println(arg);
#endif
}

void ATSerial::at_text(const char* text)
{
    at_flush();
    print(text);
    print((char)26);
#ifdef SERIAL_DEBUG
Serial.println(text);
#endif
}

bool ATSerial::at_get_response()
{
    uint8_t nb = 0;

    while(1)
    {
        char c = timedRead();
        
        if(c == -1)
        {
#ifdef SERIAL_DEBUG
            Serial.println(F("No response"));
#endif    
            return false;
        }

        buffer += c;
        if(c == '\n')
        {
            ++nb;
            if(nb == 2)
            {
#ifdef SERIAL_DEBUG
                Serial.println(buffer.c_str());
#endif    
                return true;
            }
        }
    }
}

bool ATSerial::at_is_response_available()
{
    while(available())
        buffer += (char) read(); // force usage of the char method, otherwise it makes int

    uint8_t nb = 0;
    for(unsigned int i = 0; i < buffer.length(); ++i)
    {
        if(buffer[i] == '\n')
        {
            ++nb;
            if(nb == 2)
            {
#ifdef SERIAL_DEBUG
                Serial.println(buffer.c_str());
#endif    
                return true;
            }
        }
    }
    return false;
}

bool ATSerial::at_is_response(const char* rsp)
{
    return buffer.indexOf(rsp) != -1;
}

bool ATSerial::at_is_response_ok()
{
        return buffer.indexOf("OK") != -1;
}

bool ATSerial::at_get_response_tag(const char* tag, uint8_t* value)
{
    int index = buffer.indexOf(tag);
    if(index == -1)
    {
        return false;
    }
    else
    {
        uint8_t len = strlen(tag);
        int end_index = buffer.indexOf(',', index);
        end_index = (end_index == -1? buffer.length() : end_index);
        *value = buffer.substring(index + len, end_index).toInt();

        return true;
    }
}
