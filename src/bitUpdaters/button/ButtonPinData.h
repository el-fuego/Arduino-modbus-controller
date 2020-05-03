#ifndef BUTTON_PIN_DATA
#define BUTTON_PIN_DATA

#include <inttypes.h>


struct ButtonPinData {
  uint8_t pin;
  unsigned long pressStartTime = 0;
  unsigned long pressEndTime = 0;
  bool isEventCatched = false;
  bool isInited = false;
  ButtonPinData(uint8_t _pin);
};

#endif