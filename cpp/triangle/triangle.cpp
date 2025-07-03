#include "triangle.h"
#include <stdexcept>
#include <algorithm>

namespace triangle {

flavor kind(double a, double b, double c) {
    const auto shortest = std::min({a, b, c});
    const auto longest = std::max({a, b, c});
    if (a + b + c < 2 * longest || shortest <= 0) {
        throw std::domain_error("Not a triangle!");
    }

    if (a == b && a == c) {
        return flavor::equilateral;
    }

    if (a == b || b == c || a == c) {
        return flavor::isosceles;
    }

    return flavor::scalene;
}

}  // namespace triangle
