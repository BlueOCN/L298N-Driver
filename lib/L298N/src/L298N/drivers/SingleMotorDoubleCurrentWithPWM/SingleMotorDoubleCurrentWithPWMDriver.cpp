#include "SingleMotorDoubleCurrentWithPWMDriver.h"

void SingleMotorDoubleCurrentWithPWMDriver::begin() {
    pinMode(pins.getIn1Pin(), OUTPUT);
    pinMode(pins.getIn2Pin(), OUTPUT);
    pinMode(pins.getIn3Pin(), OUTPUT);
    pinMode(pins.getIn4Pin(), OUTPUT);
    pinMode(pins.getEnAPin(), OUTPUT);
    pinMode(pins.getEnBPin(), OUTPUT);
}

void SingleMotorDoubleCurrentWithPWMDriver::start(MotorDirection direction, uint8_t pwm) {
    analogWrite(pins.getEnAPin(), pwm);
    analogWrite(pins.getEnBPin(), pwm);
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
}

void SingleMotorDoubleCurrentWithPWMDriver::stop(uint8_t pwm) {
    analogWrite(pins.getEnAPin(), pwm);
    analogWrite(pins.getEnBPin(), pwm);
    digitalWrite(pins.getIn1Pin(), LOW);
    digitalWrite(pins.getIn2Pin(), LOW);
    digitalWrite(pins.getIn3Pin(), LOW);
    digitalWrite(pins.getIn4Pin(), LOW);
}
