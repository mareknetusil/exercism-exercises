#pragma once

#include <string>
#include <string_view>

namespace rotational_cipher {

[[nodiscard]] std::string rotate(std::string_view text, int key);

}  // namespace rotational_cipher
