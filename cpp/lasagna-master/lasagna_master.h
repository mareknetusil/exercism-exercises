#pragma once

#include <vector>
#include <string>

namespace lasagna_master {

struct amount {
    int noodles;
    double sauce;
};

int preparationTime(const std::vector<std::string> &layers, int layerTime = 2);

amount quantities(const std::vector<std::string> &layers);

void addSecretIngredient(
    std::vector<std::string> &myList,
    const std::vector<std::string> &friendsList
);
void addSecretIngredient(
    std::vector<std::string> &myList,
    const std::string &ingredient
);

std::vector<double> scaleRecipe(const std::vector<double> &quantities, unsigned portions);

}  // namespace lasagna_master
