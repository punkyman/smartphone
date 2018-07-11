# smartphone
The smartphone of the future :

The project aims to be a very simple platform based on arduino, allowing to plug modules and display / manipulate things on a screen.
The system embeds a bunch of sensors, some inputs, an RTC clock, a GPS, and a GSM module, hence the idea of smartphone !



Hardware v2 is based on similar components as v1, except :
- Custom circuit board is now in place to link all the components together. See pcb-design\ for the gerber files used to produce the circuit board
- Arduino pro mini has been replaced by a stm32f103c8t6 (aka the bluepill). The main issue with arduino was a code size issue, where everything could not fit into 32kb of ram. The code has been ported to the bluepill by using the maple framework.
- The screen has been replaced with a sh1106. This gives better resolution than the nokia, and simplifies the circuit board since it works in i2c instead of SPI for the PCD8544.

![](./hardware-v2.jpg)



Hardware v1 was based on :
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

