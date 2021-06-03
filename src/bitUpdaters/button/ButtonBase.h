#ifndef BUTTON_BASE_UPDATER
#define BUTTON_BASE_UPDATER

#include <inttypes.h>
#include "../BitUpdater.h"
#include "./ButtonPinData.h"


#define BUTTON_MIN_TAP_TIME_MS 3
#define BUTTON_LONG_PRESS_TIME_MS 1000
#define BUTTON_TAP_TIMEOUT_MS 300

/**
* Write digital value from Arduino pin to register
**/
class ButtonBase: public BitUpdater {
  public:
    ButtonPinData* pinData;
    ButtonBase(ButtonPinData* _pinData);

    void init();
    void clearTime();
    void updateTime(bool isPressed);
    void writeEvent(uint16_t* registerData, char bitIndex);
};

#endif
