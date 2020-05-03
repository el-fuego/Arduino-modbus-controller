#ifndef ONE_WIRE_TEMPERATURE_UPDATER
#define ONE_WIRE_TEMPERATURE_UPDATER

#include <inttypes.h>
#include "../RegisterUpdater.h"
#include "./OneWireTemperaturePinData.h"


#define ONE_WIRE_TEMPERATURE_UPDATE_INTERVAL 1000

/**
* Write one wire temperature sensor value from Arduino to register
**/
class OneWireTemperature: public RegisterUpdater {
  private:
    uint8_t* address;
    OneWireTemperaturePinData* pinData;
    unsigned long lastUpdateTime = 0;
    
  public:
    // 9 provide smallest request time, but resolution at 0.5*C, so using closest yet slower
    uint8_t resolution = 10;

    OneWireTemperature(OneWireTemperaturePinData* _pinData, uint8_t* _address);

    void init();
    void update(uint16_t* registerData);
};

#endif