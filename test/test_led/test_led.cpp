#include <Arduino.h>
#include <unity.h>
#include "TKJHAT.h"

TKJHAT hat;

void setUp(void) {
    hat.begin();
}

void tearDown(void) {
}

void test_led_set_on() {
    hat.led.set(true);
    delay(10);
    TEST_ASSERT_EQUAL(HIGH, digitalRead(RED_LED_PIN));
}

void test_led_set_off() {
    hat.led.set(false);
    delay(10);
    TEST_ASSERT_EQUAL(LOW, digitalRead(RED_LED_PIN));
}

void setup() {
    delay(2000); 
    while(!Serial) {}
    UNITY_BEGIN();

    RUN_TEST(test_led_set_on);
    delay(200);
    RUN_TEST(test_led_set_off);
    delay(200);

    UNITY_END();
}

void loop() {}