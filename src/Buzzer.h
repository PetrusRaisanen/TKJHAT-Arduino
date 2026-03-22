#ifndef TKJHAT_BUZZER_H
#define TKJHAT_BUZZER_H

#include <Arduino.h>

/**
* @brief A class to control a buzzer
* 
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
  * 
*/

    void begin();

/**
  * @brief Play a tone on the buzzer
  * @param frequency Frequency of the tone in Hz
  * @param duration Duration of the tone in milliseconds
  *
*/

    void playTone(uint32_t frequency, uint32_t duration);

/**
  * @brief Turn off the buzzer
*/

    void turnOff();
};

#endif