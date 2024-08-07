/*
  Project8

  This script is based on project 6 

  modified 15 July 2024
  by Yasmin Bohak
  modified 16 July 2024 (project 8)
  by Yasmin Bohak

  Interupt led on but off only x seconds after turned off using MsTimer2
  x is input read from the serial monitor

*/
int ledPin = 4;
//Short pin 6 --> 2 on the arduino board
int buttonPin = 2;//6;
int buttonState = LOW; 
//long t = 30;

//Libraries
#include <MsTimer2.h>


void setup() {
  pinMode(ledPin, OUTPUT);          // Initialize the LED pin as an output
  pinMode(buttonPin, INPUT); // Initialize the button pin with internal pull-up
  Serial.begin(9600); // Initialize serial communication

  // Attach interrupt to buttonPin, call the function on RISING edge
  attachInterrupt(digitalPinToInterrupt(buttonPin), buttonFun, RISING);
  //Set up the timmer so that it will activate ledOff when 5 seconds elapsed
  MsTimer2::set(t, ledOff); // Set timer to 5000 ms (5 seconds)
  
}

void loop() {
  //add some delay
  delay(1000);
  // Continously read input from serial monitor
  
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
   MsTimer2::stop();
}
  
  