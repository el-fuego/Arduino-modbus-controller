#ifndef ONE_WIRE_TEMPERATURE_PIN_DATA
#define ONE_WIRE_TEMPERATURE_PIN_DATA

#include <inttypes.h>
#include <OneWire.h>
#include <DallasTemperature.h>


struct OneWireTemperaturePinData {
  OneWire oneWire;
  DallasTemperature sensors;
  bool isInited = false;
  OneWireTemperaturePinData(uint8_t _pin);
};

#endif