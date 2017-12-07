#include "i2c_communication.h"

#include <Wire.h>

namespace i2c
{
uint8_t rawADC[6];

void setup(void)
{
  Wire.begin();
}

void i2c_read_reg_to_buf(uint8_t add, uint8_t reg, uint8_t *buf, uint8_t size)
{
  Wire.beginTransmission(add);
  Wire.write(reg);
  Wire.endTransmission();

  Wire.requestFrom(add, size);

  if(Wire.available() >= size)
  {
    while (size > 0)
    {
      *buf = Wire.read();
      ++buf;
      --size;
    }
  }
}

void i2c_read_to_buf(uint8_t add, uint8_t *buf, uint8_t size)
{
  Wire.requestFrom(add, size);

  if(Wire.available() >= size)
  {
    while (size > 0)
    {
      *buf = Wire.read();
      ++buf;
      --size;
    }
  }
}

void i2c_getSixRawADC(uint8_t add, uint8_t reg)
{
  i2c_read_reg_to_buf(add, reg, rawADC, 6);
}

void i2c_writeReg(uint8_t add, uint8_t reg, uint8_t val)
{
  Wire.beginTransmission(add);
  Wire.write(reg);
  Wire.write(val);
  Wire.endTransmission();
}

void i2c_selectReg(uint8_t add, uint8_t reg)
{
  Wire.beginTransmission(add);
  Wire.write(reg);
  Wire.endTransmission();
}

uint8_t i2c_readReg(uint8_t add, uint8_t reg)
{
  uint8_t val;
  i2c_read_reg_to_buf(add, reg, &val, 1);
  return val;
}

}