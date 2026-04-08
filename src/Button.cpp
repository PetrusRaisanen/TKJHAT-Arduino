#include <Arduino.h>
#include "Button.h"

// Instance that selects pin
Button::Button(uint8_t pin) {
    this->pin = pin;
}
// Initialization
void Button::begin() {
    pinMode(pin, INPUT_PULLUP);
}
// Check if the button is pressed (active HIGH)
bool Button::isPressed() {
    return digitalRead(pin) == HIGH;
}
