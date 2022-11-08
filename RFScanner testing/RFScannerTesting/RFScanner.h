#pragma once // Include the library MFRC522 by GithubCommunity Version 1.4.1
#include <deprecated.h>
#include <MFRC522.h>
#include <MFRC522Extended.h>
#include <require_cpp11.h>



class RFScanner {
public:
    RFScanner(); // Constructor, i use pins 53, 6 for the RFID scanner
    void init(); // Initialize the RFID scanner
    void scan(); // Scan for RFID tags
    bool getAccess(); // Get the access status
    void setAccess(bool access); // Set the access status

private:
    MFRC522 mfrc522; // Create MFRC522 instance.
    bool access = false;
};

