#include "TKJHAT.h"

TKJHAT hat; // Create an instance of the TKJHAT class

// Initialize the light sensor and set up serial communication
void setup() {
    Serial.begin(9600);
    hat.lightSensor.begin();
}

// This loop continuously reads the light intensity from the sensor and prints it to the serial monitor every second
void loop() {
    uint32_t lux = hat.lightSensor.readLight();
    Serial.println("Light: " + String(lux) + " lx");
    delay(1000);
}
