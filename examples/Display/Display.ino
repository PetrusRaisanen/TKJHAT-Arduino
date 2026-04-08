// This code is an example of how to use the Display class to show text on the display
#include "TKJHAT.h"

// Create TKJHAT object which provides access to onboard components
TKJHAT hat;

// Initializes serial communication and the TKJHAT hardware
void setup() {
    Serial.begin(9600);
    hat.begin();
}

void loop() {
    hat.display.writeText("Hello HAT!");
    delay(2000);
    hat.display.clear();

    hat.display.drawLine(0, 0, 127, 63); // Draw a diagonal line across the display
    delay(2000);

    hat.display.drawLine(0, 63, 127, 0); // Draw the opposite diagonal
    delay(2000);
    hat.display.drawCircle(64, 32, 20, false); // Draw an empty circle at the center of the display
    delay(2000);

    hat.display.clear();
    hat.display.writeText("Goodbye!");
    delay(2000);

    hat.display.clear();
    hat.display.stopDisplay(); // Power off the display
}
