#include "protein_translation.h"
#include <set>
#include <stdexcept>
#include <string>
#include <utility>
#include <variant>

namespace protein_translation {

constexpr size_t CODON_SIZE = 3;

struct Stop {};

using codon_instruction_t = std::variant<std::string, Stop>;
using codons_set_t = std::set<std::string_view>;
using codon_meaning_t = std::pair<codons_set_t, codon_instruction_t>;

static const std::vector<codon_meaning_t> codon_mapping = {
    {{"AUG"},                       "Methionine"},
    {{"UUU", "UUC"},                "Phenylalanine"},
    {{"UUA", "UUG"},                "Leucine"},
    {{"UCU", "UCC", "UCA", "UCG"},  "Serine"},
    {{"UAU", "UAC"},                "Tyrosine"},
    {{"UGU", "UGC"},                "Cysteine"},
    {{"UGG"},                       "Tryptophan"},
    {{"UAA", "UAG", "UGA"},         Stop{}}
};

std::variant<std::string, Stop> codon_to_protein(std::string_view codon) {
    if (codon.size() != CODON_SIZE) {
        throw std::invalid_argument("Wrong codon size.");
    }

    for (const auto &[codons, instruction] : codon_mapping) {
        if (codons.find(codon) != std::end(codons)) {
            return instruction;
        }
    }

    throw std::domain_error("Unknown codon.");
}

std::vector<std::string> proteins(std::string_view rna) {
    std::vector<std::string> retval;
    for (size_t i = 0; i < rna.size(); i += CODON_SIZE) {
        const auto codon = rna.substr(i, CODON_SIZE);
        auto instruction = codon_to_protein(codon);
        if (std::holds_alternative<Stop>(instruction)) {
            break;
        }
        retval.push_back(std::move(std::get<std::string>(instruction)));
    }
    return retval;
}

}  // namespace protein_translation
