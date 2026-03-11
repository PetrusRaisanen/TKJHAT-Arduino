#include "Microphone.h"

// Constructor
Microphone::Microphone(uint8_t dataPin, uint8_t clkPin) {
    this->dataPin = dataPin;
    this->clkPin = clkPin;
}

int Microphone::begin() {
    const struct pdm_microphone_config config = {
    // GPIO pin for the PDM DAT signal
    .gpio_data = dataPin,

    // GPIO pin for the PDM CLK signal
    .gpio_clk = clkPin,

    // PIO instance to use
    .pio = pio0,

    // PIO State Machine instance to use
    .pio_sm = 0,

    // sample rate in Hz
    .sample_rate = 16000,

    // number of samples to buffer
    .sample_buffer_size = 256,
    };

    return pdm_microphone_init(&config);
   
}

// Starts the microphone sampling
int Microphone::start() {
    return pdm_microphone_start();
}

// Stops the microphone sampling
void Microphone::stop() {
    pdm_microphone_stop();
}

// Sets the callback function that will be called when new samples are ready
void Microphone::setCallback(pdm_samples_ready_handler_t handler) {
    pdm_microphone_set_samples_ready_handler(handler);
}

// Reads samples from the microphone into the provided buffer
int Microphone::getSamples(int16_t* buffer, size_t samples) {
    return pdm_microphone_read(buffer,samples);
}
