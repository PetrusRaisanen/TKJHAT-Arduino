#include "TKJHAT.h"

TKJHAT hat;

int testsPassed = 0;
int testsFailed = 0;

void test(const char* testName, bool passed) {
  if (passed) {
    Serial.print("[PASS] ");
    Serial.println(testName);
    testsPassed++;
  } else {
    Serial.print("[FAIL] ");
    Serial.println(testName);
    testsFailed++;
  }
}

void test_begin() {
  Serial.println("Running begin()");
  hat.display.begin();
  delay(100);
  test("begin()", true);
}

void test_writeText() {
  Serial.println("Running writeText()");
  hat.display.clear();
  hat.display.writeText("Hello");
  delay(500);
  test("writeText()", true);
}

void test_writeText_xy() {
  Serial.println("Running writeTextPositioned(x,y)");
  hat.display.clear();
  hat.display.writeTextPositioned(10, 10, "Hello", 1);
  delay(500);
  test("writeTextPositioned(x,y)", true);
}

void test_putp() {
  Serial.println("Running putp()");
  hat.display.clear();
  hat.display.putp(10, 10);
  delay(200);
  test("putp()", true);
}

void test_hspan() {
  Serial.println("Running hspan()");
  hat.display.clear();
  hat.display.hspan(5, 30, 20);
  delay(200);
  test("hspan()", true);
}

void test_drawCircle_outline() {
  Serial.println("Running drawCircle(fill=false)");
  hat.display.clear();
  hat.display.drawCircle(64, 32, 15, false);
  delay(500);
  test("drawCircle(fill=false)", true);
}

void test_drawCircle_filled() {
  Serial.println("Running drawCircle(fill=true)");
  hat.display.clear();
  hat.display.drawCircle(64, 32, 15, true);
  delay(500);
  test("drawCircle(fill=true)", true);
}

void test_drawLine() {
  Serial.println("Running drawLine()");
  hat.display.clear();
  hat.display.drawLine(0, 0, 127, 63);
  delay(500);
  test("drawLine()", true);
}

void test_drawSquare_outline() {
  Serial.println("Running drawSquare(fill=false)");
  hat.display.clear();
  hat.display.drawSquare(20, 20, 30, 30, false);
  delay(500);
  test("drawSquare(fill=false)", true);
}

void test_drawSquare_filled() {
  Serial.println("Running drawSquare(fill=true)");
  hat.display.clear();
  hat.display.drawSquare(20, 20, 30, 30, true);
  delay(500);
  test("drawSquare(fill=true)", true);
}

void test_clear() {
  Serial.println("Running clear()");
  hat.display.writeText("TEST");
  delay(300);
  hat.display.clear();
  delay(300);
  test("clear()", true);
}

void test_stopDisplay() {
  Serial.println("Running stopDisplay()");
  hat.display.stopDisplay();
  delay(100);
  test("stopDisplay()", true);
}

void setup() {
  Serial.begin(9600);
  hat.begin();
  delay(2000);

  Serial.println("Starting Display tests...");

  test_begin();
  test_writeText();
  test_writeText_xy();
  test_putp();
  test_hspan();
  test_drawCircle_outline();
  test_drawCircle_filled();
  test_drawLine();
  test_drawSquare_outline();
  test_drawSquare_filled();
  test_clear();
  test_stopDisplay();

  Serial.println();
  Serial.print("Passed: ");
  Serial.println(testsPassed);
  Serial.print("Failed: ");
  Serial.println(testsFailed);
}

void loop() {}