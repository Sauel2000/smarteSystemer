#pragma once

#include <Stepper.h>

class MotorController {
public:
    const static int stepsPerRevolution = 1600;
    const static int stepsInCoords = 10;

    Stepper stepper;

    MotorController(int pin1, int pin2);

    void step(int steps);
};
