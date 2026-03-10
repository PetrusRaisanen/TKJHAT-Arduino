#include "Arduino.h"
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
 * reads HIGH when pressed and LOW when released.
 */
void Button::begin() {
    pinMode(pin, INPUT_PULLUP);
}

/**
 * @brief Check if the button is pressed
 * @return true if pressed (logic HIGH)
 * @return false if not pressed (logic LOW)
 */
bool Button::isPressed() {
    return digitalRead(pin) == HIGH;
}