#include <Arduino.h>
#include <unity.h>
#include "TKJHAT.h"
#include "pins.h"

TKJHAT hat;

void setUp(void) {
    hat.begin();
}

void tearDown(void) {
}

// Test that write(255,0,0) turns on only the red LED channel (LOW = on, HIGH = off)
void testRgbLedWriteRed() {
    hat.rgbLed.write(255, 0, 0);
    delay(10);
    TEST_ASSERT_EQUAL(LOW, digitalRead(RGB_LED_R));
    TEST_ASSERT_EQUAL(HIGH, digitalRead(RGB_LED_G));
    TEST_ASSERT_EQUAL(HIGH, digitalRead(RGB_LED_B));
}

// Test that write(0,255,0) turns on only the green LED channel (LOW = on, HIGH = off)
void testRgbLedWriteGreen() {
    hat.rgbLed.write(0, 255, 0);
    delay(10);
    TEST_ASSERT_EQUAL(HIGH, digitalRead(RGB_LED_R));
    TEST_ASSERT_EQUAL(LOW, digitalRead(RGB_LED_G));
    TEST_ASSERT_EQUAL(HIGH, digitalRead(RGB_LED_B));
}

// Test that write(0,0,255) turns on only the blue LED channel (LOW = on, HIGH = off)
void testRgbLedWriteBlue() {
    hat.rgbLed.write(0, 0, 255);
    delay(10);
    TEST_ASSERT_EQUAL(HIGH, digitalRead(RGB_LED_R));
    TEST_ASSERT_EQUAL(HIGH, digitalRead(RGB_LED_G));
    TEST_ASSERT_EQUAL(LOW, digitalRead(RGB_LED_B));
}

// Test that stop() turns off all LED channels (HIGH = off)
void testRgbLedStop() {
    hat.rgbLed.stop();
    delay(10);
    TEST_ASSERT_EQUAL(HIGH, digitalRead(RGB_LED_R));
    TEST_ASSERT_EQUAL(HIGH, digitalRead(RGB_LED_G));
    TEST_ASSERT_EQUAL(HIGH, digitalRead(RGB_LED_B));
}

// Main function to run the tests
void setup() {
    delay(1000);
    while (!Serial) {}
    UNITY_BEGIN();

    RUN_TEST(testRgbLedWriteRed);
    delay(100);

    RUN_TEST(testRgbLedWriteGreen);
    delay(100);

    RUN_TEST(testRgbLedWriteBlue);
    delay(100);

    RUN_TEST(testRgbLedStop);
    delay(100);

    UNITY_END();
}

void loop() {}