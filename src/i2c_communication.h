#pragma once
#include <Arduino.h>

namespace i2c
{
    extern uint8_t rawADC[6];
    void setup();

void i2c_writeReg(uint8_t add, uint8_t reg, uint8_t val);
// allows to prepare register reading
void i2c_selectReg(uint8_t add, uint8_t reg);

uint8_t i2c_readReg(uint8_t add, uint8_t reg);
// read instantly register values into buffer
void i2c_read_reg_to_buf(uint8_t add, uint8_t reg, uint8_t *buf, uint8_t size);
// read register after selection into buffer
void i2c_read_to_buf(uint8_t add, uint8_t *buf, uint8_t size);

void i2c_getSixRawADC(uint8_t add, uint8_t reg);

}
