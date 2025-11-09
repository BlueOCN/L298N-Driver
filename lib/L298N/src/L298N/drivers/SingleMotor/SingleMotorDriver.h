#pragma once

#include <Arduino.h>
#include <L298N/pins/Pins.h>
#include "L298N/drivers/DriverInterface.h"

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
