#ifndef TKJHAT_H
#define TKJHAT_H

#include <Arduino.h>

#include "Button.h"
#include "Led.h"
#include "Buzzer.h"
#include "Display.h"
#include "RGBLed.h"
#include "ICM42670.h"
#include "Lightsensor.h"
#include "HDC2021.h"

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
    Display display;
    RGBLed rgbLed;
    ICM42670 icm42670;    
    LightSensor lightSensor;
    HDC2021 hdc2021;

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