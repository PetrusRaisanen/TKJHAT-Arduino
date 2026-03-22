#ifndef TKJHAT_DISPLAY_H
#define TKJHAT_DISPLAY_H

#include <Arduino.h>

/**
 * @brief A class to control the SSD1306 OLED display, uses the ssd1306 header for low-level operations
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
     * @param text The text to display
     * @param scale The scale of the text (default is 1)
     * 
     */
    void writeText(const char* text, uint8_t scale = 1);

    /** @brief Clear the display
     * 
     */ 
    void clear();
};

#endif
