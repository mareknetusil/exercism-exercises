#pragma once

#include "boost/date_time/posix_time/posix_time.hpp"

using namespace boost::posix_time;

namespace gigasecond {

[[nodiscard]] ptime advance(ptime start);

}  // namespace gigasecond
