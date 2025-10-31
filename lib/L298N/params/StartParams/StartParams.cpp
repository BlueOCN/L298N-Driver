#include "StartParams.h"

void StartParams::setMotor(const MotorInstance m) {
    motor.set(m);
}

void StartParams::setDirection(const MotorDirection md) {
    direction.set(md);
}

void StartParams::setPwm(const uint8_t p) {
    pwm.set(p);
}

const MotorInstance &StartParams::getMotor() const {
    return motor.get();
}

const MotorDirection &StartParams::getDirection() const {
    return direction.get();
}

const uint8_t &StartParams::getPwm() const {
    return pwm.get();
}

bool StartParams::hasMotor() const {
    return motor.hasValue();
}

bool StartParams::hasDirection() const {
    return direction.hasValue();
}

bool StartParams::hasPwm() const
{
    return pwm.hasValue();
}
