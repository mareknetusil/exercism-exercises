#include "lasagna_master.h"
#include <algorithm>

static constexpr int NOODLES_PER_LAYER = 50;  // in grams
static constexpr double SAUCE_PER_LAYER = 0.2;  // in liters

static const std::string NOODLE_LAYER_NAME = "noodles";
static const std::string SAUCE_LAYER_NAME = "sauce";

static const int DEFAULT_PORTION_COUNT = 2;

namespace lasagna_master {

int preparationTime(const std::vector<std::string> &layers, int layerTime) {
    return layerTime * layers.size();
}

amount quantities(const std::vector<std::string> &layers) {
    amount result { 0, 0. };
    for (const auto &layer : layers) {
        if (layer == NOODLE_LAYER_NAME)
            result.noodles += NOODLES_PER_LAYER;
        else if (layer == SAUCE_LAYER_NAME)
            result.sauce += SAUCE_PER_LAYER;
    }
    return result;
}

void addSecretIngredient(
    std::vector<std::string> &myList,
    const std::vector<std::string> &friendsList
) {
    myList.back() = friendsList.back();
}

void addSecretIngredient(
    std::vector<std::string> &myList,
    const std::string &ingredient
) {
    myList.back() = ingredient;
}

std::vector<double> scaleRecipe(const std::vector<double> &quantities, unsigned portions) {
    std::vector<double> scaledQuantities(quantities.size());
    std::transform(
        begin(quantities), end(quantities), begin(scaledQuantities),
        [portions](double quantity) { return quantity * portions / DEFAULT_PORTION_COUNT; }
    );
    return scaledQuantities;
}

}  // namespace lasagna_master
