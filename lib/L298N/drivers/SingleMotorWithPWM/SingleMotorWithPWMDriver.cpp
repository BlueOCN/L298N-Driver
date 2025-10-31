#include "SingleMotorWithPWMDriver.h"

void SingleMotorWithPWMDriver::begin() {
    pinMode(pins.getIn1Pin(), OUTPUT);
    pinMode(pins.getIn2Pin(), OUTPUT);
    pinMode(pins.getEnAPin(), OUTPUT);
}

void SingleMotorWithPWMDriver::start(MotorDirection direction, uint8_t pwm) {
    analogWrite(pins.getEnAPin(), pwm);
    if (direction == MotorDirection::CLOCKWISE) {
        digitalWrite(pins.getIn1Pin(), HIGH);
        digitalWrite(pins.getIn2Pin(), LOW);
    } else {
        digitalWrite(pins.getIn1Pin(), LOW);
        digitalWrite(pins.getIn2Pin(), HIGH);
    }
}

void SingleMotorWithPWMDriver::stop(uint8_t pwm) {
    digitalWrite(pins.getIn1Pin(), LOW);
    digitalWrite(pins.getIn2Pin(), LOW);
    analogWrite(pins.getEnAPin(), pwm);
}