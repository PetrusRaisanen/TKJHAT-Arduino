#include <Arduino.h>
#include <unity.h>
#include <Wire.h>
#include "LightSensor.h"
#include "pins.h"

LightSensor lightSensor(DEFAULT_I2C_SDA_PIN, DEFAULT_I2C_SCL_PIN);

void setUp(void) {
    Wire.setSDA(DEFAULT_I2C_SDA_PIN);
    Wire.setSCL(DEFAULT_I2C_SCL_PIN);
    Wire.begin();
    
    lightSensor.begin();
}

void tearDown(void) {
}

// This test tests that lightsensor functions can be called without errors
void testCalls() {
    uint32_t lux = lightSensor.readLight();
    (void)lux;
    lightSensor.stop();
    TEST_PASS();
}

// Test that the lux value is reasonable
void testFormat() {
    uint32_t lux = lightSensor.readLight();
// VEML6030 has a maximum measurable illuminance of around 120,000-140,000 lux, so 140 000 is safe upper bound for testing
    TEST_ASSERT_TRUE(lux >= 0);
    TEST_ASSERT_TRUE(lux < 140000);
}

// Test that stop() can be called without errors
void testStop() {
    lightSensor.stop();
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
