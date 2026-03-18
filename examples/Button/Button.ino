// This code is an example of how to use the Button class

#include <Button.h>
#include <pins.h>

// Create an instance of the Button class with the defined pin for the button
Button button1(SW1_PIN);

// Button initialization
void setup() {
  Serial.begin(9600);
  button1.begin();
}

// In this example, we will check if the button is pressed and print a message to the serial monitor every 100 milliseconds
void loop() {
  if (button1.isPressed()) {
    Serial.println("Button 1 Pressed!");
  }
  delay(100);
}
