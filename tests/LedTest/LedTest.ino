#include <Led.h>
#include <pins.h>

Led led(RED_LED_PIN);

int testsPassed = 0;
int testsFailed = 0;

void test(const char* testName, int expected, int actual) {
  if (expected == actual) {
    Serial.print("[PASS] ");
    Serial.println(testName);
    testsPassed++;
  } else {
    Serial.print("[FAIL] ");
    Serial.print(testName);
    Serial.print(" expected=");
    Serial.print(expected);
    Serial.print(" actual=");
    Serial.println(actual);
    testsFailed++;
  }
}

// This test tests the functionality of the set() method by setting the LED on and verifying that the pin reads HIGH.
void testSetTrueTurnsLedOn() {
  led.set(true);
  delay(10);
  test("set(true) turns LED on", HIGH, digitalRead(RED_LED_PIN));
}

void testSetFalseTurnsLedOff() {
  led.set(false);
  delay(10);
  test("set(false) turns LED off", LOW, digitalRead(RED_LED_PIN));
}

// This test tests the functionality of the toggle() method by toggling the LED state from LOW to HIGH and verifying that the pin reads HIGH.
void testToggleFromLowToHigh() {
  led.set(false);
  delay(10);
  led.toggle();
  delay(10);
  test("toggle() LOW -> HIGH", HIGH, digitalRead(RED_LED_PIN));

}

// This test tests the functionality of the toggle() method by toggling the LED state from HIGH to LOW and verifying that the pin reads LOW.
void testToggleFromHighToLow() {
  led.set(true);
  delay(10);
  led.toggle();
  delay(10);
  test("toggle() HIGH -> LOW", LOW, digitalRead(RED_LED_PIN));
}

void setup() {
  Serial.begin(115200);
  delay(2000);

  Serial.println("Starting LED tests...");
  led.begin();

  testSetTrueTurnsLedOn();
  testSetFalseTurnsLedOff();
  testToggleFromLowToHigh();
  testToggleFromHighToLow();

  Serial.println();
  Serial.print("Passed: ");
  Serial.println(testsPassed);
  Serial.print("Failed: ");
  Serial.println(testsFailed);
}

void loop() {
}
