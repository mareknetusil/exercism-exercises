#pragma once

namespace space_age {

class space_age {
public:
    explicit space_age(unsigned long seconds) noexcept
        : m_seconds(seconds) {}

    using age_t = double;

    [[nodiscard]] age_t seconds() const noexcept { return m_seconds; }
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
