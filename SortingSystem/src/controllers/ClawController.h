#pragma once
#include <Servo.h> //Included to run functions that are properly setup with the motors properties.
#include <Arduino.h> //Included to run arudino functions and variables.(Delay,Serialprint,etc)
class ClawController {
public:

ClawController();
/*

*/
void OpenClaw(); //Function to grab the item
void CloseClaw(); //Function to ungrab the item

private:
    Servo myServo;  //Creating an servo object to controll.
    const int servoPinOutput = 22;   //Creating variable for ouptput pin from arduino to motor.
};
