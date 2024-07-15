int ledPin = 4;
//int potentiometer = A0;
int value;

void setup() {
  // put your setup code here, to run once:
  pinMode(A0, INPUT); 
  pinMode(ledPin,OUTPUT)
  Serial.begin(9600); // Initialize serial communication
}

void loop() {
  // put your main code here, to run repeatedly:
  value = analogRead(A0); 
  digitalWrite(ledPin, HIGH);
  digitalWrite(ledPin, LOW);
  //Serial.println(value);

}
