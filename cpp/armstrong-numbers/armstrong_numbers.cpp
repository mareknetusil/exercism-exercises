#include "armstrong_numbers.h"
#include <cmath>
#include <numeric>
#include <vector>

namespace armstrong_numbers {

std::vector<int> split_to_digits(int n) {
    if (n == 0) {
        return {0};
    }

    std::vector<int> digits;
    while (n != 0) {
        digits.push_back(n % 10);
        n /= 10;
    }
    return digits;
}

bool is_armstrong_number(int n) {
    if (n < 0) {
        return false;
    }

    const auto digits = split_to_digits(n);
    const auto p = digits.size();
    const auto sum = std::accumulate(digits.begin(), digits.end(), 0, [p](int acc, int x) {
        return acc + std::pow(x, p);
    });
    return sum == n;
}

}  // namespace armstrong_numbers
