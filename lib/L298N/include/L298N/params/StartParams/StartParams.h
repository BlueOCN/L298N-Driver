#pragma once

#include <stdint.h>
#include <L298N/optionals/SimpleOptional.h>
#include <L298N/channels/MotorInstance.h>
#include <L298N/directions/MotorDirection.h>

class StartParams {
    private:
        SimpleOptional<MotorInstance> motor;
        SimpleOptional<MotorDirection> direction;
        SimpleOptional<uint8_t> pwm;
    public:
        StartParams() = default;
        ~StartParams() = default;

        void setMotor(const MotorInstance m);
        void setDirection(const MotorDirection md);
        void setPwm(const uint8_t p);

        const MotorInstance& getMotor() const;
        const MotorDirection& getDirection() const;
        const uint8_t& getPwm() const;

        bool hasMotor() const;
        bool hasDirection() const;
        bool hasPwm() const;
};
