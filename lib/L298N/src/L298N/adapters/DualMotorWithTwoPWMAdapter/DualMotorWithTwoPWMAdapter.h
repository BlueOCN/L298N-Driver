#pragma once

#include "L298N/drivers/DriverInterface.h"
#include "L298N/drivers/DualMotorWithTwoPWM/DualMotorWithTwoPWMDriver.h"

class DualMotorWithTwoPWMAdapter: public DriverInterface {
    private:
        DualMotorWithTwoPWMDriver driver;
    public:
        explicit DualMotorWithTwoPWMAdapter(Pins pins): driver(pins) {};
        ~DualMotorWithTwoPWMAdapter() = default;

        void begin(const BeginParams& p) override;
        void start(const StartParams& p) override;
        void stop(const StopParams& p) override;
};

