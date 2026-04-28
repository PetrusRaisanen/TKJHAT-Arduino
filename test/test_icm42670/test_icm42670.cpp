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
    bool detected = imu.detectAddress();
    TEST_ASSERT_TRUE(detected);
}

void testReset() {
    bool resetSuccessful = imu.reset();
    TEST_ASSERT_TRUE(resetSuccessful);
}

void testEnableLnMode() {
    bool lnModeEnabled = imu.enableAccelGyroLnMode();
    TEST_ASSERT_TRUE(lnModeEnabled);
}

void testStartWithDefaultValues() {
    bool started = imu.startWithDefaultValues();
    TEST_ASSERT_TRUE(started);
}

void testStartAccel() {
    bool accelStarted = imu.startAccel(ICM42670_ACCEL_ODR_DEFAULT, ICM42670_ACCEL_FSR_DEFAULT);
    TEST_ASSERT_TRUE(accelStarted);
}

void testStartGyro() {
    bool gyroStarted = imu.startGyro(ICM42670_GYRO_ODR_DEFAULT, ICM42670_GYRO_FSR_DEFAULT);
    TEST_ASSERT_TRUE(gyroStarted);
}

void testStartAccelGyro() {
    bool accelStarted = imu.startAccel(ICM42670_ACCEL_ODR_DEFAULT, ICM42670_ACCEL_FSR_DEFAULT);
    bool gyroStarted = imu.startGyro(ICM42670_GYRO_ODR_DEFAULT, ICM42670_GYRO_FSR_DEFAULT);
    TEST_ASSERT_TRUE(accelStarted);
    TEST_ASSERT_TRUE(gyroStarted);
}

void testReadSensorData() {
    float ax, ay, az, gx, gy, gz, t;
    bool success = imu.readSensorData(ax, ay, az, gx, gy, gz, t);
    TEST_ASSERT_TRUE(success);
    // We can't assert specific values since it depends on the environment,
    // but we can check that the values are within reasonable ranges.
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
