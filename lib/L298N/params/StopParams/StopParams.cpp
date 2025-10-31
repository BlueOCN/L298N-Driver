#include "StopParams.h"

void StopParams::setMotor(const MotorInstance m) {
    motor.set(m);
}

void StopParams::setPwm(const uint8_t p) {
    pwm.set(p);
}

const MotorInstance & StopParams::getMotor() const {
    return motor.get();
}

const uint8_t &StopParams::getPwm() const {
    return pwm.get();
}

bool StopParams::hasMotor() const {
    return motor.hasValue();
}

bool StopParams::hasPwm() const {
    return pwm.hasValue();
}
