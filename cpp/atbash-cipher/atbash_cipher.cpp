#include "atbash_cipher.h"
#include <cctype>

namespace atbash_cipher {

char map_char(char c) {
    if (std::isdigit(c)) {
        return c;
    }

    const auto dist =  std::tolower(c) - 'a';
    return 'z' - dist;
}

std::string encode(std::string_view text) {
    std::string retval;
    retval.reserve(text.size() + text.size() / 5);
    for (const char c : text) {
        if (!std::isalnum(c)) {
            continue;
        }

        // If I'm about to add a 6th char without a space.
        if (retval.size() % 6 == 5) {
            retval += ' ';
        }

        retval += map_char(c);
    }
    return retval;
}

std::string decode(std::string_view text) {
    std::string retval;
    retval.reserve(text.size());
    for (const char c : text) {
        if (std::isalnum(c)) {
            retval += map_char(c);
        }
    }
    return retval;
}

}  // namespace atbash_cipher
