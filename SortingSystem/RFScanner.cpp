#include "RFScanner.h"

RFScanner::RFScanner() {
    mfrc522 = MFRC522(53, 6); // Create MFRC522 instance.
}

void RFScanner :: init() {
    SPI.begin(); // Init SPI bus
    mfrc522.PCD_Init(); // Init MFRC522
    mfrc522.PCD_DumpVersionToSerial(); // Show details of PCD - MFRC522 Card Reader details
}
void RFScanner::scan() {
bool access = false;
while (access == false) {
    if ( ! mfrc522.PICC_IsNewCardPresent()) { // If a new card present
        return;
    }
    // Select one of the cards
    if ( ! mfrc522.PICC_ReadCardSerial()) { // Read the card
        return;
    }
Serial.print("UID tag :");
  String content= ""; //makes a string for the for loop
  byte letter; //makes a byte variable for the for loop
  for (byte i = 0; i < mfrc522.uid.size; i++)  //for loop to read the uid
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "); //prints a space and a 0 if the uid is less than 0x10
     Serial.print(mfrc522.uid.uidByte[i], HEX); //prints the uid in hex
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ")); //adds the uid to the string
     content.concat(String(mfrc522.uid.uidByte[i], HEX)); //adds the uid to the string
  }
    content.toUpperCase(); //makes the string uppercase
  if (content.substring(1) == "67 F2 D5 B5") //change here the UID of the card/cards that you want to give access
  {
    Serial.println("Authorized access"); //prints authorized access
    Serial.println();
    delay(3000);
  }
 
 else   {
    Serial.println(" Access denied"); //prints access denied
    delay(3000);
  }
}
}
