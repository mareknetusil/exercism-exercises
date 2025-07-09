#pragma once

#include <string_view>
#include <map>

namespace nucleotide_count {

using count_t = std::map<char, int>;

[[nodiscard]] count_t count(std::string_view dna);

}  // namespace nucleotide_count
