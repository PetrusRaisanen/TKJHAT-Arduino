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
    // Test that the LED can be turned on successfully
    led.set(true);
    delay(10);
    TEST_ASSERT_EQUAL(HIGH, digitalRead(RED_LED_PIN));
}

void testLedSetOff() {
    // Ensure the LED is on before testing that it can be turned off
    led.set(false);
    delay(10);
    TEST_ASSERT_EQUAL(LOW, digitalRead(RED_LED_PIN));
}

void testLedToggle() {
    // Test that toggling the LED changes its state
    bool initialState = digitalRead(RED_LED_PIN);
    led.toggle();
    delay(10);
    TEST_ASSERT_EQUAL(!initialState, digitalRead(RED_LED_PIN));
    led.toggle();
    delay(10);
    TEST_ASSERT_EQUAL(initialState, digitalRead(RED_LED_PIN));
}

void setup() {
    delay(1000); 
    while(!Serial) {}
    UNITY_BEGIN();

    RUN_TEST(testLedSetOn);
    delay(100);
    RUN_TEST(testLedSetOff);
    delay(100);
    RUN_TEST(testLedToggle);
    delay(100);

    UNITY_END();
}

void loop() {}