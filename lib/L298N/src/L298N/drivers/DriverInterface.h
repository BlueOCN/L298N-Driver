#pragma once

#include <stdint.h>
#include <L298N/channels/MotorInstance.h>
#include <L298N/params/BeginParams/BeginParams.h>
#include <L298N/params/StartParams/StartParams.h>
#include <L298N/params/StopParams/StopParams.h>


class DriverInterface {
    public:
        virtual ~DriverInterface() {};
        virtual void begin(const BeginParams& p) = 0;
        virtual void start(const StartParams& p) = 0;
        virtual void stop(const StopParams& p) = 0;
};
