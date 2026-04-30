#include "queen_attack.h"
#include <cstdlib>
#include <stdexcept>


namespace {

constexpr int board_size = 8;

bool is_valid(queen_attack::pos_t pos) noexcept
{
    return 0 <= pos.first && pos.first < board_size &&
           0 <= pos.second && pos.second < board_size;
}

}

namespace queen_attack {

chess_board::chess_board(pos_t white, pos_t black)
    : m_white(white), m_black(black)
{
    if (!is_valid(white) || !is_valid(black)) {
        throw std::domain_error("Queens don't fit to the board!");
    }

    if (white == black) {
        throw std::domain_error("Queens can't occupy the same square!");
    }
}

bool chess_board::can_attack() const noexcept {
    return m_white.first == m_black.first ||
           m_white.second == m_black.second ||
           std::abs(m_white.first - m_black.first) == std::abs(m_white.second - m_black.second);
}

}  // namespace queen_attack
