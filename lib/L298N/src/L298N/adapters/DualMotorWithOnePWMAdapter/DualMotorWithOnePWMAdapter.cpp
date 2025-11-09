#include "DualMotorWithOnePWMAdapter.h"

void DualMotorWithOnePWMAdapter::begin(const BeginParams &p) {
    driver.begin();
}

void DualMotorWithOnePWMAdapter::start(const StartParams &p) {
    if (p.hasMotor() && p.hasDirection() && p.hasPwm()) {
        driver.start(p.getMotor(), p.getDirection(), p.getPwm());
    }
}

void DualMotorWithOnePWMAdapter::stop(const StopParams &p) {
    if (p.hasMotor() && p.hasPwm()) {
        driver.stop(p.getMotor(), p.getPwm());
    }
}
