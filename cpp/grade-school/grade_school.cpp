#include "grade_school.h"
#include <algorithm>

namespace grade_school {


static const school::students_t empty_grade{};

void school::add(std::string name, int grade) {
    auto &students = m_roster[grade];
    const auto posIt = std::upper_bound(
        std::begin(students), std::end(students), name
    );
    students.insert(posIt, std::move(name));
}

const school::students_t &school::grade(int grade_) const noexcept {
    const auto gradeIt = m_roster.find(grade_);
    if (gradeIt != std::end(m_roster)) {
        return gradeIt->second;
    }

    return empty_grade;
}

}  // namespace grade_school
