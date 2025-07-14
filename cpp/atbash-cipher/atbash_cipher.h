#pragma once

#include <string>
#include <string_view>
namespace atbash_cipher {

[[nodiscard]] std::string encode(std::string_view text);
[[nodiscard]] std::string decode(std::string_view text);

}  // namespace atbash_cipher
