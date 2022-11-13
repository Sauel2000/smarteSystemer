#include "MotorController.h"


MotorController::MotorController(int pin1, int pin2): stepper(stepsPerRevolution, pin1, pin2) { 
      this->stepper.setSpeed(200);    
}

void MotorController::step(int steps) {
      this->stepper.step(steps);
}

const int MotorController::getstepsPerRevolution(){
      return this->stepsPerRevolution;
}
const int MotorController::getstepsPerRevolutionY(){
      return this->stepsPerRevolutionY;
}

const int MotorController::getstepInCoords(){ 
      return this->stepsInCoords;
}
