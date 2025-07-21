#include "luhn.h"
#include <iterator>

namespace luhn {

bool valid(std::string_view text) {
    int sum = 0;
    size_t count = 0;
    bool double_ = false;
    for (auto cIt = std::rbegin(text); cIt != std::rend(text); ++cIt) {
        const auto c = *cIt;
        if (c < '0' || '9' < c) {
            if (c != ' ') {
                return false;
            }
            continue;
        }

        ++count;
        auto num = c - '0';
        if (double_) {
            num *= 2;
            if (num > 9) {
                num -= 9;
            }
        }
        sum += num;
        double_ = !double_;
    }
    return count > 1 && sum % 10 == 0;
}

}  // namespace luhn
