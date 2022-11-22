
#include "ClawController.h"
ClawController::ClawController()
{
    myServo.attach(servoPinOutput); 
}

void ClawController::OpenClaw() {
    myServo.write(maxAngle);
    delay(delayTime);
}

void ClawController::CloseClaw() {
    myServo.write(100);
    delay(delayTime);
}
