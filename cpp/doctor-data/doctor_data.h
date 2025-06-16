#include <string>

namespace star_map {
    enum class System {
        AlphaCentauri, BetaHydri, DeltaEridani, EpsilonEridani,
        Omicron2Eridani, Sol
    };
}

namespace heaven {
    class Vessel {
    public:
        Vessel(std::string name, int generation);
        Vessel(std::string name, int generation, star_map::System system);

        Vessel replicate(std::string name) const;
        void make_buster();
        bool shoot_buster();

        std::string name;
        int generation;
        star_map::System current_system;
        int busters = 0;
    };

    std::string get_older_bob(const Vessel &first, const Vessel &second);
    bool in_the_same_system(const Vessel &first, const Vessel &second);
}
