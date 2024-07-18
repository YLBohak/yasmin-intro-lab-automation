
//This is the package for the Accelerometer (I installed)
#include "LIS3DHTR.h"
//Needs this package (already installed?)
#include <Wire.h>
//Define the variable LIS as type LIS3DHTR<TwoWire>
LIS3DHTR<TwoWire> LIS; //IIC
//Changed name Wire to WIRE
#define WIRE Wire


void setup() {
  //set up connection:
  Serial.begin(115200);
  LIS.begin(WIRE,0x19); //IIC init
  //I don't think that we want temperature control so I tried to shut it off
  LIS.closeTemp();
  //setFullScaleRange sets the full range of the accelometer --> defines how much acceleration the sensor cna measure
  //LIS3DHTR_RANGE_2G means +-2 gravitational acceleration
  LIS.setFullScaleRange(LIS3DHTR_RANGE_2G); 
  //provide output measurements at this rate
  LIS.setOutputDataRate(LIS3DHTR_DATARATE_50HZ); 
}

void loop() {
  if (!LIS)
  {
    Serial.println("LIS3DHTR didn't connect.");
  }
  Serial.print("x:"); Serial.print(LIS.getAccelerationX()); Serial.print("  ");
  Serial.print("y:"); Serial.print(LIS.getAccelerationY()); Serial.print("  ");
  Serial.print("z:"); Serial.println(LIS.getAccelerationZ());
  delay(500);
}
