#ifndef TKJHAT_LED_H
#define TKJHAT_LED_H

#include <Arduino.h>

class Led {
private:
    uint8_t pin;

public:
    Led(uint8_t pin);

    void begin();
    void toggle();
    void set(bool status);
    void blink(int n);
};

#endif
