#ifndef SYNCHRONIZABLE_TIME_EMULATOR
#define SYNCHRONIZABLE_TIME_EMULATOR

#include <inttypes.h>
#include "../RegisterUpdater.h"

/**
* Emulate RTC on internal Arduino clock basing on the minutes time in the register
**/
class SynchronizableTimeEmulator: public RegisterUpdater {
  private:
    unsigned long lastRegisterUpdateTimeMs;
    uint16_t lastRegisterValue;

  public:
    uint16_t currentTimeMinutes;
    void init();
    void update(uint16_t* registerData);
};

#endif
