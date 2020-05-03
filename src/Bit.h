#ifndef BIT
#define BIT

#include <inttypes.h>
#include "./bitUpdaters/BitUpdater.h"


class Bit {
  private:
    uint16_t* data;
    char bitIndex;

  public:
    BitUpdater* updater;
  
    Bit(uint16_t* _data, char _bitIndex, BitUpdater* _updater);
};

#endif