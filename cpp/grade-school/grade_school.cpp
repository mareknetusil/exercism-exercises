#include "grade_school.h"
#include <algorithm>

namespace grade_school {

void school::add(std::string name, int grade) noexcept{
    auto &students = m_roster[grade];
    const auto posIt = std::lower_bound(
        std::begin(students), std::end(students), name, std::less<>{}
    );
    students.insert(posIt, std::move(name));
}

school::students_t school::grade(int grade_) const noexcept {
    const auto gradeIt = m_roster.find(grade_);
    if (gradeIt != std::end(m_roster)) {
        return gradeIt->second;
    }

    return {};
}

}  // namespace grade_school
