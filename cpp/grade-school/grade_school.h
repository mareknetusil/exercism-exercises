#pragma once

#include <map>
#include <string>
#include <vector>

namespace grade_school {

class school {
public:
    using students_t = std::vector<std::string>;
    using roster_t = std::map<int, students_t>;

    [[nodiscard]] const roster_t &roster() const noexcept { return m_roster; }
    students_t grade(int grade_) const noexcept;
    void add(std::string name, int grade) noexcept;
private:
    roster_t m_roster;
};

}  // namespace grade_school
