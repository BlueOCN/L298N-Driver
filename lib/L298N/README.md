# L298N Library

A small, modular C++ library for controlling L298N motor driver configurations on Arduino and embedded platforms. The library exposes a simple public API while keeping driver implementations, adapters, and pin builders internal to the library implementation.

---

## Features

- Unified public API for motor control: begin, start, stop
- Multiple driver implementations and adapters (dual/single motor, PWM variants)
- Pins builder to configure wiring in a fluent way
- Small public headers in include/L298N and private implementation in src
- PlatformIO and Arduino friendly layout

---

## Contents

- Public API headers: include/L298N
  - L298N.h, L298N_Driver.h
  - channels/MotorInstance.h
  - directions/MotorDirection.h
  - modes/Mode.h
  - params/BeginParams, StartParams, StopParams
  - pins/Pins.h and pins/builder/L298N_Pins_Builder.h
- Private implementation: src/L298N
  - drivers/ (DriverInterface, DriverFactory, concrete drivers)
  - adapters/
  - params implementations
  - pins implementations

---

## Installation

PlatformIO
- Place the L298N folder under the project lib/ directory, or publish and add it via lib_deps in platformio.ini.

Arduino IDE
- Copy the L298N folder into the Arduino libraries folder (Documents/Arduino/libraries/) so the include path becomes <L298N/...>.

Note
- Public headers are under include/L298N. Use angle-bracket style includes shown in the examples below.

---

## Quick Start Example

Example demonstrating typical usage. This example assumes you have wiring set up and that your board supports the required pins.

```cpp
#include <Arduino.h>
#include <L298N/L298N.h>

using namespace l298n;

void setup() {
  // Build pins (example values)
  Pins pins = L298N_Pins_Builder()
                .setIn1Pin(2)
                .setIn2Pin(3)
                .setIn3Pin(4)
                .setIn4Pin(5)
                .build();

  // Create driver instance for a selected mode
  L298N driver(Mode::DualMotorBasic, pins);

  // Begin with default params
  BeginParams bp;
  driver.begin(bp);
}

void loop() {
  StartParams sp;
  sp.setMotor(ALL);
  sp.setDirection(CLOCKWISE);
  driver.start(sp);

  delay(2000);

  StopParams stop;
  stop.setMotor(ALL);
  driver.stop(stop);

  delay(1000);
}
```

---

## API Overview

- Class L298N (public)
  - L298N(Mode mode, Pins pins)
  - ~L298N()
  - void begin(const BeginParams& p)
  - void start(const StartParams& p)
  - void stop(const StopParams& p)

- Pins builder
  - L298N_Pins_Builder fluent setters and build()

- Enums and small types
  - Mode, MotorInstance, MotorDirection

- Params
  - BeginParams, StartParams, StopParams (declarations in include; implementations in src as needed)

Design note
- Public headers are intentionally minimal and stable. Concrete drivers and adapters implement an internal DriverInterface kept in src and are hidden from consumers.

---

## Wiring Guide

- Connect the L298N module power, ground, and motor outputs as usual for your motors.
- Use the pins configured in L298N_Pins_Builder to match your hardware wiring.
- Make sure the board provides sufficient current and correct supply voltage for motors.

---

## Build and Compatibility

- Frameworks: Arduino
- Platforms: Typical targets such as atmelavr and esp32 are supported; see library.json for exact platforms.
- PlatformIO will automatically add include/L298N to the compiler include path when the library is in lib/ or installed via the registry.

---

## Contributing

- Prefer API-stable changes in include/L298N. Internal implementation changes should live in src/.
- Add examples under examples/ when creating new usage demonstrations.
- Add unit tests under test/ when adding features that can be validated in CI.

---

## License

This library is provided under the license in the LICENSE file included with the library.

---

## Contact and Resources

- See library.json for repository and metadata.
- Use the public headers in include/L298N for integration: #include <L298N/L298N.h>  

---