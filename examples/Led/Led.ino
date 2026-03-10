// This code tests the functionality of the Led class.
#include <Led.h>
#include <pins.h>

Led led(RED_LED_PIN);

void setup() {
    led.begin();
}

void loop() {
    led.toggle();
    delay(1000);
}
