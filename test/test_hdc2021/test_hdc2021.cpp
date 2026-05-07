#include <Arduino.h>
#include <unity.h>
#include <Wire.h>
#include "HDC2021.h"
#include "pins.h"

HDC2021 hdc(DEFAULT_I2C_SDA_PIN, DEFAULT_I2C_SCL_PIN, HDC2021_INTERRUPT);

void setUp(void) {
    Wire.setSDA(DEFAULT_I2C_SDA_PIN);
    Wire.setSCL(DEFAULT_I2C_SCL_PIN);
    Wire.begin();
    
    hdc.begin();
}

void tearDown(void) {
}

// Read 8-bit register directly from HDC2021
static uint8_t readRegister8(uint8_t reg) {
    Wire.beginTransmission(HDC2021_I2C_ADDRESS);
    Wire.write(reg);
    Wire.endTransmission(false);

    Wire.requestFrom(HDC2021_I2C_ADDRESS, (uint8_t)1);
    if (!Wire.available()) return 0;

    return Wire.read();
}

// Read 16-bit register directly from HDC2021 (MSB -> LSB)
static uint16_t readRegister16(uint8_t reg) {
    Wire.beginTransmission(HDC2021_I2C_ADDRESS);
    Wire.write(reg);
    Wire.endTransmission(false);

    Wire.requestFrom(HDC2021_I2C_ADDRESS, (uint8_t)2);
    if (Wire.available() < 2) return 0;

    uint8_t msb = Wire.read();
    uint8_t lsb = Wire.read();

    return ((uint16_t)msb << 8) | lsb;
}

// Verify that the register values are set correctly after initialization
void testRate() {
    uint8_t cfg = readRegister8(HDC2021_CONFIG);
    TEST_ASSERT_EQUAL_HEX8(0x50, cfg & 0x70);
}

// Verify that the measurement mode is set to temperature and humidity (AMM=000)
void testMeasurementMode() {
    uint8_t cfg = readRegister8(HDC2021_MEASUREMENT_CONFIG);
    TEST_ASSERT_EQUAL_HEX8(0x00, cfg & 0x06);
}

// Verify that the temperature resolution is set to 14 bits (TM_RES=00)
void testTempRes() {
    uint8_t cfg = readRegister8(HDC2021_MEASUREMENT_CONFIG);
    TEST_ASSERT_EQUAL_HEX8(0x00, cfg & 0xC0);
}

// Verify that the humidity resolution is set to 14 bits (HM_RES=00)
void testHumidityRes() {
    uint8_t cfg = readRegister8(HDC2021_MEASUREMENT_CONFIG);
    TEST_ASSERT_EQUAL_HEX8(0x00, cfg & 0x30);
}

// Verify that the temperature reading is within the valid range of -40 to 125 °C
void testReadTemperature() {
    delay(1000); // Allow some time for the first measurement to be ready
    float t = hdc.readTemperature();
    TEST_ASSERT_TRUE(t > -40 && t < 125);
}

// Verify that the humidity reading is within the valid range of 0 to 100 %
void testReadHumidity() {
    delay(1000);
    float h = hdc.readHumidity();
    TEST_ASSERT_TRUE(h >= 0 && h <= 100);
}

// Verify that the stop function correctly disables measurements and puts the sensor into low-power state
void testStop() {
    hdc.begin();
    hdc.stop();

    uint8_t cfg = readRegister8(HDC2021_CONFIG);
    TEST_ASSERT_EQUAL_HEX8(0x00, cfg & 0x70);

    uint8_t meas = readRegister8(HDC2021_MEASUREMENT_CONFIG);
    TEST_ASSERT_EQUAL_HEX8(0x00, meas & 0x01);
}


void setup() {
    delay(1000);
    while (!Serial) {}
    UNITY_BEGIN();

    RUN_TEST(testRate);
    delay(100);

    RUN_TEST(testMeasurementMode);
    delay(100);

    RUN_TEST(testTempRes);
    delay(100);

    RUN_TEST(testHumidityRes);
    delay(100);

    RUN_TEST(testReadTemperature);
    delay(100);

    RUN_TEST(testReadHumidity);
    delay(100);

    RUN_TEST(testStop);
    delay(100);

    UNITY_END();
}

void loop() {}
