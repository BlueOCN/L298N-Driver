# 📘 `SimpleOptional<T>` Class Documentation

## Overview
`SimpleOptional<T>` is a lightweight, embedded-safe utility class that conditionally stores a value of type `T`. It provides a minimal alternative to `std::optional` for environments where dynamic memory, exceptions, or full STL support are unavailable.

This class is designed for **predictable behavior**, **zero heap usage**, and **compile-time safety**, making it ideal for bare-metal firmware, RTOS drivers, and embedded adapters.

---

## Template Parameters

| Parameter | Description |
|----------|-------------|
| `T`      | The type of value to store. Must be copy- or move-assignable. |

---

## Public Member Functions

### `SimpleOptional() noexcept`
Default constructor. Initializes the container in an uninitialized state.

---

### `SimpleOptional(SimpleOptional&& other) noexcept`
Move constructor. Transfers the value from another `SimpleOptional<T>` if it is initialized.

- **Behavior**: If `other` is initialized, its value is moved into this instance.
- **Postcondition**: `this->hasValue() == true` if `other.hasValue() == true`.

---

### `explicit operator bool() const noexcept`
Boolean conversion operator.

- **Returns**: `true` if the container holds a value, `false` otherwise.
- **Usage**: Enables idiomatic checks like `if (opt)`.

---

### `void set(const T& val) noexcept`
Sets the value by copy.

- **Parameters**: `val` — the value to store.
- **Postcondition**: `hasValue() == true`.

---

### `void set(T&& val) noexcept`
Sets the value by move.

- **Parameters**: `val` — the value to move into storage.
- **Postcondition**: `hasValue() == true`.

---

### `constexpr bool hasValue() const noexcept`
Checks whether the container holds a value.

- **Returns**: `true` if initialized, `false` otherwise.
- **Usage**: Prefer this over `operator bool()` for clarity in conditionals.

---

### `const T& get() const`
Returns a const reference to the stored value.

- **Precondition**: `hasValue() == true`
- **Behavior**: Triggers `assert()` if accessed while uninitialized.
- **Returns**: `const T&` — reference to the stored value.
- **Note**: This method is not `constexpr`-safe due to runtime `assert`.

---

### `void reset() noexcept`
Clears the stored value.

- **Postcondition**: `hasValue() == false`
- **Note**: The underlying value remains in memory but is considered invalid.

---

## Private Members

| Member        | Description |
|---------------|-------------|
| `bool initialized` | Tracks whether a value is currently stored. |
| `T value`          | The stored value. |

---

## Design Notes

- **No dynamic allocation**: All storage is static and inline.
- **No exceptions**: Uses `assert()` for runtime safety.
- **No copy constructor**: Intentional to avoid accidental duplication in embedded contexts. Add if needed.
- **Minimal interface**: Only essential methods are exposed to reduce surface area and cognitive load.

---

## Usage Example

```cpp
SimpleOptional<int> opt;
opt.set(42);

if (opt.hasValue()) {
    int val = opt.get(); // safe access
}

opt.reset();
```

---

## Integration Guidelines

- Use in place of raw pointers or flags when conditional value storage is needed.
- Ideal for driver configuration, optional parameters, or deferred initialization.
- Compatible with static allocation and deterministic startup.

---
