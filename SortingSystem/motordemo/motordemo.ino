int dirPin = 2;
int stepPin = 3;
//int enPin = 8;
int dirPinDriver2 = 4;
int stepPinDriver2 = 5;
int dirPinDriver3 = 8;
int stepPinDriver3 = 9;
//int stepsPerRevolution = 1600;

void setup() {
  // put your setup code here, to run once:
  pinMode(dirPin, OUTPUT);
  pinMode(stepPin, OUTPUT);
  pinMode(dirPinDriver2, OUTPUT);
  pinMode(stepPinDriver2, OUTPUT);
  pinMode(dirPinDriver3, OUTPUT);
  pinMode(stepPinDriver3, OUTPUT);
}

void loop() {
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
  digitalWrite(dirPinDriver2, LOW); 
  for(int x = 0; x < 400; x++) {
    digitalWrite(stepPinDriver2,HIGH); 
    delay(2); 
    digitalWrite(stepPinDriver2,LOW); 
    delay(2); 
  }
  
  digitalWrite(dirPinDriver2, HIGH); 
  for(int x = 0; x < 400; x++) {
    digitalWrite(stepPinDriver2,HIGH); 
    delay(2); 
    digitalWrite(stepPinDriver2,LOW); 
    delay(2); 
  }
  digitalWrite(dirPinDriver3, LOW); 
  for(int x = 0; x < 400; x++) {
    digitalWrite(stepPinDriver3,HIGH); 
    delay(2); 
    digitalWrite(stepPinDriver3,LOW); 
    delay(2); 
  }
  
  digitalWrite(dirPinDriver3, HIGH); 
  for(int x = 0; x < 400; x++) {
    digitalWrite(stepPinDriver3,HIGH); 
    delay(2); 
    digitalWrite(stepPinDriver3,LOW); 
    delay(2); 
  }
 
}
