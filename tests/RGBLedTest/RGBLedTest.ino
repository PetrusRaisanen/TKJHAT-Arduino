#include <RGBLed.h>
#include <pins.h>

RGBLed rgbLed(RGB_LED_R, RGB_LED_G, RGB_LED_B);

int testsPassed = 0;
int testsFailed = 0;

void test(const char* testName, int expected, int actual) {
  if (expected == actual) {
    Serial.print("[PASS] ");
    Serial.println(testName);
    testsPassed++;
  } else {
    Serial.print("[FAIL] ");
    Serial.print(testName);
    Serial.print(" expected=");
    Serial.print(expected);
    Serial.print(" actual=");
    Serial.println(actual);
    testsFailed++;
  }
}

// This test test tests if the red channel of the RGB LED returns HIGH (off)
void testRedReturnsHigh() {
  rgbLed.write(0, 255, 255);
  delay(10);
  test("Red channel returns HIGH when pwm is 255", HIGH, digitalRead(RGB_LED_R));
}

// This test test tests if the green channel of the RGB LED returns HIGH (off)
void testGreenReturnsHigh() {
  rgbLed.write(255, 0, 255);
  delay(10);
  test("Green channel returns HIGH when pwm is 255", HIGH, digitalRead(RGB_LED_G));
}

// This test test tests if the blue channel of the RGB LED returns HIGH (off)
void testBlueReturnsHigh() {
  rgbLed.write(255, 255, 0);
  delay(10);
  test("Blue channel returns HIGH when pwm is 255", HIGH, digitalRead(RGB_LED_B));
}

// This test tests if the red channel of the RGB LED returns LOW (on)
void testRedReturnsLow() {
  rgbLed.write(255, 0, 0);
  delay(10);
  test("Red channel returns LOW when pwm is 0", LOW, digitalRead(RGB_LED_R));
}

// This test tests if the green channel of the RGB LED returns LOW (on)
void testGreenReturnsLow() {
  rgbLed.write(0, 255, 0);
  delay(10);
  test("Green channel returns LOW when pwm is 0", LOW, digitalRead(RGB_LED_G));
}

// This test tests if the blue channel of the RGB LED returns LOW (on)
void testBlueReturnsLow() {  
  rgbLed.write(0, 0, 255);
  delay(10);
  test("Blue channel returns LOW when pwm is 0", LOW, digitalRead(RGB_LED_B));
}

void setup() {
  Serial.begin(115200);
  delay(2000);

  Serial.println("Starting RGBLED tests...");
  rgbLed.begin();

    testRedReturnsHigh();
    testGreenReturnsHigh();
    testBlueReturnsHigh();
    testRedReturnsLow();
    testGreenReturnsLow();
    testBlueReturnsLow();

  Serial.println();
  Serial.print("Passed: ");
  Serial.println(testsPassed);
  Serial.print("Failed: ");
  Serial.println(testsFailed);
}

void loop() {
}
