#include "Display.h"
#include "pins.h"
#include <unity.h>
#include <Wire.h>

Display display;

void setUp(void) {
    // Needs I2C initialization
    Wire.setSDA(DEFAULT_I2C_SDA_PIN);
    Wire.setSCL(DEFAULT_I2C_SCL_PIN);
    Wire.begin();

    display.begin();
}

void testDisplayWriteText() {
    // Test that writeText does not cause errors
    display.writeText("Hello, World!");
    TEST_ASSERT_TRUE(true); // If we reach this point without errors, the test passes
}

void testDisplayBasic() {

    display.begin();
    display.clear();
    display.writeText("Hello");
    display.drawLine(0, 0, 50, 50);

    TEST_ASSERT_TRUE(true);
}

void testDisplayCircleEdgeCases() {

    display.clear();
    display.drawCircle(10, 10, -1, false); // should do nothing
    display.drawCircle(10, 10, 0, false);  // single pixel
    display.drawCircle(0, 0, 100, false);  // out-of-bounds

    TEST_ASSERT_TRUE(true);
}

void setup() {
    delay(1000);
    while(!Serial) {}
    UNITY_BEGIN();

    RUN_TEST(testDisplayWriteText);
    delay(100);
    RUN_TEST(testDisplayBasic);
    delay(100);
    RUN_TEST(testDisplayCircleEdgeCases);
    delay(100);
    display.clear();
    UNITY_END();
}

void loop() {}