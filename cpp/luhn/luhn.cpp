#include "luhn.h"
#include <iterator>

namespace luhn {

bool valid(std::string_view text) {
    int sum = 0;
    size_t count = 0;
    bool should_double = false;
    for (auto cIt = std::rbegin(text); cIt != std::rend(text); ++cIt) {
        const auto c = *cIt;
        if (c == ' ') {
            continue;
        }

        if (c < '0' || '9' < c) {
            return false;
        }

        ++count;
        auto num = c - '0';
        if (should_double) {
            num *= 2;
            if (num > 9) {
                num -= 9;
            }
        }
        sum += num;
        should_double = !should_double;
    }
    return count > 1 && sum % 10 == 0;
}

}  // namespace luhn
