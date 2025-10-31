#include "DualMotorBasicAdapter.h"

void DualMotorBasicAdapter::begin(const BeginParams &p) {
    driver.begin();
}

void DualMotorBasicAdapter::start(const StartParams &p) {
    if (p.hasMotor() && p.hasDirection()) {
        driver.start(p.getMotor(), p.getDirection());
    }
}

void DualMotorBasicAdapter::stop(const StopParams &p) {
    if (p.hasMotor()) {
        driver.stop(p.getMotor());
    }
}
