#pragma once
#include <Stepper.h> //Stepper library built inn from arduino to run functions that are properly setup with the motors properties.

class MotorController {
public:
    /*
    * @desc making a stepper object to control the motor.
    */
    Stepper stepper;

    /*
    * @desc This method is used to attach the stepper to the pins.
    * this metod also sets the speed of the motor.
    * @param
    * - pin1: The first pin that the stepper is attached to.
    * - pin2: The second pin that the stepper is attached to.
    */
    MotorController(int pin1, int pin2);
    /*
    * @desc This method is used to get the number of steps per revolution.
    * @return stepsPerRevolution
    */
    const int getstepsPerRevolution();
    const int getstepsPerRevolutionY();

    
    /*
    * @desc This method is used to get the number of steps in one coordinate.
    * @return stepsInCoords
    */
    const int getstepInCoords();
    
    /*
    * @desc This method is used to make the motor take steps.
    * @return void
    */
    void step(int steps);
    
    private:
    const static int stepsPerRevolution = 1300; // Number of steps per revolution
    const static int stepsPerRevolutionY = 7680;
    const static int stepsInCoords = 1; // Number of steps in one coordinate
};
