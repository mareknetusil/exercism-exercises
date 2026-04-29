#include "nth_prime.h"

#include <stdexcept>
#include <vector>

namespace nth_prime {

int nth(size_t n) {
    if (n == 0) {
        throw std::domain_error("Input must be a positive integer!");
    }

    std::vector<int> primes{2};
    for (int candidate = 3; primes.size() < n; candidate += 2) {
        bool isPrime = true;
        for (int p : primes) {
            if (p * p > candidate) break;
            if (candidate % p == 0) { isPrime = false; break; }
        }
        if (isPrime) {
            primes.push_back(candidate);
        }
    }

    return primes.back();
}

}  // namespace nth_prime
