#pragma once
#include <stdexcept>

namespace maze
{
    enum class Direction { NORTH, SOUTH, EAST, WEST };

    inline std::ostream &operator<< (std::ostream &os, Direction const &d) {
        switch (d) {
            case Direction::NORTH: os << "N"; break;
            case Direction::SOUTH: os << "S"; break;
            case Direction::EAST: os << "E"; break;
            case Direction::WEST: os << "W"; break;
            default: std::to_string((int)d);
        }
        return os;
    }

    inline Direction reverse(const Direction &d) {
        switch (d) {
            case Direction::NORTH: return Direction::SOUTH;
            case Direction::SOUTH: return Direction::NORTH;
            case Direction::EAST: return Direction::WEST;
            case Direction::WEST: return Direction::EAST;
            default: throw std::logic_error("This can't happen");
        }
    }
}
