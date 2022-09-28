#include <Servo.h>
Servo testServo;  
int pos = 0;
int sensorValue;
void setup() {
  testServo.attach(A0);  //Using attach method to attach servo to arduino pin
  Serial.begin(9600);

}

void loop() {
  for (pos = 0; pos <= 180; pos += 1) {// Making loop for the servo to go 15 degrees
    // in steps of 1 degree
    testServo.write(pos);              // Using write method to move the servo to position
    delay(15);
    sensorValue = analogRead(A1);
    float voltage = sensorValue * (5.0 / 1023.0);
    Serial.println(voltage);
  }


  // print out the value you read:

  /*
  for (pos = 180; pos >= 0; pos -= 1) { // Loop to return from 15 to 0 degrees.
    testServo.write(pos);                // Use write method to move servo back to 0 degrees.
    delay(15);                         // Delay to let servo reach its' destination.
  }
  */

}
