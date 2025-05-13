#include "raindrops.h"
#include <vector>
#include <tuple>
#include <numeric>

namespace raindrops {

const std::vector<std::pair<int, std::string>> rules = {
	{3, "Pling"},
	{5, "Plang"},
	{7, "Plong"}
};

std::string convert(const int number)
{
	// std::string retval{};
	// for (const auto& [divisor, word] : rules) {
	// 	if (number % divisor == 0)
	// 		retval += word;
	// }

	const auto retval = std::accumulate(
		begin(rules),
		end(rules),
		std::string{},
		[number](const auto &acc, const auto &rule) {
			return acc + (number % rule.first == 0 ? rule.second : "");
		});

	if (retval.empty())
		return std::to_string(number);

	return retval;
}

}  // namespace raindrops
