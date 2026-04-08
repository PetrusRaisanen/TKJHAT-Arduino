// This code is an example of how to use the Button class
#include "TKJHAT.h"

TKJHAT hat; // Create an instance of the TKJHAT class to access the button


// Button initialization
void setup() {
  Serial.begin(9600);
  hat.button1.begin();
}

// In this example, we will check if the button is pressed and print a message to the serial monitor every 100 milliseconds
void loop() {
  if (hat.button1.isPressed()) {
    Serial.println("Button 1 Pressed!");
  }
  delay(100);
}
