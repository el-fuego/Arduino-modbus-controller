#ifndef SI7021_PIN_DATA
#define SI7021_PIN_DATA

#include <inttypes.h>
#include <Adafruit_Si7021.h>


struct Si7021_PinData {
  Adafruit_Si7021 sensor;
  bool isInited = false;
};

#endif