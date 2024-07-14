/*
  Project4


  modified 14 July 2024
  by Yasmin Bohak

  
*/
int led_pin_1 = 12;
int led_pin_2 = 13;
int x_i; 


void setup() {
  // put your setup code here, to run once:
pinMode(led_pin_1, OUTPUT);
pinMode(led_pin_2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  digitalWrite(led_pin_1, HIGH);
  x_i = x_i + 1;
  digitalWrite(led_pin_2, HIGH);
  digitalWrite(led_pin_1, LOW);
  digitalWrite(led_pin_2, LOW);

}
