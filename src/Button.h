/**
 * @file Button.h
 * @brief Button interface for the TKJHAT board
 *
 * This class provides a simple interface for reading
 * the state of a push button connected to the TKJHAT board.
 *
 * The button is assumed to be connected using a pull-up configuration.
 * The pressed state corresponds to a LOW signal on the pin.
 */

#ifndef TKJHAT_BUTTON_H
#define TKJHAT_BUTTON_H

#include <Arduino.h>

/**
 * @class Button
 * @brief Represents a push button connected to a GPIO pin.
 */
class Button {
  private:
    uint8_t pin; ///< GPIO pin connected to the button

  public:
    /**
     * @brief Create a Button instance
     * 
     * @param pin GPIO pin connected to the button
     */
    Button(uint8_t pin);
    /**
     * @brief Initialize the button pin
     * 
     * Configures the pin mode. Must be called in setup().
     */
    void begin();
    /**
     * @brief Read the button state
     * 
     * @return true if the button is currently pressed, false otherwise
     */
    bool isPressed();
};

#endif