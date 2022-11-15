
#include "ClawController.h"
ClawController::ClawController()
{
    myServo.attach(servoPinOutput); 
}
void ClawController::OpenClaw(){
                                        
    for (int pos = 0; pos <= 100; pos += 1) { 
    myServo.write(pos);                    
    delay(5);                              
    }
}

void ClawController::CloseClaw(){
    for (int pos = 100; pos >= 0; pos -= 1) {
    myServo.write(pos);                 
    delay(5);                          
    }
}