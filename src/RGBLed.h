#ifndef TKJHAT_RGBLED_H
#define TKJHAT_RGBLED_H

#include <Arduino.h>

class RGBLed {
private:
    uint8_t pinR;
    uint8_t pinG;
    uint8_t pinB;

public:
    RGBLed(uint8_t pinR, uint8_t pinG, uint8_t pinB);

    void begin();
    void stop();
    void write(uint8_t r, uint8_t g, uint8_t b);
};

#endif
