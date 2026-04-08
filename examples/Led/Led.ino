// This code is an example of how to use the Led class to control a simple LED
#include "TKJHAT.h"

TKJHAT hat; // Create an instance of the TKJHAT class to access the LED

// LED initialization
void setup() {
    hat.led.begin();
}

// In this example, we will toggle the LED on and off every one second
void loop() {
    hat.led.toggle();
    delay(1000);
}
