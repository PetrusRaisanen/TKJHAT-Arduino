// This is an example code for using the HDC2021 sensor with an Arduino.
#include "TKJHAT.h"

TKJHAT hat; // Create an instance of the TKJHAT class to access the HDC2021 sensor

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
