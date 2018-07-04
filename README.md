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

STM32F103C8T6 support, on 4.3.1 sdk, the following modification has to be made :

in
/home/punky/.platformio/packages/framework-arduinoststm32/STM32F1/libraries/Wire/Wire.cpp :
//TwoWire Wire(1);
TwoWire Wire(1, 0x4);

because of :
in
/home/punky/.platformio/packages/framework-arduinoststm32/STM32F1/system/libmaple/stm32f1/include/series/i2c.h

/* Flag to use alternate pin mapping in i2c_master_enable(). */
#define _I2C_HAVE_DEPRECATED_I2C_REMAP 1
#define I2C_REMAP 0x4

