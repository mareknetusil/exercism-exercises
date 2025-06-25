#pragma once

#include <string>
#include <vector>

namespace speedywagon {

struct pillar_men_sensor {
    int activity{};
    std::string location{};
    std::vector<int> data{};
};

inline bool connection_check(const pillar_men_sensor *sensorPtr) {
    return sensorPtr != nullptr;
}

int activity_counter(const pillar_men_sensor sensorArray[], size_t capacity);

bool alarm_control(const pillar_men_sensor *sensorPtr);

int uv_light_heuristic(std::vector<int>* data_array);

bool uv_alarm(pillar_men_sensor *sensorPtr);

}  // namespace speedywagon
