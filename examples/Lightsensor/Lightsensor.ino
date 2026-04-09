/*
  Light Sensor Example

  This example demonstrates how to use the LightSensor class from the TKJHAT library to read light intensity values and print them to the Serial Monitor.

  Circuit:
  - Light sensor integrated in Pico HAT

  created 2026
*/

#include "TKJHAT.h"

// Create an instance of the TKJHAT class
TKJHAT hat; 

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
