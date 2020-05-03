#include "./OneWireTemperaturePinData.h"

OneWireTemperaturePinData::OneWireTemperaturePinData(uint8_t _pin): oneWire(_pin), sensors(&oneWire) {};
