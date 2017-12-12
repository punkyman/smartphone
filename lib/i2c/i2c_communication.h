#pragma once
#include <Arduino.h>

namespace i2c
{
    extern uint8_t rawADC[6];
    void setup();

void swap_endianness(void *buf, size_t size);

void writeReg(uint8_t add, uint8_t reg, uint8_t val);
// allows to prepare register reading
void selectReg(uint8_t add, uint8_t reg);

uint8_t readReg(uint8_t add, uint8_t reg);
// read instantly register values into buffer
void read_reg_to_buf(uint8_t add, uint8_t reg, uint8_t *buf, uint8_t size);
// read register after selection into buffer
void read_to_buf(uint8_t add, uint8_t *buf, uint8_t size);

void getSixRawADC(uint8_t add, uint8_t reg);

}
