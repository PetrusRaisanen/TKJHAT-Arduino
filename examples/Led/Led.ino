// This code is an example of how to use the Led class to control a simple LED

#include <Led.h>
#include <pins.h>

// Create an instance of the Led class with the defined pin for the red LED
Led led(RED_LED_PIN);

// LED initialization
void setup() {
    led.begin();
}

// In this example, we will toggle the LED on and off every one second
void loop() {
    led.toggle();
    delay(1000);
}
