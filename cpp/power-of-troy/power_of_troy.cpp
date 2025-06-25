#include "power_of_troy.h"
#include <memory>

namespace troy {

void give_new_artifact(human &_human, std::string artifactName) {
    _human.possession = std::make_unique<artifact>(artifactName);
}

void manifest_power(human &_human, std::string powerName) {
    _human.own_power = std::make_shared<power>(powerName);
}

void use_power(human& caster, human& target) {
    target.influenced_by = caster.own_power;
}

int power_intensity(human &caster) {
    if (!caster.own_power)
        return 0;

    return caster.own_power.use_count();
}

}  // namespace troy
