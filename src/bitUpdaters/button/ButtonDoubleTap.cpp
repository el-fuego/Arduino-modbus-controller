#include <Arduino.h>
#include "./ButtonDoubleTap.h"


// pin -> register
void ButtonDoubleTap::update(uint16_t* registerData, char bitIndex) {
  bool isPressed = digitalRead(pinData->pin);

  if (
    !pinData->isEventCatched &&
    pinData->pressEndTimeMs != 0 &&
    isPressed &&
    millis() - pinData->pressEndTimeMs < BUTTON_TAP_TIMEOUT_MS
  ) {
    writeEvent(registerData, bitIndex);
  }

  if (pinData->isEventCatched && !isPressed) {
    return clearTime();
  }

  updateTime(isPressed);
};
