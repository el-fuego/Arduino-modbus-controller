#include "./Register.h"

Register::Register(uint16_t* _data, RegisterUpdater* _updater) : data(_data), updater(_updater) {};
Register::Register(uint16_t* _data) : data(_data) {};

Bit* Register::addBit(BitUpdater* updater) {
  bits[addedCount] = new Bit(data, addedCount, updater);
  addedCount++;
  
  return bits[addedCount - 1];
};

void Register::skipBit() {
  addedCount++;
};

void Register::init() {
  if (updater != nullptr) {
    return updater->init();
  }
  
  for (char i = 0; i < 16; i++) {
    if (bits[i] != nullptr) {
      bits[i]->updater->init();
    }
  }
};

void Register::update() {
  if (updater != nullptr) {
    return updater->update(data);
  }
  
  for (char i = 0; i < 16; i++) {
    if (bits[i] != nullptr) {
      bits[i]->updater->update(data, i);
    }
  }
};