#include "Button.h"

/**
 * @brief Construct a new Button object
 * @param pin GPIO pin connected to the button
 */
Button::Button(uint8_t pin) {
    this->pin = pin;
}

/**
 * @brief Initialize the button
 * 
 * Configures the pin as INPUT_PULLUP, so the button
 * reads LOW when pressed and HIGH when released.
 */
void Button::begin() {
    pinMode(pin, INPUT_PULLUP);
}

/**
 * @brief Check if the button is pressed
 * @return true if pressed (logic LOW)
 * @return false if not pressed (logic HIGH)
 */
bool Button::isPressed() {
    return digitalRead(pin) == LOW;
}