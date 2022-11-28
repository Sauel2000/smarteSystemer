
#include "ClawController.h"
ClawController::ClawController()
{
    myServo.attach(servoPinOutput);
        /*Description : Pinoutput for servo, minValue, on pulse per microsec, maxValue, on pulse per microsec)
        * Parameters : Para1 required,Para2 optional, Para3 optional.
        */
}

void ClawController::OpenClaw() {
    myServo.write(maxAngle); //Max angle for the claw so that it does not get stressed and broken.
        /*Description : Pinoutput for servo, minValue, on pulse per microsec, maxValue, on pulse per microsec)
        * Parameters : Para1 required,Para2 optional, Para3 optional.
        * If write is less than 0 then it is seen as 0.
        * If write is greater than 180 then it seen as microseconds for controlling duty cycle.
        */
    delay(delayTime); //Some delay to let servo reach its position.
}

void ClawController::CloseClaw() {
    myServo.write(100); //Input value has to be adjusted for which items to pick
    delay(delayTime); //Some delay to let servo reach its position.
}
