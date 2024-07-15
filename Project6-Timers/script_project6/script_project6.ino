/*
  Project6


  modified 15 July 2024
  by Yasmin Bohak

  Interupt led on but off only 5 seconds after turned off
*/
int ledPin = 4;
int buttonPin = 2;//6;
int buttonState = LOW; 

//Libraries
#include <MsTimer2.h>


void setup() {
  pinMode(ledPin, OUTPUT);          // Initialize the LED pin as an output
  pinMode(buttonPin, INPUT); // Initialize the button pin with internal pull-up
  Serial.begin(9600); // Initialize serial communication

  // Attach interrupt to buttonPin, call the function on RISING edge
  attachInterrupt(digitalPinToInterrupt(buttonPin), buttonFun, RISING);
  //Set up the timmer so that it will activate ledOff when 5 seconds elapsed
  MsTimer2::set(5000, ledOff); // Set timer to 5000 ms (5 seconds)

}

void loop() {
  //add some delay
  delay(1000);
}


// Interrupt service routine (ISR)
void buttonFun() {
   digitalWrite(ledPin, HIGH); 
   MsTimer2::start();
   Serial.println("led was turned on");
}

void ledOff() {
   digitalWrite(ledPin, LOW); 
   Serial.println("led was turned off");
}
  
  