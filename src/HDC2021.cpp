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
