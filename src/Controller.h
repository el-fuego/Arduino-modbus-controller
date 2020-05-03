#ifndef CONTROLLER
#define CONTROLLER

#include <inttypes.h>
#include "./Register.h"

#define REGISTERS_COUNT 12

class Controller {
  private:
    Register* registers[REGISTERS_COUNT] = {0};
    char addedCount = 0;

  public:
    uint16_t registerData[REGISTERS_COUNT];

    Register* addRegister();
    Register* addRegister(RegisterUpdater *updater);
    void skipRegister();
    void init();
    void update();
};

#endif