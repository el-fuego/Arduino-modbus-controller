#include <Arduino-modbus-controller.h>
#include <registerUpdaters/Si7021/index.h>
#include <registerUpdaters/oneWireTemperature/index.h>
#include <bitUpdaters/button/index.h>


Controller controller;

// One pin can have few devices and/or register updaters, so you need to share sensors config
ButtonPinData buttonPinData(3); // button on pin 3
OneWireTemperaturePinData temperaturePinData(2); // one wire temperature sensors on pin 2
Si7021_PinData si7021PinData; // temperature and humidity sensor on I2C

// For the multipple sensors on single pin
DeviceAddress firstTemperatureSensorAddress = { 0x28, 0x1D, 0x39, 0x31, 0x2, 0x0, 0x0, 0xF0 };
DeviceAddress secondTemperatureSensorAddress = { 0x30, 0x1D, 0x39, 0x31, 0x2, 0x0, 0x0, 0xF0 };

unsigned long lastPrintTime = 0; // Used for debug only

void setup() {
  Serial.begin(115200); // Used for debug only

  Register* bitsRegister = controller.addRegister();
  // Note: button bits is need to be cleared after reading by master device
  // Use DigitalInputPin in case of dumb slave
  bitsRegister->addBit(new ButtonTap(&buttonPinData));
  bitsRegister->addBit(new ButtonDoubleTap(&buttonPinData));
  bitsRegister->addBit(new ButtonLongPress(&buttonPinData));
  
  controller.addRegister(new Si7021_Temperature(&si7021PinData));
  controller.addRegister(new Si7021_Humidity(&si7021PinData));
  controller.addRegister(new OneWireTemperature(&temperaturePinData, firstTemperatureSensorAddress));
  controller.addRegister(new OneWireTemperature(&temperaturePinData, secondTemperatureSensorAddress));

  controller.init();
}

void loop() {
  controller.update();

  // Used for debug only
  if (millis() - lastPrintTime > 500) {
    lastPrintTime = millis();
    Serial.println(bitRead(controller.registerData[0], 0));
    Serial.println(bitRead(controller.registerData[0], 1));
    Serial.println(bitRead(controller.registerData[0], 2));
    Serial.println(controller.registerData[1]);
    Serial.println(controller.registerData[2]);
    Serial.println(controller.registerData[3]);
    Serial.println(controller.registerData[4]);
    Serial.println("");

    // !!! Don`t forgot to connect sensors to pins to see real values
    // !!! Use resistor (1-200k) from button pin to GND to avoid failure pressing
  }
}
