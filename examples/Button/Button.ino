/*
  Button Example

  This example shows how to read a button using the TKJHAT library.
  When the button is pressed, a message is printed to the Serial Monitor.

  Circuit:
  - Button connected via TKJHAT

  created 2026
*/

#include "TKJHAT.h"

// Create an instance of the TKJHAT class to access the peripherals
TKJHAT hat; 


// Button and serial initialization
void setup() {
  Serial.begin(9600);
  hat.button1.begin();
}


void loop() {
  // Check if button 1 is pressed
  if (hat.button1.isPressed()) {
    Serial.println("Button 1 Pressed!");
  }
  // Small delay to avoid flooding the Serial Monitor
  delay(100);
}
