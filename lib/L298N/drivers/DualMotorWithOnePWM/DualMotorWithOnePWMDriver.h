#pragma once

#include "Arduino.h"
#include "drivers/DriverInterface.h"
#include "pins/Pins.h"

class DualMotorWithOnePWMDriver {
    private:
        Pins pins;
    public:
        explicit DualMotorWithOnePWMDriver(Pins p): pins(p) {};
        ~DualMotorWithOnePWMDriver() = default;
        void begin();
        void start(MotorInstance motor, MotorDirection direction, uint8_t pwm);
        void stop(MotorInstance motor, uint8_t pwm);
};

