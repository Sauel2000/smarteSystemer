#include "MotorController.h"

MotorController::MotorController(int pin1, int pin2): stepper(stepsPerRevolution, pin1, pin2) {
  stepper.setSpeed(200);    
}

void MotorController::step(int steps) {
    stepper.step(steps);
}
