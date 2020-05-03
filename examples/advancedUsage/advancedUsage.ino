#include <Arduino-modbus-controller.h>


#define REGISTERS_COUNT 3

class AverageValueInput: public RegisterUpdater {
  private:
    uint8_t pin1;
    uint8_t pin2;
    
  public:
    AverageValueInput(uint8_t _pin1, uint8_t _pin2): pin1(_pin1), pin2(_pin2) {};

    void init() {
      pinMode(pin1, INPUT);
      pinMode(pin2, INPUT);
    };

    void update(uint16_t* registerData) {
      *registerData = (analogRead(pin1) + analogRead(pin2)) / 2;
    };
};


Controller controller;

void setup() {
  Serial.begin(115200); // used for debug only

  // 0 register
  Register* bitsRegister = controller.addRegister();
  // 0 bit at 0 register
  bitsRegister->addBit(new DigitalInputPin(2));
  // skip 1 bit at 0 register
  bitsRegister->skipBit();
  // 2 bit at 0 register
  bitsRegister->addBit(new DigitalOutputPin(3));
  
  // skip 1 register
  controller.skipRegister();
  // 2 register
  controller.addRegister(new AverageValueInput(A1, A2));

  controller.init();
}

void loop() {
  controller.update();

  // used for debug only
  Serial.println(bitRead(controller.registerData[0], 0));
  Serial.println(bitRead(controller.registerData[0], 2));
  Serial.println(controller.registerData[2]);
  Serial.println("");
  delay(1000);
}