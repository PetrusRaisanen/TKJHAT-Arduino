#ifndef TKJHAT_BUZZER_H
#define TKJHAT_BUZZER_H

#include <Arduino.h>

/**
* @brief A class to control a buzzer
* 
 * @details
 * This module provides simple control for the buzzer (@ref BUZZER_PIN — GPIO 17).
 *
 * **Buzzer (@ref BUZZER_PIN — GPIO 17)**
 * - Output-only pin for tone generation using PWM or software toggling.
 * - Useful for short alerts, melodies, or feedback tones.
 *
 * {@
*/

class Buzzer {
  private:
    uint8_t pin;

/**
  * @brief Construct a new Buzzer object
  * @param pin GPIO pin connected to the buzzer
  * 
*/

  public:
    Buzzer(uint8_t pin);

/**
  * @brief Initialize the buzzer pin
  * Configures the buzzer pin as a digital output. 
  * 
*/

    void begin();

/**
 * @brief Play a tone on the buzzer.
 *
 * Generates a square wave at the requested frequency for the
 * specified duration by toggling the buzzer pin.
 * 
 * @brief Play a tone on the buzzer
 * @param frequency Frequency of the tone in Hz
 * @param duration Duration of the tone in milliseconds
 *
*/

    void playTone(uint32_t frequency, uint32_t duration);

/**
  * @brief Turn off the buzzer
  * 
  * Drives the buzzer pin low.
*/

    void turnOff();
};
/** @example Buzzer.ino
 * 
 *@}
 */

#endif