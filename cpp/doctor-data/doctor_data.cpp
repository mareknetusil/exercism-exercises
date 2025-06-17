#include "doctor_data.h"

namespace heaven {

    Vessel Vessel::replicate(std::string new_name) const
    {
        return Vessel{
            std::move(new_name),
            generation + 1,
            current_system
        };
    }

    void Vessel::make_buster()
    {
        busters += 1;
    }

    bool Vessel::shoot_buster()
    {
        if (busters <= 0)
            return false;

        busters -= 1;
        return true;
    }

    std::string get_older_bob(const Vessel &first, const Vessel &second)
    {
        const auto &older = first.generation < second.generation ? first : second;
        return older.name;
    }

    bool in_the_same_system(const Vessel &first, const Vessel &second)
    {
        return first.current_system == second.current_system;
    }
}
