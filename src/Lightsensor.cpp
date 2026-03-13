#include "Lightsensor.h"
#include "pins.h"
#include <math.h>

// Constructor
LightSensor::LightSensor(uint8_t sdapin, uint8_t sclpin) {
    this->sdapin = sdapin;
    this->sclpin = sclpin;
}

// Initialize the sensor
static void init_veml6030() {

    uint8_t config[3] = {
        VEML6030_CONFIG_REG,
        0x00,
        0x10
    };

    Wire.beginTransmission(VEML6030_I2C_ADDR);
    Wire.write(config, 3);
    Wire.endTransmission();

    delay(10);
}

// Read light level from VEML6030
// Light in LUX
static uint32_t veml6030_read_light() {
    Wire.beginTransmission(VEML6030_I2C_ADDR);
    Wire.write(VEML6030_ALS_REG);
    Wire.endTransmission(false);

    Wire.requestFrom(VEML6030_I2C_ADDR, (uint8_t)2);
    if (Wire.available() < 2) {
        return 0;
    }
    uint8_t lsb = Wire.read();
    uint8_t msb = Wire.read();

    uint16_t lightbits = ((uint16_t)lsb) | ((uint16_t)msb << 8);
    uint32_t luxVal_uncorrected = lightbits * 0.5376;

    if (luxVal_uncorrected > 1000) {
        uint32_t luxVal = (.00000000000060135 * (pow(luxVal_uncorrected, 4))) - 
                            (.0000000093924 * (pow(luxVal_uncorrected, 3))) + 
                            (.000081488 * (pow(luxVal_uncorrected, 2))) + 
                            (1.0023 * luxVal_uncorrected);
        return luxVal;
    }
    return luxVal_uncorrected;
    }

// Stop the sensor
static void veml6030_stop() {

    uint8_t config[3] = {
        VEML6030_CONFIG_REG,  // Configuration register (0x00)
        0x00,                 // High byte
        0x11                  // Low byte: shutdown bit = 1
    };

    Wire.beginTransmission(VEML6030_I2C_ADDR);
    Wire.write(config, 3);
    Wire.endTransmission();

    delay(10);
}

// Public methods

void LightSensor::begin() {
    Wire.setSDA(this->sdapin);
    Wire.setSCL(this->sclpin);
    Wire.begin();
    init_veml6030();
}

uint32_t LightSensor::readLight() {
    return veml6030_read_light();
}

void LightSensor::stop() {
    veml6030_stop();
}
