#pragma once

#include "drivers/DriverInterface.h"
#include "drivers/DualMotorBasic/DualMotorBasicDriver.h"


class DualMotorBasicAdapter : public DriverInterface {
    private:
        DualMotorBasicDriver driver;
    public:
        explicit DualMotorBasicAdapter(Pins pins): driver(pins) {};
        ~DualMotorBasicAdapter() = default;

        void begin(const BeginParams& p) override;
        void start(const StartParams& p) override;
        void stop(const StopParams& p) override;
};

