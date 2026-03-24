#include "HDC2021.h"

// Constructor initializes I2C pins and interrupt pin
HDC2021::HDC2021(uint8_t sdaPin, uint8_t sclPin, uint8_t interruptPin) {
    this->sdaPin = sdaPin;
    this->sclPin = sclPin;
    this->interruptPin = interruptPin;
}

// Sensor initialization
void HDC2021::begin() {
    Wire.setSDA(sdaPin);
    Wire.setSCL(sclPin);
    Wire.begin();
    pinMode(interruptPin, INPUT);

    reset();
    setHighTempThreshold(50);
    setLowTempThreshold(-30);
    setHighHumidityThreshold(100);
    setLowHumidityThreshold(0);
    setMeasurementMode();
    setRate();
    setTempRes();
    setHumidityRes();
    triggerMeasurement();
}

// This function is called to stop the sensor
void HDC2021::stop() {
    uint8_t cfg = readRegister(HDC2021_CONFIG);  // 0x0E
    cfg &= 0x8F;  // clear AMM[2:0] (bits 6:4) -> 000 = AMM disabled
    writeRegister(HDC2021_CONFIG, cfg);
    // Make sure we don't accidentally retrigger
    uint8_t meas = readRegister(HDC2021_MEASUREMENT_CONFIG); // 0x0F
    meas &= (uint8_t)~0x01; // clear MEAS_TRIG (bit 0)
    writeRegister(HDC2021_MEASUREMENT_CONFIG, meas);
    //turn heater & DRDY pin off to minimize current
    cfg &= ~(uint8_t)(1<<3); // HEAT_EN=0
    cfg &= ~(uint8_t)(1<<2); // DRDY/INT_EN=0 (pin Hi-Z)
    writeRegister(HDC2021_CONFIG, cfg);
}

// This function reads a byte from the specified register
uint8_t HDC2021::readRegister(uint8_t reg) {
    Wire.beginTransmission(HDC2021_I2C_ADDRESS);
    Wire.write(reg);
    Wire.endTransmission(false);
    Wire.requestFrom(HDC2021_I2C_ADDRESS, (uint8_t)1);
    return Wire.read();
}

// This function writes a byte to the specified register
void HDC2021::writeRegister(uint8_t reg, uint8_t value) {
    Wire.beginTransmission(HDC2021_I2C_ADDRESS);
    Wire.write(reg);
    Wire.write(value);
    Wire.endTransmission();
}

// This function resets the sensor to its default state
void HDC2021::reset() {
    uint8_t cfg = readRegister(HDC2021_CONFIG);
    writeRegister(HDC2021_CONFIG, cfg | 0x80);
    delay(50);
}

// This function sets the measurement mode to temperature and humidity
void HDC2021::setMeasurementMode() {
    uint8_t cfg = readRegister(HDC2021_MEASUREMENT_CONFIG);
    writeRegister(HDC2021_MEASUREMENT_CONFIG, cfg & 0xF9);
}

// This function sets the sampling rate to 1 measurement per second
void HDC2021::setRate() {
    uint8_t cfg = readRegister(HDC2021_CONFIG);
    cfg = (cfg & 0x8F) | 0x50; // Set 1 measurement/second
    writeRegister(HDC2021_CONFIG, cfg);
}

// This function sets the temperature resolution to 14 bits
void HDC2021::setTempRes() {
    uint8_t cfg = readRegister(HDC2021_MEASUREMENT_CONFIG);
    writeRegister(HDC2021_MEASUREMENT_CONFIG, cfg & 0x3F); // 14-bit
}

// This function sets the humidity resolution to 14 bits
void HDC2021::setHumidityRes() {
    uint8_t cfg = readRegister(HDC2021_MEASUREMENT_CONFIG);
    writeRegister(HDC2021_MEASUREMENT_CONFIG, cfg & 0xCF); // 14-bit
}

// This function triggers a measurement
void HDC2021::triggerMeasurement() {
    uint8_t cfg = readRegister(HDC2021_MEASUREMENT_CONFIG);
    writeRegister(HDC2021_MEASUREMENT_CONFIG, cfg | 0x01);
}


float HDC2021:: readTemperature() {

}


float HDC2021::readHumidity() {

}


void HDC2021::setLowTempThreshold(float temp) {

}


void HDC2021::setHighTempThreshold(float temp) {

}


void HDC2021::setLowHumidityThreshold(float humid) {

}


void HDC2021::setHighHumidityThreshold(float humid) {

}
