#pragma once

#include "Arduino.h"
#include "drivers/DriverInterface.h"
#include "pins/Pins.h"

class SingleMotorDoubleCurrentWithPWMDriver {
    private:
        Pins pins;
    public:
        explicit SingleMotorDoubleCurrentWithPWMDriver(Pins p): pins(p) {};
        ~SingleMotorDoubleCurrentWithPWMDriver() = default;
        void begin();
        void start(MotorDirection direction, uint8_t pwm);
        void stop(uint8_t pwm);
};

