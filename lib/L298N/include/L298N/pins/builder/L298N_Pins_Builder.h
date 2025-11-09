#pragma once

#include <stdint.h>
#include <L298N/optionals/SimpleOptional.h>

class Pins;

class L298N_Pins_Builder {
    private:
        SimpleOptional<uint8_t> in1Pin;
        SimpleOptional<uint8_t> in2Pin;
        SimpleOptional<uint8_t> in3Pin;
        SimpleOptional<uint8_t> in4Pin;
        SimpleOptional<uint8_t> enAPin;
        SimpleOptional<uint8_t> enBPin;
    public:
        L298N_Pins_Builder(): in1Pin(), in2Pin(), in3Pin(), in4Pin(), enAPin(), enBPin() {}
        ~L298N_Pins_Builder() = default;

        const SimpleOptional<uint8_t>& getIn1Pin() const;
        const SimpleOptional<uint8_t>& getIn2Pin() const;
        const SimpleOptional<uint8_t>& getIn3Pin() const;
        const SimpleOptional<uint8_t>& getIn4Pin() const;
        const SimpleOptional<uint8_t>& getEnAPin() const;
        const SimpleOptional<uint8_t>& getEnBPin() const;

        L298N_Pins_Builder& setIn1Pin(const uint8_t& pin);
        L298N_Pins_Builder& setIn2Pin(const uint8_t& pin);
        L298N_Pins_Builder& setIn3Pin(const uint8_t& pin);
        L298N_Pins_Builder& setIn4Pin(const uint8_t& pin);
        L298N_Pins_Builder& setEnAPin(const uint8_t& pin);
        L298N_Pins_Builder& setEnBPin(const uint8_t& pin);
        Pins build();
};

