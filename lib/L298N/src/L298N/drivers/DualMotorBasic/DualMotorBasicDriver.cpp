#include "DualMotorBasicDriver.h"

void DualMotorBasicDriver::begin() {
    pinMode(pins.getIn1Pin(), OUTPUT);
    pinMode(pins.getIn2Pin(), OUTPUT);
    pinMode(pins.getIn3Pin(), OUTPUT);
    pinMode(pins.getIn4Pin(), OUTPUT);
}

void DualMotorBasicDriver::start(MotorInstance motor, MotorDirection direction) {
    switch (motor) {
        case MotorInstance::A:
            if (MotorDirection::CLOCKWISE) {
                digitalWrite(pins.getIn1Pin(), HIGH);
                digitalWrite(pins.getIn2Pin(), LOW);
            } else {
                digitalWrite(pins.getIn1Pin(), LOW);
                digitalWrite(pins.getIn2Pin(), HIGH);
            }
            break;

        case MotorInstance::B:
            if (MotorDirection::CLOCKWISE) {
                digitalWrite(pins.getIn3Pin(), HIGH);
                digitalWrite(pins.getIn4Pin(), LOW);
            } else {
                digitalWrite(pins.getIn3Pin(), LOW);
                digitalWrite(pins.getIn4Pin(), HIGH);
            }
            break;

        case MotorInstance::ALL:
            if (MotorDirection::CLOCKWISE) {
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
            break;
        
        default:
            break;
    }
}

void DualMotorBasicDriver::stop(MotorInstance motor) {
    switch (motor) {
        case MotorInstance::A:
            digitalWrite(pins.getIn1Pin(), LOW);
            digitalWrite(pins.getIn2Pin(), LOW);
            break;

        case MotorInstance::B:
            digitalWrite(pins.getIn3Pin(), LOW);
            digitalWrite(pins.getIn4Pin(), LOW);
            break;

        case MotorInstance::ALL:
            digitalWrite(pins.getIn1Pin(), LOW);
            digitalWrite(pins.getIn2Pin(), LOW);
            digitalWrite(pins.getIn3Pin(), LOW);
            digitalWrite(pins.getIn4Pin(), LOW);
            break;
    
        default:
            break;
    }
}
