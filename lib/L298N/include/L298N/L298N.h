#pragma once

#include <stdint.h>
#include <L298N/modes/Mode.h>
#include <L298N/pins/Pins.h>
#include <L298N/params/BeginParams/BeginParams.h>
#include <L298N/params/StartParams/StartParams.h>
#include <L298N/params/StopParams/StopParams.h>

class DriverInterface;

class L298N {
    private:
        DriverInterface* driver = nullptr;

    public:
        L298N(Mode mode, Pins pins);
        ~L298N();

        void begin(const BeginParams& p);
        void start(const StartParams& p);
        void stop(const StopParams& p);
};

