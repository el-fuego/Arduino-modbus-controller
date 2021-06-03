#include <Arduino.h>
#include "./SynchronizableTimeEmulator.h"


void SynchronizableTimeEmulator::init() {
  lastRegisterUpdateTimeMs = millis();
}

// registerData contains time in minutes to be updated externally
void SynchronizableTimeEmulator::update(uint16_t* registerData) {
  unsigned long currentTimeMs = millis();

  if (lastRegisterValue != *registerData) {
    lastRegisterUpdateTimeMs = currentTimeMs;
    currentTimeMinutes = *registerData;
    lastRegisterValue = *registerData;
    return;
  }

  currentTimeMinutes = *registerData + static_cast<int>((currentTimeMs - lastRegisterUpdateTimeMs) / (1000 * 60));
}
