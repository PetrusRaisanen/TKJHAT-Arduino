#include "Button.h"

Button button1(22);

void setup() {
  Serial.begin(9600);
  button1.begin();
}

void loop() {
  if (button1.isPressed())
  {
    Serial.println("Button 1 Pressed!");
  }
  delay(100);
}
