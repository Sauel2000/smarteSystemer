#pragma once

#include <Stepper.h>

class MotorController {
public:
    Stepper stepper;
    MotorController(int pin1, int pin2); //Constructor for Motorcontroller 
    const int getstepsPerRevolution();
    const int getstepInCoords();
    void step(int steps); // Interface method for stepper library
    private:
    const static int stepsPerRevolution = 1600; // Number of steps per revolution
    const static int stepsInCoords = 10; // Number of steps in one coordinate
};