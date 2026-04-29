#include <Arduino.h>
#include <unity.h>
#include "Led.h"
#include "pins.h"

Led led(RED_LED_PIN);

void setUp(void) {
    led.begin();
}

void tearDown(void) {
}

void testLedSetOn() {
    led.set(true);
    delay(10);
    TEST_ASSERT_EQUAL(HIGH, digitalRead(RED_LED_PIN));
}

void testLedSetOff() {
    led.set(false);
    delay(10);
    TEST_ASSERT_EQUAL(LOW, digitalRead(RED_LED_PIN));
}

void setup() {
    delay(1000); 
    while(!Serial) {}
    UNITY_BEGIN();

    RUN_TEST(testLedSetOn);
    delay(100);
    RUN_TEST(testLedSetOff);
    delay(100);

    UNITY_END();
}

void loop() {}