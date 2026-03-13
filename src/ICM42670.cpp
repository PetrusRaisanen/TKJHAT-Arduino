#include "ICM42670.h"
#include "pins.h"
#include <Arduino.h>

ICM42670::ICM42670()
    : wire(&Wire), address(0) {
}

ICM42670::ICM42670(TwoWire& w)
    : wire(&w), address(0) {
}

// Write a single byte to a register
bool ICM42670::writeByte(uint8_t reg, uint8_t value) {
    wire->beginTransmission(address); // start communication with the sensor at the address
    wire->write(reg); // write the register address
    wire->write(value); // write the value to the register
    return wire->endTransmission() == 0; // success if 0
}

// Read a single byte from a register
bool ICM42670::readByte(uint8_t reg, uint8_t& value) {
    wire->beginTransmission(address);
    wire->write(reg);
    if (wire->endTransmission(false) != 0) { // Stop = false, we want to keep the connection active for reading
        return false;
    }
    if (wire->requestFrom(address, (uint8_t)1) != 1) { // should request 1 byte
        return false;
    }
    value = wire->read(); // read the byte
    return true;
}

// Read multiple bytes starting from a register
bool ICM42670::readBytes(uint8_t reg, uint8_t* buffer, size_t len) {
    wire->beginTransmission(address);
    wire->write(reg);
    if (wire->endTransmission(false) != 0) {
        return false;
    }
    if (wire->requestFrom(address, (uint8_t)len) != len) {
        return false;
    }
    for (size_t i = 0; i < len; ++i) {
        buffer[i] = wire->read();
    }
    return true;
}

// Address detection
bool ICM42670::detectAddress() {
    uint8_t who = 0;
    if (!readByte(ICM42670_REG_WHO_AM_I, who)) {
        return false;
    }
    return who == ICM42670_WHO_AM_I_RESPONSE;
}

// Initialization
bool ICM42670::begin() {

    reset(); // Soft reset

    if (detectAddress()) {
        address = ICM42670_I2C_ADDRESS;
        return true;
    }
    return false;
}

// Reset the sensor
bool ICM42670::reset() {
    return writeByte(ICM42670_REG_SIGNAL_PATH_RESET, ICM42670_RESET_CONFIG_BITS); // SIGNAL_PATH_RESET register, reset command
}

// Read WHO_AM_I register
bool ICM42670::readWhoAmI(uint8_t& who) {
    return readByte(ICM42670_REG_WHO_AM_I, who); // reads the WHO_AM_I register into given parameter
}

// Get the detected I2C address
uint8_t ICM42670::getAddress() const {
    return address;
}

// bool ICM42670::startAccel(uint16_t rate, uint16_t range) {}

// bool ICM42670::startGyro(uint16_t rate, uint16_t range) {}

// bol ICM42670::readSensorData(float& ax, float& ay, float& az,
//     float& gx, float& gy, float& gz, float& t) {}



