#ifndef REGISTER_UPDATER
#define REGISTER_UPDATER

#include <inttypes.h>


class RegisterUpdater {
  public:
    virtual void init() = 0;
    virtual void update(uint16_t* registerData) = 0;
};

#endif