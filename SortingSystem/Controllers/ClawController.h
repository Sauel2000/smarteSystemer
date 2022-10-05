#pragma once
#include <Servo.h> //Included to run functions that are properly setup with the motors properties.
#include <Arduino.h> //Included to run arudino functions and variables.(Delay,Serialprint,etc)
class ClawController {
public:

ClawController();
void ClawGrab();
void ClawUngrab();

private:
    Servo myServo;  //Creating an servo object to controll.
    const int servoPinOutput = 22;   //Creating variable for ouptput pin from arduino to motor.
};
