#include "rotational_cipher.h"
#include <cctype>

namespace rotational_cipher {

constexpr int ABC_SIZE = 'z' - 'a' + 1;

inline bool is_alpha(char c) {
    return std::isalpha(static_cast<unsigned char>(c));
}

inline bool is_upper(char c) {
    return std::isupper(static_cast<unsigned char>(c));
}

char rot_char(char c, int key) {
    const auto base = is_upper(c) ? 'A' : 'a';
    const auto pos = (c - base + key) % ABC_SIZE;
    return base + pos;
}

std::string rotate(std::string_view text, int key) {
    std::string retval;
    retval.reserve(text.size());
    key = (key % ABC_SIZE + ABC_SIZE) % ABC_SIZE; // normalization
    for (char c : text) {
        if (is_alpha(c)) {
            c = rot_char(c, key);
        }
        retval += c;
    }
    return retval;
}

}  // namespace rotational_cipher
