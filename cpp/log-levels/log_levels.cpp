#include <string>
#include <algorithm>

namespace log_line {
std::string message(std::string line) {
    // return the message
	const auto pos = line.find("]");
	return line.substr(pos + 3);
}

std::string log_level(std::string line) {
    // return the log level
	const auto pos_end = line.find("]");
	auto log_lvl = line.substr(1, pos_end - 1);
	std::transform(begin(log_lvl), end(log_lvl), begin(log_lvl),
				   [](auto c) { return std::toupper(c); });
	return log_lvl;
}

std::string reformat(const std::string& line) {
    // return the reformatted message
	const auto log_lvl = log_level(line);
	const auto msg = message(line);
	return msg + " (" + log_lvl + ")";
}

}  // namespace log_line
