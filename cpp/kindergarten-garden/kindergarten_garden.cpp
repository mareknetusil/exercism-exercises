#include "kindergarten_garden.h"
#include <algorithm>
#include <iterator>
#include <optional>
#include <stdexcept>
#include <string_view>

namespace kindergarten_garden {

std::optional<size_t> kids_pos(std::string_view name, const kids_list_t &kids_list) {
    const auto it = std::find(kids_list.begin(), kids_list.end(), name);
    if (it == kids_list.end()) {
        return std::nullopt;
    }
    return std::distance(kids_list.begin(), it);
}

kid_plants_t plants(
    std::string_view diagram, std::string_view name,
    const plant_encoding_t &plant_encoding,
    const kids_list_t &kids_list
) {
    const auto kids_pos_ = kids_pos(name, kids_list);
    if (!kids_pos_) {
        throw std::invalid_argument("Kid not found in the kids_list.");
    }
    const auto plants_pos = *kids_pos_ * 2;
    auto newLinePos = diagram.find('\n');
    if (newLinePos == std::string_view::npos) {
        throw std::invalid_argument("Invalid diagram format.");
    }
    const auto row1 = diagram.substr(0, newLinePos);
    const auto row2 = diagram.substr(newLinePos + 1);

    if (plants_pos + 1 >= row1.size() || plants_pos + 1 >= row2.size()) {
        throw std::invalid_argument("Kid's plant not in the diagram.");
    }

    kid_plants_t retval;
    std::array<char, 4> plant_chars {
        row1[plants_pos], row1[plants_pos + 1],
        row2[plants_pos], row2[plants_pos + 1]
    };

    for (size_t i = 0; i < 4; ++i) {
        const auto it = plant_encoding.find(plant_chars[i]);
        if (it == plant_encoding.end()) {
            throw std::invalid_argument("Unknown plant character.");
        }
        retval[i] = it->second;
    }

    return retval;
}

}  // namespace kindergarten_garden
