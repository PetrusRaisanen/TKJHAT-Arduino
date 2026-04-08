// This code is an example of how to use the RGBLed class
#include "TKJHAT.h"

TKJHAT hat; // Create an instance of the TKJHAT class to access the RGB LED


// RGBLed.begin() initializes the RGB LED, and RGBLed.write() sets the color of the LED
// First value is for red, second for green, and third for blue. Each value can range from 0 to 255.
void setup() {
    hat.rgbLed.begin();
    hat.rgbLed.write(10, 0, 10);
}

// In this example, we don't need to do anything in the loop
void loop() {
}
