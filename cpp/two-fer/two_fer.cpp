#include "two_fer.h"
#include <sstream>

namespace two_fer {

std::string two_fer(std::string_view name) noexcept {
    std::ostringstream retval;
    retval << "One for "
           << name
           << ", one for me.";
    return retval.str();
}

}  // namespace two_fer
