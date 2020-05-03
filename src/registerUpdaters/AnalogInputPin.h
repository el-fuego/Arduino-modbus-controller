#ifndef ANALOG_INPUT_PIN_UPDATER
#define ANALOG_INPUT_PIN_UPDATER

#include <inttypes.h>
#include "./RegisterUpdater.h"


/**
* Write analog value from Arduino pin to register
**/
class AnalogInputPin: public RegisterUpdater {
  private:
    uint8_t pin;
    
  public:
    AnalogInputPin(uint8_t _pin);

    void init();
    void update(uint16_t* registerData);
};

#endif