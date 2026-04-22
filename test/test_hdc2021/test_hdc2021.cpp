#include <Arduino.h>
#include <unity.h>
#include "TKJHAT.h"

TKJHAT hat;

void setUp(void) {
    hat.begin();
}

void tearDown(void) {
}

// Test that temperature value is a valid float (not NaN)
void testTempFloat() {
    float temperature = hat.hdc2021.readTemperature();
    TEST_ASSERT_TRUE(!isnan(temperature));
}

// Test that humidity value is a valid float (not NaN)
void testHumidityFloat() {
    float humidity = hat.hdc2021.readHumidity();
    TEST_ASSERT_TRUE(!isnan(humidity));
}

// Test that temperature can be read multiple times without errors
void testTempMultipleReads() {
    for (int i = 0; i < 5; i++) {
        float temperature = hat.hdc2021.readTemperature();
        TEST_ASSERT_TRUE(!isnan(temperature));
    }
}

// Test that humidity can be read multiple times without errors
void testHumidityMultipleReads() {
    for (int i = 0; i < 5; i++) {
        float humidity = hat.hdc2021.readHumidity();
        TEST_ASSERT_TRUE(!isnan(humidity));
    }
}

// Test that temperature thresholds can be set without errors
void testTempThresholds() {
    hat.hdc2021.setLowTempThreshold(0.0f);
    hat.hdc2021.setHighTempThreshold(50.0f);
    TEST_PASS();
}

// Test that humidity thresholds can be set without errors
void testHumidityThresholds() {
    hat.hdc2021.setLowHumidityThreshold(20.0f);
    hat.hdc2021.setHighHumidityThreshold(80.0f);
    TEST_PASS();
}

// Test that stop can be called without errors
void testStop() {
    hat.hdc2021.stop();
    TEST_PASS();
}

void setup() {
    delay(1000);
    while (!Serial) {}
    UNITY_BEGIN();

    RUN_TEST(testTempFloat);
    delay(100);

    RUN_TEST(testHumidityFloat);
    delay(100);

    RUN_TEST(testTempMultipleReads);
    delay(100);

    RUN_TEST(testHumidityMultipleReads);
    delay(100);

    RUN_TEST(testTempThresholds);
    delay(100);

    RUN_TEST(testHumidityThresholds);
    delay(100);

    RUN_TEST(testStop);
    delay(100);

    UNITY_END();
}

void loop() {}
