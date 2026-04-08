#include "Display.h"
#include "display/font.h"
#include "pins.h"

// Instance that initializes the display
Display::Display() {
    _disp.external_vcc = false;
}

// Display initialization
void Display::begin() {

    // Initialize the SSD1306 display with external VCC
    ssd1306_init(&_disp, 128, 64, SSD1306_I2C_ADDRESS, i2c_default);

    ssd1306_poweron(&_disp);    // Power on the display

    ssd1306_clear(&_disp);  // Clear the display

    ssd1306_show(&_disp);   // Update the display to show the cleared state
}


void Display::writeText(const char* text) {
    if (!text) return;
    // Draw the text at the specified position with a font size of 2
    ssd1306_draw_string(&_disp, 8, 24, 2, text);
        // Update the display
    ssd1306_show(&_disp);

    // Delay for 800 milliseconds
    delay(800);
}

// Write text to the display with a specified scale and position
void Display::writeTextPositioned(int16_t x, int16_t y, const char* text, uint8_t scale) {
    if (!text) return;

    ssd1306_draw_string(&_disp, (uint32_t)x, (uint32_t)y, scale, text);
    ssd1306_show(&_disp);

    // Delay for 800 milliseconds
    delay(800);
}

void Display::putp(int16_t x, int16_t y) {
    if (x >= 0 && y >= 0 &&
        x < (int16_t)_disp.width && y < (int16_t)_disp.height) {
        ssd1306_draw_pixel(&_disp, (uint32_t)x, (uint32_t)y);
    }
}

void Display::hspan(int16_t x1, int16_t x2, int16_t y) {
    if (y < 0 || y >= (int16_t)_disp.height) return;
    if (x1 > x2) { int16_t t = x1; x1 = x2; x2 = t; }
    if (x2 < 0 || x1 >= (int16_t)_disp.width) return;
    if (x1 < 0) x1 = 0;
    if (x2 >= (int16_t)_disp.width) x2 = (int16_t)_disp.width - 1;

    for (int16_t x = x1; x <= x2; ++x) {
        ssd1306_draw_pixel(&_disp, (uint32_t)x, (uint32_t)y);
    }
}


void Display::drawCircle(int16_t x0, int16_t y0, int16_t r, bool fill) {
    // Draw a circle using the Bresenham algorithm
    if (r < 0) 
        return;
    if (r == 0) { 
        putp(x0, y0); 
        ssd1306_show(&_disp); 
        return; 
    }

    // Midpoint circle algorithm
    int16_t f = 1 - r;
    int16_t ddF_x = 1;
    int16_t ddF_y = -2 * r;
    int16_t x = 0;
    int16_t y = r;

    if (fill) {
        hspan((int16_t)(x0 - r), (int16_t)(x0 + r), y0);  // center row
    } else {
        putp(x0, (int16_t)(y0 + r));
        putp(x0, (int16_t)(y0 - r));
        putp((int16_t)(x0 + r), y0);
        putp((int16_t)(x0 - r), y0);
    }

    while (x < y) {
        if (f >= 0) { y--; ddF_y += 2; f += ddF_y; }
        x++; ddF_x += 2; f += ddF_x;

        if (fill) {
            hspan((int16_t)(x0 - x), (int16_t)(x0 + x), (int16_t)(y0 + y));
            hspan((int16_t)(x0 - x), (int16_t)(x0 + x), (int16_t)(y0 - y));
            hspan((int16_t)(x0 - y), (int16_t)(x0 + y), (int16_t)(y0 + x));
            hspan((int16_t)(x0 - y), (int16_t)(x0 + y), (int16_t)(y0 - x));
        } else {
            putp((int16_t)(x0 + x), (int16_t)(y0 + y));
            putp((int16_t)(x0 - x), (int16_t)(y0 + y));
            putp((int16_t)(x0 + x), (int16_t)(y0 - y));
            putp((int16_t)(x0 - x), (int16_t)(y0 - y));
            putp((int16_t)(x0 + y), (int16_t)(y0 + x));
            putp((int16_t)(x0 - y), (int16_t)(y0 + x));
            putp((int16_t)(x0 + y), (int16_t)(y0 - x));
            putp((int16_t)(x0 - y), (int16_t)(y0 - x));
        }
    }
    ssd1306_show(&_disp);  // remove if batching multiple draws
}

void Display::drawLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1) {
    // Draw a line between the specified points
    ssd1306_draw_line(&_disp, x0, y0, x1, y1);

    // Update the display
    ssd1306_show(&_disp);
}

void Display::drawSquare(uint32_t x, uint32_t y, uint32_t w, uint32_t h, bool fill) {
    // Draw a square at the specified position with the given width and height
    if (fill)
        ssd1306_draw_square(&_disp, x, y, w, h);
    else
        ssd1306_draw_empty_square(&_disp, x, y, w, h);

    // Update the display
    ssd1306_show(&_disp);
}

// Clear the display
void Display::clear() {
    ssd1306_clear(&_disp);
    ssd1306_show(&_disp);
}

// Power off the display
void Display::stopDisplay() {
    ssd1306_poweroff(&_disp);
}
