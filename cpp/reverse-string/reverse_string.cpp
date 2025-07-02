#include "reverse_string.h"
#include <iterator>

namespace reverse_string {

std::string reverse_string(const std::string_view &str) {
    return {std::rbegin(str), std::rend(str)};
}

}  // namespace reverse_string
