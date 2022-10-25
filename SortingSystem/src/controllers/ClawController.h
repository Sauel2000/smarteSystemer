#pragma once
#include <Servo.h> //Included to run functions that are properly setup with the motors properties.
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
};
