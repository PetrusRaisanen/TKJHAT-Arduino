/**
 * @file Button.h
 * @brief Button interface for the TKJHAT board
 * Based on TKJHAT Pico C implementation
 * This class provides a simple interface for reading
 * button states from the TKJHAT extension board.
 */

#ifndef TKJHAT_BUTTON_H
#define TKJHAT_BUTTON_H

#include "Arduino.h"

/**
 * @class Button
 * @brief Represents a push button on the TKJHAT board.
 */
class Button {
  private:
    uint8_t pin;

  public:
    /**
     * @brief Construct a new Button
     * @param pin GPIO pin connected to the button
     */
    Button(uint8_t pin);
    /**
     * @brief Initialize the button
     */
    void begin();
    /**
     * @brief Check if button is pressed
     * @return true if pressed
     */
    bool isPressed();
};

#endif