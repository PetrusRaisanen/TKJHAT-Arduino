#include "TKJHAT.h"
#include "pins.h"
#include <Wire.h>

// Constructor creates instances of all peripherals with their respective pins
TKJHAT::TKJHAT()
    : button1(SW1_PIN),
      button2(SW2_PIN),
      led(RED_LED_PIN),
      buzzer(BUZZER_PIN),
      display(),
      rgbLed(RGB_LED_R, RGB_LED_G, RGB_LED_B),
      icm42670(),
      lightSensor(DEFAULT_I2C_SDA_PIN, DEFAULT_I2C_SCL_PIN)
      {
}

// Initialize all peripherals
void TKJHAT::begin() {
    Wire.setSDA(DEFAULT_I2C_SDA_PIN);
    Wire.setSCL(DEFAULT_I2C_SCL_PIN);
    Wire.begin();

    button1.begin();
    button2.begin();
    led.begin();
    buzzer.begin();
    rgbLed.begin();
    display.begin();
    icm42670.begin();
    lightSensor.begin();

    // Initial states
    led.set(false);
    rgbLed.stop(); 
}