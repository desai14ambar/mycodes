////////////////////////////////////////////////////////////
// Arduino firmware for use with FreeSixCube processing example
////////////////////////////////////////////////////////////

// The libraries included below have been adapted to work on Arduino DUE by PedalSensor team 

#include <FreeSixIMU_DUE.h>
#include <FIMU_ADXL345_DUE.h>
#include <FIMU_ITG3200_DUE.h>
//#include "kalman_acc.h"
#include "getBodyAcc.h"

#define DEBUG
#ifdef DEBUG
#include "DebugUtils.h"
#endif

//#include "CommunicationUtils.h"
#include <Wire.h>
//#include <math.h>

float accel[4];
float bacc[3];

float euangles[3];
float fcalib; //calibration factor

// Set the FreeIMU object
FreeSixIMU_DUE my3IMU = FreeSixIMU_DUE();

void setup() {
  Serial.begin(115200);
  Wire.begin();

  delay(5);
  my3IMU.init();
  delay(5);
  
  fcalib = my3IMU.calibAcc();
  
}

void loop() { 

//read acceleration values
    my3IMU.getValues(accel);
    my3IMU.getAngles(euangles);
    //my3IMU.getBodyAcc(bacc);
    
  Serial.print("\t Ax:");     Serial.print(accel[0]);
  Serial.print("\t Ay:");     Serial.print(accel[1]);
  Serial.print("\t Az:");     Serial.print(accel[2]);
  Serial.print("\t g:");      Serial.print(accel[2]/fcalib);
  
  getBodyAcc accltn(accel[0],accel[1],accel[2],euangles[0], euangles[1], euangles[2], fcalib);
  accltn.readAcc(&bacc[0]);
  
  Serial.print("\t Body Ax:");     Serial.print(bacc[0]);
  Serial.print("\t Body Ay:");     Serial.print(bacc[1]);
  Serial.print("\t Body Az:");     Serial.print(bacc[2]);
  Serial.println(""); //line break
  delay(100);
    
}


