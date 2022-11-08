#include "RFScanner.h"
#include <Arduino.h>

void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);

  RFScanner scanner;
  scanner.init();
  scanner.scan();
  Serial.println("FØR");
  bool result = scanner.getAccess();
 if (result) {
  mainRoutine(1);
  scanner.setAccess(false);
 }


}

void mainRoutine(bool access) {
  
  Serial.println("Main routine");

}
void loop() {
  // put your main code here, to run repeatedly:

}

