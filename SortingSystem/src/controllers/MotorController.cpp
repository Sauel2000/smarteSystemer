#include "MotorController.h"


MotorController::MotorController(int pin1, int pin2, int speed): 
      stepper(stepsPerRevolution, pin1, pin2) { 
      this->stepper.setSpeed(speed); //Speed and steps does impact each other
      /*
      The longer the distance the more speed is applied and could overrun if speed and distance are high
      
      */

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
const int MotorController::getstepsPerRevolutionZ(){
      return this->stepsPerRevolutionZ;
}

const int MotorController::getstepInCoords(){ 
      return this->stepsInCoords;
}
