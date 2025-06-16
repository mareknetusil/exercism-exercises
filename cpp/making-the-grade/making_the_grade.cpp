#include <algorithm>
#include <array>
#include <cmath>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

constexpr int PASS_THRESHOLD = 41; // min score to pass
constexpr int MAX_SCORE = 100;

constexpr std::array<char, 5> MARKS = {
    'A', 'B', 'C', 'D', 'F'
};
constexpr int MARKS_COUNT = MARKS.size();
constexpr int PASS_MARKS_COUNT = MARKS_COUNT - 1;

// Round down all provided student scores.
[[nodiscard]] std::vector<int> round_down_scores(const std::vector<double> &student_scores) noexcept {
    std::vector<int> rounded(student_scores.size());
    std::transform(
        begin(student_scores), end(student_scores),
        begin(rounded),
        [](double s) { return std::floor(s); });
    return rounded;
}

// Count the number of failing students out of the group provided.
[[nodiscard]] int count_failed_students(const std::vector<int> &student_scores) noexcept {
    return std::count_if(
        begin(student_scores), end(student_scores),
        [](int s) { return s < PASS_THRESHOLD; });
}

// Create a list of grade thresholds based on the provided highest grade.
[[nodiscard]] std::array<int, PASS_MARKS_COUNT> letter_grades(int highest_score) {
    if (highest_score <= PASS_THRESHOLD)
        throw std::invalid_argument("highest score must be higher then PASS_THRESHOLD!");

    const auto range = highest_score - PASS_THRESHOLD + 1;
    std::array<int, PASS_MARKS_COUNT> retval;
    for (int i = 0; i < PASS_MARKS_COUNT; ++i) {
        retval[i] = PASS_THRESHOLD + i * range / PASS_MARKS_COUNT;
    }
    return retval;
}

// Organize the student's rank, name, and grade information in ascending order.
[[nodiscard]] std::vector<std::string> student_ranking(
    const std::vector<int> &student_scores,
    const std::vector<std::string> &student_names
) {
    if (student_scores.size() != student_names.size())
        throw std::invalid_argument("student_scores and student_names must be the same size!");

    std::vector<std::string> ranking;
    ranking.resize(student_scores.size());
    for (size_t i = 0; i < student_scores.size(); ++i) {
        std::stringstream line;
        line << i + 1 << ". " << student_names.at(i) << ": " << student_scores.at(i);
        ranking[i] = line.str();
    }
    return ranking;
}

// Create a string that contains the name of the first student to make a perfect
// score on the exam.
[[nodiscard]] std::string perfect_score(
    const std::vector<int> &student_scores,
    const std::vector<std::string> &student_names
) {
    if (student_scores.size() != student_names.size())
        throw std::invalid_argument("student_scores and student_names must be the same size!");

    for (size_t i = 0; i < student_scores.size(); ++i) {
        if (student_scores[i] == MAX_SCORE)
            return student_names.at(i);
    }
    return "";
}
