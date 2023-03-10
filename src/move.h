#pragma once
#include "src/direction.h"
#include "src/coordinate.h"

namespace maze {

    class Move
    {
    public:
        Move(const Direction &entryFrom, const Coordinate &coord) : entryFrom(entryFrom), coord(coord) {};
        Move(const Move &m) : entryFrom(m.entryFrom), coord(m.coord), isPathToExit(m.isPathToExit) {};
        const Direction entryFrom;
        const Coordinate coord;
        bool isPathToExit = false;
    };

    inline std::ostream &operator<< (std::ostream &os, Move const &m) {
        os << "Move[entry=" << m.entryFrom << ", coord=" << m.coord << ", isPathToExit=" << m.isPathToExit << "]";
        return os;
    }
}