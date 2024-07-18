
//This is the package for the Accelerometer (I installed)
#include "LIS3DHTR.h"
//Needs this package (already installed?)
#include <Wire.h>
//import servo package
#include <Servo.h>
//import package used for OLED screen
#include <U8x8lib.h>
//Define the variable LIS as type LIS3DHTR<TwoWire>
LIS3DHTR<TwoWire> LIS; //IIC
//Changed name Wire to WIRE
#define WIRE Wire
//oled
U8X8_SSD1306_128X64_NONAME_HW_I2C Oled(/* reset=*/ U8X8_PIN_NONE);
float yAcc;
int val;
float valMap;
// create Servo object to control a servo
Servo myservo;  


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
  //attaches the servo on pin 7 to the Servo object
  myservo.attach(7);
  //Initiate the OLED screen
  Oled.begin();
  // Sets the rotation of the screen
  Oled.setFlipMode(1);  
  
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
  //the y value is converted into a range between 0 and 2000, this will enable me to work with map
  valMap = (yAcc+1)*1000;
  //converts value from gravitational acceleration into angles between 0 and 150
  val = map(valMap, 0, 2000, 0, 150);
  Serial.print("angle:"); Serial.print(valMap); Serial.print(" "); Serial.println(val);
  //write the value val (angle) to the servo
  myservo.write(val);  
  //set up the OLED screen
  Oled.setFont(u8x8_font_chroma48medium8_r); 
  Oled.setCursor(0, 0);    // Set the Coordinates 
  //print the angle to the screen
  Oled.print("Servo angle:");   
  Oled.println(val); // Print the Values  
  Oled.refreshDisplay();    // Update the Display 
  //otherwise prints too fast to screen
  delay(20);

}
