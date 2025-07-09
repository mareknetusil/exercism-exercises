#pragma once

#include <string_view>
namespace rna_transcription {

[[nodiscard]] char to_rna(char nucleotide);
[[nodiscard]] std::string to_rna(std::string_view nucleotide);

}  // namespace rna_transcription
