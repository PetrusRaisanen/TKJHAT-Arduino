#include <Led.h>
#include <pins.h>

LightSensor lightSensor(DEFAULT_I2C_SDA_PIN, DEFAULT_I2C_SCL_PIN);

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



void setup() {
  Serial.begin(115200);
  delay(2000);

  Serial.println("Starting LightSensor tests...");
  lightSensor.begin();



  Serial.println();
  Serial.print("Passed: ");
  Serial.println(testsPassed);
  Serial.print("Failed: ");
  Serial.println(testsFailed);
}

void loop() {
}
