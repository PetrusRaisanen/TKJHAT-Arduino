#include <Button.h>
#include <pins.h>

Button button1(SW1_PIN);

void setup() {
  Serial.begin(9600);
  button1.begin();
}

void loop() {
  if (button1.isPressed()) {
    Serial.println("Button 1 Pressed!");
  }
  delay(100);
}
