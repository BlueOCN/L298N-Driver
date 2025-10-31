#pragma once

#include "Arduino.h"
#include "pins/Pins.h"
#include "drivers/MotorDirection.h"

class SingleMotorWithPWMDriver {
    private:
        Pins pins;
    public:
        explicit SingleMotorWithPWMDriver(Pins p): pins(p) {}
        ~SingleMotorWithPWMDriver() = default;
        void begin();
        void start(MotorDirection direction, uint8_t pwm);
        void stop(uint8_t pwm);
};
