#pragma once

#include "Arduino.h"
#include "drivers/DriverInterface.h"
#include "pins/Pins.h"

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

