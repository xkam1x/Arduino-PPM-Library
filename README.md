Arduino PPM Reader!
===================
This library uses interrupts to read PPM values. Only pins 2 and 3 are usable on Arduino Uno and pins 2, 3, 18, 19, 20 and 21 are usable on Mega2560 and MegaADK. Refer to https://www.arduino.cc/en/Reference/attachInterrupt for details.
 
Usage:
-------------

1. Copy PPM.cpp and PPM.hpp in your project folder.
2. Include PPM.hpp in your program. example #include "PPM.hpp"
3. Modify the 'no_of_channels' parameter in 'PPM.hpp' and set it equal to or greater than the number of channels you are expecting.
3. Create a PPM instance variable and call it what you want. example: PPM my_ppm;
4. Initialise PPM instance you made and provide pin and trigger condition. example my_ppm.begin(2, 1);
5. Call getValue to get PPM value. example 'some_variable' = my_ppm.getValue('channel_number');


Example:
-------------

```
#include "PPM.hpp"

PPM my_ppm;

void setup() {
  Serial.begin(115200); // Serial for debug
  my_ppm.begin(2, 1); // PPM on pin 2 triggering on HIGH state
}

void loop() {
  for (byte i = 1; i <= 6; i++) {
    Serial.print(my_ppm.getValue(i));
    Serial.print("\t");
  }
  Serial.println();
  delay(100);
}
```

paypal.me/xkam1x