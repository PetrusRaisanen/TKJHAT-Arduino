#include <TKJHAT.h>
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

// The following simple tests basically test that the functions inside LightSensor can be called without crashing

// This test tests that begin() initializes the sensor and readLight() returns a value bigger than or equal to 0
void testBeginAndRead() {
  uint32_t value = lightSensor.readLight();

  Serial.print("Read value after begin: ");
  Serial.println(value);

  test("begin() + readLight() returns valid value", 1, value >= 0);
}

// This test tests that stop() can be called without errors
void testStop() {
  lightSensor.stop();
  delay(100);

  Serial.println("stop() called successfully");
  test("stop() executes without error", 1, 1);
}

void setup() {
  Serial.begin(115200);
  delay(2000);

  Serial.println("Starting LightSensor tests...");
  lightSensor.begin();
  testBeginAndRead();
  testStop();

  Serial.println();
  Serial.print("Passed: ");
  Serial.println(testsPassed);
  Serial.print("Failed: ");
  Serial.println(testsFailed);
}

void loop() {
}
