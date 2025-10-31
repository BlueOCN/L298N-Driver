#include "DriverFactory.h"

DriverInterface *DriverFactory::getDriver(Mode mode, Pins pins) {
    switch (mode) {
        case Mode::SingleMotor:
            return new SingleMotorAdapter(pins);

        case Mode::SingleMotorWithPWM:
            return new SingleMotorWithPWMAdapter(pins);

        case Mode::SingleMotorDoubleCurrent:
            return new SingleMotorDoubleCurrentAdapter(pins);

        case Mode::SingleMotorDoubleCurrentWithPWM:
            return new SingleMotorDoubleCurrentWithPWMAdapter(pins);

        case Mode::DualMotorBasic:
            return new DualMotorBasicAdapter(pins);

        case Mode::DualMotorWithOnePWM:
            return new DualMotorWithOnePWMAdapter(pins);

        case Mode::DualMotorWithTwoPWM:
            return new DualMotorWithTwoPWMAdapter(pins);
        
        default:
            return nullptr;
    }
}
