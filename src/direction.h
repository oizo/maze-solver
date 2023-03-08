#pragma once
#include <stdexcept>

namespace maze
{
    enum class Direction { NORTH, SOUTH, EAST, WEST };
    
    inline const std::string toString(const Direction &d)
    {
        switch (d)
        {
            case Direction::NORTH: return "NORTH";
            case Direction::SOUTH: return "SOUTH";
            case Direction::EAST: return "EAST";
            case Direction::WEST: return "WEST";
            default: throw std::invalid_argument("Invalid enum type");
        }
    }
    
    inline const std::string toShortString(const Direction &d) {
        switch (d)
        {
            case Direction::NORTH: return "N";
            case Direction::SOUTH: return "S";
            case Direction::EAST: return "E";
            case Direction::WEST: return "W";
            default: throw std::invalid_argument("Invalid enum type");
        }
    }

    inline const std::string toShortString(const std::vector<Direction> &directions) {
        std::string tmp;
        for (auto d = directions.begin(); d != directions.end(); ++d) {
            tmp.append(toShortString(*d));
        }
        return tmp;
    }

    inline Direction reverse(const Direction &d) {
        switch (d)
        {
        case Direction::NORTH: return Direction::SOUTH;
        case Direction::SOUTH: return Direction::NORTH;
        case Direction::EAST: return Direction::WEST;
        case Direction::WEST: return Direction::EAST;
        default: throw std::logic_error("This can't happen");
        }
    }

}
