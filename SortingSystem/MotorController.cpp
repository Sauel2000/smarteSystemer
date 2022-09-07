#include "MotorController.h"

/**
 * @param pin1 
 * @param pin2
 */
MotorController::MotorController(int pin1, int pin2): stepper(stepsPerRevolution, pin1, pin2) {
  stepper.setSpeed(200);    
}
void MotorController::step(int steps) {
    stepper.step(steps);
}
const int MotorController::getstepsPerRevolution(){
      return stepsPerRevolution;
}
const int MotorController::getstepInCoords(){
      return stepsInCoords;
}
