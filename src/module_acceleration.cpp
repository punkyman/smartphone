#include "module_acceleration.h"
#include "i2c_communication.h"

#define ACC_1G 265
#define ACCZ_25deg   (int16_t)(ACC_1G * 0.90631) // 0.90631 = cos(25deg) (cos(theta) of accZ comparison)
#define ACC_VelScale (9.80665f / 10000.0f / ACC_1G)
#define ACC_ORIENTATION(X, Y, Z)  {accADC[ROLL]  = X; accADC[PITCH]  = Y; accADC[YAW]  = Z;}

enum rc {
  ROLL,
  PITCH,
  YAW
};

namespace ModuleAcceleration
{
  int16_t accZero[3] = {0, 0, 0};
  int16_t  accADC[3];
  uint16_t calibratingA = 512;  // the calibration is done in the main loop. Calibrating decreases at each cycle down to 0, then we enter in a normal mode.

// ****************
// ACC common part
// ****************
void ACC_Common() {
  static int32_t a[3];
  if (calibratingA>0) {
    calibratingA--;
    for (uint8_t axis = 0; axis < 3; axis++) {
      if (calibratingA == 511) a[axis]=0;   // Reset a[axis] at start of calibration
      a[axis] += accADC[axis];           // Sum up 512 readings
      accZero[axis] = a[axis]>>9; // Calculate average, only the last itteration where (calibratingA == 0) is relevant
    }
    if (calibratingA == 0) {
      accZero[YAW] -= ACC_1G;   // shift Z down by ACC_1G and store values in EEPROM at end of calibration
      //conf.angleTrim[ROLL]   = 0;
      //conf.angleTrim[PITCH]  = 0;
      //writeGlobalSet(1); // write accZero in EEPROM
    }
  }

  accADC[ROLL]  -=  accZero[ROLL] ;
  accADC[PITCH] -=  accZero[PITCH];
  accADC[YAW]   -=  accZero[YAW] ;

  #if defined(SENSORS_TILT_45DEG_LEFT)
    int16_t temp = ((accADC[PITCH] - accADC[ROLL] )*7)/10;
    accADC[ROLL] = ((accADC[ROLL]  + accADC[PITCH])*7)/10;
    accADC[PITCH] = temp;
  #endif
  #if defined(SENSORS_TILT_45DEG_RIGHT)
    int16_t temp = ((accADC[PITCH] + accADC[ROLL] )*7)/10;
    accADC[ROLL] = ((accADC[ROLL]  - accADC[PITCH])*7)/10;
    accADC[PITCH] = temp;
  #endif
}

// I2C adress: 0x3A (8bit)    0x1D (7bit)
// Resolution: 10bit (Full range - 14bit, but this is autoscaling 10bit ADC to the range +- 16g)
// principle:
//  1) CS PIN must be linked to VCC to select the I2C mode
//  2) SD0 PIN must be linked to VCC to select the right I2C adress
//  3) bit  b00000100 must be set on register 0x2D to read data (only once at the initialization)
//  4) bits b00001011 must be set on register 0x31 to select the data format (only once at the initialization)

void setup () {
  delay(10);
  i2c::writeReg(ADXL345_ADDRESS,0x2D,1<<3); //  register: Power CTRL  -- value: Set measure bit 3 on
  i2c::writeReg(ADXL345_ADDRESS,0x31,0x0B); //  register: DATA_FORMAT -- value: Set bits 3(full range) and 1 0 on (+/- 16g-range)
  i2c::writeReg(ADXL345_ADDRESS,0x2C,0x09); //  register: BW_RATE     -- value: rate=50hz, bw=20hz
}

void upate () {
  i2c::getSixRawADC(ADXL345_ADDRESS,0x32);

  ACC_ORIENTATION( ((i2c::rawADC[1]<<8) | i2c::rawADC[0]) ,
                   ((i2c::rawADC[3]<<8) | i2c::rawADC[2]) ,
                   ((i2c::rawADC[5]<<8) | i2c::rawADC[4]) );
  ACC_Common();
}

} // namespace ModuleAcceleration


