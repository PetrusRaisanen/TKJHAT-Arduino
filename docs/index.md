# Arduino TKJHAT

Library for the Pico HAT extension board for the Raspberry Pi Pico W.

This library provides access to onboard components including buttons, LEDs, sensors, display, and buzzer using Arduino-style APIs.

---

## Basic Usage

```cpp
#include "TKJHAT.h"

TKJHAT hat;

void setup() {
    // example code
}

void loop() {
    //...
}
```

---

## Components

The following components are available on the board:

**Actuators**
- Button: `button1`, `button2`
- Led: `led`
- RGBLed: `rgbLed`
- Buzzer: `buzzer`
- Display, SSD1306 OLED: `display`

**Sensors**
- Microphone: `microphone`
- LightSensor, VEML6030: `lightSensor`
- ICM42670, 6-axis accelerometer + gyroscope: `icm42670`
- HDC2021, Temperature and humidity sensor: `hdc2021`

---

## Getting Started

Try these example sketches:

- \ref Button.ino
- \ref Led.ino
- \ref RGBLed.ino
- \ref Buzzer.ino
- \ref Display.ino
- \ref Lightsensor.ino
- \ref ICM42670.ino
- \ref HDC2021.ino
