#ifndef HDC2021_H
#define HDC2021_H

/** 
 * @brief A class for the Texas Instruments HDC2021 digital temperature and humidity sensor.
 *
 * @details
 * The HDC2021 is a low-power, high-accuracy sensor connected via I2C at
 * address @ref HDC2021_I2C_ADDRESS (0x40). It measures both temperature
 * and relative humidity with 14-bit resolution.
 *
 * Default connections:
 * | Signal | I2C Macro | GPIO | Description |
 * |---------|-----------|------|-------------|
 * | SDA | @ref DEFAULT_I2C_SDA_PIN | 12 | I2C data |
 * | SCL | @ref DEFAULT_I2C_SCL_PIN | 13 | I2C clock |
 * | Address | @ref HDC2021_I2C_ADDRESS | 0x40 | Sensor I2C address |
 * | Interrupt | @ref HDC2021_INTERRUPT | 21 | Optional alert pin |
 *
 * Default thresholds configured by @ref init_hdc2021_():
 * - Temperature low:  -30 °C  
 * - Temperature high: +50 °C  
 * - Humidity low:       0 %  
 * - Humidity high:    100 %  
 *
 * These thresholds are part of the sensor’s alert system.
 * 
 * @pre The I2C interface must be initialized (use @ref TKJHAT::begin() or @ref HDC2021::begin()).
 * 
 * @see Datasheet: https://www.ti.com/lit/ds/symlink/hdc2021.pdf  
 * @see Usage Guide: https://www.ti.com/lit/ug/snau250/snau250.pdf
 * {@
 */

#include <Arduino.h>
#include <Wire.h>
#include "pins.h"

class HDC2021 {
    private:
    uint8_t sdaPin;
    uint8_t sclPin;
    uint8_t interruptPin;

    uint8_t readRegister(uint8_t reg);
        void writeRegister(uint8_t reg, uint8_t value);
        void reset();
        void setMeasurementMode();
        void setRate();
        void setTempRes();
        void setHumidityRes();
        void triggerMeasurement();

    public:

    /** @brief Construct a new HDC2021 object with specified I2C pins and optional interrupt pin
     * 
     * @param sdaPin GPIO pin number for I2C SDA (default: @ref DEFAULT_I2C_SDA_PIN)
     * @param sclPin GPIO pin number for I2C SCL (default: @ref DEFAULT_I2C_SCL_PIN)
     * @param interruptPin GPIO pin number for optional alert interrupt (default: @ref HDC2021_INTERRUPT)
     */
    HDC2021(uint8_t sdaPin, uint8_t sclPin, uint8_t interruptPin);

    /**
     * @brief Initialize the HDC2021 sensor (@ref HDC2021_I2C_ADDRESS — 0x40).
     *
     * Performs a soft reset and configures the sensor for continuous
     * measurement mode with default thresholds and 1 Hz sampling rate:
     * - Resolution: 14 bits (temperature and humidity)
     * - Thresholds: -30 °C / +50 °C and 0 % / 100 %
     */

    void begin();
    
    /** @brief Set the low temperature threshold
     * 
     * @param temp Temperature threshold in degrees Celsius
     */
    void setLowTempThreshold(float temp);

    /** @brief Set the high temperature threshold
     * 
     * @param temp Temperature threshold in degrees Celsius
     */
    void setHighTempThreshold(float temp);

    /** @brief Set the low humidity threshold
     * 
     * @param humid Humidity threshold in percentage
     */
    void setLowHumidityThreshold(float humid);

    /** @brief Set the high humidity threshold
     * 
     * @param humid Humidity threshold in percentage
     */
    void setHighHumidityThreshold(float humid);

    /** @brief Read the current temperature in degrees Celsius
     * 
     * @return Temperature in degrees Celsius
     */
    float readTemperature();

    /** @brief Read the current relative humidity in percentage
     * 
     * @return Relative humidity in percentage
     */
    float readHumidity();

    /** @brief Stop the HDC2021 sensor
     * 
     * Puts the sensor into a low-power state and stops measurements.
     */
    void stop();
};

/** @example HDC2021.ino
 * 
 *@}
 */
#endif
