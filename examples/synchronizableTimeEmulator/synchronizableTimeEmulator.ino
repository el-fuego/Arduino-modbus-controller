#include <ModbusRtu.h>
#include <Arduino-modbus-controller.h>
#include <registerUpdaters/synchronizableTimeEmulator/index.h>

#define MODBUS_ID 1

// Use https://www.modbusdriver.com or any other modbus poller for test
// exaple usage: ./modpoll -b 115200 -p none -m rtu -c 12 /dev/ttyUSB0
Modbus modbus(MODBUS_ID, 0, 0);
Controller controller;

SynchronizableTimeEmulator* timer = new SynchronizableTimeEmulator();

unsigned long lastPrintTimeMs = 0; // Used for debug only

void setup() {
  modbus.begin( 115200 );

  // 0 register
  controller.addRegister(timer);

  controller.init();
}

void loop() {
  // update registers from Modbus
  modbus.poll(controller.registerData, REGISTERS_COUNT);

  // calculate actual time in minutes
  controller.update();

  // Condition is used for the debug only
  if (millis() - lastPrintTimeMs > 500) {
    lastPrintTimeMs = millis();

    int hours = timer->currentTimeMinutes / 60;
    int minutes = timer->currentTimeMinutes - hours * 60;

    Serial.print(hours);
    Serial.print(":");
    Serial.print(minutes);
    Serial.println("");
  }
}
