#include "difference_of_squares.h"
#include <cmath>

namespace difference_of_squares {

namespace arithmetic_sequence {
    inline unsigned n_th(unsigned a_1, unsigned n, unsigned diff) {
        return a_1 + (n - 1) * diff;
    }

    inline unsigned sum(unsigned a_1, unsigned n, int diff) {
        return n * (a_1 + n_th(a_1, n, diff)) / 2;
    }
}


unsigned square_of_sum(unsigned n) {
    return std::pow(arithmetic_sequence::sum(1, n, 1), 2);
}

unsigned sum_of_squares(unsigned n) {
    unsigned retval = 0;
    for (unsigned i = 1; i < n + 1; ++i) {
        retval += std::pow(i, 2);
    }
    return retval;
}

unsigned difference(unsigned n) {
    return square_of_sum(n) - sum_of_squares(n);
}

}  // namespace difference_of_squares
