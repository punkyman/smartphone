#include "module_barometer.h"
#include "i2c_communication.h"
#include "globals.h"

// principle:
//  1) read the calibration register (only once at the initialization)
//  2) read uncompensated temperature (not mandatory at every cycle)
//  3) read uncompensated pressure
//  4) raw temp + raw pressure => calculation of the adjusted pressure
//  the following code uses the maximum precision setting (oversampling setting 3)

namespace ModuleBarometer
{
uint32_t currentTime = 0;
int32_t baroPressure;
int16_t baroTemperature;
int32_t baroPressureSum;

static struct
{
  // sensor registers from the BOSCH BMP085 datasheet
  int16_t ac1, ac2, ac3;
  uint16_t ac4, ac5, ac6;
  int16_t b1, b2, mb, mc, md;
  union {
    uint16_t val;
    uint8_t raw[2];
  } ut; //uncompensated T
  union {
    uint32_t val;
    uint8_t raw[4];
  } up; //uncompensated P
  uint8_t state;
  uint32_t deadline;
} bmp085_ctx;
#define OSS 3

static void Baro_Common()
{
  static int32_t baroHistTab[BARO_TAB_SIZE];
  static uint8_t baroHistIdx;

  uint8_t indexplus1 = (baroHistIdx + 1);
  if (indexplus1 == BARO_TAB_SIZE)
    indexplus1 = 0;
  baroHistTab[baroHistIdx] = baroPressure;
  baroPressureSum += baroHistTab[baroHistIdx];
  baroPressureSum -= baroHistTab[indexplus1];
  baroHistIdx = indexplus1;
}

void i2c_BMP085_readCalibration()
{
  delay(10);
  //read calibration data in one go
  size_t s_bytes = (uint8_t *)&bmp085_ctx.md - (uint8_t *)&bmp085_ctx.ac1 + sizeof(bmp085_ctx.ac1);
  i2c::read_reg_to_buf(BMP085_ADDRESS, 0xAA, (uint8_t *)&bmp085_ctx.ac1, s_bytes);
  // now fix endianness
  int16_t *p;
  for (p = &bmp085_ctx.ac1; p <= &bmp085_ctx.md; p++)
  {
    i2c::swap_endianness(p, sizeof(*p));
  }
}

// read uncompensated temperature value: send command first
void i2c_BMP085_UT_Start(void)
{
  i2c::writeReg(BMP085_ADDRESS, 0xf4, 0x2e);
  i2c::selectReg(BMP085_ADDRESS, 0xF6);
}

// read uncompensated pressure value: send command first
void i2c_BMP085_UP_Start()
{
  i2c::writeReg(BMP085_ADDRESS, 0xf4, 0x34 + (OSS << 6)); // control register value for oversampling setting 3
  i2c::selectReg(BMP085_ADDRESS, 0xF6);
}

// read uncompensated pressure value: read result bytes
// the datasheet suggests a delay of 25.5 ms (oversampling settings 3) after the send command
void i2c_BMP085_UP_Read()
{
  i2c::read_to_buf(BMP085_ADDRESS, bmp085_ctx.up.raw, 3);
  i2c::swap_endianness(bmp085_ctx.up.raw, 3);
}

// read uncompensated temperature value: read result bytes
// the datasheet suggests a delay of 4.5 ms after the send command
void i2c_BMP085_UT_Read()
{
  i2c::read_to_buf(BMP085_ADDRESS, bmp085_ctx.ut.raw, 2);
  i2c::swap_endianness(bmp085_ctx.ut.raw, 2);
}

void i2c_BMP085_Calculate()
{
  int32_t x1, x2, x3, b3, b5, b6, p, tmp;
  uint32_t b4, b7;
  // Temperature calculations
  x1 = ((int32_t)bmp085_ctx.ut.val - bmp085_ctx.ac6) * bmp085_ctx.ac5 >> 15;
  x2 = ((int32_t)bmp085_ctx.mc << 11) / (x1 + bmp085_ctx.md);
  b5 = x1 + x2;
  baroTemperature = (b5 * 10 + 8) >> 4; // in 0.01 degC (same as MS561101BA temperature)
  // Pressure calculations
  b6 = b5 - 4000;
  x1 = (bmp085_ctx.b2 * (b6 * b6 >> 12)) >> 11;
  x2 = bmp085_ctx.ac2 * b6 >> 11;
  x3 = x1 + x2;
  tmp = bmp085_ctx.ac1;
  tmp = (tmp * 4 + x3) << OSS;
  b3 = (tmp + 2) / 4;
  x1 = bmp085_ctx.ac3 * b6 >> 13;
  x2 = (bmp085_ctx.b1 * (b6 * b6 >> 12)) >> 16;
  x3 = ((x1 + x2) + 2) >> 2;
  b4 = (bmp085_ctx.ac4 * (uint32_t)(x3 + 32768)) >> 15;
  b7 = ((uint32_t)(bmp085_ctx.up.val >> (8 - OSS)) - b3) * (50000 >> OSS);
  p = b7 < 0x80000000 ? (b7 * 2) / b4 : (b7 / b4) * 2;
  x1 = (p >> 8) * (p >> 8);
  x1 = (x1 * 3038) >> 16;
  x2 = (-7357 * p) >> 16;
  baroPressure = p + ((x1 + x2 + 3791) >> 4);
}

void setup()
{
  delay(10);
  i2c_BMP085_readCalibration();
  delay(5);
  i2c_BMP085_UT_Start();
  bmp085_ctx.deadline = currentTime + 5000;
}

uint8_t update()
{
  currentTime = micros();
  // first UT conversion is started in init procedure
  if (currentTime < bmp085_ctx.deadline)
    return 0;
  bmp085_ctx.deadline = currentTime + 6000; // 1.5ms margin according to the spec (4.5ms T convetion time)
  if (bmp085_ctx.state == 0)
  {
    i2c_BMP085_UT_Read();
    i2c_BMP085_UP_Start();
    bmp085_ctx.state = 1;
    Baro_Common();
    bmp085_ctx.deadline += 21000; // 6000+21000=27000 1.5ms margin according to the spec (25.5ms P convetion time with OSS=3)

    g_set_temperature(baroTemperature);  
    g_set_pressure(baroPressure);

    return 1;
  }
  else
  {
    i2c_BMP085_UP_Read();
    i2c_BMP085_UT_Start();
    i2c_BMP085_Calculate();

    bmp085_ctx.state = 0;
    return 2;
  }
}

} // namespace ModuleBarometer
