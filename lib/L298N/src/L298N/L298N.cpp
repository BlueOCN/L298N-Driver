#include <L298N/L298N.h>
#include "drivers/DriverInterface.h"
#include "drivers/DriverFactory/DriverFactory.h"

L298N::L298N(Mode mode, Pins pins) {
    DriverFactory driverFactory = DriverFactory();
    this->driver = driverFactory.getDriver(mode, pins);
}

L298N::~L298N() {
    if (driver) {
        delete driver;
        driver = nullptr;
    }
}

void L298N::begin(const BeginParams &p) {
    driver->begin(p);
}

void L298N::start(const StartParams &p) {
    driver->start(p);
}

void L298N::stop(const StopParams &p) {
    driver->stop(p);
}
