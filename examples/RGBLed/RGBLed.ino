// This code is an example of how to use the RGBLed class

#include <RGBLed.h>
#include <pins.h>

// Create an instance of the RGBLed class with the defined pins for the RGB LED
RGBLed rgbLed(RGB_LED_R, RGB_LED_G, RGB_LED_B);

// RGBLed.begin() initializes the RGB LED, and RGBLed.write() sets the color of the LED
// First value is for red, second for green, and third for blue. Each value can range from 0 to 255.
void setup() {
    rgbLed.begin();
    rgbLed.write(10, 0, 10);
}

// In this example, we don't need to do anything in the loop, as we just want to set the RGB LED to a specific color once
void loop() {
}
