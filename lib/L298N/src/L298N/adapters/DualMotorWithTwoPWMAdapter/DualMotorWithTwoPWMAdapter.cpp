#include "DualMotorWithTwoPWMAdapter.h"

void DualMotorWithTwoPWMAdapter::begin(const BeginParams &p) {
    driver.begin();
}

void DualMotorWithTwoPWMAdapter::start(const StartParams &p) {
    if (p.hasMotor() && p.hasDirection() && p.hasPwm()) {
        driver.start(p.getMotor(), p.getDirection(), p.getPwm());
    }
}

void DualMotorWithTwoPWMAdapter::stop(const StopParams &p) {
    if (p.hasMotor() && p.hasPwm()) {
        driver.stop(p.getMotor(), p.getPwm());
    }
}
