// This code is an example of how to use the Display class to show text on the display

#include <Arduino.h>
#include <TKJHAT.h>

// Create TKJHAT object which provides access to onboard components
TKJHAT hat;

// Initializes serial communication and the TKJHAT hardware
void setup() {
    Serial.begin(9600);
    hat.begin();
}

// Displays text on the screen, waits, clears the display, and repeats.
void loop() {
    hat.display.writeText("Hello World!", 1);
    delay(2000);

    hat.display.clear();
    delay(1000);
}
