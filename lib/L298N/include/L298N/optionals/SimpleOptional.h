#pragma once

#include "assert.h"

template<typename T> class SimpleOptional {
    private:
        bool initialized = false;
        T value;
    public:
        constexpr SimpleOptional() noexcept : initialized(false), value{} {}
        SimpleOptional(const SimpleOptional&) = default;
        SimpleOptional& operator=(const SimpleOptional&) = default;

        // SimpleOptional(SimpleOptional&& other) noexcept {
        //     if (other.initialized) {
        //         value = move(other.value);
        //         initialized = true;
        //     }
        // }

        constexpr explicit operator bool() const noexcept {
            return initialized;
        }

        void set(const T& val) noexcept {
            value = val;
            initialized = true;
        }

        void set(T&& val) noexcept {
            value = move(val);
            initialized = true;
        }

        constexpr bool hasValue() const noexcept {
            return initialized;
        }

        const T& get() const {
            assert(initialized);
            return value;
        }

        void reset() noexcept {
            initialized = false;
        }
};
