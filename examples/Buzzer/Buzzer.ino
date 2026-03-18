// This example shows how to use the Buzzer class to play a tone at a specific frequency and duration

#include <Buzzer.h>
#include <pins.h>

// Create an instance of the Buzzer class with the defined pin for the buzzer
Buzzer buzzer(BUZZER_PIN );

// Initialize the buzzer
void setup() {
    buzzer.begin();
}

// In this loop, we will play a tone at 1000 Hz for 1 second, then wait for 1 second before repeating
// First value is the frequency in Hz, and the second value is the duration in milliseconds
void loop() {
    buzzer.playTone(1000, 1000);
    delay(1000);
}
