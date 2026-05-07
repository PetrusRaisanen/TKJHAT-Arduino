#include "ICM42670.h"
#include "pins.h"
#include <Wire.h>
#include <unity.h>

ICM42670 imu;

void setUp(void) {
    // Initialize I2C communication
    Wire.setSDA(DEFAULT_I2C_SDA_PIN);
    Wire.setSCL(DEFAULT_I2C_SCL_PIN);
    Wire.begin();
}

void testDetectAddress() {
    // Test that the sensor is detected at the expected I2C address
    bool detected = imu.detectAddress();
    TEST_ASSERT_TRUE(detected);
}

void testReset() {
    // Test that the sensor can be reset successfully
    bool resetSuccessful = imu.reset();
    TEST_ASSERT_TRUE(resetSuccessful);
}

void testEnableLnMode() {
    // Test that low-noise mode can be enabled successfully
    bool lnModeEnabled = imu.enableAccelGyroLnMode();
    TEST_ASSERT_TRUE(lnModeEnabled);
}

void testStartWithDefaultValues() {
    // Test that the sensor can be started with default values successfully
    bool started = imu.startWithDefaultValues();
    TEST_ASSERT_TRUE(started);
}

void testStartAccel() {
    // Test that the accelerometer can be started with default ODR and FSR successfully
    bool accelStarted = imu.startAccel(ICM42670_ACCEL_ODR_DEFAULT, ICM42670_ACCEL_FSR_DEFAULT);
    TEST_ASSERT_TRUE(accelStarted);
}

void testStartGyro() {
    // Test that the gyroscope can be started with default ODR and FSR successfully
    bool gyroStarted = imu.startGyro(ICM42670_GYRO_ODR_DEFAULT, ICM42670_GYRO_FSR_DEFAULT);
    TEST_ASSERT_TRUE(gyroStarted);
}

void testStartAccelGyro() {
    // Test that both accelerometer and gyroscope can be started with default ODR and FSR successfully
    bool accelStarted = imu.startAccel(ICM42670_ACCEL_ODR_DEFAULT, ICM42670_ACCEL_FSR_DEFAULT);
    bool gyroStarted = imu.startGyro(ICM42670_GYRO_ODR_DEFAULT, ICM42670_GYRO_FSR_DEFAULT);
    TEST_ASSERT_TRUE(accelStarted);
    TEST_ASSERT_TRUE(gyroStarted);
}

void testReadSensorData() {
    // Test that sensor data can be read successfully and values are within reasonable ranges
    float ax, ay, az, gx, gy, gz, t;
    bool success = imu.readSensorData(ax, ay, az, gx, gy, gz, t);
    TEST_ASSERT_TRUE(success);
    // Check that the accelerometer values are within the expected range based on the FSR (±16g)
    // and that the gyroscope values are within the expected range based on the FSR (±2000 dps)
    TEST_ASSERT(ax > -16.0f && ax < 16.0f);
    TEST_ASSERT(ay > -16.0f && ay < 16.0f);
    TEST_ASSERT(az > -16.0f && az < 16.0f);
    TEST_ASSERT(gx > -2000.0f && gx < 2000.0f);
    TEST_ASSERT(gy > -2000.0f && gy < 2000.0f);
    TEST_ASSERT(gz > -2000.0f && gz < 2000.0f);
}

void setup() {
    delay(1000);
    while(!Serial) {}
    UNITY_BEGIN();

    RUN_TEST(testDetectAddress);
    delay(100);
    RUN_TEST(testReset);
    delay(100);
    RUN_TEST(testEnableLnMode);
    delay(100);
    RUN_TEST(testStartWithDefaultValues);
    delay(100);
    RUN_TEST(testStartAccel);
    delay(100);
    RUN_TEST(testStartGyro);
    delay(100);
    RUN_TEST(testStartAccelGyro);
    delay(100);
    RUN_TEST(testReadSensorData);
    delay(100);

    UNITY_END();
}

void loop() {}
