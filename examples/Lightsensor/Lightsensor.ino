// This example shows how to use the LightSensor class to read light intensity in lux and print it to the serial monitor

#include <Lightsensor.h>
#include <pins.h>

// Create an instance of the LightSensor class with the defined I2C pins for SDA and SCL
LightSensor lightSensor(DEFAULT_I2C_SDA_PIN, DEFAULT_I2C_SCL_PIN);

// Initialize the light sensor and set up serial communication
void setup() {
    Serial.begin(9600);
    lightSensor.begin();
}

// This loop continuously reads the light intensity from the sensor and prints it to the serial monitor every second
void loop() {
    uint32_t lux = lightSensor.readLight();
    Serial.println("Light: " + String(lux) + " lx");
    delay(1000);
}
