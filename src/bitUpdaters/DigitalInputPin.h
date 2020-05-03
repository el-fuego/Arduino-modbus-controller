#ifndef DIGITAL_INPUT_PIN_UPDATER
#define DIGITAL_INPUT_PIN_UPDATER

#include <inttypes.h>
#include "./BitUpdater.h"


/**
* Write digital value from Arduino pin to register
**/
class DigitalInputPin: public BitUpdater {
  private:
    uint8_t pin;
    
  public:
    DigitalInputPin(uint8_t _pin);

    void init();
    void update(uint16_t* registerData, char bitIndex);
};

#endif