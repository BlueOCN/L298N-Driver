#include "SingleMotorDriver.h"

void SingleMotorDriver::begin() {
    pinMode(pins.getIn1Pin(), OUTPUT);
    pinMode(pins.getIn2Pin(), OUTPUT);
}

void SingleMotorDriver::start(MotorDirection direction) {
    if (direction == MotorDirection::CLOCKWISE) {
        digitalWrite(pins.getIn1Pin(), HIGH);
        digitalWrite(pins.getIn2Pin(), LOW);
    } else {
        digitalWrite(pins.getIn1Pin(), LOW);
        digitalWrite(pins.getIn2Pin(), HIGH);
    }
    
}

void SingleMotorDriver::stop() {
    digitalWrite(pins.getIn1Pin(), LOW);
    digitalWrite(pins.getIn2Pin(), LOW);
}