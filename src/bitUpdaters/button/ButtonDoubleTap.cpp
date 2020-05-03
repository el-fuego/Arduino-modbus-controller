#include <Arduino.h>
#include "./ButtonDoubleTap.h"


// pin -> register
void ButtonDoubleTap::update(uint16_t* registerData, char bitIndex) {
  bool isPressed = digitalRead(pinData->pin);

  if (
    !pinData->isEventCatched &&
    pinData->pressEndTime != 0 &&
    isPressed &&
    millis() - pinData->pressEndTime < BUTTON_TAP_TIMEOUT
  ) {
    writeEvent(registerData, bitIndex);
  }

  if (pinData->isEventCatched && !isPressed) {
    return clearTime();
  }

  updateTime(isPressed);
};