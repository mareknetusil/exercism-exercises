#include "difference_of_squares.h"

namespace difference_of_squares {

unsigned square_of_sum(unsigned n) {
    const auto sum = n * (n + 1) / 2;
    return sum * sum;
}

unsigned sum_of_squares(unsigned n) {
    return (2 * n + 1) * (n + 1) * n / 6;
}

unsigned difference(unsigned n) {
    return square_of_sum(n) - sum_of_squares(n);
}

}  // namespace difference_of_squares
