#include "rna_transcription.h"
#include <stdexcept>
#include <algorithm>

namespace rna_transcription {

char to_rna(char nucleotide) {
    switch (nucleotide) {
        case 'G': return 'C';
        case 'C': return 'G';
        case 'T': return 'A';
        case 'A': return 'U';
        default: throw std::invalid_argument("Invalid nucleotide.");
    }
}

std::string to_rna(std::string_view dna) {
    std::string rna{};
    rna.resize(dna.size());
    std::transform(
        std::begin(dna), std::end(dna), std::begin(rna),
        [](char c) { return to_rna(c); }
    );
    return rna;
}

}  // namespace rna_transcription
