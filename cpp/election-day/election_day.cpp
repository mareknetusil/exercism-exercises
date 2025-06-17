#include <algorithm>
#include <iterator>
#include <string>
#include <vector>

namespace election {

// The election result struct is already created for you:

struct ElectionResult {
    // Name of the candidate
    std::string name{};
    // Number of votes the candidate has
    int votes{};
};

int vote_count(const ElectionResult &result) {
    return result.votes;
}

void increment_vote_count(ElectionResult &result, int count) {
    result.votes += count;
}

ElectionResult &determine_result(std::vector<ElectionResult> &final_count) {
    if (final_count.empty()) {
        throw std::invalid_argument("final_count must contain at least one candidate");
    }

    auto winnerIter = std::max_element(
        begin(final_count),
        end(final_count),
        [](const ElectionResult &first, const ElectionResult &second) {
            return first.votes < second.votes;
        }
    );
    ElectionResult &winner = *winnerIter;
    static const std::string title{"President "};
    if (winner.name.rfind(title, 0) != 0) {          // avoid double‐prefixing
        winner.name.insert(0, title);
    }
    return winner;
}

}  // namespace election
