#pragma once

#include "Arduino.h"
#include "drivers/DriverInterface.h"
#include "pins/Pins.h"

class SingleMotorDriver {
    private:
        Pins pins;
    public:
        explicit SingleMotorDriver(Pins p): pins(p) {}
        ~SingleMotorDriver() = default;
        void begin();
        void start(MotorDirection direction);
        void stop();
};
