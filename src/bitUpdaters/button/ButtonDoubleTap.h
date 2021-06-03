#ifndef BUTTON_DOUBLE_TAP_UPDATER
#define BUTTON_DOUBLE_TAP_UPDATER

#include <inttypes.h>
#include "./ButtonBase.h"


/**
* Write digital value from Arduino pin to register
* pressed after previous press in < BUTTON_TAP_TIMEOUT_MS
**/
class ButtonDoubleTap: public ButtonBase {
  public:
    ButtonDoubleTap(ButtonPinData* _pinData): ButtonBase(_pinData) {};

    void update(uint16_t* registerData, char bitIndex);
};

#endif
