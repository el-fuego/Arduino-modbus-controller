#include "./Si7021_Base.h"


Si7021_Base::Si7021_Base(Si7021_PinData* _pinData): pinData(_pinData) {};

void Si7021_Base::init() {
  if (pinData->isInited) {
    return;
  }
  pinData->isInited = true;
  pinData->sensor.begin();
};

