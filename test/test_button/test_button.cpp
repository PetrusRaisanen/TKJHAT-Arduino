#include <Arduino.h>
#include <unity.h>
#include "Button.h"
#include "pins.h"

Button button1(SW1_PIN);
Button button2(SW2_PIN);

void setUp(void) {
    button1.begin();
    button2.begin();
}

void testButtonsNotPressed() {
    TEST_ASSERT_FALSE(button1.isPressed());
    TEST_ASSERT_FALSE(button2.isPressed());
}

void setup() {
    delay(1000);
    while(!Serial) {}
    UNITY_BEGIN();

    RUN_TEST(testButtonsNotPressed);
    delay(100);

    UNITY_END();
}

void loop() {}