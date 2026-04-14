#include <TKJHAT.h>

TKJHAT hat;

float accelBias[3] = {0.0, 0.0, 0.0};
float gyroBias[3] = {0.0, 0.0, 0.0};

void setup() {
  Serial.begin(115200);
  while (!Serial);

  Serial.println("ax ay az gx gy gz temp");

  hat.begin();
  hat.icm42670.startWithDefaultValues();
  hat.icm42670.calibrateAccel(accelBias);
  hat.icm42670.calibrateGyro(gyroBias);
}



void loop() {
  float ax, ay, az, gx, gy, gz, t;

  hat.icm42670.readSensorData(ax, ay, az, gx, gy, gz, t);

  ax -= accelBias[0];
  ay -= accelBias[1];
  az -= accelBias[2];
  gx -= gyroBias[0];
  gy -= gyroBias[1];
  gz -= gyroBias[2];

  Serial.print(ax); Serial.print(' ');
  Serial.print(ay); Serial.print(' ');
  Serial.print(az); Serial.print(' ');
  Serial.print(gx); Serial.print(' ');
  Serial.print(gy); Serial.print(' ');
  Serial.print(gz); Serial.print(' ');
  Serial.println(t);

  delay(200);
}
