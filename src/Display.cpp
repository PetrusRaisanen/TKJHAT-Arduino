#include "Display.h"
#include "display/font.h"
#include "pins.h"
// Instance that initializes the display
Display::Display() {
    _disp.external_vcc = false;
}
// Display initialization
void Display::begin() {
    ssd1306_init(&_disp, 128, 64, SSD1306_I2C_ADDRESS, i2c_default);
    ssd1306_poweron(&_disp);
    ssd1306_clear(&_disp);
    ssd1306_show(&_disp);
}
// Write text to the display with a specified scale
void Display::writeText(const char* text, uint8_t scale) {
    if (!text) return;

    ssd1306_draw_string(&_disp, 8, 24, scale, text);
    ssd1306_show(&_disp);
}
// Clear the display
void Display::clear() {
    ssd1306_clear(&_disp);
    ssd1306_show(&_disp);
}
