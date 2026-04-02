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

void test_set_true_turns_led_on() {
  led.set(true);
  delay(10);
  test("set(true) turns LED on", HIGH, digitalRead(RED_LED_PIN));
}

void setup() {
  Serial.begin(115200);
  delay(2000);

  Serial.println("Starting LED tests...");
  led.begin();

  test_set_true_turns_led_on();

  Serial.println();
  Serial.print("Passed: ");
  Serial.println(testsPassed);
  Serial.print("Failed: ");
  Serial.println(testsFailed);
}

void loop() {
}
