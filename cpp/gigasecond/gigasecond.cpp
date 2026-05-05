#include "gigasecond.h"

constexpr uint64_t SECOND = 1;
constexpr uint64_t KILO_SECOND = 1000 * SECOND;
constexpr uint64_t MEGA_SECOND = 1000 * KILO_SECOND;
constexpr uint64_t GIGA_SECOND = 1000 * MEGA_SECOND;

namespace gigasecond {

ptime advance(ptime start) {
    return start + seconds(GIGA_SECOND);
}

}  // namespace gigasecond
