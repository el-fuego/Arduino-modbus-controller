#ifndef BUTTON_TAP_UPDATER
#define BUTTON_TAP_UPDATER

#include <inttypes.h>
#include "./ButtonBase.h"


/**
* Write digital value from Arduino pin to register
* pressed once in ButtonTapBase_TAP_TIMEOUT
**/
class ButtonTap: public ButtonBase {
  public:
    ButtonTap(ButtonPinData* _pinData): ButtonBase(_pinData) {};

    void update(uint16_t* registerData, char bitIndex);
};

#endif