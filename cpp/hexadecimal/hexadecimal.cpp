#include "hexadecimal.h"
#include <iterator>
#include <stdexcept>

namespace hexadecimal {

int convert(std::string_view text) {
    int retval = 0;
    for (const auto c : text) {
        // DIGIT
        if ('0' <= c && c <= '9') {
            retval = retval * 16 + c - '0';
            continue;
        }

        // LETTER
        const auto base = c >= 'a' ? 'a' : 'A';
        const auto val = 10 + c - base;
        if (10 <= val && val <=15) {
            retval = retval * 16 + val;
            continue;
        }

        // INVALID CHARACTER
        return 0;
    }
    return retval;
}

}  // namespace hexadecimal
