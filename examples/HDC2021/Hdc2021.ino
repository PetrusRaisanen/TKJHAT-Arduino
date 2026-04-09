/*
  HDC2021 Example

  This example demonstrates how to use the HDC2021 temperature and humidity sensor with the TKJHAT library. 
  It initializes the sensor, reads temperature and humidity values, and prints them to the Serial Monitor every second.

  Circuit:
  - HDC2021 sensor integrated in Pico HAT

  created 2026
 */

#include "TKJHAT.h"

// Create an instance of the TKJHAT class
TKJHAT hat; 

// Initializes serial communication and the HDC2021 sensor
void setup() {
    Serial.begin(9600); // Start serial communication at 9600 baud rate
    hat.hdc2021.begin();
}

// Reads temperature and humidity from the sensor and prints the values to the serial monitor every second
void loop() {
    Serial.print("Temperature: ");
    Serial.println(hat.hdc2021.readTemperature()); // Read and print the temperature value
    Serial.print("Humidity: ");
    Serial.println(hat.hdc2021.readHumidity()); // Read and print the humidity value
    delay(1000); // Wait for 1 second before the next reading
}
