// This code tests the functionality of the Led class.
#include <Arduino.h>
#include "Led.h"

Led led(14);

void setup() {
    Serial.begin(9600);
    led.begin();
}

void loop() {
    led.toggle();
    delay(1000);
}
