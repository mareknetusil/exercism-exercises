#include "hamming.h"
#include <functional>
#include <stdexcept>
#include <numeric>

namespace hamming {

size_t compute(std::string_view a, std::string_view b) {
    if (a.size() != b.size()) {
        throw std::domain_error("Strings must be the same length.");
    }

    const auto count = std::transform_reduce(
        std::begin(a), std::end(a), std::begin(b), 0,
        std::plus<>(), std::not_equal_to<>()
    );
    return count;
}
}  // namespace hamming
