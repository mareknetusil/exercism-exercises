#pragma once

namespace grains {

// Computes the amount of grains on a given chessboard square.
[[nodiscard]] unsigned long long square(unsigned n);

// Computes the sum of grains on a chessboard.
[[nodiscard]] unsigned long long total();

}  // namespace grains
