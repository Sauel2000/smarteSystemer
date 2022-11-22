#include <Servo.h>
Servo testServo;  
int pos = 0;
int sensorValue;
void setup() {
  testServo.attach(22);  //Using attach method to attach servo to arduino pin
  Serial.begin(9600);

}

void loop() {
      
        //for (int pos = 180; pos >= 0; pos -= 1) {
    testServo.write(150);                 
    delay(5);   
        //}
     //   delay(10000);
  
    //for (int pos = 0; pos <= 50; pos += 1) { 
    testServo.write(180);                    
    delay(5);                              
    //}
    
    


        
        
}
