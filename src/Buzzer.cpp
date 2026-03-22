#include "Buzzer.h"

/**
 * @brief Construct a new Buzzer object
 * @param pin GPIO pin connected to the buzzer
 */

Buzzer::Buzzer(uint8_t pin) {
    this->pin = pin;
}

/**
 * @brief Initialize the buzzer pin
 * 
 * Configures the pin as OUTPUT and ensures it's off.
 */

void Buzzer::begin() {
    pinMode(pin, OUTPUT);
    digitalWrite(pin, LOW); // Ensure buzzer is off
}

/**
 * @brief Play a tone on the buzzer
 * @param frequency Frequency of the tone in Hz
 * @param duration Duration of the tone in milliseconds
 */

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

/**
 * @brief Turn off the buzzer
 */

void Buzzer::turnOff() {
    digitalWrite(pin, LOW);
}
