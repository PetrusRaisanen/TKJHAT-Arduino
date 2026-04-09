/*
  LED Example

  This example demonstrates how to use the TKJHAT library to control an LED.
  The LED will toggle on and off every second.

  Circuit:
  - LED integrated in Pico HAT

  created 2026
 */

#include "TKJHAT.h"

TKJHAT hat; // Create an instance of the TKJHAT class to access the LED

// LED initialization
void setup() {
    hat.led.begin();
}

// In this loop, we will toggle the LED on and off every second
void loop() {
    hat.led.toggle();
    delay(1000);
}
