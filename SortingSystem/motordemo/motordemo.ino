#include <Stepper.h>

const int stepsPerRevolution = 1200;
 int stepsPerRevolution2 = 1200;
  // change this to fit the number of steps per revolution
// for your motor

// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 2, 3 );
Stepper myStepper2(stepsPerRevolution2, 4, 5 );

void setup() {
  // set the speed at 60 rpm:
  myStepper.setSpeed(40);
  myStepper2.setSpeed(100);
  // initialize the serial port:
  Serial.begin(9600);
    // step one revolution in the other direction:
}

void loop() {
  Serial.println("clockwise");
  myStepper.step(stepsPerRevolution);
  
  delay(500);

  // step one revolution in the other direction:
  Serial.println("counterclockwise");
  myStepper.step(-stepsPerRevolution);
  delay(500);

  Serial.println("clockwise");
  myStepper2.step(stepsPerRevolution2);
  delay(500);

  // step one revolution in the other direction:
  Serial.println("counterclockwise");
  myStepper2.step(-stepsPerRevolution2);
  delay(500);
}
