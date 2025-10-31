#pragma once

#include "stdint.h"
#include "modes/Mode.h"
#include "pins/Pins.h"
#include "params/BeginParams/BeginParams.h"
#include "params/StartParams/StartParams.h"
#include "drivers/DriverInterface.h"
#include "drivers/DriverFactory/DriverFactory.h"

class L298N : public DriverInterface {
    private:
        DriverInterface* driver = nullptr;

    public:
        L298N(Mode mode, Pins pins);
        ~L298N();

        void begin(const BeginParams& p) override;
        void start(const StartParams& p) override;
        void stop(const StopParams& p) override;
};

inline L298N::L298N(Mode mode, Pins pins) {
    DriverFactory driverFactory = DriverFactory();
    this->driver = driverFactory.getDriver(mode, pins);
}

inline L298N::~L298N() {
    if (driver) {
        delete driver;
        driver = nullptr;
    }
}

inline void L298N::begin(const BeginParams &p) {
    driver->begin(p);
}

inline void L298N::start(const StartParams &p) {
    driver->start(p);
}

inline void L298N::stop(const StopParams &p) {
    driver->stop(p);
}
