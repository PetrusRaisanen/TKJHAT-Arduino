#include <Arduino.h>
#include <unity.h>
#include "TKJHAT.h"

TKJHAT hat;

void setUp(void) {
    hat.begin();
}

void tearDown(void) {
}

// This test tests that lightsensor functions can be called without errors
void testCalls() {
    uint32_t lux = hat.lightSensor.readLight();
    (void)lux;
    hat.lightSensor.stop();
    TEST_PASS();
}

// Test that the lux value is reasonable
void testFormat() {
    uint32_t lux = hat.lightSensor.readLight();
// VEML6030 has a maximum measurable illuminance of around 120,000-140,000 lux, so 140 000 is safe upper bound for testing
    TEST_ASSERT_TRUE(lux >= 0);
    TEST_ASSERT_TRUE(lux < 140000);
}

// Test that stop() can be called without errors
void testStop() {
    hat.lightSensor.stop();
    TEST_PASS();
}

void setup() {
    delay(1000);
    while (!Serial) {}
    UNITY_BEGIN();

    RUN_TEST(testCalls);
    delay(100);

    RUN_TEST(testFormat);
    delay(100);

    RUN_TEST(testStop);
    delay(100);

    UNITY_END();
}

void loop() {}
