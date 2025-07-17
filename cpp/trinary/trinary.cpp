#include "trinary.h"

namespace trinary {

unsigned to_decimal(std::string_view text) {
    unsigned retval = 0;
    for (const char c : text) {
        if (c < '0' || '2' < c) {
            return 0;
        }

        retval = retval * 3 + c - '0';
    }
    return retval;
}

}  // namespace trinary
