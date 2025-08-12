#include "allergies.h"
#include <map>

namespace allergies {

static const std::map<std::string_view, int> item_flags {
    {"eggs", 1},
    {"peanuts", 2},
    {"shellfish", 4},
    {"strawberries", 8},
    {"tomatoes", 16},
    {"chocolate", 32},
    {"pollen", 64},
    {"cats", 128}
};

bool allergy_test::is_allergic_to(std::string_view item_name) const {
    const auto flagIt = item_flags.find(item_name);
    if (flagIt == item_flags.end()) {
        return false;
    }

    return flagIt->second & score;
}

std::unordered_set<std::string> allergy_test::get_allergies() const {
    std::unordered_set<std::string> retval{};
    for (const auto &[name, flag] : item_flags) {
            if (flag & score) {
                retval.emplace(name);
            }
    }
    return retval;
}

}  // namespace allergies
