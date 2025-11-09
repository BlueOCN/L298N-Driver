#include "SingleMotorDoubleCurrentAdapter.h"

void SingleMotorDoubleCurrentAdapter::begin(const BeginParams &p) {
    driver.begin();
}

void SingleMotorDoubleCurrentAdapter::start(const StartParams &p) {
    if (p.hasDirection()) {
        driver.start(p.getDirection());
    }
}

void SingleMotorDoubleCurrentAdapter::stop(const StopParams &p) {
    driver.stop();
}
