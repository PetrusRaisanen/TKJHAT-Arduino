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
void test_lightsensor_basic_calls() {
    uint32_t lux = hat.lightSensor.readLight();
    (void)lux;
    hat.lightSensor.stop();
    TEST_PASS();
}

void setup() {
    delay(1000);
    while (!Serial) {}
    UNITY_BEGIN();

    RUN_TEST(test_lightsensor_basic_calls);
    delay(100);

    UNITY_END();
}

void loop() {}