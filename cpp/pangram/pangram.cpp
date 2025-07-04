#include "pangram.h"
#include <bitset>

namespace pangram {

constexpr auto LETTER_COUNT = 'z' - 'a' + 1;

bool is_pangram(std::string_view text) {
    std::bitset<LETTER_COUNT> seen;

    for (char c : text) {
        if (std::isalpha(c)) {
            seen.set(std::tolower(c) - 'a');
        }
    }

    return seen.all();
}

}  // namespace pangram
