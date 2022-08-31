#include <Stepper.h>
 
int dirPin = 2;
int stepPin = 5;
//int enPin = 8;

//int stepsPerRevolution = 1600;

void setup() {
  // put your setup code here, to run once:
  pinMode(dirPin, OUTPUT);
  pinMode(stepPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(dirPin, LOW); 
  for(int x = 0; x < 400; x++) {
    digitalWrite(stepPin,HIGH); 
    delay(2); 
    digitalWrite(stepPin,LOW); 
    delay(2); 
  }
  
  digitalWrite(dirPin, HIGH); 
  for(int x = 0; x < 400; x++) {
    digitalWrite(stepPin,HIGH); 
    delay(2); 
    digitalWrite(stepPin,LOW); 
    delay(2); 
  }
}
