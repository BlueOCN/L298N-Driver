#include <Arduino.h>
#include "L298N.h"
#include "pins/Pins.h"
#include "pins/builder/L298N_Pins_Builder.h"

Pins pins = L298N_Pins_Builder().setIn1Pin(1).setIn2Pin(2).build();
L298N driver = L298N(Mode::SingleMotor, pins);

L298N driver2 = L298N(Mode::DualMotorBasic, L298N_Pins_Builder().setIn1Pin(1).setIn2Pin(2).setIn3Pin(3).setIn4Pin(4).build());

void setup() {
  BeginParams bp;
  driver.begin(bp);
}

void loop() {

  StartParams sp;
  sp.setMotor(MotorInstance::ALL);
  sp.setDirection(MotorDirection::CLOCKWISE);
  driver.start(sp);
  delay(2000);

  StopParams sop;
  sp.setMotor(MotorInstance::ALL);
  driver.stop(sop);
  delay(1000);

}
