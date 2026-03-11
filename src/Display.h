#ifndef TKJHAT_DISPLAY_H
#define TKJHAT_DISPLAY_H

#include <Arduino.h>


extern "C" {    // Including C headers in a C++ file requires extern "C"
#include "ssd1306.h"
}

class Display {
private:
    ssd1306_t _disp;

public:
    Display();
    void begin();
    void writeText(const char* text, uint8_t scale = 1);
    void clear();
};

#endif
