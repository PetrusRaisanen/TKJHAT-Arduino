#include "TKJHAT.h"

TKJHAT hat;

int testsPassed = 0;
int testsFailed = 0;

void test(const char* testName, bool passed) {
  if (passed) {
    Serial.print("[PASS] ");
    Serial.println(testName);
    testsPassed++;
  } else {
    Serial.print("[FAIL] ");
    Serial.println(testName);
    testsFailed++;
  }
}

//Tests

// This test checks that begin() can be called without errors
void test_begin() {
  Serial.println("Running begin()");
  hat.hdc2021.begin();
  delay(100);
  test("begin()", true);
}

//
void test_stop() {

}



void setup() {
  Serial.begin(115200);
  hat.begin();
  delay(2000);

  Serial.println("Starting HDC2021 tests...");
  // Run all the tests
  test_begin();
  test_stop();

  Serial.println();
  Serial.print("Passed: ");
  Serial.println(testsPassed);
  Serial.print("Failed: ");
  Serial.println(testsFailed);
}

void loop() {}