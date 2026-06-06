#include <Arduino.h>
#include "LEDflow.h"
#include "Passwordlock.h"
/*LEDflow part
void setup() {
    Serial.begin(115200);
    LEDsetup();
}

void loop() {
    LEDflow();
}*/
void setup() {
    passwordlocksetup();
}
void loop() {
    passwordlockloop();
}
