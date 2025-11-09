#include "DualMotorWithOnePWMDriver.h"

void DualMotorWithOnePWMDriver::begin() {
    pinMode(pins.getIn1Pin(), OUTPUT);
    pinMode(pins.getIn2Pin(), OUTPUT);
    pinMode(pins.getIn3Pin(), OUTPUT);
    pinMode(pins.getIn4Pin(), OUTPUT);
    pinMode(pins.getEnAPin(), OUTPUT);
}

void DualMotorWithOnePWMDriver::start(MotorInstance motor, MotorDirection direction, uint8_t pwm) {
    switch (motor) {
        case MotorInstance::A:
            if (MotorDirection::CLOCKWISE) {
                digitalWrite(pins.getIn1Pin(), HIGH);
                digitalWrite(pins.getIn2Pin(), LOW);
                analogWrite(pins.getEnAPin(), pwm);
            } else {
                digitalWrite(pins.getIn1Pin(), LOW);
                digitalWrite(pins.getIn2Pin(), HIGH);
                analogWrite(pins.getEnAPin(), pwm);
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
                analogWrite(pins.getEnAPin(), pwm);
            } else {
                digitalWrite(pins.getIn1Pin(), LOW);
                digitalWrite(pins.getIn2Pin(), HIGH);
                digitalWrite(pins.getIn3Pin(), LOW);
                digitalWrite(pins.getIn4Pin(), HIGH);
                analogWrite(pins.getEnAPin(), pwm);
            }
            break;
        
        default:
            break;
    }
}

void DualMotorWithOnePWMDriver::stop(MotorInstance motor, uint8_t pwm) {
    switch (motor) {
        case MotorInstance::A:
            digitalWrite(pins.getIn1Pin(), LOW);
            digitalWrite(pins.getIn2Pin(), LOW);
            analogWrite(pins.getEnAPin(), pwm);
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
            analogWrite(pins.getEnAPin(), pwm);
            break;
    
        default:
            break;
    }
}
