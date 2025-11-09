#pragma once

#include <Arduino.h>
#include <L298N/pins/Pins.h>
#include "L298N/drivers/DriverInterface.h"

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

