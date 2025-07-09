#include "nucleotide_count.h"
#include <stdexcept>

namespace nucleotide_count {

count_t count(std::string_view dna) {
    count_t retval {
        {'A', 0},
        {'C', 0},
        {'G', 0},
        {'T', 0}
    };

    for (const char c : dna) {
        if (c != 'A' && c != 'C' && c != 'G' && c != 'T') {
            throw std::invalid_argument("Invalid nucleotides found.");
        }
        ++retval[c];
    }
    return retval;
}

}  // namespace nucleotide_count
