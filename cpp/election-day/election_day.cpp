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
    auto winnerIter = std::max_element(
        begin(final_count),
        end(final_count),
        [](ElectionResult &first, ElectionResult &second) {
            return first.votes < second.votes;
        }
    );
    auto &winner = *winnerIter;
    winner.name = "President " + winner.name;
    return winner;
}

}  // namespace election
