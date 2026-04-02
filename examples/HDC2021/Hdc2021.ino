// This is an example code for using the HDC2021 sensor with an Arduino.

#include <HDC2021.h>
#include <pins.h>

// Create an instance of the HDC2021 sensor with the appropriate I2C pins and interrupt pin
HDC2021 sensor(DEFAULT_I2C_SDA_PIN, DEFAULT_I2C_SCL_PIN, HDC2021_INTERRUPT);

// Initializes serial communication and the HDC2021 sensor
void setup() {
    Serial.begin(9600); // Start serial communication at 9600 baud rate
    sensor.begin();
}

// Reads temperature and humidity from the sensor and prints the values to the serial monitor every second
void loop() {
    Serial.print("Temperature: ");
    Serial.println(sensor.readTemperature()); // Read and print the temperature value
    Serial.print("Humidity: ");
    Serial.println(sensor.readHumidity()); // Read and print the humidity value
    delay(1000); // Wait for 1 second before the next reading
}
