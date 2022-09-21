#pragma once
#include <Servo.h>
#include <Arduino.h>
class ClawController {
public:
Servo myServo;

ClawController(int pin);

void ClawGrab();

  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position
  
private:
};
