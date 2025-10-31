#pragma once

#include "drivers/DriverInterface.h"
#include "drivers/SingleMotor/SingleMotorDriver.h"

class SingleMotorAdapter : public DriverInterface {
    private:
        SingleMotorDriver driver;
    public:
        explicit SingleMotorAdapter(Pins pins): driver(pins) {};
        ~SingleMotorAdapter() = default;

        void begin(const BeginParams& p) override;
        void start(const StartParams& p) override;
        void stop(const StopParams& p) override;
};

