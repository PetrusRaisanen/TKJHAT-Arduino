// This demo shows how to use different components of the TKJHAT library together
// This demo will read the light intensity from light sensor, and display it on the OLED screen
// Button will be used to toggle between showing light intensity and showing a static message "STOPPED"

#include "TKJHAT.h"

TKJHAT hat;

// hat.begin() initializes all the components on the HAT
void setup() {
    hat.begin();
}

void loop () {
    // Read light intensity from the sensor
    uint32_t lux = hat.lightSensor.readLight();
    // Check if button1 is not pressed
    if (!hat.button1.isPressed()) {
        // If button1 is not pressed, show the light intensity on the display
        hat.display.clear();
        // Type: void Display::writeTextPositioned(int16_t x, int16_t y, const char* text, uint8_t scale){}
        hat.display.writeTextPositioned(0, 0, "Light Intensity:", 1);
        String text = String(lux);
        hat.display.writeTextPositioned(0, 16, text.c_str(), 1);
    } else {
        // If button1 is pressed, show "STOPPED" on the display
        hat.display.clear();
        hat.display.writeTextPositioned(0, 0, "STOPPED");
    }
}
