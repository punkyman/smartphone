# smartphone
The smartphone of the future :

The project aims to be a very simple platform based on arduino, allowing to plug modules and display / manipulate things on a screen.
The system embeds a bunch of sensors, some inputs, an RTC clock, a GPS, and a GSM module, hence the idea of smartphone !

The current hardware is based on :
- Arduino pro mini 3,3V : that embeds the AtMega328P, running at 8mhz, and providing 32kB of progmem, 2kB of ram
- a PCD8544 screen (the same as the nokia 5110)
- GY-80 sensor board : provides temperature/atmospheric pressure, a digital compass, an accelerometer, a gyroscope
- DS3231 RTC module
- NEO6MV2 gps module
- Sim800l GPRS module

And for the inputs, a Playstation2 joystick, and a rotary encoder.

![](./hardware.jpg)
