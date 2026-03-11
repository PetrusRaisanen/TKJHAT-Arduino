#ifndef TKJHAT_MICROPHONE_H
#define TKJHAT_MICROPHONE_H

#include <Arduino.h>
#include "pdm_microphone.h"

class Microphone {
private:
    uint8_t dataPin;
    uint8_t clkPin;

public:
    Microphone(uint8_t dataPin, uint8_t clkPin);
    int begin();
    int start();
    void stop();

    void setCallback(pdm_samples_ready_handler_t handler);
    int getSamples(int16_t* buffer, size_t samples);

};

#endif
