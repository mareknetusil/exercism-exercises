#pragma once

#include <cstdint>

namespace space_age {

class space_age {
public:
    using seconds_t = std::uint64_t;

    explicit space_age(seconds_t seconds) noexcept
        : m_seconds(seconds) {}

    // years
    using age_t    = double;
    // raw seconds
    using second_t = std::uint64_t;

    [[nodiscard]] seconds_t seconds()   const noexcept { return m_seconds; }
    [[nodiscard]] age_t on_mercury() const noexcept;
    [[nodiscard]] age_t on_venus() const noexcept;
    [[nodiscard]] age_t on_earth() const noexcept;
    [[nodiscard]] age_t on_mars() const noexcept;
    [[nodiscard]] age_t on_jupiter() const noexcept;
    [[nodiscard]] age_t on_saturn() const noexcept;
    [[nodiscard]] age_t on_uranus() const noexcept;
    [[nodiscard]] age_t on_neptune() const noexcept;
private:
    unsigned long m_seconds;
};

}  // namespace space_age
