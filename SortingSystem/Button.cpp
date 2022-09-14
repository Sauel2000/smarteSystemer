#include <Arduino.h>
#include "Button.h"

Button::Button(int pin) {
    pin = pin;
    pinMode(pin, INPUT);
}

bool Button::isPressed() {
    bool isPressed = (digitalRead(pin) == HIGH);
    delay(debounceDelay);

    return isPressed;
}
