#pragma once

#include <string_view>
#include <climits>
#include <optional>

namespace hexadecimal {

[[nodiscard]] constexpr long long convert(std::string_view text);

constexpr std::optional<int> char_to_number(char c) {
    // DIGIT
    if ('0' <= c && c <= '9') {
        return c - '0';
    }

    // LETTER
    const auto base = c >= 'a' ? 'a' : 'A';
    const auto val = 10 + c - base;
    if (10 <= val && val <= 15) {
        return val;
    }

    return std::nullopt;
}

constexpr long long convert(std::string_view text) {
    long long retval = 0;
    for (const auto c : text) {
        const auto number = char_to_number(c);
        if (!number) return 0;

        // OVERFLOW CHECK
        if (retval > (LLONG_MAX - *number) / 16) {
            return 0;
        }

        retval = retval * 16 + *number;
    }

    return retval;
}

}  // namespace hexadecimal
