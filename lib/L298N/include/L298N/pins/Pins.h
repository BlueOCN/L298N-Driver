#pragma once

#include "stdint.h"
//#include "optionals/SimpleOptional.h"
#include <L298N/optionals/SimpleOptional.h>

class L298N_Pins_Builder;

class Pins {
    private:
        const SimpleOptional<uint8_t> in1Pin;
        const SimpleOptional<uint8_t> in2Pin;
        const SimpleOptional<uint8_t> in3Pin;
        const SimpleOptional<uint8_t> in4Pin;
        const SimpleOptional<uint8_t> enAPin;
        const SimpleOptional<uint8_t> enBPin;

    public:
        explicit Pins(const L298N_Pins_Builder& builder);

        const uint8_t& getIn1Pin() const;
        const uint8_t& getIn2Pin() const;
        const uint8_t& getIn3Pin() const;
        const uint8_t& getIn4Pin() const;
        const uint8_t& getEnAPin() const;
        const uint8_t& getEnBPin() const;

        const uint8_t getIn1PinOr(const uint8_t value) const;
        const uint8_t getIn2PinOr(const uint8_t value) const;
        const uint8_t getIn3PinOr(const uint8_t value) const;
        const uint8_t getIn4PinOr(const uint8_t value) const;
        const uint8_t getEnAPinOr(const uint8_t value) const;
        const uint8_t getEnBPinOr(const uint8_t value) const;

        const bool hasIn1Pin() const;
        const bool hasIn2Pin() const;
        const bool hasIn3Pin() const;
        const bool hasIn4Pin() const;
        const bool hasEnAPin() const;
        const bool hasEnBPin() const;

};
