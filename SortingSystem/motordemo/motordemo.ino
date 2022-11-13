#include <Stepper.h>

const int stepsPerRevolution = 1300;
 int stepsPerRevolution2 = 7680;
  // change this to fit the number of steps per revolution
// for your motor

// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 2, 3 );
Stepper myStepper2(stepsPerRevolution2, 4, 5 );

void setup() {
  // set the speed at 60 rpm:
  myStepper.setSpeed(50);
  myStepper2.setSpeed(50);
  // initialize the serial port:
  Serial.begin(9600);
    // step one revolution in the other direction:
}

void loop() {
  Serial.println("clockwise");
  myStepper.step(stepsPerRevolution);
  
  

  // step one revolution in the other direction:
  Serial.println("counterclockwise");
  myStepper.step(-stepsPerRevolution);


  Serial.println("clockwise");
  myStepper2.step(stepsPerRevolution2);


  // step one revolution in the other direction:
  Serial.println("counterclockwise");
  myStepper2.step(-stepsPerRevolution2);
}
