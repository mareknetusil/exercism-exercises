#include "sieve.h"
#include <cmath>
#include <vector>

namespace sieve {

std::vector<int> primes(int n) {
    std::vector<bool> flags(n - 1, false);
    for (int i = 0; i < n - 1; ++i) {
        if (flags[i]) {
            continue;
        }

        for (int j = 2 * i + 2; j < n - 1; j += (i + 2)) {
            flags[j] = true;
        }
    }

    std::vector<int> primes_;
    primes_.reserve(n / std::log(n));
    for (int i = 0; i < n - 1; ++i) {
        if (!flags[i]) {
            primes_.push_back(i + 2);
        }
    }
    return primes_;
}

}  // namespace sieve
