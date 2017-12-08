#include "module_gyroscope.h"
#include "i2c_communication.h"

enum rc {
  ROLL,
  PITCH,
  YAW
};

// GYRO SCALE: we ignore the last 2 bits and convert it for rad/s
#define GYRO_SCALE ((4.0f * PI * 70.0f)/(1000.0f * 180.0f * 1000000.0f)) // 70 milli deg/s /digit => 1 deg/s = 1000/70 LSB
#define GYRO_DLPF_CFG   0 //Default settings LPF 256Hz/8000Hz sample
#define GYRO_ORIENTATION(X, Y, Z) {gyroADC[ROLL] = X; gyroADC[PITCH] = Y; gyroADC[YAW] = Z;}

namespace ModuleGyroscope
{
  int16_t gyroADC[3] = {0,0,0};
  int16_t gyroZero[3] = {0,0,0};
  uint16_t calibratingG = 512;

  void setup()
  {
    delay(100);
    i2c::writeReg(L3G4200D_ADDRESS ,0x20 ,0x8F ); // CTRL_REG1   400Hz ODR, 20hz filter, run!
    delay(5);
    i2c::writeReg(L3G4200D_ADDRESS ,0x24 ,0x02 ); // CTRL_REG5   low pass filter enable
    delay(5);
    i2c::writeReg(L3G4200D_ADDRESS ,0x23 ,0x30); // CTRL_REG4 Select 2000dps
  }

  void GYRO_Common() {
  static int16_t previousGyroADC[3] = {0,0,0};
  static int32_t g[3];
  uint8_t axis, tilt=0;

  if (calibratingG>0) {
    for (axis = 0; axis < 3; axis++) {
      if (calibratingG == 512) { // Reset g[axis] at start of calibration
        g[axis]=0;
    /* #if defined(GYROCALIBRATIONFAILSAFE)
        previousGyroADC[axis] = gyroADC[axis];
      }
      if (calibratingG % 10 == 0) {
        if(abs(gyroADC[axis] - previousGyroADC[axis]) > 8) tilt=1;
        previousGyroADC[axis] = gyroADC[axis];
    #endif */
      }
      g[axis] += gyroADC[axis]; // Sum up 512 readings
      gyroZero[axis]=g[axis]>>9;
      /*if (calibratingG == 1) {
        SET_ALARM_BUZZER(ALRM_FAC_CONFIRM, ALRM_LVL_CONFIRM_ELSE);
      }*/
    }
    /* #if defined(GYROCALIBRATIONFAILSAFE)
      if(tilt) {
        calibratingG=1000;
        LEDPIN_ON;
      } else {
        calibratingG--;
        LEDPIN_OFF;
      }
      return;
    #else */
      calibratingG--;
    //#endif
  }

  for (axis = 0; axis < 3; axis++) {
    gyroADC[axis]  -= gyroZero[axis];
    //anti gyro glitch, limit the variation between two consecutive readings
    gyroADC[axis] = constrain(gyroADC[axis],previousGyroADC[axis]-800,previousGyroADC[axis]+800);
    previousGyroADC[axis] = gyroADC[axis];
  }

  #if defined(SENSORS_TILT_45DEG_LEFT)
    int16_t temp  = ((imu.gyroADC[PITCH] - imu.gyroADC[ROLL] )*7)/10;
    imu.gyroADC[ROLL] = ((imu.gyroADC[ROLL]  + imu.gyroADC[PITCH])*7)/10;
    imu.gyroADC[PITCH]= temp;
  #endif
  #if defined(SENSORS_TILT_45DEG_RIGHT)
    int16_t temp  = ((imu.gyroADC[PITCH] + imu.gyroADC[ROLL] )*7)/10;
    imu.gyroADC[ROLL] = ((imu.gyroADC[ROLL]  - imu.gyroADC[PITCH])*7)/10;
    imu.gyroADC[PITCH]= temp;
  #endif
}

void update() {
  i2c::getSixRawADC(L3G4200D_ADDRESS,0x80|0x28);

  GYRO_ORIENTATION( ((i2c::rawADC[1]<<8) | i2c::rawADC[0])>>2  ,
                    ((i2c::rawADC[3]<<8) | i2c::rawADC[2])>>2  ,
                    ((i2c::rawADC[5]<<8) | i2c::rawADC[4])>>2  );
  GYRO_Common();
}

}

