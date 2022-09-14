#include <Arduino.h>
#include "Button.h"

Button::Button(int pinNum) {
    this->pin = pinNum;
    pinMode(pin, INPUT);
}

bool Button::isPressed() {
    bool isPressed = (digitalRead(pin) == HIGH);
    
    if (isPressed) {
        delay(debounceDelay);
    }

    return isPressed;
}
