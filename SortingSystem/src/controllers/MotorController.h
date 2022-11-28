#pragma once
#include <Stepper.h> 
/*
The library Stepper.h does fit with our systems requirement, but is not implemented that good since
amount of steps and speed does affect each other in some cases. Therefore start with low values
before increasing to find sweet spot for your system. Methods to be careful with setspeed(),step().
*/

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
    * -Usually the stepper motor requres 4 cables but can be reduced to two because of bipolarity.
    */

    MotorController(int pin1, int pin2, int speed);
    /*
    * @desc This method is used to get the number of steps per revolution in the x axis.
    * @return stepsPerRevolution
    */
    const int getstepsPerRevolution();

    /**
     * @brief This method is used to get the number of steps per revolution in the y axis.
     * 
     * @return const int 
     */
    const int getstepsPerRevolutionY();

    /**
     * @brief This method is used to get the number of steps per revolution in the z axis.
     * 
     * @return const int 
     */
    const int getstepsPerRevolutionZ();

    
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
    const static int stepsPerRevolution = 940; // Number of steps per revolution
    const static int stepsPerRevolutionY = 4500; // Number of steps per revolution in the y axis
    const static int stepsPerRevolutionZ = 940; // Number of steps per revolution in the z axis
    const static int stepsInCoords = 1; // Number of steps in one coordinate
};
