#pragma once

#include "L298N/drivers/DriverInterface.h"
#include "L298N/drivers/SingleMotorDoubleCurrent/SingleMotorDoubleCurrentDriver.h"

class SingleMotorDoubleCurrentAdapter: public DriverInterface {
    private:
        SingleMotorDoubleCurrentDriver driver;
    public:
        explicit SingleMotorDoubleCurrentAdapter(Pins pins): driver(pins) {};
        ~SingleMotorDoubleCurrentAdapter() = default;

        void begin(const BeginParams& p) override;
        void start(const StartParams& p) override;
        void stop(const StopParams& p) override;
};

