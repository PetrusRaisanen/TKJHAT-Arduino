#ifndef TKJHAT_LIGHTSENSOR_H
#define TKJHAT_LIGHTSENSOR_H

#include <Arduino.h>
#include <Wire.h>

// VEML6030 sensor

class LightSensor {
    private:
        uint8_t sdapin;
        uint8_t sclpin;

    public:
        LightSensor(uint8_t sdapin, uint8_t sclpin);
        void begin();
        uint32_t readLight();
        void stop();

};

#endif
