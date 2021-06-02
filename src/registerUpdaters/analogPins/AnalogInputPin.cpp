#include <Arduino.h>
#include "./AnalogInputPin.h"


AnalogInputPin::AnalogInputPin(uint8_t _pin): pin(_pin) {};

void AnalogInputPin::init() {
  pinMode(pin, INPUT);
}

// pin -> register
void AnalogInputPin::update(uint16_t* registerData) {
  *registerData = analogRead(pin);
}
