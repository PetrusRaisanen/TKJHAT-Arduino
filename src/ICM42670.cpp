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
    if (wire->requestFrom(address, (uint8_t)len) != len) { // now we want to read 'len' bytes
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
    if (!readByte(ICM42670_REG_WHO_AM_I, who)) { // try to read the WHO_AM_I register
        return false;
    }
    return who == ICM42670_WHO_AM_I_RESPONSE;
}

// Initialization
bool ICM42670::begin() {

    reset();  // Soft reset

    // Detect I2C address
    if (!detectAddress()) {
        return false;
    }

    // Check WHO_AM_I
    uint8_t who = 0;
    if (!readByte(ICM42670_REG_WHO_AM_I, who)) {
        return false;
    }
    if (who != ICM42670_WHO_AM_I_RESPONSE) {
        return false;
    } 
    delay(1); // Short delay after reset and detection
    return true;
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

// Start accelerometer with specified ODR and FSR
bool ICM42670::startAccel(uint16_t odr_hz, uint16_t fsr_g) {
    uint8_t fsr_bits = 0;
    uint8_t odr_bits = 0;

    // Map FSR to register bits, aRes (See Datasheet Table 2)
    switch (fsr_g) {
        case 2:  
            fsr_bits = ICM42670_ACCEL_FSR_2G;
            aRes = 16384; 
            break;
        case 4:  
            fsr_bits = ICM42670_ACCEL_FSR_4G;
            aRes = 8192;
            break;
        case 8:  
            fsr_bits = ICM42670_ACCEL_FSR_8G; 
            aRes =4096;
            break;
        case 16: 
            fsr_bits = ICM42670_ACCEL_FSR_16G;
            aRes = 2048;
            break;
        default: return -1; // invalid FSR
    }

    // Map ODR to register bits
    switch (odr_hz) {
        case 25:   odr_bits = ICM42670_ACCEL_ODR_25HZ; break;
        case 50:   odr_bits = ICM42670_ACCEL_ODR_50HZ; break;
        case 100:  odr_bits = ICM42670_ACCEL_ODR_100HZ; break;
        case 200:  odr_bits = ICM42670_ACCEL_ODR_200HZ; break;
        case 400:  odr_bits = ICM42670_ACCEL_ODR_400HZ; break;
        case 800:  odr_bits = ICM42670_ACCEL_ODR_800HZ; break;
        case 1600: odr_bits = ICM42670_ACCEL_ODR_1600HZ; break;
        default:   return -2; // invalid ODR
    }

    // Combine into ACCEL_CONFIG0: [7:5] = fsr, [3:0] = odr
    uint8_t accel_config0_val = (fsr_bits << 5) | (odr_bits & 0x0F);
    int rc = writeByte(ICM42670_ACCEL_CONFIG0_REG, accel_config0_val);
    delay(1); 
    if (!rc) return false;
    return true; // success
}

// Start gyroscope with specified ODR and FSR
bool ICM42670::startGyro(uint16_t odr_hz, uint16_t fsr_dps) {
    uint8_t fsr_bits = 0;
    uint8_t odr_bits = 0;
 
    // Map FSR, gRes
    switch (fsr_dps) {
        case 250:  
            fsr_bits = 0x03;
            gRes = 131; 
            break;
        case 500:  
            fsr_bits = 0x02;
            gRes = 65.5;
            break;
        case 1000: 
            fsr_bits = 0x01;
            gRes = 32.8;
            break;
        case 2000: 
            fsr_bits = 0x00;
            gRes = 16.4;
            break;
        default:   return -1;
    }

    // Map ODR
    switch (odr_hz) {
        case 25:   odr_bits = 0x0B; break;
        case 50:   odr_bits = 0x0A; break;
        case 100:  odr_bits = 0x09; break;
        case 200:  odr_bits = 0x08; break;
        case 400:  odr_bits = 0x07; break;
        case 800:  odr_bits = 0x06; break;
        case 1600: odr_bits = 0x05; break;
        default:   return -2;
    }

    // Write GYRO_CONFIG0
    uint8_t gyro_config0_val = (fsr_bits << 5) | (odr_bits & 0x0F);
    if (!writeByte(ICM42670_GYRO_CONFIG0_REG, gyro_config0_val)) return false;
    delay(1);
    return true;
}

// Enable low-noise (LN) mode for both accelerometer and gyroscope.
bool ICM42670::enableAccelGyroLNMode() {
    bool rc = writeByte(ICM42670_PWR_MGMT0_REG , 0x0F); // bits 3:2 = gyro LN, bits 1:0 = accel LN
    delay(1);
    return rc;
}

// Start IMU with default values and enable LN mode.
bool ICM42670::startWithDefaultValues() {
    bool rc;

    // Put both sensors into Low-Noise mode
    rc = enableAccelGyroLNMode();
    if (!rc) return false;

    // Start accelerometer with defaults
    rc = startAccel(ICM42670_ACCEL_ODR_DEFAULT, ICM42670_ACCEL_FSR_DEFAULT);
    if (!rc) return false;

    // Start gyroscope with defaults 
    rc = startGyro(ICM42670_GYRO_ODR_DEFAULT, ICM42670_GYRO_FSR_DEFAULT);
    if (!rc) return false;

    return true;
}

bool ICM42670::readSensorData(float& ax, float& ay, float& az,
    float& gx, float& gy, float& gz, float& t) {

        uint8_t raw[14]; // 14 bytes total from TEMP to GYRO Z

        if (!readBytes(ICM42670_SENSOR_DATA_START_REG, raw, sizeof(raw))) {
            return false;
        }

        // Convert to signed 16-bit integers (big-endian)
        int16_t t_raw = (int16_t)((raw[0] << 8) | raw[1]);
        int16_t ax_raw = ((int16_t)raw[2] << 8) | raw[3];
        int16_t ay_raw = ((int16_t)raw[4] << 8) | raw[5];
        int16_t az_raw = ((int16_t)raw[6] << 8) | raw[7];
        int16_t gx_raw = (int16_t)((raw[8] << 8) | raw[9]);
        int16_t gy_raw = (int16_t)((raw[10] << 8) | raw[11]);
        int16_t gz_raw = (int16_t)((raw[12] << 8) | raw[13]);

        ax = (float)ax_raw / aRes;
        ay = (float)ay_raw / aRes;
        az = (float)az_raw / aRes;
        gx = (float)gx_raw / gRes;
        gy = (float)gy_raw / gRes;
        gz = (float)gz_raw / gRes;
        t  = ((float)t_raw / 128.0f) + 25.0f;
        return 0; // success
    }

// void ICM42670::calibrateAccel(float *dest1){}

// void ICM42670::calibrateGyro(float *dest2){}


