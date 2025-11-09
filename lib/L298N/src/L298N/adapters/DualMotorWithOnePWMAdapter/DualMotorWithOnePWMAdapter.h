#pragma once

#include "L298N/drivers/DriverInterface.h"
#include "L298N/drivers/DualMotorWithOnePWM/DualMotorWithOnePWMDriver.h"

class DualMotorWithOnePWMAdapter: public DriverInterface {
    private:
        DualMotorWithOnePWMDriver driver;
    public:
        explicit DualMotorWithOnePWMAdapter(Pins pins): driver(pins) {};
        ~DualMotorWithOnePWMAdapter() = default;

        void begin(const BeginParams& p) override;
        void start(const StartParams& p) override;
        void stop(const StopParams& p) override;
};
