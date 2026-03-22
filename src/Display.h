#ifndef TKJHAT_DISPLAY_H
#define TKJHAT_DISPLAY_H

#include <Arduino.h>

/**
 * @brief API for the SSD1306 OLED display, uses the ssd1306 library for low-level operations
 * Datasheet can be found at: https://cdn-shop.adafruit.com/datasheets/SSD1306.pdf
 * Library used can be found at: https://github.com/daschr/pico-ssd1306https://github.com/daschr/pico-ssd1306
 * Functions are based on TKJHAT C SDK with minimal modifications to fit Arduino style and the class structure.
 * 
 */

extern "C" {    // Including C headers in a C++ file requires extern "C"
#include "display/ssd1306.h"
}

/** @brief A class to control the SSD1306 OLED display 
 * 
*/

class Display {

private:
    ssd1306_t _disp;

public:

    /** @brief Construct a new Display object
     * 
     */
    Display();

    /** @brief Initialize the display
     * 
     */
    void begin();

    /** @brief Write text to the display with a specified scale
     * 
     * @param text The text to display
     * @param scale The scale of the text (default is 1)
     * 
     */
    void writeText(const char* text, uint8_t scale = 1);

    /** @brief Put a pixel on the display
     * 
     * @param x The x-coordinate of the pixel
     * @param y The y-coordinate of the pixel
     */
    void putp(int16_t x, int16_t y);

    /** @brief Draw a horizontal span
     * 
     * @param x0 The x-coordinate of the first point
     * @param x1 The x-coordinate of the second point
     * @param y The y-coordinate of the line
     */
    void hspan(int16_t x0, int16_t x1, int16_t y);

    /** @brief Draw a circle
     * 
     * @param x0 The x-coordinate of the center
     * @param y0 The y-coordinate of the center
     * @param r The radius of the circle
     * @param fill Whether to fill the circle
     */
    void drawCircle(int16_t x0, int16_t y0, int16_t r, bool fill);

    /** @brief Draw a line between two points
     * 
     * @param x0 The x-coordinate of the first point
     * @param y0 The y-coordinate of the first point
     * @param x1 The x-coordinate of the second point
     * @param y1 The y-coordinate of the second point
     */
    void drawLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1);

    /** @brief Draw a square
     * 
     * @param x The x-coordinate of the top-left corner
     * @param y The y-coordinate of the top-left corner
     * @param w The width of the square
     * @param h The height of the square
     * @param fill Whether to fill the square
     */
    void drawSquare(uint32_t x, uint32_t y, uint32_t w, uint32_t h, bool fill);

    /** @brief Clear the display
     * 
     */ 
    void clear();

    /** @brief Stop the display (power off)
     */
    void stopDisplay();
};

#endif
