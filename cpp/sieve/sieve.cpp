#include "sieve.h"
#include <cmath>
#include <vector>

namespace sieve {

std::vector<int> primes(int n) {
    const auto offset = 2;
    std::vector<bool> is_composite(n - 1, false);
    for (int i = 0; i < n - 1; ++i) {
        if (is_composite[i]) {
            continue;
        }

        const auto startPos = (i + offset) * (i + offset) - offset;
        for (int j = startPos; j < n - 1; j += (i + offset)) {
            is_composite[j] = true;
        }
    }

    std::vector<int> result;
    result.reserve(n / std::log(n));
    for (int i = 0; i < n - 1; ++i) {
        if (!is_composite[i]) {
            result.push_back(i + offset);
        }
    }
    return result;
}

}  // namespace sieve
