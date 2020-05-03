#include <ModbusRtu.h>
#include <Arduino-modbus-controller.h>

#define MODBUS_ID 1

// Use https://www.modbusdriver.com or any other modbus poller for test
// exaple usage: ./modpoll -b 115200 -p none -m rtu -c 12 /dev/ttyUSB0
Modbus modbus(MODBUS_ID, 0, 0);
Controller controller;

void setup() {
  modbus.begin( 115200 );

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
  modbus.poll(controller.registerData, REGISTERS_COUNT);

  controller.update();
}