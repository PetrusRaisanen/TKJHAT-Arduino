#ifndef ICM42670_H
#define ICM42670_H

#include <Arduino.h>
#include <Wire.h>

class ICM42670 {
public:
    ICM42670();                // default uses Wire
    ICM42670(TwoWire& w);      // optional I2C bus

    bool begin();
    bool detectAddress();
    bool reset();
    bool readWhoAmI(uint8_t& who);

    uint8_t getAddress() const;

    // bool startAccel(uint16_t rate, uint16_t range);
    // bool startGyro(uint16_t rate, uint16_t range);

    // bool readSensorData(float& ax, float& ay, float& az,
    //     float& gx, float& gy, float& gz, float& t);



private:
    TwoWire* wire;
    uint8_t address;

    bool writeByte(uint8_t reg, uint8_t value);
    bool readByte(uint8_t reg, uint8_t& value);
    bool readBytes(uint8_t reg, uint8_t* buffer, size_t len);
};

#endif