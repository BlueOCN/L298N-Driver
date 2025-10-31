#include "SingleMotorDoubleCurrentDriver.h"

void SingleMotorDoubleCurrentDriver::begin() {
    pinMode(pins.getIn1Pin(), OUTPUT);
    pinMode(pins.getIn2Pin(), OUTPUT);
    pinMode(pins.getIn3Pin(), OUTPUT);
    pinMode(pins.getIn4Pin(), OUTPUT);

}

void SingleMotorDoubleCurrentDriver::start(MotorDirection direction) {
    if (direction == MotorDirection::CLOCKWISE) {
        digitalWrite(pins.getIn1Pin(), HIGH);
        digitalWrite(pins.getIn2Pin(), LOW);
        digitalWrite(pins.getIn3Pin(), HIGH);
        digitalWrite(pins.getIn4Pin(), LOW);
    } else {
        digitalWrite(pins.getIn1Pin(), LOW);
        digitalWrite(pins.getIn2Pin(), HIGH);
        digitalWrite(pins.getIn3Pin(), LOW);
        digitalWrite(pins.getIn4Pin(), HIGH);
    }
}

void SingleMotorDoubleCurrentDriver::stop() {
    digitalWrite(pins.getIn1Pin(), LOW);
    digitalWrite(pins.getIn2Pin(), LOW);
    digitalWrite(pins.getIn3Pin(), LOW);
    digitalWrite(pins.getIn4Pin(), LOW);
}