#include "SingleMotorWithPWMAdapter.h"

void SingleMotorWithPWMAdapter::begin(const BeginParams &p) {
    driver.begin();
}

void SingleMotorWithPWMAdapter::start(const StartParams &p) {
    if (p.hasDirection() && p.hasPwm()) {
        driver.start(p.getDirection(), p.getPwm());
    }
}

void SingleMotorWithPWMAdapter::stop(const StopParams &p) {
    if (p.hasPwm()) {
        driver.stop(p.getPwm());
    }
}
