#pragma once
#include <vector>
#include "src/direction.h"
#include "src/maze.h"
#include "src/coordinate.h"

namespace maze {

    class Solver
    {
    private:
        bool solve(Maze &maze, Coordinate &from, Coordinate &current);
    public:
        Solver() {};
        bool solve(Maze &maze);
    };
}
