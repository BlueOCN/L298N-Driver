#include <Arduino.h>
#include <L298N/L298N_Driver.h>

Pins pins = L298N_Pins_Builder().setIn1Pin(2).setIn2Pin(3).build();
L298N driver = L298N(Mode::SingleMotor, pins);

void setup() {
  BeginParams bp;
  driver.begin(bp);
}

void loop() {

  StartParams sp;
  StopParams sop;

  sp.setMotor(ALL);
  sp.setDirection(CLOCKWISE);
  driver.start(sp);
  delay(2000);

  sop.setMotor(ALL);
  driver.stop(sop);
  delay(1000);

  sp.setDirection(COUNTER_CLOCKWISE);
  driver.start(sp);
  delay(2000);

  sop.setMotor(ALL);
  driver.stop(sop);
  delay(1000);

}
