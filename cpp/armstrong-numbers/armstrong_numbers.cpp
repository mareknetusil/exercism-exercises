#include "armstrong_numbers.h"
#include <cmath>
#include <numeric>
#include <vector>

namespace armstrong_numbers {

template <typename Number>
constexpr Number pow(Number x, size_t p) {
    if (p == 0) {
        return 1;
    }
    const auto isEven = p % 2 == 0;
    const auto partial = pow(x, p / 2);
    const auto partialSqr = partial * partial;
    if (isEven) {
        return partialSqr;
    } else {
        return partialSqr * x;
    }
}

std::vector<int> split_to_digits(int n) {
    std::vector<int> digits;
    while (n != 0) {
        digits.push_back(n % 10);
        n /= 10;
    }
    return digits;
}

bool is_armstrong_number(int n) {
    const auto digits = split_to_digits(n);
    const auto p = digits.size();
    const auto sum = std::accumulate(digits.begin(), digits.end(), 0, [p](int acc, int x) {
        return acc + pow(x, p);
    });
    return sum == n;
}

}  // namespace armstrong_numbers
