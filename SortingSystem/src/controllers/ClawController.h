#pragma once
#include <Servo.h> //Included library to handle servo motor with pulse modulation.
#include <Arduino.h> //Included to run arudino functions and variables.(Delay,Serialprint,etc)
class ClawController {
public:
/*
* @desc This method is used to attach the servo to the pin.
* @param
* - servoPinOutput: The pin that the servo is attached to.
*@return void
*/
ClawController();
/*
* @desc This function is used to open the claw by controlling the servo motor.
* @return void
*/
void OpenClaw();
/*
* @desc This function is used to close the claw by controlling the servo motor.
* @return void
*/
void CloseClaw();

private:
    Servo myServo;  //Creating an servo object to controll.
    const int servoPinOutput = 22;   //Creating variable for ouptput pin from arduino to motor.
    const int maxAngle = 180; //Creating variable for max angle of the servo.
    const int delayTime = 5; //Creating variable for delay time.
};
