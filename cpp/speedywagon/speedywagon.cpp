#include "speedywagon.h"

namespace speedywagon {

// Enter your code below:

// Please don't change the interface of the uv_light_heuristic function
int uv_light_heuristic(std::vector<int>* data_array) {
    double avg{};
    for (auto element : *data_array) {
        avg += element;
    }
    avg /= data_array->size();
    int uv_index{};
    for (auto element : *data_array) {
        if (element > avg) ++uv_index;
    }
    return uv_index;
}


int activity_counter(const pillar_men_sensor sensorArray[], size_t capacity) {
    int total = 0;
    for (size_t i = 0; i < capacity; ++i) {
        const auto *sensorPtr = sensorArray + i;
        total += sensorPtr->activity;
    }
    return total;
}

bool alarm_control(const pillar_men_sensor *sensorPtr) {
    if (!connection_check(sensorPtr))
        return false;

    return sensorPtr->activity > 0;
}

bool uv_alarm(pillar_men_sensor *sensorPtr) {
    if (!connection_check(sensorPtr))
        return false;

    const auto heuristics = uv_light_heuristic(&sensorPtr->data);
    return heuristics > sensorPtr->activity;
}

}  // namespace speedywagon
