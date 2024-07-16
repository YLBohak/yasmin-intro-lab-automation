/*
  Project6


  modified 15 July 2024
  by Yasmin Bohak

  Interupt led on but off only 5 seconds after turned off
  use millis()
*/
int ledPin = 4;
int buttonPin = 2;  //6;
int buttonState = LOW;
long current_time = 0;
long t = 5000;



void setup() {
  pinMode(ledPin, OUTPUT);    // Initialize the LED pin as an output
  pinMode(buttonPin, INPUT);  // Initialize the button pin with internal pull-up
  Serial.begin(9600);         // Initialize serial communication

  // Attach interrupt to buttonPin, call the function on RISING edge
  attachInterrupt(digitalPinToInterrupt(buttonPin), buttonFun, RISING);
  //Set up the timmer so that it will activate ledOff when 5 seconds elapsed
}

void loop() {
  //add some delay
  if (millis() - current_time >= t)
  {
    digitalWrite(ledPin, LOW);
    Serial.println("led was turned off");
  }
}


// Interrupt service routine (ISR)
void buttonFun() {
  digitalWrite(ledPin, HIGH);
  current_time = millis();
  Serial.println("led was turned on");
}
