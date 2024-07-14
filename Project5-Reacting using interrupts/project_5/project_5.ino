/*
  Project5


  modified 14 July 2024
  by Yasmin Bohak

  
*/
int ledPin = 4;
int buttonPin = 2;//6;
int buttonState = LOW; 

void setup() {
  pinMode(ledPin, OUTPUT);          // Initialize the LED pin as an output
  pinMode(buttonPin, INPUT); // Initialize the button pin with internal pull-up
  Serial.begin(9600); // Initialize serial communication

  // Attach interrupt to buttonPin, call the function on RISING edge
  attachInterrupt(digitalPinToInterrupt(buttonPin), buttonFun, CHANGE);
}

void loop() {
  // Use this section of code when dont use interrupt:
  //buttonState = digitalRead(buttonPin); // for 1st part of question Read the state of the button

  
  //if (buttonState == LOW) { // Button pressed (active LOW)
  //  Serial.println("some message");
  delay(1000);
  //  Serial.println("some message");
  //  digitalWrite(ledPin, LOW); // Turn LED on
  //} else {
  //  digitalWrite(ledPin, HIGH);  // Turn LED off
  //}
}


// Interrupt service routine (ISR)
void buttonFun() {
  buttonState = digitalRead(buttonPin); // Read the button state
  if (buttonState == LOW) { // Button pressed (active LOW)
   Serial.println("led is off");
   digitalWrite(ledPin, LOW); // Turn LED on
  } else {
   digitalWrite(ledPin, HIGH); 
   Serial.println("led is on");
  }
  }