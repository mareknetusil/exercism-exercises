#pragma once

#include <string_view>
#include <string>

namespace two_fer {

[[nodiscard]] std::string two_fer(std::string_view name = "you") noexcept;

}  // namespace two_fer
