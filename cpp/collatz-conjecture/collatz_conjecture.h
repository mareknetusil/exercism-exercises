#pragma once

#include <cstdint>
#include <stdexcept>

namespace collatz_conjecture {

[[nodiscard]] constexpr int steps(int value) {
    static_assert(sizeof(int) <= 4, "int should be at most 32-bit to prevent overflow");

    if (value < 1) {
        throw std::domain_error{"Input must be positive!"};
    }

    std::int64_t value_ = value;
    int count = 0;
    while (value_ != 1) {
        value_ = value_ % 2 ? 3 * value_ + 1 : value_ / 2;
        ++count;
    }
    return count;
}

}  // namespace collatz_conjecture
