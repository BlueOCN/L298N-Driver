#pragma once

#include "Arduino.h"
#include "drivers/DriverInterface.h"
#include "pins/Pins.h"

class DualMotorWithTwoPWMDriver {
    private:
        Pins pins;
    public:
        explicit DualMotorWithTwoPWMDriver(Pins p): pins(p) {};
        ~DualMotorWithTwoPWMDriver() = default;
        void begin();
        void start(MotorInstance motor, MotorDirection direction, uint8_t pwm);
        void stop(MotorInstance motor, uint8_t pwm);
};

