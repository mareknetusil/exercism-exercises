#include "space_age.h"
#include <array>
#include <cstddef>

namespace space_age {

constexpr unsigned long SECS_IN_EARTH_YEAR = 31'557'600;

enum Planet {
    MERCURY, VENUS, EARTH, MARS, JUPITER, SATURN, URANUS, NEPTUNE
};

constexpr std::array<double, 8> ORBIT_PERIOD_RATIOS = {
    0.2408467,  // MERCURY
    0.61519726, // VENUS
    1.0,        // EARTH
    1.8808158,  // MARS
    11.862615,  // JUPITER
    29.447498,  // SATURN
    84.016846,  // URANUS
    164.79132   // NEPTUNE
};

constexpr space_age::age_t age_on_planet(double age_in_secs, Planet planet) {
    return age_in_secs / SECS_IN_EARTH_YEAR / ORBIT_PERIOD_RATIOS[planet];
}


space_age::age_t space_age::on_mercury() const noexcept {
    return age_on_planet(m_seconds, Planet::MERCURY);
}

space_age::age_t space_age::on_venus() const noexcept {
    return age_on_planet(m_seconds, Planet::VENUS);
}

space_age::age_t space_age::on_earth() const noexcept {
    return age_on_planet(m_seconds, Planet::EARTH);
}

space_age::age_t space_age::on_mars() const noexcept {
    return age_on_planet(m_seconds, Planet::MARS);
}

space_age::age_t space_age::on_jupiter() const noexcept {
    return age_on_planet(m_seconds, Planet::JUPITER);
}

space_age::age_t space_age::on_saturn() const noexcept {
    return age_on_planet(m_seconds, Planet::SATURN);
}

space_age::age_t space_age::on_uranus() const noexcept {
    return age_on_planet(m_seconds, Planet::URANUS);
}

space_age::age_t space_age::on_neptune() const noexcept {
    return age_on_planet(m_seconds, Planet::NEPTUNE);
}

}  // namespace space_age
