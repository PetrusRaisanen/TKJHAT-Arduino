#include "Buzzer.h"

Buzzer::Buzzer(uint8_t pin) {
    this->pin = pin;
}

void Buzzer::begin() {
    pinMode(pin, OUTPUT);
    digitalWrite(pin, LOW); // Ensure buzzer is off
}

void Buzzer::playTone(uint32_t frequency, uint32_t duration) {
    // Calculate the period (in microseconds) and number of cycles
    uint32_t period_us = 1000000 / frequency;
    uint32_t num_cycles = duration * frequency / 1000;

    // Generate the tone by toggling the buzzer pin at the specified frequency
    for (uint32_t i = 0; i < num_cycles; i++) {
        digitalWrite(pin, HIGH);
        delayMicroseconds(period_us / 2);
        digitalWrite(pin, LOW);
        delayMicroseconds(period_us / 2);
    }
}

void Buzzer::turnOff() {
    digitalWrite(pin, LOW);
}
