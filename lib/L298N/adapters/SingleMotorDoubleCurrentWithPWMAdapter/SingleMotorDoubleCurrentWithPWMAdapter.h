#pragma once

#include "drivers/DriverInterface.h"
#include "drivers/SingleMotorDoubleCurrentWithPWM/SingleMotorDoubleCurrentWithPWMDriver.h"

class SingleMotorDoubleCurrentWithPWMAdapter: public DriverInterface {
    private:
        SingleMotorDoubleCurrentWithPWMDriver driver;
    public:
        explicit SingleMotorDoubleCurrentWithPWMAdapter(Pins pins): driver(pins) {};
        ~SingleMotorDoubleCurrentWithPWMAdapter() = default;

        void begin(const BeginParams& p) override;
        void start(const StartParams& p) override;
        void stop(const StopParams& p) override;
};

