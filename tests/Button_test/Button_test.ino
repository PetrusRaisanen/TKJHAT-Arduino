#include "TKJHAT.h"

TKJHAT hat;

bool lastSW1 = false;
bool lastSW2 = false;

void setup() {
    Serial.begin(9600);
    hat.begin();
    Serial.println("Button test started.");
    
    lastSW1 = hat.button1.isPressed();
    lastSW2 = hat.button2.isPressed();
}

void loop() {
    bool sw1State = hat.button1.isPressed();
    bool sw2State = hat.button2.isPressed();

    if (sw1State != lastSW1) {
        Serial.print("Button 1: ");
        Serial.println(sw1State ? "Pressed" : "Released");
        lastSW1 = sw1State;
    }

    if (sw2State != lastSW2) {
        Serial.print("Button 2: ");
        Serial.println(sw2State ? "Pressed" : "Released");
        lastSW2 = sw2State;
    }

    delay(50);
}
