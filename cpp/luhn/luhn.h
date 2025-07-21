#pragma once

#include <string_view>

namespace luhn {

[[nodiscard]] bool valid(std::string_view text);

}  // namespace luhn
