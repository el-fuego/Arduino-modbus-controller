#include "./Bit.h"

Bit::Bit(uint16_t* _data, char _bitIndex, BitUpdater* _updater) :
 data(_data),
  bitIndex(_bitIndex),
   updater(_updater)
    {};

