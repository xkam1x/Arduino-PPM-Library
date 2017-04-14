#include "PPM.hpp"
// Global variables
byte my_pin, my_state, pulse = 0;
unsigned int channels[no_of_channels + 1];
unsigned long timers[no_of_channels + 2];
// Calculates the channel values
void getChannelValue(byte pointer) {
    channels[pointer -1] = timers[pointer] - timers[pointer -1];
    if (channels[pointer -1] > 3000) {
        timers[0] = timers[pointer];
        pulse = 1;
    } else pulse++;
}
// Stores the pulse position timers
void my_ISR() {
    byte state_now = digitalRead(my_pin);
    if (state_now == my_state) {
        timers[pulse] = micros();
        if (pulse > 0) {
            getChannelValue(pulse);
        } else pulse++;
    }
}
// Setup ISR
void PPM::begin(byte pin, byte state) {
    my_state = state;
    my_pin = pin;
    attachInterrupt(digitalPinToInterrupt(pin), my_ISR, CHANGE);
}
// Get Value
unsigned int PPM::getValue(byte channel) {
    return channels[channel - 1];
}
