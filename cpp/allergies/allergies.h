#pragma once

#include <string>
#include <string_view>
#include <unordered_set>

namespace allergies {

struct allergy_test {
    int score;

    explicit allergy_test(int score): score{score} {}

    [[nodiscard]] bool is_allergic_to(std::string_view item_name) const;
    [[nodiscard]] std::unordered_set<std::string> get_allergies() const;
};

}  // namespace allergies
