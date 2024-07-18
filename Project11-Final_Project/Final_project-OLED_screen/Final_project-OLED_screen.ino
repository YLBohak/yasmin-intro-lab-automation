//This script is based on: https://sensorkit.arduino.cc/sensorkit/module/lessons/lesson/10-the-oled-screen



//Installed this package
#include "Arduino_SensorKit.h"



void setup() {
  Oled.begin();
  // Sets the rotation of the screen
  Oled.setFlipMode(true); 

}

void loop() {
  int random_value = analogRead(A0);
  Oled.setFont(u8x8_font_chroma48medium8_r); 
  Oled.setCursor(0, 33);    // Set the Coordinates 
  Oled.print("The angle is:");   
  Oled.print(random_value); 
  Oled.refreshDisplay();    // Update the Display 
  delay(1000);
}
