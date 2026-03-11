#include "Display.h"
#include "font.h"
#include "pins.h"

Display::Display() {
    _disp.external_vcc = false;
}

void Display::begin() {
    ssd1306_init(&_disp, 128, 64, SSD1306_I2C_ADDRESS, i2c_default);
    ssd1306_poweron(&_disp);
    ssd1306_clear(&_disp);
    ssd1306_show(&_disp);
}

void Display::writeText(const char* text, uint8_t scale) {
    if (!text) return;

    ssd1306_draw_string(&_disp, 8, 24, scale, text);
    ssd1306_show(&_disp);
}

void Display::clear() {
    ssd1306_clear(&_disp);
    ssd1306_show(&_disp);
}
