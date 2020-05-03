#include <Arduino-modbus-controller.h>


Controller controller;

void setup() {
  Serial.begin(115200); // used for debug only

  // 0 register
  Register* bitsRegister = controller.addRegister();
  // 0 bit at 0 register
  bitsRegister->addBit(new DigitalInputPin(2));
  // 1 bit at 0 register
  bitsRegister->addBit(new DigitalOutputPin(3));
  
  // 1 register
  controller.addRegister(new AnalogInputPin(A1));
  // 2 register
  controller.addRegister(new AnalogOutputPin(A2));

  controller.init();
}

void loop() {
  controller.update();

  // used for debug only
  Serial.println(bitRead(controller.registerData[0], 0));
  Serial.println(bitRead(controller.registerData[0], 1));
  Serial.println(controller.registerData[1]);
  Serial.println(controller.registerData[2]);
  Serial.println("");
  delay(1000);
}