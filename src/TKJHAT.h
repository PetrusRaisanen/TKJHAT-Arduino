#ifndef TKJHAT_H
#define TKJHAT_H

#include <Arduino.h>

#include "Button.h"
#include "Led.h"
#include "Buzzer.h"
#include "RGBLed.h"

/**
 * @class TKJHAT
 * @brief Arduino-style interface for the TKJHAT board.
 */
class TKJHAT {
public:
    Button button1;
    Button button2;
    Led led;
    Buzzer buzzer;
    RGBLed rgbLed;

    /**
     * @brief Construct a new TKJHAT object.
     */
    TKJHAT();

    /**
     * @brief Initialize the board peripherals.
     */
    void begin();
};

#endif