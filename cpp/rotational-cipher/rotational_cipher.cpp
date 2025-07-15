#include "rotational_cipher.h"
#include <cctype>
#include <stdexcept>

namespace rotational_cipher {

constexpr int ABC_SIZE = 'z' - 'a' + 1;

char rot_char(char c, int key) {
    const auto base = std::isupper(c) ? 'A' : 'a';
    const auto pos = (c - base + key) % ABC_SIZE;
    return base + pos;
}

std::string rotate(std::string_view text, int key) {
    std::string retval;
    retval.reserve(text.size());
    for (char c : text) {
        if (std::isalpha(c)) {
            c = rot_char(c, key);
        }
        retval += c;
    }
    return retval;
}

}  // namespace rotational_cipher
