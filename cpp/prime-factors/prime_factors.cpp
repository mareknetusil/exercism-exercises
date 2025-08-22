#include "prime_factors.h"

namespace prime_factors {

long long next_prime(const std::vector<long long> &primes) {
    long long n = primes.back() == 2 ? primes.back() + 1 : primes.back() + 2;
    while (true) {
        bool is_prime = true;
        for (auto prime : primes) {
            if (prime * prime > n) {
                break;
            }
            if (n % prime == 0) {
                is_prime = false;
                break;
            }
        }

        if (is_prime) {
            return n;
        }
        n += 2;
    }
}

std::vector<long long> of(long long n) {
    if (n < 2) {
        return {};
    }

    std::vector<long long> primes{2};
    std::vector<long long> factors{};
    while (n != 1) {
        auto prime = primes.back();
        if (n % prime == 0) {
            n /= prime;
            factors.push_back(prime);
        } else {
            primes.emplace_back(next_prime(primes));
        }
    }
    return factors;
}

}  // namespace prime_factors
