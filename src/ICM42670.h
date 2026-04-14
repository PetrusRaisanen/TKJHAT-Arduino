#ifndef ICM42670_H
#define ICM42670_H

#include <Arduino.h>
#include <Wire.h>

/** 
 * @brief C++ class for the TDK InvenSense ICM-42670 6-axis accelerometer + gyroscope.
 * @details
 * Datasheet can be found at: https://invensense.tdk.com/wp-content/uploads/2021/07/DS-000451-ICM-42670-P-v1.0.pdf
 * Functions are based on TKJHAT C SDK with minimal modifications to fit Arduino style and the class structure.
 * 
 * The IMU is connected on I2C at @ref ICM42670_I2C_ADDRESS (0x69).
 *
 * **Recommended defaults**
 * - Accelerometer: ±@ref ICM42670_ACCEL_FSR_DEFAULT g at @ref ICM42670_ACCEL_ODR_DEFAULT Hz  
 *   (typically: ±4 g @ 100 Hz)
 * - Gyroscope:    ±@ref ICM42670_GYRO_FSR_DEFAULT dps at @ref ICM42670_GYRO_ODR_DEFAULT Hz  
 *   (typically: ±250 dps @ 100 Hz)
 *
 * **Modes**
 * - This SDK supports Low-Noise (LN) mode (higher precision, higher power).
 * - Other modes (LP/ULP/hybrid) are not implemented in this SDK.
 *
 * @pre The I2C interface must be initialized (use @ref init_i2c_default() or @ref init_hat_sdk()).
 * {@
 */

class ICM42670 {
public:

    /** @brief Construct a new ICM42670 object
     * Default constructor uses the default Wire I2C bus. You can also provide a custom TwoWire instance if needed.
     * 
     */
    ICM42670();                // default uses Wire
    ICM42670(TwoWire& w);      // optional I2C bus

    /** @brief Initialize the IMU
     * 
     * Performs a soft reset and verifies device identity (WHO_AM_I).
     * 
     * @return true on success, false on error.
     */
    bool begin();

    bool detectAddress();

    /** @brief Perform a soft reset of the IMU
     * 
     * This function sends the appropriate command to reset the device and waits for it to become ready again.
     * 
     * @return true on success, false on error.
     */
    bool reset();

    bool readWhoAmI(uint8_t& who);

    void calibrateAccel(float *dest1);
    void calibrateGyro(float *dest2);

    /** @brief Start the accelerometer
     * 
     * Configures the accelerometer with the requested ODR and FSR.
     *
     * @param odr_hz Desired output data rate in Hz (e.g., @ref ICM42670_ACCEL_ODR_DEFAULT).
     * @param fsr_g  Full-scale range in g (2, 4, 8, 16; e.g., @ref ICM42670_ACCEL_FSR_DEFAULT).
     * 
     * @return true on success, false on error.
     */
    bool startAccel(uint16_t odr_hz, uint16_t fsr_g);

    /** @brief Start the gyroscope
     * 
     * Configures the gyroscope with the requested ODR and FSR.
     *
     * @param odr_hz Desired output data rate in Hz (e.g., @ref ICM42670_GYRO_ODR_DEFAULT).
     * @param fsr_dps  Full-scale range in degrees per second (250, 500, 1000, 2000; e.g., @ref ICM42670_GYRO_FSR_DEFAULT).
     * 
     * @return true on success, false on error.
     */
    bool startGyro(uint16_t odr_hz, uint16_t fsr_dps);

    /** @brief Enable low-noise mode for both accelerometer and gyroscope
     * 
     * @return true on success, false on error.
     */
    bool readSensorData(float& ax, float& ay, float& az,
        float& gx, float& gy, float& gz, float& t);

    /** @brief Enable low-noise mode for both accelerometer and gyroscope
     * 
     * @return true on success, false on error.
     */
    bool enableAccelGyroLnMode(void);

    /** @brief Start IMU with SDK default settings and enable LN mode
     * 
     * Calls:
     * - ::startAccel(@ref ICM42670_ACCEL_ODR_DEFAULT,
     *                 @ref ICM42670_ACCEL_FSR_DEFAULT)
     * - ::startGyro (@ref ICM42670_GYRO_ODR_DEFAULT,
     *                 @ref ICM42670_GYRO_FSR_DEFAULT)
     * - ::enableAccelGyroLnMode()
     *
     * @pre Call ::begin() successfully before this function.
     *
     * @return true on success, false on error.
     */
    bool startWithDefaultValues(void);

    /** @brief Private member variables
     * 
        * - wire: Pointer to the TwoWire instance used for I2C communication.
        * - address: I2C address of the device (0x68 or 0x69).
        * - aRes: Accelerometer resolution in LSB/g, calculated based on the FSR setting.
        * - gRes: Gyroscope resolution in LSB/dps, calculated based on the FSR setting.
     * 
    */
private:
    TwoWire* wire;
    uint8_t address;
    float aRes;
    float gRes;

    bool readByte(uint8_t reg, uint8_t& value);
    bool readBytes(uint8_t reg, uint8_t* buffer, size_t len);
    bool writeByte(uint8_t reg, uint8_t value);
};

/**
 * @example ICM42670.ino
 * 
 * @}
 */

#endif