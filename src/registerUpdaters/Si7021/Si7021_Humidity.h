#ifndef SI7021_HUMIDITY_UPDATER
#define SI7021_HUMIDITY_UPDATER

#include <inttypes.h>
#include "./Si7021_Base.h"

#define SI7021_HUMIDITY_UPDATE_INTERVAL 1000

/**
* Write analog value from Arduino pin to register
**/
class Si7021_Humidity: public Si7021_Base {
  public:
    Si7021_Humidity(Si7021_PinData* _pinData): Si7021_Base(_pinData) {};
    void update(uint16_t* registerData);
};

#endif