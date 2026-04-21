#ifndef TKJHAT_MICROPHONE_H
#define TKJHAT_MICROPHONE_H

#include <Arduino.h>

/**
 * @brief A class to control MEMS microphone 
 * 
 * @details
 * This class provides control for the PDM MEMS microphone connected via PIO.
 * 
 * **Microphone (@ref PDM_CLK — GPIO 15, @ref PDM_DATA — GPIO 16)**
 * - Based on the [Arm Developer Ecosystem Microphone Library for Pico]
 *   (https://github.com/ArmDeveloperEcosystem/microphone-library-for-pico/tree/main)
 * - Uses PIO for PDM capture and OpenPDM2PCM for conversion to PCM.
 *
 * Default microphone parameters:
 * | Setting | Value |
 * |----------|--------|
 * | Data pin | @ref PDM_DATA (GPIO 16) |
 * | Clock pin | @ref PDM_CLK (GPIO 15) |
 * | Sample rate | 16 kHz |
 * | Buffer size | 256 samples |
 */

extern "C" {
#include "microphone/pico/pdm_microphone.h"
}

class Microphone {
private:
    uint8_t dataPin;
    uint8_t clkPin;

public:

    /** @brief Construct a new Microphone object
     * @param dataPin GPIO pin connected to the PDM data signal (default: GPIO 16)
     * @param clkPin GPIO pin connected to the PDM clock signal (default: GPIO 15)
     */

    Microphone(uint8_t dataPin, uint8_t clkPin);

/**
 * @brief Initialize the PDM MEMS microphone.
 *
 * Configures the microphone using PIO to capture PDM data and the
 * OpenPDM2PCM library to transform it into PCM samples.
 *
 * Implementation is based on the official
 * [Arm Developer Ecosystem microphone library for Pico]
 * (https://github.com/ArmDeveloperEcosystem/microphone-library-for-pico/tree/main).
 *
 * Default parameters:
 * - Data pin: GPIO 16
 * - Clock pin: GPIO 15
 * - Sample rate: 16 kHz
 * - Buffer size: 256 samples
 *
 * @return 0 on success, negative value on error.
 */

    int begin();

    /** @brief Start capturing audio samples.
     * @return 0 on success, negative value on error.
     */
    int start();

/** @brief Stop capturing audio samples.
 * @return 0 on success, negative value on error.
 */
    void stop();

/** @brief Set a callback function to be called when new samples are ready.
 * 
 * @param handler Callback function of type ::pdm_samples_ready_handler_t.
 * 
 */
    void setCallback(pdm_samples_ready_handler_t handler);

/** @brief Read PCM samples from the microphone buffer.
 * 
 * @param buffer Pointer to an array where the samples will be stored.
 * @param samples Number of samples to read.
 * @return The number of samples actually read, or negative on error.
 * */
    int getSamples(int16_t* buffer, size_t samples);
};

#endif
