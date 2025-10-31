#include "L298N_Pins_Builder.h"
#include "pins/Pins.h"

const SimpleOptional<uint8_t> &L298N_Pins_Builder::getIn1Pin() const {
    return in1Pin;
}

const SimpleOptional<uint8_t> &L298N_Pins_Builder::getIn2Pin() const {
    return in2Pin;
}

const SimpleOptional<uint8_t> &L298N_Pins_Builder::getIn3Pin() const {
    return in3Pin;
}

const SimpleOptional<uint8_t> &L298N_Pins_Builder::getIn4Pin() const {
    return in4Pin;
}

const SimpleOptional<uint8_t> &L298N_Pins_Builder::getEnAPin() const {
    return enAPin;
}

const SimpleOptional<uint8_t> &L298N_Pins_Builder::getEnBPin() const {
    return enBPin;
}

L298N_Pins_Builder &L298N_Pins_Builder::setIn1Pin(const uint8_t &pin) {
    this->in1Pin.set(pin);
    return *this;
}

L298N_Pins_Builder &L298N_Pins_Builder::setIn2Pin(const uint8_t &pin) {
    this->in2Pin.set(pin);
    return *this;
}

L298N_Pins_Builder &L298N_Pins_Builder::setIn3Pin(const uint8_t &pin) {
    this->in3Pin.set(pin);
    return *this;
}

L298N_Pins_Builder &L298N_Pins_Builder::setIn4Pin(const uint8_t &pin) {
    this->in4Pin.set(pin);
    return *this;
}

L298N_Pins_Builder &L298N_Pins_Builder::setEnAPin(const uint8_t &pin) {
    this->enAPin.set(pin);
    return *this;
}

L298N_Pins_Builder &L298N_Pins_Builder::setEnBPin(const uint8_t &pin) {
    this->enBPin.set(pin);
    return *this;
}

Pins L298N_Pins_Builder::build() {
    return Pins(*this);
}
