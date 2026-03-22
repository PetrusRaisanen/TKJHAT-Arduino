#ifndef TKJHAT_LED_H
#define TKJHAT_LED_H

#include <Arduino.h>

/** @brief A class to control an LED
 * 
 */

class Led {

private:
    uint8_t pin;

public:

    /** @brief Construct a new Led object
     * @param pin GPIO pin connected to the LED
     * 
     */
    Led(uint8_t pin);

    /** @brief Initialize the LED
     * 
     */
    void begin();

    /** @brief Toggle the LED state
     * 
     */
    void toggle();

    /** @brief Set the LED on or off
     * @param status Set to @c true to turn the LED on, @c false to turn it off
     * 
     */
    void set(bool status);

    /** @brief Blink the LED a given number of times
     * @param n Number of times to blink
     * 
     */
    void blink(int n);
};

#endif
