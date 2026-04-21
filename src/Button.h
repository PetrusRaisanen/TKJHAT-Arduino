#ifndef TKJHAT_BUTTON_H
#define TKJHAT_BUTTON_H

#include <Arduino.h>

/**
 * @class Button
 * @brief A class to handle a push button connected to the TKJHAT board
 * 
 * @details
 * The JTKJ HAT exposes two user buttons connected to GPIO 2 and GPIO 22.
 * They are configured as digital inputs using the board’s hardware pull-downs.
 * Use @c gpio_get(SW1_PIN) or @c gpio_get(SW2_PIN) to poll their state.
 *
 * Pins:
 * | Name | Macro       | GPIO |
 * |------|-------------|------|
 * | SW1  | @ref SW1_PIN / @ref BUTTON1 | 2 |
 * | SW2  | @ref SW2_PIN / @ref BUTTON2 | 22 |
 *
 * @note Logic is active-high (pressed = 1, released = 0).
 * @{
 */

class Button {
  private:
    uint8_t pin; ///< GPIO pin connected to the button

  public:
    /**
     * @brief Create a Button instance
     * 
     * @param pin GPIO pin connected to the button, either 2 (SW1) or 22 (SW2)
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

/** @example Button.ino
 * 
 *@}
 */
#endif