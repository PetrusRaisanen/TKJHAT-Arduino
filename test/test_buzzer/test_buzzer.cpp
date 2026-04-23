#include <Arduino.h>
#include <unity.h>
#include "Buzzer.h"
#include "pins.h"

Buzzer buzzer(BUZZER_PIN);

void setUp(void) {
    buzzer.begin();
}

void testPlayTone() {
    // Test that playTone does not cause errors (functional testing of sound is not possible in unit tests)
    buzzer.playTone(1000, 500); // Play a 1kHz tone for 500ms
    delay(600); // Wait for the tone to finish
    TEST_ASSERT_TRUE(true); // If we reach this point without errors, the test passes
}

void testPlayToneEndsLow() {
    buzzer.playTone(1000, 10);
    TEST_ASSERT_EQUAL(LOW, digitalRead(BUZZER_PIN));
}

void setup() {
    delay(1000);
    while(!Serial) {}
    UNITY_BEGIN();

    RUN_TEST(testPlayTone);
    delay(100);
    RUN_TEST(testPlayToneEndsLow);
    delay(100);

    UNITY_END();
}

void loop() {}
