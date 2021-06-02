#ifndef ANALOG_OUTPUT_PIN_UPDATER
#define ANALOG_OUTPUT_PIN_UPDATER

#include <inttypes.h>
#include "../RegisterUpdater.h"


/**
* Write analog value from Arduino pin to register
**/
class AnalogOutputPin: public RegisterUpdater {
  private:
    uint8_t pin;

  public:
    AnalogOutputPin(uint8_t _pin);

    void init();
    void update(uint16_t* registerData);
};

#endif
