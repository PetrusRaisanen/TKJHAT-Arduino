#ifndef TKJHAT_RGBLED_H
#define TKJHAT_RGBLED_H

#include <Arduino.h>

/** @brief A class to control a RGB LED
 * 
 * @details
 * The JTKJ HAT includes a common-anode RGB LED driven by PWM on GPIO 18 (R), 19 (G), and 20 (B).
 * 
 *  * Pins:
 * | Function  | Macro         | GPIO |
 * |-----------|---------------|------|
 * | RGB Red   | @ref RGB_LED_R | 18 |
 * | RGB Green | @ref RGB_LED_G | 19 |
 * | RGB Blue  | @ref RGB_LED_B | 20 |
 * 
 * Colors are set with @ref write using 8-bit channels (0 = full on, 255 = off).
 * {@
 */

class RGBLed {
private:
    uint8_t pinR;
    uint8_t pinG;
    uint8_t pinB;

public:

/** @brief Construct a new RGBLed object
 * @param pinR GPIO pin connected to the red channel
 * @param pinG GPIO pin connected to the green channel
 * @param pinB GPIO pin connected to the blue channel
 */
    RGBLed(uint8_t pinR, uint8_t pinG, uint8_t pinB);

    /** @brief Initialize the RGB LED
     *
     */
    void begin();

    /** @brief Stop the RGB LED
     *
     */
    void stop();

    /** @brief  * Writes PWM duty cycles to the RGB LED channels to produce the
     * requested color. The LED is wired as common-anode, so inputs are
     * inverted internally (0 = full on, 255 = off). A simple gamma
     * correction is applied by squaring the 8-bit values.
     * 
     * @param r Red channel value (0 = full on, 255 = off)
     * @param g Green channel value (0 = full on, 255 = off)
     * @param b Blue channel value (0 = full on, 255 = off)
     * 
     */
    void write(uint8_t r, uint8_t g, uint8_t b);
};
    
/** @example RGBLed.ino
 * 
 *@}
 */

#endif
