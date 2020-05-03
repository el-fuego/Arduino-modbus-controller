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
  pinData->pressStartTime = 0;
  pinData->pressEndTime = 0;
};

void ButtonBase::updateTime(bool isPressed) {
  if (isPressed) {
    if (
      !pinData->pressStartTime ||
      (pinData->pressEndTime && static_cast<long>(pinData->pressEndTime - pinData->pressStartTime) > BUTTON_MIN_TAP_TIME)
    ) {
      pinData->pressStartTime = millis();
    }
  } else {
    if (pinData->pressStartTime && 
      (!pinData->pressEndTime || static_cast<long>(pinData->pressStartTime - pinData->pressEndTime) > BUTTON_MIN_TAP_TIME)
    ) {
      pinData->pressEndTime =  millis();
    }
  }
};
