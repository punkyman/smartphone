#include "i2c_communication.h"

#include <Wire.h>

namespace i2c
{
uint8_t rawADC[6];

void setup(void)
{
  Wire.begin();
}

/* transform a series of bytes from big endian to little
   endian and vice versa. */
void swap_endianness(void *buf, size_t size)
{
  /* we swap in-place, so we only have to
  * place _one_ element on a temporary tray
  */
  uint8_t tray;
  uint8_t *from;
  uint8_t *to;
  /* keep swapping until the pointers have assed each other */
  for (from = (uint8_t *)buf, to = &from[size - 1]; from < to; from++, to--)
  {
    tray = *from;
    *from = *to;
    *to = tray;
  }
}


void read_reg_to_buf(uint8_t add, uint8_t reg, uint8_t *buf, uint8_t size)
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

void read_to_buf(uint8_t add, uint8_t *buf, uint8_t size)
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

void getSixRawADC(uint8_t add, uint8_t reg)
{
  read_reg_to_buf(add, reg, rawADC, 6);
}

void writeReg(uint8_t add, uint8_t reg, uint8_t val)
{
  Wire.beginTransmission(add);
  Wire.write(reg);
  Wire.write(val);
  Wire.endTransmission();
}

void selectReg(uint8_t add, uint8_t reg)
{
  Wire.beginTransmission(add);
  Wire.write(reg);
  Wire.endTransmission();
}

uint8_t readReg(uint8_t add, uint8_t reg)
{
  uint8_t val;
  read_reg_to_buf(add, reg, &val, 1);
  return val;
}

}