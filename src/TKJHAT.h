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
 * @brief Main interface for accessing TKJHAT board features.
 *
 * Example:
 * @code
 * TKJHAT hat;
 *
 * void setup() {
 *   hat.begin();
 * }
 *
 * void loop() {
 *   if (hat.button1.isPressed()) {
 *     hat.led.on();
 *   }
 * }
 * @endcode
 */

class TKJHAT {
public:
    /** @brief Button 1 on the board */
    Button button1;

    /** @brief Button 2 on the board */
    Button button2;

    /** @brief Onboard LED */
    Led led;

    /** @brief Buzzer output */
    Buzzer buzzer;

    /** @brief Display module */
    Display display;

    /** @brief RGB LED */
    RGBLed rgbLed;

    /** @brief IMU sensor (accelerometer + gyroscope) */
    ICM42670 icm42670;

    /** @brief Ambient light sensor */
    LightSensor lightSensor;

    /** @brief Temperature and humidity sensor */
    HDC2021 hdc2021;

    /**
     * @brief Construct a new TKJHAT object
     */
    TKJHAT();

    /**
     * @brief Initialize all peripherals on the HAT
     * Also initializes the default I2C bus for sensors and display
     *
     * Must be called in setup() before using any components.
     */
    void begin();
};

#endif