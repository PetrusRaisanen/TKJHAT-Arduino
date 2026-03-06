#include "Led.h"

Led::Led(uint8_t pin) {
    this->pin = pin;
}

void Led::begin() {
    pinMode(pin, OUTPUT);
}

void Led::toggle() {
    bool curr = digitalRead(pin);
    digitalWrite(pin, !curr);
}

void Led::set(bool status) {
    digitalWrite(pin, status ? HIGH : LOW);
}

void Led::blink(int n) {
    for (int i = 0; i < n; i++) {
        toggle();
        delay(120);
        toggle();
        delay(120);
    }
    digitalWrite(pin, LOW);
}
