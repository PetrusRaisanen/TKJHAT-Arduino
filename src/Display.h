#ifndef TKJHAT_DISPLAY_H
#define TKJHAT_DISPLAY_H

#include <Arduino.h>

class Display {
public:
    Display();

    void begin();
    void print(const char* text);
    void clear();
};

#endif
