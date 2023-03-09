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
        std::string toString() const {
            return "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
        };
    };
}
