#pragma once

#include <Arduino.h>
#include <L298N/pins/Pins.h>
#include "L298N/drivers/DriverInterface.h"

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

