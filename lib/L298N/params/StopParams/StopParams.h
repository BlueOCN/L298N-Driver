#pragma once

#include "stdint.h"
#include "optionals/SimpleOptional.h"
#include "drivers/MotorInstance.h"

class StopParams {
    private:
        SimpleOptional<MotorInstance> motor;
        SimpleOptional<uint8_t> pwm;
    public:
        StopParams() = default;
        ~StopParams() = default;

        void setMotor(const MotorInstance m);
        void setPwm(const uint8_t p);

        const MotorInstance& getMotor() const;
        const uint8_t& getPwm() const;

        bool hasMotor() const;
        bool hasPwm() const;
};