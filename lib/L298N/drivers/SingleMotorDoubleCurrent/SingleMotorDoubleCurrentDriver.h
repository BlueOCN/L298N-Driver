#pragma once

#include "Arduino.h"
#include "pins/Pins.h"
#include "drivers/MotorDirection.h"

class SingleMotorDoubleCurrentDriver {
    private:
        Pins pins;
    public:
        explicit SingleMotorDoubleCurrentDriver(Pins p): pins(p) {}
        ~SingleMotorDoubleCurrentDriver() = default;
        void begin();
        void start(MotorDirection direction);
        void stop();
};
