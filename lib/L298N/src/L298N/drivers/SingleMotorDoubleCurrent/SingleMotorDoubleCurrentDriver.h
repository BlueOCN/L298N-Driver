#pragma once

#include <Arduino.h>
#include <L298N/pins/Pins.h>
#include <L298N/directions/MotorDirection.h>

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
