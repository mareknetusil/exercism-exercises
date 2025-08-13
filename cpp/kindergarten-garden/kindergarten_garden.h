#pragma once

#include <string_view>
#include <array>
#include <map>
#include <vector>

namespace kindergarten_garden {
    enum class Plants { clover, grass, radishes, violets };

    using kid_plants_t = std::array<Plants, 4>;
    using plant_encoding_t = std::map<char, Plants>;
    using kids_list_t = std::vector<std::string_view>;

    static const plant_encoding_t example_plant_encoding {
        {'G', Plants::grass},
        {'C', Plants::clover},
        {'R', Plants::radishes},
        {'V', Plants::violets}
    };

    static const kids_list_t example_kids_list {
        "Alice", "Bob", "Charlie", "David", "Eve", "Fred",
        "Ginny", "Harriet", "Ileana", "Joseph", "Kincaid", "Larry"
    };

    [[nodiscard]] kid_plants_t plants(
        std::string_view diagram, std::string_view name,
        const plant_encoding_t &plant_encoding = example_plant_encoding,
        const kids_list_t &kids_list = example_kids_list
    );

}  // namespace kindergarten_garden
