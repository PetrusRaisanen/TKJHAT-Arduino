#ifndef TKJHAT_LIGHTSENSOR_H
#define TKJHAT_LIGHTSENSOR_H

#include <Arduino.h>
#include <Wire.h>

 /**
 * @brief A class to configure and read the Vishay VEML6030 ambient light sensor.
 *
 * @details
 * The VEML6030 is a high-sensitivity ambient light sensor connected
 * through the I2C bus at address @ref VEML6030_I2C_ADDR (0x10).
 * It provides a 16-bit dynamic range and adjustable gain and
 * integration time for accurate lux readings.
 *
 * Default connections:
 * | Signal | I2C Macro | GPIO | Description |
 * |---------|-----------|------|-------------|
 * | SDA | @ref DEFAULT_I2C_SDA_PIN | 12 | I2C data |
 * | SCL | @ref DEFAULT_I2C_SCL_PIN | 13 | I2C clock |
 * | Address | @ref VEML6030_I2C_ADDR | 0x10 | Light sensor I2C address |
 * | Interrupt | @ref VEML6030_INTERRUPT | 9 | Optional interrupt output |
 *
 * @pre The I2C interface must be initialized (use @ref TKJHAT::begin()).
 *
 * @see SparkFun Guide: https://learn.sparkfun.com/tutorials/qwiic-ambient-light-sensor-veml6030-hookup-guide/all#arduino-library  
 * @see Application Note: https://www.vishay.com/docs/84367/designingveml6030.pdf  
 * @see Datasheet: https://www.vishay.com/docs/84366/veml6030.pdf
 * 
 * {@
 */


class LightSensor {
    private:
        uint8_t sdapin;
        uint8_t sclpin;

    public:

    /** @brief Construct a new LightSensor object
     * @param sdapin GPIO pin connected to the I2C SDA line (default: GPIO 12)
     * @param sclpin GPIO pin connected to the I2C SCL line (default: GPIO 13)
     *  
     */
        LightSensor(uint8_t sdapin, uint8_t sclpin);

        /** @brief Initialize the VEML6030 light sensor
         * 
         * Configures the sensor with default parameters:
         * - Gain: 1/8  
         * - Integration time: 100 ms  
         * - Power: ON  
         * - Interrupts: disabled
         *
         * @pre Call @ref TKJHAT::begin() before this function.
         */
        void begin();

        /** @brief Read the current light level in lux
         * 
         * @return The ambient light level in lux, or a negative value on error.
         */
        uint32_t readLight();

        /** @brief Stop the sensor
         * 
         * Powers down the sensor to save energy. The sensor will not respond to read commands until re-initialized.
         */
        void stop();
};

/** @example Lightsensor.ino
 * 
 *@}
 */
#endif
