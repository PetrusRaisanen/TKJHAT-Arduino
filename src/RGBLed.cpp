#include "RGBLed.h"

// Constructor
RGBLed::RGBLed(uint8_t pinR, uint8_t pinG, uint8_t pinB) {
    this->pinR = pinR;
    this->pinG = pinG;
    this->pinB = pinB;
}

// Initializes the RGB LED by setting the pin modes and turning it off
void RGBLed::begin() {
    pinMode(pinR, OUTPUT);
    pinMode(pinG, OUTPUT);
    pinMode(pinB, OUTPUT);

    analogWrite(pinR, 255);
    analogWrite(pinG, 255);
    analogWrite(pinB, 255);
}

// Turns off the LED by setting all colors to 255 (off)
void RGBLed::stop() {
    analogWrite(pinR, 255);
    analogWrite(pinG, 255);
    analogWrite(pinB, 255);
}

// 255 = off, 0 = full brightness
void RGBLed::write(uint8_t r, uint8_t g, uint8_t b) {
    r = 255 - r;
    g = 255 - g;
    b = 255 - b;

    analogWrite(pinR, r);
    analogWrite(pinG, g);
    analogWrite(pinB, b);
}
