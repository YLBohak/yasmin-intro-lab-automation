//Project 7 - Yasmin L Bohak
//PWM - dimming a led

#include <MD_PWM.h>

//int ledPin = 4;
int ledPin = 4;
//int potentiometer = A0; //un-neccesary because default
float value;
int freq = 50;
//Initialize PWM
MD_PWM pwm = MD_PWM(ledPin);
float counter = 0;


void setup() {
  // put your setup code here, to run once:
  pinMode(A0, INPUT); 
  pinMode(ledPin,OUTPUT);
  Serial.begin(9600); // Initialize serial communication
  pwm.begin(freq);
}

void loop() {
  // put your main code here, to run repeatedly:
  value = analogRead(A0); 
  //digitalWrite(ledPin, HIGH);
  //digitalWrite(ledPin, LOW);
  counter = (value / 1023) * 225;
  pwm.write(counter);	

  //Serial.println(value);
  //Serial.println(counter);

}
