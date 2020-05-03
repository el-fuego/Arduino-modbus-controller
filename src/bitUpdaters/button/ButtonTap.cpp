#include <Arduino.h>
#include "./ButtonTap.h"


// pin -> register
void ButtonTap::update(uint16_t* registerData, char bitIndex) {
  bool isPressed = digitalRead(pinData->pin);

  if (
    !pinData->isEventCatched &&
    pinData->pressStartTime != 0 &&
    pinData->pressEndTime != 0 &&
    static_cast<long>(pinData->pressEndTime - pinData->pressStartTime) > BUTTON_MIN_TAP_TIME &&
    !isPressed &&
    millis() - pinData->pressEndTime > BUTTON_TAP_TIMEOUT
  ) {
    writeEvent(registerData, bitIndex);
  }

  if (pinData->isEventCatched && !isPressed) {
    return clearTime();
  }

  updateTime(isPressed);
};