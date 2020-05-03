#ifndef REGISTER
#define REGISTER

#include <inttypes.h>
#include "./Bit.h"
#include "./registerUpdaters/RegisterUpdater.h"


class Register {
  private:
    uint16_t* data;
    Bit* bits[16] = {0};
    char addedCount = 0;
    RegisterUpdater *updater = 0;

  public:
    Register(uint16_t* _data, RegisterUpdater* _updater);
    Register(uint16_t* _data);
  
    Bit* addBit(BitUpdater* updater);
    void skipBit();
    void init();
    void update();
};

#endif