#pragma once
#include <vector>
#include "src/direction.h"

namespace maze
{
    class Coordinate
    {
    public:
        Coordinate(int x, int y) : x(x), y(y) {};
        const int x;
        const int y;
    };

    inline std::ostream &operator<< (std::ostream &os, Coordinate const &c) {
        os << "Coord[x=" << c.x << ", y=" << c.y << "]";
        return os;
    }
}
