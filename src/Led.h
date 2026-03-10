#ifndef TKJHAT_LED_H
#define TKJHAT_LED_H

#include <Arduino.h>

class Led {
public:
    void begin();

    void toggle();

    void set(bool status);
    
    void blink(int n);
};

#endif
