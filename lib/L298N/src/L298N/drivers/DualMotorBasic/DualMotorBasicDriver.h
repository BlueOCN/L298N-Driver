#pragma once

#include <Arduino.h>
#include <L298N/pins/Pins.h>
#include "L298N/drivers/DriverInterface.h"

class DualMotorBasicDriver {
    private:
        Pins pins;
    public:
        explicit DualMotorBasicDriver(Pins p): pins(p) {};
        ~DualMotorBasicDriver() = default;
        void begin();
        void start(MotorInstance motor, MotorDirection direction);
        void stop(MotorInstance motor);
};

