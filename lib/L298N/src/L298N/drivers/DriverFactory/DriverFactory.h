#pragma once

#include <L298N/modes/Mode.h>
#include <L298N/pins/Pins.h>
#include "L298N/drivers/DriverInterface.h"
#include "L298N/adapters/DualMotorBasicAdapter/DualMotorBasicAdapter.h"
#include "L298N/adapters/SingleMotorAdapter/SingleMotorAdapter.h"
#include "L298N/adapters/SingleMotorWithPWMAdapter/SingleMotorWithPWMAdapter.h"
#include "L298N/adapters/SingleMotorDoubleCurrentAdapter/SingleMotorDoubleCurrentAdapter.h"
#include "L298N/adapters/SingleMotorDoubleCurrentWithPWMAdapter/SingleMotorDoubleCurrentWithPWMAdapter.h"
#include "L298N/adapters/DualMotorWithOnePWMAdapter/DualMotorWithOnePWMAdapter.h"
#include "L298N/adapters/DualMotorWithTwoPWMAdapter/DualMotorWithTwoPWMAdapter.h"

class DriverFactory {
    public:
        DriverFactory() = default;
        ~DriverFactory() = default;
        DriverInterface* getDriver(Mode mode, Pins pins);
};
