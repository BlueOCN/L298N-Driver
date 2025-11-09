#include "SingleMotorDoubleCurrentWithPWMAdapter.h"

void SingleMotorDoubleCurrentWithPWMAdapter::begin(const BeginParams &p) {
    driver.begin();
}

void SingleMotorDoubleCurrentWithPWMAdapter::start(const StartParams &p) {
    if (p.hasDirection() && p.hasPwm()) {
        driver.start(p.getDirection(), p.getPwm());
    }
}

void SingleMotorDoubleCurrentWithPWMAdapter::stop(const StopParams &p) {
    if (p.hasPwm()) {
        driver.stop(p.getPwm());
    }
}
