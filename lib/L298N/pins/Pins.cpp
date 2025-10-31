#include "Pins.h"
#include "pins/builder/L298N_Pins_Builder.h"


Pins::Pins(const L298N_Pins_Builder& builder): 
    in1Pin(builder.getIn1Pin()),
    in2Pin(builder.getIn2Pin()),
    in3Pin(builder.getIn3Pin()),
    in4Pin(builder.getIn4Pin()),
    enAPin(builder.getEnAPin()),
    enBPin(builder.getEnBPin())
{}

const uint8_t &Pins::getIn1Pin() const {
    return in1Pin.get();
}

const uint8_t &Pins::getIn2Pin() const {
    return in2Pin.get();
}

const uint8_t &Pins::getIn3Pin() const {
    return in3Pin.get();
}

const uint8_t &Pins::getIn4Pin() const {
    return in4Pin.get();
}

const uint8_t &Pins::getEnAPin() const {
    return enAPin.get();
}

const uint8_t &Pins::getEnBPin() const {
    return enBPin.get();
}

const uint8_t Pins::getIn1PinOr( uint8_t value) const {
    if (in1Pin.hasValue()) {
        return in1Pin.get();
    }
    return value;
}

const uint8_t Pins::getIn2PinOr(const uint8_t value) const {
    if (in2Pin.hasValue()) {
        return in2Pin.get();
    }
    return value;
}

const uint8_t Pins::getIn3PinOr(const uint8_t value) const {
    if (in3Pin.hasValue()) {
        return in3Pin.get();
    }
    return value;
}

const uint8_t Pins::getIn4PinOr(const uint8_t value) const {
    if (in4Pin.hasValue()) {
        return in4Pin.get();
    }
    return value;
}

const uint8_t Pins::getEnAPinOr(const uint8_t value) const {
    if (enAPin.hasValue()) {
        return enAPin.get();
    }
    return value;
}

const uint8_t Pins::getEnBPinOr(const uint8_t value) const {
    if (enBPin.hasValue()) {
        return enBPin.get();
    }
    return value;
}

const bool Pins::hasIn1Pin() const {
    return in1Pin.hasValue();
}

const bool Pins::hasIn2Pin() const {
    return in2Pin.hasValue();
}

const bool Pins::hasIn3Pin() const {
    return in3Pin.hasValue();
}

const bool Pins::hasIn4Pin() const {
    return in4Pin.hasValue();
}

const bool Pins::hasEnAPin() const {
    return enAPin.hasValue();
}

const bool Pins::hasEnBPin() const {
    return enBPin.hasValue();
}
