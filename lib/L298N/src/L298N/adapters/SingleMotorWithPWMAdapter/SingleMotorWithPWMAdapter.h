#pragma once

#include "L298N/drivers/DriverInterface.h"
#include "L298N/drivers/SingleMotorWithPWM/SingleMotorWithPWMDriver.h"

class SingleMotorWithPWMAdapter : public DriverInterface {
    private:
        SingleMotorWithPWMDriver driver;
    public:
        explicit SingleMotorWithPWMAdapter(Pins pins): driver(pins) {};
        ~SingleMotorWithPWMAdapter() = default;

        void begin(const BeginParams& p) override;
        void start(const StartParams& p) override;
        void stop(const StopParams& p) override;
};

