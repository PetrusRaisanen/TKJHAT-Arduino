#include <Arduino.h>
#include <unity.h>
#include "TKJHAT.h"

TKJHAT hat;

void setUp(void) {
    hat.begin();
}

void test_buzzer_play_tone() {
    // Test that playTone does not cause errors (functional testing of sound is not possible in unit tests)
    hat.buzzer.playTone(1000, 500); // Play a 1kHz tone for 500ms
    delay(600); // Wait for the tone to finish
    TEST_ASSERT_TRUE(true); // If we reach this point without errors, the test passes
}

void test_play_tone_ends_low() {
    hat.buzzer.playTone(1000, 10);
    TEST_ASSERT_EQUAL(LOW, digitalRead(BUZZER_PIN));
}

void setup() {
    delay(1000);
    while(!Serial) {}
    UNITY_BEGIN();

    RUN_TEST(test_buzzer_play_tone);
    delay(100);
    RUN_TEST(test_play_tone_ends_low);
    delay(100);

    UNITY_END();
}

void loop() {}
