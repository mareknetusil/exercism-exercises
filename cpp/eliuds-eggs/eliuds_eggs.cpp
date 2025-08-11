#include "eliuds_eggs.h"
#include <stdexcept>

namespace chicken_coop {

int positions_to_quantity(int position) {
    if (position < 0) {
        throw std::invalid_argument("Position must be non-negative.");
    }

    int count = 0;
    while (position > 0) {
        count += position & 1;
        position >>= 1;
    }

    return count;
}

}  // namespace chicken_coop
