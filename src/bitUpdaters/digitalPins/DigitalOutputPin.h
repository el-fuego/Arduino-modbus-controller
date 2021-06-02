#ifndef DIGITAL_OUTPUT_PIN_UPDATER
#define DIGITAL_OUTPUT_PIN_UPDATER

#include <inttypes.h>
#include "../BitUpdater.h"


/**
* Write digital value from register to Arduino pin
**/
class DigitalOutputPin: public BitUpdater {
  private:
    uint8_t pin;

  public:
    DigitalOutputPin(uint8_t _pin);

    void init();
    void update(uint16_t* registerData, char bitIndex);
};

#endif
