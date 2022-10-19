#include "MotorController.h"

/**
 * @param pin1 
 * @param pin2
 */
MotorController::MotorController(int pin1, int pin2): stepper(stepsPerRevolution, pin1, pin2) { //sets the speed of the motor with the use of stepper libary
      this->stepper.setSpeed(200);    
}

void MotorController::step(int steps) { //sets how many steps the motor should take with step function from stepper libary
      this->stepper.step(steps);
}

const int MotorController::getstepsPerRevolution(){ //returns the number of steps per revolution
      return this->stepsPerRevolution;
}

const int MotorController::getstepInCoords(){ //returns the number of steps in one coordinate
      return this->stepsInCoords;
}
