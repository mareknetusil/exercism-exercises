#pragma once

#include <string>
#include <string_view>
#include <vector>
namespace protein_translation {

[[nodiscard]] std::vector<std::string> proteins(std::string_view rna);

}  // namespace protein_translation
