#include "pangram.h"
#include <array>
#include <cmath>
#include <algorithm>
#include <cctype>

namespace pangram {

constexpr auto LETTER_COUNT = 'z' - 'a' + 1;

bool is_pangram(std::string_view text) {
    std::array<bool, LETTER_COUNT> seen{false};

    for (char c : text) {
        if (std::isalpha(c)) {
            seen[std::tolower(c) - 'a'] = true;
        }
    }

    return std::all_of(
        std::begin(seen), std::end(seen),
        [](bool b) { return b; }
    );
}

}  // namespace pangram
