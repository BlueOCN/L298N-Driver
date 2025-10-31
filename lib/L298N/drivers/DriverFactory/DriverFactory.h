#pragma once

#include "modes/Mode.h"
#include "pins/Pins.h"
#include "drivers/DriverInterface.h"
#include "adapters/DualMotorBasicAdapter/DualMotorBasicAdapter.h"
#include "adapters/SingleMotorAdapter/SingleMotorAdapter.h"
#include "adapters/SingleMotorWithPWMAdapter/SingleMotorWithPWMAdapter.h"
#include "adapters/SingleMotorDoubleCurrentAdapter/SingleMotorDoubleCurrentAdapter.h"
#include "adapters/SingleMotorDoubleCurrentWithPWMAdapter/SingleMotorDoubleCurrentWithPWMAdapter.h"
#include "adapters/DualMotorWithOnePWMAdapter/DualMotorWithOnePWMAdapter.h"
#include "adapters/DualMotorWithTwoPWMAdapter/DualMotorWithTwoPWMAdapter.h"

class DriverFactory {
    public:
        DriverFactory() = default;
        ~DriverFactory() = default;
        DriverInterface* getDriver(Mode mode, Pins pins);
};
