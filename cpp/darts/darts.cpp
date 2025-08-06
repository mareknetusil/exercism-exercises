#include "darts.h"
#include <array>
#include <utility>

namespace darts {

using dist_t = double;
using points_t = int;

template <typename T>
constexpr T square(const T &x) {
    return x * x;
}

static constexpr std::array<std::pair<dist_t, points_t>, 3> SCORE_THRESHOLDS {{
    {square(1.), 10},
    {square(5.), 5},
    {square(10.), 1}
}};

int score(double x, double y) {
    const auto dart_dist = square(x) + square(y);
    for (const auto &[dist, points] : SCORE_THRESHOLDS) {
        if (dart_dist <= dist) {
            return points;
        }
    }
    return 0;
}

}  // namespace darts
