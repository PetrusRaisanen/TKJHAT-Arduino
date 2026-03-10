#ifndef TKJHAT_BUZZER_H
#define TKJHAT_BUZZER_H

#include <Arduino.h>

class Buzzer {
  private:
    uint8_t pin;

  public:
    Buzzer(uint8_t pin);

    void begin();

    void playTone(uint32_t frequency, uint32_t duration);

    void turnOff();
};

#endif