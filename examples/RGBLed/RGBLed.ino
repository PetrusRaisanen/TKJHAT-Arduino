/*
  RGB LED Example

  This example demonstrates how to use the RGB LED on the TKJHAT. 
  The RGB LED can be controlled by setting the intensity of the red, green, and blue components.

  Circuit:
  - RGB LED integrated in Pico HAT

  created 2026
 */

#include "TKJHAT.h"

// Create an instance of the TKJHAT class
TKJHAT hat; 


// RGBLed.begin() initializes the RGB LED, and RGBLed.write() sets the color of the LED
// First value is for red, second for green, and third for blue. Each value can range from 0 to 255.
void setup() {
    hat.rgbLed.begin();
    hat.rgbLed.write(10, 0, 10);
}

// In this example, we don't need to do anything in the loop
void loop() {
}
