#include <Arduino.h>
#include "./ButtonBase.h"


ButtonBase::ButtonBase(ButtonPinData* _pinData): pinData(_pinData) {};

void ButtonBase::init() {
  if (pinData->isInited) {
    return;
  }
  pinData->isInited = true;
  pinMode(pinData->pin, INPUT);
};

void ButtonBase::writeEvent(uint16_t* registerData, char bitIndex) {
  pinData->isEventCatched = true;
  bitWrite(*registerData, bitIndex, 1);
};

void ButtonBase::clearTime() {
  pinData->isEventCatched = false;
  pinData->pressStartTimeMs = 0;
  pinData->pressEndTimeMs = 0;
};

void ButtonBase::updateTime(bool isPressed) {
  if (isPressed) {
    if (
      !pinData->pressStartTimeMs ||
      (pinData->pressEndTimeMs && static_cast<long>(pinData->pressEndTimeMs - pinData->pressStartTimeMs) > BUTTON_MIN_TAP_TIME_MS)
    ) {
      pinData->pressStartTimeMs = millis();
    }
  } else {
    if (pinData->pressStartTimeMs &&
      (!pinData->pressEndTimeMs || static_cast<long>(pinData->pressStartTimeMs - pinData->pressEndTimeMs) > BUTTON_MIN_TAP_TIME_MS)
    ) {
      pinData->pressEndTimeMs =  millis();
    }
  }
};
