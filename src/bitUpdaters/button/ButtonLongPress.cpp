#include <Arduino.h>
#include "./ButtonLongPress.h"


// pin -> register
void ButtonLongPress::update(uint16_t* registerData, char bitIndex) {
  bool isPressed = digitalRead(pinData->pin);

  if (
    !pinData->isEventCatched &&
    isPressed &&
    pinData->pressStartTime != 0 &&
    pinData->pressEndTime == 0 &&
    millis() - pinData->pressStartTime > BUTTON_LONG_PRESS_TIME
  ) {
    writeEvent(registerData, bitIndex);
  }

  if (pinData->isEventCatched && !isPressed) {
    return clearTime();
  }

  updateTime(isPressed);
};