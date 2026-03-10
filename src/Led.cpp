#include "Led.h"
#include "pins.h"
#include <Arduino.h>

void Led::begin() {
    pinMode(RED_LED_PIN, OUTPUT);
}

void Led::toggle() {
    bool curr = digitalRead(RED_LED_PIN);
    digitalWrite(RED_LED_PIN, !curr);
}

void Led::set(bool status) {
    digitalWrite(RED_LED_PIN, status ? HIGH : LOW);
}

void Led::blink(int n) {
    for (int i = 0; i < n; i++) {
        toggle();
        delay(120);
        toggle();
        delay(120);
    }
    digitalWrite(RED_LED_PIN, LOW);
}
