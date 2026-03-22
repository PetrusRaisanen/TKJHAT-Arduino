#include "Led.h"
// Instance that selects pin
Led::Led(uint8_t pin) {
    this->pin = pin;
}
// Initialization
void Led::begin() {
    pinMode(pin, OUTPUT);
}
// Toggle led state
void Led::toggle() {
    bool curr = digitalRead(pin);
    digitalWrite(pin, !curr);
}
// Set led on or off
void Led::set(bool status) {
    digitalWrite(pin, status ? HIGH : LOW);
}
// Blink led n times
void Led::blink(int n) {
    for (int i = 0; i < n; i++) {
        toggle();
        delay(120);
        toggle();
        delay(120);
    }
    digitalWrite(pin, LOW);
}
