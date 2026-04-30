#pragma once

#include <utility>

namespace queen_attack {

using pos_t = std::pair<int, int>;

class chess_board {
public:

    chess_board(pos_t white, pos_t black);

    [[nodiscard]] const pos_t &white() const noexcept { return m_white; }
    [[nodiscard]] const pos_t &black() const noexcept { return m_black; }

    [[nodiscard]] bool can_attack() const noexcept;
private:
    pos_t m_white;
    pos_t m_black;
};

}  // namespace queen_attack
