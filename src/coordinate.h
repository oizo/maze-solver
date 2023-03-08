#pragma once
#include <vector>
#include "src/direction.h"

namespace maze
{
    class Coordinate
    {
    public:
        Coordinate(int x, int y);
        const int x;
        const int y;
        bool visited = false;
        std::string toString() const {
            return "x=" + std::to_string(x) + ", y=" + std::to_string(y) + ", visited=" + std::to_string(visited);
        };
    };
}
