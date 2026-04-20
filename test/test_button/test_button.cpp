#include <Arduino.h>
#include <unity.h>
#include "TKJHAT.h"

TKJHAT hat;

void setUp(void) {
    hat.begin();
}

void test_button_not_pressed() {
    TEST_ASSERT_FALSE(hat.button1.isPressed());
}

void setup() {
    delay(1000);
    while(!Serial) {}
    UNITY_BEGIN();

    RUN_TEST(test_button_not_pressed);
    delay(100);

    UNITY_END();
}

void loop() {}