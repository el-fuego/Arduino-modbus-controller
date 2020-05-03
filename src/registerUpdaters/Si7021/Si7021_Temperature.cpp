#include "./Si7021_Temperature.h"


// sensor -> register
// write value*10 as int to use single register
void Si7021_Temperature::update(uint16_t* registerData) {
  // Too often temperature sensors reading can cause heating => wrong values can be read
  unsigned long currentTime = millis();
  if (currentTime - lastUpdateTime < SI7021_TEMPERATURE_UPDATE_INTERVAL) {
    return;
  }
  lastUpdateTime = currentTime;
  
  *registerData = static_cast<int>(pinData->sensor.readTemperature() * 10);
}
