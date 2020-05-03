#include "./Controller.h"

Register* Controller::addRegister() {
  registers[addedCount] = new Register(&registerData[addedCount]);
  addedCount++;

  return registers[addedCount - 1];
};

Register* Controller::addRegister(RegisterUpdater *updater) {
  registers[addedCount] = new Register(&registerData[addedCount], updater);
  addedCount++;
  
  return registers[addedCount - 1];
};

void Controller::skipRegister() {
  addedCount++;
};

void Controller::init() {
  for (char i = 0; i < addedCount; i++) {
    if (registers[i] != nullptr) {
      registers[i]->init();
    }
  }
};

void Controller::update() {
  for (char i = 0; i < addedCount; i++) {
    if (registers[i] != nullptr) {
      registers[i]->update();
    }
  }
};


