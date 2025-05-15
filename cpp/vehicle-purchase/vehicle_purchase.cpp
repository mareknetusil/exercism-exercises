#include "vehicle_purchase.h"
#include <algorithm>

namespace vehicle_purchase {

// needs_license determines whether a license is needed to drive a type of
// vehicle. Only "car" and "truck" require a license.
bool needs_license(const std::string &kind) {
    const std::vector<std::string> need_license = {
        "car", "truck"
    };
    const auto it = std::find(
        need_license.begin(), need_license.end(), kind);
    return it != need_license.end();
}

// choose_vehicle recommends a vehicle for selection. It always recommends the
// vehicle that comes first in lexicographical order.
std::string choose_vehicle(const std::string &option1, const std::string &option2) {
    return std::min(option1, option2) + " is clearly the better choice.";
}

// calculate_resell_price calculates how much a vehicle can resell for at a
// certain age.
double calculate_resell_price(double original_price, double age) {
    const std::vector<std::pair<int, double>> thresholds = {
        {10, .5},
        {3, .7},
        {0, .8},
    };
    const auto it = std::find_if(
        begin(thresholds), end(thresholds),
        [age](const auto &p) { return p.first <= age; });
    return it->second * original_price;
}

}  // namespace vehicle_purchase