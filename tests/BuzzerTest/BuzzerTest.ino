#include <Buzzer.h>
#include <pins.h>

Buzzer buzzer(BUZZER_PIN);

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

// This test tests the, is BUZZER_PIN LOW after turnOff() funktion
void testTurnOff() {
  buzzer.turnOff();
  delay(10);
  test("Is BUZZER_PIN LOW after turnOff()", LOW, digitalRead(BUZZER_PIN));

}

// This test tests the, is BUZZER_PIN LOW after playTone() funktion
void testPlayTone() {
  buzzer.playTone(100, 100);
  delay(10);
  test("Is BUZZER_PIN LOW after playTone()", LOW, digitalRead(BUZZER_PIN));
}

void setup() {
  Serial.begin(115200);
  delay(2000);

  Serial.println("Starting Buzzer tests...");
  buzzer.begin();

  testTurnOff();
  testPlayTone();

  Serial.println();
  Serial.print("Passed: ");
  Serial.println(testsPassed);
  Serial.print("Failed: ");
  Serial.println(testsFailed);
}

void loop() {
}
