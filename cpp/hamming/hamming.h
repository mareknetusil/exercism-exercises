#pragma once

#include <string_view>

namespace hamming {

[[nodiscard]] size_t compute(std::string_view a, std::string_view b);

}  // namespace hamming
