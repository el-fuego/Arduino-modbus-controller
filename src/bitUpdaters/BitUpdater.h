#ifndef BIT_UPDATER
#define BIT_UPDATER

#include <inttypes.h>


class BitUpdater {
  public:
    virtual void init() = 0;
    virtual void update(uint16_t* registerData, char bitIndex) = 0;
};

#endif