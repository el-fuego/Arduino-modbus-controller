#include <Arduino.h>
#include "./ButtonTap.h"


// pin -> register
void ButtonTap::update(uint16_t* registerData, char bitIndex) {
  bool isPressed = digitalRead(pinData->pin);

  if (
    !pinData->isEventCatched &&
    pinData->pressStartTimeMs != 0 &&
    pinData->pressEndTimeMs != 0 &&
    static_cast<long>(pinData->pressEndTimeMs - pinData->pressStartTimeMs) > BUTTON_MIN_TAP_TIME_MS &&
    !isPressed &&
    millis() - pinData->pressEndTimeMs > BUTTON_TAP_TIMEOUT_MS
  ) {
    writeEvent(registerData, bitIndex);
  }

  if (pinData->isEventCatched && !isPressed) {
    return clearTime();
  }

  updateTime(isPressed);
};
