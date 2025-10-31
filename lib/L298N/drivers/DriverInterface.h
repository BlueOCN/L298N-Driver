#pragma once

#include "stdint.h"
#include "drivers/MotorInstance.h"
#include "params/BeginParams/BeginParams.h"
#include "params/StartParams/StartParams.h"
#include "params/StopParams/StopParams.h"


class DriverInterface {
public:
    virtual ~DriverInterface() {};
    virtual void begin(const BeginParams& p) = 0;
    virtual void start(const StartParams& p) = 0;
    virtual void stop(const StopParams& p) = 0;
};
