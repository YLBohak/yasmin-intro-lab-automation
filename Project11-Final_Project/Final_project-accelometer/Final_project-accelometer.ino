
//This is the package for the Accelerometer (I installed)
#include "LIS3DHTR.h"
//Needs this package (already installed?)
#include <Wire.h>
//Define the variable LIS as type LIS3DHTR<TwoWire>
LIS3DHTR<TwoWire> LIS; //IIC
//Changed name Wire to WIRE
#define WIRE Wire
float yAcc;
int val;
float valMap;


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
  //calculate the angle from the y-axis output of the accelerometer (-1 to 1)
  //I chose to use the y-axis = board hold in front of your face and move left right (displaces the servo the least)
  yAcc = LIS.getAccelerationY();
  Serial.print("y:"); Serial.print(LIS.getAccelerationY()); Serial.print("  ");
  //converts value from gravitational acceleration into angles between 0 and 150
  valMap = (yAcc+1)*1000;
  val = map(valMap, 0, 2000, 0, 150);
  Serial.print("angle:"); Serial.print(valMap); Serial.print(" "); Serial.println(val);
  delay(1000);
}
