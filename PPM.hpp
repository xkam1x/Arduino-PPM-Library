/*
 * This library uses interrupts to read PPM values.
 * Only pins 2 and 3 are usable on Arduino Uno and pins 2, 3, 18, 19, 20 and 21 are usable on Mega2560 and MegaADK.
 * Refer to https://www.arduino.cc/en/Reference/attachInterrupt for details.
 */

#include <Arduino.h>
// Set this to number of channels you are expecting.
const byte no_of_channels = 6;

class PPM {
public:
    void begin(byte pin, byte state);
    // pin = digital pin to attach interrupt
    // state = 1 => trigger on HIGH pulse
    // state = 0 => trigger on LOW pulse
    unsigned int getValue(byte channel);
    // returns channel value
};
