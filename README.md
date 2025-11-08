# ST L298N Dual Full Bridge Driver for Arduino
🚀 A flexible and modular library for controlling DC motors using the L298N H-Bridge driver. Designed for rapid prototyping and scalable motor control across single and dual motor setups.
[Click here to access L298N datasheet!](https://www.st.com/resource/en/datasheet/l298.pdf "L298N's Datasheet")

## ![L298N Dual H Bridge DC Stepper Motor Module Twins Chip 3-550x550w](https://user-images.githubusercontent.com/107767647/174517043-9c2c1b10-d21c-4f86-a766-66006bcef72f.jpg)

## 📦 Features
- Supports 7 control modes including SingleMotor and DualMotorBasic
- Builder pattern for intuitive pin configuration
- Type-safe parameter objects for initialization and runtime control
- Clean separation of concerns for embedded architecture
- Easy integration with PlatformIO and Arduino IDE

## ⚠️ Caution
The L298N Driver Module has a 5V regulator that can be enabled/disabled using a jumper.

| Pin | With Jumper | Without Jumper |
|-|-|-|
| +12V | Expects an external voltage source of +12V | Expects an external voltage source of up to +30V |
| +5V | Regulator provides a regulated voltage of +5V | Expects an external voltage source of +5V |
| GND | Shared ground | Shared ground or Isolated ground |

## 🛠 Installation
Clone or download the repository and include it in your Arduino or PlatformIO project.

```bash
git clone https://github.com/BlueOCN/L298N-Driver.git
```

## 📚 Usage Example
```cpp
#include <Arduino.h>
#include "L298N.h"
#include "pins/Pins.h"
#include "pins/builder/L298N_Pins_Builder.h"

// Configure pins using builder pattern
Pins pins = L298N_Pins_Builder().setIn1Pin(1).setIn2Pin(2).build();
L298N driver = L298N(Mode::SingleMotor, pins);

// Dual motor configuration
L298N driver2 = L298N(Mode::DualMotorBasic,
  L298N_Pins_Builder()
    .setIn1Pin(1)
    .setIn2Pin(2)
    .setIn3Pin(3)
    .setIn4Pin(4)
    .build()
);

void setup() {
  BeginParams bp;
  driver.begin(bp);
}

void loop() {
  StartParams sp;
  StopParams sop;

  sp.setMotor(MotorInstance::ALL);
  sp.setDirection(MotorDirection::CLOCKWISE);
  driver.start(sp);
  delay(2000);

  sp.setMotor(MotorInstance::ALL);
  driver.stop(sop);
  delay(1000);

  sp.setMotor(MotorInstance::ALL);
  sp.setDirection(MotorDirection::COUNTER_CLOCKWISE);
  driver.start(sp);
  delay(2000);

  sp.setMotor(MotorInstance::ALL);
  driver.stop(sop);
  delay(1000);
}
```

## ⚙️ Supported Modes

| Mode                          | Description                                                                 |
|-------------------------------|-----------------------------------------------------------------------------|
| `SingleMotor`                 | Controls a single motor using IN1 and IN2 pins.                            |
| `SingleMotorWithPWM`         | Controls a single motor with PWM support for speed control.                |
| `SingleMotorDoubleCurrent`   | Drives a single motor using both channels of the H-Bridge for higher current. |
| `SingleMotorDoubleCurrentWithPWM` | Combines double current drive with PWM speed control for a single motor. |
| `DualMotorBasic`             | Controls two motors using IN1–IN4 pins without PWM.                        |
| `DualMotorWithOnePWM`        | Controls two motors with a shared PWM channel for basic speed control.     |
| `DualMotorWithTwoPWM`        | Controls two motors with independent PWM channels for precise speed control. |

## 🧱 Pin Configuration
Use the L298N_Pins_Builder to declaratively set up your motor pins:

```cpp
L298N_Pins_Builder()
  .setIn1Pin(1)
  .setIn2Pin(2)
  .setEnablePin(9)
  .build();
```

## 🧪 Parameters Overview
The library uses strongly typed parameter objects to configure motor behavior at runtime. These objects ensure clarity, safety, and extensibility when interacting with the driver. All parameter classes use SimpleOptional<T> internally, allowing you to omit fields you don't need. The driver will apply defaults or ignore unset fields based on the selected mode.

### 🔹 `BeginParams`
Used during initialization via `driver.begin(...)`.

- Currently a placeholder for future configuration options.
- Ensures consistent API even if no parameters are needed today.

```cpp
BeginParams bp;
driver.begin(bp);
```
### 🔹 `StartParams`
Used to start motor(s) with specific behavior.


|Field	|Type	|Description|
|-|-|-|
|motor	|MotorInstance	|Specifies which motor(s) to activate (e.g., MotorInstance::ALL, M1, M2).|
|direction	|MotorDirection	|Sets the rotation direction (CLOCKWISE or COUNTERCLOCKWISE).|
|pwm	|uint8_t	|Optional PWM value (0–255) for speed control (only in PWM-supported modes).|

```cpp
StartParams sp;
sp.setMotor(MotorInstance::ALL);
sp.setDirection(MotorDirection::CLOCKWISE);
sp.setPwm(128); // Optional
driver.start(sp);
```

### 🔹 `StopParams`
Used to stop motor(s) selectively or entirely.


|Field	|Type	|Description|
|-|-|-|
|motor	|MotorInstance	|Specifies which motor(s) to stop.|
|pwm	|uint8_t	|Optional PWM channel to stop (used in advanced PWM modes).|

```cpp
StopParams sop;
sop.setMotor(MotorInstance::M1);
driver.stop(sop);
```

## 🧰 PlatformIO Integration
Add this to your platformio.ini:
``` ini
lib_deps = BlueOCN/L298N-Driver
```

## 📄 License
MIT License. See LICENSE for details.

## 🤝 Contributing
Pull requests and issues are welcome! Help expand support for PWM, speed control, and advanced motor modes.
