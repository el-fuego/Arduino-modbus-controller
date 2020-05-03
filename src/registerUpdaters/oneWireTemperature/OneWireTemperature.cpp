#include <Arduino.h>
#include "./OneWireTemperature.h"


OneWireTemperature::OneWireTemperature(OneWireTemperaturePinData* _pinData, uint8_t* _address): 
  pinData(_pinData),
  address(_address) {};

void OneWireTemperature::init() {
  if (!pinData->isInited) {
    pinData->sensors.begin();
    pinData->sensors.setWaitForConversion(false);
    pinData->isInited = true;
  }
  pinData->sensors.setResolution(address, resolution);
  pinData->sensors.requestTemperaturesByAddress(address);
}

// sensor -> register
// write value*10 as int to use single register
void OneWireTemperature::update(uint16_t* registerData) {
  // Too often temperature sensors reading can cause heating => wrong values can be read
  unsigned long currentTime = millis();
  if (currentTime - lastUpdateTime < max(pinData->sensors.millisToWaitForConversion(resolution), ONE_WIRE_TEMPERATURE_UPDATE_INTERVAL)) {
    return;
  }
  lastUpdateTime = currentTime;

  *registerData = static_cast<int>(pinData->sensors.getTempC(address) * 10);
  pinData->sensors.requestTemperaturesByAddress(address);
}
