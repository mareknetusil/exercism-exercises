#include "prime_factors.h"

namespace prime_factors {

std::vector<long long> of(long long n) {
    std::vector<long long> factors;

    while (n % 2 == 0) {
        factors.push_back(2);
        n /= 2;
    }

    for (long long d = 3; d * d <=n; d += 2) {
        while (n % d == 0) {
            factors.push_back(d);
            n /= d;
        }
    }

    if (n > 1) {
        factors.push_back(n);
    }

    return factors;
}

}  // namespace prime_factors
