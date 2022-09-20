#include <Arduino.h>
#include "Button.h"

Button::Button(int pinNum) {
    pin = pinNum;
    pinMode(pin, INPUT);
}

bool Button::isPressed() {
    bool isPressed = (digitalRead(pin) == HIGH);
    
    if (isPressed) {
        delay(debounceDelay);
    }

    Serial.println(isPressed);
    Serial.println(pin);
    return isPressed;
}
