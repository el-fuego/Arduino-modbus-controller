#include <Arduino.h>
#include "./AnalogOutputPin.h"


AnalogOutputPin::AnalogOutputPin(uint8_t _pin): pin(_pin) {};

void AnalogOutputPin::init() {
  pinMode(pin, OUTPUT);
}

// register -> pin
void AnalogOutputPin::update(uint16_t* registerData) {
  analogWrite(pin, *registerData);
}
