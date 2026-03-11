#include "TKJHAT.h"
#include "pins.h"
#include <Wire.h>

TKJHAT::TKJHAT()
    : button1(SW1_PIN),
      button2(SW2_PIN),
      led(RED_LED_PIN),
      buzzer(BUZZER_PIN)
      rgbLed(RGB_LED_R, RGB_LED_G, RGB_LED_B) {
}

void TKJHAT::begin() {
    // Initialize default I2C pins and bus
    Wire.setSDA(DEFAULT_I2C_SDA_PIN);
    Wire.setSCL(DEFAULT_I2C_SCL_PIN);
    Wire.begin();

    // Initialize peripherals
    button1.begin();
    button2.begin();
    led.begin();
    buzzer.begin();
    rgbLed.begin();

    // Set initial states
    led.set(false);
}