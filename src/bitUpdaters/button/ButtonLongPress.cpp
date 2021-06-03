#include <Arduino.h>
#include "./ButtonLongPress.h"


// pin -> register
void ButtonLongPress::update(uint16_t* registerData, char bitIndex) {
  bool isPressed = digitalRead(pinData->pin);

  if (
    !pinData->isEventCatched &&
    isPressed &&
    pinData->pressStartTimeMs != 0 &&
    pinData->pressEndTimeMs == 0 &&
    millis() - pinData->pressStartTimeMs > BUTTON_LONG_PRESS_TIME_MS
  ) {
    writeEvent(registerData, bitIndex);
  }

  if (pinData->isEventCatched && !isPressed) {
    return clearTime();
  }

  updateTime(isPressed);
};
