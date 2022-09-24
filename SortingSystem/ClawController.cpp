
#include "ClawController.h"
ClawController::ClawController()
{
    myServo.attach(servoPinOutput); //Attaching pin to controll output voltage.
}
void ClawController::ClawGrab(){
    while(true){                        //Run the grab and reverse for ever for testing.
    for (int pos = 0; pos <= 180; pos += 1) { //Using loop to controll angle parameter.
    myServo.write(pos);                 //Use write function to set angle for the motor.
    delay(10);                          //Delay to controll rotation velocity.
    }
    for (int pos = 180; pos >= 0; pos -= 1) {//Loop to ungrab item
    myServo.write(pos);                 //Controll angle in reverse
    delay(10);                          //Delay to controll rotatation veloity in reverse.
    }
    }
}
