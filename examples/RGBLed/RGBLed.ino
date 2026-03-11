// This code tests the functionality of the RGBLed
#include <RGBLed.h>
#include <Pins.h>

RGBLed rgbLed(RGB_LED_R, RGB_LED_G, RGB_LED_B);

void setup() {
    rgbLed.begin();
    rgbLed.write(10, 0, 10); // Magenta
}

void loop() {
}
