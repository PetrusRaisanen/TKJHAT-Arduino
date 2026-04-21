/* TKJHAT ICM42670 Example

This example demonstrates how to use the ICM42670 IMU sensor on the TKJHAT. 
It initializes the sensor, performs calibration, and continuously reads and prints accelerometer, 
gyroscope, and temperature data.

Circuit:
- ICM42670 IMU integrated in Pico HAT

created 2026
*/

#include <TKJHAT.h>

TKJHAT hat;

// Bias values for calibration (replace with actual calibration results)
float accelBias[3] = {0.0, 0.0, 0.0};
float gyroBias[3] = {0.0, 0.0, 0.0};


void setup() {
  // Start serial communication for output
  Serial.begin(115200);
  // Wait for serial connection
  while (!Serial); 

  Serial.println("ax ay az gx gy gz temp");

  // Initialize the HAT with the peripherals including IMU
  hat.begin();

  // Start the sensor and perform calibration
  hat.icm42670.startWithDefaultValues();
  hat.icm42670.calibrateAccel(accelBias);
  hat.icm42670.calibrateGyro(gyroBias);
}

void loop() {
  // Variables to hold sensor data
  float ax, ay, az, gx, gy, gz, t;

  // Read sensor data (ax, ay, az in g; gx, gy, gz in dps; t in °C)
  hat.icm42670.readSensorData(ax, ay, az, gx, gy, gz, t);

  // Apply calibration bias correction
  ax -= accelBias[0];
  ay -= accelBias[1];
  az -= accelBias[2];
  gx -= gyroBias[0];
  gy -= gyroBias[1];
  gz -= gyroBias[2];

  // Print the sensor data in a space-separated format
  Serial.print(ax); Serial.print(' ');
  Serial.print(ay); Serial.print(' ');
  Serial.print(az); Serial.print(' ');
  Serial.print(gx); Serial.print(' ');
  Serial.print(gy); Serial.print(' ');
  Serial.print(gz); Serial.print(' ');
  Serial.println(t);

  // Delay before next reading
  delay(200);
}
