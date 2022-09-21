
#include "ClawController.h"
ClawController::ClawController(int pin)
{
    myServo.attach(pin);
    Serial.println(pin);
    
}
void ClawController::ClawGrab(){
    while(true){
    for (pos = 0; pos <= 20; pos += 1) { 
    Serial.println(pos);
    myServo.write(pos); 
    delay(15);                 
    }
    
    for (pos = 20; pos >= 0; pos -= 1) {
    Serial.println("LOOP");
    Serial.println(pos);
    myServo.write(pos);              
    delay(15);               
    }
    
    }
}
