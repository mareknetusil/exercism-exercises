#include "grains.h"
#include <cmath>
#include <array>
#include <cstdint>
#include <limits>
#include <numeric>
#include <algorithm>
#include <ranges>

namespace grains {

unsigned long long square(unsigned n) {
    return 1ULL << (n - 1);
}

unsigned long long total() {
    // SPACE EXPENSIVE SOLUTION, O(n) TIME, O(n) SPACE
    // std::array<unsigned long long, 64> grains;
    // std::iota(std::begin(grains), std::end(grains), 1);
    // std::transform(
    //     std::begin(grains), std::end(grains), std::begin(grains),
    //     [](auto n) { return square(n); });
    // return std::accumulate(std::begin(grains), std::end(grains), 0);

    // SIMPLE TRADITIONAL FOR-LOOP SOLUTION, O(n) TIME, O(1) SPACE
    // auto total = 0ULL;
    // for (unsigned i = 1; i < 65; ++i) {
    //     total += square(i);
    // }
    // return total;

    // MODERN C++23 RANGES SOLUTION, O(n) TIME, O(1) SPACE
    // const auto grains = std::ranges::iota_view(1)
    //     | std::views::take(64)
    //     | std::views::transform(square);
    // return std::ranges::fold_left(grains, 0, std::plus<>());

    // MATHEMATICAL SOLUTION, O(1) TIME, O(1) SPACE
    // \sum_{k=0}^n q^k = q^{n + 1} - 1
    // All solutions bellow are just the same formula written in different ways.
    // return square(64) - 1;

    // TRICK, PLATFORM SPECIFIC, SOLUTION
    // return ~0ULL;

    // TRICK, PLATFORM SPECIFIC, SOLUTION THAT ABUSES UNDERFLOW
    // return -1;

    // TRICK SOLUTION
    return std::numeric_limits<uint64_t>::max();
}

}  // namespace grains
