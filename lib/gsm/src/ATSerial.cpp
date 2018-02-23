#include "ATSerial.h"

ATSerial::ATSerial(uint8_t receivePin, uint8_t transmitPin)
: 
#if defined(STM32_MCU_SERIES)
    serial(Serial2)
#elif defined(__AVR_ARCH__)
    serial(receivePin,transmitPin)
#endif

{
    serial.begin(9600);
}

int ATSerial::timed_read()
{
  int c;
  unsigned long startMillis = millis();
  do {
    c = serial.read();
    if (c >= 0) return c;
  } while(millis() - startMillis < AT_SERIAL_TIMEOUT);
  return -1;     // -1 indicates timeout
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
    while(serial.available())
    {
        serial.read();
    }
}

void ATSerial::at_command(const __FlashStringHelper * cmd)
{
    at_flush();
    serial.print(cmd);
    serial.print('\r');
#ifdef SERIAL_DEBUG
    Serial.println(cmd);
#endif    
}

void ATSerial::at_command(const __FlashStringHelper * cmd, int arg)
{
    at_flush();
    serial.print(cmd);
    serial.print(arg);
    serial.print('\r');
#ifdef SERIAL_DEBUG
    Serial.print(cmd);
    Serial.println(arg);
#endif    
}

void ATSerial::at_command(const __FlashStringHelper * cmd, const char* arg)
{
    at_flush();
    serial.print(cmd);
    serial.print(arg);
    serial.print('\r');
#ifdef SERIAL_DEBUG
    Serial.print(cmd);
    Serial.println(arg);
#endif
}

void ATSerial::at_text(const char* text)
{
    at_flush();
    serial.print(text);
    serial.print((char)26);
#ifdef SERIAL_DEBUG
    Serial.println(text);
#endif
}

bool ATSerial::at_get_response()
{
    uint8_t nb = 0;

    while(1)
    {
        char c = timed_read();
        
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
    while(serial.available())
        buffer += (char) serial.read(); // force usage of the char method, otherwise it makes int

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
