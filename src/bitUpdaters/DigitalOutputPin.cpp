#include <Arduino.h>
#include "./DigitalOutputPin.h"


DigitalOutputPin::DigitalOutputPin(uint8_t _pin): pin(_pin) {};

void DigitalOutputPin::init() {
  pinMode(pin, OUTPUT);
};

// register -> pin
void DigitalOutputPin::update(uint16_t* registerData, char bitIndex) {
  digitalWrite(pin, bitRead(*registerData, bitIndex));
};