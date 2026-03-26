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

// This function reads the temperature from the sensor
// Temperature is 16-bit value, and we will read it as two bytes (low and high)
// This is because i2c works in 8-bit chunks
// When TEMP_LOW is read, the sensor will automatically update TEMP_HIGH with the corresponding high byte of the temperature measurement
float HDC2021:: readTemperature() {
    Wire.beginTransmission(HDC2021_I2C_ADDRESS);
    Wire.write(HDC2021_TEMP_LOW);
    Wire.endTransmission(false); // Keeps the connection active

    Wire.requestFrom(HDC2021_I2C_ADDRESS, (uint8_t)2); // Request 2 bytes (low and high)
    uint8_t low = Wire.read(); // Read the low byte of the temperature measurement and store it in a variable
    uint8_t high = Wire.read(); // Read the high byte of the temperature measurement and store it in a variable
    uint16_t temp = ((uint16_t)high << 8) | low; // Combine the high and low bytes to form a 16-bit temperature value
    return temp / 65536.0 * 165 - 40; // Convert the raw temp data into degrees celsius
}

// This function reads the humidity from the sensor
// Works similarly to the temperature reading, but with different registers and conversion formula
// Humidity is also a 16-bit value
float HDC2021::readHumidity() {
    Wire.beginTransmission(HDC2021_I2C_ADDRESS);
    Wire.write(HDC2021_HUMIDITY_LOW);
    Wire.endTransmission(false);

    Wire.requestFrom(HDC2021_I2C_ADDRESS, (uint8_t)2);
    uint8_t lowH = Wire.read();
    uint8_t highH = Wire.read();
    uint16_t humid = ((uint16_t)highH << 8) | lowH;
    return humid / 65536.0 * 100; // Convert the raw humidity data into percentage
}

// This function sets the low temperature threshold for the sensor's interrupt
void HDC2021::setLowTempThreshold(float temp) {
    temp = (temp < -40.0f) ? -40.0f : (temp > 125.0f) ? 125.0f : temp;
    uint8_t tempThresh = (uint8_t)((temp + 40.0f) * 256.0f / 165.0f);
    writeRegister(HDC2021_TEMP_THR_L, tempThresh);
}

// This function sets the high temperature threshold for the sensor's interrupt
void HDC2021::setHighTempThreshold(float temp) {
    temp = (temp < -40.0f) ? -40.0f : (temp > 125.0f) ? 125.0f : temp;
    uint8_t tempThresh = (uint8_t)((temp + 40.0f) * 256.0f / 165.0f);
    writeRegister(HDC2021_TEMP_THR_H, tempThresh);
}

// This function sets the low humidity threshold for the sensor's interrupt
void HDC2021::setLowHumidityThreshold(float humid) {
    humid = (humid < 0.0f) ? 0.0f : (humid > 100.0f) ? 100.0f : humid;
    uint8_t humidThresh = (uint8_t)(humid * 2.56f);
    writeRegister(HDC2021_HUMID_THR_L, humidThresh);
}

// This function sets the high humidity threshold for the sensor's interrupt
void HDC2021::setHighHumidityThreshold(float humid) {
    humid = (humid < 0.0f) ? 0.0f : (humid > 100.0f) ? 100.0f : humid;
    uint8_t humidThresh = (uint8_t)(humid * 2.56f);
    writeRegister(HDC2021_HUMID_THR_H, humidThresh);
}
