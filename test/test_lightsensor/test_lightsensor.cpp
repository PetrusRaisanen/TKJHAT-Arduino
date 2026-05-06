#include <Arduino.h>
#include <unity.h>
#include <Wire.h>
#include "LightSensor.h"
#include "pins.h"

LightSensor lightSensor(DEFAULT_I2C_SDA_PIN, DEFAULT_I2C_SCL_PIN);

void setUp(void) {
    // Initialize I2C communication
    Wire.setSDA(DEFAULT_I2C_SDA_PIN);
    Wire.setSCL(DEFAULT_I2C_SCL_PIN);
    Wire.begin();
    
    lightSensor.begin();
}

void tearDown(void) {
}

// Helper function to read a 16-bit register value from the sensor
static uint16_t readRegister(uint8_t reg) {
    Wire.beginTransmission(VEML6030_I2C_ADDR);
    Wire.write(reg);
    Wire.endTransmission(false);

    Wire.requestFrom(VEML6030_I2C_ADDR, (uint8_t)2);
    if (Wire.available() < 2) {
        return 0; // error case
    }

    uint8_t msb = Wire.read();
    uint8_t lsb = Wire.read();

    return (uint16_t)lsb | ((uint16_t)msb << 8);
}

// Test that the sensor is initialized with the expected configuration
void testInitConfig() {
    uint16_t config = readRegister(VEML6030_CONFIG_REG);
    TEST_ASSERT_EQUAL_HEX16(0x0010, config);
}

// Test that the lux value is reasonable
void testFormat() {
    uint32_t lux = lightSensor.readLight();
// VEML6030 has a maximum measurable illuminance of around 120,000-140,000 lux, so 140 000 is safe upper bound for testing
    TEST_ASSERT_TRUE(lux >= 0);
    TEST_ASSERT_TRUE(lux < 140000);
}

// Test that multiple consecutive reads return values in a reasonable range
void testMultipleReads() {
    for (int i = 0; i < 10; i++) {
        uint32_t lux = lightSensor.readLight();
        TEST_ASSERT_TRUE(lux < 200000);
        delay(50);
    }
}

// Test that stop() puts the sensor in shutdown mode
void testStop() {
    lightSensor.stop();
    uint16_t config = readRegister(VEML6030_CONFIG_REG);
    TEST_ASSERT_EQUAL_HEX16(0x0011, config);
}

void setup() {
    delay(1000);
    while (!Serial) {}
    UNITY_BEGIN();

    RUN_TEST(testInitConfig);
    delay(100);

    RUN_TEST(testFormat);
    delay(100);

    RUN_TEST(testMultipleReads);
    delay(100);

    RUN_TEST(testStop);
    delay(100);

    UNITY_END();
}

void loop() {}
