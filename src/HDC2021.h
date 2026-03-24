#ifndef HDC2021_H
#define HDC2021_H

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
    HDC2021(uint8_t sdaPin, uint8_t sclPin, uint8_t interruptPin);
    void begin();
    void setLowTempThreshold(float temp);
    void setHighTempThreshold(float temp);
    void setLowHumidityThreshold(float humid);
    void setHighHumidityThreshold(float humid);
    float readTemperature();
    float readHumidity();
    void stop();
};

#endif
