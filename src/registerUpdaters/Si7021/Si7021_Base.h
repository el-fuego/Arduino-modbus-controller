#ifndef SI7021_BASE_PIN_UPDATER
#define SI7021_BASE_PIN_UPDATER

#include <inttypes.h>
#include "../RegisterUpdater.h"
#include "./Si7021_PinData.h"


class Si7021_Base: public RegisterUpdater {
  protected:
    Si7021_PinData* pinData;
    unsigned long lastUpdateTime;

  public:
    Si7021_Base(Si7021_PinData* _pinData);
    void init();
};

#endif