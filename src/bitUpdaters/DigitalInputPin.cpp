#include <Arduino.h>
#include "./DigitalInputPin.h"


DigitalInputPin::DigitalInputPin(uint8_t _pin): pin(_pin) {};

void DigitalInputPin::init() {
  pinMode(pin, INPUT);
};

// pin -> register
void DigitalInputPin::update(uint16_t* registerData, char bitIndex) {
  bitWrite(*registerData, bitIndex, digitalRead(pin));
};