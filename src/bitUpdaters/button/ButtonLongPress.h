#ifndef BUTTON_LONG_PRESS_UPDATER
#define BUTTON_LONG_PRESS_UPDATER

#include <inttypes.h>
#include "./ButtonBase.h"


/**
* Write digital value from Arduino pin to register
* hold longer then BUTTON_LONG_PRESS_TIME_MS
**/
class ButtonLongPress: public ButtonBase {
  public:
    ButtonLongPress(ButtonPinData* _pinData): ButtonBase(_pinData) {};

    void update(uint16_t* registerData, char bitIndex);
};

#endif
