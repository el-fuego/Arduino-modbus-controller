
#include "./Si7021_Humidity.h"


// sensor -> register
// write value*10 as int to use single register
void Si7021_Humidity::update(uint16_t* registerData) {
  // Too often temperature sensors reading can cause heating => wrong values can be read
  unsigned long currentTimeMs = millis();
  if (currentTimeMs - lastUpdateTimeMs < SI7021_HUMIDITY_UPDATE_INTERVAL_MS) {
    return;
  }
  lastUpdateTimeMs = currentTimeMs;

  *registerData = static_cast<int>(pinData->sensor.readHumidity() * 10);
}
