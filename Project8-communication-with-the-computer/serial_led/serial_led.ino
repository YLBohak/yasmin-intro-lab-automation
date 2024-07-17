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
long t = 0;
long value = -1;
String value_read = "-1";
bool wrong_input = false;


//Libraries
#include <MsTimer2.h>


void setup() {
  pinMode(ledPin, OUTPUT);          // Initialize the LED pin as an output
  pinMode(buttonPin, INPUT); // Initialize the button pin with internal pull-up
  Serial.begin(115200); // Initialize serial communication

  // Attach interrupt to buttonPin, call the function on RISING edge
  attachInterrupt(digitalPinToInterrupt(buttonPin), buttonFun, CHANGE);
  }

void loop() {
  //add some delay
  delay(1000);
  // Continously check for input from serial monitor, but only read when an input was giver
  if (Serial.available() > 0) {
    // Break the loop if we encounter a non-digit character
    value_read = Serial.readStringUntil('\n');
    //If the input is not a digit, print error message and exist the loop
    value = value_read.toInt();
    for (int i = 0; i < value_read.length(); i++) {
      //if (!isDigit(value_read[i])) {
        // If input is not a digit print eror
        //wrong_input = true;
      //}
    //}
    //if (wrong_input == true) {
      //Serial.println("Only numbers (in ms) can be given as input, please try again.");
      //wrong_input = false;
    //}
    //else {
    //Serial.println("I received: ");
      //Serial.println(value);
      //Set up the timer is set up using input from serial monitor
      MsTimer2::set(value, turn_off); // Set timer to value ms 
    }
  }
}


// Interrupt service routine (ISR)
void buttonFun() {
   buttonState = digitalRead(buttonPin);
   if (buttonState == HIGH) { 
      digitalWrite(ledPin, HIGH); 
      MsTimer2::start();
      Serial.println("1"); //send back to python
   }
   else {
    Serial.println("2"); //send back to python- button state is off
   }
}

void turn_off() {
   digitalWrite(ledPin, LOW); 
   Serial.println("0"); //send back to python
   MsTimer2::stop();
}
  
  