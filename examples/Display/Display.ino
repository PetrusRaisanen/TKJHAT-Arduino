#include <Arduino.h>
#include <TKJHAT.h>

TKJHAT hat;

void setup() {
    Serial.begin(9600);
    hat.begin();
}

void loop() {
    hat.display.writeText("Hello World!", 1);
    delay(2000);

    hat.display.clear();
    delay(1000);
}
