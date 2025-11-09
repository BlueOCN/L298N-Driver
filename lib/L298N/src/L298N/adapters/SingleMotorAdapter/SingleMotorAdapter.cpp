#include "SingleMotorAdapter.h"

void SingleMotorAdapter::begin(const BeginParams &p) {
    driver.begin();
}

void SingleMotorAdapter::start(const StartParams &p) {
    if (p.hasDirection()) {
        driver.start(p.getDirection());
    }
}

void SingleMotorAdapter::stop(const StopParams &p) {
    driver.stop();
}
